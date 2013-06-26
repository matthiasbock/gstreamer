/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Define if building universal (internal helper macro) */
/* #undef AC_APPLE_UNIVERSAL_BUILD */

/* Default audio sink */
#define DEFAULT_AUDIOSINK "autoaudiosink"

/* Default audio source */
#define DEFAULT_AUDIOSRC "alsasrc"

/* Default video sink */
#define DEFAULT_VIDEOSINK "autovideosink"

/* Default video source */
#define DEFAULT_VIDEOSRC "v4l2src"

/* Default visualizer */
#define DEFAULT_VISUALIZER "goom"

/* The GIO library directory. */
#define GIO_LIBDIR "/usr/lib/arm-linux-gnueabihf"

/* The GIO modules directory. */
#define GIO_MODULE_DIR "/usr/lib/arm-linux-gnueabihf/gio/modules"

/* GStreamer API Version */
#define GST_API_VERSION "1.0"

/* macro to use to show function name */
#define GST_FUNCTION __PRETTY_FUNCTION__

/* Defined if gcov is enabled to force a rebuild due to config.h changing */
/* #undef GST_GCOV_ENABLED */

/* Default errorlevel to use */
#define GST_LEVEL_DEFAULT GST_LEVEL_ERROR

/* GStreamer license */
#define GST_LICENSE "LGPL"

/* The struct packing used for OpenMAX structures */
#define GST_OMX_STRUCT_PACKING 4

/* package name in plugins */
#define GST_PACKAGE_NAME "GStreamer OpenMAX Plug-ins git"

/* package origin */
#define GST_PACKAGE_ORIGIN "Unknown package origin"

/* GStreamer package release date/time for plugins as YYYY-MM-DD */
#define GST_PACKAGE_RELEASE_DATETIME "2013-06-25T17:42Z"

/* Define if static plugins should be built */
/* #undef GST_PLUGIN_BUILD_STATIC */

/* Define if the target CPU is an Alpha */
/* #undef HAVE_CPU_ALPHA */

/* Define if the target CPU is an ARM */
#define HAVE_CPU_ARM 1

/* Define if the target CPU is a CRIS */
/* #undef HAVE_CPU_CRIS */

/* Define if the target CPU is a CRISv32 */
/* #undef HAVE_CPU_CRISV32 */

/* Define if the target CPU is a HPPA */
/* #undef HAVE_CPU_HPPA */

/* Define if the target CPU is an x86 */
/* #undef HAVE_CPU_I386 */

/* Define if the target CPU is a IA64 */
/* #undef HAVE_CPU_IA64 */

/* Define if the target CPU is a M68K */
/* #undef HAVE_CPU_M68K */

/* Define if the target CPU is a MIPS */
/* #undef HAVE_CPU_MIPS */

/* Define if the target CPU is a PowerPC */
/* #undef HAVE_CPU_PPC */

/* Define if the target CPU is a 64 bit PowerPC */
/* #undef HAVE_CPU_PPC64 */

/* Define if the target CPU is a S390 */
/* #undef HAVE_CPU_S390 */

/* Define if the target CPU is a SPARC */
/* #undef HAVE_CPU_SPARC */

/* Define if the target CPU is a x86_64 */
/* #undef HAVE_CPU_X86_64 */

/* Define to 1 if you have the declaration of `OMX_VIDEO_CodingTheora', and to
   0 if you don't. */
#define HAVE_DECL_OMX_VIDEO_CODINGTHEORA 0

/* Define to 1 if you have the declaration of `OMX_VIDEO_CodingVP8', and to 0
   if you don't. */
#define HAVE_DECL_OMX_VIDEO_CODINGVP8 0

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to enable building of experimental plug-ins. */
/* #undef HAVE_EXPERIMENTAL */

/* defined if the compiler implements __func__ */
#define HAVE_FUNC 1

/* defined if the compiler implements __FUNCTION__ */
#define HAVE_FUNCTION 1

/* Have gstreamer-egl */
#define HAVE_GST_EGL 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* defined if the compiler implements __PRETTY_FUNCTION__ */
#define HAVE_PRETTY_FUNCTION 1

/* Define if RDTSC is available */
/* #undef HAVE_RDTSC */

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* OpenMAX IL has Theora support */
/* #undef HAVE_THEORA */

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define if valgrind should be used */
/* #undef HAVE_VALGRIND */

/* OpenMAX IL has VP8 support */
/* #undef HAVE_VP8 */

/* the host CPU */
#define HOST_CPU "armv6l"

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#define LT_OBJDIR ".libs/"

/* Define to 1 if your C compiler doesn't accept -c and -o together. */
/* #undef NO_MINUS_C_MINUS_O */

/* Name of package */
#define PACKAGE "gst-omx"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "http://bugzilla.gnome.org/enter_bug.cgi?product=GStreamer"

/* Define to the full name of this package. */
#define PACKAGE_NAME "GStreamer OpenMAX Plug-ins"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "GStreamer OpenMAX Plug-ins 1.0.0.1"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "gst-omx"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.0.0.1"

/* directory where plugins are located */
#define PLUGINDIR "/usr/local/lib/gstreamer-1.0"

/* The size of `char', as computed by sizeof. */
/* #undef SIZEOF_CHAR */

/* The size of `int', as computed by sizeof. */
/* #undef SIZEOF_INT */

/* The size of `long', as computed by sizeof. */
/* #undef SIZEOF_LONG */

/* The size of `short', as computed by sizeof. */
/* #undef SIZEOF_SHORT */

/* The size of `void*', as computed by sizeof. */
/* #undef SIZEOF_VOIDP */

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* the target CPU */
#define TARGET_CPU "armv6l"

/* Use Bellagio OpenMAX IL target */
/* #undef USE_OMX_TARGET_BELLAGIO */

/* Use generic OpenMAX IL target */
/* #undef USE_OMX_TARGET_GENERIC */

/* Use RPi OpenMAX IL target */
#define USE_OMX_TARGET_RPI 1

/* Version number of package */
#define VERSION "1.0.0.1"

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
/* #  undef WORDS_BIGENDIAN */
# endif
#endif

/* Enable large inode numbers on Mac OS X 10.5.  */
#ifndef _DARWIN_USE_64_BIT_INODE
# define _DARWIN_USE_64_BIT_INODE 1
#endif

/* Number of bits in a file offset, on hosts where this is settable. */
#define _FILE_OFFSET_BITS 64

/* Define for large files, on AIX-style hosts. */
/* #undef _LARGE_FILES */
