/* -*- Mode: C -*- */
/* Author: Henrik Theiling
 * Description:
 *       The Erwin library for standard data structures and algorithms.
 *       This include file includes all forward declarations.
 *
 * @@Begin: Licencing and Copying@@
 *
 * Copyright (c) Henrik Theiling
 * Licence Version 2, Special Version for Erwin.
 *
 * The term 'this software' used in the following, additional to its
 * usual usage, also includes the instantiated source files generated by
 * tools of this package.
 *
 * This software is provided 'as-is', without warranty of any kind,
 * express or implied.  In no event will the authors or copyright holders
 * be held liable for any damages arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must
 * not claim that you wrote the original software. If you use this
 * software in a product, an acknowledgment in the product documentation
 * would be appreciated.
 *
 * 2. Altered source versions must be plainly marked as such, and must
 * not be misrepresented as being the original software.
 *
 * 3. You must not use any of the names of the authors or copyright
 * holders of the original software for advertising or publicity
 * pertaining to distribution without specific, written prior permission.
 *
 * 4. If you change this software and redistribute parts or all of it in
 * any form, you must make the source code of the altered version of this
 * software available.  As an exception, files that were generated by
 * tools of this package may be used freely, including modification.
 *
 * 5. This notice must not be removed or altered from any source
 * distribution.
 *
 * This licence is governed by the Laws of Germany.  Disputes shall be
 * settled by Saarbruecken City Court.
 *
 * @@End: Licencing and Copying@@
 *
 */

#ifdef ERWIN_DEBUG_INCLUDE
#warning "Including typeinfo.h."
#endif

#ifndef ERWIN_TYPEINFO_H
#define ERWIN_TYPEINFO_H

#ifdef ERWIN_DEBUG_INCLUDE
#warning "First inclusion of typeinfo.h."
#endif

#ifdef ERWIN_COMPILING
#  include "erwin/defs.h"
#else
#  include <erwin/defs.h>
#endif

#if ERWIN_TYPE_INFO && !defined(TYPE_INFO_T)

#define erwin_kind_t_defined 1
enum _erwin_kind_t {
    KIND_VOID,     /* void */
    KIND_SINT,     /* int, short, ... */
    KIND_UINT,     /* unsigned, unsigned short, ... */
    KIND_ENUM,     /* enums (kind of int, but named values) */
    KIND_FLOAT,    /* float, double */
    KIND_STRUCT,   /* containing some slots */
    KIND_ARRAY,    /* constant sized array */
    KIND_UNION,    /* is is doubtful that GCs can handle this. */
    KIND_POINTER,  /* a pointer to some other type. */
    KIND_REF,      /* a pointer to some other type; C++ variant: a reference. */
    KIND_STRING,   /* 0-terminated array (if all bytes of element type == 0 => end) */
    KIND_VECTOR,   /* dynamically sized array (must be embedded in struct) */
    KIND_FUNCTION, /* NYI */
    KIND_TUPLE     /* NYI */
};

ERWIN_KIND_TYPEDEFS(enum,   erwin_kind_t)
ERWIN_KIND_TYPEDEFS(struct, erwin_type_t)
ERWIN_KIND_TYPEDEFS(struct, erwin_slot_t)

/* Slots: */
#define erwin_slot_t_defined 1
struct _erwin_slot_t {
    char const *name;
    size_t value;
        /* struct: relative char* offset in struct,
         * enum:   value,
         * union:  unused */
    erwin_type_t_const_p type;
        /* struct/union: type of this sub-structure
         * enum: unused */
};

/* The type info: */
#define erwin_type_t_defined 1
struct _erwin_type_t {
    erwin_kind_t kind;
    char const *name;
    size_t size;
        /* For all but vector and string: the size of this type in sizeof(char).
         * vector: sizeof the nentries slot.
         * string: NYI */
    size_t nentries;
        /* array:  number of elements
         * enum:   number of values
         * struct: number of slots
         * union:  number of choices
         * vector: the offset in the surrounding struct of the slot giving the length
         * else:   0 */
    erwin_type_t_const_p element;
        /* pointer/vector/array/string: element type
         * else:   NULL */
    erwin_slot_t_const_p slot;
        /* struct: slots,
         * enum:   values
         * union:  choices
         * else:   NULL */
};

