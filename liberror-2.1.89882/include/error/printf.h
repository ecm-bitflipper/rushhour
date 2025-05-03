/* -*- Mode: C -*- */

#ifndef HT_ERROR_EPRINTF_H
#define HT_ERROR_EPRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

#ifdef IN_LIBERROR_COMPILING
#  include "error/erwin/defs.h"
#  include "error/erwin/forwards.h"
#else
#  include <error/erwin/defs.h>
#  include <error/erwin/forwards.h>
#endif

/* Printing */

/* ********************************************************************** */

/* for the address type, we will not have a configure option for 32bit
 * addresses, since printing errors is a task that needs no speed
 * optimisations */
#ifdef ERWIN_UNSIGNED_LONG_LONG
typedef ERWIN_UNSIGNED_LONG_LONG err_address_t;
#define ERR_FORMAT_ADDRESS "0x%Lx"
#else
typedef unsigned long err_address_t;
#define ERR_FORMAT_ADDRESS "0x%lx"
#endif

/* ********************************************************************** */

struct err_ext_address_t;
#ifdef __cplusplus
typedef struct err_ext_address_t ErrExtAddress;
#else
typedef struct err_ext_address_t err_ext_address_t;
#endif

enum err_preposition_t {
    ERR_PREP_NONE,
    ERR_PREP_CAPITAL_AT,
    ERR_PREP_CAPITAL_FROM,
    ERR_PREP_CAPITAL_TO,
    ERR_PREP_LOWER_AT,
    ERR_PREP_LOWER_FROM,
    ERR_PREP_LOWER_TO
};
#ifdef __cplusplus
typedef enum err_preposition_t ErrPreposition;
#else
typedef enum err_preposition_t err_preposition_t;
#endif

enum err_format_style_t {
    ERR_FS_HUMAN,       /* readable for humans: this should be the old behaviour before
                         * this type was introduced. */
    ERR_FS_ADDRESS,     /* only the plain address information */
    ERR_FS_LOCATION_ID, /* if known, the location id */
    ERR_FS_ROUTINE,     /* if known, the routine name */
    ERR_FS_ROUTINE_ID   /* if known, the routine id */
};
#ifdef __cplusplus
typedef enum err_format_style_t ErrFormatStyle;
#else
typedef enum err_format_style_t err_format_style_t;
#endif

struct err_position_t;
#ifdef __cplusplus
typedef struct err_position_t ErrPosition;
#else
typedef struct err_position_t err_position_t;
#endif

struct err_ext_address_class_t {
    void                 (* destruct)    (err_ext_address_t *);

    err_ext_address_t *  (* clone)       (err_ext_address_t const *);

    void                 (* format)      (err_v_char_t *,
                                          err_ext_address_t const *,
                                          err_preposition_t);

    err_address_t        (* to_linear)   (err_ext_address_t const *);

    /* The following one may be NULL: */
    void                 (* resolve)     (int /*tag*/,
                                          int /*orig_tag*/,
                                          int /*number*/,
                                          err_position_t * /*pos*/);

    void                 (* format_ext)  (err_v_char_t *,
                                          err_ext_address_t const *,
                                          err_preposition_t,
                                          err_format_style_t);
        /* if non-null, preferred over format, otherwise, format is tried.
         * if this is non-null, liberror will never invoke the old-style function,
         * so it may be NULL. */
};

#ifdef __cplusplus
typedef struct err_ext_address_class_t ErrExtAddressClass;
#else
typedef struct err_ext_address_class_t err_ext_address_class_t;
#endif

struct err_ext_address_t {
    err_ext_address_class_t const *klass;
#ifdef __cplusplus
    err_ext_address_t (err_ext_address_class_t const *a):
        klass  (a)
    {}

    /* Redirect the virtual functions to the C interface: */
    void destruct ()
        { if (this) klass->destruct (this); }

    err_ext_address_t *clone() const
        { return klass->clone (this); }

