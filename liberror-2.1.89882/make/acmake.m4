
builtin([include], [make/actools.m4])

AC_SUBST(BASE_VERSION)

AC_CONFIG_AUX_DIR(make)
AC_CANONICAL_SYSTEM

dnl let the user have a default prefix for initialisation:
AC_PREFIX_DEFAULT([${configure_default_prefix-/usr/local}])

dnl Delete version.h and others.  It must be regenerated during next make.
rm -f version.h version.c version.cpp version.h.stamp version.stamp version.o

WINPREFIX="${WINPREFIX-E:\\WINNT}"
AC_SUBST(WINPREFIX)

WINDIR="${WINDIR-$HOME/winnt}"
AC_SUBST(WINDIR)

AC_SUBST(DEFINES)

define([feature_declare_raw],[
    ifdef([$1],, [
        define([$1],)
    ])
])

define([feature_declare],[
    feature_declare_raw([_DEFINE_$1])
    feature_declare_raw([_USE_$1])
])

define([feature_check],[
    ifelse([$1],,, [
        ifelse([$1],1,,[
            ifdef([$1],, [
                m4_errprint([acmake.m4 is broken:
    Found usage of undeclared feature [$1].
    Please check spelling and possibly declare it.
])
            ])
        ])
    ])
])

define([feature_if],[
    feature_check([$1])
    ifelse($1,,[
    $3
    ],[
    $2
    ])
])

define([feature_or], [ifelse($1,,ifelse($2,,,1),1)])
define([feature_and],[ifelse($1,,,ifelse($2,,,1))])

define([MY_MSG_DEBUG], [
    echo "acmake: $1" 1>&2
])

define([feature_depend],[
    feature_if([_USE_$1], [
        feature_if([_USE_$2],, [
            define([_USE_$2], _USE_$1) dnl inherit the value of the feature
            MY_MSG_DEBUG([[_USE_$1] implies [_USE_$2], value _USE_$1.])
        ])
    ])
    feature_if([_DEFINE_$1], [
        feature_if([_USE_$2],, [
            define([_USE_$2], _DEFINE_$1) dnl inherit the value of the feature
            MY_MSG_DEBUG([[_DEFINE_$1] implies [_USE_$2], value _DEFINE_$1.])
        ])
    ])
])

dnl set things to empty string if undefined:
feature_declare([AT])
feature_declare([BEX])
feature_declare([BINUTILS])
feature_declare([CRL2FRONT])
feature_declare([CRL2])
feature_declare([BEZIER])
feature_declare([CRLFRONT])
feature_declare([CXX])
feature_declare([DMALLOC])
feature_declare([DOXYGEN])
feature_declare([ERWIN])
feature_declare([FRACTION])
feature_declare([ATTRPROP])
feature_declare([MEMBANK])
feature_declare([BOEHM])
feature_declare([LIBAICA])
feature_declare([LIBAICA2])
feature_declare([LIBERROR])
feature_declare([NSL])
feature_declare([SOCKET])
feature_declare([LICENCE])
feature_declare([LICENSE])
feature_declare([LISP])
feature_declare([LIBCONFIG])
feature_declare([LOOP])
feature_declare([PAG])
feature_declare([PATHAN])
feature_declare([PATHAN2])
feature_declare([PATTERN])
feature_declare([QT])
feature_declare([PNG])
feature_declare([ZLIB])
feature_declare([SETUP])
feature_declare([SNDFILE])
feature_declare([LISHT])
feature_declare([GMP])
feature_declare([SYMBOL])
feature_declare([TF14NET])    feature_declare_raw([_TF14NET_TARGETS])
feature_declare([WINNET])
feature_declare([OPENOBEX])
feature_declare([OPENOBEX_USB])
feature_declare([USB])
feature_declare([LIBUNICODE])
feature_declare([LIBUNINORM])
feature_declare([STR2INT])
feature_declare([XAI])
feature_declare([LIBRARY])
feature_declare([LIBRANDOM])
feature_declare([LIBCRL])
dnl !!!
dnl !!! DONT FORGET TO UPDATE Defs.in at MAKESUB_SOURCES !!!
dnl !!!

dnl alternative spellings:
feature_depend([LICENSE],   [LICENCE])

dnl dependencies:
feature_depend([SYMBOL],    [ERWIN])

