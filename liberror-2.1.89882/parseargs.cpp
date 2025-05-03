// -*- Mode: C++ -*-

#include <string.h>
#include <stdarg.h>

#include "liberror.h"
#include "internal.h"
#include "failure.h"

volatile int err_continue= 0;

ErrEnumValue const err_tag_enum[]= {
    { "banner",                  C_TAG_BANNER                        },
    { "devel-banner",            C_TAG_BANNER    | C_TAG_DEBUG       },

    { "prompt",                  C_TAG_PROMPT                        },
    { "devel-prompt",            C_TAG_PROMPT    | C_TAG_DEBUG       },

    { "progress",                C_TAG_PROGRESS                      },
    { "devel-progress",          C_TAG_PROGRESS  | C_TAG_DEBUG       },

    { "note",                    C_TAG_NOTE                          },
    { "devel-note",              C_TAG_NOTE      | C_TAG_DEBUG       },

    { "info",                    C_TAG_INFO                          },
    { "informational",           C_TAG_INFO                          },
    { "devel-info",              C_TAG_INFO      | C_TAG_DEBUG       },
    { "devel-informational",     C_TAG_INFO      | C_TAG_DEBUG       },

    { "warn",                    C_TAG_WARNING                       },
    { "warning",                 C_TAG_WARNING                       },
    { "devel-warn",              C_TAG_WARNING   | C_TAG_DEBUG       },
    { "devel-warning",           C_TAG_WARNING   | C_TAG_DEBUG       },

    { "err",                     C_TAG_ERROR                         },
    { "error",                   C_TAG_ERROR                         },
    { "devel-err",               C_TAG_ERROR     | C_TAG_DEBUG       },
    { "devel-error",             C_TAG_ERROR     | C_TAG_DEBUG       },

    { "internal",                C_TAG_INTERNAL                      },
    { "devel-internal",          C_TAG_INTERNAL  | C_TAG_DEBUG       },

    { "fatal",                   C_TAG_FATAL                         },
    { "devel-fatal",             C_TAG_FATAL     | C_TAG_DEBUG       },

    { "assert",                  C_TAG_ASSERTION                     },
    { "assertion",               C_TAG_ASSERTION                     },
    { "devel-assert",            C_TAG_ASSERTION | C_TAG_DEBUG       },
    { "devel-assertion",         C_TAG_ASSERTION | C_TAG_DEBUG       },

    { "debug",                                     C_TAG_DEBUG       },

    { "none",                    C_TAG_NONE                          },

    { "unclassified",            C_TAG_UNCLASSIFIED                  },
    { "no-class",                C_TAG_UNCLASSIFIED                  },
    { "no_class",                C_TAG_UNCLASSIFIED                  },
    { "noclass",                 C_TAG_UNCLASSIFIED                  },

    { "all",                     C_TAG_ALL                           },

    { NULL,                      0                                   }
};

ErrEnumValue const err_style_enum[]= {
    { "default",      ERR_STYLE_DEFAULT },
    { "none",         ERR_STYLE_NONE },
    { "simple",       ERR_STYLE_SIMPLE },
    { "plain",        ERR_STYLE_PLAIN },
    { "plain-colon",  ERR_STYLE_COLON },
    { "plain-quotes", ERR_STYLE_QUOTES },
    { "qt",           ERR_STYLE_QT },
    { "qt3",          ERR_STYLE_QT3 },
    { NULL,           0 }
};

static bool is_prefix (int &len, char const *haystack, char const *needle)
{
    return0_if_null2 (haystack, needle);
    len= strlen (needle);
    return err_erwin_strncasecmp (haystack, needle, len) == 0;
}

static bool get_positive (char const *&key)
{
    // possible negation at the beginning
    int len;
    if (is_prefix (len, key, "no-") ||
        is_prefix (len, key, "not-")  ||
        is_prefix (len, key, "dont-"))
    {
        key+= len;
        return false;
    }

    return true;
}

static bool get_positive (bool &error, char const *&key, char const *value, bool must)
{
    bool positive= get_positive (key);

    if (must && value) {
        if (strcmp (value, "0") == 0 ||
            strcmp (value, "no") == 0 ||
            strcmp (value, "false") == 0)
        {
            return !positive;
        }

        if (strcmp (value, "1") == 0 ||
            strcmp (value, "yes") == 0 ||
            strcmp (value, "true") == 0)
        {
            return positive;
        }

        error= true;
        return true;
    }

    return positive;
}

static bool is_opt_bool (
    bool &error,
    bool &result, char const *name,
    char const *key, char const *value, bool must)
{
    bool local_error= false;
    bool positive= get_positive (local_error, key, value, must);
    //int len= strlen (key);

    if (err_erwin_strcasecmp (name, key) != 0)
        return false;

    if (local_error) {
       qeprintf (ERR_TAG_ERROR, 0,
           "Illegal argument %s for option %s.\n"
           "Boolean, i.e., \"0\" or \"1\" expected.\n",
           value, key);
       error= true;
       return true;
    }

    result= positive;
    return true;
}

