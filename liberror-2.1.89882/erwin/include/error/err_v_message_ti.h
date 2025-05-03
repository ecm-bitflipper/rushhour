
#ifndef ERWIN_ERR_V_MESSAGE_ti_h
#define ERWIN_ERR_V_MESSAGE_ti_h

#define err_v_message_size_t_KIND UINT
#define err_v_message_size_t_TYPE_INFO  TYPE_INFO_NAME(err_v_message_size_t)
extern  TYPE_INFO_T(err_v_message_size_t);

#define err_v_message_cnt_t_KIND SINT
#define err_v_message_cnt_t_TYPE_INFO  TYPE_INFO_NAME(err_v_message_cnt_t)
extern  TYPE_INFO_T(err_v_message_cnt_t);

#define err_v_message_index_t_KIND SINT
#define err_v_message_index_t_TYPE_INFO  TYPE_INFO_NAME(err_v_message_index_t)
extern  TYPE_INFO_T(err_v_message_index_t);

#define err_v_message_t_KIND STRUCT
#define err_v_message_t_TYPE_INFO  TYPE_INFO_NAME(err_v_message_t)
extern  TYPE_INFO_T(err_v_message_t);

#define err_v_message_t_p_KIND POINTER
#define err_v_message_t_p_TYPE_INFO  TYPE_INFO_NAME(err_v_message_t_p)
extern  TYPE_INFO_T(err_v_message_t_p);

#define err_v_message_t_const_p_KIND POINTER
#define err_v_message_t_const_p_TYPE_INFO  TYPE_INFO_NAME(err_v_message_t_const_p)
extern  TYPE_INFO_T(err_v_message_t_const_p);

#define err_v_message_content_KIND VECTOR
#define err_v_message_content_TYPE_INFO  TYPE_INFO_NAME(err_v_message_content)
extern  TYPE_INFO_T(err_v_message_content);

#define err_v_message_content_p_KIND POINTER
#define err_v_message_content_p_TYPE_INFO  TYPE_INFO_NAME(err_v_message_content_p)
extern  TYPE_INFO_T(err_v_message_content_p);

#define ErrVMessage_TYPE_INFO           err_v_message_t_TYPE_INFO
#define ErrVMessage_p_TYPE_INFO         err_v_message_t_p_TYPE_INFO
#define ErrVMessage_const_p_TYPE_INFO   err_v_message_t_const_p_TYPE_INFO

#endif /* defined ERWIN_ERR_V_MESSAGE_ti_h */

