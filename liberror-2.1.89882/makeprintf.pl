#! /usr/bin/perl -w

use strict;

my %argtype= (
    ""   => ["..."],
    "v"  => ["va_list"]
);

my %options= (
    ""   => [],
    "q"  => [],
    "o"  => ["int"]
);

my %location= (
    ""    => [],
    "fl"  => ["char const *", "int"],
    "flp" => ["char const *", "int", "int"],
    "l"   => ["err_location_t const *"]
);

my %mapname= (
    "fl0"  => "file",
    "flp0" => "file",

    "fl1"  => "line",
    "flp1" => "line",

    "flp2" => "pos",

    "l0"   => "loc",

    "o0"   => "options",

    "v0"   => "v0"
);

sub make_params ($$)
{
    my ($arr, $index)= @_;
    my @result= ();
    my $param= $$arr{$index};
    for my $i (0..$#$param) {
        push @result, {
            type => $$param[$i],
            name => $index eq "" ? "" : $mapname{"$index$i"}
        };
    }
    return \@result;
}

sub make_arg_decl ($$)
{
    my ($type, $name)= @_;
    return "$type $name"
        if $name eq "tag"  || $name eq "number";

    return "$type /*$name*/"
        if $name eq "file" || $name eq "line" || $name eq "pos" || $name eq "options";

    return $type;
}

my $mother= "voleprintf";

sub print_family ($$)
{
    my ($impl, $family)= @_;
    print "\n";
    for my $argtype ("", "v") {
        for my $options ("", "o", "q") {
            for my $location ("", "fl", "flp", "l") {
                my $prefix= $argtype.$options.$location;

                my @pre_args= (
                    { type => "int", name => "tag" },
                    { type => "int", name => "number" },
                    @{make_params \%options,  $options},
                    @{make_params \%location, $location}
                );
                my @format_args= (
                    { type => "char const *", name => "format" },
                    @{make_params \%argtype, $argtype}
                );
                my $format_attr= $argtype eq "v" ?
                         "ATTR_FORMAT_VPRINTF(".($#pre_args+2).")"
                       : "ATTR_FORMAT_PRINTF(".($#pre_args+2).",".($#pre_args+3).")";

                my $return_type= $family =~ /-debug$/ ? "void" : "int";

                if ($family eq "de-yes") {
                    my $name= sprintf "%-20s", "${prefix}deprintf";
                    print "/* err-renumber name=$name =${prefix}eprintf */\n";
                    print "/* err-skip */\n",
                          "#define $name /*err-skip*/ ${prefix}eprintf_devel\n\n";
                }
                elsif ($family eq "de-no") {
                    my $name= sprintf "%-20s", "${prefix}deprintf";
                    print "/* err-skip */\n",
                          "#define $name while (0) /*err-skip*/ ${prefix}eprintf_devel\n\n";
                        # this is a problem: I haven'n found a possibility to
                        # generate an expression (printf returns int), so the
                        # whole deprintf family will return void.
                        # (With the ?: operator, there are precedence problems because
                        # we cannot generate a closing paren on the right of the expression.
                }
                elsif ($family eq "de-no-vararg") {
                    my $name= sprintf "%-20s", "${prefix}deprintf(X...)";
                    print "/* err-skip */\n",
                          "#define $name ((void)0)\n\n";
                }
                else {
                    my $func= "${prefix}eprintf".($family eq "e-debug" ? "_devel" : "");
                    if ($impl) {
                        if ($func eq $mother) {
                            print "/* $mother() is the generic function. */\n\n";
                        }
                        else {
                            my $args=
                                join ", ",
                                    map { "$_->{type} $_->{name}" } @pre_args, @format_args;

                            my %name2name= ();
                            for my $arg (@pre_args, @format_args) {
                                $name2name{$arg->{name}}= $arg->{name};
                            }

                            my $tag= ($family eq "e-debug") ? "tag | C_TAG_DEBUG" : "tag";

                            my $num= "number";

                            my $opt= $options eq "q" ?
                                          "ERR_FO_QUOTE_C_STRING"
                                        : $name2name{'options'} || "0";

                            my $loc=
                                 $name2name{'loc'} ||
                                 (!defined $name2name{'file'} ? "NULL" : (
                                 "ErrLocation (".
                                     ($name2name{'file'} || "(char const *)NULL").
                                 ",".($name2name{'line'} || "0").
                                 ",".($name2name{'pos'}  || "0").")"));

                            my $va= $name2name{"v0"} || "va";

                            print "$return_type /*err-skip*/\n",
                                  "$func ($args)\n{\n";
                            if ($va eq "va") {
                                print "    va_list va;\n";
                                print "    va_start (va, format);\n";
                            }

                            print "    ";
                            print "$return_type result= " if $return_type ne "void";
                            print "/*err-skip*/ $mother ($tag, $num, $opt, $loc, format, $va);\n";

                            if ($va eq "va") {
                                print "    va_end (va);\n";
                            }
                            print "    return result;\n" if $return_type ne "void";
                            print "}\n\n";
                        }
                    }
                    else {
                        if ($func eq $mother) {
                            print "/* $mother() is the generic function. */\n\n";
                        }
                        else {
                            my $args=
                               join ", ",
                                  map { make_arg_decl ($_->{type}, $_->{name}) }
                                     @pre_args, @format_args;
                            print "/* err-renumber */\n".
                                  "extern $return_type\n".
                                  "$func ($args) $format_attr;\n".
                                  "/* See $mother for more documentation. */\n\n";
                        }
                    }
                }
            }
        }
    }
    print "\n";
}

open (F, ">include/error/printf-gen.h") || die "$!";
select F;
print "/* -*- Mode: C++ -*- */\n";
print "/* err-default scope=project */\n";
print_family 0, "e";
print_family 0, "e-debug";

print "#if defined(NDEBUG) || defined(RELEASE)\n";
print "#ifdef __GNUC__\n";
print_family 0, "de-no-vararg";
print "#else\n";
print_family 0, "de-no";
print "#endif\n";
print "#else\n";
print_family 0, "de-yes";
print "#endif\n";
close;

open (F, ">printf-gen.cpp") || die "$!";
select F;
print "/* -*- Mode: C++ -*- */\n\n";
print "#include \"liberror.h\"\n\n";
print_family 1, "e";
print_family 1, "e-debug";
close F;

0;
