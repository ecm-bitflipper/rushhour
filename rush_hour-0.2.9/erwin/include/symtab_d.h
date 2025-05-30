/* -*- Mode: C -*- */
/* Generated Tue Aug 19 15:44:00 GMT 2008
 */

#ifdef ERWIN_DEBUG_INCLUDE
#warning "Including symtab_d.h"
#endif

#ifndef ERWIN_SYMTAB_D_h
#define ERWIN_SYMTAB_D_h

#ifdef ERWIN_DEBUG_INCLUDE
#warning "First inclusion of symtab_d.h"
#endif

#include "map_u.h"
#include "symtab_u.h"


#ifndef HAVE_CHAR_CONST_P_CMP
#define HAVE_CHAR_CONST_P_CMP
#endif

/* Preface */
#  define SYMTAB_INDEX_IS_VOID 0
#  define SYMTAB_INDEX_IS_INT 1
#  define SYMTAB_INDEX_IS_CHAR 0

/* CONSTANT_ZERO */
#if SYMTAB_INDEX_IS_VOID
#  undef SYMTAB_CONSTANT_ZERO
#  define SYMTAB_CONSTANT_ZERO 1
#  undef SYMTAB_DYN_ZERO
#elif defined(SYMTAB_CONSTANT_ZERO)
#  if ERWIN_BOOL_VALUE(SYMTAB_CONSTANT_ZERO)
#    undef SYMTAB_CONSTANT_ZERO
#    define SYMTAB_CONSTANT_ZERO 1
#  else
#    undef SYMTAB_CONSTANT_ZERO
#    define SYMTAB_CONSTANT_ZERO 0
#  endif
#elif defined(SYMTAB_DYN_ZERO)
#  if !ERWIN_BOOL_VALUE(SYMTAB_DYN_ZERO)
#    define SYMTAB_CONSTANT_ZERO 1
#  else
#    define SYMTAB_CONSTANT_ZERO 0
#  endif
#elif defined(INT_HAS_CONSTANT_ZERO)
#  if ERWIN_BOOL_VALUE(INT_HAS_CONSTANT_ZERO)
#    define SYMTAB_CONSTANT_ZERO 1
#  else
#    define SYMTAB_CONSTANT_ZERO 0
#  endif
#elif defined(MAP_CONSTANT_ZERO)
#  if ERWIN_BOOL_VALUE(MAP_CONSTANT_ZERO)
#    define SYMTAB_CONSTANT_ZERO 1
#  else
#    define SYMTAB_CONSTANT_ZERO 0
#  endif
#elif defined(MAP_DYN_ZERO)
#  if !ERWIN_BOOL_VALUE(MAP_DYN_ZERO)
#    define SYMTAB_CONSTANT_ZERO 1
#  else
#    define SYMTAB_CONSTANT_ZERO 0
#  endif
#elif defined(ERWIN_CONSTANT_ZERO)
#  if ERWIN_BOOL_VALUE(ERWIN_CONSTANT_ZERO)
#    define SYMTAB_CONSTANT_ZERO 1
#  else
#    define SYMTAB_CONSTANT_ZERO 0
#  endif
#elif defined(ERWIN_DYN_ZERO)
#  if !ERWIN_BOOL_VALUE(ERWIN_DYN_ZERO)
#    define SYMTAB_CONSTANT_ZERO 1
#  else
#    define SYMTAB_CONSTANT_ZERO 0
#  endif
#elif defined(ALL_ERWIN_CONSTANT_ZERO)
#  if ERWIN_BOOL_VALUE(ALL_ERWIN_CONSTANT_ZERO)
#    define SYMTAB_CONSTANT_ZERO 1
#  else
#    define SYMTAB_CONSTANT_ZERO 0
#  endif
#elif !defined(ALL_ERWIN_DYN_ZERO)
#  define SYMTAB_CONSTANT_ZERO 0
#elif !ERWIN_BOOL_VALUE(ALL_ERWIN_DYN_ZERO)
#  define SYMTAB_CONSTANT_ZERO 1
#else
#  define SYMTAB_CONSTANT_ZERO 0
#endif
#if !defined(SYMTAB_DYN_ZERO)
#elif SYMTAB_CONSTANT_ZERO == ERWIN_BOOL_VALUE(SYMTAB_DYN_ZERO)
#  error "Inconsistency: SYMTAB_CONSTANT_ZERO == SYMTAB_DYN_ZERO"
#endif
#if ERWIN_BOOL_VALUE(SYMTAB_CONSTANT_ZERO)
#  define SYMTAB_DYN_ZERO 0
#else
#  define SYMTAB_DYN_ZERO 1
#endif

