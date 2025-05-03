/* -*- Mode: C -*- */
/* Generated automatically by assert.pl (part of Erwin library). */

#ifndef HT_FAILURE_H
#define HT_FAILURE_H

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

/* #define ASSERT_IS_BROKEN */

#ifndef ASSERT_IS_BROKEN

/*
 * Additional user provided assertion failure, warning,
 * and error handlers.
 */
#ifndef USER_ASSERTION_FAILED_HANDLER
#define USER_ASSERTION_FAILED_HANDLER(FI,L,FU,A) ASSERT_NO_EFFECT
#endif

#ifndef USER_ERROR_HANDLER
#define USER_ERROR_HANDLER(FI,L,FU,A) ASSERT_NO_EFFECT
#endif

#ifndef USER_WARNING_HANDLER
#define USER_WARNING_HANDLER(FI,L,FU,A) ASSERT_NO_EFFECT
#endif

#ifdef __GNUC__

#define ASSERT_NORETURN  __attribute__((__noreturn__))

#if defined __cplusplus && (__GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 95))
#define ASSERT_CAST_VOID static_cast<void>
   /* for compiler warning -Wold-style-cast */
#endif

#ifndef ASSERT_FUNCTION
#define ASSERT_FUNCTION   __PRETTY_FUNCTION__
#endif

#ifndef ASSERT_NO_EFFECT
#define ASSERT_NO_EFFECT  (ASSERT_CAST_VOID(0)) /* To get rid of warnings. */
 /* FIXME: CHECK: do we need the different versions of ASSERT_NO_EFFECT? */
#endif

#else

#define ASSERT_NORETURN

#ifndef ASSERT_FUNCTION
#define ASSERT_FUNCTION   "-unknown-"
#endif

#ifndef ASSERT_NO_EFFECT
#define ASSERT_NO_EFFECT  0
#endif

#endif

#ifndef ASSERT_CAST_VOID
#define ASSERT_CAST_VOID (void)
#endif

#ifndef NDEBUG
#define ASSERT_DEBUG_CODE(X) X
#else
#define ASSERT_DEBUG_CODE(X)
#endif

#if defined(__KERNEL__)

#ifndef ASSERT_EPRINTF_MORE_0
#define ASSERT_EPRINTF_MORE_0(F) \
        ASSERT_CAST_VOID (printk (KERN_ERR "\t"F))
#endif

#ifndef ASSERT_EPRINTF_MORE_1
#define ASSERT_EPRINTF_MORE_1(F,V1) \
        ASSERT_CAST_VOID (printk (KERN_ERR "\t"F, V1))
#endif

#ifndef ASSERT_EPRINTF_MORE_2
#define ASSERT_EPRINTF_MORE_2(F,V1,V2) \
        ASSERT_CAST_VOID (printk (KERN_ERR "\t"F, V1, V2))
#endif

#ifndef ASSERT_FLEPRINTF_ASSERT_2
#define ASSERT_FLEPRINTF_ASSERT_2(FILE,LINE,F,V1,V2) \
        ASSERT_CAST_VOID (printk (KERN_ERR "%s:%d: "F, FILE, LINE, V1, V2))
#endif