/* Even if Erwin provides the structures, the names can be changed by the user: */
#ifndef TYPE_INFO_NAME_RAW
#define TYPE_INFO_NAME_RAW(X)          ERWIN_CONCAT_TOKEN (X, _type_info)
#endif

#ifndef TYPE_STRUCT_SLOTS_NAME_RAW
#define TYPE_STRUCT_SLOTS_NAME_RAW(X)  ERWIN_CONCAT_TOKEN (X, _ti_struct_slots)
#endif

#ifndef TYPE_ENUM_VALUES_NAME_RAW
#define TYPE_ENUM_VALUES_NAME_RAW(X)   ERWIN_CONCAT_TOKEN (X, _ti_enum_values)
#endif

#ifndef TYPE_UNION_CHOICES_NAME_RAW
#define TYPE_UNION_CHOICES_NAME_RAW(X) ERWIN_CONCAT_TOKEN (X, _ti_union_choices)
#endif


/* Main type info defs: */
#define TYPE_STRUCT_T(X) erwin_slot_t TYPE_STRUCT_SLOTS(X)[]
#define TYPE_UNION_T(X)  erwin_slot_t TYPE_UNION_CHOICES(X)[]
#define TYPE_ENUM_T(X)   erwin_slot_t TYPE_ENUM_VALUES(X)[]

#define TYPE_INFO_T(X)   erwin_type_t TYPE_INFO(X)

/* Basic scalars: */
#define TYPE_INFO_SINT(Type)  { KIND_SINT,  #Type, sizeof(Type), 0, NULL, NULL }
#define TYPE_INFO_UINT(Type)  { KIND_UINT,  #Type, sizeof(Type), 0, NULL, NULL }
#define TYPE_INFO_FLOAT(Type) { KIND_FLOAT, #Type, sizeof(Type), 0, NULL, NULL }

#define TYPE_INFO_VOID(Type)  { KIND_VOID,  #Type, 0,            0, NULL, NULL }

/* Struct: */
#define TYPE_STRUCT_BEGIN(Container) {

#define TYPE_STRUCT_SLOT(Container,QElement,slot)     \
            { #slot,                                  \
              ERWIN_OFFSETOF(Container, slot), \
              &TYPE_INFO(QElement)                    \
            },

/* A slot entry for the super class.  Virtual classes are currently not supported. */
#define TYPE_SUPER(Container,Super) \
            { #Super,               \
              0                     \
              &TYPE_INFO(Super)     \
            },

#define TYPE_STRUCT_END   }

#define TYPE_INFO_STRUCT(Type,Slots)                                                    \
            {                                                                           \
                KIND_STRUCT,                                                     \
                #Type,                                                                  \
                sizeof(Type),                                                           \
                sizeof(TYPE_STRUCT_SLOTS(Slots)) / sizeof(TYPE_STRUCT_SLOTS(Slots)[0]), \
                NULL,                                                                   \
                TYPE_STRUCT_SLOTS(Slots)                                                \
            }

/* Enum: */
#define TYPE_ENUM_BEGIN(Container) {
#define TYPE_ENUM_VALUE(Container,Value)  { #Value, (int)Value, NULL },
#define TYPE_ENUM_END   }

#define TYPE_INFO_ENUM(Type,Slots)                                                     \
            {                                                                          \
                 KIND_ENUM,                                                     \
                 #Type,                                                                \
                 sizeof(Type),                                                         \
                 sizeof(TYPE_ENUM_VALUES(Slots)) / sizeof(TYPE_ENUM_VALUES(Slots)[0]), \
                 NULL,                                                                 \
                 TYPE_ENUM_VALUES(Slots)                                               \
            }

/* Union: */
#define TYPE_INFO_UNION(Type,Slots)                                                       \
            {                                                                             \
                KIND_UNION,                                                        \
                #Type                                                                     \
                sizeof(Type),                                                             \
                sizeof(TYPE_UNION_CHOICES(Slots)) / sizeof(TYPE_UNION_CHOICES(Slots)[0]), \
                NULL,                                                                     \
                TYPE_UNION_CHOICES(Slots)                                                 \
            }

