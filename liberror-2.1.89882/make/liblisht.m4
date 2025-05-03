AC_DEFUN([AM_WITH_LIBLISHT], [
   AC_ARG_WITH(liblisht,
[  --with-liblisht=PREFIX defines the path where liblisht is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_LANG_CPLUSPLUS
   HAVE_LIBLISHT=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(lisht, li_init,
   [
       HAVE_LIBLISHT=1
       AC_DEFINE(HAVE_LIBLISHT, 1, [Whether Lisht library is available.])
       DEFINES="$DEFINES HAVE_LIBLISHT=1"
       LIBS="-llisht $LIBS"
       WIN_LIBS="lisht $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   AC_LANG_C
   MK_CONDITION([LIBLISHT], [test x"$HAVE_LIBLISHT" = x1])
])
