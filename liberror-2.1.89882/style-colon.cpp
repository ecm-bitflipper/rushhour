// -*- Mode: C++ -*-

// Currently, the output is one of (vaguely GNU Tools with column plus range):
//
//   FILE: PROGNAME[PID]: TAG NUMBER:
//   FILE:LINE: PROGNAME[PID]: TAG NUMBER:
//   FILE:LINE:COL: PROGNAME[PID]: TAG NUMBER:
//
// The following types using ranges are not normally displayed since they are not
// part of GNU style.  They can be switched on with the configure option
// --enable-style-colon-ranges:
//
//   FILE:LINE:COL:..COL: PROGNAME[PID]: TAG NUMBER:
//   FILE:LINE:COL:..LINE:COL: PROGNAME[PID]: TAG NUMBER:
//   FILE:LINE:COL:..FILE:LINE: PROGNAME[PID]: TAG NUMBER:
//   FILE:LINE:COL:..FILE:LINE:COL: PROGNAME[PID]: TAG NUMBER:
//
// The file is displayed in a shell-quoted manor.
//
// This can only be parsed by Emacs if there is a colon in front of "..", so
// we cannot change this to a simple "-".
//

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "liberror.h"
#include "internal.h"
#include "failure.h"                          

#ifdef UNIX
#  include "unistd.h"
#endif

#define ERR_STYLE_COLON_SHOW_LAST 1

err_style_t const err_style_colon_s = {
    "plain-colon",
    err_style_colon_format,
    err_style_plain_post_format
};

/* ********************************************************************** */

extern int err_style_colon_format_flp (
    err_markup_t *,
    err_formatted_stream_t * /*stream*/,
    err_v_char_t *msg,
    int  /*tag*/, int /*orig_tag*/,
    ERR_ERWIN_BOOL hide_file,
    ERR_ERWIN_BOOL hide_line,
    char const *file, int line, int pos)
{
    // file/line:
    if (file != NULL) {
        bool schon= false;
        int  j1= err_v_char_nentries (msg);
        if (!hide_file) {
            err_v_char_oformat (msg, ERR_FO_QUOTE_SHELL, "%s", file);
            schon= true;
        }
        if (line > 0) {
            if (!hide_line) {
                if (schon)
                    err_v_char_append (msg, ':');
                err_v_char_format (msg, "%d", line);
                schon= true;
            }
            if (pos > 0) {
                if (schon)
                    err_v_char_append (msg, ':');
                err_v_char_format (msg, "%d", pos);
            }
        }
        int j2= err_v_char_nentries (msg);

        return j2 - j1 + 1;
    }
    return 0;
}

extern int err_style_colon_format_position (
    err_markup_t *m,
    err_formatted_stream_t *stream,
    err_v_char_t *msg,
    int tag, int orig_tag,
    ERR_ERWIN_BOOL hide_file,
    ERR_ERWIN_BOOL hide_line,
    err_position_t const *loc)
{
    return err_style_colon_format_flp (
        m, stream, msg, tag, orig_tag, hide_file, hide_line, loc->file, loc->line, loc->pos);
}

extern int err_style_colon_format_area (
    err_markup_t *m,
    err_formatted_stream_t *stream,
    err_v_char_t *msg,
    int tag, int orig_tag,
    err_area_t const *loc)
{
    if (loc->first.file != NULL) {
        // file/line:
        err_begin_part (m, stream, msg, ERR_MSG_PART_LOC, orig_tag);

        int j= err_style_colon_format_position (
            m, stream, msg, tag, orig_tag, false, false, &loc->first);

#ifdef ERR_STYLE_COLON_SHOW_LAST
        if (j > 0) {
            bool hide_file = err_string_cmp (loc->first.file, loc->last.file) == 0;
            bool hide_line = hide_file && loc->first.line == loc->last.line;
            if (loc->last.file != NULL &&
                (!hide_file || loc->last.line > 0) &&
                (!hide_line || loc->last.pos  > 0) &&
                err_position_pieces (&loc->last) >= err_position_pieces (&loc->first))
            {
                err_v_char_append_string (msg, ":..");
                j+= err_style_colon_format_position (
                    m, stream, msg, tag, orig_tag,
                    hide_file,
                    hide_line,
                    &loc->last);
            }
            err_v_char_append (msg, ':');
    
            err_begin_part (m, stream, msg, ERR_MSG_PART_SPACE, orig_tag);
            err_v_char_append (msg, ' ');
        }
#endif

        err_end_part (m, msg);

        return j;
    }

    return 0;
}

