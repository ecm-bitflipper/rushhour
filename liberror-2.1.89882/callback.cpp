// -*- Mode: C++ -*-

#include <signal.h>

#include "liberror.h"
#include "internal.h"
#include "failure.h"

static ErrMapIntMapIntVCallback callbacks;
static ErrMapIntCallback  subsystem_callbacks;

/* ********************************************************************** */

void err_crash_aux()
{
    signal(SIGSEGV, SIG_DFL);           /* break recursion loop */
    ((void)(*((int volatile *)NULL)));  /* crash, please. */
    abort();                            /* in case we're not crashed yet... */
}

void err_exit_1 (
    int /*tag*/, int orig_tag, int /*number*/, err_location_t const *, char const * /*text*/)
{
    // For C_TAG_FATAL messages that are not supposed to terminate,
    // use C_TAG_PRE_FATAL.
    if ((orig_tag & C_TAG_VARIANT) == 0) {
        static int incarn= 0;
        if (incarn++ == 0)
            err_printf_incarnation= 0;  // enable debug message from the atexit-hook (only once)
        exit (EXIT_FAILURE);
    }
}

void err_abort (
    int /*tag*/, int orig_tag, int /*number*/, err_location_t const *, char const * /*text*/)
{
    // For C_TAG_ASSERTION messages that are not supposed to terminate,
    // use C_TAG_PRE_ASSERTION.
    if ((orig_tag & C_TAG_VARIANT) == 0) {
        static int incarn= 0;
        if (incarn++ == 0)
            err_printf_incarnation= 0;
        err_crash ();
        // Dear Debugging Person!
        //
        // To find the source location where that triggered this off, scan
        // back in the backtrace of the debugger for a function invocation
        // to an *eprintf function.  It is likely not to be the last one to
        // voleprintf(), but the directly preceding one.  Have a look at
        // the caller to find out what lead to the invocation.
        //
        // Sorry that there are so many intermediate stack frames that lead
        // to this code.
        //
        // Best regards and have a good day despite this abort(),
        //     **Henrik
    }
}

void err_callback_init()
{
#if ERR_REINIT
    subsystem_callbacks.clear ();
    callbacks.clear ();
#endif
    err_add_callback (C_TAG_FATAL,     -1, err_exit_1, NULL);
    err_add_callback (C_TAG_ASSERTION, -1, err_abort,  NULL);

}

/* ********************************************************************** */
/* Callbacks */

err_formatted_callback_t::err_formatted_callback_t (
    err_style_t const *b):
    which (0),
    style (b)
{
    callback.f= NULL;
    user.d_int= 0;
}

err_formatted_callback_t::err_formatted_callback_t (
    err_callback0_t a, err_style_t const *b):
    which (0),
    style (b)
{
    callback.f0= a;
    user.d_int= 0;
}

err_formatted_callback_t::err_formatted_callback_t (
    err_callback0_voidp_t a, void *b, err_style_t const *c):
    which (1),
    style (c)
{
    callback.f0_voidp= a;
    user.d_voidp= b;
}

err_formatted_callback_t::err_formatted_callback_t (
    err_callback0_int_t a, int b, err_style_t const *c):
    which (2),
    style (c)
{
    callback.f0_int= a;
    user.d_int= b;
}

err_formatted_callback_t::err_formatted_callback_t (
    err_callback2_t a, err_style_t const *b):
    which (3),
    style (b)
{
    callback.f2= a;
    user.d_int= 0;
}

err_formatted_callback_t::err_formatted_callback_t (
    err_callback2_voidp_t a, void *b, err_style_t const *c):
    which (4),
    style (c)
{
    callback.f2_voidp= a;
    user.d_voidp= b;
}

err_formatted_callback_t::err_formatted_callback_t (
    err_callback2_int_t a, int b, err_style_t const *c):
    which (5),
    style (c)
{
    callback.f2_int= a;
    user.d_int= b;
}

err_formatted_callback_t::err_formatted_callback_t (
    err_callback0_info_t a, err_style_t const *b):
    which (6),
    style (b)
{
    callback.f0i= a;
    user.d_int= 0;
}