/* Pointer: */
#define TYPE_INFO_POINTER(Type,Element) \
            {                           \
                KIND_POINTER,    \
                #Type,                  \
                sizeof(Type),           \
                0,                      \
                &TYPE_INFO(Element),    \
                NULL                    \
            }

/* Reference: */
#define TYPE_INFO_REF(Type,Element)  \
            {                        \
                KIND_REF,     \
                #Type,               \
                sizeof(Type),        \
                0,                   \
                &TYPE_INFO(Element), \
                NULL                 \
            }

/* Vector: */
#define TYPE_INFO_VECTOR(Type,Element,Container,slot)        \
            {                                                \
                KIND_VECTOR,                          \
                #Type,                                       \
                ERWIN_SIZEOF_MEMBER(Container, slot), \
                ERWIN_OFFSETOF(Container, slot),      \
                &TYPE_INFO(Element),                         \
                NULL                                         \
            }

/* String: */
#define TYPE_INFO_STRING(Type,Element) \
            {                          \
                KIND_STRING,    \
                #Type,                 \
                0,                     \
                0,                     \
                &TYPE_INFO(Element),   \
                NULL                   \
            }

/* Array: */
#define TYPE_INFO_ARRAY(Type,Element,NEntries) \
            {                                  \
                KIND_ARRAY,             \
                #Type,                         \
                0,                             \
                NEntries,                      \
                &TYPE_INFO(Element),           \
                NULL                           \
            }

#endif /* defined ERWIN_TYPE_INFO */


/* Whether or not Erwin provides the stuctures, */
#if defined(TYPE_INFO_T)

/* Call the _NAME_ macros indirectly to force another macro expansion step. */
#define TYPE_INFO_NAME(X)          ERWIN_IDENTITY(TYPE_INFO_NAME_RAW(X))
#define TYPE_STRUCT_SLOTS_NAME(X)  ERWIN_IDENTITY(TYPE_STRUCT_SLOTS_NAME_RAW(X))
#define TYPE_ENUM_VALUES_NAME(X)   ERWIN_IDENTITY(TYPE_ENUM_VALUES_NAME_RAW(X))
#define TYPE_UNION_CHOICES_NAME(X) ERWIN_IDENTITY(TYPE_UNION_CHOICES_NAME_RAW(X))

#define TYPE_INFO3(X)              ERWIN_IDENTITY(X##_TYPE_INFO)
#define TYPE_INFO2(X)              ERWIN_IDENTITY(TYPE_INFO3 (X))
#define TYPE_INFO(X)               ERWIN_IDENTITY(TYPE_INFO2 (X))

#define TYPE_STRUCT_SLOTS(X)       ERWIN_IDENTITY(TYPE_STRUCT_SLOTS_NAME(X))
#define TYPE_ENUM_VALUES(X)        ERWIN_IDENTITY(TYPE_ENUM_VALUES_NAME(X))
#define TYPE_UNION_CHOICES(X)      ERWIN_IDENTITY(TYPE_UNION_CHOICES_NAME(X))


/* It may be useful to include some standard types.  However, we must be
 * careful since this must also work if several Erwin libraries are linked
 * into one executable.  Thus we must include a prefix in the types although
 * the type name as such does not have such a prefix.  The defines will all
 * be protected with ifdefs. */

#define ERWIN_BOOL_KIND      ENUM
#define ERWIN_BOOL_TYPE_INFO TYPE_INFO_NAME(ERWIN_BOOL)
extern  TYPE_INFO_T(ERWIN_BOOL);
   /* This has a prefix, so that's ok. */

#ifdef __cplusplus
#ifndef bool_KIND
#define bool_KIND ENUM
#endif /* !defined bool_KIND */
#ifndef bool_TYPE_INFO
#define bool_TYPE_INFO TYPE_INFO_NAME(erwininternalbool)
#endif /* !defined bool_TYPE_INFO */
#ifndef bool_TYPE_INFO
#define bool_TYPE_INFO erwininternalbool_TYPE_INFO
#endif /* !defined bool_TYPE_INFO */
extern  TYPE_INFO_T(erwininternalbool);
#endif

