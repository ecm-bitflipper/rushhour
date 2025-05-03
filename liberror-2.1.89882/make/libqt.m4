
AC_DEFUN([AM_WITH_LIBQT], [
   AC_ARG_WITH(libqt,
[  --with-libqt=PREFIX     defines the path where libqt is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
           QTDIR=${withval}
       ],
       [
           CPPFLAGS="$CPPFLAGS -I${QTDIR}/include"
           LDFLAGS="$LDFLAGS -L${QTDIR}/lib"
       ])
   AC_LANG_CPLUSPLUS
   AC_SUBST(QTDIR)
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(qt-mt, main,
   [
       AC_DEFINE(HAVE_LIBQT, 1, [Whether Qt is available.])
       DEFINES="$DEFINES HAVE_QT=1"
       LIBS="-lqt-mt $LIBS"
       WIN_LIBS="qt $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   AC_LANG_C
])
