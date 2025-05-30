/* -*- Mode: C -*- */
/* Generated Wed Sep 17 00:48:10 GMT 2008
 */

#ifdef ERWIN_DEBUG_INCLUDE
#warning "Including err_map_int_int_d.h"
#endif

#ifndef ERWIN_ERR_MAP_INT_INT_D_h
#define ERWIN_ERR_MAP_INT_INT_D_h

#ifdef ERWIN_DEBUG_INCLUDE
#warning "First inclusion of err_map_int_int_d.h"
#endif

#include "error/err_map_u.h"
#include "error/err_map_int_int_u.h"



/* Preface */
#  define ERR_MAP_INT_INT_INDEX_IS_VOID 0
#  define ERR_MAP_INT_INT_INDEX_IS_INT 1
#  define ERR_MAP_INT_INT_INDEX_IS_CHAR 0

/* CONSTANT_ZERO */
#if ERR_MAP_INT_INT_INDEX_IS_VOID
#  undef ERR_MAP_INT_INT_CONSTANT_ZERO
#  define ERR_MAP_INT_INT_CONSTANT_ZERO 1
#  undef ERR_MAP_INT_INT_DYN_ZERO
#elif defined(ERR_MAP_INT_INT_CONSTANT_ZERO)
#  if ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_CONSTANT_ZERO)
#    undef ERR_MAP_INT_INT_CONSTANT_ZERO
#    define ERR_MAP_INT_INT_CONSTANT_ZERO 1
#  else
#    undef ERR_MAP_INT_INT_CONSTANT_ZERO
#    define ERR_MAP_INT_INT_CONSTANT_ZERO 0
#  endif
#elif defined(ERR_MAP_INT_INT_DYN_ZERO)
#  if !ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_DYN_ZERO)
#    define ERR_MAP_INT_INT_CONSTANT_ZERO 1
#  else
#    define ERR_MAP_INT_INT_CONSTANT_ZERO 0
#  endif
#elif defined(ERR_INT_HAS_CONSTANT_ZERO)
#  if ERWIN_BOOL_VALUE(ERR_INT_HAS_CONSTANT_ZERO)
#    define ERR_MAP_INT_INT_CONSTANT_ZERO 1
#  else
#    define ERR_MAP_INT_INT_CONSTANT_ZERO 0
#  endif
#elif defined(ERR_MAP_CONSTANT_ZERO)
#  if ERWIN_BOOL_VALUE(ERR_MAP_CONSTANT_ZERO)
#    define ERR_MAP_INT_INT_CONSTANT_ZERO 1
#  else
#    define ERR_MAP_INT_INT_CONSTANT_ZERO 0
#  endif
#elif defined(ERR_MAP_DYN_ZERO)
#  if !ERWIN_BOOL_VALUE(ERR_MAP_DYN_ZERO)
#    define ERR_MAP_INT_INT_CONSTANT_ZERO 1
#  else
#    define ERR_MAP_INT_INT_CONSTANT_ZERO 0
#  endif
#elif defined(ERR_ERWIN_CONSTANT_ZERO)
#  if ERWIN_BOOL_VALUE(ERR_ERWIN_CONSTANT_ZERO)
#    define ERR_MAP_INT_INT_CONSTANT_ZERO 1
#  else
#    define ERR_MAP_INT_INT_CONSTANT_ZERO 0
#  endif
#elif defined(ERR_ERWIN_DYN_ZERO)
#  if !ERWIN_BOOL_VALUE(ERR_ERWIN_DYN_ZERO)
#    define ERR_MAP_INT_INT_CONSTANT_ZERO 1
#  else
#    define ERR_MAP_INT_INT_CONSTANT_ZERO 0
#  endif
#elif defined(ALL_ERWIN_CONSTANT_ZERO)
#  if ERWIN_BOOL_VALUE(ALL_ERWIN_CONSTANT_ZERO)
#    define ERR_MAP_INT_INT_CONSTANT_ZERO 1
#  else
#    define ERR_MAP_INT_INT_CONSTANT_ZERO 0
#  endif
#elif !defined(ALL_ERWIN_DYN_ZERO)
#  define ERR_MAP_INT_INT_CONSTANT_ZERO 0
#elif !ERWIN_BOOL_VALUE(ALL_ERWIN_DYN_ZERO)
#  define ERR_MAP_INT_INT_CONSTANT_ZERO 1
#else
#  define ERR_MAP_INT_INT_CONSTANT_ZERO 0
#endif
#if !defined(ERR_MAP_INT_INT_DYN_ZERO)
#elif ERR_MAP_INT_INT_CONSTANT_ZERO == ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_DYN_ZERO)
#  error "Inconsistency: ERR_MAP_INT_INT_CONSTANT_ZERO == ERR_MAP_INT_INT_DYN_ZERO"
#endif
#if ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_CONSTANT_ZERO)
#  define ERR_MAP_INT_INT_DYN_ZERO 0
#else
#  define ERR_MAP_INT_INT_DYN_ZERO 1
#endif

