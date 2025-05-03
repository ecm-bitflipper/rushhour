/* -*- Mode: C++ -*- */
/* err-default scope=project */

/* err-renumber */
extern int
eprintf (int tag, int number, char const *, ...) ATTR_FORMAT_PRINTF(3,4);
/* See voleprintf for more documentation. */

/* err-renumber */
extern int
fleprintf (int tag, int number, char const * /*file*/, int /*line*/, char const *, ...) ATTR_FORMAT_PRINTF(5,6);
/* See voleprintf for more documentation. */

/* err-renumber */
extern int
flpeprintf (int tag, int number, char const * /*file*/, int /*line*/, int /*pos*/, char const *, ...) ATTR_FORMAT_PRINTF(6,7);
/* See voleprintf for more documentation. */

/* err-renumber */
extern int
leprintf (int tag, int number, err_location_t const *, char const *, ...) ATTR_FORMAT_PRINTF(4,5);
/* See voleprintf for more documentation. */

/* err-renumber */
extern int
oeprintf (int tag, int number, int /*options*/, char const *, ...) ATTR_FORMAT_PRINTF(4,5);
/* See voleprintf for more documentation. */

/* err-renumber */
extern int
ofleprintf (int tag, int number, int /*options*/, char const * /*file*/, int /*line*/, char const *, ...) ATTR_FORMAT_PRINTF(6,7);
/* See voleprintf for more documentation. */

/* err-renumber */
extern int
oflpeprintf (int tag, int number, int /*options*/, char const * /*file*/, int /*line*/, int /*pos*/, char const *, ...) ATTR_FORMAT_PRINTF(7,8);
/* See voleprintf for more documentation. */

/* err-renumber */
extern int
oleprintf (int tag, int number, int /*options*/, err_location_t const *, char const *, ...) ATTR_FORMAT_PRINTF(5,6);
/* See voleprintf for more documentation. */

/* err-renumber */
extern int
qeprintf (int tag, int number, char const *, ...) ATTR_FORMAT_PRINTF(3,4);
/* See voleprintf for more documentation. */

/* err-renumber */
extern int
qfleprintf (int tag, int number, char const * /*file*/, int /*line*/, char const *, ...) ATTR_FORMAT_PRINTF(5,6);
/* See voleprintf for more documentation. */

/* err-renumber */
extern int
qflpeprintf (int tag, int number, char const * /*file*/, int /*line*/, int /*pos*/, char const *, ...) ATTR_FORMAT_PRINTF(6,7);
/* See voleprintf for more documentation. */

/* err-renumber */
extern int
qleprintf (int tag, int number, err_location_t const *, char const *, ...) ATTR_FORMAT_PRINTF(4,5);
/* See voleprintf for more documentation. */

/* err-renumber */
extern int
veprintf (int tag, int number, char const *, va_list) ATTR_FORMAT_VPRINTF(3);
/* See voleprintf for more documentation. */

/* err-renumber */
extern int
vfleprintf (int tag, int number, char const * /*file*/, int /*line*/, char const *, va_list) ATTR_FORMAT_VPRINTF(5);
/* See voleprintf for more documentation. */

/* err-renumber */
extern int
vflpeprintf (int tag, int number, char const * /*file*/, int /*line*/, int /*pos*/, char const *, va_list) ATTR_FORMAT_VPRINTF(6);
/* See voleprintf for more documentation. */

/* err-renumber */
extern int
vleprintf (int tag, int number, err_location_t const *, char const *, va_list) ATTR_FORMAT_VPRINTF(4);
/* See voleprintf for more documentation. */

/* err-renumber */
extern int
voeprintf (int tag, int number, int /*options*/, char const *, va_list) ATTR_FORMAT_VPRINTF(4);
/* See voleprintf for more documentation. */

/* err-renumber */
extern int
vofleprintf (int tag, int number, int /*options*/, char const * /*file*/, int /*line*/, char const *, va_list) ATTR_FORMAT_VPRINTF(6);
/* See voleprintf for more documentation. */

/* err-renumber */
extern int
voflpeprintf (int tag, int number, int /*options*/, char const * /*file*/, int /*line*/, int /*pos*/, char const *, va_list) ATTR_FORMAT_VPRINTF(7);
/* See voleprintf for more documentation. */

