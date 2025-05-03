AC_DEFUN([AM_WITH_LIBCONFIG], [
   AC_ARG_WITH(libconfig,
[  --with-libconfig=PREFIX  defines the path where libconfig is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_LANG_CPLUSPLUS
   HAVE_LIBCONFIG=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(config, cfg_init,
   [
       HAVE_LIBCONFIG=1
       AC_DEFINE(HAVE_LIBCONFIG, 1, [Whether Configure library is available.])
       DEFINES="$DEFINES HAVE_LIBCONFIG=1"
       LIBS="-lconfig $LIBS"
       WIN_LIBS="config $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   AC_LANG_C
   MK_CONDITION([LIBCONFIG], [test x"$HAVE_LIBCONFIG" = x1])
])