/* USE_DEFAULT_ARGS */
#if !defined(__cplusplus)
#  undef ERR_MAP_INT_INT_USE_DEFAULT_ARGS
#  define ERR_MAP_INT_INT_USE_DEFAULT_ARGS 0
#  undef ERR_MAP_INT_INT_NO_DEFAULT_ARGS
#elif defined(ERR_MAP_INT_INT_USE_DEFAULT_ARGS)
#  if ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_USE_DEFAULT_ARGS)
#    undef ERR_MAP_INT_INT_USE_DEFAULT_ARGS
#    define ERR_MAP_INT_INT_USE_DEFAULT_ARGS 1
#  else
#    undef ERR_MAP_INT_INT_USE_DEFAULT_ARGS
#    define ERR_MAP_INT_INT_USE_DEFAULT_ARGS 0
#  endif
#elif defined(ERR_MAP_INT_INT_NO_DEFAULT_ARGS)
#  if !ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_NO_DEFAULT_ARGS)
#    define ERR_MAP_INT_INT_USE_DEFAULT_ARGS 1
#  else
#    define ERR_MAP_INT_INT_USE_DEFAULT_ARGS 0
#  endif
#elif defined(ERR_MAP_USE_DEFAULT_ARGS)
#  if ERWIN_BOOL_VALUE(ERR_MAP_USE_DEFAULT_ARGS)
#    define ERR_MAP_INT_INT_USE_DEFAULT_ARGS 1
#  else
#    define ERR_MAP_INT_INT_USE_DEFAULT_ARGS 0
#  endif
#elif defined(ERR_MAP_NO_DEFAULT_ARGS)
#  if !ERWIN_BOOL_VALUE(ERR_MAP_NO_DEFAULT_ARGS)
#    define ERR_MAP_INT_INT_USE_DEFAULT_ARGS 1
#  else
#    define ERR_MAP_INT_INT_USE_DEFAULT_ARGS 0
#  endif
#elif defined(ERR_ERWIN_USE_DEFAULT_ARGS)
#  if ERWIN_BOOL_VALUE(ERR_ERWIN_USE_DEFAULT_ARGS)
#    define ERR_MAP_INT_INT_USE_DEFAULT_ARGS 1
#  else
#    define ERR_MAP_INT_INT_USE_DEFAULT_ARGS 0
#  endif
#elif defined(ERR_ERWIN_NO_DEFAULT_ARGS)
#  if !ERWIN_BOOL_VALUE(ERR_ERWIN_NO_DEFAULT_ARGS)
#    define ERR_MAP_INT_INT_USE_DEFAULT_ARGS 1
#  else
#    define ERR_MAP_INT_INT_USE_DEFAULT_ARGS 0
#  endif
#elif defined(ALL_ERWIN_USE_DEFAULT_ARGS)
#  if ERWIN_BOOL_VALUE(ALL_ERWIN_USE_DEFAULT_ARGS)
#    define ERR_MAP_INT_INT_USE_DEFAULT_ARGS 1
#  else
#    define ERR_MAP_INT_INT_USE_DEFAULT_ARGS 0
#  endif
#elif !defined(ALL_ERWIN_NO_DEFAULT_ARGS)
#  define ERR_MAP_INT_INT_USE_DEFAULT_ARGS 1
#elif !ERWIN_BOOL_VALUE(ALL_ERWIN_NO_DEFAULT_ARGS)
#  define ERR_MAP_INT_INT_USE_DEFAULT_ARGS 1
#else
#  define ERR_MAP_INT_INT_USE_DEFAULT_ARGS 0
#endif
#if !defined(ERR_MAP_INT_INT_NO_DEFAULT_ARGS)
#elif ERR_MAP_INT_INT_USE_DEFAULT_ARGS == ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_NO_DEFAULT_ARGS)
#  error "Inconsistency: ERR_MAP_INT_INT_USE_DEFAULT_ARGS == ERR_MAP_INT_INT_NO_DEFAULT_ARGS"
#endif
#if ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_USE_DEFAULT_ARGS)
#  define ERR_MAP_INT_INT_NO_DEFAULT_ARGS 0
#else
#  define ERR_MAP_INT_INT_NO_DEFAULT_ARGS 1
#endif
#if defined(ERR_MAP_INT_INT_USE_DEFAULT_ARGS) && ERR_MAP_INT_INT_USE_DEFAULT_ARGS
#  define ERR_MAP_INT_INT_DEFAULT_ARG(X) = X
#else
#  define ERR_MAP_INT_INT_DEFAULT_ARG(X)
#endif

/* SUPER_CLASS */
#if !defined(__cplusplus)
#elif defined(ERR_MAP_INT_INT_SUPER_CLASS)
#elif defined(ERR_MAP_SUPER_CLASS)
#  define ERR_MAP_INT_INT_SUPER_CLASS ERR_MAP_SUPER_CLASS
#elif defined(ERR_ERWIN_SUPER_CLASS)
#  define ERR_MAP_INT_INT_SUPER_CLASS ERR_ERWIN_SUPER_CLASS
#elif defined(ALL_ERWIN_SUPER_CLASS)
#  define ERR_MAP_INT_INT_SUPER_CLASS ALL_ERWIN_SUPER_CLASS
#endif

/* SUPER_CLASS_ACCESS */
#if !defined(__cplusplus)
#elif defined(ERR_MAP_INT_INT_SUPER_CLASS_ACCESS)
#elif defined(ERR_MAP_SUPER_CLASS_ACCESS)
#  define ERR_MAP_INT_INT_SUPER_CLASS_ACCESS ERR_MAP_SUPER_CLASS_ACCESS
#elif defined(ERR_ERWIN_SUPER_CLASS_ACCESS)
#  define ERR_MAP_INT_INT_SUPER_CLASS_ACCESS ERR_ERWIN_SUPER_CLASS_ACCESS
#elif defined(ALL_ERWIN_SUPER_CLASS_ACCESS)
#  define ERR_MAP_INT_INT_SUPER_CLASS_ACCESS ALL_ERWIN_SUPER_CLASS_ACCESS
#else
#  define ERR_MAP_INT_INT_SUPER_CLASS_ACCESS private
#endif

/* STD_MEMBERS */
#if defined(ERR_MAP_INT_INT_TYPE_INFO_STD_MEMBERS)
#elif defined(err_map_int_int_t_TYPE_INFO_STD_MEMBERS)
#  define ERR_MAP_INT_INT_TYPE_INFO_STD_MEMBERS err_map_int_int_t_TYPE_INFO_STD_MEMBERS
#endif
#if defined(ERR_MAP_INT_INT_STD_MEMBERS)
#elif defined(ERR_MAP_STD_MEMBERS)
#  define ERR_MAP_INT_INT_STD_MEMBERS(CLASS_NAME) ERR_MAP_STD_MEMBERS(CLASS_NAME)
#  define ERR_MAP_INT_INT_TYPE_INFO_STD_MEMBERS ERR_MAP_TYPE_INFO_STD_MEMBERS
#elif defined(ERR_ERWIN_STD_MEMBERS)
#  define ERR_MAP_INT_INT_STD_MEMBERS(CLASS_NAME) ERR_ERWIN_STD_MEMBERS(CLASS_NAME)
#  define ERR_MAP_INT_INT_TYPE_INFO_STD_MEMBERS ERR_ERWIN_TYPE_INFO_STD_MEMBERS
#elif defined(ALL_ERWIN_STD_MEMBERS)
#  define ERR_MAP_INT_INT_STD_MEMBERS(CLASS_NAME) ALL_ERWIN_STD_MEMBERS(CLASS_NAME)
#  define ERR_MAP_INT_INT_TYPE_INFO_STD_MEMBERS ALL_ERWIN_TYPE_INFO_STD_MEMBERS
#else
#  define ERR_MAP_INT_INT_STD_MEMBERS(CLASS_NAME)
#  define ERR_MAP_INT_INT_TYPE_INFO_STD_MEMBERS
#endif

