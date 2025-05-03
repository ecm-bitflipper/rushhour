AC_DEFUN([AM_WITH_LIBATTRPROP], [
   AC_ARG_WITH(libattrprop,
[  --with-libattrprop=PREFIX defines the path where libattrprop is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_LANG_CPLUSPLUS
   HAVE_LIBATTRPROP=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(attrprop, attr_init,
   [
       HAVE_LIBATTRPROP=1
       AC_DEFINE(HAVE_LIBATTRPROP, 1, [Whether attrprop library is available.])
       DEFINES="$DEFINES HAVE_LIBATTRPROP=1"
       LIBS="-lattrprop $LIBS"
       WIN_LIBS="attrprop $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   AC_LANG_C
   MK_CONDITION([LIBATTRPROP], [test x"$HAVE_LIBATTRPROP" = x1])
])