feature_depend([LIBAICA],   [CRLFRONT])
feature_depend([LIBAICA],   [PAG])

feature_depend([LIBAICA2],  [CRLFRONT2])
feature_depend([LIBAICA2],  [PAG])

feature_depend([XAI],       [LIBERROR])
feature_depend([XAI],       [LICENCE])
feature_depend([XAI],       [LIBUNINORM])
feature_depend([XAI],       [CXX])

feature_depend([LICENCE],   [WINNET])
feature_depend([LICENCE],   [NSL])
feature_depend([LICENCE],   [SOCKET])
feature_depend([LICENCE],   [CXX])

feature_depend([PATHAN],    [CRLFRONT])
feature_depend([PATHAN],    [CXX])
feature_depend([PATHAN],    [PAG])

feature_depend([PATHAN2],   [CRL2FRONT])
feature_depend([PATHAN2],   [CXX])
feature_depend([PATHAN2],   [PAG])

feature_depend([CRLFRONT],  [PAG])

feature_depend([CRL2FRONT], [PAG])
feature_depend([CRL2FRONT], [CRL2])

feature_depend([CRL2],      [LIBERROR])
feature_depend([CRL2],      [ATTRPROP])
feature_depend([CRL2],      [MEMBANK])

feature_depend([BEZIER],    [LIBERROR])

feature_depend([QT],        [WINNET])
feature_depend([QT],        [CXX])

feature_depend([SETUP],     [LISP])

feature_depend([LISHT],     [GMP])
feature_depend([LISHT],     [LIBUNICODE])
feature_depend([LISHT],     [LIBUNINORM])
feature_depend([LISHT],     [LIBCONFIG])
feature_depend([LISHT],     [LIBERROR])

feature_depend([LIBCONFIG], [LISP])

feature_depend([LOOP],      [LIBERROR])
feature_depend([LOOP],      [MEMBANK])
feature_depend([LOOP],      [CXX])

feature_depend([FRACTION],  [LIBERROR])
feature_depend([FRACTION],  [CXX])

feature_depend([TF14NET],   [LIBERROR])
feature_depend([TF14NET],   [MEMBANK])
feature_depend([TF14NET],   [CXX])

feature_depend([BEX],       [LIBERROR])
feature_depend([BEX],       [CXX])

feature_depend([LISP],      [LIBERROR])
feature_depend([LISP],      [CXX])

feature_depend([MEMBANK],   [CXX])

feature_depend([PNG],       [ZLIB])

feature_depend([AT],        [CXX])

feature_depend([LIBERROR],  [CXX])

feature_depend([OPENOBEX],  [USB])

feature_depend([LIBUNINORM],[LIBUNICODE])

feature_depend([STR2INT],   [LIBERROR])


dnl AC_MSG_CHECKING(for cvs branch label)
dnl if test -d CVS ; then
dnl     BRANCH="`cvs status Makefile.in | grep 'Sticky Tag:' | sed 's@^[[^:]]*:[[^-()A-Za-z0-9_]]*@@'`" 2>/dev/null
dnl     if test -z "$BRANCH" ; then
dnl         BRANCH="(unknown)"
dnl     else
dnl         BRANCH="`echo \"$BRANCH\" | sed 's@  *.*$@@'`"
dnl     fi
dnl else
dnl     BRANCH="(no cvs)"
dnl fi
dnl AC_MSG_RESULT([$BRANCH])

BRANCH="(not available)"

AC_SUBST(BRANCH)

PROGNAME="_PROGNAME"
PROGNAME_UC="translit(_PROGNAME, [a-z], [A-Z])"
AC_SUBST(PROGNAME)
AC_SUBST(PROGNAME_UC)

AC_SUBST(WIN_INC)
AC_SUBST(WIN_LIBS)
AC_SUBST(WIN_LIBS_SYSTEM)

if test -n "$FORCED_PREFIX"; then
    prefix="$FORCED_PREFIX"
    CPPFLAGS="-I${prefix}/include $CPPFLAGS"
    LDFLAGS="-L${prefix}/lib $LDFLAGS"
fi

CPPFLAGS="$CPPFLAGS -DPROGNAME_TOKEN=$PROGNAME"

dnl echo "USE_LIBERROR=$USE_LIBERROR"

