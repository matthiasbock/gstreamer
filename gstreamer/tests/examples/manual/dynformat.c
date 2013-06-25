
/*** block  from ../../../docs/manual/advanced-dataaccess.xml ***/
#include <stdlib.h>

#include <gst/gst.h>

#define MAX_ROUND 100

int
main (int argc, char **argv)
{
  GstElement *pipe, *filter;
  GstCaps *caps;
  gint width, height;
  gint xdir, ydir;
  gint round;
  GstMessage *message;

  gst_init (&argc, &argv);

  pipe = gst_parse_launch_full ("videotestsrc ! capsfilter name=filter ! "
             "ximagesink", NULL, GST_PARSE_FLAG_NONE, NULL);
  g_assert (pipe != NULL);

  filter = gst_bin_get_by_name (GST_BIN (pipe), "filter");
  g_assert (filter);

  width = 320;
  height = 240;
  xdir = ydir = -10;

  for (round = 0; round < MAX_ROUND; round++) {
    gchar *capsstr;
    g_print ("resize to %dx%d (%d/%d)   \r", width, height, round, MAX_ROUND);

    /* we prefer our fixed width and height but allow other dimensions to pass
     * as well */
    capsstr = g_strdup_printf ("video/x-raw, width=(int)%d, height=(int)%d",
        width, height);

    caps = gst_caps_from_string (capsstr);
    g_free (capsstr);
    g_object_set (filter, "caps", caps, NULL);
    gst_caps_unref (caps);

    if (round == 0)
      gst_element_set_state (pipe, GST_STATE_PLAYING);

    width += xdir;
    if (width >= 320)
      xdir = -10;
    else if (width < 200)
      xdir = 10;

    height += ydir;
    if (height >= 240)
      ydir = -10;
    else if (height < 150)
      ydir = 10;

    message =
        gst_bus_poll (GST_ELEMENT_BUS (pipe), GST_MESSAGE_ERROR,
        50 * GST_MSECOND);
    if (message) {
      g_print ("got error           \n");

      gst_message_unref (message);
    }
  }
  g_print ("done                    \n");

  gst_object_unref (filter);
  gst_element_set_state (pipe, GST_STATE_NULL);
  gst_object_unref (pipe);

  return 0;
}
