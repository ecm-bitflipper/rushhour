#! /bin/sh

# input vars:
#     VERSION
#     PREFIX
#     PREFIX_UC
#     PROGNAME_UC

echo '/* Automatically generated */'
echo '#ifndef '"$PREFIX_UC"'VERSION_H'
echo '#define '"$PREFIX_UC"'VERSION_H 1'
echo
echo '#define '"$PREFIX_UC"'MAKE_STRING_AUX(X) #X'
echo '#define '"$PREFIX_UC"'MAKE_STRING(X) '"$PREFIX_UC"'MAKE_STRING_AUX(X)'
echo
echo '#ifdef __cplusplus'
echo 'extern "C" {'
echo '#endif'
echo
echo 'extern char const *'"${PREFIX}"'version;'
echo 'extern int '"${PREFIX}"'revision;'
echo 'extern char const *'"${PREFIX}"'branch_id;'
echo '/* The following only work under Linux and *must* be configurable,'
echo ' * since the program need not run where it is installed! (->NFS)'
echo ' * Further note that these variables are NULL under Windows, as'
echo ' * the paths are Unix specific and have to be looked up in the'
echo ' * registry.  So again: keep them configurable!'
echo ' * These variables are meant to be overwritten by the config'
echo ' * procedure at the beginning of your application. */'
echo 'extern char const *'"${PREFIX}"'config_prog_docdir;'
echo 'extern char const *'"${PREFIX}"'config_prog_sysconfdir;'
echo 'extern char const *'"${PREFIX}"'config_prog_datadir;'
echo 'extern char const *'"${PREFIX}"'config_prog_libexecdir;'
echo 'extern char const *'"${PREFIX}"'config_prog_localstatedir;'
echo 'extern char const *'"${PREFIX}"'config_prog_sharedstatedir;'
echo
echo '#ifdef __cplusplus'
echo '}'
echo '#endif'
echo
echo '#define '"$PREFIX_UC"'BRANCH "$(BRANCH)"'
echo
echo '#ifdef IN_LIB'"$PROGNAME_UC"'_COMPILE'
echo '#define PROGNAME '"$PREFIX_UC"'MAKE_STRING(PROGNAME_TOKEN)'
echo
echo '#if defined(R_TAG) && !defined(RELEASE_TAG)'
echo '#  define RELEASE_TAG '"$PREFIX_UC"'MAKE_STRING(R_TAG)'
echo '#endif'
echo
echo '#ifndef RELEASE_TAG'
echo '#  define RELEASE_TAG "none"'
echo '#endif'
echo '#endif'
echo

echo '/* The version number in the following does not include the sub version.'
echo ' * The sub version is only dynamically available, but not in preprocessing */ '

key=1
PARAMS=
MAJOR=0
MINOR=0
MICRO=0
VERSION_NUM="`echo $VERSION | sed 's@[^.0-9]@.@g' | sed 's@[.][.]*@.@g'`"
for val in `echo $VERSION_NUM | sed 's@\.[0-9][0-9]*$@@' | sed 's@\.@ @g'`; do
    echo '#define '"$PREFIX_UC"'VERSION_'"$key $val"
    case "$key" in
        1) MAJOR=MAJOR; PARAMS="MAJOR";;
        2) MINOR=MINOR; PARAMS="MAJOR,MINOR";;
        3) MICRO=MICRO; PARAMS="MAJOR,MINOR,MICRO";;
    esac ;
    key=`expr $key + 1`;
done

echo
echo '#define '"$PREFIX_UC"'VERSION_MAJOR '"$PREFIX_UC"'VERSION_1'
if test "$MINOR" = MINOR; then
   echo '#define '"$PREFIX_UC"'VERSION_MINOR '"$PREFIX_UC"'VERSION_2'
else
   echo '#define '"$PREFIX_UC"'VERSION_MINOR 0'
fi
if test "$MICRO" = MICRO; then
   echo '#define '"$PREFIX_UC"'VERSION_MICRO '"$PREFIX_UC"'VERSION_3'
else
   echo '#define '"$PREFIX_UC"'VERSION_MICRO 0'
fi

echo
echo '#define '"$PREFIX_UC"'BASE_VERSION('"${PARAMS}"') '"\\"
echo "            ((${MAJOR} * 1000 + ${MINOR}) * 1000 + ${MICRO} * 1000)"
echo
echo '#define '"$PREFIX_UC"'BASE_VERSION_CODE '"\\"
echo '        '"$PREFIX_UC"'BASE_VERSION( '"\\"
if test "$MICRO" = MICRO; then
    echo "          ${PREFIX_UC}VERSION_MAJOR, ${PREFIX_UC}VERSION_MINOR, ${PREFIX_UC}VERSION_MICRO)"
else
   if test "$MINOR" = MINOR; then
       echo "          ${PREFIX_UC}VERSION_MAJOR, ${PREFIX_UC}VERSION_MINOR)"
   else
       echo "          ${PREFIX_UC}VERSION_MAJOR)"
   fi
fi

echo
echo '#ifndef  '"$PREFIX_UC"'COMPAT'
echo '#  define '"$PREFIX_UC"'COMPAT 999999999'
echo '#endif'

echo
echo '#ifndef  '"$PREFIX_UC"'NO_COMPAT'
echo '#  define '"$PREFIX_UC"'NO_COMPAT 0'
echo '#endif'

echo
echo '/* Version checks can only be performed on base versions! */'
echo '#define '"$PREFIX_UC"'CHECK_COMPAT_CODE(CODE) '"\\"
echo '            ((CODE) <= '"$PREFIX_UC"'COMPAT && '"\\"
echo '             (CODE) >= '"$PREFIX_UC"'NO_COMPAT)'

echo
echo '#define '"$PREFIX_UC"'CHECK_COMPAT('"${PARAMS}"') '"\\"
echo '            '"$PREFIX_UC"'CHECK_COMPAT_CODE( '"\\"
echo '                '"$PREFIX_UC"'BASE_VERSION('"${PARAMS}"'))'

echo
echo '#endif /* defined '"$PREFIX_UC"'VERSION_H */'
