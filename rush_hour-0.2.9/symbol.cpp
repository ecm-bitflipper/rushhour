/* -*- Mode: C -*- */
/* Automatically generated, do not edit. */
/* --extra-options-gcc: -Wno-unused */

#include <assert.h>

#include "symbol.h"

#define DEF_SYMBOL(X,Y) symbol_t X= NULL;
#include "symbol.inc"
#undef  DEF_SYMBOL

symtab_t *symtab= NULL;

void symbol_init (int *argc_p, char ***argv_p)
{
    symtab= symtab_new();

#define DEF_SYMBOL(X,Y) X= string2symbol (Y);
#include "symbol.inc"
#undef DEF_SYMBOL
}

#if SYMBOL_DYNAMIC_TABLE

symbol_t string2symbol_default (char const *x)
{
    return symtab_ensure (symtab, x);
}

symbol_t (*string2symbol_func) (char const *) = string2symbol_default;

void set_string2symbol (symbol_t (*x)(char const *))
{
    assert ((symtab == NULL) &&
            "set_string2symbol must be invoked before symbol_init");
    string2symbol_func= x;
}

#else

symbol_t string2symbol_func (char const *x)
{
    return symtab_ensure (symtab, x);
}

#endif
