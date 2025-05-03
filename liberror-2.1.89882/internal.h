/* -*- Mode: C++ -*- */

#ifndef ERROR_INTERNAL_23483_H
#define ERROR_INTERNAL_23483_H

#include "liberror.h"
#include "symbol.h"

#ifndef __cplusplus
#error "This should be compiled with C++ only."
#endif

#define forever   for(;;)
#define never     while(0)
#define unless(X) if(!(X))
#define until(X)  while(!(X))

/* If a message is swallowed, but should not: */
#define ERR_DEBUG_FILTER 0
   /* possible values: 0, 1 or 2  */

/* If a message is shown, but should not: */
#define ERR_DEBUG_SHOW   0
   /* possible values: 0, 1 or 2 */


#if ERR_DEBUG_FILTER && defined(ERR_HAVE_STDERR)
#  define ERR_FOR_DEBUG_FILTER(X) X
#  define ERR_DEBUG_FILTER_YES
#  if ERR_DEBUG_FILTER >= 2
#    define ERR_FOR_DEBUG_FILTER2(X) X
#    define ERR_DEBUG_FILTER2_YES
#  else
#    define ERR_FOR_DEBUG_FILTER2(X)
#  endif
#else
#  define ERR_FOR_DEBUG_FILTER(X)
#  define ERR_FOR_DEBUG_FILTER2(X)
#endif

#define ERR_IF_DEBUG_FILTER(X)  do { ERR_FOR_DEBUG_FILTER(X);  } while(0)
#define ERR_IF_DEBUG_FILTER2(X) do { ERR_FOR_DEBUG_FILTER2(X); } while(0)


#if ERR_DEBUG_SHOW && defined(ERR_HAVE_STDERR)
#  define ERR_FOR_DEBUG_SHOW(X) X
#  define ERR_DEBUG_SHOW_YES
#  if ERR_DEBUG_SHOW >= 2
#    define ERR_FOR_DEBUG_SHOW2(X) X
#    define ERR_DEBUG_SHOW2_YES
#  else
#    define ERR_FOR_DEBUG_SHOW2(X)
#  endif
#else
#  define ERR_FOR_DEBUG_SHOW(X)
#  define ERR_FOR_DEBUG_SHOW2(X)
#endif

#define ERR_IF_DEBUG_SHOW(X)  do { ERR_FOR_DEBUG_SHOW(X);  } while(0)
#define ERR_IF_DEBUG_SHOW2(X) do { ERR_FOR_DEBUG_SHOW2(X); } while(0)


#define DELETE(X) do { if (X) { delete (X); (X)= NULL; } } while(0)

enum ErrDevel {
    ERR_DEVEL_ONLY        = 1,
    ERR_RELEASE_ONLY      = 2,
    ERR_DEVEL_AND_RELEASE = ERR_DEVEL_ONLY & ERR_RELEASE_ONLY
};

extern ErrMapIntSymbol err_subsystem_names;
extern ErrMapSymbolInt err_subsystem_ids;
extern ErrMapSymbolInt err_group_ids;
extern ErrMapIntSymbol err_group_names;

#define ERR_REINIT 0

/* This is meant to be for assertions, since the implementation is
 * quite slow.  Note that C_TAG_PREFIX,SUFFIX,MORE are not tested
 * by this macro. */
#define ERR_SINGLE_TAG(X) ERR_EXACTLY_ONE_BIT (ERR_PURE_TAG (X))

#define ERR_FOR_SOME_TAGS(tags, invocation)                       \
        do {                                                      \
            int tag;                                              \
            tag= tags & C_TAG_NONE;      if (tag) { invocation; } \
            tag= tags & C_TAG_NOCLASS;   if (tag) { invocation; } \
            tag= tags & C_TAG_INFO;      if (tag) { invocation; } \
            tag= tags & C_TAG_NOTE;      if (tag) { invocation; } \
            tag= tags & C_TAG_PROMPT;    if (tag) { invocation; } \
            tag= tags & C_TAG_PROGRESS;  if (tag) { invocation; } \
            tag= tags & C_TAG_WARN;      if (tag) { invocation; } \
            tag= tags & C_TAG_ERROR;     if (tag) { invocation; } \
            tag= tags & C_TAG_FATAL;     if (tag) { invocation; } \
            tag= tags & C_TAG_INTERNAL;  if (tag) { invocation; } \
            tag= tags & C_TAG_ASSERTION; if (tag) { invocation; } \
            tag= tags & C_TAG_DEBUG;     if (tag) { invocation; } \
            tag= tags & C_TAG_BANNER;    if (tag) { invocation; } \
        } while (0)

#define ERR_FOR_SOME_STATUSES(statuses, invocation)                                \
        do {                                                                       \
            int status;                                                            \
            if (statuses == 0)                                                     \
                statuses= ERR_STATUS_DISTRIBUTED;                                  \
            status= statuses & ERR_STATUS_RECEIVED;    if (status) { invocation; } \
            status= statuses & ERR_STATUS_ISSUED;      if (status) { invocation; } \
            status= statuses & ERR_STATUS_BUFFERED;    if (status) { invocation; } \
            status= statuses & ERR_STATUS_DISTRIBUTED; if (status) { invocation; } \
            status= statuses & ERR_STATUS_SHOWN;       if (status) { invocation; } \
            status= statuses & ERR_STATUS_PRINTED;     if (status) { invocation; } \
        } while (0)