/* USE_DEFAULT_ARGS */
#if !defined(__cplusplus)
#  undef SYMTAB_USE_DEFAULT_ARGS
#  define SYMTAB_USE_DEFAULT_ARGS 0
#  undef SYMTAB_NO_DEFAULT_ARGS
#elif defined(SYMTAB_USE_DEFAULT_ARGS)
#  if ERWIN_BOOL_VALUE(SYMTAB_USE_DEFAULT_ARGS)
#    undef SYMTAB_USE_DEFAULT_ARGS
#    define SYMTAB_USE_DEFAULT_ARGS 1
#  else
#    undef SYMTAB_USE_DEFAULT_ARGS
#    define SYMTAB_USE_DEFAULT_ARGS 0
#  endif
#elif defined(SYMTAB_NO_DEFAULT_ARGS)
#  if !ERWIN_BOOL_VALUE(SYMTAB_NO_DEFAULT_ARGS)
#    define SYMTAB_USE_DEFAULT_ARGS 1
#  else
#    define SYMTAB_USE_DEFAULT_ARGS 0
#  endif
#elif defined(MAP_USE_DEFAULT_ARGS)
#  if ERWIN_BOOL_VALUE(MAP_USE_DEFAULT_ARGS)
#    define SYMTAB_USE_DEFAULT_ARGS 1
#  else
#    define SYMTAB_USE_DEFAULT_ARGS 0
#  endif
#elif defined(MAP_NO_DEFAULT_ARGS)
#  if !ERWIN_BOOL_VALUE(MAP_NO_DEFAULT_ARGS)
#    define SYMTAB_USE_DEFAULT_ARGS 1
#  else
#    define SYMTAB_USE_DEFAULT_ARGS 0
#  endif
#elif defined(ERWIN_USE_DEFAULT_ARGS)
#  if ERWIN_BOOL_VALUE(ERWIN_USE_DEFAULT_ARGS)
#    define SYMTAB_USE_DEFAULT_ARGS 1
#  else
#    define SYMTAB_USE_DEFAULT_ARGS 0
#  endif
#elif defined(ERWIN_NO_DEFAULT_ARGS)
#  if !ERWIN_BOOL_VALUE(ERWIN_NO_DEFAULT_ARGS)
#    define SYMTAB_USE_DEFAULT_ARGS 1
#  else
#    define SYMTAB_USE_DEFAULT_ARGS 0
#  endif
#elif defined(ALL_ERWIN_USE_DEFAULT_ARGS)
#  if ERWIN_BOOL_VALUE(ALL_ERWIN_USE_DEFAULT_ARGS)
#    define SYMTAB_USE_DEFAULT_ARGS 1
#  else
#    define SYMTAB_USE_DEFAULT_ARGS 0
#  endif
#elif !defined(ALL_ERWIN_NO_DEFAULT_ARGS)
#  define SYMTAB_USE_DEFAULT_ARGS 1
#elif !ERWIN_BOOL_VALUE(ALL_ERWIN_NO_DEFAULT_ARGS)
#  define SYMTAB_USE_DEFAULT_ARGS 1
#else
#  define SYMTAB_USE_DEFAULT_ARGS 0
#endif
#if !defined(SYMTAB_NO_DEFAULT_ARGS)
#elif SYMTAB_USE_DEFAULT_ARGS == ERWIN_BOOL_VALUE(SYMTAB_NO_DEFAULT_ARGS)
#  error "Inconsistency: SYMTAB_USE_DEFAULT_ARGS == SYMTAB_NO_DEFAULT_ARGS"
#endif
#if ERWIN_BOOL_VALUE(SYMTAB_USE_DEFAULT_ARGS)
#  define SYMTAB_NO_DEFAULT_ARGS 0
#else
#  define SYMTAB_NO_DEFAULT_ARGS 1
#endif
#if defined(SYMTAB_USE_DEFAULT_ARGS) && SYMTAB_USE_DEFAULT_ARGS
#  define SYMTAB_DEFAULT_ARG(X) = X
#else
#  define SYMTAB_DEFAULT_ARG(X)
#endif

/* SUPER_CLASS */
#if !defined(__cplusplus)
#elif defined(SYMTAB_SUPER_CLASS)
#elif defined(MAP_SUPER_CLASS)
#  define SYMTAB_SUPER_CLASS MAP_SUPER_CLASS
#elif defined(ERWIN_SUPER_CLASS)
#  define SYMTAB_SUPER_CLASS ERWIN_SUPER_CLASS
#elif defined(ALL_ERWIN_SUPER_CLASS)
#  define SYMTAB_SUPER_CLASS ALL_ERWIN_SUPER_CLASS
#endif

/* SUPER_CLASS_ACCESS */
#if !defined(__cplusplus)
#elif defined(SYMTAB_SUPER_CLASS_ACCESS)
#elif defined(MAP_SUPER_CLASS_ACCESS)
#  define SYMTAB_SUPER_CLASS_ACCESS MAP_SUPER_CLASS_ACCESS
#elif defined(ERWIN_SUPER_CLASS_ACCESS)
#  define SYMTAB_SUPER_CLASS_ACCESS ERWIN_SUPER_CLASS_ACCESS
#elif defined(ALL_ERWIN_SUPER_CLASS_ACCESS)
#  define SYMTAB_SUPER_CLASS_ACCESS ALL_ERWIN_SUPER_CLASS_ACCESS
#else
#  define SYMTAB_SUPER_CLASS_ACCESS private
#endif

/* STD_MEMBERS */
#if defined(SYMTAB_TYPE_INFO_STD_MEMBERS)
#elif defined(symtab_t_TYPE_INFO_STD_MEMBERS)
#  define SYMTAB_TYPE_INFO_STD_MEMBERS symtab_t_TYPE_INFO_STD_MEMBERS
#endif
#if defined(SYMTAB_STD_MEMBERS)
#elif defined(MAP_STD_MEMBERS)
#  define SYMTAB_STD_MEMBERS(CLASS_NAME) MAP_STD_MEMBERS(CLASS_NAME)
#  define SYMTAB_TYPE_INFO_STD_MEMBERS MAP_TYPE_INFO_STD_MEMBERS
#elif defined(ERWIN_STD_MEMBERS)
#  define SYMTAB_STD_MEMBERS(CLASS_NAME) ERWIN_STD_MEMBERS(CLASS_NAME)
#  define SYMTAB_TYPE_INFO_STD_MEMBERS ERWIN_TYPE_INFO_STD_MEMBERS
#elif defined(ALL_ERWIN_STD_MEMBERS)
#  define SYMTAB_STD_MEMBERS(CLASS_NAME) ALL_ERWIN_STD_MEMBERS(CLASS_NAME)
#  define SYMTAB_TYPE_INFO_STD_MEMBERS ALL_ERWIN_TYPE_INFO_STD_MEMBERS
#else
#  define SYMTAB_STD_MEMBERS(CLASS_NAME)
#  define SYMTAB_TYPE_INFO_STD_MEMBERS
#endif

