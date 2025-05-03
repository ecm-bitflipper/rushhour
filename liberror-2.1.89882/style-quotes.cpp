// -*- Mode: C++ -*-

// This style displayes the error message as follows:
//
//   PROGNAME[PID]: TAG NUMBER, "FILE", line LINE:
//   PROGNAME[PID]: TAG NUMBER, "FILE", line LINE(COL):
//   PROGNAME[PID]: TAG NUMBER, "FILE", line LINE(COL..COL):
//   PROGNAME[PID]: TAG NUMBER, "FILE", lines LINE(COL)..LINE(COL):
//   PROGNAME[PID]: TAG NUMBER, "FILE", line LINE(COL) .. "FILE", line LINE(COL):
//
// The FILE is shell-quoted in double quotes (which is a bit tricky under
// Windows...).  Erwin does not support this quotation, so we will probably
// have to implement that ourselves.
//
// This style has the advantage that the buzz word is quite at the beginning
// of the line, that is is more readable than GNU style, and that it can
// display the range in a nice looking way that Emacs can parse by default.


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

err_style_t const err_style_quotes_s = {
    "plain-quotes",
    err_style_quotes_format,
    err_style_plain_post_format
};

/* ********************************************************************** */

extern void err_style_quotes_append_shell_quoted (
    err_v_char_t *msg,
    char const *file)
{
    // This is shell quotation under Unix.  According to the man page,
    // only \, " and ` are special inside a double quoted token.
    // Unfortunately, the interactive bash adds ! which cannot be quoted
    // with a backslash.  For a !, we have to close the double quoted
    // string and instead start a single quoted string that only contains
    // the !.
    err_v_char_append (msg, '"');
    for (char const *s = file; *s; s++) {
        switch (*s) {
        case '!':
            err_v_char_append_string (msg, "\"'!'\"");
            break;

        case '\\':
        case '"':
        case '`':
            err_v_char_append (msg, '\\');
            /* no break */
        default:
            err_v_char_append (msg, *s);
            break;
        }
    }
    err_v_char_append (msg, '"');
}

extern int err_style_quotes_format_area (
    err_markup_t *m,
    err_formatted_stream_t *stream,
    err_v_char_t *msg,
    int /*tag*/, int orig_tag,
    err_area_t const *loc)
{
    return0_if_null (loc);
    int p1= err_position_pieces (&loc->first);
    int p2= err_position_pieces (&loc->last);

    if (p1 > 0) {
        err_begin_part (m, stream, msg, ERR_MSG_PART_LOC, orig_tag);

        bool same_file= p1 >= 1 &&
                        p2 >= 1 &&
                        err_string_cmp (loc->first.file, loc->last.file) == 0;

        bool same_line= same_file &&
                        p1 >= 2 &&
                        p2 >= 2 &&
                        loc->first.line == loc->last.line;

        bool same_pos=  same_line &&
                        p1 >= 3 &&
                        p2 >= 3 &&
                        loc->first.pos == loc->last.pos;

        bool last_valid= loc->last.valid() &&
                         !(p1 <= 1 && same_file) &&  /* trivial case "A".."A" */
                         !(p1 <= 2 && same_line) &&  /* trivial case "A", lines B..B */
                         !(p1 <= 3 && same_pos);     /* trivial case "A", line B(C..C) */

        int j1= err_v_char_nentries (msg);
        err_v_char_format (msg, "In ");
        err_style_quotes_append_shell_quoted (msg, loc->first.file);

        if (!last_valid || !same_file) {
            // The following styles:
            // last_valid:
            //     In "file"
            //     In "file", line LINE
            //     In "file", line LINE(POS)
            // !same_file:
            //     In "file" .. "file"
            //     In "file", line LINE .. "file", line LINE
            //     In "file", line LINE(POS) .. "file", line LINE(POS)
            if (p1 >= 2) {
                err_v_char_format (msg, ", line %d", loc->first.line);
                if (p1 >= 3)
                    err_v_char_format (msg, "(%d)", loc->first.pos);
            }

            if (last_valid) {
                err_v_char_append_string (msg, " .. ");
                err_style_quotes_append_shell_quoted (msg, loc->last.file);
                if (p2 >= 2) {
                    // Small hack, which is not really bad here, since this
                    // code will not be reached very often, since two
                    // different file names are likely to be not likely. :-)
                    // The hack is to prevent Emacs to match the second
                    // file,line/pos on the line, so we simply let the
                    // comma vanish here.
                    // This would be very correct:
                    //    err_v_char_format (msg, ", line %d", loc->last.line);
                    //
                    // but instead, we do the following:
                    err_v_char_format (msg, " line %d", loc->last.line);
                    if (p2 >= 3)
                        err_v_char_format (msg, "(%d)", loc->last.pos);
                }
            }
        }
        else
        if (!same_line) {
            // Conditions for this to be reached:
            //     - last is valid
            //       (so last is always printed)
            //     - last.file is the same as first.file
            //       (so last.file is never printed).
            //     - different lines (maybe no second line at all)
            //       (so second line is always printed)
            //
            // The following styles:
            //     In "file", lines LINE .. LINE
            //     In "file", lines LINE(POS) .. LINE(POS)

            err_v_char_format (msg, ", lines %d", loc->first.line);
            if (p1 >= 3)
                err_v_char_format (msg, "(%d)", loc->first.pos);

            err_v_char_format (msg, ".. %d", loc->last.line);
            if (p2 >= 3)
                err_v_char_format (msg, "(%d)", loc->last.pos);
        }
        else {
            // Additional conditions for this to be reached:
            //    - lines are equal
            //
            // The following style:
            //     In "file", line LINE(POS..POS)
            err_v_char_format (msg, ", line %d(%d..%d)",
                loc->first.line,
                loc->first.pos, loc->last.pos);
        }
        err_v_char_append (msg, ':');

        int j2= err_v_char_nentries (msg);

        err_begin_part (m, stream, msg, ERR_MSG_PART_SPACE, orig_tag);
        err_v_char_append (msg, ' ');

        err_end_part (m, msg);

        return j2 - j1 + 1;
   }

    return 0;
}

