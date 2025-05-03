/*-*- Mode: C -*-*/
/* ----------------------------------------------------------------------
 *
 * Author: Henrik Theiling
 *
 * ---------------------------------------------------------------------- */

/* err-default scope=project */

#ifndef HT_DECLS_7214_H
#define HT_DECLS_7214_H

#ifdef IN_LIBERROR_COMPILE
#include "error/erwin/forwards.h"
#include "error/printf.h"
#else
#include <error/erwin/forwards.h>
#include <error/printf.h>
#endif

#include <stdio.h>
#include <time.h>

/* ********************************************************************** */

typedef err_v_message_t err_buffer_t;
   /* This will change soon!!  Do not rely on the buffer to be a vector.
    * Only the following functions are blessed to be used:
    *
    * Note: We need a callback when the destructor of err_buffer_t is
    *       invoked, that, if the buffer is in use, either erases the
    *       buffer from the buffer stack or issues an assertion.
    */

#define err_buffer_new               err_v_message_new
#define err_buffer_delete            err_v_message_delete
#define err_buffer_append            err_v_message_append
#define err_buffer_clear             err_v_message_clear
#define err_buffer_nth               err_v_message_nth
#define err_buffer_nth_ptr           err_v_message_nth_ptr
#define err_buffer_erase             err_v_message_erase
#define err_buffer_erase_if          err_v_message_erase_if
#define err_buffer_nentries          err_v_message_nentries
#define err_buffer_empty             err_v_message_empty
#define err_buffer_last              err_v_message_last
#define err_buffer_first             err_v_message_first
#define err_buffer_forall            err_v_message_forall
#define err_buffer_forall_values     err_v_message_forall_values

#ifdef __cplusplus
typedef ErrVMessage ErrBuffer;
#endif

/* ********************************************************************** */

typedef char const *err_symbol_t;
typedef err_symbol_t ErrSymbol;

typedef ERR_ERWIN_BOOL ERR_BOOL;
#define ERR_TRUE  ERR_ERWIN_TRUE
#define ERR_FALSE ERR_ERWIN_FALSE

/* ********************************************************************** */

typedef void (*err_function_ptr_t)(void);
typedef err_function_ptr_t ErrFunctionPtr;

typedef void (*err_callback2_voidp_t) (
    ERR_BOOL * /*stop_callbacks*/,
    int *      /*show_counter*/,
    int /*tag*/, int /*orig_tag*/,  int /*orig_number*/, err_location_t const * /*loc*/,
    char const *, void * /*user_data*/);
    /* tag may be C_TAG_MORE, but orig_tag will always reflect the real tag with which
     * preceeded in this case.
     *
     * If you set *stop_callbacks to non-zero, no other callbacks of the current
     * group will be invoked (there are two groups: one before (with positive priorities)
     * and one after showing the message (with negative priorities)).
     *
     * For subsystem callbacks, this decides whether callback are invoked at all,
     * thus, whether the callback/showing phase is entered or not.
     * this has no effect, since there is only one callback per tag.  If this is
     * not done, the error is *not* counted as distributed.
     *
     * NOTE: continuing is the default for distribution callbacks, but
     *       not continuing is the default for subsystem callbacks.
     *
     * If *show_counter is <= 0 after the callback process, the message will not
     * be shown.  This variable is initialised to 1.
     */

typedef void (*err_callback2_int_t) (
    ERR_BOOL * /*stop_callbacks*/,
    int *      /*show_counter*/,
    int /*tag*/, int /*orig_tag*/,  int /*orig_number*/, err_location_t const * /*loc*/,
    char const *, int /*user_data*/);

typedef void (*err_callback2_t) (
    ERR_BOOL * /*stop_callbacks*/,
    int *      /*show_counter*/,
    int /*tag*/, int /*orig_tag*/,  int /*orig_number*/, err_location_t const * /*loc*/,
    char const *);

typedef void (*err_callback0_voidp_t) (
    int /*tag*/, int /*orig_tag*/,  int /*orig_number*/, err_location_t const * /*loc*/,
    char const *, void * /*user_data*/);

typedef void (*err_callback0_int_t) (
    int /*tag*/, int /*orig_tag*/,  int /*orig_number*/, err_location_t const * /*loc*/,
    char const *, int /*user_data*/);

typedef void (*err_callback0_t) (
    int /*tag*/, int /*orig_tag*/,  int /*orig_number*/, err_location_t const * /*loc*/,
    char const *);                                         

typedef void (*err_callback2_info_voidp_t) (
    ERR_BOOL * /*stop_callbacks*/,
    int *      /*show_counter*/,
    int /*tag*/, int /*orig_tag*/,  int /*orig_number*/,
    err_msg_info_t const * /*info*/,
    err_location_t const * /*loc*/,
    char const *, void * /*user_data*/);
    /* tag may be C_TAG_MORE, but orig_tag will always reflect the real tag with which
     * preceeded in this case.
     *
     * If you set *stop_callbacks to non-zero, no other callbacks of the current
     * group will be invoked (there are two groups: one before (with positive priorities)
     * and one after showing the message (with negative priorities)).
     *
     * For subsystem callbacks, this decides whether callback are invoked at all,
     * thus, whether the callback/showing phase is entered or not.
     * this has no effect, since there is only one callback per tag.  If this is
     * not done, the error is *not* counted as distributed.
     *
     * NOTE: continuing is the default for distribution callbacks, but
     *       not continuing is the default for subsystem callbacks.
     *
     * If *show_counter is <= 0 after the callback process, the message will not
     * be shown.  This variable is initialised to 1.
     */

