dnl check for a minimum version of GLib

dnl AG_GST_GLIB_CHECK([minimum-version-required])

AC_DEFUN([AG_GST_GLIB_CHECK],
[
  AC_REQUIRE([AS_NANO])

  dnl Minimum required version of GLib
  GLIB_REQ=[$1]
  if test "x$GLIB_REQ" = "x"
  then
    AC_MSG_ERROR([Please specify a required version for GLib 2.0])
  fi
  AC_SUBST(GLIB_REQ)

  dnl Check for glib with everything
  AG_GST_PKG_CHECK_MODULES(GLIB,
    glib-2.0 >= $GLIB_REQ gobject-2.0 gthread-2.0 gmodule-no-export-2.0)

  if test "x$HAVE_GLIB" = "xno"; then
    AC_MSG_ERROR([This package requires GLib >= $GLIB_REQ to compile.])
  fi

  dnl Add define to tell GLib that threading is always enabled within GStreamer
  dnl code (optimisation, bypasses checks if the threading system is enabled
  dnl when using threading primitives)
  GLIB_EXTRA_CFLAGS="$GLIB_EXTRA_CFLAGS -DG_THREADS_MANDATORY"

  dnl Define G_DISABLE_DEPRECATED for GIT versions
  if test "x$PACKAGE_VERSION_NANO" = "x1"; then
    GLIB_EXTRA_CFLAGS="$GLIB_EXTRA_CFLAGS -DG_DISABLE_DEPRECATED"
  fi

  AC_ARG_ENABLE(gobject-cast-checks,
    AS_HELP_STRING([--enable-gobject-cast-checks[=@<:@no/auto/yes@:>@]],
      [Enable GObject cast checks]),, 
    [enable_gobject_cast_checks=auto])

  if test "x$enable_gobject_cast_checks" = "xauto"; then
    dnl For releases, turn off the cast checks
    if test "x$PACKAGE_VERSION_NANO" = "x1"; then
      enable_gobject_cast_checks=yes
    else
      enable_gobject_cast_checks=no
    fi
  fi

  if test "x$enable_gobject_cast_checks" = "xno"; then
    GLIB_EXTRA_CFLAGS="$GLIB_EXTRA_CFLAGS -DG_DISABLE_CAST_CHECKS"
  fi

  AC_ARG_ENABLE(glib-asserts,
    AS_HELP_STRING([--enable-glib-asserts[=@<:@no/auto/yes@:>@]],
      [Enable GLib assertion]),, 
    [enable_glib_assertions=auto])

  if test "x$enable_glib_assertions" = "xauto"; then
    dnl For releases, turn off the assertions
    if test "x$PACKAGE_VERSION_NANO" = "x1"; then
      enable_glib_assertions=yes
    else
      enable_glib_assertions=no
    fi
  fi

  if test "x$enable_glib_assertions" = "xno"; then
    GLIB_EXTRA_CFLAGS="$GLIB_EXTRA_CFLAGS -DG_DISABLE_ASSERT"
  fi

  dnl for the poor souls who for example have glib in /usr/local
  AS_SCRUB_INCLUDE(GLIB_CFLAGS)
])