/* voleprintf() is the generic function. */

/* err-renumber */
extern int
vqeprintf (int tag, int number, char const *, va_list) ATTR_FORMAT_VPRINTF(3);
/* See voleprintf for more documentation. */

/* err-renumber */
extern int
vqfleprintf (int tag, int number, char const * /*file*/, int /*line*/, char const *, va_list) ATTR_FORMAT_VPRINTF(5);
/* See voleprintf for more documentation. */

/* err-renumber */
extern int
vqflpeprintf (int tag, int number, char const * /*file*/, int /*line*/, int /*pos*/, char const *, va_list) ATTR_FORMAT_VPRINTF(6);
/* See voleprintf for more documentation. */

/* err-renumber */
extern int
vqleprintf (int tag, int number, err_location_t const *, char const *, va_list) ATTR_FORMAT_VPRINTF(4);
/* See voleprintf for more documentation. */



/* err-renumber */
extern void
eprintf_devel (int tag, int number, char const *, ...) ATTR_FORMAT_PRINTF(3,4);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
fleprintf_devel (int tag, int number, char const * /*file*/, int /*line*/, char const *, ...) ATTR_FORMAT_PRINTF(5,6);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
flpeprintf_devel (int tag, int number, char const * /*file*/, int /*line*/, int /*pos*/, char const *, ...) ATTR_FORMAT_PRINTF(6,7);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
leprintf_devel (int tag, int number, err_location_t const *, char const *, ...) ATTR_FORMAT_PRINTF(4,5);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
oeprintf_devel (int tag, int number, int /*options*/, char const *, ...) ATTR_FORMAT_PRINTF(4,5);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
ofleprintf_devel (int tag, int number, int /*options*/, char const * /*file*/, int /*line*/, char const *, ...) ATTR_FORMAT_PRINTF(6,7);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
oflpeprintf_devel (int tag, int number, int /*options*/, char const * /*file*/, int /*line*/, int /*pos*/, char const *, ...) ATTR_FORMAT_PRINTF(7,8);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
oleprintf_devel (int tag, int number, int /*options*/, err_location_t const *, char const *, ...) ATTR_FORMAT_PRINTF(5,6);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
qeprintf_devel (int tag, int number, char const *, ...) ATTR_FORMAT_PRINTF(3,4);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
qfleprintf_devel (int tag, int number, char const * /*file*/, int /*line*/, char const *, ...) ATTR_FORMAT_PRINTF(5,6);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
qflpeprintf_devel (int tag, int number, char const * /*file*/, int /*line*/, int /*pos*/, char const *, ...) ATTR_FORMAT_PRINTF(6,7);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
qleprintf_devel (int tag, int number, err_location_t const *, char const *, ...) ATTR_FORMAT_PRINTF(4,5);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
veprintf_devel (int tag, int number, char const *, va_list) ATTR_FORMAT_VPRINTF(3);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
vfleprintf_devel (int tag, int number, char const * /*file*/, int /*line*/, char const *, va_list) ATTR_FORMAT_VPRINTF(5);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
vflpeprintf_devel (int tag, int number, char const * /*file*/, int /*line*/, int /*pos*/, char const *, va_list) ATTR_FORMAT_VPRINTF(6);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
vleprintf_devel (int tag, int number, err_location_t const *, char const *, va_list) ATTR_FORMAT_VPRINTF(4);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
voeprintf_devel (int tag, int number, int /*options*/, char const *, va_list) ATTR_FORMAT_VPRINTF(4);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
vofleprintf_devel (int tag, int number, int /*options*/, char const * /*file*/, int /*line*/, char const *, va_list) ATTR_FORMAT_VPRINTF(6);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
voflpeprintf_devel (int tag, int number, int /*options*/, char const * /*file*/, int /*line*/, int /*pos*/, char const *, va_list) ATTR_FORMAT_VPRINTF(7);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
voleprintf_devel (int tag, int number, int /*options*/, err_location_t const *, char const *, va_list) ATTR_FORMAT_VPRINTF(5);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
vqeprintf_devel (int tag, int number, char const *, va_list) ATTR_FORMAT_VPRINTF(3);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
vqfleprintf_devel (int tag, int number, char const * /*file*/, int /*line*/, char const *, va_list) ATTR_FORMAT_VPRINTF(5);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
vqflpeprintf_devel (int tag, int number, char const * /*file*/, int /*line*/, int /*pos*/, char const *, va_list) ATTR_FORMAT_VPRINTF(6);
/* See voleprintf for more documentation. */