extern void err_style_colon_format_marked_up (
    err_markup_t *m,
    err_formatted_stream_t *stream,
    err_v_char_t *target,
    int tag, int orig_tag, int number,
    err_msg_info_t info,
    err_location_t const *loc,
    char const *progname, char const *hostname, int pid,
    char const *text)
{
    int nentries= 0;
    int pure_tag= ERR_PURE_TAG (orig_tag);
    bool prefix_tag=
        pure_tag != C_TAG_NONE &&
        pure_tag != C_TAG_BANNER;

    if (tag == C_TAG_MORE &&
        prefix_tag &&
        !loc->valid())
    {
        err_begin_part (m, stream, target, ERR_MSG_PART_BODY, orig_tag);
        err_v_char_append_string (target, err_style_plain_tab);
        nentries+= strlen (err_style_plain_tab);
    }

    if (prefix_tag) {
        nentries+= err_style_colon_format_area (m, stream, target, tag, orig_tag, loc->here);

        if (tag != C_TAG_MORE && prefix_tag) {
            nentries+= err_style_plain_format_progname (
                m, stream, target, tag, orig_tag, progname, hostname, pid);

            nentries+= err_style_plain_format_tag (
                m, stream, target, tag, orig_tag, number);
        }

        nentries+= err_style_plain_format_address_range (
            m, stream, target, tag, orig_tag, loc->here);

        err_style_plain_append_cr_perhaps (target, loc->valid(), &nentries, text);

        nentries+=
            err_style_plain_format_time (m, stream, target, tag, orig_tag, info.issue_time);
    }


    // Prepend every new line with \t.
    bool last_cr= (nentries == 0);
        // if this is a continued message and if target is empty,
        // we're at the beginning of a line that should still be
        // indented.

    if (ERR_IS_DEVEL (orig_tag)) {
        err_begin_part (m, stream, target, ERR_MSG_PART_BODY, C_TAG_DEBUG);
        if (last_cr &&
            pure_tag != C_TAG_NONE &&
            pure_tag != C_TAG_BANNER &&
            pure_tag != C_TAG_UNCLASSIFIED)
        {
            err_v_char_append_string (target, err_style_plain_tab);
        }
        err_v_char_append_string (target, "Developer: ");
        last_cr= false;
        err_end_part (m, target);
    }

    err_begin_part (m, stream, target, ERR_MSG_PART_BODY, orig_tag);
    for (char const *c= text; *c; c++) {
        if (last_cr &&
            pure_tag != C_TAG_NONE &&
            pure_tag != C_TAG_BANNER &&
            pure_tag != C_TAG_UNCLASSIFIED)
        {
            err_v_char_append_string (target, err_style_plain_tab);
        }
        err_v_char_append (target, *c);
        last_cr= (*c == '\n');
    }
    err_end_part (m, target);


    /* Possibly format the original position: */
    if (loc->orig.valid()) {
        nentries= 0;
        nentries+= err_style_colon_format_area (m, stream, target, tag, orig_tag, loc->orig);
        nentries+= err_style_plain_format_address_range (
            m, stream, target, tag, orig_tag, loc->orig);
        if (nentries > 0) {
            static char const *orig_pos_text = "This is the original location.\n";
            err_style_plain_append_cr_perhaps (target, true, &nentries, orig_pos_text);

            err_begin_part (m, stream, target, ERR_MSG_PART_BODY, orig_tag);
            err_v_char_append_string (target,orig_pos_text);
            err_end_part (m, target);
        }
    }

    /* Print further locations: */
    forever {
        void (*printer)(err_v_char_t *, err_location_t const *)= loc->print_next;

        loc= loc->next_loc;
        if (loc == NULL)
            break;

        nentries= 0;
        nentries+= err_style_colon_format_area (m, stream, target, tag, orig_tag, loc->here);
        nentries+= err_style_plain_format_address_range (
            m, stream, target, tag, orig_tag, loc->here);

        if (nentries > 0) {
            err_v_char_t *description= err_v_char_new ();
            printer (description, loc);
            char const *t= err_v_char_as_array (description);
            err_style_plain_append_cr_perhaps (target, true, &nentries, t);

            err_begin_part (m, stream, target, ERR_MSG_PART_BODY, orig_tag);
            err_v_char_append_string (target, t);
            err_end_part (m, target);
        }
    }
}

extern void err_style_colon_format (
    err_formatted_stream_t *stream,
    err_v_char_t *target,
    int tag, int orig_tag, int number,
    err_msg_info_t info,
    err_location_t const *loc,
    char const *progname, char const *hostname, int pid,
    char const *text)
{
    err_style_colon_format_marked_up (
        err_markup_plain, stream, target, tag, orig_tag, number, info, loc, progname,
        hostname, pid, text);
}

/* redirected to plain: */

extern int err_style_colon_format_progname (
    err_markup_t *m,
    err_formatted_stream_t *stream,
    err_v_char_t *msg,
    int  tag, int orig_tag,
    char const *progname, char const *hostname, int pid)
{
    return err_style_plain_format_progname (
        m, stream, msg, tag, orig_tag, progname, hostname, pid);
}

extern int err_style_colon_format_tag (
    err_markup_t *m,
    err_formatted_stream_t *stream,
    err_v_char_t *msg,
    int tag, int orig_tag, int number)
{
    return err_style_plain_format_tag (m, stream, msg, tag, orig_tag, number);
}

extern int err_style_colon_format_address_range (
    err_markup_t *m,
    err_formatted_stream_t *stream,
    err_v_char_t *msg,
    int  tag, int orig_tag,
    err_area_t const *loc)
{
    return err_style_plain_format_address_range (m, stream, msg, tag, orig_tag, loc);
}

extern err_v_char_t *err_style_colon_post_format (
    err_formatted_stream_t *stream,
    int tag, int orig_tag, err_v_char_t const *msg)
{
    /* If you change this, also adjust err_style_colon_s above! */
    return err_style_plain_post_format (stream, tag, orig_tag, msg);
}