typedef void (*err_callback2_info_int_t) (
    ERR_BOOL * /*stop_callbacks*/,
    int *      /*show_counter*/,
    int /*tag*/, int /*orig_tag*/,  int /*orig_number*/,
    err_msg_info_t const * /*info*/,
    err_location_t const * /*loc*/,
    char const *, int /*user_data*/);

typedef void (*err_callback2_info_t) (
    ERR_BOOL * /*stop_callbacks*/,
    int *      /*show_counter*/,
    int /*tag*/, int /*orig_tag*/,  int /*orig_number*/,
    err_msg_info_t const * /*info*/,
    err_location_t const * /*loc*/,
    char const *);

typedef void (*err_callback0_info_voidp_t) (
    int /*tag*/, int /*orig_tag*/,  int /*orig_number*/,
    err_msg_info_t const * /*info*/,
    err_location_t const * /*loc*/,
    char const *, void * /*user_data*/);

typedef void (*err_callback0_info_int_t) (
    int /*tag*/, int /*orig_tag*/,  int /*orig_number*/,
    err_msg_info_t const * /*info*/,
    err_location_t const * /*loc*/,
    char const *, int /*user_data*/);

typedef void (*err_callback0_info_t) (
    int /*tag*/, int /*orig_tag*/,  int /*orig_number*/,
    err_msg_info_t const * /*info*/,
    err_location_t const * /*loc*/,
    char const *);

typedef err_callback0_t            ErrCallback0;
typedef err_callback0_voidp_t      ErrCallback0Voidp;
typedef err_callback0_int_t        ErrCallback0Int;
typedef err_callback2_t            ErrCallback2;
typedef err_callback2_voidp_t      ErrCallback2Voidp;
typedef err_callback2_int_t        ErrCallback2Int;
typedef err_callback0_info_t       ErrCallback0Info;
typedef err_callback0_info_voidp_t ErrCallback0InfoVoidp;
typedef err_callback0_info_int_t   ErrCallback0InfoInt;
typedef err_callback2_info_t       ErrCallback2Info;
typedef err_callback2_info_voidp_t ErrCallback2InfoVoidp;
typedef err_callback2_info_int_t   ErrCallback2InfoInt;

/* ********************************************************************** */

struct err_style_t;
typedef struct err_style_t ErrStyle;
#ifndef __cplusplus
typedef struct err_style_t err_style_t;
#endif

    /* will be defined in liberror.h */

/* ********************************************************************** */

struct err_number_t {
    int number;
#ifdef __cplusplus
    err_number_t (int a = 0): number (a) {}
    operator err_number_t const *() const { return this; }
    operator int () const { return number; }
#endif
};

typedef struct err_number_t /*err-skip*/ErrNumber;
/* err-renumber name=ErrNumber min_argc=1 max_argc=1 argc_number=1 */

#ifndef __cplusplus
typedef struct err_number_t err_number_t;
#endif

/* Error numbers that are automatically renumbered are only recognized in
 * eprintf(), err_number(), and ErrNumber() calls.  So if you encapsulate
 * eprintf() in macros, invoke the macro with an argument that is constructed
 * using err_number() or ErrNumber().  If you use (NUMBER)->number in your
 * macro, you force the user to use err_number() in the invocation. */

/* ********************************************************************** */

struct err_filter_t;

struct err_stream_status_t {
    int    count;
    char  *last;
    int    last_tag;
    time_t started;  /* if != 0, the start time for the last message printed into
                      * this file.  This also means that we should output the
                      * elapsed time since before printing anything else into
                      * this stream. */

    err_symbol_t last_sym;
    ERR_BOOL last_sym_printed;

    struct err_filter_t *once;
    err_symtab_t *remember_once;

#ifdef __cplusplus
private:
    void release();
    void import (int, char*, int, time_t, err_symbol_t, ERR_BOOL, err_filter_t *, err_symtab_t *);

public:
    err_stream_status_t ();
    err_stream_status_t (err_stream_status_t const &);

    void operator= (err_stream_status_t const &);
    ~err_stream_status_t ();

    void detach()
    {
        once= NULL;
        remember_once= NULL;
    }
#endif
};

struct err_formatted_stream_t {
    FILE *file;
    char const *name;
    err_style_t const *style;

    struct err_filter_t *filter;

    struct err_stream_status_t status;

#ifdef __cplusplus
public:
    err_formatted_stream_t (char const *);
    err_formatted_stream_t (FILE *, err_style_t const *);

private:
    /* Thou shalt not copy streams.  For there shall only be one stream per file! */
    err_formatted_stream_t (err_formatted_stream_t const &) {}
    void operator= (err_formatted_stream_t const &)         {}

public:
    ~err_formatted_stream_t ();

