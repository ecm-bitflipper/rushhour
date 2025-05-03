AC_DEFUN([AM_WITH_LIBRANDOM], [
   AC_ARG_WITH(librandom,
[  --with-librandom=PREFIX  defines the path where librandom is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_LANG_C
   HAVE_LIBRANDOM=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(random, ai_random,
   [
       HAVE_LIBRANDOM=1
       AC_DEFINE(HAVE_LIBRANDOM, 1, [Whether random library is available.])
       DEFINES="$DEFINES HAVE_LIBRANDOM=1"
       LIBS="-lrandom $LIBS"
       WIN_LIBS="random $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   AC_LANG_C
   ifdef([MK_CONDITION], [MK_CONDITION([LIBRANDOM], [test x"$HAVE_LIBRANDOM" = x1])])
])