err_formatted_callback_t::err_formatted_callback_t (
    err_callback0_info_voidp_t a, void *b, err_style_t const *c):
    which (7),
    style (c)
{
    callback.f0i_voidp= a;
    user.d_voidp= b;
}

err_formatted_callback_t::err_formatted_callback_t (
    err_callback0_info_int_t a, int b, err_style_t const *c):
    which (8),
    style (c)
{
    callback.f0i_int= a;
    user.d_int= b;
}

err_formatted_callback_t::err_formatted_callback_t (
    err_callback2_info_t a, err_style_t const *b):
    which (9),
    style (b)
{
    callback.f2i= a;
    user.d_int= 0;
}

err_formatted_callback_t::err_formatted_callback_t (
    err_callback2_info_voidp_t a, void *b, err_style_t const *c):
    which (10),
    style (c)
{
    callback.f2i_voidp= a;
    user.d_voidp= b;
}

err_formatted_callback_t::err_formatted_callback_t (
    err_callback2_info_int_t a, int b, err_style_t const *c):
    which (11),
    style (c)
{
    callback.f2i_int= a;
    user.d_int= b;
}

void err_formatted_callback_t::invoke (
    ERR_BOOL *continuep, int *showp,
    int tag, int orig_tag, int number,
    err_msg_info_t const &info,
    err_location_t const *loc,
    char const *text)
{
    err_v_char_t *message1= NULL;
    err_v_char_t *message2= NULL;
    err_v_char_t *message;
    char const *new_text;
    if (style == NULL)
        new_text= text;
    else {
        message= err_format (
                     NULL, message1, message2, style, tag, orig_tag, number, info, loc, text);
        new_text= err_v_char_as_array (message);
    }

    if (callback.f != NULL) {
        static int incarn= 0;
        if (incarn == 0) {
            incarn++;
            int old_printf_incarn= err_printf_incarnation;
            err_printf_incarnation= 0;
            switch (which) {
                case 0:
                    callback.f0 (tag, orig_tag, number, loc, new_text);
                    break;
                case 1:
                    callback.f0_voidp (tag, orig_tag, number, loc, new_text, user.d_voidp);
                    break;
                case 2:
                    callback.f0_int (tag, orig_tag, number, loc, new_text, user.d_int);
                    break;
                case 3:
                    callback.f2 (continuep, showp, tag, orig_tag, number, loc, new_text);
                    break;
                case 4:
                    callback.f2_voidp (
                        continuep, showp, tag, orig_tag, number, loc, new_text, user.d_voidp);
                    break;
                case 5:
                    callback.f2_int (
                        continuep, showp, tag, orig_tag, number, loc, new_text, user.d_int);
                    break;
                case 6:
                    callback.f0i (tag, orig_tag, number, &info, loc, new_text);
                    break;
                case 7:
                    callback.f0i_voidp (tag, orig_tag, number, &info, loc, new_text, user.d_voidp);
                    break;
                case 8:
                    callback.f0i_int (tag, orig_tag, number, &info, loc, new_text, user.d_int);
                    break;
                case 9:
                    callback.f2i (continuep, showp, tag, orig_tag, number, &info, loc, new_text);
                    break;
                case 10:
                    callback.f2i_voidp (
                        continuep, showp, tag, orig_tag, number,&info,loc, new_text, user.d_voidp);
                    break;
                case 11:
                    callback.f2i_int (
                        continuep, showp, tag, orig_tag, number, &info, loc, new_text, user.d_int);
                    break;
                default:
                    nothing_if_reached ();
            }
            err_printf_incarnation= old_printf_incarn;
            incarn--;
        }
    }

    err_v_char_delete (message2);
    err_v_char_delete (message1);
}


/* ********************************************************************** */

static void err_add_callback_aux (
    int tag,
    int priority,
    err_formatted_callback_t *callback)
{
    ErrMapIntVCallback **c= callbacks.find_ptr_ensure (tag);
    if (!*c)
        *c= new ErrMapIntVCallback;
    ErrVCallback **v= (*c)->find_ptr_ensure (priority);
    if (!*v)
        *v= new ErrVCallback;
    (*v)->append (callback);
}