static bool is_opt_enum (
    bool &error,
    int &result, char const *name,
    char const *key, char const *value, ErrEnumValue const *va)
{
    if (err_erwin_strcasecmp (key, name) != 0)
        return false;

    if (value == NULL) {
        qeprintf (ERR_TAG_ERROR, 0,
           "Option %s requires an argument.\n", key);
        error= true;
        return true;
    }

    ErrVChar possible;
    forever {
        char const *v_name= va->key;
        if (v_name == NULL) {
            qeprintf (ERR_TAG_ERROR, 0,
                "Illegal argument %s for option %s.\n"
                "Good values: %-s.\n",
                value, key,
                possible.as_array());

            error= true;
            break;
        }

        if (!possible.empty())
            possible.append (", ");
        possible.format (ERR_FO_QUOTE_C_STRING, "%s", v_name);

        if (err_erwin_strcasecmp (v_name, value) == 0) {
            result= va->value;
            break;
        }

        va++;
    }

    return true;
}

static bool is_opt_int (
    bool &error,
    int &result, char const *name,
    char const *key, char const *value)
{
    if (err_erwin_strcasecmp (key, name) != 0)
        return false;

    if (value == NULL) {
        qeprintf (ERR_TAG_ERROR, 0,
           "Numeric option %s requires an argument.\n", key);
        error= true;
        return true;
    }

    char *r;
    result= err_erwin_strtol (value, &r, 0);

    if (*r || !*value) {
        qeprintf (ERR_TAG_ERROR, 0,
           "Illegal argument %s for option %s.\n"
           "Expected an integer.\n", value, key);
        error= true;
    }

    return true;
}

static bool is_int (char const *s)
{
    if (!*s)
        return false;
    char *r;
    err_erwin_strtol (s, &r, 0);
    return *r == 0;
}

static bool is_opt_intenum_list (
    bool &error,
    ErrVInt &result_int,
    ErrVInt &result_enum, char const *name,
    char const *key, char const *value, ErrEnumValue const *va)
{
    if (err_erwin_strcasecmp (key, name) != 0)
        return false;

    if (value == NULL) {
        qeprintf (ERR_TAG_ERROR, 0,
           "Option %s requires an argument.\n", key);
        error= true;
        return true;
    }

    char const *r;
    int n;
    forever {
        r= strchr (value, ',');

        ErrVChar part;
        if (r)
            part.append_raw (value, r-value);
        else
            part.append (value);

        if (&result_int && is_int (part)) {
            if (!is_opt_int (error, n, name, key, part))
                return false;
            if (!error)
                result_int.append (n);
        }
        else
        if (&result_enum) {
            if (!is_opt_enum (error, n, name, key, part, va))
                return false;

            if (!error)
                result_enum.append (n);
        }
        else {
            qeprintf (ERR_TAG_ERROR, 0,
               "Illegal argument %s for option %s.\n"
               "Expected an integer.\n", value, key);
            error= true;
            return false;
        }

        if (r == NULL)
            break;

        value= r+1;
    }
    return true;
}