extern void err_style_quotes_format_marked_up (
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

    if (pure_tag != C_TAG_NONE &&
        pure_tag != C_TAG_BANNER)
    {
        if (tag == C_TAG_MORE) {
            if (!loc->valid()) {
                err_begin_part (m, stream, target, ERR_MSG_PART_BODY, orig_tag);
                err_v_char_append_string (target, err_style_plain_tab);
                nentries+= strlen (err_style_plain_tab);
            }
        }
        else {
            nentries+= err_style_plain_format_progname (
                m, stream, target, tag, orig_tag, progname, hostname, pid);

            nentries+= err_style_plain_format_tag (
                m, stream, target, tag, orig_tag, number);
        }

        nentries+= err_style_quotes_format_area (m, stream, target, tag, orig_tag, loc->here);

        if (loc->here.first.address != NULL) {
            err_style_plain_append_cr_perhaps (target, loc->valid(), &nentries, text);
            nentries+= err_style_plain_format_address_range (
                m, stream, target, tag, orig_tag, loc->here);
        }

        nentries+=
            err_style_plain_format_time (m, stream, target, tag, orig_tag, info.issue_time);

        err_style_plain_append_cr_perhaps (target, loc->valid(), &nentries, text);
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
        static char const *const orig_pos_text = "This is the original location.\n";
        nentries= 0;
        nentries+= err_style_quotes_format_area (m, stream, target, tag, orig_tag, loc->orig);
        if (loc->orig.first.address != NULL) {
            err_style_plain_append_cr_perhaps (target, true, &nentries, orig_pos_text);
            nentries+= err_style_plain_format_address_range (
                m, stream, target, tag, orig_tag, loc->orig);
        }
        if (nentries > 0) {
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

        err_v_char_t *description= err_v_char_new ();
        printer (description, loc);
        char const *t= err_v_char_as_array (description);

        nentries= 0;
        nentries+= err_style_quotes_format_area (m, stream, target, tag, orig_tag, loc->here);
        if (loc->here.first.address != NULL) {
            err_style_plain_append_cr_perhaps (target, true, &nentries, t);
            nentries+= err_style_plain_format_address_range (
                m, stream, target, tag, orig_tag, loc->here);
        }

        if (nentries > 0) {
            err_style_plain_append_cr_perhaps (target, true, &nentries, t);

            err_begin_part (m, stream, target, ERR_MSG_PART_BODY, orig_tag);
            err_v_char_append_string (target, t);
            err_end_part (m, target);
        }
    }
}

extern void err_style_quotes_format (
    err_formatted_stream_t *stream,
    err_v_char_t *target,
    int tag, int orig_tag, int number,
    err_msg_info_t info,
    err_location_t const *loc,
    char const *progname, char const *hostname, int pid,
    char const *text)
{
    err_style_quotes_format_marked_up (
        err_markup_plain, stream, target, tag, orig_tag, number,
        info, loc, progname, hostname, pid, text);
}

/* redirected to plain: */

extern int err_style_quotes_format_progname (
    err_markup_t *m,
    err_formatted_stream_t *stream,
    err_v_char_t *msg,
    int  tag, int orig_tag,
    char const *progname, char const *hostname, int pid)
{
    return err_style_plain_format_progname (
        m, stream, msg, tag, orig_tag, progname, hostname, pid);
}

extern int err_style_quotes_format_tag (
    err_markup_t *m,
    err_formatted_stream_t *stream,
    err_v_char_t *msg,
    int tag, int orig_tag, int number)
{
    return err_style_plain_format_tag (m, stream, msg, tag, orig_tag, number);
}

extern int err_style_quotes_format_address_range (
    err_markup_t *m,
    err_formatted_stream_t *stream,
    err_v_char_t *msg,
    int  tag, int orig_tag,
    err_area_t const *loc)
{
    return err_style_plain_format_address_range (m, stream, msg, tag, orig_tag, loc);
}

extern err_v_char_t *err_style_quotes_post_format (
    err_formatted_stream_t *stream,
    int tag, int orig_tag, err_v_char_t const *msg)
{
    /* If you change this, also adjust err_style_quotes_s above! */
    return err_style_plain_post_format (stream, tag, orig_tag, msg);
}