/* err-renumber */
extern void
vqleprintf_devel (int tag, int number, err_location_t const *, char const *, va_list) ATTR_FORMAT_VPRINTF(4);
/* See voleprintf for more documentation. */


#if defined(NDEBUG) || defined(RELEASE)
#ifdef __GNUC__

/* err-skip */
#define deprintf(X...)       ((void)0)

/* err-skip */
#define fldeprintf(X...)     ((void)0)

/* err-skip */
#define flpdeprintf(X...)    ((void)0)

/* err-skip */
#define ldeprintf(X...)      ((void)0)

/* err-skip */
#define odeprintf(X...)      ((void)0)

/* err-skip */
#define ofldeprintf(X...)    ((void)0)

/* err-skip */
#define oflpdeprintf(X...)   ((void)0)

/* err-skip */
#define oldeprintf(X...)     ((void)0)

/* err-skip */
#define qdeprintf(X...)      ((void)0)

/* err-skip */
#define qfldeprintf(X...)    ((void)0)

/* err-skip */
#define qflpdeprintf(X...)   ((void)0)

/* err-skip */
#define qldeprintf(X...)     ((void)0)

/* err-skip */
#define vdeprintf(X...)      ((void)0)

/* err-skip */
#define vfldeprintf(X...)    ((void)0)

/* err-skip */
#define vflpdeprintf(X...)   ((void)0)

/* err-skip */
#define vldeprintf(X...)     ((void)0)

/* err-skip */
#define vodeprintf(X...)     ((void)0)

/* err-skip */
#define vofldeprintf(X...)   ((void)0)

/* err-skip */
#define voflpdeprintf(X...)  ((void)0)

/* err-skip */
#define voldeprintf(X...)    ((void)0)

/* err-skip */
#define vqdeprintf(X...)     ((void)0)

/* err-skip */
#define vqfldeprintf(X...)   ((void)0)

/* err-skip */
#define vqflpdeprintf(X...)  ((void)0)

/* err-skip */
#define vqldeprintf(X...)    ((void)0)


#else

/* err-skip */
#define deprintf             while (0) /*err-skip*/ eprintf_devel

/* err-skip */
#define fldeprintf           while (0) /*err-skip*/ fleprintf_devel

/* err-skip */
#define flpdeprintf          while (0) /*err-skip*/ flpeprintf_devel

/* err-skip */
#define ldeprintf            while (0) /*err-skip*/ leprintf_devel

/* err-skip */
#define odeprintf            while (0) /*err-skip*/ oeprintf_devel

/* err-skip */
#define ofldeprintf          while (0) /*err-skip*/ ofleprintf_devel

/* err-skip */
#define oflpdeprintf         while (0) /*err-skip*/ oflpeprintf_devel

/* err-skip */
#define oldeprintf           while (0) /*err-skip*/ oleprintf_devel

/* err-skip */
#define qdeprintf            while (0) /*err-skip*/ qeprintf_devel

/* err-skip */
#define qfldeprintf          while (0) /*err-skip*/ qfleprintf_devel

/* err-skip */
#define qflpdeprintf         while (0) /*err-skip*/ qflpeprintf_devel

/* err-skip */
#define qldeprintf           while (0) /*err-skip*/ qleprintf_devel

/* err-skip */
#define vdeprintf            while (0) /*err-skip*/ veprintf_devel

/* err-skip */
#define vfldeprintf          while (0) /*err-skip*/ vfleprintf_devel

/* err-skip */
#define vflpdeprintf         while (0) /*err-skip*/ vflpeprintf_devel

/* err-skip */
#define vldeprintf           while (0) /*err-skip*/ vleprintf_devel

/* err-skip */
#define vodeprintf           while (0) /*err-skip*/ voeprintf_devel

/* err-skip */
#define vofldeprintf         while (0) /*err-skip*/ vofleprintf_devel

/* err-skip */
#define voflpdeprintf        while (0) /*err-skip*/ voflpeprintf_devel

