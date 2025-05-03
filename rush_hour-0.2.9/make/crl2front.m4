
AC_DEFUN([AM_WITH_CRL2FRONT], [
    AC_SUBST(CRL2FRONT_TRUE)
    AC_SUBST(CRL2FRONT_FALSE)
    CRL2FRONT_TRUE=" # "
    CRL2FRONT_FALSE=""
    if test "x$1" = xoptional; then
        AC_ARG_WITH(crl2front,
        [  --without-crl2front     disable support for crl2 frontend.])
    fi
    if test "x$with_crl2front" = xno; then :; else
        AC_LANG_CPLUSPLUS
        AC_CHECK_LIB(crl2f, main, [
            dnl LIBS="-lcrl2f $LIBS"        handled in Rules.in
            dnl WIN_LIBS="crl2f $WIN_LIBS"
            CRL2FRONT_TRUE=""
            CRL2FRONT_FALSE=" # "
            PAG_FRONTEND=crl2
            KFG_INTERFACE=2
            AC_DEFINE(HAVE_CRL2FRONT, 1, [Whether the crl2 frontend is available])
        ], [
            if test "x$1" = xoptional; then
                true
            else
                AC_MSG_ERROR(This library is needed.)
            fi
        ])
        AC_LANG_C
    fi
])
