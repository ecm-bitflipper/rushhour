
AC_DEFUN([AM_WITH_LIBPNG], [
   AC_ARG_WITH(libpng,
[  --with-libpng=PREFIX     defines the path where libpng is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
           PNGDIR=${withval}
       ],
       [
           CPPFLAGS="$CPPFLAGS -I${PNGDIR}/include"
           LDFLAGS="$LDFLAGS -L${PNGDIR}/lib"
       ])
   AC_LANG_CPLUSPLUS
   AC_SUBST(PNGDIR)
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(png, main,
   [
       AC_DEFINE(HAVE_LIBPNG, 1, [Whether libpng is available.])
       DEFINES="$DEFINES HAVE_LIBPNG=1"
       LIBS="-lpng $LIBS"
       WIN_INC="/I..\\libpng $WIN_INC"
       WIN_LIBS="libpng $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   AC_LANG_C
])