/* HAVE_SIG */
#if defined(SYMTAB_HAVE_SIG)
#  if ERWIN_BOOL_VALUE(SYMTAB_HAVE_SIG)
#    undef SYMTAB_HAVE_SIG
#    define SYMTAB_HAVE_SIG 1
#  else
#    undef SYMTAB_HAVE_SIG
#    define SYMTAB_HAVE_SIG 0
#  endif
#elif defined(SYMTAB_NO_SIG)
#  if !ERWIN_BOOL_VALUE(SYMTAB_NO_SIG)
#    define SYMTAB_HAVE_SIG 1
#  else
#    define SYMTAB_HAVE_SIG 0
#  endif
#elif defined(SYMTAB_FORCE_SIG)
#  if ERWIN_BOOL_VALUE(SYMTAB_FORCE_SIG)
#    define SYMTAB_HAVE_SIG 1
#  else
#    define SYMTAB_HAVE_SIG 0
#  endif
#elif defined(MAP_HAVE_SIG)
#  if ERWIN_BOOL_VALUE(MAP_HAVE_SIG)
#    define SYMTAB_HAVE_SIG 1
#  else
#    define SYMTAB_HAVE_SIG 0
#  endif
#elif defined(MAP_NO_SIG)
#  if !ERWIN_BOOL_VALUE(MAP_NO_SIG)
#    define SYMTAB_HAVE_SIG 1
#  else
#    define SYMTAB_HAVE_SIG 0
#  endif
#elif defined(MAP_FORCE_SIG)
#  if ERWIN_BOOL_VALUE(MAP_FORCE_SIG)
#    define SYMTAB_HAVE_SIG 1
#  else
#    define SYMTAB_HAVE_SIG 0
#  endif
#elif defined(ERWIN_HAVE_SIG)
#  if ERWIN_BOOL_VALUE(ERWIN_HAVE_SIG)
#    define SYMTAB_HAVE_SIG 1
#  else
#    define SYMTAB_HAVE_SIG 0
#  endif
#elif defined(ERWIN_NO_SIG)
#  if !ERWIN_BOOL_VALUE(ERWIN_NO_SIG)
#    define SYMTAB_HAVE_SIG 1
#  else
#    define SYMTAB_HAVE_SIG 0
#  endif
#elif defined(ERWIN_FORCE_SIG)
#  if ERWIN_BOOL_VALUE(ERWIN_FORCE_SIG)
#    define SYMTAB_HAVE_SIG 1
#  else
#    define SYMTAB_HAVE_SIG 0
#  endif
#elif defined(ALL_ERWIN_HAVE_SIG)
#  if ERWIN_BOOL_VALUE(ALL_ERWIN_HAVE_SIG)
#    define SYMTAB_HAVE_SIG 1
#  else
#    define SYMTAB_HAVE_SIG 0
#  endif
#elif defined(ALL_ERWIN_NO_SIG)
#  if !ERWIN_BOOL_VALUE(ALL_ERWIN_NO_SIG)
#    define SYMTAB_HAVE_SIG 1
#  else
#    define SYMTAB_HAVE_SIG 0
#  endif
#elif defined(ALL_ERWIN_FORCE_SIG)
#  if ERWIN_BOOL_VALUE(ALL_ERWIN_FORCE_SIG)
#    define SYMTAB_HAVE_SIG 1
#  else
#    define SYMTAB_HAVE_SIG 0
#  endif
#elif defined(DEVEL)
#  define SYMTAB_HAVE_SIG 1
#else
#  define SYMTAB_HAVE_SIG 0
#endif
#if !defined(SYMTAB_NO_SIG)
#elif SYMTAB_HAVE_SIG == ERWIN_BOOL_VALUE(SYMTAB_NO_SIG)
#  error "Inconsistency: SYMTAB_HAVE_SIG == SYMTAB_NO_SIG"
#endif
#if !defined(SYMTAB_FORCE_SIG)
#elif SYMTAB_HAVE_SIG != ERWIN_BOOL_VALUE(SYMTAB_FORCE_SIG)
#  error "Inconsistency: SYMTAB_HAVE_SIG != SYMTAB_FORCE_SIG"
#endif
#if ERWIN_BOOL_VALUE(SYMTAB_HAVE_SIG)
#  define SYMTAB_NO_SIG 0
#else
#  define SYMTAB_NO_SIG 1
#endif

/* PROFILE */
#if defined(SYMTAB_PROFILE)
#  if ERWIN_BOOL_VALUE(SYMTAB_PROFILE)
#    undef SYMTAB_PROFILE
#    define SYMTAB_PROFILE 1
#  else
#    undef SYMTAB_PROFILE
#    define SYMTAB_PROFILE 0
#  endif
#elif defined(MAP_PROFILE)
#  if ERWIN_BOOL_VALUE(MAP_PROFILE)
#    define SYMTAB_PROFILE 1
#  else
#    define SYMTAB_PROFILE 0
#  endif
#elif defined(ERWIN_PROFILE)
#  if ERWIN_BOOL_VALUE(ERWIN_PROFILE)
#    define SYMTAB_PROFILE 1
#  else
#    define SYMTAB_PROFILE 0
#  endif
#elif !defined(ALL_ERWIN_PROFILE)
#  define SYMTAB_PROFILE 0
#elif ERWIN_BOOL_VALUE(ALL_ERWIN_PROFILE)
#  define SYMTAB_PROFILE 1
#else
#  define SYMTAB_PROFILE 0
#endif

