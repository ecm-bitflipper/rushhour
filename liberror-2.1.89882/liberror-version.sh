#! /bin/sh
#
# The main purpose of this program is to have a program in bindir so
# that AC_PREFIX_PROGRAM works.
#
# Additionally, users have a program that tells them the version and
# install path of the library. :-)
#

prefix=/usr/local
exec_prefix=/usr/local
includedir=/usr/local/include
libdir=/usr/local/lib

echo "This is liberror-2.1.89882."
echo "Copyright (c) Henrik Theiling and AbsInt Angewandte Informatik GmbH"
echo "   using Erwin 2.1.89877."
echo "   includedir = ${includedir}"
echo "   libdir     = ${libdir}"
