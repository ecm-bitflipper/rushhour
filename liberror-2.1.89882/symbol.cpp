/* -*- Mode: C -*- */
/* Automatically generated, do not edit. */
/* --extra-options-gcc: -Wno-unused */

#include <assert.h>

#include "error/symbol.h"

#define DEF_SYMBOL(X,Y) err_symbol_t X= NULL;
#include "error/symbol.inc"
#undef  DEF_SYMBOL

err_symtab_t *err_symtab= NULL;

void err_symbol_init (int *argc_p, char ***argv_p)
{
    err_symtab= err_symtab_new();

#define DEF_SYMBOL(X,Y) X= err_string2symbol (Y);
#include "error/symbol.inc"
#undef DEF_SYMBOL
}

#if ERR_SYMBOL_DYNAMIC_TABLE

err_symbol_t err_string2symbol_default (char const *x)
{
    return err_symtab_ensure (err_symtab, x);
}

err_symbol_t (*err_string2symbol_func) (char const *) = err_string2symbol_default;

void err_set_string2symbol (err_symbol_t (*x)(char const *))
{
    assert ((err_symtab == NULL) &&
            "err_set_string2symbol must be invoked before err_symbol_init");
    err_string2symbol_func= x;
}

#else

err_symbol_t err_string2symbol_func (char const *x)
{
    return err_symtab_ensure (err_symtab, x);
}

#endif