/* ALLOW_NULL */
#if defined(SYMTAB_ALLOW_NULL)
#  if ERWIN_BOOL_VALUE(SYMTAB_ALLOW_NULL)
#    undef SYMTAB_ALLOW_NULL
#    define SYMTAB_ALLOW_NULL 1
#  else
#    undef SYMTAB_ALLOW_NULL
#    define SYMTAB_ALLOW_NULL 0
#  endif
#elif defined(MAP_ALLOW_NULL)
#  if ERWIN_BOOL_VALUE(MAP_ALLOW_NULL)
#    define SYMTAB_ALLOW_NULL 1
#  else
#    define SYMTAB_ALLOW_NULL 0
#  endif
#elif defined(ERWIN_ALLOW_NULL)
#  if ERWIN_BOOL_VALUE(ERWIN_ALLOW_NULL)
#    define SYMTAB_ALLOW_NULL 1
#  else
#    define SYMTAB_ALLOW_NULL 0
#  endif
#elif !defined(ALL_ERWIN_ALLOW_NULL)
#  define SYMTAB_ALLOW_NULL 0
#elif ERWIN_BOOL_VALUE(ALL_ERWIN_ALLOW_NULL)
#  define SYMTAB_ALLOW_NULL 1
#else
#  define SYMTAB_ALLOW_NULL 0
#endif

/* DIRECT_RECURSION */
#if !defined(__cplusplus)
#elif defined(SYMTAB_DIRECT_RECURSION)
#  if ERWIN_BOOL_VALUE(SYMTAB_DIRECT_RECURSION)
#    undef SYMTAB_DIRECT_RECURSION
#    define SYMTAB_DIRECT_RECURSION 1
#  else
#    undef SYMTAB_DIRECT_RECURSION
#    define SYMTAB_DIRECT_RECURSION 0
#  endif
#elif defined(MAP_DIRECT_RECURSION)
#  if ERWIN_BOOL_VALUE(MAP_DIRECT_RECURSION)
#    define SYMTAB_DIRECT_RECURSION 1
#  else
#    define SYMTAB_DIRECT_RECURSION 0
#  endif
#elif defined(ERWIN_DIRECT_RECURSION)
#  if ERWIN_BOOL_VALUE(ERWIN_DIRECT_RECURSION)
#    define SYMTAB_DIRECT_RECURSION 1
#  else
#    define SYMTAB_DIRECT_RECURSION 0
#  endif
#elif !defined(ALL_ERWIN_DIRECT_RECURSION)
#  define SYMTAB_DIRECT_RECURSION 0
#elif ERWIN_BOOL_VALUE(ALL_ERWIN_DIRECT_RECURSION)
#  define SYMTAB_DIRECT_RECURSION 1
#else
#  define SYMTAB_DIRECT_RECURSION 0
#endif

/* HAVE_INT_CONSTRUCTOR */
#if defined(__cplusplus)
#  if SYMTAB_DYN_ZERO && SYMTAB_INDEX_IS_INT
#    undef SYMTAB_HAVE_INT_CONSTRUCTOR
#    define SYMTAB_HAVE_INT_CONSTRUCTOR 0
#    undef SYMTAB_NO_INT_CONSTRUCTOR
#  elif defined(SYMTAB_HAVE_INT_CONSTRUCTOR)
#    if ERWIN_BOOL_VALUE(SYMTAB_HAVE_INT_CONSTRUCTOR)
#      undef SYMTAB_HAVE_INT_CONSTRUCTOR
#      define SYMTAB_HAVE_INT_CONSTRUCTOR 1
#    else
#      undef SYMTAB_HAVE_INT_CONSTRUCTOR
#      define SYMTAB_HAVE_INT_CONSTRUCTOR 0
#    endif
#  elif defined(SYMTAB_NO_INT_CONSTRUCTOR)
#    if !ERWIN_BOOL_VALUE(SYMTAB_NO_INT_CONSTRUCTOR)
#      define SYMTAB_HAVE_INT_CONSTRUCTOR 1
#    else
#      define SYMTAB_HAVE_INT_CONSTRUCTOR 0
#    endif
#  elif defined(MAP_HAVE_INT_CONSTRUCTOR)
#    if ERWIN_BOOL_VALUE(MAP_HAVE_INT_CONSTRUCTOR)
#      define SYMTAB_HAVE_INT_CONSTRUCTOR 1
#    else
#      define SYMTAB_HAVE_INT_CONSTRUCTOR 0
#    endif
#  elif defined(MAP_NO_INT_CONSTRUCTOR)
#    if !ERWIN_BOOL_VALUE(MAP_NO_INT_CONSTRUCTOR)
#      define SYMTAB_HAVE_INT_CONSTRUCTOR 1
#    else
#      define SYMTAB_HAVE_INT_CONSTRUCTOR 0
#    endif
#  elif defined(ERWIN_HAVE_INT_CONSTRUCTOR)
#    if ERWIN_BOOL_VALUE(ERWIN_HAVE_INT_CONSTRUCTOR)
#      define SYMTAB_HAVE_INT_CONSTRUCTOR 1
#    else
#      define SYMTAB_HAVE_INT_CONSTRUCTOR 0
#    endif
#  elif defined(ERWIN_NO_INT_CONSTRUCTOR)
#    if !ERWIN_BOOL_VALUE(ERWIN_NO_INT_CONSTRUCTOR)
#      define SYMTAB_HAVE_INT_CONSTRUCTOR 1
#    else
#      define SYMTAB_HAVE_INT_CONSTRUCTOR 0
#    endif
#  elif defined(ALL_ERWIN_HAVE_INT_CONSTRUCTOR)
#    if ERWIN_BOOL_VALUE(ALL_ERWIN_HAVE_INT_CONSTRUCTOR)
#      define SYMTAB_HAVE_INT_CONSTRUCTOR 1
#    else
#      define SYMTAB_HAVE_INT_CONSTRUCTOR 0
#    endif
#  elif !defined(ALL_ERWIN_NO_INT_CONSTRUCTOR)
#    define SYMTAB_HAVE_INT_CONSTRUCTOR 1
#  elif !ERWIN_BOOL_VALUE(ALL_ERWIN_NO_INT_CONSTRUCTOR)
#    define SYMTAB_HAVE_INT_CONSTRUCTOR 1
#  else
#    define SYMTAB_HAVE_INT_CONSTRUCTOR 0
#  endif
#  if !defined(SYMTAB_NO_INT_CONSTRUCTOR)
#  elif SYMTAB_HAVE_INT_CONSTRUCTOR == ERWIN_BOOL_VALUE(SYMTAB_NO_INT_CONSTRUCTOR)
#    error "Inconsistency: SYMTAB_HAVE_INT_CONSTRUCTOR == SYMTAB_NO_INT_CONSTRUCTOR"
#  endif
#  if ERWIN_BOOL_VALUE(SYMTAB_HAVE_INT_CONSTRUCTOR)
#    define SYMTAB_NO_INT_CONSTRUCTOR 0
#  else
#    define SYMTAB_NO_INT_CONSTRUCTOR 1
#  endif
#endif

