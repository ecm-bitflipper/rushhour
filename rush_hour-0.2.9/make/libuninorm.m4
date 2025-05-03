AC_DEFUN([AM_WITH_LIBUNINORM], [
   AC_ARG_WITH(libuninorm,
[  --with-libuninorm=PREFIX   defines the path where libuninorm is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_LANG_CPLUSPLUS
   HAVE_LIBUNINORM=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(uninorm, unicode_combining_class,
   [
       HAVE_LIBUNINORM=1
       AC_DEFINE(HAVE_LIBUNINORM, 1, [Whether uninorm library is available.])
       DEFINES="$DEFINES HAVE_LIBUNINORM=1"
       LIBS="-luninorm $LIBS"
       WIN_LIBS="uninorm $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   AC_LANG_C
   ifdef([MK_CONDITION], [MK_CONDITION([LIBUNINORM], [test x"$HAVE_LIBUNINORM" = x1])])
])
