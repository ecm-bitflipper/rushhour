/* -*- Mode: C -*- */

#ifndef HT_ERROR_TAGS_H
#define HT_ERROR_TAGS_H

/* ********************************************************************** */
/* The kinds of messages ('color tags'): */

#define _C_TAG_NONE        (1 << 0)
#define C_TAG_NONE         _C_TAG_NONE
   /* This is a message that explicitly does not want a prefix.
    * Use this seldom, e.g. for help pages for lengthy version
    * information etc.
    *
    * For banners, there is a special tag C_TAG_BANNER, which
    * also suppresses the prefix.
    */

#define _C_TAG_UNCLASSIFIED (1 << 1)
#define C_TAG_UNCLASSIFIED  _C_TAG_UNCLASSIFIED
#define C_TAG_NOCLASS       C_TAG_UNCLASSIFIED
   /* An unclassified message (use this seldom).
    * This is almost like the above, but progname[PID]: are printed.
    * E.g. all fprintf (stderr, ...) is internally translated to this error tag.
    */

#define _C_TAG_BANNER      (1 << 2)
#define C_TAG_BANNER       _C_TAG_BANNER
   /* For informational messages at the beginning of the program. */

#define _C_TAG_PROGRESS    (1 << 3)
#define C_TAG_PROGRESS     _C_TAG_PROGRESS
   /* Progress messages.  A bit like Info, but can be seperately filtered. */

#define _C_TAG_INFO        (1 << 4)
#define C_TAG_INFO         _C_TAG_INFO
   /* This is information that is really useful for the user.   It should
    * be displayed even in quiet mode operation.  If your program has a
    * very quiet mode, then these messages could be swiched off then. */

#define _C_TAG_NOTE        (1 << 5)
#define C_TAG_NOTE         _C_TAG_NOTE
   /* This is merely a note and is likely to disappear when the user wants a
    * quiet program. */

#define _C_TAG_PROMPT      (1 << 6)
#define C_TAG_PROMPT       _C_TAG_PROMPT
   /* This is a prompt when you ask the user something */

#define _C_TAG_WARN        (1 << 7)
#define C_TAG_WARN         _C_TAG_WARN
#define C_TAG_WARNING      C_TAG_WARN
   /* A warning message */

#define _C_TAG_ERR         (1 << 8)
#define C_TAG_ERR          _C_TAG_ERR
#define C_TAG_ERROR        C_TAG_ERR
   /* An error message */

#define _C_TAG_INTERNAL    (1 << 9)
#define C_TAG_INTERNAL     _C_TAG_INTERNAL
   /* internal error */

#define _C_TAG_FATAL       (1 << 10)
#define C_TAG_FATAL        _C_TAG_FATAL
   /* Fatal error: these are errors that immediately call exit(1) or abort),
    * because everything is bad. */

#define _C_TAG_ASSERT      (1 << 11)
#define C_TAG_ASSERT       _C_TAG_ASSERT
#define C_TAG_ASSERTION    C_TAG_ASSERT
   /* Failed assertion.
    * These have to print their own tag, not error number is output.
    * However, it should be tried to output the file and line number using
    * the normal liberror mechanisms (which is not always trivial to change
    * for existing libraries).
    */
#define _C_TAG_DEBUG       (1 << 12)
#define C_TAG_DEBUG        _C_TAG_DEBUG
   /* debug output (usually disabled) */


#define C_TAG_BITS         13 /* 13 is maximum, since 13 + 9 + 9 + 1 is 32. */
#define C_TAG_NEXT_BIT     C_TAG_BITS

#define C_TAG_MASK         ((1 << C_TAG_BITS) - 1)


#define C_TAG_VARIANT      (((unsigned)1) << ((unsigned)31))
   /* A bit that modifies the above message in some ways that
    * depends on the tag. */

#define C_TAG_PRE_FATAL     (C_TAG_FATAL     | C_TAG_VARIANT)

#define C_TAG_PRE_ASSERT    (C_TAG_ASSERTION | C_TAG_VARIANT)
#define C_TAG_PRE_ASSERTION (C_TAG_ASSERTION | C_TAG_VARIANT)
   /* Variants that do not cause immediate termination of the
    * program. */

/*
 * Other color tags that rather describe groups of tags (not for eprintf group!) */
#define C_TAG_ALL          C_TAG_MASK
#define C_TAG_ALL_NORMAL   (C_TAG_ALL & ~C_TAG_NONE & ~C_TAG_UNCLASSIFIED)

#define C_TAG_ERRORS       (_C_TAG_ERR | _C_TAG_INTERNAL | _C_TAG_FATAL | _C_TAG_ASSERT)
    /* These are classified to be errors. */

#define C_TAG_WARNINGS     (_C_TAG_WARN)
    /* These are classified to be warnings (trivial, but in accordance with C_TAG_ERRORS). */

#define C_TAG_INFOS        (_C_TAG_PROGRESS | _C_TAG_NOTE | _C_TAG_INFO)
    /* These are classified to be info messages */


#define C_TAG_GROUP_STDOUT (_C_TAG_BANNER | _C_TAG_PROMPT | _C_TAG_INFO | _C_TAG_NOTE)
#define C_TAG_GROUP_STDERR (C_TAG_MASK & ~C_TAG_GROUP_STDOUT)
   /* Some people print all of these to stderr. */

