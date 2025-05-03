/* -*- Mode: C -*- */

/*! section -2: Overview / Features
 *
 * +---------------+-------------------+
 * |! Author       | Henrik Theiling   |
 * |! Description  | Message printing  |
 * +---------------+-------------------+
 *
 * Features
 * --------
 *     - message ids
 *         - assigned by a script and stored in a data base in cvs
 *     - output streams
 *         - different ones for each type of message
 *         - multiple streams
 *     - counting
 *         - different counters per tag, group, subsystem, id
 *         - different counters for different events:
 *               received, issued, distributed, shown,
 *               buffered, printed.
 *     - filtering
 *         - by type of message (group, subsystem, tag)
 *         - by id of message
 *         - per stream (also by type & id)
 *         - per stream: print messages only once
 *         - different levels of filtering:
 *              - so that counting is suppressed (-> issue filter)
 *              - so that messages are invisible (-> show  filter)
 *              - per stream printing decision   (-> print filter)
 *     - buffering
 *         - for locally suppressing messages
 *         - for postponing and re-filtering messages
 *     - callbacks
 *         - for user extensions
 *         - for systems that lack stderr
 *         - for graphical environments
 *     - styles
 *         - customisable by the user
 *         - for colour tags, HTML messages, etc.
 *     - 'address' resolving:
 *         - For 'address' to file, line, pos-mapping, user plug-in
 *           may be used
 *         - here, 'address' may be any concept of source code
 *           location: you can provide your own format function.
 *     - C and C++ support
 *     - substitute of clib's printf family to have advantages
 *       of Erwin format: consistency between platforms, quotation,
 *       NULL-handling: %s prints NULL, 0x%Lx etc.
 *       FILE* may be NULL to suppress output
 *       The family is called *xprintf: fxprintf, vxprintf, snxprintf, etc.
 */

/* err-default scope=project */

#ifndef HT_LIBERROR_2932_H
#define HT_LIBERROR_2932_H

#ifndef HAVE_LIBERROR
#define HAVE_LIBERROR 1
#endif

/*
 * Includes */
#include <stdarg.h>
#include <stdio.h>

#ifdef IN_LIBERROR_COMPILE
#include "error/erwin/defs.h"
#include "error/version.h"
#include "error/symbol.h"
#else
#include <error/erwin/defs.h>
#include <error/version.h>
#include <error/symbol.h>
#endif

#ifndef ERR_HAVE_STDERR
#  ifdef ERWIN_DOS
#    if defined(SUBSYSTEM_CONSOLE)
#      define ERR_HAVE_STDERR 1
       /* we have stderr on the console under Windows. */
#    endif
#  else
#    define ERR_HAVE_STDERR 1
     /* assume stderr always exists on other platforms */
#  endif
#endif

#ifdef IN_LIBERROR_COMPILE

#  include "error/err-config.h"
#  include "error/erwin/erwin.h"
#  include "error/tags.h"
#  include "error/printf.h"
   /* Styles: */
#  include "error/style.h"
     /* Plain: */
#    include "error/style-colon.h"
#    include "error/style-quotes.h"
#      include "error/style-plain.h"
     /* Qt: */
#    include "error/style-qt.h"
#    include "error/style-qt3.h"
   /* Assertions (implementation only): */
#  include "error/assert.h"

#else

#  include <error/err-config.h>
#  include <error/erwin/erwin.h>
#  include <error/tags.h>
#  include <error/printf.h>
   /* Styles: */
#  include <error/style.h>
     /* Plain: */
#    include <error/style-colon.h>
#    include <error/style-quotes.h>
#      include <error/style-plain.h>
     /* Qt: */
#    include <error/style-qt.h>
#    include <error/style-qt3.h>

#endif

/* Color tags are defined in        <error/tags.h>    */
/* Print functions are defined in   <error/printf.h> */
/* Error style handling is defined  <error/style.h>   */

#ifdef ERWIN_DOS

#  define err_crash() abort()

#else

#  define err_crash() err_crash_aux()
   /* The normal glibc abort() does not seem to produce a stack backtrace
    * in the core anymore!?
    * An ordinary SIGSEGV, however, does.  So we will abort that way. */

#endif

/* ********************************************************************** */
/* Some typical error messages: */

#define ERR_OPEN_READ       "Unable to open file '%s' for reading.\nReason: %m."
#define ERR_OPEN_WRITE      "Unable to open file '%s' for writing.\nReason: %m."
#define ERR_OPEN_READWRITE  "Unable to open file '%s' for reading and writing.\nReason: %m."
#define ERR_OPEN_APPEND     "Unable to open file '%s' for appending.\nReason: %m."
   /* Example of usage:
    *
    *    : eprintf (C_TAG_ERR, 517, ERR_OPEN_READ, filename);
    *
    * To trigger an exit(1) automatically, use C_TAG_FATAL:
    *
    *    : FILE *f= fopen (filename, "rt");
    *    : if (!f)
    *    :     eprintf (C_TAG_FATAL, 0, ERR_OPEN_READ, filename);
    *
    * Please don't use FATAL for file open errors inside libraries!
    *
    * NOTE: The format strings only work with Erwin formatting functions (e.g. all
    *       error printing functions of this library), since they contain the GNU
    *       extension %m, which Erwin implements, but your LibC is not likely to do
    *       unless you have a GLibC.
    */

#ifndef NDEBUG
#define ERR_TRACE  eprintf (C_TAG_DEBUG, 0, __FILE__, __LINE__, "reached.\n")
#else
#define ERR_TRACE
#endif

/* ********************************************************************** */
/* Declarations */