feature_if([_USE_WINNET], [
   WIN_LIBS_SYSTEM="advapi32 wsock32 netapi32 user32 $WIN_LIBS_SYSTEM"
])

LINK_CXX=0
AC_SUBST(LINK_CXX)
feature_if([_USE_CXX], [
   LINK_CXX=1
])

feature_if([_USE_ERWIN], [
   builtin(include, erwin/acerwin.m4)
   ER_ARG_ENABLE_OPT
   ER_PROG_CC
   ER_MANY_CC_WARNINGS
   ER_PROG_CXX
   ER_MANY_CXX_WARNINGS
   ER_SPECIAL_CFLAGS
   dnl ER_SPECIAL_CXXFLAGS  dnl switches off rtti and some other similar stuff
   AC_CHECK_LIB(m, sqrt)
], [
   AC_PROG_CC
   AC_PROG_CXX
])

feature_if([_USE_DMALLOC], [
   builtin(include, make/dmalloc.m4)
   AM_WITH_DMALLOC
   dnl WIN_LIBS="dmalloc $WIN_LIBS" not for Windows.
])

feature_if([_USE_LIBERROR], [
   builtin(include, make/liberror.m4)
   AM_WITH_LIBERROR(_USE_LIBERROR)
])

feature_if([_USE_LIBUNICODE], [
   builtin(include, make/libunicode.m4)
   AM_WITH_LIBUNICODE(_USE_LIBUNICODE)
])

feature_if([_USE_LIBUNINORM], [
   builtin(include, make/libuninorm.m4)
   AM_WITH_LIBUNINORM(_USE_LIBUNINORM)
])

feature_if([_USE_STR2INT], [
   builtin(include, make/libstr2int.m4)
   AM_WITH_LIBSTR2INT(_USE_STR2INT)
])

feature_if([_USE_NSL], [
   AC_CHECK_LIB(nsl, gethostbyname)
])

feature_if([_USE_SOCKET], [
   AC_CHECK_LIB(socket, main)
])

feature_if([_USE_USB], [
   builtin(include, make/libusb.m4)
   AM_WITH_LIBUSB(_USE_USB)
])

feature_if([_USE_OPENOBEX], [
   builtin(include, make/libopenobex.m4)
   AM_WITH_LIBOPENOBEX(_USE_OPENOBEX, _USE_OPENOBEX_USB)
])

feature_if([_USE_LICENCE], [
   builtin(include, make/liblicence.m4)
   AM_WITH_LIBLICENCE(_USE_LICENCE)
])

feature_if([_USE_ATTRPROP], [
   builtin(include, make/libattrprop.m4)
   AM_WITH_LIBATTRPROP(_USE_ATTRPROP)
])

feature_if([_USE_BOEHM], [
   builtin(include, make/libboehm.m4)
   AM_WITH_LIBBOEHM(_USE_BOEHM)
])

feature_if([_USE_MEMBANK], [
   builtin(include, make/libmembank.m4)
   AM_WITH_LIBMEMBANK(_USE_MEMBANK)
])

feature_if([_USE_CRL2], [
   builtin(include, make/libcrl2.m4)
   AM_WITH_LIBCRL2(_USE_CRL2)
])

feature_if([_USE_BEZIER], [
   builtin(include, make/libbezier.m4)
   AM_WITH_LIBBEZIER(_USE_BEZIER)
])

feature_if([_USE_LOOP], [
   builtin(include, make/libloop.m4)
   AM_WITH_LIBLOOP(_USE_LOOP)
])

feature_if([_USE_TF14NET], [
   builtin(include, make/libtf14net.m4)
   feature_check([_TF14NET_TARGETS])
   AM_WITH_LIBTF14NET(_USE_TF14NET, _TF14NET_TARGETS)
])

feature_if([_USE_QT], [
   builtin(include, make/libqt.m4)
   AM_WITH_LIBQT(_USE_QT)
])

feature_if([_USE_ZLIB], [
   builtin(include, make/libz.m4)
   AM_WITH_ZLIB(_USE_ZLIB)
])

feature_if([_USE_PNG], [
   builtin(include, make/libpng.m4)
   AM_WITH_LIBPNG(_USE_PNG)
])

feature_if([_USE_SNDFILE], [
   builtin(include, make/libsndfile.m4)
   AM_WITH_LIBSNDFILE(_USE_SNDFILE)
])

