AC_DEFUN([AM_WITH_LIBLICENCE], [
   AC_ARG_WITH(licence,
[  --with-licence=PREFIX   defines the path where liblicence is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_ARG_WITH(license,
[  --with-license=PREFIX   same as --with-licence.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   AC_SUBST(DEFINES)
   if test "x$with_license" = "xno"
   then
       HAVE_LIBLICENCE=0
   else
       AC_LANG_CPLUSPLUS
       HAVE_LIBLICENCE=0
       AC_CHECK_LIB(license, license_init,
       [
           AC_DEFINE([HAVE_LIBLICENCE], 1, [Whether we have LIBLICENCE])
           HAVE_LIBLICENCE=1
           DEFINES="$DEFINES HAVE_LICENSE=1 HAVE_LICENCE=1"
           LIBS="-llicense $LIBS"
           WIN_LIBS="license $WIN_LIBS"
       ],
       [
          if test "x$1" = xoptional; then
              true
          else
              AC_MSG_ERROR(This library is needed.)
          fi
       ])
       AC_LANG_C
   fi
   ifdef([MK_CONDITION], [MK_CONDITION([LIBLICENCE], [test x"$HAVE_LIBLICENCE" = x1])])
])
