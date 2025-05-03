// -*- Mode: C++ -*-
/* ----------------------------------------------------------------------
 *
 * Author: Henrik Theiling
 * Description: Error printing function
 *
 * COPYRIGHT NOTICE:
 *
 *   (c) Copyright 2001-2002 Henrik Theiling
 *
 * ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include "liberror.h"
#include "internal.h"
#include "failure.h"

#ifdef UNIX
#  include "unistd.h"
#  define  RAW_PID  (getpid())

#ifdef ERR_WITH_HOSTNAME
// Make this configure itself correctly and then let the user switch
// the feature on with an option.

#include <unistd.h>

static char const *err_hostname_normalise (char const *x)
{
    ErrVChar sh= x;
    if (x && strchr (x, '.')) {
        sh= x;
        sh.set_size (sh.find ('.'));
        x= sh;
    }
    if (err_erwin_strequ (x, "localhost"))
        return NULL;
    return err_string2symbol (x);
}

static char const *err_get_hostname()
{
    static char const *x= NULL;
    static bool have_x= false;
    if (have_x)
        return x;

    have_x= true;

#if 0
    struct hostent *he= gethostbyaddr("\x7f\0\0\1", 4, AF_INET);
    if (he) {
        while (
        x= err_hostname_normalise (he->h_name);
        char **alias= he->h_aliases;
        while (x == NULL && alias && *alias) {
            x= err_hostname_normalise (*alias);
            alias++;
        }
    }
#endif
    char h[200];
    if (gethostname (h, 200) == 0)
        x= err_hostname_normalise (h);

    return x;
}

#   define HOSTNAME (err_get_hostname())

#else
#   define HOSTNAME NULL
#endif

#else
#  define  RAW_PID  (-1)
#  define  HOSTNAME NULL
#endif

#  define  PID  (err_user_pid >= 0 ? err_user_pid : RAW_PID)

char const *err_callbacks_only= "";

int err_printf_incarnation=  0;
int err_printf_incarnation2= 0;
int err_user_pid= -1;

static int subsystem_counter= 1;
ErrMapIntSymbol err_subsystem_names;
ErrMapSymbolInt err_subsystem_ids;

static ErrMapIntVStream streams;
static ErrMapFileStream file2stream;
static ErrMapSymbolStream name2stream;
static ErrMapIntCharP   err_group_prefix;

#ifdef ERR_REDIR_STDERR
static int fprintf_tag= C_TAG_NOCLASS;
#endif

static int group_counter= 1;
ErrMapSymbolInt err_group_ids;
ErrMapIntSymbol err_group_names;

int err_err_subsystem= 0;

static void (*err_user_resolve_address)(int, int, int, err_position_t *) = NULL;

/* ********************************************************************** */

#ifdef ERR_REDIR_STDERR
static void fprintf_flush ();
#endif

/* ********************************************************************** */

#ifdef ERR_REDIR_STDERR

int err_fprintf_tag (void)
{
    return fprintf_tag;
}

int err_fprintf_tag_set (int tag)
{
    int result= fprintf_tag;
    fprintf_tag= tag;
    return result;
}

#endif

/* ********************************************************************** */
/* pid */

int err_pid ()
{
    return PID;
}

void err_set_pid (int apid)
{
    err_user_pid= apid;
}

/* ********************************************************************** */
/* err_number */

err_number_t const * /*err-skip*/err_number(int i)
{
    static /*err-skip*/ErrNumber num;
    num= /*err-skip*/ErrNumber (i);
    return &num;
}

/* ********************************************************************** */
/* Streams */

#define TRUE_P ((ErrFilterElement)&file2stream)
   /* This is != NULL and thus represents true instead of false.  That's all we
    * need here.  Other modules really store something. */

ErrFormattedStream *err_get_stream (FILE *file)
{
    ErrFormattedStream **streamp= file2stream.find_ptr_ensure (file);
    return0_if_null (streamp);
    if (*streamp == NULL) {
        *streamp= new ErrFormattedStream (file, NULL);
        //fprintf (stderr, "DEBUG: new stream.\n");
#ifdef ERR_HAVE_STDERR
        if (file == stderr) {
            //fprintf (stderr, "DEBUG: =stderr.\n");
            err_stream_set_name (file, "stderr");
        }
        if (file == stdout) {
            //fprintf (stderr, "DEBUG: =stdout.\n");
            err_stream_set_name (file, "stdout");
        }
#endif
    }
    return *streamp;
}

ErrFormattedStream *err_get_stream_by_name (char const *name_raw)
{
    err_symbol_t name= err_string2symbol (name_raw);
    ErrFormattedStream **streamp= name2stream.find_ptr_ensure (name);
    return0_if_null (streamp);
    if (*streamp == NULL) {
        *streamp= new ErrFormattedStream (NULL, NULL);
        (*streamp)->name= name;
        //fprintf (stderr, "DEBUG: new named stream %s\n", name);
    }
    return *streamp;
}

/* print/swallow */
void err_print_aux (ErrFormattedStream *stream, int x, ErrDevel devel, err_decision_t show)
{
    return_if_null (stream);
    if (stream->filter == NULL)
        stream->filter= new ErrFilter;
    err_filter (*stream->filter, x, devel, show, TRUE_P);
}

void err_print (FILE *file, int x, err_decision_t show)
{
    err_print_aux (err_get_stream (file), x, ERR_RELEASE_ONLY, show);
}

void err_print_devel (FILE *file, int x, err_decision_t show)
{
    err_print_aux (err_get_stream (file), x, ERR_DEVEL_ONLY, show);
}

void /*err-skip*/err_print_message (FILE *file, int x, err_decision_t show)
{
    ErrFormattedStream *stream= err_get_stream (file);
    return_if_null (stream);
    if (stream->filter == NULL)
        stream->filter= new ErrFilter;
    err_filter_message (*stream->filter, x, show, TRUE_P);
}