/* MANY_CASTS */
#if !defined(__cplusplus)
#  undef SYMTAB_MANY_CASTS
#  define SYMTAB_MANY_CASTS 0
#elif defined(SYMTAB_MANY_CASTS)
#  if ERWIN_BOOL_VALUE(SYMTAB_MANY_CASTS)
#    undef SYMTAB_MANY_CASTS
#    define SYMTAB_MANY_CASTS 1
#  else
#    undef SYMTAB_MANY_CASTS
#    define SYMTAB_MANY_CASTS 0
#  endif
#elif defined(MAP_MANY_CASTS)
#  if ERWIN_BOOL_VALUE(MAP_MANY_CASTS)
#    define SYMTAB_MANY_CASTS 1
#  else
#    define SYMTAB_MANY_CASTS 0
#  endif
#elif defined(ERWIN_MANY_CASTS)
#  if ERWIN_BOOL_VALUE(ERWIN_MANY_CASTS)
#    define SYMTAB_MANY_CASTS 1
#  else
#    define SYMTAB_MANY_CASTS 0
#  endif
#elif !defined(ALL_ERWIN_MANY_CASTS)
#  define SYMTAB_MANY_CASTS 0
#elif ERWIN_BOOL_VALUE(ALL_ERWIN_MANY_CASTS)
#  define SYMTAB_MANY_CASTS 1
#else
#  define SYMTAB_MANY_CASTS 0
#endif
#if defined(SYMTAB_MANY_CASTS) && SYMTAB_MANY_CASTS
#  define SYMTAB_DEFAULT_ARG_MANY(X) SYMTAB_DEFAULT_ARG(X)
#else
#  define SYMTAB_DEFAULT_ARG_MANY(X)
#endif

/* # */
#ifdef SYMTAB_IMPLEMENTATION


#define CHAR_CONST_P_ICOPY string_dup
#define CHAR_CONST_P_IFREE string_free
#define CHAR_CONST_P_HASH string_hash
#define CHAR_CONST_P_CMP string_cmp

#ifdef ERWIN_COMPILING
#  include "erwin/defaults.h"
#  include "erwin/forwards.h"
#else
#  include <erwin/defaults.h>
#  include <erwin/forwards.h>
#endif

/* NOMEM_IS_FATAL */
#if defined(SYMTAB_NOMEM_IS_FATAL)
#  if ERWIN_BOOL_VALUE(SYMTAB_NOMEM_IS_FATAL)
#    undef SYMTAB_NOMEM_IS_FATAL
#    define SYMTAB_NOMEM_IS_FATAL 1
#  else
#    undef SYMTAB_NOMEM_IS_FATAL
#    define SYMTAB_NOMEM_IS_FATAL 0
#  endif
#elif defined(MAP_NOMEM_IS_FATAL)
#  if ERWIN_BOOL_VALUE(MAP_NOMEM_IS_FATAL)
#    define SYMTAB_NOMEM_IS_FATAL 1
#  else
#    define SYMTAB_NOMEM_IS_FATAL 0
#  endif
#elif defined(ERWIN_NOMEM_IS_FATAL)
#  if ERWIN_BOOL_VALUE(ERWIN_NOMEM_IS_FATAL)
#    define SYMTAB_NOMEM_IS_FATAL 1
#  else
#    define SYMTAB_NOMEM_IS_FATAL 0
#  endif
#elif !defined(ALL_ERWIN_NOMEM_IS_FATAL)
#  define SYMTAB_NOMEM_IS_FATAL 0
#elif ERWIN_BOOL_VALUE(ALL_ERWIN_NOMEM_IS_FATAL)
#  define SYMTAB_NOMEM_IS_FATAL 1
#else
#  define SYMTAB_NOMEM_IS_FATAL 0
#endif

/* ASSERTION_FAILED_HANDLER */
#if defined(SYMTAB_ASSERTION_FAILED_HANDLER)
#elif defined(MAP_ASSERTION_FAILED_HANDLER)
#  define SYMTAB_ASSERTION_FAILED_HANDLER(FILE,LINE,FUNC,CHECK) MAP_ASSERTION_FAILED_HANDLER(FILE,LINE,FUNC,CHECK)
#elif defined(ERWIN_ASSERTION_FAILED_HANDLER)
#  define SYMTAB_ASSERTION_FAILED_HANDLER(FILE,LINE,FUNC,CHECK) ERWIN_ASSERTION_FAILED_HANDLER(FILE,LINE,FUNC,CHECK)
#elif defined(ALL_ERWIN_ASSERTION_FAILED_HANDLER)
#  define SYMTAB_ASSERTION_FAILED_HANDLER(FILE,LINE,FUNC,CHECK) ALL_ERWIN_ASSERTION_FAILED_HANDLER(FILE,LINE,FUNC,CHECK)
#else
#  define SYMTAB_ASSERTION_FAILED_HANDLER(FILE,LINE,FUNC,CHECK) ERWIN_DEFAULT_ASSERTION_FAILED_HANDLER(FILE,LINE,FUNC,CHECK)
#endif

