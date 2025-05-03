// -*- Mode: C++ -*-

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "liberror.h"
#include "internal.h"
#include "failure.h"


int err_style_default_redirect= ERR_STYLE_PLAIN;

#define REDIRECT(STYLE, MEMBER)                                       \
          ( (STYLE) == ERR_STYLE_QT ?      err_style_qt_##MEMBER      \
          : (STYLE) == ERR_STYLE_QT3 ?     err_style_qt3_##MEMBER     \
          : (STYLE) == ERR_STYLE_SIMPLE ?  err_style_simple_##MEMBER  \
          : (STYLE) == ERR_STYLE_PLAIN ?   err_style_plain_##MEMBER   \
          : (STYLE) == ERR_STYLE_COLON ?   err_style_colon_##MEMBER   \
          : (STYLE) == ERR_STYLE_QUOTES ?  err_style_quotes_##MEMBER  \
          : (STYLE) == ERR_STYLE_DEFAULT ? err_style_default_##MEMBER \
          : err_style_none_##MEMBER)

err_style_t const *err_style_from_int (int style)
{
    return & REDIRECT (style, s);
}

/* ********************************************************************** */

err_style_t const err_style_default_s = {
    "default",
    err_style_default_format, /* this will dynamically redirect the invocation */
    err_style_default_post_format
};

/* ********************************************************************** */

void err_style_default_format (
    err_formatted_stream_t *stream,
    err_v_char_t *target,
    int tag, int orig_tag, int number,
    err_msg_info_t info,
    err_location_t const *loc,
    char const *progname, char const *hostname, int pid,
    char const *text)
{
    if (err_style_default_redirect == ERR_STYLE_DEFAULT)
        return;
    REDIRECT (err_style_default_redirect, format)
        (stream, target, tag, orig_tag, number, info, loc, progname, hostname, pid, text);
}

err_v_char_t *err_style_default_post_format (
    err_formatted_stream_t *stream, int tag, int orig_tag, err_v_char_t const *text)
{
    if (err_style_default_redirect == ERR_STYLE_DEFAULT)
        return NULL;

    return REDIRECT (err_style_default_redirect, post_format)
               (stream, tag, orig_tag, text);
}
