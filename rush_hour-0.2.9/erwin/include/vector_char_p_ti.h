
#ifndef ERWIN_VECTOR_CHAR_P_ti_h
#define ERWIN_VECTOR_CHAR_P_ti_h

#define vector_char_p_size_t_KIND UINT
#define vector_char_p_size_t_TYPE_INFO  TYPE_INFO_NAME(vector_char_p_size_t)
extern  TYPE_INFO_T(vector_char_p_size_t);

#define vector_char_p_cnt_t_KIND SINT
#define vector_char_p_cnt_t_TYPE_INFO  TYPE_INFO_NAME(vector_char_p_cnt_t)
extern  TYPE_INFO_T(vector_char_p_cnt_t);

#define vector_char_p_index_t_KIND SINT
#define vector_char_p_index_t_TYPE_INFO  TYPE_INFO_NAME(vector_char_p_index_t)
extern  TYPE_INFO_T(vector_char_p_index_t);

#define vector_char_p_t_KIND STRUCT
#define vector_char_p_t_TYPE_INFO  TYPE_INFO_NAME(vector_char_p_t)
extern  TYPE_INFO_T(vector_char_p_t);

#define vector_char_p_t_p_KIND POINTER
#define vector_char_p_t_p_TYPE_INFO  TYPE_INFO_NAME(vector_char_p_t_p)
extern  TYPE_INFO_T(vector_char_p_t_p);

#define vector_char_p_t_const_p_KIND POINTER
#define vector_char_p_t_const_p_TYPE_INFO  TYPE_INFO_NAME(vector_char_p_t_const_p)
extern  TYPE_INFO_T(vector_char_p_t_const_p);

#define vector_char_p_content_KIND VECTOR
#define vector_char_p_content_TYPE_INFO  TYPE_INFO_NAME(vector_char_p_content)
extern  TYPE_INFO_T(vector_char_p_content);

#define vector_char_p_content_p_KIND POINTER
#define vector_char_p_content_p_TYPE_INFO  TYPE_INFO_NAME(vector_char_p_content_p)
extern  TYPE_INFO_T(vector_char_p_content_p);

#define VectorCharP_TYPE_INFO           vector_char_p_t_TYPE_INFO
#define VectorCharP_p_TYPE_INFO         vector_char_p_t_p_TYPE_INFO
#define VectorCharP_const_p_TYPE_INFO   vector_char_p_t_const_p_TYPE_INFO

#endif /* defined ERWIN_VECTOR_CHAR_P_ti_h */