/* OPTIMISE_SIZE */
#if defined(SYMTAB_OPTIMISE_SIZE)
#  if ERWIN_BOOL_VALUE(SYMTAB_OPTIMISE_SIZE)
#    undef SYMTAB_OPTIMISE_SIZE
#    define SYMTAB_OPTIMISE_SIZE 1
#  else
#    undef SYMTAB_OPTIMISE_SIZE
#    define SYMTAB_OPTIMISE_SIZE 0
#  endif
#elif defined(MAP_OPTIMISE_SIZE)
#  if ERWIN_BOOL_VALUE(MAP_OPTIMISE_SIZE)
#    define SYMTAB_OPTIMISE_SIZE 1
#  else
#    define SYMTAB_OPTIMISE_SIZE 0
#  endif
#elif defined(ERWIN_OPTIMISE_SIZE)
#  if ERWIN_BOOL_VALUE(ERWIN_OPTIMISE_SIZE)
#    define SYMTAB_OPTIMISE_SIZE 1
#  else
#    define SYMTAB_OPTIMISE_SIZE 0
#  endif
#elif !defined(ALL_ERWIN_OPTIMISE_SIZE)
#elif ERWIN_BOOL_VALUE(ALL_ERWIN_OPTIMISE_SIZE)
#  define SYMTAB_OPTIMISE_SIZE 1
#else
#  define SYMTAB_OPTIMISE_SIZE 0
#endif

/* SPLIT */
#if defined(SYMTAB_SPLIT)
#  if ERWIN_BOOL_VALUE(SYMTAB_SPLIT)
#    undef SYMTAB_SPLIT
#    define SYMTAB_SPLIT 1
#  else
#    undef SYMTAB_SPLIT
#    define SYMTAB_SPLIT 0
#  endif
#elif defined(MAP_SPLIT)
#  if ERWIN_BOOL_VALUE(MAP_SPLIT)
#    define SYMTAB_SPLIT 1
#  else
#    define SYMTAB_SPLIT 0
#  endif
#elif defined(ERWIN_SPLIT)
#  if ERWIN_BOOL_VALUE(ERWIN_SPLIT)
#    define SYMTAB_SPLIT 1
#  else
#    define SYMTAB_SPLIT 0
#  endif
#elif !defined(ALL_ERWIN_SPLIT)
#elif ERWIN_BOOL_VALUE(ALL_ERWIN_SPLIT)
#  define SYMTAB_SPLIT 1
#else
#  define SYMTAB_SPLIT 0
#endif

/* INITIAL_SIZE */
#if defined(SYMTAB_INITIAL_SIZE)
#elif defined(MAP_INITIAL_SIZE)
#  define SYMTAB_INITIAL_SIZE MAP_INITIAL_SIZE
#elif defined(ERWIN_INITIAL_SIZE)
#  define SYMTAB_INITIAL_SIZE ERWIN_INITIAL_SIZE
#elif defined(ALL_ERWIN_INITIAL_SIZE)
#  define SYMTAB_INITIAL_SIZE ALL_ERWIN_INITIAL_SIZE
#else
#  define SYMTAB_INITIAL_SIZE 4
#endif

/* MINIMAL_SIZE */
#if defined(SYMTAB_MINIMAL_SIZE)
#elif defined(MAP_MINIMAL_SIZE)
#  define SYMTAB_MINIMAL_SIZE MAP_MINIMAL_SIZE
#elif defined(ERWIN_MINIMAL_SIZE)
#  define SYMTAB_MINIMAL_SIZE ERWIN_MINIMAL_SIZE
#elif defined(ALL_ERWIN_MINIMAL_SIZE)
#  define SYMTAB_MINIMAL_SIZE ALL_ERWIN_MINIMAL_SIZE
#else
#  define SYMTAB_MINIMAL_SIZE 4
#endif

/* TRIGGER_DENOMINATOR */
#if defined(SYMTAB_TRIGGER_DENOMINATOR)
#elif defined(MAP_TRIGGER_DENOMINATOR)
#  define SYMTAB_TRIGGER_DENOMINATOR MAP_TRIGGER_DENOMINATOR
#elif defined(ERWIN_TRIGGER_DENOMINATOR)
#  define SYMTAB_TRIGGER_DENOMINATOR ERWIN_TRIGGER_DENOMINATOR
#elif defined(ALL_ERWIN_TRIGGER_DENOMINATOR)
#  define SYMTAB_TRIGGER_DENOMINATOR ALL_ERWIN_TRIGGER_DENOMINATOR
#else
#  define SYMTAB_TRIGGER_DENOMINATOR 5
#endif

/* TRIGGER_NUMERATOR */
#if defined(SYMTAB_TRIGGER_NUMERATOR)
#elif defined(MAP_TRIGGER_NUMERATOR)
#  define SYMTAB_TRIGGER_NUMERATOR MAP_TRIGGER_NUMERATOR
#elif defined(ERWIN_TRIGGER_NUMERATOR)
#  define SYMTAB_TRIGGER_NUMERATOR ERWIN_TRIGGER_NUMERATOR
#elif defined(ALL_ERWIN_TRIGGER_NUMERATOR)
#  define SYMTAB_TRIGGER_NUMERATOR ALL_ERWIN_TRIGGER_NUMERATOR
#else
#  define SYMTAB_TRIGGER_NUMERATOR 4
#endif

/* PLAIN_LIST_LENGTH */
#if defined(SYMTAB_PLAIN_LIST_LENGTH)
#elif defined(MAP_PLAIN_LIST_LENGTH)
#  define SYMTAB_PLAIN_LIST_LENGTH MAP_PLAIN_LIST_LENGTH
#elif defined(ERWIN_PLAIN_LIST_LENGTH)
#  define SYMTAB_PLAIN_LIST_LENGTH ERWIN_PLAIN_LIST_LENGTH
#elif defined(ALL_ERWIN_PLAIN_LIST_LENGTH)
#  define SYMTAB_PLAIN_LIST_LENGTH ALL_ERWIN_PLAIN_LIST_LENGTH
#elif !defined(SYMTAB_TRIGGER_NUMERATOR)
#elif defined(SYMTAB_TRIGGER_DENOMINATOR)
#  define SYMTAB_PLAIN_LIST_LENGTH (5 * (SYMTAB_TRIGGER_NUMERATOR)) / (SYMTAB_TRIGGER_DENOMINATOR)
#endif

