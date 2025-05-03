
AC_DEFUN([AM_WITH_LIBBEX], [
   AC_ARG_WITH(libbex,
[  --with-licence=PREFIX   defines the path where libbex is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_ARG_WITH(bex,
[  --with-bex=PREFIX   same as --with-licence.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])

   AC_LANG_CPLUSPLUS
   AC_SUBST(DEFINES)
   DEFINES="$DEFINES HAVE_BEX=1 HAVE_BEX=1"
   LIBS="-lbex $LIBS"
   WIN_LIBS="bex $WIN_LIBS"
   AC_LANG_C
])

