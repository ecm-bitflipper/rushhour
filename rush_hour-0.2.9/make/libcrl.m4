AC_DEFUN([AM_WITH_LIBCRL], [
   AC_ARG_WITH(libcrl,
[  --with-libcrl=PREFIX  defines the path where libcrl is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_LANG_C
   HAVE_LIBCRL=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(crl, crl_new_cfg,
   [
       HAVE_LIBCRL=1
       AC_DEFINE(HAVE_LIBCRL, 1, [Whether crl library is available.])
       DEFINES="$DEFINES HAVE_LIBCRL=1"
       LIBS="-lcrl $LIBS"
       WIN_LIBS="crl $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   AC_LANG_C
   ifdef([MK_CONDITION], [MK_CONDITION([LIBCRL], [test x"$HAVE_LIBCRL" = x1])])
])