static ERR_ERWIN_BOOL /*err-skip*/err_is_printed_raw (
    bool &decided, ErrFormattedStream const *stream, int tag, int number)
{
    return0_if_null (stream);
    decided= false;

    if (stream->filter != NULL) {
        if (!err_lookup_filter (decided, *stream->filter, tag, number, TRUE_P))
            return ERR_ERWIN_FALSE;
    }
    return ERR_ERWIN_TRUE;
}

static ERR_ERWIN_BOOL /*err-skip*/err_is_printed (
    ErrFormattedStream const *stream, int tag, int number)
{
    bool decided;

    ERR_ERWIN_BOOL result= err_is_printed_raw (decided, stream, tag, number);
    if (decided)
        return result;

    stream= err_get_stream (NULL);
    return err_is_printed_raw (decided, stream, tag, number);
}

static ERR_ERWIN_BOOL /*err-skip*/err_is_printed_set_last (
    ErrFormattedStream const *stream, int tag, int number)
{
    return0_if_null (stream);

    bool decided= false;
    ErrFilterElement last;

    last= err_is_printed_raw (decided, stream, tag, number) ? TRUE_P : (ErrFilterElement)0;

    if (!decided) {
        ErrFormattedStream const *stream2= err_get_stream (NULL);

        ErrFilterElement sub_last=
            err_is_printed_raw (decided, stream2, tag, number) ? TRUE_P : (ErrFilterElement)0;

        if (tag != C_TAG_MORE || decided)
            last= sub_last;
    }

    if (stream->filter != NULL) {
        stream->filter->last= last;
        stream->filter->last_decided= decided;
    }
    return (bool)last;
}

ERR_ERWIN_BOOL /*err-skip*/err_is_printed (FILE *file, int tag, int number)
{
    ErrFormattedStream const *stream= err_get_stream (file);
    return err_is_printed (stream, tag, number);
}

/* print_once/swallow */
static void err_print_once_aux (
    FILE *file, int x, ErrDevel devel, err_decision_t show, err_symtab_t *table)
{
    ErrFormattedStream *stream= err_get_stream (file);
    return_if_null (stream);
    if (stream->status.once == NULL)
        stream->status.once= new ErrFilter;
    if (table == NULL) {
        if (stream->status.remember_once == NULL)
            stream->status.remember_once= err_symtab_new();
        table= stream->status.remember_once;
    }
    err_filter (*stream->status.once, x, devel, show, (ErrFilterElement)table);
}

void err_print_once (
    FILE *file, int x, err_decision_t show, err_symtab_t *table)
{
    err_print_once_aux (file, x, ERR_RELEASE_ONLY, show, table);
}

void err_print_once_devel (
    FILE *file, int x, err_decision_t show, err_symtab_t *table)
{
    err_print_once_aux (file, x, ERR_DEVEL_ONLY, show, table);
}

void /*err-skip*/err_print_once_message (
    FILE *file, int x, err_decision_t show, err_symtab_t *table)
{
    ErrFormattedStream *stream= err_get_stream (file);
    return_if_null (stream);
    if (stream->status.once == NULL)
        stream->status.once= new ErrFilter;
    if (table == NULL) {
        if (stream->status.remember_once == NULL)
            stream->status.remember_once= err_symtab_new ();
        table= stream->status.remember_once;
    }
    err_filter_message (*stream->status.once, x, show, (ErrFilterElement)table);
}

static err_symtab_t * /*err-skip*/err_is_printed_once_raw (
    bool &decided, ErrFormattedStream const *stream, int tag, int number)
{
    return0_if_null (stream);
    decided= false;
    if (stream->status.once != NULL)
        return (err_symtab_t *)err_lookup_filter (decided, *stream->status.once, tag, number, NULL);
    return NULL;
}

static err_symtab_t * /*err-skip*/err_is_printed_once_set_last (
    ErrFormattedStream *stream, int tag, int number)
{
    return0_if_null (stream);

    bool decided= false;
    err_symtab_t *last= NULL;

    last= err_is_printed_once_raw (decided, stream, tag, number);

    if (!decided) {
        ErrFormattedStream *stream2= err_get_stream (NULL);

        err_symtab_t *sub_last=
            err_is_printed_once_raw (decided, stream2, tag, number);

        if (tag != C_TAG_MORE || decided) {
            // Ok, the default stream may say that we have to cache the message.
            // But we must not use tables from the default stream.  Therefore,
            // we must use the default remember_once table from the corresponding
            // stream.  If none exists, we will create one.
            if (last == NULL && sub_last != NULL) {
                if (stream->status.remember_once == NULL)
                    stream->status.remember_once= err_symtab_new ();
                last= stream->status.remember_once; // dont use anything from stream2 here!
            }
        }
    }

    if (stream->status.once != NULL) {
        stream->status.once->last= (ErrFilterElement)last;
        stream->status.once->last_decided= decided;
    }
    return last;
}

static void err_add_stream_aux (int tag, FILE *file, err_style_t const *style)
{
    ErrVStream **v= streams.find_ptr_ensure (tag);
    if (!*v)
        *v= new ErrVStream;

    ErrFormattedStream *stream= file2stream.find (file);

    if (stream == NULL) {
        stream= err_get_stream (file);
        return_if_null (stream);

        if (stream->style == NULL)
            stream->style= style; // set the new style
    }

    (*v)->append (stream);
}

void err_add_stream (int tags, FILE *file, err_style_t const *style)
{
    if (style == NULL)
        style= err_style_default;
    ERR_FOR_SOME_TAGS (tags, err_add_stream_aux (tag, file, style));
}

void err_stream_set_style (FILE *file, err_style_t const *style)
{
    err_get_stream (file)->style= style;
}

