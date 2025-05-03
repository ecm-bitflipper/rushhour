// -*- Mode: C++ -*-

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "liberror.h"
#include "internal.h"
#include "failure.h"

#define APPEND_DEVEL(STR) (debug ? STR " (debug)" : STR)

char const *err_tag_string (int tag)
{
    if (tag == C_TAG_MORE)
        return NULL;

    return0_if_fail_pxx (ERR_SINGLE_TAG (tag), tag, ERR_PURE_TAG (tag));

    /* everything that yields NULL here cannot be filtered by message number */
    bool debug= ERR_IS_DEVEL (tag);
    switch (ERR_PURE_TAG (tag)) {
    case C_TAG_INFO:         return APPEND_DEVEL("Info");
    case C_TAG_NOTE:         return APPEND_DEVEL("Note");
    case C_TAG_PROMPT:       return NULL;
    case C_TAG_PROGRESS:     return APPEND_DEVEL("Progress");
    case C_TAG_WARN:         return APPEND_DEVEL("Warning");
    case C_TAG_ERROR:        return APPEND_DEVEL("Error");
    case C_TAG_INTERNAL:     return APPEND_DEVEL("Internal Error");
    case C_TAG_FATAL:        return APPEND_DEVEL("Fatal Error");
    case C_TAG_DEBUG:        return "DEBUG";

    /* The following have no introductory text: */
    case C_TAG_BANNER:       return NULL;
    case C_TAG_ASSERTION:    return NULL;
    case C_TAG_UNCLASSIFIED: return NULL;
    case C_TAG_NONE:         return NULL;

    default:                 return NULL;
    }

    /* Maybe we should add an assertion here?  Ok. */
    return0_if_reached_pi(tag);
    return NULL;
}
#undef APPEND_DEVEL


char const *err_tag_description (ERR_BOOL *initial_vowel, int tag, ERR_BOOL plural)
{
    return0_if_fail_pxx (ERR_SINGLE_TAG (tag), tag, ERR_PURE_TAG (tag));

    /* everything that yields NULL here cannot be filtered by message number */
    if (initial_vowel)
        *initial_vowel= false;

    switch (ERR_PURE_TAG (tag)) {
    case C_TAG_INFO:
        if (initial_vowel)
            *initial_vowel= true;
        return plural ? "infos" : "info";

    case C_TAG_NOTE:
        return plural ? "notes" : "note";

    case C_TAG_PROMPT:
        return plural ? "prompts" : "prompt";

    case C_TAG_PROGRESS:
        return plural ? "progress messages" : "progress message";

    case C_TAG_WARN:
        return plural ? "warnings" : "warning";

    case C_TAG_ERROR:
        if (initial_vowel)
            *initial_vowel= true;
        return plural ? "errors" : "error";

    case C_TAG_INTERNAL:
        if (initial_vowel)
            *initial_vowel= true;
        return plural ? "internal errors" : "internal error";

    case C_TAG_FATAL:
        return plural ? "fatal errors" : "fatal error";

    case C_TAG_DEBUG:
        return plural ? "debug messages" : "debug message";

    case C_TAG_BANNER:
        return plural ? "banners" : "banner";

    case C_TAG_ASSERTION:
        if (initial_vowel)
            *initial_vowel= true;
        return plural ? "assertions" : "assertion";

    case C_TAG_UNCLASSIFIED:
        if (initial_vowel)
            *initial_vowel= true;
        return plural ? "unclassified messages" : "unclassified message";

    case C_TAG_NONE:
        if (initial_vowel)
            *initial_vowel= true;
        return plural ? "untagged messages" : "untagged message";
    } /* plural is trivial here, but need not be */

    /* Maybe we should add an assertion here?  Ok. */
    nothing_if_reached_pi(tag);
    return plural ? "messages" : "message";
}

