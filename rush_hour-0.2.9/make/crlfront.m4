
AC_DEFUN([AM_WITH_CRLFRONT], [
    AC_SUBST(CRLFRONT_TRUE)
    AC_SUBST(CRLFRONT_FALSE)
    CRLFRONT_TRUE=" # "
    CRLFRONT_FALSE=""
    if test "x$1" = xoptional; then
        AC_ARG_WITH(crlfront,
        [  --without-crlfront      disable support for crl frontend.])
    fi
    if test "x$with_crlfront" = xno; then :; else
        AC_LANG_CPLUSPLUS
        AC_CHECK_LIB(crlf, pagerd_read, [
            dnl LIBS="-lcrlf $LIBS"
            dnl WIN_LIBS="crlf $WIN_LIBS"
            CRLFRONT_TRUE=""
            CRLFRONT_FALSE=" # "
            PAG_FRONTEND=crl
            KFG_INTERFACE=1
            AC_DEFINE(HAVE_CRLFRONT, 1, [Whether the crl frontend is available])
        ], [
            if test "x$1" = xoptional; then
                true
            else
                AC_MSG_ERROR(This library is needed with ERD enabled.)
            fi
        ])
        AC_LANG_C
    fi
])
