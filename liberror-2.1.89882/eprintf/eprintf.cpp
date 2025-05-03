//-*- Mode: C++ -*-

//
// Author: Henrik Theiling
// Description: command line tool 'eprintf'
//

#include <string.h>
#include "liberror.h"

static bool get_string (char const *&result, char const *key, char const *opt)
{
    int n= err_erwin_strlen (key);
    if (err_erwin_strncaseequ (opt, key, n) && opt[n] == '=') {
        result= opt + n + 1;
        return true;
    }
    if (err_erwin_strncaseequ (opt, key, n) && key[1] == 0) {
        result= opt + n;
        return true;
    }
    return false;
}

static int atoi_check (char const *str, char const *opt)
{
    char *r= NULL;
    int   a= err_erwin_strtol (str, &r, 0);
    if (*str && !*r) {
        return a;
    }
    eprintf (C_TAG_FATAL, 0, "In option '%s', '%s' is not an integer.", opt, str);
    return 0;
}

static bool get_int (int &result, char const *key, char const *opt)
{
    char const *str;
    if (get_string (str, key, opt)) {
        result= atoi_check (str, opt);
        return true;
    }
    return false;
}

int main (int argc, char **argv)
{
    err_init (&argc, &argv);
    err_add_stream (C_TAG_ALL, stderr, err_style_default);

    bool debug=  false;
    bool escape= false;
    char const *file= NULL;
    char const *progname= NULL;
    char const *subsystem= NULL;
    char const *group= NULL;
    int tag=    0;
    int number= 0;
    int line=   0;
    int pos=    0;
    int mypid=  -1;
    ErrVChar text;

    char const *help;
    ErrVChar lastarg;
    bool options= true;
    for (int i=1; i < argc; i++) {
        ErrVChar arg= argv[i];
        if (lastarg.non_empty()) {
            arg.insert (0, lastarg);
            lastarg.clear();
        }

        if (options && err_erwin_strequ (arg, "--"))
            options= false;
        else
        if (options && arg[0] == '-') {
            char const *a= arg;
            while (*a == '-')
                a++;

            if      (err_erwin_strcaseequ (a, "assert") ||
                     err_erwin_strcaseequ (a, "assertion"))   tag= C_TAG_ASSERT | C_TAG_VARIANT;
            else if (err_erwin_strcaseequ (a, "fatal"))       tag= C_TAG_FATAL | C_TAG_VARIANT;
            else if (err_erwin_strcaseequ (a, "internal"))    tag= C_TAG_INTERNAL;
            else if (err_erwin_strcaseequ (a, "err") ||
                     err_erwin_strcaseequ (a, "error"))       tag= C_TAG_ERROR;
            else if (err_erwin_strcaseequ (a, "warn") ||
                     err_erwin_strcaseequ (a, "warning"))     tag= C_TAG_WARNING;
            else if (err_erwin_strcaseequ (a, "info") ||
                     err_erwin_strcaseequ (a, "information")) tag= C_TAG_INFO;
            else if (err_erwin_strcaseequ (a, "unclassified") ||
                     err_erwin_strcaseequ (a, "noclass") ||
                     err_erwin_strcaseequ (a, "no-class"))    tag= C_TAG_NOCLASS;
            else if (err_erwin_strcaseequ (a, "note"))        tag= C_TAG_NOTE;
            else if (err_erwin_strcaseequ (a, "none"))        tag= C_TAG_NONE;
            else if (err_erwin_strcaseequ (a, "banner"))      tag= C_TAG_BANNER;
            else if (err_erwin_strcaseequ (a, "prompt"))      tag= C_TAG_PROMPT;
            else if (err_erwin_strcaseequ (a, "progress"))    tag= C_TAG_PROGRESS;
            else if (err_erwin_strcaseequ (a, "debug"))       debug= true;
            else
            if (err_erwin_strcaseequ (a, "colon"))
                err_style_plain_redirect= ERR_STYLE_PLAIN_COLON;
            else
            if (err_erwin_strcaseequ (a, "quotes"))
                err_style_plain_redirect= ERR_STYLE_PLAIN_QUOTES;
            else
            if (err_erwin_strcaseequ (a, "plain"))
                err_style_default_redirect= ERR_STYLE_PLAIN;
            else
            if (err_erwin_strcaseequ (a, "qt"))
                err_style_default_redirect= ERR_STYLE_QT;
            else
            if (err_erwin_strcaseequ (a, "qt3"))
                err_style_default_redirect= ERR_STYLE_QT3;
            else
            if (err_erwin_strcaseequ (a, "h") || err_erwin_strcaseequ (a, "help"))
            {
                printf ("Usage: eprintf [options] [text]\n");
                printf ("Options:\n");
                printf ("    -assert, -fatal, -internal, -error, -warn, -info, -note,\n"
                        "    -banner, -prompt, -none, -no-class\n"
                        "                                  sets the error type.\n");
                printf ("    -NUM                          sets the error number.\n");
                printf ("    -l FILE[:LINE[:POS]], --loc=FILE[:LINE[:POS]]\n"
                        "                                  sets the error location.\n");
                printf ("    -n NAME, --name=NAME          sets the program name.\n");
                printf ("    -s NAME, --subsystem=NAME     sets the subsystem name.\n");
                printf ("    -g NAME, --group=NAME         sets the group name.\n");
                printf ("    -p PID,  --pid=PID            defines the PID and displays it.\n");
                printf ("    -d, --debug                   sets debug/developer flag.\n");
                printf ("    -quotes, -colon               sets the error text layout.\n");
                printf ("    -plain, -qt, -qt3             sets the markup style.\n");
#if 0
                printf ("    -e, --escape                  interprets escapes in text.\n");
#endif
                printf ("    -h, --help                    displays this basic help text.\n");
                printf ("    --msg-help                    displays all message library options.\n");
                printf ("    --                            ends options list\n");
                exit (EXIT_SUCCESS);
            }
            else
            if (err_erwin_strcaseequ (a, "l") || err_erwin_strcaseequ (a, "loc") ||
                err_erwin_strcaseequ (a, "p") || err_erwin_strcaseequ (a, "pid") ||
                err_erwin_strcaseequ (a, "n") || err_erwin_strcaseequ (a, "name") ||
                err_erwin_strcaseequ (a, "g") || err_erwin_strcaseequ (a, "group") ||
                err_erwin_strcaseequ (a, "s") || err_erwin_strcaseequ (a, "subsystem"))
            {
                lastarg= arg;
                lastarg.append ('=');
            }
            else
            if (err_char_is_digit (*a))
                number= atoi_check (a, arg);
            else
            if (get_string (help, "l", a) || get_string (help, "loc", a))
            {
                char *n= (char*)strrchr (help, ':');
                if (n) {
                    line= atoi_check (n+1, arg);
                    *n= 0;
                    char *m= (char*)strrchr (help, ':');
                    if (m) {
                        pos= line;
                        line= atoi_check (m+1, arg);
                        *m= 0;
                    }
                }
                file= err_string2symbol (help);
            }
            else
            if (get_string (help, "n", a) || get_string (help, "name", a))
                progname= err_string2symbol (help);
            else
            if (get_int (mypid, "p", a) || get_int (mypid, "pid", a)) {
                /*ok*/
            }
            else if (get_string (help, "s", a) ||
                     get_string (help, "sub-system", a) ||
                     get_string (help, "subsystem", a))
            {
                subsystem= err_string2symbol (help);
            }
            else
            if (get_string (help, "g", a) || get_string (help, "group", a))
                group= err_string2symbol (help);
            else
            if (err_erwin_strcaseequ (a, "e") || err_erwin_strcaseequ (a, "escape"))
                escape= true; // like 'echo -n ...'
            else
                eprintf (C_TAG_FATAL, 0, "Unrecognised option: '%s'\n", +arg);
        }
        else {
            if (text.non_empty())
                text.append (' ');
            text.append (arg);
        }
    }

    if (debug)
        tag|= C_TAG_DEBUG;

    if (tag == 0)
        tag= C_TAG_ERROR;

    if (subsystem)
        tag|= err_subsystem (subsystem);
    if (group)
        tag|= err_group (group);

    if (mypid >= 0) {
        err_set_pid (mypid);
        err_style_plain_show_pid= true;
    }

    if (progname)
        err_set_progname (progname);

#if 0
    // NYI:
    if (escape) {
        for (int i=0; i < text.nentries(); i++) {
            if (text[i] == '\\') {
                switch (text[i+1]) {
                // oct:
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                    break;

                // hex:
                case 'x':
                    break;

                // unicode 4:
                case 'u':
                    break;

                // unicode 8:
                case 'U':
                    break;

                // single specials:
                case 'a':  text[i]= '\007'; text.erase (i+1); break;
                case 'e':  text[i]= '\033'; text.erase (i+1); break;
                case 'b':  text[i]= '\b';   text.erase (i+1); break;
                case 't':  text[i]= '\t';   text.erase (i+1); break;
                case 'f':  text[i]= '\f';   text.erase (i+1); break;
                case 'v':  text[i]= '\v';   text.erase (i+1); break;
                case 'n':  text[i]= '\n';   text.erase (i+1); break;
                case 'r':  text[i]= '\r';   text.erase (i+1); break;
                case '\\': text[i]= '\\';   text.erase (i+1); break;
                // case 'c': not implemented: trailing newline cannot be suppressed.
                default:
                    /* skip */;
                    i++;
                    break;
                }
            }
        }
    }
#endif

    if (text.non_empty())
        flpeprintf (tag, number, file, line, pos, "%s", +text);

    return 0;
}