char const *err_tag_abbreviation (int tag)
{
    return0_if_fail_pxx (ERR_SINGLE_TAG (tag), tag, ERR_PURE_TAG (tag));

    switch (ERR_PURE_TAG (tag)) {
    case C_TAG_INFO:           return sym_info;
    case C_TAG_NOTE:           return sym_note;
    case C_TAG_PROMPT:         return sym_prompt;
    case C_TAG_PROGRESS:       return sym_progress;
    case C_TAG_WARN:           return sym_warning;
    case C_TAG_ERROR:          return sym_error;
    case C_TAG_INTERNAL:       return sym_internal;
    case C_TAG_FATAL:          return sym_fatal;
    case C_TAG_DEBUG:          return sym_debug;
    case C_TAG_BANNER:         return sym_banner;
    case C_TAG_ASSERTION:      return sym_assertion;
    case C_TAG_UNCLASSIFIED:   return sym_unclassified;
    case C_TAG_NONE:           return sym_untagged;
    } /* plural is trivial here, but need not be */

    /* Maybe we should add an assertion here?  Ok. */
    nothing_if_reached_pi(tag);
    return sym_general;
}

int err_position_pieces (err_position_t const *pos)
{
    if (pos->file == NULL)
        return 0;
    if (pos->line <= 0)
        return 1;
    if (pos->pos <= 0)
        return 2;
    return 3;
}

////////////////////////////////////////////////////////////////////////////////

void err_color_define (ErrMapIntSymbol &table, int part, int tags, char const *color)
{
    tags&= C_TAG_MASK;
    if (tags == 0)
        table.set (part << C_TAG_GROUP_SHIFT, err_string2symbol (color));
    else {
        ERR_FOR_SOME_TAGS (tags,
            table.set (tag | (part << C_TAG_GROUP_SHIFT), err_string2symbol (color)));
    }
}

err_symbol_t err_color_find (ErrMapIntSymbol const &table, int part, int tag)
{
    return0_if_fail_pxx (tag == 0 || ERR_SINGLE_TAG (tag), tag, ERR_PURE_TAG (tag));
    return table.find (ERR_PURE_TAG (tag) | (part << C_TAG_GROUP_SHIFT));
}

char const *err_color_lookup (
    ErrMapIntSymbol const &table, int part, int tag, ERR_BOOL on)
{
    char const *result= NULL;

    //Not here.  The style must mark-up the debug property.
    //if (part == ERR_MSG_PART_TAG && ERR_IS_DEVEL (tag))
    //    tag= C_TAG_DEBUG; // format the tag of special debug messages at debug messages.

    if (part == ERR_MSG_COLOR_PREFIX)
        result= err_color_find (table, ERR_MSG_COLOR_PREFIX, 0);
    else
    if (part == ERR_MSG_COLOR_SUFFIX)
        result= err_color_find (table, ERR_MSG_COLOR_SUFFIX, 0);
    else
    if (on)
        result= err_color_find (table, part, tag);
    else {
        result= err_color_find (table, part | ERR_MSG_COLOR_OFF, tag);
           /* special ,off' defines per part/tag? */

        if (result == NULL) {
            /* check for a negation prefix (e.g. HTML style markup): */

            result= err_color_find (table, ERR_MSG_COLOR_PREFIX | ERR_MSG_COLOR_OFF, 0);
            if (result != NULL) {
                /* yes, we have a prefix for negation */
                char const *colstr= err_color_find (table, part, tag);
                if (colstr == NULL)
                    return NULL; /* do not continue, but return! */

                result= err_string2symbol (ErrVChar().format ("%s%s", result, colstr));
            }
        }

        if (result == NULL) {
            /* check for a negation suffix: */

            result= err_color_find (table, ERR_MSG_COLOR_SUFFIX | ERR_MSG_COLOR_OFF, 0);
            if (result != NULL) {
                /* yes, we have a suffix for negation */
                char const *colstr= err_color_find (table, part, tag);
                if (colstr == NULL)
                    return NULL; /* do not continue, but return! */

                result= err_string2symbol (ErrVChar().format ("%s%s", colstr, result));
            }
        }

        if (result == NULL) /* use default */
            result= err_color_find (table, ERR_MSG_COLOR_OFF, 0);
    }

    return result;
}

static bool match_token (char const *def, int length, char const *s)
{
    int len= err_erwin_strlen (s);

    if (len == length &&
        err_erwin_strncasecmp (def, s, len) == 0)
    {
        return true;
    }

    return false;
}

