/* -*- Mode: C -*- */
/* Generated automatically by assert.pl (part of Erwin library). */

#ifndef ERR_HT_FAILURE_H
#define ERR_HT_FAILURE_H

/*
 * This file contains ugly macros.  Their purpose is to debug code, and
 * to be a substitute for assert.h.  This file should compile under any compiler
 * with all (sensible) compiler settings and #defines.  This is meant to be ANSI
 * code with GNUC extensions if we compile under GNUC.  It should under no
 * circumstances produce compiler errors and under GNUC it should not produce
 * any warnings.
 * So if it fails to compile, it is a severe bug.  Please report this to
 * henrik@theiling.de.  To temporarily circumvent the problem, you can comment
 * out the following line. */

/* #define ERR_ASSERT_IS_BROKEN */

#ifndef ERR_ASSERT_IS_BROKEN

/*
 * Additional user provided assertion failure, warning,
 * and error handlers.
 */
#ifndef ERR_USER_ASSERTION_FAILED_HANDLER
#define ERR_USER_ASSERTION_FAILED_HANDLER(FI,L,FU,A) ERR_ASSERT_NO_EFFECT
#endif

#ifndef ERR_USER_ERROR_HANDLER
#define ERR_USER_ERROR_HANDLER(FI,L,FU,A) ERR_ASSERT_NO_EFFECT
#endif

#ifndef ERR_USER_WARNING_HANDLER
#define ERR_USER_WARNING_HANDLER(FI,L,FU,A) ERR_ASSERT_NO_EFFECT
#endif

#ifdef __GNUC__

#define ERR_ASSERT_NORETURN  __attribute__((__noreturn__))

#if defined __cplusplus && (__GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 95))
#define ERR_ASSERT_CAST_VOID static_cast<void>
   /* for compiler warning -Wold-style-cast */
#endif

#ifndef ERR_ASSERT_FUNCTION
#define ERR_ASSERT_FUNCTION   __PRETTY_FUNCTION__
#endif

#ifndef ERR_ASSERT_NO_EFFECT
#define ERR_ASSERT_NO_EFFECT  (ERR_ASSERT_CAST_VOID(0)) /* To get rid of warnings. */
 /* FIXME: CHECK: do we need the different versions of ERR_ASSERT_NO_EFFECT? */
#endif

#else

#define ERR_ASSERT_NORETURN

#ifndef ERR_ASSERT_FUNCTION
#define ERR_ASSERT_FUNCTION   "-unknown-"
#endif

#ifndef ERR_ASSERT_NO_EFFECT
#define ERR_ASSERT_NO_EFFECT  0
#endif

#endif

#ifndef ERR_ASSERT_CAST_VOID
#define ERR_ASSERT_CAST_VOID (void)
#endif

#ifndef NDEBUG
#define ERR_ASSERT_DEBUG_CODE(X) X
#else
#define ERR_ASSERT_DEBUG_CODE(X)
#endif

#if defined(__KERNEL__)

#ifndef ERR_ASSERT_EPRINTF_MORE_0
#define ERR_ASSERT_EPRINTF_MORE_0(F) \
        ERR_ASSERT_CAST_VOID (printk (KERN_ERR "\t"F))
#endif

#ifndef ERR_ASSERT_EPRINTF_MORE_1
#define ERR_ASSERT_EPRINTF_MORE_1(F,V1) \
        ERR_ASSERT_CAST_VOID (printk (KERN_ERR "\t"F, V1))
#endif

#ifndef ERR_ASSERT_EPRINTF_MORE_2
#define ERR_ASSERT_EPRINTF_MORE_2(F,V1,V2) \
        ERR_ASSERT_CAST_VOID (printk (KERN_ERR "\t"F, V1, V2))
#endif

#ifndef ERR_ASSERT_FLEPRINTF_ASSERT_2
#define ERR_ASSERT_FLEPRINTF_ASSERT_2(FILE,LINE,F,V1,V2) \
        ERR_ASSERT_CAST_VOID (printk (KERN_ERR "%s:%d: "F, FILE, LINE, V1, V2))
#endif

