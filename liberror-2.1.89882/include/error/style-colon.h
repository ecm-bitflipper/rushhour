/* -*- Mode: C -*- */

#ifndef ERR_STYLE_COLON_34234_H
#define ERR_STYLE_COLON_34234_H

#ifdef __cplusplus
extern "C" {
#endif

/* This also uses the following variables from plain style:
 *    err_style_plain_show_pid
 *    err_style_plain_line_break
 *    err_style_plain_color
 */

extern err_style_t const err_style_colon_s;
#define err_style_colon (&err_style_colon_s)
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
    * The colon style post_format () function always returns NULL.
    */

/* The following functions may be used to compose your own error
 * styles: */

extern void err_style_colon_format_marked_up (
    err_markup_t * /*markup*/,
    err_formatted_stream_t *,
    err_v_char_t * /*target*/,
    int /*tag*/, int /*orig_tag*/, int /*orig_number*/,
    err_msg_info_t,
    err_location_t const * /*location*/,
    char const * /*progname*/, char const * /*hostname*/, int /*pid*/,
    char const * /*text*/);
    /* This is the format function for plain style. */

extern void err_style_colon_format (
    err_formatted_stream_t *,
    err_v_char_t * /*target*/,
    int /*tag*/, int /*orig_tag*/, int /*orig_number*/,
    err_msg_info_t,
    err_location_t const * /*location*/,
    char const * /*progname*/, char const * /*hostname*/, int /*pid*/,
    char const * /*text*/);
    /* This is the format function for colon style. */

extern int err_style_colon_format_flp (
    err_markup_t *,
    err_formatted_stream_t *,
    err_v_char_t *,
    int  /*tag*/, int /*orig_tag*/,
    ERR_ERWIN_BOOL /* hide_file */,
    ERR_ERWIN_BOOL /* hide_line */,
    char const * /*file*/, int /*line*/, int /*pos*/);

extern int err_style_colon_format_position (
    err_markup_t *,
    err_formatted_stream_t *,
    err_v_char_t *,
    int /*tag*/, int /*orig_tag*/,
    ERR_ERWIN_BOOL /*hide_file*/,
    ERR_ERWIN_BOOL /*hide_line*/,
    err_position_t const * /*loc*/);

/* The following are functions that are used by err_style_colon_format() any
 * which might be useful for the user in order to compose their own styles. */
extern int err_style_colon_format_area (
    err_markup_t * /*markup*/,
    err_formatted_stream_t *stream,
    err_v_char_t *,
    int /*tag*/, int /*orig_tag*/,
    err_area_t const *);
   /* This prints the first part of the error message in colon format, i.e.,
    *
    *    "file:line:pos: "
    * or
    *    "file:line:pos--line:pos: "
    * or the like.
    *
    */

/*
 * The following functions are currently identical to the err_style_plain versions */
extern int err_style_colon_format_address_range (
    err_markup_t * /*markup*/,
    err_formatted_stream_t *stream,
    err_v_char_t *,
    int /*tag*/, int /*orig_tag*/,
    err_location_t const *);
    /* simply invokes err_style_plain_post_format (but this may change in the future) */

extern int err_style_colon_format_progname (
    err_markup_t * /*markup*/,
    err_formatted_stream_t *stream,
    err_v_char_t *,
    int /*tag*/, int /*orig_tag*/,
    char const * /*progname*/, char const * /*hostname*/, int /*pid*/);
    /* simply invokes err_style_plain_post_format (but this may change in the future) */

extern int err_style_colon_format_tag (
    err_markup_t * /*markup*/,
    err_formatted_stream_t *,
    err_v_char_t *, int /*tag*/, int /*orig_tag*/, int /*number*/);
    /* simply invokes err_style_plain_post_format (but this may change in the future) */

extern err_v_char_t *err_style_colon_post_format (
    err_formatted_stream_t *,
    int /*tag*/, int /*orig_tag*/, err_v_char_t const *);
    /* simply invokes err_style_plain_post_format (but this may change in the future) */


#ifdef __cplusplus
}
#endif

#endif /* ERR_STYLE_COLON_34234_H */
