AC_DEFUN([AM_WITH_LIBUSB], [
   HAVE_LIBUSB=0
   AC_CHECK_LIB(usb, usb_get_busses,
   [
       HAVE_LIBUSB=1
       AC_DEFINE(HAVE_LIBUSB, 1, [Whether USB library is available.])
       LIBS="-lusb $LIBS"
       WIN_LIBS="usb $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   MK_CONDITION([LIBUSB], [test x"$HAVE_LIBUSB" = x1])
])
