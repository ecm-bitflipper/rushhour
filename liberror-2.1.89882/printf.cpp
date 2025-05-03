// -*- Mode: C++ -*-
//
// substitutes of printf family.
//
// Please note: this is a hack!  If you do not want it, simply remove this
// module from Makefile.in.
//
// compile without header in order to avoid conflicts.  These are
// link-time overrides.

#include <stdarg.h>
#include "error/err-config.h"

#ifdef ERR_REPLACE_PRINTF

// cheat a bit: FILE * = void * here just to make it compile...
#define FILE void

extern "C" {

// Imports
// from liberror.h:
extern int vfxprintf(FILE *, char const *, va_list);

#ifdef ERR_HAVE_STDERR

extern FILE *_err_get_stdout ();
extern FILE *_err_get_stderr ();

#endif /* ERR_HAVE_STDERR */

// Exports
// These are overridden:
extern int vfprintf (FILE *, char const *, va_list);
extern int fprintf  (FILE *, char const *, ...);

#ifdef ERR_HAVE_STDERR

extern int vprintf  (char const *, va_list);
extern int printf   (char const *, ...);

#endif /* defined ERR_HAVE_STDERR */

}

// generate errors whenever the following functions are invoked:
extern int vfprintf (FILE *f, char const *format, va_list va)
{
    return vfxprintf (f, format, va);
}

extern int fprintf (FILE *f, char const *format, ...)
{
    va_list va;
    va_start (va, format);
    int result= vfxprintf (f, format, va);
    va_end (va);
    return result;
}

#ifdef ERR_HAVE_STDERR

extern int vprintf (char const *format, va_list va)
{
    return vfxprintf (_err_get_stdout(), format, va);
}

extern int printf (char const *format, ...)
{
    va_list va;
    va_start (va, format);
    int result= vfxprintf (_err_get_stdout(), format, va);
    va_end (va);
    return result;
}

#endif /* defined ERR_HAVE_STDERR */

#endif /* defined ERR_REPLACE_PRINTF */
