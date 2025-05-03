/* -*- Mode: C -*- */

#ifndef ERR_STYLE_QT3_34234_H
#define ERR_STYLE_QT3_34234_H

#ifdef __cplusplus
extern "C" {
#endif

extern err_style_t const err_style_qt3_s;
#define err_style_qt3 (&err_style_qt3_s)
   /* Similar to err_style_plain, but with a few mark-ups useful for Qt3
    *
    * Since this style uses the plain style's formatting routines,
    * their behaviour is reflected in this style, too.  (E.g. line breaks,
    * printing of PID, etc.)
    */

extern err_markup_t *err_markup_qt3;

extern char const *err_markup_qt3_color (err_markup_t *, int, int, ERR_BOOL);

extern void err_markup_qt3_begin_part (
    err_markup_t *,
    err_formatted_stream_t *,
    err_v_char_t *,
    int,
    int);

extern void err_style_qt3_format (
    err_formatted_stream_t *,
    err_v_char_t *,
    int, int, int,
    err_msg_info_t,
    err_location_t const *,
    char const *, char const *, int,
    char const *);

extern err_v_char_t *err_style_qt3_post_format (
    err_formatted_stream_t *,
    int /*tag*/, int /*orig_tag*/, err_v_char_t const *);
    /* This is the post-format function for plain style. */

#ifdef __cplusplus
}
#endif

#endif /* ERR_STYLE_QT3_34234_H */