/* HASH_RAW */
#if defined(CHAR_CONST_P_HASH_RAW)
#elif defined(CHAR_CONST_P_HASHVAL)
#  define CHAR_CONST_P_HASH_RAW(X) CHAR_CONST_P_HASHVAL(X)
#else
#  define CHAR_CONST_P_HASH_RAW(X) ERWIN_DEFAULT_HASH_RAW(X)
#endif

/* HASH_RAW */
#if defined(INT_HASH_RAW)
#elif defined(INT_HASHVAL)
#  define INT_HASH_RAW(X) INT_HASHVAL(X)
#endif

/* HASH */
#if defined(CHAR_CONST_P_HASH)
#elif defined(CHAR_CONST_P_HASH_RAW)
#  define CHAR_CONST_P_HASH(X) hashval_t_hash((CHAR_CONST_P_HASH_RAW(X)))
#endif

/* HASH */
#if defined(INT_HASH)
#elif SYMTAB_INDEX_IS_VOID
#  define INT_HASH(X) ERWIN_HASH_INIT8
#elif defined(INT_HASH_RAW)
#  define INT_HASH(X) hashval_t_hash((INT_HASH_RAW(X)))
#endif

/* CMP */
#if defined(CHAR_CONST_P_CMP_PROVIDED)
#elif defined(CHAR_CONST_P_CMP)
#  define CHAR_CONST_P_CMP_PROVIDED 1
#else
#  define CHAR_CONST_P_CMP_PROVIDED 0
#endif
#if defined(CHAR_CONST_P_CMP)
#elif CHAR_CONST_P_CMP_PROVIDED
#  error "Inconsistency: CHAR_CONST_P_CMP_PROVIDED is true but CHAR_CONST_P_CMP is undefined."
#endif

/* CMP */
#if defined(INT_CMP_PROVIDED)
#elif SYMTAB_INDEX_IS_VOID
#  define INT_CMP_PROVIDED 0
#  undef INT_CMP
#  define INT_CMP(A,B) 0
#elif defined(INT_CMP)
#  define INT_CMP_PROVIDED 1
#else
#  define INT_CMP_PROVIDED 0
#endif
#if defined(INT_CMP)
#elif INT_CMP_PROVIDED
#  error "Inconsistency: INT_CMP_PROVIDED is true but INT_CMP is undefined."
#endif

/* DETCMP */
#if defined(CHAR_CONST_P_DETCMP_PROVIDED)
#elif defined(CHAR_CONST_P_DETCMP)
#  define CHAR_CONST_P_DETCMP_PROVIDED 1
#else
#  if defined(CHAR_CONST_P_CMP)
#    define CHAR_CONST_P_DETCMP(A,B) CHAR_CONST_P_CMP(A,B)
#  endif
#  define CHAR_CONST_P_DETCMP_PROVIDED 0
#endif
#if defined(CHAR_CONST_P_DETCMP)
#elif CHAR_CONST_P_DETCMP_PROVIDED
#  error "Inconsistency: CHAR_CONST_P_DETCMP_PROVIDED is true but CHAR_CONST_P_DETCMP is undefined."
#endif
#if defined(CHAR_CONST_P_DETCMP)
#elif !defined(ERWIN_REQUIRE_DETERMINISM)
#elif !defined(ERWIN_WEAK_DETERMINISM)
#  error "Need CHAR_CONST_P_DETCMP or CHAR_CONST_P_CMP when enforcing determinism. Try to #define CHAR_CONST_P_DETCMP(x,y) false_if_reached_pk(CHAR_CONST_P_DETCMP) if you think you never invoke it."
#endif

/* DETCMP */
#if defined(INT_DETCMP_PROVIDED)
#elif SYMTAB_INDEX_IS_VOID
#  define INT_DETCMP_PROVIDED 0
#  undef INT_DETCMP
#  define INT_DETCMP(A,B) 0
#elif defined(INT_DETCMP)
#  define INT_DETCMP_PROVIDED 1
#else
#  if defined(INT_CMP)
#    define INT_DETCMP(A,B) INT_CMP(A,B)
#  endif
#  define INT_DETCMP_PROVIDED 0
#endif
#if defined(INT_DETCMP)
#elif INT_DETCMP_PROVIDED
#  error "Inconsistency: INT_DETCMP_PROVIDED is true but INT_DETCMP is undefined."
#endif
#if defined(INT_DETCMP)
#elif !defined(ERWIN_REQUIRE_DETERMINISM)
#elif !defined(ERWIN_WEAK_DETERMINISM)
#  error "Need INT_DETCMP or INT_CMP when enforcing determinism. Try to #define INT_DETCMP(x,y) false_if_reached_pk(INT_DETCMP) if you think you never invoke it."
#endif

/* EQUAL */
#if defined(CHAR_CONST_P_EQUAL_PROVIDED)
#elif defined(CHAR_CONST_P_EQUAL)
#  define CHAR_CONST_P_EQUAL_PROVIDED 1
#else
#  if !CHAR_CONST_P_CMP_PROVIDED
#    define CHAR_CONST_P_EQUAL(A,B) (A) == (B)
#  elif defined(CHAR_CONST_P_CMP)
#    define CHAR_CONST_P_EQUAL(A,B) (CHAR_CONST_P_CMP(A,B)) == 0
#  endif
#  define CHAR_CONST_P_EQUAL_PROVIDED 0
#endif
#if defined(CHAR_CONST_P_EQUAL)
#elif CHAR_CONST_P_EQUAL_PROVIDED
#  error "Inconsistency: CHAR_CONST_P_EQUAL_PROVIDED is true but CHAR_CONST_P_EQUAL is undefined."
#endif