static void err_help (void)
{
    eprintf (C_TAG_BANNER, 0, "Message Library Options\n");
    eprintf (C_TAG_NONE,   0, "\n");

    eprintf (C_TAG_BANNER, 0, "Usage of messages options\n");
    eprintf (C_TAG_NONE, 0,
        "All options either on command line prefixed with --%s, or\n"
        "in the environment variable %s", +err_arg_prefix(0), +err_envvar_global(0));
    if (err_progname())
        eprintf (C_TAG_NONE, 0, "or in %s", +err_envvar_program(0));
    eprintf (C_TAG_NONE, 0, "\n");

    eprintf (C_TAG_BANNER, 0, "Options");
    eprintf (C_TAG_NONE, 0, "\n");

    /////////////////////////
    eprintf (C_TAG_NONE, 0,
            "   help\n");
    eprintf (C_TAG_MORE, 0,
            "       Displays this help text.\n");
    eprintf (C_TAG_MORE, 0, "\n");

    /////////////////////////
    eprintf (C_TAG_NONE, 0,
            "   version\n");
    eprintf (C_TAG_MORE, 0,
            "       Displays the library's version number.\n");
    eprintf (C_TAG_MORE, 0, "\n");

    /////////////////////////
#if !defined(NDEBUG) && !defined(RELEASE)
    eprintf (C_TAG_NONE, 0,
            "   segfault / sigsegv / crash\n");
    eprintf (C_TAG_MORE, 0,
            "       Artificially produce a segmentation fault.\n");
    eprintf (C_TAG_MORE, 0, "\n");

    eprintf (C_TAG_NONE, 0,
            "   assert0\n");
    eprintf (C_TAG_MORE, 0,
            "       Artificially produce an assertion failure.\n");
    eprintf (C_TAG_MORE, 0, "\n");

    eprintf (C_TAG_NONE, 0,
            "   forever\n");
    eprintf (C_TAG_MORE, 0,
            "       Loop forever until the variable err_continue is manually\n"
            "       set to 1 (e.g. in the debugger).\n");
    eprintf (C_TAG_MORE, 0, "\n");
#endif

    /////////////////////////
    eprintf (C_TAG_NONE, 0,
            "   colourise= { 0, 1, tty }\n");
    eprintf (C_TAG_MORE, 0,
            "       Whether to use ANSI colour control characters.\n");
    eprintf (C_TAG_MORE, 0,
            "       Example: --%scolourise=tty\n", +err_arg_prefix(0));
    eprintf (C_TAG_MORE, 0, "\n");

    /////////////////////////
    eprintf (C_TAG_NONE, 0,
            "   progress-level= INT\n");
    eprintf (C_TAG_MORE, 0,
            "       Progress levels are hierarchically ordered: a progress message\n"
            "       may be followed by a lot of sub-progress messages, each of which\n"
            "       may be followed by sub-sub-progress messages.  The levels are\n"
            "       indicated in the output by indentation levels. This option\n"
            "       defines the level of progress messages that are shown.  A level less\n"
            "       than zero means all.  Zero means none, one means top-level progress\n"
            "       messages only, etc.\n");
    eprintf (C_TAG_MORE, 0, "\n");

    /////////////////////////
    eprintf (C_TAG_NONE, 0,
            "   fatal-count= INT\n");
    eprintf (C_TAG_MORE, 0,
            "       Sets the error fatal counter for errors and internal errors to the\n"
            "       given value, i.e., a fatal error (probably resulting in immediate\n"
            "       program termination) will be generated after the given number of\n"
            "       errors.\n");
    eprintf (C_TAG_MORE, 0, "\n");

    /////////////////////////
    eprintf (C_TAG_NONE, 0,
            "   show-pid / no-show-pid / hide-pid / no-hide-pid\n");
    eprintf (C_TAG_MORE, 0,
            "       Whether to show the process id (PID) (Unix only).\n");
    eprintf (C_TAG_MORE, 0,
            "       Example: --%sshow-pid\n", +err_arg_prefix(0));
    eprintf (C_TAG_MORE, 0, "\n");

    /////////////////////////
    eprintf (C_TAG_NONE, 0,
            "   no-show-time / hide-time \n"
            "   show-time = { 0, 1, progress }\n");
    eprintf (C_TAG_MORE, 0,
            "       Whether to show the time in error messages.  'progress' means to\n"
            "       only show the time in progress messages.\n");
    eprintf (C_TAG_MORE, 0,
            "       Example: --%sshow-time=progress\n", +err_arg_prefix(0));
    eprintf (C_TAG_MORE, 0, "\n");

    eprintf (C_TAG_NONE, 0,
            "   show-date / no-hide-date \n"
            "   show-date = { 0, 1 }\n");
    eprintf (C_TAG_MORE, 0,
            "       Whether to show the date also when showing the time\n"
            "       in error messages.\n");
    eprintf (C_TAG_MORE, 0,
            "       Example: --%sshow-date=1\n", +err_arg_prefix(0));
    eprintf (C_TAG_MORE, 0, "\n");

#ifdef ERR_WITH_HOSTNAME
    // Only when configured, this will really work.
    /////////////////////////
    eprintf (C_TAG_NONE, 0,
            "   show-host-name / no-show-host-name / hide-host-name / no-hide-host-name\n");
    eprintf (C_TAG_MORE, 0,
            "       Whether to show the hostname (Unix only):\n");
    eprintf (C_TAG_MORE, 0,
            "       Example: --%sno-show-host\n", +err_arg_prefix(0));
    eprintf (C_TAG_MORE, 0, "\n");
#endif

    /////////////////////////
    eprintf (C_TAG_NONE, 0,
            "   style= STYLE\n");
    eprintf (C_TAG_MORE, 0,
            "       Change the default style:\n"
            "           STYLE= { none, simple, plain, plain-colon, plain-quotes, qt, qt3 }\n");
    eprintf (C_TAG_MORE, 0,
            "       Example: --%sstyle=plain\n", +err_arg_prefix(0));
    eprintf (C_TAG_MORE, 0, "\n");

    /////////////////////////
    eprintf (C_TAG_NONE, 0,
            "   style:NAME= STYLE\n");
    eprintf (C_TAG_MORE, 0,
            "       Set the style of a specific stream:\n"
            "           NAME: the name of the stream\n");
    eprintf (C_TAG_MORE, 0,
            "       Example: --%sstyle:stderr=plain\n", +err_arg_prefix(0));
    eprintf (C_TAG_MORE, 0, "\n");

    /////////////////////////
    eprintf (C_TAG_NONE, 0,
            "   sub-style= { colon, quotes }\n");
    eprintf (C_TAG_MORE, 0,
            "       Set the sub-style of plain, qt and qt3 styles:\n"
            "       Example: --%ssub-style=quotes\n", +err_arg_prefix(0));
    eprintf (C_TAG_MORE, 0, "\n");

    /////////////////////////
    eprintf (C_TAG_NONE, 0,
            "   color-plain= COLOR_SPEC_LIST\n");
    eprintf (C_TAG_MORE, 0,
            "       Change control sequences that are used for colourising:\n"
            "           COLOR_SPEC_LIST= list of COLOR_SPEC separated by colons (:)\n"
            "           COLOR_SPEC: {\n"
            "               TYPE.clear,\n"
            "               TYPE.ACTION\n"
            "           }\n"
            "           TYPE: {\n"
            "              prefix,\n"
            "              suffix,\n"
            "              off,\n"
            "              prefix.off,\n"
            "              suffix.off,\n"
            "              [-]TAG_LIST.[-]PART_LIST\n"
            "              [-]TAG_LIST.[-]PART_LIST.off\n"
            "           }\n"
            "           ACTION: {\n"
            "              .clear,\n"
            "              =STRING\n"
            "           }\n"
            "           TAG_LIST: list of TAG separated by commas\n"
            "           TAG: { assert, fatal, internal, error, warn, info, note\n"
            "                  progress, banner, debug, none, noclass, all\n"
            "           }\n"
            "           PART_LIST: list of PART separated by commas\n"
            "           PART: { location, progname, tag, address, body, space }\n"
            );
    eprintf (C_TAG_MORE, 0,
            "       This is very complex: you can redefine the messages to use\n"
            "       a completely different mark-up.\n");
    eprintf (C_TAG_MORE, 0,
            "       Example: --%scolor-plain=note.tag=32\n"
            "           (makes the tag part of info messages green on some machines)\n",
            +err_arg_prefix(0));
    eprintf (C_TAG_MORE, 0, "\n");

    /////////////////////////
    eprintf (C_TAG_NONE, 0,
            "   quiet= INT\n");
    eprintf (C_TAG_NONE, 0,
            "   quiet-devel= INT\n");
    eprintf (C_TAG_MORE, 0,
            "       Increase the default quiet level:\n");
    eprintf (C_TAG_MORE, 0,
            "       The default is 0.\n"
            "          1 disables banner and progress messages,\n"
            "          2 disables notes, too,\n"
            "          3 disables informational messages, too,\n"
            "          4 disables warnings, too,\n"
            "          5 disables errors and internal errors, too,\n"
            "          6 disables fatal errors and assertion failure messages, too.\n");
    eprintf (C_TAG_MORE, 0, "       Example: --%squiet=2\n", +err_arg_prefix(0));
    eprintf (C_TAG_MORE, 0, "\n");

    /////////////////////////
    eprintf (C_TAG_NONE, 0,
            "   quiet:NAME= INT\n");
    eprintf (C_TAG_NONE, 0,
            "   quiet-devel:NAME= INT\n");
    eprintf (C_TAG_MORE, 0,
            "       Increase the quiet level of a specific stream:\n"
            "           NAME: the name of the stream\n"
            "       The -devel form sets the level for developer messages.\n");
    eprintf (C_TAG_MORE, 0,
            "       Example: --%squiet:report=1\n", +err_arg_prefix(0));
    eprintf (C_TAG_MORE, 0, "\n");

    /////////////////////////
    eprintf (C_TAG_BANNER, 0,
            "   Message filtering");
    eprintf (C_TAG_NONE, 0,
            "       {show, hide, issue, suppress}=           MESSAGE_OR_NUMBER_LIST\n"
            "       {show, hide, issue, suppress}-subsystem= SUBSYSTEM_LIST\n"
            "       {show, hide, issue, suppress}-group=     GROUP_LIST\n"
            "           All lists separated by commas\n");
    eprintf (C_TAG_MORE, 0,
            "       Suppression makes the program ignore the message in counting\n"
            "       and action handling; hiding only prevents the message to be\n"
            "       printed.  Fatal errors and assertion failure messages cannot be\n"
            "       suppressed.\n");
    eprintf (C_TAG_MORE, 0,
            "       Examples: --%shide=23,24,25\n", +err_arg_prefix(0));
    eprintf (C_TAG_MORE, 0,
            "                 --%shide=banner,internal\n", +err_arg_prefix(0));
    eprintf (C_TAG_MORE, 0,
            "                 --%ssuppress-subsystem=lexer\n", +err_arg_prefix(0));
    eprintf (C_TAG_MORE, 0, "\n");
}

