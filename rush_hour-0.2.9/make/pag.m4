AC_DEFUN([AM_PAGPATH],[
AC_MSG_CHECKING(for PAG installation directory)
if test "x${PAGPATH+set}" != xset; then
    PAG_BIN="`which pag 2>/dev/null`"
    if test "x${PAG_BIN}" != x; then
        PAGPATH="`echo $PAG_BIN | sed 's:/bin/pag$::'`"
    fi
fi
if test "x${PAGPATH+set}" = xset; then
    AC_MSG_RESULT($PAGPATH)
else
    AC_MSG_RESULT(Not found.  Maybe compiling and linking works anyway.)
fi
])