    ErrStyle const *get_style() const;
#endif
};

typedef struct err_formatted_stream_t ErrFormattedStream;
#ifndef __cplusplus
typedef struct err_formatted_stream_t err_formatted_stream_t;
#endif

/* ********************************************************************** */

struct err_formatted_callback_t {
    union {
        err_callback0_t            f0;        /*0*/
        err_callback0_voidp_t      f0_voidp;  /*1*/
        err_callback0_int_t        f0_int;    /*2*/
        err_callback2_t            f2;        /*3*/
        err_callback2_voidp_t      f2_voidp;  /*4*/
        err_callback2_int_t        f2_int;    /*5*/
        err_callback0_info_t       f0i;       /*6*/
        err_callback0_info_voidp_t f0i_voidp; /*7*/
        err_callback0_info_int_t   f0i_int;   /*8*/
        err_callback2_info_t       f2i;       /*9*/
        err_callback2_info_voidp_t f2i_voidp; /*10*/
        err_callback2_info_int_t   f2i_int;   /*11*/
        err_function_ptr_t         f;         /*generic*/
    } callback;
    int which;
    err_style_t const *style;
    union {
        void *d_voidp;
        int   d_int;
    } user;

#ifdef __cplusplus
    err_formatted_callback_t (err_style_t const *);

    err_formatted_callback_t (err_callback0_t, err_style_t const *);
    err_formatted_callback_t (err_callback0_voidp_t, void *, err_style_t const *);
    err_formatted_callback_t (err_callback0_int_t, int, err_style_t const *);
    err_formatted_callback_t (err_callback2_t, err_style_t const *);
    err_formatted_callback_t (err_callback2_voidp_t, void *, err_style_t const *);
    err_formatted_callback_t (err_callback2_int_t, int, err_style_t const *);
    err_formatted_callback_t (err_callback0_info_t, err_style_t const *);
    err_formatted_callback_t (err_callback0_info_voidp_t, void *, err_style_t const *);
    err_formatted_callback_t (err_callback0_info_int_t, int, err_style_t const *);
    err_formatted_callback_t (err_callback2_info_t, err_style_t const *);
    err_formatted_callback_t (err_callback2_info_voidp_t, void *, err_style_t const *);
    err_formatted_callback_t (err_callback2_info_int_t, int, err_style_t const *);

    void invoke (ERR_BOOL *, int *, int, int, int,
                 err_msg_info_t const &, err_location_t const *, char const *);
#endif
};

typedef struct err_formatted_callback_t ErrFormattedCallback;
#ifndef __cplusplus
typedef struct err_formatted_callback_t err_formatted_callback_t;
#endif

/* ********************************************************************** */

struct err_next_message_t {
    int number;
    err_msg_info_t info;
    err_location_t loc;
    char *text; /* may be NULL */
    struct err_next_message_t *next;

#ifdef __cplusplus
private:
    void release ();
    void import (int, err_msg_info_t const &, err_location_t const *, char const *, err_next_message_t *);
public:
    err_next_message_t ():
        number (0),
        text (NULL),
        next (NULL)
    {}

    err_next_message_t (int, err_msg_info_t const &, err_location_t const *, char const *);

    err_next_message_t  (err_next_message_t const &);
    void operator=      (err_next_message_t const &);
    ~err_next_message_t ();
#endif
};

typedef struct err_next_message_t ErrNextMessage;
#ifndef __cplusplus
typedef struct err_next_message_t err_next_message_t;
#endif

/* ********************************************************************** */

struct err_message_t {
    int   tag;
    int   number;
    err_msg_info_t info;
    err_location_t loc;
    char *text; /* may be NULL */
    struct err_next_message_t *more;
    struct err_next_message_t **bottom;

#ifdef __cplusplus
private:
    void release ();
    void import (int, int, err_msg_info_t const &,
                 err_location_t const *, char const *, err_next_message_t *);
public:
    err_message_t ():
        tag  (0),
        number  (0),
        text (NULL),
        more (NULL),
        bottom (&more)
    {}

    err_message_t (int tag, int number, err_msg_info_t const &, err_location_t const *, char const *);

    void append (err_next_message_t *);

    err_message_t   (err_message_t const &);
    void operator = (err_message_t const &);
    ~err_message_t ();

private:
    err_next_message_t **get_bottom();
#endif
};

typedef struct err_message_t ErrMessage;
#ifndef __cplusplus
typedef struct err_message_t err_message_t;
#endif

/* ********************************************************************** */

#ifdef __cplusplus
extern "C" {
#endif

extern int err_err_subsystem; /* the error subsystem id */

/* err-renumber */
extern err_number_t const *err_number(int);
   /* In C++, write ErrNumber(int) instead.
    * Info: this function returns a pointer to a static variable!
    */

extern err_next_message_t *err_next_message_copy (err_next_message_t const *);

extern err_message_t *err_message_copy (err_message_t const *, int *);
extern void err_message_free (err_message_t *);
    /* These copy/free the struct, the file name and the text. */

#ifdef __cplusplus
}
#endif

#endif /* HT_DECLS_7214_H */