void err_add_callback0 (
    int tags, int priority, err_callback0_t callback, err_style_t const *style)
{
    return_if_fail (priority != 0);
    ERR_FOR_SOME_TAGS (tags,
        err_add_callback_aux (tag, priority,
           new ErrFormattedCallback (callback, style)));
           // NOTE: new() is invoked for every tag.  That's correct!
}

void err_add_callback0_voidp (
    int tags, int priority, err_callback0_voidp_t callback, void *u, err_style_t const *style)
{
    return_if_fail (priority != 0);
    ERR_FOR_SOME_TAGS (tags,
        err_add_callback_aux (tag, priority,
           new ErrFormattedCallback (callback, u, style)));
           // NOTE: new() is invoked for every tag.  That's correct!
}

void err_add_callback0_int (
    int tags, int priority, err_callback0_int_t callback, int u, err_style_t const *style)
{
    return_if_fail (priority != 0);
    ERR_FOR_SOME_TAGS (tags,
        err_add_callback_aux (tag, priority,
           new ErrFormattedCallback (callback, u, style)));
           // NOTE: new() is invoked for every tag.  That's correct!
}

void err_add_callback2 (
    int tags, int priority, err_callback2_t callback, err_style_t const *style)
{
    return_if_fail (priority != 0);
    ERR_FOR_SOME_TAGS (tags,
        err_add_callback_aux (tag, priority,
           new ErrFormattedCallback (callback, style)));
           // NOTE: new() is invoked for every tag.  That's correct!
}

void err_add_callback2_voidp (
    int tags, int priority, err_callback2_voidp_t callback, void *u, err_style_t const *style)
{
    return_if_fail (priority != 0);
    ERR_FOR_SOME_TAGS (tags,
        err_add_callback_aux (tag, priority,
           new ErrFormattedCallback (callback, u, style)));
           // NOTE: new() is invoked for every tag.  That's correct!
}

void err_add_callback2_int (
    int tags, int priority, err_callback2_int_t callback, int u, err_style_t const *style)
{
    return_if_fail (priority != 0);
    ERR_FOR_SOME_TAGS (tags,
        err_add_callback_aux (tag, priority,
           new ErrFormattedCallback (callback, u, style)));
           // NOTE: new() is invoked for every tag.  That's correct!
}

void err_add_callback (
    int tags, int priority, err_callback0_t callback, err_style_t const *style)
{
    err_add_callback0 (tags, priority, callback, style);
}

void err_add_callback (
    int tags, int priority, err_callback0_voidp_t callback, void *u, err_style_t const *style)
{
    err_add_callback0_voidp (tags, priority, callback, u, style);
}

void err_add_callback (
    int tags, int priority, err_callback0_int_t callback, int u, err_style_t const *style)
{
    err_add_callback0_int (tags, priority, callback, u, style);
}

void err_add_callback (
    int tags, int priority, err_callback2_t callback, err_style_t const *style)
{
    err_add_callback2 (tags, priority, callback, style);
}

void err_add_callback (
    int tags, int priority, err_callback2_voidp_t callback, void *u, err_style_t const *style)
{
    err_add_callback2_voidp (tags, priority, callback, u, style);
}

void err_add_callback (
    int tags, int priority, err_callback2_int_t callback, int u, err_style_t const *style)
{
    err_add_callback2_int (tags, priority, callback, u, style);
}

void err_add_callback0_info (
    int tags, int priority, err_callback0_info_t callback, err_style_t const *style)
{
    return_if_fail (priority != 0);
    ERR_FOR_SOME_TAGS (tags,
        err_add_callback_aux (tag, priority,
           new ErrFormattedCallback (callback, style)));
           // NOTE: new() is invoked for every tag.  That's correct!
}

void err_add_callback0_info_voidp (
    int tags, int priority, err_callback0_info_voidp_t callback, void *u, err_style_t const *style)
{
    return_if_fail (priority != 0);
    ERR_FOR_SOME_TAGS (tags,
        err_add_callback_aux (tag, priority,
           new ErrFormattedCallback (callback, u, style)));
           // NOTE: new() is invoked for every tag.  That's correct!
}

