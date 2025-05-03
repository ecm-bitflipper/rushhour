// -*- Mode: C++ -*-

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "liberror.h"
#include "internal.h"
#include "failure.h"

err_style_t const err_style_none_s = {
    "none",
    err_style_none_format,
    err_style_none_post_format
};

/* ********************************************************************** */

extern void err_style_none_format (
    err_formatted_stream_t *,
    err_v_char_t *,
    int, int, int,
    err_msg_info_t,
    err_location_t const *,
    char const *, char const *, int,
    char const *)
{
}

extern err_v_char_t *err_style_none_post_format (
    err_formatted_stream_t *, int, int, err_v_char_t const *)
{
    return NULL;
}
