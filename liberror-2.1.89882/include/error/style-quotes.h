/* -*- Mode: C -*- */

#ifndef ERR_STYLE_QUOTES_34234_H
#define ERR_STYLE_QUOTES_34234_H

#ifdef __cplusplus
extern "C" {
#endif

/* This also uses the following variables from plain style:
 *    err_style_plain_show_pid
 *    err_style_plain_line_break
 *    err_style_plain_color
 */

extern err_style_t const err_style_quotes_s;
#define err_style_quotes (&err_style_quotes_s)
   /* This is the default style that is used for printing.
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
    * The quotes style post_format () function always returns NULL.
    */

/* The following functions may be used to compose your own error
 * styles: */

extern void err_style_quotes_append_shell_quoted (
    err_v_char_t *,
    char const *);
    /* This puts the string into double quotes and does the quotation
     * just like a (possibly interactive) shell would expect it.  The
     * interactive shell is special wrt. to the character !.
     *
     * Note: althought the string is in double quotes, it is *NOT* C-string
     *       quoted!
     *
     * Examples:
     *    Literal        Shell            (C-String)
     *    abs.txt        "abs.txt"        "abs.txt"          (trivial)
     *    A"B            "A\"B"           "A\"B"             (shell = C)
     *    C:\A.TEST      "C:\A.TEST"      "C:\\A.TEST"       (shell != C)
     *    A'B            "A"'!'"B"        "A'B"              (shell != C)
     */

extern void err_style_quotes_format_marked_up (
    err_markup_t * /*markup*/,
    err_formatted_stream_t *,
    err_v_char_t * /*target*/,
    int /*tag*/, int /*orig_tag*/, int /*orig_number*/,
    err_msg_info_t,
    err_location_t const * /*location*/,
    char const * /*progname*/, char const * /*hostname*/, int /*pid*/,
    char const * /*text*/);
    /* This is the format function for plain style. */

extern void err_style_quotes_format (
    err_formatted_stream_t *,
    err_v_char_t * /*target*/,
    int /*tag*/, int /*orig_tag*/, int /*orig_number*/,
    err_msg_info_t,
    err_location_t const * /*location*/,
    char const * /*progname*/, char const * /*hostname*/, int /*pid*/,
    char const * /*text*/);
    /* This is the format function for quotes style. */

/* The following are functions that are used by err_style_quotes_format() any
 * which might be useful for the user in order to compose their own styles. */
extern int err_style_quotes_format_area (
    err_markup_t * /*markup*/,
    err_formatted_stream_t *stream,
    err_v_char_t *,
    int /*tag*/, int /*orig_tag*/,
    err_area_t const *);
   /* This prints the first part of the error message in quotes format, i.e.,
    *
    *    "FILE", line LINE(pos)
    * or
    *    "FILE", line LINE(pos..pos)
    * or
    *    "FILE", lines LINE(pos)..LINE(pos)
    * or the like.
    *
    * Currently only prints the first part, since Emacs cannot mark ranges.
    */

/*
 * The following functions are currently identical to the err_style_plain versions */
extern int err_style_quotes_format_address_range (
    err_markup_t * /*markup*/,
    err_formatted_stream_t *stream,
    err_v_char_t *,
    int /*tag*/, int /*orig_tag*/,
    err_location_t const *);
    /* simply invokes err_style_plain_post_format (but this may change in the future) */

extern int err_style_quotes_format_progname (
    err_markup_t * /*markup*/,
    err_formatted_stream_t *stream,
    err_v_char_t *,
    int /*tag*/, int /*orig_tag*/,
    char const * /*progname*/, char const * /*hostname*/, int /*pid*/);
    /* simply invokes err_style_plain_post_format (but this may change in the future) */

extern int err_style_quotes_format_tag (
    err_markup_t * /*markup*/,
    err_formatted_stream_t *,
    err_v_char_t *, int /*tag*/, int /*orig_tag*/, int /*number*/);
    /* simply invokes err_style_plain_post_format (but this may change in the future) */

extern err_v_char_t *err_style_quotes_post_format (
    err_formatted_stream_t *,
    int /*tag*/, int /*orig_tag*/, err_v_char_t const *);
    /* simply invokes err_style_plain_post_format (but this may change in the future) */



#ifdef __cplusplus
}
#endif

#endif /* ERR_STYLE_QUOTES_34234_H */
