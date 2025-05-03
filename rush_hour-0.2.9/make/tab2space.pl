#! /usr/bin/perl -w
#
# Converts tabs to spaces, assuming tabwidth of 8.
#

use strict;

FILE: for my $file (@ARGV) {
    next FILE if $file=~ /_(scanner|parser)\.c/;
    open (F, "$file") or die "$file: $!";
    open (G, ">$file.new") or die "$file.new: $!";
    while (<F>) {
        s/\G([^\t\n\r]{0,7}\t|[^\t\n\r]{8})/do {
            my $a= $1."        ";
            $a=~ s|\t||;
            substr($a,0,8);
        }/gsex;
        print G;
    }
    close F;
    close G;

    if (-s "$file.new" && system("cmp -s '$file' '$file.new'")) {
        rename "$file.new","$file";
        print STDERR "\n\nWARNING: Thou shalt not use tab characters!\n\tThe source file '$file' was modified.\n\n";
    }
    else {
        unlink ("$file.new");
    }
}
