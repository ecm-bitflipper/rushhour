#! /usr/bin/perl -w

use strict;

srand;

my $makedir= "make/";

my $mypath= $0;
my $mydir=  $mypath;
$mydir=~ s|/[^/]*$||;
if (-d $mydir && -f "$mydir/Rules.in") {
    print "Note: Found myself in $mydir.\n";
    $makedir= $mydir;
}

my @cvs_files= ();
my @cvs_dirs=  ();

sub yes_or_no($;$$$)
{
    my ($question, $default, $yes, $no)= @_;
    my $orig_yes= $yes;
    $yes= "y" unless $yes;
    $no=  "n" unless $no;

    if (defined $default) {
        $default= $default ? $yes : $no;
    }

    my $lorp= "";
    do {
        print "$question? ";
        print " (";
        print defined $default && $default eq $yes ? uc($yes) : lc($yes);
        print "/";
        print defined $default && $default eq $no  ? uc($no)  : lc($no);
        print "): ";
        $lorp= <>;
        $lorp||= "";
        $lorp=~ s/\s+//g;
        if (!$lorp && $default) {
            $lorp= "$default\n";
        }
        print "\n" if !$lorp;
    } while (!$lorp || $lorp !~ /^($yes|$no)/);
    my $result= $lorp=~ /^$yes/;
    print ($result ? "Yes.\n" : "No.\n") unless $orig_yes;
    return $result;
}

sub run ($)
{
    my ($command)= @_;
    print "> $command\n";
    system ($command);
}

sub p_copy ($$)
{
    my ($a, $b)= @_;
    push @cvs_files, $b;
    run ("cp '$a' '$b'");
}

sub p_touch ($)
{
    my ($a)= @_;
    p_copy ("/dev/null", $a);
}

sub p_echo ($$)
{
    my ($a, $b)= @_;
    push @cvs_files, $b;
    print "> echo ... > '$b'\n";
    open (F, ">$b") || die "$b: $!";
    print F "$a\n";
    close F;
}

sub p_mkdir ($)
{
    my ($a)= @_;
    push @cvs_dirs, $a;
    print "> mkdir $a\n";
    mkdir "$a", 0777;
}

######################################################################
######################################################################

print "This initialises your directory in a very simple way.\n";
print "You can change and extend it afterwards.\n";

######################################################################

my $default_name= `pwd`;
chomp $default_name;
$default_name=~ s|.*/||;

my $default_is_library= $default_name =~ /^lib./;

$default_name=~ s/^lib(.+)/$1/;
print "Default program name: $default_name\n";

my $is_library= yes_or_no ("Library or program", $default_is_library, "l", "p");
print ($is_library ? "Library.\n" : "Program.\n");

######################################################################

my $name;
do {
   print "Name of the project (for libraries, without 'lib', default is '$default_name'): ";
   $name= <>;
   $name||= "";
   $name=~ s/\s+//g;
   $name=~ s/-/_/g;
   chomp $name;
   if (!$name) {
       $name= $default_name;
   }
   $name= lc($name);
   print "\n" if !$name;
} while (!$name || !$name=~ /^[a-zA-Z_][a-zA-Z_0-9]*$/);
my $NAME= uc($name);
print "Program name is '$name' / '$NAME'.\n";

my $prefix=        $name;
my $global_prefix= $name;
do {
   print "Symbol prefix (default is '$default_name'): ";
   $global_prefix= <>;
   $global_prefix||= "";
   $global_prefix=~ s/\s+//g;
   $global_prefix=~ s/-/_/g;
   chomp $global_prefix;
   if (!$global_prefix) {
       $global_prefix= $name;
   }
   print "\n" if !$name;
} while (!$global_prefix || !$global_prefix =~ /^[a-zA-Z_][a-zA-Z_0-9]*$/);

my $GLOBAL_PREFIX= uc($global_prefix);

my $GlobalPrefix= $global_prefix;
$GlobalPrefix=~ s/_([a-z])/uc($1)/eg;
$GlobalPrefix=~ s/^([a-z])/uc($1)/e;
print "Prefix is '$global_prefix' / '$GLOBAL_PREFIX' / '$GlobalPrefix'.\n";

