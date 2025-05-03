
AC_DEFUN([AM_WITH_LIBTF14NET], [
    AC_ARG_WITH(tf14net,   [  --with-tf14net=DIR      path to TF14Net library], [
       CPPFLAGS="$CPPFLAGS -I $with_tf14net/include"
       LDFLAGS="$LDFLAGS -L $with_tf14net/lib"
    ], [
    AC_PATH_PROG(READNET, readnet)
    if test "x$READNET" = xno; then
       true
    else
       with_tf14net="`echo $READNET | sed 's@/[[^/]]*/readnet[$]@@g'`"
       if test "x$with_tf14net" = x; then
           true
       else
           CPPFLAGS="$CPPFLAGS -I $with_tf14net/include"
           LDFLAGS="$LDFLAGS -L $with_tf14net/lib"
       fi
    fi
    ])
    PATH_TF14NET="$with_tf14net"
    AC_SUBST(PATH_TF14NET)
 
    AC_MSG_CHECKING(for path to tf14net library)
    AC_SUBST(PATH_TF14NET)
    AC_MSG_RESULT($PATH_TF14NET)
    
    protocol=net_protocol_2000_07_16
 
    TF14LIBS="-ltf14net"
 
    OLD_LIBS="$LIBS"
    LIBS="$TF14LIBS $LIBS"
    AC_CACHE_CHECK(for TF14Net library protocol 2000_07_16, ai_cv_tf14net, [
    AC_LANG_SAVE
    AC_LANG_CPLUSPLUS
    AC_SUBST(DEFINES)
 
    AC_TRY_LINK([
    #include <tf14net.h>
    char const *progname= "testprog";
    ],
    [
    net_protocol_2000_07_16()
    ],
    ai_cv_tf14net=yes,
    ai_cv_tf14net=no)
 
    AC_LANG_RESTORE
    ])
    LIBS="$OLD_LIBS"
 
    if test "x$ai_cv_tf14net" = xyes; then
        AC_DEFINE(HAVE_TF14NET, 1, [Whether we have the tf14net library])
	DEFINES="$DEFINES HAVE_TF14NET=1"
        LIBS="-ltf14net $LIBS"
        WIN_LIBS="tf14net $WIN_LIBS"
        for i in . $2; do
           if test "x$i" = x.; then
              true
           else
              LIBS="-ltf14net$i $LIBS"
              WIN_LIBS="tf14net$i $WIN_LIBS"
           fi
        done
    else
        if test "x$1" = xoptional; then
            true
        else
            AC_MSG_ERROR([TF14Net library is needed.])
        fi
    fi
])
