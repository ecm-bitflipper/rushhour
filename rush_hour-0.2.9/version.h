/* Automatically generated */
#ifndef RUSH_HOUR_VERSION_H
#define RUSH_HOUR_VERSION_H 1

#define RUSH_HOUR_MAKE_STRING_AUX(X) #X
#define RUSH_HOUR_MAKE_STRING(X) RUSH_HOUR_MAKE_STRING_AUX(X)

#ifdef __cplusplus
extern "C" {
#endif

extern char const *rush_hour_version;
extern int rush_hour_revision;
extern char const *rush_hour_branch_id;
/* The following only work under Linux and *must* be configurable,
 * since the program need not run where it is installed! (->NFS)
 * Further note that these variables are NULL under Windows, as
 * the paths are Unix specific and have to be looked up in the
 * registry.  So again: keep them configurable!
 * These variables are meant to be overwritten by the config
 * procedure at the beginning of your application. */
extern char const *rush_hour_config_prog_docdir;
extern char const *rush_hour_config_prog_sysconfdir;
extern char const *rush_hour_config_prog_datadir;
extern char const *rush_hour_config_prog_libexecdir;
extern char const *rush_hour_config_prog_localstatedir;
extern char const *rush_hour_config_prog_sharedstatedir;

#ifdef __cplusplus
}
#endif

#define RUSH_HOUR_BRANCH "$(BRANCH)"

#ifdef IN_LIBRUSH_HOUR_COMPILE
#define PROGNAME RUSH_HOUR_MAKE_STRING(PROGNAME_TOKEN)

#if defined(R_TAG) && !defined(RELEASE_TAG)
#  define RELEASE_TAG RUSH_HOUR_MAKE_STRING(R_TAG)
#endif

#ifndef RELEASE_TAG
#  define RELEASE_TAG "none"
#endif
#endif

/* The version number in the following does not include the sub version.
 * The sub version is only dynamically available, but not in preprocessing */ 
#define RUSH_HOUR_VERSION_1 0
#define RUSH_HOUR_VERSION_2 2

#define RUSH_HOUR_VERSION_MAJOR RUSH_HOUR_VERSION_1
#define RUSH_HOUR_VERSION_MINOR RUSH_HOUR_VERSION_2
#define RUSH_HOUR_VERSION_MICRO 0

#define RUSH_HOUR_BASE_VERSION(MAJOR,MINOR) \
            ((MAJOR * 1000 + MINOR) * 1000 + 0 * 1000)

#define RUSH_HOUR_BASE_VERSION_CODE \
        RUSH_HOUR_BASE_VERSION( \
          RUSH_HOUR_VERSION_MAJOR, RUSH_HOUR_VERSION_MINOR)

#ifndef  RUSH_HOUR_COMPAT
#  define RUSH_HOUR_COMPAT 999999999
#endif

#ifndef  RUSH_HOUR_NO_COMPAT
#  define RUSH_HOUR_NO_COMPAT 0
#endif

/* Version checks can only be performed on base versions! */
#define RUSH_HOUR_CHECK_COMPAT_CODE(CODE) \
            ((CODE) <= RUSH_HOUR_COMPAT && \
             (CODE) >= RUSH_HOUR_NO_COMPAT)

#define RUSH_HOUR_CHECK_COMPAT(MAJOR,MINOR) \
            RUSH_HOUR_CHECK_COMPAT_CODE( \
                RUSH_HOUR_BASE_VERSION(MAJOR,MINOR))

#endif /* defined RUSH_HOUR_VERSION_H */