my $subdir= $name;
print "Subdir name is '$subdir'.\n";

######################################################################

my $use_cxx=        yes_or_no ("C++ project", 1);

my $use_erwin=      1; # don't bother people with rhetorical questions

my $use_erwin_cgen= $use_erwin && $use_cxx && $is_library &&
                    yes_or_no ("Create C wrapper automatically", 1);

my $use_cxx_only=   $use_erwin && $use_cxx && !$use_erwin_cgen &&
                    yes_or_no ("C++ only", 0);

my $use_liberror=   1; # don't bother people with rhetorical questions

my $use_pag=        yes_or_no ("Use PAG", 0);

my $use_crl2=       yes_or_no ("Use CRL2", 0);

my $use_symbol=     yes_or_no ("Use symbols", 1);

######################################################################

my $cext=       $use_cxx ? "cpp" : "c";
my $emacs_mode= $use_cxx ? "C++" : "C";

# Makefile.in:
open (F, "$makedir/Makefile.in") || die "$!";
push @cvs_files, "./Makefile.in";
open (G, ">./Makefile.in")     || die "$!";
my $mainfile= $is_library ? '$(LIBRARY)' : '$(PROG)';
while (<F>) {
    chomp;
    s/^\s*PROG         \s* = \s*_REPLACE_\s*$/"PROG=".         ($is_library      ? ""    : $name)/ex;
    s/^\s*LIBRARY      \s* = \s*_REPLACE_\s*$/"LIBRARY=".      ($is_library      ? $name : "")/ex;
    s/^\s*GLOBAL_PREFIX\s* =             \s*$/"GLOBAL_PREFIX=".($is_library      ? "${global_prefix}_" : "")/ex
        if $global_prefix ne $prefix;
    s/^\s*USE_ERWIN    \s* =             \s*$/"USE_ERWIN=".    ($use_erwin       ? "1"   : "")/ex;
    s/^\s*USE_ERWIN_CGEN\s*=             \s*$/"USE_ERWIN_CGEN=".($use_erwin_cgen ? "1"   : "")/ex;
    s/^\s*USE_PAG      \s* =             \s*$/"USE_PAG=".      ($use_pag         ? "1"   : "")/ex;
    s/^\s*USE_SYMBOL   \s* =             \s*$/"USE_SYMBOL=".   ($use_symbol      ? "1"   : "")/ex;
    s/^\s*do-it-all\s*: .*               $/do-it-all: \$(PROG)/x  if !$is_library;
    s/^\s*do-it-all\s*: .*               $/do-it-all: all-top/x   if $is_library;

    s/^\s*CMODULES     \s* =\s*$/CMODULES  =$mainfile/x   if !$use_cxx;

    s/^\s*CMODULES     \s* =\s*$/CMODULES  = testcompile/x if $use_cxx && $is_library && !$use_cxx_only;
    s/^\s*CPPMODULES   \s* =\s*$/CPPMODULES=$mainfile/x    if $use_cxx;

    s/^\s*SUBDIRS      \s* =\s*$/SUBDIRS   =linktest/x     if $is_library;

    s/^\s*HHEADERS     \s* =\s*$/HHEADERS  = include\/$subdir include\/$subdir\/decls include\/$subdir\/settings/x if $is_library;
    print G "$_\n";;
}
close G;
close F;

