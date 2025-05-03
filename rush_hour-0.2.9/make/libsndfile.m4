AC_DEFUN([AM_WITH_LIBSNDFILE], [
   AC_ARG_WITH(libsndfile,
[  --with-libsndfile=PREFIX
                          defines the path where libsndfile is found.],
       [
           CPPFLAGS="$CPPFLAGS -I${withval}/include"
           LDFLAGS="$LDFLAGS -L${withval}/lib"
       ])
   HAVE_LIBSNDFILE=0
   AC_SUBST(DEFINES)
   AC_CHECK_LIB(sndfile, sf_open,
   [
       HAVE_LIBSNDFILE=1
       AC_DEFINE(HAVE_LIBSNDFILE, 1, [Whether SND file library is available.])
       DEFINES="$DEFINES HAVE_LIBSNDFILE=1"
       LIBS="-lsndfile $LIBS"
       WIN_LIBS="sndfile $WIN_LIBS"
   ],
   [
      if test "x$1" = xoptional; then
          true
      else
          AC_MSG_ERROR(This library is needed.)
      fi
   ])
   MK_CONDITION([LIBSNDFILE], [test x"$HAVE_LIBSNDFILE" = x1])
])
