AC_DEFUN([AM_WITH_LIBLISP], [
   AC_ARG_WITH(liblisp,
[  --with-liblisp=PREFIX   defines the path where liblisp is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_LANG_CPLUSPLUS
   HAVE_LIBLISP=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(lisp, lisp_init,
   [
       HAVE_LIBLISP=1
       AC_DEFINE(HAVE_LIBLISP, 1, [Whether Lisp library is available.])
       DEFINES="$DEFINES HAVE_LIBLISP=1"
       LIBS="-llisp $LIBS"
       WIN_LIBS="lisp $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   AC_LANG_C
   MK_CONDITION([LIBLISP], [test x"$HAVE_LIBLISP" = x1])
])
