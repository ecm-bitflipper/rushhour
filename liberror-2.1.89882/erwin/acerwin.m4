dnl -*- Mode: M4 -*-

dnl
dnl To include this, add the following line to aclocal.m4 (or acinclude.m4 for automake):
dnl
dnl aclocal.m4/acinclude.m4:
dnl     builtin(include,erwin/acerwin.m4)
dnl
dnl If you are using automake, and want to use ER_PROG_CXX or ER_PROG_CC, you should
dnl either run AC_PROG_CXX and AC_PROG_CC before (but note that ER_PROG_CXX searches
dnl for a C++ compiler more thoroughly when the standard C++ library is not needed),
dnl or include a comment:
dnl
dnl configure.in:
dnl     # look, automake: AC_PROG_CC
dnl     ER_PROG_CC
dnl     # look, automake: AC_PROG_CXX
dnl     ER_PROG_CXX
dnl

AC_DEFUN([ER_FILTER_GNU_WARNING_OPTIONS], [
    dnl define([er_flag_vars_CFLAGS_old], defn([er_flag_vars_CFLAGS]))
    dnl define([er_flag_vars_CFLAGS], defn([er_flag_vars_CFLAGS])[,_old2_CFLAGS])
    _old2_CFLAGS="`for i in $CFLAGS; do case $i in -W*|-w) echo $i;;esac; done`"
    CFLAGS="`for i in $CFLAGS; do case $i in -W*|-w);; *) echo $i;;esac; done` $1"

    dnl define([er_flag_vars_CXXFLAGS_old], defn([er_flag_vars_CXXFLAGS]))
    dnl define([er_flag_vars_CXXFLAGS], defn([er_flag_vars_CXXFLAGS])[,old2_CXXFLAGS])
    _old2_CXXFLAGS="`for i in $CXXFLAGS; do case $i in -W*|-w) echo $i;;esac; done`"
    CXXFLAGS="`for i in $CXXFLAGS; do case $i in -W*|-w);; *) echo $i;;esac; done` $1"

    $2

    CFLAGS="`for i in $CFLAGS; do case $i in $1);; *) echo $i;;esac; done`"
    CFLAGS="`echo $_old2_CFLAGS $CFLAGS`"
    dnl define([er_flag_vars_CXXFLAGS], defn([er_flag_vars_CXXFLAGS_old]))

    CXXFLAGS="`for i in $CXXFLAGS; do case $i in $1);; *) echo $i;;esac; done`"
    CXXFLAGS="`echo $_old2_CXXFLAGS $CXXFLAGS`"
    dnl define([er_flag_vars_CXXFLAGS], defn([er_flag_vars_CXXFLAGS_old]))
])

