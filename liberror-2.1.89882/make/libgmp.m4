AC_DEFUN([AM_WITH_LIBGMP], [
   AC_ARG_WITH(libgmp,
[  --with-libgmp=PREFIX   defines the path where libgmp is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   HAVE_LIBGMP=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(gmp, __gmpz_init,
   [
       HAVE_LIBGMP=1
       AC_DEFINE(HAVE_LIBGMP, 1, [Whether GNU MP library is available.])
       DEFINES="$DEFINES HAVE_LIBGMP=1"
       LIBS="-lgmp $LIBS"
       WIN_LIBS="gmp $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   MK_CONDITION([LIBGMP], [test x"$HAVE_LIBGMP" = x1])
])
