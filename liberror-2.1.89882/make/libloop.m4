AC_DEFUN([AM_WITH_LIBLOOP], [
   AC_ARG_WITH(libloop,
[  --with-libloop=PREFIX   defines the path where libloop is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_LANG_CPLUSPLUS
   HAVE_LIBLOOP=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(loop, main,
   [
       HAVE_LIBLOOP=1
       AC_DEFINE(HAVE_LIBLOOP, 1, [Whether Loop library is available.])
       DEFINES="$DEFINES HAVE_LIBLOOP=1"
       LIBS="-lloop $LIBS"
       WIN_LIBS="loop $WIN_LIBS"
   ],
   [
       if test "x$1" = xoptional; then
           true
       else
           AC_MSG_ERROR(This library is needed.)
       fi
   ])
   AC_LANG_C
   MK_CONDITION([LIBLOOP], [test x"$HAVE_LIBLOOP" = x1])
])
