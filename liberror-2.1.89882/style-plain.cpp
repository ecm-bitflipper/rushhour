// -*- Mode: C++ -*-

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "liberror.h"
#include "internal.h"
#include "failure.h"

#ifdef UNIX
#  include "unistd.h"
#endif

int err_style_plain_redirect= ERR_STYLE_QUOTES;

#define REDIRECT(MEMBER)                                 \
          (err_style_plain_redirect == ERR_STYLE_COLON ? \
              err_style_colon_##MEMBER                   \
          : err_style_quotes_##MEMBER)

int         err_style_plain_line_break=    ERR_STYLE_LINE_BREAK_LOCATION_GIVEN;
ERR_BOOL    err_style_plain_show_pid=      ERR_ERWIN_FALSE; // don't be overly talkative
ERR_BOOL    err_style_plain_show_hostname= ERR_ERWIN_FALSE; // ditto
int         err_style_plain_show_time=     ERR_STYLE_TIME_PROGRESS;
ERR_BOOL    err_style_plain_show_date=     0;
int         err_style_plain_color=         ERR_STYLE_COLOR_IF_TTY;
char const *err_style_plain_tab=           "        ";

/* ********************************************************************** */

err_style_t const err_style_plain_s = {
    "plain",
    err_style_plain_format, /* this will dynamically redirect the invocation */
    err_style_plain_post_format
};

/* ********************************************************************** */

ErrMapIntSymbol err_plain_colors;

void err_plain_color_define (int part, int tags, char const *color)
{
    err_color_define (err_plain_colors, part, tags, color);
}


#define BOLD               "01"
#define DIM_BOLD           BOLD
                        // "05" blinks in modern xterms, so we change the default

#define BLACK              "30"
#define RED                "31"
#define GREEN              "32"
#define YELLOW             "33"
#define BLUE               "34"
#define MAGENTA            "35"
#define CYAN               "36"
#define WHITE              "37"

#define BOLD_RED           BOLD ";" RED
#define BOLD_BLUE          BOLD ";" BLUE
#define BOLD_MAGENTA       BOLD ";" MAGENTA

#define DIM_BOLD_GREEN     DIM_BOLD ";" GREEN
#define DIM_BOLD_YELLOW    DIM_BOLD ";" YELLOW

void err_plain_color_init (int *, char ***)
{
    err_plain_colors.clear ();

    /* General */
    err_plain_color_define (ERR_MSG_COLOR_PREFIX,  0, "\033[");
    err_plain_color_define (ERR_MSG_COLOR_SUFFIX,  0, "m");
    err_plain_color_define (ERR_MSG_COLOR_OFF,     0, "0");

    /* Address */
    err_plain_color_define (ERR_MSG_PART_ADDRESS,  C_TAG_BANNER,    BOLD);
    err_plain_color_define (ERR_MSG_PART_ADDRESS,  C_TAG_DEBUG,     BOLD_BLUE);
    err_plain_color_define (ERR_MSG_PART_ADDRESS,  C_TAG_ASSERTION, BOLD_RED);

    /* Body */
    err_plain_color_define (ERR_MSG_PART_BODY,     C_TAG_ALL_NORMAL, BOLD); /* default */

    err_plain_color_define (ERR_MSG_PART_BODY,     C_TAG_BANNER,    BOLD);
    err_plain_color_define (ERR_MSG_PART_BODY,     C_TAG_DEBUG,     BOLD_BLUE);
    err_plain_color_define (ERR_MSG_PART_BODY,     C_TAG_ASSERTION, BOLD_RED);

    /* Location */
    err_plain_color_define (ERR_MSG_PART_LOC,      C_TAG_ASSERTION, BOLD_RED);
    err_plain_color_define (ERR_MSG_PART_LOC,      C_TAG_DEBUG,     BOLD_BLUE);

    /* Time */
    err_plain_color_define (ERR_MSG_PART_TIME,     C_TAG_ASSERTION, BOLD_RED);
    err_plain_color_define (ERR_MSG_PART_TIME,     C_TAG_DEBUG,     BOLD_BLUE);
    err_plain_color_define (ERR_MSG_PART_TIME,     C_TAG_PROGRESS,  BOLD_BLUE);

    /* Program name and PID */
    err_plain_color_define (ERR_MSG_PART_PROGNAME, C_TAG_ASSERTION, BOLD_RED);
    err_plain_color_define (ERR_MSG_PART_PROGNAME, C_TAG_DEBUG,     BOLD_BLUE);

    /* Tag */
    err_plain_color_define (ERR_MSG_PART_TAG,
                         C_TAG_INFO | C_TAG_NOTE,
                         DIM_BOLD_GREEN);

    err_plain_color_define (ERR_MSG_PART_TAG,      C_TAG_WARN,      DIM_BOLD_YELLOW);

    err_plain_color_define (ERR_MSG_PART_TAG,
                         C_TAG_INTERNAL | C_TAG_FATAL | C_TAG_ERROR | C_TAG_ASSERTION,
                         BOLD_RED);

    err_plain_color_define (ERR_MSG_PART_TAG,      C_TAG_DEBUG,     BOLD_BLUE);
#if 0
    err_plain_color_define (ERR_MSG_PART_TAG,      C_TAG_PROGRESS,  BOLD_BLUE);
#endif
}


char const *err_markup_plain_color (err_markup_t *, int part, int tag, ERR_BOOL on)
{
    return err_color_lookup (err_plain_colors, part, tag, on);
}

static bool do_color (err_formatted_stream_t *stream)
{
#ifdef UNIX
    if ((err_style_plain_color == ERR_STYLE_COLOR_ALWAYS) ||
            (err_style_plain_color == ERR_STYLE_COLOR_IF_TTY &&
            stream != NULL &&
            stream->file != NULL)) {
        int old_errno = errno;
        bool have_tty = isatty (fileno (stream->file));
        errno = old_errno;
        return have_tty;
    }
#endif
    return false;
}

extern void err_markup_plain_begin_part (
    err_markup_t *m,
    err_formatted_stream_t *stream,
    err_v_char_t *msg,
    int part,
    int orig_tag)
{
    if (do_color (stream))
        err_open_markup (m, msg, part, orig_tag);
}

static err_markup_t err_markup_plain_s = {
    0,
    0,
    err_markup_plain_color,
    err_markup_plain_begin_part
};

err_markup_t *err_markup_plain= &err_markup_plain_s;

/* ********************************************************************** */
/* Some things that all plain modes do in the same way: */

extern int err_style_plain_format_progname (
    err_markup_t *m,
    err_formatted_stream_t *stream,
    err_v_char_t *msg,
    int  /*tag*/, int orig_tag,
    char const *progname, char const *hostname, int pid)
{
    ErrSymbol name= err_subsystem_names.find (orig_tag & C_TAG_SUBSYSTEM_MASK);

    if (progname != NULL || name != NULL) {
        err_begin_part (m, stream, msg, ERR_MSG_PART_PROGNAME, orig_tag);

        int j1= err_v_char_nentries (msg);
        // progname:
        if (progname != NULL) {
            err_v_char_append_string (msg, progname);
            bool show_pid=  pid > 0  && err_style_plain_show_pid;
            bool show_host= hostname && err_style_plain_show_hostname;
            if (show_pid || show_host) {
                err_v_char_append (msg, '[');
                if (show_host) {
                    err_v_char_append_string (msg, hostname);
                    if (show_pid)
                        err_v_char_append (msg, '.');
                }
                if (show_pid)
                    err_v_char_format (msg, "%d", pid);
                err_v_char_append (msg, ']');
            }
        }

        // subsystem
        if (name != NULL)
            err_v_char_format (msg, ".%s", name);

        err_v_char_append (msg, ':');
        int j2= err_v_char_nentries (msg);

        err_begin_part (m, stream, msg, ERR_MSG_PART_SPACE, orig_tag);
        err_v_char_append (msg, ' ');

        err_end_part (m, msg);

        return j2 - j1 + 1;
    }

    return 0;
}

extern int err_style_plain_format_tag (
    err_markup_t *m,
    err_formatted_stream_t *stream,
    err_v_char_t *msg,
    int tag, int orig_tag, int number)
{
    char const *k= err_tag_string (ERR_PURE_TAG (tag));
        // we do not want the '(debug)' suffix, so we invoke this with ERR_PURE_TAG.

    if (k != NULL) {
        err_begin_part (m, stream, msg, ERR_MSG_PART_TAG, orig_tag);

        int j1= err_v_char_nentries (msg);
        err_v_char_append_string (msg, k);
        if (number > 0)
            err_v_char_format (msg, " %05d", number);

        err_v_char_append (msg, ':');
        int j2= err_v_char_nentries (msg);

        err_begin_part (m, stream, msg, ERR_MSG_PART_SPACE, orig_tag);
        err_v_char_append (msg, ' ');

        err_end_part (m, msg);

        return j2 - j1 + 1;
    }
    return 0;
}

extern int err_style_plain_format_address_range (
    err_markup_t *m,
    err_formatted_stream_t *stream,
    err_v_char_t *msg,
    int  /*tag*/, int orig_tag,
    err_area_t const *loc)
{
    if (loc->first.address != NULL) {
        err_begin_part (m, stream, msg, ERR_MSG_PART_ADDRESS, orig_tag);

        int j1= err_v_char_nentries (msg);
        if (loc->last.address != NULL) {
            loc->first.address->format (msg, ERR_PREP_CAPITAL_FROM);
            loc->last.address->format  (msg, ERR_PREP_LOWER_TO);
        }
        else {
            loc->first.address->format (msg, ERR_PREP_CAPITAL_AT);
        }
        err_v_char_format (msg, ":");
        int j2= err_v_char_nentries (msg);

        err_begin_part (m, stream, msg, ERR_MSG_PART_SPACE, orig_tag);
        err_v_char_append (msg, ' ');

        err_end_part (m, msg);

        return j2 - j1 + 1;
    }
    return 0;
}

extern int err_style_plain_format_time (
    err_markup_t *m,
    err_formatted_stream_t *stream,
    err_v_char_t *msg,
    int  tag, int orig_tag,
    time_t time)
{
    if (time &&
        (err_style_plain_show_time == ERR_STYLE_TIME_ALWAYS ||
         (err_style_plain_show_time == ERR_STYLE_TIME_PROGRESS &&
          ((tag & C_TAG_MASK) == C_TAG_PROGRESS ||
           (tag & C_TAG_MASK) == C_TAG_FATAL ||
           (tag & C_TAG_MASK) == C_TAG_ASSERTION))))
    {
        err_begin_part (m, stream, msg, ERR_MSG_PART_TIME, orig_tag);

        struct tm *t= localtime (&time);
        if (err_style_plain_show_date) {
            int year= t->tm_year;
            if (year < 1900) year+= 1900;
            if (year < 1970) year+= 100;
            err_v_char_format (msg, "[%04d-%02d-%02d %02d:%02d:%02d]:",
                year,       t->tm_mon+1, t->tm_mday,
                t->tm_hour, t->tm_min,   t->tm_sec);
        }
        else
            err_v_char_format (msg, "[%02d:%02d:%02d]:", t->tm_hour, t->tm_min, t->tm_sec);

        err_begin_part (m, stream, msg, ERR_MSG_PART_SPACE, orig_tag);
        err_v_char_append (msg, ' ');

        err_end_part (m, msg);

        return 2+2+3*2+1+1;
    }
    return 0;
}

extern void err_style_plain_append_cr_perhaps (
    err_v_char_t *target,
    ERR_BOOL loc_valid,
    int *nentries,
    char const *text)
{
    // decide whether to insert a line break
    if (*nentries > 0) {
        switch (err_style_plain_line_break) {
        case ERR_STYLE_LINE_BREAK_TOO_LONG: {
                char const *l= strchr (text, '\n'); /* first cr */
                int len= (l == NULL) ?
                              strlen (text)
                            : l - text;
                if (*nentries + len >= 79) {
                    err_v_char_append_string (target, "\n");
                    err_v_char_append_string (target, err_style_plain_tab);
                    *nentries+= 1 + strlen (err_style_plain_tab);
                }
            }
            break;

        case ERR_STYLE_LINE_BREAK_NEVER:
            break;

        case ERR_STYLE_LINE_BREAK_ALWAYS:
            err_v_char_append_string (target, "\n");
            err_v_char_append_string (target, err_style_plain_tab);
            *nentries+= 1 + strlen (err_style_plain_tab);
            break;

        case ERR_STYLE_LINE_BREAK_LOCATION_GIVEN:
            if (loc_valid) {
                err_v_char_append_string (target, "\n");
                err_v_char_append_string (target, err_style_plain_tab);
            }
            break;
        }
    }
}


/* ********************************************************************** */
/* Redirected to selected plain format: */

extern int err_style_plain_format_area (
    err_markup_t *m,
    err_formatted_stream_t *stream,
    err_v_char_t *msg,
    int tag, int orig_tag,
    err_area_t const *loc)
{
    return REDIRECT (format_area) (m, stream, msg, tag, orig_tag, loc);
}

extern void err_style_plain_format_marked_up (
    err_markup_t *m,
    err_formatted_stream_t *stream,
    err_v_char_t *target,
    int tag, int orig_tag, int number,
    err_msg_info_t info,
    err_location_t const *loc,
    char const *progname, char const *hostname, int pid,
    char const *text)
{
    REDIRECT (format_marked_up)
        (m, stream, target, tag, orig_tag, number, info, loc, progname, hostname, pid, text);
}

extern void err_style_plain_format (
    err_formatted_stream_t *stream,
    err_v_char_t *target,
    int tag, int orig_tag, int number,
    err_msg_info_t info,
    err_location_t const *loc,
    char const *progname, char const *hostname, int pid,
    char const *text)
{
    REDIRECT (format)
        (stream, target, tag, orig_tag, number, info, loc, progname, hostname, pid, text);
}

extern err_v_char_t *err_style_plain_post_format (
    err_formatted_stream_t *, int, int, err_v_char_t const *)
{
    return NULL;
}
