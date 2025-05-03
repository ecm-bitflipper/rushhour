/* Automatically generated */
#ifndef TESTERROR_VERSION_H
#define TESTERROR_VERSION_H 1

#define TESTERROR_MAKE_STRING_AUX(X) #X
#define TESTERROR_MAKE_STRING(X) TESTERROR_MAKE_STRING_AUX(X)

#ifdef __cplusplus
extern "C" {
#endif

extern char const *testerror_version;
extern int testerror_revision;
extern char const *testerror_branch_id;
/* The following only work under Linux and *must* be configurable,
 * since the program need not run where it is installed! (->NFS)
 * Further note that these variables are NULL under Windows, as
 * the paths are Unix specific and have to be looked up in the
 * registry.  So again: keep them configurable!
 * These variables are meant to be overwritten by the config
 * procedure at the beginning of your application. */
extern char const *testerror_config_prog_docdir;
extern char const *testerror_config_prog_sysconfdir;
extern char const *testerror_config_prog_datadir;
extern char const *testerror_config_prog_libexecdir;
extern char const *testerror_config_prog_localstatedir;
extern char const *testerror_config_prog_sharedstatedir;

#ifdef __cplusplus
}
#endif

#define TESTERROR_BRANCH "$(BRANCH)"

#ifdef IN_LIBERROR_COMPILE
#define PROGNAME TESTERROR_MAKE_STRING(PROGNAME_TOKEN)

#if defined(R_TAG) && !defined(RELEASE_TAG)
#  define RELEASE_TAG TESTERROR_MAKE_STRING(R_TAG)
#endif

#ifndef RELEASE_TAG
#  define RELEASE_TAG "none"
#endif
#endif

/* The version number in the following does not include the sub version.
 * The sub version is only dynamically available, but not in preprocessing */ 
#define TESTERROR_VERSION_1 2
#define TESTERROR_VERSION_2 1

#define TESTERROR_VERSION_MAJOR TESTERROR_VERSION_1
#define TESTERROR_VERSION_MINOR TESTERROR_VERSION_2
#define TESTERROR_VERSION_MICRO 0

#define TESTERROR_BASE_VERSION(MAJOR,MINOR) \
            ((MAJOR * 1000 + MINOR) * 1000 + 0 * 1000)

#define TESTERROR_BASE_VERSION_CODE \
        TESTERROR_BASE_VERSION( \
          TESTERROR_VERSION_MAJOR, TESTERROR_VERSION_MINOR)

#ifndef  TESTERROR_COMPAT
#  define TESTERROR_COMPAT 999999999
#endif

#ifndef  TESTERROR_NO_COMPAT
#  define TESTERROR_NO_COMPAT 0
#endif

/* Version checks can only be performed on base versions! */
#define TESTERROR_CHECK_COMPAT_CODE(CODE) \
            ((CODE) <= TESTERROR_COMPAT && \
             (CODE) >= TESTERROR_NO_COMPAT)

#define TESTERROR_CHECK_COMPAT(MAJOR,MINOR) \
            TESTERROR_CHECK_COMPAT_CODE( \
                TESTERROR_BASE_VERSION(MAJOR,MINOR))

#endif /* defined TESTERROR_VERSION_H */
