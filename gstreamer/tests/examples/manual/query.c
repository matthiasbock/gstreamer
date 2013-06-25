
/*** block a  from ../../../docs/manual/advanced-position.xml ***/
#include <gst/gst.h>

/*** block b  from ../../../docs/manual/advanced-position.xml ***/
static void
my_bus_message_cb (GstBus     *bus,
                   GstMessage *message,
                   gpointer    data)
{
  GMainLoop *loop = (GMainLoop *) data;

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
      break;
  }
}

/*** block c  from ../../../docs/manual/advanced-position.xml ***/
static gboolean
cb_print_position (GstElement *pipeline)
{
  gint64 pos, len;

  if (gst_element_query_position (pipeline, GST_FORMAT_TIME, &pos)
    && gst_element_query_duration (pipeline, GST_FORMAT_TIME, &len)) {
    g_print ("Time: %" GST_TIME_FORMAT " / %" GST_TIME_FORMAT "\r",
	     GST_TIME_ARGS (pos), GST_TIME_ARGS (len));
  }

  /* call me again */
  return TRUE;
}

gint
main (gint   argc,
      gchar *argv[])
{
  GstElement *pipeline;

/*** block d  from ../../../docs/manual/advanced-position.xml ***/
  GstStateChangeReturn ret;
  GMainLoop *loop;
  GError *err = NULL;
  GstBus *bus;
  gchar *l;

  /* init */
  gst_init (&argc, &argv);

  /* args */
  if (argc != 2) {
    g_print ("Usage: %s <filename>\n", argv[0]);
    return -1;
  }

  loop = g_main_loop_new (NULL, FALSE);

  /* build pipeline, the easy way */
  l = g_strdup_printf ("filesrc location=\"%s\" ! oggdemux ! vorbisdec ! "
		       "audioconvert ! audioresample ! alsasink",
		       argv[1]);
  pipeline = gst_parse_launch (l, &err);
  if (pipeline == NULL || err != NULL) {
    g_printerr ("Cannot build pipeline: %s\n", err->message);
    g_error_free (err);
    g_free (l);
    if (pipeline)
      gst_object_unref (pipeline);
    return -1;
  }
  g_free (l);

  bus = gst_pipeline_get_bus (GST_PIPELINE (pipeline));
  gst_bus_add_signal_watch (bus);
  g_signal_connect (bus, "message", G_CALLBACK (my_bus_message_cb), loop);
  gst_object_unref (bus);

  /* play */
  ret = gst_element_set_state (pipeline, GST_STATE_PLAYING);
  if (ret == GST_STATE_CHANGE_FAILURE)
    g_error ("Failed to set pipeline to PLAYING.\n");

/*** block e  from ../../../docs/manual/advanced-position.xml ***/
  /* run pipeline */
  g_timeout_add (200, (GSourceFunc) cb_print_position, pipeline);
  g_main_loop_run (loop);

/*** block f  from ../../../docs/manual/advanced-position.xml ***/
  /* clean up */
  gst_element_set_state (pipeline, GST_STATE_NULL);
  gst_object_unref (GST_OBJECT (pipeline));

  return 0;

/*** block g  from ../../../docs/manual/advanced-position.xml ***/
}