int err_process_option (char const *key, char const *value, ERR_ERWIN_BOOL must)
{
    bool error= false;
    int n;

    // colorize
    {
        char const *local_key= key;
        if (!get_positive (local_key) &&
            (err_erwin_strcasecmp (local_key, "colorize") == 0 ||
             err_erwin_strcasecmp (local_key, "colourize") == 0 ||
             err_erwin_strcasecmp (local_key, "colorise") == 0 ||
             err_erwin_strcasecmp (local_key, "colourise") == 0))
        {
            err_style_plain_color= ERR_STYLE_COLOR_NEVER;
            return 1;
        }
    }
    {
        static ErrEnumValue const values[]= {
            { "0",      ERR_STYLE_COLOR_NEVER  },
            { "no",     ERR_STYLE_COLOR_NEVER  },
            { "never",  ERR_STYLE_COLOR_NEVER  },
            { "false",  ERR_STYLE_COLOR_NEVER  },
            { "1",      ERR_STYLE_COLOR_ALWAYS },
            { "yes",    ERR_STYLE_COLOR_ALWAYS },
            { "true",   ERR_STYLE_COLOR_ALWAYS },
            { "always", ERR_STYLE_COLOR_ALWAYS },
            { "iftty",  ERR_STYLE_COLOR_IF_TTY },
            { "if-tty", ERR_STYLE_COLOR_IF_TTY },
            { "if_tty", ERR_STYLE_COLOR_IF_TTY },
            { "tty",    ERR_STYLE_COLOR_IF_TTY },
            { NULL,     0 }
        };
        if (is_opt_enum (error, err_style_plain_color, "colorize",  key, value, values) ||
            is_opt_enum (error, err_style_plain_color, "colourize", key, value, values) ||
            is_opt_enum (error, err_style_plain_color, "colorise",  key, value, values) ||
            is_opt_enum (error, err_style_plain_color, "colourise", key, value, values))
            return error ? 0 : 2;
    }

    // show-time
    {
        char const *local_key= key;
        if (!get_positive (local_key) &&
            (err_erwin_strcasecmp (local_key, "show-time") == 0))
        {
            err_style_plain_show_time= ERR_STYLE_TIME_NEVER;
            return 1;
        }
        if (get_positive (local_key) &&
            (err_erwin_strcasecmp (local_key, "hide-time") == 0))
        {
            err_style_plain_show_time= ERR_STYLE_TIME_NEVER;
            return 1;
        }
    }
    {
        static ErrEnumValue const values[]= {
            { "0",           ERR_STYLE_TIME_NEVER  },
            { "no",          ERR_STYLE_TIME_NEVER  },
            { "never",       ERR_STYLE_TIME_NEVER  },
            { "false",       ERR_STYLE_TIME_NEVER  },
            { "1",           ERR_STYLE_TIME_ALWAYS },
            { "yes",         ERR_STYLE_TIME_ALWAYS },
            { "true",        ERR_STYLE_TIME_ALWAYS },
            { "always",      ERR_STYLE_TIME_ALWAYS },
            { "ifprogress",  ERR_STYLE_TIME_PROGRESS },
            { "if-progress", ERR_STYLE_TIME_PROGRESS },
            { "if_progress", ERR_STYLE_TIME_PROGRESS },
            { "progress",    ERR_STYLE_TIME_PROGRESS },
            { NULL,     0 }
        };
        if (is_opt_enum (error, err_style_plain_show_time, "show-time",  key, value, values))
            return error ? 0 : 2;
    }

    // show date
    {
        bool x;
        if (is_opt_bool (error, x, "show-date", key, value, must)) {
        found_date:
            if (error)
                return 0;
            else {
                err_style_plain_show_date= x;
                return 1;
            }
        }
        else
        if (is_opt_bool (error, x, "hide-date", key, value, must)) {
            x= !x;
            goto found_date;
        }
    }

    // show pid
    {
        bool x;
        if (is_opt_bool (error, x, "show-pid", key, value, must)) {
        found_pid:
            if (error)
                return 0;
            else {
                err_style_plain_show_pid= x;
                return 1;
            }
        }
        else
        if (is_opt_bool (error, x, "hide-pid", key, value, must)) {
            x= !x;
            goto found_pid;
        }
    }

    // progress level
    {
        int x;
        if (is_opt_int (error, x, "progress-level", key, value)) {
            if (error)
                return 0;
            else {
                err_progress_level= x;
                return 1;
            }
        }
    }

    // fatal count
    {
        int x;
        if (is_opt_int (error, x, "fatal-count", key, value)) {
            if (error)
                return 0;
            else {
                err_set_fatal_count (ERR_STATUS_DISTRIBUTED, C_TAG_ERROR,    x);
                err_set_fatal_count (ERR_STATUS_DISTRIBUTED, C_TAG_INTERNAL, x);
                return 1;
            }
        }
    }

    // show hostname
    {
        bool x;
        if (is_opt_bool (error, x, "show-host-name", key, value, must) ||
            is_opt_bool (error, x, "show-hostname", key, value, must) ||
            is_opt_bool (error, x, "show-host", key, value, must))
        {
        found_host:
            if (error)
                return 0;
            else {
                err_style_plain_show_hostname= x;
                return 1;
            }
        }
        else
        if (is_opt_bool (error, x, "hide-host-name", key, value, must) ||
            is_opt_bool (error, x, "hide-hostname", key, value, must) ||
            is_opt_bool (error, x, "hide-host", key, value, must))
        {
            goto found_host;
        }
    }

    // default style
    {
        int x;
        if (is_opt_enum (error, x, "style", key, value, err_style_enum)) {
            if (x == ERR_STYLE_DEFAULT) {
                eprintf (C_TAG_ERROR, 0,
                    "Error style 'default' is illegal as default style.\n");
                return 0;
            }
            err_style_default_redirect= x;
            return error ? 0 : 2;
        }
    }

    // sub-style (style that plain is redirected to)
    {
        static ErrEnumValue const values[]= {
            { "colon",  ERR_STYLE_PLAIN_COLON },
            { "quotes", ERR_STYLE_PLAIN_QUOTES },
            { NULL,     0 }
        };
        if (is_opt_enum (error, err_style_plain_redirect, "sub-style", key, value, values) ||
            is_opt_enum (error, err_style_plain_redirect, "substyle",  key, value, values))
            return error ? 0 : 2;
    }

    // stream-style for special streams:
    // fprintf (stderr, "DEBUG: key='%s', value='%s'\n", key, value);
    {
        if (is_prefix (n, key, "style:")) {
            char const *name= key + n;
            int x;
            if (is_opt_enum (error, x, NULL, NULL, value, err_style_enum)) {
                //fprintf (stderr, "DEBUG: style '%s' = %d\n", value, x);
                if (error)
                    return 0;
                else {
                    err_formatted_stream_t *stream= err_get_stream_by_name (name);
                    return0_if_null (stream);
                    //fprintf (stderr, "DEBUG: setting style '%s' (%p) for stream '%s'\n",
                    //    value, stream, name);
                    stream->style= err_style_from_int (x);
                    //fprintf (stderr, "DEBUG: style '%s' (%d) = %p (%s)\n",
                    //         value, x, stream->style, stream->style->name);
                    return 2;
                }
            }
        }
    }

    // color setup
    if (err_erwin_strcasecmp (key, "color-plain") == 0 ||
        err_erwin_strcasecmp (key, "colors-plain") == 0 ||
        err_erwin_strcasecmp (key, "colour-plain") == 0 ||
        err_erwin_strcasecmp (key, "colours-plain") == 0)
    {
        if (value == NULL) {
            qeprintf (C_TAG_ERROR, 0, "Option %s requires an argument.\n", key);
            return 0;
        }
        return err_color_parse_definition (err_plain_colors, value) ? 2 : 0;
    }

    // help
    if (err_erwin_strcasecmp (key, "help") == 0) {
        err_help ();
        exit (0);
    }

    // version
    if (err_erwin_strcasecmp (key, "version") == 0) {
        printf ("LibError %s\n", err_version);
        exit (0);
    }

    // crash
    if (err_erwin_strcasecmp (key, "crash") == 0 ||
        err_erwin_strcasecmp (key, "sigsegv") == 0 ||
        err_erwin_strcasecmp (key, "segfault") == 0)
    {
        (void)(*((volatile char *)NULL));
        exit (0);
    }

    // assert0
    if (err_erwin_strcasecmp (key, "assert0") == 0)
    {
        exit_if_reached();
        return 1;
    }

    // forever
    if (err_erwin_strcasecmp (key, "forever") == 0)
    {
        while (!err_continue) ;
        return 1;
    }

    // quiet level
    if (is_opt_int (error, n, "quiet", key, value)) {
        if (!error) {
           err_set_quiet_level (n);
           return 2;
        }
        else
           return 0;
    }

    // devel quiet level
    if (is_opt_int (error, n, "quiet-devel", key, value)) {
        if (!error) {
           err_set_quiet_level_devel (n);
           return 2;
        }
        else
           return 0;
    }

    // stream quiet level
    {
        if (is_prefix (n, key, "quiet:")) {
            char const *name= key + n;
            int x;
            if (is_opt_int (error, x, NULL, NULL, value)) {
                if (!error) {
                    ERR_IF_DEBUG_SHOW2 (
                        fprintf (stderr, "DEBUG: setting quiet level %s (%d) for stream '%s'\n",
                            value, x, name));
                    err_stream_set_quiet_level_aux (
                        err_get_stream_by_name (name), x, ERR_RELEASE_ONLY);
                    return 2;
                }
                else
                    return 0;
            }
        }
    }

    // stream devel quiet level
    {
        if (is_prefix (n, key, "quiet-devel:")) {
            char const *name= key + n;
            int x;
            if (is_opt_int (error, x, NULL, NULL, value)) {
                if (!error) {
                    ERR_IF_DEBUG_SHOW2 (
                        fprintf (stderr, "DEBUG: setting quiet level %s (%d) for stream '%s'\n",
                            value, x, name));
                    err_stream_set_quiet_level_aux (
                        err_get_stream_by_name (name), x, ERR_DEVEL_ONLY);
                    return 2;
                }
                else
                    return 0;
            }
        }
    }

    // showing/hiding/issuing
    {
        struct Option {
            char const *key;
            void (*cb_int)        (int, err_decision_t);
            void (*cb_enum)       (int, err_decision_t);
            void (*cb_enum_devel) (int, err_decision_t);
            err_decision_t value;
        };
        static Option const option[] = {
            { "show",     /*err-skip*/err_show_message,  err_show,  err_show_devel,  ERR_YES },
            { "hide",     /*err-skip*/err_show_message,  err_show,  err_show_devel,  ERR_NO  },
            { "issue",    /*err-skip*/err_issue_message, err_issue, err_issue_devel, ERR_YES },
            { "suppress", /*err-skip*/err_issue_message, err_issue, err_issue_devel, ERR_NO  },
            { NULL,       NULL,                          NULL,      NULL,            ERR_NO  }
        };

        char const *local_key2= key;
        bool positive1= get_positive (local_key2);

        bool local_error= false;
        char const *local_key= key;
        bool positive2= get_positive (local_error, local_key, value, must);

        for (Option const *o= option; o->key; o++) {
            ErrVInt ns_int;
            ErrVInt ns_enum;
            err_decision_t dec1= positive1 ? o->value : o->value == ERR_YES ? ERR_NO : ERR_YES;
            err_decision_t dec2= positive2 ? o->value : o->value == ERR_YES ? ERR_NO : ERR_YES;

            // Options of the kind: --err-hide=banner,410,progress
            if (is_opt_intenum_list (
                    error, ns_int, ns_enum, o->key, local_key, value, err_tag_enum)) {
                if (error == 0) {
                    err_vector_forall_values (ns_int, n)
                        o->cb_int (n, dec1);
                    err_vector_forall_values (ns_enum, n) {
                        if (ERR_IS_DEVEL(n))
                            o->cb_enum_devel (n, dec1);
                        else
                            o->cb_enum (n, dec1);
                    }
                    return 2;
                }
                else
                    return 0;
            }

            // Options of the kind: --err-hide-banner=1
            for (ErrEnumValue const *va=err_tag_enum; va->key; va++) {
                if (is_prefix (n, local_key, o->key) &&
                    local_key[n] == '-' &&
                    err_erwin_strcasecmp (local_key + n + 1, va->key) == 0)
                {
                    if (local_error) {
                        qeprintf (ERR_TAG_ERROR, 0,
                            "Illegal argument %s for option %s.\n"
                            "Boolean, i.e., \"0\" or \"1\" expected.\n",
                            value, key);
                        return 0;
                    }
                    else {
                        if (ERR_IS_DEVEL(va->value))
                            o->cb_enum_devel (va->value, dec2);
                        else
                            o->cb_enum (va->value, dec2);
                        return 2;
                    }
                }
            }

            // Options of the kind: --err-hide-group=x1,y2,z3,...
            if (is_prefix (n, local_key, o->key) &&
                local_key[n] == '-' &&
                err_erwin_strcasecmp (local_key + n + 1, "group") == 0)
            {
                if (value == NULL) {
                    qeprintf (C_TAG_ERROR, 0, "Option %s requires an argument.\n", key);
                    return 0;
                }

                char const *r;
                forever {
                    r= strchr (value, ',');
                    ErrVChar part;
                    if (r) {
                        part.append_raw (value, r-value);
                        value= r+1;
                    }
                    else
                        part.append (value);
                    if (part.non_empty())
                        o->cb_enum (err_group (part), dec1);
                    if (r == NULL)
                        return 2;
                }
            }

            // Options of the kind: --err-hide-subsystem=x1,y2,z3,...
            if (is_prefix (n, local_key, o->key) &&
                local_key[n] == '-' &&
                (err_erwin_strcasecmp (local_key + n + 1, "subsystem") == 0 ||
                 err_erwin_strcasecmp (local_key + n + 1, "sub-system") == 0 ||
                 err_erwin_strcasecmp (local_key + n + 1, "module") == 0))
            {
                if (value == NULL) {
                    qeprintf (C_TAG_ERROR, 0, "Option %s requires an argument.\n", key);
                    return 0;
                }

                char const *r;
                forever {
                    r= strchr (value, ',');
                    ErrVChar part;
                    if (r) {
                        part.append_raw (value, r-value);
                        value= r+1;
                    }
                    else
                        part.append (value);
                    if (part.non_empty())
                        o->cb_enum (err_subsystem (part), dec1);
                    if (r == NULL)
                        return 2;
                }
            }
        }
    }

    // unrecognised
    return 0;
}

