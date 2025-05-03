/* -*- Mode: C++ -*- */

#include "liberror.h"


int /*err-skip*/
eprintf (int tag, int number, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    int result= /*err-skip*/ voleprintf (tag, number, 0, NULL, format, va);
    va_end (va);
    return result;
}

int /*err-skip*/
fleprintf (int tag, int number, char const * file, int line, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    int result= /*err-skip*/ voleprintf (tag, number, 0, ErrLocation (file,line,0), format, va);
    va_end (va);
    return result;
}

int /*err-skip*/
flpeprintf (int tag, int number, char const * file, int line, int pos, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    int result= /*err-skip*/ voleprintf (tag, number, 0, ErrLocation (file,line,pos), format, va);
    va_end (va);
    return result;
}

int /*err-skip*/
leprintf (int tag, int number, err_location_t const * loc, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    int result= /*err-skip*/ voleprintf (tag, number, 0, loc, format, va);
    va_end (va);
    return result;
}

int /*err-skip*/
oeprintf (int tag, int number, int options, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    int result= /*err-skip*/ voleprintf (tag, number, options, NULL, format, va);
    va_end (va);
    return result;
}

int /*err-skip*/
ofleprintf (int tag, int number, int options, char const * file, int line, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    int result= /*err-skip*/ voleprintf (tag, number, options, ErrLocation (file,line,0), format, va);
    va_end (va);
    return result;
}

int /*err-skip*/
oflpeprintf (int tag, int number, int options, char const * file, int line, int pos, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    int result= /*err-skip*/ voleprintf (tag, number, options, ErrLocation (file,line,pos), format, va);
    va_end (va);
    return result;
}

int /*err-skip*/
oleprintf (int tag, int number, int options, err_location_t const * loc, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    int result= /*err-skip*/ voleprintf (tag, number, options, loc, format, va);
    va_end (va);
    return result;
}

int /*err-skip*/
qeprintf (int tag, int number, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    int result= /*err-skip*/ voleprintf (tag, number, ERR_FO_QUOTE_C_STRING, NULL, format, va);
    va_end (va);
    return result;
}

int /*err-skip*/
qfleprintf (int tag, int number, char const * file, int line, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    int result= /*err-skip*/ voleprintf (tag, number, ERR_FO_QUOTE_C_STRING, ErrLocation (file,line,0), format, va);
    va_end (va);
    return result;
}

int /*err-skip*/
qflpeprintf (int tag, int number, char const * file, int line, int pos, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    int result= /*err-skip*/ voleprintf (tag, number, ERR_FO_QUOTE_C_STRING, ErrLocation (file,line,pos), format, va);
    va_end (va);
    return result;
}

int /*err-skip*/
qleprintf (int tag, int number, err_location_t const * loc, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    int result= /*err-skip*/ voleprintf (tag, number, ERR_FO_QUOTE_C_STRING, loc, format, va);
    va_end (va);
    return result;
}

int /*err-skip*/
veprintf (int tag, int number, char const * format, va_list v0)
{
    int result= /*err-skip*/ voleprintf (tag, number, 0, NULL, format, v0);
    return result;
}

int /*err-skip*/
vfleprintf (int tag, int number, char const * file, int line, char const * format, va_list v0)
{
    int result= /*err-skip*/ voleprintf (tag, number, 0, ErrLocation (file,line,0), format, v0);
    return result;
}

int /*err-skip*/
vflpeprintf (int tag, int number, char const * file, int line, int pos, char const * format, va_list v0)
{
    int result= /*err-skip*/ voleprintf (tag, number, 0, ErrLocation (file,line,pos), format, v0);
    return result;
}

int /*err-skip*/
vleprintf (int tag, int number, err_location_t const * loc, char const * format, va_list v0)
{
    int result= /*err-skip*/ voleprintf (tag, number, 0, loc, format, v0);
    return result;
}

int /*err-skip*/
voeprintf (int tag, int number, int options, char const * format, va_list v0)
{
    int result= /*err-skip*/ voleprintf (tag, number, options, NULL, format, v0);
    return result;
}

int /*err-skip*/
vofleprintf (int tag, int number, int options, char const * file, int line, char const * format, va_list v0)
{
    int result= /*err-skip*/ voleprintf (tag, number, options, ErrLocation (file,line,0), format, v0);
    return result;
}

int /*err-skip*/
voflpeprintf (int tag, int number, int options, char const * file, int line, int pos, char const * format, va_list v0)
{
    int result= /*err-skip*/ voleprintf (tag, number, options, ErrLocation (file,line,pos), format, v0);
    return result;
}

/* voleprintf() is the generic function. */

int /*err-skip*/
vqeprintf (int tag, int number, char const * format, va_list v0)
{
    int result= /*err-skip*/ voleprintf (tag, number, ERR_FO_QUOTE_C_STRING, NULL, format, v0);
    return result;
}

int /*err-skip*/
vqfleprintf (int tag, int number, char const * file, int line, char const * format, va_list v0)
{
    int result= /*err-skip*/ voleprintf (tag, number, ERR_FO_QUOTE_C_STRING, ErrLocation (file,line,0), format, v0);
    return result;
}

