/* -*- Mode: C -*- */
/* Automatically generated, do not edit. */

#ifndef SYMBOL_H_432347983
#define SYMBOL_H_432347983

#ifdef IN_LIBRUSH_HOUR_COMPILE
#include "erwin/erwin.h"
#else
#include <erwin/erwin.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define DEF_SYMBOL(X,Y) extern symbol_t X;

#ifdef IN_LIBRUSH_HOUR_COMPILE
#   include "symbol.inc"
#else
#   include <symbol.inc>
#endif

#undef  DEF_SYMBOL

extern symtab_t *symtab;

extern void symbol_init (int *, char ***);

#ifndef SYMBOL_DYNAMIC_TABLE
#define SYMBOL_DYNAMIC_TABLE 0
#endif

#if SYMBOL_DYNAMIC_TABLE

    extern symbol_t string2symbol_default(char const *);
    extern symbol_t (*string2symbol_func) (char const *);

#   ifndef string2symbol
#   define string2symbol(X) string2symbol_func (X)
#   endif

    extern void set_string2symbol (symbol_t (*)(char const *));

#else /* !SYMBOL_DYNAMIC_TABLE */

    extern symbol_t string2symbol_func(char const *);
       /* you might need string2symbol as a function for synchronizing
        * another library's string2symbol */

#   ifndef string2symbol
#   define string2symbol(X) symtab_ensure (symtab, (X))
#   endif

#endif /* !SYMBOL_DYNAMIC_TABLE */

#ifdef __cplusplus
}
#endif

#endif /* SYMBOL_H_432347983 */