/* HAVE_SIG */
#if defined(ERR_MAP_INT_INT_HAVE_SIG)
#  if ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_HAVE_SIG)
#    undef ERR_MAP_INT_INT_HAVE_SIG
#    define ERR_MAP_INT_INT_HAVE_SIG 1
#  else
#    undef ERR_MAP_INT_INT_HAVE_SIG
#    define ERR_MAP_INT_INT_HAVE_SIG 0
#  endif
#elif defined(ERR_MAP_INT_INT_NO_SIG)
#  if !ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_NO_SIG)
#    define ERR_MAP_INT_INT_HAVE_SIG 1
#  else
#    define ERR_MAP_INT_INT_HAVE_SIG 0
#  endif
#elif defined(ERR_MAP_INT_INT_FORCE_SIG)
#  if ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_FORCE_SIG)
#    define ERR_MAP_INT_INT_HAVE_SIG 1
#  else
#    define ERR_MAP_INT_INT_HAVE_SIG 0
#  endif
#elif defined(ERR_MAP_HAVE_SIG)
#  if ERWIN_BOOL_VALUE(ERR_MAP_HAVE_SIG)
#    define ERR_MAP_INT_INT_HAVE_SIG 1
#  else
#    define ERR_MAP_INT_INT_HAVE_SIG 0
#  endif
#elif defined(ERR_MAP_NO_SIG)
#  if !ERWIN_BOOL_VALUE(ERR_MAP_NO_SIG)
#    define ERR_MAP_INT_INT_HAVE_SIG 1
#  else
#    define ERR_MAP_INT_INT_HAVE_SIG 0
#  endif
#elif defined(ERR_MAP_FORCE_SIG)
#  if ERWIN_BOOL_VALUE(ERR_MAP_FORCE_SIG)
#    define ERR_MAP_INT_INT_HAVE_SIG 1
#  else
#    define ERR_MAP_INT_INT_HAVE_SIG 0
#  endif
#elif defined(ERR_ERWIN_HAVE_SIG)
#  if ERWIN_BOOL_VALUE(ERR_ERWIN_HAVE_SIG)
#    define ERR_MAP_INT_INT_HAVE_SIG 1
#  else
#    define ERR_MAP_INT_INT_HAVE_SIG 0
#  endif
#elif defined(ERR_ERWIN_NO_SIG)
#  if !ERWIN_BOOL_VALUE(ERR_ERWIN_NO_SIG)
#    define ERR_MAP_INT_INT_HAVE_SIG 1
#  else
#    define ERR_MAP_INT_INT_HAVE_SIG 0
#  endif
#elif defined(ERR_ERWIN_FORCE_SIG)
#  if ERWIN_BOOL_VALUE(ERR_ERWIN_FORCE_SIG)
#    define ERR_MAP_INT_INT_HAVE_SIG 1
#  else
#    define ERR_MAP_INT_INT_HAVE_SIG 0
#  endif
#elif defined(ALL_ERWIN_HAVE_SIG)
#  if ERWIN_BOOL_VALUE(ALL_ERWIN_HAVE_SIG)
#    define ERR_MAP_INT_INT_HAVE_SIG 1
#  else
#    define ERR_MAP_INT_INT_HAVE_SIG 0
#  endif
#elif defined(ALL_ERWIN_NO_SIG)
#  if !ERWIN_BOOL_VALUE(ALL_ERWIN_NO_SIG)
#    define ERR_MAP_INT_INT_HAVE_SIG 1
#  else
#    define ERR_MAP_INT_INT_HAVE_SIG 0
#  endif
#elif defined(ALL_ERWIN_FORCE_SIG)
#  if ERWIN_BOOL_VALUE(ALL_ERWIN_FORCE_SIG)
#    define ERR_MAP_INT_INT_HAVE_SIG 1
#  else
#    define ERR_MAP_INT_INT_HAVE_SIG 0
#  endif
#elif defined(DEVEL)
#  define ERR_MAP_INT_INT_HAVE_SIG 1
#else
#  define ERR_MAP_INT_INT_HAVE_SIG 0
#endif
#if !defined(ERR_MAP_INT_INT_NO_SIG)
#elif ERR_MAP_INT_INT_HAVE_SIG == ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_NO_SIG)
#  error "Inconsistency: ERR_MAP_INT_INT_HAVE_SIG == ERR_MAP_INT_INT_NO_SIG"
#endif
#if !defined(ERR_MAP_INT_INT_FORCE_SIG)
#elif ERR_MAP_INT_INT_HAVE_SIG != ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_FORCE_SIG)
#  error "Inconsistency: ERR_MAP_INT_INT_HAVE_SIG != ERR_MAP_INT_INT_FORCE_SIG"
#endif
#if ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_HAVE_SIG)
#  define ERR_MAP_INT_INT_NO_SIG 0
#else
#  define ERR_MAP_INT_INT_NO_SIG 1
#endif

/* PROFILE */
#if defined(ERR_MAP_INT_INT_PROFILE)
#  if ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_PROFILE)
#    undef ERR_MAP_INT_INT_PROFILE
#    define ERR_MAP_INT_INT_PROFILE 1
#  else
#    undef ERR_MAP_INT_INT_PROFILE
#    define ERR_MAP_INT_INT_PROFILE 0
#  endif
#elif defined(ERR_MAP_PROFILE)
#  if ERWIN_BOOL_VALUE(ERR_MAP_PROFILE)
#    define ERR_MAP_INT_INT_PROFILE 1
#  else
#    define ERR_MAP_INT_INT_PROFILE 0
#  endif
#elif defined(ERR_ERWIN_PROFILE)
#  if ERWIN_BOOL_VALUE(ERR_ERWIN_PROFILE)
#    define ERR_MAP_INT_INT_PROFILE 1
#  else
#    define ERR_MAP_INT_INT_PROFILE 0
#  endif
#elif !defined(ALL_ERWIN_PROFILE)
#  define ERR_MAP_INT_INT_PROFILE 0
#elif ERWIN_BOOL_VALUE(ALL_ERWIN_PROFILE)
#  define ERR_MAP_INT_INT_PROFILE 1
#else
#  define ERR_MAP_INT_INT_PROFILE 0
#endif

