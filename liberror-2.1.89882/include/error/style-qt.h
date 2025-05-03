/* -*- Mode: C -*- */

#ifndef ERR_STYLE_QT_34234_H
#define ERR_STYLE_QT_34234_H

#ifdef __cplusplus
extern "C" {
#endif

extern err_style_t const err_style_qt_s;
#define err_style_qt (&err_style_qt_s)
   /* Similar to err_style_plain, but with a few mark-ups useful for Qt
    *
    * Since this style uses the plain style's formatting routines,
    * their behaviour is reflected in this style, too.  (E.g. line breaks,
    * printing of PID, etc.)
    */

extern char const *err_tag_qt (int /*tag*/);
    /* one of:
     * "",     unclassified, banner, prompt
     * "<n>"   notes, infos, progress,
     * "<w>"   warning
     * "<e>"   assertion, error, fatal,
     * "<d>"   debug
     */

extern void err_style_qt_format (
    err_formatted_stream_t *,
    err_v_char_t *,
    int, int, int,
    err_msg_info_t,
    err_location_t const *,
    char const *, char const *, int,
    char const *);

extern err_v_char_t *err_style_qt_post_format (
    err_formatted_stream_t *,
    int /*tag*/, int /*orig_tag*/, err_v_char_t const *);
    /* This is the post-format function for plain style. */

#ifdef __cplusplus
}
#endif

#endif /* ERR_STYLE_QT_34234_H */
