AC_DEFUN([AM_WITH_LIBBOEHM], [
   AC_ARG_WITH(libboehm,
[  --with-libboehm=PREFIX defines the path where libboehm is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_LANG_CPLUSPLUS
   HAVE_LIBGC=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(gc, GC_malloc,
   [
       HAVE_LIBGC=1
       AC_DEFINE(HAVE_LIBGC, 1, [Whether Boehm GC library is available.])
       DEFINES="$DEFINES HAVE_LIBGC=1"
       LIBS="-lgc $LIBS"
       WIN_LIBS="gc $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   AC_LANG_C
   MK_CONDITION([LIBBOEHM], [test x"$HAVE_LIBGC" = x1])
])
