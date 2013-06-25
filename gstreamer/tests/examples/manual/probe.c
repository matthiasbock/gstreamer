
/*** block  from ../../../docs/manual/advanced-dataaccess.xml ***/
#include <gst/gst.h>

static GstPadProbeReturn
cb_have_data (GstPad          *pad,
              GstPadProbeInfo *info,
              gpointer         user_data)
{
  gint x, y;
  GstMapInfo map;
  guint16 *ptr, t;
  GstBuffer *buffer;

  buffer = GST_PAD_PROBE_INFO_BUFFER (info);

  buffer = gst_buffer_make_writable (buffer);
  
  gst_buffer_map (buffer, &map, GST_MAP_WRITE);

  ptr = (guint16 *) map.data;
  /* invert data */
  for (y = 0; y < 288; y++) {
    for (x = 0; x < 384 / 2; x++) {
      t = ptr[384 - 1 - x];
      ptr[384 - 1 - x] = ptr[x];
      ptr[x] = t;
    }
    ptr += 384;
  }
  gst_buffer_unmap (buffer, &map);

  GST_PAD_PROBE_INFO_DATA (info) = buffer;

  return GST_PAD_PROBE_OK;
}

gint
main (gint   argc,
      gchar *argv[])
{
  GMainLoop *loop;
  GstElement *pipeline, *src, *sink, *filter, *csp;
  GstCaps *filtercaps;
  GstPad *pad;

  /* init GStreamer */
  gst_init (&argc, &argv);
  loop = g_main_loop_new (NULL, FALSE);

  /* build */
  pipeline = gst_pipeline_new ("my-pipeline");
  src = gst_element_factory_make ("videotestsrc", "src");
  if (src == NULL)
    g_error ("Could not create 'videotestsrc' element");

  filter = gst_element_factory_make ("capsfilter", "filter");
  g_assert (filter != NULL); /* should always exist */

  csp = gst_element_factory_make ("videoconvert", "csp");
  if (csp == NULL)
    g_error ("Could not create 'videoconvert' element");

  sink = gst_element_factory_make ("xvimagesink", "sink");
  if (sink == NULL) {
    sink = gst_element_factory_make ("ximagesink", "sink");
    if (sink == NULL)
      g_error ("Could not create neither 'xvimagesink' nor 'ximagesink' element");
  }

  gst_bin_add_many (GST_BIN (pipeline), src, filter, csp, sink, NULL);
  gst_element_link_many (src, filter, csp, sink, NULL);
  filtercaps = gst_caps_new_simple ("video/x-raw",
			   "format", G_TYPE_STRING, "RGB16",
			   "width", G_TYPE_INT, 384,
			   "height", G_TYPE_INT, 288,
			   "framerate", GST_TYPE_FRACTION, 25, 1,
			   NULL);
  g_object_set (G_OBJECT (filter), "caps", filtercaps, NULL);
  gst_caps_unref (filtercaps);

  pad = gst_element_get_static_pad (src, "src");
  gst_pad_add_probe (pad, GST_PAD_PROBE_TYPE_BUFFER,
      (GstPadProbeCallback) cb_have_data, NULL, NULL);
  gst_object_unref (pad);

  /* run */
  gst_element_set_state (pipeline, GST_STATE_PLAYING);

  /* wait until it's up and running or failed */
  if (gst_element_get_state (pipeline, NULL, NULL, -1) == GST_STATE_CHANGE_FAILURE) {
    g_error ("Failed to go into PLAYING state");
  }

  g_print ("Running ...\n");
  g_main_loop_run (loop);

  /* exit */
  gst_element_set_state (pipeline, GST_STATE_NULL);
  gst_object_unref (pipeline);

  return 0;
}
