#! /usr/bin/perl -w

# Generates a GDL file from acmake.m4 to show the package dependencies.

use strict;

{
    my %node= ();

    sub node($)
    {
        my ($a)= @_;
        unless ($node{$a}) {
            $node{$a}= 1;
            print G "node: { title: \"$a\" }\n";
        }
    }

    sub edge($$)
    {
        my ($a, $b)= @_;
        print G "edge: { source: \"$a\" target: \"$b\" }\n";
    }
}

open (F, "acmake.m4") || die "acmake.m4: $!";
open (G, ">dep.gdl")  || die "dep.gdl: $!";

print G "graph: {\n";
print G "amax: 0\n";
print G "layoutalgorithm: minbackward\n";
print G "orientation: lefttoright\n";
while (<F>) {
    if (m|^\s*ifelse\s*\(\s*(\w+)\s*,\s*,\s*,\s*
                  \[\s*define\s*\(\s*\[\s*(\w+)\s*\]\s*,\s*1\s*\)\s*\]\s*\)\s*$|x)
    {
        my ($a,$b)= ($1,$2);
        node $a;
        node $b;
        edge $a, $b;
    }
}
print G "}\n";

close G;
close F;

0;
