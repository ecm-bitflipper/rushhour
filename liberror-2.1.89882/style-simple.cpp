// -*- Mode: C++ -*-

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "liberror.h"
#include "internal.h"
#include "failure.h"

err_style_t const err_style_simple_s = {
    "simple",
    err_style_simple_format,
    err_style_simple_post_format
};

/* ********************************************************************** */

extern void err_style_simple_format (
    err_formatted_stream_t *,
    err_v_char_t *target,
    int, int, int,
    err_msg_info_t,
    err_location_t const *,
    char const *, char const *, int,
    char const *text)
{
    err_v_char_append_string (target, text);
}

extern err_v_char_t *err_style_simple_post_format (
    err_formatted_stream_t *, int, int, err_v_char_t const *)
{
    return NULL;
}
