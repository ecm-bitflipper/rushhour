dnl ----------------------------------------------------------------------
dnl    AbsInt -- Angewandte Informatik GmbH
dnl    http://www.AbsInt.de/
dnl ----------------------------------------------------------------------
dnl
dnl Time-stamp:
dnl $Revision: 73328 $
dnl Author: Florian Martin
dnl Description: Common defines for all configure scripts in c166pagopt
dnl
dnl COPYRIGHT NOTICE:
dnl
dnl   (c) Copyright 2000 AbsInt Angewandte Informatik GmbH
dnl
dnl All rights reserved. This file, or parts of it, or modified versions of it,
dnl may not be copied, reproduced or transmitted in any form, or by any means,
dnl or stored in a retrieval system, or used for any purpose, without the prior
dnl written permission of AbsInt Angewandte Informatik GmbH.
dnl
dnl Every care has been taken in manufacturing the supplied product and its
dnl documentation. AbsInt Angewandte Informatik GmbH will neither assume
dnl responsibility for any damage caused by the use of its products, nor accept
dnl warranty or update claims, unless stated explicitly otherwise in a special
dnl agreement.
dnl
dnl ----------------------------------------------------------------------


dnl
dnl Test if INSTALL -d can make directories
dnl
AC_DEFUN(FM_CHECK_INSTALL_D,[
    AC_CACHE_CHECK(whether ${INSTALL} -d can create directories, ac_cv_installd, [
    ac_cv_installd=yes
    ${INSTALL} -d -m 755 config.testdir 2>/dev/null > /dev/null || ac_cv_installd=no
    test -d config.testdir 2>/dev/null > /dev/null || ac_cv_installd=no
    ${RMDIR} config.testdir 2>/dev/null > /dev/null
    ])

    installok=yes
    test "$ac_cv_installd" = "yes" || installok=no

    if test "$installok" = "no" ; then
    INSTALL="${ac_install_sh}"
    ${ECHO} "Warning: using fall-back script ${INSTALL}." 1>&2
    fi

    test -z "${INSTALL_PROGRAM}" && INSTALL_PROGRAM='${INSTALL}'
    test -z "${INSTALL_DATA}"    && INSTALL_DATA='${INSTALL} -m 644'
    test -z "${INSTALL_DIR}"     && INSTALL_DIR='${INSTALL} -d -m 755'
])


dnl
dnl Looking for PAGPATH
dnl
AC_DEFUN(FM_CHECK_PAG,[
    AC_ARG_WITH(pag-dir, [  --with-pag-dir=DIR      path to base directory of pag installation])

    if test "x$with_pag_dir" = xno; then
        AC_MSG_ERROR([pag is required use --with-pag-dir])
    fi

    if test "x$with_pag_dir" = xyes; then
        AC_MSG_ERROR([you should give a path behind the --with-pag-dir parameter])
    fi

    AC_PATH_PROG(PAG,pag,none,$with_pag_dir/bin:$FORCED_PREFIX/bin:$PAGPATH/bin:$prefix/bin:$PATH:$default_prefix/bin)

    PAGPATH="`echo $PAG | sed 's@/bin/pag@@'`"

    if test "$PAGPATH/bin/pag" != "$PAG"; then
        AC_MSG_ERROR([can not determin pagpath. try --with-pag-dir])
    fi

    if test "x$PAGPATH" = xnone ; then
        AC_MSG_ERROR([no pag executable found use --with-pag-dir parameter or the enviroment varibale $PAGPATH])
    fi
    AC_MSG_RESULT([*** found $PAGPATH as path to pag installation ***])

    AC_SUBST(PAGPATH)

    dnl Check things that some PAG headers need:

    dnl Checks for header files.
    AC_HEADER_DIRENT
    AC_HEADER_STDC
    AC_CHECK_HEADERS(libgen.h limits.h sys/time.h unistd.h sys/types.h search.h sys/resource.h sys/stat.h errno.h)

    dnl Checks for typedefs, structures, and compiler characteristics.
    AC_C_CONST
    AC_C_BIGENDIAN
    AC_CHECK_SIZEOF(void *, 4)
    AC_CHECK_SIZEOF(char *, 4)
    AC_CHECK_SIZEOF(long *, 4)
    AC_CHECK_SIZEOF(long long, 8)
    AC_CHECK_SIZEOF(__int64, 8)
    AC_CHECK_SIZEOF(long, 4)
    AC_CHECK_SIZEOF(int, 4)
    AC_C_INLINE

    dnl Checks for library functions.
    AC_CHECK_LIB(compat, main)
    AC_FUNC_MEMCMP
    AC_FUNC_ALLOCA
    AC_TYPE_SIGNAL
    AC_FUNC_VPRINTF
    AC_CHECK_FUNCS(strchr memmove memset getrusage lfind mkdir stat chdir getcwd chmod strerror)
])