#ifdef __CHAR_UNSIGNED__
#ifndef char_KIND
#define char_KIND            UINT
#endif /* !defined char_KIND */
#else
#ifndef char_KIND
#define char_KIND            SINT
#endif /* !defined char_KIND */
#endif
#define erwininternalchar_TYPE_INFO        TYPE_INFO_NAME(erwininternalchar)
#ifndef char_TYPE_INFO
#define char_TYPE_INFO       erwininternalchar_TYPE_INFO
#endif /* !defined char_TYPE_INFO */
extern  TYPE_INFO_T(erwininternalchar);

#ifndef int_KIND
#define int_KIND             SINT
#endif /* !defined int_KIND */
#define erwininternalint_TYPE_INFO         TYPE_INFO_NAME(erwininternalint)
#ifndef int_TYPE_INFO
#define int_TYPE_INFO        erwininternalint_TYPE_INFO
#endif /* !defined int_TYPE_INFO */
extern  TYPE_INFO_T(erwininternalint);

#ifndef float_KIND
#define float_KIND           FLOAT
#endif /* !defined float_KIND */
#define erwininternalfloat_TYPE_INFO       TYPE_INFO_NAME(erwininternalfloat)
#ifndef float_TYPE_INFO
#define float_TYPE_INFO      erwininternalfloat_TYPE_INFO
#endif /* !defined float_TYPE_INFO */
extern  TYPE_INFO_T(erwininternalfloat);

#ifndef double_KIND
#define double_KIND          FLOAT
#endif /* !defined double_KIND */
#define erwininternaldouble_TYPE_INFO      TYPE_INFO_NAME(erwininternaldouble)
#ifndef double_TYPE_INFO
#define double_TYPE_INFO     erwininternaldouble_TYPE_INFO
#endif /* !defined double_TYPE_INFO */
extern  TYPE_INFO_T(erwininternaldouble);

#ifndef short_KIND
#define short_KIND           SINT
#endif /* !defined short_KIND */
#define erwininternalshort_TYPE_INFO      TYPE_INFO_NAME(erwininternalshort)
#ifndef short_TYPE_INFO
#define short_TYPE_INFO      erwininternalshort_TYPE_INFO
#endif /* !defined short_TYPE_INFO */
extern  TYPE_INFO_T(erwininternalshort);

#ifndef long_KIND
#define long_KIND            SINT
#endif /* !defined long_KIND */
#define erwininternallong_TYPE_INFO       TYPE_INFO_NAME(erwininternallong)
#ifndef long_TYPE_INFO
#define long_TYPE_INFO       erwininternallong_TYPE_INFO
#endif /* !defined long_TYPE_INFO */
extern  TYPE_INFO_T(erwininternallong);

#ifdef ERWIN_LONG_LONG
#ifndef ERWIN_LONG_LONG_KIND
#define ERWIN_LONG_LONG_KIND            SINT
#endif /* !defined ERWIN_LONG_LONG_KIND */
#define erwininternalERWIN_LONG_LONG_TYPE_INFO       TYPE_INFO_NAME(erwininternalERWIN_LONG_LONG)
#ifndef ERWIN_LONG_LONG_TYPE_INFO
#define ERWIN_LONG_LONG_TYPE_INFO       erwininternalERWIN_LONG_LONG_TYPE_INFO
#endif /* !defined ERWIN_LONG_LONG_TYPE_INFO */
extern  TYPE_INFO_T(erwininternalERWIN_LONG_LONG);
#endif

#ifndef unsigned_char_KIND
#define unsigned_char_KIND       UINT
#endif /* !defined unsigned_char_KIND */
#define erwininternalunsigned_char_TYPE_INFO  TYPE_INFO_NAME(erwininternalunsigned_char)
#ifndef unsigned_char_TYPE_INFO
#define unsigned_char_TYPE_INFO  erwininternalunsigned_char_TYPE_INFO
#endif /* !defined unsigned_char_TYPE_INFO */
extern  TYPE_INFO_T(erwininternalunsigned_char);

#ifndef unsigned_KIND
#define unsigned_KIND            UINT
#endif /* !defined unsigned_KIND */
#define erwininternalunsigned_TYPE_INFO       TYPE_INFO_NAME(erwininternalunsigned)
#ifndef unsigned_TYPE_INFO
#define unsigned_TYPE_INFO       erwininternalunsigned_TYPE_INFO
#endif /* !defined unsigned_TYPE_INFO */
extern  TYPE_INFO_T(erwininternalunsigned);

