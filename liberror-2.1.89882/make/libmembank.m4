AC_DEFUN([AM_WITH_LIBMEMBANK], [
   AC_ARG_WITH(libmembank,
[  --with-libmembank=PREFIX defines the path where libmembank is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_LANG_CPLUSPLUS
   HAVE_LIBMEMBANK=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(membank, bank_init,
   [
       HAVE_LIBMEMBANK=1
       AC_DEFINE(HAVE_LIBMEMBANK, 1, [Whether membank library is available.])
       DEFINES="$DEFINES HAVE_LIBMEMBANK=1"
       LIBS="-lmembank $LIBS"
       WIN_LIBS="membank $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   AC_LANG_C
   MK_CONDITION([LIBMEMBANK], [test x"$HAVE_LIBMEMBANK" = x1])
])