ERR_BOOL err_stream_set_name (FILE *file, char const *name_raw)
{
    return0_if_null (file);
    return0_if_null (name_raw);

    err_symbol_t name= err_string2symbol (name_raw);

    err_formatted_stream_t *stream_file= err_get_stream (file);
    return0_if_null (stream_file);
    return0_if_fail (stream_file->file == file);

    err_formatted_stream_t *stream_name= name2stream.find (name);

    if (stream_name == NULL) {
        //fprintf (stderr, "DEBUG:ERR: new stream w/ name %s\n", name);
        stream_file->name= err_string2symbol (name);
        name2stream.insert (name, stream_file);
    }
    else
    if (stream_name != stream_file) {
        //fprintf (stderr, "DEBUG:ERR: two stream: one w/ name %s, one w/ file\n", name);
        if (stream_name->file == NULL) {
            //fprintf (stderr, "DEBUG:ERR: named stream also has file.\n");
            //fprintf (stderr, "DEBUG: stream %p -> style %s\n",
            //    file, file2stream.find (file)->get_style()->name);

            // different streams.  Ok, then copy
            return0_if_fail (stream_name->name == name);

            // Copy style and filtering rules if existent
            if (stream_name->style != NULL) {
                stream_file->style= stream_name->style;
                stream_name->style= NULL;
            }
            //fprintf (stderr, "DEBUG: stream %p -> style %s\n",
            //    file, stream_file->style->name);

            if (stream_name->filter != NULL) {
                if (stream_file->filter == NULL) {
                    stream_file->filter= stream_name->filter;
                    stream_name->filter= NULL; // detach
                }
                else {
                    err_merge_filter (*stream_file->filter, *stream_name->filter);
                       // settings from name override those from file.
                    err_merge_filter (*stream_file->filter, *stream_name->filter,
                                      err_group (name));
                       // further, the default also overwrites the settings for the
                       // group with the name of the stream.
                }
            }

            // erase the old structure from all the data structures:
            stream_file->name= name;

            // use stream_name for file.
            name2stream.set (name, stream_file);

            DELETE (stream_name);
            //fprintf (stderr, "DEBUG: stream %p -> style %s\n",
            //    file, file2stream.find (file)->get_style()->name);
        }
        else {
            //fprintf (stderr, "DEBUG:ERR: two different streams.  should not happen.\n");
            //qeprintf (C_TAG_INTERNAL, 0,
            //    "Stream %s already exists with different file pointer.\n", name);
            return false;
        }
    }
    else {
        return0_if_fail (stream_name->name == stream_file->name);
    }
    return true;
}

static FILE *err_comparison_file= NULL;

static ERR_ERWIN_BOOL stream_equal (ErrFormattedStream *s)
{
    return0_if_null (s);
    return s->file == err_comparison_file;
}

static void err_remove_stream_aux (int tag, FILE *file)
{
    ErrVStream *v= streams.find (tag);
    if (!v)
        return;
    err_comparison_file= file;
    v->erase_if (stream_equal);
    if (v->empty()) {
        delete v;
        streams.remove(tag);
    }
}

void err_remove_stream (int tags, FILE *file)
{
    ERR_FOR_SOME_TAGS (tags, err_remove_stream_aux (tag, file));
}

/* err_stream_status_t */
void err_stream_status_t::release()
{
    DELETE (once);
    if (remember_once) {
        err_symtab_delete(remember_once);
        remember_once = NULL;
    }
    if (last) {
        free(last);
        last = NULL;
    }
}

void err_stream_status_t::import (
    int a, char *b, int c, time_t d,
    err_symbol_t e, ERR_BOOL f, struct err_filter_t *g, err_symtab_t *h)
{
    count= a;
    last=  b;
    last_tag= c;
    started= d;

    last_sym= e;
    last_sym_printed= f;

    once= g;
    remember_once= h;
}

err_stream_status_t::err_stream_status_t ()
{
    import (0, NULL, 0, 0, NULL, false, NULL, NULL);
}

err_stream_status_t::err_stream_status_t (err_stream_status_t const &o)
{
    import (o.count, o.last, o.last_tag, o.started,
            o.last_sym, o.last_sym_printed, o.once, o.remember_once);
}

void err_stream_status_t::operator= (err_stream_status_t const &o)
{
    release ();
    import (o.count, o.last, o.last_tag, o.started,
            o.last_sym, o.last_sym_printed, o.once, o.remember_once);
}

err_stream_status_t::~err_stream_status_t ()
{
    release ();
}

/* err_formatted_stream_t */
err_formatted_stream_t::err_formatted_stream_t (char const *a):
        file (NULL),
        name (err_string2symbol (a)),
        style (NULL),
        filter (NULL)
    {}

err_formatted_stream_t::err_formatted_stream_t (FILE *a, err_style_t const *b):
        file (a),
        name (NULL),
        style (b),
        filter (NULL)
    {}

err_formatted_stream_t::~err_formatted_stream_t ()
    {
        DELETE (filter);
    }

void err_reset_stream (FILE *file)
    {
        ErrFormattedStream *stream= file2stream.find (file);
        if (stream) {
            file2stream.erase (file);
            name2stream.erase (stream->name);
            err_remove_stream (C_TAG_ALL, file);
            delete stream;
        }
    }

/* ********************************************************************** */
/* generic formatting */

err_v_char_t *err_format (
    err_formatted_stream_t *stream,
    err_v_char_t *&message1,
    err_v_char_t *&message2,
    err_style_t const *style,
    int tag, int orig_tag, int orig_number,
    err_msg_info_t const &info,
    err_location_t const *loc,
    char const *text)
{
    return0_if_null (style);

    message1= err_v_char_new ();
    style->format (stream, message1, tag, orig_tag, orig_number, info, loc, err_progname(),
        HOSTNAME, PID, text);
    message2= style->post_format (stream, tag, orig_tag, message1);
    if (message2)
        return message2;
    else
        return message1;
}

/* ********************************************************************** */

ErrVChar err_ext_address_t::to_vchar(ErrPreposition p) const
{
    ErrVChar x;
    format (&x, p);
    return x;
}

/* ********************************************************************** */
/* Groups */

