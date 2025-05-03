
dnl $1= "1" | "optional"
dnl $2= "1"  | "optional" | "0" ; for USB
AC_DEFUN([AM_WITH_LIBOPENOBEX], [
   if test ! "x$2" = x0; then
       AC_CHECK_LIB(openobex, UsbOBEX_TransportConnect,
       [
           AC_DEFINE(HAVE_LIBOPENOBEX_USB, 1, [Whether ObenOBEX supports USB.])
       ],
       [
           if test "x$2" = "xoptional-usb"; then
               true
           else
               AC_MSG_ERROR(This library is needed.)
           fi
       ])
   fi

   HAVE_LIBOPENOBEX=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(openobex, OBEX_Init,
   [
       HAVE_LIBOPENOBEX=0
       AC_DEFINE(HAVE_LIBOPENOBEX, 1, [Whether ObenOBEX is available.])
       DEFINES="$DEFINES HAVE_LIBOPENOBEX=1"
       LIBS="-lopenobex $LIBS"
       WIN_LIBS="openobex $WIN_LIBS"
   ],
   [
       if test "x$1" = xoptional; then
           true
       else
           AC_MSG_ERROR(This library is needed.)
       fi
   ])
   MK_CONDITION([LIBOPENOBEX], [test x"$HAVE_LIBOPENOBEX" = x1])
])