feature_if([_USE_GMP], [
   builtin(include, make/libgmp.m4)
   AM_WITH_LIBGMP(_USE_GMP)
])

feature_if([_USE_LISHT], [
   builtin(include, make/liblisht.m4)
   AM_WITH_LIBLISHT(_USE_LISHT)
])

feature_if([_USE_AT], [
   builtin(include, make/libat.m4)
   AM_WITH_LIBAT(_USE_AT)
])

feature_if([_USE_FRACTION], [
   builtin(include, make/libfraction.m4)
   AM_WITH_LIBFRACTION(_USE_FRACTION)
])

feature_if([_USE_XAI], [
   builtin(include, make/libxai.m4)
   AM_WITH_LIBXAI(_USE_XAI)
])

feature_if([_USE_LISP], [
   builtin(include, make/liblisp.m4)
   AM_WITH_LIBLISP(_USE_LISP)
])

feature_if([_USE_SETUP], [
   builtin(include, make/libsetup.m4)
   AM_WITH_LIBSETUP(_USE_SETUP)
])

feature_if([_USE_LIBCONFIG], [
   builtin(include, make/libconfig.m4)
   AM_WITH_LIBCONFIG(_USE_LIBCONFIG)
])

feature_if([_USE_BEX], [
    builtin(include, make/libbex.m4)
    AM_WITH_LIBBEX(_USE_BEX)
])

feature_if([_USE_BINUTILS], [
    builtin(include, make/binutils.m4)
    AM_WITH_BINUTILS(_USE_BINUTILS)
])

feature_if([_USE_LIBRARY], [
    builtin(include, make/library.m4)
    AM_WITH_LIBRARY(_USE_LIBRARY)
])

feature_if([_USE_LIBRANDOM], [
    builtin(include, make/librandom.m4)
    AM_WITH_LIBRANDOM(_USE_LIBRANDOM)
])

feature_if([_USE_LIBCRL], [
    builtin(include, make/libcrl.m4)
    AM_WITH_LIBCRL(_USE_LIBCRL)
])

dnl erwin also checks for gcc, but it is not always used, so
dnl the following code does these checks


MK_CONDITION([GNUG], [test "x${GXX}" = xyes])
MK_CONDITION([GXX],  [test "x${GXX}" = xyes])
MK_CONDITION([GNUC], [test "x${GCC}" = xyes])
MK_CONDITION([GCC],  [test "x${GCC}" = xyes])

AC_PROG_CPP

feature_if([_USE_PAG], [
    builtin(include, make/acfm.m4)
    FM_CHECK_PAG
    LDFLAGS="$LDFLAGS -L$PAGPATH/lib/pag"
    dnl AC_CHECK_LIB(pag, main,, AC_ERROR(This library is needed with ERD enabled.))
    LIBS="-lpag $LIBS"
    WIN_LIBS="pag $WIN_LIBS"

    PAG="$PAGPATH/bin/pag"
    AC_SUBST(PAG)

    PAG_FRONTEND=${PAG_DEFAULT_FRONTEND-none}
    AC_SUBST(PAG_FRONTEND)

    KFG_INTERFACE=0
    AC_SUBST(KFG_INTERFACE)

    AC_ARG_WITH(pag-frontend,
    [  --with-pag-frontend=NAME
                          which frontend to use for PAG], [
        PAG_FRONTEND="${withval}"
    ])

    dnl Possibly disable checks for some frontends if a specific frontend is
    dnl explicitly selected:
    if test "x${PAG_FRONTEND}" = xnone; then :; else
        with_crl2front=no
        with_crlfront=no
        eval "with_${PAG_FRONTEND}front=yes"
    fi
])

dnl Check for frontends:
feature_if([_USE_CRL2FRONT], [
    builtin(include, make/crl2front.m4)
    AM_WITH_CRL2FRONT(_USE_CRL2FRONT)
])
feature_if([_USE_CRLFRONT], [
    builtin(include, make/crlfront.m4)
    AM_WITH_CRLFRONT(_USE_CRLFRONT)
])


