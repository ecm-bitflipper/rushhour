AC_DEFUN([AM_WITH_LIBAT], [
   AC_ARG_WITH(libat,
[  --with-libat=PREFIX     defines the path where libat is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_LANG_CPLUSPLUS
   HAVE_LIBAT=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(at, at_expand,
   [
       HAVE_LIBAT=1
       AC_DEFINE(HAVE_LIBAT, 1, [Whether @-expansion library is available.])
       DEFINES="$DEFINES HAVE_LIBAT=1"
       LIBS="-lat $LIBS"
       WIN_LIBS="at $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   AC_LANG_C
   MK_CONDITION([LIBAT], [test x"$HAVE_LIBAT" = x1])
])