#define ERR_TAG_ERROR     (C_TAG_ERROR    | err_err_subsystem)
#define ERR_TAG_WARNING   (C_TAG_WARNING  | err_err_subsystem)
#define ERR_TAG_INTERNAL  (C_TAG_INTERNAL | err_err_subsystem)
#define ERR_TAG_NOTE      (C_TAG_NOTE     | err_err_subsystem)
#define ERR_TAG_INFO      (C_TAG_INFO     | err_err_subsystem)
#define ERR_TAG_DEBUG     (C_TAG_DEBUG    | err_err_subsystem)
#define ERR_TAG_MORE      C_TAG_MORE

struct ErrEnumValue {
    char const *key;
    int value;
};


/* init */
extern int err_initialised;

extern ErrVChar err_envvar_global  (int compat_level);
extern ErrVChar err_envvar_program (int compat_level);
extern ErrVChar err_arg_prefix     (int compat_level);
   /* compat_level == 1 forces "err" prefix.  All init functions
    * also check these, unless ERR_COMPAT_VERSION is #undef'ined or
    * smaller than ERR_VERSION_CODE(1,0).
    */

/* parseargs */
extern ErrEnumValue const err_tag_enum[];

int err_process_option (char const *key, char const *value, ERR_ERWIN_BOOL must);

/* error */
extern int err_printf_incarnation;
extern int err_printf_incarnation2;
extern int err_user_pid;

extern void err_print_aux (ErrFormattedStream *stream, int x, ErrDevel, err_decision_t show);

extern err_v_char_t *err_format (
    err_formatted_stream_t *stream,
    err_v_char_t *&message1,
    err_v_char_t *&message2,
    err_style_t const *style,
    int tag, int orig_tag, int orig_number,
    err_msg_info_t const &info,
    err_location_t const *loc,
    char const *text);

extern void err_do_issue (
    int tag, int orig_tag, int number, int orig_number,
    err_msg_info_t const &info, err_location_t const *loc, char const *text);

/* style */

extern void err_color_define (ErrMapIntSymbol &, int /*part*/, int /*tags*/, char const *);
extern bool err_color_parse_definition (ErrMapIntSymbol &, char const *);
extern err_symbol_t err_color_get (ErrMapIntSymbol const &, int /*part*/, int /*tag*/);
extern char const *err_color_lookup (ErrMapIntSymbol const &, int /*part*/, int /*tag*/, ERR_BOOL);

/* plain */
extern ErrMapIntSymbol err_plain_colors;

extern void err_plain_color_init (int *, char ***);
extern void err_plain_color_define (int /*part*/, int /*tags*/, char const *);

/* count */
extern void err_count_init ();
extern void err_check_too_many (int /*tag*/, int /*number*/);

/* callback */
extern void err_callback_init ();
extern void err_invoke_callbacks_before (
    int *showp,
    int tag, int orig_tag, int orig_number,
    err_msg_info_t const &,
    err_location_t const *loc,
    char const *text);
extern void err_invoke_callbacks_after (
    int *showp,
    int tag, int orig_tag, int orig_number,
    err_msg_info_t const &,
    err_location_t const *loc,
    char const *text);

extern ErrFormattedCallback *err_subsystem_callback_find (int orig_tag);

/* filter */
typedef char *ErrFilterElement;
typedef ErrMapIntCharP ErrFilterMap;

struct err_filter_t {
    ErrFilterMap tag;
    ErrFilterMap message;
    ErrFilterElement last;
    bool last_decided;

    err_filter_t ();
    void clear ();
};
#ifdef __cplusplus
typedef struct err_filter_t ErrFilter;
#else
typedef struct err_filter_t err_filter_t;
#endif

extern ErrVChar err_tag_full_description (int);
extern bool err_filter         (ErrFilter &, int, ErrDevel, err_decision_t, ErrFilterElement);
extern bool err_filter_message (ErrFilter &, int, err_decision_t, ErrFilterElement);
extern void err_merge_filter   (ErrFilter &target, ErrFilter &source, int /* specialise */ = 0);

extern ErrFilterElement err_lookup_filter (bool &, ErrFilter const &, int, int, ErrFilterElement);
   /* The bool returns whether there was a filtering rule or whether the default
    * was returned. */

extern bool err_is_shown_set_last  (int, int);
extern bool err_is_issued_set_last (bool &, int, int);
extern void err_stream_set_quiet_level_aux (ErrFormattedStream *, int, ErrDevel);

/* buffer */
extern void err_buffer_init();
extern bool err_flushing;

extern bool err_do_buffer (
    int tag, int orig_tag, int orig_number,
    err_msg_info_t const &, err_location_t const *loc, char const *text);

extern "C" {

extern int err_progress_level;

#ifndef NDEBUG
extern bool err_force_fprintf;
#else
#define err_force_fprintf false
#endif

/* Furthermore, a substitute for vfprintf.  It is used when you link
 * printf.o (this is the default).   Do not invoke them yourself: */
extern int _err_vfprintf (FILE *, char const *, va_list);
extern FILE *_err_get_stdout ();
extern FILE *_err_get_stderr ();


}

#endif /* ERROR_INTERNAL_23483_H */