int err_group (char const *name)
{
    name= err_string2symbol (name);

    int id= err_group_ids.find (name);
    if (id == 0) {
        id= group_counter << C_TAG_GROUP_SHIFT;
        err_group_ids.insert   (name, id);
        err_group_names.insert (id, name);
        group_counter++;
    }
    return id;
}

/* ********************************************************************** */
/* Subsystems */

int err_subsystem (char const *name)
{
    name= err_string2symbol (name);

    int id= err_subsystem_ids.find (name);
    if (id == 0) {
        id= subsystem_counter << C_TAG_SUBSYSTEM_SHIFT;
        err_subsystem_ids.insert   (name, id);
        err_subsystem_names.insert (id, name);
        subsystem_counter++;
    }
    return id;
}

int err_declare_subsystem (char const *name)
{
    return err_subsystem (name);
}

/* ********************************************************************** */
/* printing */

static inline void err_output_to_file (FILE *f, char const *text)
{
    if (f && text) {
        ERR_IF_DEBUG_SHOW(fprintf (stderr, "DEBUG:ERR: fputs '%s'.\n", text));

        fputs (text, f);
        fflush (f); // we display error messages: these are always displayed immediately.
    }
    else
        ERR_IF_DEBUG_FILTER(fprintf (stderr, "DEBUG:ERR: no fputs '%s'.\n", text));
}

static char *err_realloc (char *old, int len)
{
    if (old == NULL)
        return (char*)malloc (len);
    else
        return (char*)realloc((void *)old, len);
}

static void err_do_print (
    ErrFormattedStream *s, int tag, int orig_tag, int number, int, char const *text)
{
    ErrVChar full_text_v;
    ERR_IF_DEBUG_SHOW(
        fprintf (stderr,
            "DEBUG:ERR: printing into stream %s: tag=%s\n"
            "\tnumber=%d, orig_tag=%s\n"
            "\ttext:'%s'.\n",
            s->name,
            err_tag_full_description (tag).as_array(),
            number,
            err_tag_full_description (orig_tag).as_array(),
            text));

    err_symtab_t *remember_once= err_is_printed_once_set_last (s, orig_tag, number);
    if (remember_once == NULL) {
        ERR_IF_DEBUG_SHOW2(
            fprintf (stderr, "no remember_once table\n"));
    }
    else {
        char const *full_text= text;

        ERR_IF_DEBUG_SHOW2(
            fprintf (stderr, "using remember_once table %p\n", remember_once));

        if (tag == C_TAG_MORE) {
            // The prefix was not printed.  To decide whether to print this,
            // we must take into account the whole message, not only the
            // piece we just got:
            full_text_v.append (s->status.last_sym);
            full_text_v.append (text);
            full_text= full_text_v;
            ERR_IF_DEBUG_SHOW2(
                fprintf (stderr,
                    "DEBUG:ERR: tag=more, testing full message: '%s'.\n",
                    full_text));

        }

        err_symbol_t sym= err_symtab_ensure (remember_once, full_text);
        s->status.last_sym= sym;

        if (tag == C_TAG_MORE && s->status.last_sym_printed) {
            ERR_IF_DEBUG_SHOW2(
                fprintf (stderr,
                    "DEBUG:ERR: tag=more, last was printed -> print.\n"));
            goto do_print;
        }
        else
            text= full_text; // if we decide to print now, we must print the prefix, too,
                             // since it was not printed.

        if (err_map_errno != ERR_MAP_OK) {
            ERR_IF_DEBUG_FILTER(
                fprintf (stderr, "DEBUG:ERR: not printing again in stream %s: '%s'.\n",
                    s->name, text));
            s->status.last_sym_printed= ERR_FALSE;
            return; // already present, so exit.
        }
        s->status.last_sym_printed= ERR_TRUE;
    }

do_print:
    if (err_string_cmp (s->status.last, text) == 0) {
        ERR_IF_DEBUG_FILTER(
            fprintf (stderr, "DEBUG:ERR: same as last on stream %s: '%s'.\n",
                s->name, text));
        s->status.count++;
    }
    else {
        if (s->status.count > 0) {
            ErrVChar more_text;
            switch (s->status.count) {
            case 1:
                more_text.format ("This message was repeated once.\n");
                break;
            case 2:
                more_text.format ("This message was repeated twice.\n");
                break;
            default:
                more_text.format ("This message was repeated %d times.\n", s->status.count);
            }

            if (s->style == NULL)
                err_output_to_file (s->file, more_text);
            else {
                ErrMsgInfo info;
                ErrLocation loc;

                err_v_char_t *message1;
                err_v_char_t *message2;
                err_v_char_t *message=
                    err_format (s, message1, message2, s->style,
                                ERR_TAG_MORE, s->status.last_tag, ErrNumber(0),
                                info, loc, more_text);

                err_output_to_file (s->file, err_v_char_as_array (message));

                err_v_char_delete (message2);
                err_v_char_delete (message1);
            }
        }

        ERR_IF_DEBUG_SHOW(
            fprintf (stderr, "DEBUG:ERR: output to file on stream %s: '%s'.\n",
                s->name, text));

        err_output_to_file (s->file, text);
        s->status.count= 0;
        s->status.last= strcpy (err_realloc (s->status.last, strlen (text) + 1), text);
        s->status.last_tag= orig_tag;
    }

    /*err-skip*/err_do_count (tag, number, ERR_STATUS_PRINTED);
}

