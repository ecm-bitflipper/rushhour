AC_DEFUN([AM_WITH_LIBRARY], [
   AC_ARG_WITH(library,
[  --with-library=PREFIX  defines the path where library is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_LANG_C
   HAVE_LIBRARY=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(rary, str_create,
   [
       HAVE_LIBRARY=1
       AC_DEFINE(HAVE_LIBRARY, 1, [Whether rary library is available.])
       DEFINES="$DEFINES HAVE_LIBRARY=1"
       LIBS="-lrary $LIBS"
       WIN_LIBS="rary $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   AC_LANG_C
   ifdef([MK_CONDITION], [MK_CONDITION([LIBRARY], [test x"$HAVE_LIBRARY" = x1])])
])
