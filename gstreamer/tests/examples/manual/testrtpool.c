
/*** block a  from ../../../docs/manual/advanced-threads.xml ***/
#include <gst/gst.h>

#define TEST_TYPE_RT_POOL             (test_rt_pool_get_type ())
#define TEST_RT_POOL(pool)            (G_TYPE_CHECK_INSTANCE_CAST ((pool), TEST_TYPE_RT_POOL, TestRTPool))
#define TEST_IS_RT_POOL(pool)         (G_TYPE_CHECK_INSTANCE_TYPE ((pool), TEST_TYPE_RT_POOL))
#define TEST_RT_POOL_CLASS(pclass)    (G_TYPE_CHECK_CLASS_CAST ((pclass), TEST_TYPE_RT_POOL, TestRTPoolClass))
#define TEST_IS_RT_POOL_CLASS(pclass) (G_TYPE_CHECK_CLASS_TYPE ((pclass), TEST_TYPE_RT_POOL))
#define TEST_RT_POOL_GET_CLASS(pool)  (G_TYPE_INSTANCE_GET_CLASS ((pool), TEST_TYPE_RT_POOL, TestRTPoolClass))
#define TEST_RT_POOL_CAST(pool)       ((TestRTPool*)(pool))

typedef struct _TestRTPool TestRTPool;
typedef struct _TestRTPoolClass TestRTPoolClass;

struct _TestRTPool {
  GstTaskPool    object;
};

struct _TestRTPoolClass {
  GstTaskPoolClass parent_class;
};

GType           test_rt_pool_get_type    (void);

GstTaskPool *   test_rt_pool_new         (void);


/*** block b  from ../../../docs/manual/advanced-threads.xml ***/
#include <pthread.h>

typedef struct
{
  pthread_t thread;
} TestRTId;

G_DEFINE_TYPE (TestRTPool, test_rt_pool, GST_TYPE_TASK_POOL);

static void
default_prepare (GstTaskPool * pool, GError ** error)
{
  /* we don't do anything here. We could construct a pool of threads here that
   * we could reuse later but we don't */
}

static void
default_cleanup (GstTaskPool * pool)
{
}

static gpointer
default_push (GstTaskPool * pool, GstTaskPoolFunction func, gpointer data,
    GError ** error)
{
  TestRTId *tid;
  gint res;
  pthread_attr_t attr;
  struct sched_param param;

  tid = g_slice_new0 (TestRTId);

  pthread_attr_init (&attr);
  if ((res = pthread_attr_setschedpolicy (&attr, SCHED_RR)) != 0)
    g_warning ("setschedpolicy: failure: %p", g_strerror (res));

  param.sched_priority = 50;
  if ((res = pthread_attr_setschedparam (&attr, &param)) != 0)
    g_warning ("setschedparam: failure: %p", g_strerror (res));

  if ((res = pthread_attr_setinheritsched (&attr, PTHREAD_EXPLICIT_SCHED)) != 0)
    g_warning ("setinheritsched: failure: %p", g_strerror (res));

  res = pthread_create (&tid->thread, &attr, (void *(*)(void *)) func, data);

  if (res != 0) {
    g_set_error (error, G_THREAD_ERROR, G_THREAD_ERROR_AGAIN,
        "Error creating thread: %s", g_strerror (res));
    g_slice_free (TestRTId, tid);
    tid = NULL;
  }

  return tid;
}

static void
default_join (GstTaskPool * pool, gpointer id)
{
  TestRTId *tid = (TestRTId *) id;

  pthread_join (tid->thread, NULL);

  g_slice_free (TestRTId, tid);
}

static void
test_rt_pool_class_init (TestRTPoolClass * klass)
{
  GstTaskPoolClass *gsttaskpool_class;

  gsttaskpool_class = (GstTaskPoolClass *) klass;

  gsttaskpool_class->prepare = default_prepare;
  gsttaskpool_class->cleanup = default_cleanup;
  gsttaskpool_class->push = default_push;
  gsttaskpool_class->join = default_join;
}

static void
test_rt_pool_init (TestRTPool * pool)
{
}

GstTaskPool *
test_rt_pool_new (void)
{
  GstTaskPool *pool;

  pool = g_object_new (TEST_TYPE_RT_POOL, NULL);

  return pool;
}

/*** block c  from ../../../docs/manual/advanced-threads.xml ***/
static GMainLoop* loop;

static void
on_stream_status (GstBus     *bus,
                  GstMessage *message,
                  gpointer    user_data)
{
  GstStreamStatusType type;
  GstElement *owner;
  const GValue *val;
  GstTask *task = NULL;

  gst_message_parse_stream_status (message, &type, &owner);

  val = gst_message_get_stream_status_object (message);

  /* see if we know how to deal with this object */
  if (G_VALUE_TYPE (val) == GST_TYPE_TASK) {
    task = g_value_get_object (val);
  }

  switch (type) {
    case GST_STREAM_STATUS_TYPE_CREATE:
      if (task) {
        GstTaskPool *pool;

        pool = test_rt_pool_new();

        gst_task_set_pool (task, pool);
      }
      break;
    default:
      break;
  }
}

static void
on_error (GstBus     *bus,
          GstMessage *message,
          gpointer    user_data)
{
  g_message ("received ERROR");
  g_main_loop_quit (loop);
}

static void
on_eos (GstBus     *bus,
        GstMessage *message,
        gpointer    user_data)
{
  g_main_loop_quit (loop);
}

int
main (int argc, char *argv[])
{
  GstElement *bin, *fakesrc, *fakesink;
  GstBus *bus;
  GstStateChangeReturn ret;
  
  gst_init (&argc, &argv);

  /* create a new bin to hold the elements */
  bin = gst_pipeline_new ("pipeline");
  g_assert (bin);

  /* create a source */
  fakesrc = gst_element_factory_make ("fakesrc", "fakesrc");
  g_assert (fakesrc);
  g_object_set (fakesrc, "num-buffers", 50, NULL);

  /* and a sink */
  fakesink = gst_element_factory_make ("fakesink", "fakesink");
  g_assert (fakesink);

  /* add objects to the main pipeline */
  gst_bin_add_many (GST_BIN (bin), fakesrc, fakesink, NULL);

  /* link the elements */
  gst_element_link (fakesrc, fakesink);

  loop = g_main_loop_new (NULL, FALSE);

  /* get the bus, we need to install a sync handler */
  bus = gst_pipeline_get_bus (GST_PIPELINE (bin));
  gst_bus_enable_sync_message_emission (bus);
  gst_bus_add_signal_watch (bus);

  g_signal_connect (bus, "sync-message::stream-status",
      (GCallback) on_stream_status, NULL);
  g_signal_connect (bus, "message::error",
      (GCallback) on_error, NULL);
  g_signal_connect (bus, "message::eos",
      (GCallback) on_eos, NULL);

  /* start playing */
  ret = gst_element_set_state (bin, GST_STATE_PLAYING);
  if (ret != GST_STATE_CHANGE_SUCCESS) {
    g_message ("failed to change state");
    return -1;
  }

  /* Run event loop listening for bus messages until EOS or ERROR */
  g_main_loop_run (loop);

  /* stop the bin */
  gst_element_set_state (bin, GST_STATE_NULL);
  gst_object_unref (bus);
  g_main_loop_unref (loop);

  return 0;
}
