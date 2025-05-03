/* Automatically generated */
#ifndef EPRINTF_VERSION_H
#define EPRINTF_VERSION_H 1

#define EPRINTF_MAKE_STRING_AUX(X) #X
#define EPRINTF_MAKE_STRING(X) EPRINTF_MAKE_STRING_AUX(X)

#ifdef __cplusplus
extern "C" {
#endif

extern char const *eprintf_version;
extern int eprintf_revision;
extern char const *eprintf_branch_id;
/* The following only work under Linux and *must* be configurable,
 * since the program need not run where it is installed! (->NFS)
 * Further note that these variables are NULL under Windows, as
 * the paths are Unix specific and have to be looked up in the
 * registry.  So again: keep them configurable!
 * These variables are meant to be overwritten by the config
 * procedure at the beginning of your application. */
extern char const *eprintf_config_prog_docdir;
extern char const *eprintf_config_prog_sysconfdir;
extern char const *eprintf_config_prog_datadir;
extern char const *eprintf_config_prog_libexecdir;
extern char const *eprintf_config_prog_localstatedir;
extern char const *eprintf_config_prog_sharedstatedir;

#ifdef __cplusplus
}
#endif

#define EPRINTF_BRANCH "$(BRANCH)"

#ifdef IN_LIBERROR_COMPILE
#define PROGNAME EPRINTF_MAKE_STRING(PROGNAME_TOKEN)

#if defined(R_TAG) && !defined(RELEASE_TAG)
#  define RELEASE_TAG EPRINTF_MAKE_STRING(R_TAG)
#endif

#ifndef RELEASE_TAG
#  define RELEASE_TAG "none"
#endif
#endif

/* The version number in the following does not include the sub version.
 * The sub version is only dynamically available, but not in preprocessing */ 
#define EPRINTF_VERSION_1 2
#define EPRINTF_VERSION_2 1

#define EPRINTF_VERSION_MAJOR EPRINTF_VERSION_1
#define EPRINTF_VERSION_MINOR EPRINTF_VERSION_2
#define EPRINTF_VERSION_MICRO 0

#define EPRINTF_BASE_VERSION(MAJOR,MINOR) \
            ((MAJOR * 1000 + MINOR) * 1000 + 0 * 1000)

#define EPRINTF_BASE_VERSION_CODE \
        EPRINTF_BASE_VERSION( \
          EPRINTF_VERSION_MAJOR, EPRINTF_VERSION_MINOR)

#ifndef  EPRINTF_COMPAT
#  define EPRINTF_COMPAT 999999999
#endif

#ifndef  EPRINTF_NO_COMPAT
#  define EPRINTF_NO_COMPAT 0
#endif

/* Version checks can only be performed on base versions! */
#define EPRINTF_CHECK_COMPAT_CODE(CODE) \
            ((CODE) <= EPRINTF_COMPAT && \
             (CODE) >= EPRINTF_NO_COMPAT)

#define EPRINTF_CHECK_COMPAT(MAJOR,MINOR) \
            EPRINTF_CHECK_COMPAT_CODE( \
                EPRINTF_BASE_VERSION(MAJOR,MINOR))

#endif /* defined EPRINTF_VERSION_H */