void err_add_callback0_info_int (
    int tags, int priority, err_callback0_info_int_t callback, int u, err_style_t const *style)
{
    return_if_fail (priority != 0);
    ERR_FOR_SOME_TAGS (tags,
        err_add_callback_aux (tag, priority,
           new ErrFormattedCallback (callback, u, style)));
           // NOTE: new() is invoked for every tag.  That's correct!
}

void err_add_callback2_info (
    int tags, int priority, err_callback2_info_t callback, err_style_t const *style)
{
    return_if_fail (priority != 0);
    ERR_FOR_SOME_TAGS (tags,
        err_add_callback_aux (tag, priority,
           new ErrFormattedCallback (callback, style)));
           // NOTE: new() is invoked for every tag.  That's correct!
}

void err_add_callback2_info_voidp (
    int tags, int priority, err_callback2_info_voidp_t callback, void *u, err_style_t const *style)
{
    return_if_fail (priority != 0);
    ERR_FOR_SOME_TAGS (tags,
        err_add_callback_aux (tag, priority,
           new ErrFormattedCallback (callback, u, style)));
           // NOTE: new() is invoked for every tag.  That's correct!
}

void err_add_callback2_info_int (
    int tags, int priority, err_callback2_info_int_t callback, int u, err_style_t const *style)
{
    return_if_fail (priority != 0);
    ERR_FOR_SOME_TAGS (tags,
        err_add_callback_aux (tag, priority,
           new ErrFormattedCallback (callback, u, style)));
           // NOTE: new() is invoked for every tag.  That's correct!
}

void err_add_callback (
    int tags, int priority, err_callback0_info_t callback, err_style_t const *style)
{
    err_add_callback0_info (tags, priority, callback, style);
}

void err_add_callback (
    int tags, int priority, err_callback0_info_voidp_t callback, void *u, err_style_t const *style)
{
    err_add_callback0_info_voidp (tags, priority, callback, u, style);
}

void err_add_callback (
    int tags, int priority, err_callback0_info_int_t callback, int u, err_style_t const *style)
{
    err_add_callback0_info_int (tags, priority, callback, u, style);
}

void err_add_callback (
    int tags, int priority, err_callback2_info_t callback, err_style_t const *style)
{
    err_add_callback2_info (tags, priority, callback, style);
}

void err_add_callback (
    int tags, int priority, err_callback2_info_voidp_t callback, void *u, err_style_t const *style)
{
    err_add_callback2_info_voidp (tags, priority, callback, u, style);
}

void err_add_callback (
    int tags, int priority, err_callback2_info_int_t callback, int u, err_style_t const *style)
{
    err_add_callback2_info_int (tags, priority, callback, u, style);
}

/* FIXME: Not thread safe!! */
static err_function_ptr_t comparison_callback= NULL;
static void *comparison_user_voidp= NULL;
static int   comparison_user_int=   0;

/* Old interface */

static ERR_ERWIN_BOOL callback_equal (ErrFormattedCallback *s)
{
    return comparison_callback == NULL || s->callback.f == comparison_callback;
}

static void err_remove_callback_aux (
    ErrMapIntVCallback *c, int priority, err_function_ptr_t callback)
{
    ErrVCallback *v= c->find (priority);
    if (!v)
        return;
    comparison_callback= callback;
    v->erase_if (callback_equal);
    if (v->empty()) {
        delete v;
        c->remove(priority);
    }
}

static void err_remove_callback_aux (int tag, int priority, err_function_ptr_t callback)
{
    ErrMapIntVCallback *c;
    if (priority == 0) {
        err_map_forall_values (callbacks, c)
            err_remove_callback_aux (c, priority, callback);
    }
    else {
        c= callbacks.find (tag);
        if (!c)
            return;
        err_remove_callback_aux (c, priority, callback);
        if (c->empty()) {
            delete c;
            callbacks.remove (tag);
        }
    }
}

void err_remove_callback (int tags, int priority, void *callback)
{
    ERR_FOR_SOME_TAGS (tags, err_remove_callback_aux (tag,priority,(err_function_ptr_t)callback));
}