/* ALLOW_NULL */
#if defined(ERR_MAP_INT_INT_ALLOW_NULL)
#  if ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_ALLOW_NULL)
#    undef ERR_MAP_INT_INT_ALLOW_NULL
#    define ERR_MAP_INT_INT_ALLOW_NULL 1
#  else
#    undef ERR_MAP_INT_INT_ALLOW_NULL
#    define ERR_MAP_INT_INT_ALLOW_NULL 0
#  endif
#elif defined(ERR_MAP_ALLOW_NULL)
#  if ERWIN_BOOL_VALUE(ERR_MAP_ALLOW_NULL)
#    define ERR_MAP_INT_INT_ALLOW_NULL 1
#  else
#    define ERR_MAP_INT_INT_ALLOW_NULL 0
#  endif
#elif defined(ERR_ERWIN_ALLOW_NULL)
#  if ERWIN_BOOL_VALUE(ERR_ERWIN_ALLOW_NULL)
#    define ERR_MAP_INT_INT_ALLOW_NULL 1
#  else
#    define ERR_MAP_INT_INT_ALLOW_NULL 0
#  endif
#elif !defined(ALL_ERWIN_ALLOW_NULL)
#  define ERR_MAP_INT_INT_ALLOW_NULL 0
#elif ERWIN_BOOL_VALUE(ALL_ERWIN_ALLOW_NULL)
#  define ERR_MAP_INT_INT_ALLOW_NULL 1
#else
#  define ERR_MAP_INT_INT_ALLOW_NULL 0
#endif

/* DIRECT_RECURSION */
#if !defined(__cplusplus)
#elif defined(ERR_MAP_INT_INT_DIRECT_RECURSION)
#  if ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_DIRECT_RECURSION)
#    undef ERR_MAP_INT_INT_DIRECT_RECURSION
#    define ERR_MAP_INT_INT_DIRECT_RECURSION 1
#  else
#    undef ERR_MAP_INT_INT_DIRECT_RECURSION
#    define ERR_MAP_INT_INT_DIRECT_RECURSION 0
#  endif
#elif defined(ERR_MAP_DIRECT_RECURSION)
#  if ERWIN_BOOL_VALUE(ERR_MAP_DIRECT_RECURSION)
#    define ERR_MAP_INT_INT_DIRECT_RECURSION 1
#  else
#    define ERR_MAP_INT_INT_DIRECT_RECURSION 0
#  endif
#elif defined(ERR_ERWIN_DIRECT_RECURSION)
#  if ERWIN_BOOL_VALUE(ERR_ERWIN_DIRECT_RECURSION)
#    define ERR_MAP_INT_INT_DIRECT_RECURSION 1
#  else
#    define ERR_MAP_INT_INT_DIRECT_RECURSION 0
#  endif
#elif !defined(ALL_ERWIN_DIRECT_RECURSION)
#  define ERR_MAP_INT_INT_DIRECT_RECURSION 0
#elif ERWIN_BOOL_VALUE(ALL_ERWIN_DIRECT_RECURSION)
#  define ERR_MAP_INT_INT_DIRECT_RECURSION 1
#else
#  define ERR_MAP_INT_INT_DIRECT_RECURSION 0
#endif

/* HAVE_INT_CONSTRUCTOR */
#if defined(__cplusplus)
#  if ERR_MAP_INT_INT_DYN_ZERO && ERR_MAP_INT_INT_INDEX_IS_INT
#    undef ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR
#    define ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR 0
#    undef ERR_MAP_INT_INT_NO_INT_CONSTRUCTOR
#  elif defined(ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR)
#    if ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR)
#      undef ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR
#      define ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR 1
#    else
#      undef ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR
#      define ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR 0
#    endif
#  elif defined(ERR_MAP_INT_INT_NO_INT_CONSTRUCTOR)
#    if !ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_NO_INT_CONSTRUCTOR)
#      define ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR 1
#    else
#      define ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR 0
#    endif
#  elif defined(ERR_MAP_HAVE_INT_CONSTRUCTOR)
#    if ERWIN_BOOL_VALUE(ERR_MAP_HAVE_INT_CONSTRUCTOR)
#      define ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR 1
#    else
#      define ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR 0
#    endif
#  elif defined(ERR_MAP_NO_INT_CONSTRUCTOR)
#    if !ERWIN_BOOL_VALUE(ERR_MAP_NO_INT_CONSTRUCTOR)
#      define ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR 1
#    else
#      define ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR 0
#    endif
#  elif defined(ERR_ERWIN_HAVE_INT_CONSTRUCTOR)
#    if ERWIN_BOOL_VALUE(ERR_ERWIN_HAVE_INT_CONSTRUCTOR)
#      define ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR 1
#    else
#      define ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR 0
#    endif
#  elif defined(ERR_ERWIN_NO_INT_CONSTRUCTOR)
#    if !ERWIN_BOOL_VALUE(ERR_ERWIN_NO_INT_CONSTRUCTOR)
#      define ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR 1
#    else
#      define ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR 0
#    endif
#  elif defined(ALL_ERWIN_HAVE_INT_CONSTRUCTOR)
#    if ERWIN_BOOL_VALUE(ALL_ERWIN_HAVE_INT_CONSTRUCTOR)
#      define ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR 1
#    else
#      define ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR 0
#    endif
#  elif !defined(ALL_ERWIN_NO_INT_CONSTRUCTOR)
#    define ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR 1
#  elif !ERWIN_BOOL_VALUE(ALL_ERWIN_NO_INT_CONSTRUCTOR)
#    define ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR 1
#  else
#    define ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR 0
#  endif
#  if !defined(ERR_MAP_INT_INT_NO_INT_CONSTRUCTOR)
#  elif ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR == ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_NO_INT_CONSTRUCTOR)
#    error "Inconsistency: ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR == ERR_MAP_INT_INT_NO_INT_CONSTRUCTOR"
#  endif
#  if ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_HAVE_INT_CONSTRUCTOR)
#    define ERR_MAP_INT_INT_NO_INT_CONSTRUCTOR 0
#  else
#    define ERR_MAP_INT_INT_NO_INT_CONSTRUCTOR 1
#  endif
#endif