dnl Check which aica library to use (depends on used frontend):
feature_if(feature_or([_USE_LIBAICA], [_USE_LIBAICA2]), [
    builtin(include, make/libaica.m4)

    if test "x$KFG_INTERFACE" = x2; then
        true
		feature_if([_USE_LIBAICA2], [
            AM_WITH_LIBAICA(_USE_LIBAICA2, aica2, ${PAG_FRONTEND}f)
        ])
    else
        true
        feature_if([_USE_LIBAICA], [
            AM_WITH_LIBAICA(_USE_LIBAICA, aica, ${PAG_FRONTEND}f)
        ])
    fi
])

dnl The very same for libpathan (NYI):
feature_if(feature_or([_USE_PATHAN], [_USE_PATHAN2]), [
    builtin(include, make/libpathan.m4)

    if test "x$KFG_INTERFACE" = x2; then
        true
        feature_if([_USE_PATHAN2], [
            AM_WITH_LIBPATHAN(_USE_PATHAN, pathan2)
        ])
    else
        true
        feature_if([_USE_PATHAN], [
            AM_WITH_LIBPATHAN(_USE_PATHAN2, pathan)
        ])
    fi
])

dnl from Erwin:
dnl
dnl AC_PREFIX_PROGRAM is broken in several ways.  This hopefully fixes the
dnl problems:
dnl     a) minus in paths,
dnl     b) does not chop of /bin,
dnl     c) finds programs in ./
dnl
AC_DEFUN(HT_PREFIX_PROGRAM,
[
if test "x$prefix" = xNONE; then
changequote(<<, >>)dnl
define(<<ER_VAR_NAME>>, translit($1, <<-a-z>>, <<_A-Z>>))dnl
changequote([, ])dnl
dnl We reimplement AC_MSG_CHECKING (mostly) to avoid the ... in the middle.
echo $ac_n "checking for prefix by $ac_c" 1>&AC_FD_MSG
ac_OLD_PATH="$PATH"
PATH="`echo $PATH | sed 's@^\.[$]@@'  | sed 's@^\.:@@'  | sed 's@:\.[$]@@'  | sed 's@:\.:@:@g'`"
PATH="`echo $PATH | sed 's@^\./[$]@@' | sed 's@^\./:@@' | sed 's@:\./[$]@@' | sed 's@:\./:@:@g'`"
AC_PATH_PROG(ER_VAR_NAME, $1)
PATH="$ac_OLD_PATH"
changequote(<<, >>)dnl
  if test -n "$ac_cv_path_<<>>ER_VAR_NAME"; then
    prefix=`echo $ac_cv_path_<<>>ER_VAR_NAME|sed 's%/[^/][^/]*//*[^/][^/]*$%%'`
changequote([, ])dnl
  fi
fi
undefine([ER_VAR_NAME])dnl
])

AC_PROG_MAKE_SET
AC_PROG_INSTALL
AC_PROG_LN_S

AC_PROG_RANLIB

AC_PATH_PROGS(AR,           ar)

AC_PATH_PROGS(PERL,         perl, [:])
AC_PATH_PROGS(PERL_OR_ERR,  perl, [_no_perl_])

AC_PATH_PROGS(CLISP,         clisp, [:])
AC_PATH_PROGS(CLISP_OR_ERR,  clisp, [_no_clisp_])

AC_PATH_PROGS(BISON,  bison)
AC_PATH_PROGS(FLEX,   flex)
AC_PATH_PROGS(M4,     m4)

AC_CHECK_PROGS(GPERF,       gperf, [:])

dnl The following are also part of Erwin, but they can be used as standalone tools.
dnl These are checked with and without path, so you can make dependencies on them
dnl in Makefiles.
AC_CHECK_PROGS(MAKEFAILURE,     assert.pl)
AC_PATH_PROGS(PATH_MAKEFAILURE, assert.pl)

AC_CHECK_PROGS(MAKESYMBOL,      makesymbol.pl)
AC_PATH_PROGS(PATH_MAKESYMBOL,  makesymbol.pl)

AC_CHECK_PROGS(MAKELOOKUP,      makelookup.pl)
AC_PATH_PROGS(PATH_MAKELOOKUP,  makelookup.pl)

AC_CHECK_PROGS(ERWIN_CGEN,      erwin-cgen)
AC_PATH_PROGS(PATH_ERWIN_CGEN,  erwin-cgen)

