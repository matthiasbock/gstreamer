
#ifndef __gst_tcp_marshal_MARSHAL_H__
#define __gst_tcp_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* VOID:STRING,UINT (gsttcp-marshal.list:1) */
extern void gst_tcp_marshal_VOID__STRING_UINT (GClosure     *closure,
                                               GValue       *return_value,
                                               guint         n_param_values,
                                               const GValue *param_values,
                                               gpointer      invocation_hint,
                                               gpointer      marshal_data);

/* VOID:OBJECT,ENUM (gsttcp-marshal.list:2) */
extern void gst_tcp_marshal_VOID__OBJECT_ENUM (GClosure     *closure,
                                               GValue       *return_value,
                                               guint         n_param_values,
                                               const GValue *param_values,
                                               gpointer      invocation_hint,
                                               gpointer      marshal_data);

/* VOID:OBJECT,ENUM,ENUM,UINT64,ENUM,UINT64 (gsttcp-marshal.list:3) */
extern void gst_tcp_marshal_VOID__OBJECT_ENUM_ENUM_UINT64_ENUM_UINT64 (GClosure     *closure,
                                                                       GValue       *return_value,
                                                                       guint         n_param_values,
                                                                       const GValue *param_values,
                                                                       gpointer      invocation_hint,
                                                                       gpointer      marshal_data);

/* BOXED:OBJECT (gsttcp-marshal.list:4) */
extern void gst_tcp_marshal_BOXED__OBJECT (GClosure     *closure,
                                           GValue       *return_value,
                                           guint         n_param_values,
                                           const GValue *param_values,
                                           gpointer      invocation_hint,
                                           gpointer      marshal_data);

/* VOID:INT,ENUM,INT,UINT64,INT,UINT64 (gsttcp-marshal.list:5) */
extern void gst_tcp_marshal_VOID__INT_ENUM_INT_UINT64_INT_UINT64 (GClosure     *closure,
                                                                  GValue       *return_value,
                                                                  guint         n_param_values,
                                                                  const GValue *param_values,
                                                                  gpointer      invocation_hint,
                                                                  gpointer      marshal_data);

/* VOID:INT (gsttcp-marshal.list:6) */
#define gst_tcp_marshal_VOID__INT	g_cclosure_marshal_VOID__INT

/* VOID:INT,ENUM (gsttcp-marshal.list:7) */
extern void gst_tcp_marshal_VOID__INT_ENUM (GClosure     *closure,
                                            GValue       *return_value,
                                            guint         n_param_values,
                                            const GValue *param_values,
                                            gpointer      invocation_hint,
                                            gpointer      marshal_data);

/* BOXED:INT (gsttcp-marshal.list:8) */
extern void gst_tcp_marshal_BOXED__INT (GClosure     *closure,
                                        GValue       *return_value,
                                        guint         n_param_values,
                                        const GValue *param_values,
                                        gpointer      invocation_hint,
                                        gpointer      marshal_data);

G_END_DECLS

#endif /* __gst_tcp_marshal_MARSHAL_H__ */