static void err_do_show_message (
    int tag, int orig_tag, int number, int orig_number,
    err_msg_info_t const &info,
    err_location_t const *loc,
    char const *text)
{
    ERR_IF_DEBUG_SHOW(fprintf (stderr, "DEBUG:ERR: showing '%s'.\n", text));

    ErrVStream *v;
    v= streams.find (ERR_PURE_TAG (orig_tag));
    if (v == NULL || v->empty()) {
        ERR_IF_DEBUG_FILTER(fprintf (stderr, "DEBUG:ERR: no stream for '%s'.\n", text));
    }
    else {
        ErrFormattedStream *s;
        err_vector_forall_values (v, s) {
            if (!err_is_printed_set_last (s, tag, number)) {
                ERR_IF_DEBUG_FILTER(
                    fprintf (stderr, "DEBUG:ERR: not printing in stream %s: '%s'.\n",
                        s->name, text));
            }
            else {
                if (s->style == NULL) {
                    ERR_IF_DEBUG_SHOW(
                        fprintf (stderr, "DEBUG:ERR: no style for '%s'.\n", text));
                    err_do_print (s, tag, orig_tag, number, orig_number, text);
                }
                else {
                    err_v_char_t *message1;
                    err_v_char_t *message2;
                    err_v_char_t *message=
                        err_format (s, message1, message2,
                                    s->style, tag, orig_tag, orig_number, info, loc, text);

                    ERR_IF_DEBUG_SHOW2(
                        fprintf (stderr, "DEBUG:ERR: formatted, loc valid=%d.\n",
                            loc->valid()));
                    ERR_IF_DEBUG_SHOW(
                        fprintf (stderr, "DEBUG:ERR: formatted using style %s: '%s'.\n",
                            s->style->name, err_v_char_as_array (message)));

                    err_do_print (
                        s, tag, orig_tag, number, orig_number, err_v_char_as_array (message));

                    err_v_char_delete (message2);
                    err_v_char_delete (message1);
                }
            }
        }
    }

    /*err-skip*/err_do_count (tag, number, ERR_STATUS_SHOWN);
}

static void err_do_distribute (
    int tag, int orig_tag, int number, int orig_number, err_msg_info_t const &info,
    err_location_t const *loc,
    char const *text)
{
    ERR_IF_DEBUG_SHOW(fprintf (stderr, "DEBUG:ERR: distributing '%s'.\n", text));

    ErrFormattedCallback *cb= err_subsystem_callback_find (orig_tag);

    return_if_null2 (loc, text);
    ERR_BOOL cont= true;
    int show_count= 1;
    if (cb) {
        cont= false;
        cb->invoke  (&cont, &show_count, tag, orig_tag, orig_number, info, loc, text);
    }

    if (!cont) {
        ERR_IF_DEBUG_FILTER(fprintf (stderr, "DEBUG:ERR: not distributing: '%s'.\n", text));
    }
    else {
        err_invoke_callbacks_before (&show_count, tag, orig_tag, orig_number, info, loc, text);
        if (*text && show_count > 0)
            err_do_show_message (tag, orig_tag, number, orig_number, info, loc, text);
        else {
            ERR_IF_DEBUG_FILTER(fprintf (stderr, "DEBUG:ERR: not showing: '%s'.\n", text));
        }
        err_invoke_callbacks_after  (&show_count, tag, orig_tag, orig_number, info, loc, text);

        /*err-skip*/err_do_count (tag, number, ERR_STATUS_DISTRIBUTED);
    }
}

void err_set_resolve_address (void (*resolve)(int, int, int, err_position_t *))
{
    return_if_null (resolve);
    err_user_resolve_address= resolve;
}

void err_unset_resolve_address (void)
{
    err_user_resolve_address= NULL;
}

static bool err_needs_resolving (err_position_t const *loc)
{
    return0_if_null (loc);
    return loc->address != NULL && loc->file == NULL;
}

static bool err_needs_resolving (err_area_t const *loc)
{
    return0_if_null (loc);
    return err_needs_resolving (&loc->first) ||
           err_needs_resolving (&loc->last);
}

static bool err_needs_resolving (err_location_t const *loc)
{
    if (loc == NULL)
        return false;
    return err_needs_resolving (&loc->here) ||
           err_needs_resolving (&loc->orig) ||
           err_needs_resolving (loc->next_loc);
}

static bool err_resolve_address (int tag, int orig_tag, int number, err_position_t *loc)
{
    return0_if_null (loc);
    if (err_needs_resolving (loc)) {
        if (err_user_resolve_address) {
            err_user_resolve_address (tag, orig_tag, number, loc);
            if (err_needs_resolving (loc))
                loc->address->resolve (tag, orig_tag, number, loc);
        }
        else
            loc->address->resolve (tag, orig_tag, number, loc);
        return loc->file != NULL;
    }
    return false;
}

static bool err_resolve_address (
    int tag, int orig_tag, int number, err_area_t *loc)
{
    return0_if_null (loc);
    bool change= false;
    change|= err_resolve_address (tag, orig_tag, number, &loc->first);
    change|= err_resolve_address (tag, orig_tag, number, &loc->last);
    return change;
}

static int err_address_resolve_incarnation= 0;

static bool err_resolve_address_aux (
    int tag, int orig_tag, int number, err_location_t *loc)
{
    bool change= false;
    if (loc) {
        // Do not put these into one expression, since we need all ones
        // to be called regardless of what the first one returns!
        change|= err_resolve_address     (tag, orig_tag, number, &loc->here);
        change|= err_resolve_address     (tag, orig_tag, number, &loc->orig);
        change|= err_resolve_address_aux (tag, orig_tag, number, loc->next_loc);
    }
    return change;
}

err_location_t const *err_resolve_address (
    int tag, int orig_tag, int number, err_location_t const *loc)
{
    if (err_address_resolve_incarnation == 0) {
        err_address_resolve_incarnation++;

        if (loc && err_needs_resolving (loc)) {
            static err_location_t result;
            result= *loc;
            if (err_resolve_address_aux (tag, orig_tag, number, &result))
                loc= &result;
        }

        err_address_resolve_incarnation--;
    }

    return loc;
}

