/* -*- Mode: C -*- */
/* Automatically generated, do not edit. */

#ifndef ERR_SYMBOL_H_432347983
#define ERR_SYMBOL_H_432347983

#ifdef IN_LIBERROR_COMPILE
#include "error/erwin/erwin.h"
#else
#include <error/erwin/erwin.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define DEF_SYMBOL(X,Y) extern err_symbol_t X;

#ifdef IN_LIBERROR_COMPILE
#   include "error/symbol.inc"
#else
#   include <error/symbol.inc>
#endif

#undef  DEF_SYMBOL

extern err_symtab_t *err_symtab;

extern void err_symbol_init (int *, char ***);

#ifndef ERR_SYMBOL_DYNAMIC_TABLE
#define ERR_SYMBOL_DYNAMIC_TABLE 1
#endif

#if ERR_SYMBOL_DYNAMIC_TABLE

    extern err_symbol_t err_string2symbol_default(char const *);
    extern err_symbol_t (*err_string2symbol_func) (char const *);

#   ifndef err_string2symbol
#   define err_string2symbol(X) err_string2symbol_func (X)
#   endif

    extern void err_set_string2symbol (err_symbol_t (*)(char const *));

#else /* !ERR_SYMBOL_DYNAMIC_TABLE */

    extern err_symbol_t err_string2symbol_func(char const *);
       /* you might need string2symbol as a function for synchronizing
        * another library's string2symbol */

#   ifndef err_string2symbol
#   define err_string2symbol(X) err_symtab_ensure (err_symtab, (X))
#   endif

#endif /* !ERR_SYMBOL_DYNAMIC_TABLE */

#ifdef __cplusplus
}
#endif

#endif /* ERR_SYMBOL_H_432347983 */

