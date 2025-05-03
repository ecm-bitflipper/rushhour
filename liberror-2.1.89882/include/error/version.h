/* Automatically generated */
#ifndef ERR_VERSION_H
#define ERR_VERSION_H 1

#define ERR_MAKE_STRING_AUX(X) #X
#define ERR_MAKE_STRING(X) ERR_MAKE_STRING_AUX(X)

#ifdef __cplusplus
extern "C" {
#endif

extern char const *err_version;
extern int err_revision;
extern char const *err_branch_id;
/* The following only work under Linux and *must* be configurable,
 * since the program need not run where it is installed! (->NFS)
 * Further note that these variables are NULL under Windows, as
 * the paths are Unix specific and have to be looked up in the
 * registry.  So again: keep them configurable!
 * These variables are meant to be overwritten by the config
 * procedure at the beginning of your application. */
extern char const *err_config_prog_docdir;
extern char const *err_config_prog_sysconfdir;
extern char const *err_config_prog_datadir;
extern char const *err_config_prog_libexecdir;
extern char const *err_config_prog_localstatedir;
extern char const *err_config_prog_sharedstatedir;

#ifdef __cplusplus
}
#endif

#define ERR_BRANCH "$(BRANCH)"

#ifdef IN_LIBERROR_COMPILE
#define PROGNAME ERR_MAKE_STRING(PROGNAME_TOKEN)

#if defined(R_TAG) && !defined(RELEASE_TAG)
#  define RELEASE_TAG ERR_MAKE_STRING(R_TAG)
#endif

#ifndef RELEASE_TAG
#  define RELEASE_TAG "none"
#endif
#endif

/* The version number in the following does not include the sub version.
 * The sub version is only dynamically available, but not in preprocessing */ 
#define ERR_VERSION_1 2
#define ERR_VERSION_2 1

#define ERR_VERSION_MAJOR ERR_VERSION_1
#define ERR_VERSION_MINOR ERR_VERSION_2
#define ERR_VERSION_MICRO 0

#define ERR_BASE_VERSION(MAJOR,MINOR) \
            ((MAJOR * 1000 + MINOR) * 1000 + 0 * 1000)

#define ERR_BASE_VERSION_CODE \
        ERR_BASE_VERSION( \
          ERR_VERSION_MAJOR, ERR_VERSION_MINOR)

#ifndef  ERR_COMPAT
#  define ERR_COMPAT 999999999
#endif

#ifndef  ERR_NO_COMPAT
#  define ERR_NO_COMPAT 0
#endif

/* Version checks can only be performed on base versions! */
#define ERR_CHECK_COMPAT_CODE(CODE) \
            ((CODE) <= ERR_COMPAT && \
             (CODE) >= ERR_NO_COMPAT)

#define ERR_CHECK_COMPAT(MAJOR,MINOR) \
            ERR_CHECK_COMPAT_CODE( \
                ERR_BASE_VERSION(MAJOR,MINOR))

#endif /* defined ERR_VERSION_H */
