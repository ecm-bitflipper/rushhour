/* -*- Mode: C -*- */
/* For OpenWatcom 1.0 */

#define STDC_HEADERS 1

/* 32bit environment */
#define SIZEOF_SHORT       2
#define SIZEOF_INT         4
#define SIZEOF_LONG        4
#define SIZEOF_SIZE_T      4
#define SIZEOF_VOIDP       4
#define SIZEOF_FLOAT       4
#define SIZEOF_DOUBLE      8

#define SIZEOF_LONG_LONG   8
#define ERWIN_LONG_LONG    long long

#define ERWIN_LL_AUX2(X)   X ## i64
#define ERWIN_LL_AUX(X)    ERWIN_LL_AUX2(X)
#define ERWIN_LL(X)        ERWIN_LL_AUX(X)

#define ERWIN_ULL_AUX2(X)  X ## ui64
#define ERWIN_ULL_AUX(X)   ERWIN_ULL_AUX2(X)
#define ERWIN_ULL(X)       ERWIN_ULL_AUX(X)

#define ERWIN_LONG_LONG_V2 1

#define SIZEOF_LONG_DOUBLE 8

#define SIZEOF_WCHAR_T	   2
#define SIZEOF_WINT_T      0
#define SIZEOF_PTRDIFF_T   0

#define SIZEOF_INTMAX_T    0
#define SIZEOF_UINTMAX_T   0

#define SIZEOF_INTPTR_T    0
#define SIZEOF_UINTPTR_T   0

#define HAVE_TIME_H        1
#define HAVE_STDIO_H       1
#define HAVE_STDLIB_H      1
#define HAVE_STDARG_H      1
#define HAVE_LIMITS_H      1
#define HAVE_CTYPE_H       1
#define HAVE_MATH_H        1
#define HAVE_STRING_H      1
#define HAVE_SETJMP_H      1
#define HAVE_SIGNAL_H      1
#define HAVE_STDDEF_H      1
#define HAVE_DIRECT_H      1
#define RETSIGTYPE         void
#define HAVE_IO_H          1

#define HAVE_ISALPHA       1
#define HAVE_ISSPACE       1
#define HAVE_ISDIGIT       1
#define HAVE_ISXDIGIT      1
#define HAVE_TOLOWER       1
#define HAVE_TOUPPER       1
#define HAVE_STRTOUL       1
#define HAVE_RAND          1
#define HAVE_SRAND         1
#define HAVE_TIME          1
#define HAVE_SQRT          1
#define HAVE_FLOOR         1

#define HAVE_LIBM          1

/* Maybe you have more complex methods of getting the place to store
 * configuration info under Win */
#define ERWIN_PATH_SEP           '\\'
#define ERWIN_PATH_SEP_STR       "\\"
#define ERWIN_DIR_LIST_SEP       ';'
#define ERWIN_DIR_LIST_SEP_STR   ";"
#define ERWIN_GLOBAL_CONF_DIR    "C:\\ETC"
#define ERWIN_GLOBAL_CONF_EXT    ".INI"
#define ERWIN_LOCAL_CONF_PREFIX  ""
#define ERWIN_LOCAL_CONF_EXT     ".INI"

#define CONFIG_WITH_LONG_LONG 1
