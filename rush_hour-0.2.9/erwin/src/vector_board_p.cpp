#include "erwin/defs.h"
#if !ERWIN_CAST_INLINING
#include "vector_board_p.h"

vector_board_p_t * vector_board_p_new (void) 
{
    return (vector_board_p_t *)(void*)vector_char_p_new ();
}
#if VECTOR_BOARD_P_DYN_ZERO
vector_board_p_t * vector_board_p_new_with_zero (Board *  a0) 
{
    return (vector_board_p_t *)(void*)vector_char_p_new_with_zero ((char * )a0);
}
vector_board_p_t * vector_board_p_new_with_zero_and_initial_size (Board *  a0, vector_board_p_cnt_t a1) 
{
    return (vector_board_p_t *)(void*)vector_char_p_new_with_zero_and_initial_size ((char * )a0, (vector_char_p_cnt_t)a1);
}
#endif
vector_board_p_t * vector_board_p_new_with_initial_size (vector_board_p_cnt_t a0) 
{
    return (vector_board_p_t *)(void*)vector_char_p_new_with_initial_size ((vector_char_p_cnt_t)a0);
}
vector_board_p_t * vector_board_p_new_from_raw (Board * * a0, vector_board_p_cnt_t a1, vector_board_p_cnt_t a2) 
{
    return (vector_board_p_t *)(void*)vector_char_p_new_from_raw ((char * *)(void*)a0, (vector_char_p_cnt_t)a1, (vector_char_p_cnt_t)a2);
}
#if VECTOR_BOARD_P_DYN_ZERO
vector_board_p_t * vector_board_p_new_from_raw_with_zero (Board * * a0, vector_board_p_cnt_t a1, vector_board_p_cnt_t a2, Board *  a3) 
{
    return (vector_board_p_t *)(void*)vector_char_p_new_from_raw_with_zero ((char * *)(void*)a0, (vector_char_p_cnt_t)a1, (vector_char_p_cnt_t)a2, (char * )a3);
}
#endif
vector_board_p_t * vector_board_p_new_from_vector (vector_board_p_t * a0) 
{
    return (vector_board_p_t *)(void*)vector_char_p_new_from_vector ((vector_char_p_t *)(void*)a0);
}
int vector_board_p_init (vector_board_p_t * a0) 
{
    return vector_char_p_init ((vector_char_p_t *)(void*)a0);
}
#if VECTOR_BOARD_P_DYN_ZERO
int vector_board_p_init_with_zero_and_initial_size (vector_board_p_t * a0, Board *  a1, vector_board_p_cnt_t a2) 
{
    return vector_char_p_init_with_zero_and_initial_size ((vector_char_p_t *)(void*)a0, (char * )a1, (vector_char_p_cnt_t)a2);
}
#endif
int vector_board_p_init_with_initial_size (vector_board_p_t * a0, vector_board_p_cnt_t a1) 
{
    return vector_char_p_init_with_initial_size ((vector_char_p_t *)(void*)a0, (vector_char_p_cnt_t)a1);
}
void vector_board_p_destroy (vector_board_p_t * a0)
{
    vector_char_p_destroy ((vector_char_p_t *)(void*)a0);
}
void vector_board_p_xchg (vector_board_p_t * a0, vector_board_p_t * a1)
{
    vector_char_p_xchg ((vector_char_p_t *)(void*)a0, (vector_char_p_t *)(void*)a1);
}
#if !ERWIN_GLOBAL_ERRNO
int vector_board_p_errno (vector_board_p_t const * a0)  
{
    return vector_char_p_errno ((vector_char_p_t const *)(void*)a0);
}
void vector_board_p_clear_errno (vector_board_p_t const * a0) 
{
    vector_char_p_clear_errno ((vector_char_p_t const *)(void*)a0);
}
#else
#endif
vector_board_p_t * vector_board_p_copy (vector_board_p_t const * a0)
{
    return (vector_board_p_t *)(void*)vector_char_p_copy ((vector_char_p_t const *)(void*)a0);
}
vector_board_p_t * vector_board_p_copy_err (vector_board_p_t const * a0, int * a1)
{
    return (vector_board_p_t *)(void*)vector_char_p_copy_err ((vector_char_p_t const *)(void*)a0, a1);
}
int vector_board_p_insert_subvector (vector_board_p_t * a0, vector_board_p_index_t a1, vector_board_p_t const * a2, vector_board_p_index_t a3, vector_board_p_cnt_t a4, ERWIN_BOOL a5)
{
    return vector_char_p_insert_subvector ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (vector_char_p_t const *)(void*)a2, (vector_char_p_index_t)a3, (vector_char_p_cnt_t)a4, a5);
}
vector_board_p_t * vector_board_p_subvector (vector_board_p_t const * a0, vector_board_p_index_t a1, vector_board_p_cnt_t a2, ERWIN_BOOL a3)
{
    return (vector_board_p_t *)(void*)vector_char_p_subvector ((vector_char_p_t const *)(void*)a0, (vector_char_p_index_t)a1, (vector_char_p_cnt_t)a2, a3);
}
void vector_board_p_delete (vector_board_p_t * a0)
{
    vector_char_p_delete ((vector_char_p_t *)(void*)a0);
}
void vector_board_p_detach (vector_board_p_t * a0)
{
    vector_char_p_detach ((vector_char_p_t *)(void*)a0);
}
void vector_board_p_delete_array (vector_board_p_element_ptr_t a0)
{
    vector_char_p_delete_array ((vector_char_p_element_ptr_t)a0);
}
void vector_board_p_detach_as_is (vector_board_p_t * a0)
{
    vector_char_p_detach_as_is ((vector_char_p_t *)(void*)a0);
}
int vector_board_p_append (vector_board_p_t * a0, Board *  a1)
{
    return vector_char_p_append ((vector_char_p_t *)(void*)a0, (char * )a1);
}
Board *  vector_board_p_zero (vector_board_p_t const * a0) 
{
    return (Board * )vector_char_p_zero ((vector_char_p_t const *)(void*)a0);
}
Board *  vector_board_p_nth_char (vector_board_p_t const * a0, vector_board_p_index_t a1) 
{
    return (Board * )vector_char_p_nth_char ((vector_char_p_t const *)(void*)a0, (vector_char_p_index_t)a1);
}
Board *  vector_board_p_first (vector_board_p_t const * a0) 
{
    return (Board * )vector_char_p_first ((vector_char_p_t const *)(void*)a0);
}
Board *  vector_board_p_last (vector_board_p_t const * a0) 
{
    return (Board * )vector_char_p_last ((vector_char_p_t const *)(void*)a0);
}
Board * vector_board_p_modify (vector_board_p_t * a0, vector_board_p_index_t a1, Board *  a2) 
{
    return (Board *)vector_char_p_modify ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (char * )a2);
}
int vector_board_p_set (vector_board_p_t * a0, vector_board_p_index_t a1, Board *  a2) 
{
    return vector_char_p_set ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (char * )a2);
}
void vector_board_p_swap (vector_board_p_t * a0, vector_board_p_index_t a1, vector_board_p_index_t a2) 
{
    vector_char_p_swap ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (vector_char_p_index_t)a2);
}
vector_board_p_element_ptr_t vector_board_p_nth_ptr (vector_board_p_t * a0, vector_board_p_index_t a1) 
{
    return (vector_board_p_element_ptr_t)vector_char_p_nth_ptr ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1);
}
vector_board_p_element_ptr_t vector_board_p_nth_ptr_check (vector_board_p_t * a0, vector_board_p_index_t a1)
{
    return (vector_board_p_element_ptr_t)vector_char_p_nth_ptr_check ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1);
}
vector_board_p_element_ptr_t vector_board_p_nth_ptr_char (vector_board_p_t * a0, vector_board_p_index_t a1) 
{
    return (vector_board_p_element_ptr_t)vector_char_p_nth_ptr_char ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1);
}
vector_board_p_element_ptr_t vector_board_p_first_ptr (vector_board_p_t * a0) 
{
    return (vector_board_p_element_ptr_t)vector_char_p_first_ptr ((vector_char_p_t *)(void*)a0);
}
vector_board_p_element_ptr_t vector_board_p_last_ptr (vector_board_p_t * a0) 
{
    return (vector_board_p_element_ptr_t)vector_char_p_last_ptr ((vector_char_p_t *)(void*)a0);
}
void vector_board_p_reverse (vector_board_p_t * a0)
{
    vector_char_p_reverse ((vector_char_p_t *)(void*)a0);
}
int vector_board_p_erase (vector_board_p_t * a0, vector_board_p_index_t a1, vector_board_p_cnt_t a2)
{
    return vector_char_p_erase ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (vector_char_p_cnt_t)a2);
}
int vector_board_p_erase_flags (vector_board_p_t * a0, vector_board_p_index_t a1, vector_board_p_cnt_t a2, ERWIN_BOOL a3, ERWIN_BOOL a4)
{
    return vector_char_p_erase_flags ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (vector_char_p_cnt_t)a2, a3, a4);
}
int vector_board_p_swap_erase (vector_board_p_t * a0, vector_board_p_index_t a1, vector_board_p_cnt_t a2)
{
    return vector_char_p_swap_erase ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (vector_char_p_cnt_t)a2);
}
int vector_board_p_swap_erase_flags (vector_board_p_t * a0, vector_board_p_index_t a1, vector_board_p_cnt_t a2, ERWIN_BOOL a3, ERWIN_BOOL a4)
{
    return vector_char_p_swap_erase_flags ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (vector_char_p_cnt_t)a2, a3, a4);
}
vector_board_p_cnt_t vector_board_p_erase_if (vector_board_p_t * a0, vector_board_p_feature_t a1, ERWIN_BOOL a2)
{
    return (vector_board_p_cnt_t)vector_char_p_erase_if ((vector_char_p_t *)(void*)a0, (vector_char_p_feature_t)a1, a2);
}
vector_board_p_cnt_t vector_board_p_erase_equals (vector_board_p_t * a0, vector_board_p_cmp_t a1, vector_board_p_combine_t a2)
{
    return (vector_board_p_cnt_t)vector_char_p_erase_equals ((vector_char_p_t *)(void*)a0, (vector_char_p_cmp_t)a1, (vector_char_p_combine_t)a2);
}
vector_board_p_cnt_t vector_board_p_erase_zero (vector_board_p_t * a0)
{
    return (vector_board_p_cnt_t)vector_char_p_erase_zero ((vector_char_p_t *)(void*)a0);
}
vector_board_p_cnt_t vector_board_p_erase_if_flags (vector_board_p_t * a0, vector_board_p_feature_t a1, ERWIN_BOOL a2, ERWIN_BOOL a3, ERWIN_BOOL a4)
{
    return (vector_board_p_cnt_t)vector_char_p_erase_if_flags ((vector_char_p_t *)(void*)a0, (vector_char_p_feature_t)a1, a2, a3, a4);
}
void vector_board_p_make_heap (vector_board_p_t * a0, vector_board_p_cmp_t a1)
{
    vector_char_p_make_heap ((vector_char_p_t *)(void*)a0, (vector_char_p_cmp_t)a1);
}
vector_board_p_index_t vector_board_p_heap_left (vector_board_p_t const * a0, vector_board_p_index_t a1) 
{
    return (vector_board_p_index_t)vector_char_p_heap_left ((vector_char_p_t const *)(void*)a0, (vector_char_p_index_t)a1);
}
vector_board_p_index_t vector_board_p_heap_right (vector_board_p_t const * a0, vector_board_p_index_t a1) 
{
    return (vector_board_p_index_t)vector_char_p_heap_right ((vector_char_p_t const *)(void*)a0, (vector_char_p_index_t)a1);
}
vector_board_p_index_t vector_board_p_heap_father (vector_board_p_t const * a0, vector_board_p_index_t a1) 
{
    return (vector_board_p_index_t)vector_char_p_heap_father ((vector_char_p_t const *)(void*)a0, (vector_char_p_index_t)a1);
}
Board * vector_board_p_heap_extract (vector_board_p_t * a0, vector_board_p_cmp_t a1) 
{
    return (Board *)vector_char_p_heap_extract ((vector_char_p_t *)(void*)a0, (vector_char_p_cmp_t)a1);
}
void vector_board_p_heap_raise (vector_board_p_t * a0, vector_board_p_index_t a1, vector_board_p_cmp_t a2) 
{
    vector_char_p_heap_raise ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (vector_char_p_cmp_t)a2);
}
void vector_board_p_heap_sink (vector_board_p_t * a0, vector_board_p_index_t a1, vector_board_p_cmp_t a2) 
{
    vector_char_p_heap_sink ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (vector_char_p_cmp_t)a2);
}
void vector_board_p_heap_fix (vector_board_p_t * a0, vector_board_p_index_t a1, vector_board_p_cmp_t a2) 
{
    vector_char_p_heap_fix ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (vector_char_p_cmp_t)a2);
}
int vector_board_p_heap_insert (vector_board_p_t * a0, Board *  a1, vector_board_p_cmp_t a2) 
{
    return vector_char_p_heap_insert ((vector_char_p_t *)(void*)a0, (char * )a1, (vector_char_p_cmp_t)a2);
}
void vector_board_p_heap_erase (vector_board_p_t * a0, vector_board_p_index_t a1, vector_board_p_cmp_t a2) 
{
    vector_char_p_heap_erase ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (vector_char_p_cmp_t)a2);
}
void vector_board_p_heap_sort (vector_board_p_t * a0, vector_board_p_cmp_t a1)
{
    vector_char_p_heap_sort ((vector_char_p_t *)(void*)a0, (vector_char_p_cmp_t)a1);
}
int vector_board_p_priority_cmp (vector_board_p_t const * a0, vector_board_p_t const * a1, vector_board_p_cmp_t a2)
{
    return vector_char_p_priority_cmp ((vector_char_p_t const *)(void*)a0, (vector_char_p_t const *)(void*)a1, (vector_char_p_cmp_t)a2);
}
int vector_board_p_chop (vector_board_p_t * a0, vector_board_p_cnt_t a1)
{
    return vector_char_p_chop ((vector_char_p_t *)(void*)a0, (vector_char_p_cnt_t)a1);
}
int vector_board_p_chop_flags (vector_board_p_t * a0, vector_board_p_cnt_t a1, ERWIN_BOOL a2, ERWIN_BOOL a3)
{
    return vector_char_p_chop_flags ((vector_char_p_t *)(void*)a0, (vector_char_p_cnt_t)a1, a2, a3);
}
Board * vector_board_p_last_chop1 (vector_board_p_t * a0) 
{
    return (Board *)vector_char_p_last_chop1 ((vector_char_p_t *)(void*)a0);
}
Board * vector_board_p_first_swap_chop1 (vector_board_p_t * a0) 
{
    return (Board *)vector_char_p_first_swap_chop1 ((vector_char_p_t *)(void*)a0);
}
int vector_board_p_append_raw (vector_board_p_t * a0, Board * const * a1, vector_board_p_cnt_t a2) 
{
    return vector_char_p_append_raw ((vector_char_p_t *)(void*)a0, (char * const *)(void*)a1, (vector_char_p_cnt_t)a2);
}
int vector_board_p_append_no_copy (vector_board_p_t * a0, Board * const * a1, vector_board_p_cnt_t a2) 
{
    return vector_char_p_append_no_copy ((vector_char_p_t *)(void*)a0, (char * const *)(void*)a1, (vector_char_p_cnt_t)a2);
}
int vector_board_p_append_vector (vector_board_p_t * a0, vector_board_p_t const * a1) 
{
    return vector_char_p_append_vector ((vector_char_p_t *)(void*)a0, (vector_char_p_t const *)(void*)a1);
}
int vector_board_p_append_string (vector_board_p_t * a0, Board * const * a1) 
{
    return vector_char_p_append_string ((vector_char_p_t *)(void*)a0, (char * const *)(void*)a1);
}
int vector_board_p_make_gap (vector_board_p_t * a0, vector_board_p_index_t a1, vector_board_p_cnt_t a2)
{
    return vector_char_p_make_gap ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (vector_char_p_cnt_t)a2);
}
int vector_board_p_make_gap_with (vector_board_p_t * a0, vector_board_p_index_t a1, Board *  a2, vector_board_p_cnt_t a3)
{
    return vector_char_p_make_gap_with ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (char * )a2, (vector_char_p_cnt_t)a3);
}
int vector_board_p_overwrite_raw (vector_board_p_t * a0, vector_board_p_index_t a1, Board * const * a2, vector_board_p_cnt_t a3)
{
    return vector_char_p_overwrite_raw ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (char * const *)(void*)a2, (vector_char_p_cnt_t)a3);
}
int vector_board_p_overwrite_flags (vector_board_p_t * a0, vector_board_p_index_t a1, Board * const * a2, vector_board_p_cnt_t a3, ERWIN_BOOL a4, ERWIN_BOOL a5)
{
    return vector_char_p_overwrite_flags ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (char * const *)(void*)a2, (vector_char_p_cnt_t)a3, a4, a5);
}
int vector_board_p_overwrite_string (vector_board_p_t * a0, vector_board_p_index_t a1, Board * const * a2)
{
    return vector_char_p_overwrite_string ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (char * const *)(void*)a2);
}
int vector_board_p_overwrite_vector (vector_board_p_t * a0, vector_board_p_index_t a1, vector_board_p_t const * a2)
{
    return vector_char_p_overwrite_vector ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (vector_char_p_t const *)(void*)a2);
}
int vector_board_p_overwrite (vector_board_p_t * a0, vector_board_p_index_t a1, vector_board_p_t const * a2, vector_board_p_index_t a3, vector_board_p_cnt_t a4)
{
    return vector_char_p_overwrite ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (vector_char_p_t const *)(void*)a2, (vector_char_p_index_t)a3, (vector_char_p_cnt_t)a4);
}
int vector_board_p_insert (vector_board_p_t * a0, vector_board_p_index_t a1, Board *  a2) 
{
    return vector_char_p_insert ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (char * )a2);
}
int vector_board_p_insert_raw (vector_board_p_t * a0, vector_board_p_index_t a1, Board * const * a2, vector_board_p_cnt_t a3)
{
    return vector_char_p_insert_raw ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (char * const *)(void*)a2, (vector_char_p_cnt_t)a3);
}
int vector_board_p_insert_no_copy (vector_board_p_t * a0, vector_board_p_index_t a1, Board * const * a2, vector_board_p_cnt_t a3)
{
    return vector_char_p_insert_no_copy ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (char * const *)(void*)a2, (vector_char_p_cnt_t)a3);
}
int vector_board_p_insert_string (vector_board_p_t * a0, vector_board_p_index_t a1, Board * const * a2) 
{
    return vector_char_p_insert_string ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (char * const *)(void*)a2);
}
int vector_board_p_insert_vector (vector_board_p_t * a0, vector_board_p_index_t a1, vector_board_p_t const * a2)
{
    return vector_char_p_insert_vector ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t)a1, (vector_char_p_t const *)(void*)a2);
}
vector_board_p_cnt_t vector_board_p_string_length (vector_board_p_t const * a0, Board * const * a1) 
{
    return (vector_board_p_cnt_t)vector_char_p_string_length ((vector_char_p_t const *)(void*)a0, (char * const *)(void*)a1);
}
int vector_board_p_ensure_size (vector_board_p_t * a0, vector_board_p_cnt_t a1) 
{
    return vector_char_p_ensure_size ((vector_char_p_t *)(void*)a0, (vector_char_p_cnt_t)a1);
}
int vector_board_p_ensure_size_with (vector_board_p_t * a0, vector_board_p_cnt_t a1, Board *  a2) 
{
    return vector_char_p_ensure_size_with ((vector_char_p_t *)(void*)a0, (vector_char_p_cnt_t)a1, (char * )a2);
}
int vector_board_p_set_size (vector_board_p_t * a0, vector_board_p_cnt_t a1)
{
    return vector_char_p_set_size ((vector_char_p_t *)(void*)a0, (vector_char_p_cnt_t)a1);
}
int vector_board_p_set_size_with (vector_board_p_t * a0, vector_board_p_cnt_t a1, Board *  a2)
{
    return vector_char_p_set_size_with ((vector_char_p_t *)(void*)a0, (vector_char_p_cnt_t)a1, (char * )a2);
}
int vector_board_p_set_size_no_resize (vector_board_p_t * a0, vector_board_p_cnt_t a1)
{
    return vector_char_p_set_size_no_resize ((vector_char_p_t *)(void*)a0, (vector_char_p_cnt_t)a1);
}
int vector_board_p_set_size_raw (vector_board_p_t * a0, vector_board_p_cnt_t a1)
{
    return vector_char_p_set_size_raw ((vector_char_p_t *)(void*)a0, (vector_char_p_cnt_t)a1);
}
void vector_board_p_shrink (vector_board_p_t * a0, ERWIN_BOOL a1)
{
    vector_char_p_shrink ((vector_char_p_t *)(void*)a0, a1);
}
int vector_board_p_ensure_table_size (vector_board_p_t * a0, vector_board_p_cnt_t a1) 
{
    return vector_char_p_ensure_table_size ((vector_char_p_t *)(void*)a0, (vector_char_p_cnt_t)a1);
}
vector_board_p_element_ptr_t vector_board_p_as_array (vector_board_p_t const * a0)
{
    return (vector_board_p_element_ptr_t)vector_char_p_as_array ((vector_char_p_t const *)(void*)a0);
}
vector_board_p_element_ptr_t vector_board_p_as_open_array (vector_board_p_t const * a0) 
{
    return (vector_board_p_element_ptr_t)vector_char_p_as_open_array ((vector_char_p_t const *)(void*)a0);
}
vector_board_p_element_ptr_t vector_board_p_as_array_detach (vector_board_p_t * a0)
{
    return (vector_board_p_element_ptr_t)vector_char_p_as_array_detach ((vector_char_p_t *)(void*)a0);
}
void vector_board_p_ensure_heap_storage (vector_board_p_t * a0) 
{
    vector_char_p_ensure_heap_storage ((vector_char_p_t *)(void*)a0);
}
ERWIN_BOOL vector_board_p_has_heap_storage (vector_board_p_t const * a0) 
{
    return vector_char_p_has_heap_storage ((vector_char_p_t const *)(void*)a0);
}
vector_board_p_cnt_t vector_board_p_inline_store_cnt (void) 
{
    return (vector_board_p_cnt_t)vector_char_p_inline_store_cnt ();
}
vector_board_p_element_ptr_t vector_board_p_as_open_array_detach (vector_board_p_t * a0)
{
    return (vector_board_p_element_ptr_t)vector_char_p_as_open_array_detach ((vector_char_p_t *)(void*)a0);
}
void vector_board_p_qsort (vector_board_p_t * a0, vector_board_p_cmp_t a1)
{
    vector_char_p_qsort ((vector_char_p_t *)(void*)a0, (vector_char_p_cmp_t)a1);
}
void vector_board_p_sort (vector_board_p_t * a0, vector_board_p_cmp_t a1)
{
    vector_char_p_sort ((vector_char_p_t *)(void*)a0, (vector_char_p_cmp_t)a1);
}
vector_board_p_index_t vector_board_p_bfind (vector_board_p_t const * a0, Board *  a1, vector_board_p_cmp_t a2)
{
    return (vector_board_p_index_t)vector_char_p_bfind ((vector_char_p_t const *)(void*)a0, (char * )a1, (vector_char_p_cmp_t)a2);
}
ERWIN_BOOL vector_board_p_locate (vector_board_p_index_t * a0, vector_board_p_t const * a1, Board *  a2, vector_board_p_cmp_t a3, int a4)
{
    return vector_char_p_locate ((vector_char_p_index_t *)(void*)a0, (vector_char_p_t const *)(void*)a1, (char * )a2, (vector_char_p_cmp_t)a3, a4);
}
void vector_board_p_init_iterator (vector_board_p_t const * a0, vector_board_p_index_t * a1)
{
    vector_char_p_init_iterator ((vector_char_p_t const *)(void*)a0, (vector_char_p_index_t *)(void*)a1);
}
ERWIN_BOOL vector_board_p_next_iteration (vector_board_p_t const * a0, vector_board_p_index_t * a1, Board * * a2)
{
    return vector_char_p_next_iteration ((vector_char_p_t const *)(void*)a0, (vector_char_p_index_t *)(void*)a1, (char * *)(void*)a2);
}
ERWIN_BOOL vector_board_p_next_iteration_ptr (vector_board_p_t * a0, vector_board_p_index_t * a1, Board * * * a2)
{
    return vector_char_p_next_iteration_ptr ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t *)(void*)a1, (char * * *)(void*)a2);
}
ERWIN_BOOL vector_board_p_next_iteration_ptr_const (vector_board_p_t const * a0, vector_board_p_index_t * a1, Board * const * * a2)
{
    return vector_char_p_next_iteration_ptr_const ((vector_char_p_t const *)(void*)a0, (vector_char_p_index_t *)(void*)a1, (char * const * *)(void*)a2);
}
void vector_board_p_init_iterator_reverse (vector_board_p_t const * a0, vector_board_p_index_t * a1)
{
    vector_char_p_init_iterator_reverse ((vector_char_p_t const *)(void*)a0, (vector_char_p_index_t *)(void*)a1);
}
ERWIN_BOOL vector_board_p_next_iteration_reverse (vector_board_p_t const * a0, vector_board_p_index_t * a1, Board * * a2)
{
    return vector_char_p_next_iteration_reverse ((vector_char_p_t const *)(void*)a0, (vector_char_p_index_t *)(void*)a1, (char * *)(void*)a2);
}
ERWIN_BOOL vector_board_p_next_iteration_ptr_reverse (vector_board_p_t * a0, vector_board_p_index_t * a1, Board * * * a2)
{
    return vector_char_p_next_iteration_ptr_reverse ((vector_char_p_t *)(void*)a0, (vector_char_p_index_t *)(void*)a1, (char * * *)(void*)a2);
}
ERWIN_BOOL vector_board_p_next_iteration_ptr_const_reverse (vector_board_p_t const * a0, vector_board_p_index_t * a1, Board * const * * a2)
{
    return vector_char_p_next_iteration_ptr_const_reverse ((vector_char_p_t const *)(void*)a0, (vector_char_p_index_t *)(void*)a1, (char * const * *)(void*)a2);
}
void vector_board_p_clear (vector_board_p_t * a0)
{
    vector_char_p_clear ((vector_char_p_t *)(void*)a0);
}
void vector_board_p_clear_keep (vector_board_p_t * a0, vector_board_p_cnt_t a1)
{
    vector_char_p_clear_keep ((vector_char_p_t *)(void*)a0, (vector_char_p_cnt_t)a1);
}
void vector_board_p_clear_flags (vector_board_p_t * a0, ERWIN_BOOL a1, ERWIN_BOOL a2)
{
    vector_char_p_clear_flags ((vector_char_p_t *)(void*)a0, a1, a2);
}
void vector_board_p_clear_no_resize (vector_board_p_t * a0)
{
    vector_char_p_clear_no_resize ((vector_char_p_t *)(void*)a0);
}
vector_board_p_cnt_t vector_board_p_table_size (vector_board_p_t const * a0) 
{
    return (vector_board_p_cnt_t)vector_char_p_table_size ((vector_char_p_t const *)(void*)a0);
}
vector_board_p_index_t vector_board_p_find (vector_board_p_t const * a0, vector_board_p_index_t a1, Board *  a2) 
{
    return (vector_board_p_index_t)vector_char_p_find ((vector_char_p_t const *)(void*)a0, (vector_char_p_index_t)a1, (char * )a2);
}
vector_board_p_element_ptr_t vector_board_p_find_ptr (vector_board_p_t const * a0, vector_board_p_index_t a1, Board *  a2) 
{
    return (vector_board_p_element_ptr_t)vector_char_p_find_ptr ((vector_char_p_t const *)(void*)a0, (vector_char_p_index_t)a1, (char * )a2);
}
vector_board_p_index_t vector_board_p_rfind (vector_board_p_t const * a0, vector_board_p_index_t a1, Board *  a2) 
{
    return (vector_board_p_index_t)vector_char_p_rfind ((vector_char_p_t const *)(void*)a0, (vector_char_p_index_t)a1, (char * )a2);
}
vector_board_p_element_ptr_t vector_board_p_rfind_ptr (vector_board_p_t const * a0, vector_board_p_index_t a1, Board *  a2) 
{
    return (vector_board_p_element_ptr_t)vector_char_p_rfind_ptr ((vector_char_p_t const *)(void*)a0, (vector_char_p_index_t)a1, (char * )a2);
}
vector_board_p_index_t vector_board_p_find_raw (vector_board_p_t const * a0, vector_board_p_index_t a1, Board * const * a2, vector_board_p_cnt_t a3) 
{
    return (vector_board_p_index_t)vector_char_p_find_raw ((vector_char_p_t const *)(void*)a0, (vector_char_p_index_t)a1, (char * const *)(void*)a2, (vector_char_p_cnt_t)a3);
}
vector_board_p_index_t vector_board_p_rfind_raw (vector_board_p_t const * a0, vector_board_p_index_t a1, Board * const * a2, vector_board_p_cnt_t a3) 
{
    return (vector_board_p_index_t)vector_char_p_rfind_raw ((vector_char_p_t const *)(void*)a0, (vector_char_p_index_t)a1, (char * const *)(void*)a2, (vector_char_p_cnt_t)a3);
}
vector_board_p_index_t vector_board_p_find_if (vector_board_p_t const * a0, vector_board_p_index_t a1, vector_board_p_feature_t a2, ERWIN_BOOL a3)
{
    return (vector_board_p_index_t)vector_char_p_find_if ((vector_char_p_t const *)(void*)a0, (vector_char_p_index_t)a1, (vector_char_p_feature_t)a2, a3);
}
vector_board_p_index_t vector_board_p_rfind_if (vector_board_p_t const * a0, vector_board_p_index_t a1, vector_board_p_feature_t a2, ERWIN_BOOL a3)
{
    return (vector_board_p_index_t)vector_char_p_rfind_if ((vector_char_p_t const *)(void*)a0, (vector_char_p_index_t)a1, (vector_char_p_feature_t)a2, a3);
}
ERWIN_BOOL vector_board_p_is_equal_at (vector_board_p_t const * a0, vector_board_p_index_t a1, Board * const * a2, vector_board_p_cnt_t a3) 
{
    return vector_char_p_is_equal_at ((vector_char_p_t const *)(void*)a0, (vector_char_p_index_t)a1, (char * const *)(void*)a2, (vector_char_p_cnt_t)a3);
}
void vector_board_p_ltrim_if (vector_board_p_t * a0, vector_board_p_feature_t a1, ERWIN_BOOL a2)
{
    vector_char_p_ltrim_if ((vector_char_p_t *)(void*)a0, (vector_char_p_feature_t)a1, a2);
}
void vector_board_p_rtrim_if (vector_board_p_t * a0, vector_board_p_feature_t a1, ERWIN_BOOL a2)
{
    vector_char_p_rtrim_if ((vector_char_p_t *)(void*)a0, (vector_char_p_feature_t)a1, a2);
}
void vector_board_p_trim_if (vector_board_p_t * a0, vector_board_p_feature_t a1, ERWIN_BOOL a2)
{
    vector_char_p_trim_if ((vector_char_p_t *)(void*)a0, (vector_char_p_feature_t)a1, a2);
}
void vector_board_p_map (vector_board_p_t * a0, vector_board_p_map_t a1)
{
    vector_char_p_map ((vector_char_p_t *)(void*)a0, (vector_char_p_map_t)a1);
}
int vector_board_p_cmp (vector_board_p_t const * a0, vector_board_p_t const * a1, vector_board_p_cmp_t a2)
{
    return vector_char_p_cmp ((vector_char_p_t const *)(void*)a0, (vector_char_p_t const *)(void*)a1, (vector_char_p_cmp_t)a2);
}
hashval_t vector_board_p_hash_raw (vector_board_p_t const * a0) 
{
    return vector_char_p_hash_raw ((vector_char_p_t const *)(void*)a0);
}
hashval_t vector_board_p_hash (vector_board_p_t const * a0) 
{
    return vector_char_p_hash ((vector_char_p_t const *)(void*)a0);
}

