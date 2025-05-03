/* -*- Mode: C -*- */
/* _AUTO_MSG_ */

#ifndef _UPREFIX_SYMBOL_H_432347983
#define _UPREFIX_SYMBOL_H_432347983

#ifdef IN_LIB_ULPREFIX__COMPILE
#include "_EPREFIX_erwin/erwin.h"
#else
#include <_EPREFIX_erwin/erwin.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define DEF_SYMBOL(X,Y) extern _PREFIX_symbol_t X;

#ifdef IN_LIB_ULPREFIX__COMPILE
#   include "_EDPREFIX_symbol.inc"
#else
#   include <_EDPREFIX_symbol.inc>
#endif

#undef  DEF_SYMBOL

extern _PREFIX_symtab_t *_PREFIX_symtab;

extern void _PREFIX_symbol_init (int *, char ***);

#ifndef _UPREFIX_SYMBOL_DYNAMIC_TABLE
#define _UPREFIX_SYMBOL_DYNAMIC_TABLE _UPREFIX_SYMBOL_DYNAMIC_TABLE_DEFAULT
#endif

#if _UPREFIX_SYMBOL_DYNAMIC_TABLE

    extern _PREFIX_symbol_t _PREFIX_string2symbol_default(char const *);
    extern _PREFIX_symbol_t (*_PREFIX_string2symbol_func) (char const *);

#   ifndef _PREFIX_string2symbol
#   define _PREFIX_string2symbol(X) _PREFIX_string2symbol_func (X)
#   endif

    extern void _PREFIX_set_string2symbol (_PREFIX_symbol_t (*)(char const *));

#else /* !_UPREFIX_SYMBOL_DYNAMIC_TABLE */

    extern _PREFIX_symbol_t _PREFIX_string2symbol_func(char const *);
       /* you might need string2symbol as a function for synchronizing
        * another library's string2symbol */

#   ifndef _PREFIX_string2symbol
#   define _PREFIX_string2symbol(X) _PREFIX_symtab_ensure (_PREFIX_symtab, (X))
#   endif

#endif /* !_UPREFIX_SYMBOL_DYNAMIC_TABLE */

#ifdef __cplusplus
}
#endif

#endif /* _UPREFIX_SYMBOL_H_432347983 */

