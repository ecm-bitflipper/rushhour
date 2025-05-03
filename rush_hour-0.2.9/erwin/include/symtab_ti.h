
#ifndef ERWIN_SYMTAB_ti_h
#define ERWIN_SYMTAB_ti_h

#define symtab_hashlist_t_KIND STRUCT
#define symtab_hashlist_t_TYPE_INFO  TYPE_INFO_NAME(symtab_hashlist_t)
extern  TYPE_INFO_T(symtab_hashlist_t);

#define symtab_hashlist_t_p_KIND  POINTER
#define symtab_hashlist_t_p_TYPE_INFO  TYPE_INFO_NAME(symtab_hashlist_t_p)
extern  TYPE_INFO_T(symtab_hashlist_t_p);

#define symtab_hashlist_t_const_p_KIND POINTER
#define symtab_hashlist_t_const_p_TYPE_INFO  TYPE_INFO_NAME(symtab_hashlist_t_const_p)
extern  TYPE_INFO_T(symtab_hashlist_t_const_p);

#define symtab_internal_Iterator_KIND STRUCT
#define symtab_internal_Iterator_TYPE_INFO  TYPE_INFO_NAME(symtab_internal_Iterator)
extern  TYPE_INFO_T(symtab_internal_Iterator);

#define symtab_t_KIND STRUCT
#define symtab_t_TYPE_INFO  TYPE_INFO_NAME(symtab_t)
extern  TYPE_INFO_T(symtab_t);

#define symtab_t_p_KIND POINTER
#define symtab_t_p_TYPE_INFO  TYPE_INFO_NAME(symtab_t_p)
extern  TYPE_INFO_T(symtab_t_p);

#define symtab_t_const_p_KIND POINTER
#define symtab_t_const_p_TYPE_INFO  TYPE_INFO_NAME(symtab_t_const_p)
extern  TYPE_INFO_T(symtab_t_const_p);

#define symtab_content_KIND VECTOR
#define symtab_content_TYPE_INFO  TYPE_INFO_NAME(symtab_content)
extern  TYPE_INFO_T(symtab_content);

#define symtab_content_p_KIND POINTER
#define symtab_content_p_TYPE_INFO  TYPE_INFO_NAME(symtab_content_p)
extern  TYPE_INFO_T(symtab_content_p);

#define Symtab_TYPE_INFO          symtab_t_TYPE_INFO
#define Symtab_p_TYPE_INFO        symtab_t_p_TYPE_INFO
#define Symtab_const_p_TYPE_INFO  symtab_t_const_p_TYPE_INFO

#endif /* defined ERWIN_SYMTAB_ti_h */