/* MANY_CASTS */
#if !defined(__cplusplus)
#  undef ERR_MAP_INT_INT_MANY_CASTS
#  define ERR_MAP_INT_INT_MANY_CASTS 0
#elif defined(ERR_MAP_INT_INT_MANY_CASTS)
#  if ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_MANY_CASTS)
#    undef ERR_MAP_INT_INT_MANY_CASTS
#    define ERR_MAP_INT_INT_MANY_CASTS 1
#  else
#    undef ERR_MAP_INT_INT_MANY_CASTS
#    define ERR_MAP_INT_INT_MANY_CASTS 0
#  endif
#elif defined(ERR_MAP_MANY_CASTS)
#  if ERWIN_BOOL_VALUE(ERR_MAP_MANY_CASTS)
#    define ERR_MAP_INT_INT_MANY_CASTS 1
#  else
#    define ERR_MAP_INT_INT_MANY_CASTS 0
#  endif
#elif defined(ERR_ERWIN_MANY_CASTS)
#  if ERWIN_BOOL_VALUE(ERR_ERWIN_MANY_CASTS)
#    define ERR_MAP_INT_INT_MANY_CASTS 1
#  else
#    define ERR_MAP_INT_INT_MANY_CASTS 0
#  endif
#elif !defined(ALL_ERWIN_MANY_CASTS)
#  define ERR_MAP_INT_INT_MANY_CASTS 0
#elif ERWIN_BOOL_VALUE(ALL_ERWIN_MANY_CASTS)
#  define ERR_MAP_INT_INT_MANY_CASTS 1
#else
#  define ERR_MAP_INT_INT_MANY_CASTS 0
#endif
#if defined(ERR_MAP_INT_INT_MANY_CASTS) && ERR_MAP_INT_INT_MANY_CASTS
#  define ERR_MAP_INT_INT_DEFAULT_ARG_MANY(X) ERR_MAP_INT_INT_DEFAULT_ARG(X)
#else
#  define ERR_MAP_INT_INT_DEFAULT_ARG_MANY(X)
#endif

/* # */
#ifdef ERR_MAP_INT_INT_IMPLEMENTATION



#ifdef ERR_ERWIN_COMPILING
#  include "error/erwin/defaults.h"
#  include "error/erwin/forwards.h"
#else
#  include <error/erwin/defaults.h>
#  include <error/erwin/forwards.h>
#endif

/* NOMEM_IS_FATAL */
#if defined(ERR_MAP_INT_INT_NOMEM_IS_FATAL)
#  if ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_NOMEM_IS_FATAL)
#    undef ERR_MAP_INT_INT_NOMEM_IS_FATAL
#    define ERR_MAP_INT_INT_NOMEM_IS_FATAL 1
#  else
#    undef ERR_MAP_INT_INT_NOMEM_IS_FATAL
#    define ERR_MAP_INT_INT_NOMEM_IS_FATAL 0
#  endif
#elif defined(ERR_MAP_NOMEM_IS_FATAL)
#  if ERWIN_BOOL_VALUE(ERR_MAP_NOMEM_IS_FATAL)
#    define ERR_MAP_INT_INT_NOMEM_IS_FATAL 1
#  else
#    define ERR_MAP_INT_INT_NOMEM_IS_FATAL 0
#  endif
#elif defined(ERR_ERWIN_NOMEM_IS_FATAL)
#  if ERWIN_BOOL_VALUE(ERR_ERWIN_NOMEM_IS_FATAL)
#    define ERR_MAP_INT_INT_NOMEM_IS_FATAL 1
#  else
#    define ERR_MAP_INT_INT_NOMEM_IS_FATAL 0
#  endif
#elif !defined(ALL_ERWIN_NOMEM_IS_FATAL)
#  define ERR_MAP_INT_INT_NOMEM_IS_FATAL 0
#elif ERWIN_BOOL_VALUE(ALL_ERWIN_NOMEM_IS_FATAL)
#  define ERR_MAP_INT_INT_NOMEM_IS_FATAL 1
#else
#  define ERR_MAP_INT_INT_NOMEM_IS_FATAL 0
#endif

/* ASSERTION_FAILED_HANDLER */
#if defined(ERR_MAP_INT_INT_ASSERTION_FAILED_HANDLER)
#elif defined(ERR_MAP_ASSERTION_FAILED_HANDLER)
#  define ERR_MAP_INT_INT_ASSERTION_FAILED_HANDLER(FILE,LINE,FUNC,CHECK) ERR_MAP_ASSERTION_FAILED_HANDLER(FILE,LINE,FUNC,CHECK)
#elif defined(ERR_ERWIN_ASSERTION_FAILED_HANDLER)
#  define ERR_MAP_INT_INT_ASSERTION_FAILED_HANDLER(FILE,LINE,FUNC,CHECK) ERR_ERWIN_ASSERTION_FAILED_HANDLER(FILE,LINE,FUNC,CHECK)
#elif defined(ALL_ERWIN_ASSERTION_FAILED_HANDLER)
#  define ERR_MAP_INT_INT_ASSERTION_FAILED_HANDLER(FILE,LINE,FUNC,CHECK) ALL_ERWIN_ASSERTION_FAILED_HANDLER(FILE,LINE,FUNC,CHECK)
#else
#  define ERR_MAP_INT_INT_ASSERTION_FAILED_HANDLER(FILE,LINE,FUNC,CHECK) ERR_ERWIN_DEFAULT_ASSERTION_FAILED_HANDLER(FILE,LINE,FUNC,CHECK)
#endif

