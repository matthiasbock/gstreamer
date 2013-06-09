dnl AG_GST_PLUGIN_DOCS([MINIMUM-GTK-DOC-VERSION],[MINIMUM-PYTHON-VERSION])
dnl
dnl checks for prerequisites for the common/mangle-tmpl.py script
dnl used when building the plugin documentation

AC_DEFUN([AG_GST_PLUGIN_DOCS],
[
  AC_BEFORE([GTK_DOC_CHECK],[$0])dnl check for gtk-doc first
  AC_BEFORE([AS_PATH_PYTHON],[$1])dnl find python first

  build_plugin_docs=no
  AC_MSG_CHECKING([whether to build plugin documentation])
  if test x$enable_gtk_doc = xyes; then
    build_plugin_docs=yes
    AC_MSG_RESULT([yes])
  else
    AC_MSG_RESULT([no (gtk-doc disabled or not available)])
  fi

  AM_CONDITIONAL(ENABLE_PLUGIN_DOCS, test x$build_plugin_docs = xyes)
])
