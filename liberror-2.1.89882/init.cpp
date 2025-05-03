// -*- Mode: C++ -*-

#include "liberror.h"
#include "internal.h"
#include "failure.h"
#include "version.h"

int err_initialised= 0;
int err_progress_level= -1; // show any progress messages by default

char const *_err_config_prefix;

#ifndef err_force_fprintf
bool err_force_fprintf= getenv("MSG_FORCE_FPRINTF") != NULL;
#endif

static char const *progname= NULL;

/* ********************************************************************** */

char const *err_config_prefix()
{
    if (_err_config_prefix == NULL)
        return "msg";
    return _err_config_prefix;
}

void err_set_config_prefix(char const *c)
{
    _err_config_prefix= c;
}

ErrVChar err_arg_prefix(int compat_level)
{
    if (ERR_CHECK_COMPAT(2,0) && compat_level >= 1)
        return "err-";

    return *err_config_prefix() ?
               ErrVChar().format ("%s-", err_config_prefix ())
             : ErrVChar("");
}

static void illegal_to_underscore (ErrVChar &result)
{
    char *p;
    err_vector_forall_values_ptr (result, p)
        if (!err_char_is_alpha(*p) && !err_char_is_digit(*p) && *p != '_')
            *p= '_';
}

ErrVChar err_envvar_global (int compat_level)
{
    if (ERR_CHECK_COMPAT(2,0) && compat_level >= 1)
        return "ERR_OPTIONS";

    ErrVChar result;
    result.format ("%s_OPTIONS", err_config_prefix());
    result.to_upper();
    illegal_to_underscore (result);
    return result;
}

ErrVChar err_envvar_program (int compat_level)
{
    ErrVChar result;
    result.format ("%s_%s", +err_envvar_global(compat_level), err_progname());
    result.to_upper();
    illegal_to_underscore (result);
    return result;
}

void err_init (int *argc, char ***argv)
{
    if (err_initialised == 0) {
        err_initialised= 1;
            // prevent recursion (if an assertion fails, this would be called again.)

        err_erwin_init (argc, argv);
        err_symbol_init (argc, argv);
        err_plain_color_init (argc, argv);

#if ERR_REINIT
        // Done automatically anyway.  Could be used for allowed re-initialisation.
        // Currently, we assume that the library is only initialised once and
        // that it is correct to re-invoke this function.

#ifdef ERR_REDIR_STDERR
        fprintf_tag= C_TAG_NOCLASS;
#endif

        streams.clear();  // No output by default!

        subsystem_counter= 1;
        err_subsystem_ids.clear();
        err_subsystem_names.clear ();

        group_counter= 1;
        group_names.clear();
        group_ids.clear();

        /* progname= NULL; * mal be set before invocation of err_init. */
        err_printf_incarnation= 0;
        err_printf_incarnation2= 0;

#endif /* ERR_REINIT */

        err_err_subsystem= err_declare_subsystem ("error");

        if (progname == NULL) {
            if (argv && *argv && (*argv)[0]) {
                ErrVChar p;
                p.append ((*argv)[0]);
                p.erase (0, p.basename_index());

#ifdef ERWIN_DOS
                // always lower cast
                p.to_lower ();

                // erase .exe, .com, .bat and .pif at the end.
                if (p.is_equal_at (-4, ".exe"))
                    p.erase (p.nentries()-4, -1);
                else
                if (p.is_equal_at (-4, ".com"))
                    p.erase (p.nentries()-4, -1);
                else
                if (p.is_equal_at (-4, ".bat"))
                    p.erase (p.nentries()-4, -1);
                else
                if (p.is_equal_at (-4, ".pif"))
                    p.erase (p.nentries()-4, -1);
#endif
                if (!p.empty())
                    progname= err_string2symbol (p);
            }
        }

#ifdef ERR_REDIR_STDERR
        atexit (fprintf_flush);
#endif

        err_count_init();
        err_callback_init();
        err_buffer_init();

        // For a start, add stdout as the banner and none stream and
        // stderr as an normal output stream for everything else.
        // These must be removed again later since the user may want to
        // do something else.
        err_add_stream (C_TAG_BANNER | C_TAG_NONE,                stdout, NULL);
        err_add_stream (C_TAG_ALL & ~(C_TAG_BANNER | C_TAG_NONE), stderr, NULL);

        err_initialised= 2; // completed: the print functions should work now...

        // Now parse the environment variables:
        if (ERR_CHECK_COMPAT (2,0)) {
            err_opt_parse_string (getenv (+err_envvar_global (1)), err_process_option);
            if (err_progname ())
                err_opt_parse_string (getenv (+err_envvar_program (1)), err_process_option);
        }

        err_opt_parse_string (getenv (+err_envvar_global (0)), err_process_option);
        if (err_progname ())
            err_opt_parse_string (getenv (+err_envvar_program (0)), err_process_option);

        // Now parse the arguments (this may produce errors that are
        // hopefully put to stderr, since err_initialised is != 2.
        err_opt_parse_args (argc, argv, +err_arg_prefix(0), err_process_option);
        err_opt_parse_args (argc, argv, +err_arg_prefix(1), err_process_option);

        // remove the streams again:
        err_remove_stream (C_TAG_BANNER | C_TAG_NONE,                stdout);
        err_remove_stream (C_TAG_ALL & ~(C_TAG_BANNER | C_TAG_NONE), stderr);
    }
}

char const *err_progname ()
{
    return progname;
}

void err_set_progname (char const *aprogname)
{
    if (err_initialised)
        progname= err_string2symbol (aprogname);
    else
        progname= aprogname;
}

