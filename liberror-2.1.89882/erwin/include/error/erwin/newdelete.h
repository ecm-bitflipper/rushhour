/* -*- Mode: C -*- */

/*
 * Author:      Henrik Theiling
 * Description: Extended C++ programming, definition file for DELETE/REF/UNREF
 *
 * @@Begin: Licencing and Copying@@
 *
 * Copyright (c) Henrik Theiling
 * Licence Version 2, Special Version for Erwin.
 *
 * The term 'this software' used in the following, additional to its
 * usual usage, also includes the instantiated source files generated by
 * tools of this package.
 *
 * This software is provided 'as-is', without warranty of any kind,
 * express or implied.  In no event will the authors or copyright holders
 * be held liable for any damages arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must
 * not claim that you wrote the original software. If you use this
 * software in a product, an acknowledgment in the product documentation
 * would be appreciated.
 *
 * 2. Altered source versions must be plainly marked as such, and must
 * not be misrepresented as being the original software.
 *
 * 3. You must not use any of the names of the authors or copyright
 * holders of the original software for advertising or publicity
 * pertaining to distribution without specific, written prior permission.
 *
 * 4. If you change this software and redistribute parts or all of it in
 * any form, you must make the source code of the altered version of this
 * software available.  As an exception, files that were generated by
 * tools of this package may be used freely, including modification.
 *
 * 5. This notice must not be removed or altered from any source
 * distribution.
 *
 * This licence is governed by the Laws of Germany.  Disputes shall be
 * settled by Saarbruecken City Court.
 *
 * @@End: Licencing and Copying@@
 */

#ifndef ERR_ERWIN_NEWDELETE_H
#define ERR_ERWIN_NEWDELETE_H

/*
 * Note: The _RVAL versions and REF permit something that is computed without invoking
 *       anything twice.  The other versions do not permit that since there
 *       is no way to write that in standard C.
 */

#define ERR_FREE_FOREIGN(free, x)                \
        do {                                        \
            void *ERWIN_GENSYM(local_x)= (void *)x; \
            if (ERWIN_GENSYM(local_x)) {            \
                (x)= NULL;                          \
                free (ERWIN_GENSYM(local_x));       \
            }                                       \
        } while (0)

#define ERR_FREE_FOREIGN_RVAL(free, x) \
        do {                              \
            if (x) {                      \
                free (x);                 \
            }                             \
        } while (0)

#ifdef __cplusplus

/* DELETE_FOREIGN is currently not supported due to lack of recursion
 * protection.  Use DELETE_QUALIFIED instead. */


/* DELETE_QUALIFIED first assigns NULL before invoking ref_unref
 * in order to install a recursion protection.
 *
 * This function uses another trick to detect possibly wrong pointer
 * assignments: if you derive B from A, but for deleting B, you need
 * a pointer to B, not to A, you might accidentally pass A* to the
 * following macro.  This will invoke the wrong destructor and go
 * without warning since you may cast B* to A* in C++.  By assigning
 * (Type*)NULL to the reference, you will get an error, however, because
 * you cannot assign from A* to B*.
 */
#define ERR_DELETE_QUALIFIED(Type, x)        \
        do {                                    \
            Type ERWIN_GENSYM(local_x)= x;      \
            if (ERWIN_GENSYM(local_x)) {        \
                (x)= ((Type)(NULL));            \
                delete (ERWIN_GENSYM(local_x)); \
            }                                   \
        } while (0)

#define ERR_DELETE_FOREIGN_RVAL(x) \
        do {                          \
            if (x) {                  \
                delete (x);           \
            }                         \
        } while (0)

/* DELETE first assigns NULL before invoking ref_unref in order
 * to install a recursion protection. */
#define ERR_DELETE(x)                                       \
        do {                                                   \
            ErrDeletable *ERWIN_GENSYM(local_x)= x; \
            if (ERWIN_GENSYM(local_x)) {                       \
                (x)= NULL;                                     \
                delete ERWIN_GENSYM(local_x);                  \
            }                                                  \
        } while (0)

#define ERR_DELETE_RVAL(x)                                  \
        do {                                                   \
            ErrDeletable *ERWIN_GENSYM(local_x)= x; \
            if (ERWIN_GENSYM(local_x))                         \
                delete ERWIN_GENSYM(local_x);                  \
        } while (0)

#if ERWIN_BOOL_VALUE(ERR_ERWIN_CLASS_REFCOUNT) || ERWIN_BOOL_VALUE(ERR_ERWIN_CLASS_REFCOUNT_FAKE)

#define ERR_REF(x) \
        ((x)->_ref())

/* REF_UNREF first assigns NULL before invoking ref_unref in order
 * to install a recursion protection. */
#define ERR_UNREF(x)                                           \
        do {                                                      \
            ErrObject const *ERWIN_GENSYM(local_x)= x; \
            if (ERWIN_GENSYM(local_x)) {                          \
                (x)= NULL;                                        \
                ERWIN_GENSYM(local_x)->_unref();                  \
            }                                                     \
        } while (0)

#define ERR_UNREF_NO_DELETE(x) ((x)->_unref_no_delete())

#define ERR_UNREF_RVAL(x) \
        ((x)->_unref())

/* REF_UNREF first assigns NULL before invoking ref_unref in order
 * to install a recursion protection. */
#define ERR_REF_UNREF(x)                                       \
        do {                                                      \
            ErrObject const *ERWIN_GENSYM(local_x)= x; \
            if (ERWIN_GENSYM(local_x)) {                          \
                (x)= NULL;                                        \
                ERWIN_GENSYM(local_x)->_ref_unref();              \
            }                                                     \
        } while (0)

