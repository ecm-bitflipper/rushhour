AC_DEFUN([AM_WITH_LIBSETUP], [
   AC_ARG_WITH(libsetup,
[  --with-libsetup=PREFIX  defines the path where libsetup is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_LANG_CPLUSPLUS
   HAVE_LIBSETUP=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(setup, setup_init,
   [
       HAVE_LIBSETUP=1
       AC_DEFINE(HAVE_LIBSETUP, 1, [Whether Setup library is available.])
       DEFINES="$DEFINES HAVE_LIBSETUP=1"
       LIBS="-lsetup $LIBS"
       WIN_LIBS="setup $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   AC_LANG_C
   MK_CONDITION([LIBSETUP], [test x"$HAVE_LIBSETUP" = x1])
])
