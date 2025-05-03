#! /usr/bin/perl -w

use strict;

my @var= ();
my %version_scripts= (); # These keys need patching after extraction.
my $somekey=    undef;
my $sometarext= undef;
my %exist= ();
my $size=     undef;
my $keylen=   length("prefix");
my $progname= "this_package";
my $copying=  undef;
my $barcat=   undef;
my $version=  "1";

for my $arg (@ARGV) {
    if ($arg=~ /^([a-z_]+)=(.*)$/) {
        push @var, {
            key   => $1,
            value => $2
        };
        $keylen= length($1) if length($1) > $keylen;
    }
    elsif ($arg=~ m%/([a-z_]+)\.(tar|tgz|tbz|tar\.gz|tar\.bz2)$%) {
        $exist{$1}= $2;
        ($somekey, $sometarext)= ($1, $2);
    }
    elsif ($arg=~ m%bindir/([-+0-9A-Za-z_]+-version(\.(sh|pl))?)$%) {
        $version_scripts{$1}= 1;
    }
    elsif ($arg=~ /^PROGNAME=(.*)$/) {
        $progname= $1;
    }
    elsif ($arg=~ /^COPYING=(.*)$/) {
        $copying= `cat $1`;
    }
    elsif ($arg=~ /^BARCAT=(.*)$/) {
        $barcat= `cat $1`;
    }
    elsif ($arg=~ /^VERSION=(.*)$/) {
        $version= $1;
    }
    elsif ($arg=~ /^SIZE_KB=(.*)$/) {
        my $size_kb= $1;
        my ($value, $unit);

        if    ($size_kb > 1024000) { $unit= "GB"; $value= $size_kb / 1024 / 1024; }
        elsif ($size_kb > 1000)    { $unit= "MB"; $value= $size_kb / 1024; }
        else                       { $unit= "kB"; $value= $size_kb; }

        if    ($value > 100) { $size= sprintf ("%.0f %s", $value, $unit); }
        elsif ($value > 10)  { $size= sprintf ("%.1f %s", $value, $unit); }
        else                 { $size= sprintf ("%.2f %s", $value, $unit); }
    }
    else {
        die "Illegal argument: $arg";
    }
}

die "No tarballs, please specify!\n" unless $somekey;

# include dependencies:
my $change= 1;
while ($change) {
    $change= 0;
    for my $var (@var) {
        if ($exist{$var->{key}}) {
            for my $var2 (@var) {
                unless (defined $exist{$var2->{key}}) {
                    #print STDERR "CHECK: $var->{value} $var2->{key}\n";
                    if ($var->{value}=~ m|{\Q$var2->{key}\E}|) {
                        $exist{$var2->{key}}= 0; # 0 means: no tar, but a dependency
                        $change= 1;
                    }
                }
            }
        }
    }
}

# filter variables:
@var= grep { defined $exist{$_->{key}} } @var;

sub echo(;$$)
{
    my ($text, $stream)= @_;
    if ($text) {
        chomp $text;
        print "echo \"$text\"";
    }
    else {
        print "echo";
    }
    print " 1>&$stream" if $stream;
    print "\n";
}

sub echo_n(;$)
{
    my ($text)= @_;
    if ($text) { # FIXME: check whether the shell can do this.
        chomp $text;
        print "echo \${ECHO_N} \"$text\"\n";
    }
}

sub read_variable($)
{
    my ($var)= @_;
    echo   "Please enter $var.  The default is '\${$var}'.";
    echo_n "$var> ";
    print  "read answer\n";
    print  "if test -n \"\$answer\"; then $var=\$answer; fi\n";
    echo   "$var=\${$var}";
}

sub make_dirs()
{
    echo "Making directories...";

    print "for file in ".(join " ", map { "\"\$$_->{key}\"" } @var)."\n";
    print "do\n";
    print "   set fnord `echo \":\$file\" | sed -ne 's/^:\\//#/;s/^://;s/\\// /g;s/^#/\\//;p'`\n";
    print "   shift\n";
    print "   pathcomp=\n";
    print "   for d\n";
    print "   do\n";
    print "     pathcomp=\"\$pathcomp\$d\"\n";
    print "     case \"\$pathcomp\" in\n";
    print "       -* ) pathcomp=./\$pathcomp ;;\n";
    print "     esac\n";
    print "     if test ! -d \"\$pathcomp\"; then\n";
    #print "        echo \"mkdir \$pathcomp\"\n";
    print "        mkdir \"\$pathcomp\" || lasterr=\$?\n";
    print "        if test ! -d \"\$pathcomp\"; then\n";
    print "          echo \"Error.\" 1>&2\n";
    print "          exit \$lasterr\n"; # abort!
    print "        fi\n";
    print "     fi\n";
    print "     pathcomp=\"\$pathcomp/\"\n";
    print "   done\n";
    print "done\n";
}

sub check_tarball($$)
{
    my ($key, $ext)= @_;
    my $tarfile= "\"\${TARDIR}/$key.$ext\"";

    print "if ! test -f $tarfile; then\n";
    echo ("Error: $tarfile not found.", 2);
    print "exit 1\n";
    print "fi\n";
}

