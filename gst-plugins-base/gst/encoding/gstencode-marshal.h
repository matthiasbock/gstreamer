
#ifndef __gst_encode_marshal_MARSHAL_H__
#define __gst_encode_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* OBJECT:BOXED (gstencode-marshal.list:1) */
extern void gst_encode_marshal_OBJECT__BOXED (GClosure     *closure,
                                              GValue       *return_value,
                                              guint         n_param_values,
                                              const GValue *param_values,
                                              gpointer      invocation_hint,
                                              gpointer      marshal_data);

G_END_DECLS

#endif /* __gst_encode_marshal_MARSHAL_H__ */