/* OPTIMISE_SIZE */
#if defined(ERR_MAP_INT_INT_OPTIMISE_SIZE)
#  if ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_OPTIMISE_SIZE)
#    undef ERR_MAP_INT_INT_OPTIMISE_SIZE
#    define ERR_MAP_INT_INT_OPTIMISE_SIZE 1
#  else
#    undef ERR_MAP_INT_INT_OPTIMISE_SIZE
#    define ERR_MAP_INT_INT_OPTIMISE_SIZE 0
#  endif
#elif defined(ERR_MAP_OPTIMISE_SIZE)
#  if ERWIN_BOOL_VALUE(ERR_MAP_OPTIMISE_SIZE)
#    define ERR_MAP_INT_INT_OPTIMISE_SIZE 1
#  else
#    define ERR_MAP_INT_INT_OPTIMISE_SIZE 0
#  endif
#elif defined(ERR_ERWIN_OPTIMISE_SIZE)
#  if ERWIN_BOOL_VALUE(ERR_ERWIN_OPTIMISE_SIZE)
#    define ERR_MAP_INT_INT_OPTIMISE_SIZE 1
#  else
#    define ERR_MAP_INT_INT_OPTIMISE_SIZE 0
#  endif
#elif !defined(ALL_ERWIN_OPTIMISE_SIZE)
#elif ERWIN_BOOL_VALUE(ALL_ERWIN_OPTIMISE_SIZE)
#  define ERR_MAP_INT_INT_OPTIMISE_SIZE 1
#else
#  define ERR_MAP_INT_INT_OPTIMISE_SIZE 0
#endif

/* SPLIT */
#if defined(ERR_MAP_INT_INT_SPLIT)
#  if ERWIN_BOOL_VALUE(ERR_MAP_INT_INT_SPLIT)
#    undef ERR_MAP_INT_INT_SPLIT
#    define ERR_MAP_INT_INT_SPLIT 1
#  else
#    undef ERR_MAP_INT_INT_SPLIT
#    define ERR_MAP_INT_INT_SPLIT 0
#  endif
#elif defined(ERR_MAP_SPLIT)
#  if ERWIN_BOOL_VALUE(ERR_MAP_SPLIT)
#    define ERR_MAP_INT_INT_SPLIT 1
#  else
#    define ERR_MAP_INT_INT_SPLIT 0
#  endif
#elif defined(ERR_ERWIN_SPLIT)
#  if ERWIN_BOOL_VALUE(ERR_ERWIN_SPLIT)
#    define ERR_MAP_INT_INT_SPLIT 1
#  else
#    define ERR_MAP_INT_INT_SPLIT 0
#  endif
#elif !defined(ALL_ERWIN_SPLIT)
#elif ERWIN_BOOL_VALUE(ALL_ERWIN_SPLIT)
#  define ERR_MAP_INT_INT_SPLIT 1
#else
#  define ERR_MAP_INT_INT_SPLIT 0
#endif

/* INITIAL_SIZE */
#if defined(ERR_MAP_INT_INT_INITIAL_SIZE)
#elif defined(ERR_MAP_INITIAL_SIZE)
#  define ERR_MAP_INT_INT_INITIAL_SIZE ERR_MAP_INITIAL_SIZE
#elif defined(ERR_ERWIN_INITIAL_SIZE)
#  define ERR_MAP_INT_INT_INITIAL_SIZE ERR_ERWIN_INITIAL_SIZE
#elif defined(ALL_ERWIN_INITIAL_SIZE)
#  define ERR_MAP_INT_INT_INITIAL_SIZE ALL_ERWIN_INITIAL_SIZE
#else
#  define ERR_MAP_INT_INT_INITIAL_SIZE 4
#endif

/* MINIMAL_SIZE */
#if defined(ERR_MAP_INT_INT_MINIMAL_SIZE)
#elif defined(ERR_MAP_MINIMAL_SIZE)
#  define ERR_MAP_INT_INT_MINIMAL_SIZE ERR_MAP_MINIMAL_SIZE
#elif defined(ERR_ERWIN_MINIMAL_SIZE)
#  define ERR_MAP_INT_INT_MINIMAL_SIZE ERR_ERWIN_MINIMAL_SIZE
#elif defined(ALL_ERWIN_MINIMAL_SIZE)
#  define ERR_MAP_INT_INT_MINIMAL_SIZE ALL_ERWIN_MINIMAL_SIZE
#else
#  define ERR_MAP_INT_INT_MINIMAL_SIZE 4
#endif

/* TRIGGER_DENOMINATOR */
#if defined(ERR_MAP_INT_INT_TRIGGER_DENOMINATOR)
#elif defined(ERR_MAP_TRIGGER_DENOMINATOR)
#  define ERR_MAP_INT_INT_TRIGGER_DENOMINATOR ERR_MAP_TRIGGER_DENOMINATOR
#elif defined(ERR_ERWIN_TRIGGER_DENOMINATOR)
#  define ERR_MAP_INT_INT_TRIGGER_DENOMINATOR ERR_ERWIN_TRIGGER_DENOMINATOR
#elif defined(ALL_ERWIN_TRIGGER_DENOMINATOR)
#  define ERR_MAP_INT_INT_TRIGGER_DENOMINATOR ALL_ERWIN_TRIGGER_DENOMINATOR
#else
#  define ERR_MAP_INT_INT_TRIGGER_DENOMINATOR 5
#endif

/* TRIGGER_NUMERATOR */
#if defined(ERR_MAP_INT_INT_TRIGGER_NUMERATOR)
#elif defined(ERR_MAP_TRIGGER_NUMERATOR)
#  define ERR_MAP_INT_INT_TRIGGER_NUMERATOR ERR_MAP_TRIGGER_NUMERATOR
#elif defined(ERR_ERWIN_TRIGGER_NUMERATOR)
#  define ERR_MAP_INT_INT_TRIGGER_NUMERATOR ERR_ERWIN_TRIGGER_NUMERATOR
#elif defined(ALL_ERWIN_TRIGGER_NUMERATOR)
#  define ERR_MAP_INT_INT_TRIGGER_NUMERATOR ALL_ERWIN_TRIGGER_NUMERATOR
#else
#  define ERR_MAP_INT_INT_TRIGGER_NUMERATOR 4
#endif