    void format (err_v_char_t *v,
                 ErrPreposition p = ERR_PREP_NONE,
                 ErrFormatStyle s = ERR_FS_HUMAN) const
        {
            if (this) {
               if (klass->format_ext)
                   klass->format_ext (v, this, p, s);
               else
               if (s == ERR_FS_HUMAN)
                   klass->format (v, this, p);
               /* otherwise we print nothing since we cannot format this correctly. */
            }
        }

    ErrVChar to_vchar(ErrPreposition p = ERR_PREP_NONE) const;

    err_address_t to_linear (void) const
       { return klass->to_linear (this); }

    void resolve (int tag, int orig_tag, int number, err_position_t *pos) const
       { if (this && klass->resolve)
             klass->resolve (tag, orig_tag, number, pos);
       }
#endif
};

#ifdef __cplusplus
extern "C" {
#endif

/* and the class: */
extern err_ext_address_class_t const err_normal_address_class_s;
#define err_normal_address_class (&err_normal_address_class_s)

#ifdef __cplusplus
}
#endif

struct err_normal_address_t {
    err_ext_address_t super;
    err_address_t address;
#ifdef __cplusplus
    err_normal_address_t (err_address_t a):
        super (err_normal_address_class),
        address (a)
    {}
#endif
};
#ifdef __cplusplus
typedef struct err_normal_address_t ErrNormalAddress;
#else
typedef struct err_normal_address_t err_normal_address_t;
#endif

/* In the way err_normal_address_t is defined, you can define your own addresses. */


struct err_area_t;
#ifdef __cplusplus
typedef struct err_area_t ErrArea;
#else
typedef struct err_area_t err_area_t;
#endif

struct err_location_t;
#ifdef __cplusplus
typedef struct err_location_t ErrLocation;
#else
typedef struct err_location_t err_location_t;
#endif

/* Do not use err_position_t directly from C, only from C++ or via the
 * err_set_... functions. */
struct err_position_t {
    int  *refcount; /* Reference counter deciding when to copy/free file and address */
    char *file;
    err_ext_address_t *address;
    int line;
    int pos;
#ifdef __cplusplus
private:
    void release ();
    void import (char const *,  int, int, ErrExtAddress *);  /* always makes a full copy */
    void import (int *, char *, int, int, ErrExtAddress *);  /* shares the data */
public:
    err_position_t (char const * = NULL, int = 0, int = 0);
    err_position_t (err_address_t);
    err_position_t (err_ext_address_t const &);
    err_position_t (err_ext_address_t const *);

    void set_position (char const * = NULL, int = 0, int = 0);

    err_position_t (err_position_t const &);

    void operator= (err_position_t const &);
    void operator= (err_area_t const &);     /* for msvc 6.0 which does not find the conversion */
    void operator= (err_location_t const &); /* for msvc 6.0 which does not find the conversion */

    ~err_position_t ();

    bool valid() const { return file != NULL || address != NULL; }

    operator err_position_t const *() const { return this; }

    operator err_area_t const *() const;
    operator err_area_t () const;

    operator err_location_t const *() const;
    operator err_location_t () const;
#endif
};

struct err_area_t {
    err_position_t first;
    err_position_t last;
#ifdef __cplusplus
    err_area_t (err_position_t const &);
    err_area_t (err_address_t);
    err_area_t (err_ext_address_t const &);
    err_area_t (err_ext_address_t const *);
    err_area_t (char const * = NULL, int = 0, int = 0);
        /* An error location is actually an error area.   You can define the start here
         * and add the end using upto(). */

    err_area_t (err_position_t const &, err_position_t const &);
        /* To set both at the same time, start and end, use this. */

    err_area_t &upto (char const *a= NULL, int b= 0, int c= 0)
    {
        last= ErrPosition (a, b, c);
        return *this;
    }

    err_area_t &upto (err_address_t a)
    {
        last= ErrPosition (a);
        return *this;
    }