#ifdef __cplusplus

#ifdef __cplusplus
#if !ERWIN_DEFAULT_NEW_DELETE
#endif
#endif
vector_board_p_t::vector_board_p_t (void):
    vector_char_p_t ()
{}
vector_board_p_t const & vector_board_p_t::static_zero ()
{
    return (vector_board_p_t const &)vector_char_p_t::static_zero ();
}
#if VECTOR_BOARD_P_HAVE_INT_CONSTRUCTOR
vector_board_p_t::vector_board_p_t (vector_board_p_cnt_t a0):
    vector_char_p_t ((vector_char_p_cnt_t)a0)
{}
#endif
#if VECTOR_BOARD_P_DYN_ZERO
vector_board_p_t::vector_board_p_t (Board *  a0):
    vector_char_p_t ((char * )a0)
{}
vector_board_p_t::vector_board_p_t (Board *  a0, vector_board_p_cnt_t a1):
    vector_char_p_t ((char * )a0, (vector_char_p_cnt_t)a1)
{}
#endif
vector_board_p_t::vector_board_p_t (vector_board_p_t const * a0, bool a1):
    vector_char_p_t ((vector_char_p_t const *)(void*)a0, a1)
{}
vector_board_p_t::vector_board_p_t (vector_board_p_t const * a0, vector_board_p_index_t a1, vector_board_p_cnt_t a2, bool a3):
    vector_char_p_t ((vector_char_p_t const *)(void*)a0, (vector_char_p_index_t)a1, (vector_char_p_cnt_t)a2, a3)
{}
vector_board_p_t::vector_board_p_t (Board * const * a0, bool a1):
    vector_char_p_t ((char * const *)(void*)a0, a1)
{}
vector_board_p_t::vector_board_p_t (Board * const * a0, vector_board_p_cnt_t a1, bool a2):
    vector_char_p_t ((char * const *)(void*)a0, (vector_char_p_cnt_t)a1, a2)
{}
vector_board_p_t::vector_board_p_t (bool a0, Board * * a1, vector_board_p_cnt_t a2, vector_board_p_cnt_t a3):
    vector_char_p_t (a0, (char * *)(void*)a1, (vector_char_p_cnt_t)a2, (vector_char_p_cnt_t)a3)
{}
#if VECTOR_BOARD_P_DYN_ZERO
vector_board_p_t::vector_board_p_t (bool a0, Board * * a1, vector_board_p_cnt_t a2, vector_board_p_cnt_t a3, Board *  a4):
    vector_char_p_t (a0, (char * *)(void*)a1, (vector_char_p_cnt_t)a2, (vector_char_p_cnt_t)a3, (char * )a4)
{}
#endif
vector_board_p_t::vector_board_p_t (bool a0, vector_board_p_t * a1):
    vector_char_p_t (a0, (vector_char_p_t *)(void*)a1)
{}
vector_board_p_t::vector_board_p_t (bool a0, vector_board_p_t & a1):
    vector_char_p_t (a0, (vector_char_p_t &)a1)
{}
void vector_board_p_t::_constructor (void)
{
    vector_char_p_t::_constructor ();
}
void vector_board_p_t::_destructor (void)
{
    vector_char_p_t::_destructor ();
}
#ifndef NDEBUG
void vector_board_p_t::cn () const
{
    vector_char_p_t::cn ();
}
void vector_board_p_t::cn (void const * a0) const
{
    vector_char_p_t::cn (a0);
}
#else
void vector_board_p_t::cn ()
{
    vector_char_p_t::cn ();
}
void vector_board_p_t::cn (void const * a0)
{
    vector_char_p_t::cn (a0);
}
#endif
#if !ERWIN_GLOBAL_ERRNO
int vector_board_p_t::get_errno (void) const
{
    return vector_char_p_t::get_errno ();
}
void vector_board_p_t::clear_errno (void) const
{
    vector_char_p_t::clear_errno ();
}
#else
int vector_board_p_t::get_errno (void)
{
    return vector_char_p_t::get_errno ();
}
void vector_board_p_t::clear_errno (void)
{
    vector_char_p_t::clear_errno ();
}
#endif
vector_board_p_t::vector_board_p_t (vector_board_p_t const & a0, bool a1):
    vector_char_p_t ((vector_char_p_t const &)a0, a1)
{}
vector_board_p_t::vector_board_p_t (vector_board_p_t const & a0, vector_board_p_index_t a1, vector_board_p_cnt_t a2, bool a3):
    vector_char_p_t ((vector_char_p_t const &)a0, (vector_char_p_index_t)a1, (vector_char_p_cnt_t)a2, a3)
{}
vector_board_p_t * vector_board_p_t::copy (void) const
{
    return (vector_board_p_t *)(void*)vector_char_p_t::copy ();
}
vector_board_p_t * vector_board_p_t::copy_err (int * a0) const
{
    return (vector_board_p_t *)(void*)vector_char_p_t::copy_err (a0);
}
vector_board_p_t * vector_board_p_t::copy_detach ()
{
    return (vector_board_p_t *)(void*)vector_char_p_t::copy_detach ();
}
vector_board_p_t & vector_board_p_t::xchg (vector_board_p_t * a0)
{
    return (vector_board_p_t &)vector_char_p_t::xchg ((vector_char_p_t *)(void*)a0);
}
vector_board_p_t & vector_board_p_t::xchg (vector_board_p_t & a0)
{
    return (vector_board_p_t &)vector_char_p_t::xchg ((vector_char_p_t &)a0);
}
vector_board_p_t * vector_board_p_t::subvector (vector_board_p_index_t a0, vector_board_p_cnt_t a1) const
{
    return (vector_board_p_t *)(void*)vector_char_p_t::subvector ((vector_char_p_index_t)a0, (vector_char_p_cnt_t)a1);
}
vector_board_p_t * vector_board_p_t::subvector (vector_board_p_index_t a0, vector_board_p_cnt_t a1, bool a2) const
{
    return (vector_board_p_t *)(void*)vector_char_p_t::subvector ((vector_char_p_index_t)a0, (vector_char_p_cnt_t)a1, a2);
}
vector_board_p_t & vector_board_p_t::operator= (vector_board_p_t const & a0)
{
    return (vector_board_p_t &)vector_char_p_t::operator= ((vector_char_p_t const &)a0);
}
vector_board_p_t & vector_board_p_t::operator= (vector_board_p_t const * a0)
{
    return (vector_board_p_t &)vector_char_p_t::operator= ((vector_char_p_t const *)(void*)a0);
}
vector_board_p_t & vector_board_p_t::detach (void)
{
    return (vector_board_p_t &)vector_char_p_t::detach ();
}
vector_board_p_t & vector_board_p_t::detach_as_is (void)
{
    return (vector_board_p_t &)vector_char_p_t::detach_as_is ();
}
vector_board_p_t::operator vector_board_p_t const * () const
{
    return (vector_board_p_t const *)(void*)vector_char_p_t::operator vector_char_p_t const * ();
}
vector_board_p_t::operator vector_board_p_t * ()
{
    return (vector_board_p_t *)(void*)vector_char_p_t::operator vector_char_p_t * ();
}
#if VECTOR_BOARD_P_MANY_CASTS != 0
vector_board_p_t::operator vector_board_p_element_ptr_t () const
{
    return (vector_board_p_element_ptr_t)vector_char_p_t::operator vector_char_p_element_ptr_t ();
}
vector_board_p_t::operator bool () const
{
    return vector_char_p_t::operator bool ();
}
#endif
#if VECTOR_BOARD_P_POSITION_POINTER
vector_board_p_index_t * vector_board_p_t::pos_ptr ()
{
    return (vector_board_p_index_t *)(void*)vector_char_p_t::pos_ptr ();
}
vector_board_p_index_t & vector_board_p_t::pos_ref ()
{
    return (vector_board_p_index_t &)vector_char_p_t::pos_ref ();
}
vector_board_p_index_t vector_board_p_t::pos ()
{
    return (vector_board_p_index_t)vector_char_p_t::pos ();
}
void vector_board_p_t::set_pos (vector_board_p_index_t a0)
{
    vector_char_p_t::set_pos ((vector_char_p_index_t)a0);
}
#endif
Board *  vector_board_p_t::nth (vector_board_p_index_t a0) const
{
    return (Board * )vector_char_p_t::nth ((vector_char_p_index_t)a0);
}
Board *  vector_board_p_t::nth_char (vector_board_p_index_t a0) const
{
    return (Board * )vector_char_p_t::nth_char ((vector_char_p_index_t)a0);
}
vector_board_p_element_ptr_t vector_board_p_t::nth_ptr_check (vector_board_p_index_t a0)
{
    return (vector_board_p_element_ptr_t)vector_char_p_t::nth_ptr_check ((vector_char_p_index_t)a0);
}
Board * const * vector_board_p_t::nth_ptr_check (vector_board_p_index_t a0) const
{
    return (Board * const *)(void*)vector_char_p_t::nth_ptr_check ((vector_char_p_index_t)a0);
}
vector_board_p_element_ptr_t vector_board_p_t::nth_ptr_char (vector_board_p_index_t a0)
{
    return (vector_board_p_element_ptr_t)vector_char_p_t::nth_ptr_char ((vector_char_p_index_t)a0);
}
Board * const * vector_board_p_t::nth_ptr_char (vector_board_p_index_t a0) const
{
    return (Board * const *)(void*)vector_char_p_t::nth_ptr_char ((vector_char_p_index_t)a0);
}
vector_board_p_element_ptr_t vector_board_p_t::nth_ptr (vector_board_p_index_t a0)
{
    return (vector_board_p_element_ptr_t)vector_char_p_t::nth_ptr ((vector_char_p_index_t)a0);
}
Board * const * vector_board_p_t::nth_ptr (vector_board_p_index_t a0) const
{
    return (Board * const *)(void*)vector_char_p_t::nth_ptr ((vector_char_p_index_t)a0);
}
vector_board_p_element_ref_t vector_board_p_t::nth_ref (vector_board_p_index_t a0)
{
    return (vector_board_p_element_ref_t)vector_char_p_t::nth_ref ((vector_char_p_index_t)a0);
}
Board * const & vector_board_p_t::nth_ref (vector_board_p_index_t a0) const
{
    return (Board * const &)vector_char_p_t::nth_ref ((vector_char_p_index_t)a0);
}
vector_board_p_element_ref_t vector_board_p_t::nth_ref_check (vector_board_p_index_t a0)
{
    return (vector_board_p_element_ref_t)vector_char_p_t::nth_ref_check ((vector_char_p_index_t)a0);
}
Board * const & vector_board_p_t::nth_ref_check (vector_board_p_index_t a0) const
{
    return (Board * const &)vector_char_p_t::nth_ref_check ((vector_char_p_index_t)a0);
}
vector_board_p_element_ref_t vector_board_p_t::nth_ref_char (vector_board_p_index_t a0)
{
    return (vector_board_p_element_ref_t)vector_char_p_t::nth_ref_char ((vector_char_p_index_t)a0);
}
Board * const & vector_board_p_t::nth_ref_char (vector_board_p_index_t a0) const
{
    return (Board * const &)vector_char_p_t::nth_ref_char ((vector_char_p_index_t)a0);
}
vector_board_p_element_ref_t vector_board_p_t::operator[] (vector_board_p_index_t a0)
{
    return (vector_board_p_element_ref_t)vector_char_p_t::operator[] ((vector_char_p_index_t)a0);
}
Board *  vector_board_p_t::operator[] (vector_board_p_index_t a0) const
{
    return (Board * )vector_char_p_t::operator[] ((vector_char_p_index_t)a0);
}
Board *  vector_board_p_t::first (void) const
{
    return (Board * )vector_char_p_t::first ();
}
vector_board_p_element_ptr_t vector_board_p_t::first_ptr ()
{
    return (vector_board_p_element_ptr_t)vector_char_p_t::first_ptr ();
}
vector_board_p_element_ref_t vector_board_p_t::first_ref ()
{
    return (vector_board_p_element_ref_t)vector_char_p_t::first_ref ();
}
Board *  vector_board_p_t::last (void) const
{
    return (Board * )vector_char_p_t::last ();
}
vector_board_p_element_ptr_t vector_board_p_t::last_ptr ()
{
    return (vector_board_p_element_ptr_t)vector_char_p_t::last_ptr ();
}
vector_board_p_element_ref_t vector_board_p_t::last_ref ()
{
    return (vector_board_p_element_ref_t)vector_char_p_t::last_ref ();
}
Board * vector_board_p_t::modify (vector_board_p_index_t a0, Board *  a1)
{
    return (Board *)vector_char_p_t::modify ((vector_char_p_index_t)a0, (char * )a1);
}
vector_board_p_t & vector_board_p_t::reverse (void)
{
    return (vector_board_p_t &)vector_char_p_t::reverse ();
}
Board * vector_board_p_t::last_chop1 (void)
{
    return (Board *)vector_char_p_t::last_chop1 ();
}
Board * vector_board_p_t::first_swap_chop1 (void)
{
    return (Board *)vector_char_p_t::first_swap_chop1 ();
}
vector_board_p_t & vector_board_p_t::set (vector_board_p_index_t a0, Board *  a1)
{
    return (vector_board_p_t &)vector_char_p_t::set ((vector_char_p_index_t)a0, (char * )a1);
}
vector_board_p_t & vector_board_p_t::swap_erase (vector_board_p_index_t a0, vector_board_p_cnt_t a1)
{
    return (vector_board_p_t &)vector_char_p_t::swap_erase ((vector_char_p_index_t)a0, (vector_char_p_cnt_t)a1);
}
vector_board_p_t & vector_board_p_t::swap_erase (vector_board_p_index_t a0, vector_board_p_cnt_t a1, bool a2, bool a3)
{
    return (vector_board_p_t &)vector_char_p_t::swap_erase ((vector_char_p_index_t)a0, (vector_char_p_cnt_t)a1, a2, a3);
}
vector_board_p_t & vector_board_p_t::erase (vector_board_p_index_t a0, vector_board_p_cnt_t a1)
{
    return (vector_board_p_t &)vector_char_p_t::erase ((vector_char_p_index_t)a0, (vector_char_p_cnt_t)a1);
}
vector_board_p_cnt_t vector_board_p_t::erase_zero ()
{
    return (vector_board_p_cnt_t)vector_char_p_t::erase_zero ();
}
vector_board_p_t & vector_board_p_t::erase (vector_board_p_index_t a0, vector_board_p_cnt_t a1, bool a2, bool a3)
{
    return (vector_board_p_t &)vector_char_p_t::erase ((vector_char_p_index_t)a0, (vector_char_p_cnt_t)a1, a2, a3);
}
vector_board_p_cnt_t vector_board_p_t::erase_if (vector_board_p_feature_t a0, bool a1, bool a2, bool a3)
{
    return (vector_board_p_cnt_t)vector_char_p_t::erase_if ((vector_char_p_feature_t)a0, a1, a2, a3);
}
vector_board_p_cnt_t vector_board_p_t::erase_if_not (vector_board_p_feature_t a0, bool a1, bool a2, bool a3)
{
    return (vector_board_p_cnt_t)vector_char_p_t::erase_if_not ((vector_char_p_feature_t)a0, a1, a2, a3);
}
vector_board_p_cnt_t vector_board_p_t::erase_equals (vector_board_p_cmp_t a0, vector_board_p_combine_t a1)
{
    return (vector_board_p_cnt_t)vector_char_p_t::erase_equals ((vector_char_p_cmp_t)a0, (vector_char_p_combine_t)a1);
}
vector_board_p_t & vector_board_p_t::swap_chop (vector_board_p_cnt_t a0)
{
    return (vector_board_p_t &)vector_char_p_t::swap_chop ((vector_char_p_cnt_t)a0);
}
vector_board_p_t & vector_board_p_t::swap_chop (bool a0, bool a1)
{
    return (vector_board_p_t &)vector_char_p_t::swap_chop (a0, a1);
}
vector_board_p_t & vector_board_p_t::swap_chop (vector_board_p_cnt_t a0, bool a1, bool a2)
{
    return (vector_board_p_t &)vector_char_p_t::swap_chop ((vector_char_p_cnt_t)a0, a1, a2);
}
vector_board_p_t & vector_board_p_t::chop (vector_board_p_cnt_t a0)
{
    return (vector_board_p_t &)vector_char_p_t::chop ((vector_char_p_cnt_t)a0);
}
vector_board_p_t & vector_board_p_t::chop (bool a0, bool a1)
{
    return (vector_board_p_t &)vector_char_p_t::chop (a0, a1);
}
vector_board_p_t & vector_board_p_t::chop (vector_board_p_cnt_t a0, bool a1, bool a2)
{
    return (vector_board_p_t &)vector_char_p_t::chop ((vector_char_p_cnt_t)a0, a1, a2);
}
vector_board_p_t & vector_board_p_t::prepend (Board *  a0)
{
    return (vector_board_p_t &)vector_char_p_t::prepend ((char * )a0);
}
vector_board_p_t & vector_board_p_t::prepend_raw (Board * const * a0, vector_board_p_cnt_t a1)
{
    return (vector_board_p_t &)vector_char_p_t::prepend_raw ((char * const *)(void*)a0, (vector_char_p_cnt_t)a1);
}
vector_board_p_t & vector_board_p_t::prepend_no_copy (Board * const * a0, vector_board_p_cnt_t a1)
{
    return (vector_board_p_t &)vector_char_p_t::prepend_no_copy ((char * const *)(void*)a0, (vector_char_p_cnt_t)a1);
}
vector_board_p_t & vector_board_p_t::prepend_vector (vector_board_p_t const * a0)
{
    return (vector_board_p_t &)vector_char_p_t::prepend_vector ((vector_char_p_t const *)(void*)a0);
}
vector_board_p_t & vector_board_p_t::prepend_vector (vector_board_p_t const & a0)
{
    return (vector_board_p_t &)vector_char_p_t::prepend_vector ((vector_char_p_t const &)a0);
}
vector_board_p_t & vector_board_p_t::prepend_string (Board * const * a0)
{
    return (vector_board_p_t &)vector_char_p_t::prepend_string ((char * const *)(void*)a0);
}
vector_board_p_t & vector_board_p_t::append (Board *  a0)
{
    return (vector_board_p_t &)vector_char_p_t::append ((char * )a0);
}
vector_board_p_t & vector_board_p_t::append_raw (Board * const * a0, vector_board_p_cnt_t a1)
{
    return (vector_board_p_t &)vector_char_p_t::append_raw ((char * const *)(void*)a0, (vector_char_p_cnt_t)a1);
}
vector_board_p_t & vector_board_p_t::append_no_copy (Board * const * a0, vector_board_p_cnt_t a1)
{
    return (vector_board_p_t &)vector_char_p_t::append_no_copy ((char * const *)(void*)a0, (vector_char_p_cnt_t)a1);
}
vector_board_p_t & vector_board_p_t::append_vector (vector_board_p_t const * a0)
{
    return (vector_board_p_t &)vector_char_p_t::append_vector ((vector_char_p_t const *)(void*)a0);
}
vector_board_p_t & vector_board_p_t::append_vector (vector_board_p_t const & a0)
{
    return (vector_board_p_t &)vector_char_p_t::append_vector ((vector_char_p_t const &)a0);
}
vector_board_p_t & vector_board_p_t::append_string (Board * const * a0)
{
    return (vector_board_p_t &)vector_char_p_t::append_string ((char * const *)(void*)a0);
}
vector_board_p_t & vector_board_p_t::append_subvector (vector_board_p_t const & a0, vector_board_p_index_t a1, vector_board_p_cnt_t a2, ERWIN_BOOL a3)
{
    return (vector_board_p_t &)vector_char_p_t::append_subvector ((vector_char_p_t const &)a0, (vector_char_p_index_t)a1, (vector_char_p_cnt_t)a2, a3);
}
vector_board_p_t & vector_board_p_t::append_subvector (vector_board_p_t const * a0, vector_board_p_index_t a1, vector_board_p_cnt_t a2, ERWIN_BOOL a3)
{
    return (vector_board_p_t &)vector_char_p_t::append_subvector ((vector_char_p_t const *)(void*)a0, (vector_char_p_index_t)a1, (vector_char_p_cnt_t)a2, a3);
}
#if VECTOR_BOARD_P_DIRECT_RECURSION == 0
vector_board_p_t & vector_board_p_t::prepend (vector_board_p_t const * a0)
{
    return (vector_board_p_t &)vector_char_p_t::prepend ((vector_char_p_t const *)(void*)a0);
}
vector_board_p_t & vector_board_p_t::prepend (vector_board_p_t const & a0)
{
    return (vector_board_p_t &)vector_char_p_t::prepend ((vector_char_p_t const &)a0);
}
vector_board_p_t & vector_board_p_t::prepend (Board * const * a0)
{
    return (vector_board_p_t &)vector_char_p_t::prepend ((char * const *)(void*)a0);
}
vector_board_p_t & vector_board_p_t::append (vector_board_p_t const * a0)
{
    return (vector_board_p_t &)vector_char_p_t::append ((vector_char_p_t const *)(void*)a0);
}
vector_board_p_t & vector_board_p_t::append (vector_board_p_t const & a0)
{
    return (vector_board_p_t &)vector_char_p_t::append ((vector_char_p_t const &)a0);
}
vector_board_p_t & vector_board_p_t::append (Board * const * a0)
{
    return (vector_board_p_t &)vector_char_p_t::append ((char * const *)(void*)a0);
}
vector_board_p_t & vector_board_p_t::operator<< (Board * const * a0)
{
    return (vector_board_p_t &)vector_char_p_t::operator<< ((char * const *)(void*)a0);
}
#endif /* VECTOR_BOARD_P_DIRECT_RECURSION == 0*/
vector_board_p_t & vector_board_p_t::operator<< (Board *  a0)
{
    return (vector_board_p_t &)vector_char_p_t::operator<< ((char * )a0);
}
vector_board_p_t & vector_board_p_t::operator<< (vector_board_p_t const * a0)
{
    return (vector_board_p_t &)vector_char_p_t::operator<< ((vector_char_p_t const *)(void*)a0);
}
vector_board_p_t & vector_board_p_t::operator<< (vector_board_p_t const & a0)
{
    return (vector_board_p_t &)vector_char_p_t::operator<< ((vector_char_p_t const &)a0);
}
vector_board_p_index_t vector_board_p_t::find (Board *  a0) const
{
    return (vector_board_p_index_t)vector_char_p_t::find ((char * )a0);
}
vector_board_p_index_t vector_board_p_t::find_raw (Board * const * a0, vector_board_p_cnt_t a1) const
{
    return (vector_board_p_index_t)vector_char_p_t::find_raw ((char * const *)(void*)a0, (vector_char_p_cnt_t)a1);
}
vector_board_p_index_t vector_board_p_t::find_string (Board * const * a0) const
{
    return (vector_board_p_index_t)vector_char_p_t::find_string ((char * const *)(void*)a0);
}
vector_board_p_index_t vector_board_p_t::find_vector (vector_board_p_t const & a0) const
{
    return (vector_board_p_index_t)vector_char_p_t::find_vector ((vector_char_p_t const &)a0);
}
vector_board_p_index_t vector_board_p_t::find_vector (vector_board_p_t const * a0) const
{
    return (vector_board_p_index_t)vector_char_p_t::find_vector ((vector_char_p_t const *)(void*)a0);
}
#if VECTOR_BOARD_P_DIRECT_RECURSION == 0
vector_board_p_index_t vector_board_p_t::find (Board * const * a0, vector_board_p_cnt_t a1) const
{
    return (vector_board_p_index_t)vector_char_p_t::find ((char * const *)(void*)a0, (vector_char_p_cnt_t)a1);
}
vector_board_p_index_t vector_board_p_t::find (Board * const * a0) const
{
    return (vector_board_p_index_t)vector_char_p_t::find ((char * const *)(void*)a0);
}
vector_board_p_index_t vector_board_p_t::find (vector_board_p_t const & a0) const
{
    return (vector_board_p_index_t)vector_char_p_t::find ((vector_char_p_t const &)a0);
}
vector_board_p_index_t vector_board_p_t::find (vector_board_p_t const * a0) const
{
    return (vector_board_p_index_t)vector_char_p_t::find ((vector_char_p_t const *)(void*)a0);
}
#endif
vector_board_p_index_t vector_board_p_t::find (vector_board_p_index_t a0, Board *  a1) const
{
    return (vector_board_p_index_t)vector_char_p_t::find ((vector_char_p_index_t)a0, (char * )a1);
}
vector_board_p_index_t vector_board_p_t::find_raw (vector_board_p_index_t a0, Board * const * a1, vector_board_p_cnt_t a2) const
{
    return (vector_board_p_index_t)vector_char_p_t::find_raw ((vector_char_p_index_t)a0, (char * const *)(void*)a1, (vector_char_p_cnt_t)a2);
}
vector_board_p_index_t vector_board_p_t::find_string (vector_board_p_index_t a0, Board * const * a1) const
{
    return (vector_board_p_index_t)vector_char_p_t::find_string ((vector_char_p_index_t)a0, (char * const *)(void*)a1);
}
vector_board_p_index_t vector_board_p_t::find_vector (vector_board_p_index_t a0, vector_board_p_t const & a1) const
{
    return (vector_board_p_index_t)vector_char_p_t::find_vector ((vector_char_p_index_t)a0, (vector_char_p_t const &)a1);
}
vector_board_p_index_t vector_board_p_t::find_vector (vector_board_p_index_t a0, vector_board_p_t const * a1) const
{
    return (vector_board_p_index_t)vector_char_p_t::find_vector ((vector_char_p_index_t)a0, (vector_char_p_t const *)(void*)a1);
}
#if VECTOR_BOARD_P_DIRECT_RECURSION == 0
vector_board_p_index_t vector_board_p_t::find (vector_board_p_index_t a0, Board * const * a1, vector_board_p_cnt_t a2) const
{
    return (vector_board_p_index_t)vector_char_p_t::find ((vector_char_p_index_t)a0, (char * const *)(void*)a1, (vector_char_p_cnt_t)a2);
}
vector_board_p_index_t vector_board_p_t::find (vector_board_p_index_t a0, Board * const * a1) const
{
    return (vector_board_p_index_t)vector_char_p_t::find ((vector_char_p_index_t)a0, (char * const *)(void*)a1);
}
vector_board_p_index_t vector_board_p_t::find (vector_board_p_index_t a0, vector_board_p_t const & a1) const
{
    return (vector_board_p_index_t)vector_char_p_t::find ((vector_char_p_index_t)a0, (vector_char_p_t const &)a1);
}
vector_board_p_index_t vector_board_p_t::find (vector_board_p_index_t a0, vector_board_p_t const * a1) const
{
    return (vector_board_p_index_t)vector_char_p_t::find ((vector_char_p_index_t)a0, (vector_char_p_t const *)(void*)a1);
}
#endif
vector_board_p_index_t vector_board_p_t::rfind (Board *  a0) const
{
    return (vector_board_p_index_t)vector_char_p_t::rfind ((char * )a0);
}
vector_board_p_index_t vector_board_p_t::rfind_raw (Board * const * a0, vector_board_p_cnt_t a1) const
{
    return (vector_board_p_index_t)vector_char_p_t::rfind_raw ((char * const *)(void*)a0, (vector_char_p_cnt_t)a1);
}
vector_board_p_index_t vector_board_p_t::rfind_string (Board * const * a0) const
{
    return (vector_board_p_index_t)vector_char_p_t::rfind_string ((char * const *)(void*)a0);
}
vector_board_p_index_t vector_board_p_t::rfind_vector (vector_board_p_t const & a0) const
{
    return (vector_board_p_index_t)vector_char_p_t::rfind_vector ((vector_char_p_t const &)a0);
}
vector_board_p_index_t vector_board_p_t::rfind_vector (vector_board_p_t const * a0) const
{
    return (vector_board_p_index_t)vector_char_p_t::rfind_vector ((vector_char_p_t const *)(void*)a0);
}
#if VECTOR_BOARD_P_DIRECT_RECURSION == 0
vector_board_p_index_t vector_board_p_t::rfind (Board * const * a0, vector_board_p_cnt_t a1) const
{
    return (vector_board_p_index_t)vector_char_p_t::rfind ((char * const *)(void*)a0, (vector_char_p_cnt_t)a1);
}
vector_board_p_index_t vector_board_p_t::rfind (Board * const * a0) const
{
    return (vector_board_p_index_t)vector_char_p_t::rfind ((char * const *)(void*)a0);
}
vector_board_p_index_t vector_board_p_t::rfind (vector_board_p_t const & a0) const
{
    return (vector_board_p_index_t)vector_char_p_t::rfind ((vector_char_p_t const &)a0);
}
vector_board_p_index_t vector_board_p_t::rfind (vector_board_p_t const * a0) const
{
    return (vector_board_p_index_t)vector_char_p_t::rfind ((vector_char_p_t const *)(void*)a0);
}
#endif
vector_board_p_index_t vector_board_p_t::rfind (vector_board_p_index_t a0, Board *  a1) const
{
    return (vector_board_p_index_t)vector_char_p_t::rfind ((vector_char_p_index_t)a0, (char * )a1);
}
vector_board_p_index_t vector_board_p_t::rfind_raw (vector_board_p_index_t a0, Board * const * a1, vector_board_p_cnt_t a2) const
{
    return (vector_board_p_index_t)vector_char_p_t::rfind_raw ((vector_char_p_index_t)a0, (char * const *)(void*)a1, (vector_char_p_cnt_t)a2);
}
vector_board_p_index_t vector_board_p_t::rfind_string (vector_board_p_index_t a0, Board * const * a1) const
{
    return (vector_board_p_index_t)vector_char_p_t::rfind_string ((vector_char_p_index_t)a0, (char * const *)(void*)a1);
}
vector_board_p_index_t vector_board_p_t::rfind_vector (vector_board_p_index_t a0, vector_board_p_t const & a1) const
{
    return (vector_board_p_index_t)vector_char_p_t::rfind_vector ((vector_char_p_index_t)a0, (vector_char_p_t const &)a1);
}
vector_board_p_index_t vector_board_p_t::rfind_vector (vector_board_p_index_t a0, vector_board_p_t const * a1) const
{
    return (vector_board_p_index_t)vector_char_p_t::rfind_vector ((vector_char_p_index_t)a0, (vector_char_p_t const *)(void*)a1);
}
#if VECTOR_BOARD_P_DIRECT_RECURSION == 0
vector_board_p_index_t vector_board_p_t::rfind (vector_board_p_index_t a0, Board * const * a1, vector_board_p_cnt_t a2) const
{
    return (vector_board_p_index_t)vector_char_p_t::rfind ((vector_char_p_index_t)a0, (char * const *)(void*)a1, (vector_char_p_cnt_t)a2);
}
vector_board_p_index_t vector_board_p_t::rfind (vector_board_p_index_t a0, Board * const * a1) const
{
    return (vector_board_p_index_t)vector_char_p_t::rfind ((vector_char_p_index_t)a0, (char * const *)(void*)a1);
}
vector_board_p_index_t vector_board_p_t::rfind (vector_board_p_index_t a0, vector_board_p_t const & a1) const
{
    return (vector_board_p_index_t)vector_char_p_t::rfind ((vector_char_p_index_t)a0, (vector_char_p_t const &)a1);
}
vector_board_p_index_t vector_board_p_t::rfind (vector_board_p_index_t a0, vector_board_p_t const * a1) const
{
    return (vector_board_p_index_t)vector_char_p_t::rfind ((vector_char_p_index_t)a0, (vector_char_p_t const *)(void*)a1);
}
#endif
bool vector_board_p_t::is_equal_at_raw (vector_board_p_index_t a0, Board * const * a1, vector_board_p_cnt_t a2) const
{
    return vector_char_p_t::is_equal_at_raw ((vector_char_p_index_t)a0, (char * const *)(void*)a1, (vector_char_p_cnt_t)a2);
}
bool vector_board_p_t::is_equal_at_string (vector_board_p_index_t a0, Board * const * a1) const
{
    return vector_char_p_t::is_equal_at_string ((vector_char_p_index_t)a0, (char * const *)(void*)a1);
}
bool vector_board_p_t::is_equal_at_vector (vector_board_p_index_t a0, vector_board_p_t const & a1) const
{
    return vector_char_p_t::is_equal_at_vector ((vector_char_p_index_t)a0, (vector_char_p_t const &)a1);
}
bool vector_board_p_t::is_equal_at_vector (vector_board_p_index_t a0, vector_board_p_t const * a1) const
{
    return vector_char_p_t::is_equal_at_vector ((vector_char_p_index_t)a0, (vector_char_p_t const *)(void*)a1);
}
#if VECTOR_BOARD_P_DIRECT_RECURSION == 0
bool vector_board_p_t::is_equal_at (vector_board_p_index_t a0, Board * const * a1, vector_board_p_cnt_t a2) const
{
    return vector_char_p_t::is_equal_at ((vector_char_p_index_t)a0, (char * const *)(void*)a1, (vector_char_p_cnt_t)a2);
}
bool vector_board_p_t::is_equal_at (vector_board_p_index_t a0, Board * const * a1) const
{
    return vector_char_p_t::is_equal_at ((vector_char_p_index_t)a0, (char * const *)(void*)a1);
}
bool vector_board_p_t::is_equal_at (vector_board_p_index_t a0, vector_board_p_t const & a1) const
{
    return vector_char_p_t::is_equal_at ((vector_char_p_index_t)a0, (vector_char_p_t const &)a1);
}
bool vector_board_p_t::is_equal_at (vector_board_p_index_t a0, vector_board_p_t const * a1) const
{
    return vector_char_p_t::is_equal_at ((vector_char_p_index_t)a0, (vector_char_p_t const *)(void*)a1);
}
#endif
vector_board_p_index_t vector_board_p_t::find_if (vector_board_p_feature_t a0, bool a1)
{
    return (vector_board_p_index_t)vector_char_p_t::find_if ((vector_char_p_feature_t)a0, a1);
}
vector_board_p_index_t vector_board_p_t::find_if (vector_board_p_index_t a0, vector_board_p_feature_t a1, bool a2)
{
    return (vector_board_p_index_t)vector_char_p_t::find_if ((vector_char_p_index_t)a0, (vector_char_p_feature_t)a1, a2);
}
vector_board_p_index_t vector_board_p_t::rfind_if (vector_board_p_feature_t a0, bool a1)
{
    return (vector_board_p_index_t)vector_char_p_t::rfind_if ((vector_char_p_feature_t)a0, a1);
}
vector_board_p_index_t vector_board_p_t::rfind_if (vector_board_p_index_t a0, vector_board_p_feature_t a1, bool a2)
{
    return (vector_board_p_index_t)vector_char_p_t::rfind_if ((vector_char_p_index_t)a0, (vector_char_p_feature_t)a1, a2);
}
vector_board_p_index_t vector_board_p_t::find_if_not (vector_board_p_feature_t a0, bool a1)
{
    return (vector_board_p_index_t)vector_char_p_t::find_if_not ((vector_char_p_feature_t)a0, a1);
}
vector_board_p_index_t vector_board_p_t::find_if_not (vector_board_p_index_t a0, vector_board_p_feature_t a1, bool a2)
{
    return (vector_board_p_index_t)vector_char_p_t::find_if_not ((vector_char_p_index_t)a0, (vector_char_p_feature_t)a1, a2);
}
vector_board_p_index_t vector_board_p_t::rfind_if_not (vector_board_p_feature_t a0, bool a1)
{
    return (vector_board_p_index_t)vector_char_p_t::rfind_if_not ((vector_char_p_feature_t)a0, a1);
}
vector_board_p_index_t vector_board_p_t::rfind_if_not (vector_board_p_index_t a0, vector_board_p_feature_t a1, bool a2)
{
    return (vector_board_p_index_t)vector_char_p_t::rfind_if_not ((vector_char_p_index_t)a0, (vector_char_p_feature_t)a1, a2);
}
vector_board_p_t & vector_board_p_t::ltrim_if (vector_board_p_feature_t a0, bool a1)
{
    return (vector_board_p_t &)vector_char_p_t::ltrim_if ((vector_char_p_feature_t)a0, a1);
}
vector_board_p_t & vector_board_p_t::ltrim_if_not (vector_board_p_feature_t a0, bool a1)
{
    return (vector_board_p_t &)vector_char_p_t::ltrim_if_not ((vector_char_p_feature_t)a0, a1);
}
vector_board_p_t & vector_board_p_t::rtrim_if (vector_board_p_feature_t a0, bool a1)
{
    return (vector_board_p_t &)vector_char_p_t::rtrim_if ((vector_char_p_feature_t)a0, a1);
}
vector_board_p_t & vector_board_p_t::rtrim_if_not (vector_board_p_feature_t a0, bool a1)
{
    return (vector_board_p_t &)vector_char_p_t::rtrim_if_not ((vector_char_p_feature_t)a0, a1);
}
vector_board_p_t & vector_board_p_t::trim_if (vector_board_p_feature_t a0, bool a1)
{
    return (vector_board_p_t &)vector_char_p_t::trim_if ((vector_char_p_feature_t)a0, a1);
}
vector_board_p_t & vector_board_p_t::trim_if_not (vector_board_p_feature_t a0, bool a1)
{
    return (vector_board_p_t &)vector_char_p_t::trim_if_not ((vector_char_p_feature_t)a0, a1);
}
vector_board_p_t & vector_board_p_t::map (vector_board_p_map_t a0)
{
    return (vector_board_p_t &)vector_char_p_t::map ((vector_char_p_map_t)a0);
}
vector_board_p_t & vector_board_p_t::make_gap (vector_board_p_index_t a0, vector_board_p_cnt_t a1)
{
    return (vector_board_p_t &)vector_char_p_t::make_gap ((vector_char_p_index_t)a0, (vector_char_p_cnt_t)a1);
}
vector_board_p_t & vector_board_p_t::make_gap (vector_board_p_index_t a0, Board *  a1, vector_board_p_cnt_t a2)
{
    return (vector_board_p_t &)vector_char_p_t::make_gap ((vector_char_p_index_t)a0, (char * )a1, (vector_char_p_cnt_t)a2);
}
vector_board_p_t & vector_board_p_t::make_gap_with (vector_board_p_index_t a0, Board *  a1, vector_board_p_cnt_t a2)
{
    return (vector_board_p_t &)vector_char_p_t::make_gap_with ((vector_char_p_index_t)a0, (char * )a1, (vector_char_p_cnt_t)a2);
}
Board *  vector_board_p_t::zero (void) const
{
    return (Board * )vector_char_p_t::zero ();
}
vector_board_p_t & vector_board_p_t::overwrite (vector_board_p_index_t a0, vector_board_p_t const * a1, vector_board_p_index_t a2, vector_board_p_cnt_t a3)
{
    return (vector_board_p_t &)vector_char_p_t::overwrite ((vector_char_p_index_t)a0, (vector_char_p_t const *)(void*)a1, (vector_char_p_index_t)a2, (vector_char_p_cnt_t)a3);
}
vector_board_p_t & vector_board_p_t::overwrite (vector_board_p_index_t a0, vector_board_p_t const & a1, vector_board_p_index_t a2, vector_board_p_cnt_t a3)
{
    return (vector_board_p_t &)vector_char_p_t::overwrite ((vector_char_p_index_t)a0, (vector_char_p_t const &)a1, (vector_char_p_index_t)a2, (vector_char_p_cnt_t)a3);
}
vector_board_p_t & vector_board_p_t::overwrite_raw (vector_board_p_index_t a0, Board * const * a1, vector_board_p_cnt_t a2)
{
    return (vector_board_p_t &)vector_char_p_t::overwrite_raw ((vector_char_p_index_t)a0, (char * const *)(void*)a1, (vector_char_p_cnt_t)a2);
}
vector_board_p_t & vector_board_p_t::overwrite_string (vector_board_p_index_t a0, Board * const * a1)
{
    return (vector_board_p_t &)vector_char_p_t::overwrite_string ((vector_char_p_index_t)a0, (char * const *)(void*)a1);
}
vector_board_p_t & vector_board_p_t::overwrite_vector (vector_board_p_index_t a0, vector_board_p_t const * a1)
{
    return (vector_board_p_t &)vector_char_p_t::overwrite_vector ((vector_char_p_index_t)a0, (vector_char_p_t const *)(void*)a1);
}
vector_board_p_t & vector_board_p_t::overwrite_vector (vector_board_p_index_t a0, vector_board_p_t const & a1)
{
    return (vector_board_p_t &)vector_char_p_t::overwrite_vector ((vector_char_p_index_t)a0, (vector_char_p_t const &)a1);
}
vector_board_p_t & vector_board_p_t::overwrite_flags (vector_board_p_index_t a0, Board * const * a1, vector_board_p_cnt_t a2, bool a3, bool a4)
{
    return (vector_board_p_t &)vector_char_p_t::overwrite_flags ((vector_char_p_index_t)a0, (char * const *)(void*)a1, (vector_char_p_cnt_t)a2, a3, a4);
}
#if VECTOR_BOARD_P_DIRECT_RECURSION == 0
vector_board_p_t & vector_board_p_t::overwrite (vector_board_p_index_t a0, Board * const * a1, vector_board_p_cnt_t a2)
{
    return (vector_board_p_t &)vector_char_p_t::overwrite ((vector_char_p_index_t)a0, (char * const *)(void*)a1, (vector_char_p_cnt_t)a2);
}
vector_board_p_t & vector_board_p_t::overwrite (vector_board_p_index_t a0, Board * const * a1)
{
    return (vector_board_p_t &)vector_char_p_t::overwrite ((vector_char_p_index_t)a0, (char * const *)(void*)a1);
}
vector_board_p_t & vector_board_p_t::overwrite (vector_board_p_index_t a0, vector_board_p_t const * a1)
{
    return (vector_board_p_t &)vector_char_p_t::overwrite ((vector_char_p_index_t)a0, (vector_char_p_t const *)(void*)a1);
}
vector_board_p_t & vector_board_p_t::overwrite (vector_board_p_index_t a0, vector_board_p_t const & a1)
{
    return (vector_board_p_t &)vector_char_p_t::overwrite ((vector_char_p_index_t)a0, (vector_char_p_t const &)a1);
}
#endif
vector_board_p_t & vector_board_p_t::insert (vector_board_p_index_t a0, Board *  a1)
{
    return (vector_board_p_t &)vector_char_p_t::insert ((vector_char_p_index_t)a0, (char * )a1);
}
vector_board_p_t & vector_board_p_t::insert_raw (vector_board_p_index_t a0, Board * const * a1, vector_board_p_cnt_t a2)
{
    return (vector_board_p_t &)vector_char_p_t::insert_raw ((vector_char_p_index_t)a0, (char * const *)(void*)a1, (vector_char_p_cnt_t)a2);
}
vector_board_p_t & vector_board_p_t::insert_no_copy (vector_board_p_index_t a0, Board * const * a1, vector_board_p_cnt_t a2)
{
    return (vector_board_p_t &)vector_char_p_t::insert_no_copy ((vector_char_p_index_t)a0, (char * const *)(void*)a1, (vector_char_p_cnt_t)a2);
}
vector_board_p_t & vector_board_p_t::insert_string (vector_board_p_index_t a0, Board * const * a1)
{
    return (vector_board_p_t &)vector_char_p_t::insert_string ((vector_char_p_index_t)a0, (char * const *)(void*)a1);
}
vector_board_p_t & vector_board_p_t::insert_vector (vector_board_p_index_t a0, vector_board_p_t const * a1)
{
    return (vector_board_p_t &)vector_char_p_t::insert_vector ((vector_char_p_index_t)a0, (vector_char_p_t const *)(void*)a1);
}
vector_board_p_t & vector_board_p_t::insert_vector (vector_board_p_index_t a0, vector_board_p_t const & a1)
{
    return (vector_board_p_t &)vector_char_p_t::insert_vector ((vector_char_p_index_t)a0, (vector_char_p_t const &)a1);
}
vector_board_p_t & vector_board_p_t::insert_subvector (vector_board_p_index_t a0, vector_board_p_t const * a1, vector_board_p_index_t a2, vector_board_p_cnt_t a3, ERWIN_BOOL a4)
{
    return (vector_board_p_t &)vector_char_p_t::insert_subvector ((vector_char_p_index_t)a0, (vector_char_p_t const *)(void*)a1, (vector_char_p_index_t)a2, (vector_char_p_cnt_t)a3, a4);
}
vector_board_p_t & vector_board_p_t::insert_subvector (vector_board_p_index_t a0, vector_board_p_t const & a1, vector_board_p_index_t a2, vector_board_p_cnt_t a3, ERWIN_BOOL a4)
{
    return (vector_board_p_t &)vector_char_p_t::insert_subvector ((vector_char_p_index_t)a0, (vector_char_p_t const &)a1, (vector_char_p_index_t)a2, (vector_char_p_cnt_t)a3, a4);
}
#if VECTOR_BOARD_P_DIRECT_RECURSION == 0
vector_board_p_t & vector_board_p_t::insert (vector_board_p_index_t a0, vector_board_p_t const & a1, vector_board_p_index_t a2, vector_board_p_cnt_t a3, ERWIN_BOOL a4)
{
    return (vector_board_p_t &)vector_char_p_t::insert ((vector_char_p_index_t)a0, (vector_char_p_t const &)a1, (vector_char_p_index_t)a2, (vector_char_p_cnt_t)a3, a4);
}
vector_board_p_t & vector_board_p_t::insert (vector_board_p_index_t a0, vector_board_p_t const * a1, vector_board_p_index_t a2, vector_board_p_cnt_t a3, ERWIN_BOOL a4)
{
    return (vector_board_p_t &)vector_char_p_t::insert ((vector_char_p_index_t)a0, (vector_char_p_t const *)(void*)a1, (vector_char_p_index_t)a2, (vector_char_p_cnt_t)a3, a4);
}
vector_board_p_t & vector_board_p_t::insert (vector_board_p_index_t a0, Board * const * a1, vector_board_p_cnt_t a2)
{
    return (vector_board_p_t &)vector_char_p_t::insert ((vector_char_p_index_t)a0, (char * const *)(void*)a1, (vector_char_p_cnt_t)a2);
}
vector_board_p_t & vector_board_p_t::insert (vector_board_p_index_t a0, Board * const * a1)
{
    return (vector_board_p_t &)vector_char_p_t::insert ((vector_char_p_index_t)a0, (char * const *)(void*)a1);
}
vector_board_p_t & vector_board_p_t::insert (vector_board_p_index_t a0, vector_board_p_t const * a1)
{
    return (vector_board_p_t &)vector_char_p_t::insert ((vector_char_p_index_t)a0, (vector_char_p_t const *)(void*)a1);
}
vector_board_p_t & vector_board_p_t::insert (vector_board_p_index_t a0, vector_board_p_t const & a1)
{
    return (vector_board_p_t &)vector_char_p_t::insert ((vector_char_p_index_t)a0, (vector_char_p_t const &)a1);
}
#endif
vector_board_p_cnt_t vector_board_p_t::string_length (Board * const * a0) const
{
    return (vector_board_p_cnt_t)vector_char_p_t::string_length ((char * const *)(void*)a0);
}
vector_board_p_t & vector_board_p_t::ensure_size (vector_board_p_cnt_t a0)
{
    return (vector_board_p_t &)vector_char_p_t::ensure_size ((vector_char_p_cnt_t)a0);
}
vector_board_p_t & vector_board_p_t::ensure_size (vector_board_p_cnt_t a0, Board *  a1)
{
    return (vector_board_p_t &)vector_char_p_t::ensure_size ((vector_char_p_cnt_t)a0, (char * )a1);
}
vector_board_p_t & vector_board_p_t::set_size (vector_board_p_cnt_t a0)
{
    return (vector_board_p_t &)vector_char_p_t::set_size ((vector_char_p_cnt_t)a0);
}
vector_board_p_t & vector_board_p_t::set_size (vector_board_p_cnt_t a0, Board *  a1)
{
    return (vector_board_p_t &)vector_char_p_t::set_size ((vector_char_p_cnt_t)a0, (char * )a1);
}
int vector_board_p_t::ensure_table_size (vector_board_p_cnt_t a0)
{
    return vector_char_p_t::ensure_table_size ((vector_char_p_cnt_t)a0);
}
vector_board_p_element_ptr_t vector_board_p_t::as_array (void) const
{
    return (vector_board_p_element_ptr_t)vector_char_p_t::as_array ();
}
vector_board_p_element_ptr_t vector_board_p_t::as_open_array (void) const
{
    return (vector_board_p_element_ptr_t)vector_char_p_t::as_open_array ();
}
vector_board_p_element_ptr_t vector_board_p_t::as_array_detach (void)
{
    return (vector_board_p_element_ptr_t)vector_char_p_t::as_array_detach ();
}
vector_board_p_t & vector_board_p_t::ensure_heap_storage (void)
{
    return (vector_board_p_t &)vector_char_p_t::ensure_heap_storage ();
}
bool vector_board_p_t::has_heap_storage () const
{
    return vector_char_p_t::has_heap_storage ();
}
vector_board_p_cnt_t vector_board_p_t::inline_store_cnt ()
{
    return (vector_board_p_cnt_t)vector_char_p_t::inline_store_cnt ();
}
vector_board_p_element_ptr_t vector_board_p_t::as_open_array_detach (void)
{
    return (vector_board_p_element_ptr_t)vector_char_p_t::as_open_array_detach ();
}
vector_board_p_element_ptr_t vector_board_p_t::operator+ (vector_board_p_index_t a0)
{
    return (vector_board_p_element_ptr_t)vector_char_p_t::operator+ ((vector_char_p_index_t)a0);
}
#if ERWIN_IGNORE_BROKEN_MS_COMPILER
Board * const * vector_board_p_t::operator+ (vector_board_p_index_t a0) const
{
    return (Board * const *)(void*)vector_char_p_t::operator+ ((vector_char_p_index_t)a0);
}
#endif
vector_board_p_element_ref_t vector_board_p_t::operator* ()
{
    return (vector_board_p_element_ref_t)vector_char_p_t::operator* ();
}
#if ERWIN_IGNORE_BROKEN_MS_COMPILER
Board *  vector_board_p_t::operator* () const
{
    return (Board * )vector_char_p_t::operator* ();
}
#endif
vector_board_p_element_ptr_t vector_board_p_t::operator+ () const
{
    return (vector_board_p_element_ptr_t)vector_char_p_t::operator+ ();
}
vector_board_p_t & vector_board_p_t::make_heap (vector_board_p_cmp_t a0)
{
    return (vector_board_p_t &)vector_char_p_t::make_heap ((vector_char_p_cmp_t)a0);
}
vector_board_p_index_t vector_board_p_t::heap_left (vector_board_p_index_t a0) const
{
    return (vector_board_p_index_t)vector_char_p_t::heap_left ((vector_char_p_index_t)a0);
}
vector_board_p_index_t vector_board_p_t::heap_right (vector_board_p_index_t a0) const
{
    return (vector_board_p_index_t)vector_char_p_t::heap_right ((vector_char_p_index_t)a0);
}
vector_board_p_index_t vector_board_p_t::heap_father (vector_board_p_index_t a0) const
{
    return (vector_board_p_index_t)vector_char_p_t::heap_father ((vector_char_p_index_t)a0);
}
Board * vector_board_p_t::heap_extract (vector_board_p_cmp_t a0)
{
    return (Board *)vector_char_p_t::heap_extract ((vector_char_p_cmp_t)a0);
}
vector_board_p_t & vector_board_p_t::heap_raise (vector_board_p_index_t a0, vector_board_p_cmp_t a1)
{
    return (vector_board_p_t &)vector_char_p_t::heap_raise ((vector_char_p_index_t)a0, (vector_char_p_cmp_t)a1);
}
vector_board_p_t & vector_board_p_t::heap_sink (vector_board_p_index_t a0, vector_board_p_cmp_t a1)
{
    return (vector_board_p_t &)vector_char_p_t::heap_sink ((vector_char_p_index_t)a0, (vector_char_p_cmp_t)a1);
}
vector_board_p_t & vector_board_p_t::heap_fix (vector_board_p_index_t a0, vector_board_p_cmp_t a1)
{
    return (vector_board_p_t &)vector_char_p_t::heap_fix ((vector_char_p_index_t)a0, (vector_char_p_cmp_t)a1);
}
vector_board_p_t & vector_board_p_t::heap_insert (Board *  a0, vector_board_p_cmp_t a1)
{
    return (vector_board_p_t &)vector_char_p_t::heap_insert ((char * )a0, (vector_char_p_cmp_t)a1);
}
vector_board_p_t & vector_board_p_t::heap_erase (vector_board_p_index_t a0, vector_board_p_cmp_t a1)
{
    return (vector_board_p_t &)vector_char_p_t::heap_erase ((vector_char_p_index_t)a0, (vector_char_p_cmp_t)a1);
}
vector_board_p_t & vector_board_p_t::heap_sort (vector_board_p_cmp_t a0)
{
    return (vector_board_p_t &)vector_char_p_t::heap_sort ((vector_char_p_cmp_t)a0);
}
vector_board_p_t & vector_board_p_t::qsort (vector_board_p_cmp_t a0)
{
    return (vector_board_p_t &)vector_char_p_t::qsort ((vector_char_p_cmp_t)a0);
}
vector_board_p_t & vector_board_p_t::sort (vector_board_p_cmp_t a0)
{
    return (vector_board_p_t &)vector_char_p_t::sort ((vector_char_p_cmp_t)a0);
}
vector_board_p_index_t vector_board_p_t::bfind (Board *  a0, vector_board_p_cmp_t a1) const
{
    return (vector_board_p_index_t)vector_char_p_t::bfind ((char * )a0, (vector_char_p_cmp_t)a1);
}
hashval_t vector_board_p_t::hash_raw (void) const
{
    return vector_char_p_t::hash_raw ();
}
hashval_t vector_board_p_t::hash (void) const
{
    return vector_char_p_t::hash ();
}
void vector_board_p_t::init_iterator (vector_board_p_index_t * a0) const
{
    vector_char_p_t::init_iterator ((vector_char_p_index_t *)(void*)a0);
}
bool vector_board_p_t::next_iteration (vector_board_p_index_t * a0, Board * * a1) const
{
    return vector_char_p_t::next_iteration ((vector_char_p_index_t *)(void*)a0, (char * *)(void*)a1);
}
bool vector_board_p_t::next_iteration_ptr (vector_board_p_index_t * a0, Board * * * a1)
{
    return vector_char_p_t::next_iteration_ptr ((vector_char_p_index_t *)(void*)a0, (char * * *)(void*)a1);
}
bool vector_board_p_t::next_iteration_ptr (vector_board_p_index_t * a0, Board * const * * a1) const
{
    return vector_char_p_t::next_iteration_ptr ((vector_char_p_index_t *)(void*)a0, (char * const * *)(void*)a1);
}
void vector_board_p_t::init_iterator_reverse (vector_board_p_index_t * a0) const
{
    vector_char_p_t::init_iterator_reverse ((vector_char_p_index_t *)(void*)a0);
}
bool vector_board_p_t::next_iteration_reverse (vector_board_p_index_t * a0, Board * * a1) const
{
    return vector_char_p_t::next_iteration_reverse ((vector_char_p_index_t *)(void*)a0, (char * *)(void*)a1);
}
bool vector_board_p_t::next_iteration_ptr_reverse (vector_board_p_index_t * a0, Board * * * a1)
{
    return vector_char_p_t::next_iteration_ptr_reverse ((vector_char_p_index_t *)(void*)a0, (char * * *)(void*)a1);
}
bool vector_board_p_t::next_iteration_ptr_reverse (vector_board_p_index_t * a0, Board * const * * a1) const
{
    return vector_char_p_t::next_iteration_ptr_reverse ((vector_char_p_index_t *)(void*)a0, (char * const * *)(void*)a1);
}
vector_board_p_t & vector_board_p_t::shrink (bool a0)
{
    return (vector_board_p_t &)vector_char_p_t::shrink (a0);
}
vector_board_p_t & vector_board_p_t::clear ()
{
    return (vector_board_p_t &)vector_char_p_t::clear ();
}
vector_board_p_t & vector_board_p_t::clear_keep (vector_board_p_cnt_t a0)
{
    return (vector_board_p_t &)vector_char_p_t::clear_keep ((vector_char_p_cnt_t)a0);
}
vector_board_p_t & vector_board_p_t::clear_no_resize ()
{
    return (vector_board_p_t &)vector_char_p_t::clear_no_resize ();
}
void vector_board_p_t::delete_array (vector_board_p_element_ptr_t a0)
{
    vector_char_p_t::delete_array ((vector_char_p_element_ptr_t)a0);
}
vector_board_p_t & vector_board_p_t::clear (bool a0, bool a1)
{
    return (vector_board_p_t &)vector_char_p_t::clear (a0, a1);
}
#ifdef VECTOR_BOARD_P_INLINE__NENTRIES
vector_board_p_cnt_t vector_board_p_t::nentries () const
{
    return (vector_board_p_cnt_t)vector_char_p_t::nentries ();
}
#else
vector_board_p_cnt_t vector_board_p_t::nentries () const
{
    return (vector_board_p_cnt_t)vector_char_p_t::nentries ();
}
#endif
bool vector_board_p_t::empty () const
{
    return vector_char_p_t::empty ();
}
bool vector_board_p_t::non_empty () const
{
    return vector_char_p_t::non_empty ();
}
vector_board_p_cnt_t vector_board_p_t::table_size () const
{
    return (vector_board_p_cnt_t)vector_char_p_t::table_size ();
}
int vector_board_p_t::cmp (vector_board_p_t const * a0, vector_board_p_cmp_t a1) const
{
    return vector_char_p_t::cmp ((vector_char_p_t const *)(void*)a0, (vector_char_p_cmp_t)a1);
}
int vector_board_p_t::cmp (vector_board_p_t const & a0, vector_board_p_cmp_t a1) const
{
    return vector_char_p_t::cmp ((vector_char_p_t const &)a0, (vector_char_p_cmp_t)a1);
}
int vector_board_p_t::priority_cmp (vector_board_p_t const * a0, vector_board_p_cmp_t a1) const
{
    return vector_char_p_t::priority_cmp ((vector_char_p_t const *)(void*)a0, (vector_char_p_cmp_t)a1);
}
int vector_board_p_t::priority_cmp (vector_board_p_t const & a0, vector_board_p_cmp_t a1) const
{
    return vector_char_p_t::priority_cmp ((vector_char_p_t const &)a0, (vector_char_p_cmp_t)a1);
}
bool vector_board_p_t::operator== (vector_board_p_t const & a0)
{
    return vector_char_p_t::operator== ((vector_char_p_t const &)a0);
}
bool vector_board_p_t::operator== (vector_board_p_t const * a0)
{
    return vector_char_p_t::operator== ((vector_char_p_t const *)(void*)a0);
}
bool vector_board_p_t::operator!= (vector_board_p_t const & a0)
{
    return vector_char_p_t::operator!= ((vector_char_p_t const &)a0);
}
bool vector_board_p_t::operator!= (vector_board_p_t const * a0)
{
    return vector_char_p_t::operator!= ((vector_char_p_t const *)(void*)a0);
}
bool vector_board_p_t::operator<= (vector_board_p_t const & a0)
{
    return vector_char_p_t::operator<= ((vector_char_p_t const &)a0);
}
bool vector_board_p_t::operator<= (vector_board_p_t const * a0)
{
    return vector_char_p_t::operator<= ((vector_char_p_t const *)(void*)a0);
}
bool vector_board_p_t::operator>= (vector_board_p_t const & a0)
{
    return vector_char_p_t::operator>= ((vector_char_p_t const &)a0);
}
bool vector_board_p_t::operator>= (vector_board_p_t const * a0)
{
    return vector_char_p_t::operator>= ((vector_char_p_t const *)(void*)a0);
}
bool vector_board_p_t::operator< (vector_board_p_t const & a0)
{
    return vector_char_p_t::operator< ((vector_char_p_t const &)a0);
}
bool vector_board_p_t::operator< (vector_board_p_t const * a0)
{
    return vector_char_p_t::operator< ((vector_char_p_t const *)(void*)a0);
}
bool vector_board_p_t::operator> (vector_board_p_t const & a0)
{
    return vector_char_p_t::operator> ((vector_char_p_t const &)a0);
}
bool vector_board_p_t::operator> (vector_board_p_t const * a0)
{
    return vector_char_p_t::operator> ((vector_char_p_t const *)(void*)a0);
}
vector_board_p_t & vector_board_p_t::swap (vector_board_p_index_t a0, vector_board_p_index_t a1)
{
    return (vector_board_p_t &)vector_char_p_t::swap ((vector_char_p_index_t)a0, (vector_char_p_index_t)a1);
}
bool vector_board_p_t::locate (vector_board_p_index_t & a0, Board *  a1, int a2) const
{
    return vector_char_p_t::locate ((vector_char_p_index_t &)a0, (char * )a1, a2);
}
bool vector_board_p_t::locate (vector_board_p_index_t & a0, Board *  a1, vector_board_p_cmp_t a2, int a3) const
{
    return vector_char_p_t::locate ((vector_char_p_index_t &)a0, (char * )a1, (vector_char_p_cmp_t)a2, a3);
}

#endif /*__cplusplus*/


#endif /*!ERWIN_CAST_INLINING*/
