//-*- Mode: C++ -*-
// *
// * Author: Henrik Theiling
// * Description: Test of liberror
// *
// * COPYRIGHT NOTICE:
// *
// *   (c) Copyright 2001-2002 Henrik Theiling
// *
// * ---------------------------------------------------------------------- */

#include "liberror.h"

static void debug_callback (
    int tag, int orig_tag, int number, err_location_t const *, char const *text)
{
    fprintf (stderr, "found debug message: %d %d %d '%s'.\n", tag, orig_tag, number, text);
}

int main (int argc, char **argv)
{
    err_init (&argc, &argv);
    err_add_stream (C_TAG_ALL, stderr, err_style_default);

    err_remove_stream (C_TAG_ALL, stderr);
    err_add_stream (C_TAG_ALL, stderr, err_style_default);

    err_add_callback (C_TAG_DEBUG, 1, debug_callback, NULL);

    ErrVChar myname;
    myname.append (argv[0]);
    int index= myname.basename_index ();
    myname.erase (0, index);
    eprintf (C_TAG_BANNER, 0, "This is progname %s\n", myname.as_array());
    eprintf (C_TAG_MORE, 0,   "non-indented text\n");
    eprintf (C_TAG_MORE, 0,   "the float '5.43': %g / %5.2f\n", 5.43, 5.43);

    eprintf (C_TAG_NONE, 0, "This text should be continued on the next\n");
    eprintf (C_TAG_MORE, 0, "line.\n");

    fxprintf (stderr, "progname %s = %s/%d[%c]\n", myname.as_array(), argv[0], index, ERWIN_PATH_SEP);


#if 0
    // Test per stream filtering:
    err_print (NULL,   err_group("report"), ERR_NO);
    err_print (stdout, err_group("report"), ERR_YES);
    err_add_stream (C_TAG_ALL, stdout, err_style_default);

    eprintf (C_TAG_INFO | err_group("report"), 0, "Hallo, Report.\n");
#endif

#if 1
    // Test uniqueness filtering:
    err_print_once (NULL, C_TAG_NOTE, ERR_YES);
    eprintf (C_TAG_NOTE, 0, "a");
    eprintf (C_TAG_NOTE, 0, "a");
    eprintf (C_TAG_NOTE, 0, "a");
    eprintf (C_TAG_NOTE, 0, "ai");
    eprintf (C_TAG_NOTE, 0, "ai");
    eprintf (C_TAG_NOTE, 0, "a");

    eprintf (C_TAG_INFO,  0, "b");
    eprintf (C_TAG_INFO,  0, "b");
    eprintf (C_TAG_INFO,  0, "b");
    eprintf (C_TAG_INFO,  0, "b");
#endif

    err_issue (err_group ("test"), ERR_NO);

    eprintf (C_TAG_ERROR | err_subsystem ("subsys"), 0, "Test subsys 1");

    eprintf (C_TAG_DEBUG,  0, "Debug.  Previous line should not be blue.\n");
    leprintf(C_TAG_INFO,   0, NULL, "this should not crash.\n");

    eprintf (C_TAG_ERROR,  0, "error: Test 0.\n");
    eprintf (C_TAG_ERROR,  0, "error: Test 0.\n");

    eprintf (C_TAG_ERROR | C_TAG_DEBUG,  0, "debug error: Test 0.\n");
      // a debug error message (usually issued with deprintf):
    deprintf (C_TAG_ERROR,  0, "debug error: Test 1.\n");

    eprintf (C_TAG_ERROR,  0, "error: Test 1.\n");
    eprintf (C_TAG_ERROR,  0, "error: Test 1.\n");
    eprintf (C_TAG_ERROR,  0, "error: Test 1.\n");

    eprintf (C_TAG_ERROR,  0, "error: Test 2.\n");
    eprintf (C_TAG_ERROR,  0, "error: Test 2.\n");
    eprintf (C_TAG_ERROR,  0, "error: Test 2.\n");
    eprintf (C_TAG_ERROR,  0, "error: Test 2.\n");
    eprintf (C_TAG_ERROR,  0, "error: Test 2.\n");

    eprintf (C_TAG_ERROR,  0, "error: Test 0.\nMore test\n");
    eprintf (C_TAG_MORE,   0, "error: Even more test\n");

    eprintf (C_TAG_WARN,   0, "warning: Test 0.\n");
    eprintf (C_TAG_WARN,   0, "warning: Test 0.\nMore test\n");
    eprintf (C_TAG_MORE,   0, "warning: Even more test\n");

    eprintf (C_TAG_INFO,   0, "info: Test 0.\n");
    eprintf (C_TAG_INFO,   0, "info: Test 0.\nMore test\n");
    eprintf (C_TAG_MORE,   0, "info: Even more test\n");

    leprintf (C_TAG_DEBUG,  0, ErrLocation(0x15), "debug: Test 0.\n");
    leprintf (C_TAG_DEBUG,  0, err_at_address (0x16), "debug: Test 0.\n");

    eprintf (C_TAG_DEBUG,  0, "debug: Test 0.\n");
    eprintf (C_TAG_DEBUG,  0, "debug: Test 0.\nMore test\n");
    eprintf (C_TAG_MORE,   0, "debug: Even more test\n");

    deprintf (C_TAG_DEBUG,  0, "debug: Test 1.\n");

    flpeprintf (C_TAG_PRE_ASSERTION, 0, "testerror.cpp", 2, 5, "assertion: Test 0.\n");

    eprintf (C_TAG_PRE_ASSERTION, 0, "assertion: Test 0.\n");
    eprintf (C_TAG_PRE_ASSERTION, 0, "assertion: Test 0.\nMore test\n");
    eprintf (C_TAG_MORE,      0, "assertion: Even more test\n");

    eprintf (C_TAG_PROGRESS,  0, "progress: Test 0.\n");
    eprintf (C_TAG_PROGRESS,  0, "progress: Test 0.\nMore test\n");
    eprintf (C_TAG_MORE,      0, "progress: Even more test\n");

    eprintf (C_TAG_PROMPT,  0, "prompt: Test 0.\n");
    eprintf (C_TAG_PROMPT,  0, "prompt: Test 0.\nMore test\n");
    eprintf (C_TAG_MORE,    0, "prompt: Even more test\n");

    eprintf (C_TAG_NONE, 0, "none: Test 0.\n");
    eprintf (C_TAG_NONE, 0, "none: Test 0.\nMore test\n");
    eprintf (C_TAG_MORE, 0, "none: Even more test\n");

    leprintf (C_TAG_ERROR, 0, ErrLocation(__FILE__), "blah");
    leprintf (C_TAG_ERROR, 0, ErrLocation(__FILE__, __LINE__), "blah");
    leprintf (C_TAG_ERROR, 0, ErrLocation(__FILE__, __LINE__, 4), "blah");

    leprintf (C_TAG_ERROR, 0,
        ErrLocation(__FILE__, __LINE__, 4).upto (__LINE__, 10),
        "blah");

    leprintf (C_TAG_ERROR, 0,
        ErrLocation(__FILE__, __LINE__, 4).upto (__FILE__, __LINE__, 10),
        "blah");

    leprintf (C_TAG_ERROR, 0,
        ErrLocation(__FILE__, __LINE__, 4).upto ("Makefile", 40, 10),
        "blah");

    leprintf (C_TAG_ERROR, 0,
        ErrLocation (__FILE__, __LINE__, 4).upto (__FILE__, __LINE__, 10).
        originally  ("Makefile", __LINE__, 4).upto (__LINE__, 10),
        "blah");

    leprintf (C_TAG_ERROR, 0,
        ErrLocation (__FILE__, __LINE__, 4).originally  ("Makefile", __LINE__, 4).
        upto (__FILE__, __LINE__, 10).originally (__LINE__, 10),
        "blah");

    leprintf (C_TAG_ERROR, 0,
        ErrLocation (__FILE__, __LINE__, 4).upto (__FILE__, __LINE__, 10).
        originally  ("Makefile", __LINE__, 4).upto ("Makefile"),
        "blah");

    leprintf (C_TAG_ERROR, 0,
        ErrLocation (__FILE__, __LINE__, 4).upto (__FILE__, __LINE__ + 1, 10),
        "blah");

    leprintf (C_TAG_ERROR, 0,
        ErrLocation (__FILE__, __LINE__, 4).upto ("Makefile", __LINE__ + 1, 10),
        "blah");

    leprintf (C_TAG_ERROR, 0,
        ErrLocation (__FILE__, __LINE__).upto (__FILE__, __LINE__),
        "blah");

    leprintf (C_TAG_ERROR, 0,
        ErrLocation (__FILE__, __LINE__).upto (__FILE__, __LINE__ + 1),
        "blah");

    leprintf (C_TAG_ERROR, 0,
        ErrLocation (__FILE__, __LINE__).upto ("Makefile", __LINE__ + 1),
        "blah");

    leprintf (C_TAG_ERROR, 0,
        err_upto_position (
            err_originally_at_position (
                err_upto_position (
                    err_at_position (__FILE__, __LINE__, 4),
                    __FILE__, __LINE__, 10),
                "Makefile", __LINE__, 4),
            "Makefile", __LINE__, 10),
        "blah");

    eprintf (C_TAG_ERROR, 0, "AB");
    eprintf (C_TAG_ERROR, 0, ERR_CALLBACKS_ONLY);
    eprintf (C_TAG_ERROR, 0, "CD");

    ErrBuffer b;
    err_buffer_begin (b);
    eprintf (C_TAG_PRE_FATAL, 0, "This is");
    eprintf (C_TAG_ERROR, 0, "not");
    eprintf (C_TAG_PRE_ASSERTION, 0, "correct.");
    err_buffer_end ();

    // err_set_fprintf_tag (C_TAG_INFO);

    fxprintf (stderr, "Test 1.\n");

    fxprintf (stderr, "Test");
    fxprintf (stderr, " 2.\n");

    fxprintf (stderr, "Test 3\n...continued a...\n...continued b");
    fxprintf (stderr, "...\n...continued c...\n...continued d");
    fxprintf (stderr, "...");
    fxprintf (stderr, "\n");
    fxprintf (stderr, "\n");
    fxprintf (stderr, "...continued e...\n...continued f...\nend.");

    ERWIN_LONG_LONG a= err_erwin_strtoll ("0x99283029a48b34", 0, 0);
    fxprintf (stderr, "This is a test: 0x%Lx\n", a);

    eprintf (C_TAG_NOTE, 0, "err+warn=    %3d,%3d,%3d,%3d,%3d\n",
        err_count (ERR_STATUS_RECEIVED,    C_TAG_ERROR | C_TAG_WARN),
        err_count (ERR_STATUS_ISSUED,      C_TAG_ERROR | C_TAG_WARN),
        err_count (ERR_STATUS_DISTRIBUTED, C_TAG_ERROR | C_TAG_WARN),
        err_count (ERR_STATUS_SHOWN,       C_TAG_ERROR | C_TAG_WARN),
        err_count (ERR_STATUS_PRINTED,     C_TAG_ERROR | C_TAG_WARN));

    eprintf (C_TAG_NOTE, 0, "error_cnts=  %3d,%3d,%3d,%3d,%3d\n",
        err_count (ERR_STATUS_RECEIVED,    C_TAG_ERROR),
        err_count (ERR_STATUS_ISSUED,      C_TAG_ERROR),
        err_count (ERR_STATUS_DISTRIBUTED, C_TAG_ERROR),
        err_count (ERR_STATUS_SHOWN,       C_TAG_ERROR),
        err_count (ERR_STATUS_PRINTED,     C_TAG_ERROR));

    eprintf (C_TAG_NOTE, 0, "warning_cnts=%3d,%3d,%3d,%3d,%3d\n",
        err_count (ERR_STATUS_RECEIVED,    C_TAG_WARNING),
        err_count (ERR_STATUS_ISSUED,      C_TAG_WARNING),
        err_count (ERR_STATUS_DISTRIBUTED, C_TAG_WARNING),
        err_count (ERR_STATUS_SHOWN,       C_TAG_WARNING),
        err_count (ERR_STATUS_PRINTED,     C_TAG_WARNING));

    eprintf (C_TAG_NOTE, 0, "info_cnts=   %3d,%3d,%3d,%3d,%3d\n",
        err_count (ERR_STATUS_RECEIVED,    C_TAG_INFO),
        err_count (ERR_STATUS_ISSUED,      C_TAG_INFO),
        err_count (ERR_STATUS_DISTRIBUTED, C_TAG_INFO),
        err_count (ERR_STATUS_SHOWN,       C_TAG_INFO),
        err_count (ERR_STATUS_PRINTED,     C_TAG_INFO));

    err_clear_count (
        ERR_STATUS_ISSUED | ERR_STATUS_DISTRIBUTED,
        C_TAG_INFO | C_TAG_WARNING);

    eprintf (C_TAG_NOTE, 0, "error_cnts=  %3d,%3d,%3d,%3d,%3d\n",
        err_count (ERR_STATUS_RECEIVED,    C_TAG_ERROR),
        err_count (ERR_STATUS_ISSUED,      C_TAG_ERROR),
        err_count (ERR_STATUS_DISTRIBUTED, C_TAG_ERROR),
        err_count (ERR_STATUS_SHOWN,       C_TAG_ERROR),
        err_count (ERR_STATUS_PRINTED,     C_TAG_ERROR));

    eprintf (C_TAG_NOTE, 0, "warning_cnts=%3d,%3d,%3d,%3d,%3d\n",
        err_count (ERR_STATUS_RECEIVED,    C_TAG_WARNING),
        err_count (ERR_STATUS_ISSUED,      C_TAG_WARNING),
        err_count (ERR_STATUS_DISTRIBUTED, C_TAG_WARNING),
        err_count (ERR_STATUS_SHOWN,       C_TAG_WARNING),
        err_count (ERR_STATUS_PRINTED,     C_TAG_WARNING));

    eprintf (C_TAG_NOTE, 0, "info_cnts=   %3d,%3d,%3d,%3d,%3d\n",
        err_count (ERR_STATUS_RECEIVED,    C_TAG_INFO),
        err_count (ERR_STATUS_ISSUED,      C_TAG_INFO),
        err_count (ERR_STATUS_DISTRIBUTED, C_TAG_INFO),
        err_count (ERR_STATUS_SHOWN,       C_TAG_INFO),
        err_count (ERR_STATUS_PRINTED,     C_TAG_INFO));

    eprintf (C_TAG_NOTE, 0, "error_cnts=  %3d,%3d,%3d,%3d,%3d\n",
        err_count (ERR_STATUS_RECEIVED,    C_TAG_ERROR),
        err_count (ERR_STATUS_ISSUED,      C_TAG_ERROR),
        err_count (0,                      C_TAG_ERROR),
        err_count (ERR_STATUS_SHOWN,       C_TAG_ERROR),
        err_count (ERR_STATUS_PRINTED,     C_TAG_ERROR));

    eprintf (C_TAG_NOTE, 0, "warning_cnts=%3d,%3d,%3d,%3d,%3d\n",
        err_count (ERR_STATUS_RECEIVED,    C_TAG_WARNING),
        err_count (ERR_STATUS_ISSUED,      C_TAG_WARNING),
        err_count (0,                      C_TAG_WARNING),
        err_count (ERR_STATUS_SHOWN,       C_TAG_WARNING),
        err_count (ERR_STATUS_PRINTED,     C_TAG_WARNING));

    eprintf (C_TAG_NOTE, 0, "info_cnts=   %3d,%3d,%3d,%3d,%3d\n",
        err_count (ERR_STATUS_RECEIVED,    C_TAG_INFO),
        err_count (ERR_STATUS_ISSUED,      C_TAG_INFO),
        err_count (0,                      C_TAG_INFO),
        err_count (ERR_STATUS_SHOWN,       C_TAG_INFO),
        err_count (ERR_STATUS_PRINTED,     C_TAG_INFO));


    err_set_fatal_count (ERR_STATUS_DISTRIBUTED, C_TAG_ERROR,
              err_count (ERR_STATUS_DISTRIBUTED, C_TAG_ERROR) + 1);

    eprintf (C_TAG_ERROR, 0, "This is a test error that <b>generates</b> a fatal error.\n");
    return 0;
}