dnl
dnl Looking for library rary
dnl
AC_DEFUN(FM_CHECK_LIBRARY,[
    AC_ARG_WITH(rary-dir, [  --with-rary-dir=DIR  path to rary library ]) 

    if test x$with_rary-dir = xno; then
        AC_MSG_ERROR([rary is required use --with-rary-dir ])
    fi                                                                                                    

    if test x$with_rary-dir = xyes; then
        AC_MSG_ERROR([you should give a path behind the --with-rary-dir parameter])
    fi                                                                                                    


    dnl look in some common places for rary library
    AC_MSG_CHECKING([for rary library])
   dnl if we have WITH_DMALLOC then we search for librarydm.a
   rary_name=rary
    if test x$WITH_DMALLOC = x1; then
      rary_name=rarydm
   fi

    rary_dir=${with_rary_dir:-""}
    if test x$rary_dir = x ; then
        if test -f "$prefix/lib/lib${rary_name}.a" ; then 
            rary_dir="$prefix"
        else
            if test -f "/usr/local/lib/lib${rary_name}.a" ; then
                rary_dir="/usr/local"
            else
                if test -f "/opt/lib/lib${rary_name}.a" ; then
                    rary_dir="/opt"
                fi
            fi
        fi
    fi

    if test x$rary_dir = x ; then
        AC_MSG_ERROR([no rary library found use --with-rary-dir parameter])
    fi
    AC_MSG_RESULT([*** found $rary_dir as path to rary library ***])                             

    AC_SUBST(rary_dir)
    AC_SUBST(rary_name)
])


dnl
dnl Looking for crlforntend for PAG (do FM_CHECK PAG first)
dnl
AC_DEFUN(FM_CHECK_CRLFRONT,[

    AC_ARG_WITH(crlfront-dir, [  --with-crlfront=DIR  path to a crl frontend or --with-crlfront for the one installed with pag (default) ]) 

    if test x$with_crlfront = xno; then
        AC_MSG_ERROR([crlfront is required use --with-crlfont ])
    fi                                                                                                    

    CRLFRONT=crl
    CRLFRONTLIB=-lcrlf
    CRLFRONTINCLUDE="-I$PAGPATH/include/pag/frontend/crl"

    if test x$with_crlfront != xyes; then
        if test x$with_crlfront != x ; then
            CRLFRONT="$with_crlfront"
            CRLFRONTLIB="-L$with_crlfront -lcrlf"
            CRLFRONTINCLUDE="-I$with_crlfront"
        fi
    fi

    AC_SUBST(CRLFRONT)
    AC_SUBST(CRLFRONTLIB)
    AC_SUBST(CRLFRONTINCLUDE)
])

dnl
dnl crl version check
dnl
AC_DEFUN(FM_CHECK_CRL2,[

    AC_ARG_WITH(crl2, [  --with-crl2 Use crl2 ]) 
	
    if test x$with_crl2 = xno; then
        CRLLIB=-lcrl
        CRLINCLUDE="-I$PAGPATH/include -I$PAGPATH"
        CRLFRONT=crl
        CRLFRONTLIB=-lcrlf
        CRLFRONTINCLUDE="-I$PAGPATH/include/pag/frontend/crl"
    fi                                                                                                    
    if test x$with_crl2 = xyes; then
        CRLLIB=-lcrl2
        CRLINCLUDE="-I$PAGPATH/include -I$PAGPATH"
    	CRLFRONT=crl2
        CRLFRONTLIB=-lcrl2f
        CRLFRONTINCLUDE="-I$PAGPATH/include/pag/frontend/crl2"
        CFLAGS="$CFLAGS -DCRL2"
        WINCFLAGS="$WINCFLAGS -DCRL2"
    fi    
    
    AC_MSG_RESULT([*** using ($CRLFRONT,$CRLFRONTLIB,$CRLFRONTINCLUDE) for crlfront ***])                             

    AC_SUBST(CRLLIB)
    AC_SUBST(CRLINCLUDE)
    AC_SUBST(CRLFRONT)
    AC_SUBST(CPPFLAGS)
    AC_SUBST(WINCFLAGS)
])