static void illegal_to_dash(ErrVChar &k)
{
    char *p;
    err_vector_forall_values_ptr (k, p)
        if (!err_char_is_alpha(*p) && !err_char_is_digit(*p) && *p != '-' && *p != ':')
            *p= '-';
        else
            *p= err_char_to_lower(*p);
}

static void normalise_prefix (ErrVChar &prefix_tmp, char const *&prefix)
{
    if (prefix) {
        while (*prefix == '-') prefix++;
        if (*prefix) {
            prefix_tmp= prefix;
            while (prefix_tmp.last() == '-')
                prefix_tmp.chop();
            prefix= prefix_tmp;
        }
    }
}

static void err_parse_options (
    int *argc, char ***argv, char const *prefix, ErrProcessOption cb)
{
    if (!argc || !argv)
        return;

    ErrVChar prefix_tmp;
    normalise_prefix (prefix_tmp, prefix);

    ErrVCharConstP new_args;

    new_args.append ((*argv)[0]);
    for (int i= 1; i < *argc; i++) {
        if (prefix == NULL || *(*argv)[i] == '-') {

            char const *arg= (*argv)[i];
            while (*arg == '-') arg++;

            int len= 0;
            if (prefix == NULL ||
                (
                    is_prefix (len, arg, prefix) &&
                    arg[len] == '-'
                )
               )
            {
                char const *key= arg + len + (prefix == NULL ? 0 : 1);
                int result= -1;
                char const *equ= strchr (key, '=');
                if (equ != NULL) {
                    ErrVChar k;
                    k.append_raw (key, equ - key);
                    illegal_to_dash(k);
                    result= cb (k, equ + 1, true);
                    if (result > 1)
                        result= 1;
                }
                else {
                    ErrVChar k= key;
                    illegal_to_dash(k);
                    if (i + 1 < *argc)
                        result= cb (k, (*argv)[i+1], false);
                    else
                        result= cb (k, NULL, false);
                }

                if (result == 0)
                    eprintf (ERR_TAG_ERROR, 0, "Unrecognized option: %s.\n", arg);

                if (result == 2) // consumed one more argument
                    i++;
            }
            else
                new_args.append ((*argv)[i]);
        }
        else
            new_args.append ((*argv)[i]);
    }

    // Have we consumed entries?
    if (new_args.nentries() != *argc) {
        *argc= new_args.nentries();
        *argv= const_cast<char**> (new_args.as_array_detach());
    }
}