void err_do_issue (
    int tag, int orig_tag, int number, int orig_number, err_msg_info_t const &info,
    err_location_t const *loc, char const *text)
{
    return_if_fail_pxx (tag == C_TAG_MORE || ERR_SINGLE_TAG (tag), tag, ERR_PURE_TAG (tag));
    return_if_fail_pxx (ERR_SINGLE_TAG (orig_tag), orig_tag, ERR_PURE_TAG (orig_tag));

    ERR_IF_DEBUG_SHOW(fprintf (stderr, "DEBUG:ERR: issuing '%s'.\n", text));
    
    ERR_IF_DEBUG_SHOW2(
        fprintf (stderr, "DEBUG:ERR: loc=%p, loc->valid()=%d, file=%s, address=%p ('%s').\n",
            loc, loc && loc->valid(),
            loc->here.first.file,
            loc->here.first.address,
            +loc->here.first.address->to_vchar()));

    loc= err_resolve_address (tag, orig_tag, orig_number, loc);

    ERR_IF_DEBUG_SHOW2(
        fprintf (stderr, "DEBUG:ERR: loc=%p, loc->valid()=%d, file=%s, address=%p ('%s').\n",
            loc, loc && loc->valid(),
            loc->here.first.file,
            loc->here.first.address,
            +loc->here.first.address->to_vchar()));

    if (err_do_buffer (tag, orig_tag, orig_number, info, loc, text)) {
        ERR_IF_DEBUG_FILTER(fprintf (stderr, "DEBUG:ERR: buffering '%s'.\n", text));
    }
    else
        err_do_distribute (tag, orig_tag, number, orig_number, info, loc, text);

    /*err-skip*/err_do_count (tag, number, ERR_STATUS_ISSUED);
}

/* ********************************************************************** */
/* printing */

ERR_ERWIN_BOOL /*err_skip*/err_is_seen (int tag, int num)
{
    unless (/*err-skip*/err_is_issued (tag, num) &&
            /*err-skip*/err_is_shown  (tag, num) &&
            /*err-skip*/!err_is_buffered (tag, num))
    {
        return ERR_ERWIN_FALSE;
    }

    ErrVStream *v;
    v= streams.find (ERR_PURE_TAG (tag));
    if (v) {
        ErrFormattedStream *s;
        err_vector_forall_values (v, s)
            if (err_is_printed (s->file, tag, num))
                return ERR_ERWIN_TRUE;
    }

    return ERR_ERWIN_FALSE;
}

static int last_tag= 0;
static int last_number= 0;

static void err_exit_or_abort (int tag)
{
    if (tag == C_TAG_MORE)
        tag= last_tag;

    if (tag & C_TAG_VARIANT)
        return;

    switch (ERR_PURE_TAG (tag)) {
    case C_TAG_FATAL:
        exit (EXIT_FAILURE);
    case C_TAG_ASSERT:
        err_crash ();
    }
}

static void append_cr_perhaps (ErrVChar &message)
{
    message.chomp ();
    if (message.empty() || message.last() != '\n')
        message.append ("\n");
}

static ErrVChar err_prefix_buffer;
static ErrVChar err_suffix_buffer;
static ErrLocation err_next_location;

void err_set_next_location (err_location_t const *loc)
{
    err_next_location= *loc;
}

void err_erase_prefix (void)
{
    err_prefix_buffer.clear();
    err_next_location= ErrLocation ();
}

void err_erase_suffix (void)
{
    err_suffix_buffer.clear();
}

char const *err_group_get_prefix (int tag)
{
    return err_group_prefix.find (tag & C_TAG_GROUP_MASK);
}

void err_group_set_prefix (int tag, char const *str)
{
    tag &= C_TAG_GROUP_MASK;

    char *c= err_group_prefix.find (tag);
    err_string_free (c);
    err_group_prefix.erase (tag);

    if (str)
        err_group_prefix.insert (tag, err_string_dup (str));
}

static bool valid_format (char const *s)
{
     return s && *s && !(s[0] == '\1' && s[1] == '\0');
}

