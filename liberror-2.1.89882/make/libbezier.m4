
AC_DEFUN([AM_WITH_LIBBEZIER], [
   AC_ARG_WITH(libbezier,
[  --with-libbezier=PREFIX defines the path where libbezier is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_LANG_CPLUSPLUS
   HAVE_LIBBEZIER=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(bezier, bezier_read_file,
   [
       AC_DEFINE(HAVE_LIBBEZIER, 1, [Whether BEZIER library is available.])
       HAVE_LIBBEZIER=1
       DEFINES="$DEFINES HAVE_LIBBEZIER=1"
       LIBS="-lbezier $LIBS"
       WIN_LIBS="bezier $WIN_LIBS"
   ],
   [
       if test "x$1" = xoptional; then
           true
       else
           AC_MSG_ERROR(This library is needed.)
       fi
   ])
   AC_LANG_C
   MK_CONDITION(LIBBEZIER, test "x$HAVE_LIBBEZIER" == x1)
])
