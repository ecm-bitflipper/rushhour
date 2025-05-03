/*-*- Mode: C -*-*/

#ifndef HT_ERROR_STYLE_H
#define HT_ERROR_STYLE_H

#ifdef __cplusplus
extern "C" {
#endif

/* Error styles */

/* Printing an error works in two steps:
 *    a) Formatting
 *    b) Post-formatting (modification of line breaks, etc).
 *
 * Formatting:
 *    Prints an indentation toggle, a file, a line, a program name, a PID,
 *    a tag, a number, and a formatted message text into a string.
 *
 * Post-formatting:
 *    Converts a string into a string.  Usually this operation is empty,
 *    but may be used to change line breaks, etc.
 *
 */

struct err_style_t {
     char const *name;
     void (*format) (
          err_formatted_stream_t * /*stream*/,
          err_v_char_t * /*target*/,
          int            /*tag*/,
          int            /*orig_tag*/,
          int            /*orig_num*/,
          err_msg_info_t /*info*/,
          err_location_t const * /*loc*/,
          char const *   /*progname*/,
          char const *   /*hostname*/,
          int            /*pid*/,
          char const *   /*text*/);
       /*
        * +-------------+--------------------------------------------------+
        * | stream      | stream to format for.  may be NULL if no stream  |
	    * |             | is available.   Use this only for investigating  |
	    * |             | the stream, but not to print into it!            |
        * +-------------+--------------------------------------------------+
	    * | target      | destination of printing                          |
        * +-------------+--------------------------------------------------+
	    * | tag         | the tag that resulted in this message (possibly  |
	    * |             | C_TAG_MORE)                                      |
        * +-------------+--------------------------------------------------+
	    * | orig_tag    | never == C_TAG_MORE.  If tag == C_TAG_MORE, this |
	    * |             | will be the original tag that preceeded the      |
	    * |             | C_TAG_MORE message.                              |
        * +-------------+--------------------------------------------------+
	    * | orig_num    | the original number, even if tag == C_TAG_MORE   |
        * +-------------+--------------------------------------------------+
	    * | info        | more information about the message (e.g. time)   |
        * +-------------+--------------------------------------------------+
	    * | loc         | where the error occurred                         |
        * +-------------+--------------------------------------------------+
	    * | progname    | may be NULL                                      |
        * +-------------+--------------------------------------------------+
	    * | hostname    | hostname (only valid for Unix, otherwise NULL)   |
        * +-------------+--------------------------------------------------+
	    * | pid         | only valid for Unix,                             |
	    * |             | also invalid if progname == NULL                 |
        * +-------------+--------------------------------------------------+
	    * | text        | the text to be formatted                         |
        * +-------------+--------------------------------------------------+
        */

     err_v_char_t *(*post_format) (
         err_formatted_stream_t *, int /*tag*/, int /*orig_tag*/, err_v_char_t const *);
         /* May modify a given string just be before finalisation.
          *
          * This may return NULL if the given string is not modified. */
};

/* ********************************************************************** */
/* Style that prints nothing: */

extern err_style_t const err_style_none_s;
#define err_style_none (&err_style_none_s)

extern void err_style_none_format (
    err_formatted_stream_t *,
    err_v_char_t *,
    int, int, int,
    err_msg_info_t,
    err_location_t const *,
    char const *, char const *, int,
    char const *);

extern err_v_char_t *err_style_none_post_format (
    err_formatted_stream_t *, int, int, err_v_char_t const *);

/* ********************************************************************** */
/* Style that simply prints the text: */

extern err_style_t const err_style_simple_s;
#define err_style_simple (&err_style_simple_s)

extern void err_style_simple_format (
    err_formatted_stream_t *,
    err_v_char_t *,
    int, int, int,
    err_msg_info_t,
    err_location_t const *,
    char const *, char const *, int,
    char const *);

extern err_v_char_t *err_style_simple_post_format (
    err_formatted_stream_t *, int, int, err_v_char_t const *);

/* ********************************************************************** */
/* Default style: */

#define ERR_STYLE_DEFAULT 9999
#define ERR_STYLE_NONE    0
#define ERR_STYLE_SIMPLE  10
#define ERR_STYLE_PLAIN   20
#define ERR_STYLE_COLON   21
#define ERR_STYLE_QUOTES  22
#define ERR_STYLE_QT      30
#define ERR_STYLE_QT3     40

extern int err_style_default_redirect;  /* = ERR_STYLE_PLAIN */

extern err_style_t const err_style_default_s;
#define err_style_default (&err_style_default_s)
  /* Note that for both err plain and qit style, plain style formatting
   * is used.  Only the markup is different.  Therefore, you can change
   * the style by using the err_style_plain_redirect variable. */

extern void err_style_default_format (
    err_formatted_stream_t *,
    err_v_char_t *,
    int, int, int,
    err_msg_info_t,
    err_location_t const *,
    char const *, char const *, int,
    char const *);

extern err_v_char_t *err_style_default_post_format (
    err_formatted_stream_t *, int, int, err_v_char_t const *);

/* ********************************************************************** */
/* Structures for general markup: */

#define ERR_MSG_COLOR_PREFIX    1
#define ERR_MSG_COLOR_SUFFIX    2

#define ERR_MSG_PART_MIN        8 /* smallest number of real part */
#define ERR_MSG_PART_LOC        8
#define ERR_MSG_PART_PROGNAME   9
#define ERR_MSG_PART_TAG       10
#define ERR_MSG_PART_ADDRESS   11
#define ERR_MSG_PART_BODY      12
#define ERR_MSG_PART_TIME      13
#define ERR_MSG_PART_SPACE     15
#define ERR_MSG_PART_MAX       15 /* largest number of real part */

#define ERR_MSG_COLOR_OFF      16
   /* _OFF must be a free bit to be combinable with the rest.
    * (We have 9 bits in total, so values my be 0..511.)
    */

struct err_markup_t {
     int open_part;
     int open_tag;

     char const *(*color) (
          struct err_markup_t *,
          int /*part*/,
          int /*tag*/,
          ERR_ERWIN_BOOL /*on*/);
       /* part may have values of the ERR_MSG_* enum. */

     void (*begin_part) (
          struct err_markup_t *,
          err_formatted_stream_t * /*stream*/,
          err_v_char_t * /*msg*/,
          int /*part*/,
          int /*orig_tag*/);
};

typedef struct err_markup_t ErrMarkup;
#ifndef __cplusplus
typedef struct err_markup_t err_markup_t;
#endif

extern void err_begin_part  (
   err_markup_t *, err_formatted_stream_t *, err_v_char_t *, int part, int tag);
extern void err_open_markup (err_markup_t *, err_v_char_t *, int, int);
extern void err_end_part    (err_markup_t *, err_v_char_t *);

extern err_markup_t *err_markup_none;

extern char const *err_markup_none_color (err_markup_t *, int, int, ERR_ERWIN_BOOL);

extern void err_markup_none_begin_part (
    err_markup_t *,
    err_formatted_stream_t *,
    err_v_char_t *,
    int,
    int);

/* ********************************************************************** */

extern err_style_t const *err_style_from_int (int);
   /* gets a style from a ERR_STYLE_DEFAULT constant */

extern int err_style_from_string_to_int (char const *);
extern err_style_t const * err_style_from_string (char const *);

/* extern void err_register_feature (err_init_t); */

/* ********************************************************************** */

extern int err_position_pieces (err_position_t const *);
    /* Returns the number of valid pieces of the error position.  In detail:
     *
     * returns 0 if file is == NULL
     * otherwise
     * returns 1 if line is <= 0
     * otherwise
     * returns 2 if pos is <= 0
     * otherwise
     * returns 3.
     */

extern char const *err_tag_string (int /*tag*/);
    /* Returns a string that describes a given color tag.  E.g. "Error" for
     * C_TAG_ERROR.
     * It returns NULL, if no tag is to be written */

extern char const *err_tag_description (
    ERR_BOOL * /*initial_vowel*/, int /*tag*/, ERR_BOOL /*plural*/);
    /* Returns a description of a tag, e.g. "assertion" for C_TAG_ASSERTION.
     * It can also return the plural form.
     *
     * This never returns NULL.
     */

extern err_symbol_t err_tag_abbreviation (int /*tag*/);
    /* Returns a symbol of a tag, e.g. "assertion" for C_TAG_ASSERTION.
     * In contrast to err_tag_description, these are not for humans but
     * for computers: a simple one word tag name.  No spaces, to bells or
     * whistles.
     *
     * This never returns NULL.
     */

/* The following variables controls how line breaks are automatically
 * inserted.  Styles may use them. */
#define ERR_STYLE_LINE_BREAK_NEVER           0
#define ERR_STYLE_LINE_BREAK_ALWAYS          1
#define ERR_STYLE_LINE_BREAK_TOO_LONG        2  /* >= 79 characters */
#define ERR_STYLE_LINE_BREAK_LOCATION_GIVEN  3  /* if a location is given */

/* Possibly the style supports colors: */
#define ERR_STYLE_COLOR_NEVER   0
#define ERR_STYLE_COLOR_ALWAYS  1
#define ERR_STYLE_COLOR_IF_TTY  2

/* Time style: */
#define ERR_STYLE_TIME_NEVER    0
#define ERR_STYLE_TIME_ALWAYS   1
#define ERR_STYLE_TIME_PROGRESS 2

#ifdef __cplusplus
}
#endif

#endif /* !defined HT_ERROR_STYLE_H */
