/* -*- Mode: C -*- */
/* Generated Tue Aug 19 15:44:04 GMT 2008
 */
/* Author: Henrik Theiling
 *
 * Implementation specific header file.  Only vector_char_p.c should
 * include this.
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
#warning "Including vector_char_p_i.h"
#endif

#ifndef ERWIN_VECTOR_CHAR_P_I_h
#define ERWIN_VECTOR_CHAR_P_I_h

#ifdef ERWIN_DEBUG_INCLUDE
#warning "First inclusion of vector_char_p_i.h"
#endif

/* Note:
 *    Due to complex constraints and a lot of necessary rewriting,
 *    we currently switch off INLINE_STORE when LOW_MEM is requested.
 *    One problem is a common pattern here:
 *
 *       ...ensure_size_add...
 *       CODE: do something to the vector
 *       self->m_nentries= new_size.
 *
 *   The problem is that the CODE in the middle needs self->m_nentries to
 *   decide whether the table is on the heap or inline when INLINE_STORE
 *   and LOW_MEM is activated at the same time.  In the above code, it
 *   cannot rely on self->m_nentries, however, so we'd need to restructure
 *   a lot of code, e.g. by having TABLE2 additional to TABLE, which is
 *   passed the new size (switching the order of assignment isn't always
 *   possible, since, e.g. init_tail requires self->m_nentries to be the
 *   *old* value).
 */
#if VECTOR_CHAR_P_LOW_MEM
#  undef  VECTOR_CHAR_P_INLINE_STORE
#  define VECTOR_CHAR_P_INLINE_STORE 0
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define vector_char_p_record_table(X) X

#if VECTOR_CHAR_P_LOW_MEM
#  define vector_char_p_record_tablesize(X)
#else
#  define vector_char_p_record_tablesize(X) X
#endif

#define vector_char_p_record_nentries(X) X

#ifdef ERWIN_THREAD_SAFE
#  define vector_char_p_record_errno(X) X
#else
#  define vector_char_p_record_errno(X)
#endif

#if VECTOR_CHAR_P_DYN_ZERO
#  define vector_char_p_record_zero(X) X
#else
#  define vector_char_p_record_zero(X)
#endif

#if VECTOR_CHAR_P_HAVE_SIG
#  define vector_char_p_record_sig(X) X
#else
#  define vector_char_p_record_sig(X)
#endif

#if VECTOR_CHAR_P_POSITION_POINTER
#  define vector_char_p_record_pos(X) X
#else
#  define vector_char_p_record_pos(X)
#endif

typedef char * vector_char_p_content;
typedef vector_char_p_content *vector_char_p_content_p;

#define vector_char_p_record                                               \
        vector_char_p_record_sig       (int m_sig;)                        \
        vector_char_p_record_table     (vector_char_p_content_p m_table;)         \
        vector_char_p_record_tablesize (vector_char_p_size_t m_tablesize;)        \
        vector_char_p_record_nentries  (vector_char_p_size_t m_nentries;)         \
        vector_char_p_record_pos       (vector_char_p_index_t m_pos;)             \
        vector_char_p_record_errno     (ERWIN_MUTABLE int m_errno;) \
        vector_char_p_record_zero      (char *  m_zero;)

#ifdef ERWIN_COMPAT_2_0_264

#ifdef ERWIN_COMPAT_2_0_248
struct _vector_char_p_t
#else
struct vector_char_p_t
#endif
{
    vector_char_p_record
};

#endif

/* Force linker error when .c and .h are compiled inconsistently */
#if !defined (VECTOR_CHAR_P_IMPLEMENTATION) && defined(ERWIN_WEAK_STORAGE) && !defined(NDEBUG) && !defined(ERWIN_NO_LINKER_TRICKS)
#ifdef __cplusplus
extern "C" {
#endif
#if VECTOR_CHAR_P_DYN_ZERO
ERWIN_WEAK_STORAGE void vector_char_p_variable_zero_element_expected(void) ERWIN_LINK_WEAK;
ERWIN_WEAK_STORAGE void vector_char_p_variable_zero_element_expected(void) {}
#else
ERWIN_WEAK_STORAGE void vector_char_p_constant_zero_element_expected(void) ERWIN_LINK_WEAK;
ERWIN_WEAK_STORAGE void vector_char_p_constant_zero_element_expected(void) {}
#endif
#ifdef __cplusplus
}
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
