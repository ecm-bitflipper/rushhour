#include "error/erwin/defs.h"
#if !ERWIN_CAST_INLINING
#include "error/err_map_int_v_callback.h"

err_map_int_v_callback_t * err_map_int_v_callback_new (void) 
{
    return (err_map_int_v_callback_t *)(void*)err_map_int_char_p_new ();
}
err_map_int_v_callback_t * err_map_int_v_callback_new_with_initial_size (int a0) 
{
    return (err_map_int_v_callback_t *)(void*)err_map_int_char_p_new_with_initial_size (a0);
}
#if ERR_MAP_INT_V_CALLBACK_DYN_ZERO
err_map_int_v_callback_t * err_map_int_v_callback_new_with_zero (ErrVCallback *  a0) 
{
    return (err_map_int_v_callback_t *)(void*)err_map_int_char_p_new_with_zero ((char * )a0);
}
err_map_int_v_callback_t * err_map_int_v_callback_new_with_zero_and_initial_size (ErrVCallback *  a0, int a1) 
{
    return (err_map_int_v_callback_t *)(void*)err_map_int_char_p_new_with_zero_and_initial_size ((char * )a0, a1);
}
#endif
int err_map_int_v_callback_init (err_map_int_v_callback_t * a0) 
{
    return err_map_int_char_p_init ((err_map_int_char_p_t *)(void*)a0);
}
#if ERR_MAP_INT_V_CALLBACK_DYN_ZERO
int err_map_int_v_callback_init_with_zero_and_initial_size (err_map_int_v_callback_t * a0, ErrVCallback *  a1, int a2) 
{
    return err_map_int_char_p_init_with_zero_and_initial_size ((err_map_int_char_p_t *)(void*)a0, (char * )a1, a2);
}
#endif
int err_map_int_v_callback_init_with_initial_size (err_map_int_v_callback_t * a0, int a1) 
{
    return err_map_int_char_p_init_with_initial_size ((err_map_int_char_p_t *)(void*)a0, a1);
}
void err_map_int_v_callback_destroy (err_map_int_v_callback_t * a0)
{
    err_map_int_char_p_destroy ((err_map_int_char_p_t *)(void*)a0);
}
void err_map_int_v_callback_xchg (err_map_int_v_callback_t * a0, err_map_int_v_callback_t * a1)
{
    err_map_int_char_p_xchg ((err_map_int_char_p_t *)(void*)a0, (err_map_int_char_p_t *)(void*)a1);
}
void err_map_int_v_callback_destroy_flags (err_map_int_v_callback_t * a0, ERR_ERWIN_BOOL a1, ERR_ERWIN_BOOL a2)
{
    err_map_int_char_p_destroy_flags ((err_map_int_char_p_t *)(void*)a0, a1, a2);
}
#if !ERR_ERWIN_GLOBAL_ERRNO
int err_map_int_v_callback_errno (err_map_int_v_callback_t const * a0)  
{
    return err_map_int_char_p_errno ((err_map_int_char_p_t const *)(void*)a0);
}
void err_map_int_v_callback_clear_errno (err_map_int_v_callback_t const * a0) 
{
    err_map_int_char_p_clear_errno ((err_map_int_char_p_t const *)(void*)a0);
}
#else
#endif
err_map_int_v_callback_t * err_map_int_v_callback_copy (err_map_int_v_callback_t const * a0)
{
    return (err_map_int_v_callback_t *)(void*)err_map_int_char_p_copy ((err_map_int_char_p_t const *)(void*)a0);
}
err_map_int_v_callback_t * err_map_int_v_callback_copy_err (err_map_int_v_callback_t const * a0, int * a1)
{
    return (err_map_int_v_callback_t *)(void*)err_map_int_char_p_copy_err ((err_map_int_char_p_t const *)(void*)a0, a1);
}
void err_map_int_v_callback_delete (err_map_int_v_callback_t * a0)
{
    err_map_int_char_p_delete ((err_map_int_char_p_t *)(void*)a0);
}
void err_map_int_v_callback_delete_flags (err_map_int_v_callback_t * a0, ERR_ERWIN_BOOL a1, ERR_ERWIN_BOOL a2)
{
    err_map_int_char_p_delete_flags ((err_map_int_char_p_t *)(void*)a0, a1, a2);
}
int err_map_int_v_callback_insert (err_map_int_v_callback_t * a0, int  a1, ErrVCallback *  a2) 
{
    return err_map_int_char_p_insert ((err_map_int_char_p_t *)(void*)a0, (int )a1, (char * )a2);
}
int err_map_int_v_callback_insert_map (err_map_int_v_callback_t * a0, err_map_int_v_callback_t const * a1)
{
    return err_map_int_char_p_insert_map ((err_map_int_char_p_t *)(void*)a0, (err_map_int_char_p_t const *)(void*)a1);
}
int  err_map_int_v_callback_ensure (err_map_int_v_callback_t * a0, int  a1) 
{
    return (int )err_map_int_char_p_ensure ((err_map_int_char_p_t *)(void*)a0, (int )a1);
}
int  err_map_int_v_callback_ensure_no_icopy (err_map_int_v_callback_t * a0, int  a1) 
{
    return (int )err_map_int_char_p_ensure_no_icopy ((err_map_int_char_p_t *)(void*)a0, (int )a1);
}
ErrVCallback *  err_map_int_v_callback_find_any (err_map_int_v_callback_t const * a0)
  
{
    return (ErrVCallback * )err_map_int_char_p_find_any ((err_map_int_char_p_t const *)(void*)a0);
}
int err_map_int_v_callback_find_any_pair (err_map_int_v_callback_key_result_t * a0, err_map_int_v_callback_element_ptr_t * a1, err_map_int_v_callback_t const * a2)
  
{
    return err_map_int_char_p_find_any_pair ((err_map_int_char_p_key_result_t *)(void*)a0, (err_map_int_char_p_element_ptr_t *)(void*)a1, (err_map_int_char_p_t const *)(void*)a2);
}
ErrVCallback *  err_map_int_v_callback_find (err_map_int_v_callback_t const * a0, int  a1)
  