    err_area_t (err_area_t const &);
    void operator= (err_position_t const &); /* for msvc 6.0 which does not find the conversion */
    void operator= (err_area_t const &);
    void operator= (err_location_t const &); /* for msvc 6.0 which does not find the conversion */
    ~err_area_t ();

    operator err_position_t const *() const { return &first; }
    operator err_position_t const &() const { return first; }

    operator err_area_t const *() const     { return this;  }

    operator err_location_t const *() const;
    operator err_location_t () const;

    bool valid() const { return first.valid(); }
#endif
};

typedef void (*ErrLocationPrinter)(err_v_char_t *, err_location_t const *);
typedef ErrLocationPrinter err_location_printer_t;

struct err_location_t {
    err_area_t here;
    err_area_t orig;
        /* original position (e.g. found by #line directives)
         *
         * more complex error locations have to be modelled by several invocations
         * of eprintf(C_TAG_MORE, ...) or by the extension mechanism using next_loc
         * and print_next.  See set_next(). */

    err_location_t *next_loc;

    ErrLocationPrinter print_next;
        /* extension mechanism: if next_loc is != NULL, if is appended
         * to messages and print_next is invoked to print a text that
         * describes that other location.
         *
         * Always use set_next() to set these.
         *
         * Note that next_loc is automatically properly copied. */

#ifdef __cplusplus
    /* To set the primary position (either an address or an explicit area): */
    err_location_t (err_area_t const &);
    err_location_t (err_position_t const &);
    err_location_t (err_address_t);
    err_location_t (err_ext_address_t const &);
    err_location_t (err_ext_address_t const *);
    err_location_t (char const * = NULL, int = 0, int = 0);
        /* An error location is actually an error area.   You can define the start here
         * and add the end using upto().   Further, you can add the original position
         * by using originally(...).upto(). */

    err_location_t (err_position_t const &, err_position_t const &);
        /* To set both at the same time, start and end, use this. */

    err_location_t (err_area_t const &, err_area_t const &);
        /* To set both, the normal and the original position. */

    /* The following upto() functions change the original location if
     * that is valid, and the normal location otherwise.  Therefore, you
     * can use a sequence of member calls like the following:
     *    ErrLocation(...).upto(...).originally(...).upto(...)
     * this also works:
     *    ErrLocation(...).originally(...).upto(...).originally()
     * If that scheme is not enough for your application, you need to add
     * more calls to eprintf(C_TAG_MORE, ...).
     */
    err_area_t &free_upto()
    {
        return here.last.valid() ? orig : here;
    }

    err_position_t &free_orig()
    {
        return orig.first.valid() ? orig.last : orig.first;
    }

    err_location_t &upto (char const *a, int b= 0, int c= 0)
    {
        free_upto().last= ErrPosition (a, b, c);
        return *this;
    }

    /* Upto in the same file (pos must be given so that this constructor can be
     * distinguished from the following one*/
    err_location_t &upto (int a, int b)
    {
        free_upto().last= ErrPosition (free_upto().first.file, a, b);
        return *this;
    }

    err_location_t &upto (err_address_t a)
    {
        free_upto().last= ErrPosition (a);
        return *this;
    }

    err_location_t &originally (char const *a, int b= 0, int c= 0)
    {
        free_orig()= ErrPosition (a, b, c);
        return *this;
    }

    err_location_t &originally (int a, int b)
    {
        free_orig()= ErrPosition (orig.first.file, a, b);
        return *this;
    }

    err_location_t &originally (err_address_t a)
    {
        free_orig()= ErrPosition (a);
        return *this;
    }

    err_location_t &set_next (
        err_location_t const *,
        ErrLocationPrinter);
        /* returns the pointer to the internal copy */

    err_location_t (err_location_t const &);

    void operator= (err_position_t const &); /* for msvc 6.0 which does not find the conversion */
    void operator= (err_area_t const &);     /* for msvc 6.0 which does not find the conversion */
    void operator= (err_location_t const &);

    ~err_location_t ();

    operator err_position_t const *() const { return &here.first; }
    operator err_position_t const &() const { return here.first; }