int /*err-skip*/
vqflpeprintf (int tag, int number, char const * file, int line, int pos, char const * format, va_list v0)
{
    int result= /*err-skip*/ voleprintf (tag, number, ERR_FO_QUOTE_C_STRING, ErrLocation (file,line,pos), format, v0);
    return result;
}

int /*err-skip*/
vqleprintf (int tag, int number, err_location_t const * loc, char const * format, va_list v0)
{
    int result= /*err-skip*/ voleprintf (tag, number, ERR_FO_QUOTE_C_STRING, loc, format, v0);
    return result;
}



void /*err-skip*/
eprintf_devel (int tag, int number, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, 0, NULL, format, va);
    va_end (va);
}

void /*err-skip*/
fleprintf_devel (int tag, int number, char const * file, int line, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, 0, ErrLocation (file,line,0), format, va);
    va_end (va);
}

void /*err-skip*/
flpeprintf_devel (int tag, int number, char const * file, int line, int pos, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, 0, ErrLocation (file,line,pos), format, va);
    va_end (va);
}

void /*err-skip*/
leprintf_devel (int tag, int number, err_location_t const * loc, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, 0, loc, format, va);
    va_end (va);
}

void /*err-skip*/
oeprintf_devel (int tag, int number, int options, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, options, NULL, format, va);
    va_end (va);
}

void /*err-skip*/
ofleprintf_devel (int tag, int number, int options, char const * file, int line, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, options, ErrLocation (file,line,0), format, va);
    va_end (va);
}

void /*err-skip*/
oflpeprintf_devel (int tag, int number, int options, char const * file, int line, int pos, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, options, ErrLocation (file,line,pos), format, va);
    va_end (va);
}

void /*err-skip*/
oleprintf_devel (int tag, int number, int options, err_location_t const * loc, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, options, loc, format, va);
    va_end (va);
}

void /*err-skip*/
qeprintf_devel (int tag, int number, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, ERR_FO_QUOTE_C_STRING, NULL, format, va);
    va_end (va);
}

void /*err-skip*/
qfleprintf_devel (int tag, int number, char const * file, int line, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, ERR_FO_QUOTE_C_STRING, ErrLocation (file,line,0), format, va);
    va_end (va);
}

void /*err-skip*/
qflpeprintf_devel (int tag, int number, char const * file, int line, int pos, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, ERR_FO_QUOTE_C_STRING, ErrLocation (file,line,pos), format, va);
    va_end (va);
}

void /*err-skip*/
qleprintf_devel (int tag, int number, err_location_t const * loc, char const * format, ... )
{
    va_list va;
    va_start (va, format);
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, ERR_FO_QUOTE_C_STRING, loc, format, va);
    va_end (va);
}

void /*err-skip*/
veprintf_devel (int tag, int number, char const * format, va_list v0)
{
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, 0, NULL, format, v0);
}

void /*err-skip*/
vfleprintf_devel (int tag, int number, char const * file, int line, char const * format, va_list v0)
{
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, 0, ErrLocation (file,line,0), format, v0);
}

void /*err-skip*/
vflpeprintf_devel (int tag, int number, char const * file, int line, int pos, char const * format, va_list v0)
{
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, 0, ErrLocation (file,line,pos), format, v0);
}

void /*err-skip*/
vleprintf_devel (int tag, int number, err_location_t const * loc, char const * format, va_list v0)
{
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, 0, loc, format, v0);
}

void /*err-skip*/
voeprintf_devel (int tag, int number, int options, char const * format, va_list v0)
{
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, options, NULL, format, v0);
}

void /*err-skip*/
vofleprintf_devel (int tag, int number, int options, char const * file, int line, char const * format, va_list v0)
{
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, options, ErrLocation (file,line,0), format, v0);
}

void /*err-skip*/
voflpeprintf_devel (int tag, int number, int options, char const * file, int line, int pos, char const * format, va_list v0)
{
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, options, ErrLocation (file,line,pos), format, v0);
}

void /*err-skip*/
voleprintf_devel (int tag, int number, int options, err_location_t const * loc, char const * format, va_list v0)
{
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, options, loc, format, v0);
}

void /*err-skip*/
vqeprintf_devel (int tag, int number, char const * format, va_list v0)
{
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, ERR_FO_QUOTE_C_STRING, NULL, format, v0);
}

void /*err-skip*/
vqfleprintf_devel (int tag, int number, char const * file, int line, char const * format, va_list v0)
{
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, ERR_FO_QUOTE_C_STRING, ErrLocation (file,line,0), format, v0);
}

void /*err-skip*/
vqflpeprintf_devel (int tag, int number, char const * file, int line, int pos, char const * format, va_list v0)
{
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, ERR_FO_QUOTE_C_STRING, ErrLocation (file,line,pos), format, v0);
}

void /*err-skip*/
vqleprintf_devel (int tag, int number, err_location_t const * loc, char const * format, va_list v0)
{
    /*err-skip*/ voleprintf (tag | C_TAG_DEBUG, number, ERR_FO_QUOTE_C_STRING, loc, format, v0);
}


