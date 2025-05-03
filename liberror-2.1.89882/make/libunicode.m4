AC_DEFUN([AM_WITH_LIBUNICODE], [
   AC_ARG_WITH(libunicode,
[  --with-libunicode=PREFIX  defines the path where libunicode is found.],
       [
           UNICODE="${withval}/share/unicode"
       ])

   if test -n "$FORCED_PREFIX"; then
       UNICODE="${prefix}/share/unicode"
   fi
   AC_PATH_PROGS(LIBUNICODE_PATH, libunicode-path)
   if test "x${UNICODE-unset}" = xunset; then
       X=`libunicode-path`
       if test "x${X}" && test -s "${X}/unicodedata.txt"; then
           UNICODE=${X}
       fi
   fi
   UNICODE=${UNICODE-'${datadir}/unicode'}
   AC_SUBST(UNICODE)
   AC_SUBST(DEFINES)

   if test -f "${UNICODE}/VERSION"; then
      HAVE_LIBUNICODE=1
      AC_DEFINE(HAVE_LIBUNICODE, 1, whether libunicode is available)
      DEFINES="$DEFINES HAVE_LIBUNICODE=1"
   else
      HAVE_LIBUNICODE=0
      AC_DEFINE(HAVE_LIBUNICODE, 0, whether libunicode is available)
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   fi
   ifdef([MK_CONDITION], [MK_CONDITION([LIBUNICODE], [test x"$HAVE_LIBUNICODE" = x1])])
])