AC_SUBST(DOXYGEN)
feature_if([_USE_DOXYGEN], [
   AC_CHECK_PROGS(DOXYGEN, doxygen, [:])
])
DOXYGEN=${DOXYGEN-:}

AC_SUBST(PATTERN)
feature_if([_USE_PATTERN], [
    AC_PATH_PROGS(PATTERN, pattern)
    if test "x$PATTERN" = x; then
        if test x""_USE_PATTERN != xoptional; then
            AC_MSG_ERROR([This program is needed.])
        fi
    fi
])
PATTERN=${PATTERN-:}

WINCPPFLAGS="$WINCPPFLAGS /D_CRT_SECURE_NO_DEPRECATE /D_CRT_NONSTDC_NO_DEPRECATE"

AC_ARG_ENABLE(release,
[  --enable-release        Enable release version.  This sets -DRELEASE, removes a
                          possible -g flag, sets /RELEASE under Windows, and makes
                          'make install' strip executables.],,
[
    if echo "$CPPFLAGS" | grep -- '-DRELEASE' > /dev/null 2>&1
    then
        enable_release=yes
    fi
])
if test "x$enable_release" = xyes; then
    CXXFLAGSAUX="$CXXFLAGS" CXXFLAGS=`echo "$CXXFLAGSAUX" | sed s@-g@@g`
    CFLAGSAUX="$CFLAGS" CFLAGS=`echo "$CFLAGSAUX" | sed s@-g@@g`
    RELEASE=1
    CPPFLAGS="$CPPFLAGS -DRELEASE"
    WINCPPFLAGS="$WINCPPFLAGS /DRELEASE"
    WINLDFLAGS="$WINLDFLAGS /RELEASE"
    if test "x$GCC" = xyes; then
        CFLAGS="$CFLAGS -Wno-unused"
        dnl -freg-struct-return
    fi
    if test "x$GXX" = xyes; then
        CXXFLAGS="$CXXFLAGS -Wno-unused"
    fi
else
    RELEASE=0
fi
AC_SUBST(RELEASE)