#ifndef unsigned_short_KIND
#define unsigned_short_KIND      UINT
#endif /* !defined unsigned_short_KIND */
#define erwininternalunsigned_short_TYPE_INFO TYPE_INFO_NAME(erwininternalunsigned_short)
#ifndef unsigned_short_TYPE_INFO
#define unsigned_short_TYPE_INFO erwininternalunsigned_short_TYPE_INFO
#endif /* !defined unsigned_short_TYPE_INFO */
extern  TYPE_INFO_T(erwininternalunsigned_short);

#ifndef unsigned_long_KIND
#define unsigned_long_KIND       UINT
#endif /* !defined unsigned_long_KIND */
#define erwininternalunsigned_long_TYPE_INFO  TYPE_INFO_NAME(erwininternalunsigned_long)
#ifndef unsigned_long_TYPE_INFO
#define unsigned_long_TYPE_INFO  erwininternalunsigned_long_TYPE_INFO
#endif /* !defined unsigned_long_TYPE_INFO */
extern  TYPE_INFO_T(erwininternalunsigned_long);

#ifdef ERWIN_UNSIGNED_LONG_LONG
#ifndef ERWIN_UNSIGNED_LONG_LONG_KIND
#define ERWIN_UNSIGNED_LONG_LONG_KIND       UINT
#endif /* !defined ERWIN_UNSIGNED_LONG_LONG_KIND */
#define erwininternalERWIN_UNSIGNED_LONG_LONG_TYPE_INFO  TYPE_INFO_NAME(erwininternalERWIN_UNSIGNED_LONG_LONG)
#ifndef ERWIN_UNSIGNED_LONG_LONG_TYPE_INFO
#define ERWIN_UNSIGNED_LONG_LONG_TYPE_INFO  erwininternalERWIN_UNSIGNED_LONG_LONG_TYPE_INFO
#endif /* !defined ERWIN_UNSIGNED_LONG_LONG_TYPE_INFO */
extern  TYPE_INFO_T(erwininternalERWIN_UNSIGNED_LONG_LONG);
#endif

#ifndef signed_char_KIND
#define signed_char_KIND         SINT
#endif /* !defined signed_char_KIND */
#define erwininternalsigned_char_TYPE_INFO    TYPE_INFO_NAME(erwininternalsigned_char)
#ifndef signed_char_TYPE_INFO
#define signed_char_TYPE_INFO    erwininternalsigned_char_TYPE_INFO
#endif /* !defined signed_char_TYPE_INFO */
extern  TYPE_INFO_T(erwininternalsigned_char);

#ifndef size_t_KIND
#define size_t_KIND              UINT
#endif /* !defined size_t_KIND */
#define erwininternalsize_t_TYPE_INFO         TYPE_INFO_NAME(erwininternalsize_t)
#ifndef size_t_TYPE_INFO
#define size_t_TYPE_INFO         erwininternalsize_t_TYPE_INFO
#endif /* !defined size_t_TYPE_INFO */
extern  TYPE_INFO_T(erwininternalsize_t);

#ifndef void_KIND
#define void_KIND                VOID
#endif /* !defined void_KIND */
#define erwininternalvoid_TYPE_INFO         TYPE_INFO_NAME(erwininternalvoid)
#ifndef void_TYPE_INFO
#define void_TYPE_INFO         erwininternalvoid_TYPE_INFO
#endif /* !defined void_TYPE_INFO */
extern  TYPE_INFO_T(erwininternalvoid);

/* We also defined char * / char const * because they are so commonly
 * used as strings. */
#ifndef char_string_KIND
#define char_string_KIND         VECTOR
#endif /* !defined char_string_KIND */
#define erwininternalchar_string_TYPE_INFO    TYPE_INFO_NAME(erwininternalchar_string)
#ifndef char_string_TYPE_INFO
#define char_string_TYPE_INFO    erwininternalchar_string_TYPE_INFO
#endif /* !defined char_string_TYPE_INFO */
extern  TYPE_INFO_T(erwininternalchar_string);

#ifndef char_p_KIND
#define char_p_KIND              POINTER
#endif /* !defined char_p_KIND */
#define erwininternalchar_p_TYPE_INFO         TYPE_INFO_NAME(erwininternalchar_p)
#ifndef char_p_TYPE_INFO
#define char_p_TYPE_INFO         erwininternalchar_p_TYPE_INFO
#endif /* !defined char_p_TYPE_INFO */
extern  TYPE_INFO_T(erwininternalchar_p);