#ifndef ERR_ASSERT_FLEPRINTF_ASSERT_3
#define ERR_ASSERT_FLEPRINTF_ASSERT_3(FILE,LINE,F,V1,V2,V3) \
        ERR_ASSERT_CAST_VOID (printk (KERN_ERR "%s:%d: "F, FILE, LINE, V1, V2, #V3))
#endif

#ifndef ERR_ASSERT_END
#define ERR_ASSERT_END \
        ERR_ASSERT_CAST_VOID (0)
#endif

#ifndef ERR_ASSERT_INDENT
#define ERR_ASSERT_INDENT "\t"
#endif

#elif defined(HAVE_LIBERROR)

#ifndef IN_LIBERROR_COMPILE
#include <liberror.h>
#endif

#ifndef ERR_ASSERT_ABORT
#define ERR_ASSERT_ABORT err_crash()
#endif

#ifndef ERR_ASSERT_EPRINTF_MORE_0
#define ERR_ASSERT_EPRINTF_MORE_0(F) \
        ERR_ASSERT_CAST_VOID (eprintf (C_TAG_MORE, 0, F))
#endif

#ifndef ERR_ASSERT_EPRINTF_MORE_1
#define ERR_ASSERT_EPRINTF_MORE_1(F,V1) \
        ERR_ASSERT_CAST_VOID (eprintf (C_TAG_MORE, 0, F, V1))
#endif

#ifndef ERR_ASSERT_EPRINTF_MORE_2
#define ERR_ASSERT_EPRINTF_MORE_2(F,V1,V2) \
        ERR_ASSERT_CAST_VOID (eprintf (C_TAG_MORE, 0, F, V1, V2))
#endif

#ifndef ERR_ASSERT_FLEPRINTF_ASSERT_2
#define ERR_ASSERT_FLEPRINTF_ASSERT_2(FILE,LINE,F,V1,V2) \
        ERR_ASSERT_CAST_VOID (fleprintf (C_TAG_PRE_ASSERT | err_err_subsystem, 0, FILE, LINE, F, V1, V2))
#endif

#ifndef ERR_ASSERT_FLEPRINTF_ASSERT_3
#define ERR_ASSERT_FLEPRINTF_ASSERT_3(FILE,LINE,F,V1,V2,V3) \
        ERR_ASSERT_CAST_VOID (fleprintf (C_TAG_PRE_ASSERT | err_err_subsystem, 0, FILE, LINE, F, V1, V2, #V3))
#endif

#ifndef ERR_ASSERT_END
#define ERR_ASSERT_END \
        ERR_ASSERT_CAST_VOID (eprintf (C_TAG_ASSERT | err_err_subsystem, 0, ERR_CALLBACKS_ONLY))
#endif

#ifndef ERR_ASSERT_INDENT
#define ERR_ASSERT_INDENT
#endif

#else /* !defined HAVE_LIBERROR */

#ifndef ERR_ASSERT_EPRINTF_MORE_0
#define ERR_ASSERT_EPRINTF_MORE_0(F) \
        ERR_ASSERT_CAST_VOID (fprintf (stderr, "\t"F))
#endif

#ifndef ERR_ASSERT_EPRINTF_MORE_1
#define ERR_ASSERT_EPRINTF_MORE_1(F,V1) \
        ERR_ASSERT_CAST_VOID (fprintf (stderr, "\t"F, V1))
#endif

#ifndef ERR_ASSERT_EPRINTF_MORE_2
#define ERR_ASSERT_EPRINTF_MORE_2(F,V1,V2) \
        ERR_ASSERT_CAST_VOID (fprintf (stderr, "\t"F, V1, V2))
#endif

#ifndef ERR_ASSERT_FLEPRINTF_ASSERT_2
#define ERR_ASSERT_FLEPRINTF_ASSERT_2(FILE,LINE,F,V1,V2) \
        ERR_ASSERT_CAST_VOID (fprintf (stderr, "%s:%d: "F, FILE, LINE, V1, V2))
#endif

#ifndef ERR_ASSERT_FLEPRINTF_ASSERT_3
#define ERR_ASSERT_FLEPRINTF_ASSERT_3(FILE,LINE,F,V1,V2,V3) \
        ERR_ASSERT_CAST_VOID (fprintf (stderr, "%s:%d: "F, FILE, LINE, V1, V2, #V3))
#endif

#ifndef ERR_ASSERT_END
#define ERR_ASSERT_END \
        ERR_ASSERT_CAST_VOID (0)
#endif

#ifndef ERR_ASSERT_INDENT
#define ERR_ASSERT_INDENT "\t"
#endif

#endif /* !defined HAVE_LIBERROR */

#ifndef ERR_ASSERT_ABORT
#define ERR_ASSERT_ABORT abort()
#endif

#ifndef ERR_ASSERT_NONNEGATIVE
#ifdef erwin_nonnegative
#define ERR_ASSERT_NONNEGATIVE(X) erwin_nonnegative(X)
#else
#define ERR_ASSERT_NONNEGATIVE(X) ((X) >= 0)
#endif
#endif

#ifndef ERR_ASSERT_UNLIKELY
#ifdef ERWIN_UNLIKELY
#define ERR_ASSERT_UNLIKELY(X) ERWIN_UNLIKELY(X)
#else
#define ERR_ASSERT_UNLIKELY(X) (X)
#endif
#endif

#ifdef HAVE_LIBERROR
#ifdef __cplusplus
extern "C" {
#endif
extern int err_err_subsystem;
#ifdef __cplusplus
}
#endif
#endif

/*
 * Please note that this does not have any do { ... } while(0) protection.  This is because
 * continue_if_fail and break_if_fail would do wrong things in that case. */
#ifndef err_raw_do_if_fail
#define err_raw_do_if_fail(P,A1,A2,A3,W,F1,F2) \
        if (ERR_ASSERT_UNLIKELY(!(A1))) { \
            ERR_ASSERT_FLEPRINTF_ASSERT_3 ( \
                     __FILE__, __LINE__, \
                     ""P" function '%s':\n" \
                     ERR_ASSERT_INDENT W " failed: '%s'\n" \
                     ERR_ASSERT_INDENT "Pre-processed: '%s'\n" \
                             , ERR_ASSERT_FUNCTION, \
                             A3 \
                             ,A2 \
                             ); \
            F1; \
            ERR_USER_ASSERTION_FAILED_HANDLER(__FILE__,__LINE__,ERR_ASSERT_FUNCTION, A); \
            F2; \
        } \
        else { ; }
#endif

/*
 * If you write your ERR_USER_ASSERTION_FAILED_HANDLER in such a way that it is an expression,
 * you can use the false_if_fail, null_if_fail, etc. */
#ifndef err_raw_value_if_fail
#define err_raw_value_if_fail(P,A1,A2,A3,W,F1,FAILVAL,GOODVAL) \
        (ERR_ASSERT_UNLIKELY(!(A1)) ? ((\
                     ERR_ASSERT_FLEPRINTF_ASSERT_3 ( \
                     __FILE__, __LINE__, \
                          ""P" function '%s':\n" \
                          ERR_ASSERT_INDENT W" failed: '%s'\n" \
                          ERR_ASSERT_INDENT "Pre-processed: '%s'\n" \
                          , ERR_ASSERT_FUNCTION, \
                          A3 \
                          ,#A2 \
                          )), \
                  (F1), \
                  (ERR_USER_ASSERTION_FAILED_HANDLER(__FILE__, __LINE__, ERR_ASSERT_FUNCTION, A)), \
                  (FAILVAL)) \
                : (GOODVAL))
#endif

#ifndef NDEBUG

#ifndef err_do_if_fail
#define err_do_if_fail(A1,A2,A3,W,F1,F2) \
        err_raw_do_if_fail("In",A1,A2,A3,W,F1,F2)
#endif

#ifndef err_value_if_fail
#define err_value_if_fail(A1,A2,A3,W,F1,FAILVAL,GOODVAL) \
        err_raw_value_if_fail("In",A1,A2,A3,W,F1,FAILVAL,GOODVAL)
#endif

#else

#ifndef err_do_if_fail
#define err_do_if_fail(A1,A2,A3,W,F1,F2)
#endif

#ifndef err_value_if_fail
#define err_value_if_fail(A1,A2,A3,W,F1,FAILVAL,GOODVAL) (GOODVAL)
#endif

#endif

#ifndef err_warn_do_if_fail
#define err_warn_do_if_fail(A1,A2,A3,W,F1,F2) \
        err_raw_do_if_fail("Warning in",A1,A2,A3,W,F1,F2)
#endif

#ifndef err_warn_value_if_fail
#define err_warn_value_if_fail(A1,A2,A3,W,F1,FAILVAL,GOODVAL) \
        err_raw_value_if_fail("Warning in",A1,A2,A3,W,F1,FAILVAL,GOODVAL)
#endif

#ifndef err_error_do_if_fail
#define err_error_do_if_fail(A1,A2,A3,W,F1,F2) \
        err_raw_do_if_fail("Error in",A1,A2,A3,W,F1,F2)
#endif

#ifndef err_error_value_if_fail
#define err_error_value_if_fail(A1,A2,A3,W,F1,FAILVAL,GOODVAL) \
        err_raw_value_if_fail("Error in",A1,A2,A3,W,F1,FAILVAL,GOODVAL)
#endif

#ifndef err_error_exit_if_fail
#define err_error_exit_if_fail(A1) \
	 do { err_error_do_if_fail(A1,A1,""#A1,"Sanity constraint",;;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_fail_pC
#define err_error_exit_if_fail_pC(A1,X1) \
	 do { err_error_do_if_fail(A1,A1,""#A1,"Sanity constraint",X1;;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_fail_pi
#define err_error_exit_if_fail_pi(A1,X1) \
	 do { err_error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_fail_pii
#define err_error_exit_if_fail_pii(A1,X1,X2) \
	 do { err_error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_fail_piit
#define err_error_exit_if_fail_piit(A1,X1,X2,X3) \
	 do { err_error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_fail_pit
#define err_error_exit_if_fail_pit(A1,X1,X2) \
	 do { err_error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_fail_pt
#define err_error_exit_if_fail_pt(A1,X1) \
	 do { err_error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_fail_pts
#define err_error_exit_if_fail_pts(A1,X1,X2) \
	 do { err_error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_null
#define err_error_exit_if_null(A1) \
	 do { err_error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",;;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_null_pC
#define err_error_exit_if_null_pC(A1,X1) \
	 do { err_error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",X1;;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_null_pi
#define err_error_exit_if_null_pi(A1,X1) \
	 do { err_error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_null_pii
#define err_error_exit_if_null_pii(A1,X1,X2) \
	 do { err_error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_null_piit
#define err_error_exit_if_null_piit(A1,X1,X2,X3) \
	 do { err_error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_null_pit
#define err_error_exit_if_null_pit(A1,X1,X2) \
	 do { err_error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_null_pt
#define err_error_exit_if_null_pt(A1,X1) \
	 do { err_error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_null_pts
#define err_error_exit_if_null_pts(A1,X1,X2) \
	 do { err_error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_out_of_bounds
#define err_error_exit_if_out_of_bounds(A1,M) \
	 do { err_error_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_out_of_bounds_pC
#define err_error_exit_if_out_of_bounds_pC(A1,M,X1) \
	 do { err_error_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));X1;;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_out_of_bounds_pi
#define err_error_exit_if_out_of_bounds_pi(A1,M,X1) \
	 do { err_error_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_out_of_bounds_pii
#define err_error_exit_if_out_of_bounds_pii(A1,M,X1,X2) \
	 do { err_error_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_out_of_bounds_piit
#define err_error_exit_if_out_of_bounds_piit(A1,M,X1,X2,X3) \
	 do { err_error_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_out_of_bounds_pit
#define err_error_exit_if_out_of_bounds_pit(A1,M,X1,X2) \
	 do { err_error_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_out_of_bounds_pt
#define err_error_exit_if_out_of_bounds_pt(A1,M,X1) \
	 do { err_error_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_out_of_bounds_pts
#define err_error_exit_if_out_of_bounds_pts(A1,M,X1,X2) \
	 do { err_error_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_reached
#define err_error_exit_if_reached() \
	 do { err_error_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_reached_pC
#define err_error_exit_if_reached_pC(X1) \
	 do { err_error_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");X1;;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_reached_pi
#define err_error_exit_if_reached_pi(X1) \
	 do { err_error_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_reached_pii
#define err_error_exit_if_reached_pii(X1,X2) \
	 do { err_error_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_reached_piit
#define err_error_exit_if_reached_piit(X1,X2,X3) \
	 do { err_error_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_reached_pit
#define err_error_exit_if_reached_pit(X1,X2) \
	 do { err_error_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_reached_pt
#define err_error_exit_if_reached_pt(X1) \
	 do { err_error_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_exit_if_reached_pts
#define err_error_exit_if_reached_pts(X1,X2) \
	 do { err_error_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_error_return0_if_fail
#define err_error_return0_if_fail(A1) \
	 do { err_error_do_if_fail(A1,A1,""#A1,"Sanity constraint",;;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_fail_pC
#define err_error_return0_if_fail_pC(A1,X1) \
	 do { err_error_do_if_fail(A1,A1,""#A1,"Sanity constraint",X1;;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_fail_pi
#define err_error_return0_if_fail_pi(A1,X1) \
	 do { err_error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_fail_pii
#define err_error_return0_if_fail_pii(A1,X1,X2) \
	 do { err_error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_fail_piit
#define err_error_return0_if_fail_piit(A1,X1,X2,X3) \
	 do { err_error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_fail_pit
#define err_error_return0_if_fail_pit(A1,X1,X2) \
	 do { err_error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_fail_pt
#define err_error_return0_if_fail_pt(A1,X1) \
	 do { err_error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_fail_pts
#define err_error_return0_if_fail_pts(A1,X1,X2) \
	 do { err_error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_null
#define err_error_return0_if_null(A1) \
	 do { err_error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",;;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_null_pC
#define err_error_return0_if_null_pC(A1,X1) \
	 do { err_error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",X1;;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_null_pi
#define err_error_return0_if_null_pi(A1,X1) \
	 do { err_error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_null_pii
#define err_error_return0_if_null_pii(A1,X1,X2) \
	 do { err_error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_null_piit
#define err_error_return0_if_null_piit(A1,X1,X2,X3) \
	 do { err_error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_null_pit
#define err_error_return0_if_null_pit(A1,X1,X2) \
	 do { err_error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_null_pt
#define err_error_return0_if_null_pt(A1,X1) \
	 do { err_error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_null_pts
#define err_error_return0_if_null_pts(A1,X1,X2) \
	 do { err_error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_out_of_bounds
#define err_error_return0_if_out_of_bounds(A1,M) \
	 do { err_error_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_out_of_bounds_pC
#define err_error_return0_if_out_of_bounds_pC(A1,M,X1) \
	 do { err_error_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));X1;;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_out_of_bounds_pi
#define err_error_return0_if_out_of_bounds_pi(A1,M,X1) \
	 do { err_error_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_out_of_bounds_pii
#define err_error_return0_if_out_of_bounds_pii(A1,M,X1,X2) \
	 do { err_error_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_out_of_bounds_piit
#define err_error_return0_if_out_of_bounds_piit(A1,M,X1,X2,X3) \
	 do { err_error_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_out_of_bounds_pit
#define err_error_return0_if_out_of_bounds_pit(A1,M,X1,X2) \
	 do { err_error_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_out_of_bounds_pt
#define err_error_return0_if_out_of_bounds_pt(A1,M,X1) \
	 do { err_error_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_out_of_bounds_pts
#define err_error_return0_if_out_of_bounds_pts(A1,M,X1,X2) \
	 do { err_error_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_reached
#define err_error_return0_if_reached() \
	 do { err_error_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_reached_pC
#define err_error_return0_if_reached_pC(X1) \
	 do { err_error_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");X1;;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_reached_pi
#define err_error_return0_if_reached_pi(X1) \
	 do { err_error_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_reached_pii
#define err_error_return0_if_reached_pii(X1,X2) \
	 do { err_error_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_reached_piit
#define err_error_return0_if_reached_piit(X1,X2,X3) \
	 do { err_error_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_reached_pit
#define err_error_return0_if_reached_pit(X1,X2) \
	 do { err_error_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_reached_pt
#define err_error_return0_if_reached_pt(X1) \
	 do { err_error_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_error_return0_if_reached_pts
#define err_error_return0_if_reached_pts(X1,X2) \
	 do { err_error_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_exit1_if_fail
#define err_exit1_if_fail(A1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",;;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_fail_pC
#define err_exit1_if_fail_pC(A1,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",X1;;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_fail_pi
#define err_exit1_if_fail_pi(A1,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_fail_pii
#define err_exit1_if_fail_pii(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_fail_piit
#define err_exit1_if_fail_piit(A1,X1,X2,X3) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_fail_pit
#define err_exit1_if_fail_pit(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_fail_pt
#define err_exit1_if_fail_pt(A1,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_fail_pts
#define err_exit1_if_fail_pts(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_null
#define err_exit1_if_null(A1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",;;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_null_pC
#define err_exit1_if_null_pC(A1,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",X1;;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_null_pi
#define err_exit1_if_null_pi(A1,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_null_pii
#define err_exit1_if_null_pii(A1,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_null_piit
#define err_exit1_if_null_piit(A1,X1,X2,X3) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_null_pit
#define err_exit1_if_null_pit(A1,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_null_pt
#define err_exit1_if_null_pt(A1,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_null_pts
#define err_exit1_if_null_pts(A1,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_out_of_bounds
#define err_exit1_if_out_of_bounds(A1,M) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_out_of_bounds_pC
#define err_exit1_if_out_of_bounds_pC(A1,M,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));X1;;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_out_of_bounds_pi
#define err_exit1_if_out_of_bounds_pi(A1,M,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_out_of_bounds_pii
#define err_exit1_if_out_of_bounds_pii(A1,M,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_out_of_bounds_piit
#define err_exit1_if_out_of_bounds_piit(A1,M,X1,X2,X3) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_out_of_bounds_pit
#define err_exit1_if_out_of_bounds_pit(A1,M,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_out_of_bounds_pt
#define err_exit1_if_out_of_bounds_pt(A1,M,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_out_of_bounds_pts
#define err_exit1_if_out_of_bounds_pts(A1,M,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_reached
#define err_exit1_if_reached() \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_reached_pC
#define err_exit1_if_reached_pC(X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");X1;;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_reached_pi
#define err_exit1_if_reached_pi(X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_reached_pii
#define err_exit1_if_reached_pii(X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_reached_piit
#define err_exit1_if_reached_piit(X1,X2,X3) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_reached_pit
#define err_exit1_if_reached_pit(X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_reached_pt
#define err_exit1_if_reached_pt(X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit1_if_reached_pts
#define err_exit1_if_reached_pts(X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef err_exit_if_fail
#define err_exit_if_fail(A1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",;;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_fail_pC
#define err_exit_if_fail_pC(A1,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",X1;;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_fail_pi
#define err_exit_if_fail_pi(A1,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_fail_pii
#define err_exit_if_fail_pii(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_fail_piit
#define err_exit_if_fail_piit(A1,X1,X2,X3) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_fail_pit
#define err_exit_if_fail_pit(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_fail_pt
#define err_exit_if_fail_pt(A1,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_fail_pts
#define err_exit_if_fail_pts(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_null
#define err_exit_if_null(A1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",;;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_null_pC
#define err_exit_if_null_pC(A1,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",X1;;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_null_pi
#define err_exit_if_null_pi(A1,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_null_pii
#define err_exit_if_null_pii(A1,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_null_piit
#define err_exit_if_null_piit(A1,X1,X2,X3) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_null_pit
#define err_exit_if_null_pit(A1,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_null_pt
#define err_exit_if_null_pt(A1,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_null_pts
#define err_exit_if_null_pts(A1,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_out_of_bounds
#define err_exit_if_out_of_bounds(A1,M) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_out_of_bounds_pC
#define err_exit_if_out_of_bounds_pC(A1,M,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));X1;;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_out_of_bounds_pi
#define err_exit_if_out_of_bounds_pi(A1,M,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_out_of_bounds_pii
#define err_exit_if_out_of_bounds_pii(A1,M,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_out_of_bounds_piit
#define err_exit_if_out_of_bounds_piit(A1,M,X1,X2,X3) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_out_of_bounds_pit
#define err_exit_if_out_of_bounds_pit(A1,M,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_out_of_bounds_pt
#define err_exit_if_out_of_bounds_pt(A1,M,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_out_of_bounds_pts
#define err_exit_if_out_of_bounds_pts(A1,M,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_reached
#define err_exit_if_reached() \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_reached_pC
#define err_exit_if_reached_pC(X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");X1;;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_reached_pi
#define err_exit_if_reached_pi(X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_reached_pii
#define err_exit_if_reached_pii(X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_reached_piit
#define err_exit_if_reached_piit(X1,X2,X3) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_reached_pit
#define err_exit_if_reached_pit(X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_reached_pt
#define err_exit_if_reached_pt(X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_exit_if_reached_pts
#define err_exit_if_reached_pts(X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;ERR_ASSERT_ABORT;;); } while (0) 
#endif

#ifndef err_nothing_if_fail
#define err_nothing_if_fail(A1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",;;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_fail_pC
#define err_nothing_if_fail_pC(A1,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",X1;;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_fail_pi
#define err_nothing_if_fail_pi(A1,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_fail_pii
#define err_nothing_if_fail_pii(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_fail_piit
#define err_nothing_if_fail_piit(A1,X1,X2,X3) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_fail_pit
#define err_nothing_if_fail_pit(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_fail_pt
#define err_nothing_if_fail_pt(A1,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_fail_pts
#define err_nothing_if_fail_pts(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_null
#define err_nothing_if_null(A1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",;;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_null_pC
#define err_nothing_if_null_pC(A1,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",X1;;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_null_pi
#define err_nothing_if_null_pi(A1,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_null_pii
#define err_nothing_if_null_pii(A1,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_null_piit
#define err_nothing_if_null_piit(A1,X1,X2,X3) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_null_pit
#define err_nothing_if_null_pit(A1,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_null_pt
#define err_nothing_if_null_pt(A1,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_null_pts
#define err_nothing_if_null_pts(A1,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_out_of_bounds
#define err_nothing_if_out_of_bounds(A1,M) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_out_of_bounds_pC
#define err_nothing_if_out_of_bounds_pC(A1,M,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));X1;;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_out_of_bounds_pi
#define err_nothing_if_out_of_bounds_pi(A1,M,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_out_of_bounds_pii
#define err_nothing_if_out_of_bounds_pii(A1,M,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_out_of_bounds_piit
#define err_nothing_if_out_of_bounds_piit(A1,M,X1,X2,X3) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_out_of_bounds_pit
#define err_nothing_if_out_of_bounds_pit(A1,M,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_out_of_bounds_pt
#define err_nothing_if_out_of_bounds_pt(A1,M,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_out_of_bounds_pts
#define err_nothing_if_out_of_bounds_pts(A1,M,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_reached
#define err_nothing_if_reached() \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_reached_pC
#define err_nothing_if_reached_pC(X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");X1;;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_reached_pi
#define err_nothing_if_reached_pi(X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_reached_pii
#define err_nothing_if_reached_pii(X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_reached_piit
#define err_nothing_if_reached_piit(X1,X2,X3) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_reached_pit
#define err_nothing_if_reached_pit(X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_reached_pt
#define err_nothing_if_reached_pt(X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_nothing_if_reached_pts
#define err_nothing_if_reached_pts(X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;;;); } while (0) 
#endif

#ifndef err_return0_if_fail
#define err_return0_if_fail(A1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",;;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_fail_pC
#define err_return0_if_fail_pC(A1,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",X1;;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_fail_pi
#define err_return0_if_fail_pi(A1,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_fail_pii
#define err_return0_if_fail_pii(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_fail_piit
#define err_return0_if_fail_piit(A1,X1,X2,X3) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_fail_pit
#define err_return0_if_fail_pit(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_fail_pt
#define err_return0_if_fail_pt(A1,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_fail_pts
#define err_return0_if_fail_pts(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_fail_pxx
#define err_return0_if_fail_pxx(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=0x%lx\n", (unsigned long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=0x%lx\n", (unsigned long)(X2));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_null
#define err_return0_if_null(A1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",;;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_null2
#define err_return0_if_null2(A1,A2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",;;,ERR_ASSERT_END;return 0;;); \
	err_do_if_fail((A2) != NULL,(A2) != NULL,"("#A2") != NULL","Assertion",;;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_null_pC
#define err_return0_if_null_pC(A1,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",X1;;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_null_pi
#define err_return0_if_null_pi(A1,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_null_pii
#define err_return0_if_null_pii(A1,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_null_piit
#define err_return0_if_null_piit(A1,X1,X2,X3) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_null_pit
#define err_return0_if_null_pit(A1,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_null_pt
#define err_return0_if_null_pt(A1,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_null_pts
#define err_return0_if_null_pts(A1,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_out_of_bounds
#define err_return0_if_out_of_bounds(A1,M) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_out_of_bounds_pC
#define err_return0_if_out_of_bounds_pC(A1,M,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));X1;;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_out_of_bounds_pi
#define err_return0_if_out_of_bounds_pi(A1,M,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_out_of_bounds_pii
#define err_return0_if_out_of_bounds_pii(A1,M,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_out_of_bounds_piit
#define err_return0_if_out_of_bounds_piit(A1,M,X1,X2,X3) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_out_of_bounds_pit
#define err_return0_if_out_of_bounds_pit(A1,M,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_out_of_bounds_pt
#define err_return0_if_out_of_bounds_pt(A1,M,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_out_of_bounds_pts
#define err_return0_if_out_of_bounds_pts(A1,M,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_reached
#define err_return0_if_reached() \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_reached_pC
#define err_return0_if_reached_pC(X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");X1;;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_reached_pi
#define err_return0_if_reached_pi(X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_reached_pii
#define err_return0_if_reached_pii(X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_reached_piit
#define err_return0_if_reached_piit(X1,X2,X3) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_reached_pit
#define err_return0_if_reached_pit(X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_reached_pt
#define err_return0_if_reached_pt(X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_reached_pts
#define err_return0_if_reached_pts(X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return0_if_reached_px
#define err_return0_if_reached_px(X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=0x%lx\n", (unsigned long)(X1));;,ERR_ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef err_return1_if_fail
#define err_return1_if_fail(A1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",;;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_fail_pC
#define err_return1_if_fail_pC(A1,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",X1;;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_fail_pi
#define err_return1_if_fail_pi(A1,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_fail_pii
#define err_return1_if_fail_pii(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_fail_piit
#define err_return1_if_fail_piit(A1,X1,X2,X3) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_fail_pit
#define err_return1_if_fail_pit(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_fail_pt
#define err_return1_if_fail_pt(A1,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_fail_pts
#define err_return1_if_fail_pts(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_null
#define err_return1_if_null(A1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",;;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_null_pC
#define err_return1_if_null_pC(A1,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",X1;;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_null_pi
#define err_return1_if_null_pi(A1,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_null_pii
#define err_return1_if_null_pii(A1,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_null_piit
#define err_return1_if_null_piit(A1,X1,X2,X3) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_null_pit
#define err_return1_if_null_pit(A1,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_null_pt
#define err_return1_if_null_pt(A1,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_null_pts
#define err_return1_if_null_pts(A1,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_out_of_bounds
#define err_return1_if_out_of_bounds(A1,M) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_out_of_bounds_pC
#define err_return1_if_out_of_bounds_pC(A1,M,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));X1;;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_out_of_bounds_pi
#define err_return1_if_out_of_bounds_pi(A1,M,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_out_of_bounds_pii
#define err_return1_if_out_of_bounds_pii(A1,M,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_out_of_bounds_piit
#define err_return1_if_out_of_bounds_piit(A1,M,X1,X2,X3) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_out_of_bounds_pit
#define err_return1_if_out_of_bounds_pit(A1,M,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_out_of_bounds_pt
#define err_return1_if_out_of_bounds_pt(A1,M,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_out_of_bounds_pts
#define err_return1_if_out_of_bounds_pts(A1,M,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_reached
#define err_return1_if_reached() \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_reached_pC
#define err_return1_if_reached_pC(X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");X1;;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_reached_pi
#define err_return1_if_reached_pi(X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_reached_pii
#define err_return1_if_reached_pii(X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_reached_piit
#define err_return1_if_reached_piit(X1,X2,X3) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_reached_pit
#define err_return1_if_reached_pit(X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_reached_pt
#define err_return1_if_reached_pt(X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return1_if_reached_pts
#define err_return1_if_reached_pts(X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef err_return_if_fail
#define err_return_if_fail(A1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",;;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_fail_pC
#define err_return_if_fail_pC(A1,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",X1;;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_fail_pi
#define err_return_if_fail_pi(A1,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_fail_pii
#define err_return_if_fail_pii(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_fail_piit
#define err_return_if_fail_piit(A1,X1,X2,X3) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_fail_pit
#define err_return_if_fail_pit(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_fail_pt
#define err_return_if_fail_pt(A1,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_fail_pts
#define err_return_if_fail_pts(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_fail_pxx
#define err_return_if_fail_pxx(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=0x%lx\n", (unsigned long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=0x%lx\n", (unsigned long)(X2));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_null
#define err_return_if_null(A1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",;;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_null2
#define err_return_if_null2(A1,A2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",;;,ERR_ASSERT_END;return;;); \
	err_do_if_fail((A2) != NULL,(A2) != NULL,"("#A2") != NULL","Assertion",;;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_null2i
#define err_return_if_null2i(A1,A2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",;;,ERR_ASSERT_END;return;;); \
	err_do_if_fail((A1->A2) != NULL,(A1->A2) != NULL,"("#A1"->"#A2") != NULL","Assertion",;;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_null_pC
#define err_return_if_null_pC(A1,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",X1;;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_null_pi
#define err_return_if_null_pi(A1,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_null_pii
#define err_return_if_null_pii(A1,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_null_piit
#define err_return_if_null_piit(A1,X1,X2,X3) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_null_pit
#define err_return_if_null_pit(A1,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_null_pt
#define err_return_if_null_pt(A1,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_null_pts
#define err_return_if_null_pts(A1,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_out_of_bounds
#define err_return_if_out_of_bounds(A1,M) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_out_of_bounds_pC
#define err_return_if_out_of_bounds_pC(A1,M,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));X1;;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_out_of_bounds_pi
#define err_return_if_out_of_bounds_pi(A1,M,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_out_of_bounds_pii
#define err_return_if_out_of_bounds_pii(A1,M,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_out_of_bounds_piit
#define err_return_if_out_of_bounds_piit(A1,M,X1,X2,X3) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_out_of_bounds_pit
#define err_return_if_out_of_bounds_pit(A1,M,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_out_of_bounds_pt
#define err_return_if_out_of_bounds_pt(A1,M,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_out_of_bounds_pts
#define err_return_if_out_of_bounds_pts(A1,M,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_reached
#define err_return_if_reached() \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_reached_pC
#define err_return_if_reached_pC(X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");X1;;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_reached_pi
#define err_return_if_reached_pi(X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_reached_pii
#define err_return_if_reached_pii(X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_reached_piit
#define err_return_if_reached_piit(X1,X2,X3) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_reached_pit
#define err_return_if_reached_pit(X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_reached_pt
#define err_return_if_reached_pt(X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_if_reached_pts
#define err_return_if_reached_pts(X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return;;); } while (0) 
#endif

#ifndef err_return_m1_if_fail
#define err_return_m1_if_fail(A1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",;;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_fail_pC
#define err_return_m1_if_fail_pC(A1,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",X1;;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_fail_pi
#define err_return_m1_if_fail_pi(A1,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_fail_pii
#define err_return_m1_if_fail_pii(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_fail_piit
#define err_return_m1_if_fail_piit(A1,X1,X2,X3) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_fail_pit
#define err_return_m1_if_fail_pit(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_fail_pt
#define err_return_m1_if_fail_pt(A1,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_fail_pts
#define err_return_m1_if_fail_pts(A1,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_null
#define err_return_m1_if_null(A1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",;;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_null_pC
#define err_return_m1_if_null_pC(A1,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",X1;;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_null_pi
#define err_return_m1_if_null_pi(A1,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_null_pii
#define err_return_m1_if_null_pii(A1,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_null_piit
#define err_return_m1_if_null_piit(A1,X1,X2,X3) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_null_pit
#define err_return_m1_if_null_pit(A1,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_null_pt
#define err_return_m1_if_null_pt(A1,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_null_pts
#define err_return_m1_if_null_pts(A1,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_out_of_bounds
#define err_return_m1_if_out_of_bounds(A1,M) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_out_of_bounds_pC
#define err_return_m1_if_out_of_bounds_pC(A1,M,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));X1;;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_out_of_bounds_pi
#define err_return_m1_if_out_of_bounds_pi(A1,M,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_out_of_bounds_pii
#define err_return_m1_if_out_of_bounds_pii(A1,M,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_out_of_bounds_piit
#define err_return_m1_if_out_of_bounds_piit(A1,M,X1,X2,X3) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_out_of_bounds_pit
#define err_return_m1_if_out_of_bounds_pit(A1,M,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_out_of_bounds_pt
#define err_return_m1_if_out_of_bounds_pt(A1,M,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_out_of_bounds_pts
#define err_return_m1_if_out_of_bounds_pts(A1,M,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_reached
#define err_return_m1_if_reached() \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_reached_pC
#define err_return_m1_if_reached_pC(X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");X1;;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_reached_pi
#define err_return_m1_if_reached_pi(X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_reached_pii
#define err_return_m1_if_reached_pii(X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_reached_piit
#define err_return_m1_if_reached_piit(X1,X2,X3) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_reached_pit
#define err_return_m1_if_reached_pit(X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_reached_pt
#define err_return_m1_if_reached_pt(X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_m1_if_reached_pts
#define err_return_m1_if_reached_pts(X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef err_return_val_if_fail
#define err_return_val_if_fail(A1,O) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",;;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_fail_pC
#define err_return_val_if_fail_pC(A1,O,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",X1;;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_fail_pi
#define err_return_val_if_fail_pi(A1,O,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_fail_pii
#define err_return_val_if_fail_pii(A1,O,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_fail_piit
#define err_return_val_if_fail_piit(A1,O,X1,X2,X3) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_fail_pit
#define err_return_val_if_fail_pit(A1,O,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_fail_pt
#define err_return_val_if_fail_pt(A1,O,X1) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_fail_pts
#define err_return_val_if_fail_pts(A1,O,X1,X2) \
	 do { err_do_if_fail(A1,A1,""#A1,"Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_null
#define err_return_val_if_null(A1,O) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",;;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_null_pC
#define err_return_val_if_null_pC(A1,O,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",X1;;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_null_pi
#define err_return_val_if_null_pi(A1,O,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_null_pii
#define err_return_val_if_null_pii(A1,O,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_null_piit
#define err_return_val_if_null_piit(A1,O,X1,X2,X3) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_null_pit
#define err_return_val_if_null_pit(A1,O,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_null_pt
#define err_return_val_if_null_pt(A1,O,X1) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_null_pts
#define err_return_val_if_null_pts(A1,O,X1,X2) \
	 do { err_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_out_of_bounds
#define err_return_val_if_out_of_bounds(A1,M,O) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_out_of_bounds_pC
#define err_return_val_if_out_of_bounds_pC(A1,M,O,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));X1;;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_out_of_bounds_pi
#define err_return_val_if_out_of_bounds_pi(A1,M,O,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_out_of_bounds_pii
#define err_return_val_if_out_of_bounds_pii(A1,M,O,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_out_of_bounds_piit
#define err_return_val_if_out_of_bounds_piit(A1,M,O,X1,X2,X3) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_out_of_bounds_pit
#define err_return_val_if_out_of_bounds_pit(A1,M,O,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_out_of_bounds_pt
#define err_return_val_if_out_of_bounds_pt(A1,M,O,X1) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_out_of_bounds_pts
#define err_return_val_if_out_of_bounds_pts(A1,M,O,X1,X2) \
	 do { err_do_if_fail(ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ERR_ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ERR_ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ERR_ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ERR_ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_reached
#define err_return_val_if_reached(O) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_reached_pC
#define err_return_val_if_reached_pC(O,X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");X1;;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_reached_pi
#define err_return_val_if_reached_pi(O,X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_reached_pii
#define err_return_val_if_reached_pii(O,X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_reached_piit
#define err_return_val_if_reached_piit(O,X1,X2,X3) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_reached_pit
#define err_return_val_if_reached_pit(O,X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_reached_pt
#define err_return_val_if_reached_pt(O,X1) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef err_return_val_if_reached_pts
#define err_return_val_if_reached_pts(O,X1,X2) \
	 do { err_do_if_fail(0,0,"""0","Control flow",ERR_ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ERR_ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ERR_ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ERR_ASSERT_END;return (O);;); } while (0) 
#endif


#else /* !defined(ERR_ASSERT_IS_BROKEN) */

#ifndef err_error_exit_if_fail
#define err_error_exit_if_fail(A1)
#endif

#ifndef err_error_exit_if_fail_pC
#define err_error_exit_if_fail_pC(A1,X1)
#endif

#ifndef err_error_exit_if_fail_pi
#define err_error_exit_if_fail_pi(A1,X1)
#endif

#ifndef err_error_exit_if_fail_pii
#define err_error_exit_if_fail_pii(A1,X1,X2)
#endif

#ifndef err_error_exit_if_fail_piit
#define err_error_exit_if_fail_piit(A1,X1,X2,X3)
#endif

#ifndef err_error_exit_if_fail_pit
#define err_error_exit_if_fail_pit(A1,X1,X2)
#endif

#ifndef err_error_exit_if_fail_pt
#define err_error_exit_if_fail_pt(A1,X1)
#endif

#ifndef err_error_exit_if_fail_pts
#define err_error_exit_if_fail_pts(A1,X1,X2)
#endif

#ifndef err_error_exit_if_null
#define err_error_exit_if_null(A1)
#endif

#ifndef err_error_exit_if_null_pC
#define err_error_exit_if_null_pC(A1,X1)
#endif

#ifndef err_error_exit_if_null_pi
#define err_error_exit_if_null_pi(A1,X1)
#endif

#ifndef err_error_exit_if_null_pii
#define err_error_exit_if_null_pii(A1,X1,X2)
#endif

#ifndef err_error_exit_if_null_piit
#define err_error_exit_if_null_piit(A1,X1,X2,X3)
#endif

#ifndef err_error_exit_if_null_pit
#define err_error_exit_if_null_pit(A1,X1,X2)
#endif

#ifndef err_error_exit_if_null_pt
#define err_error_exit_if_null_pt(A1,X1)
#endif

#ifndef err_error_exit_if_null_pts
#define err_error_exit_if_null_pts(A1,X1,X2)
#endif

#ifndef err_error_exit_if_out_of_bounds
#define err_error_exit_if_out_of_bounds(A1,M)
#endif

#ifndef err_error_exit_if_out_of_bounds_pC
#define err_error_exit_if_out_of_bounds_pC(A1,M,X1)
#endif

#ifndef err_error_exit_if_out_of_bounds_pi
#define err_error_exit_if_out_of_bounds_pi(A1,M,X1)
#endif

#ifndef err_error_exit_if_out_of_bounds_pii
#define err_error_exit_if_out_of_bounds_pii(A1,M,X1,X2)
#endif

#ifndef err_error_exit_if_out_of_bounds_piit
#define err_error_exit_if_out_of_bounds_piit(A1,M,X1,X2,X3)
#endif

#ifndef err_error_exit_if_out_of_bounds_pit
#define err_error_exit_if_out_of_bounds_pit(A1,M,X1,X2)
#endif

#ifndef err_error_exit_if_out_of_bounds_pt
#define err_error_exit_if_out_of_bounds_pt(A1,M,X1)
#endif

#ifndef err_error_exit_if_out_of_bounds_pts
#define err_error_exit_if_out_of_bounds_pts(A1,M,X1,X2)
#endif

#ifndef err_error_exit_if_reached
#define err_error_exit_if_reached()
#endif

#ifndef err_error_exit_if_reached_pC
#define err_error_exit_if_reached_pC(X1)
#endif

#ifndef err_error_exit_if_reached_pi
#define err_error_exit_if_reached_pi(X1)
#endif

#ifndef err_error_exit_if_reached_pii
#define err_error_exit_if_reached_pii(X1,X2)
#endif

#ifndef err_error_exit_if_reached_piit
#define err_error_exit_if_reached_piit(X1,X2,X3)
#endif

#ifndef err_error_exit_if_reached_pit
#define err_error_exit_if_reached_pit(X1,X2)
#endif

#ifndef err_error_exit_if_reached_pt
#define err_error_exit_if_reached_pt(X1)
#endif

#ifndef err_error_exit_if_reached_pts
#define err_error_exit_if_reached_pts(X1,X2)
#endif

#ifndef err_error_return0_if_fail
#define err_error_return0_if_fail(A1)
#endif

#ifndef err_error_return0_if_fail_pC
#define err_error_return0_if_fail_pC(A1,X1)
#endif

#ifndef err_error_return0_if_fail_pi
#define err_error_return0_if_fail_pi(A1,X1)
#endif

#ifndef err_error_return0_if_fail_pii
#define err_error_return0_if_fail_pii(A1,X1,X2)
#endif

#ifndef err_error_return0_if_fail_piit
#define err_error_return0_if_fail_piit(A1,X1,X2,X3)
#endif

#ifndef err_error_return0_if_fail_pit
#define err_error_return0_if_fail_pit(A1,X1,X2)
#endif

#ifndef err_error_return0_if_fail_pt
#define err_error_return0_if_fail_pt(A1,X1)
#endif

#ifndef err_error_return0_if_fail_pts
#define err_error_return0_if_fail_pts(A1,X1,X2)
#endif

#ifndef err_error_return0_if_null
#define err_error_return0_if_null(A1)
#endif

#ifndef err_error_return0_if_null_pC
#define err_error_return0_if_null_pC(A1,X1)
#endif

#ifndef err_error_return0_if_null_pi
#define err_error_return0_if_null_pi(A1,X1)
#endif

#ifndef err_error_return0_if_null_pii
#define err_error_return0_if_null_pii(A1,X1,X2)
#endif

#ifndef err_error_return0_if_null_piit
#define err_error_return0_if_null_piit(A1,X1,X2,X3)
#endif

#ifndef err_error_return0_if_null_pit
#define err_error_return0_if_null_pit(A1,X1,X2)
#endif

#ifndef err_error_return0_if_null_pt
#define err_error_return0_if_null_pt(A1,X1)
#endif

#ifndef err_error_return0_if_null_pts
#define err_error_return0_if_null_pts(A1,X1,X2)
#endif

#ifndef err_error_return0_if_out_of_bounds
#define err_error_return0_if_out_of_bounds(A1,M)
#endif

#ifndef err_error_return0_if_out_of_bounds_pC
#define err_error_return0_if_out_of_bounds_pC(A1,M,X1)
#endif

#ifndef err_error_return0_if_out_of_bounds_pi
#define err_error_return0_if_out_of_bounds_pi(A1,M,X1)
#endif

#ifndef err_error_return0_if_out_of_bounds_pii
#define err_error_return0_if_out_of_bounds_pii(A1,M,X1,X2)
#endif

#ifndef err_error_return0_if_out_of_bounds_piit
#define err_error_return0_if_out_of_bounds_piit(A1,M,X1,X2,X3)
#endif

#ifndef err_error_return0_if_out_of_bounds_pit
#define err_error_return0_if_out_of_bounds_pit(A1,M,X1,X2)
#endif

#ifndef err_error_return0_if_out_of_bounds_pt
#define err_error_return0_if_out_of_bounds_pt(A1,M,X1)
#endif

#ifndef err_error_return0_if_out_of_bounds_pts
#define err_error_return0_if_out_of_bounds_pts(A1,M,X1,X2)
#endif

#ifndef err_error_return0_if_reached
#define err_error_return0_if_reached()
#endif

#ifndef err_error_return0_if_reached_pC
#define err_error_return0_if_reached_pC(X1)
#endif

#ifndef err_error_return0_if_reached_pi
#define err_error_return0_if_reached_pi(X1)
#endif

#ifndef err_error_return0_if_reached_pii
#define err_error_return0_if_reached_pii(X1,X2)
#endif

#ifndef err_error_return0_if_reached_piit
#define err_error_return0_if_reached_piit(X1,X2,X3)
#endif

#ifndef err_error_return0_if_reached_pit
#define err_error_return0_if_reached_pit(X1,X2)
#endif

#ifndef err_error_return0_if_reached_pt
#define err_error_return0_if_reached_pt(X1)
#endif

#ifndef err_error_return0_if_reached_pts
#define err_error_return0_if_reached_pts(X1,X2)
#endif

#ifndef err_exit1_if_fail
#define err_exit1_if_fail(A1)
#endif

#ifndef err_exit1_if_fail_pC
#define err_exit1_if_fail_pC(A1,X1)
#endif

#ifndef err_exit1_if_fail_pi
#define err_exit1_if_fail_pi(A1,X1)
#endif

#ifndef err_exit1_if_fail_pii
#define err_exit1_if_fail_pii(A1,X1,X2)
#endif

#ifndef err_exit1_if_fail_piit
#define err_exit1_if_fail_piit(A1,X1,X2,X3)
#endif

#ifndef err_exit1_if_fail_pit
#define err_exit1_if_fail_pit(A1,X1,X2)
#endif

#ifndef err_exit1_if_fail_pt
#define err_exit1_if_fail_pt(A1,X1)
#endif

#ifndef err_exit1_if_fail_pts
#define err_exit1_if_fail_pts(A1,X1,X2)
#endif

#ifndef err_exit1_if_null
#define err_exit1_if_null(A1)
#endif

#ifndef err_exit1_if_null_pC
#define err_exit1_if_null_pC(A1,X1)
#endif

#ifndef err_exit1_if_null_pi
#define err_exit1_if_null_pi(A1,X1)
#endif

#ifndef err_exit1_if_null_pii
#define err_exit1_if_null_pii(A1,X1,X2)
#endif

#ifndef err_exit1_if_null_piit
#define err_exit1_if_null_piit(A1,X1,X2,X3)
#endif

#ifndef err_exit1_if_null_pit
#define err_exit1_if_null_pit(A1,X1,X2)
#endif

#ifndef err_exit1_if_null_pt
#define err_exit1_if_null_pt(A1,X1)
#endif

#ifndef err_exit1_if_null_pts
#define err_exit1_if_null_pts(A1,X1,X2)
#endif

#ifndef err_exit1_if_out_of_bounds
#define err_exit1_if_out_of_bounds(A1,M)
#endif

#ifndef err_exit1_if_out_of_bounds_pC
#define err_exit1_if_out_of_bounds_pC(A1,M,X1)
#endif

#ifndef err_exit1_if_out_of_bounds_pi
#define err_exit1_if_out_of_bounds_pi(A1,M,X1)
#endif

#ifndef err_exit1_if_out_of_bounds_pii
#define err_exit1_if_out_of_bounds_pii(A1,M,X1,X2)
#endif

#ifndef err_exit1_if_out_of_bounds_piit
#define err_exit1_if_out_of_bounds_piit(A1,M,X1,X2,X3)
#endif

#ifndef err_exit1_if_out_of_bounds_pit
#define err_exit1_if_out_of_bounds_pit(A1,M,X1,X2)
#endif

#ifndef err_exit1_if_out_of_bounds_pt
#define err_exit1_if_out_of_bounds_pt(A1,M,X1)
#endif

#ifndef err_exit1_if_out_of_bounds_pts
#define err_exit1_if_out_of_bounds_pts(A1,M,X1,X2)
#endif

#ifndef err_exit1_if_reached
#define err_exit1_if_reached()
#endif

#ifndef err_exit1_if_reached_pC
#define err_exit1_if_reached_pC(X1)
#endif

#ifndef err_exit1_if_reached_pi
#define err_exit1_if_reached_pi(X1)
#endif

#ifndef err_exit1_if_reached_pii
#define err_exit1_if_reached_pii(X1,X2)
#endif

#ifndef err_exit1_if_reached_piit
#define err_exit1_if_reached_piit(X1,X2,X3)
#endif

#ifndef err_exit1_if_reached_pit
#define err_exit1_if_reached_pit(X1,X2)
#endif

#ifndef err_exit1_if_reached_pt
#define err_exit1_if_reached_pt(X1)
#endif

#ifndef err_exit1_if_reached_pts
#define err_exit1_if_reached_pts(X1,X2)
#endif

#ifndef err_exit_if_fail
#define err_exit_if_fail(A1)
#endif

#ifndef err_exit_if_fail_pC
#define err_exit_if_fail_pC(A1,X1)
#endif

#ifndef err_exit_if_fail_pi
#define err_exit_if_fail_pi(A1,X1)
#endif

#ifndef err_exit_if_fail_pii
#define err_exit_if_fail_pii(A1,X1,X2)
#endif

#ifndef err_exit_if_fail_piit
#define err_exit_if_fail_piit(A1,X1,X2,X3)
#endif

#ifndef err_exit_if_fail_pit
#define err_exit_if_fail_pit(A1,X1,X2)
#endif

#ifndef err_exit_if_fail_pt
#define err_exit_if_fail_pt(A1,X1)
#endif

#ifndef err_exit_if_fail_pts
#define err_exit_if_fail_pts(A1,X1,X2)
#endif

#ifndef err_exit_if_null
#define err_exit_if_null(A1)
#endif

#ifndef err_exit_if_null_pC
#define err_exit_if_null_pC(A1,X1)
#endif

#ifndef err_exit_if_null_pi
#define err_exit_if_null_pi(A1,X1)
#endif

#ifndef err_exit_if_null_pii
#define err_exit_if_null_pii(A1,X1,X2)
#endif

#ifndef err_exit_if_null_piit
#define err_exit_if_null_piit(A1,X1,X2,X3)
#endif

#ifndef err_exit_if_null_pit
#define err_exit_if_null_pit(A1,X1,X2)
#endif

#ifndef err_exit_if_null_pt
#define err_exit_if_null_pt(A1,X1)
#endif

#ifndef err_exit_if_null_pts
#define err_exit_if_null_pts(A1,X1,X2)
#endif

#ifndef err_exit_if_out_of_bounds
#define err_exit_if_out_of_bounds(A1,M)
#endif

#ifndef err_exit_if_out_of_bounds_pC
#define err_exit_if_out_of_bounds_pC(A1,M,X1)
#endif

#ifndef err_exit_if_out_of_bounds_pi
#define err_exit_if_out_of_bounds_pi(A1,M,X1)
#endif

#ifndef err_exit_if_out_of_bounds_pii
#define err_exit_if_out_of_bounds_pii(A1,M,X1,X2)
#endif

#ifndef err_exit_if_out_of_bounds_piit
#define err_exit_if_out_of_bounds_piit(A1,M,X1,X2,X3)
#endif

#ifndef err_exit_if_out_of_bounds_pit
#define err_exit_if_out_of_bounds_pit(A1,M,X1,X2)
#endif

#ifndef err_exit_if_out_of_bounds_pt
#define err_exit_if_out_of_bounds_pt(A1,M,X1)
#endif

#ifndef err_exit_if_out_of_bounds_pts
#define err_exit_if_out_of_bounds_pts(A1,M,X1,X2)
#endif

#ifndef err_exit_if_reached
#define err_exit_if_reached()
#endif

#ifndef err_exit_if_reached_pC
#define err_exit_if_reached_pC(X1)
#endif

#ifndef err_exit_if_reached_pi
#define err_exit_if_reached_pi(X1)
#endif

#ifndef err_exit_if_reached_pii
#define err_exit_if_reached_pii(X1,X2)
#endif

#ifndef err_exit_if_reached_piit
#define err_exit_if_reached_piit(X1,X2,X3)
#endif

#ifndef err_exit_if_reached_pit
#define err_exit_if_reached_pit(X1,X2)
#endif

#ifndef err_exit_if_reached_pt
#define err_exit_if_reached_pt(X1)
#endif

#ifndef err_exit_if_reached_pts
#define err_exit_if_reached_pts(X1,X2)
#endif

#ifndef err_nothing_if_fail
#define err_nothing_if_fail(A1)
#endif

#ifndef err_nothing_if_fail_pC
#define err_nothing_if_fail_pC(A1,X1)
#endif

#ifndef err_nothing_if_fail_pi
#define err_nothing_if_fail_pi(A1,X1)
#endif

#ifndef err_nothing_if_fail_pii
#define err_nothing_if_fail_pii(A1,X1,X2)
#endif

#ifndef err_nothing_if_fail_piit
#define err_nothing_if_fail_piit(A1,X1,X2,X3)
#endif

#ifndef err_nothing_if_fail_pit
#define err_nothing_if_fail_pit(A1,X1,X2)
#endif

#ifndef err_nothing_if_fail_pt
#define err_nothing_if_fail_pt(A1,X1)
#endif

#ifndef err_nothing_if_fail_pts
#define err_nothing_if_fail_pts(A1,X1,X2)
#endif

#ifndef err_nothing_if_null
#define err_nothing_if_null(A1)
#endif

#ifndef err_nothing_if_null_pC
#define err_nothing_if_null_pC(A1,X1)
#endif

#ifndef err_nothing_if_null_pi
#define err_nothing_if_null_pi(A1,X1)
#endif

#ifndef err_nothing_if_null_pii
#define err_nothing_if_null_pii(A1,X1,X2)
#endif

#ifndef err_nothing_if_null_piit
#define err_nothing_if_null_piit(A1,X1,X2,X3)
#endif

#ifndef err_nothing_if_null_pit
#define err_nothing_if_null_pit(A1,X1,X2)
#endif

#ifndef err_nothing_if_null_pt
#define err_nothing_if_null_pt(A1,X1)
#endif

#ifndef err_nothing_if_null_pts
#define err_nothing_if_null_pts(A1,X1,X2)
#endif

#ifndef err_nothing_if_out_of_bounds
#define err_nothing_if_out_of_bounds(A1,M)
#endif

#ifndef err_nothing_if_out_of_bounds_pC
#define err_nothing_if_out_of_bounds_pC(A1,M,X1)
#endif

#ifndef err_nothing_if_out_of_bounds_pi
#define err_nothing_if_out_of_bounds_pi(A1,M,X1)
#endif

#ifndef err_nothing_if_out_of_bounds_pii
#define err_nothing_if_out_of_bounds_pii(A1,M,X1,X2)
#endif

#ifndef err_nothing_if_out_of_bounds_piit
#define err_nothing_if_out_of_bounds_piit(A1,M,X1,X2,X3)
#endif

#ifndef err_nothing_if_out_of_bounds_pit
#define err_nothing_if_out_of_bounds_pit(A1,M,X1,X2)
#endif

#ifndef err_nothing_if_out_of_bounds_pt
#define err_nothing_if_out_of_bounds_pt(A1,M,X1)
#endif

#ifndef err_nothing_if_out_of_bounds_pts
#define err_nothing_if_out_of_bounds_pts(A1,M,X1,X2)
#endif

#ifndef err_nothing_if_reached
#define err_nothing_if_reached()
#endif

#ifndef err_nothing_if_reached_pC
#define err_nothing_if_reached_pC(X1)
#endif

#ifndef err_nothing_if_reached_pi
#define err_nothing_if_reached_pi(X1)
#endif

#ifndef err_nothing_if_reached_pii
#define err_nothing_if_reached_pii(X1,X2)
#endif

#ifndef err_nothing_if_reached_piit
#define err_nothing_if_reached_piit(X1,X2,X3)
#endif

#ifndef err_nothing_if_reached_pit
#define err_nothing_if_reached_pit(X1,X2)
#endif

#ifndef err_nothing_if_reached_pt
#define err_nothing_if_reached_pt(X1)
#endif

#ifndef err_nothing_if_reached_pts
#define err_nothing_if_reached_pts(X1,X2)
#endif

#ifndef err_return0_if_fail
#define err_return0_if_fail(A1)
#endif

#ifndef err_return0_if_fail_pC
#define err_return0_if_fail_pC(A1,X1)
#endif

#ifndef err_return0_if_fail_pi
#define err_return0_if_fail_pi(A1,X1)
#endif

#ifndef err_return0_if_fail_pii
#define err_return0_if_fail_pii(A1,X1,X2)
#endif

#ifndef err_return0_if_fail_piit
#define err_return0_if_fail_piit(A1,X1,X2,X3)
#endif

#ifndef err_return0_if_fail_pit
#define err_return0_if_fail_pit(A1,X1,X2)
#endif

#ifndef err_return0_if_fail_pt
#define err_return0_if_fail_pt(A1,X1)
#endif

#ifndef err_return0_if_fail_pts
#define err_return0_if_fail_pts(A1,X1,X2)
#endif

#ifndef err_return0_if_fail_pxx
#define err_return0_if_fail_pxx(A1,X1,X2)
#endif

#ifndef err_return0_if_null
#define err_return0_if_null(A1)
#endif

#ifndef err_return0_if_null2
#define err_return0_if_null2(A1,A2)
#endif

#ifndef err_return0_if_null_pC
#define err_return0_if_null_pC(A1,X1)
#endif

#ifndef err_return0_if_null_pi
#define err_return0_if_null_pi(A1,X1)
#endif

#ifndef err_return0_if_null_pii
#define err_return0_if_null_pii(A1,X1,X2)
#endif

#ifndef err_return0_if_null_piit
#define err_return0_if_null_piit(A1,X1,X2,X3)
#endif

#ifndef err_return0_if_null_pit
#define err_return0_if_null_pit(A1,X1,X2)
#endif

#ifndef err_return0_if_null_pt
#define err_return0_if_null_pt(A1,X1)
#endif

#ifndef err_return0_if_null_pts
#define err_return0_if_null_pts(A1,X1,X2)
#endif

#ifndef err_return0_if_out_of_bounds
#define err_return0_if_out_of_bounds(A1,M)
#endif

#ifndef err_return0_if_out_of_bounds_pC
#define err_return0_if_out_of_bounds_pC(A1,M,X1)
#endif

#ifndef err_return0_if_out_of_bounds_pi
#define err_return0_if_out_of_bounds_pi(A1,M,X1)
#endif

#ifndef err_return0_if_out_of_bounds_pii
#define err_return0_if_out_of_bounds_pii(A1,M,X1,X2)
#endif

#ifndef err_return0_if_out_of_bounds_piit
#define err_return0_if_out_of_bounds_piit(A1,M,X1,X2,X3)
#endif

#ifndef err_return0_if_out_of_bounds_pit
#define err_return0_if_out_of_bounds_pit(A1,M,X1,X2)
#endif

#ifndef err_return0_if_out_of_bounds_pt
#define err_return0_if_out_of_bounds_pt(A1,M,X1)
#endif

#ifndef err_return0_if_out_of_bounds_pts
#define err_return0_if_out_of_bounds_pts(A1,M,X1,X2)
#endif

#ifndef err_return0_if_reached
#define err_return0_if_reached()
#endif

#ifndef err_return0_if_reached_pC
#define err_return0_if_reached_pC(X1)
#endif

#ifndef err_return0_if_reached_pi
#define err_return0_if_reached_pi(X1)
#endif

#ifndef err_return0_if_reached_pii
#define err_return0_if_reached_pii(X1,X2)
#endif

#ifndef err_return0_if_reached_piit
#define err_return0_if_reached_piit(X1,X2,X3)
#endif

#ifndef err_return0_if_reached_pit
#define err_return0_if_reached_pit(X1,X2)
#endif

#ifndef err_return0_if_reached_pt
#define err_return0_if_reached_pt(X1)
#endif

#ifndef err_return0_if_reached_pts
#define err_return0_if_reached_pts(X1,X2)
#endif

#ifndef err_return0_if_reached_px
#define err_return0_if_reached_px(X1)
#endif

#ifndef err_return1_if_fail
#define err_return1_if_fail(A1)
#endif

#ifndef err_return1_if_fail_pC
#define err_return1_if_fail_pC(A1,X1)
#endif

#ifndef err_return1_if_fail_pi
#define err_return1_if_fail_pi(A1,X1)
#endif

#ifndef err_return1_if_fail_pii
#define err_return1_if_fail_pii(A1,X1,X2)
#endif

#ifndef err_return1_if_fail_piit
#define err_return1_if_fail_piit(A1,X1,X2,X3)
#endif

#ifndef err_return1_if_fail_pit
#define err_return1_if_fail_pit(A1,X1,X2)
#endif

#ifndef err_return1_if_fail_pt
#define err_return1_if_fail_pt(A1,X1)
#endif

#ifndef err_return1_if_fail_pts
#define err_return1_if_fail_pts(A1,X1,X2)
#endif

#ifndef err_return1_if_null
#define err_return1_if_null(A1)
#endif

#ifndef err_return1_if_null_pC
#define err_return1_if_null_pC(A1,X1)
#endif

#ifndef err_return1_if_null_pi
#define err_return1_if_null_pi(A1,X1)
#endif

#ifndef err_return1_if_null_pii
#define err_return1_if_null_pii(A1,X1,X2)
#endif

#ifndef err_return1_if_null_piit
#define err_return1_if_null_piit(A1,X1,X2,X3)
#endif

#ifndef err_return1_if_null_pit
#define err_return1_if_null_pit(A1,X1,X2)
#endif

#ifndef err_return1_if_null_pt
#define err_return1_if_null_pt(A1,X1)
#endif

#ifndef err_return1_if_null_pts
#define err_return1_if_null_pts(A1,X1,X2)
#endif

#ifndef err_return1_if_out_of_bounds
#define err_return1_if_out_of_bounds(A1,M)
#endif

#ifndef err_return1_if_out_of_bounds_pC
#define err_return1_if_out_of_bounds_pC(A1,M,X1)
#endif

#ifndef err_return1_if_out_of_bounds_pi
#define err_return1_if_out_of_bounds_pi(A1,M,X1)
#endif

#ifndef err_return1_if_out_of_bounds_pii
#define err_return1_if_out_of_bounds_pii(A1,M,X1,X2)
#endif

#ifndef err_return1_if_out_of_bounds_piit
#define err_return1_if_out_of_bounds_piit(A1,M,X1,X2,X3)
#endif

#ifndef err_return1_if_out_of_bounds_pit
#define err_return1_if_out_of_bounds_pit(A1,M,X1,X2)
#endif

#ifndef err_return1_if_out_of_bounds_pt
#define err_return1_if_out_of_bounds_pt(A1,M,X1)
#endif

#ifndef err_return1_if_out_of_bounds_pts
#define err_return1_if_out_of_bounds_pts(A1,M,X1,X2)
#endif

#ifndef err_return1_if_reached
#define err_return1_if_reached()
#endif

#ifndef err_return1_if_reached_pC
#define err_return1_if_reached_pC(X1)
#endif

#ifndef err_return1_if_reached_pi
#define err_return1_if_reached_pi(X1)
#endif

#ifndef err_return1_if_reached_pii
#define err_return1_if_reached_pii(X1,X2)
#endif

#ifndef err_return1_if_reached_piit
#define err_return1_if_reached_piit(X1,X2,X3)
#endif

#ifndef err_return1_if_reached_pit
#define err_return1_if_reached_pit(X1,X2)
#endif

#ifndef err_return1_if_reached_pt
#define err_return1_if_reached_pt(X1)
#endif

#ifndef err_return1_if_reached_pts
#define err_return1_if_reached_pts(X1,X2)
#endif

#ifndef err_return_if_fail
#define err_return_if_fail(A1)
#endif

#ifndef err_return_if_fail_pC
#define err_return_if_fail_pC(A1,X1)
#endif

#ifndef err_return_if_fail_pi
#define err_return_if_fail_pi(A1,X1)
#endif

#ifndef err_return_if_fail_pii
#define err_return_if_fail_pii(A1,X1,X2)
#endif

#ifndef err_return_if_fail_piit
#define err_return_if_fail_piit(A1,X1,X2,X3)
#endif

#ifndef err_return_if_fail_pit
#define err_return_if_fail_pit(A1,X1,X2)
#endif

#ifndef err_return_if_fail_pt
#define err_return_if_fail_pt(A1,X1)
#endif

#ifndef err_return_if_fail_pts
#define err_return_if_fail_pts(A1,X1,X2)
#endif

#ifndef err_return_if_fail_pxx
#define err_return_if_fail_pxx(A1,X1,X2)
#endif

#ifndef err_return_if_null
#define err_return_if_null(A1)
#endif

#ifndef err_return_if_null2
#define err_return_if_null2(A1,A2)
#endif

#ifndef err_return_if_null2i
#define err_return_if_null2i(A1,A2)
#endif

#ifndef err_return_if_null_pC
#define err_return_if_null_pC(A1,X1)
#endif

#ifndef err_return_if_null_pi
#define err_return_if_null_pi(A1,X1)
#endif

#ifndef err_return_if_null_pii
#define err_return_if_null_pii(A1,X1,X2)
#endif

#ifndef err_return_if_null_piit
#define err_return_if_null_piit(A1,X1,X2,X3)
#endif

#ifndef err_return_if_null_pit
#define err_return_if_null_pit(A1,X1,X2)
#endif

#ifndef err_return_if_null_pt
#define err_return_if_null_pt(A1,X1)
#endif

#ifndef err_return_if_null_pts
#define err_return_if_null_pts(A1,X1,X2)
#endif

#ifndef err_return_if_out_of_bounds
#define err_return_if_out_of_bounds(A1,M)
#endif

#ifndef err_return_if_out_of_bounds_pC
#define err_return_if_out_of_bounds_pC(A1,M,X1)
#endif

#ifndef err_return_if_out_of_bounds_pi
#define err_return_if_out_of_bounds_pi(A1,M,X1)
#endif

#ifndef err_return_if_out_of_bounds_pii
#define err_return_if_out_of_bounds_pii(A1,M,X1,X2)
#endif

#ifndef err_return_if_out_of_bounds_piit
#define err_return_if_out_of_bounds_piit(A1,M,X1,X2,X3)
#endif

#ifndef err_return_if_out_of_bounds_pit
#define err_return_if_out_of_bounds_pit(A1,M,X1,X2)
#endif

#ifndef err_return_if_out_of_bounds_pt
#define err_return_if_out_of_bounds_pt(A1,M,X1)
#endif

#ifndef err_return_if_out_of_bounds_pts
#define err_return_if_out_of_bounds_pts(A1,M,X1,X2)
#endif

#ifndef err_return_if_reached
#define err_return_if_reached()
#endif

#ifndef err_return_if_reached_pC
#define err_return_if_reached_pC(X1)
#endif

#ifndef err_return_if_reached_pi
#define err_return_if_reached_pi(X1)
#endif

#ifndef err_return_if_reached_pii
#define err_return_if_reached_pii(X1,X2)
#endif

#ifndef err_return_if_reached_piit
#define err_return_if_reached_piit(X1,X2,X3)
#endif

#ifndef err_return_if_reached_pit
#define err_return_if_reached_pit(X1,X2)
#endif

#ifndef err_return_if_reached_pt
#define err_return_if_reached_pt(X1)
#endif

#ifndef err_return_if_reached_pts
#define err_return_if_reached_pts(X1,X2)
#endif

#ifndef err_return_m1_if_fail
#define err_return_m1_if_fail(A1)
#endif

#ifndef err_return_m1_if_fail_pC
#define err_return_m1_if_fail_pC(A1,X1)
#endif

#ifndef err_return_m1_if_fail_pi
#define err_return_m1_if_fail_pi(A1,X1)
#endif

#ifndef err_return_m1_if_fail_pii
#define err_return_m1_if_fail_pii(A1,X1,X2)
#endif

#ifndef err_return_m1_if_fail_piit
#define err_return_m1_if_fail_piit(A1,X1,X2,X3)
#endif

#ifndef err_return_m1_if_fail_pit
#define err_return_m1_if_fail_pit(A1,X1,X2)
#endif

#ifndef err_return_m1_if_fail_pt
#define err_return_m1_if_fail_pt(A1,X1)
#endif

#ifndef err_return_m1_if_fail_pts
#define err_return_m1_if_fail_pts(A1,X1,X2)
#endif

#ifndef err_return_m1_if_null
#define err_return_m1_if_null(A1)
#endif

#ifndef err_return_m1_if_null_pC
#define err_return_m1_if_null_pC(A1,X1)
#endif

#ifndef err_return_m1_if_null_pi
#define err_return_m1_if_null_pi(A1,X1)
#endif

#ifndef err_return_m1_if_null_pii
#define err_return_m1_if_null_pii(A1,X1,X2)
#endif

#ifndef err_return_m1_if_null_piit
#define err_return_m1_if_null_piit(A1,X1,X2,X3)
#endif

#ifndef err_return_m1_if_null_pit
#define err_return_m1_if_null_pit(A1,X1,X2)
#endif

#ifndef err_return_m1_if_null_pt
#define err_return_m1_if_null_pt(A1,X1)
#endif

#ifndef err_return_m1_if_null_pts
#define err_return_m1_if_null_pts(A1,X1,X2)
#endif

#ifndef err_return_m1_if_out_of_bounds
#define err_return_m1_if_out_of_bounds(A1,M)
#endif

#ifndef err_return_m1_if_out_of_bounds_pC
#define err_return_m1_if_out_of_bounds_pC(A1,M,X1)
#endif

#ifndef err_return_m1_if_out_of_bounds_pi
#define err_return_m1_if_out_of_bounds_pi(A1,M,X1)
#endif

#ifndef err_return_m1_if_out_of_bounds_pii
#define err_return_m1_if_out_of_bounds_pii(A1,M,X1,X2)
#endif

#ifndef err_return_m1_if_out_of_bounds_piit
#define err_return_m1_if_out_of_bounds_piit(A1,M,X1,X2,X3)
#endif

#ifndef err_return_m1_if_out_of_bounds_pit
#define err_return_m1_if_out_of_bounds_pit(A1,M,X1,X2)
#endif

#ifndef err_return_m1_if_out_of_bounds_pt
#define err_return_m1_if_out_of_bounds_pt(A1,M,X1)
#endif

#ifndef err_return_m1_if_out_of_bounds_pts
#define err_return_m1_if_out_of_bounds_pts(A1,M,X1,X2)
#endif

#ifndef err_return_m1_if_reached
#define err_return_m1_if_reached()
#endif

#ifndef err_return_m1_if_reached_pC
#define err_return_m1_if_reached_pC(X1)
#endif

#ifndef err_return_m1_if_reached_pi
#define err_return_m1_if_reached_pi(X1)
#endif

#ifndef err_return_m1_if_reached_pii
#define err_return_m1_if_reached_pii(X1,X2)
#endif

#ifndef err_return_m1_if_reached_piit
#define err_return_m1_if_reached_piit(X1,X2,X3)
#endif

#ifndef err_return_m1_if_reached_pit
#define err_return_m1_if_reached_pit(X1,X2)
#endif

#ifndef err_return_m1_if_reached_pt
#define err_return_m1_if_reached_pt(X1)
#endif

#ifndef err_return_m1_if_reached_pts
#define err_return_m1_if_reached_pts(X1,X2)
#endif

#ifndef err_return_val_if_fail
#define err_return_val_if_fail(A1,O)
#endif

#ifndef err_return_val_if_fail_pC
#define err_return_val_if_fail_pC(A1,O,X1)
#endif

#ifndef err_return_val_if_fail_pi
#define err_return_val_if_fail_pi(A1,O,X1)
#endif

#ifndef err_return_val_if_fail_pii
#define err_return_val_if_fail_pii(A1,O,X1,X2)
#endif

#ifndef err_return_val_if_fail_piit
#define err_return_val_if_fail_piit(A1,O,X1,X2,X3)
#endif

#ifndef err_return_val_if_fail_pit
#define err_return_val_if_fail_pit(A1,O,X1,X2)
#endif

#ifndef err_return_val_if_fail_pt
#define err_return_val_if_fail_pt(A1,O,X1)
#endif

#ifndef err_return_val_if_fail_pts
#define err_return_val_if_fail_pts(A1,O,X1,X2)
#endif

#ifndef err_return_val_if_null
#define err_return_val_if_null(A1,O)
#endif

#ifndef err_return_val_if_null_pC
#define err_return_val_if_null_pC(A1,O,X1)
#endif

#ifndef err_return_val_if_null_pi
#define err_return_val_if_null_pi(A1,O,X1)
#endif

#ifndef err_return_val_if_null_pii
#define err_return_val_if_null_pii(A1,O,X1,X2)
#endif

#ifndef err_return_val_if_null_piit
#define err_return_val_if_null_piit(A1,O,X1,X2,X3)
#endif

#ifndef err_return_val_if_null_pit
#define err_return_val_if_null_pit(A1,O,X1,X2)
#endif

#ifndef err_return_val_if_null_pt
#define err_return_val_if_null_pt(A1,O,X1)
#endif

#ifndef err_return_val_if_null_pts
#define err_return_val_if_null_pts(A1,O,X1,X2)
#endif

#ifndef err_return_val_if_out_of_bounds
#define err_return_val_if_out_of_bounds(A1,M,O)
#endif

#ifndef err_return_val_if_out_of_bounds_pC
#define err_return_val_if_out_of_bounds_pC(A1,M,O,X1)
#endif

#ifndef err_return_val_if_out_of_bounds_pi
#define err_return_val_if_out_of_bounds_pi(A1,M,O,X1)
#endif

#ifndef err_return_val_if_out_of_bounds_pii
#define err_return_val_if_out_of_bounds_pii(A1,M,O,X1,X2)
#endif

#ifndef err_return_val_if_out_of_bounds_piit
#define err_return_val_if_out_of_bounds_piit(A1,M,O,X1,X2,X3)
#endif

#ifndef err_return_val_if_out_of_bounds_pit
#define err_return_val_if_out_of_bounds_pit(A1,M,O,X1,X2)
#endif

#ifndef err_return_val_if_out_of_bounds_pt
#define err_return_val_if_out_of_bounds_pt(A1,M,O,X1)
#endif

#ifndef err_return_val_if_out_of_bounds_pts
#define err_return_val_if_out_of_bounds_pts(A1,M,O,X1,X2)
#endif

#ifndef err_return_val_if_reached
#define err_return_val_if_reached(O)
#endif

#ifndef err_return_val_if_reached_pC
#define err_return_val_if_reached_pC(O,X1)
#endif

#ifndef err_return_val_if_reached_pi
#define err_return_val_if_reached_pi(O,X1)
#endif

#ifndef err_return_val_if_reached_pii
#define err_return_val_if_reached_pii(O,X1,X2)
#endif

#ifndef err_return_val_if_reached_piit
#define err_return_val_if_reached_piit(O,X1,X2,X3)
#endif

#ifndef err_return_val_if_reached_pit
#define err_return_val_if_reached_pit(O,X1,X2)
#endif

#ifndef err_return_val_if_reached_pt
#define err_return_val_if_reached_pt(O,X1)
#endif

#ifndef err_return_val_if_reached_pts
#define err_return_val_if_reached_pts(O,X1,X2)
#endif

#endif /* !defined(ERR_ASSERT_IS_BROKEN) */

#if defined(IN_LIBERROR_COMPILE) || defined(ERR_ASSERT_INTERNAL)
#define error_exit_if_fail                  err_error_exit_if_fail
#define error_exit_if_fail_pC               err_error_exit_if_fail_pC
#define error_exit_if_fail_pi               err_error_exit_if_fail_pi
#define error_exit_if_fail_pii              err_error_exit_if_fail_pii
#define error_exit_if_fail_piit             err_error_exit_if_fail_piit
#define error_exit_if_fail_pit              err_error_exit_if_fail_pit
#define error_exit_if_fail_pt               err_error_exit_if_fail_pt
#define error_exit_if_fail_pts              err_error_exit_if_fail_pts
#define error_exit_if_null                  err_error_exit_if_null
#define error_exit_if_null_pC               err_error_exit_if_null_pC
#define error_exit_if_null_pi               err_error_exit_if_null_pi
#define error_exit_if_null_pii              err_error_exit_if_null_pii
#define error_exit_if_null_piit             err_error_exit_if_null_piit
#define error_exit_if_null_pit              err_error_exit_if_null_pit
#define error_exit_if_null_pt               err_error_exit_if_null_pt
#define error_exit_if_null_pts              err_error_exit_if_null_pts
#define error_exit_if_out_of_bounds         err_error_exit_if_out_of_bounds
#define error_exit_if_out_of_bounds_pC      err_error_exit_if_out_of_bounds_pC
#define error_exit_if_out_of_bounds_pi      err_error_exit_if_out_of_bounds_pi
#define error_exit_if_out_of_bounds_pii     err_error_exit_if_out_of_bounds_pii
#define error_exit_if_out_of_bounds_piit    err_error_exit_if_out_of_bounds_piit
#define error_exit_if_out_of_bounds_pit     err_error_exit_if_out_of_bounds_pit
#define error_exit_if_out_of_bounds_pt      err_error_exit_if_out_of_bounds_pt
#define error_exit_if_out_of_bounds_pts     err_error_exit_if_out_of_bounds_pts
#define error_exit_if_reached               err_error_exit_if_reached
#define error_exit_if_reached_pC            err_error_exit_if_reached_pC
#define error_exit_if_reached_pi            err_error_exit_if_reached_pi
#define error_exit_if_reached_pii           err_error_exit_if_reached_pii
#define error_exit_if_reached_piit          err_error_exit_if_reached_piit
#define error_exit_if_reached_pit           err_error_exit_if_reached_pit
#define error_exit_if_reached_pt            err_error_exit_if_reached_pt
#define error_exit_if_reached_pts           err_error_exit_if_reached_pts
#define error_return0_if_fail               err_error_return0_if_fail
#define error_return0_if_fail_pC            err_error_return0_if_fail_pC
#define error_return0_if_fail_pi            err_error_return0_if_fail_pi
#define error_return0_if_fail_pii           err_error_return0_if_fail_pii
#define error_return0_if_fail_piit          err_error_return0_if_fail_piit
#define error_return0_if_fail_pit           err_error_return0_if_fail_pit
#define error_return0_if_fail_pt            err_error_return0_if_fail_pt
#define error_return0_if_fail_pts           err_error_return0_if_fail_pts
#define error_return0_if_null               err_error_return0_if_null
#define error_return0_if_null_pC            err_error_return0_if_null_pC
#define error_return0_if_null_pi            err_error_return0_if_null_pi
#define error_return0_if_null_pii           err_error_return0_if_null_pii
#define error_return0_if_null_piit          err_error_return0_if_null_piit
#define error_return0_if_null_pit           err_error_return0_if_null_pit
#define error_return0_if_null_pt            err_error_return0_if_null_pt
#define error_return0_if_null_pts           err_error_return0_if_null_pts
#define error_return0_if_out_of_bounds      err_error_return0_if_out_of_bounds
#define error_return0_if_out_of_bounds_pC   err_error_return0_if_out_of_bounds_pC
#define error_return0_if_out_of_bounds_pi   err_error_return0_if_out_of_bounds_pi
#define error_return0_if_out_of_bounds_pii  err_error_return0_if_out_of_bounds_pii
#define error_return0_if_out_of_bounds_piit err_error_return0_if_out_of_bounds_piit
#define error_return0_if_out_of_bounds_pit  err_error_return0_if_out_of_bounds_pit
#define error_return0_if_out_of_bounds_pt   err_error_return0_if_out_of_bounds_pt
#define error_return0_if_out_of_bounds_pts  err_error_return0_if_out_of_bounds_pts
#define error_return0_if_reached            err_error_return0_if_reached
#define error_return0_if_reached_pC         err_error_return0_if_reached_pC
#define error_return0_if_reached_pi         err_error_return0_if_reached_pi
#define error_return0_if_reached_pii        err_error_return0_if_reached_pii
#define error_return0_if_reached_piit       err_error_return0_if_reached_piit
#define error_return0_if_reached_pit        err_error_return0_if_reached_pit
#define error_return0_if_reached_pt         err_error_return0_if_reached_pt
#define error_return0_if_reached_pts        err_error_return0_if_reached_pts
#define exit1_if_fail                       err_exit1_if_fail
#define exit1_if_fail_pC                    err_exit1_if_fail_pC
#define exit1_if_fail_pi                    err_exit1_if_fail_pi
#define exit1_if_fail_pii                   err_exit1_if_fail_pii
#define exit1_if_fail_piit                  err_exit1_if_fail_piit
#define exit1_if_fail_pit                   err_exit1_if_fail_pit
#define exit1_if_fail_pt                    err_exit1_if_fail_pt
#define exit1_if_fail_pts                   err_exit1_if_fail_pts
#define exit1_if_null                       err_exit1_if_null
#define exit1_if_null_pC                    err_exit1_if_null_pC
#define exit1_if_null_pi                    err_exit1_if_null_pi
#define exit1_if_null_pii                   err_exit1_if_null_pii
#define exit1_if_null_piit                  err_exit1_if_null_piit
#define exit1_if_null_pit                   err_exit1_if_null_pit
#define exit1_if_null_pt                    err_exit1_if_null_pt
#define exit1_if_null_pts                   err_exit1_if_null_pts
#define exit1_if_out_of_bounds              err_exit1_if_out_of_bounds
#define exit1_if_out_of_bounds_pC           err_exit1_if_out_of_bounds_pC
#define exit1_if_out_of_bounds_pi           err_exit1_if_out_of_bounds_pi
#define exit1_if_out_of_bounds_pii          err_exit1_if_out_of_bounds_pii
#define exit1_if_out_of_bounds_piit         err_exit1_if_out_of_bounds_piit
#define exit1_if_out_of_bounds_pit          err_exit1_if_out_of_bounds_pit
#define exit1_if_out_of_bounds_pt           err_exit1_if_out_of_bounds_pt
#define exit1_if_out_of_bounds_pts          err_exit1_if_out_of_bounds_pts
#define exit1_if_reached                    err_exit1_if_reached
#define exit1_if_reached_pC                 err_exit1_if_reached_pC
#define exit1_if_reached_pi                 err_exit1_if_reached_pi
#define exit1_if_reached_pii                err_exit1_if_reached_pii
#define exit1_if_reached_piit               err_exit1_if_reached_piit
#define exit1_if_reached_pit                err_exit1_if_reached_pit
#define exit1_if_reached_pt                 err_exit1_if_reached_pt
#define exit1_if_reached_pts                err_exit1_if_reached_pts
#define exit_if_fail                        err_exit_if_fail
#define exit_if_fail_pC                     err_exit_if_fail_pC
#define exit_if_fail_pi                     err_exit_if_fail_pi
#define exit_if_fail_pii                    err_exit_if_fail_pii
#define exit_if_fail_piit                   err_exit_if_fail_piit
#define exit_if_fail_pit                    err_exit_if_fail_pit
#define exit_if_fail_pt                     err_exit_if_fail_pt
#define exit_if_fail_pts                    err_exit_if_fail_pts
#define exit_if_null                        err_exit_if_null
#define exit_if_null_pC                     err_exit_if_null_pC
#define exit_if_null_pi                     err_exit_if_null_pi
#define exit_if_null_pii                    err_exit_if_null_pii
#define exit_if_null_piit                   err_exit_if_null_piit
#define exit_if_null_pit                    err_exit_if_null_pit
#define exit_if_null_pt                     err_exit_if_null_pt
#define exit_if_null_pts                    err_exit_if_null_pts
#define exit_if_out_of_bounds               err_exit_if_out_of_bounds
#define exit_if_out_of_bounds_pC            err_exit_if_out_of_bounds_pC
#define exit_if_out_of_bounds_pi            err_exit_if_out_of_bounds_pi
#define exit_if_out_of_bounds_pii           err_exit_if_out_of_bounds_pii
#define exit_if_out_of_bounds_piit          err_exit_if_out_of_bounds_piit
#define exit_if_out_of_bounds_pit           err_exit_if_out_of_bounds_pit
#define exit_if_out_of_bounds_pt            err_exit_if_out_of_bounds_pt
#define exit_if_out_of_bounds_pts           err_exit_if_out_of_bounds_pts
#define exit_if_reached                     err_exit_if_reached
#define exit_if_reached_pC                  err_exit_if_reached_pC
#define exit_if_reached_pi                  err_exit_if_reached_pi
#define exit_if_reached_pii                 err_exit_if_reached_pii
#define exit_if_reached_piit                err_exit_if_reached_piit
#define exit_if_reached_pit                 err_exit_if_reached_pit
#define exit_if_reached_pt                  err_exit_if_reached_pt
#define exit_if_reached_pts                 err_exit_if_reached_pts
#define nothing_if_fail                     err_nothing_if_fail
#define nothing_if_fail_pC                  err_nothing_if_fail_pC
#define nothing_if_fail_pi                  err_nothing_if_fail_pi
#define nothing_if_fail_pii                 err_nothing_if_fail_pii
#define nothing_if_fail_piit                err_nothing_if_fail_piit
#define nothing_if_fail_pit                 err_nothing_if_fail_pit
#define nothing_if_fail_pt                  err_nothing_if_fail_pt
#define nothing_if_fail_pts                 err_nothing_if_fail_pts
#define nothing_if_null                     err_nothing_if_null
#define nothing_if_null_pC                  err_nothing_if_null_pC
#define nothing_if_null_pi                  err_nothing_if_null_pi
#define nothing_if_null_pii                 err_nothing_if_null_pii
#define nothing_if_null_piit                err_nothing_if_null_piit
#define nothing_if_null_pit                 err_nothing_if_null_pit
#define nothing_if_null_pt                  err_nothing_if_null_pt
#define nothing_if_null_pts                 err_nothing_if_null_pts
#define nothing_if_out_of_bounds            err_nothing_if_out_of_bounds
#define nothing_if_out_of_bounds_pC         err_nothing_if_out_of_bounds_pC
#define nothing_if_out_of_bounds_pi         err_nothing_if_out_of_bounds_pi
#define nothing_if_out_of_bounds_pii        err_nothing_if_out_of_bounds_pii
#define nothing_if_out_of_bounds_piit       err_nothing_if_out_of_bounds_piit
#define nothing_if_out_of_bounds_pit        err_nothing_if_out_of_bounds_pit
#define nothing_if_out_of_bounds_pt         err_nothing_if_out_of_bounds_pt
#define nothing_if_out_of_bounds_pts        err_nothing_if_out_of_bounds_pts
#define nothing_if_reached                  err_nothing_if_reached
#define nothing_if_reached_pC               err_nothing_if_reached_pC
#define nothing_if_reached_pi               err_nothing_if_reached_pi
#define nothing_if_reached_pii              err_nothing_if_reached_pii
#define nothing_if_reached_piit             err_nothing_if_reached_piit
#define nothing_if_reached_pit              err_nothing_if_reached_pit
#define nothing_if_reached_pt               err_nothing_if_reached_pt
#define nothing_if_reached_pts              err_nothing_if_reached_pts
#define return0_if_fail                     err_return0_if_fail
#define return0_if_fail_pC                  err_return0_if_fail_pC
#define return0_if_fail_pi                  err_return0_if_fail_pi
#define return0_if_fail_pii                 err_return0_if_fail_pii
#define return0_if_fail_piit                err_return0_if_fail_piit
#define return0_if_fail_pit                 err_return0_if_fail_pit
#define return0_if_fail_pt                  err_return0_if_fail_pt
#define return0_if_fail_pts                 err_return0_if_fail_pts
#define return0_if_fail_pxx                 err_return0_if_fail_pxx
#define return0_if_null                     err_return0_if_null
#define return0_if_null2                    err_return0_if_null2
#define return0_if_null_pC                  err_return0_if_null_pC
#define return0_if_null_pi                  err_return0_if_null_pi
#define return0_if_null_pii                 err_return0_if_null_pii
#define return0_if_null_piit                err_return0_if_null_piit
#define return0_if_null_pit                 err_return0_if_null_pit
#define return0_if_null_pt                  err_return0_if_null_pt
#define return0_if_null_pts                 err_return0_if_null_pts
#define return0_if_out_of_bounds            err_return0_if_out_of_bounds
#define return0_if_out_of_bounds_pC         err_return0_if_out_of_bounds_pC
#define return0_if_out_of_bounds_pi         err_return0_if_out_of_bounds_pi
#define return0_if_out_of_bounds_pii        err_return0_if_out_of_bounds_pii
#define return0_if_out_of_bounds_piit       err_return0_if_out_of_bounds_piit
#define return0_if_out_of_bounds_pit        err_return0_if_out_of_bounds_pit
#define return0_if_out_of_bounds_pt         err_return0_if_out_of_bounds_pt
#define return0_if_out_of_bounds_pts        err_return0_if_out_of_bounds_pts
#define return0_if_reached                  err_return0_if_reached
#define return0_if_reached_pC               err_return0_if_reached_pC
#define return0_if_reached_pi               err_return0_if_reached_pi
#define return0_if_reached_pii              err_return0_if_reached_pii
#define return0_if_reached_piit             err_return0_if_reached_piit
#define return0_if_reached_pit              err_return0_if_reached_pit
#define return0_if_reached_pt               err_return0_if_reached_pt
#define return0_if_reached_pts              err_return0_if_reached_pts
#define return0_if_reached_px               err_return0_if_reached_px
#define return1_if_fail                     err_return1_if_fail
#define return1_if_fail_pC                  err_return1_if_fail_pC
#define return1_if_fail_pi                  err_return1_if_fail_pi
#define return1_if_fail_pii                 err_return1_if_fail_pii
#define return1_if_fail_piit                err_return1_if_fail_piit
#define return1_if_fail_pit                 err_return1_if_fail_pit
#define return1_if_fail_pt                  err_return1_if_fail_pt
#define return1_if_fail_pts                 err_return1_if_fail_pts
#define return1_if_null                     err_return1_if_null
#define return1_if_null_pC                  err_return1_if_null_pC
#define return1_if_null_pi                  err_return1_if_null_pi
#define return1_if_null_pii                 err_return1_if_null_pii
#define return1_if_null_piit                err_return1_if_null_piit
#define return1_if_null_pit                 err_return1_if_null_pit
#define return1_if_null_pt                  err_return1_if_null_pt
#define return1_if_null_pts                 err_return1_if_null_pts
#define return1_if_out_of_bounds            err_return1_if_out_of_bounds
#define return1_if_out_of_bounds_pC         err_return1_if_out_of_bounds_pC
#define return1_if_out_of_bounds_pi         err_return1_if_out_of_bounds_pi
#define return1_if_out_of_bounds_pii        err_return1_if_out_of_bounds_pii
#define return1_if_out_of_bounds_piit       err_return1_if_out_of_bounds_piit
#define return1_if_out_of_bounds_pit        err_return1_if_out_of_bounds_pit
#define return1_if_out_of_bounds_pt         err_return1_if_out_of_bounds_pt
#define return1_if_out_of_bounds_pts        err_return1_if_out_of_bounds_pts
#define return1_if_reached                  err_return1_if_reached
#define return1_if_reached_pC               err_return1_if_reached_pC
#define return1_if_reached_pi               err_return1_if_reached_pi
#define return1_if_reached_pii              err_return1_if_reached_pii
#define return1_if_reached_piit             err_return1_if_reached_piit
#define return1_if_reached_pit              err_return1_if_reached_pit
#define return1_if_reached_pt               err_return1_if_reached_pt
#define return1_if_reached_pts              err_return1_if_reached_pts
#define return_if_fail                      err_return_if_fail
#define return_if_fail_pC                   err_return_if_fail_pC
#define return_if_fail_pi                   err_return_if_fail_pi
#define return_if_fail_pii                  err_return_if_fail_pii
#define return_if_fail_piit                 err_return_if_fail_piit
#define return_if_fail_pit                  err_return_if_fail_pit
#define return_if_fail_pt                   err_return_if_fail_pt
#define return_if_fail_pts                  err_return_if_fail_pts
#define return_if_fail_pxx                  err_return_if_fail_pxx
#define return_if_null                      err_return_if_null
#define return_if_null2                     err_return_if_null2
#define return_if_null2i                    err_return_if_null2i
#define return_if_null_pC                   err_return_if_null_pC
#define return_if_null_pi                   err_return_if_null_pi
#define return_if_null_pii                  err_return_if_null_pii
#define return_if_null_piit                 err_return_if_null_piit
#define return_if_null_pit                  err_return_if_null_pit
#define return_if_null_pt                   err_return_if_null_pt
#define return_if_null_pts                  err_return_if_null_pts
#define return_if_out_of_bounds             err_return_if_out_of_bounds
#define return_if_out_of_bounds_pC          err_return_if_out_of_bounds_pC
#define return_if_out_of_bounds_pi          err_return_if_out_of_bounds_pi
#define return_if_out_of_bounds_pii         err_return_if_out_of_bounds_pii
#define return_if_out_of_bounds_piit        err_return_if_out_of_bounds_piit
#define return_if_out_of_bounds_pit         err_return_if_out_of_bounds_pit
#define return_if_out_of_bounds_pt          err_return_if_out_of_bounds_pt
#define return_if_out_of_bounds_pts         err_return_if_out_of_bounds_pts
#define return_if_reached                   err_return_if_reached
#define return_if_reached_pC                err_return_if_reached_pC
#define return_if_reached_pi                err_return_if_reached_pi
#define return_if_reached_pii               err_return_if_reached_pii
#define return_if_reached_piit              err_return_if_reached_piit
#define return_if_reached_pit               err_return_if_reached_pit
#define return_if_reached_pt                err_return_if_reached_pt
#define return_if_reached_pts               err_return_if_reached_pts
#define return_m1_if_fail                   err_return_m1_if_fail
#define return_m1_if_fail_pC                err_return_m1_if_fail_pC
#define return_m1_if_fail_pi                err_return_m1_if_fail_pi
#define return_m1_if_fail_pii               err_return_m1_if_fail_pii
#define return_m1_if_fail_piit              err_return_m1_if_fail_piit
#define return_m1_if_fail_pit               err_return_m1_if_fail_pit
#define return_m1_if_fail_pt                err_return_m1_if_fail_pt
#define return_m1_if_fail_pts               err_return_m1_if_fail_pts
#define return_m1_if_null                   err_return_m1_if_null
#define return_m1_if_null_pC                err_return_m1_if_null_pC
#define return_m1_if_null_pi                err_return_m1_if_null_pi
#define return_m1_if_null_pii               err_return_m1_if_null_pii
#define return_m1_if_null_piit              err_return_m1_if_null_piit
#define return_m1_if_null_pit               err_return_m1_if_null_pit
#define return_m1_if_null_pt                err_return_m1_if_null_pt
#define return_m1_if_null_pts               err_return_m1_if_null_pts
#define return_m1_if_out_of_bounds          err_return_m1_if_out_of_bounds
#define return_m1_if_out_of_bounds_pC       err_return_m1_if_out_of_bounds_pC
#define return_m1_if_out_of_bounds_pi       err_return_m1_if_out_of_bounds_pi
#define return_m1_if_out_of_bounds_pii      err_return_m1_if_out_of_bounds_pii
#define return_m1_if_out_of_bounds_piit     err_return_m1_if_out_of_bounds_piit
#define return_m1_if_out_of_bounds_pit      err_return_m1_if_out_of_bounds_pit
#define return_m1_if_out_of_bounds_pt       err_return_m1_if_out_of_bounds_pt
#define return_m1_if_out_of_bounds_pts      err_return_m1_if_out_of_bounds_pts
#define return_m1_if_reached                err_return_m1_if_reached
#define return_m1_if_reached_pC             err_return_m1_if_reached_pC
#define return_m1_if_reached_pi             err_return_m1_if_reached_pi
#define return_m1_if_reached_pii            err_return_m1_if_reached_pii
#define return_m1_if_reached_piit           err_return_m1_if_reached_piit
#define return_m1_if_reached_pit            err_return_m1_if_reached_pit
#define return_m1_if_reached_pt             err_return_m1_if_reached_pt
#define return_m1_if_reached_pts            err_return_m1_if_reached_pts
#define return_val_if_fail                  err_return_val_if_fail
#define return_val_if_fail_pC               err_return_val_if_fail_pC
#define return_val_if_fail_pi               err_return_val_if_fail_pi
#define return_val_if_fail_pii              err_return_val_if_fail_pii
#define return_val_if_fail_piit             err_return_val_if_fail_piit
#define return_val_if_fail_pit              err_return_val_if_fail_pit
#define return_val_if_fail_pt               err_return_val_if_fail_pt
#define return_val_if_fail_pts              err_return_val_if_fail_pts
#define return_val_if_null                  err_return_val_if_null
#define return_val_if_null_pC               err_return_val_if_null_pC
#define return_val_if_null_pi               err_return_val_if_null_pi
#define return_val_if_null_pii              err_return_val_if_null_pii
#define return_val_if_null_piit             err_return_val_if_null_piit
#define return_val_if_null_pit              err_return_val_if_null_pit
#define return_val_if_null_pt               err_return_val_if_null_pt
#define return_val_if_null_pts              err_return_val_if_null_pts
#define return_val_if_out_of_bounds         err_return_val_if_out_of_bounds
#define return_val_if_out_of_bounds_pC      err_return_val_if_out_of_bounds_pC
#define return_val_if_out_of_bounds_pi      err_return_val_if_out_of_bounds_pi
#define return_val_if_out_of_bounds_pii     err_return_val_if_out_of_bounds_pii
#define return_val_if_out_of_bounds_piit    err_return_val_if_out_of_bounds_piit
#define return_val_if_out_of_bounds_pit     err_return_val_if_out_of_bounds_pit
#define return_val_if_out_of_bounds_pt      err_return_val_if_out_of_bounds_pt
#define return_val_if_out_of_bounds_pts     err_return_val_if_out_of_bounds_pts
#define return_val_if_reached               err_return_val_if_reached
#define return_val_if_reached_pC            err_return_val_if_reached_pC
#define return_val_if_reached_pi            err_return_val_if_reached_pi
#define return_val_if_reached_pii           err_return_val_if_reached_pii
#define return_val_if_reached_piit          err_return_val_if_reached_piit
#define return_val_if_reached_pit           err_return_val_if_reached_pit
#define return_val_if_reached_pt            err_return_val_if_reached_pt
#define return_val_if_reached_pts           err_return_val_if_reached_pts
#endif /* defined(IN_LIBERROR_COMPILE) || defined(ERR_ASSERT_INTERNAL) */

#endif /* !defined(ERR_HT_FAILURE_H) */