static bool match_prefix (char const *&def, int &length, char const *s)
{
    int len= err_erwin_strlen (s);

    if (len > 0 &&
        len <= length &&
        err_erwin_strncasecmp (def, s, len) == 0)
    {
        def+= len;
        length-= len;
        return true;
    }

    return false;
}

static bool match_word (char const *&def, int &length, char const *s)
{
    int len= err_erwin_strlen (s);

    if (len > 0 &&
        len <= length &&
        err_erwin_strncasecmp (def, s, len) == 0 &&
        (len == length ||
          !(err_char_is_alpha (def[len]) ||
            err_char_is_digit (def[len]))))
    {
        def+= len;
        length-= len;
        return true;
    }

    return false;
}

static int match_tag (char const *&def, int &length)
{
    for (ErrEnumValue const *va=err_tag_enum; va->key; va++)
        if (match_word (def, length, va->key))
            return va->value;

    return 0;
}

static int match_part (char const *&def, int &length)
{
    if (match_word (def, length, "prefix"))       return ERR_MSG_COLOR_PREFIX;
    if (match_word (def, length, "suffix"))       return ERR_MSG_COLOR_SUFFIX;

    if (match_word (def, length, "loc"))          return ERR_MSG_PART_LOC;
    if (match_word (def, length, "location"))     return ERR_MSG_PART_LOC;

    if (match_word (def, length, "progname"))     return ERR_MSG_PART_PROGNAME;
    if (match_word (def, length, "program-name")) return ERR_MSG_PART_PROGNAME;

    if (match_word (def, length, "tag"))          return ERR_MSG_PART_TAG;
    if (match_word (def, length, "address"))      return ERR_MSG_PART_ADDRESS;
    if (match_word (def, length, "body"))         return ERR_MSG_PART_BODY;

    if (match_word (def, length, "space"))        return ERR_MSG_PART_SPACE;

    return 0;
}

static void err_local_color_define (
    ErrMapIntSymbol &table, int part, int tags, bool neg_tags, char const *str)
{
    if (tags == 0 && part >= ERR_MSG_PART_MIN && part <= ERR_MSG_PART_MAX)
        tags= C_TAG_ALL;

    if (neg_tags)
        tags^= C_TAG_ALL;

    err_color_define (table, part, tags, str);
}

bool err_color_parse_definition_command (
    ErrMapIntSymbol &table, char const *def, int length)
{
    char const *orig_def= def;
    int orig_length= length;

    if (match_token (def, length, "clear")) {
        int tag;
        err_symbol_t *value_p;
        err_map_forall_ptr (table, tag, value_p)
            if ((tag & C_TAG_MASK) != 0)
                *value_p= NULL;
    }
    else
    if (match_token (def, length, "clear-all"))
        table.clear ();
    else {
        /* either of:
         *     tag_list.part=string
         *     tag_list=string
         *     part=string
         * tag_list is a comma separated list of tags.
         * tag_list may be negated with - to mean: not these tags, but all others.
         * Instead of =string, there may be a minus to clear.
         */
        bool neg_tags= match_prefix (def, length, "-");
        int tags= 0;
        int tag;
        while ((tag = match_tag (def, length)) > 0) {
            tags|= tag;
            if (!match_prefix (def, length, ","))
                break;
        }

        bool neg_parts= false;
        bool off= false;
        ErrMapIntBool parts;

        if (tags == 0 || match_prefix (def, length, ".")) {
            if (tags == 0) {
                neg_parts= neg_tags; /* first minus was meant to be for parts! */
                neg_tags= false;
            }
            else
                neg_parts= match_prefix (def, length, "-");

            int part;
            while ((part = match_part (def, length)) > 0) {
                parts.ensure (part);
                if (!match_prefix (def, length, ","))
                    break;
            }
        }

        if ((tags == 0 && parts.empty()) || match_prefix (def, length, ".")) {
            /* now there may be ,off' now */
            if (match_word (def, length, "off")) {
                off= true;
                match_prefix (def, length, "."); /* allow off.clear */
                    /* it does not matter that this makes the following
                     * a good spec: banner.off.=35
                     */
            }
            else
            if (match_word (def, length, "on")) {
                off= false; /* redundant */
                match_prefix (def, length, "."); /* allow on.clear */
            }
        }

        char const *str= NULL;
        ErrVChar v;
        if (match_token (def, length, "clear")) {
            /* ok, erase those */
            str= NULL; /* redundant */
        }
        else
        if (match_prefix (def, length, "=")) {
            v.append_raw (def, length);
            str= v;
        }
        else {
            v.append_raw (orig_def, orig_length);

            qeprintf (ERR_TAG_ERROR, 0,
                "Illegal color specification: %s\n", v.as_array());
            return false;
        }

        /* we have something now */

        if (parts.empty() && tags == 0 && off) {
            err_color_define (table, ERR_MSG_COLOR_OFF, 0, str); // set default off
        }
        else {
            int part_off= off ? ERR_MSG_COLOR_OFF : 0;

            if (parts.empty()) /* then do it for all parts */
                neg_parts= !neg_parts;

            if (neg_parts) {
                int const part_ids[]= {
                    ERR_MSG_PART_LOC,
                    ERR_MSG_PART_PROGNAME,
                    ERR_MSG_PART_TAG,
                    ERR_MSG_PART_ADDRESS,
                    ERR_MSG_PART_TIME,
                    ERR_MSG_PART_BODY,
                    ERR_MSG_PART_SPACE,
                    0
                };

                for (int const *part_id= part_ids; *part_id; part_id++)
                    if (parts.find_ptr (*part_id) == NULL)
                        err_local_color_define (table, *part_id | part_off, tags, neg_tags, str);
            }
            else {
                int part;
                err_map_forall_keys (parts, part)
                    err_local_color_define (table, part | part_off, tags, neg_tags, str);
            }
        }
    }

    return true;
}