/* New interface: same as above with function pointer */

static ERR_ERWIN_BOOL callback_equal_function (ErrFormattedCallback *s)
{
    return s->callback.f == comparison_callback;
}

static void err_remove_callback_function_aux (
    ErrMapIntVCallback *c, int priority, err_function_ptr_t callback)
{
    ErrVCallback *v= c->find (priority);
    if (!v)
        return;
    comparison_callback= callback;
    v->erase_if (callback_equal_function);
}

static void err_remove_callback_function_aux (int tag, int priority, err_function_ptr_t callback)
{
    ErrMapIntVCallback *c;
    if (priority == 0) {
        err_map_forall_values (callbacks, c)
            err_remove_callback_function_aux (c, priority, callback);
    }
    else {
        c= callbacks.find (tag);
        if (!c)
            return;
        err_remove_callback_function_aux (c, priority, callback);
    }
}

void err_remove_callback_function (int tags, int priority, err_function_ptr_t callback)
{
    ERR_FOR_SOME_TAGS (tags, err_remove_callback_function_aux (tag, priority, callback));
}

/* New interface: void functions */

static ERR_ERWIN_BOOL callback_equal_void (ErrFormattedCallback *s)
{
    return s->callback.f == comparison_callback &&
           (s->which == 0 || s->which == 3 || s->which == 6 || s->which == 9);
}

static void err_remove_callback_void_aux (
    ErrMapIntVCallback *c, int priority, err_function_ptr_t callback)
{
    ErrVCallback *v= c->find (priority);
    if (!v)
        return;
    comparison_callback= callback;
    v->erase_if (callback_equal_void);
}

static void err_remove_callback_void_aux (int tag, int priority, err_function_ptr_t callback)
{
    ErrMapIntVCallback *c;
    if (priority == 0) {
        err_map_forall_values (callbacks, c)
            err_remove_callback_void_aux (c, priority, callback);
    }
    else {
        c= callbacks.find (tag);
        if (!c)
            return;
        err_remove_callback_void_aux (c, priority, callback);
    }
}

void err_remove_callback_void (int tags, int priority, err_function_ptr_t callback)
{
    ERR_FOR_SOME_TAGS (tags, err_remove_callback_void_aux (tag, priority, callback));
}

/* New interface: void* functions */

static ERR_ERWIN_BOOL callback_equal_voidp (ErrFormattedCallback *s)
{
    return s->callback.f   == comparison_callback &&
           s->user.d_voidp == comparison_user_voidp &&
           (s->which == 1 || s->which == 4 || s->which == 7 || s->which == 10);
}

static void err_remove_callback_voidp_aux (
    ErrMapIntVCallback *c, int priority, err_function_ptr_t callback, void *user_data)
{
    ErrVCallback *v= c->find (priority);
    if (!v)
        return;
    comparison_callback=   callback;
    comparison_user_voidp= user_data;
    v->erase_if (callback_equal_voidp);
}

static void err_remove_callback_voidp_aux (
    int tag, int priority, err_function_ptr_t callback, void *user_data)
{
    ErrMapIntVCallback *c;
    if (priority == 0) {
        err_map_forall_values (callbacks, c)
            err_remove_callback_voidp_aux (c, priority, callback, user_data);
    }
    else {
        c= callbacks.find (tag);
        if (!c)
            return;
        err_remove_callback_voidp_aux (c, priority, callback, user_data);
    }
}

void err_remove_callback_voidp (
    int tags, int priority, err_function_ptr_t callback, void *user_data)
{
    ERR_FOR_SOME_TAGS (tags, err_remove_callback_voidp_aux (tag, priority, callback, user_data));
}

/* New interface: int functions */

static ERR_ERWIN_BOOL callback_equal_int (ErrFormattedCallback *s)
{
    return s->callback.f == comparison_callback &&
           s->user.d_int == comparison_user_int &&
           (s->which == 2 || s->which == 5 || s->which == 8 || s->which == 11);
}

static void err_remove_callback_int_aux (
    ErrMapIntVCallback *c, int priority, err_function_ptr_t callback, int user_data)
{
    ErrVCallback *v= c->find (priority);
    if (!v)
        return;
    comparison_callback= callback;
    comparison_user_int= user_data;
    v->erase_if (callback_equal_int);
}