#ifndef char_const_p_KIND
#define char_const_p_KIND        POINTER
#endif /* !defined char_const_p_KIND */
#define erwininternalchar_const_p_TYPE_INFO   TYPE_INFO_NAME(erwininternalchar_const_p)
#ifndef char_const_p_TYPE_INFO
#define char_const_p_TYPE_INFO   erwininternalchar_const_p_TYPE_INFO
#endif /* !defined char_const_p_TYPE_INFO */
extern  TYPE_INFO_T(erwininternalchar_const_p);

#ifndef void_p_KIND
#define void_p_KIND              POINTER
#endif /* !defined void_p_KIND */
#define erwininternalvoid_p_TYPE_INFO         TYPE_INFO_NAME(erwininternalvoid_p)
#ifndef void_p_TYPE_INFO
#define void_p_TYPE_INFO         erwininternalvoid_p_TYPE_INFO
#endif /* !defined void_p_TYPE_INFO */
extern  TYPE_INFO_T(erwininternalvoid_p);

#ifndef void_const_p_KIND
#define void_const_p_KIND        POINTER
#endif /* !defined void_const_p_KIND */
#define erwininternalvoid_const_p_TYPE_INFO   TYPE_INFO_NAME(erwininternalvoid_const_p)
#ifndef void_const_p_TYPE_INFO
#define void_const_p_TYPE_INFO   erwininternalvoid_const_p_TYPE_INFO
#endif /* !defined void_const_p_TYPE_INFO */
extern  TYPE_INFO_T(erwininternalvoid_const_p);

#ifndef short_int_TYPE_INFO
#define short_int_TYPE_INFO          short_TYPE_INFO
#endif /* !defined short_int_TYPE_INFO */
#ifndef long_int_TYPE_INFO
#define long_int_TYPE_INFO           long_TYPE_INFO
#endif /* !defined long_int_TYPE_INFO */
#ifndef unsigned_short_int_TYPE_INFO
#define unsigned_short_int_TYPE_INFO unsigned_short_TYPE_INFO
#endif /* !defined unsigned_short_int_TYPE_INFO */
#ifndef unsigned_long_int_TYPE_INFO
#define unsigned_long_int_TYPE_INFO  unsigned_long_TYPE_INFO
#endif /* !defined unsigned_long_int_TYPE_INFO */
#ifndef signed_int_TYPE_INFO
#define signed_int_TYPE_INFO         int_TYPE_INFO
#endif /* !defined signed_int_TYPE_INFO */
#ifndef signed_short_TYPE_INFO
#define signed_short_TYPE_INFO       short_TYPE_INFO
#endif /* !defined signed_short_TYPE_INFO */
#ifndef signed_short_int_TYPE_INFO
#define signed_short_int_TYPE_INFO   short_TYPE_INFO
#endif /* !defined signed_short_int_TYPE_INFO */
#ifndef signed_long_TYPE_INFO
#define signed_long_TYPE_INFO        long_TYPE_INFO
#endif /* !defined signed_long_TYPE_INFO */
#ifndef signed_long_int_TYPE_INFO
#define signed_long_int_TYPE_INFO    long_TYPE_INFO
#endif /* !defined signed_long_int_TYPE_INFO */
#ifndef charp_TYPE_INFO
#define charp_TYPE_INFO              char_p_TYPE_INFO
#endif /* !defined charp_TYPE_INFO */
#ifndef char_constp_TYPE_INFO
#define char_constp_TYPE_INFO        char_const_p_TYPE_INFO
#endif /* !defined char_constp_TYPE_INFO */
#ifndef const_char_p_TYPE_INFO
#define const_char_p_TYPE_INFO       char_const_p_TYPE_INFO
#endif /* !defined const_char_p_TYPE_INFO */
#ifndef const_charp_TYPE_INFO
#define const_charp_TYPE_INFO        char_const_p_TYPE_INFO
#endif /* !defined const_charp_TYPE_INFO */
#ifndef voidp_TYPE_INFO
#define voidp_TYPE_INFO              void_p_TYPE_INFO
#endif /* !defined voidp_TYPE_INFO */
#ifndef void_constp_TYPE_INFO
#define void_constp_TYPE_INFO        void_const_p_TYPE_INFO
#endif /* !defined void_constp_TYPE_INFO */
#ifndef const_void_p_TYPE_INFO
#define const_void_p_TYPE_INFO       void_const_p_TYPE_INFO
#endif /* !defined const_void_p_TYPE_INFO */
#ifndef const_voidp_TYPE_INFO
#define const_voidp_TYPE_INFO        void_const_p_TYPE_INFO
#endif /* !defined const_voidp_TYPE_INFO */