# Makefile.in:
open (F, "$makedir/configure.in") || die "$!";
push @cvs_files, "./configure.in";
open (G, ">configure.in")     || die "$!";
while (<F>) {
    chomp;

    s/^\s*define\(\s*_PROGNAME\s*,\s*__REPLACE__\)/define(_PROGNAME, $name)/;

    s/^\s*dnl \s+ define\(\s*_USE_LIBERROR, /define(_USE_LIBERROR,/x if $use_liberror;
    s/^\s*dnl \s+ define\(\s*_USE_ERWIN,    /define(_USE_ERWIN,/x    if $use_erwin;
    s/^\s*dnl \s+ define\(\s*_USE_PAG,      /define(_USE_PAG,/x      if $use_pag;
    s/^\s*dnl \s+ define\(\s*_USE_SYMBOL,   /define(_USE_SYMBOL,/x   if $use_symbol;
    s/^\s*dnl \s+ define\(\s*_USE_CRL2,     /define(_USE_CRL2,/x     if $use_crl2;


    if (/ER_PREFIX_PROGRAM/) {
        if ($is_library) {
            print G 'ER_PREFIX_PROGRAM([lib]_PROGNAME-version)'."\n";
        }
        else {
            print G 'ER_PREFIX_PROGRAM(_PROGNAME)'."\n";
        }
    }
    elsif (/__REPLACE__if_you_have_this__/ && !$is_library) {
        # skip line
    }
    #elsif (/__REPLACE__if_you_have_doc__/ ) {
    #    # we have docs!
    #}
    elsif (/__REPLACE__for_libraries__/ && !$is_library) {
        # skip line
    }
    elsif (/__REPLACE__for_linktest__/ && !$is_library) {
        # skip line
    }
    else {
        s/__REPLACE__if_you_have_this__\s*//;
        s/__REPLACE__if_you_have_doc__\s*//;
        s/__REPLACE__for_libraries__\s*//;
        s/__REPLACE__for_linktest__\s*//;
        print G "$_\n";;
    }
}
close G;
close F;

if ($use_erwin) {
    # makeerwin:
    open (F, "$makedir/makeerwin") || die "$!";
    push @cvs_files, "./makeerwin";
    open (G, ">makeerwin")     || die "$!";
    while (<F>) {
        chomp;
        s/^\s*PREFIX\s*=\s*_REPLACE_\s*$/"PREFIX=".($is_library ? $prefix : "")/ex;

        s/^(\s*)P_\s*=\s*\${P}_\s*$/"${1}P_=".($is_library ? "${global_prefix}_" : "")/ex
            if $prefix ne $global_prefix;

        if ($use_liberror) {
            s/--init\b/--init --liberror/;
        }
        $use_cxx_only= $use_cxx_only ? 1 : 0;
        s/--cpp-only=\d+/--cpp-only=$use_cxx_only/;
        print G "$_\n";;
    }
    close G;
    close F;
    chmod 0755, "./makeerwin";
}
my $c_linkage_begin=
    "#ifdef __cplusplus\n".
    "extern \"C\" {\n".
    "#endif /* __cplusplus */\n";

my $c_linkage_end=
    "#ifdef __cplusplus\n".
    "}\n".
    "#endif /* __cplusplus */\n";


my $do_include=
    ($is_library   ? "#include <$subdir.h>\n" : "").
    ($use_liberror ? "#include <liberror.h>\n" : "").
    ($use_crl2     ? "#include <crl2.h>\n" : "").
    ($use_erwin    ? "#include <".($is_library ? "$prefix/": "")."erwin/erwin.h>\n" : "").
    ($use_symbol   ? "#include \"symbol.h\"\n" : "");

my $do_init=
    $do_include.
    "\n".
    ($use_liberror ?
        "int ${global_prefix}_err_subsystem;\n"
    :   ""
    ).
    "void ${global_prefix}_init (int *argc_p, char ***argv_p)\n".
    "{\n".
    ($use_liberror ?
        "    ${global_prefix}_err_subsystem= err_subsystem(\"${name}\");\n"
    :   ""
    ).
    ($use_erwin    ? "    ".($is_library ? "${global_prefix}_" : "").
                          "erwin_init (argc_p, argv_p);\n" : "").
    ($use_symbol   ? "    ".($is_library ? "${global_prefix}_" : "").
                          "symbol_init (argc_p, argv_p);\n" : "").
    ($is_library ? "" :
        ($use_crl2     ?
            ($use_symbol ? "    crl_set_string2symbol (string2symbol_func);\n" : "").
                           "    crl_init (argc_p, argv_p);\n"
            : ""
        )
    ).
    "}\n";

my $decls=
      "#define unless(X)   if(!(X))\n".
      "#define until(X)    while(!(X))\n".
      "#define forever     for(;;)\n";

p_mkdir ("./doc");
p_copy  ("$makedir/Makefile.in.subdir", "./doc/Makefile.in");

if ($is_library) {
    p_mkdir ("./include");
    p_copy  ("$makedir/Makefile.in.subdir", "./include/Makefile.in");
    my $rand= int (rand 1000);
    p_echo (
        "/* -*- Mode: $emacs_mode -*- */\n\n".
        "$do_init\n".
        ($use_erwin_cgen ?
          "\n".
          "${GlobalPrefix}Object::~${GlobalPrefix}Object()\n".
          "{\n".
          "#if ${GLOBAL_PREFIX}_ERWIN_CLASS_REFCOUNT\n".
          "    return_if_fail (ref_count()==0);\n".
          "#endif /* ${GLOBAL_PREFIX}_ERWIN_CLASS_REFCOUNT */\n".
          "#if defined(DEVEL) && ${GLOBAL_PREFIX}_SIG_CHECKING\n".
          "    return_if_fail_pt (_m_heap_sig == ${GLOBAL_PREFIX}_SIG_GOOD,\n".
          "        \"Expected a good object for destruction\");\n".
          "    _m_heap_sig= ${GLOBAL_PREFIX}_SIG_DESTROYED;\n".
          "#endif\n".
          "}\n".
          "\n".
          "${GlobalPrefix}Object::${GlobalPrefix}Object()\n".
          "{\n".
          "    _m_ref_count= 0;\n".
          "#if defined(DEVEL) && ${GLOBAL_PREFIX}_SIG_CHECKING\n".
          "    return_if_fail_pt (_m_heap_sig == ${GLOBAL_PREFIX}_SIG_PREPARED,\n".
          "        \"Expected a prepared object for construction\");\n".
          "    _m_heap_sig= ${GLOBAL_PREFIX}_SIG_GOOD;\n".
          "#endif\n".
          "}\n".
          "\n".
          "#if defined(DEVEL) && ${GLOBAL_PREFIX}_SIG_CHECKING\n".
          "void ${GlobalPrefix}Object::check_sig() const\n".
          "{\n".
          "    ${GLOBAL_PREFIX}_CHECK_SIG(this);\n".
          "}\n".
          "#endif\n".
          "\n".
          "#if ${GLOBAL_PREFIX}_ERWIN_CLASS_REFCOUNT\n".
          "\n".
          "void ${global_prefix}_ref_aux(${GlobalPrefix}Object const *x)\n".
          "{\n".
          "    ${GLOBAL_PREFIX}_REF(x);\n".
          "}\n".
          "\n".
          "void ${global_prefix}_unref_aux(${GlobalPrefix}Object const *x)\n".
          "{\n".
          "    ${GLOBAL_PREFIX}_UNREF(x);\n".
          "}\n".
          "\n".
          "void ${GlobalPrefix}Object::operator delete(void *x)\n".
          "{\n".
          "    return_if_null (x);\n".
          "#if defined(DEVEL) && ${GLOBAL_PREFIX}_SIG_CHECKING\n".
          "    return_if_fail_pt (((${GlobalPrefix}Object *)x)->_m_heap_sig == ${GLOBAL_PREFIX}_SIG_DESTROYED,\n".
          "        \"Expected a destroyed object for deallocation\");\n".
          "    ((${GlobalPrefix}Object *)x)->_m_heap_sig= ${GLOBAL_PREFIX}_SIG_BAD;\n".
          "#endif\n".
          "    free(x);\n".
          "}\n".
          "\n".
          "void ${GlobalPrefix}Object::operator delete[](void *)\n".
          "{\n".
          "    return_if_reached ();\n".
          "    abort();\n".
          "}\n".
          "\n".
          "void *${GlobalPrefix}Object::operator new(size_t n)\n".
          "{\n".
          "    void *x= calloc(1,n);\n".
          "    nothing_if_null_ptC (x, \"Memory exhausted\", abort());\n".
          "#if defined(DEVEL) && ${GLOBAL_PREFIX}_SIG_CHECKING\n".
          "    ((${GlobalPrefix}Object *)x)->_m_heap_sig= ${GLOBAL_PREFIX}_SIG_PREPARED;\n".
          "#endif\n".
          "    return x;\n".
          "}\n".
          "\n".
          "void *${GlobalPrefix}Object::operator new[](size_t)\n".
          "{\n".
          "    nothing_if_reached ();\n".
          "    abort();\n".
          "}\n".
          "\n".
          "#endif /* ${GLOBAL_PREFIX}_ERWIN_CLASS_REFCOUNT */\n"
        : ""
        ),
        "./$name.$cext");

    p_echo (
        "/* -*- Mode: C -*- */\n\n".
        "$do_include\n",
        "./testcompile.c")
        if $use_cxx && !$use_cxx_only;

    p_echo (
        "/* -*- Mode: $emacs_mode -*- */\n\n".
        "#ifndef ".$NAME."_H_$rand\n".
        "#define ".$NAME."_H_$rand\n".
        "\n".
        ($use_erwin_cgen ?
          "#include <${prefix}/erwin/erwin.h>\n".
          "#include <${subdir}/failure.h>\n".
          "#include <${subdir}/gen-wrap-c.h>\n".
          "\n".
          "#include <$prefix/erwin/classdef.h>\n".
          "\n".
          "#ifdef __cplusplus\n".
          "\n".
          "struct ${GlobalPrefix}: public ${GlobalPrefix}Erwin {\n".
          "#   include <$subdir/gen-local-class.h>\n".
          "};\n".
          "\n".
          "#define THIS Object\n".
          "struct ${GLOBAL_PREFIX}_THIS: public ${GlobalPrefix} {\n".
          "    general_object\n".
          "#   include <$subdir/gen-announce.h>\n".
          "\n".
          "#if defined(DEVEL) && ${GLOBAL_PREFIX}_SIG_CHECKING\n".
          "    /*! check-sig: false */\n".
          "    child_ro(int,heap_sig,\"Signature to check heap integrity\")\n".
          "    void check_sig() const;\n".
          "#else\n".
          "    /*! c-ignore */\n".
          "    void check_sig() const {}\n".
          "#endif\n".
          "\n".
          "#if ${GLOBAL_PREFIX}_ERWIN_CLASS_REFCOUNT\n".
          "    /* If you don't want reference counting, redefine above macro (settings.h)\n".
          "     * and delete this code. */\n".
          "\n".
          "    child_ro(int,ref_count,\"Reference counter\")\n".
          "    ${GLOBAL_PREFIX}_THIS();\n".
          "protected:\n".
          "    virtual ~${GLOBAL_PREFIX}_THIS(); /* no inline refcounted objs, thus protected. */\n".
          "private:\n".
          "    void operator delete[](void *x);\n".
          "    void *operator new[](size_t n); /* cannot be used: no inline refcounted objs. */\n".
          "public:\n".
          "    void operator delete(void *x);\n".
          "    void *operator new(size_t n);\n".
          "\n".
          "    /*! c-inherit: 0, c-ignore */\n".
          "    THIS *_ref()\n".
          "    {\n".
          "        if (this == NULL) return NULL;\n".
          "        ${global_prefix}_return0_if_fail(ref_count() >= 0);\n".
          "        m_ref_count()++;\n".
          "        return this;\n".
          "    }\n".
          "    /*! c-inherit: 0, c-ignore */\n".
          "    THIS *_ref_unref()\n".
          "    {\n".
          "        if (this == NULL) return NULL;\n".
          "        ${global_prefix}_return0_if_fail(ref_count() >= 0);\n".
          "        if (ref_count() == 0) { delete this; return NULL; }\n".
          "        return this;\n".
          "    }\n".
          "    /*! c-inherit: 0, c-ignore */\n".
          "    THIS *_unref_no_delete()\n".
          "    {\n".
          "        if (this == NULL) return NULL;\n".
          "        ${global_prefix}_return0_if_fail(ref_count() > 0);\n".
          "        m_ref_count()--;\n".
          "        return this;\n".
          "    }\n".
          "    /*! c-inherit: 0, c-ignore */\n".
          "    THIS *_unref()\n".
          "    {\n".
          "        _unref_no_delete();\n".
          "        return _ref_unref();\n".
          "    }\n".
          "    /*! c-inherit: 0 */\n".
          "    THIS const *_ref() const\n".
          "        { return const_cast<THIS*>(this)->_ref(); }\n".
          "    /*! c-inherit: 0 */\n".
          "    THIS const *_unref() const\n".
          "        { return const_cast<THIS*>(this)->_unref(); }\n".
          "    /*! c-inherit: 0 */\n".
          "    THIS const *_ref_unref() const\n".
          "        { return const_cast<THIS*>(this)->_ref_unref(); }\n".
          "    /*! c-inherit: 0 */\n".
          "    THIS const *_unref_no_delete() const\n".
          "        { return const_cast<THIS*>(this)->_unref_no_delete(); }\n".
          "\n".
          "#else /* !${GLOBAL_PREFIX}_ERWIN_CLASS_REFCOUNT */\n".
          "public:\n".
          "    virtual ~${GLOBAL_PREFIX}_THIS();\n".
          "#endif /* ${GLOBAL_PREFIX}_ERWIN_CLASS_REFCOUNT */\n".
          "};\n".
          "#undef THIS\n".
          "\n".
          "#define THIS  Sample\n".
          "#define SUPER Object\n".
          "struct ${GLOBAL_PREFIX}_THIS: public ${GLOBAL_PREFIX}_SUPER {\n".
          "    /* Some documentation about Sample */\n".
          "    abstract // or concrete\n".
          "\n".
          "};\n".
          "#undef SUPER\n".
          "#undef THIS\n".
          "\n".
          "#include <$prefix/erwin/classundef.h>\n".
          "\n".
          "#endif /* defined __cplusplus */\n\n".
          "\n".
          "#include <$prefix/erwin/classundef.h>\n"
        : ""
        ).
        "\n".
        $c_linkage_begin.
        "\n".
        ($use_liberror ?
            "extern int ${global_prefix}_err_subsystem;\n"
        :   ""
        ).
        "extern void ${global_prefix}_init (int * /*argc_p*/, char *** /*argv_p*/);\n".
        "\n".
        $c_linkage_end.
        "\n".
        "#endif /* defined ".$NAME."_H_$rand */\n",
        "./include/$subdir.h"
    );

    p_mkdir ("./include/$subdir");
    p_copy  ("$makedir/Makefile.in.subdir", "./include/$subdir/Makefile.in");

    p_echo (
        "/* -*- Mode: $emacs_mode -*- */\n".
        ($use_erwin_cgen ?
            "#define ${GLOBAL_PREFIX}_ERWIN_CLASS_REFCOUNT 1\n".
            "#define ${GLOBAL_PREFIX}_SIG_CHECKING         1\n".
            "\n".
            "#define ${GLOBAL_PREFIX}_${GLOBAL_PREFIX}_OBJECT_T_P_ICOPY ${global_prefix}_ref\n".
            "#define ${GLOBAL_PREFIX}_${GLOBAL_PREFIX}_OBJECT_T_P_IFREE ${global_prefix}_unref\n".
            "#define ${GLOBAL_PREFIX}_${GLOBAL_PREFIX}_OBJECT_T_P_OCOPY ${global_prefix}_ref\n".
            "#define ${GLOBAL_PREFIX}_${GLOBAL_PREFIX}_OBJECT_T_P_OFREE ${global_prefix}_unref\n".
            "#define ${GLOBAL_PREFIX}_${GLOBAL_PREFIX}OBJECT_P_ICOPY    ${global_prefix}_ref\n".
            "#define ${GLOBAL_PREFIX}_${GLOBAL_PREFIX}OBJECT_P_IFREE    ${global_prefix}_unref\n".
            "#define ${GLOBAL_PREFIX}_${GLOBAL_PREFIX}OBJECT_P_OCOPY    ${global_prefix}_ref\n".
            "#define ${GLOBAL_PREFIX}_${GLOBAL_PREFIX}OBJECT_P_OFREE    ${global_prefix}_unref\n".
            "\n".
            "#define ${GLOBAL_PREFIX}_SIG_GOOD      ".sprintf("%#x",int(rand(0x7fffffff)))."\n".
            "#define ${GLOBAL_PREFIX}_SIG_PREPARED  (-${GLOBAL_PREFIX}_SIG_GOOD)\n".
            "#define ${GLOBAL_PREFIX}_SIG_DESTROYED (~${GLOBAL_PREFIX}_SIG_GOOD)\n".
            "#define ${GLOBAL_PREFIX}_SIG_BAD       0\n".
            "\n".
            "#if defined(DEVEL) && ${GLOBAL_PREFIX}_SIG_CHECKING\n".
            "#define ${GLOBAL_PREFIX}_CHECK_SIG(THIS) \\\n".
            "      do {                                                                                  \\\n".
            "          ${global_prefix}_exit_if_fail_ppx4t3 ((THIS) == NULL || (THIS)->heap_sig() == ${GLOBAL_PREFIX}_SIG_GOOD,    \\\n".
            "               (THIS),                                                                      \\\n".
            "               (THIS)->heap_sig(),                                                          \\\n".
            "               ${GLOBAL_PREFIX}_SIG_GOOD,                                                                \\\n".
            "               ${GLOBAL_PREFIX}_SIG_PREPARED,                                                            \\\n".
            "               ${GLOBAL_PREFIX}_SIG_DESTROYED,                                                           \\\n".
            "               \"This means the object is not properly initialised, or was doubly deleted,\", \\\n".
            "               \"or was overwritten, or used before initialisation or after destruction.\",   \\\n".
            "               \"Or anything similar to that.\");                                             \\\n".
            "      } while(0)\n".
            "#  define ${GLOBAL_PREFIX}_CHECK_OTHER_SIG(X) (((${GlobalPrefix}Object const *)(X))->check_sig())\n".
            "#else\n".
            "#  define ${GLOBAL_PREFIX}_CHECK_SIG(X)       do{;}while(0)\n".
            "#  define ${GLOBAL_PREFIX}_CHECK_OTHER_SIG(X) do{;}while(0)\n".
            "#endif\n".
            "\n"
        :   ""
        ).
        "\n",
        "./include/$subdir/settings.h");

    p_echo  (
        ($use_erwin_cgen ?
            "#include <$subdir/erwin/defs.h>\n".
            "\n".
            "typedef char const *${GlobalPrefix}Symbol;\n".
            "typedef ${GLOBAL_PREFIX}_ERWIN_BOOL ${GlobalPrefix}Bool;\n".
            "\n".
            "#include <${subdir}/gen-forwards.h>\n".
            "\n".
            $c_linkage_begin.
            "\n".
            "extern void ${global_prefix}_ref_aux(struct ${GlobalPrefix}Object const *);\n".
            "extern void ${global_prefix}_unref_aux(struct ${GlobalPrefix}Object const *);\n".
            "\n".
            $c_linkage_end.
            "\n".
            "#define ${global_prefix}_ref(x) \\\n".
            "            (${global_prefix}_ref_aux(((${GlobalPrefix}Object*)(x)),(x)))\n".
            "\n".
            "#define ${global_prefix}_unref(x) \\\n".
            "            ${global_prefix}_unref_aux((${GlobalPrefix}Object*)(x))\n".
            "\n"
        :   "typedef char const *${global_prefix}_symbol_t;\n"
        ).
        "#if IN_LIB${NAME}_COMPILE\n".
        "$decls\n".
        "#endif\n",
        "./include/$subdir/decls.h");

    p_copy  ("$makedir/libTEMPLATE-version.in.in", "./lib${name}-version.in.in");

    # generate a small link test:
    p_mkdir ("./linktest");
    open (F, "$makedir/Makefile.in.subappl") || die ("$makedir/Makefile.in.subappl: $!");
    open (G, ">./linktest/Makefile.in") || die ("./linktest/Makefile.in:$!");
    push @cvs_files, "./linktest/Makefile.in";
    while (<F>) {
        s/^\s*PROG         \s* =.*$/PROG=linktest/x;
        s/^\s*CMODULES     \s* =.*$/CMODULES=linktest/x;
        s/^\s*EXTRA_DEFS   \s* =.*$/EXTRA_DEFS = -DHAVE_LIB${NAME}/x;
        s/^\s*EXTRA_LIBS   \s* =.*$/EXTRA_LIBS = ..\/lib${name}.a/x;
        print G;
    }
    close G;
    close F;

    p_echo ("1", "./linktest/.sub-version");

    p_echo(
        "/* -*- Mode: C -*- */\n\n".
        ($use_liberror ?
            "#include <liberror.h>\n"
        :   ""
        ).
        "#include <$subdir.h>\n".
        "\n".
        "int main (int argc, char **argv)\n".
        "{\n".
        ($use_liberror ?
            "    err_init (&argc, &argv);\n".
            "    err_add_stream (C_TAG_ALL, stderr, NULL);\n"
        :   ""
        ).
        "    ${global_prefix}_init (&argc, &argv);\n".
        "    return 0;\n".
        "}\n",
        "./linktest/linktest.c");
}
else {
    p_touch ("./settings.h");
    p_echo  (
        "typedef char const *symbol_t;\n".
        "$decls\n",
        "./decls.h");
    p_echo  (
        "/* -*- Mode: $emacs_mode -*- */\n\n".
        "$do_init\n".
        "\n".
        "int main (int argc, char **argv)\n".
        "{\n".
        ($use_liberror ? "    err_init (&argc, &argv);\n" : "").
        ($use_liberror ? "    err_add_stream (C_TAG_ALL, stderr, NULL);\n" : "").
        "    ${global_prefix}_init (&argc, &argv);\n".
        "\n".
        ($use_liberror ?
            "    exit (err_count(0,C_TAG_ERRORS) > 0 ? EXIT_FAILURE : EXIT_SUCCESS);\n" :
            "    exit (EXIT_SUCCESS);\n"
        ).
        "}\n",
        "$name.$cext"
    );
}

p_echo ("0.1", "./.base-version");

p_copy  ("$makedir/cvscompile", "./cvscompile");
chmod 0755, "./cvscompile";

p_copy  ("$makedir/svncompile", "./svncompile");
chmod 0755, "./svncompile";

if (-f "$makedir/.cvsignore") {
    p_copy  ("$makedir/.cvsignore", "./.cvsignore");
}
elsif (-d "$makedir/.svn") {
    run ("svn propget svn:ignore $makedir > ./.cvsignore");
}

unless ($is_library) {
    system ("echo '$name' >> ./.cvsignore");
}

my $cvs_p= 0;
my $svn_p= 0;

p_echo ("1", ".sub-version");
        # needs to be there, otherwise we get errors until 'svn commit' has been run

if (-d "./CVS") {
    $cvs_p= yes_or_no ("Add this to the CVS", 1);
}
if (-d "./.svn") {
    $svn_p= yes_or_no ("Add this to the SVN", 1);
}

print "Dirs:\n";
for (@cvs_dirs) { print "    $_\n"; }
if ($cvs_p) {
    run ("cvs add ".join (" ", @cvs_dirs));
}
if ($svn_p) {
    run ("svn propset --file .cvsignore svn:ignore .");
    run ("rm .cvsignore");
    run ("svn add -N ".join (" ", @cvs_dirs));
}

print "Files:\n";
for (@cvs_files) { print "    $_\n"; }
if ($cvs_p) {
    run ("cvs add ".join (" ", @cvs_files));
}
if ($svn_p) {
    run ("svn add ".join (" ", @cvs_files));
}

exit 0;