bool err_color_parse_definition (ErrMapIntSymbol &table, char const *def)
{
    if (def == NULL)
        return false;

    // split at colons
    forever {
        char const *colon= strchr (def, ':');
        if (colon == NULL)
            colon= def + err_erwin_strlen (def);

        if (!err_color_parse_definition_command (table, def, colon - def))
            return false; //!

        if (!*colon)
            break; //!

        def= colon + 1;
    }

    return true;
}

////////////////////////////////////////////////////////////////////////////////

static void err_print_color (err_markup_t *m, err_v_char_t *msg, int part, int tag, bool on)
{
    if (part) {
        if (m->color (m, part, tag, on) != NULL) {
            /* we do not store the result in a local variable, since it is allowed to
             * return a pointer to a static. */
            err_v_char_append_string (msg, m->color (m, ERR_MSG_COLOR_PREFIX, tag, on));
            err_v_char_append_string (msg, m->color (m, part, tag, on));
            err_v_char_append_string (msg, m->color (m, ERR_MSG_COLOR_SUFFIX, tag, on));
            m->open_part= part;
            m->open_tag=  tag;
        }
    }
}

void err_end_part (err_markup_t *m, err_v_char_t *msg)
{
    if (m->open_part) {
        err_print_color (m, msg, m->open_part, m->open_tag, false);
        m->open_part= 0;
        m->open_tag=  0;
    }
}

void err_open_markup (err_markup_t *m, err_v_char_t *msg, int part, int tag)
{
    if (m->open_part != part || m->open_tag != tag) {
        err_end_part (m, msg);
        err_print_color (m, msg, part, tag, true);
    }
}


void err_begin_part (
    err_markup_t *m,
    err_formatted_stream_t *stream,
    err_v_char_t *msg,
    int part,
    int orig_tag)
{
    return_if_null2i (m, begin_part);
    m->begin_part (m, stream, msg, part, orig_tag);
}


char const *err_markup_none_color (err_markup_t *, int, int, ERR_ERWIN_BOOL)
{
    return NULL;
}

void err_markup_none_begin_part (
    err_markup_t *m,
    err_formatted_stream_t *,
    err_v_char_t *msg,
    int part,
    int orig_tag)
{
    err_open_markup (m, msg, part, orig_tag);
}

static err_markup_t err_markup_none_s = {
    0,
    0,
    err_markup_none_color,
    err_markup_none_begin_part
};

err_markup_t *err_markup_none= &err_markup_none_s;

ErrStyle const *ErrFormattedStream::get_style() const
{
    return style ? style : err_style_none;
}