    operator err_area_t     const *() const { return &here; }
    operator err_area_t     const &() const { return here; }

    operator err_location_t const *() const { return this; }

    bool valid() const { return here.valid(); }
#endif
};

struct err_msg_info_t;
#ifdef __cplusplus
typedef struct err_msg_info_t ErrMsgInfo;
#else
typedef struct err_msg_info_t err_msg_info_t;
#endif

struct err_msg_info_t {
    time_t issue_time;
#ifdef __cplusplus
    err_msg_info_t ():
         issue_time (time(NULL))
    {}
#endif
};

/* ********************************************************************** */

#ifdef __cplusplus
extern "C" {
#endif

/* C interface for the super class: currently only _init: */
extern void err_ext_address_init (err_ext_address_t *, err_ext_address_class_t const *);

/* virtual functions and class of the standard implementation: */
extern void err_normal_address_destruct (err_ext_address_t *);
extern err_ext_address_t *err_normal_address_clone (err_ext_address_t const *);
extern void err_normal_address_format (
    err_v_char_t *, err_ext_address_t const *, err_preposition_t);
extern void err_normal_address_format_ext (
    err_v_char_t *, err_ext_address_t const *, err_preposition_t, err_format_style_t);
extern err_address_t err_normal_address_to_linear (err_ext_address_t const *);
extern void err_normal_address_format_preposition (err_v_char_t *, err_preposition_t);

/*
 * The following return a reference to a static variable, so you
 * cannot invoke these twice in the same expression.
 *
 * When using C++, use ErrPosition(...) instead, this does
 * not have this problem.
 */
extern err_location_t *err_in_file     (char const *);
extern err_location_t *err_in_line     (char const *, int);
extern err_location_t *err_at_position (char const *, int, int);
extern err_location_t *err_at_address  (err_address_t);
extern err_location_t *err_at_ext_address  (err_ext_address_t const *);
   /* These define an error position
    * Info: this function returns a pointer to a static variable!
    */

extern err_location_t *err_location_copy (err_location_t const *) ATTR_MALLOC;
extern void            err_location_delete (err_location_t *);

extern err_location_t *err_upto_file        (err_location_t *, char const *);
extern err_location_t *err_upto_line        (err_location_t *, char const *, int);
extern err_location_t *err_upto_position    (err_location_t *, char const *, int, int);
extern err_location_t *err_upto_address     (err_location_t *, err_address_t);
extern err_location_t *err_upto_ext_address (err_location_t *, err_ext_address_t const *);
   /* These adds the end of the error area */

extern err_location_t *err_originally_in_file (err_location_t *, err_location_t *, char const *);
extern err_location_t *err_originally_in_line (err_location_t *, char const *, int);
extern err_location_t *err_originally_at_position   (err_location_t *, char const *, int, int);
extern err_location_t *err_originally_at_address    (err_location_t *, err_address_t);
extern err_location_t *err_originally_at_ext_address(err_location_t *, err_ext_address_t const *);
   /* These adds the original position of the error which can also be modified
    * by the upto functions. */

extern err_location_t *err_set_next_loc (
    err_location_t *,
    err_location_t const *,
    err_location_printer_t);

extern void err_set_in_file     (err_position_t *, char const *);
extern void err_set_in_line     (err_position_t *, char const *, int);
extern void err_set_at_position (err_position_t *, char const *, int, int);
   /* for modification of a position (e.g. during resolving of addresses) */

/* ********************************************************************** */

extern int fxprintf   (FILE *, char const *format, ...)          ATTR_FORMAT_PRINTF (2,3);
  /*
   * *xprintf family: extended printf implemented with Erwin's VectorChar::format.
   *
   * By using Erwin for printing:
   *    - %Lx is supported
   *    - %s prints NULL safely
   *    - etc.
   *
   * And they are NULL-safe: if either the file, string or the format is NULL, the
   * functions simply return 0.
   *
   */

extern int vfxprintf  (FILE *, char const *format, va_list)      ATTR_FORMAT_VPRINTF(2);
  /* Varargs version of fxprintf */

extern int foxprintf  (FILE *, int, char const *format, ...)     ATTR_FORMAT_PRINTF (3,4);
  /* Like fxprintf with Erwin format options. */

extern int vfoxprintf (FILE *, int, char const *format, va_list) ATTR_FORMAT_VPRINTF(3);
  /* Varargs version of fxprintf with Erwin format options */

#ifdef ERR_HAVE_STDERR

extern int xprintf   (char const *format, ...)          ATTR_FORMAT_PRINTF (1,2);
  /* like fxprintf with stream == stdout */

extern int vxprintf  (char const *format, va_list)      ATTR_FORMAT_VPRINTF(1);
  /* like vfxprintf with stream == stdout */

extern int oxprintf  (int, char const *format, ...)     ATTR_FORMAT_PRINTF (2,3);
  /* like foxprintf with stream == stdout */

extern int voxprintf (int, char const *format, va_list) ATTR_FORMAT_VPRINTF(2);
  /* like vfoxprintf with stream == stdout */

#endif /* defined ERR_HAVE_STDERR */

extern int snxprintf   (char *, int, char const *format, ...)          ATTR_FORMAT_PRINTF (3,4);
   /* Like snprintf, but implemented with Erwin and buffer overflow safe.
    *
    * Well, better use Erwin directly than this family of functions.  They
    * are here for convenience only.  However, they work. :-)
    *
    * Also, sprintf should never be used (-> buffer overflow), so its equivalent
    * is not implemented here.
    */

extern int vsnxprintf  (char *, int, char const *format, va_list)      ATTR_FORMAT_VPRINTF(3);
   /* Varargs version of snxprintf */

extern int snoxprintf  (char *, int, int, char const *format, ...)     ATTR_FORMAT_PRINTF (4,5);
   /* Like snxprintf with Erwin format options. */

extern int vsnoxprintf (char *, int, int, char const *format, va_list) ATTR_FORMAT_VPRINTF(4);
   /* Varargs version of snxprintf with Erwin format options. */

/*
 * Main routines for printing messages. */

#ifdef IN_LIBERROR_COMPILE
#  include "error/printf-gen.h"
#else
#  include <error/printf-gen.h>
#endif

/* err-renumber */
extern int voleprintf (
    int tag, int number, int /*options*/, err_location_t const *,
    char const *, va_list) ATTR_FORMAT_VPRINTF(5);
   /* Many variants if eprintf() and deprintf():
    *
    * The name is a concatenation of (in that very order):
    *
    *   a) The argument passing type:
    *         - "":    by ...
    *                    : eprintf  (tag, num, format, ...)
    *         - "v":   by va_list e.g.
    *                    : veprintf (tag, num, format, va)
    *
    *   b) The option argument to Erwin format:
    *         - "":    options are 0:
    *                    : eprintf (tag, num, format, ...)
    *         - "q":   options are ERR_FO_QUOTE_C_STRING:
    *                    : qeprintf  (tag, num, format, ...)
    *                    : vqeprintf (tag, num, format, va)
    *         - "o":   options are passed before the format string:
    *                    : oeprintf  (tag, num, options, format, ...)
    *                    : voeprintf (tag, num, options, format, va)
    *
    *   c) The location argument:
    *         - "":    no location:
    *                    :  eprintf (tag, num, format, ...)
    *         - "fl":  file and line are given:
    *                    :  fleprintf   (tag, num, file, line, format, ...)
    *                    :  vofleprintf (tag, num, file, line, options, format, va)
    *         - "flp": file, line and position (=column) are given:
    *                    :  flpeprintf   (tag, num, file, line, pos, format, ...)
    *                    :  voflpeprintf (tag, num, file, line, pos, options, format, va)
    *         - "p":   an err_location_t const * argument is passed.  This pointer
    *                  may always be a local reference even if the message is buffered.
    *                  The library copies the contents if needed.
    *                    :  leprintf   (tag, num, loc, format, ...)
    *                    :  voleprintf (tag, num, loc, options, format, va)
    *
    *   d) The debugging indicator:
    *         - "":    not a debugging version
    *                    :  eprintf (tag, num, format, ...)
    *         - "d":  debugging version
    *                    :  deprintf (tag, num, format, ...)
    *                 This marks the message as a developer message by
    *                 adding C_TAG_DEBUG to the tag.  Further, with
    *                 either -DNDEBUG or -DRELEASE, these functions will
    *                 not produce any message at all (it fact, the calls
    *                 will not even produce any code, so you can safely
    *                 use these without fearing that shipped code contains
    *                 debug code for generating the arguments).
    *
    * The tag is a single bit C_TAG_xyz constant (see error/tags.h).  You may
    * add a subsystem and/or group classification to it by using err_group()
    * and err_subsystem:
    *
    *   : eprintf (C_TAG_ERROR | err_subsystem("lexer"), 0, "blahblah");
    *
    * If num == 0, the number it is not printed.
    * You can use the errcodes script to insert the numbers automatically and
    * to check them into CVS.
    *
    * Note: the error message will automatically be ensured to end in
    * \n.  You, therefore, cannot issue one message using several
    * eprintf() calls.  This is vital for the internal handling of
    * error messages anyway: one call = one message.  However,
    * multi-line messages with additional lines that give additional
    * information can be implemented with the special error tag
    * C_TAG_MORE.
    *
    * Options are Erwin vector options (e.g. ERR_FO_QUOTE_C_STRING etc.)
    * (The Erwin library of this error library has the prefix err_/ERR_/Err.)
    *
    * The functions print the progname, PID, possible color tag, and a prefix
    * depending on the kind of message.
    *
    * If tag == C_TAG_MORE and num == 0, the previous number is used.  The same
    * holds for the tag in this case, which is replaced by the previous tag for
    * formatting.  However, C_TAG_MORE may have a different number to allow
    * separate filtering etc.
    *
    * The q-functions use the ERR_FO_QUOTE_C_STRING as options for printing (this is a
    * convenience abbreviation).
    *
    * The fl types print a file and a line number in front of the message.
    *
    * The flp types print a file, a line number and a line position.
    *
    * The a types print an address or, if they can look up that address, the corresponding
    * file, a line number and possibly a line position.
    *
    * Note that because of the compatibility with the fprintf family, these
    * routines return the number of characters that were printed, althought
    * this is really quite uninteresting information most of the time.
    * To be precise, the functions return the number of characters printed
    * without the automatic prefix (file, line, etc.), but the amount of
    * characters that resulted from formatting the user format string with
    * its arguments:
    *
    *   : fleprintf (C_TAG_ERROR, 0, "hello.c", 24, "abc");
    *
    * returns 3 (the length of "abc")
    *
    * The de-variants (instead of e-variants) are for development and are not
    * compiled in when NDEBUG is defined.  Messages issued using the de-family
    * never change the message counters, because counting would change in the
    * development version.  Further, bodies of messages printed with de-variants
    * are colored using the C_TAG_DEBUG color.
    *
    * Note that the de-family does not return a value.  (This is due to some
    * compilers that do not support macro varargs.)
    *
    * C_TAG_FATAL should be used with de-printf, since the call-back that
    * exits the program will not be invoked with NDEBUG.
    *
    * Note: the tag C_TAG_DEBUG is a different message classification:
    * deprintf is thought to be for all kinds of messages that are
    * interesting to the developer, but not to users.  E.g. a message
    * might indicate that some strange situation was encountered so that
    * an algorithm is not used, while in the production line of the
    * program, the algorithm is silently not used.  C_TAG_DEBUG is more meant
    * to be for larger loads of messages that issue state information
    * about the algorithm during debugging, while deprintf is for messages
    * that are issued when unexpected things happend while you think that
    * an algorithm works.
    */

#ifdef __cplusplus
}
#endif

#endif /* !defined HT_ERROR_EPRINTF_H */