/* va version */
/* This is the basic function.  All others use this one. */
int /*err-skip*/ voleprintf (
    int tag, int number,
    int options,
    err_location_t const *loc,
    char const *format, va_list va)
{
    // "" is the same as NULL: it means not to show any message, but
    // only to invoke the callbacks.
    unless (valid_format(format))
        format= "";

#ifndef err_force_fprintf
    if (err_force_fprintf) {
        if (format) {
            int i= vfprintf (stderr, format, va);
            if ((i > 0 && strlen(format) == 0) || format[strlen(format)-1] != '\n') {
                int o= fprintf(stderr, "\n");
                if (o > 0)
                    i+= o;
            }
            return i;
        }
    }
#endif

    int result= 0;
    int progress_level= 0;

    ERR_IF_DEBUG_SHOW(fprintf (stderr, "DEBUG:ERR: ***** received %s, number %d:\n\ttext:'%s'.\n",
         err_tag_full_description (tag).as_array(),
         number,
         format));

    // allow the printf group to be invoked without previous err_init()
    if (err_initialised == 0) {
        err_init (NULL, NULL);
#ifdef ERR_HAVE_STDERR
        err_add_stream (C_TAG_ALL, stderr, err_style_plain);
#endif
    }

    progress_level= 0;
    if (ERR_PURE_TAG(tag) == C_TAG_PROGRESS ||
        (tag == C_TAG_MORE && ERR_PURE_TAG(last_tag) == C_TAG_PROGRESS))
    {
        progress_level= 1;
        while (*format == '.') {
            progress_level++;
            format++;
        }
    }

    if (err_initialised == 1) {
        // initialisation running, but not completed.  => we cannot use the data
        // structures of this library but must instead use fprintf family (if
        // we did not redefine that...)

#ifndef ERR_HAVE_STDERR
        err_crash();
#else
        if (err_printf_incarnation2 != 0) {
            fputs ("**** Unknown severe internal error while initialising liberror.\n", stderr);
        }
        else {
            err_printf_incarnation2++;  // we have our own recursion protection counter.

            // I hope we can report this problem, otherwise there's a problem.
            char const *tag_str=
                err_tag_string (tag == C_TAG_MORE ? last_tag : tag);

#ifdef ERR_REPLACE_PRINTF
            // If we redefined fprintf family, we must try to use our own Erwin
            // library, which might fail again.  But we have a recursion
            // protection.
            ErrVChar text;
            text.format ("*** Error while initialising liberror:\n");
            if (tag_str)
                text.format (" %s: ", tag_str);

            if (valid_format(format)) {
                result= text.vformat (text, format, va);
                append_cr_perhaps (text);
                err_output_to_file (stderr, text);
            }
#else
            fprintf (stderr, "*** Error while initialising liberror:\n");
            if (tag_str)
                fprintf (stderr, "%s: ", tag_str);
            result= vfprintf (stderr, format, va);
#endif /* defined(ERR_REPLACE_PRINTF) */
            err_printf_incarnation2--;
        }
#endif /* !defined(ERR_HAVE_STDERR) */
         err_exit_or_abort (tag);
    }
    else
    if (err_printf_incarnation == 0 ||
        (err_printf_incarnation == 1 && err_address_resolve_incarnation == 1))
    {       // This is necessary because assertion failures inside this
            // function produce an infinite recursion otherwise.
            
        err_printf_incarnation++;

        if (tag == C_TAG_PREFIX) {
            ERR_IF_DEBUG_SHOW(
                fprintf (stderr, "DEBUG:ERR: setting prefix '%s'.\n", format));

            err_prefix_buffer.vformat (options, format, va);
            ERR_IF_DEBUG_SHOW2(
                fprintf (stderr, "DEBUG:ERR: loc=%p, loc->valid()=%d, address=%p, next_valid()=%d (file=%s, address=%p).\n",
                    loc,
                    loc && loc->valid(),
                    loc ? loc->here.first.address : NULL,
                    err_next_location.valid(),
                    err_next_location.here.first.file,
                    err_next_location.here.first.address));

            if (loc && loc->valid() && !err_next_location.valid()) {
                ERR_IF_DEBUG_SHOW2(
                    fprintf (stderr, "DEBUG:ERR: setting next err location.\n"));
                err_set_next_location (loc);
            }
        }
        else
        if (tag == C_TAG_SUFFIX) {
            ERR_IF_DEBUG_SHOW(
                fprintf (stderr, "DEBUG:ERR: setting suffix '%s'.\n", format));

            err_suffix_buffer.vformat (options, format, va);
        }
        else {
            /*err-skip*/err_do_count (tag, number, ERR_STATUS_RECEIVED);

            bool user_wants_issue_p= true;
            bool issue_p= (err_progress_level < 0 || err_progress_level >= progress_level) &&
                          err_is_issued_set_last (user_wants_issue_p, tag, number);
            int last_last_tag=     last_tag;
            int last_last_number=  last_number;
            if (tag != C_TAG_MORE) {
                last_tag= tag;
                last_number= number;
            }
            if (!issue_p) {
                ERR_IF_DEBUG_FILTER(
                    fprintf (stderr, "DEBUG:ERR: not issuing '%s', erasing affixes ('%s'-, -'%s').\n",
                        format,
                        +err_prefix_buffer,
                        +err_suffix_buffer));

                // have to delete the affix buffers anyway: they belong to this message.
                if (valid_format(format)) {
                    err_erase_prefix ();
                    err_erase_suffix ();
                }
            }
            else {
                ERR_IF_DEBUG_SHOW(fprintf (stderr, "DEBUG:ERR: may issue '%s'.\n", format));

                bool show_p= err_is_shown_set_last (tag, number);
                if (!show_p) {
                    ERR_IF_DEBUG_FILTER(
                        fprintf (stderr, "DEBUG:ERR: not showing '%s'.\n", format));
                    format= "";
                }
                else
                    ERR_IF_DEBUG_SHOW(fprintf (stderr, "DEBUG:ERR: may show '%s'.\n", format));

                char const *message_str= NULL;
                ErrVChar message;

                if (err_next_location.valid()) {
                    loc= &err_next_location;
                    ERR_IF_DEBUG_SHOW2(
                        fprintf (stderr, "DEBUG:ERR: using next err loc.\n"));
                }
                ERR_IF_DEBUG_SHOW2(
                    fprintf (stderr, "DEBUG:ERR: A: location %p valid=%d.\n",
                         loc, loc && loc->valid()));

                static ErrLocation err_dummy_loc;
                if (loc == NULL)
                    loc= &err_dummy_loc;

                ERR_IF_DEBUG_SHOW2(
                    fprintf (stderr, "DEBUG:ERR: B: location %p valid=%d.\n",
                         loc, loc && loc->valid()));

                if (valid_format(format)) {
                    ERR_IF_DEBUG_FILTER(
                        fprintf (stderr,
                            "DEBUG:ERR: formatting params into '%s', adding & erasing affixes ('%'s-, -'%s'.\n",
                            format,
                            +err_prefix_buffer,
                            +err_suffix_buffer));

                    // print the message:
                    if (char const *p= err_group_get_prefix (tag))
                        message.append (p);

                    message.append (err_prefix_buffer);
                    if (progress_level >= 2)
                        message.format ("%*s- ", 2 * (progress_level - 2), "");
                    message.vformat (options, format, va);
                    message.append (err_suffix_buffer);

#if 0
                    // Do not append "\n" in progress messages that do not
                    // have \n.  This means the user wants the time difference
                    // to be printed.
                    if (ERR_PURE_TAG (tag) == C_TAG_PROGRESS &&
                        (message.nentries() == 0 || message.last() != "\n"))
                    {
                        // Store the time of issue somewhere.  can we simply drop
                        // the trailing \n?
                    }
#endif

                    // always let the error message end in \n:
                    append_cr_perhaps (message);
                    if (!user_wants_issue_p)
                        message.append ("This message cannot be suppressed.\n");
                }
                message_str= message.as_array();
                result= message.nentries();

                // err_erase_prefix (); Must be done manually by the user!
                // err_erase_suffix ();

                ERR_IF_DEBUG_SHOW2(
                    fprintf (stderr, "DEBUG:ERR: C: location %p valid=%d.\n",
                         loc, loc && loc->valid()));

                // issue the message:
                ErrMsgInfo info;
                if (tag == C_TAG_MORE) {
                    int local_last_number= number;
                    if (local_last_number == 0) // If no number was given, use the number
                                                // of the original message.
                        local_last_number= last_last_number;
                    err_do_issue (
                        tag, last_last_tag, number, local_last_number, info, loc, message_str);
                }
                else
                    err_do_issue (tag, tag, number, number, info, loc, message_str);

                /* err_next_location= ErrLocation();
                 * nothing_if_fail (!err_next_location.valid());
                 *    No, wait for err_prefix_erase.
                 */
            }

        }

        err_printf_incarnation--;

        if (tag != C_TAG_FATAL) // could trigger infinite recursion
            err_check_too_many (tag, number);
    }
    else
    if (err_printf_incarnation == 1) {
           // -> assertion failure inside this library.
           // What can we do now??  Simply dump the assertion failure to stderr.

#ifdef ERR_HAVE_STDERR
         err_printf_incarnation++;

         if (valid_format(format)) {
             ErrVChar message;
             message.vformat (options, format, va);
             append_cr_perhaps (message);
             err_output_to_file (stderr, message);
         }

         err_printf_incarnation--;
#endif
         err_exit_or_abort (tag);
         //abort(); // this is bad
    }
    else {
         /* give up.  Even the short emergency code had a failed assertion. */
         err_exit_or_abort (tag);
         //abort(); // this is bad
    }

    return result;
}

