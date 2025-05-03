AC_DEFUN([AM_WITH_LIBERROR], [
   AC_ARG_WITH(liberror,
[  --with-liberror=PREFIX  defines the path where liberror is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_LANG_CPLUSPLUS
   HAVE_LIBERROR=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(error, eprintf,
   [
       HAVE_LIBERROR=1
       AC_DEFINE(HAVE_LIBERROR, 1, [Whether Error/Message library is available.])
       DEFINES="$DEFINES HAVE_LIBERROR=1"
       LIBS="-lerror $LIBS"
       WIN_LIBS="error $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   AC_LANG_C
   ifdef([MK_CONDITION], [MK_CONDITION([LIBERROR], [test x"$HAVE_LIBERROR" = x1])])
])
