
AC_DEFUN([AM_WITH_LIBCRL2], [
   AC_ARG_WITH(libcrl2,
[  --with-libcrl2=PREFIX   defines the path where libcrl2 is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_LANG_CPLUSPLUS
   HAVE_LIBCRL2=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(crl2, crl_graph_read,
   [
       AC_DEFINE(HAVE_LIBCRL2, 1, [Whether CRL2 library is available.])
       HAVE_LIBCRL2=1
       DEFINES="$DEFINES HAVE_LIBCRL2=1"
       LIBS="-lcrl2 $LIBS"
       WIN_LIBS="crl2 $WIN_LIBS"
   ],
   [
       if test "x$1" = xoptional; then
           true
       else
           AC_MSG_ERROR(This library is needed.)
       fi
   ])
   AC_LANG_C
   MK_CONDITION(LIBCRL2, test "x$HAVE_LIBCRL2" == x1)
])