dnl
dnl Looking for library crl (do FM_CHECK_RARY first)
dnl
AC_DEFUN(FM_CHECK_CRL,[

    AC_ARG_WITH(crl-dir, [  --with-crl-dir=DIR  path to crl library]) 

    if test x$with_crl-dir = xno; then
        AC_MSG_ERROR([libcrl is required use --with-crl-dir])
    fi                                                                                                    

    if test x$with_crl-dir = xyes; then
        AC_MSG_ERROR([you should give a path behind the --with-crl-dir parameter])
    fi                                                                                                    


    dnl look in some common places for rary library
    AC_MSG_CHECKING(for crl library)
   dnl if we have WITH_DMALLOC then we search for librarydm.a
   crl_name=crl
    if test x$WITH_DMALLOC = x1; then
      crl_name=crldm
   fi
    crl_dir=${with_crl_dir:-""}
    if test x$crl_dir = x ; then
        if test -f $prefix/lib/lib${crl_name}.a ; then 
            crl_dir="$prefix"
        else
            if test -f "$rary_dir/lib/lib${crl_name}.a"; then
                crl_dir="$rary_dir"
            else
                if test -f "/usr/local/lib/lib${crl_name}.a" ; then
                    crl_dir="/usr/local"
                else
                    if test -f "/opt/lib/lib${crl_name}.a" ; then
                    crl_dir="/opt"
                fi
            fi
        fi
        fi
    fi

    if test x$crl_dir = x ; then
        AC_MSG_ERROR([no crl library found use --with-crl-dir parameter])
    fi
    AC_MSG_RESULT([*** found $crl_dir as path to crl library ***])                             

    AC_SUBST(crl_dir)
    AC_SUBST(crl_name)
])


dnl
dnl Looking for c166bits from reader
dnl
AC_DEFUN(FM_CHECK_C166BITS,[
    AC_MSG_CHECKING(for c166bits.h)

    if test -f ../common/c166bits.h; then
        AC_MSG_RESULT([found])
    else
        AC_MSG_ERROR([c166bits.h mut be located in ../common !])
    fi                                                                                                    
])

dnl 
dnl if enable opt is set do somthing useful for PAG
dnl 
AC_DEFUN(FM_ENABLE_OPT,[
    AC_MSG_CHECKING(for options to speeding PAG)
 
    dnl if test "x$enable_opt" = xno; then
   dnl      CPPFLAGS="$CPPFLAGS ...."
    dnl fi
    if test "x$enable_opt" = xmax; then
        CPPFLAGS="$CPPFLAGS -DILON -DNORCHECK"
        AC_MSG_RESULT([-DILON -DNORCHECK])
    else
        AC_MSG_RESULT([none])
    fi                                                                                                                               
])


dnl 
dnl check for dmalloc
dnl 
dnl we look for the dmalloc library
AC_DEFUN(FM_DMALLOC,[
AC_ARG_WITH(dmalloc-dir, [  --with-dmalloc-dir      path to base directory of dmalloc installation])
 
if test "$with_dmalloc_dir" = "no" || test -z "$with_dmalloc_dir"; then
 AC_MSG_RESULT([configured for no dmalloc support])
else
 if test "$with_dmalloc_dir" = "yes"; then
  AC_MSG_ERROR([you should give a path behind the --with-dmalloc-dir parameter])
 else
  WITH_DMALLOC=1
  LDFLAGS="$LDFLAGS -L$with_dmalloc_dir/lib"
  CPPFLAGS="$CPPFLAGS -DDMALLOC -I$with_dmalloc_dir/include"
  AC_CHECK_LIB(dmalloc,main, LIBS="$LIBS -ldmalloc", AC_MSG_ERROR([library dmalloc not found in specified path]))
 fi
fi
])

dnl
dnl Looking for library aica
dnl
AC_DEFUN(FM_CHECK_LIBAICA,[
    AC_ARG_WITH(aica-dir, [  --with-aica-dir=DIR  path to aica libaica ])

    if test -z "$with_aica_dir"; then
        BIN="`which libaica-version`"
        with_aica_dir="`echo $BIN | sed s@/bin/libaica-version@@`"
    fi

    if test -z "$with_aica_dir" || test x$with_aica_dir = xno; then
        AC_MSG_ERROR([Aica was not found but is required.  Use --with-aica-dir])
    fi

    if test x$with_aica_dir = xyes; then
        AC_MSG_ERROR([You should give a path with --with-aica-dir .])
    fi

    dnl look in some common places for aica libaica
    AC_MSG_CHECKING([for aica library])
    aica_name=aica

    aica_dir=${with_aica_dir:-""}
    if test x$aica_dir = x ; then
        if test -f "$prefix/lib/lib${aica_name}.a" ; then
            aica_dir="$prefix"
        else
            if test -f "/usr/local/lib/lib${aica_name}.a" ; then
                aica_dir="/usr/local"
            else
                if test -f "/opt/lib/lib${aica_name}.a" ; then
                    aica_dir="/opt"
                fi
            fi
        fi
    fi

    if test x$aica_dir = x ; then
        AC_MSG_ERROR([no aica libaica found use --with-aica-dir parameter])
    fi
    AC_MSG_RESULT([*** found $aica_dir as path to aica libaica ***])

    AC_SUBST(aica_dir)
    AC_SUBST(aica_name)
])