/* PLAIN_LIST_LENGTH */
#if defined(ERR_MAP_INT_INT_PLAIN_LIST_LENGTH)
#elif defined(ERR_MAP_PLAIN_LIST_LENGTH)
#  define ERR_MAP_INT_INT_PLAIN_LIST_LENGTH ERR_MAP_PLAIN_LIST_LENGTH
#elif defined(ERR_ERWIN_PLAIN_LIST_LENGTH)
#  define ERR_MAP_INT_INT_PLAIN_LIST_LENGTH ERR_ERWIN_PLAIN_LIST_LENGTH
#elif defined(ALL_ERWIN_PLAIN_LIST_LENGTH)
#  define ERR_MAP_INT_INT_PLAIN_LIST_LENGTH ALL_ERWIN_PLAIN_LIST_LENGTH
#elif !defined(ERR_MAP_INT_INT_TRIGGER_NUMERATOR)
#elif defined(ERR_MAP_INT_INT_TRIGGER_DENOMINATOR)
#  define ERR_MAP_INT_INT_PLAIN_LIST_LENGTH (5 * (ERR_MAP_INT_INT_TRIGGER_NUMERATOR)) / (ERR_MAP_INT_INT_TRIGGER_DENOMINATOR)
#endif

/* HASH_RAW */
#if defined(ERR_INT_HASH_RAW)
#elif defined(ERR_INT_HASHVAL)
#  define ERR_INT_HASH_RAW(X) ERR_INT_HASHVAL(X)
#else
#  define ERR_INT_HASH_RAW(X) ERR_ERWIN_DEFAULT_HASH_RAW(X)
#endif

/* HASH_RAW */
#if defined(ERR_INT_HASH_RAW)
#elif defined(ERR_INT_HASHVAL)
#  define ERR_INT_HASH_RAW(X) ERR_INT_HASHVAL(X)
#endif

/* HASH */
#if defined(ERR_INT_HASH)
#elif defined(ERR_INT_HASH_RAW)
#  define ERR_INT_HASH(X) err_hashval_t_hash((ERR_INT_HASH_RAW(X)))
#endif

/* HASH */
#if defined(ERR_INT_HASH)
#elif ERR_MAP_INT_INT_INDEX_IS_VOID
#  define ERR_INT_HASH(X) ERR_ERWIN_HASH_INIT8
#elif defined(ERR_INT_HASH_RAW)
#  define ERR_INT_HASH(X) err_hashval_t_hash((ERR_INT_HASH_RAW(X)))
#endif

/* CMP */
#if defined(ERR_INT_CMP_PROVIDED)
#elif defined(ERR_INT_CMP)
#  define ERR_INT_CMP_PROVIDED 1
#else
#  define ERR_INT_CMP_PROVIDED 0
#endif
#if defined(ERR_INT_CMP)
#elif ERR_INT_CMP_PROVIDED
#  error "Inconsistency: ERR_INT_CMP_PROVIDED is true but ERR_INT_CMP is undefined."
#endif

/* CMP */
#if defined(ERR_INT_CMP_PROVIDED)
#elif ERR_MAP_INT_INT_INDEX_IS_VOID
#  define ERR_INT_CMP_PROVIDED 0
#  undef ERR_INT_CMP
#  define ERR_INT_CMP(A,B) 0
#elif defined(ERR_INT_CMP)
#  define ERR_INT_CMP_PROVIDED 1
#else
#  define ERR_INT_CMP_PROVIDED 0
#endif
#if defined(ERR_INT_CMP)
#elif ERR_INT_CMP_PROVIDED
#  error "Inconsistency: ERR_INT_CMP_PROVIDED is true but ERR_INT_CMP is undefined."
#endif

/* DETCMP */
#if defined(ERR_INT_DETCMP_PROVIDED)
#elif defined(ERR_INT_DETCMP)
#  define ERR_INT_DETCMP_PROVIDED 1
#else
#  if defined(ERR_INT_CMP)
#    define ERR_INT_DETCMP(A,B) ERR_INT_CMP(A,B)
#  endif
#  define ERR_INT_DETCMP_PROVIDED 0
#endif
#if defined(ERR_INT_DETCMP)
#elif ERR_INT_DETCMP_PROVIDED
#  error "Inconsistency: ERR_INT_DETCMP_PROVIDED is true but ERR_INT_DETCMP is undefined."
#endif
#if defined(ERR_INT_DETCMP)
#elif !defined(ERR_ERWIN_REQUIRE_DETERMINISM)
#elif !defined(ERR_ERWIN_WEAK_DETERMINISM)
#  error "Need ERR_INT_DETCMP or ERR_INT_CMP when enforcing determinism. Try to #define ERR_INT_DETCMP(x,y) false_if_reached_pk(ERR_INT_DETCMP) if you think you never invoke it."
#endif

/* DETCMP */
#if defined(ERR_INT_DETCMP_PROVIDED)
#elif ERR_MAP_INT_INT_INDEX_IS_VOID
#  define ERR_INT_DETCMP_PROVIDED 0
#  undef ERR_INT_DETCMP
#  define ERR_INT_DETCMP(A,B) 0
#elif defined(ERR_INT_DETCMP)
#  define ERR_INT_DETCMP_PROVIDED 1
#else
#  if defined(ERR_INT_CMP)
#    define ERR_INT_DETCMP(A,B) ERR_INT_CMP(A,B)
#  endif
#  define ERR_INT_DETCMP_PROVIDED 0
#endif
#if defined(ERR_INT_DETCMP)
#elif ERR_INT_DETCMP_PROVIDED
#  error "Inconsistency: ERR_INT_DETCMP_PROVIDED is true but ERR_INT_DETCMP is undefined."
#endif
#if defined(ERR_INT_DETCMP)
#elif !defined(ERR_ERWIN_REQUIRE_DETERMINISM)
#elif !defined(ERR_ERWIN_WEAK_DETERMINISM)
#  error "Need ERR_INT_DETCMP or ERR_INT_CMP when enforcing determinism. Try to #define ERR_INT_DETCMP(x,y) false_if_reached_pk(ERR_INT_DETCMP) if you think you never invoke it."
#endif

/* EQUAL */
#if defined(ERR_INT_EQUAL_PROVIDED)
#elif defined(ERR_INT_EQUAL)
#  define ERR_INT_EQUAL_PROVIDED 1
#else
#  if !ERR_INT_CMP_PROVIDED
#    define ERR_INT_EQUAL(A,B) (A) == (B)
#  elif defined(ERR_INT_CMP)
#    define ERR_INT_EQUAL(A,B) (ERR_INT_CMP(A,B)) == 0
#  endif
#  define ERR_INT_EQUAL_PROVIDED 0
#endif
#if defined(ERR_INT_EQUAL)
#elif ERR_INT_EQUAL_PROVIDED
#  error "Inconsistency: ERR_INT_EQUAL_PROVIDED is true but ERR_INT_EQUAL is undefined."
#endif

