/*
 * Opus Depayloader Gst Element
 *
 *   @author: Danilo Cesar Lemes de Paula <danilo.eu@gmail.com>
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

#ifndef __GST_RTP_OPUS_DEPAY_H__
#define __GST_RTP_OPUS_DEPAY_H__

#include <gst/gst.h>
#include <gst/rtp/gstbasertpdepayload.h>

G_BEGIN_DECLS typedef struct _GstRTPOpusDepay GstRTPOpusDepay;
typedef struct _GstRTPOpusDepayClass GstRTPOpusDepayClass;

#define GST_TYPE_RTP_OPUS_DEPAY \
  (gst_rtp_opus_depay_get_type())
#define GST_RTP_OPUS_DEPAY(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_RTP_OPUS_DEPAY,GstRTPOpusDepay))
#define GST_RTP_OPUS_DEPAY_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_RTP_OPUS_DEPAY,GstRTPOpusDepayClass))
#define GST_IS_RTP_OPUS_DEPAY(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_RTP_OPUS_DEPAY))
#define GST_IS_RTP_OPUS_DEPAY_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_RTP_OPUS_DEPAY))


struct _GstRTPOpusDepay
{
  GstBaseRTPDepayload depayload;

};

struct _GstRTPOpusDepayClass
{
  GstBaseRTPDepayloadClass parent_class;
};

GType gst_rtp_opus_depay_get_type (void);

G_END_DECLS
#endif /* __GST_RTP_OPUS_DEPAY_H__ */