sub install_tarball($$)
{
    my ($key, $ext)= @_;
    my $tarfile= "\"\${TARDIR}/$key.$ext\"";

    echo "Installing $key=\${$key}...";

    print "(cd \"\${$key}\" && ";
    if ($ext eq 'tar') {
        print "tar xf ${tarfile}";
    }
    else {
        my $decompress= 'cat';
        if    ($ext eq 'tgz' || $ext eq 'tar.gz')  { $decompress= 'gzip -dc'; }
        elsif ($ext eq 'tbz' || $ext eq 'tar.bz2') { $decompress= 'bzip2 -dc'; }
        else {
            die "Unknown tarball extension: $ext";
        }
        print "$decompress < $tarfile | tar xf -";

        #This does not work in a normal Bourne Shell:
        # print "trap 'rm -f .Ierror' EXIT && ";
        # print "( ( $decompress < $tarfile || touch .Ierror ) | tar xf - && test ! -f .Ierror )";
        #
        #This catches more errors, tough.
    }
    print " ) || exit 1\n";
}

sub install_tarballs($@)
{
    my $ext= shift;
    my @tarballs= @_;

    #my $tarfile= "\"\${TARDIR}/$key.$ext\"";
    #
    echo "Installing...";

    my $cmd= "test -n \"`eval echo \\\"\$\\\"\${bar_file}`\" && ".
             "cd \"`eval echo \\\"\$\\\"\${bar_file}`\" && ( ";

    #print "(cd \"\${$key}\" && ";
    if ($ext eq 'tar') {
        $cmd.= "tar xf -";
    }
    else {
        my $decompress= 'cat';
        if    ($ext eq 'tgz' || $ext eq 'tar.gz')  { $decompress= 'gzip -dc'; }
        elsif ($ext eq 'tbz' || $ext eq 'tar.bz2') { $decompress= 'bzip2 -dc'; }
        else {
            die "Unknown tarball extension: $ext";
        }
        $cmd.="$decompress | tar xf -";
    }
    $cmd.= ' )';

    print "\n$barcat\n\n";
    print "BAR_CMD='$cmd' BAR_DIR=\"\${TARDIR}/\" BAR_EXT='.$ext' BAR_CLEAR=1 bar_cat ".
          join(" ", map { $_->{key} } @tarballs).
          " 2>&1\n";
}

sub do_install()
{
    # resolve variables:
    for my $var ({ key => 'prefix' }, @var) {
        print "eval $var->{key}=\"\${$var->{key}}\"\n";
    }

    # create directories:
    make_dirs;

    # untar:
    my @tarballs= grep { $exist{$_->{key}} } @var;
    if (0+@tarballs) {
        for my $var (@tarballs) {
            check_tarball ($var->{key}, $exist{$var->{key}});
        }

        my $ext= $exist{$tarballs[0]->{key}}; # get extension and assume it is the
                                       # same for all tarballs.
        install_tarballs $ext, @tarballs;
    }

    # patch version scripts:
    # FIXME:
    # Some day we might also want to patch a configuration file.
    # E.g. liberror's 'errcodes' script needs to know the paths, so
    #      it does not work in a binary distribution.
    #      Possibility 1: there should be one config file for each
    #      package that can be patched here, too, and an environment
    #      variable pointing to that file.
    #      Possibility 2: the scripts below generate a new file in
    #      a users home directory to set the path to the config
    #      file correctly.
    #      Problem: NFS: the installation dir might still not be
    #      where the package is found later by the user.
    # Not easy to get this right.  We'll postpone this. :-/
    echo "Configuring package...";
    for my $script (keys %version_scripts) {
        print "cat \"\${bindir}/$script\" \\\n";
        for my $var ({ key => 'prefix' }, @var) {
            print "    | sed 's\@^$var->{key}=.*\@$var->{key}='\"\${$var->{key}}\"'\@' \\\n";
        }
        print "    > \"\${bindir}/$script\".new \\\n";
        print "    && mv \"\${bindir}/$script\".new \"\${bindir}/$script\"\n";
        print "chmod 755 \"\${bindir}/$script\"\n";
    }
    echo "Done.";
    echo;
    echo "Congratulations!";
    echo "${progname}-${version} was installed successfully.";
}

######################################################################

print "#! /bin/sh\n";
if ($copying) {
    print "# Copyright Notice:\n";
    for my $line (split /\s*\n/s, $copying) {
        print "# $line\n";
    }
}
print "\n";

echo;
echo "Welcome to the binary distribution of ${progname}!";
echo "This is ${progname}-${version}.";
my $date= `TZ=GMT LANG=POSIX LC_DATE=POSIX LC_ALL=POSIX date`;
chomp $date;
echo "The time of packaging was $date.";

# Find the tars:
print "TARDIR_AUTO=\"`pwd`/data\"\n";
print "if test -f \"`dirname \$0`/data/$somekey.$sometarext\"; then\n";
print "TARDIR_AUTO=\"`dirname \$0`/data\"\n";
print "fi\n";
print "TARDIR=\${TARDIR-\${TARDIR_AUTO}}\n";
# make absolute path:
print "TARDIR=\"`cd \${TARDIR} ; pwd`\"\n";