/* err-skip */
#define voldeprintf          while (0) /*err-skip*/ voleprintf_devel

/* err-skip */
#define vqdeprintf           while (0) /*err-skip*/ vqeprintf_devel

/* err-skip */
#define vqfldeprintf         while (0) /*err-skip*/ vqfleprintf_devel

/* err-skip */
#define vqflpdeprintf        while (0) /*err-skip*/ vqflpeprintf_devel

/* err-skip */
#define vqldeprintf          while (0) /*err-skip*/ vqleprintf_devel


#endif
#else

/* err-renumber name=deprintf             =eprintf */
/* err-skip */
#define deprintf             /*err-skip*/ eprintf_devel

/* err-renumber name=fldeprintf           =fleprintf */
/* err-skip */
#define fldeprintf           /*err-skip*/ fleprintf_devel

/* err-renumber name=flpdeprintf          =flpeprintf */
/* err-skip */
#define flpdeprintf          /*err-skip*/ flpeprintf_devel

/* err-renumber name=ldeprintf            =leprintf */
/* err-skip */
#define ldeprintf            /*err-skip*/ leprintf_devel

/* err-renumber name=odeprintf            =oeprintf */
/* err-skip */
#define odeprintf            /*err-skip*/ oeprintf_devel

/* err-renumber name=ofldeprintf          =ofleprintf */
/* err-skip */
#define ofldeprintf          /*err-skip*/ ofleprintf_devel

/* err-renumber name=oflpdeprintf         =oflpeprintf */
/* err-skip */
#define oflpdeprintf         /*err-skip*/ oflpeprintf_devel

/* err-renumber name=oldeprintf           =oleprintf */
/* err-skip */
#define oldeprintf           /*err-skip*/ oleprintf_devel

/* err-renumber name=qdeprintf            =qeprintf */
/* err-skip */
#define qdeprintf            /*err-skip*/ qeprintf_devel

/* err-renumber name=qfldeprintf          =qfleprintf */
/* err-skip */
#define qfldeprintf          /*err-skip*/ qfleprintf_devel

/* err-renumber name=qflpdeprintf         =qflpeprintf */
/* err-skip */
#define qflpdeprintf         /*err-skip*/ qflpeprintf_devel

/* err-renumber name=qldeprintf           =qleprintf */
/* err-skip */
#define qldeprintf           /*err-skip*/ qleprintf_devel

/* err-renumber name=vdeprintf            =veprintf */
/* err-skip */
#define vdeprintf            /*err-skip*/ veprintf_devel

/* err-renumber name=vfldeprintf          =vfleprintf */
/* err-skip */
#define vfldeprintf          /*err-skip*/ vfleprintf_devel

/* err-renumber name=vflpdeprintf         =vflpeprintf */
/* err-skip */
#define vflpdeprintf         /*err-skip*/ vflpeprintf_devel

/* err-renumber name=vldeprintf           =vleprintf */
/* err-skip */
#define vldeprintf           /*err-skip*/ vleprintf_devel

/* err-renumber name=vodeprintf           =voeprintf */
/* err-skip */
#define vodeprintf           /*err-skip*/ voeprintf_devel

/* err-renumber name=vofldeprintf         =vofleprintf */
/* err-skip */
#define vofldeprintf         /*err-skip*/ vofleprintf_devel

/* err-renumber name=voflpdeprintf        =voflpeprintf */
/* err-skip */
#define voflpdeprintf        /*err-skip*/ voflpeprintf_devel

/* err-renumber name=voldeprintf          =voleprintf */
/* err-skip */
#define voldeprintf          /*err-skip*/ voleprintf_devel

/* err-renumber name=vqdeprintf           =vqeprintf */
/* err-skip */
#define vqdeprintf           /*err-skip*/ vqeprintf_devel

/* err-renumber name=vqfldeprintf         =vqfleprintf */
/* err-skip */
#define vqfldeprintf         /*err-skip*/ vqfleprintf_devel

/* err-renumber name=vqflpdeprintf        =vqflpeprintf */
/* err-skip */
#define vqflpdeprintf        /*err-skip*/ vqflpeprintf_devel

/* err-renumber name=vqldeprintf          =vqleprintf */
/* err-skip */
#define vqldeprintf          /*err-skip*/ vqleprintf_devel


#endif
