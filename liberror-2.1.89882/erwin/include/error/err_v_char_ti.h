
#ifndef ERWIN_ERR_V_CHAR_ti_h
#define ERWIN_ERR_V_CHAR_ti_h

#define err_v_char_size_t_KIND UINT
#define err_v_char_size_t_TYPE_INFO  TYPE_INFO_NAME(err_v_char_size_t)
extern  TYPE_INFO_T(err_v_char_size_t);

#define err_v_char_cnt_t_KIND SINT
#define err_v_char_cnt_t_TYPE_INFO  TYPE_INFO_NAME(err_v_char_cnt_t)
extern  TYPE_INFO_T(err_v_char_cnt_t);

#define err_v_char_index_t_KIND SINT
#define err_v_char_index_t_TYPE_INFO  TYPE_INFO_NAME(err_v_char_index_t)
extern  TYPE_INFO_T(err_v_char_index_t);

#define err_v_char_t_KIND STRUCT
#define err_v_char_t_TYPE_INFO  TYPE_INFO_NAME(err_v_char_t)
extern  TYPE_INFO_T(err_v_char_t);

#define err_v_char_t_p_KIND POINTER
#define err_v_char_t_p_TYPE_INFO  TYPE_INFO_NAME(err_v_char_t_p)
extern  TYPE_INFO_T(err_v_char_t_p);

#define err_v_char_t_const_p_KIND POINTER
#define err_v_char_t_const_p_TYPE_INFO  TYPE_INFO_NAME(err_v_char_t_const_p)
extern  TYPE_INFO_T(err_v_char_t_const_p);

#define err_v_char_content_KIND VECTOR
#define err_v_char_content_TYPE_INFO  TYPE_INFO_NAME(err_v_char_content)
extern  TYPE_INFO_T(err_v_char_content);

#define err_v_char_content_p_KIND POINTER
#define err_v_char_content_p_TYPE_INFO  TYPE_INFO_NAME(err_v_char_content_p)
extern  TYPE_INFO_T(err_v_char_content_p);

#define ErrVChar_TYPE_INFO           err_v_char_t_TYPE_INFO
#define ErrVChar_p_TYPE_INFO         err_v_char_t_p_TYPE_INFO
#define ErrVChar_const_p_TYPE_INFO   err_v_char_t_const_p_TYPE_INFO

#endif /* defined ERWIN_ERR_V_CHAR_ti_h */