#define ERR_REF_UNREF_RVAL(x) \
        ((x)->_ref_unref())

/* #elif ERWIN_BOOL_VALUE(ERR_ERWIN_CLASS_REFCOUNT_FAKE)
 *
 * We do want the resetting to NULL, so we just use the same functions as
 * with full refcounting.  This was introduced when we found places ni
 * existing code that relied on the NULLing.  Might be that the move to
 * use the above macros instead of these will trigger off problems with
 * a missing type def of ErrObject.  We'll see and repair.
 *
 * #define ERR_REF(x)             ((x)->_ref())
 * #define ERR_UNREF(x)           do{ (x)->_unref(); }while(0)
 * #define ERR_UNREF_NO_DELETE(x) ((x)->_unref_no_delete())
 * #define ERR_UNREF_RVAL(x)      ((x)->_unref())
 * #define ERR_REF_UNREF(x)       do{ (x)->_ref_unref(); }while(0)
 * #define ERR_REF_UNREF_RVAL(x)  ((x)->_ref_unref())
 */

#endif /* ERR_ERWIN_CLASS_REFCOUNT(FAKE) */

#else /* C */

#define ERR_DELETE(x)                                                     \
        do {                                                                 \
            err_object_t *ERWIN_GENSYM(local_x)= ERR_OBJECT(x);        \
            if (ERWIN_GENSYM(local_x)) {                                     \
                (x)= NULL;                                                   \
                err_object_delete (ERR_OBJECT(ERWIN_GENSYM(local_x))); \
            }                                                                \
        } while (0)

#define ERR_DELETE_RVAL(x)                                         \
        do {                                                          \
            err_object_t *ERWIN_GENSYM(local_x)= ERR_OBJECT(x); \
            if (ERWIN_GENSYM(local_x))                                \
                err_object_delete (ERWIN_GENSYM(local_x));         \
        } while (0)


#if ERWIN_BOOL_VALUE(ERR_ERWIN_CLASS_REFCOUNT)

#define ERR_REF(x) \
        err_object__ref ((err_object_t const *)(x))

/* UNREF first assigns NULL before invoking ref_unref in order
 * to install a recursion protection. */
#define ERR_UNREF(x)                                                           \
        do {                                                                      \
            err_object_t const *ERWIN_GENSYM(local_x)= ERR_OBJECT_CONST(x); \
            if (ERWIN_GENSYM(local_x)) {                                          \
                (x)= NULL;                                                        \
                err_object__unref(ERWIN_GENSYM(local_x));                      \
            }                                                                     \
        } while (0)

#define ERR_UNREF_NO_DELETE(x)                                             \
        do {                                                                  \
            if (x)                                                            \
                (void)err_object__unref_no_delete(ERR_OBJECT_CONST(x)); \
        } while (0)

#define ERR_UNREF_RVAL(x) \
        err_object__unref((err_object_t const *)(x))

/* REF_UNREF first assigns NULL before invoking ref_unref in order
 * to install a recursion protection. */
#define ERR_REF_UNREF(x)                                                       \
        do {                                                                      \
            err_object_t const *ERWIN_GENSYM(local_x)= ERR_OBJECT_CONST(x); \
            if (ERWIN_GENSYM(local_x)) {                                          \
                (x)= NULL;                                                        \
                err_object__ref_unref(ERWIN_GENSYM(local_x));                  \
            }                                                                     \
        } while (0)

#define ERR_REF_UNREF_RVAL(x) \
        err_object__ref_unref ((err_object_t const *)(x))

#elif ERWIN_BOOL_VALUE(ERR_ERWIN_CLASS_REFCOUNT_FAKE)

#define ERR_REF(x)             (x)
#define ERR_UNREF(x)           do{}while(0)
#define ERR_UNREF_NO_DELETE(x) do{}while(0)
#define ERR_UNREF_RVAL(x)      (x)
#define ERR_REF_UNREF(x)       do{}while(0)
#define ERR_REF_UNREF_RVAL(x)  (x)

#endif /* ERR_ERWIN_CLASS_REFCOUNT */

#endif /* C */

/*
 * Note: the following is outside the #ifdef protection for
 * switching the aliases back on after including classundef.h:
 */
#ifdef IN_LIBERR__COMPILE

#if ERWIN_BOOL_VALUE(ERR_ERWIN_CLASS_REFCOUNT) || ERWIN_BOOL_VALUE(ERR_ERWIN_CLASS_REFCOUNT_FAKE)
#define REF                    ERR_REF
#define UNREF                  ERR_UNREF
#define UNREF_NO_DELETE        ERR_UNREF_NO_DELETE
#define REF_UNREF              ERR_REF_UNREF
#define UNREF_RVAL             ERR_UNREF_RVAL
#define REF_UNREF_RVAL         ERR_REF_UNREF_RVAL
#endif /* ERR_ERWIN_CLASS_REFCOUNT(FAKE) */

#define DELETE                 ERR_DELETE
#define DELETE_FOREIGN         ERR_DELETE_FOREIGN
#define DELETE_FOREIGN_RVAL    ERR_DELETE_FOREIGN_RVAL
#define DELETE_QUALIFIED       ERR_DELETE_QUALIFIED
#define DELETE_QUALIFIED_RVAL  ERR_DELETE_QUALIFIED_RVAL

#define FREE_FOREIGN           ERR_FREE_FOREIGN
#define FREE_FOREIGN_RVAL      ERR_FREE_FOREIGN_RVAL

#endif /* IN_LIBERR__COMPILE */

#endif /* ERR_ERWIN_NEWDELETE_H */