for my $tarext ('tar', 'tgz', 'tbz', 'tar.gz', 'tar.bz2') {
    my @tars= grep { $exist{$_->{key}} eq $tarext } @var;
    if (@tars) {
        print "for tarball in ".(join " ", map { $_->{key} } @tars)."\n";
        print "do\n";
        print "if test -f \"\${TARDIR}/\${tarball}.${tarext}\"; then true; else\n";
        echo ("Missing installation data \${TARDIR}/\${tarball}.${tarext}.", 2);
        echo ("Please set the installation data directory with the TARDIR environment", 2);
        echo ("variable before invoking this installation script.", 2);
        echo ("Error.", 2);
        print "exit 1\n";
        print "fi\n";
        print "done\n";
    }
}

# decide whether we're root or a normal user:
print "if test \"x\${UID}\" = x0 ; then\n";
print "prefix=\${prefix-'/usr/local'}\n";
print "else\n";
print "prefix=\${prefix-'\${HOME}'}\n";
print "fi\n";

# check echo:
print "case `echo -n testing` in\n";
print "-n*) ECHO_N=   ;; \n";
print "*)   ECHO_N=-n ;; \n";
print "esac\n";

# read command line:
print "interactive=1\n";
print "prev=\n";
print "for arg\n";
print "do\n";
print "if test -n \"\${prev}\"; then\n";
print "eval \"\$prev=\\\$arg\"\n";
print "prev=\n";
print "continue\n";
print "fi\n";
print "optarg=`expr \"x\$arg\" : 'x[^=]*=\\(.*\\)'`\n";

print "case \"\${arg}\" in\n";
for my $var ({ key => 'prefix' }, @var) {
    print "  $var->{key}|-$var->{key}|--$var->{key})\n";
    print "    prev=$var->{key}\n";
    print ";;\n";

    print "  $var->{key}=*|-$var->{key}=*|--$var->{key}=*)\n";
    print "    $var->{key}=\${optarg}\n";
    print ";;\n";
}

print "  -help|--help|-h)\n";
echo;
echo  "Usage: install-sh [options]";
echo  "Options:";
for my $var ({ key => 'prefix' }, @var) {
    echo ("    --$var->{key}=PATH");
}
echo "                These set the installation directories.\n";
echo "    --help      Shows this help screen\n";
echo "    --batch     Suppresses all questions\n";
print "exit 0\n";
print ";;\n";

print "  -batch|--batch)\n";
print "    interactive=0\n";
print ";;\n";

print "*)\n";
echo  ("Unrecognised command line option: \${arg}", 2);
echo  ("Error.", 2);
print "  exit 1\n";
print ";;\n";

print "esac\n";
print "done\n";

# set variables; then may be set already in the environment:
for my $var (@var) {
    print "$var->{key}=\${$var->{key}-'$var->{value}'}\n";
}

if ($copying) {
    echo;
    echo "Copyright Notice:\n";
    for my $line (split /\s*\n/s, $copying) {
        echo $line;
    }
}

if ($size) {
    echo;
    echo "This package requires about $size space to install.";
}

print "if test \"x\${interactive}\" = x1 ; then\n";
echo;
echo "Where do you want to install this package?";
read_variable "prefix";
print "fi\n";

#### Loop:
print "SHOW=1\n";
print "while true; do\n";

# show:
echo;
print "if test \"x\${interactive}\" = x1 ; then\n";
print "if test \"x\${SHOW}\" = x1 ; then\n";
echo "Current installation directories:";
{
    my $i= 1;
    for my $var ({ key => 'prefix' }, @var) {
        echo (sprintf ("%2d: %-*s", $i, $keylen, $var->{key})." = \${$var->{key}}");
        $i++;
    }
}
print "SHOW=\n";
print "fi\n";
print "fi\n";

# select:
print "if test \"x\${interactive}\" = x1 ; then\n";
echo "Enter number to change, 'LIST' to show again, 'OK' to install, or 'Q' to abort:";
echo_n "1...".(2+$#var).", LIST, OK, Q> ";
print "read answer\n";
echo;
print "else\n";
print "answer=ok\n";
print "fi\n";

# case:
print "case \"\$answer\" in\n";

# ok:
print "ok|OK|yes|y|YES)\n";
do_install;
print "exit 0\n";
print ";;\n";

# quit:
print "q|quit|QUIT|n|no|NO)\n";
echo  ("Cancel.", 2);
print "exit 1\n";
print ";;\n";

# show:
print "l|list|LIST|show|SHOW)\n";
print "SHOW=1\n";
print ";;\n";

# numbers or dirnames:
{
    my $i= 1;
    for my $var ({ key => 'prefix' }, @var) {
        print "$i|$var->{key})\n";
        read_variable $var->{key};
        print "SHOW=1\n";
        print ";;\n";
        $i++;
    }
}

# ignore empty line:
print "'')\n";
print "true\n";
print ";;\n";

# error:
print "*)\n";
echo  ("Error: Unrecognized response, please try again.\n", 2);
print ";;\n";

print "esac\n";

print "done\n";

0;
