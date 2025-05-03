AC_DEFUN([AM_WITH_LIBXAI], [
   AC_ARG_WITH(libxai,
[  --with-libxai=PREFIX      defines the path where libxai is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_LANG_CPLUSPLUS
   HAVE_LIBXAI=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(xai, xai_init,
   [
       HAVE_LIBXAI=1
       AC_DEFINE(HAVE_LIBXAI, 1, [Whether xai library is available.])
       DEFINES="$DEFINES HAVE_LIBXAI=1"
       LIBS="-lxai $LIBS"
       WIN_LIBS="xai $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   AC_LANG_C
   MK_CONDITION([LIBXAI], [test x"$HAVE_LIBXAI" = x1])
])