void err_opt_parse_args (int *argc, char ***argv, char const *prefix, ErrProcessOption cb)
{
    err_parse_options (argc, argv, prefix, cb);
}

void err_opt_parse_string (char const *s, ErrProcessOption cb)
// splits at spaces and passes to err_parse_options
// FIXME: implement "..." C quotation.
{
    unless (s)
        return;

    ErrVCharConstP args;
    args.append ((char const *)NULL); /* argv[0] is not used by err_parse_options */

    forever {
        while (*s && err_erwin_isspace (*s))
            s++;

        unless (*s)
            break;

        char const *space= s;
        while (*space && !err_erwin_isspace (*space))
            space++;

        args.append (err_string2symbol (ErrVChar().append_raw (s, space - s)));

        s= space;
    }

    int argc=    args.nentries();
    char **argv= const_cast<char**> (args.as_array_detach());

    err_parse_options (&argc, &argv, NULL, cb);
}

static void illegal_to_underscore (ErrVChar &result)
{
    char *p;
    err_vector_forall_values_ptr (result, p)
        if (!err_char_is_alpha(*p) && !err_char_is_digit(*p) && *p != '_' && *p != ':')
            *p= '_';
}

void err_get_envvar_global (ErrVChar *envvar, char const *prefix)
{
    ErrVChar prefix_tmp;
    normalise_prefix (prefix_tmp, prefix);

    // lowest priority: global env. variable:
    *envvar= "";
    envvar->format ("%s_OPTIONS", prefix);
    envvar->to_upper();
}

