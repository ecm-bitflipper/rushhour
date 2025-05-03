/* -*- Mode: C -*- */

#ifndef ERR_STYLE_PLAIN_34234_H
#define ERR_STYLE_PLAIN_34234_H

#ifdef __cplusplus
extern "C" {
#endif

#define ERR_STYLE_PLAIN_COLON  ERR_STYLE_COLON
#define ERR_STYLE_PLAIN_QUOTES ERR_STYLE_QUOTES

extern int err_style_plain_redirect; /* = ERR_STYLE_PLAIN_QUOTES; */

extern err_style_t const err_style_plain_s;
#define err_style_plain (&err_style_plain_s)
   /* This is the default style that is used for printing.
    *
    * Depending on err_style_plain_redirect, this is either plain-colon
    * or plain quotes.
    *
    * The format() function uses the following template to print
    * an error message:
    *
    *    "file:line: progname[pid].subsystem: tag_string number: text"
    *
    * If tag      == C_TAG_NONE, only "text"            is printed.
    * If file     == NULL,       "file:line: "          is not printed.
    * If line     <= 0,          "line:"                is not printed.
    * If progname == NULL,       "progname[pid]: "      is not printed.
    * If subsystem is unknown,   ".subsystem"           is not printed.
    * If pid < 0,                "[pid]"                is not printed.
    * If number   <= 0,          " number"              is not printed.
    * If tag      == C_TAG_MORE, "tag_string number: "  is not printed.
    *
    * This function also replaces all \n in the text by \t\n.
    *
    * The plain style post_format () function always returns NULL.
    */

extern err_markup_t *err_markup_plain;

extern char const *err_markup_plain_color (err_markup_t *, int, int, ERR_BOOL);

extern void err_markup_plain_begin_part (
    err_markup_t *,
    err_formatted_stream_t *,
    err_v_char_t *,
    int,
    int);

/* **********************************************************************
 * The following functions and variables are shared by all plain styles: */

extern int          err_style_plain_line_break;    /* = ERR_STYLE_LINE_BREAK_TOO_LONG */
extern ERR_BOOL     err_style_plain_show_pid;      /* = ERR_ERWIN_TRUE */
extern ERR_BOOL     err_style_plain_show_hostname; /* = ERR_ERWIN_TRUE */
   /* if enabled in configure, decides whether to show hostname. */
extern int          err_style_plain_show_time;     /* = ERR_STYLE_TIME_PROGRESS */
extern ERR_BOOL     err_style_plain_show_date;     /* = 0 */
extern int          err_style_plain_color;         /* = ERR_STYLE_COLOR_IF_TTY */
extern char const * err_style_plain_tab;           /* = "        "; */

extern int err_style_plain_format_progname (
    err_markup_t *,
    err_formatted_stream_t *,
    err_v_char_t *,
    int /*tag*/, int /*orig_tag*/,
    char const * /*progname*/, char const * /*hostname*/, int /*pid*/);
   /* This prints the first part of the error message in plain format, i.e.,
    *
    *    "progname[host.pid]: "
    */

extern int err_style_plain_format_tag (
    err_markup_t *,
    err_formatted_stream_t *,
    err_v_char_t *, int /*tag*/, int /*orig_tag*/, int /*number*/);
    /* This prints the tag and the number in plain format. */

/* Print an address (range). */
extern int err_style_plain_format_address_range (
    err_markup_t *,
    err_formatted_stream_t *,
    err_v_char_t *,
    int /*tag*/, int /*orig_tag*/,
    err_area_t const *);
   /* Prints an address:
    *
    *    "At address ...: "
    */

/* Print an address (range). */
extern int err_style_plain_format_time (
    err_markup_t *,
    err_formatted_stream_t *,
    err_v_char_t *,
    int /*tag*/, int /*orig_tag*/,
    time_t /*time*/);
   /* Prints the time:
    *    "[12:53:60]"
    */

extern void err_style_plain_append_cr_perhaps (
    err_v_char_t *,
    ERR_BOOL /* loc_valid */,
    int * /* nentries */,
    char const * /* text */);

extern err_v_char_t *err_style_plain_post_format (
    err_formatted_stream_t *,
    int /*tag*/, int /*orig_tag*/, err_v_char_t const *);
    /* This is the post-format function for plain style. */

/* **********************************************************************
 * The following functions redirect plain style to some of the plain
 * styles. */

extern void err_style_plain_format (
    err_formatted_stream_t *,
    err_v_char_t * /*target*/,
    int /*tag*/, int /*orig_tag*/, int /*orig_number*/,
    err_msg_info_t,
    err_location_t const * /*location*/,
    char const * /*progname*/, char const * /*hostname*/, int /*pid*/,
    char const * /*text*/);
    /* This is the format function for plain style. */

extern void err_style_plain_format_marked_up (
    err_markup_t * /*markup*/,
    err_formatted_stream_t *,
    err_v_char_t * /*target*/,
    int /*tag*/, int /*orig_tag*/, int /*orig_number*/,
    err_msg_info_t,
    err_location_t const * /*location*/,
    char const * /*progname*/, char const * /*hostname*/, int /*pid*/,
    char const * /*text*/);
    /* This is the format function for plain style. */

/* The following are functions that are used by err_style_plain_format() any
 * which might be useful for the user in order to compose their own styles. */
extern int err_style_plain_format_area (
    err_markup_t *,
    err_formatted_stream_t *,
    err_v_char_t *,
    int /*tag*/, int /*orig_tag*/,
    err_area_t const *);
   /* This prints the first part of the error message in plain format, i.e.,
    *
    *    "file:line:pos: "
    * or
    *    "file:line:pos:..line:pos: "
    * or the like.
    *
    * Currently only prints the first part, since Emacs cannot mark ranges.
    */

#ifdef __cplusplus
}
#endif

#endif /* ERR_STYLE_PLAIN_34234_H */