/* ********************************************************************** */

#ifdef ERR_REDIR_STDERR
static ErrVChar fprintf_old_text; // for remembring old message suffixes.

static void fprintf_flush ()
{
    if (fprintf_old_text.nentries()) {
        eprintf (fprintf_tag, 0, "%s", fprintf_old_text.as_array());
        fprintf_old_text.clear ();
    }
}
#endif

// Have a nicer version of printf family.  This also catches usage of
// stderr and redirects that to the eprintf family.
int vfoxprintf (FILE *f, int options, char const *format, va_list va)
{
    if (f == NULL || !valid_format(format)) // this is a NULL safe version
        return 0;

#ifndef err_force_fprintf
    if (err_force_fprintf)
        return vfprintf (f, format, va);
#endif

#if defined(ERR_HAVE_STDERR) && defined(ERR_REDIR_STDERR)
    if (f == stderr) {
        // This isn't as easy as you might think:
        //    return voleprintf (fprintf_tag, 0, 0, ErrLocation(), format, va);
        // Instead, we have to split the message onto several lines: each line a
        //          separate message (all but the first with C_TAG_MORE).

        int result= -fprintf_old_text.nentries();

        ErrVChar text;
        text.append (fprintf_old_text);
        fprintf_old_text.clear ();
        text.vformat (options, format, va);

        int tag= fprintf_tag;
        int i;
        char c;
        int old_i= 0;
        err_vector_forall (text, i, c) {
            if (c == '\n') {
                if (i != old_i - 1)
                    result+= eprintf (tag, 0, "%.*s", i - old_i + 1, text.as_array() + old_i);
                old_i= i + 1;
                tag= C_TAG_MORE;
            }
            else
            if (i == text.nentries() - 1) { // last char but not \n
                fprintf_old_text.append_raw (
                    text.as_array() + old_i, i - old_i + 1);
            }
        }

        return result + fprintf_old_text.nentries();
    }
    else
#endif /* defined ERR_HAVE_STDERR */
    {
        ErrVChar text;
        text.vformat (options, format, va);
        if (f) fputs (text, f);
        return text.nentries();
    }
}

int vfxprintf (FILE *f, char const *format, va_list va)
{
    return vfoxprintf (f, 0, format, va);
}

int fxprintf (FILE *f, char const *format, ...)
{
    va_list va;
    va_start (va, format);
    int result= vfoxprintf (f, 0, format, va);
    va_end (va);
    return result;
}

int foxprintf (FILE *f, int options, char const *format, ...)
{
    va_list va;
    va_start (va, format);
    int result= vfoxprintf (f, options, format, va);
    va_end (va);
    return result;
}

#ifdef ERR_HAVE_STDERR

FILE *_err_get_stdout () { return stdout; }
FILE *_err_get_stderr () { return stderr; }

int vxprintf (char const *format, va_list va)
{
    return vfoxprintf (stdout, 0, format, va);
}

int voxprintf (int options, char const *format, va_list va)
{
    return vfoxprintf (stdout, options, format, va);
}

int oxprintf (int options, char const *format, ...)
{
    va_list va;
    va_start (va, format);
    int result= vfoxprintf (stdout, options, format, va);
    va_end (va);
    return result;
}

int xprintf (char const *format, ...)
{
    va_list va;
    va_start (va, format);
    int result= vfoxprintf (stdout, 0, format, va);
    va_end (va);
    return result;
}

#endif /* defined ERR_HAVE_STDERR */

int vsnoxprintf (char *dst, int max, int options, char const *format, va_list va)
{
    if (dst == NULL || format == NULL)
        return 0;
#ifndef err_force_fprintf
    if (err_force_fprintf)
        return vsnprintf (dst, max, format, va);
#endif

    ErrVChar text;
    text.vformat (options, format, va);
    int length= text.nentries();
    strncpy (dst, text.as_array(), max);
    return length;
}

int vsnxprintf (char *dst, int max, char const *format, va_list va)
{
    return vsnoxprintf (dst, max, 0, format, va);
}

int snoxprintf (char *dst, int max, int options, char const *format, ...)
{
    va_list va;
    va_start (va, format);
    int result= vsnoxprintf (dst, max, options, format, va);
    va_end (va);
    return result;
}

int snxprintf (char *dst, int max, char const *format, ...)
{
    va_list va;
    va_start (va, format);
    int result= vsnoxprintf (dst, max, 0, format, va);
    va_end (va);
    return result;
}