{
    return (ErrVCallback * )err_map_int_char_p_find ((err_map_int_char_p_t const *)(void*)a0, (int )a1);
}
ErrVCallback *  err_map_int_v_callback_find_ensure (err_map_int_v_callback_t * a0, int  a1)
{
    return (ErrVCallback * )err_map_int_char_p_find_ensure ((err_map_int_char_p_t *)(void*)a0, (int )a1);
}
int  err_map_int_v_callback_find_key (err_map_int_v_callback_t const * a0, int  a1) 
{
    return (int )err_map_int_char_p_find_key ((err_map_int_char_p_t const *)(void*)a0, (int )a1);
}
int  err_map_int_v_callback_find_any_key (err_map_int_v_callback_t const * a0) 
{
    return (int )err_map_int_char_p_find_any_key ((err_map_int_char_p_t const *)(void*)a0);
}
err_map_int_v_callback_element_ptr_t err_map_int_v_callback_find_ptr (err_map_int_v_callback_t const * a0, int  a1) 
{
    return (err_map_int_v_callback_element_ptr_t)err_map_int_char_p_find_ptr ((err_map_int_char_p_t const *)(void*)a0, (int )a1);
}
err_map_int_v_callback_element_ptr_t err_map_int_v_callback_find_any_ptr (err_map_int_v_callback_t const * a0) 
{
    return (err_map_int_v_callback_element_ptr_t)err_map_int_char_p_find_any_ptr ((err_map_int_char_p_t const *)(void*)a0);
}
err_map_int_v_callback_element_ptr_t err_map_int_v_callback_find_ptr_ensure (err_map_int_v_callback_t * a0, int  a1)
{
    return (err_map_int_v_callback_element_ptr_t)err_map_int_char_p_find_ptr_ensure ((err_map_int_char_p_t *)(void*)a0, (int )a1);
}
ErrVCallback * err_map_int_v_callback_modify (err_map_int_v_callback_t * a0, int  a1, ErrVCallback *  a2) 
{
    return (ErrVCallback *)err_map_int_char_p_modify ((err_map_int_char_p_t *)(void*)a0, (int )a1, (char * )a2);
}
int err_map_int_v_callback_modify_map (err_map_int_v_callback_t * a0, err_map_int_v_callback_t const * a1)
{
    return err_map_int_char_p_modify_map ((err_map_int_char_p_t *)(void*)a0, (err_map_int_char_p_t const *)(void*)a1);
}
int err_map_int_v_callback_set (err_map_int_v_callback_t * a0, int  a1, ErrVCallback *  a2) 
{
    return err_map_int_char_p_set ((err_map_int_char_p_t *)(void*)a0, (int )a1, (char * )a2);
}
int err_map_int_v_callback_set_map (err_map_int_v_callback_t * a0, err_map_int_v_callback_t const * a1)
{
    return err_map_int_char_p_set_map ((err_map_int_char_p_t *)(void*)a0, (err_map_int_char_p_t const *)(void*)a1);
}
int err_map_int_v_callback_intersect (err_map_int_v_callback_t * a0, err_map_int_v_callback_t const * a1)
{
    return err_map_int_char_p_intersect ((err_map_int_char_p_t *)(void*)a0, (err_map_int_char_p_t const *)(void*)a1);
}
int err_map_int_v_callback_intersect_no_resize (err_map_int_v_callback_t * a0, err_map_int_v_callback_t const * a1)
{
    return err_map_int_char_p_intersect_no_resize ((err_map_int_char_p_t *)(void*)a0, (err_map_int_char_p_t const *)(void*)a1);
}
ErrVCallback * err_map_int_v_callback_remove (err_map_int_v_callback_t * a0, int  a1) 
{
    return (ErrVCallback *)err_map_int_char_p_remove ((err_map_int_char_p_t *)(void*)a0, (int )a1);
}
ErrVCallback * err_map_int_v_callback_remove_no_resize (err_map_int_v_callback_t * a0, int  a1) 
{
    return (ErrVCallback *)err_map_int_char_p_remove_no_resize ((err_map_int_char_p_t *)(void*)a0, (int )a1);
}
int err_map_int_v_callback_remove_map (err_map_int_v_callback_t * a0, err_map_int_v_callback_t const * a1)
{
    return err_map_int_char_p_remove_map ((err_map_int_char_p_t *)(void*)a0, (err_map_int_char_p_t const *)(void*)a1);
}
int err_map_int_v_callback_remove_if (err_map_int_v_callback_t * a0, err_map_int_v_callback_feature_t a1, ERR_ERWIN_BOOL a2)
{
    return err_map_int_char_p_remove_if ((err_map_int_char_p_t *)(void*)a0, (err_map_int_char_p_feature_t)a1, a2);
}
int err_map_int_v_callback_erase (err_map_int_v_callback_t * a0, int  a1) 
{
    return err_map_int_char_p_erase ((err_map_int_char_p_t *)(void*)a0, (int )a1);
}
int err_map_int_v_callback_erase_no_resize (err_map_int_v_callback_t * a0, int  a1) 
{
    return err_map_int_char_p_erase_no_resize ((err_map_int_char_p_t *)(void*)a0, (int )a1);
}
int err_map_int_v_callback_erase_map (err_map_int_v_callback_t * a0, err_map_int_v_callback_t const * a1)
{
    return err_map_int_char_p_erase_map ((err_map_int_char_p_t *)(void*)a0, (err_map_int_char_p_t const *)(void*)a1);
}
int err_map_int_v_callback_erase_map_no_resize (err_map_int_v_callback_t * a0, err_map_int_v_callback_t const * a1)
{
    return err_map_int_char_p_erase_map_no_resize ((err_map_int_char_p_t *)(void*)a0, (err_map_int_char_p_t const *)(void*)a1);
}
int err_map_int_v_callback_erase_if (err_map_int_v_callback_t * a0, err_map_int_v_callback_feature_t a1, ERR_ERWIN_BOOL a2)
{
    return err_map_int_char_p_erase_if ((err_map_int_char_p_t *)(void*)a0, (err_map_int_char_p_feature_t)a1, a2);
}
int err_map_int_v_callback_poke (int * a0, ErrVCallback * * a1, err_map_int_v_callback_t * a2, int  a3, ErrVCallback *  a4, ERR_ERWIN_BOOL a5, ERR_ERWIN_BOOL a6) 
{
    return err_map_int_char_p_poke ((int *)(void*)a0, (char * *)(void*)a1, (err_map_int_char_p_t *)(void*)a2, (int )a3, (char * )a4, a5, a6);
}
int err_map_int_v_callback_poke_no_icopy (int * a0, ErrVCallback * * a1, err_map_int_v_callback_t * a2, int  a3, ErrVCallback *  a4, ERR_ERWIN_BOOL a5, ERR_ERWIN_BOOL a6) 
{
    return err_map_int_char_p_poke_no_icopy ((int *)(void*)a0, (char * *)(void*)a1, (err_map_int_char_p_t *)(void*)a2, (int )a3, (char * )a4, a5, a6);
}
int err_map_int_v_callback_poke_no_ocopy (int * a0, ErrVCallback * * a1, err_map_int_v_callback_t * a2, int  a3, ErrVCallback *  a4, ERR_ERWIN_BOOL a5, ERR_ERWIN_BOOL a6) 
{
    return err_map_int_char_p_poke_no_ocopy ((int *)(void*)a0, (char * *)(void*)a1, (err_map_int_char_p_t *)(void*)a2, (int )a3, (char * )a4, a5, a6);
}
int err_map_int_v_callback_poke_no_icopy_no_ocopy (int * a0, ErrVCallback * * a1, err_map_int_v_callback_t * a2, int  a3, ErrVCallback *  a4, ERR_ERWIN_BOOL a5, ERR_ERWIN_BOOL a6) 
{
    return err_map_int_char_p_poke_no_icopy_no_ocopy ((int *)(void*)a0, (char * *)(void*)a1, (err_map_int_char_p_t *)(void*)a2, (int )a3, (char * )a4, a5, a6);
}
ErrVCallback *  err_map_int_v_callback_zero (err_map_int_v_callback_t const * a0)  
{
    return (ErrVCallback * )err_map_int_char_p_zero ((err_map_int_char_p_t const *)(void*)a0);
}
int err_map_int_v_callback_cmp (err_map_int_v_callback_t const * a0, err_map_int_v_callback_t const * a1) 
{
    return err_map_int_char_p_cmp ((err_map_int_char_p_t const *)(void*)a0, (err_map_int_char_p_t const *)(void*)a1);
}
ERR_ERWIN_BOOL err_map_int_v_callback_equal (err_map_int_v_callback_t const * a0, err_map_int_v_callback_t const * a1) 
{
    return err_map_int_char_p_equal ((err_map_int_char_p_t const *)(void*)a0, (err_map_int_char_p_t const *)(void*)a1);
}
int err_map_int_v_callback_cmp_keys (err_map_int_v_callback_t const * a0, err_map_int_v_callback_t const * a1) 
{
    return err_map_int_char_p_cmp_keys ((err_map_int_char_p_t const *)(void*)a0, (err_map_int_char_p_t const *)(void*)a1);
}
ERR_ERWIN_BOOL err_map_int_v_callback_equal_keys (err_map_int_v_callback_t const * a0, err_map_int_v_callback_t const * a1) 
{
    return err_map_int_char_p_equal_keys ((err_map_int_char_p_t const *)(void*)a0, (err_map_int_char_p_t const *)(void*)a1);
}
err_hashval_t err_map_int_v_callback_hash_raw (err_map_int_v_callback_t const * a0) 
{
    return err_map_int_char_p_hash_raw ((err_map_int_char_p_t const *)(void*)a0);
}
err_hashval_t err_map_int_v_callback_hash (err_map_int_v_callback_t const * a0) 
{
    return err_map_int_char_p_hash ((err_map_int_char_p_t const *)(void*)a0);
}
void err_map_int_v_callback_clear (err_map_int_v_callback_t * a0)
{
    err_map_int_char_p_clear ((err_map_int_char_p_t *)(void*)a0);
}
void err_map_int_v_callback_clear_no_resize (err_map_int_v_callback_t * a0)
{
    err_map_int_char_p_clear_no_resize ((err_map_int_char_p_t *)(void*)a0);
}
void err_map_int_v_callback_clear_flags (err_map_int_v_callback_t * a0, ERR_ERWIN_BOOL a1, ERR_ERWIN_BOOL a2)
{
    err_map_int_char_p_clear_flags ((err_map_int_char_p_t *)(void*)a0, a1, a2);
}
void err_map_int_v_callback_clear_flags_no_resize (err_map_int_v_callback_t * a0, ERR_ERWIN_BOOL a1, ERR_ERWIN_BOOL a2)
{
    err_map_int_char_p_clear_flags_no_resize ((err_map_int_char_p_t *)(void*)a0, a1, a2);
}
int err_map_int_v_callback_nentries (err_map_int_v_callback_t const * a0) 
{
    return err_map_int_char_p_nentries ((err_map_int_char_p_t const *)(void*)a0);
}
ERR_ERWIN_BOOL err_map_int_v_callback_empty (err_map_int_v_callback_t const * a0) 
{
    return err_map_int_char_p_empty ((err_map_int_char_p_t const *)(void*)a0);
}
err_map_int_v_callback_pair_t * err_map_int_v_callback_get_entries (err_map_int_v_callback_t const * a0) 
{
    return (err_map_int_v_callback_pair_t *)(void*)err_map_int_char_p_get_entries ((err_map_int_char_p_t const *)(void*)a0);
}
void err_map_int_v_callback_delete_entries (err_map_int_v_callback_pair_t * a0)
{
    err_map_int_char_p_delete_entries ((err_map_int_char_p_pair_t *)(void*)a0);
}
err_map_int_v_callback_pair_ptr_t * err_map_int_v_callback_get_entries_ptr (err_map_int_v_callback_t const * a0) 
{
    return (err_map_int_v_callback_pair_ptr_t *)(void*)err_map_int_char_p_get_entries_ptr ((err_map_int_char_p_t const *)(void*)a0);
}
void err_map_int_v_callback_delete_entries_ptr (err_map_int_v_callback_pair_ptr_t * a0)
{
    err_map_int_char_p_delete_entries_ptr ((err_map_int_char_p_pair_ptr_t *)(void*)a0);
}
ErrVCallback * * err_map_int_v_callback_get_values (err_map_int_v_callback_t const * a0) 
{
    return (ErrVCallback * *)(void*)err_map_int_char_p_get_values ((err_map_int_char_p_t const *)(void*)a0);
}
void err_map_int_v_callback_delete_values (ErrVCallback * * a0)
{
    err_map_int_char_p_delete_values ((char * *)(void*)a0);
}
int * err_map_int_v_callback_get_keys (err_map_int_v_callback_t const * a0) 
{
    return (int *)(void*)err_map_int_char_p_get_keys ((err_map_int_char_p_t const *)(void*)a0);
}
void err_map_int_v_callback_delete_keys (int * a0)
{
    err_map_int_char_p_delete_keys ((int *)(void*)a0);
}
int err_map_int_v_callback_hash_size (err_map_int_v_callback_t const * a0) 
{
    return err_map_int_char_p_hash_size ((err_map_int_char_p_t const *)(void*)a0);
}
void err_map_int_v_callback_rehash (err_map_int_v_callback_t * a0, int a1)
{
    err_map_int_char_p_rehash ((err_map_int_char_p_t *)(void*)a0, a1);
}
ERR_ERWIN_BOOL err_map_int_v_callback_expect_size (err_map_int_v_callback_t * a0, int a1)
{
    return err_map_int_char_p_expect_size ((err_map_int_char_p_t *)(void*)a0, a1);
}
double err_map_int_v_callback_average_line_length (err_map_int_v_callback_t const * a0) 
{
    return err_map_int_char_p_average_line_length ((err_map_int_char_p_t const *)(void*)a0);
}
double err_map_int_v_callback_variance_line_length (err_map_int_v_callback_t const * a0) 
{
    return err_map_int_char_p_variance_line_length ((err_map_int_char_p_t const *)(void*)a0);
}
#ifdef HAVE_SQRT
double err_map_int_v_callback_deviation_line_length (err_map_int_v_callback_t const * a0) 
{
    return err_map_int_char_p_deviation_line_length ((err_map_int_char_p_t const *)(void*)a0);
}
#endif
int err_map_int_v_callback_max_line_length (err_map_int_v_callback_t const * a0) 
{
    return err_map_int_char_p_max_line_length ((err_map_int_char_p_t const *)(void*)a0);
}
int err_map_int_v_callback_min_line_length (err_map_int_v_callback_t const * a0) 
{
    return err_map_int_char_p_min_line_length ((err_map_int_char_p_t const *)(void*)a0);
}
void err_map_int_v_callback_dump (FILE * a0, err_map_int_v_callback_t const * a1)
{
    err_map_int_char_p_dump (a0, (err_map_int_char_p_t const *)(void*)a1);
}
#if !defined (ERR_ERWIN_REQUIRE_DETERMINISM) || defined (ERR_ERWIN_WEAK_DETERMINISM)
#endif
void err_map_int_v_callback_init_iterator (err_map_int_v_callback_t const * a0, err_map_iterator_t * a1)
{
    err_map_int_char_p_init_iterator ((err_map_int_char_p_t const *)(void*)a0, a1);
}
#ifdef __cplusplus
void err_map_int_v_callback_init_iterator_sorted_by_key (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_init_iterator_sorted_by_key ((err_map_int_char_p_t const *)(void*)a0, a1);
}
void err_map_int_v_callback_init_iterator_sorted_by_value (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_init_iterator_sorted_by_value ((err_map_int_char_p_t const *)(void*)a0, a1);
}
void err_map_int_v_callback_init_iterator_sorted_by_key_and_value (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_init_iterator_sorted_by_key_and_value ((err_map_int_char_p_t const *)(void*)a0, a1);
}
void err_map_int_v_callback_init_iterator_sorted_by_value_and_key (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_init_iterator_sorted_by_value_and_key ((err_map_int_char_p_t const *)(void*)a0, a1);
}
void err_map_int_v_callback_init_iterator_sorted_by_user (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1, err_map_int_v_callback_pair_cmp_t a2)
{
    err_map_int_char_p_init_iterator_sorted_by_user ((err_map_int_char_p_t const *)(void*)a0, a1, (err_map_int_char_p_pair_cmp_t)a2);
}
void err_map_int_v_callback_init_iterator_ptr_sorted_by_key (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_init_iterator_ptr_sorted_by_key ((err_map_int_char_p_t const *)(void*)a0, a1);
}
void err_map_int_v_callback_init_iterator_ptr_sorted_by_value (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_init_iterator_ptr_sorted_by_value ((err_map_int_char_p_t const *)(void*)a0, a1);
}
void err_map_int_v_callback_init_iterator_ptr_sorted_by_key_and_value (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_init_iterator_ptr_sorted_by_key_and_value ((err_map_int_char_p_t const *)(void*)a0, a1);
}
void err_map_int_v_callback_init_iterator_ptr_sorted_by_value_and_key (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_init_iterator_ptr_sorted_by_value_and_key ((err_map_int_char_p_t const *)(void*)a0, a1);
}
void err_map_int_v_callback_init_iterator_ptr_sorted_by_user (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1, err_map_int_v_callback_pair_ptr_cmp_t a2)
{
    err_map_int_char_p_init_iterator_ptr_sorted_by_user ((err_map_int_char_p_t const *)(void*)a0, a1, (err_map_int_char_p_pair_ptr_cmp_t)a2);
}
void err_map_int_v_callback_init_iterator_sorted_by_key_reverse (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_init_iterator_sorted_by_key_reverse ((err_map_int_char_p_t const *)(void*)a0, a1);
}
void err_map_int_v_callback_init_iterator_sorted_by_value_reverse (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_init_iterator_sorted_by_value_reverse ((err_map_int_char_p_t const *)(void*)a0, a1);
}
void err_map_int_v_callback_init_iterator_sorted_by_key_and_value_reverse (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_init_iterator_sorted_by_key_and_value_reverse ((err_map_int_char_p_t const *)(void*)a0, a1);
}
void err_map_int_v_callback_init_iterator_sorted_by_value_and_key_reverse (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_init_iterator_sorted_by_value_and_key_reverse ((err_map_int_char_p_t const *)(void*)a0, a1);
}
void err_map_int_v_callback_init_iterator_sorted_by_user_reverse (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1, err_map_int_v_callback_pair_cmp_t a2)
{
    err_map_int_char_p_init_iterator_sorted_by_user_reverse ((err_map_int_char_p_t const *)(void*)a0, a1, (err_map_int_char_p_pair_cmp_t)a2);
}
void err_map_int_v_callback_init_iterator_ptr_sorted_by_key_reverse (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_init_iterator_ptr_sorted_by_key_reverse ((err_map_int_char_p_t const *)(void*)a0, a1);
}
void err_map_int_v_callback_init_iterator_ptr_sorted_by_value_reverse (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_init_iterator_ptr_sorted_by_value_reverse ((err_map_int_char_p_t const *)(void*)a0, a1);
}
void err_map_int_v_callback_init_iterator_ptr_sorted_by_key_and_value_reverse (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_init_iterator_ptr_sorted_by_key_and_value_reverse ((err_map_int_char_p_t const *)(void*)a0, a1);
}
void err_map_int_v_callback_init_iterator_ptr_sorted_by_value_and_key_reverse (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_init_iterator_ptr_sorted_by_value_and_key_reverse ((err_map_int_char_p_t const *)(void*)a0, a1);
}
void err_map_int_v_callback_init_iterator_ptr_sorted_by_user_reverse (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1, err_map_int_v_callback_pair_ptr_cmp_t a2)
{
    err_map_int_char_p_init_iterator_ptr_sorted_by_user_reverse ((err_map_int_char_p_t const *)(void*)a0, a1, (err_map_int_char_p_pair_ptr_cmp_t)a2);
}
ERR_ERWIN_BOOL err_map_int_v_callback_next_iteration_sorted (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1, int * a2, ErrVCallback * * a3)
{
    return err_map_int_char_p_next_iteration_sorted ((err_map_int_char_p_t const *)(void*)a0, a1, (int *)(void*)a2, (char * *)(void*)a3);
}
ERR_ERWIN_BOOL err_map_int_v_callback_next_iteration_sorted_ptr (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1, int * a2, err_map_int_v_callback_element_ptr_t * a3)
{
    return err_map_int_char_p_next_iteration_sorted_ptr ((err_map_int_char_p_t const *)(void*)a0, a1, (int *)(void*)a2, (err_map_int_char_p_element_ptr_t *)(void*)a3);
}
ERR_ERWIN_BOOL err_map_int_v_callback_next_iteration_sorted_keys (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1, int * a2)
{
    return err_map_int_char_p_next_iteration_sorted_keys ((err_map_int_char_p_t const *)(void*)a0, a1, (int *)(void*)a2);
}
ERR_ERWIN_BOOL err_map_int_v_callback_next_iteration_sorted_values (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1, ErrVCallback * * a2)
{
    return err_map_int_char_p_next_iteration_sorted_values ((err_map_int_char_p_t const *)(void*)a0, a1, (char * *)(void*)a2);
}
ERR_ERWIN_BOOL err_map_int_v_callback_next_iteration_sorted_values_ptr (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1, err_map_int_v_callback_element_ptr_t * a2)
{
    return err_map_int_char_p_next_iteration_sorted_values_ptr ((err_map_int_char_p_t const *)(void*)a0, a1, (err_map_int_char_p_element_ptr_t *)(void*)a2);
}
ERR_ERWIN_BOOL err_map_int_v_callback_next_iteration_sorted_pairs (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1, err_map_int_v_callback_pair_t * a2)
{
    return err_map_int_char_p_next_iteration_sorted_pairs ((err_map_int_char_p_t const *)(void*)a0, a1, (err_map_int_char_p_pair_t *)(void*)a2);
}
ERR_ERWIN_BOOL err_map_int_v_callback_next_iteration_sorted_pairs_ptr (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1, err_map_int_v_callback_pair_ptr_t * a2)
{
    return err_map_int_char_p_next_iteration_sorted_pairs_ptr ((err_map_int_char_p_t const *)(void*)a0, a1, (err_map_int_char_p_pair_ptr_t *)(void*)a2);
}
ERR_ERWIN_BOOL err_map_int_v_callback_next_iteration_sorted_reverse (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1, int * a2, ErrVCallback * * a3)
{
    return err_map_int_char_p_next_iteration_sorted_reverse ((err_map_int_char_p_t const *)(void*)a0, a1, (int *)(void*)a2, (char * *)(void*)a3);
}
ERR_ERWIN_BOOL err_map_int_v_callback_next_iteration_sorted_ptr_reverse (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1, int * a2, err_map_int_v_callback_element_ptr_t * a3)
{
    return err_map_int_char_p_next_iteration_sorted_ptr_reverse ((err_map_int_char_p_t const *)(void*)a0, a1, (int *)(void*)a2, (err_map_int_char_p_element_ptr_t *)(void*)a3);
}
ERR_ERWIN_BOOL err_map_int_v_callback_next_iteration_sorted_keys_reverse (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1, int * a2)
{
    return err_map_int_char_p_next_iteration_sorted_keys_reverse ((err_map_int_char_p_t const *)(void*)a0, a1, (int *)(void*)a2);
}
ERR_ERWIN_BOOL err_map_int_v_callback_next_iteration_sorted_values_reverse (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1, ErrVCallback * * a2)
{
    return err_map_int_char_p_next_iteration_sorted_values_reverse ((err_map_int_char_p_t const *)(void*)a0, a1, (char * *)(void*)a2);
}
ERR_ERWIN_BOOL err_map_int_v_callback_next_iteration_sorted_values_ptr_reverse (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1, err_map_int_v_callback_element_ptr_t * a2)
{
    return err_map_int_char_p_next_iteration_sorted_values_ptr_reverse ((err_map_int_char_p_t const *)(void*)a0, a1, (err_map_int_char_p_element_ptr_t *)(void*)a2);
}
ERR_ERWIN_BOOL err_map_int_v_callback_next_iteration_sorted_pairs_reverse (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1, err_map_int_v_callback_pair_t * a2)
{
    return err_map_int_char_p_next_iteration_sorted_pairs_reverse ((err_map_int_char_p_t const *)(void*)a0, a1, (err_map_int_char_p_pair_t *)(void*)a2);
}
ERR_ERWIN_BOOL err_map_int_v_callback_next_iteration_sorted_pairs_ptr_reverse (err_map_int_v_callback_t const * a0, err_map_iterator_sorted_t * a1, err_map_int_v_callback_pair_ptr_t * a2)
{
    return err_map_int_char_p_next_iteration_sorted_pairs_ptr_reverse ((err_map_int_char_p_t const *)(void*)a0, a1, (err_map_int_char_p_pair_ptr_t *)(void*)a2);
}
#endif /* defined(__cplusplus) */
ERR_ERWIN_BOOL err_map_int_v_callback_next_iteration (err_map_int_v_callback_t const * a0, err_map_iterator_t * a1, int * a2, ErrVCallback * * a3)
{
    return err_map_int_char_p_next_iteration ((err_map_int_char_p_t const *)(void*)a0, a1, (int *)(void*)a2, (char * *)(void*)a3);
}
ERR_ERWIN_BOOL err_map_int_v_callback_next_iteration_ptr (err_map_int_v_callback_t const * a0, err_map_iterator_t * a1, int * a2, err_map_int_v_callback_element_ptr_t * a3)
{
    return err_map_int_char_p_next_iteration_ptr ((err_map_int_char_p_t const *)(void*)a0, a1, (int *)(void*)a2, (err_map_int_char_p_element_ptr_t *)(void*)a3);
}
ERR_ERWIN_BOOL err_map_int_v_callback_next_iteration_values (err_map_int_v_callback_t const * a0, err_map_iterator_t * a1, ErrVCallback * * a2)
{
    return err_map_int_char_p_next_iteration_values ((err_map_int_char_p_t const *)(void*)a0, a1, (char * *)(void*)a2);
}
ERR_ERWIN_BOOL err_map_int_v_callback_next_iteration_values_ptr (err_map_int_v_callback_t const * a0, err_map_iterator_t * a1, err_map_int_v_callback_element_ptr_t * a2)
{
    return err_map_int_char_p_next_iteration_values_ptr ((err_map_int_char_p_t const *)(void*)a0, a1, (err_map_int_char_p_element_ptr_t *)(void*)a2);
}
ERR_ERWIN_BOOL err_map_int_v_callback_next_iteration_keys (err_map_int_v_callback_t const * a0, err_map_iterator_t * a1, int * a2)
{
    return err_map_int_char_p_next_iteration_keys ((err_map_int_char_p_t const *)(void*)a0, a1, (int *)(void*)a2);
}
ERR_ERWIN_BOOL err_map_int_v_callback_next_iteration_pairs (err_map_int_v_callback_t const * a0, err_map_iterator_t * a1, err_map_int_v_callback_pair_t * a2)
{
    return err_map_int_char_p_next_iteration_pairs ((err_map_int_char_p_t const *)(void*)a0, a1, (err_map_int_char_p_pair_t *)(void*)a2);
}
ERR_ERWIN_BOOL err_map_int_v_callback_next_iteration_pairs_ptr (err_map_int_v_callback_t const * a0, err_map_iterator_t * a1, err_map_int_v_callback_pair_ptr_t * a2)
{
    return err_map_int_char_p_next_iteration_pairs_ptr ((err_map_int_char_p_t const *)(void*)a0, a1, (err_map_int_char_p_pair_ptr_t *)(void*)a2);
}
#ifdef ERR_ERWIN_PROFILE
int err_map_int_v_callback_nrehash_ops (err_map_int_v_callback_t const * a0) 
{
    return err_map_int_char_p_nrehash_ops ((err_map_int_char_p_t const *)(void*)a0);
}
int err_map_int_v_callback_nrehash (err_map_int_v_callback_t const * a0) 
{
    return err_map_int_char_p_nrehash ((err_map_int_char_p_t const *)(void*)a0);
}
int err_map_int_v_callback_ninsert (err_map_int_v_callback_t const * a0) 
{
    return err_map_int_char_p_ninsert ((err_map_int_char_p_t const *)(void*)a0);
}
int err_map_int_v_callback_nremove (err_map_int_v_callback_t const * a0) 
{
    return err_map_int_char_p_nremove ((err_map_int_char_p_t const *)(void*)a0);
}
int err_map_int_v_callback_nfind (err_map_int_v_callback_t const * a0) 
{
    return err_map_int_char_p_nfind ((err_map_int_char_p_t const *)(void*)a0);
}
int err_map_int_v_callback_nops (err_map_int_v_callback_t const * a0) 
{
    return err_map_int_char_p_nops ((err_map_int_char_p_t const *)(void*)a0);
}
#endif

