/*-*- Mode: C -*-*/
/* ----------------------------------------------------------------------
 *
 * Author: Henrik Theiling
 *
 * ---------------------------------------------------------------------- */

#ifndef AI_SETTINGS_1550_H
#define AI_SETTINGS_1550_H

#if defined(HAVE_CONFIG_H)
# if defined(IN_LIBERROR_COMPILE)
#   include "error/err-config.h"
# else
#   include <error/err-config.h>
# endif
#elif defined(_MSC_VER)
# define HAVE_STDERR 1
#endif

#ifdef WITH_DMALLOC
#include <stdlib.h>
#include <dmalloc.h>
#endif

#ifdef IN_LIBERROR_COMPILE
#include "error/tags.h"
#else
#include <error/tags.h>
#endif

/* Erwin settings */
#if !defined(ERR_CHECK_COMPILE)
#if defined(__cplusplus) || defined(IN_LIBERROR_COMPILE) || defined(ERR_ERWIN_COMPILING)
#define ERR_ERWIN_REQUIRE_DETERMINISM   1
#endif
#endif

#define ERR_ERWIN_ERROR_STREAM  C_TAG_ASSERT, 0
#define ERR_ERWIN_ERROR_PRINT   eprintf

#define ERR_V_CHAR_MANY_CASTS     1

#define ERR_ERWIN_CONSTANT_ZERO   1
#define ERR_ERWIN_RANGE_CHECK     DEBUG

#define ERR_CHAR_P_DETCMP(A,B)                      (abort(), 0)
#define ERR_FILE_P_DETCMP(A,B)                      (abort(), 0)
#define ERR_ERR_SYMBOL_T_DETCMP(A,B)                (abort(), 0)
#define ERR_ERRVCALLBACK_P_DETCMP(A,B)              (abort(), 0)
#define ERR_ERRVSTREAM_P_DETCMP(A,B)                (abort(), 0)
#define ERR_ERR_FORMATTED_CALLBACK_T_P_DETCMP(A,B)  (abort(), 0)

#if 0

#define ERR_LOG(S,P,P2,Z,T)                                         \
        ({                                                          \
            void *__p2= (P2);                                       \
            fprintf (stderr, "%s:%d: TRACE: %s: %s %s %zu %p %p\n", \
                __FILE__, __LINE__, ERWIN_PRETTY_FUNCTION,          \
                S, T, (size_t)(Z), (void*)(P), __p2);               \
            __p2;                                                   \
        })

/* non-resizable stuff: */
#define ERR_ERWIN_TMALLOC(T,S) \
                        (T*)(ERR_LOG("malloc1", 0, malloc(S),                S,             #T))

#define ERR_ERWIN_TCALLOC(T,S) \
                        (T*)(ERR_LOG("calloc1", 0, calloc(1,S),              S,             #T))

#define ERR_ERWIN_TFREE(P,T,S) \
                        free(ERR_LOG("free1",   0, P,                        S,             #T))

/* resizable stuff: */
#define ERR_ERWIN_TMALLOC_ARRAY(T,N) \
                        (T*)(ERR_LOG("malloc",  0, malloc(sizeof(T)*(N)),    sizeof(T)*(N), #T))

#define ERR_ERWIN_TCALLOC_ARRAY(T,N) \
                        (T*)(ERR_LOG("calloc",  0, calloc(N,sizeof(T)),      sizeof(T)*(N), #T))

#define ERR_ERWIN_TREALLOC_ARRAY(P,T,N,O) \
                        (T*)(ERR_LOG("realloc", P, realloc(P,sizeof(T)*(N)), sizeof(T)*(N), #T))

#define ERR_ERWIN_TFREE_ARRAY(P) \
                        free(ERR_LOG("free",    0, P,                        0,             ""))

#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* AI_SETTINGS_1550_H */