static void err_remove_callback_int_aux (
    int tag, int priority, err_function_ptr_t callback, int user_data)
{
    ErrMapIntVCallback *c;
    if (priority == 0) {
        err_map_forall_values (callbacks, c)
            err_remove_callback_int_aux (c, priority, callback, user_data);
    }
    else {
        c= callbacks.find (tag);
        if (!c)
            return;
        err_remove_callback_int_aux (c, priority, callback, user_data);
    }
}

void err_remove_callback_int (
    int tags, int priority, err_function_ptr_t callback, int user_data)
{
    ERR_FOR_SOME_TAGS (tags, err_remove_callback_int_aux (tag, priority, callback, user_data));
}

/* C++ wrappers (a little more type safe) */

extern void err_remove_callback (
    int tags, int priority, err_callback2_voidp_t function)
{
    err_remove_callback_function (tags, priority, (err_function_ptr_t)function);
}

extern void err_remove_callback (
    int tags, int priority, err_callback2_voidp_t function, void * data)
{
    err_remove_callback_voidp (tags, priority, (err_function_ptr_t)function, data);
}

extern void err_remove_callback (
    int tags, int priority, err_callback0_voidp_t function)
{
    err_remove_callback_function (tags, priority, (err_function_ptr_t)function);
}

extern void err_remove_callback (
    int tags, int priority, err_callback0_voidp_t function, void * data)
{
    err_remove_callback_voidp (tags, priority, (err_function_ptr_t)function, data);
}

extern void err_remove_callback (
    int tags, int priority, err_callback2_info_voidp_t function)
{
    err_remove_callback_function (tags, priority, (err_function_ptr_t)function);
}

extern void err_remove_callback (
    int tags, int priority, err_callback2_info_voidp_t function, void * data)
{
    err_remove_callback_voidp (tags, priority, (err_function_ptr_t)function, data);
}

extern void err_remove_callback (
    int tags, int priority, err_callback0_info_voidp_t function)
{
    err_remove_callback_function (tags, priority, (err_function_ptr_t)function);
}

extern void err_remove_callback (
    int tags, int priority, err_callback0_info_voidp_t function, void * data)
{
    err_remove_callback_voidp (tags, priority, (err_function_ptr_t)function, data);
}

extern void err_remove_callback (
    int tags, int priority, err_callback2_int_t function)
{
    err_remove_callback_function (tags, priority, (err_function_ptr_t)function);
}

extern void err_remove_callback (
    int tags, int priority, err_callback2_int_t function, int data)
{
    err_remove_callback_int (tags, priority, (err_function_ptr_t)function, data);
}

extern void err_remove_callback (
    int tags, int priority, err_callback0_int_t function)
{
    err_remove_callback_function (tags, priority, (err_function_ptr_t)function);
}

extern void err_remove_callback (
    int tags, int priority, err_callback0_int_t function, int data)
{
    err_remove_callback_int (tags, priority, (err_function_ptr_t)function, data);
}

extern void err_remove_callback (
    int tags, int priority, err_callback2_info_int_t function)
{
    err_remove_callback_function (tags, priority, (err_function_ptr_t)function);
}

extern void err_remove_callback (
    int tags, int priority, err_callback2_info_int_t function, int data)
{
    err_remove_callback_int (tags, priority, (err_function_ptr_t)function, data);
}

extern void err_remove_callback (
    int tags, int priority, err_callback0_info_int_t function)
{
    err_remove_callback_function (tags, priority, (err_function_ptr_t)function);
}

extern void err_remove_callback (
    int tags, int priority, err_callback0_info_int_t function, int data)
{
    err_remove_callback_int (tags, priority, (err_function_ptr_t)function, data);
}

extern void err_remove_callback (
    int tags, int priority, err_callback2_t function)
{
    err_remove_callback_void (tags, priority, (err_function_ptr_t)function);
}

extern void err_remove_callback (
    int tags, int priority, err_callback0_t function)
{
    err_remove_callback_void (tags, priority, (err_function_ptr_t)function);
}

