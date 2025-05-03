AC_DEFUN([AM_WITH_LIBPATHAN], [
   AC_ARG_WITH(lib$2,
[  --with-libpathan=PREFIX defines the path where lib$2 is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_LANG_CPLUSPLUS
   HAVE_LIBPATHAN=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB($2, main,
   [
       HAVE_LIBPATHAN=1
       AC_DEFINE(HAVE_LIBPATHAN, 1, [Whether Path Analysis library is available.])
       DEFINES="$DEFINES HAVE_LIBPATHAN=1"
       LIBS="-l$2 $LIBS"
       WIN_LIBS="$2 $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   AC_LANG_C
   ifdef([MK_CONDITION], [MK_CONDITION([LIBPATHAN], [test x"$HAVE_LIBPATHAN" = x1])])
])