/* EQUAL */

/* ICOPY */
#if defined(CHAR_CONST_P_ICOPY_PROVIDED)
#elif defined(CHAR_CONST_P_ICOPY)
#  define CHAR_CONST_P_ICOPY_PROVIDED 1
#elif defined(CHAR_CONST_P_COPY)
#  define CHAR_CONST_P_ICOPY_PROVIDED 1
#  define CHAR_CONST_P_ICOPY(TO_BE_COPIED,ERR_P) CHAR_CONST_P_COPY(TO_BE_COPIED,ERR_P)
#else
#  define CHAR_CONST_P_ICOPY(TO_BE_COPIED,ERR_P) TO_BE_COPIED
#  define CHAR_CONST_P_ICOPY_PROVIDED 0
#endif
#if defined(CHAR_CONST_P_ICOPY)
#elif CHAR_CONST_P_ICOPY_PROVIDED
#  error "Inconsistency: CHAR_CONST_P_ICOPY_PROVIDED is true but CHAR_CONST_P_ICOPY is undefined."
#endif

/* IFREE */
#if defined(CHAR_CONST_P_IFREE_PROVIDED)
#elif defined(CHAR_CONST_P_IFREE)
#  define CHAR_CONST_P_IFREE_PROVIDED 1
#elif defined(CHAR_CONST_P_FREE)
#  define CHAR_CONST_P_IFREE_PROVIDED 1
#  define CHAR_CONST_P_IFREE(TO_BE_DESTROYED) CHAR_CONST_P_FREE(TO_BE_DESTROYED)
#else
#  define CHAR_CONST_P_IFREE(TO_BE_DESTROYED)
#  define CHAR_CONST_P_IFREE_PROVIDED 0
#endif
#if defined(CHAR_CONST_P_IFREE)
#elif CHAR_CONST_P_IFREE_PROVIDED
#  error "Inconsistency: CHAR_CONST_P_IFREE_PROVIDED is true but CHAR_CONST_P_IFREE is undefined."
#endif

/* ZERO */
#if !defined(CHAR_CONST_P_ZERO)
#  define CHAR_CONST_P_ZERO (char const * )0
#endif

/* OCOPY */
#if defined(INT_OCOPY_PROVIDED)
#elif SYMTAB_INDEX_IS_VOID
#  define INT_OCOPY_PROVIDED 0
#  undef INT_OCOPY
#  define INT_OCOPY(TO_BE_COPIED,ERR_P) TO_BE_COPIED
#  undef INT_COPY
#elif defined(INT_OCOPY)
#  define INT_OCOPY_PROVIDED 1
#elif defined(INT_COPY)
#  define INT_OCOPY_PROVIDED 1
#  define INT_OCOPY(TO_BE_COPIED,ERR_P) INT_COPY(TO_BE_COPIED,ERR_P)
#else
#  define INT_OCOPY(TO_BE_COPIED,ERR_P) TO_BE_COPIED
#  define INT_OCOPY_PROVIDED 0
#endif
#if defined(INT_OCOPY)
#elif INT_OCOPY_PROVIDED
#  error "Inconsistency: INT_OCOPY_PROVIDED is true but INT_OCOPY is undefined."
#endif

/* OFREE */
#if defined(INT_OFREE_PROVIDED)
#elif SYMTAB_INDEX_IS_VOID
#  define INT_OFREE_PROVIDED 0
#  undef INT_OFREE
#  define INT_OFREE(TO_BE_DESTROYED)
#  undef INT_FREE
#elif defined(INT_OFREE)
#  define INT_OFREE_PROVIDED 1
#elif defined(INT_FREE)
#  define INT_OFREE_PROVIDED 1
#  define INT_OFREE(TO_BE_DESTROYED) INT_FREE(TO_BE_DESTROYED)
#else
#  define INT_OFREE(TO_BE_DESTROYED)
#  define INT_OFREE_PROVIDED 0
#endif
#if defined(INT_OFREE)
#elif INT_OFREE_PROVIDED
#  error "Inconsistency: INT_OFREE_PROVIDED is true but INT_OFREE is undefined."
#endif

/* ZERO */
#if defined(INT_ZERO)
#elif SYMTAB_INDEX_IS_VOID
#  define INT_ZERO (int )0
#else
#  define INT_ZERO (int )0
#endif

/* ENSURE_VALUE */
#if defined(SYMTAB_ENSURE_VALUE)
#elif defined(INT_ENSURE_VALUE)
#  define SYMTAB_ENSURE_VALUE(SELF,KEY,COPY_ERR) INT_ENSURE_VALUE(COPY_ERR)
#elif defined(MAP_ENSURE_VALUE)
#  define SYMTAB_ENSURE_VALUE(SELF,KEY,COPY_ERR) MAP_ENSURE_VALUE(SELF,KEY,COPY_ERR)
#elif defined(ERWIN_ENSURE_VALUE)
#  define SYMTAB_ENSURE_VALUE(SELF,KEY,COPY_ERR) ERWIN_ENSURE_VALUE(SELF,KEY,COPY_ERR)
#elif defined(ALL_ERWIN_ENSURE_VALUE)
#  define SYMTAB_ENSURE_VALUE(SELF,KEY,COPY_ERR) ALL_ERWIN_ENSURE_VALUE(SELF,KEY,COPY_ERR)
#elif defined(INT_OCOPY)
#  define SYMTAB_ENSURE_VALUE(SELF,KEY,COPY_ERR) INT_OCOPY((ZERO(SELF)),COPY_ERR)
#endif

#endif /* SYMTAB_IMPLEMENTATION */
#endif /* !defined(ERWIN_SYMTAB_D_h) */