AC_ARG_ENABLE(ndebug,
[  --enable-ndebug         Enables no-debug version.  This sets -DNDEBUG and adds
                          compilation options that obfuscate gcc's output],,
[
    if echo "$CPPFLAGS" | grep -- '-DNDEBUG' > /dev/null 2>&1
    then
        enable_ndebug=yes
    fi
])
if test "x$enable_ndebug" = xyes; then
    NDEBUG=1
    CPPFLAGS="$CPPFLAGS -DNDEBUG"
    WINCPPFLAGS="$WINCPPFLAGS /DNDEBUG"
    dnl if test "x$GCC" = xyes; then
        dnl CFLAGS="$CFLAGS -fomit-frame-pointer -Wno-unused"
        dnl -freg-struct-return
    dnl fi
    dnl if test "x$GXX" = xyes; then
        dnl CXXFLAGS="$CXXFLAGS -fomit-frame-pointer -Wno-unused"
    dnl fi
else
    NDEBUG=0
fi
AC_SUBST(NDEBUG)

AC_ARG_ENABLE(debug,
[  --enable-debug          enable Windows debugging]
[  --enable-debug=Dd       enable Windows debugging with library /MDd],,[enable_debug=no])
if test "x$enable_debug" = xDd; then
      WINCFLAGS="$WINCFLAGS   /Zi /GX /Gs /Yd /Od /MDd"
    WINCXXFLAGS="$WINCXXFLAGS /Zi /GX /Gs /Yd /Od /MDd"
     WINLDFLAGS="$WINLDFLAGS  /NODEFAULTLIB:msvcrt /NODEFAULTLIB:libc"
elif test "x$enable_debug" = xno; then
      WINCFLAGS="$WINCFLAGS /O2 /MD"    dnl not /Ox or /Ob2
    WINCXXFLAGS="$WINCXXFLAGS /O2 /MD"
else
      WINCFLAGS="$WINCFLAGS   /Zi /GX /Gs /Yd /Od /MD"
    WINCXXFLAGS="$WINCXXFLAGS /Zi /GX /Gs /Yd /Od /MD"
      WINLDFLAGS="$WINLDFLAGS /DEBUG"
fi

FUNDAMENTAL_MODE="-*- Mode: Fundamental -*-"
AC_SUBST(FUNDAMENTAL_MODE)

define([RESOLVE_DIR],
   [[$1]="`cd [$2] && pwd`"])

define([RESOLVE_PATH], [
   __help="`dirname \"[$2]\"`"
   RESOLVE_DIR([__help2], [$__help])
   [$1]="$__help2/`basename \"[$2]\"`"
])

# local variables for the package:
packagedocdir=${packagedocdir-'${datadir}/doc/packages'}
AC_SUBST(packagedocdir)

mydocdir=${mydocdir-'${packagedocdir}/${PROGNAME}'}
AC_SUBST(mydocdir)

mydatadir=${mydatadir-'${datadir}/${PROGNAME}'}
AC_SUBST(mydatadir)

mysysconfdir=${mysysconfdir-'${sysconfdir}/${PROGNAME}'}
AC_SUBST(mysysconfdir)

mysharedstatedir=${mysharedstatedir-'${sharedstatedir}/${PROGNAME}'}
AC_SUBST(mysharedstatedir)

mylocalstatedir=${mylocalstatedir-'${localstatedir}/${PROGNAME}'}
AC_SUBST(mylocalstatedir)

mylibexecdir=${mylibexecdir-'${libexecdir}/${PROGNAME}'}
AC_SUBST(mylibexecdir)

ifdef([m4_PACKAGE_VERSION],[
dnl I don't know when HELP_BEGIN was introduced.  It must have been
dnl between 2.13 and 2.57.  In the same range of versions, the macro
dnl m4_PACKAGE_VERSION was added.  Therefore I check for that variable.
dnl
dnl NOTE: This code does not actually break 2.13, it is just not shown
dnl       if the divisions are differently used than in 2.57.  I protect
dnl       it with an ifdef() anyway just to be sure.
dnl
m4_divert_push([HELP_BEGIN])
m4_changequote(`,')dnl
Exact installation directories for this package:
  packagedocdir=DIR      documentation [DATADIR/doc/packages]
  mydocdir=DIR           documentation [PACKAGEDOCDIR/_PROGNAME]
  mylibexecdir=DIR       program executables [LIBEXECDIR/_PROGNAME]
  mydatadir=DIR          read-only arch-independent data [DATADIR/_PROGNAME]
  mysysconfdir=DIR       read-only single-machine data [SYSCONFDIR/_PROGNAME]
  mysharedstatedir=DIR   modifiable arch-indep. data [SHAREDSTATEDIR/_PROGNAME]
  mylocalstatedir=DIR    modifiable single mach. data [LOCALSTATEDIR/_PROGNAME]
  (Note that all these options are specified without -- in front, since
  they are all normal shell variables.)
m4_changequote([,])dnl
m4_divert_pop([HELP_BEGIN])
])


RESOLVE_DIR([resolved_top_srcdir], [$srcdir])
AC_SUBST(resolved_top_srcdir)
   dnl Note: srcdir here is top_srcdir for all sub-directories that
   dnl       are configured by this script.  It is always the
   dnl       where the configure script resides.

AC_SUBST(BASE_VERSION)
AC_SUBST(PROGNAME)
AC_SUBST(MORE_CPPFLAGS)
AC_SUBST(MORE_CFLAGS)
AC_SUBST(MORE_CXXFLAGS)
AC_SUBST(MORE_LDFLAGS)
AC_SUBST(WINCPPFLAGS)
AC_SUBST(WINCFLAGS)
AC_SUBST(WINCXXFLAGS)
AC_SUBST(WINLDFLAGS)

AC_SUBST(LAMBDA)
AC_SUBST(ODVIPS)
AC_SUBST(LATEX)
AC_SUBST(DVIPS)

AC_PATH_PROGS(SVN, svn, [:])

ifelse(_USE_ERWIN,,[
    AC_PATH_PROGS(LAMBDA, uklambda lambda, [:])
    AC_PATH_PROGS(ODVIPS, odvips, [:])
    AC_PATH_PROGS(LATEX,  uklambda lambda uklatex latex, [:])
    AC_PATH_PROGS(DVIPS,  odvips dvips, [:])
],[
    ER_CONFIG_ERWIN
    ER_PROG_LATEX
       dnl This is somewhat more complicated and it has extra checks for version 2e.
])

RESOLVE_PATH([INSTALL], [$INSTALL])