/* EQUAL */

/* ICOPY */
#if defined(ERR_INT_ICOPY_PROVIDED)
#elif defined(ERR_INT_ICOPY)
#  define ERR_INT_ICOPY_PROVIDED 1
#elif defined(ERR_INT_COPY)
#  define ERR_INT_ICOPY_PROVIDED 1
#  define ERR_INT_ICOPY(TO_BE_COPIED,ERR_P) ERR_INT_COPY(TO_BE_COPIED,ERR_P)
#else
#  define ERR_INT_ICOPY(TO_BE_COPIED,ERR_P) TO_BE_COPIED
#  define ERR_INT_ICOPY_PROVIDED 0
#endif
#if defined(ERR_INT_ICOPY)
#elif ERR_INT_ICOPY_PROVIDED
#  error "Inconsistency: ERR_INT_ICOPY_PROVIDED is true but ERR_INT_ICOPY is undefined."
#endif

/* IFREE */
#if defined(ERR_INT_IFREE_PROVIDED)
#elif defined(ERR_INT_IFREE)
#  define ERR_INT_IFREE_PROVIDED 1
#elif defined(ERR_INT_FREE)
#  define ERR_INT_IFREE_PROVIDED 1
#  define ERR_INT_IFREE(TO_BE_DESTROYED) ERR_INT_FREE(TO_BE_DESTROYED)
#else
#  define ERR_INT_IFREE(TO_BE_DESTROYED)
#  define ERR_INT_IFREE_PROVIDED 0
#endif
#if defined(ERR_INT_IFREE)
#elif ERR_INT_IFREE_PROVIDED
#  error "Inconsistency: ERR_INT_IFREE_PROVIDED is true but ERR_INT_IFREE is undefined."
#endif

/* ZERO */
#if !defined(ERR_INT_ZERO)
#  define ERR_INT_ZERO (int )0
#endif

/* OCOPY */
#if defined(ERR_INT_OCOPY_PROVIDED)
#elif ERR_MAP_INT_INT_INDEX_IS_VOID
#  define ERR_INT_OCOPY_PROVIDED 0
#  undef ERR_INT_OCOPY
#  define ERR_INT_OCOPY(TO_BE_COPIED,ERR_P) TO_BE_COPIED
#  undef ERR_INT_COPY
#elif defined(ERR_INT_OCOPY)
#  define ERR_INT_OCOPY_PROVIDED 1
#elif defined(ERR_INT_COPY)
#  define ERR_INT_OCOPY_PROVIDED 1
#  define ERR_INT_OCOPY(TO_BE_COPIED,ERR_P) ERR_INT_COPY(TO_BE_COPIED,ERR_P)
#else
#  define ERR_INT_OCOPY(TO_BE_COPIED,ERR_P) TO_BE_COPIED
#  define ERR_INT_OCOPY_PROVIDED 0
#endif
#if defined(ERR_INT_OCOPY)
#elif ERR_INT_OCOPY_PROVIDED
#  error "Inconsistency: ERR_INT_OCOPY_PROVIDED is true but ERR_INT_OCOPY is undefined."
#endif

/* OFREE */
#if defined(ERR_INT_OFREE_PROVIDED)
#elif ERR_MAP_INT_INT_INDEX_IS_VOID
#  define ERR_INT_OFREE_PROVIDED 0
#  undef ERR_INT_OFREE
#  define ERR_INT_OFREE(TO_BE_DESTROYED)
#  undef ERR_INT_FREE
#elif defined(ERR_INT_OFREE)
#  define ERR_INT_OFREE_PROVIDED 1
#elif defined(ERR_INT_FREE)
#  define ERR_INT_OFREE_PROVIDED 1
#  define ERR_INT_OFREE(TO_BE_DESTROYED) ERR_INT_FREE(TO_BE_DESTROYED)
#else
#  define ERR_INT_OFREE(TO_BE_DESTROYED)
#  define ERR_INT_OFREE_PROVIDED 0
#endif
#if defined(ERR_INT_OFREE)
#elif ERR_INT_OFREE_PROVIDED
#  error "Inconsistency: ERR_INT_OFREE_PROVIDED is true but ERR_INT_OFREE is undefined."
#endif

/* ZERO */
#if defined(ERR_INT_ZERO)
#elif ERR_MAP_INT_INT_INDEX_IS_VOID
#  define ERR_INT_ZERO (int )0
#else
#  define ERR_INT_ZERO (int )0
#endif

/* ENSURE_VALUE */
#if defined(ERR_MAP_INT_INT_ENSURE_VALUE)
#elif defined(ERR_INT_ENSURE_VALUE)
#  define ERR_MAP_INT_INT_ENSURE_VALUE(SELF,KEY,COPY_ERR) ERR_INT_ENSURE_VALUE(COPY_ERR)
#elif defined(ERR_MAP_ENSURE_VALUE)
#  define ERR_MAP_INT_INT_ENSURE_VALUE(SELF,KEY,COPY_ERR) ERR_MAP_ENSURE_VALUE(SELF,KEY,COPY_ERR)
#elif defined(ERR_ERWIN_ENSURE_VALUE)
#  define ERR_MAP_INT_INT_ENSURE_VALUE(SELF,KEY,COPY_ERR) ERR_ERWIN_ENSURE_VALUE(SELF,KEY,COPY_ERR)
#elif defined(ALL_ERWIN_ENSURE_VALUE)
#  define ERR_MAP_INT_INT_ENSURE_VALUE(SELF,KEY,COPY_ERR) ALL_ERWIN_ENSURE_VALUE(SELF,KEY,COPY_ERR)
#elif defined(ERR_INT_OCOPY)
#  define ERR_MAP_INT_INT_ENSURE_VALUE(SELF,KEY,COPY_ERR) ERR_INT_OCOPY((ZERO(SELF)),COPY_ERR)
#endif

#endif /* ERR_MAP_INT_INT_IMPLEMENTATION */
#endif /* !defined(ERWIN_ERR_MAP_INT_INT_D_h) */