#ifndef ASSERT_FLEPRINTF_ASSERT_3
#define ASSERT_FLEPRINTF_ASSERT_3(FILE,LINE,F,V1,V2,V3) \
        ASSERT_CAST_VOID (printk (KERN_ERR "%s:%d: "F, FILE, LINE, V1, V2, #V3))
#endif

#ifndef ASSERT_END
#define ASSERT_END \
        ASSERT_CAST_VOID (0)
#endif

#ifndef ASSERT_INDENT
#define ASSERT_INDENT "\t"
#endif

#elif defined(HAVE_LIBERROR)

#ifndef IN_LIBERROR_COMPILE
#include <liberror.h>
#endif

#ifndef ASSERT_ABORT
#define ASSERT_ABORT err_crash()
#endif

#ifndef ASSERT_EPRINTF_MORE_0
#define ASSERT_EPRINTF_MORE_0(F) \
        ASSERT_CAST_VOID (eprintf (C_TAG_MORE, 0, F))
#endif

#ifndef ASSERT_EPRINTF_MORE_1
#define ASSERT_EPRINTF_MORE_1(F,V1) \
        ASSERT_CAST_VOID (eprintf (C_TAG_MORE, 0, F, V1))
#endif

#ifndef ASSERT_EPRINTF_MORE_2
#define ASSERT_EPRINTF_MORE_2(F,V1,V2) \
        ASSERT_CAST_VOID (eprintf (C_TAG_MORE, 0, F, V1, V2))
#endif

#ifndef ASSERT_FLEPRINTF_ASSERT_2
#define ASSERT_FLEPRINTF_ASSERT_2(FILE,LINE,F,V1,V2) \
        ASSERT_CAST_VOID (fleprintf (C_TAG_PRE_ASSERT | 0, 0, FILE, LINE, F, V1, V2))
#endif

#ifndef ASSERT_FLEPRINTF_ASSERT_3
#define ASSERT_FLEPRINTF_ASSERT_3(FILE,LINE,F,V1,V2,V3) \
        ASSERT_CAST_VOID (fleprintf (C_TAG_PRE_ASSERT | 0, 0, FILE, LINE, F, V1, V2, #V3))
#endif

#ifndef ASSERT_END
#define ASSERT_END \
        ASSERT_CAST_VOID (eprintf (C_TAG_ASSERT | 0, 0, ERR_CALLBACKS_ONLY))
#endif

#ifndef ASSERT_INDENT
#define ASSERT_INDENT
#endif

#else /* !defined HAVE_LIBERROR */

#ifndef ASSERT_EPRINTF_MORE_0
#define ASSERT_EPRINTF_MORE_0(F) \
        ASSERT_CAST_VOID (fprintf (stderr, "\t"F))
#endif

#ifndef ASSERT_EPRINTF_MORE_1
#define ASSERT_EPRINTF_MORE_1(F,V1) \
        ASSERT_CAST_VOID (fprintf (stderr, "\t"F, V1))
#endif

#ifndef ASSERT_EPRINTF_MORE_2
#define ASSERT_EPRINTF_MORE_2(F,V1,V2) \
        ASSERT_CAST_VOID (fprintf (stderr, "\t"F, V1, V2))
#endif

#ifndef ASSERT_FLEPRINTF_ASSERT_2
#define ASSERT_FLEPRINTF_ASSERT_2(FILE,LINE,F,V1,V2) \
        ASSERT_CAST_VOID (fprintf (stderr, "%s:%d: "F, FILE, LINE, V1, V2))
#endif

#ifndef ASSERT_FLEPRINTF_ASSERT_3
#define ASSERT_FLEPRINTF_ASSERT_3(FILE,LINE,F,V1,V2,V3) \
        ASSERT_CAST_VOID (fprintf (stderr, "%s:%d: "F, FILE, LINE, V1, V2, #V3))
#endif

#ifndef ASSERT_END
#define ASSERT_END \
        ASSERT_CAST_VOID (0)
#endif

#ifndef ASSERT_INDENT
#define ASSERT_INDENT "\t"
#endif

#endif /* !defined HAVE_LIBERROR */

#ifndef ASSERT_ABORT
#define ASSERT_ABORT abort()
#endif

#ifndef ASSERT_NONNEGATIVE
#ifdef erwin_nonnegative
#define ASSERT_NONNEGATIVE(X) erwin_nonnegative(X)
#else
#define ASSERT_NONNEGATIVE(X) ((X) >= 0)
#endif
#endif

#ifndef ASSERT_UNLIKELY
#ifdef ERWIN_UNLIKELY
#define ASSERT_UNLIKELY(X) ERWIN_UNLIKELY(X)
#else
#define ASSERT_UNLIKELY(X) (X)
#endif
#endif


/*
 * Please note that this does not have any do { ... } while(0) protection.  This is because
 * continue_if_fail and break_if_fail would do wrong things in that case. */
#ifndef raw_do_if_fail
#define raw_do_if_fail(P,A1,A2,A3,W,F1,F2) \
        if (ASSERT_UNLIKELY(!(A1))) { \
            ASSERT_FLEPRINTF_ASSERT_3 ( \
                     __FILE__, __LINE__, \
                     ""P" function '%s':\n" \
                     ASSERT_INDENT W " failed: '%s'\n" \
                     ASSERT_INDENT "Pre-processed: '%s'\n" \
                             , ASSERT_FUNCTION, \
                             A3 \
                             ,A2 \
                             ); \
            F1; \
            USER_ASSERTION_FAILED_HANDLER(__FILE__,__LINE__,ASSERT_FUNCTION, A); \
            F2; \
        } \
        else { ; }
#endif

/*
 * If you write your USER_ASSERTION_FAILED_HANDLER in such a way that it is an expression,
 * you can use the false_if_fail, null_if_fail, etc. */
#ifndef raw_value_if_fail
#define raw_value_if_fail(P,A1,A2,A3,W,F1,FAILVAL,GOODVAL) \
        (ASSERT_UNLIKELY(!(A1)) ? ((\
                     ASSERT_FLEPRINTF_ASSERT_3 ( \
                     __FILE__, __LINE__, \
                          ""P" function '%s':\n" \
                          ASSERT_INDENT W" failed: '%s'\n" \
                          ASSERT_INDENT "Pre-processed: '%s'\n" \
                          , ASSERT_FUNCTION, \
                          A3 \
                          ,#A2 \
                          )), \
                  (F1), \
                  (USER_ASSERTION_FAILED_HANDLER(__FILE__, __LINE__, ASSERT_FUNCTION, A)), \
                  (FAILVAL)) \
                : (GOODVAL))
#endif

#ifndef NDEBUG

#ifndef do_if_fail
#define do_if_fail(A1,A2,A3,W,F1,F2) \
        raw_do_if_fail("In",A1,A2,A3,W,F1,F2)
#endif

#ifndef value_if_fail
#define value_if_fail(A1,A2,A3,W,F1,FAILVAL,GOODVAL) \
        raw_value_if_fail("In",A1,A2,A3,W,F1,FAILVAL,GOODVAL)
#endif

#else

#ifndef do_if_fail
#define do_if_fail(A1,A2,A3,W,F1,F2)
#endif

#ifndef value_if_fail
#define value_if_fail(A1,A2,A3,W,F1,FAILVAL,GOODVAL) (GOODVAL)
#endif

#endif

#ifndef warn_do_if_fail
#define warn_do_if_fail(A1,A2,A3,W,F1,F2) \
        raw_do_if_fail("Warning in",A1,A2,A3,W,F1,F2)
#endif

#ifndef warn_value_if_fail
#define warn_value_if_fail(A1,A2,A3,W,F1,FAILVAL,GOODVAL) \
        raw_value_if_fail("Warning in",A1,A2,A3,W,F1,FAILVAL,GOODVAL)
#endif

#ifndef error_do_if_fail
#define error_do_if_fail(A1,A2,A3,W,F1,F2) \
        raw_do_if_fail("Error in",A1,A2,A3,W,F1,F2)
#endif

#ifndef error_value_if_fail
#define error_value_if_fail(A1,A2,A3,W,F1,FAILVAL,GOODVAL) \
        raw_value_if_fail("Error in",A1,A2,A3,W,F1,FAILVAL,GOODVAL)
#endif

#ifndef error_exit_if_fail
#define error_exit_if_fail(A1) \
	 do { error_do_if_fail(A1,A1,""#A1,"Sanity constraint",;;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_fail_pC
#define error_exit_if_fail_pC(A1,X1) \
	 do { error_do_if_fail(A1,A1,""#A1,"Sanity constraint",X1;;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_fail_pi
#define error_exit_if_fail_pi(A1,X1) \
	 do { error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_fail_pii
#define error_exit_if_fail_pii(A1,X1,X2) \
	 do { error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_fail_piit
#define error_exit_if_fail_piit(A1,X1,X2,X3) \
	 do { error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_fail_pit
#define error_exit_if_fail_pit(A1,X1,X2) \
	 do { error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_fail_pt
#define error_exit_if_fail_pt(A1,X1) \
	 do { error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_fail_pts
#define error_exit_if_fail_pts(A1,X1,X2) \
	 do { error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_null
#define error_exit_if_null(A1) \
	 do { error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",;;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_null_pC
#define error_exit_if_null_pC(A1,X1) \
	 do { error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",X1;;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_null_pi
#define error_exit_if_null_pi(A1,X1) \
	 do { error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_null_pii
#define error_exit_if_null_pii(A1,X1,X2) \
	 do { error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_null_piit
#define error_exit_if_null_piit(A1,X1,X2,X3) \
	 do { error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_null_pit
#define error_exit_if_null_pit(A1,X1,X2) \
	 do { error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_null_pt
#define error_exit_if_null_pt(A1,X1) \
	 do { error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_null_pts
#define error_exit_if_null_pts(A1,X1,X2) \
	 do { error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_out_of_bounds
#define error_exit_if_out_of_bounds(A1,M) \
	 do { error_do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_out_of_bounds_pC
#define error_exit_if_out_of_bounds_pC(A1,M,X1) \
	 do { error_do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));X1;;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_out_of_bounds_pi
#define error_exit_if_out_of_bounds_pi(A1,M,X1) \
	 do { error_do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_out_of_bounds_pii
#define error_exit_if_out_of_bounds_pii(A1,M,X1,X2) \
	 do { error_do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_out_of_bounds_piit
#define error_exit_if_out_of_bounds_piit(A1,M,X1,X2,X3) \
	 do { error_do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_out_of_bounds_pit
#define error_exit_if_out_of_bounds_pit(A1,M,X1,X2) \
	 do { error_do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_out_of_bounds_pt
#define error_exit_if_out_of_bounds_pt(A1,M,X1) \
	 do { error_do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_out_of_bounds_pts
#define error_exit_if_out_of_bounds_pts(A1,M,X1,X2) \
	 do { error_do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_reached
#define error_exit_if_reached() \
	 do { error_do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_reached_pC
#define error_exit_if_reached_pC(X1) \
	 do { error_do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");X1;;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_reached_pi
#define error_exit_if_reached_pi(X1) \
	 do { error_do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_reached_pii
#define error_exit_if_reached_pii(X1,X2) \
	 do { error_do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_reached_piit
#define error_exit_if_reached_piit(X1,X2,X3) \
	 do { error_do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_reached_pit
#define error_exit_if_reached_pit(X1,X2) \
	 do { error_do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_reached_pt
#define error_exit_if_reached_pt(X1) \
	 do { error_do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_exit_if_reached_pts
#define error_exit_if_reached_pts(X1,X2) \
	 do { error_do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef error_return0_if_fail
#define error_return0_if_fail(A1) \
	 do { error_do_if_fail(A1,A1,""#A1,"Sanity constraint",;;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_fail_pC
#define error_return0_if_fail_pC(A1,X1) \
	 do { error_do_if_fail(A1,A1,""#A1,"Sanity constraint",X1;;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_fail_pi
#define error_return0_if_fail_pi(A1,X1) \
	 do { error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_fail_pii
#define error_return0_if_fail_pii(A1,X1,X2) \
	 do { error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_fail_piit
#define error_return0_if_fail_piit(A1,X1,X2,X3) \
	 do { error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_fail_pit
#define error_return0_if_fail_pit(A1,X1,X2) \
	 do { error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_fail_pt
#define error_return0_if_fail_pt(A1,X1) \
	 do { error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_fail_pts
#define error_return0_if_fail_pts(A1,X1,X2) \
	 do { error_do_if_fail(A1,A1,""#A1,"Sanity constraint",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_null
#define error_return0_if_null(A1) \
	 do { error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",;;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_null_pC
#define error_return0_if_null_pC(A1,X1) \
	 do { error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",X1;;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_null_pi
#define error_return0_if_null_pi(A1,X1) \
	 do { error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_null_pii
#define error_return0_if_null_pii(A1,X1,X2) \
	 do { error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_null_piit
#define error_return0_if_null_piit(A1,X1,X2,X3) \
	 do { error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_null_pit
#define error_return0_if_null_pit(A1,X1,X2) \
	 do { error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_null_pt
#define error_return0_if_null_pt(A1,X1) \
	 do { error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_null_pts
#define error_return0_if_null_pts(A1,X1,X2) \
	 do { error_do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Sanity constraint",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_out_of_bounds
#define error_return0_if_out_of_bounds(A1,M) \
	 do { error_do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_out_of_bounds_pC
#define error_return0_if_out_of_bounds_pC(A1,M,X1) \
	 do { error_do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));X1;;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_out_of_bounds_pi
#define error_return0_if_out_of_bounds_pi(A1,M,X1) \
	 do { error_do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_out_of_bounds_pii
#define error_return0_if_out_of_bounds_pii(A1,M,X1,X2) \
	 do { error_do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_out_of_bounds_piit
#define error_return0_if_out_of_bounds_piit(A1,M,X1,X2,X3) \
	 do { error_do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_out_of_bounds_pit
#define error_return0_if_out_of_bounds_pit(A1,M,X1,X2) \
	 do { error_do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_out_of_bounds_pt
#define error_return0_if_out_of_bounds_pt(A1,M,X1) \
	 do { error_do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_out_of_bounds_pts
#define error_return0_if_out_of_bounds_pts(A1,M,X1,X2) \
	 do { error_do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Sanity constraint",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_reached
#define error_return0_if_reached() \
	 do { error_do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_reached_pC
#define error_return0_if_reached_pC(X1) \
	 do { error_do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");X1;;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_reached_pi
#define error_return0_if_reached_pi(X1) \
	 do { error_do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_reached_pii
#define error_return0_if_reached_pii(X1,X2) \
	 do { error_do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_reached_piit
#define error_return0_if_reached_piit(X1,X2,X3) \
	 do { error_do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_reached_pit
#define error_return0_if_reached_pit(X1,X2) \
	 do { error_do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_reached_pt
#define error_return0_if_reached_pt(X1) \
	 do { error_do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef error_return0_if_reached_pts
#define error_return0_if_reached_pts(X1,X2) \
	 do { error_do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef exit1_if_fail
#define exit1_if_fail(A1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",;;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_fail_pC
#define exit1_if_fail_pC(A1,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",X1;;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_fail_pi
#define exit1_if_fail_pi(A1,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_fail_pii
#define exit1_if_fail_pii(A1,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_fail_piit
#define exit1_if_fail_piit(A1,X1,X2,X3) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_fail_pit
#define exit1_if_fail_pit(A1,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_fail_pt
#define exit1_if_fail_pt(A1,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_fail_pts
#define exit1_if_fail_pts(A1,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_null
#define exit1_if_null(A1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",;;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_null_pC
#define exit1_if_null_pC(A1,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",X1;;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_null_pi
#define exit1_if_null_pi(A1,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_null_pii
#define exit1_if_null_pii(A1,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_null_piit
#define exit1_if_null_piit(A1,X1,X2,X3) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_null_pit
#define exit1_if_null_pit(A1,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_null_pt
#define exit1_if_null_pt(A1,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_null_pts
#define exit1_if_null_pts(A1,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_out_of_bounds
#define exit1_if_out_of_bounds(A1,M) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_out_of_bounds_pC
#define exit1_if_out_of_bounds_pC(A1,M,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));X1;;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_out_of_bounds_pi
#define exit1_if_out_of_bounds_pi(A1,M,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_out_of_bounds_pii
#define exit1_if_out_of_bounds_pii(A1,M,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_out_of_bounds_piit
#define exit1_if_out_of_bounds_piit(A1,M,X1,X2,X3) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_out_of_bounds_pit
#define exit1_if_out_of_bounds_pit(A1,M,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_out_of_bounds_pt
#define exit1_if_out_of_bounds_pt(A1,M,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_out_of_bounds_pts
#define exit1_if_out_of_bounds_pts(A1,M,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_reached
#define exit1_if_reached() \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_reached_pC
#define exit1_if_reached_pC(X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");X1;;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_reached_pi
#define exit1_if_reached_pi(X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_reached_pii
#define exit1_if_reached_pii(X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_reached_piit
#define exit1_if_reached_piit(X1,X2,X3) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_reached_pit
#define exit1_if_reached_pit(X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_reached_pt
#define exit1_if_reached_pt(X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit1_if_reached_pts
#define exit1_if_reached_pts(X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;exit(1);;); } while (0) 
#endif

#ifndef exit_if_fail
#define exit_if_fail(A1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",;;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_fail_pC
#define exit_if_fail_pC(A1,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",X1;;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_fail_pi
#define exit_if_fail_pi(A1,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_fail_pii
#define exit_if_fail_pii(A1,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_fail_piit
#define exit_if_fail_piit(A1,X1,X2,X3) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_fail_pit
#define exit_if_fail_pit(A1,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_fail_pt
#define exit_if_fail_pt(A1,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_fail_pts
#define exit_if_fail_pts(A1,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_null
#define exit_if_null(A1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",;;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_null_pC
#define exit_if_null_pC(A1,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",X1;;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_null_pi
#define exit_if_null_pi(A1,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_null_pii
#define exit_if_null_pii(A1,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_null_piit
#define exit_if_null_piit(A1,X1,X2,X3) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_null_pit
#define exit_if_null_pit(A1,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_null_pt
#define exit_if_null_pt(A1,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_null_pts
#define exit_if_null_pts(A1,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_out_of_bounds
#define exit_if_out_of_bounds(A1,M) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_out_of_bounds_pC
#define exit_if_out_of_bounds_pC(A1,M,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));X1;;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_out_of_bounds_pi
#define exit_if_out_of_bounds_pi(A1,M,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_out_of_bounds_pii
#define exit_if_out_of_bounds_pii(A1,M,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_out_of_bounds_piit
#define exit_if_out_of_bounds_piit(A1,M,X1,X2,X3) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_out_of_bounds_pit
#define exit_if_out_of_bounds_pit(A1,M,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_out_of_bounds_pt
#define exit_if_out_of_bounds_pt(A1,M,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_out_of_bounds_pts
#define exit_if_out_of_bounds_pts(A1,M,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_reached
#define exit_if_reached() \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_reached_pC
#define exit_if_reached_pC(X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");X1;;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_reached_pi
#define exit_if_reached_pi(X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_reached_pii
#define exit_if_reached_pii(X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_reached_piit
#define exit_if_reached_piit(X1,X2,X3) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_reached_pit
#define exit_if_reached_pit(X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_reached_pt
#define exit_if_reached_pt(X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef exit_if_reached_pts
#define exit_if_reached_pts(X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;ASSERT_ABORT;;); } while (0) 
#endif

#ifndef nothing_if_fail
#define nothing_if_fail(A1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",;;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_fail_pC
#define nothing_if_fail_pC(A1,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",X1;;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_fail_pi
#define nothing_if_fail_pi(A1,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_fail_pii
#define nothing_if_fail_pii(A1,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_fail_piit
#define nothing_if_fail_piit(A1,X1,X2,X3) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_fail_pit
#define nothing_if_fail_pit(A1,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_fail_pt
#define nothing_if_fail_pt(A1,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_fail_pts
#define nothing_if_fail_pts(A1,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_null
#define nothing_if_null(A1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",;;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_null_pC
#define nothing_if_null_pC(A1,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",X1;;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_null_pi
#define nothing_if_null_pi(A1,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_null_pii
#define nothing_if_null_pii(A1,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_null_piit
#define nothing_if_null_piit(A1,X1,X2,X3) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_null_pit
#define nothing_if_null_pit(A1,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_null_pt
#define nothing_if_null_pt(A1,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_null_pts
#define nothing_if_null_pts(A1,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_out_of_bounds
#define nothing_if_out_of_bounds(A1,M) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_out_of_bounds_pC
#define nothing_if_out_of_bounds_pC(A1,M,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));X1;;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_out_of_bounds_pi
#define nothing_if_out_of_bounds_pi(A1,M,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_out_of_bounds_pii
#define nothing_if_out_of_bounds_pii(A1,M,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_out_of_bounds_piit
#define nothing_if_out_of_bounds_piit(A1,M,X1,X2,X3) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_out_of_bounds_pit
#define nothing_if_out_of_bounds_pit(A1,M,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_out_of_bounds_pt
#define nothing_if_out_of_bounds_pt(A1,M,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_out_of_bounds_pts
#define nothing_if_out_of_bounds_pts(A1,M,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_reached
#define nothing_if_reached() \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_reached_pC
#define nothing_if_reached_pC(X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");X1;;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_reached_pi
#define nothing_if_reached_pi(X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_reached_pii
#define nothing_if_reached_pii(X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_reached_piit
#define nothing_if_reached_piit(X1,X2,X3) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_reached_pit
#define nothing_if_reached_pit(X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_reached_pt
#define nothing_if_reached_pt(X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef nothing_if_reached_pts
#define nothing_if_reached_pts(X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;;;); } while (0) 
#endif

#ifndef return0_if_fail
#define return0_if_fail(A1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",;;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_fail_pC
#define return0_if_fail_pC(A1,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",X1;;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_fail_pi
#define return0_if_fail_pi(A1,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_fail_pii
#define return0_if_fail_pii(A1,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_fail_piit
#define return0_if_fail_piit(A1,X1,X2,X3) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_fail_pit
#define return0_if_fail_pit(A1,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_fail_pt
#define return0_if_fail_pt(A1,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_fail_pts
#define return0_if_fail_pts(A1,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_null
#define return0_if_null(A1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",;;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_null_pC
#define return0_if_null_pC(A1,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",X1;;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_null_pi
#define return0_if_null_pi(A1,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_null_pii
#define return0_if_null_pii(A1,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_null_piit
#define return0_if_null_piit(A1,X1,X2,X3) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_null_pit
#define return0_if_null_pit(A1,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_null_pt
#define return0_if_null_pt(A1,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_null_pts
#define return0_if_null_pts(A1,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_out_of_bounds
#define return0_if_out_of_bounds(A1,M) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_out_of_bounds_pC
#define return0_if_out_of_bounds_pC(A1,M,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));X1;;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_out_of_bounds_pi
#define return0_if_out_of_bounds_pi(A1,M,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_out_of_bounds_pii
#define return0_if_out_of_bounds_pii(A1,M,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_out_of_bounds_piit
#define return0_if_out_of_bounds_piit(A1,M,X1,X2,X3) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_out_of_bounds_pit
#define return0_if_out_of_bounds_pit(A1,M,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_out_of_bounds_pt
#define return0_if_out_of_bounds_pt(A1,M,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_out_of_bounds_pts
#define return0_if_out_of_bounds_pts(A1,M,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_reached
#define return0_if_reached() \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_reached_pC
#define return0_if_reached_pC(X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");X1;;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_reached_pi
#define return0_if_reached_pi(X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_reached_pii
#define return0_if_reached_pii(X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_reached_piit
#define return0_if_reached_piit(X1,X2,X3) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_reached_pit
#define return0_if_reached_pit(X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_reached_pt
#define return0_if_reached_pt(X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return0_if_reached_pts
#define return0_if_reached_pts(X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return 0;;); } while (0) 
#endif

#ifndef return1_if_fail
#define return1_if_fail(A1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",;;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_fail_pC
#define return1_if_fail_pC(A1,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",X1;;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_fail_pi
#define return1_if_fail_pi(A1,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_fail_pii
#define return1_if_fail_pii(A1,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_fail_piit
#define return1_if_fail_piit(A1,X1,X2,X3) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_fail_pit
#define return1_if_fail_pit(A1,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_fail_pt
#define return1_if_fail_pt(A1,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_fail_pts
#define return1_if_fail_pts(A1,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_null
#define return1_if_null(A1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",;;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_null_pC
#define return1_if_null_pC(A1,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",X1;;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_null_pi
#define return1_if_null_pi(A1,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_null_pii
#define return1_if_null_pii(A1,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_null_piit
#define return1_if_null_piit(A1,X1,X2,X3) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_null_pit
#define return1_if_null_pit(A1,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_null_pt
#define return1_if_null_pt(A1,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_null_pts
#define return1_if_null_pts(A1,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_out_of_bounds
#define return1_if_out_of_bounds(A1,M) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_out_of_bounds_pC
#define return1_if_out_of_bounds_pC(A1,M,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));X1;;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_out_of_bounds_pi
#define return1_if_out_of_bounds_pi(A1,M,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_out_of_bounds_pii
#define return1_if_out_of_bounds_pii(A1,M,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_out_of_bounds_piit
#define return1_if_out_of_bounds_piit(A1,M,X1,X2,X3) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_out_of_bounds_pit
#define return1_if_out_of_bounds_pit(A1,M,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_out_of_bounds_pt
#define return1_if_out_of_bounds_pt(A1,M,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_out_of_bounds_pts
#define return1_if_out_of_bounds_pts(A1,M,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_reached
#define return1_if_reached() \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_reached_pC
#define return1_if_reached_pC(X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");X1;;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_reached_pi
#define return1_if_reached_pi(X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_reached_pii
#define return1_if_reached_pii(X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_reached_piit
#define return1_if_reached_piit(X1,X2,X3) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_reached_pit
#define return1_if_reached_pit(X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_reached_pt
#define return1_if_reached_pt(X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return1_if_reached_pts
#define return1_if_reached_pts(X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return 1;;); } while (0) 
#endif

#ifndef return_if_fail
#define return_if_fail(A1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",;;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_fail_pC
#define return_if_fail_pC(A1,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",X1;;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_fail_pi
#define return_if_fail_pi(A1,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_fail_pii
#define return_if_fail_pii(A1,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_fail_piit
#define return_if_fail_piit(A1,X1,X2,X3) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_fail_pit
#define return_if_fail_pit(A1,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_fail_pt
#define return_if_fail_pt(A1,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_fail_pts
#define return_if_fail_pts(A1,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_null
#define return_if_null(A1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",;;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_null_pC
#define return_if_null_pC(A1,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",X1;;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_null_pi
#define return_if_null_pi(A1,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_null_pii
#define return_if_null_pii(A1,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_null_piit
#define return_if_null_piit(A1,X1,X2,X3) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_null_pit
#define return_if_null_pit(A1,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_null_pt
#define return_if_null_pt(A1,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_null_pts
#define return_if_null_pts(A1,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_out_of_bounds
#define return_if_out_of_bounds(A1,M) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_out_of_bounds_pC
#define return_if_out_of_bounds_pC(A1,M,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));X1;;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_out_of_bounds_pi
#define return_if_out_of_bounds_pi(A1,M,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_out_of_bounds_pii
#define return_if_out_of_bounds_pii(A1,M,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_out_of_bounds_piit
#define return_if_out_of_bounds_piit(A1,M,X1,X2,X3) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_out_of_bounds_pit
#define return_if_out_of_bounds_pit(A1,M,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_out_of_bounds_pt
#define return_if_out_of_bounds_pt(A1,M,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_out_of_bounds_pts
#define return_if_out_of_bounds_pts(A1,M,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_reached
#define return_if_reached() \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_reached_pC
#define return_if_reached_pC(X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");X1;;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_reached_pi
#define return_if_reached_pi(X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_reached_pii
#define return_if_reached_pii(X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_reached_piit
#define return_if_reached_piit(X1,X2,X3) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_reached_pit
#define return_if_reached_pit(X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_reached_pt
#define return_if_reached_pt(X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_if_reached_pts
#define return_if_reached_pts(X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return;;); } while (0) 
#endif

#ifndef return_m1_if_fail
#define return_m1_if_fail(A1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",;;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_fail_pC
#define return_m1_if_fail_pC(A1,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",X1;;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_fail_pi
#define return_m1_if_fail_pi(A1,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_fail_pii
#define return_m1_if_fail_pii(A1,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_fail_piit
#define return_m1_if_fail_piit(A1,X1,X2,X3) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_fail_pit
#define return_m1_if_fail_pit(A1,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_fail_pt
#define return_m1_if_fail_pt(A1,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_fail_pts
#define return_m1_if_fail_pts(A1,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_null
#define return_m1_if_null(A1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",;;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_null_pC
#define return_m1_if_null_pC(A1,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",X1;;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_null_pi
#define return_m1_if_null_pi(A1,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_null_pii
#define return_m1_if_null_pii(A1,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_null_piit
#define return_m1_if_null_piit(A1,X1,X2,X3) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_null_pit
#define return_m1_if_null_pit(A1,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_null_pt
#define return_m1_if_null_pt(A1,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_null_pts
#define return_m1_if_null_pts(A1,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_out_of_bounds
#define return_m1_if_out_of_bounds(A1,M) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_out_of_bounds_pC
#define return_m1_if_out_of_bounds_pC(A1,M,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));X1;;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_out_of_bounds_pi
#define return_m1_if_out_of_bounds_pi(A1,M,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_out_of_bounds_pii
#define return_m1_if_out_of_bounds_pii(A1,M,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_out_of_bounds_piit
#define return_m1_if_out_of_bounds_piit(A1,M,X1,X2,X3) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_out_of_bounds_pit
#define return_m1_if_out_of_bounds_pit(A1,M,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_out_of_bounds_pt
#define return_m1_if_out_of_bounds_pt(A1,M,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_out_of_bounds_pts
#define return_m1_if_out_of_bounds_pts(A1,M,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_reached
#define return_m1_if_reached() \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_reached_pC
#define return_m1_if_reached_pC(X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");X1;;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_reached_pi
#define return_m1_if_reached_pi(X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_reached_pii
#define return_m1_if_reached_pii(X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_reached_piit
#define return_m1_if_reached_piit(X1,X2,X3) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_reached_pit
#define return_m1_if_reached_pit(X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_reached_pt
#define return_m1_if_reached_pt(X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_m1_if_reached_pts
#define return_m1_if_reached_pts(X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return -1;;); } while (0) 
#endif

#ifndef return_val_if_fail
#define return_val_if_fail(A1,O) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",;;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_fail_pC
#define return_val_if_fail_pC(A1,O,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",X1;;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_fail_pi
#define return_val_if_fail_pi(A1,O,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_fail_pii
#define return_val_if_fail_pii(A1,O,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_fail_piit
#define return_val_if_fail_piit(A1,O,X1,X2,X3) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_fail_pit
#define return_val_if_fail_pit(A1,O,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_fail_pt
#define return_val_if_fail_pt(A1,O,X1) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_fail_pts
#define return_val_if_fail_pts(A1,O,X1,X2) \
	 do { do_if_fail(A1,A1,""#A1,"Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_null
#define return_val_if_null(A1,O) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",;;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_null_pC
#define return_val_if_null_pC(A1,O,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",X1;;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_null_pi
#define return_val_if_null_pi(A1,O,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_null_pii
#define return_val_if_null_pii(A1,O,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_null_piit
#define return_val_if_null_piit(A1,O,X1,X2,X3) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_null_pit
#define return_val_if_null_pit(A1,O,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_null_pt
#define return_val_if_null_pt(A1,O,X1) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_null_pts
#define return_val_if_null_pts(A1,O,X1,X2) \
	 do { do_if_fail((A1) != NULL,(A1) != NULL,"("#A1") != NULL","Assertion",ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_out_of_bounds
#define return_val_if_out_of_bounds(A1,M,O) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_out_of_bounds_pC
#define return_val_if_out_of_bounds_pC(A1,M,O,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));X1;;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_out_of_bounds_pi
#define return_val_if_out_of_bounds_pi(A1,M,O,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_out_of_bounds_pii
#define return_val_if_out_of_bounds_pii(A1,M,O,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_out_of_bounds_piit
#define return_val_if_out_of_bounds_piit(A1,M,O,X1,X2,X3) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_out_of_bounds_pit
#define return_val_if_out_of_bounds_pit(A1,M,O,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_out_of_bounds_pt
#define return_val_if_out_of_bounds_pt(A1,M,O,X1) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_out_of_bounds_pts
#define return_val_if_out_of_bounds_pts(A1,M,O,X1,X2) \
	 do { do_if_fail(ASSERT_NONNEGATIVE((A1)) && (A1) < (M),ASSERT_NONNEGATIVE((A1)) && (A1) < (M),"ASSERT_NONNEGATIVE(("#A1")) && ""("#A1") < ("#M")","Assertion",ASSERT_EPRINTF_MORE_1 (""#A1"=%ld\n", (long)(A1));ASSERT_EPRINTF_MORE_1 (""#M"=%ld\n", (long)(M));ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_reached
#define return_val_if_reached(O) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_reached_pC
#define return_val_if_reached_pC(O,X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");X1;;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_reached_pi
#define return_val_if_reached_pi(O,X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_reached_pii
#define return_val_if_reached_pii(O,X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_reached_piit
#define return_val_if_reached_piit(O,X1,X2,X3) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 (""#X2"=%ld\n", (long)(X2));ASSERT_EPRINTF_MORE_1 ("%s\n", (X3));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_reached_pit
#define return_val_if_reached_pit(O,X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 (""#X1"=%ld\n", (long)(X1));ASSERT_EPRINTF_MORE_1 ("%s\n", (X2));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_reached_pt
#define return_val_if_reached_pt(O,X1) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));;,ASSERT_END;return (O);;); } while (0) 
#endif

#ifndef return_val_if_reached_pts
#define return_val_if_reached_pts(O,X1,X2) \
	 do { do_if_fail(0,0,"""0","Control flow",ASSERT_EPRINTF_MORE_0 ("This code should never be reached.\n");ASSERT_EPRINTF_MORE_1 ("%s\n", (X1));ASSERT_EPRINTF_MORE_1 (""#X2"='%s'\n", ((X2) == NULL) ? "<NULL>" : ((char const *)((X2))));;,ASSERT_END;return (O);;); } while (0) 
#endif


#else /* !defined(ASSERT_IS_BROKEN) */

#ifndef error_exit_if_fail
#define error_exit_if_fail(A1)
#endif

#ifndef error_exit_if_fail_pC
#define error_exit_if_fail_pC(A1,X1)
#endif

#ifndef error_exit_if_fail_pi
#define error_exit_if_fail_pi(A1,X1)
#endif

#ifndef error_exit_if_fail_pii
#define error_exit_if_fail_pii(A1,X1,X2)
#endif

#ifndef error_exit_if_fail_piit
#define error_exit_if_fail_piit(A1,X1,X2,X3)
#endif

#ifndef error_exit_if_fail_pit
#define error_exit_if_fail_pit(A1,X1,X2)
#endif

#ifndef error_exit_if_fail_pt
#define error_exit_if_fail_pt(A1,X1)
#endif

#ifndef error_exit_if_fail_pts
#define error_exit_if_fail_pts(A1,X1,X2)
#endif

#ifndef error_exit_if_null
#define error_exit_if_null(A1)
#endif

#ifndef error_exit_if_null_pC
#define error_exit_if_null_pC(A1,X1)
#endif

#ifndef error_exit_if_null_pi
#define error_exit_if_null_pi(A1,X1)
#endif

#ifndef error_exit_if_null_pii
#define error_exit_if_null_pii(A1,X1,X2)
#endif

#ifndef error_exit_if_null_piit
#define error_exit_if_null_piit(A1,X1,X2,X3)
#endif

#ifndef error_exit_if_null_pit
#define error_exit_if_null_pit(A1,X1,X2)
#endif

#ifndef error_exit_if_null_pt
#define error_exit_if_null_pt(A1,X1)
#endif

#ifndef error_exit_if_null_pts
#define error_exit_if_null_pts(A1,X1,X2)
#endif

#ifndef error_exit_if_out_of_bounds
#define error_exit_if_out_of_bounds(A1,M)
#endif

#ifndef error_exit_if_out_of_bounds_pC
#define error_exit_if_out_of_bounds_pC(A1,M,X1)
#endif

#ifndef error_exit_if_out_of_bounds_pi
#define error_exit_if_out_of_bounds_pi(A1,M,X1)
#endif

#ifndef error_exit_if_out_of_bounds_pii
#define error_exit_if_out_of_bounds_pii(A1,M,X1,X2)
#endif

#ifndef error_exit_if_out_of_bounds_piit
#define error_exit_if_out_of_bounds_piit(A1,M,X1,X2,X3)
#endif

#ifndef error_exit_if_out_of_bounds_pit
#define error_exit_if_out_of_bounds_pit(A1,M,X1,X2)
#endif

#ifndef error_exit_if_out_of_bounds_pt
#define error_exit_if_out_of_bounds_pt(A1,M,X1)
#endif

#ifndef error_exit_if_out_of_bounds_pts
#define error_exit_if_out_of_bounds_pts(A1,M,X1,X2)
#endif

#ifndef error_exit_if_reached
#define error_exit_if_reached()
#endif

#ifndef error_exit_if_reached_pC
#define error_exit_if_reached_pC(X1)
#endif

#ifndef error_exit_if_reached_pi
#define error_exit_if_reached_pi(X1)
#endif

#ifndef error_exit_if_reached_pii
#define error_exit_if_reached_pii(X1,X2)
#endif

#ifndef error_exit_if_reached_piit
#define error_exit_if_reached_piit(X1,X2,X3)
#endif

#ifndef error_exit_if_reached_pit
#define error_exit_if_reached_pit(X1,X2)
#endif

#ifndef error_exit_if_reached_pt
#define error_exit_if_reached_pt(X1)
#endif

#ifndef error_exit_if_reached_pts
#define error_exit_if_reached_pts(X1,X2)
#endif

#ifndef error_return0_if_fail
#define error_return0_if_fail(A1)
#endif

#ifndef error_return0_if_fail_pC
#define error_return0_if_fail_pC(A1,X1)
#endif

#ifndef error_return0_if_fail_pi
#define error_return0_if_fail_pi(A1,X1)
#endif

#ifndef error_return0_if_fail_pii
#define error_return0_if_fail_pii(A1,X1,X2)
#endif

#ifndef error_return0_if_fail_piit
#define error_return0_if_fail_piit(A1,X1,X2,X3)
#endif

#ifndef error_return0_if_fail_pit
#define error_return0_if_fail_pit(A1,X1,X2)
#endif

#ifndef error_return0_if_fail_pt
#define error_return0_if_fail_pt(A1,X1)
#endif

#ifndef error_return0_if_fail_pts
#define error_return0_if_fail_pts(A1,X1,X2)
#endif

#ifndef error_return0_if_null
#define error_return0_if_null(A1)
#endif

#ifndef error_return0_if_null_pC
#define error_return0_if_null_pC(A1,X1)
#endif

#ifndef error_return0_if_null_pi
#define error_return0_if_null_pi(A1,X1)
#endif

#ifndef error_return0_if_null_pii
#define error_return0_if_null_pii(A1,X1,X2)
#endif

#ifndef error_return0_if_null_piit
#define error_return0_if_null_piit(A1,X1,X2,X3)
#endif

#ifndef error_return0_if_null_pit
#define error_return0_if_null_pit(A1,X1,X2)
#endif

#ifndef error_return0_if_null_pt
#define error_return0_if_null_pt(A1,X1)
#endif

#ifndef error_return0_if_null_pts
#define error_return0_if_null_pts(A1,X1,X2)
#endif

#ifndef error_return0_if_out_of_bounds
#define error_return0_if_out_of_bounds(A1,M)
#endif

#ifndef error_return0_if_out_of_bounds_pC
#define error_return0_if_out_of_bounds_pC(A1,M,X1)
#endif

#ifndef error_return0_if_out_of_bounds_pi
#define error_return0_if_out_of_bounds_pi(A1,M,X1)
#endif

#ifndef error_return0_if_out_of_bounds_pii
#define error_return0_if_out_of_bounds_pii(A1,M,X1,X2)
#endif

#ifndef error_return0_if_out_of_bounds_piit
#define error_return0_if_out_of_bounds_piit(A1,M,X1,X2,X3)
#endif

#ifndef error_return0_if_out_of_bounds_pit
#define error_return0_if_out_of_bounds_pit(A1,M,X1,X2)
#endif

#ifndef error_return0_if_out_of_bounds_pt
#define error_return0_if_out_of_bounds_pt(A1,M,X1)
#endif

#ifndef error_return0_if_out_of_bounds_pts
#define error_return0_if_out_of_bounds_pts(A1,M,X1,X2)
#endif

#ifndef error_return0_if_reached
#define error_return0_if_reached()
#endif

#ifndef error_return0_if_reached_pC
#define error_return0_if_reached_pC(X1)
#endif

#ifndef error_return0_if_reached_pi
#define error_return0_if_reached_pi(X1)
#endif

#ifndef error_return0_if_reached_pii
#define error_return0_if_reached_pii(X1,X2)
#endif

#ifndef error_return0_if_reached_piit
#define error_return0_if_reached_piit(X1,X2,X3)
#endif

#ifndef error_return0_if_reached_pit
#define error_return0_if_reached_pit(X1,X2)
#endif

#ifndef error_return0_if_reached_pt
#define error_return0_if_reached_pt(X1)
#endif

#ifndef error_return0_if_reached_pts
#define error_return0_if_reached_pts(X1,X2)
#endif

#ifndef exit1_if_fail
#define exit1_if_fail(A1)
#endif

#ifndef exit1_if_fail_pC
#define exit1_if_fail_pC(A1,X1)
#endif

#ifndef exit1_if_fail_pi
#define exit1_if_fail_pi(A1,X1)
#endif

#ifndef exit1_if_fail_pii
#define exit1_if_fail_pii(A1,X1,X2)
#endif

#ifndef exit1_if_fail_piit
#define exit1_if_fail_piit(A1,X1,X2,X3)
#endif

#ifndef exit1_if_fail_pit
#define exit1_if_fail_pit(A1,X1,X2)
#endif

#ifndef exit1_if_fail_pt
#define exit1_if_fail_pt(A1,X1)
#endif

#ifndef exit1_if_fail_pts
#define exit1_if_fail_pts(A1,X1,X2)
#endif

#ifndef exit1_if_null
#define exit1_if_null(A1)
#endif

#ifndef exit1_if_null_pC
#define exit1_if_null_pC(A1,X1)
#endif

#ifndef exit1_if_null_pi
#define exit1_if_null_pi(A1,X1)
#endif

#ifndef exit1_if_null_pii
#define exit1_if_null_pii(A1,X1,X2)
#endif

#ifndef exit1_if_null_piit
#define exit1_if_null_piit(A1,X1,X2,X3)
#endif

#ifndef exit1_if_null_pit
#define exit1_if_null_pit(A1,X1,X2)
#endif

#ifndef exit1_if_null_pt
#define exit1_if_null_pt(A1,X1)
#endif

#ifndef exit1_if_null_pts
#define exit1_if_null_pts(A1,X1,X2)
#endif

#ifndef exit1_if_out_of_bounds
#define exit1_if_out_of_bounds(A1,M)
#endif

#ifndef exit1_if_out_of_bounds_pC
#define exit1_if_out_of_bounds_pC(A1,M,X1)
#endif

#ifndef exit1_if_out_of_bounds_pi
#define exit1_if_out_of_bounds_pi(A1,M,X1)
#endif

#ifndef exit1_if_out_of_bounds_pii
#define exit1_if_out_of_bounds_pii(A1,M,X1,X2)
#endif

#ifndef exit1_if_out_of_bounds_piit
#define exit1_if_out_of_bounds_piit(A1,M,X1,X2,X3)
#endif

#ifndef exit1_if_out_of_bounds_pit
#define exit1_if_out_of_bounds_pit(A1,M,X1,X2)
#endif

#ifndef exit1_if_out_of_bounds_pt
#define exit1_if_out_of_bounds_pt(A1,M,X1)
#endif

#ifndef exit1_if_out_of_bounds_pts
#define exit1_if_out_of_bounds_pts(A1,M,X1,X2)
#endif

#ifndef exit1_if_reached
#define exit1_if_reached()
#endif

#ifndef exit1_if_reached_pC
#define exit1_if_reached_pC(X1)
#endif

#ifndef exit1_if_reached_pi
#define exit1_if_reached_pi(X1)
#endif

#ifndef exit1_if_reached_pii
#define exit1_if_reached_pii(X1,X2)
#endif

#ifndef exit1_if_reached_piit
#define exit1_if_reached_piit(X1,X2,X3)
#endif

#ifndef exit1_if_reached_pit
#define exit1_if_reached_pit(X1,X2)
#endif

#ifndef exit1_if_reached_pt
#define exit1_if_reached_pt(X1)
#endif

#ifndef exit1_if_reached_pts
#define exit1_if_reached_pts(X1,X2)
#endif

#ifndef exit_if_fail
#define exit_if_fail(A1)
#endif

#ifndef exit_if_fail_pC
#define exit_if_fail_pC(A1,X1)
#endif

#ifndef exit_if_fail_pi
#define exit_if_fail_pi(A1,X1)
#endif

#ifndef exit_if_fail_pii
#define exit_if_fail_pii(A1,X1,X2)
#endif

#ifndef exit_if_fail_piit
#define exit_if_fail_piit(A1,X1,X2,X3)
#endif

#ifndef exit_if_fail_pit
#define exit_if_fail_pit(A1,X1,X2)
#endif

#ifndef exit_if_fail_pt
#define exit_if_fail_pt(A1,X1)
#endif

#ifndef exit_if_fail_pts
#define exit_if_fail_pts(A1,X1,X2)
#endif

#ifndef exit_if_null
#define exit_if_null(A1)
#endif

#ifndef exit_if_null_pC
#define exit_if_null_pC(A1,X1)
#endif

#ifndef exit_if_null_pi
#define exit_if_null_pi(A1,X1)
#endif

#ifndef exit_if_null_pii
#define exit_if_null_pii(A1,X1,X2)
#endif

#ifndef exit_if_null_piit
#define exit_if_null_piit(A1,X1,X2,X3)
#endif

#ifndef exit_if_null_pit
#define exit_if_null_pit(A1,X1,X2)
#endif

#ifndef exit_if_null_pt
#define exit_if_null_pt(A1,X1)
#endif

#ifndef exit_if_null_pts
#define exit_if_null_pts(A1,X1,X2)
#endif

#ifndef exit_if_out_of_bounds
#define exit_if_out_of_bounds(A1,M)
#endif

#ifndef exit_if_out_of_bounds_pC
#define exit_if_out_of_bounds_pC(A1,M,X1)
#endif

#ifndef exit_if_out_of_bounds_pi
#define exit_if_out_of_bounds_pi(A1,M,X1)
#endif

#ifndef exit_if_out_of_bounds_pii
#define exit_if_out_of_bounds_pii(A1,M,X1,X2)
#endif

#ifndef exit_if_out_of_bounds_piit
#define exit_if_out_of_bounds_piit(A1,M,X1,X2,X3)
#endif

#ifndef exit_if_out_of_bounds_pit
#define exit_if_out_of_bounds_pit(A1,M,X1,X2)
#endif

#ifndef exit_if_out_of_bounds_pt
#define exit_if_out_of_bounds_pt(A1,M,X1)
#endif

#ifndef exit_if_out_of_bounds_pts
#define exit_if_out_of_bounds_pts(A1,M,X1,X2)
#endif

#ifndef exit_if_reached
#define exit_if_reached()
#endif

#ifndef exit_if_reached_pC
#define exit_if_reached_pC(X1)
#endif

#ifndef exit_if_reached_pi
#define exit_if_reached_pi(X1)
#endif

#ifndef exit_if_reached_pii
#define exit_if_reached_pii(X1,X2)
#endif

#ifndef exit_if_reached_piit
#define exit_if_reached_piit(X1,X2,X3)
#endif

#ifndef exit_if_reached_pit
#define exit_if_reached_pit(X1,X2)
#endif

#ifndef exit_if_reached_pt
#define exit_if_reached_pt(X1)
#endif

#ifndef exit_if_reached_pts
#define exit_if_reached_pts(X1,X2)
#endif

#ifndef nothing_if_fail
#define nothing_if_fail(A1)
#endif

#ifndef nothing_if_fail_pC
#define nothing_if_fail_pC(A1,X1)
#endif

#ifndef nothing_if_fail_pi
#define nothing_if_fail_pi(A1,X1)
#endif

#ifndef nothing_if_fail_pii
#define nothing_if_fail_pii(A1,X1,X2)
#endif

#ifndef nothing_if_fail_piit
#define nothing_if_fail_piit(A1,X1,X2,X3)
#endif

#ifndef nothing_if_fail_pit
#define nothing_if_fail_pit(A1,X1,X2)
#endif

#ifndef nothing_if_fail_pt
#define nothing_if_fail_pt(A1,X1)
#endif

#ifndef nothing_if_fail_pts
#define nothing_if_fail_pts(A1,X1,X2)
#endif

#ifndef nothing_if_null
#define nothing_if_null(A1)
#endif

#ifndef nothing_if_null_pC
#define nothing_if_null_pC(A1,X1)
#endif

#ifndef nothing_if_null_pi
#define nothing_if_null_pi(A1,X1)
#endif

#ifndef nothing_if_null_pii
#define nothing_if_null_pii(A1,X1,X2)
#endif

#ifndef nothing_if_null_piit
#define nothing_if_null_piit(A1,X1,X2,X3)
#endif

#ifndef nothing_if_null_pit
#define nothing_if_null_pit(A1,X1,X2)
#endif

#ifndef nothing_if_null_pt
#define nothing_if_null_pt(A1,X1)
#endif

#ifndef nothing_if_null_pts
#define nothing_if_null_pts(A1,X1,X2)
#endif

#ifndef nothing_if_out_of_bounds
#define nothing_if_out_of_bounds(A1,M)
#endif

#ifndef nothing_if_out_of_bounds_pC
#define nothing_if_out_of_bounds_pC(A1,M,X1)
#endif

#ifndef nothing_if_out_of_bounds_pi
#define nothing_if_out_of_bounds_pi(A1,M,X1)
#endif

#ifndef nothing_if_out_of_bounds_pii
#define nothing_if_out_of_bounds_pii(A1,M,X1,X2)
#endif

#ifndef nothing_if_out_of_bounds_piit
#define nothing_if_out_of_bounds_piit(A1,M,X1,X2,X3)
#endif

#ifndef nothing_if_out_of_bounds_pit
#define nothing_if_out_of_bounds_pit(A1,M,X1,X2)
#endif

#ifndef nothing_if_out_of_bounds_pt
#define nothing_if_out_of_bounds_pt(A1,M,X1)
#endif

#ifndef nothing_if_out_of_bounds_pts
#define nothing_if_out_of_bounds_pts(A1,M,X1,X2)
#endif

#ifndef nothing_if_reached
#define nothing_if_reached()
#endif

#ifndef nothing_if_reached_pC
#define nothing_if_reached_pC(X1)
#endif

#ifndef nothing_if_reached_pi
#define nothing_if_reached_pi(X1)
#endif

#ifndef nothing_if_reached_pii
#define nothing_if_reached_pii(X1,X2)
#endif

#ifndef nothing_if_reached_piit
#define nothing_if_reached_piit(X1,X2,X3)
#endif

#ifndef nothing_if_reached_pit
#define nothing_if_reached_pit(X1,X2)
#endif

#ifndef nothing_if_reached_pt
#define nothing_if_reached_pt(X1)
#endif

#ifndef nothing_if_reached_pts
#define nothing_if_reached_pts(X1,X2)
#endif

#ifndef return0_if_fail
#define return0_if_fail(A1)
#endif

#ifndef return0_if_fail_pC
#define return0_if_fail_pC(A1,X1)
#endif

#ifndef return0_if_fail_pi
#define return0_if_fail_pi(A1,X1)
#endif

#ifndef return0_if_fail_pii
#define return0_if_fail_pii(A1,X1,X2)
#endif

#ifndef return0_if_fail_piit
#define return0_if_fail_piit(A1,X1,X2,X3)
#endif

#ifndef return0_if_fail_pit
#define return0_if_fail_pit(A1,X1,X2)
#endif

#ifndef return0_if_fail_pt
#define return0_if_fail_pt(A1,X1)
#endif

#ifndef return0_if_fail_pts
#define return0_if_fail_pts(A1,X1,X2)
#endif

#ifndef return0_if_null
#define return0_if_null(A1)
#endif

#ifndef return0_if_null_pC
#define return0_if_null_pC(A1,X1)
#endif

#ifndef return0_if_null_pi
#define return0_if_null_pi(A1,X1)
#endif

#ifndef return0_if_null_pii
#define return0_if_null_pii(A1,X1,X2)
#endif

#ifndef return0_if_null_piit
#define return0_if_null_piit(A1,X1,X2,X3)
#endif

#ifndef return0_if_null_pit
#define return0_if_null_pit(A1,X1,X2)
#endif

#ifndef return0_if_null_pt
#define return0_if_null_pt(A1,X1)
#endif

#ifndef return0_if_null_pts
#define return0_if_null_pts(A1,X1,X2)
#endif

#ifndef return0_if_out_of_bounds
#define return0_if_out_of_bounds(A1,M)
#endif

#ifndef return0_if_out_of_bounds_pC
#define return0_if_out_of_bounds_pC(A1,M,X1)
#endif

#ifndef return0_if_out_of_bounds_pi
#define return0_if_out_of_bounds_pi(A1,M,X1)
#endif

#ifndef return0_if_out_of_bounds_pii
#define return0_if_out_of_bounds_pii(A1,M,X1,X2)
#endif

#ifndef return0_if_out_of_bounds_piit
#define return0_if_out_of_bounds_piit(A1,M,X1,X2,X3)
#endif

#ifndef return0_if_out_of_bounds_pit
#define return0_if_out_of_bounds_pit(A1,M,X1,X2)
#endif

#ifndef return0_if_out_of_bounds_pt
#define return0_if_out_of_bounds_pt(A1,M,X1)
#endif

#ifndef return0_if_out_of_bounds_pts
#define return0_if_out_of_bounds_pts(A1,M,X1,X2)
#endif

#ifndef return0_if_reached
#define return0_if_reached()
#endif

#ifndef return0_if_reached_pC
#define return0_if_reached_pC(X1)
#endif

#ifndef return0_if_reached_pi
#define return0_if_reached_pi(X1)
#endif

#ifndef return0_if_reached_pii
#define return0_if_reached_pii(X1,X2)
#endif

#ifndef return0_if_reached_piit
#define return0_if_reached_piit(X1,X2,X3)
#endif

#ifndef return0_if_reached_pit
#define return0_if_reached_pit(X1,X2)
#endif

#ifndef return0_if_reached_pt
#define return0_if_reached_pt(X1)
#endif

#ifndef return0_if_reached_pts
#define return0_if_reached_pts(X1,X2)
#endif

#ifndef return1_if_fail
#define return1_if_fail(A1)
#endif

#ifndef return1_if_fail_pC
#define return1_if_fail_pC(A1,X1)
#endif

#ifndef return1_if_fail_pi
#define return1_if_fail_pi(A1,X1)
#endif

#ifndef return1_if_fail_pii
#define return1_if_fail_pii(A1,X1,X2)
#endif

#ifndef return1_if_fail_piit
#define return1_if_fail_piit(A1,X1,X2,X3)
#endif

#ifndef return1_if_fail_pit
#define return1_if_fail_pit(A1,X1,X2)
#endif

#ifndef return1_if_fail_pt
#define return1_if_fail_pt(A1,X1)
#endif

#ifndef return1_if_fail_pts
#define return1_if_fail_pts(A1,X1,X2)
#endif

#ifndef return1_if_null
#define return1_if_null(A1)
#endif

#ifndef return1_if_null_pC
#define return1_if_null_pC(A1,X1)
#endif

#ifndef return1_if_null_pi
#define return1_if_null_pi(A1,X1)
#endif

#ifndef return1_if_null_pii
#define return1_if_null_pii(A1,X1,X2)
#endif

#ifndef return1_if_null_piit
#define return1_if_null_piit(A1,X1,X2,X3)
#endif

#ifndef return1_if_null_pit
#define return1_if_null_pit(A1,X1,X2)
#endif

#ifndef return1_if_null_pt
#define return1_if_null_pt(A1,X1)
#endif

#ifndef return1_if_null_pts
#define return1_if_null_pts(A1,X1,X2)
#endif

#ifndef return1_if_out_of_bounds
#define return1_if_out_of_bounds(A1,M)
#endif

#ifndef return1_if_out_of_bounds_pC
#define return1_if_out_of_bounds_pC(A1,M,X1)
#endif

#ifndef return1_if_out_of_bounds_pi
#define return1_if_out_of_bounds_pi(A1,M,X1)
#endif

#ifndef return1_if_out_of_bounds_pii
#define return1_if_out_of_bounds_pii(A1,M,X1,X2)
#endif

#ifndef return1_if_out_of_bounds_piit
#define return1_if_out_of_bounds_piit(A1,M,X1,X2,X3)
#endif

#ifndef return1_if_out_of_bounds_pit
#define return1_if_out_of_bounds_pit(A1,M,X1,X2)
#endif

#ifndef return1_if_out_of_bounds_pt
#define return1_if_out_of_bounds_pt(A1,M,X1)
#endif

#ifndef return1_if_out_of_bounds_pts
#define return1_if_out_of_bounds_pts(A1,M,X1,X2)
#endif

#ifndef return1_if_reached
#define return1_if_reached()
#endif

#ifndef return1_if_reached_pC
#define return1_if_reached_pC(X1)
#endif

#ifndef return1_if_reached_pi
#define return1_if_reached_pi(X1)
#endif

#ifndef return1_if_reached_pii
#define return1_if_reached_pii(X1,X2)
#endif

#ifndef return1_if_reached_piit
#define return1_if_reached_piit(X1,X2,X3)
#endif

#ifndef return1_if_reached_pit
#define return1_if_reached_pit(X1,X2)
#endif

#ifndef return1_if_reached_pt
#define return1_if_reached_pt(X1)
#endif

#ifndef return1_if_reached_pts
#define return1_if_reached_pts(X1,X2)
#endif

#ifndef return_if_fail
#define return_if_fail(A1)
#endif

#ifndef return_if_fail_pC
#define return_if_fail_pC(A1,X1)
#endif

#ifndef return_if_fail_pi
#define return_if_fail_pi(A1,X1)
#endif

#ifndef return_if_fail_pii
#define return_if_fail_pii(A1,X1,X2)
#endif

#ifndef return_if_fail_piit
#define return_if_fail_piit(A1,X1,X2,X3)
#endif

#ifndef return_if_fail_pit
#define return_if_fail_pit(A1,X1,X2)
#endif

#ifndef return_if_fail_pt
#define return_if_fail_pt(A1,X1)
#endif

#ifndef return_if_fail_pts
#define return_if_fail_pts(A1,X1,X2)
#endif

#ifndef return_if_null
#define return_if_null(A1)
#endif

#ifndef return_if_null_pC
#define return_if_null_pC(A1,X1)
#endif

#ifndef return_if_null_pi
#define return_if_null_pi(A1,X1)
#endif

#ifndef return_if_null_pii
#define return_if_null_pii(A1,X1,X2)
#endif

#ifndef return_if_null_piit
#define return_if_null_piit(A1,X1,X2,X3)
#endif

#ifndef return_if_null_pit
#define return_if_null_pit(A1,X1,X2)
#endif

#ifndef return_if_null_pt
#define return_if_null_pt(A1,X1)
#endif

#ifndef return_if_null_pts
#define return_if_null_pts(A1,X1,X2)
#endif

#ifndef return_if_out_of_bounds
#define return_if_out_of_bounds(A1,M)
#endif

#ifndef return_if_out_of_bounds_pC
#define return_if_out_of_bounds_pC(A1,M,X1)
#endif

#ifndef return_if_out_of_bounds_pi
#define return_if_out_of_bounds_pi(A1,M,X1)
#endif

#ifndef return_if_out_of_bounds_pii
#define return_if_out_of_bounds_pii(A1,M,X1,X2)
#endif

#ifndef return_if_out_of_bounds_piit
#define return_if_out_of_bounds_piit(A1,M,X1,X2,X3)
#endif

#ifndef return_if_out_of_bounds_pit
#define return_if_out_of_bounds_pit(A1,M,X1,X2)
#endif

#ifndef return_if_out_of_bounds_pt
#define return_if_out_of_bounds_pt(A1,M,X1)
#endif

#ifndef return_if_out_of_bounds_pts
#define return_if_out_of_bounds_pts(A1,M,X1,X2)
#endif

#ifndef return_if_reached
#define return_if_reached()
#endif

#ifndef return_if_reached_pC
#define return_if_reached_pC(X1)
#endif

#ifndef return_if_reached_pi
#define return_if_reached_pi(X1)
#endif

#ifndef return_if_reached_pii
#define return_if_reached_pii(X1,X2)
#endif

#ifndef return_if_reached_piit
#define return_if_reached_piit(X1,X2,X3)
#endif

#ifndef return_if_reached_pit
#define return_if_reached_pit(X1,X2)
#endif

#ifndef return_if_reached_pt
#define return_if_reached_pt(X1)
#endif

#ifndef return_if_reached_pts
#define return_if_reached_pts(X1,X2)
#endif

#ifndef return_m1_if_fail
#define return_m1_if_fail(A1)
#endif

#ifndef return_m1_if_fail_pC
#define return_m1_if_fail_pC(A1,X1)
#endif

#ifndef return_m1_if_fail_pi
#define return_m1_if_fail_pi(A1,X1)
#endif

#ifndef return_m1_if_fail_pii
#define return_m1_if_fail_pii(A1,X1,X2)
#endif

#ifndef return_m1_if_fail_piit
#define return_m1_if_fail_piit(A1,X1,X2,X3)
#endif

#ifndef return_m1_if_fail_pit
#define return_m1_if_fail_pit(A1,X1,X2)
#endif

#ifndef return_m1_if_fail_pt
#define return_m1_if_fail_pt(A1,X1)
#endif

#ifndef return_m1_if_fail_pts
#define return_m1_if_fail_pts(A1,X1,X2)
#endif

#ifndef return_m1_if_null
#define return_m1_if_null(A1)
#endif

#ifndef return_m1_if_null_pC
#define return_m1_if_null_pC(A1,X1)
#endif

#ifndef return_m1_if_null_pi
#define return_m1_if_null_pi(A1,X1)
#endif

#ifndef return_m1_if_null_pii
#define return_m1_if_null_pii(A1,X1,X2)
#endif

#ifndef return_m1_if_null_piit
#define return_m1_if_null_piit(A1,X1,X2,X3)
#endif

#ifndef return_m1_if_null_pit
#define return_m1_if_null_pit(A1,X1,X2)
#endif

#ifndef return_m1_if_null_pt
#define return_m1_if_null_pt(A1,X1)
#endif

#ifndef return_m1_if_null_pts
#define return_m1_if_null_pts(A1,X1,X2)
#endif

#ifndef return_m1_if_out_of_bounds
#define return_m1_if_out_of_bounds(A1,M)
#endif

#ifndef return_m1_if_out_of_bounds_pC
#define return_m1_if_out_of_bounds_pC(A1,M,X1)
#endif

#ifndef return_m1_if_out_of_bounds_pi
#define return_m1_if_out_of_bounds_pi(A1,M,X1)
#endif

#ifndef return_m1_if_out_of_bounds_pii
#define return_m1_if_out_of_bounds_pii(A1,M,X1,X2)
#endif

#ifndef return_m1_if_out_of_bounds_piit
#define return_m1_if_out_of_bounds_piit(A1,M,X1,X2,X3)
#endif

#ifndef return_m1_if_out_of_bounds_pit
#define return_m1_if_out_of_bounds_pit(A1,M,X1,X2)
#endif

#ifndef return_m1_if_out_of_bounds_pt
#define return_m1_if_out_of_bounds_pt(A1,M,X1)
#endif

#ifndef return_m1_if_out_of_bounds_pts
#define return_m1_if_out_of_bounds_pts(A1,M,X1,X2)
#endif

#ifndef return_m1_if_reached
#define return_m1_if_reached()
#endif

#ifndef return_m1_if_reached_pC
#define return_m1_if_reached_pC(X1)
#endif

#ifndef return_m1_if_reached_pi
#define return_m1_if_reached_pi(X1)
#endif

#ifndef return_m1_if_reached_pii
#define return_m1_if_reached_pii(X1,X2)
#endif

#ifndef return_m1_if_reached_piit
#define return_m1_if_reached_piit(X1,X2,X3)
#endif

#ifndef return_m1_if_reached_pit
#define return_m1_if_reached_pit(X1,X2)
#endif

#ifndef return_m1_if_reached_pt
#define return_m1_if_reached_pt(X1)
#endif

#ifndef return_m1_if_reached_pts
#define return_m1_if_reached_pts(X1,X2)
#endif

#ifndef return_val_if_fail
#define return_val_if_fail(A1,O)
#endif

#ifndef return_val_if_fail_pC
#define return_val_if_fail_pC(A1,O,X1)
#endif

#ifndef return_val_if_fail_pi
#define return_val_if_fail_pi(A1,O,X1)
#endif

#ifndef return_val_if_fail_pii
#define return_val_if_fail_pii(A1,O,X1,X2)
#endif

#ifndef return_val_if_fail_piit
#define return_val_if_fail_piit(A1,O,X1,X2,X3)
#endif

#ifndef return_val_if_fail_pit
#define return_val_if_fail_pit(A1,O,X1,X2)
#endif

#ifndef return_val_if_fail_pt
#define return_val_if_fail_pt(A1,O,X1)
#endif

#ifndef return_val_if_fail_pts
#define return_val_if_fail_pts(A1,O,X1,X2)
#endif

#ifndef return_val_if_null
#define return_val_if_null(A1,O)
#endif

#ifndef return_val_if_null_pC
#define return_val_if_null_pC(A1,O,X1)
#endif

#ifndef return_val_if_null_pi
#define return_val_if_null_pi(A1,O,X1)
#endif

#ifndef return_val_if_null_pii
#define return_val_if_null_pii(A1,O,X1,X2)
#endif

#ifndef return_val_if_null_piit
#define return_val_if_null_piit(A1,O,X1,X2,X3)
#endif

#ifndef return_val_if_null_pit
#define return_val_if_null_pit(A1,O,X1,X2)
#endif

#ifndef return_val_if_null_pt
#define return_val_if_null_pt(A1,O,X1)
#endif

#ifndef return_val_if_null_pts
#define return_val_if_null_pts(A1,O,X1,X2)
#endif

#ifndef return_val_if_out_of_bounds
#define return_val_if_out_of_bounds(A1,M,O)
#endif

#ifndef return_val_if_out_of_bounds_pC
#define return_val_if_out_of_bounds_pC(A1,M,O,X1)
#endif

#ifndef return_val_if_out_of_bounds_pi
#define return_val_if_out_of_bounds_pi(A1,M,O,X1)
#endif

#ifndef return_val_if_out_of_bounds_pii
#define return_val_if_out_of_bounds_pii(A1,M,O,X1,X2)
#endif

#ifndef return_val_if_out_of_bounds_piit
#define return_val_if_out_of_bounds_piit(A1,M,O,X1,X2,X3)
#endif

#ifndef return_val_if_out_of_bounds_pit
#define return_val_if_out_of_bounds_pit(A1,M,O,X1,X2)
#endif

#ifndef return_val_if_out_of_bounds_pt
#define return_val_if_out_of_bounds_pt(A1,M,O,X1)
#endif

#ifndef return_val_if_out_of_bounds_pts
#define return_val_if_out_of_bounds_pts(A1,M,O,X1,X2)
#endif

#ifndef return_val_if_reached
#define return_val_if_reached(O)
#endif

#ifndef return_val_if_reached_pC
#define return_val_if_reached_pC(O,X1)
#endif

#ifndef return_val_if_reached_pi
#define return_val_if_reached_pi(O,X1)
#endif

#ifndef return_val_if_reached_pii
#define return_val_if_reached_pii(O,X1,X2)
#endif

#ifndef return_val_if_reached_piit
#define return_val_if_reached_piit(O,X1,X2,X3)
#endif

#ifndef return_val_if_reached_pit
#define return_val_if_reached_pit(O,X1,X2)
#endif

#ifndef return_val_if_reached_pt
#define return_val_if_reached_pt(O,X1)
#endif

#ifndef return_val_if_reached_pts
#define return_val_if_reached_pts(O,X1,X2)
#endif

#endif /* !defined(ASSERT_IS_BROKEN) */


#endif /* !defined(HT_FAILURE_H) */
