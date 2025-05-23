/* -*- Mode: C -*- */
/* Generated Wed Sep 17 00:47:56 GMT 2008
 */
/* Author: Henrik Theiling
 *
 * Implementation specific header file.  Only err_symtab.c should
 * include this.  (For technical reasons, err_symtab.h also includes
 * it).
 */
/*
 * Copyright (c) 1999-2002 Henrik Theiling
 * 
 * This file was generated by tools of the Erwin library.  It may be used
 * freely.
 * 
 * This software is provided 'as-is', without warranty of any kind,
 * express or implied.  In no event will the authors or copyright holders
 * be held liable for any damages arising from the use of this software.
 * 
 * Disputes shall be settled by Saarbruecken City Court.
*/

#ifdef ERWIN_DEBUG_INCLUDE
#warning "Including err_symtab_i.h"
#endif

#ifndef ERWIN_ERR_SYMTAB_I_h
#define ERWIN_ERR_SYMTAB_I_h

#ifdef ERWIN_DEBUG_INCLUDE
#warning "First inclusion of err_symtab_i.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

ERWIN_KIND_TYPEDEFS(struct, err_symtab_hashlist_t)

/* For the following ones, type info isn't easy.  We need a new
 * type, a dynamic array, because we do not store the size of
 * the these arrays.  They are no vectors, which must be embedded
 * in structs. */

typedef char const * err_symtab_key_dynarray;


typedef err_symtab_hashlist_t_p err_symtab_content;
typedef err_symtab_content *err_symtab_content_p;

struct _err_symtab_hashlist_t {
    char * key;


    err_symtab_hashlist_t_p next;
#ifdef __cplusplus
    _err_symtab_hashlist_t ():
        next(NULL)
        {}

    _err_symtab_hashlist_t (char *  k):
        key (k),
        next (NULL)
        {}

#endif
};

typedef struct _err_symtab_internal_Iterator {
    err_symtab_hashlist_t *cnode;
    int    cslot;
} err_symtab_internal_Iterator;

typedef struct _err_symtab_internal_sorted_Iterator {
    err_symtab_pair_t *table;
    int         lauf;
    int         count;
    void        (*free_cb)(void *);
} err_symtab_internal_sorted_Iterator;

typedef struct _err_symtab_internal_sorted_ptr_Iterator {
    err_symtab_pair_ptr_t *table;
    int             lauf;
    int             count;
    void            (*free_cb)(void *);
} err_symtab_internal_sorted_ptr_Iterator;

#define err_symtab_record_table(X) X

#define err_symtab_record_sizes(X) X

#ifdef ERR_ERWIN_THREAD_SAFE
#  define err_symtab_record_errno(X) X
#else
#  define err_symtab_record_errno(X)
#endif

#if ERR_SYMTAB_DYN_ZERO
#  define err_symtab_record_zero(X) X
#else
#  define err_symtab_record_zero(X)
#endif

#ifdef ERR_ERWINMM_COMPAT1
#define err_symtab_record_compat(X) X
#else
#define err_symtab_record_compat(X)
#endif

#ifdef ERR_ERWIN_PROFILE
#define err_symtab_record_profile(X) X
#else
#define err_symtab_record_profile(X)
#endif

#if ERR_SYMTAB_HAVE_SIG
#  define err_symtab_record_sig(X) X
#else
#  define err_symtab_record_sig(X)
#endif

/* If m_hashsize becomes 64 bit, we need to adjust the 64-bit hashinto
 * functions (hashval_t is already 64 bit), but maps with more than
 * 2G entries currently still seem too large no matter what.  This view
 * will change soon, of course...
 *
 * Note than vectors have been switched to 64 bit values (on demand with
 * Vector_LARGE_INDEX).
 */
#define err_symtab_record                                             \
        err_symtab_record_sig     (int m_sig;)                        \
        err_symtab_record_table   (err_symtab_content_p m_table;)            \
        err_symtab_record_sizes   (int    m_hashsize;)                \
        err_symtab_record_sizes   (int    m_nentries;)                \
        err_symtab_record_errno   (ERR_ERWIN_MUTABLE int m_errno;) \
        err_symtab_record_zero    (void  m_zero;)                 \
        err_symtab_record_compat  (map_iterator_t compat1_iter;)      \
        err_symtab_record_profile (int m_nrehash;)                    \
        err_symtab_record_profile (int m_nrehashops;)                 \
        err_symtab_record_profile (int m_nfind;)                      \
        err_symtab_record_profile (int m_ninsert;)                    \
        err_symtab_record_profile (int m_ndelete;)


#ifdef ERR_ERWIN_COMPAT_2_0_264

#ifdef ERR_ERWIN_COMPAT_2_0_248
struct _err_symtab_t
#else
struct err_symtab_t
#endif
{
    err_symtab_record
};

#endif

/*
 * Force linker error when .c and .h are compiled inconsistently */
#if !defined (ERR_SYMTAB_IMPLEMENTATION) && defined(ERWIN_WEAK_STORAGE) && !defined(NDEBUG) && !defined(ERR_ERWIN_NO_LINKER_TRICKS)

#if ERR_SYMTAB_DYN_ZERO
ERWIN_WEAK_STORAGE void err_symtab_variable_zero_element_expected(void) ERWIN_LINK_WEAK;
ERWIN_WEAK_STORAGE void err_symtab_variable_zero_element_expected(void) {}
#else
ERWIN_WEAK_STORAGE void err_symtab_constant_zero_element_expected(void) ERWIN_LINK_WEAK;
ERWIN_WEAK_STORAGE void err_symtab_constant_zero_element_expected(void) {}
#endif

#ifdef ERR_ERWIN_PROFILE
ERWIN_WEAK_STORAGE void err_symtab_profile_expected(void) ERWIN_LINK_WEAK;
ERWIN_WEAK_STORAGE void err_symtab_profile_expected(void) {}
#else
ERWIN_WEAK_STORAGE void err_symtab_no_profile_expected(void) ERWIN_LINK_WEAK;
ERWIN_WEAK_STORAGE void err_symtab_no_profile_expected(void) {}
#endif

#ifdef ERR_ERWINMM_COMPAT1
ERWIN_WEAK_STORAGE void err_symtab_erwinmm_compat1_expected(void) ERWIN_LINK_WEAK;
ERWIN_WEAK_STORAGE void err_symtab_erwinmm_compat1_expected(void) {}
#else
ERWIN_WEAK_STORAGE void err_symtab_no_erwinmm_compat1_expected(void) ERWIN_LINK_WEAK;
ERWIN_WEAK_STORAGE void err_symtab_no_erwinmm_compat1_expected(void) {}
#endif

#endif /* defined(INTERNAL... *) */

#ifdef __cplusplus
}
#endif

#endif /* !defined(ERWIN_ERR_SYMTAB_I_h) */