extern void err_remove_callback (
    int tags, int priority, err_callback2_info_t function)
{
    err_remove_callback_void (tags, priority, (err_function_ptr_t)function);
}

extern void err_remove_callback (
    int tags, int priority, err_callback0_info_t function)
{
    err_remove_callback_void (tags, priority, (err_function_ptr_t)function);
}



/* Clear */

static void err_clear_callback_aux (ErrMapIntVCallback *c, int priority)
{
#if 1
    /* release memory */
    c->erase (priority);
#else
    /* never release memory :-) */
    ErrVCallback *v= c->find_ptr_ensure (priority);
    if (!v)
        return;
    v->clear();
#endif
}

static void err_clear_callback_aux (int tag, int priority)
{
    ErrMapIntVCallback *c;
    if (priority == 0) {
        err_map_forall_values (callbacks, c)
            err_clear_callback_aux (c, priority);
    }
    else {
        c= callbacks.find (tag);
        if (!c)
            return;
        err_clear_callback_aux (c, priority);
    }
}

void err_clear_callback (int tags, int priority)
{
    ERR_FOR_SOME_TAGS (tags, err_clear_callback_aux (tag, priority));
}

void err_invoke_callbacks_before (
    int *showp,
    int tag, int orig_tag, int orig_number,
    err_msg_info_t const &info,
    err_location_t const *loc,
    char const *text)
{
    ErrMapIntVCallback *c;
    c= callbacks.find (ERR_PURE_TAG (orig_tag));
    if (c) {
        int priority;
        ErrVCallback *v;
        ERR_BOOL cont= true;
        err_map_forall_sorted_by_key (c, priority, v) {
            if (v && priority > 0) {
                ErrFormattedCallback *cb;
                err_vector_forall_values (v, cb) {
                    cb->invoke (&cont, showp, tag, orig_tag, orig_number, info, loc, text);
                    if (!cont)
                        return;
                }
            }
        }
    }
}

void err_invoke_callbacks_after (
    int *showp,
    int tag, int orig_tag, int orig_number,
    err_msg_info_t const &info,
    err_location_t const *loc,
    char const *text)
{
    ErrMapIntVCallback *c;
    c= callbacks.find (ERR_PURE_TAG (orig_tag));
    if (c) {
        int priority;
        ErrVCallback *v;
        ERR_BOOL cont= true;
        err_map_forall_sorted_by_key (c, priority, v) {
            if (v && priority < 0) {
                ErrFormattedCallback *cb;
                err_vector_forall_values_reverse (v, cb) {
                    cb->invoke (&cont, showp, tag, orig_tag, orig_number, info, loc, text);
                    if (!cont)
                        return;
                }
            }
        }
    }
}

/* ********************************************************************** */

void err_set_subsystem_callback0 (
    int subsystem, err_callback0_t callback, err_style_t const *style)
{
    subsystem_callbacks.set (subsystem, new ErrFormattedCallback (callback, style));
}

void err_set_subsystem_callback2 (
    int subsystem, err_callback2_t callback, err_style_t const *style)
{
    subsystem_callbacks.set (subsystem, new ErrFormattedCallback (callback, style));
}

void err_set_subsystem_callback0_voidp (
    int subsystem, err_callback0_voidp_t callback, void *u, err_style_t const *style)
{
    subsystem_callbacks.set (subsystem, new ErrFormattedCallback (callback, u, style));
}

void err_set_subsystem_callback2_voidp (
    int subsystem, err_callback2_voidp_t callback, void *u, err_style_t const *style)
{
    subsystem_callbacks.set (subsystem, new ErrFormattedCallback (callback, u, style));
}

void err_set_subsystem_callback0_int (
    int subsystem, err_callback0_int_t callback, int u, err_style_t const *style)
{
    subsystem_callbacks.set (subsystem, new ErrFormattedCallback (callback, u, style));
}

void err_set_subsystem_callback2_int (
    int subsystem, err_callback2_int_t callback, int u, err_style_t const *style)
{
    subsystem_callbacks.set (subsystem, new ErrFormattedCallback (callback, u, style));
}

