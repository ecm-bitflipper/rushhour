// -*- Mode: C++ -*-

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "liberror.h"
#include "internal.h"
#include "failure.h"

/* ********************************************************************** */

err_style_t const err_style_qt_s = {
    "qt",
    err_style_qt_format,
    err_style_qt_post_format
};

/* ********************************************************************** */

extern char const *err_tag_qt (int tag)
{
    /* everything that yields NULL here cannot be filtered by message number */
    switch (ERR_PURE_TAG (tag)) {
    case C_TAG_PROGRESS:
    case C_TAG_INFO:
    case C_TAG_NOTE:         return "<n>";

    case C_TAG_WARN:         return "<w>";

    case C_TAG_INTERNAL:
    case C_TAG_FATAL:
    case C_TAG_ASSERTION:
    case C_TAG_ERROR:        return "<e>";

    case C_TAG_DEBUG:        return "<d>";

    case C_TAG_BANNER:
    case C_TAG_UNCLASSIFIED:
    case C_TAG_NONE:
    default:
                             return "";
    }

    /* Maybe we should add an assertion here?  Ok. */
    return0_if_reached_pi(tag);
    return "";
}

extern void err_style_qt_format (
    err_formatted_stream_t *stream,
    err_v_char_t *target,
    int tag, int orig_tag, int number,
    err_msg_info_t info,
    err_location_t const *loc,
    char const *progname, char const *hostname, int pid,
    char const *text)
{
    err_style_plain_format_marked_up (
        err_markup_none,
        stream, target, tag, orig_tag, number, info, loc, progname, hostname, pid, text);
}

extern err_v_char_t *err_style_qt_post_format (
    err_formatted_stream_t *, int, int orig_tag, err_v_char_t const *v)
{
    char const *color= err_tag_qt (orig_tag);
    if (color == NULL || *color == 0)
        return NULL;

    err_v_char_t *result= err_v_char_new();
    int i;
    char c;
    bool bol= true;
    err_v_char_forall (v, i, c) {
        if (c == '\n')
            bol= true;
        else {
            if (bol)
                err_v_char_append_string (result, color);
            bol= false;
        }
        err_v_char_append (result, c);
    }

    return result;
}