#ifdef __cplusplus
extern "C" {
#endif

extern volatile int err_continue;

extern char const *err_callbacks_only; /* for compatibility */
#define ERR_CALLBACKS_ONLY "\1"
   /* use this format string if you want no message but only
    * invocation of the callbacks */

/* Set-up */
extern void err_init (int *, char ***);
   /*
    * In contrast to many other libraries that use Erwin, the invocation
    * of this function is not needed.  However, the error output is
    * improved if you invoke this (e.g., the program name is output).
    * If you do not invoke this, then the library also sets up a default
    * output stream to stderr.  This is convenient for testing (simply
    * link -lerror and there you go).
    *
    * Furthermore, if you do not invoke err_init(), you are only allowed
    * *printf functions, but no other functions from this library.
    *
    * In total, it is highly advisable to invoke err_init() at the beginning
    * of your program.
    *
    * Typical invocation:
    *
    *   : err_init (&argc, &argv);
    *
    * If you want a progname different from the base name in argv[0] (under DOS
    * without .exe), then invoke err_set_progname with the desired name.
    *
    * IMPORTANT NOTE:
    *    If you invoke err_init, then by default, no output stream is
    *    set, so no error messages are ever seen!  So typically, you
    *    will set a default error stream directly after the above
    *    invocation.  E.g.:
    *
    *     : err_add_stream (C_TAG_ALL, stderr, NULL);
    *
    *    Please only give a non-NULL error style if you know what
    *    you are doing.  E.g. if you do set the style here,
    *    the user cannot set it from the command line anymore.
    *    Usually, plain style is the default, but can be set
    *    differently.  err_init() parses part of the command
    *    line to check user settings.
    */

extern char const *err_progname (void);
   /* Return current setting of progname.  See err_set_progname(). */

extern void err_set_progname (char const *);
   /* Getting and setting the program name that is displayed
    *
    * You are uncouraged to invoke err_set_progname before err_init,
    * but then you must ensure that the string you pass is not
    * deallocated.
    * (If you invoke the function after err_init, you may do so
    * even with temporary strings.)
    *
    * Invoking err_set_progname before init makes the library
    * parse another environment variable ("ERR_OPTIONS_"
    * concatenated with the program name in upper case) specific to
    * the application.
    */

extern int err_pid (void);
   /* Return current setting of pid.  See err_set_pid().
    *
    * If no PID is known, returns -1.
    */

extern void err_set_pid (int /*pid*/);
   /* Getting and setting the PID that is displayed.
    *
    * Under Unix, the PID that is displayed defaults to the value
    * of getpid().  Under Windos, there is currently no PID
    * default.  This can be overridden with this function.
    *
    * Note that there is a command line option 'show-pid' that
    * decides whether the PID is displayed.
    */

extern char const *err_config_prefix(void);
   /* Return current config prefix.  See err_set_config_prefix(). */

extern void err_set_config_prefix(char const *);
   /* Getting and settings the prefix by which the error library is configured,
    * i.e., the prefix for the environment variables it reads from and the
    * command line options.  By default, this is "err".  It is converted
    * to upper case for the environment variables, thus "ERR" is the default
    * there.  Further, if this is non-empty, a "-" is inserted
    * in the command line options and a "_" in the environment variables.
    * Therefore, the default environment variable is "ERR_OPTIONS" and the
    * default prefix for command line options is "--err-".
    *
    * Setting this is NULL effectively resets the prefix to "msg".
    *
    * Note: the default used to be "err" in older versions.
    *
    * Using "msg" is recommended, since this refers to more than errors.
    * "err" is merely a historic misnomer.
    *
    * The prefix must be set before an invocation to err_init(), otherwise,
    * it has no effect.
    */

typedef void (*ErrAddressResolver)(int, int, int, err_position_t *);

extern void err_unset_resolve_address (void);
   /* Unsets the current resolver set with err_set_resolve_address() */

extern void err_set_resolve_address   (ErrAddressResolver);
   /* Sets a user-provided callback for resolving addresses, i.e.,
    * to look up to which source code location an address corresponds.
    *
    * If you have several address spaces, you should use the number, subsystem or
    * group mechanism to pass through information about memory space to this
    * function.
    *
    * An alternative to this look-up mechanism is to provide a resolve function
    * for an overloaded extended address (err_ext_address_t).  This way, the
    * resolver is invoked depending on the type of extended address.
    */

/* err-renumber */
extern err_location_t const *err_resolve_address (
    int tag, int /*orig_tag*/, int number, err_location_t const *);
   /* A function that resolves, if possible, an address to a
    * source code location.
    *
    * In case anything changes, this function returns a pointer to a statically
    * allocated err_location_t.  Otherwise, the original pointer is returned.
    *
    * The user provided callback is only invoked if the file
    * is unset and the address is valid.
    */

extern void err_set_next_location (err_location_t const *);
   /* If this is invoked, the error location will be used in the
    * next eprintf command regardless of a possibly given location.
    *
    * Note that only the last location set this way will have an
    * effect.
    *
    * Further note that an eprintf with the C_TAG_PREFIX tag and
    * a given location also invokes this function if the next
    * location is not set.  Therefore, calling this function is
    * equivalent to C_TAG_PREFIX with a location and an empty
    * format string when the next location is unset.  However, use
    * this err_set_next_location() for clarity.
    *
    * The function err_erase_prefix() deletes this location.  If
    * you set a location whose file and address are invalid, this
    * is also equal to erasing the location.
    */

extern void err_erase_prefix (void);
extern void err_erase_suffix (void);
   /* Erases a buffered prefix (suffix) that has been printed with
    * C_TAG_PREFIX (C_TAG_SUFFIX). */

extern void err_add_stream    (
    int /*tags*/, FILE * /*stream*/, err_style_t const * ERWIN_IF_CXX (= NULL));
    /* If the stream already exists for the given file, the style will not
     * be changed.  This is to allow the user to change the style explicitly
     *
     * The streams stderr and stdout automatically get the names "stderr"
     * and "stdout".
     *
     * Use err_stream_set_style for changing a stream style (remember to use
     * this AFTER err_stream_set_name since that function also likes to change
     * the error style if it has settings for that name, so it would again
     * reset the style.).  */

extern ERR_BOOL err_stream_set_name (FILE * /*stream*/, char const * /*name*/);
   /* When you set this, command line options for styles are enabled for
    * the given stream.  (E.g. print filtering (NYI), style settings)
    *
    * NOTE: When a stream with this name exists and has a file pointer
    *       of NULL or equal to the given file, then the current settings
    *       will be copied from the named stream to the stream defined
    *       by the file pointer.  After that, the two streams will be
    *       identified.
    *
    *       If a stream with the given name exists that has a different file
    *       pointer, this routine returns false (= no success).
    *
    * Note: when you erase a stream with a name, then the settings will be
    *       erased, too, together with its name.
    */

extern void err_stream_set_style (FILE * /*stream*/, err_style_t const * /*style*/);
   /* Resets the current stream style. */

extern void err_remove_stream (int /*tags*/, FILE * /*stream*/);
   /* Add/remove an stream for error messages.
    *
    * You can have only one style per FILE*.  If you add a stream for
    * a FILE* that is already in use, the style is switched to the
    * new style before added the additional stream.  Please note
    * the in this case, there are still two streams for this file,
    * although only one style.  So if the filtering for both streams
    * is not mutually exclusive, some error messages are printed into
    * that stream twice per issue.
    *
    * To change a style, first err_remove_stream() and then add it again.
    * Note that filtering rules are stored per file, so you cannot
    * reset a stream filter by removing the stream and adding it again.
    *
    * If you want to reset a stream including its filtering rules, use
    * err_reset_stream().
    *
    * You can set a group of tags by using bit operators for simple
    * filtering: E.g.
    *      : C_TAG_WARN | C_TAG_ERROR
    *      : ~C_TAG_DEBUG
    *
    * For all tags, use C_TAG_ALL.
    *
    * The values 0 and -1 for tags are illegal.
    *
    * By default, there is one stream for the messages, stderr,
    * used for all messages.
    *
    * A stream may be NULL in which case err_style_default will
    * be used.
    *
    * The style must not be NULL!
    */

extern void err_reset_stream (FILE *);
   /* Resets a stream to its initial contents: it deletes all
    * filters, styles, its.
    *
    * This also performs err_remove_stream (C_TAG_ALL, file).
    */

extern void err_add_callback2_voidp (
    int /*tags*/, int /*priority*/, err_callback2_voidp_t, void *, err_style_t const *);
extern void err_add_callback2_int (
    int /*tags*/, int /*priority*/, err_callback2_int_t, int, err_style_t const *);
extern void err_add_callback2 (
    int /*tags*/, int /*priority*/, err_callback2_t, err_style_t const *);

extern void err_add_callback0_voidp (
    int /*tags*/, int /*priority*/, err_callback0_voidp_t, void *, err_style_t const *);
extern void err_add_callback0_int (
    int /*tags*/, int /*priority*/, err_callback0_int_t, int, err_style_t const *);
extern void err_add_callback0 (
    int /*tags*/, int /*priority*/, err_callback0_t, err_style_t const *);

extern void err_add_callback2_info_voidp (
    int /*tags*/, int /*priority*/, err_callback2_info_voidp_t, void *, err_style_t const *);
extern void err_add_callback2_info_int (
    int /*tags*/, int /*priority*/, err_callback2_info_int_t, int, err_style_t const *);
extern void err_add_callback2_info (
    int /*tags*/, int /*priority*/, err_callback2_info_t, err_style_t const *);

extern void err_add_callback0_info_voidp (
    int /*tags*/, int /*priority*/, err_callback0_info_voidp_t, void *, err_style_t const *);
extern void err_add_callback0_info_int (
    int /*tags*/, int /*priority*/, err_callback0_info_int_t, int, err_style_t const *);
extern void err_add_callback0_info (
    int /*tags*/, int /*priority*/, err_callback0_info_t, err_style_t const *);

extern void err_remove_callback (
    int /*tags*/, int /*priority*/, void * /*function*/);

extern void err_remove_callback_function (
    int /*tags*/, int /*priority*/, err_function_ptr_t /*function*/);
extern void err_remove_callback_void (
    int /*tags*/, int /*priority*/, err_function_ptr_t /*function*/);
extern void err_remove_callback_voidp (
    int /*tags*/, int /*priority*/, err_function_ptr_t /*function*/, void * /*user_data*/);
extern void err_remove_callback_int (
    int /*tags*/, int /*priority*/, err_function_ptr_t /*function*/, int /*user_data*/);

extern void err_clear_callback (
    int /*tags*/, int /*priority*/);
   /*
    * A function to call back for every message after filtering and formatting.
    *
    * Like for err_(add/remove)_stream, you can specify groups of tags.
    *
    * The callbacks are invoked in the following order:
    *    - Before the call to the print function, all priorities > 0
    *      are invoked in rising order of the priority (1, 2, 3....)
    *      and for the same priority, callbacks added later are invoked
    *      later.
    *    - After the call to the print function, all priorities < 0
    *      are invoked in RISING ORDER OF THE PRIORITY (... -3, -2, -1)
    *      and for the same priority, callbacks added later are invoked
    *      earlier.
    *
    * By default, there are the following call backs:
    *    : err_add_callback (C_TAG_FATAL,     -1, { exit(1); }, NULL)
    *    : err_add_callback (C_TAG_ASSERTION, -1, { abort(); }, NULL)
    * So the program will immediately be terminated after an error message
    * is issued with C_TAG_FATAL or C_TAG_ASSERTION.
    *
    * For err_add_callback, a priority of 0 is illegal.
    *
    * For err_add_callback a callback may be NULL in which case nothing
    * is invoked.  However, the error message is formatted with the
    * given style, so this may be used for a more complex call back
    * mechanism anyway (by providing your own style).
    *
    * For err_remove_callback and err_clear_callback, if priority is 0,
    * the commands perform on all priorities.
    *
    * err_remove_callback_void removes a callback by its function pointer
    * that does not receive any user data.
    *
    * err_remove_callback_voidp removes a callback by its function pointer
    * and the user data.
    *
    * err_remove_callback_int removes a callback by its function pointer
    * and the user data.
    *
    * err_remove_callback removes a callback by its function pointer.
    * Note that on machines were code pointers have a different size that
    * data pointers, this currently does not work.  We will have to implement
    * something else.  This function is deprecated, please use the other
    * alternatives that receive a ErrFunctionPtr.
    *
    * err_clear_callback() erases all callbacks for a given tag/priority.
    * (E.g. this can be used to remove the terminating exit(0) / abort()
    * invocations.  However, this is sincerely deprecated!)
    *
    * If the style is NULL, the pure text of the error message is passed
    * to the callback.
    *
    * [For the behaviour of the old interface, use priority = 1.]
    */

extern void err_exit_1 (
    int /*tag*/, int orig_tag, int /*number*/, err_location_t const *, char const * /*text*/);
    /* This is a function suitable for ther err_add_callback* function family that
     * exits the program with exit(1).  */

extern void err_abort (
    int /*tag*/, int orig_tag, int /*number*/, err_location_t const *, char const * /*text*/);
    /* This is a function suitable for ther err_add_callback* function family that
     * exits the program with abort(). */

/* ********************************************************************** */
/* Sub-system handling */

extern int err_declare_subsystem (char const * /*name*/);
   /* Note that this function does not need to be invoked.  You may
    * directly use err_subsystem() instead.
    *
    * Generates a new, unique identifier of a new sub-system with the
    * given name.  The returned value can be combined with the C_TAG_...
    * constants to generate errors in this sub-system.  E.g.:
    *
    *    : int lisp_subsystem= err_declare_subsystem ("Lisp");
    *    :
    *    : ...
    *    : eprintf (C_TAG_ERR | lisp_subsystem, 172, "Some error\n");
    *
    * This is equivalent to:
    *
    *    : eprintf (C_TAG_ERR | err_subsystem("Lisp"), 172, "Some error\n");
    *
    * Sub-systems are used for two purposes:
    *    a) identification of an error message (the name of the
    *       sub-system will be printed with the error message)
    *
    *    b) redirection of error messages.
    *
    * b) was mainly introduced to keep old libraries compatible by
    * allowing them to set a default callback that prints all their
    * error messages into a vector.  (liblisp and libtf14net work
    * like this).
    *
    * To handle the errors with the normal method, use
    * err_unset_subsystem_callback() to switch off redirection.
    *
    * You may specify NULL for name, if the subsystem has no name.
    * You can still use the returned number for the following
    * functions.
    *
    * A predefined subsystem is 0, the core subsystem.  You can also
    * use 0 for settings callbacks without need of declaration.
    */

extern ATTR_PURE int err_subsystem (char const * /*name*/);
   /* Return the identifier of a given subsystem */

extern void err_set_subsystem_callback2_voidp (
    int /*subsystem*/, err_callback2_voidp_t, err_style_t const *, void *);
extern void err_set_subsystem_callback2_int (
    int /*subsystem*/, err_callback2_int_t, err_style_t const *, int);
extern void err_set_subsystem_callback2 (
    int /*subsystem*/, err_callback2_t, err_style_t const *);
extern void err_set_subsystem_callback0_voidp (
    int /*subsystem*/, err_callback0_voidp_t, err_style_t const *, void *);
extern void err_set_subsystem_callback0_int (
    int /*subsystem*/, err_callback0_int_t, err_style_t const *, int);
extern void err_set_subsystem_callback0 (
    int /*subsystem*/, err_callback0_t, err_style_t const *);
    /* For C++, these functions are also accessible via
     *     err_set_subsystem_callback
     */

extern void err_unset_subsystem_callback (int /*subsystem*/);
   /* This implements a mechanism of filtering sub-systems completely.
    *
    * A callback for a subsystem overrides all other callback and stream
    * settings.
    *
    * As usual, you can set callback to NULL in order to do the formatting,
    * but not invoke anything.
    *
    * IF the style is NULL, no formatting will be done.  Instead, the
    * raw message text string is passed to the callback.
    */

extern char const *err_subsystem_name (int /*tag*/);
   /* gets the group name or return NULL */

#ifdef ERR_SUBSYSTEM_ID

static int _err_subsystem_cache() ATTR_PURE;
static int _err_subsystem_cache()
{
    static int x= 0;
    if (!x)
        x= err_subsystem(ERR_MODULE);
    return x;
}

#endif

/* ********************************************************************** */
/* Groups */

extern ATTR_PURE int err_group (char const * /*name*/);
   /* Returns the identifier of a given group.  You need not declare groups,
    * but may freely use them directly.  Groups are a bit like subsystems,
    * but in contrast, the group is not shown, but instead meant to be
    * an additional level of classification of messages.  They are used
    * mainly for filtering. */

extern char const *err_group_name (int /*tag*/);
   /* gets the group name or return NULL */

extern void err_group_set_prefix (int /*tag*/, char const * /*prefix*/);
   /* Sets a string to print as a prefix in front of all errors
    * printed with the given err_group() in tag.
    *
    * E.g., you might want to do:
    *    err_group_set_prefix (err_group("nyi"), "Not yet implemented:\n");
    *
    * Then you can:
    *    eprintf (C_TAG_ERROR|err_group("nyi"), "Syntax error before ...");
    *
    * To print:
    *    "Not yet implemented:\nSyntax error before ..."
    *
    * The prefix is added in front of texts added with ERR_PREFIX.
    *
    * You can set a default prefix for all messages without a group
    * by setting tag=0.
    *
    * You can reset a prefix by setting it to NULL.
    */

extern char const *err_group_get_prefix (int /*tag*/);
   /* Returns a prefix set with err_group_set_prefix. */

/* ********************************************************************** */
/* Buffering */


extern void err_buffer_begin (err_buffer_t * /*buffer*/);
   /* Start buffering all message into given buffer.
    * This locally makes error message issuing quiet.
    * Usage may be nested: this pushes an error buffer
    * which is then the innermost buffer.
    *
    * If buffer is NULL, messages are hidden.
    *
    * When buffering is active, only the innermost buffer
    * is filled with messages.   The messages are already
    * filtered, but not formatted (apart from the mere
    * message).
    *
    * Note that the buffer combines messages that have the
    * C_TAG_MORE with previous messages for convenience.  This
    * is reflected in the typedef of err_message_t in
    * include/error/decls.h .
    *
    * Note: Messages with the following tags cannot be gathered in buffers:
    *     : C_TAG_ASSERTION
    *     : C_TAG_FATAL
    */

extern void err_buffer_end (void);
   /* End the buffering set with err_buffer_begin() */

/* err-renumber */
extern ERR_BOOL err_is_buffered (int tag, int number);
   /* whether something is buffered. */

extern void err_re_issue (err_message_t *);
   /* With this function, you can manually re-issue messages from
    * an error buffer. */

extern void err_buffer_re_issue (err_buffer_t * /*buffer*/);
   /* Seldom used: issues the messages but keeps them.
    * Introduced for debugging and otherwise not useful.
    *
    * Don't use!
    */

extern void err_buffer_flush (err_buffer_t * /*buffer*/);
   /* Re-issue buffered error messages that where gathered
    * using err_begin_buffer and err_end_buffer.
    *
    * Note that this function does not filter the messages,
    * because filtering is done before already.
    *
    * After re-issuing the mesages, the buffer is cleared.
    *
    * Note that an err_buffer_t is not an Erwin vector.
    * Still, many functions are identical to Erwin vectors,
    * so you can easily filter it before unbuffering using e.g.
    * err_buffur_erase_if etc.  You don't need to take care
    * of freeing messages, because this is done by Erwin.
    */

/* ********************************************************************** */
/* Filtering
 *
 * If a filter rule for a message number is found, then that is used.
 *
 * Otherwise, if filtering says not to display a rule due to group,
 * subsystem or tag number filtering, that message is not displayed.
 */

enum err_decision_t {
    ERR_NO,
    ERR_YES,
    ERR_WEAK_NO,
    ERR_WEAK_YES,
    ERR_DEFAULT
};

#ifndef __cplusplus
typedef int err_decision_t;
#endif

extern char const *err_decision_to_char_p (err_decision_t);
   /* Return the a human readable symbol name of the given enum value. */

/* err-renumber */
extern void err_show_message (int /*number*/, err_decision_t /*show*/);
   /* Selection of messages to show/hide.
    *
    *    +-----------------------+------------------------------------------------+
    *    | show == ERR_YES       | show                                           |
    *    | show == ERR_NO        | hide                                           |
    *    | show == ERR_WEAK_YES  | show if not set otherwise yet                  |
    *    | show == ERR_WEAK_NO   | hide if not set otherwise yet                  |
    *    | show == ERR_DEFAULT   | use setting for tag (deletes previous setting) |
    *    +-----------------------+------------------------------------------------+
    *
    * Usually an application should stick to the ERR_DEFAULT_(YES,NO)
    * values, since this library will soon parse the command line
    * and configure itself at the users will.
    *
    * The default is to use the setting for the given group.
    * If you set this, this overrides settings for the group.
    *
    * Note: Messages with the following tags cannot be filtered,
    *       since they have no numbers:
    *     :  C_TAG_NONE
    *     :  C_TAG_UNCLASSIFIED
    *     :  C_TAG_ASSERTION
    */

extern void err_show_devel (int /*tags*/, err_decision_t /*show*/);
extern void err_show       (int /*tags*/, err_decision_t /*show*/);
   /* Select filtering a certain group of tags or certain tags
    * of subsystems or the like.  Use the ERR_YES,NO, etc. macros
    * as with err_show_message().
    *
    * You can specify groups of tags, 0 means all tags.
    *
    * You can combine tags and subsystem and group ids to form a narrow
    * selection of what is to be filtered.  E.g.,
    *    : err_show (C_TAG_WARNING | err_subsystem ("lex"), ERR_NO)
    * hides warnings from subsystem lex.
    *
    * More specific selections override less specific ones.
    *
    * The default is to hide debug messages (C_TAG_DEBUG) if NDEBUG is #defined
    * and to show all others.   If NDEBUG is not #defined, all messages are
    * displayed by default.  (Of course, this behaviour can be overriden using
    * this function, since that is only the default.  It is even a weaker
    * default than can be defined with this function, so you can change it
    * with ERR_DEFAULT_YES and ERR_DEFAULT_NO.)
    *
    * Note than currently, the library has only one table far the settings,
    * so the following sequence:
    *
    *   :  err_show (C_TAG_WARNING, ERR_YES);
    *   :  err_show (C_TAG_WARNING, ERR_DEFAULT_NO);
    *   :  err_show (C_TAG_WARNING, ERR_DEFAULT);
    *
    * will let the library show warnings, since the second call has no
    * effect, since the value was already set.
    *
    * No setting can be defined for C_TAG_MORE.  The
    * setting of the previous message is used.
    */

/* err-renumber */
extern ERR_ERWIN_BOOL err_is_shown (int tag, int number);
   /* Returns 1 if the message would be issued and 0 if not */

/* err-renumber */
extern void err_print_message (FILE * /*stream*/, int /*number*/, err_decision_t /*print*/);
   /* Define that the given error number shall be printed.  See err_print()
    * for more details on the difference between printing and showing and
    * the filtering thereof. */

extern void err_print_devel (FILE * /*file*/, int /*tags*/, err_decision_t /*print*/);
extern void err_print       (FILE * /*file*/, int /*tags*/, err_decision_t /*print*/);
   /* Like err_show*, but local to a file.
    *
    * You can set-up filtering rules without actually currently using
    * that FILE*.  The next time you err_add_stream(), the filtering
    * will be active.
    *
    * With this function, you can set-up filtering on streams, e.g.,
    * have all messages of group 'logfile' go into a special file only.
    *
    * You can use NULL as a file pointer to set a default behaviour
    * for all possible files.  This default behaviour can be reset
    * using err_reset_stream (NULL).
    */

/* err-renumber */
extern void err_print_once_message (
    FILE *,
    int /*number*/,
    err_decision_t /*print*/,
    err_symtab_t * /*table*/ ERWIN_IF_CXX (= NULL));
    /* Defines that the given message be printed only once.  See err_print_once()
     * for more details of the one-time issuing */

extern void err_print_once_devel (
    FILE *,
    int /*tags*/,
    err_decision_t /*print*/,
    err_symtab_t * /*table*/ ERWIN_IF_CXX (= NULL));

extern void err_print_once (
    FILE *,
    int /*tags*/,
    err_decision_t /*print*/,
    err_symtab_t * /*table*/ ERWIN_IF_CXX (= NULL));
   /* Any message returning YES using the given filtering will only be
    * printed once into the given stream.
    *
    * To accomplish this, the text of every message is stored in
    * a hash table.
    *
    * If 'table' is NULL, an internal global table is used.  Otherwise,
    * the given symbol table is used for remembering messages.  If
    * you want to, you can give a different table to the system.
    * Note: The library never deallocates tables that you give it.
    *
    * To set a default behaviour for all possible files, use NULL as
    * a file pointer.
    *
    * The only way to remove the filtering per stream is by using
    * err_reset_stream ().
    *
    * You can reset the default values by using err_reset_stream(NULL).
    */


/* err-renumber */
extern ERR_ERWIN_BOOL err_is_printed (FILE *, int tag, int number);
   /* checks the stream filtering for the given file.
    *
    * Note: even if the FILE* is currently not in use, it's filtering
    * rules are still active.
    *
    * If you want to reset a stream including its filtering rules, use
    * err_reset_stream().
    *
    * Further note: even if a FILE* was never seen by the library, it
    * does have filtering rules.  So even without ever using err_add_stream()
    * on a new FILE*, this function will return ERR_ERWIN_TRUE if
    * the message is issued and shown.
    */

/* err-renumber */
extern ERR_ERWIN_BOOL err_is_seen (int tag, int number);
   /* The functions consider all possible filters that prevent
    * messages from being printed in to a stream:  issue filters,
    * show filters, and buffering.  err_is_seen_in() also considers
    * stream filtering.
    *
    * In short, this functions return whether the user will see
    * a message that is produced with an eprintf call in at least
    * one of the streams it is printed into.
    */

extern void err_set_quiet_level_devel (int);
extern void err_set_quiet_level (int);
   /* Set a typical show/hide behaviour suitable for many programs:
    *
    *   +-------+------------------------------------------------------+
    *   |  <=0 =| every tag is shown.                                  |
    *   |    1 =| progress messages are hidden.                        |
    *   |    2 =| notes are also hidden.                               |
    *   |    3 =| infos are also hidden.                               |
    *   |    4 =| warnings are also hidden.                            |
    *   |    5 =| errors are also hidden.                              |
    *   |  >=6 =| fatal errors and assertion failures are also hidden. |
    *   +-------+------------------------------------------------------+
    *
    * This uses ERR_DEFAULT_YES and ERR_DEFAULT_NO to do the setting,
    * so it does not override older settings.
    */

extern void err_stream_set_quiet_level_devel (FILE*, int);
extern void err_stream_set_quiet_level       (FILE*, int);
   /* like err_set_quiet_level() for streams.  See err_print() for
    * details */


/* err-renumber */
extern void err_issue_message (int /*number*/, err_decision_t /*show*/);
   /* Define whether a message is issued.  This is a global filter
    * that filters by error number.  See err_is_issued() and err_issue(),
    * also.
    */

extern void err_issue_devel (int /*tags*/, err_decision_t /*show*/);
extern void err_issue       (int /*tags*/, err_decision_t /*show*/);
   /* An issued message is one that is counted.  Those messages
    * whose issuing is prevented by a filter will not be seen by
    * error buffers and will not be distributed into streams and
    * user callbacks, and will also not be shown or printed.
    * So this a very hard filtering.  The only counters that
    * are increased when a message is filtered from issuing are
    * the 'received' counters, which count the number of eprintf
    * invocations altogether.
    *
    * See the ERR_STATUS_* enum for a list of filtering and
    * counting levels.
    */

/* err-renumber */
extern ERR_ERWIN_BOOL err_is_issued (int tag, int number);
   /* The parameters are the same as for the _show_ family, but
    * the effect is that the filtering is done such that the messages
    * are not even processed if they are filtered this way.  In
    * contrast to only hiding them, this means:
    *     - they are not counted
    *     - the callbacks are not invoked
    *     - they are not stored in buffers.
    *
    * Note: Messages with the following tags cannot be suppressed:
    *     :  C_TAG_ASSERTION
    *     :  C_TAG_FATAL
    * (But they can be hidden.)
    */

/* ********************************************************************** */
/* Counting */

#define ERR_STATUS_RECEIVED     (1 << 0)
    /* those errors for which an eprintf was invoked */
#define ERR_STATUS_ISSUED       (1 << 1)
    /* those errors that passed the initial filtering (err_issue_...) */
#define ERR_STATUS_BUFFERED     (1 << 2)
    /* those errors that were written into a buffer. */
#define ERR_STATUS_DISTRIBUTED  (1 << 3)
    /* those errors for which callbacks where invoked; that's those
     * issued ones that where not buffered and then dropped. */
#define ERR_STATUS_SHOWN        (1 << 4)
    /* those that went into a stream */
#define ERR_STATUS_PRINTED      (1 << 5)
    /* like _SHOWN, but every stream counts one here, so this
     * might count one error more than once */

#define ERR_STATUS_ALL          (~0)

typedef int err_status_t;

/* Due to being the most common case, the following functions accept
 * abbreviations:
 *     instead of ERR_STATUS_DISTRIBUTED, you may write 0.
 *     instead of ERR_COUNTER_TYPE_TAG,   you may write 0.
 */

extern int err_count (
   err_status_t ERWIN_IF_CXX (= 0),
   int /*tag*/  ERWIN_IF_CXX (= C_TAG_ERRORS));
   /* Get the value of a tag counter.
    *
    * A typical idiom at the end of main is:
    *
    *   : exit (err_count(0,0) ? EXIT_FAILURE : EXIT_SUCCESS);
    *
    * You can access different types of counters via this
    * function, depending on whether you specify the tag, the group
    * or the subsystem.
    *
    *  +---------------------------+--------------------------------------+
    *  |! Counter Type             |! Example for 'tag'                   |
    *  |  per tag                  |  C_TAG_ERROR                         |
    *  |  per tag and subsystem    |  C_TAG_ERROR + err_subsystem ("lex") |
    *  |  per tag and group        |  C_TAG_ERROR + err_group ("lex")     |
    *  |  per subsystem            |  err_subsystem ("lex")               |
    *  |  per group                |  err_group ("lex")                   |
    *  +---------------------------+--------------------------------------+
    *
    * Furthermore, you may use groups of tags to get the total
    * count (the sum of all single counts).  E.g.:
    *   :  err_count (ERR_STATUS_DISTRIBUTED,
    *   :      C_TAG_ERROR | C_TAG_WARNING | err_subsystem("lex"))
    *
    * It is (currently) illegal to specify both a subsystem and a group.
    *
    * You cannot specify groups of statuses (this would make no sense).
    *
    * If tag is 0, it defaults of C_TAG_ERRORS.  If status is 0, it
    * defaults to ERR_STATUS_DISTRIBUTED, so the above is normally
    * what you want.
    */

/* err-renumber */
extern int err_message_count (err_status_t, int /*number*/);
   /* Get the value of a message counter. */

/* err-renumber */
extern void err_clear_count (err_status_t, int /*number*/);
   /* Set a particular counter to 0 */

/* err-renumber */
extern void err_clear_message_count (err_status_t, int /*number*/);
   /* Set a particular counter to 0 */

/* err-renumber */
extern void err_set_count (err_status_t, int number, int /*val*/);
   /* Set a particular counter to a given value */

/* err-renumber */
extern void err_add_count (err_status_t, int number, int /*val*/);
   /* Add to a particular counter */

/* err-renumber */
extern void err_set_message_count (err_status_t, int number, int /*val*/);

/* err-renumber */
extern void err_add_message_count (err_status_t, int number, int /*val*/);
   /* For general modification of the counters.
    * You may use groups of tags and groups of statuses here.
    *
    * None of these functions checks the fatal counters.
    *
    * E.g.
    *     :  err_count_dec (
    *     :      ERR_STATUS_SHOWN | ERR_STATUS_PRINTED,
    *     :      ERR_COUNTER_TYPE_TAG,
    *     :      C_TAG_ERROR | C_TAG_WARNING);
    *
    * Please note:
    * If you modify the tag counters manually, it may or
    * may not be guaranteed that e.g.
    *     : err_count (0, err_subsystem(X)) ==
    *     : err_count (0, C_TAG_ALL + err_subsystem(X))
    * since the library may or may not use own counters for the
    * sums per subsystem/group.
    */

extern void err_clear_all_count (err_status_t);
   /* This accepts groups of statuses.
    *
    * E.g.
    *     : err_count_clear_all (ERR_STATUS_ALL);
    *
    */

/* err-renumber */
extern void err_do_count (int tag, int number, err_status_t);
   /* Counts this error in the internal counters.
    *
    * This is usually not very interesting to the user, since this
    * the function the library uses internally to count.  If the
    * user wants to contribute, they can use this.
    *
    * This function does not generate a fatal error if any of the fatal
    * counters is exceeded by the counting.  This checking is only done in
    * eprintf functions.
    *
    * In contrast to err_add_count, you cannot count groups of tags with
    * this function.  (The result of trying to do so will be strange.)
    */

/* ********************************************************************** */
/* fatal counts */

extern void err_set_fatal_count (err_status_t, int /*tag*/, int /*cnt*/);
   /* This function let's you define a maximal amount of errors
    * that leads to a fatal error.  This is useful if you are
    * expecting a large number of errors when you'd start fixing
    * at the beginning anyway.
    *
    * This function sets the counter to a given tag.
    */

extern void err_unset_fatal_count (err_status_t, int /*tag*/);
extern void err_unset_all_fatal_count (err_status_t);
   /* Unset a fatal error counter.  See err_set_fatal_count(). */

/* err-renumber */
extern void
err_set_fatal_message_count (err_status_t, int number, int /*cnt*/);
   /* Set err_set_fatal_counter().
    *
    * This function sets the counter to a given message id.
    */

/* err-renumber */
extern void
err_unset_fatal_message_count (err_status_t, int /*number*/);
   /* Unset a fatal error counter.  See err_set_fatal_message_count(). */

extern void err_unset_all_fatal_message_count (err_status_t);
    /* set/unset the amount of times a certain message may occur, that is
     * considered to be fatal.  As with the normal message counters,
     * you may set/unset this for tags, groups, sub-systems, and messages.
     *
     * cnt <= 0 is illegal.
     *
     * As with counters, these functions work with groups of statuses, and
     * for ERR_COUNTER_TYPE_TAG, groups of tags.
     *
     * Please note that these functions do not split the tag into tag,
     * subsystem and group.  Instead, the fatal count may be specified
     * for any integer value.  To check the fatal count, exactly this
     * value will be used to compare to the actual count.  Therefore,
     * you can specify a fatal count for the sum of errors and
     * warnings, which in turn does not effect any fatal count for
     * errors and warnings alone.  Or you could specify a fatal count
     * for C_TAG_ERROR of a given subsystem or group only.
     *
     * This implies that you can only unset fatal counts exactly
     * for the tag you specified before.  (So this behaves quite
     * differently from err_clear_count().)
     */

/* err-renumber */
extern int err_fatal_count (err_status_t, int number);
    /* Query a fatal counter. */

/* err-renumber */
extern int err_fatal_message_count (err_status_t, int number);
    /* Get the amount of times a certain message may occur.  You may
     * specify groups of status, in which case, the minimum count will
     * be returned.
     *
     * -1 is returned if any of the matching error counts is unset.
     */

extern ErrFormattedStream *err_get_stream (FILE *);
   /* never returns NULL: if the stream does not exist, a new one is
    * allocated */

extern ErrFormattedStream *err_get_stream_by_name (char const *);
   /* may return NULL if no such stream is known. */


/* ********************************************************************** */
/* Helpers */

extern void err_flush_buffers(void);
    /* For debugging purposes: dump all buffered error messages and clear
     * the message buffers. */

extern ATTR_NORETURN void err_crash_aux(void);
    /* use err_crash() macro instead */

typedef int (*ErrProcessOption) (
    char const * /*key*/, char const * /*value*/, ERR_ERWIN_BOOL /*must*/);
   /* return value = number of input arguments that were used:
    *    0= unknown key
    *    1= option without value
    *    2= option with value
    * An error message is printed by this function if the result
    * is 0.
    * Value may be NULL.
    * must==false defines that value may be used, must==true defines that
    * it must be used, or otherwise an error about an illegal argument must
    * be produced.
    */

extern void err_get_envvar_global (ErrVChar * /*result*/, char const * /*prefix*/);
   /* Returns the name of the global environment variable for a
    * given prefix.  E.g. for "msg", this returns "MSG_OPTIONS"
    */

extern void err_get_envvar_local (ErrVChar * /*result*/, char const * /*prefix*/);
   /* Returns the name of the local environment variable for a
    * given prefix.  This requires err_prognam() to return non-NULL.
    * E.g. for a prefix of "msg" and an err_progname() of "exec2crl",
    * this returns "MSG_OPTIONS_EXEC2CRL".
    *
    * If err_progname() returns NULL, this returns "".
    */

extern void err_opt_parse_args (
    int *             /*argc_p*/,
    char ***          /*argv_p*/,
    char const *      /*prefix*/,
    ErrProcessOption  /*callback*/);
    /* Parses the command line searching for options for the given library
     * (defined by the prefix) and calls the callback for each option found.
     * The processed options are removed from the command line.
     *
     * Any dashes around the given prefix will be removed before being used.
     */

extern void err_opt_parse_string (
    char const *     /*envstr*/,
    ErrProcessOption /*callback*/);
    /* Parses an environment string for options and calls the callback for
     * each option found.
     */

extern void err_opt_parse (
    int *             /*argc_p*/,
    char ***          /*argv_p*/,
    char const *      /*prefix*/,
    ErrProcessOption  /*callback*/);
    /* First parses the environment variables for the given prefix,
     * then parses the command line args.  This combines err_opt_parse_args()
     * and err_opt_parse_string() into one call.
     *
     * The env.variables checked are derived from the prefix, which is
     * taken in upper case with _OPTIONS added, e.g. MSG_OPTIONS.  This
     * is the first variable checked.  The second variable, which may override
     * the settings, would be <PREFIX>_OPTIONS_<PROGNAME>, e.g.
     * MSG_OPTIONS_EXEC2CRL for a prefix of 'msg' and an err_progname() of
     * 'exec2crl'.
     *
     * See err_get_envvar_global() and err_get_envvar_local().
     */

/* ********************************************************************** */
/* stderr redirection (deprecated)*/

#ifdef ERR_REDIR_STDERR
    /* This is deprecated. */

extern int  err_fprintf_tag (void);
extern void err_fprintf_tag_set (int /*tag*/);
   /* The tag to use for messages coming in via fprintf (stderr...)
    *
    * By default, this is C_TAG_NOCLASS.
    */

#endif

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

extern void err_add_callback (
    int /*tags*/, int /*priority*/, err_style_t const *);

extern void err_add_callback (
    int /*tags*/, int /*priority*/, err_callback2_voidp_t, void *, err_style_t const *);
extern void err_add_callback (
    int /*tags*/, int /*priority*/, err_callback2_int_t, int, err_style_t const *);
extern void err_add_callback (
    int /*tags*/, int /*priority*/, err_callback2_t, err_style_t const *);

extern void err_add_callback (
    int /*tags*/, int /*priority*/, err_callback0_voidp_t, void *, err_style_t const *);
extern void err_add_callback (
    int /*tags*/, int /*priority*/, err_callback0_int_t, int, err_style_t const *);
extern void err_add_callback (
    int /*tags*/, int /*priority*/, err_callback0_t, err_style_t const *);

extern void err_add_callback (
    int /*tags*/, int /*priority*/, err_callback2_info_voidp_t, void *, err_style_t const *);
extern void err_add_callback (
    int /*tags*/, int /*priority*/, err_callback2_info_int_t, int, err_style_t const *);
extern void err_add_callback (
    int /*tags*/, int /*priority*/, err_callback2_info_t, err_style_t const *);

extern void err_add_callback (
    int /*tags*/, int /*priority*/, err_callback0_info_voidp_t, void *, err_style_t const *);
extern void err_add_callback (
    int /*tags*/, int /*priority*/, err_callback0_info_int_t, int, err_style_t const *);
extern void err_add_callback (
    int /*tags*/, int /*priority*/, err_callback0_info_t, err_style_t const *);


extern void err_remove_callback (
    int /*tags*/, int /*priority*/, err_callback2_voidp_t /*function*/);
extern void err_remove_callback (
    int /*tags*/, int /*priority*/, err_callback2_voidp_t /*function*/, void * /*data*/);
extern void err_remove_callback (
    int /*tags*/, int /*priority*/, err_callback0_voidp_t /*function*/);
extern void err_remove_callback (
    int /*tags*/, int /*priority*/, err_callback0_voidp_t /*function*/, void * /*data*/);
extern void err_remove_callback (
    int /*tags*/, int /*priority*/, err_callback2_info_voidp_t /*function*/);
extern void err_remove_callback (
    int /*tags*/, int /*priority*/, err_callback2_info_voidp_t /*function*/, void * /*data*/);
extern void err_remove_callback (
    int /*tags*/, int /*priority*/, err_callback0_info_voidp_t /*function*/);
extern void err_remove_callback (
    int /*tags*/, int /*priority*/, err_callback0_info_voidp_t /*function*/, void * /*data*/);

extern void err_remove_callback (
    int /*tags*/, int /*priority*/, err_callback2_int_t /*function*/);
extern void err_remove_callback (
    int /*tags*/, int /*priority*/, err_callback2_int_t /*function*/, int /*data*/);
extern void err_remove_callback (
    int /*tags*/, int /*priority*/, err_callback0_int_t /*function*/);
extern void err_remove_callback (
    int /*tags*/, int /*priority*/, err_callback0_int_t /*function*/, int /*data*/);
extern void err_remove_callback (
    int /*tags*/, int /*priority*/, err_callback2_info_int_t /*function*/);
extern void err_remove_callback (
    int /*tags*/, int /*priority*/, err_callback2_info_int_t /*function*/, int /*data*/);
extern void err_remove_callback (
    int /*tags*/, int /*priority*/, err_callback0_info_int_t /*function*/);
extern void err_remove_callback (
    int /*tags*/, int /*priority*/, err_callback0_info_int_t /*function*/, int /*data*/);

extern void err_remove_callback (
    int /*tags*/, int /*priority*/, err_callback2_t /*function*/);
extern void err_remove_callback (
    int /*tags*/, int /*priority*/, err_callback0_t /*function*/);
extern void err_remove_callback (
    int /*tags*/, int /*priority*/, err_callback2_info_t /*function*/);
extern void err_remove_callback (
    int /*tags*/, int /*priority*/, err_callback0_info_t /*function*/);


extern void err_set_subsystem_callback (
    int /*subsystem*/, err_style_t const *);

extern void err_set_subsystem_callback (
    int /*subsystem*/, err_callback2_voidp_t, void *, err_style_t const *);
extern void err_set_subsystem_callback (
    int /*subsystem*/, err_callback2_int_t, int, err_style_t const *);
extern void err_set_subsystem_callback (
    int /*subsystem*/, err_callback2_t, err_style_t const *);
extern void err_set_subsystem_callback (
    int /*subsystem*/, err_callback0_voidp_t, void *, err_style_t const *);
extern void err_set_subsystem_callback (
    int /*subsystem*/, err_callback0_int_t, int, err_style_t const *);
extern void err_set_subsystem_callback (
    int /*subsystem*/, err_callback0_t, err_style_t const *);

extern void err_set_subsystem_callback (
    int /*subsystem*/, err_callback2_info_voidp_t, void *, err_style_t const *);
extern void err_set_subsystem_callback (
    int /*subsystem*/, err_callback2_info_int_t, int, err_style_t const *);
extern void err_set_subsystem_callback (
    int /*subsystem*/, err_callback2_info_t, err_style_t const *);
extern void err_set_subsystem_callback (
    int /*subsystem*/, err_callback0_info_voidp_t, void *, err_style_t const *);
extern void err_set_subsystem_callback (
    int /*subsystem*/, err_callback0_info_int_t, int, err_style_t const *);
extern void err_set_subsystem_callback (
    int /*subsystem*/, err_callback0_info_t, err_style_t const *);

#endif

#endif /* !defined HT_LIBERROR_2932_H */
