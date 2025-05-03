AC_DEFUN([AM_WITH_LIBAICA], [
   AC_ARG_WITH(lib$2,
[  --with-libaica=PREFIX  defines the path where lib$2 is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_LANG_CPLUSPLUS
   OLD_LIBS="$LIBS"
   LIBS="-l$3 $LIBS"
   dnl echo "** Frontend: $3"
   AC_SUBST(DEFINES)
   HAVE_LIBAICA=0
   AC_CHECK_LIB($2, aip_init_options,
   [
       AC_DEFINE([HAVE_LIBAICA], 1, [Whether we have LIBAICA])
       HAVE_LIBAICA=1
       DEFINES="$DEFINES HAVE_LIBAICA=1"
       OLD_LIBS="-l$2 $LIBS"
       WIN_LIBS="$2 $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   LIBS="$OLD_LIBS"
   AC_LANG_C
   ifdef([MK_CONDITION], [MK_CONDITION([LIBAICA], [test x"$HAVE_LIBAICA" = x1])])
])
