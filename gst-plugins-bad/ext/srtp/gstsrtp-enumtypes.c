


#include "gstsrtp-enumtypes.h"

#include "gstsrtpdec.h" 
#include "gstsrtpenc.h"

/* enumerations from "gstsrtpenc.h" */
GType
gst_srtp_cipher_type_get_type (void)
{
  static volatile gsize g_define_type_id__volatile = 0;
  if (g_once_init_enter (&g_define_type_id__volatile)) {
    static const GEnumValue values[] = {
      { GST_SRTP_CIPHER_NULL, "GST_SRTP_CIPHER_NULL", "null" },
      { GST_SRTP_CIPHER_AES_128_ICM, "GST_SRTP_CIPHER_AES_128_ICM", "aes-128-icm" },
      { 0, NULL, NULL }
    };
    GType g_define_type_id = g_enum_register_static ("GstSrtpCipherType", values);
    g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
  }
  return g_define_type_id__volatile;
}
GType
gst_srtp_auth_type_get_type (void)
{
  static volatile gsize g_define_type_id__volatile = 0;
  if (g_once_init_enter (&g_define_type_id__volatile)) {
    static const GEnumValue values[] = {
      { GST_SRTP_AUTH_NULL, "GST_SRTP_AUTH_NULL", "null" },
      { GST_SRTP_AUTH_HMAC_SHA1_32, "GST_SRTP_AUTH_HMAC_SHA1_32", "hmac-sha1-32" },
      { GST_SRTP_AUTH_HMAC_SHA1_80, "GST_SRTP_AUTH_HMAC_SHA1_80", "hmac-sha1-80" },
      { 0, NULL, NULL }
    };
    GType g_define_type_id = g_enum_register_static ("GstSrtpAuthType", values);
    g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
  }
  return g_define_type_id__volatile;
}



