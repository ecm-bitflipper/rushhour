
AC_DEFUN([AM_PREFIX_PROGRAM_BRANCH],[
    AC_MSG_CHECKING([for prefix for program $1, cvs branch $BRANCH])
    if test "x$prefix" = xNONE; then
        _save_ifs=$IFS
        IFS=:
        _dummy="$PATH"
        _mismatch=
        for _dir in $_dummy; do
            IFS=$_save_ifs
            if test "x$_dir" != "x." && \
               test "x$_dir" != "x" && \
               test -x "$_dir/$1"
            then
                _branch_string="`strings -n 9 \"$_dir/$1\" | grep '@branch:' | sed 's%^.*@branch:%%' | sed 's%@.*%%'`" 2>/dev/null
                if test -z "$_branch_string" ; then
                    _branch_string="`cat \"$_dir/$1\" | egrep '^ *echo .* branch *= *' | sed 's@.*branch *= *@@' | sed 's@\".*@@'`" 2>/dev/null
                fi
                _this_prefix="`echo $_dir | sed 's%/[[^/]][[^/]]*/*$%%'`"

                if test "x${BRANCH}" = "x$_branch_string"; then
                    prefix="$_this_prefix"
                    _mismatch=0
                    break
                else
                    if test "x$prefix" = xNONE; then
                        prefix="$_this_prefix"
                    fi
                    if test -z "$_branch_string"; then
                        if test "x$_mismatch" = x2; then
                            prefix="$_this_prefix"
                        fi
                        _mismatch=1
                    else
                        if test "x$_mismatch" = x; then
                            _mismatch=2
                        fi
                    fi
                fi
            fi
        done
        dnl echo "*** _mismatch=$_mismatch, prefix=$prefix"
        if test "x$_mismatch" = x2; then
            dnl AC_MSG_ERROR([CVS branch $BRANCH not found for executable $1.]
dnl [Please set --prefix manually.])
            AC_MSG_RESULT([(branch $BRANCH not found)])
        elif test "x$_mismatch" = x1; then
            AC_MSG_RESULT([$prefix (no cvs tag found)])
        elif test "x$_mismatch" = x0; then
            AC_MSG_RESULT([$prefix])
        else
            AC_MSG_RESULT([($1 not found)])
        fi
     else
        AC_MSG_RESULT([$prefix (already set)])
     fi
])

dnl
dnl $1: prefix of variable
dnl $2: condition (for the shell), e.g. test "x${GXX}" = xyes
dnl
AC_DEFUN([MK_CONDITION],[
if ( [$2] )  >/dev/null 2>&1
then
    [$1]_TRUE=''
    [$1]_FALSE=' # '
else
    [$1]_TRUE=' # '
    [$1]_FALSE=''
fi
AC_SUBST([$1]_TRUE)
AC_SUBST([$1]_FALSE)
])