void err_set_subsystem_callback (
    int subsystem, err_callback0_t callback, err_style_t const *style)
{
    err_set_subsystem_callback0 (subsystem, callback, style);
}

void err_set_subsystem_callback (
    int subsystem, err_callback2_t callback, err_style_t const *style)
{
    err_set_subsystem_callback2 (subsystem, callback, style);
}

void err_set_subsystem_callback (
    int subsystem, err_callback0_voidp_t callback, void *u, err_style_t const *style)
{
    err_set_subsystem_callback0_voidp (subsystem, callback, u, style);
}

void err_set_subsystem_callback (
    int subsystem, err_callback2_voidp_t callback, void *u, err_style_t const *style)
{
    err_set_subsystem_callback2_voidp (subsystem, callback, u, style);
}

void err_set_subsystem_callback (
    int subsystem, err_callback0_int_t callback, int u, err_style_t const *style)
{
    err_set_subsystem_callback0_int (subsystem, callback, u, style);
}

void err_set_subsystem_callback (
    int subsystem, err_callback2_int_t callback, int u, err_style_t const *style)
{
    err_set_subsystem_callback2_int (subsystem, callback, u, style);
}

void err_set_subsystem_callback0_info (
    int subsystem, err_callback0_info_t callback, err_style_t const *style)
{
    subsystem_callbacks.set (subsystem, new ErrFormattedCallback (callback, style));
}

void err_set_subsystem_callback2_info (
    int subsystem, err_callback2_info_t callback, err_style_t const *style)
{
    subsystem_callbacks.set (subsystem, new ErrFormattedCallback (callback, style));
}

void err_set_subsystem_callback0_info_voidp (
    int subsystem, err_callback0_info_voidp_t callback, void *u, err_style_t const *style)
{
    subsystem_callbacks.set (subsystem, new ErrFormattedCallback (callback, u, style));
}

void err_set_subsystem_callback2_info_voidp (
    int subsystem, err_callback2_info_voidp_t callback, void *u, err_style_t const *style)
{
    subsystem_callbacks.set (subsystem, new ErrFormattedCallback (callback, u, style));
}

void err_set_subsystem_callback0_info_int (
    int subsystem, err_callback0_info_int_t callback, int u, err_style_t const *style)
{
    subsystem_callbacks.set (subsystem, new ErrFormattedCallback (callback, u, style));
}

void err_set_subsystem_callback2_info_int (
    int subsystem, err_callback2_info_int_t callback, int u, err_style_t const *style)
{
    subsystem_callbacks.set (subsystem, new ErrFormattedCallback (callback, u, style));
}

void err_set_subsystem_callback (
    int subsystem, err_callback0_info_t callback, err_style_t const *style)
{
    err_set_subsystem_callback0_info (subsystem, callback, style);
}

void err_set_subsystem_callback (
    int subsystem, err_callback2_info_t callback, err_style_t const *style)
{
    err_set_subsystem_callback2_info (subsystem, callback, style);
}

void err_set_subsystem_callback (
    int subsystem, err_callback0_info_voidp_t callback, void *u, err_style_t const *style)
{
    err_set_subsystem_callback0_info_voidp (subsystem, callback, u, style);
}

void err_set_subsystem_callback (
    int subsystem, err_callback2_info_voidp_t callback, void *u, err_style_t const *style)
{
    err_set_subsystem_callback2_info_voidp (subsystem, callback, u, style);
}

void err_set_subsystem_callback (
    int subsystem, err_callback0_info_int_t callback, int u, err_style_t const *style)
{
    err_set_subsystem_callback0_info_int (subsystem, callback, u, style);
}

void err_set_subsystem_callback (
    int subsystem, err_callback2_info_int_t callback, int u, err_style_t const *style)
{
    err_set_subsystem_callback2_info_int (subsystem, callback, u, style);
}

void err_unset_subsystem_callback (int subsystem)
{
    subsystem_callbacks.erase (subsystem);
}

ErrFormattedCallback *err_subsystem_callback_find (int orig_tag)
{
    return subsystem_callbacks.find (orig_tag & C_TAG_SUBSYSTEM_MASK);
}

