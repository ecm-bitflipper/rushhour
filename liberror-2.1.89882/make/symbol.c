/* -*- Mode: C -*- */
/* _AUTO_MSG_ */
/* --extra-options-gcc: -Wno-unused */

#include <assert.h>

#include "_EDPREFIX_symbol.h"

#define DEF_SYMBOL(X,Y) _PREFIX_symbol_t X= NULL;
#include "_EDPREFIX_symbol.inc"
#undef  DEF_SYMBOL

_PREFIX_symtab_t *_PREFIX_symtab= NULL;

void _PREFIX_symbol_init (int *argc_p, char ***argv_p)
{
    _PREFIX_symtab= _PREFIX_symtab_new();

#define DEF_SYMBOL(X,Y) X= _PREFIX_string2symbol (Y);
#include "_EDPREFIX_symbol.inc"
#undef DEF_SYMBOL
}

#if _UPREFIX_SYMBOL_DYNAMIC_TABLE

_PREFIX_symbol_t _PREFIX_string2symbol_default (char const *x)
{
    return _PREFIX_symtab_ensure (_PREFIX_symtab, x);
}

_PREFIX_symbol_t (*_PREFIX_string2symbol_func) (char const *) = _PREFIX_string2symbol_default;

void _PREFIX_set_string2symbol (_PREFIX_symbol_t (*x)(char const *))
{
    assert ((_PREFIX_symtab == NULL) &&
            "_PREFIX_set_string2symbol must be invoked before _PREFIX_symbol_init");
    _PREFIX_string2symbol_func= x;
}

#else

_PREFIX_symbol_t _PREFIX_string2symbol_func (char const *x)
{
    return _PREFIX_symtab_ensure (_PREFIX_symtab, x);
}

#endif