/* Special value for continued message (for eprintf group only!) */
#define C_TAG_MORE         -1
   /* Adds the message to the last error message. */

#define C_TAG_PREFIX       -2
#define C_TAG_SUFFIX       -3
   /* For composing messages with multiple eprintfs: when C_TAG_PREFIX
    * is used, no messages is generated, but this is buffered until
    * the next non C_TAG_PREFIX tag is found.  Then, the buffered
    * prefix is prepended.
    *
    * SUFFIX works accordingly.
    *
    * This is useful since it is the only way of printing without a \n at
    * the end of the string.  All other tags add \n automatically.
    */

/* Subsystem encoding in the color tag fields: */
#define C_TAG_SUBSYSTEM_FIRST_BIT  C_TAG_NEXT_BIT
#define C_TAG_SUBSYSTEM_BITS       9

#define C_TAG_SUBSYSTEM_SHIFT      C_TAG_SUBSYSTEM_FIRST_BIT
#define C_TAG_SUBSYSTEM_MASK_LOW   ((1 << C_TAG_SUBSYSTEM_BITS) - 1)
#define C_TAG_SUBSYSTEM_MAX        C_TAG_SUBSYSTEM_MASK_LOW
#define C_TAG_SUBSYSTEM_MASK       (C_TAG_SUBSYSTEM_MASK_LOW << C_TAG_SUBSYSTEM_SHIFT)

#define C_TAG_SUBSYSTEM_NEXT_BIT   (C_TAG_SUBSYSTEM_FIRST_BIT + C_TAG_SUBSYSTEM_BITS)

/* Subsystem encoding in the color tag fields: */
#define C_TAG_GROUP_FIRST_BIT  C_TAG_SUBSYSTEM_NEXT_BIT
#define C_TAG_GROUP_BITS       9

#define C_TAG_GROUP_SHIFT      C_TAG_GROUP_FIRST_BIT
#define C_TAG_GROUP_MASK_LOW   ((1 << C_TAG_GROUP_BITS) - 1)
#define C_TAG_GROUP_MAX        C_TAG_GROUP_MASK_LOW
#define C_TAG_GROUP_MASK       (C_TAG_GROUP_MASK_LOW << C_TAG_GROUP_SHIFT)

#define C_TAG_GROUP_NEXT_BIT   (C_TAG_GROUP_FIRST_BIT + C_TAG_GROUP_BITS)

#define ERR_IS_DEVEL(X) (((X) & C_TAG_DEBUG) && (((X) & C_TAG_MASK) != C_TAG_DEBUG))

#define ERR_PURE_TAG(X) ((((X) & C_TAG_MASK) == C_TAG_DEBUG) ? \
                            C_TAG_DEBUG \
                          : ((X) & (C_TAG_MASK & ~C_TAG_DEBUG)))

#define ERR_EXACTLY_ONE_BIT(X) \
           ((X) != 0 && (((X) | ((X)-1)) == (2*(X)-1)))


/* ********************************************************************** */
/* A simple means of adding a module string is to define
 * ERR_MODULE_TOKEN (a token) or ERR_MODULE (a string) during
 * compilation of a file.
 *
 * Note that the following tags are not redefined:
 *    C_TAG_BANNER
 *    C_TAG_ASSERTION
 *    C_TAG_PROGESS
 * If you want them, too, you can make similar definitions for these
 * tags in your own files.
 */
#if !defined(IN_LIBERROR_COMPILE)
#  if defined(ERR_MODULE_TOKEN) || defined(ERR_MODULE)

#    ifndef ERR_MODULE
#      define ERR_MAKE_STRING_AUX(X)  #X
#      define ERR_MAKE_STRING(X)      ERR_MAKE_STRING_AUX(X)
#      define ERR_MODULE              ERR_MAKE_STRING(ERR_MODULE_TOKEN)
#    endif

#define ERR_SUBSYSTEM_ID (_err_subsystem_cache())

#    undef  C_TAG_ERR
#    define C_TAG_ERR      (_C_TAG_ERR      + ERR_SUBSYSTEM_ID)
#    undef  C_TAG_WARN
#    define C_TAG_WARN     (_C_TAG_WARN     + ERR_SUBSYSTEM_ID)
#    undef  C_TAG_INFO
#    define C_TAG_INFO     (_C_TAG_INFO     + ERR_SUBSYSTEM_ID)
#    undef  C_TAG_NOTE
#    define C_TAG_NOTE     (_C_TAG_NOTE     + ERR_SUBSYSTEM_ID)
#    undef  C_TAG_PROMPT
#    define C_TAG_PROMPT   (_C_TAG_PROMPT   + ERR_SUBSYSTEM_ID)
#    undef  C_TAG_DEBUG
#    define C_TAG_DEBUG    (_C_TAG_DEBUG    + ERR_SUBSYSTEM_ID)
#    undef  C_TAG_INTERNAL
#    define C_TAG_INTERNAL (_C_TAG_INTERNAL + ERR_SUBSYSTEM_ID)
#    undef  C_TAG_FATAL
#    define C_TAG_FATAL    (_C_TAG_FATAL    + ERR_SUBSYSTEM_ID)

#  endif /* defined MODULES_TOKEN */
#endif   /* !defined IN_LIBERROR_COMPILE */

#endif /* !defined HT_ERROR_TAGS_H */
