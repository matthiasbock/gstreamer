plugin_LTLIBRARIES = libgstcelt.la

libgstcelt_la_SOURCES = gstcelt.c gstceltdec.c gstceltenc.c
libgstcelt_la_CFLAGS = -DGST_USE_UNSTABLE_API \
	$(GST_PLUGINS_BASE_CFLAGS) \
	$(GST_CFLAGS) \
	$(CELT_CFLAGS)
libgstcelt_la_LIBADD = \
	$(GST_PLUGINS_BASE_LIBS) \
	-lgstaudio-$(GST_API_VERSION) -lgsttag-$(GST_API_VERSION) \
	$(GST_BASE_LIBS) \
	$(GST_LIBS) \
	$(CELT_LIBS)
libgstcelt_la_LDFLAGS = $(GST_PLUGIN_LDFLAGS) $(LIBM)
libgstcelt_la_LIBTOOLFLAGS = $(GST_PLUGIN_LIBTOOLFLAGS)

noinst_HEADERS = gstceltenc.h gstceltdec.h 
