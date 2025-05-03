AC_DEFUN([AM_WITH_LIBFRACTION], [
   AC_ARG_WITH(libfraction,
[  --with-libfraction=PREFIX defines the path where libfraction is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_LANG_CPLUSPLUS
   HAVE_LIBFRACTION=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(fraction, frac_init,
   [
       HAVE_LIBFRACTION=1
       AC_DEFINE(HAVE_LIBFRACTION, 1, [Whether fraction library is available.])
       DEFINES="$DEFINES HAVE_LIBFRACTION=1"
       LIBS="-lfraction $LIBS"
       WIN_LIBS="fraction $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   AC_LANG_C
   MK_CONDITION([LIBFRACTION], [test x"$HAVE_LIBFRACTION" = x1])
])