#ifdef __cplusplus

#ifdef __cplusplus
#if !ERR_ERWIN_DEFAULT_NEW_DELETE
#endif
#endif
err_map_int_v_callback_t::err_map_int_v_callback_t (void):
    err_map_int_char_p_t ()
{}
err_map_int_v_callback_t const & err_map_int_v_callback_t::static_zero ()
{
    return (err_map_int_v_callback_t const &)err_map_int_char_p_t::static_zero ();
}
#if ERR_MAP_INT_V_CALLBACK_HAVE_INT_CONSTRUCTOR
err_map_int_v_callback_t::err_map_int_v_callback_t (int a0):
    err_map_int_char_p_t (a0)
{}
#endif
#if ERR_MAP_INT_V_CALLBACK_DYN_ZERO
err_map_int_v_callback_t::err_map_int_v_callback_t (ErrVCallback *  a0):
    err_map_int_char_p_t ((char * )a0)
{}
err_map_int_v_callback_t::err_map_int_v_callback_t (ErrVCallback *  a0, int a1):
    err_map_int_char_p_t ((char * )a0, a1)
{}
#endif
#if !ERR_ERWIN_GLOBAL_ERRNO
int err_map_int_v_callback_t::get_errno (void) const
{
    return err_map_int_char_p_t::get_errno ();
}
void err_map_int_v_callback_t::clear_errno (void) const
{
    err_map_int_char_p_t::clear_errno ();
}
#else
int err_map_int_v_callback_t::get_errno (void)
{
    return err_map_int_char_p_t::get_errno ();
}
void err_map_int_v_callback_t::clear_errno (void)
{
    err_map_int_char_p_t::clear_errno ();
}
#endif
err_map_int_v_callback_t::err_map_int_v_callback_t (err_map_int_v_callback_t const * a0):
    err_map_int_char_p_t ((err_map_int_char_p_t const *)(void*)a0)
{}
err_map_int_v_callback_t::err_map_int_v_callback_t (err_map_int_v_callback_t const & a0):
    err_map_int_char_p_t ((err_map_int_char_p_t const &)a0)
{}
err_map_int_v_callback_t * err_map_int_v_callback_t::copy (void) const
{
    return (err_map_int_v_callback_t *)(void*)err_map_int_char_p_t::copy ();
}
err_map_int_v_callback_t * err_map_int_v_callback_t::copy_err (int * a0) const
{
    return (err_map_int_v_callback_t *)(void*)err_map_int_char_p_t::copy_err (a0);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::xchg (err_map_int_v_callback_t * a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::xchg ((err_map_int_char_p_t *)(void*)a0);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::xchg (err_map_int_v_callback_t & a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::xchg ((err_map_int_char_p_t &)a0);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::operator= (err_map_int_v_callback_t const & a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::operator= ((err_map_int_char_p_t const &)a0);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::operator= (err_map_int_v_callback_t const * a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::operator= ((err_map_int_char_p_t const *)(void*)a0);
}
void err_map_int_v_callback_t::_constructor (void)
{
    err_map_int_char_p_t::_constructor ();
}
void err_map_int_v_callback_t::_destructor (void)
{
    err_map_int_char_p_t::_destructor ();
}
err_map_int_v_callback_t::operator err_map_int_v_callback_t * (void)
{
    return (err_map_int_v_callback_t *)(void*)err_map_int_char_p_t::operator err_map_int_char_p_t * ();
}
err_map_int_v_callback_t::operator err_map_int_v_callback_t const * (void) const
{
    return (err_map_int_v_callback_t const *)(void*)err_map_int_char_p_t::operator err_map_int_char_p_t const * ();
}
ErrVCallback *  err_map_int_v_callback_t::operator[] (int  a0) const
{
    return (ErrVCallback * )err_map_int_char_p_t::operator[] ((int )a0);
}
ErrVCallback * & err_map_int_v_callback_t::operator[] (int  a0)
{
    return (ErrVCallback * &)err_map_int_char_p_t::operator[] ((int )a0);
}
ErrVCallback * * err_map_int_v_callback_t::find_ptr (int  a0) const
{
    return (ErrVCallback * *)(void*)err_map_int_char_p_t::find_ptr ((int )a0);
}
ErrVCallback * * err_map_int_v_callback_t::find_ptr_ensure (int  a0)
{
    return (ErrVCallback * *)(void*)err_map_int_char_p_t::find_ptr_ensure ((int )a0);
}
ErrVCallback *  err_map_int_v_callback_t::find (int  a0) const
{
    return (ErrVCallback * )err_map_int_char_p_t::find ((int )a0);
}
ErrVCallback *  err_map_int_v_callback_t::find_ensure (int  a0)
{
    return (ErrVCallback * )err_map_int_char_p_t::find_ensure ((int )a0);
}
int  err_map_int_v_callback_t::find_any_key () const
{
    return (int )err_map_int_char_p_t::find_any_key ();
}
ErrVCallback *  err_map_int_v_callback_t::find_any () const
{
    return (ErrVCallback * )err_map_int_char_p_t::find_any ();
}
err_map_int_v_callback_element_ptr_t err_map_int_v_callback_t::find_any_ptr () const
{
    return (err_map_int_v_callback_element_ptr_t)err_map_int_char_p_t::find_any_ptr ();
}
int err_map_int_v_callback_t::find_any_pair (err_map_int_v_callback_key_result_t & a0, err_map_int_v_callback_element_ptr_t & a1) const
{
    return err_map_int_char_p_t::find_any_pair ((err_map_int_char_p_key_result_t &)a0, (err_map_int_char_p_element_ptr_t &)a1);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::insert (int  a0, ErrVCallback *  a1)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::insert ((int )a0, (char * )a1);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::insert_map (err_map_int_v_callback_t const & a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::insert_map ((err_map_int_char_p_t const &)a0);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::insert_map (err_map_int_v_callback_t const * a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::insert_map ((err_map_int_char_p_t const *)(void*)a0);
}
#if ERR_MAP_INT_V_CALLBACK_DIRECT_RECURSION == 0
err_map_int_v_callback_t & err_map_int_v_callback_t::insert (err_map_int_v_callback_t const & a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::insert ((err_map_int_char_p_t const &)a0);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::insert (err_map_int_v_callback_t const * a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::insert ((err_map_int_char_p_t const *)(void*)a0);
}
#endif
ErrVCallback * err_map_int_v_callback_t::modify (int  a0, ErrVCallback *  a1)
{
    return (ErrVCallback *)err_map_int_char_p_t::modify ((int )a0, (char * )a1);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::modify_map (err_map_int_v_callback_t const & a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::modify_map ((err_map_int_char_p_t const &)a0);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::modify_map (err_map_int_v_callback_t const * a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::modify_map ((err_map_int_char_p_t const *)(void*)a0);
}
#if ERR_MAP_INT_V_CALLBACK_DIRECT_RECURSION == 0
err_map_int_v_callback_t & err_map_int_v_callback_t::modify (err_map_int_v_callback_t const & a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::modify ((err_map_int_char_p_t const &)a0);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::modify (err_map_int_v_callback_t const * a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::modify ((err_map_int_char_p_t const *)(void*)a0);
}
#endif
err_map_int_v_callback_t & err_map_int_v_callback_t::set (int  a0, ErrVCallback *  a1)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::set ((int )a0, (char * )a1);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::set_map (err_map_int_v_callback_t const & a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::set_map ((err_map_int_char_p_t const &)a0);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::set_map (err_map_int_v_callback_t const * a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::set_map ((err_map_int_char_p_t const *)(void*)a0);
}
#if ERR_MAP_INT_V_CALLBACK_DIRECT_RECURSION == 0
err_map_int_v_callback_t & err_map_int_v_callback_t::set (err_map_int_v_callback_t const & a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::set ((err_map_int_char_p_t const &)a0);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::set (err_map_int_v_callback_t const * a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::set ((err_map_int_char_p_t const *)(void*)a0);
}
#endif
ErrVCallback * err_map_int_v_callback_t::remove (int  a0)
{
    return (ErrVCallback *)err_map_int_char_p_t::remove ((int )a0);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::remove_map (err_map_int_v_callback_t const & a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::remove_map ((err_map_int_char_p_t const &)a0);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::remove_map (err_map_int_v_callback_t const * a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::remove_map ((err_map_int_char_p_t const *)(void*)a0);
}
int err_map_int_v_callback_t::remove_if (err_map_int_v_callback_feature_t a0, bool a1)
{
    return err_map_int_char_p_t::remove_if ((err_map_int_char_p_feature_t)a0, a1);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::erase (int  a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::erase ((int )a0);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::erase_map (err_map_int_v_callback_t const & a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::erase_map ((err_map_int_char_p_t const &)a0);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::erase_map (err_map_int_v_callback_t const * a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::erase_map ((err_map_int_char_p_t const *)(void*)a0);
}
#if ERR_MAP_INT_V_CALLBACK_DIRECT_RECURSION == 0
err_map_int_v_callback_t & err_map_int_v_callback_t::erase (err_map_int_v_callback_t const & a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::erase ((err_map_int_char_p_t const &)a0);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::erase (err_map_int_v_callback_t const * a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::erase ((err_map_int_char_p_t const *)(void*)a0);
}
#endif
int err_map_int_v_callback_t::erase_if (err_map_int_v_callback_feature_t a0, bool a1)
{
    return err_map_int_char_p_t::erase_if ((err_map_int_char_p_feature_t)a0, a1);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::intersect (err_map_int_v_callback_t const & a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::intersect ((err_map_int_char_p_t const &)a0);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::intersect (err_map_int_v_callback_t const * a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::intersect ((err_map_int_char_p_t const *)(void*)a0);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::intersect_no_resize (err_map_int_v_callback_t const & a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::intersect_no_resize ((err_map_int_char_p_t const &)a0);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::intersect_no_resize (err_map_int_v_callback_t const * a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::intersect_no_resize ((err_map_int_char_p_t const *)(void*)a0);
}
int  err_map_int_v_callback_t::find_key (int  a0) const
{
    return (int )err_map_int_char_p_t::find_key ((int )a0);
}
ErrVCallback *  err_map_int_v_callback_t::zero (void) const
{
    return (ErrVCallback * )err_map_int_char_p_t::zero ();
}
int  err_map_int_v_callback_t::ensure (int  a0)
{
    return (int )err_map_int_char_p_t::ensure ((int )a0);
}
int  err_map_int_v_callback_t::ensure_no_icopy (int  a0)
{
    return (int )err_map_int_char_p_t::ensure_no_icopy ((int )a0);
}
int  err_map_int_v_callback_t::operator() (int  a0)
{
    return (int )err_map_int_char_p_t::operator() ((int )a0);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::poke (int * a0, ErrVCallback * * a1, int  a2, ErrVCallback *  a3, bool a4, bool a5)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::poke ((int *)(void*)a0, (char * *)(void*)a1, (int )a2, (char * )a3, a4, a5);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::poke_no_icopy (int * a0, ErrVCallback * * a1, int  a2, ErrVCallback *  a3, bool a4, bool a5)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::poke_no_icopy ((int *)(void*)a0, (char * *)(void*)a1, (int )a2, (char * )a3, a4, a5);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::poke_no_ocopy (int * a0, ErrVCallback * * a1, int  a2, ErrVCallback *  a3, bool a4, bool a5)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::poke_no_ocopy ((int *)(void*)a0, (char * *)(void*)a1, (int )a2, (char * )a3, a4, a5);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::poke_no_icopy_no_ocopy (int * a0, ErrVCallback * * a1, int  a2, ErrVCallback *  a3, bool a4, bool a5)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::poke_no_icopy_no_ocopy ((int *)(void*)a0, (char * *)(void*)a1, (int )a2, (char * )a3, a4, a5);
}
err_map_int_v_callback_t & err_map_int_v_callback_t::clear (void)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::clear ();
}
err_map_int_v_callback_t & err_map_int_v_callback_t::clear_no_resize (void)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::clear_no_resize ();
}
err_map_int_v_callback_t & err_map_int_v_callback_t::clear (bool a0, bool a1)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::clear (a0, a1);
}
int err_map_int_v_callback_t::nentries (void) const
{
    return err_map_int_char_p_t::nentries ();
}
bool err_map_int_v_callback_t::empty (void) const
{
    return err_map_int_char_p_t::empty ();
}
bool err_map_int_v_callback_t::non_empty (void) const
{
    return err_map_int_char_p_t::non_empty ();
}
int * err_map_int_v_callback_t::get_keys (void) const
{
    return (int *)(void*)err_map_int_char_p_t::get_keys ();
}
void err_map_int_v_callback_t::delete_keys (int * a0)
{
    err_map_int_char_p_t::delete_keys ((int *)(void*)a0);
}
err_map_int_v_callback_pair_t * err_map_int_v_callback_t::get_entries (void) const
{
    return (err_map_int_v_callback_pair_t *)(void*)err_map_int_char_p_t::get_entries ();
}
err_map_int_v_callback_pair_ptr_t * err_map_int_v_callback_t::get_entries_ptr (void) const
{
    return (err_map_int_v_callback_pair_ptr_t *)(void*)err_map_int_char_p_t::get_entries_ptr ();
}
ErrVCallback * * err_map_int_v_callback_t::get_values (void) const
{
    return (ErrVCallback * *)(void*)err_map_int_char_p_t::get_values ();
}
void err_map_int_v_callback_t::delete_entries_ptr (err_map_int_v_callback_pair_ptr_t * a0)
{
    err_map_int_char_p_t::delete_entries_ptr ((err_map_int_char_p_pair_ptr_t *)(void*)a0);
}
void err_map_int_v_callback_t::delete_entries (err_map_int_v_callback_pair_t * a0)
{
    err_map_int_char_p_t::delete_entries ((err_map_int_char_p_pair_t *)(void*)a0);
}
void err_map_int_v_callback_t::delete_values (ErrVCallback * * a0)
{
    err_map_int_char_p_t::delete_values ((char * *)(void*)a0);
}
int err_map_int_v_callback_t::hash_size (void) const
{
    return err_map_int_char_p_t::hash_size ();
}
err_map_int_v_callback_t & err_map_int_v_callback_t::rehash (int a0)
{
    return (err_map_int_v_callback_t &)err_map_int_char_p_t::rehash (a0);
}
double err_map_int_v_callback_t::average_line_length (void) const
{
    return err_map_int_char_p_t::average_line_length ();
}
double err_map_int_v_callback_t::variance_line_length (void) const
{
    return err_map_int_char_p_t::variance_line_length ();
}
#ifdef HAVE_SQRT
double err_map_int_v_callback_t::deviation_line_length (void) const
{
    return err_map_int_char_p_t::deviation_line_length ();
}
#endif
int err_map_int_v_callback_t::max_line_length (void) const
{
    return err_map_int_char_p_t::max_line_length ();
}
int err_map_int_v_callback_t::min_line_length (void) const
{
    return err_map_int_char_p_t::min_line_length ();
}
void err_map_int_v_callback_t::dump (FILE * a0) const
{
    err_map_int_char_p_t::dump (a0);
}
#ifdef ERR_ERWIN_PROFILE
int err_map_int_v_callback_t::nrehash_ops (void) const
{
    return err_map_int_char_p_t::nrehash_ops ();
}
int err_map_int_v_callback_t::nrehash (void) const
{
    return err_map_int_char_p_t::nrehash ();
}
int err_map_int_v_callback_t::ninsert (void) const
{
    return err_map_int_char_p_t::ninsert ();
}
int err_map_int_v_callback_t::nremove (void) const
{
    return err_map_int_char_p_t::nremove ();
}
int err_map_int_v_callback_t::nfind (void) const
{
    return err_map_int_char_p_t::nfind ();
}
int err_map_int_v_callback_t::nops (void) const
{
    return err_map_int_char_p_t::nops ();
}
#endif
err_hashval_t err_map_int_v_callback_t::hash_raw (void) const
{
    return err_map_int_char_p_t::hash_raw ();
}
err_hashval_t err_map_int_v_callback_t::hash (void) const
{
    return err_map_int_char_p_t::hash ();
}
bool err_map_int_v_callback_t::equal (err_map_int_v_callback_t const * a0) const
{
    return err_map_int_char_p_t::equal ((err_map_int_char_p_t const *)(void*)a0);
}
bool err_map_int_v_callback_t::equal (err_map_int_v_callback_t const & a0) const
{
    return err_map_int_char_p_t::equal ((err_map_int_char_p_t const &)a0);
}
int err_map_int_v_callback_t::cmp (err_map_int_v_callback_t const * a0) const
{
    return err_map_int_char_p_t::cmp ((err_map_int_char_p_t const *)(void*)a0);
}
int err_map_int_v_callback_t::cmp (err_map_int_v_callback_t const & a0) const
{
    return err_map_int_char_p_t::cmp ((err_map_int_char_p_t const &)a0);
}
bool err_map_int_v_callback_t::operator== (err_map_int_v_callback_t const & a0) const
{
    return err_map_int_char_p_t::operator== ((err_map_int_char_p_t const &)a0);
}
bool err_map_int_v_callback_t::operator== (err_map_int_v_callback_t const * a0) const
{
    return err_map_int_char_p_t::operator== ((err_map_int_char_p_t const *)(void*)a0);
}
bool err_map_int_v_callback_t::operator!= (err_map_int_v_callback_t const & a0) const
{
    return err_map_int_char_p_t::operator!= ((err_map_int_char_p_t const &)a0);
}
bool err_map_int_v_callback_t::operator!= (err_map_int_v_callback_t const * a0) const
{
    return err_map_int_char_p_t::operator!= ((err_map_int_char_p_t const *)(void*)a0);
}
bool err_map_int_v_callback_t::operator<= (err_map_int_v_callback_t const & a0) const
{
    return err_map_int_char_p_t::operator<= ((err_map_int_char_p_t const &)a0);
}
bool err_map_int_v_callback_t::operator<= (err_map_int_v_callback_t const * a0) const
{
    return err_map_int_char_p_t::operator<= ((err_map_int_char_p_t const *)(void*)a0);
}
bool err_map_int_v_callback_t::operator>= (err_map_int_v_callback_t const & a0) const
{
    return err_map_int_char_p_t::operator>= ((err_map_int_char_p_t const &)a0);
}
bool err_map_int_v_callback_t::operator>= (err_map_int_v_callback_t const * a0) const
{
    return err_map_int_char_p_t::operator>= ((err_map_int_char_p_t const *)(void*)a0);
}
bool err_map_int_v_callback_t::operator< (err_map_int_v_callback_t const & a0) const
{
    return err_map_int_char_p_t::operator< ((err_map_int_char_p_t const &)a0);
}
bool err_map_int_v_callback_t::operator< (err_map_int_v_callback_t const * a0) const
{
    return err_map_int_char_p_t::operator< ((err_map_int_char_p_t const *)(void*)a0);
}
bool err_map_int_v_callback_t::operator> (err_map_int_v_callback_t const & a0) const
{
    return err_map_int_char_p_t::operator> ((err_map_int_char_p_t const &)a0);
}
bool err_map_int_v_callback_t::operator> (err_map_int_v_callback_t const * a0) const
{
    return err_map_int_char_p_t::operator> ((err_map_int_char_p_t const *)(void*)a0);
}
void err_map_int_v_callback_t::init_iterator (void const * a0, err_map_iterator_t * a1)
{
    err_map_int_char_p_t::init_iterator (a0, a1);
}
bool err_map_int_v_callback_t::next (err_map_iterator_t & a0, int & a1, ErrVCallback * & a2) const
{
    return err_map_int_char_p_t::next (a0, (int &)a1, (char * &)a2);
}
void err_map_int_v_callback_t::init_iterator_sorted_by_key (void const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_t::init_iterator_sorted_by_key (a0, a1);
}
bool err_map_int_v_callback_t::next_sorted (err_map_iterator_sorted_t & a0, int & a1, ErrVCallback * & a2) const
{
    return err_map_int_char_p_t::next_sorted (a0, (int &)a1, (char * &)a2);
}
void err_map_int_v_callback_t::init_iterator_sorted_by_value (void const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_t::init_iterator_sorted_by_value (a0, a1);
}
void err_map_int_v_callback_t::init_iterator_sorted_by_key_and_value (void const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_t::init_iterator_sorted_by_key_and_value (a0, a1);
}
void err_map_int_v_callback_t::init_iterator_sorted_by_value_and_key (void const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_t::init_iterator_sorted_by_value_and_key (a0, a1);
}
void err_map_int_v_callback_t::init_iterator_sorted_by_user (void const * a0, err_map_iterator_sorted_t * a1, err_map_int_v_callback_void_pair_cmp_t a2)
{
    err_map_int_char_p_t::init_iterator_sorted_by_user (a0, a1, (err_map_int_char_p_void_pair_cmp_t)a2);
}
bool err_map_int_v_callback_t::next_user_sorted (err_map_iterator_sorted_t & a0, err_map_int_v_callback_pair_cmp_t a1, int & a2, ErrVCallback * & a3) const
{
    return err_map_int_char_p_t::next_user_sorted (a0, (err_map_int_char_p_pair_cmp_t)a1, (int &)a2, (char * &)a3);
}
bool err_map_int_v_callback_t::next_ptr (err_map_iterator_t & a0, int & a1, err_map_int_v_callback_element_ptr_t & a2) const
{
    return err_map_int_char_p_t::next_ptr (a0, (int &)a1, (err_map_int_char_p_element_ptr_t &)a2);
}
void err_map_int_v_callback_t::init_iterator_ptr_sorted_by_key (void const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_t::init_iterator_ptr_sorted_by_key (a0, a1);
}
bool err_map_int_v_callback_t::next_sorted_ptr (err_map_iterator_sorted_t & a0, int & a1, err_map_int_v_callback_element_ptr_t & a2) const
{
    return err_map_int_char_p_t::next_sorted_ptr (a0, (int &)a1, (err_map_int_char_p_element_ptr_t &)a2);
}
void err_map_int_v_callback_t::init_iterator_ptr_sorted_by_value (void const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_t::init_iterator_ptr_sorted_by_value (a0, a1);
}
void err_map_int_v_callback_t::init_iterator_ptr_sorted_by_key_and_value (void const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_t::init_iterator_ptr_sorted_by_key_and_value (a0, a1);
}
void err_map_int_v_callback_t::init_iterator_ptr_sorted_by_value_and_key (void const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_t::init_iterator_ptr_sorted_by_value_and_key (a0, a1);
}
void err_map_int_v_callback_t::init_iterator_ptr_sorted_by_user (void const * a0, err_map_iterator_sorted_t * a1, err_map_int_v_callback_void_pair_cmp_t a2)
{
    err_map_int_char_p_t::init_iterator_ptr_sorted_by_user (a0, a1, (err_map_int_char_p_void_pair_cmp_t)a2);
}
bool err_map_int_v_callback_t::next_user_sorted_ptr (err_map_iterator_sorted_t & a0, err_map_int_v_callback_pair_ptr_cmp_t a1, int & a2, err_map_int_v_callback_element_ptr_t & a3) const
{
    return err_map_int_char_p_t::next_user_sorted_ptr (a0, (err_map_int_char_p_pair_ptr_cmp_t)a1, (int &)a2, (err_map_int_char_p_element_ptr_t &)a3);
}
bool err_map_int_v_callback_t::next_key (err_map_iterator_t & a0, int & a1) const
{
    return err_map_int_char_p_t::next_key (a0, (int &)a1);
}
bool err_map_int_v_callback_t::next_sorted_key (err_map_iterator_sorted_t & a0, int & a1) const
{
    return err_map_int_char_p_t::next_sorted_key (a0, (int &)a1);
}
bool err_map_int_v_callback_t::next_user_sorted_key (err_map_iterator_sorted_t & a0, err_map_int_v_callback_pair_cmp_t a1, int & a2) const
{
    return err_map_int_char_p_t::next_user_sorted_key (a0, (err_map_int_char_p_pair_cmp_t)a1, (int &)a2);
}
bool err_map_int_v_callback_t::next_value (err_map_iterator_t & a0, ErrVCallback * & a1) const
{
    return err_map_int_char_p_t::next_value (a0, (char * &)a1);
}
bool err_map_int_v_callback_t::next_sorted_value (err_map_iterator_sorted_t & a0, ErrVCallback * & a1) const
{
    return err_map_int_char_p_t::next_sorted_value (a0, (char * &)a1);
}
bool err_map_int_v_callback_t::next_user_sorted_value (err_map_iterator_sorted_t & a0, err_map_int_v_callback_pair_cmp_t a1, ErrVCallback * & a2) const
{
    return err_map_int_char_p_t::next_user_sorted_value (a0, (err_map_int_char_p_pair_cmp_t)a1, (char * &)a2);
}
bool err_map_int_v_callback_t::next_value_ptr (err_map_iterator_t & a0, err_map_int_v_callback_element_ptr_t & a1) const
{
    return err_map_int_char_p_t::next_value_ptr (a0, (err_map_int_char_p_element_ptr_t &)a1);
}
bool err_map_int_v_callback_t::next_sorted_value_ptr (err_map_iterator_sorted_t & a0, err_map_int_v_callback_element_ptr_t & a1) const
{
    return err_map_int_char_p_t::next_sorted_value_ptr (a0, (err_map_int_char_p_element_ptr_t &)a1);
}
bool err_map_int_v_callback_t::next_user_sorted_value_ptr (err_map_iterator_sorted_t & a0, err_map_int_v_callback_pair_ptr_cmp_t a1, err_map_int_v_callback_element_ptr_t & a2) const
{
    return err_map_int_char_p_t::next_user_sorted_value_ptr (a0, (err_map_int_char_p_pair_ptr_cmp_t)a1, (err_map_int_char_p_element_ptr_t &)a2);
}
bool err_map_int_v_callback_t::next_pair (err_map_iterator_t & a0, err_map_int_v_callback_pair_t & a1) const
{
    return err_map_int_char_p_t::next_pair (a0, (err_map_int_char_p_pair_t &)a1);
}
bool err_map_int_v_callback_t::next_sorted_pair (err_map_iterator_sorted_t & a0, err_map_int_v_callback_pair_t & a1) const
{
    return err_map_int_char_p_t::next_sorted_pair (a0, (err_map_int_char_p_pair_t &)a1);
}
bool err_map_int_v_callback_t::next_user_sorted_pair (err_map_iterator_sorted_t & a0, err_map_int_v_callback_pair_cmp_t a1, err_map_int_v_callback_pair_t & a2) const
{
    return err_map_int_char_p_t::next_user_sorted_pair (a0, (err_map_int_char_p_pair_cmp_t)a1, (err_map_int_char_p_pair_t &)a2);
}
bool err_map_int_v_callback_t::next_pair_ptr (err_map_iterator_t & a0, err_map_int_v_callback_pair_ptr_t & a1) const
{
    return err_map_int_char_p_t::next_pair_ptr (a0, (err_map_int_char_p_pair_ptr_t &)a1);
}
bool err_map_int_v_callback_t::next_sorted_pair_ptr (err_map_iterator_sorted_t & a0, err_map_int_v_callback_pair_ptr_t & a1) const
{
    return err_map_int_char_p_t::next_sorted_pair_ptr (a0, (err_map_int_char_p_pair_ptr_t &)a1);
}
bool err_map_int_v_callback_t::next_user_sorted_pair_ptr (err_map_iterator_sorted_t & a0, err_map_int_v_callback_pair_ptr_cmp_t a1, err_map_int_v_callback_pair_ptr_t & a2) const
{
    return err_map_int_char_p_t::next_user_sorted_pair_ptr (a0, (err_map_int_char_p_pair_ptr_cmp_t)a1, (err_map_int_char_p_pair_ptr_t &)a2);
}
void err_map_int_v_callback_t::init_iterator_sorted_by_key_reverse (void const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_t::init_iterator_sorted_by_key_reverse (a0, a1);
}
bool err_map_int_v_callback_t::next_sorted_reverse (err_map_iterator_sorted_t & a0, int & a1, ErrVCallback * & a2) const
{
    return err_map_int_char_p_t::next_sorted_reverse (a0, (int &)a1, (char * &)a2);
}
void err_map_int_v_callback_t::init_iterator_sorted_by_value_reverse (void const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_t::init_iterator_sorted_by_value_reverse (a0, a1);
}
void err_map_int_v_callback_t::init_iterator_sorted_by_key_and_value_reverse (void const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_t::init_iterator_sorted_by_key_and_value_reverse (a0, a1);
}
void err_map_int_v_callback_t::init_iterator_sorted_by_value_and_key_reverse (void const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_t::init_iterator_sorted_by_value_and_key_reverse (a0, a1);
}
void err_map_int_v_callback_t::init_iterator_sorted_by_user_reverse (void const * a0, err_map_iterator_sorted_t * a1, err_map_int_v_callback_void_pair_cmp_t a2)
{
    err_map_int_char_p_t::init_iterator_sorted_by_user_reverse (a0, a1, (err_map_int_char_p_void_pair_cmp_t)a2);
}
bool err_map_int_v_callback_t::next_user_sorted_reverse (err_map_iterator_sorted_t & a0, err_map_int_v_callback_pair_cmp_t a1, int & a2, ErrVCallback * & a3) const
{
    return err_map_int_char_p_t::next_user_sorted_reverse (a0, (err_map_int_char_p_pair_cmp_t)a1, (int &)a2, (char * &)a3);
}
void err_map_int_v_callback_t::init_iterator_ptr_sorted_by_key_reverse (void const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_t::init_iterator_ptr_sorted_by_key_reverse (a0, a1);
}
bool err_map_int_v_callback_t::next_sorted_ptr_reverse (err_map_iterator_sorted_t & a0, int & a1, err_map_int_v_callback_element_ptr_t & a2) const
{
    return err_map_int_char_p_t::next_sorted_ptr_reverse (a0, (int &)a1, (err_map_int_char_p_element_ptr_t &)a2);
}
void err_map_int_v_callback_t::init_iterator_ptr_sorted_by_value_reverse (void const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_t::init_iterator_ptr_sorted_by_value_reverse (a0, a1);
}
void err_map_int_v_callback_t::init_iterator_ptr_sorted_by_key_and_value_reverse (void const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_t::init_iterator_ptr_sorted_by_key_and_value_reverse (a0, a1);
}
void err_map_int_v_callback_t::init_iterator_ptr_sorted_by_value_and_key_reverse (void const * a0, err_map_iterator_sorted_t * a1)
{
    err_map_int_char_p_t::init_iterator_ptr_sorted_by_value_and_key_reverse (a0, a1);
}
void err_map_int_v_callback_t::init_iterator_ptr_sorted_by_user_reverse (void const * a0, err_map_iterator_sorted_t * a1, err_map_int_v_callback_void_pair_cmp_t a2)
{
    err_map_int_char_p_t::init_iterator_ptr_sorted_by_user_reverse (a0, a1, (err_map_int_char_p_void_pair_cmp_t)a2);
}
bool err_map_int_v_callback_t::next_user_sorted_ptr_reverse (err_map_iterator_sorted_t & a0, err_map_int_v_callback_pair_ptr_cmp_t a1, int & a2, err_map_int_v_callback_element_ptr_t & a3) const
{
    return err_map_int_char_p_t::next_user_sorted_ptr_reverse (a0, (err_map_int_char_p_pair_ptr_cmp_t)a1, (int &)a2, (err_map_int_char_p_element_ptr_t &)a3);
}
bool err_map_int_v_callback_t::next_sorted_key_reverse (err_map_iterator_sorted_t & a0, int & a1) const
{
    return err_map_int_char_p_t::next_sorted_key_reverse (a0, (int &)a1);
}
bool err_map_int_v_callback_t::next_user_sorted_key_reverse (err_map_iterator_sorted_t & a0, err_map_int_v_callback_pair_cmp_t a1, int & a2) const
{
    return err_map_int_char_p_t::next_user_sorted_key_reverse (a0, (err_map_int_char_p_pair_cmp_t)a1, (int &)a2);
}
bool err_map_int_v_callback_t::next_sorted_value_reverse (err_map_iterator_sorted_t & a0, ErrVCallback * & a1) const
{
    return err_map_int_char_p_t::next_sorted_value_reverse (a0, (char * &)a1);
}
bool err_map_int_v_callback_t::next_user_sorted_value_reverse (err_map_iterator_sorted_t & a0, err_map_int_v_callback_pair_cmp_t a1, ErrVCallback * & a2) const
{
    return err_map_int_char_p_t::next_user_sorted_value_reverse (a0, (err_map_int_char_p_pair_cmp_t)a1, (char * &)a2);
}
bool err_map_int_v_callback_t::next_sorted_value_ptr_reverse (err_map_iterator_sorted_t & a0, err_map_int_v_callback_element_ptr_t & a1) const
{
    return err_map_int_char_p_t::next_sorted_value_ptr_reverse (a0, (err_map_int_char_p_element_ptr_t &)a1);
}
bool err_map_int_v_callback_t::next_user_sorted_value_ptr_reverse (err_map_iterator_sorted_t & a0, err_map_int_v_callback_pair_ptr_cmp_t a1, err_map_int_v_callback_element_ptr_t & a2) const
{
    return err_map_int_char_p_t::next_user_sorted_value_ptr_reverse (a0, (err_map_int_char_p_pair_ptr_cmp_t)a1, (err_map_int_char_p_element_ptr_t &)a2);
}
bool err_map_int_v_callback_t::next_sorted_pair_reverse (err_map_iterator_sorted_t & a0, err_map_int_v_callback_pair_t & a1) const
{
    return err_map_int_char_p_t::next_sorted_pair_reverse (a0, (err_map_int_char_p_pair_t &)a1);
}
bool err_map_int_v_callback_t::next_user_sorted_pair_reverse (err_map_iterator_sorted_t & a0, err_map_int_v_callback_pair_cmp_t a1, err_map_int_v_callback_pair_t & a2) const
{
    return err_map_int_char_p_t::next_user_sorted_pair_reverse (a0, (err_map_int_char_p_pair_cmp_t)a1, (err_map_int_char_p_pair_t &)a2);
}
bool err_map_int_v_callback_t::next_sorted_pair_ptr_reverse (err_map_iterator_sorted_t & a0, err_map_int_v_callback_pair_ptr_t & a1) const
{
    return err_map_int_char_p_t::next_sorted_pair_ptr_reverse (a0, (err_map_int_char_p_pair_ptr_t &)a1);
}
bool err_map_int_v_callback_t::next_user_sorted_pair_ptr_reverse (err_map_iterator_sorted_t & a0, err_map_int_v_callback_pair_ptr_cmp_t a1, err_map_int_v_callback_pair_ptr_t & a2) const
{
    return err_map_int_char_p_t::next_user_sorted_pair_ptr_reverse (a0, (err_map_int_char_p_pair_ptr_cmp_t)a1, (err_map_int_char_p_pair_ptr_t &)a2);
}

#endif /*__cplusplus*/


#endif /*!ERWIN_CAST_INLINING*/