#if defined(erwin_kind_t_defined)

extern char const *erwin_kind_to_string (erwin_kind_t) ATTR_PURE;

#endif

#ifdef __cplusplus
#ifdef erwin_type_t_defined

#define ERWIN_DEF_TYPE(Type, Which)                          \
    ERWIN_WRAPPER                                                   \
    erwin_type_t const *erwin_type (Type) ATTR_CONST; \
    ERWIN_WRAPPER                                                   \
    erwin_type_t const *erwin_type (Type)             \
        { return &Which##_TYPE_INFO; }

ERWIN_DEF_TYPE(void,           void)

ERWIN_DEF_TYPE(char,           char)
ERWIN_DEF_TYPE(signed char,    signed_char)
ERWIN_DEF_TYPE(unsigned char,  unsigned_char)

ERWIN_DEF_TYPE(short,          short)
ERWIN_DEF_TYPE(unsigned short, unsigned_short)

ERWIN_DEF_TYPE(int,            int)
ERWIN_DEF_TYPE(unsigned,       unsigned)

ERWIN_DEF_TYPE(long,           long)
ERWIN_DEF_TYPE(unsigned long,  unsigned_long)

ERWIN_DEF_TYPE(char *,        char_p)
ERWIN_DEF_TYPE(char const *,  char_p)

ERWIN_DEF_TYPE(void *,        void_p)
ERWIN_DEF_TYPE(void const *,  void_p)

#ifdef ERWIN_UNSIGNED_LONG_LONG
ERWIN_DEF_TYPE(ERWIN_LONG_LONG,          ERWIN_LONG_LONG)
ERWIN_DEF_TYPE(ERWIN_UNSIGNED_LONG_LONG, ERWIN_UNSIGNED_LONG_LONG)
#endif /* ERWIN_UNSIGNED_LONG_LONG */

#endif /* erwin_type_t_defined */
#endif /* !cplusplus */

/* @@Begin: #include@@ */
#ifdef ERWIN_COMPILING
#include "vector_char_p_ti.h"
#else
#include <vector_char_p_ti.h>
#endif
#ifdef ERWIN_COMPILING
#include "vector_edge_p_ti.h"
#else
#include <vector_edge_p_ti.h>
#endif
#ifdef ERWIN_COMPILING
#include "vector_car_p_ti.h"
#else
#include <vector_car_p_ti.h>
#endif
#ifdef ERWIN_COMPILING
#include "map_int_char_p_ti.h"
#else
#include <map_int_char_p_ti.h>
#endif
#ifdef ERWIN_COMPILING
#include "symtab_ti.h"
#else
#include <symtab_ti.h>
#endif
#ifdef ERWIN_COMPILING
#include "map_board_p_node_p_ti.h"
#else
#include <map_board_p_node_p_ti.h>
#endif
#ifdef ERWIN_COMPILING
#include "vector_board_p_ti.h"
#else
#include <vector_board_p_ti.h>
#endif
#ifdef ERWIN_COMPILING
#include "vector_node_p_ti.h"
#else
#include <vector_node_p_ti.h>
#endif
#ifdef ERWIN_COMPILING
#include "v_char_ti.h"
#else
#include <v_char_ti.h>
#endif
#ifdef ERWIN_COMPILING
#include "map_int_int_ti.h"
#else
#include <map_int_int_ti.h>
#endif
#ifdef ERWIN_COMPILING
#include "map_int_rgbcolour_p_ti.h"
#else
#include <map_int_rgbcolour_p_ti.h>
#endif
/* @@End: #include@@ */

#endif /* defined TYPE_INFO_T */

#endif
