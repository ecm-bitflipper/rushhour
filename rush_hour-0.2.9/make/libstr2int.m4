AC_DEFUN([AM_WITH_LIBSTR2INT], [
   AC_ARG_WITH(libstr2int,
[  --with-str2int=PREFIX   defines the path where libstr2int is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_LANG_CPLUSPLUS
   HAVE_LIBSTR2INT=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(str2int, s2i_init,
   [
       HAVE_LIBSTR2INT=1
       AC_DEFINE(HAVE_LIBSTR2INT, 1, [Whether stri2int library is available.])
       DEFINES="$DEFINES HAVE_LIBSTR2INT=1"
       LIBS="-lstr2int $LIBS"
       WIN_LIBS="str2int $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   AC_LANG_C
   ifdef([MK_CONDITION], [MK_CONDITION([LIBSTR2INT], [test x"$HAVE_LIBSTR2INT" = x1])])
])
