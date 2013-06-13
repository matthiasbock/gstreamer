/* GStreamer
 * Copyright (C) <2006> Wim Taymans <wim.taymans@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <gst/rtp/gstrtpbuffer.h>

#include <string.h>
#include "gstrtpmpvdepay.h"

GST_DEBUG_CATEGORY_STATIC (rtpmpvdepay_debug);
#define GST_CAT_DEFAULT (rtpmpvdepay_debug)

/* FIXME, we set the mpeg version to 2, we should ideally be looking at contents
 * of the stream to figure out the version */
static GstStaticPadTemplate gst_rtp_mpv_depay_src_template =
GST_STATIC_PAD_TEMPLATE ("src",
    GST_PAD_SRC,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS
    ("video/mpeg, mpegversion = (int) 2, systemstream = (boolean) FALSE")
    );

static GstStaticPadTemplate gst_rtp_mpv_depay_sink_template =
    GST_STATIC_PAD_TEMPLATE ("sink",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS ("application/x-rtp, "
        "media = (string) \"video\", "
        "payload = (int) " GST_RTP_PAYLOAD_DYNAMIC_STRING ", "
        "clock-rate = (int) 90000, " "encoding-name = (string) \"MPV\";"
        "application/x-rtp, "
        "media = (string) \"video\", "
        "payload = (int) " GST_RTP_PAYLOAD_MPV_STRING ", "
        "clock-rate = (int) 90000")
    );

GST_BOILERPLATE (GstRtpMPVDepay, gst_rtp_mpv_depay, GstBaseRTPDepayload,
    GST_TYPE_BASE_RTP_DEPAYLOAD);

static gboolean gst_rtp_mpv_depay_setcaps (GstBaseRTPDepayload * depayload,
    GstCaps * caps);
static GstBuffer *gst_rtp_mpv_depay_process (GstBaseRTPDepayload * depayload,
    GstBuffer * buf);

static void
gst_rtp_mpv_depay_base_init (gpointer klass)
{
  GstElementClass *element_class = GST_ELEMENT_CLASS (klass);

  gst_element_class_add_static_pad_template (element_class,
      &gst_rtp_mpv_depay_src_template);
  gst_element_class_add_static_pad_template (element_class,
      &gst_rtp_mpv_depay_sink_template);

  gst_element_class_set_details_simple (element_class,
      "RTP MPEG video depayloader", "Codec/Depayloader/Network/RTP",
      "Extracts MPEG video from RTP packets (RFC 2250)",
      "Wim Taymans <wim.taymans@gmail.com>");
}

static void
gst_rtp_mpv_depay_class_init (GstRtpMPVDepayClass * klass)
{
  GstBaseRTPDepayloadClass *gstbasertpdepayload_class;

  gstbasertpdepayload_class = (GstBaseRTPDepayloadClass *) klass;

  gstbasertpdepayload_class->set_caps = gst_rtp_mpv_depay_setcaps;
  gstbasertpdepayload_class->process = gst_rtp_mpv_depay_process;

  GST_DEBUG_CATEGORY_INIT (rtpmpvdepay_debug, "rtpmpvdepay", 0,
      "MPEG Video RTP Depayloader");
}

static void
gst_rtp_mpv_depay_init (GstRtpMPVDepay * rtpmpvdepay,
    GstRtpMPVDepayClass * klass)
{
  /* needed because of GST_BOILERPLATE */
}

static gboolean
gst_rtp_mpv_depay_setcaps (GstBaseRTPDepayload * depayload, GstCaps * caps)
{
  GstStructure *structure;
  gint clock_rate;
  GstCaps *outcaps;
  gboolean res;

  structure = gst_caps_get_structure (caps, 0);

  if (!gst_structure_get_int (structure, "clock-rate", &clock_rate))
    clock_rate = 90000;         /* default */
  depayload->clock_rate = clock_rate;

  outcaps = gst_caps_new_simple ("video/mpeg",
      "mpegversion", G_TYPE_INT, 2,
      "systemstream", G_TYPE_BOOLEAN, FALSE, NULL);
  res = gst_pad_set_caps (depayload->srcpad, outcaps);
  gst_caps_unref (outcaps);

  return res;
}

static GstBuffer *
gst_rtp_mpv_depay_process (GstBaseRTPDepayload * depayload, GstBuffer * buf)
{
  GstRtpMPVDepay *rtpmpvdepay;
  GstBuffer *outbuf;

  rtpmpvdepay = GST_RTP_MPV_DEPAY (depayload);

  {
    gint payload_len, payload_header;
    guint8 *payload;
    guint8 T;

    payload_len = gst_rtp_buffer_get_payload_len (buf);
    payload = gst_rtp_buffer_get_payload (buf);
    payload_header = 0;

    if (payload_len <= 4)
      goto empty_packet;

    /* 3.4 MPEG Video-specific header
     *
     *  0                   1                   2                   3
     *  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
     * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
     * |    MBZ  |T|         TR        | |N|S|B|E|  P  | | BFC | | FFC |
     * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
     *                                  AN              FBV     FFV
     */
    T = (payload[0] & 0x04);

    payload_len -= 4;
    payload_header += 4;
    payload += 4;

    if (T) {
      /* 
       * 3.4.1 MPEG-2 Video-specific header extension
       *
       *  0                   1                   2                   3
       *  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
       * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
       * |X|E|f_[0,0]|f_[0,1]|f_[1,0]|f_[1,1]| DC| PS|T|P|C|Q|V|A|R|H|G|D|
       * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
       */
      if (payload_len <= 4)
        goto empty_packet;

      payload_len -= 4;
      payload_header += 4;
      payload += 4;
    }

    outbuf = gst_rtp_buffer_get_payload_subbuffer (buf, payload_header, -1);

    if (outbuf) {
      GST_DEBUG_OBJECT (rtpmpvdepay,
          "gst_rtp_mpv_depay_chain: pushing buffer of size %d",
          GST_BUFFER_SIZE (outbuf));
    }

    return outbuf;
  }

  return NULL;

  /* ERRORS */
empty_packet:
  {
    GST_ELEMENT_WARNING (rtpmpvdepay, STREAM, DECODE,
        (NULL), ("Empty payload."));
    return NULL;
  }
}

gboolean
gst_rtp_mpv_depay_plugin_init (GstPlugin * plugin)
{
  return gst_element_register (plugin, "rtpmpvdepay",
      GST_RANK_SECONDARY, GST_TYPE_RTP_MPV_DEPAY);
}