dnl
dnl Quote an option name to form a valid cv-variable.
dnl    $1 - the option
dnl    $2 - the family (e.g. CFLAGS, CXXFLAGS, ...)
dnl
define([er_quote_var],
[changequote(<<,>>)dnl
patsubst(er_cv_<<$1>>_<<$2>>, <<[-/+\\="' 	]>>, <<_>>)<<>>dnl "
changequote([,])dnl
])

dnl
dnl Return the first element of a list
dnl
define([er_first],[[$1]])

dnl
dnl Map a function to several arguments
dnl   $1         - the function
dnl   all others - arguments
dnl
define([er_map],[
ifelse(
[$#],0,
,
[$#],1,
,
[$2],,
,
[$#],2,
[indir([$1],[$2])],
[indir([$1],[$2])
er_map([$1],builtin([shift],builtin([shift],$@)))])])

dnl
dnl AC_PREFIX_PROGRAM is broken in several ways.  This hopefully fixes the
dnl problems:
dnl     a) minus in paths,
dnl     b) does not chop of /bin,
dnl     c) finds programs in ./
dnl
AC_DEFUN(ER_PREFIX_PROGRAM,
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

dnl   
dnl If the compiler understands it, add an option to the given variables.
dnl   $1 - Flag to test
dnl        This may be a list of flags: they will all be passed to the
dnl        compiler, but only the first will be added to the variables.
dnl   $2 - Variables to add to (may be a comma separated list)
dnl        The first variable will the used as the family name, i.e.
dnl        for forming the er_cv_ cache variable name.
dnl   $3 - the thing that is tested (e.g. 'the C++ compiler')
dnl   $4 - Test to use (ER_VAR_NAME has to be set to yes or no)
dnl        (if this is empty, AC_TRY_LINK will be used.)
dnl   $5 - (optional) command to switch language (e.g. AC_LANG_CPLUSPLUS)
dnl
dnl You are really crazy if you can understand this macro without thinking for an hour.
dnl
AC_DEFUN([ER_ADD_FLAG],[
define([ER_VAR_NAME], er_quote_var(er_first($2),[$1]))
define([er_add_to_var],[
er_old_$][1="$$][1"
$][1="$$][1 [$1]"])
define([er_add_to_var_first],[
er_old_$][1="$$][1"
$][1="$$][1 er_first($1)"])
er_map([er_add_to_var],$2)
ifelse([$5],,,[AC_LANG_SAVE])[]dnl
ifelse([$5],,,[$5])[]dnl
AC_CACHE_CHECK(whether [$3] accepts [$1], ER_VAR_NAME,
    ifelse([$4],,[AC_TRY_LINK(,, ER_VAR_NAME=yes, ER_VAR_NAME=no)],[$4]))
ifelse([$5],,,[AC_LANG_RESTORE])[]dnl
define([er_restore_var],[
$][1="$er_old_$][1"])
er_map([er_restore_var],$2)
if test "x$ER_VAR_NAME" = "xyes"; then
   er_map([er_add_to_var_first],$2)
fi
undefine([er_add_to_var])
undefine([er_restore_var])
undefine([ER_VAR_NAME])
])

dnl
dnl Run $1 if we use GNU C (requires AC_PROG_CC)
dnl
AC_DEFUN([ER_IF_GCC],[
if test "x${GCC}" = xyes; then
   $1
ifelse($2,,,[
else
   $2
])
fi
])

dnl
dnl Run $1 if we use GNU C++ (requires AC_PROG_CXX)
dnl
AC_DEFUN([ER_IF_GXX],[
if test "x${GXX}" = xyes; then
   $1
ifelse([$2],,,[
else
   $2
])
fi
])

dnl
dnl $1: prefix of variable
dnl $2: condition (for the shell), e.g. test "x${GXX}" = xyes
dnl
AC_DEFUN([ER_CONDITION],[
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

AC_DEFUN([ER_IS_GCC],[
GNUC_TRUE=' # '
GNUC_FALSE=''
GCC_TRUE=' # '
GCC_FALSE=''
ER_IF_GCC([
GNUC_TRUE=''
GNUC_FALSE=' # '
GCC_TRUE=''
GCC_FALSE=' # '
])
AC_SUBST(GNUC_TRUE)
AC_SUBST(GNUC_FALSE)
AC_SUBST(GCC_TRUE)
AC_SUBST(GCC_FALSE)
])

AC_DEFUN([ER_IS_GXX],[
GNUG_TRUE=' # '
GNUG_FALSE=''
GXX_TRUE=' # '
GXX_FALSE=''
ER_IF_GXX([
GNUG_TRUE=''
GXX_TRUE=''
GNUG_FALSE=' # '
GXX_FALSE=' # '
])
AC_SUBST(GNUG_TRUE)
AC_SUBST(GNUG_FALSE)
AC_SUBST(GXX_TRUE)
AC_SUBST(GXX_FALSE)
])

dnl ----------------------------------------------------------------------

define([er_flag_vars_CPPFLAGS],[])
define([er_flag_vars_CXXFLAGS],[])
define([er_flag_vars_CFLAGS],[])
define([er_flag_vars_LDFLAGS],[])
define([er_flag_vars_LIBS],[])

AC_DEFUN([er_add_accu],
[define([er_flag_vars_$1],defn([er_flag_vars_$1])[,$2])])

dnl
dnl For a protocol for ER_ADD_XY in another variable, use the following macros:
dnl
AC_DEFUN([ER_USE_ACCU],
[er_oldold_[$1]="$[$1]"
er_add_accu([$1],[$2])])

AC_DEFUN([ER_RESET_ACCU],
[define([er_flag_vars_$1],[])
[$1]="$er_oldold_[$1]"
])


dnl
dnl Check for a CXXFLAG with C++ compiler
dnl
AC_DEFUN([ER_ADD_CXXFLAG],
[if test "x${with_cxx}" != xno; then
    ER_ADD_FLAG(
        [$1],
        [CXXFLAGS]defn([er_flag_vars_CXXFLAGS]),
        [the C++ compiler],
        [],
        [AC_LANG_CPLUSPLUS])
fi
])

AC_DEFUN([ER_ADD_CXXFLAGS], [er_map([ER_ADD_CXXFLAG],$@)])
AC_DEFUN([ER_ADD_GNU_CXXFLAGS], [
    ER_IF_GXX([
        ER_FILTER_GNU_WARNING_OPTIONS(-Werror, [
            ER_ADD_CXXFLAGS($@)
        ])
    ])
])

dnl
dnl Check for a CFLAG with C compiler
dnl
AC_DEFUN([ER_ADD_CFLAG],
[
dnl autoconf is broken, we need CC
dnl if test "x${with_cc}" != xno; then
    ER_ADD_FLAG(
        [$1],
        [CFLAGS]defn([er_flag_vars_CFLAGS]),
        [the C compiler],
        [],
        [AC_LANG_C])
dnl fi
])

AC_DEFUN([ER_ADD_CFLAGS], [er_map([ER_ADD_CFLAG],$@)])
AC_DEFUN([ER_ADD_GNU_CFLAGS], [
    ER_IF_GCC([
        # checking flags: $@
        ER_FILTER_GNU_WARNING_OPTIONS(-Werror, [
            ER_ADD_CFLAGS($@)
        ])
    ])
])

dnl
dnl If the preprocessor understands it, add an option to the CPPFLAGS.
dnl
AC_DEFUN([ER_ADD_CPPFLAG],
[
    ER_ADD_FLAG(
        [$1],
        [CPPFLAGS]defn([er_flag_vars_CPPFLAGS]),
        [the C/C++ preprocessor],
        [AC_TRY_CPP(, ER_VAR_NAME=yes, ER_VAR_NAME=no)])
])

AC_DEFUN([ER_ADD_CPPFLAGS], [er_map([ER_ADD_CPPFLAG],$@)])
AC_DEFUN([ER_ADD_GNU_CPPFLAGS], [ER_IF_GCC(ER_ADD_CPPFLAGS($@))])

dnl
dnl If the linker understands it, add an option to the LDFLAGS.
dnl
AC_DEFUN([ER_ADD_LDFLAG],
    [ER_ADD_FLAG(
        [$1],
        [LDFLAGS]defn([er_flag_vars_LDFLAGS]),
        [the C/C++ linker])])

AC_DEFUN([ER_ADD_LDFLAGS], [er_map([ER_ADD_LDFLAG],$@)])
AC_DEFUN([ER_ADD_GNU_LDFLAGS], [ER_IF_GCC(ER_ADD_LDFLAGS($@))])

dnl
dnl If the linker understands it, add an option to the LIBS.
dnl
AC_DEFUN([ER_ADD_LIB],
    [ER_ADD_FLAG(
        [$1],
        [LIBS]defn([er_flag_vars_LIBS]),
        [the C/C++ linker])])

AC_DEFUN([ER_ADD_LIBS], [er_map([ER_ADD_LIB],$@)])
AC_DEFUN([ER_ADD_GNU_LIBS], [ER_IF_GCC(ER_ADD_LIBS($@))])

dnl ----------------------------------------------------------------------

dnl
dnl Add a --disable/enable-opt(=max) option to the command line
dnl
AC_DEFUN([ER_ARG_ENABLE_OPT], [
AC_ARG_ENABLE(opt,
[  --disable-opt           gcc only: set optimisation level to 0
  --enable-opt            gcc: enable some optimisations
  --enable-opt=max        gcc: set maximal optimisation level
                               also switches off debugging support
  --enable-opt=unsafe     gcc: set maximal unsafe optimisation level])
])

dnl
dnl Release
dnl
AC_DEFUN([ER_ARG_ENABLE_RELEASE], [
AC_ARG_ENABLE(release,
[  --enable-release        switches off debug symbols (-g) and sets -DRELEASE],,
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
else
    RELEASE=0
fi
AC_SUBST(RELEASE)
])

dnl
dnl NDEBUG
dnl
AC_DEFUN([ER_ARG_ENABLE_NDEBUG], [
AC_ARG_ENABLE(ndebug,
[  --enable-ndebug         disables assertions, sets -DNDEBUG (but does not touch -g)],,
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
else
    NDEBUG=0
fi
AC_SUBST(NDEBUG)
])

dnl
dnl acconfig.h: /* User en-/disabled long long support */
dnl acconfig.h: #undef CONFIG_WITH_LONG_LONG
dnl
AC_DEFUN([ER_ARG_LONG_LONG], [
AC_ARG_WITH(long-long,
[  --without-long-long     do not support 64 bit integers even if the compiler
                          handles them well])

if test "x${with_long_long}" != xno; then
    AC_DEFINE(CONFIG_WITH_LONG_LONG, 1, [whether 64-bit ints shall be used])
fi
])

dnl ----------------------------------------------------------------------
dnl This checks whether the C++ compiler works.  If it does not link, it
dnl tries whether it works without stdlib (i.e., it uses the C compiler. This
dnl works for gcc.  We could also try to use -nostdlib.
dnl
dnl You can define the following M4 variables to 1 to influence the behaviour of
dnl this macro:
dnl     er_need_cxxlib
dnl          prevents the trial of using the C compiler for C++
dnl     er_no_warnings
dnl          prevents adding additional warning flags for GNU C++
dnl
AC_DEFUN([ER_PROG_CXX], [
WITH_CXX=""
WITHOUT_CXX="# "
AC_SUBST(WITH_CXX)
AC_SUBST(WITHOUT_CXX)

if test x${with_cxx} = xno
then
    CXX=":"
    CXXCPP=":"
    CXXFLAGS=""
    WITH_CXX="# "
    WITHOUT_CXX=""
    AC_SUBST(CXX)
    AC_SUBST(CXXCPP)
    AC_SUBST(CXXFLAGS)
else
    if test "${GXX+set}" != set; then
        dnl Hacks to work around 'exit 1' if the C++ compiler does not work.
        dnl we will try again to compile a C++ program with the C compiler, this
        dnl is sensible only if no C++ library is needed.
        ifelse(er_need_cxxlib,1,
        [AC_PROG_CXX],
        [
            define([er_old_AC_MSG_ERROR],defn([AC_MSG_ERROR]))
            define([AC_MSG_ERROR],[:])
            AC_PROG_CXX
            define([AC_MSG_ERROR],defn([er_old_AC_MSG_ERROR]))
            if test "x$ac_cv_prog_cxx_works" = xno; then
                ifelse(er_ac_prog_cc_called,1,,
                [if test "${ac_cv_prog_CC+set}" != set; then
                    define([er_old_er_no_warnigs],defn([er_no_warnings]))
                    define([er_no_warnings],1)
                    AC_PROG_CC
                    define([er_no_warnings],defn([er_old_er_no_warnings]))
                fi])
                ac_cv_prog_CXX="$ac_cv_prog_CC"
                CXX="$ac_cv_prog_CC"
                AC_PROG_CXX
            fi
        ])
        AC_PROG_CXXCPP
    fi

    _has_O="`for i in $CXXFLAGS; do case $i in -O*) echo $i;;esac; done`"
    if test "x$_has_O" = x;  then
        ER_ADD_GNU_CXXFLAGS(-O2)
    fi
    _has_g="`for i in $CXXFLAGS; do case $i in -g*) echo $i;;esac; done`"
    if test "x$_has_g" = x;  then
        ER_ADD_GNU_CXXFLAGS(-g)
    fi
    ifelse(er_no_warnings,1,,
        [ER_ADD_GNU_CXXFLAGS(
            -Wall,
            -W,
            -Wpointer-arith,
            -Wno-cast-align,
            -Woverloaded-virtual)])

    if test x"$enable_opt" = xno; then
        CXXFLAGSAUX="$CXXFLAGS" CXXFLAGS=`echo "$CXXFLAGSAUX" | sed 's@-g[[-_0-9a-z]]*@@g' | sed 's@-O[[-_0-9a-z]]*@@g'`
        ER_ADD_GNU_CXXFLAGS(
           -O0,
           -fno-inline,
           -g)
        ER_ADD_CXXFLAGS($1)
    else
        if test x"$enable_opt" = xyes; then
            CXXFLAGSAUX="$CXXFLAGS" CXXFLAGS=`echo "$CXXFLAGSAUX" | sed 's@-g[[-_0-9a-z]]*@@g' | sed 's@-O[[-_0-9a-z]]*@@g'`
            ER_ADD_GNU_CXXFLAGS(-O2,-g)
            ER_ADD_CXXFLAGS($2)
        else
            if test x"$enable_opt" = xmax; then
                CXXFLAGSAUX="$CXXFLAGS" CXXFLAGS=`echo "$CXXFLAGSAUX" | sed 's@-g[[-_0-9a-z]]*@@g' | sed 's@-O[[-_0-9a-z]]*@@g'`
                ER_ADD_GNU_CXXFLAGS(
                    -O2,
                    -finline-functions,
                    -fomit-frame-pointer,
                    -ffast-math)
                ER_ADD_CXXFLAGS($2)
            else
                if test x"$enable_opt" = xunsafe; then
                    CXXFLAGSAUX="$CXXFLAGS" CXXFLAGS=`echo "$CXXFLAGSAUX" | sed 's@-g[[-_0-9a-z]]*@@g' | sed 's@-O[[-_0-9a-z]]*@@g'`
                    ER_ADD_GNU_CXXFLAGS(
                        -O9,
                        -finline-functions,
                        -fomit-frame-pointer,
                        -ffast-math)
                    ER_ADD_CXXFLAGS($2)
                fi
            fi
        fi
    fi
fi
ER_IS_GXX
])

AC_DEFUN([ER_MANY_CC_WARNINGS],
[ER_ADD_GNU_CFLAGS(
    -Wundef,
    -Wmissing-format-attribute,
    -Wstrict-prototypes,
    -Wwrite-strings)
])

AC_DEFUN([ER_SPECIAL_CFLAGS],[])

AC_DEFUN([ER_MANY_CXX_WARNINGS],
[ER_ADD_GNU_CXXFLAGS(
    -Wundef,
    -Wmissing-format-attribute,
    -Wconversion,
    -Wwrite-strings,
    -Wenum-clash,
    -Wsign-promo)
])
dnl    -Weffc++,    No, I cannot tell the compiler in which case I mean what I write.
dnl                 Instead, I choose no such warnings.


AC_DEFUN([ER_SPECIAL_CXXFLAGS],
[ER_ADD_GNU_CXXFLAGS(
    -fno-rtti,
    -felide-constructors,
    -fno-exceptions)
])

dnl add many warnings for C and C++
AC_DEFUN([ER_MANY_WARNINGS],
[ER_MANY_CC_WARNINGS
ER_MANY_CXX_WARNINGS])

AC_DEFUN([ER_SPECIAL_FLAGS],
[ER_SPECIAL_CFLAGS
ER_SPECIAL_CXXFLAGS])


AC_DEFUN([ER_ARG_WITH_CXX],
[AC_ARG_WITH(cxx,
[  --without-cxx           disables C++ parts of library
  --with-cxx              enables C++ parts of library])
])

AC_DEFUN([ER_ARG_WITH_CC],
[AC_ARG_WITH(cc,
[  --without-cc            disables C parts of library
  --with-cc               enables C parts of library])
])

AC_DEFUN([ER_PROG_CC], [
WITH_CC=""
WITHOUT_CC="# "
AC_SUBST(WITH_CC)
AC_SUBST(WITHOUT_CC)

dnl if test x${with_cc} = xno
dnl then
dnl     CC=":"
dnl     CPP=":"
dnl     CCFLAGS=""
dnl     WITH_CC="# "
dnl     WITHOUT_CC=""
dnl     AC_SUBST(CC)
dnl     AC_SUBST(CPP)
dnl     AC_SUBST(CCFLAGS)
dnl else
    if test "${GCC+set}" != set; then
        define([er_ac_prog_cc_called],1)
        AC_PROG_CC
        AC_PROG_CPP
    fi

    _has_O="`for i in $CFLAGS; do case $i in -O*) echo $i;;esac; done`"
    if test "x$_has_O" = x;  then
        ER_ADD_GNU_CFLAGS(-O2)
    fi
    _has_g="`for i in $CFLAGS; do case $i in -g*) echo $i;;esac; done`"
    if test "x$_has_g" = x;  then
        ER_ADD_GNU_CFLAGS(-g)
    fi
    ifelse(er_no_warnings,1,,
        [ER_ADD_GNU_CFLAGS(
            -Wall,
            -W,
            -Wpointer-arith,
            -Wno-cast-align,
            -Wmissing-prototypes)])

    if test x"$enable_opt" = xno; then
        CFLAGSAUX="$CFLAGS" CFLAGS=`echo "$CFLAGSAUX" | sed 's@-g[[-_0-9a-z]]*@@g' | sed 's@-O[[-_0-9a-z]]*@@g'`
        ER_ADD_GNU_CFLAGS(
            -O0,
            -fno-inline,
            -g)
        ER_ADD_CFLAGS($1)
    else
        if test x"$enable_opt" = xmax; then
            CFLAGSAUX="$CFLAGS" CFLAGS=`echo "$CFLAGSAUX" | sed 's@-g[[-_0-9a-z]]*@@g' | sed 's@-O[[-_0-9a-z]]*@@g'`
            ER_ADD_GNU_CFLAGS(
                -O9,
                -finline-functions,
                -fomit-frame-pointer,
                -ffast-math)
            ER_ADD_CFLAGS($2)
        fi
    fi
dnl fi
ER_IS_GCC
])

dnl
dnl acconfig: /* Are ctype function broken for 8 bit characters? */
dnl acconfig: #undef BROKEN_CTYPE
dnl
AC_DEFUN([ER_BROKEN_CTYPE], [
AC_CACHE_CHECK(whether ctype functions are broken for 8 bit characters, er_cv_broken_ctype, [
   AC_TRY_LINK([
#include <stdlib.h>
#include <ctype.h>
],
[
        int i;

        if (isspace (129)) exit (EXIT_FAILURE);
        if (isspace (255)) exit (EXIT_FAILURE);
        if (toupper ('a') != 'A') exit(EXIT_FAILURE);
        if (toupper ('A') != 'A') exit(EXIT_FAILURE);
        if (tolower ('A') != 'a') exit(EXIT_FAILURE);
        if (tolower ('a') != 'a') exit(EXIT_FAILURE);

        for (i=-128; i < 255; i++) {
            (void)isspace (i);
            (void)isalpha (i);
            (void)isdigit (i);
            (void)tolower (i);
            (void)toupper (i);
        }

        exit (EXIT_SUCCESS);
],
er_cv_broken_ctype=no,
er_cv_broken_ctype=yes)])

if test x"$er_cv_broken_type" = xyes; then
    AC_DEFINE(BROKEN_CTYPE, 1, [whether ctype definitions are broken])
fi

AC_SUBST(BROKEN_CTYPE)
])

dnl
dnl Wrapper around AC_CHECK_FUNCS and AC_CHECK_DECLS
dnl
AC_DEFUN([ER_HAVE_FUNC],[
  AC_CHECK_DECLS([$1],[
    AC_CHECK_FUNCS([$1])
  ],[],[$2])
])

dnl acconfig: /* Does the C++ compiler have a working 'mutable' keyword? */
dnl acconfig: #undef HAVE_WORKING_MUTABLE
dnl
dnl Define whether C++ compiler understands mutable.
dnl
AC_DEFUN([ER_WORKING_MUTABLE], [
AC_CACHE_CHECK(whether C++ compiler honours mutable, er_cv_working_mutable, [
if test x${with_cxx} = xno; then
   er_cv_working_mutable=untested
else
   AC_LANG_SAVE
   AC_LANG_CPLUSPLUS
   AC_TRY_LINK([
#include <stdlib.h>
class A {
    mutable int i;
public:
    A (): i(0) {}
    void assign_test (void) const { i= 0; }
};

static void test (A const *a)
{
    a->assign_test ();
}
],
[
        A a;
        test (&a);

        exit (EXIT_SUCCESS);
],
er_cv_working_mutable=yes,
er_cv_working_mutable=no)
    AC_LANG_RESTORE
fi
])

if test x"$er_cv_working_mutable" = xyes; then
    AC_DEFINE(HAVE_WORKING_MUTABLE, 1, [whether C++ keyword mutable works])
fi

AC_SUBST(HAVE_WORKING_MUTABLE)
])

dnl
dnl acconfig: /* Does __thread work? */
dnl acconfig: #undef HAVE_THREAD_KEYWORD
dnl
AC_DEFUN([ER_HAVE_THREAD_KEYWORD], [
AC_CACHE_CHECK(whether __thread works, er_cv_have_thread_keyword, [
   AC_LANG_SAVE
   AC_LANG_C
   AC_TRY_LINK([
#include <stdlib.h>
static __thread int a = 1;
],
[
        exit (a == 1 ? EXIT_SUCCESS : EXIT_FAILURE);
],
er_cv_have_thread_keyword=yes,
er_cv_have_thread_keyword=no)
    AC_LANG_RESTORE
])
if test x"$er_cv_have_thread_keyword" = xyes; then
    AC_DEFINE(HAVE_THREAD_KEYWORD, 1, [whether __thread keyword works])
fi

AC_SUBST(HAVE_THREAD_KEYWORD)
])

dnl
dnl acconfig: /* Does the C++ compiler have a working 'explicit' keyword? */
dnl acconfig: #undef HAVE_WORKING_EXPLICIT
dnl
dnl Define whether C++ compiler understands explicit.
dnl
AC_DEFUN([ER_WORKING_EXPLICIT], [
AC_CACHE_CHECK(whether C++ compiler honours explicit, er_cv_working_explicit, [
if test x${with_cxx} = xno; then
   er_cv_working_explicit=untested
else
   AC_LANG_SAVE
   AC_LANG_CPLUSPLUS
   dnl Step one, check for syntax errors:
   AC_TRY_LINK([
#include <stdlib.h>
class A {
    int i;
public:
    A (): i(0) {}
    explicit A (int a): i(a) {}
};
],
[
        A a(6);
        exit (EXIT_SUCCESS);
],
er_cv_working_explicit=yes,
er_cv_working_explicit=no)

   dnl Step one, check for functionality.  If this succeeds, there is no support.
   AC_TRY_LINK([
#include <stdlib.h>
class A {
    int i;
public:
    A (): i(0) {}
    explicit A (int a): i(a) {}
};
],
[
        A a;
        a= 6;
        exit (EXIT_SUCCESS);
],
er_cv_working_explicit=no)
    AC_LANG_RESTORE
fi
])

if test x"$er_cv_working_explicit" = xyes; then
    AC_DEFINE(HAVE_WORKING_EXPLICIT, 1, [whether C++ keyword explicit works])
fi

AC_SUBST(HAVE_WORKING_EXPLICIT)
])

dnl
dnl Check for Perl.  For now, this is easy.
dnl
AC_DEFUN([ER_PROG_PERL], [AC_PATH_PROGS(PERL,perl5 perl, [:])])


dnl
dnl Check for Gnu M4
dnl
AC_DEFUN([ER_PROG_GNU_M4], [
AC_BEFORE([$0], [ER_MAKE_MAKEFILE_IN])dnl

AC_PATH_PROG(M4,m4)
if test ! -z "$M4"; then
    AC_MSG_CHECKING(whether $M4 is GNU M4)
    result="`echo 'change''quote(<,>)if''def(<__g''nu__>,<<yes>>,<<no>>)' | $M4`"
    test x"$result" = xyes || result=no
    AC_MSG_RESULT($result);
    if test x"$result" = xno; then
       M4=
    fi
fi

if test -z "$M4"; then
    AC_PATH_PROG(GM4,gm4)
    if test ! -z "$GM4"; then
        AC_MSG_CHECKING(whether $GM4 is GNU M4)
        result="`echo 'change''quote(<,>)if''def(<__g''nu__>,<<yes>>,<<no>>)' | $GM4`"
        test x"$result" = xyes || result=no
        AC_MSG_RESULT($result);
        if test x"$result" = xno; then
           GM4=
        fi
    fi
    M4="$GM4"
fi

AC_SUBST(M4)
if test -z "$M4"; then
    echo "Warning: GNU M4 is needed for the development version of this library." 1>&2
    M4=:
fi
])

dnl
dnl Generate Makefile.in from Makefile.m4 for some directories
dnl
AC_DEFUN([ER_MAKE_MAKEFILE_IN], [
for i in [$1]; do
   if test ! -f $i/Makefile.in; then
       (cd $i
           echo "creating $i/Makefile.in from $i/Makefile.m4..." 1>&6
           "${M4}" Makefile.m4 > Makefile.in.new
           if test -s Makefile.m4; then
               if test -f Makefile.in && cmp -s Makefile.in.new Makefile.in >/dev/null 2>/dev/null
               then
                   rm -f Makefile.in.new
               else
                   mv Makefile.in.new Makefile.in
               fi
           else
               AC_MSG_WARN("Unable to create $i/Makefile.in")
           fi
       )
   fi
done
])

AC_DEFUN([ER_PROG_GNU_MAKE], [
AC_CHECK_PROGS(MAKE, gnumake gmake make pmake nmake, [:])
AC_CACHE_CHECK(whether $MAKE is a working GNU Make, er_cv_gnu_make, [
   (mkdir test-dir
    cd test-dir
    > it_is_gnu_make.first
    (
     echo 'TEST := $(shell echo Hallo > it_is_gnu_make.horgan || :)'
     echo 'all: it_is_gnu_make.really'
     echo '%.really: %.first'
     echo '	cp $(*F).horgan $(*F).magic'
     ) > GNUmakefile
    ${MAKE} > /dev/null 2>&1
   )
   if test -s test-dir/it_is_gnu_make.magic; then
       er_cv_gnu_make=yes
   else
       er_cv_gnu_make=no
   fi
   rm -rf test-dir
])
GNUMAKE="${er_cv_gnu_make}"
AC_SUBST(GNUMAKE)
])

dnl
dnl Use the Erwin library.
dnl
AC_DEFUN([ER_LIBERWIN],
[ER_CONFIG_ERWIN
erwindir="\$(top_srcdir)/erwin"
AC_SUBST(erwindir)

CPPFLAGS="$CPPFLAGS -I. -I\$(erwindir)/include"
LDFLAGS="$LDFLAGS -L\$(erwindir)/lib"
LIBS="$LIBS -lerwin"

FAKE_MODE='-*- Mode: Fundamental -*-'
AC_SUBST(FAKE_MODE)])

dnl Rubbish.
dnl AC_DEFUN([ER_PERL_DIRS], [
dnl perl_prefix="`echo $prefix | tr '{}' '()'`"
dnl AC_SUBST(perl_prefix)
dnl perl_execprefix="`echo $execprefix | tr '{}' '()'`"
dnl AC_SUBST(perl_execprefix)
dnl perl_datadir="`echo $datadir | tr '{}' '()'`"
dnl AC_SUBST(perl_datadir)
dnl perl_includedir="`echo $includedir | tr '{}' '()'`"
dnl AC_SUBST(perl_includedir)
dnl perl_oldincludedir="`echo $oldincludedir | tr '{}' '()'`"
dnl AC_SUBST(perl_oldincludedir)
dnl perl_libdir="`echo $libdir | tr '{}' '()'`"
dnl AC_SUBST(perl_libdir)
dnl perl_bindir="`echo $bindir | tr '{}' '()'`"
dnl AC_SUBST(perl_bindir)
dnl perl_sbindir="`echo $sbindir | tr '{}' '()'`"
dnl AC_SUBST(perl_sbindir)
dnl perl_libexecdir="`echo $libexecdir | tr '{}' '()'`"
dnl AC_SUBST(perl_libexecdir)
dnl perl_srcdir="`echo $srcdir | tr '{}' '()'`"
dnl AC_SUBST(perl_srcdir)
dnl perl_top_srcdir="`echo $top_srcdir | tr '{}' '()'`"
dnl AC_SUBST(perl_top_srcdir)
dnl perl_sysconfdir="`echo $sysconfdir | tr '{}' '()'`"
dnl AC_SUBST(perl_sysconfdir)
dnl perl_infodir="`echo $infodir | tr '{}' '()'`"
dnl AC_SUBST(perl_infodir)
dnl perl_mandir="`echo $mandir | tr '{}' '()'`"
dnl AC_SUBST(perl_mandir)
dnl perl_sharedstatedir="`echo $sharedstatedir | tr '{}' '()'`"
dnl AC_SUBST(perl_sharedstatedir)
dnl perl_localstatedir="`echo $localstatedir | tr '{}' '()'`"
dnl AC_SUBST(perl_localstatedir)
dnl ])

AC_DEFUN([ER_CONFIG_ERWIN], [
dnl ######################################################################
dnl # Configure erwin
dnl ######################################################################

dnl #
dnl # Environment variables for Erwin configure script
export MORE_CPPFLAGS          # additional entries to the CPPFLAGS
export MORE_CXXFLAGS          # dito for CXXFLAGS
export MORE_CFLAGS            # dito for CFLAGS
export MORE_LDFLAGS           # dito for LDFLAGS
export LESS_CPPFLAGS          # additional entries to the CPPFLAGS
export LESS_CXXFLAGS          # dito for CXXFLAGS
export LESS_CFLAGS            # dito for CFLAGS
export LESS_LDFLAGS           # dito for LDFLAGS

if test -z "$UNT"; then
    UNT=":"
    echo "Starting to configure Erwin library..."
    if test -f config.unt; then
        UNT=`cat config.unt`
    fi

    if test "x$UNT" != "x:" ; then
        echo "Untemplatize is already set to $UNT"
    else
        AC_PATH_PROG(untemplatize2,untemplatize2)
        AC_PATH_PROG(untemplatize,untemplatize)

        if test ! -z "$untemplatize2"; then
            UNT="$untemplatize2"
            echo "Found Erwin2 untemplatize in $UNT.  This will be the default."
            echo "$UNT" > config.unt
        else
           if test ! -z "$untemplatize"; then
              UNT="$untemplatize"
              echo "Found Erwin2 untemplatize in $UNT.  This will be the default."
              echo "$UNT" > config.unt
           fi
        fi
    fi

    if test "x$UNT" = "x:" ; then
        for testprog in /usr/local/bin/untemplatize2 \
                        /usr/local/bin/untemplatize \
                        "$HOME/opt/bin/untemplatize2" \
                        "$HOME/opt/bin/untemplatize"
        do
            if test "x$UNT" = "x:" ; then
                if grep Erwin-Version-2 "$testprog" 2>/dev/null >/dev/null ; then
                    UNT="$testprog"
                    echo "Found Erwin2 untemplatize in $UNT.  This will be the default."
                    echo "$UNT" > config.unt
                fi
            fi
        done
    fi
fi

if test "x$UNT" = "x:" ; then
    UNT=your/path/to/untemplatize
else
    echo "$UNT" > config.unt
fi

if test -d erwin; then
   AC_CONFIG_SUBDIRS(erwin)
else
   echo "Please untemplatize to generate erwin sub-directory."
   echo "I.e. do something like: make unt UNT=$UNT"
fi

######################################################################
])

dnl ER_CHECK_SIZEOF_WITH_CODE(TYPE, CODE [, CROSS-SIZE])
dnl Allows you to include code and translates parentheses to underbars.
AC_DEFUN(ER_CHECK_SIZEOF_WITH_CODE,                          
[changequote(<<, >>)dnl
dnl The name to #define.
define(<<AC_TYPE_NAME>>, translit(sizeof_$1, [a-z *()], [A-Z_P__]))dnl
dnl The cache variable name.
define(<<AC_CV_NAME>>, translit(ac_cv_sizeof_$1, [ *()], [_p__]))dnl
changequote([, ])dnl
AC_MSG_CHECKING(size of $1)
AC_CACHE_VAL(AC_CV_NAME,
[AC_TRY_RUN([#include <stdio.h>
$2
main()
{
  FILE *f=fopen("conftestval", "w");
  if (!f) exit(1);
  fprintf(f, "%d\n", (int)sizeof($1));
  exit(0);
}], AC_CV_NAME=`cat conftestval`, AC_CV_NAME=0, ifelse([$3], , , AC_CV_NAME=$3))])dnl
AC_MSG_RESULT($AC_CV_NAME)
AC_DEFINE_UNQUOTED(AC_TYPE_NAME, $AC_CV_NAME, [The size of $1])
undefine([AC_TYPE_NAME])dnl
undefine([AC_CV_NAME])dnl
])

dnl ER_CHECK_SIZEOF_INCLUDE(TYPE, INCLUDE_FILE [, CROSS-SIZE])
dnl Allows you to include code and translates parentheses to underbars.
AC_DEFUN(ER_CHECK_SIZEOF_INCLUDE,
[changequote(<<, >>)dnl
dnl The name to #define.
define(<<AC_TYPE_NAME>>, translit(sizeof_$1, [a-z *()], [A-Z_P__]))dnl
dnl The cache variable name.
define(<<AC_CV_NAME>>, translit(ac_cv_sizeof_$1, [ *()], [_p__]))dnl
changequote([, ])dnl
AC_MSG_CHECKING(size of $1 in $2)
AC_CACHE_VAL(AC_CV_NAME,
[AC_TRY_RUN([#include <stdio.h>
#include <$2>
main()
{
  FILE *f=fopen("conftestval", "w");
  if (!f) exit(1);
  fprintf(f, "%d\n", (int)sizeof($1));
  exit(0);
}], AC_CV_NAME=`cat conftestval`, AC_CV_NAME=0, ifelse([$3], , , AC_CV_NAME=$3))])dnl
AC_MSG_RESULT($AC_CV_NAME)
AC_DEFINE_UNQUOTED(AC_TYPE_NAME, $AC_CV_NAME, [The size of $1])
undefine([AC_TYPE_NAME])dnl
undefine([AC_CV_NAME])dnl
])


dnl
dnl Check whether C++ compiler has the a.b().c() -> a.c() optimisation in
dnl special cases (some gcc's have)
dnl
AC_DEFUN([ER_CHECK_CXX_STATIC_OPT_BUG],
[
FIXME: continue
])

dnl The macro AC_DECL_SYS_SIGLIST is broken for C++: it assignes to char *
dnl instead of char.  Moreover, it also checks for _sys_siglist.
AC_DEFUN([ER_DECL_SYS_SIGLIST], [
AC_CACHE_CHECK([for sys_siglist in signal.h or unistd.h],er_cv_sys_siglist,[
AC_TRY_LINK([
#include <sys/types.h>
#include <signal.h>
/* NetBSD declares sys_siglist in unistd.h.  */
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
],
[char const *msg = *(sys_siglist + 1);],
er_cv_sys_siglist=yes,
er_cv_sys_siglist=no)])
if test "x${er_cv_sys_siglist}" = xyes; then
    AC_DEFINE(SYS_SIGLIST_DECLARED, 1, [whether siglist is declared])
fi

AC_CACHE_CHECK([for _sys_siglist in signal.h or unistd.h],er_cv__sys_siglist,[
AC_TRY_LINK([
#include <sys/types.h>
#include <signal.h>
/* NetBSD declares _sys_siglist in unistd.h.  */
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
],
[char const *msg = *(_sys_siglist + 1);],
er_cv__sys_siglist=yes,
er_cv__sys_siglist=no)])
if test "x${er_cv_sys__siglist}" = xyes; then
    AC_DEFINE(_SYS_SIGLIST_DECLARED, 1, [whether _siglist is declared])
fi
])

dnl
dnl Try to run latex on a given program
dnl   $1 - 'checking' message to print
dnl   $2 - cache variable to set to yes or no
dnl   $3 - the latex program to try to compile using $LATEX and $DVIPS
dnl
define([er_try_latex_aux],
[
    mkdir config-latex-test >/dev/null 2>&1
    if cd config-latex-test; then
        [$2]
        if test "x${LATEX}" = x: || test "x${DVIPS}" = x: || \
           test "x${LATEX}" = x  || test "x${DVIPS}" = x
        then
            [$1]=no
        else
            if "${LATEX}" -interaction=batchmode configtest.tex < /dev/null >/dev/null 2>&1 && \
               "${DVIPS}" configtest.dvi -o configtest.ps >/dev/null 2>&1 && \
               test -f configtest.dvi && \
               test -f configtest.aux && \
               test -f configtest.ps
            then
                [$1]=yes
            else
                [$1]=no
            fi
        fi
        cd ..
    else
        [$1]=no
    fi
    rm -rf config-latex-test
])
dnl
AC_DEFUN([ER_TRY_LATEX],
[
   er_try_latex_aux([$1], [cat > configtest.tex <<\EOF
[$2]
EOF
])])
dnl
AC_DEFUN([ER_TRY_LATEX_UNQUOTED],
[
   er_try_latex_aux([$1], [cat > configtest.tex << EOF
[$2]
EOF
])])

dnl
dnl Find LaTeX and see that it accepts documentclass (latex 2e)
dnl
AC_DEFUN([ER_PROG_LATEX],
[
    dnl Try to find Omega first
    AC_CHECK_PROGS(LAMBDA, uklambda lambda, [:])
    AC_CHECK_PROGS(ODVIPS, odvips, [:])
    if test "x${LAMBDA}" = "x:"; then
        ODVIPS=:
    fi
    if test "x${ODVIPS}" != "x:" ; then
        LATEX=${LATEX-"$LAMBDA"}
        DVIPS=${DVIPS-"$ODVIPS"}
    fi

    AC_CHECK_PROGS(LATEX, uklatex latex, [:])
    AC_CHECK_PROGS(DVIPS, dvips, [:])
    if test "x${LATEX}" = "x:"; then
        DVIPS=:
    fi

    AC_MSG_CHECKING([whether LaTeX has version >= 2e])
    AC_CACHE_VAL(er_cv_latex_2e,
        ER_TRY_LATEX(er_cv_latex_2e,
[% Test the comment
\documentclass{report}
\begin{document}
\large ein test. $math mode \sum_i^j$
\end{document}
]))
    AC_MSG_RESULT(["${er_cv_latex_2e}"])
    if test "x${er_cv_latex_2e}" = xno; then
        LATEX=:
        DVIPS=:
    fi
])

dnl
dnl Check for a LaTeX package (needs LATEX variable to run latex)
dnl Defines LATEX_PACKAGE_$1 to the package that was found to work,
dnl and LATEX_$1_TRUE and dnl LATEX_$1_FALSE depending on
dnl the success.
dnl
AC_DEFUN([ER_LATEX_CHECK_PACKAGE],
[
    if test "x${LATEX_PACKAGE_$1+set}" = xset; then
        er_cv_latex_package_$1="${LATEX_PACKAGE_$1}"
    fi

    AC_CACHE_CHECK([which LaTeX package to use for $1],er_cv_latex_package_$1,
    if test "x${LATEX}" != "x:"; then
        for i in $2; do
            ER_TRY_LATEX_UNQUOTED(er_cv_latex_package_$1,
[\\documentclass{report}
\\usepackage{$i}
\\begin{document}
hallo.
\\end{document}
])
            if test "x$er_cv_latex_package_$1" = xyes; then
                er_cv_latex_package_$1="$i"
                break
            else
                er_cv_latex_package_$1=
            fi
        done
    fi
    )

    AC_SUBST(LATEX_$1)
    AC_SUBST(LATEX_$1_TRUE)
    AC_SUBST(LATEX_$1_FALSE)
    LATEX_$1="$er_cv_latex_package_$1"
    LATEX_$1_TRUE=" % "
    LATEX_$1_FALSE=" % "
    if test "x$er_cv_latex_package_$1" != x; then
        LATEX_$1_TRUE=
    else
        LATEX_$1_FALSE=
    fi
])

AC_DEFUN([ER_PROG_LORDER_TSORT],
[
AC_PATH_PROGS(LORDER, lorder lorder.sh lorder-sh, ./lorder-sh)
AC_PATH_PROGS(TSORT,  tsort, no)

if test -x "$LORDER"; then
    :
else
    LORDER=./lorder-sh
fi

if test -x "$TSORT"; then
    :
else
    TSORT=no
fi

if test "x$TSORT" = "xno"; then
    LORDER=echo
    TSORT=cat
    dnl # this makes $LORDER $FILES | $TSORT -> echo $FILES | cat which is the identity.
    dnl # in this case, the precomputed order will be used, which might be correct, too.
fi
])

dnl $1: name of feature to test.
dnl     The variable er_cv_func_attr_$1 will be defined to yes or no.
dnl     Also, AC_DEFINE(HAVE_GNU_FUNC_ATTRIBUTE_(upcase($1))) will be performed
dnl
dnl $2: optional: parameter list for the attribute
dnl $3: optional: parameter list for the function that is defined for testing
dnl     Note: the function will not be tried to be invoked, only declared.
dnl $4: optional: storage declarations (e.g. 'static' etc.)
dnl $5: alternative function body (if - , no function is printed)
dnl $6: alternative return type
dnl
dnl Another function test1 will always be defined.
AC_DEFUN([ER_CHECK_GNU_FUNC_ATTRIBUTE],[
   AC_CACHE_CHECK([whether GNU attribute(($1$2)) works for functions], [er_cv_func_attr_$1], [
       ER_IF_GCC([
           ER_FILTER_GNU_WARNING_OPTIONS(-Werror, [
               AC_TRY_COMPILE([

static void* a;
static void* b;

extern void* test1 (]ifelse([$3],,[void* a],[[$3]])[);
extern void* test1 (]ifelse([$3],,[void* a],[[$3]])[) { return a; }

$4 ]ifelse([$6],,[void*],[[$6]])[ test_func (]ifelse([$3],,[void* a],[[$3]])[) __attribute__((__$1__$2));
]ifelse([$5],-,,[
$4 ]ifelse([$6],,[void*],[[$6]])[ test_func (]ifelse([$3],,[void* a],[[$3]])[)
{
    a= b;
    ]ifelse([$5],,[return a],[$5]);[
}
][
$4 __attribute__((__$1__$2)) ]ifelse([$6],,[void*],[[$6]])[ test_func2 (]ifelse([$3],,[void* a],[[$3]])[)
{
    a= b;
    ]ifelse([$5],,[return a],[$5]);[
}
][
$4 ]ifelse([$6],,[void*],[[$6]])[ __attribute__((__$1__$2)) test_func3 (]ifelse([$3],,[void* a],[[$3]])[)
{
    a= b;
    ]ifelse([$5],,[return a],[$5]);[
}

#ifdef __cplusplus
class A {
    A();
};
__attribute__((__$1__$2)) A::A ()
{
}
#endif
])[

],
[  a= 0; b= 0; ],
[ er_cv_func_attr_$1=yes ],
[ er_cv_func_attr_$1=no ])
           ])
        ], [
           er_cv_func_attr_$1=no
        ])
   ])
   if test "x$er_cv_func_attr_[$1]" = xyes; then
       [$1]=yes
       AC_DEFINE(HAVE_GNU_FUNC_ATTRIBUTE_[]translit($1,a-z,A-Z), [1], [whether GNU attribute(($1$2)) works on functions])
   else
       [$1]=no
   fi
])

dnl $1: name of feature to test.
dnl     The variable er_cv_var_attr_$1 will be defined to yes or no.
dnl     Also, AC_DEFINE(HAVE_GNU_VAR_ATTRIBUTE_(upcase($1))) will be performed
dnl
dnl $2: optional: parameter list for the attribute.
dnl     if - no __attribute__ is generated: you must provide it yourself.
dnl $3: optional: type of the variable (a union by default)
dnl $4: optional: storage declarations (e.g. 'static' etc.)
dnl $5: optional: init value for the variable
AC_DEFUN([ER_CHECK_GNU_VAR_ATTRIBUTE],[
   AC_CACHE_CHECK(whether GNU attribute(($1[]ifelse($2,-,,[$2]))) works for variables, [er_cv_var_attr_$1], [
       ER_IF_GCC([
           ER_FILTER_GNU_WARNING_OPTIONS(-Werror, [
               AC_TRY_COMPILE([
$4 ]ifelse($3,,[union _test_type {
    int *a;
    char *b;
}],[$3]) test_var ifelse([$2],-,,[__attribute__((__$1__$2))]) ifelse($5,,,[= $5])[;

],
[],
[ er_cv_var_attr_$1=yes ],
[ er_cv_var_attr_$1=no ])
           ])
        ], [
           er_cv_var_attr_$1=no
        ])
   ])
   if test "x$er_cv_var_attr_[$1]" = xyes; then
       [$1]=yes
       AC_DEFINE(HAVE_GNU_VAR_ATTRIBUTE_[]translit($1,a-z,A-Z), [1], [whether GNU attribute(($1$2)) works on variables])
   else
       [$1]=no
   fi
])

dnl $1: name of feature to test.
dnl     The type er_cv_type_attr_$1 will be defined to yes or no.
dnl     Also, AC_DEFINE(HAVE_GNU_TYPE_ATTRIBUTE_(upcase($1))) will be performed
dnl
dnl $2: optional: parameter list for the attribute
dnl $3: optional: type of the type (a union by default)
AC_DEFUN([ER_CHECK_GNU_TYPE_ATTRIBUTE],[
   AC_CACHE_CHECK([whether GNU attribute(($1$2)) works for types], [er_cv_type_attr_$1], [
       ER_IF_GCC([
           ER_FILTER_GNU_WARNING_OPTIONS(-Werror, [
               AC_TRY_COMPILE([
typedef ]ifelse($3,,[union _test_type {
    int *a;
    char *b;
}],[$3])[ __attribute__((__$1__$2)) test_type;

],
[],
[ er_cv_type_attr_$1=yes ],
[ er_cv_type_attr_$1=no ])
           ])
        ], [
           er_cv_type_attr_$1=no
        ])
   ])
   if test "x$er_cv_type_attr_[$1]" = xyes; then
       [$1]=yes
       AC_DEFINE(HAVE_GNU_TYPE_ATTRIBUTE_[]translit($1,a-z,A-Z), [1], [whether GNU attribute(($1$2)) works on types])
   else
       [$1]=no
   fi
])

dnl Checks for GNU attribute $1 with a possible parameter list $2.
dnl If function, variable and type attributes are available, defines
dnl HAVE_GNU_ATTRIBUTE_(update($1)).
AC_DEFUN([ER_CHECK_GNU_ATTRIBUTE], [
   ER_CHECK_GNU_FUNC_ATTRIBUTE($@)
   ER_CHECK_GNU_VAR_ATTRIBUTE($@)
   ER_CHECK_GNU_TYPE_ATTRIBUTE($@)
   if test "x$er_cv_type_attr_[$1]" = xyes && \
      test "x$er_cv_func_attr_[$1]" = xyes && \
      test "x$er_cv_var_attr_[$1]" = xyes
   then
       AC_DEFINE(HAVE_GNU_ATTRIBUTE_[]translit($1,a-z,A-Z), [1], [whether GNU attribute(($1$2)) works])
   fi
])

dnl Checks all known attributes.
AC_DEFUN([ER_CHECK_ALL_GNU_ATTRIBUTES], [
   ER_CHECK_GNU_ATTRIBUTE(unused)
   ER_CHECK_GNU_ATTRIBUTE(deprecated)

   ER_CHECK_GNU_FUNC_ATTRIBUTE(noreturn,,,,[test_func(0)])
   ER_CHECK_GNU_FUNC_ATTRIBUTE(noinline)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(always_inline)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(flatten)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(pure)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(const)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(nothrow)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(format,     [(__printf__, 1, 2)], [char const *x, ...])
   ER_CHECK_GNU_FUNC_ATTRIBUTE(format_arg, (1), [char const *x])
   ER_CHECK_GNU_FUNC_ATTRIBUTE(nonnull,    (1), [char const *x])
   ER_CHECK_GNU_FUNC_ATTRIBUTE(no_instrument_function)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(section, ("test"))
   ER_CHECK_GNU_FUNC_ATTRIBUTE(constructor)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(destructor)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(used)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(weak)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(malloc,,,,[return (void *)0;],[void *])
   ER_CHECK_GNU_FUNC_ATTRIBUTE(alias, ("test1"),,,-)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(visibility, ("hidden"))
   dnl regparm is a parameter attribute and currently not tested.
   ER_CHECK_GNU_FUNC_ATTRIBUTE(stdcall)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(fastcall)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(cdecl)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(longcall)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(shortcall)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(long_call)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(short_call)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(dllimport)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(dllexport)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(exception)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(function_vector)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(interrupt)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(interrupt_handler)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(sp_switch, ("alt_stack"))
   ER_CHECK_GNU_FUNC_ATTRIBUTE(trap_exit)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(eightbit_data)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(tiny_data)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(signal)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(naked)
   ER_CHECK_GNU_FUNC_ATTRIBUTE(model, ("medium"))
   ER_CHECK_GNU_FUNC_ATTRIBUTE(no_check_memory_usage)

   ER_CHECK_GNU_VAR_ATTRIBUTE(aligned,(8))
   ER_CHECK_GNU_VAR_ATTRIBUTE(mode,(__word__))
   ER_CHECK_GNU_VAR_ATTRIBUTE(nocommon)
   ER_CHECK_GNU_VAR_ATTRIBUTE(packed, -,[struct{char a; int b[2] __attribute__((__packed__));}])
   ER_CHECK_GNU_VAR_ATTRIBUTE(section, ("test"), int,, 5)
   ER_CHECK_GNU_VAR_ATTRIBUTE(shared)
   ER_CHECK_GNU_VAR_ATTRIBUTE(transparent_union)
   ER_CHECK_GNU_VAR_ATTRIBUTE(vector_size, (16), int)
   ER_CHECK_GNU_VAR_ATTRIBUTE(weak)
   ER_CHECK_GNU_VAR_ATTRIBUTE(model, ("medium"))

   ER_CHECK_GNU_TYPE_ATTRIBUTE(aligned,(8))
   ER_CHECK_GNU_TYPE_ATTRIBUTE(packed,,[struct{char a; int b[2];}])
   ER_CHECK_GNU_TYPE_ATTRIBUTE(transparent_union)
   ER_CHECK_GNU_TYPE_ATTRIBUTE(may_alias,, short)
])
