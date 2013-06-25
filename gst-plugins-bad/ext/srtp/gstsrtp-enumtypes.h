


#ifndef __GST_SRTP_ENUM_TYPES_H__
#define __GST_SRTP_ENUM_TYPES_H__

#include <glib-object.h>

G_BEGIN_DECLS

/* enumerations from "gstsrtpenc.h" */
GType gst_srtp_cipher_type_get_type (void);
#define GST_TYPE_SRTP_CIPHER_TYPE (gst_srtp_cipher_type_get_type())
GType gst_srtp_auth_type_get_type (void);
#define GST_TYPE_SRTP_AUTH_TYPE (gst_srtp_auth_type_get_type())
G_END_DECLS

#endif /* __GST_SRTP_ENUM_TYPES_H__ */