void err_get_envvar_local (ErrVChar *envvar, char const *prefix)
{
    *envvar= "";
    if (err_progname()) {
        envvar->format ("%s_OPTIONS_%s", prefix, err_progname());
        envvar->to_upper();
        illegal_to_underscore (*envvar);
    }
}

void err_opt_parse (int *argc, char ***argv, char const *prefix, ErrProcessOption cb)
{
    // lowest priority: global env. variable:
    {
        ErrVChar envvar;
        err_get_envvar_global (&envvar, prefix);
        err_opt_parse_string(getenv(+envvar), cb);
    }

    // local env. variable
    {
        ErrVChar envvar;
        err_get_envvar_local (&envvar, prefix);
        if (envvar.non_empty())
            err_opt_parse_string(getenv(+envvar), cb);
    }

    // highest priority: command line
    err_opt_parse_args (argc, argv, prefix, cb);
}

int err_style_from_string_to_int (char const *style)
{
    int x= ERR_STYLE_NONE;
    bool error;
    if (is_opt_enum (error, x, NULL, NULL, style, err_style_enum) && !error) {
        //fprintf (stderr, "DEBUG: style '%s' = %d\n", style, x);
        return x;
    }
    return -1;
}

err_style_t const * err_parse_style (char const *style)
{
    int x= err_style_from_string_to_int (style);
    if (x < 0)
        return NULL;
    return err_style_from_int (x);
}

