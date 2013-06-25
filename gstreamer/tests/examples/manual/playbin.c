
/*** block a  from ../../../docs/manual/highlevel-playback.xml ***/
#include <gst/gst.h>

/*** block b  from ../../../docs/manual/highlevel-playback.xml ***/
static gboolean
my_bus_callback (GstBus     *bus,
		 GstMessage *message,
		 gpointer    data)
{
  GMainLoop *loop = data;

  switch (GST_MESSAGE_TYPE (message)) {
    case GST_MESSAGE_ERROR: {
      GError *err;
      gchar *debug;

      gst_message_parse_error (message, &err, &debug);
      g_print ("Error: %s\n", err->message);
      g_error_free (err);
      g_free (debug);

      g_main_loop_quit (loop);
      break;
    }
    case GST_MESSAGE_EOS:
      /* end-of-stream */
      g_main_loop_quit (loop);
      break;
    default:
      /* unhandled message */
      break;
  }

  /* remove message from the queue */
  return TRUE;
}

/*** block c  from ../../../docs/manual/highlevel-playback.xml ***/
gint
main (gint   argc,
      gchar *argv[])
{
  GMainLoop *loop;
  GstElement *play;
  GstBus *bus;

  /* init GStreamer */
  gst_init (&argc, &argv);
  loop = g_main_loop_new (NULL, FALSE);

  /* make sure we have a URI */
  if (argc != 2) {
    g_print ("Usage: %s <URI>\n", argv[0]);
    return -1;
  }

  /* set up */
  play = gst_element_factory_make ("playbin", "play");
  g_object_set (G_OBJECT (play), "uri", argv[1], NULL);

  bus = gst_pipeline_get_bus (GST_PIPELINE (play));
  gst_bus_add_watch (bus, my_bus_callback, loop);
  gst_object_unref (bus);

  gst_element_set_state (play, GST_STATE_PLAYING);

  /* now run */
  g_main_loop_run (loop);

  /* also clean up */
  gst_element_set_state (play, GST_STATE_NULL);
  gst_object_unref (GST_OBJECT (play));

  return 0;
}
