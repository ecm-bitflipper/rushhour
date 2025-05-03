// -*- Mode: C++ -*-

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "liberror.h"
#include "internal.h"
#include "failure.h"

/* ********************************************************************** */

err_style_t const err_style_qt3_s = {
    "qt3",
    err_style_qt3_format,
    err_style_qt3_post_format
};

/* ********************************************************************** */

extern char const *err_markup_qt3_color (err_markup_t *, int part, int tag, ERR_BOOL on)
{
    if (part == ERR_MSG_COLOR_PREFIX)
        return on ? "<" : "</";
    else
    if (part == ERR_MSG_COLOR_SUFFIX)
        return ">";
    else
    switch (part) {
        case ERR_MSG_PART_SPACE:
            return NULL;
        case ERR_MSG_PART_ADDRESS:
            return "err-address";
        case ERR_MSG_PART_TIME:
            return "err-time";
        case ERR_MSG_PART_BODY:
            return "err-body";
        case ERR_MSG_PART_LOC:
            return "err-loc";
        case ERR_MSG_PART_PROGNAME:
            return "err-progname";
        case ERR_MSG_PART_TAG:
            return "err-tag";
        default:
            return NULL;
    }

    /* Maybe we should add an assertion here?  Ok. */
    return0_if_reached_pi(tag);
    return NULL;
}

extern void err_markup_qt3_begin_part (
    err_markup_t *m,
    err_formatted_stream_t *,
    err_v_char_t *msg,
    int part,
    int orig_tag)
{
    err_open_markup (m, msg, part, orig_tag);
}

static err_markup_t err_markup_qt3_s = {
    0,
    0,
    err_markup_qt3_color,
    err_markup_qt3_begin_part
};

err_markup_t *err_markup_qt3= &err_markup_qt3_s;

/* ********************************************************************** */


static void err_style_qt3_format_position (
    err_v_char_t *msg, err_position_t const *loc, char const *infix, char const *infix2)
{
    return_if_null (loc);
    if (loc->file != NULL) {
        err_v_char_oformat (msg, ERR_FO_QUOTE_HTML,
            " %-s%-sfile=\"%s\"", infix, infix2, loc->file);
        if (loc->line > 0) {
            err_v_char_format (msg, " %s%sline=%d", infix, infix2, loc->line);
            if (loc->pos)
                err_v_char_format (msg, " %s%spos=%d", infix, infix2, loc->pos);
        }
    }
    if (loc->address != NULL) {
        err_v_char_format (msg, " %s%saddress-description=\"", infix, infix2);
        loc->address->format (msg, ERR_PREP_NONE);
        err_v_char_append (msg, '"');
        err_v_char_format (msg, " %s%saddress=\"", infix, infix2);
        err_v_char_format (msg, ERR_FORMAT_ADDRESS, loc->address->to_linear ());
        err_v_char_append (msg, '"');
    }
}

static void err_style_qt3_format_area (
    err_v_char_t *msg, err_area_t const *loc, char const *infix)
{
    return_if_null (loc);
    err_style_qt3_format_position (msg, &loc->first, infix, "begin-");
    if (loc->last.file != NULL)
        err_style_qt3_format_position (msg, &loc->last, infix, "end-");
}

extern void err_style_qt3_format (
    err_formatted_stream_t *stream,
    err_v_char_t *target,
    int tag, int orig_tag, int number,
    err_msg_info_t info,
    err_location_t const *loc,
    char const *progname, char const *hostname, int pid,
    char const *text)
{
    return_if_null (loc);

    // insert all info into the err tag:
    err_v_char_append_string (target, "<err");
    if (number != 0)
        err_v_char_format (target, " id=\"%d\"", number);

    if (pid > 0)
        err_v_char_format (target, " pid=\"%d\"", pid);

    if (hostname)
        err_v_char_format (target, " host=\"%s\"", hostname);

    if (progname != NULL)
        err_v_char_oformat (target, ERR_FO_QUOTE_HTML, " progname=\"%s\"", progname);

    if (tag == C_TAG_MORE)
        err_v_char_append_string (target, " continued=\"1\"");

    err_v_char_oformat (target, ERR_FO_QUOTE_HTML,
        " type=\"%s\"", err_tag_description (NULL, orig_tag, false));

    if (ERR_IS_DEVEL (orig_tag))
        err_v_char_format (target, " developer=\"1\"");

    if ((orig_tag & C_TAG_GROUP_MASK) != 0)
        err_v_char_oformat (target, ERR_FO_QUOTE_HTML,
            " group=\"%s\"", err_group_names.find (tag & C_TAG_GROUP_MASK));

    if ((orig_tag & C_TAG_SUBSYSTEM_MASK) != 0)
        err_v_char_oformat (target, ERR_FO_QUOTE_HTML,
            " subsystem=\"%s\"", err_subsystem_names.find (tag & C_TAG_SUBSYSTEM_MASK));

    if (loc->valid()) {
        err_style_qt3_format_area (target, loc->here, "");
        if (loc->orig.valid())
            err_style_qt3_format_area (target, loc->orig, "orig-");
    }

    err_v_char_append_string (target, ">\n");

    // print the message
    err_style_plain_format_marked_up (
        err_markup_qt3,
        stream, target, tag, orig_tag, number, info, loc, progname, hostname, pid,
        ErrVChar().format (ERR_FO_QUOTE_HTML, "%s", text));

    // end message
    if (err_v_char_last (target) != '\n')
        err_v_char_append (target, '\n');
    err_v_char_format (target, "</err>\n");
}

extern err_v_char_t *err_style_qt3_post_format (
    err_formatted_stream_t *, int, int, err_v_char_t const *)
{
    return NULL;
}
