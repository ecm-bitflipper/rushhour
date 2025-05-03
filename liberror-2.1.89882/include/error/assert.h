/*-*- Mode: C -*-*/

#ifndef HT_ERROR_ASSERT_H
#define HT_ERROR_ASSERT_H

/* assert.h substitute using liberror to print assertions */

#ifdef assert
#undef assert
#endif

#if defined(err_exit_if_fail)

#  define assert(expr) err_exit_if_fail(expr)

#elif defined(NDEBUG)

#  define assert(expr) ((void)0)

#else

#  define assert(expr)                                          \
        ((void) ((expr) ? 0 :                                   \
                 (fleprintf (C_TAG_ASSERT, 0,                   \
                      __FILE__, __LINE__,                       \
                      "In function %s: Assertion failed: %s\n", \
                      __ASSERT_FUNCTION, #expr),                \
                  abort(),                                      \
                  0)))

#  ifdef __GNUC__
#     define __ASSERT_FUNCTION    __PRETTY_FUNCTION__
#  else
#     define __ASSERT_FUNCTION    "unknown"
#  endif

#endif

#endif /* !defined HT_ERROR_ASSERT_H */
