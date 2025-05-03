
#ifndef ERWIN_V_CHAR_ti_h
#define ERWIN_V_CHAR_ti_h

#define v_char_size_t_KIND UINT
#define v_char_size_t_TYPE_INFO  TYPE_INFO_NAME(v_char_size_t)
extern  TYPE_INFO_T(v_char_size_t);

#define v_char_cnt_t_KIND SINT
#define v_char_cnt_t_TYPE_INFO  TYPE_INFO_NAME(v_char_cnt_t)
extern  TYPE_INFO_T(v_char_cnt_t);

#define v_char_index_t_KIND SINT
#define v_char_index_t_TYPE_INFO  TYPE_INFO_NAME(v_char_index_t)
extern  TYPE_INFO_T(v_char_index_t);

#define v_char_t_KIND STRUCT
#define v_char_t_TYPE_INFO  TYPE_INFO_NAME(v_char_t)
extern  TYPE_INFO_T(v_char_t);

#define v_char_t_p_KIND POINTER
#define v_char_t_p_TYPE_INFO  TYPE_INFO_NAME(v_char_t_p)
extern  TYPE_INFO_T(v_char_t_p);

#define v_char_t_const_p_KIND POINTER
#define v_char_t_const_p_TYPE_INFO  TYPE_INFO_NAME(v_char_t_const_p)
extern  TYPE_INFO_T(v_char_t_const_p);

#define v_char_content_KIND VECTOR
#define v_char_content_TYPE_INFO  TYPE_INFO_NAME(v_char_content)
extern  TYPE_INFO_T(v_char_content);

#define v_char_content_p_KIND POINTER
#define v_char_content_p_TYPE_INFO  TYPE_INFO_NAME(v_char_content_p)
extern  TYPE_INFO_T(v_char_content_p);

#define VChar_TYPE_INFO           v_char_t_TYPE_INFO
#define VChar_p_TYPE_INFO         v_char_t_p_TYPE_INFO
#define VChar_const_p_TYPE_INFO   v_char_t_const_p_TYPE_INFO

#endif /* defined ERWIN_V_CHAR_ti_h */

