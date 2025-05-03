
#ifndef ERWIN_ERR_V_INT_f_h
#define ERWIN_ERR_V_INT_f_h

/* Unification of ErrVInt and err_v_int_t: they are identical now. */
struct err_v_int_t;

#ifndef __cplusplus
typedef struct err_v_int_t err_v_int_t;
#endif /* not defined __cplusplus */

typedef err_v_int_t ErrVInt;

typedef err_v_int_t *err_v_int_t_p;

typedef err_v_int_t const *err_v_int_t_const_p;

#define ERR_V_INT_SIG 1726800637



#ifdef ERR_ERR_V_INT_TP_DEEP
#  if ERR_ERR_V_INT_TP_DEEP
#    ifndef ERR_ERR_V_INT_TP_DEEP_COPY
#      define ERR_ERR_V_INT_TP_DEEP_COPY 1
#    endif
#    ifndef ERR_ERR_V_INT_TP_DEEP_COMPARE
#      define ERR_ERR_V_INT_TP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERR_V_INT_TP_DEEP_COPY
#      define ERR_ERR_V_INT_TP_DEEP_COPY 0
#    endif
#    ifndef ERR_ERR_V_INT_TP_DEEP_COMPARE
#      define ERR_ERR_V_INT_TP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERR_V_INT_TP_DEEP_COPY
#define ERR_ERR_V_INT_TP_DEEP_COPY 0
#endif /* !defined ERR_ERR_V_INT_TP_DEEP_COPY */

#ifndef ERR_ERR_V_INT_TP_DEEP_COMPARE
#define ERR_ERR_V_INT_TP_DEEP_COMPARE 0
#endif /* !defined ERR_ERR_V_INT_TP_DEEP_COMPARE */

#ifdef ERR_ERR_V_INT_T_CONSTP_DEEP
#  if ERR_ERR_V_INT_T_CONSTP_DEEP
#    ifndef ERR_ERR_V_INT_T_CONSTP_DEEP_COPY
#      define ERR_ERR_V_INT_T_CONSTP_DEEP_COPY 1
#    endif
#    ifndef ERR_ERR_V_INT_T_CONSTP_DEEP_COMPARE
#      define ERR_ERR_V_INT_T_CONSTP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERR_V_INT_T_CONSTP_DEEP_COPY
#      define ERR_ERR_V_INT_T_CONSTP_DEEP_COPY 0
#    endif
#    ifndef ERR_ERR_V_INT_T_CONSTP_DEEP_COMPARE
#      define ERR_ERR_V_INT_T_CONSTP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERR_V_INT_T_CONSTP_DEEP_COPY
#define ERR_ERR_V_INT_T_CONSTP_DEEP_COPY 0
#endif /* !defined ERR_ERR_V_INT_T_CONSTP_DEEP_COPY */

#ifndef ERR_ERR_V_INT_T_CONSTP_DEEP_COMPARE
#define ERR_ERR_V_INT_T_CONSTP_DEEP_COMPARE 0
#endif /* !defined ERR_ERR_V_INT_T_CONSTP_DEEP_COMPARE */

#ifdef ERR_CONST_ERR_V_INT_TP_DEEP
#  if ERR_CONST_ERR_V_INT_TP_DEEP
#    ifndef ERR_CONST_ERR_V_INT_TP_DEEP_COPY
#      define ERR_CONST_ERR_V_INT_TP_DEEP_COPY 1
#    endif
#    ifndef ERR_CONST_ERR_V_INT_TP_DEEP_COMPARE
#      define ERR_CONST_ERR_V_INT_TP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_CONST_ERR_V_INT_TP_DEEP_COPY
#      define ERR_CONST_ERR_V_INT_TP_DEEP_COPY 0
#    endif
#    ifndef ERR_CONST_ERR_V_INT_TP_DEEP_COMPARE
#      define ERR_CONST_ERR_V_INT_TP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_CONST_ERR_V_INT_TP_DEEP_COPY
#define ERR_CONST_ERR_V_INT_TP_DEEP_COPY 0
#endif /* !defined ERR_CONST_ERR_V_INT_TP_DEEP_COPY */

#ifndef ERR_CONST_ERR_V_INT_TP_DEEP_COMPARE
#define ERR_CONST_ERR_V_INT_TP_DEEP_COMPARE 0
#endif /* !defined ERR_CONST_ERR_V_INT_TP_DEEP_COMPARE */

#ifdef ERR_ERRVINTP_DEEP
#  if ERR_ERRVINTP_DEEP
#    ifndef ERR_ERRVINTP_DEEP_COPY
#      define ERR_ERRVINTP_DEEP_COPY 1
#    endif
#    ifndef ERR_ERRVINTP_DEEP_COMPARE
#      define ERR_ERRVINTP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERRVINTP_DEEP_COPY
#      define ERR_ERRVINTP_DEEP_COPY 0
#    endif
#    ifndef ERR_ERRVINTP_DEEP_COMPARE
#      define ERR_ERRVINTP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERRVINTP_DEEP_COPY
#define ERR_ERRVINTP_DEEP_COPY 0
#endif /* !defined ERR_ERRVINTP_DEEP_COPY */

#ifndef ERR_ERRVINTP_DEEP_COMPARE
#define ERR_ERRVINTP_DEEP_COMPARE 0
#endif /* !defined ERR_ERRVINTP_DEEP_COMPARE */

#ifdef ERR_ERRVINT_CONSTP_DEEP
#  if ERR_ERRVINT_CONSTP_DEEP
#    ifndef ERR_ERRVINT_CONSTP_DEEP_COPY
#      define ERR_ERRVINT_CONSTP_DEEP_COPY 1
#    endif
#    ifndef ERR_ERRVINT_CONSTP_DEEP_COMPARE
#      define ERR_ERRVINT_CONSTP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERRVINT_CONSTP_DEEP_COPY
#      define ERR_ERRVINT_CONSTP_DEEP_COPY 0
#    endif
#    ifndef ERR_ERRVINT_CONSTP_DEEP_COMPARE
#      define ERR_ERRVINT_CONSTP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERRVINT_CONSTP_DEEP_COPY
#define ERR_ERRVINT_CONSTP_DEEP_COPY 0
#endif /* !defined ERR_ERRVINT_CONSTP_DEEP_COPY */

#ifndef ERR_ERRVINT_CONSTP_DEEP_COMPARE
#define ERR_ERRVINT_CONSTP_DEEP_COMPARE 0
#endif /* !defined ERR_ERRVINT_CONSTP_DEEP_COMPARE */

#ifdef ERR_CONST_ERRVINTP_DEEP
#  if ERR_CONST_ERRVINTP_DEEP
#    ifndef ERR_CONST_ERRVINTP_DEEP_COPY
#      define ERR_CONST_ERRVINTP_DEEP_COPY 1
#    endif
#    ifndef ERR_CONST_ERRVINTP_DEEP_COMPARE
#      define ERR_CONST_ERRVINTP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_CONST_ERRVINTP_DEEP_COPY
#      define ERR_CONST_ERRVINTP_DEEP_COPY 0
#    endif
#    ifndef ERR_CONST_ERRVINTP_DEEP_COMPARE
#      define ERR_CONST_ERRVINTP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_CONST_ERRVINTP_DEEP_COPY
#define ERR_CONST_ERRVINTP_DEEP_COPY 0
#endif /* !defined ERR_CONST_ERRVINTP_DEEP_COPY */

#ifndef ERR_CONST_ERRVINTP_DEEP_COMPARE
#define ERR_CONST_ERRVINTP_DEEP_COMPARE 0
#endif /* !defined ERR_CONST_ERRVINTP_DEEP_COMPARE */

#ifdef ERR_ERR_V_INT_T_P_DEEP
#  if ERR_ERR_V_INT_T_P_DEEP
#    ifndef ERR_ERR_V_INT_T_P_DEEP_COPY
#      define ERR_ERR_V_INT_T_P_DEEP_COPY 1
#    endif
#    ifndef ERR_ERR_V_INT_T_P_DEEP_COMPARE
#      define ERR_ERR_V_INT_T_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERR_V_INT_T_P_DEEP_COPY
#      define ERR_ERR_V_INT_T_P_DEEP_COPY 0
#    endif
#    ifndef ERR_ERR_V_INT_T_P_DEEP_COMPARE
#      define ERR_ERR_V_INT_T_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERR_V_INT_T_P_DEEP_COPY
#define ERR_ERR_V_INT_T_P_DEEP_COPY 0
#endif /* !defined ERR_ERR_V_INT_T_P_DEEP_COPY */

#ifndef ERR_ERR_V_INT_T_P_DEEP_COMPARE
#define ERR_ERR_V_INT_T_P_DEEP_COMPARE 0
#endif /* !defined ERR_ERR_V_INT_T_P_DEEP_COMPARE */

#ifdef ERR_ERR_V_INT_T_CONST_P_DEEP
#  if ERR_ERR_V_INT_T_CONST_P_DEEP
#    ifndef ERR_ERR_V_INT_T_CONST_P_DEEP_COPY
#      define ERR_ERR_V_INT_T_CONST_P_DEEP_COPY 1
#    endif
#    ifndef ERR_ERR_V_INT_T_CONST_P_DEEP_COMPARE
#      define ERR_ERR_V_INT_T_CONST_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERR_V_INT_T_CONST_P_DEEP_COPY
#      define ERR_ERR_V_INT_T_CONST_P_DEEP_COPY 0
#    endif
#    ifndef ERR_ERR_V_INT_T_CONST_P_DEEP_COMPARE
#      define ERR_ERR_V_INT_T_CONST_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERR_V_INT_T_CONST_P_DEEP_COPY
#define ERR_ERR_V_INT_T_CONST_P_DEEP_COPY 0
#endif /* !defined ERR_ERR_V_INT_T_CONST_P_DEEP_COPY */

#ifndef ERR_ERR_V_INT_T_CONST_P_DEEP_COMPARE
#define ERR_ERR_V_INT_T_CONST_P_DEEP_COMPARE 0
#endif /* !defined ERR_ERR_V_INT_T_CONST_P_DEEP_COMPARE */

#ifdef ERR_CONST_ERR_V_INT_T_P_DEEP
#  if ERR_CONST_ERR_V_INT_T_P_DEEP
#    ifndef ERR_CONST_ERR_V_INT_T_P_DEEP_COPY
#      define ERR_CONST_ERR_V_INT_T_P_DEEP_COPY 1
#    endif
#    ifndef ERR_CONST_ERR_V_INT_T_P_DEEP_COMPARE
#      define ERR_CONST_ERR_V_INT_T_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_CONST_ERR_V_INT_T_P_DEEP_COPY
#      define ERR_CONST_ERR_V_INT_T_P_DEEP_COPY 0
#    endif
#    ifndef ERR_CONST_ERR_V_INT_T_P_DEEP_COMPARE
#      define ERR_CONST_ERR_V_INT_T_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_CONST_ERR_V_INT_T_P_DEEP_COPY
#define ERR_CONST_ERR_V_INT_T_P_DEEP_COPY 0
#endif /* !defined ERR_CONST_ERR_V_INT_T_P_DEEP_COPY */

#ifndef ERR_CONST_ERR_V_INT_T_P_DEEP_COMPARE
#define ERR_CONST_ERR_V_INT_T_P_DEEP_COMPARE 0
#endif /* !defined ERR_CONST_ERR_V_INT_T_P_DEEP_COMPARE */

#ifdef ERR_ERRVINT_P_DEEP
#  if ERR_ERRVINT_P_DEEP
#    ifndef ERR_ERRVINT_P_DEEP_COPY
#      define ERR_ERRVINT_P_DEEP_COPY 1
#    endif
#    ifndef ERR_ERRVINT_P_DEEP_COMPARE
#      define ERR_ERRVINT_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERRVINT_P_DEEP_COPY
#      define ERR_ERRVINT_P_DEEP_COPY 0
#    endif
#    ifndef ERR_ERRVINT_P_DEEP_COMPARE
#      define ERR_ERRVINT_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERRVINT_P_DEEP_COPY
#define ERR_ERRVINT_P_DEEP_COPY 0
#endif /* !defined ERR_ERRVINT_P_DEEP_COPY */

#ifndef ERR_ERRVINT_P_DEEP_COMPARE
#define ERR_ERRVINT_P_DEEP_COMPARE 0
#endif /* !defined ERR_ERRVINT_P_DEEP_COMPARE */

#ifdef ERR_ERRVINT_CONST_P_DEEP
#  if ERR_ERRVINT_CONST_P_DEEP
#    ifndef ERR_ERRVINT_CONST_P_DEEP_COPY
#      define ERR_ERRVINT_CONST_P_DEEP_COPY 1
#    endif
#    ifndef ERR_ERRVINT_CONST_P_DEEP_COMPARE
#      define ERR_ERRVINT_CONST_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERRVINT_CONST_P_DEEP_COPY
#      define ERR_ERRVINT_CONST_P_DEEP_COPY 0
#    endif
#    ifndef ERR_ERRVINT_CONST_P_DEEP_COMPARE
#      define ERR_ERRVINT_CONST_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERRVINT_CONST_P_DEEP_COPY
#define ERR_ERRVINT_CONST_P_DEEP_COPY 0
#endif /* !defined ERR_ERRVINT_CONST_P_DEEP_COPY */

#ifndef ERR_ERRVINT_CONST_P_DEEP_COMPARE
#define ERR_ERRVINT_CONST_P_DEEP_COMPARE 0
#endif /* !defined ERR_ERRVINT_CONST_P_DEEP_COMPARE */

#ifdef ERR_CONST_ERRVINT_P_DEEP
#  if ERR_CONST_ERRVINT_P_DEEP
#    ifndef ERR_CONST_ERRVINT_P_DEEP_COPY
#      define ERR_CONST_ERRVINT_P_DEEP_COPY 1
#    endif
#    ifndef ERR_CONST_ERRVINT_P_DEEP_COMPARE
#      define ERR_CONST_ERRVINT_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_CONST_ERRVINT_P_DEEP_COPY
#      define ERR_CONST_ERRVINT_P_DEEP_COPY 0
#    endif
#    ifndef ERR_CONST_ERRVINT_P_DEEP_COMPARE
#      define ERR_CONST_ERRVINT_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_CONST_ERRVINT_P_DEEP_COPY
#define ERR_CONST_ERRVINT_P_DEEP_COPY 0
#endif /* !defined ERR_CONST_ERRVINT_P_DEEP_COPY */

#ifndef ERR_CONST_ERRVINT_P_DEEP_COMPARE
#define ERR_CONST_ERRVINT_P_DEEP_COMPARE 0
#endif /* !defined ERR_CONST_ERRVINT_P_DEEP_COMPARE */

#if ERR_ERR_V_INT_TP_DEEP_COMPARE && !defined(ERR_ERR_V_INT_TP_HASH_RAW)
#define ERR_ERR_V_INT_TP_HASH_RAW(A1) err_v_int_hash_raw((A1))
#endif

#if ERR_ERR_V_INT_T_CONSTP_DEEP_COMPARE && !defined(ERR_ERR_V_INT_T_CONSTP_HASH_RAW)
#define ERR_ERR_V_INT_T_CONSTP_HASH_RAW(A1) err_v_int_hash_raw((A1))
#endif

#if ERR_CONST_ERR_V_INT_TP_DEEP_COMPARE && !defined(ERR_CONST_ERR_V_INT_TP_HASH_RAW)
#define ERR_CONST_ERR_V_INT_TP_HASH_RAW(A1) err_v_int_hash_raw((A1))
#endif

#if ERR_ERRVINTP_DEEP_COMPARE && !defined(ERR_ERRVINTP_HASH_RAW)
#define ERR_ERRVINTP_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if ERR_ERRVINT_CONSTP_DEEP_COMPARE && !defined(ERR_ERRVINT_CONSTP_HASH_RAW)
#define ERR_ERRVINT_CONSTP_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if ERR_CONST_ERRVINTP_DEEP_COMPARE && !defined(ERR_CONST_ERRVINTP_HASH_RAW)
#define ERR_CONST_ERRVINTP_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if ERR_ERR_V_INT_T_P_DEEP_COMPARE && !defined(ERR_ERR_V_INT_T_P_HASH_RAW)
#define ERR_ERR_V_INT_T_P_HASH_RAW(A1) err_v_int_hash_raw((A1))
#endif

#if ERR_ERR_V_INT_T_CONST_P_DEEP_COMPARE && !defined(ERR_ERR_V_INT_T_CONST_P_HASH_RAW)
#define ERR_ERR_V_INT_T_CONST_P_HASH_RAW(A1) err_v_int_hash_raw((A1))
#endif

#if ERR_CONST_ERR_V_INT_T_P_DEEP_COMPARE && !defined(ERR_CONST_ERR_V_INT_T_P_HASH_RAW)
#define ERR_CONST_ERR_V_INT_T_P_HASH_RAW(A1) err_v_int_hash_raw((A1))
#endif

#if ERR_ERRVINT_P_DEEP_COMPARE && !defined(ERR_ERRVINT_P_HASH_RAW)
#define ERR_ERRVINT_P_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if ERR_ERRVINT_CONST_P_DEEP_COMPARE && !defined(ERR_ERRVINT_CONST_P_HASH_RAW)
#define ERR_ERRVINT_CONST_P_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if ERR_CONST_ERRVINT_P_DEEP_COMPARE && !defined(ERR_CONST_ERRVINT_P_HASH_RAW)
#define ERR_CONST_ERRVINT_P_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#ifndef ERR_ERRVINT_HASH_RAW
#define ERR_ERRVINT_HASH_RAW(A1) ((A1).hash_raw())
#endif

#if ERR_ERR_V_INT_TP_DEEP_COMPARE && !defined(ERR_ERR_V_INT_TP_CMP)
#define ERR_ERR_V_INT_TP_CMP(A1,A2) err_v_int_cmp((A1),(A2),NULL)
#endif

#if ERR_ERR_V_INT_T_CONSTP_DEEP_COMPARE && !defined(ERR_ERR_V_INT_T_CONSTP_CMP)
#define ERR_ERR_V_INT_T_CONSTP_CMP(A1,A2) err_v_int_cmp((A1),(A2),NULL)
#endif

#if ERR_CONST_ERR_V_INT_TP_DEEP_COMPARE && !defined(ERR_CONST_ERR_V_INT_TP_CMP)
#define ERR_CONST_ERR_V_INT_TP_CMP(A1,A2) err_v_int_cmp((A1),(A2),NULL)
#endif

#if ERR_ERRVINTP_DEEP_COMPARE && !defined(ERR_ERRVINTP_CMP)
#define ERR_ERRVINTP_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if ERR_ERRVINT_CONSTP_DEEP_COMPARE && !defined(ERR_ERRVINT_CONSTP_CMP)
#define ERR_ERRVINT_CONSTP_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if ERR_CONST_ERRVINTP_DEEP_COMPARE && !defined(ERR_CONST_ERRVINTP_CMP)
#define ERR_CONST_ERRVINTP_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if ERR_ERR_V_INT_T_P_DEEP_COMPARE && !defined(ERR_ERR_V_INT_T_P_CMP)
#define ERR_ERR_V_INT_T_P_CMP(A1,A2) err_v_int_cmp((A1),(A2),NULL)
#endif

#if ERR_ERR_V_INT_T_CONST_P_DEEP_COMPARE && !defined(ERR_ERR_V_INT_T_CONST_P_CMP)
#define ERR_ERR_V_INT_T_CONST_P_CMP(A1,A2) err_v_int_cmp((A1),(A2),NULL)
#endif

#if ERR_CONST_ERR_V_INT_T_P_DEEP_COMPARE && !defined(ERR_CONST_ERR_V_INT_T_P_CMP)
#define ERR_CONST_ERR_V_INT_T_P_CMP(A1,A2) err_v_int_cmp((A1),(A2),NULL)
#endif

#if ERR_ERRVINT_P_DEEP_COMPARE && !defined(ERR_ERRVINT_P_CMP)
#define ERR_ERRVINT_P_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if ERR_ERRVINT_CONST_P_DEEP_COMPARE && !defined(ERR_ERRVINT_CONST_P_CMP)
#define ERR_ERRVINT_CONST_P_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if ERR_CONST_ERRVINT_P_DEEP_COMPARE && !defined(ERR_CONST_ERRVINT_P_CMP)
#define ERR_CONST_ERRVINT_P_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#ifndef ERR_ERRVINT_CMP
#define ERR_ERRVINT_CMP(A1,A2) ((A1).cmp((A2),NULL))
#endif

#ifndef ERR_ERRVINT_ZERO
#define ERR_ERRVINT_ZERO (ErrVInt::static_zero())
#endif

#if ERR_ERR_V_INT_TP_DEEP_COPY && !defined(ERR_ERR_V_INT_TP_ICOPY)
#define ERR_ERR_V_INT_TP_ICOPY(A1,A2) err_v_int_copy_err((A1),(A2))
#endif

#if ERR_ERR_V_INT_T_CONSTP_DEEP_COPY && !defined(ERR_ERR_V_INT_T_CONSTP_ICOPY)
#define ERR_ERR_V_INT_T_CONSTP_ICOPY(A1,A2) err_v_int_copy_err((A1),(A2))
#endif

#if ERR_CONST_ERR_V_INT_TP_DEEP_COPY && !defined(ERR_CONST_ERR_V_INT_TP_ICOPY)
#define ERR_CONST_ERR_V_INT_TP_ICOPY(A1,A2) err_v_int_copy_err((A1),(A2))
#endif

#if ERR_ERRVINTP_DEEP_COPY && !defined(ERR_ERRVINTP_ICOPY)
#define ERR_ERRVINTP_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERRVINT_CONSTP_DEEP_COPY && !defined(ERR_ERRVINT_CONSTP_ICOPY)
#define ERR_ERRVINT_CONSTP_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_CONST_ERRVINTP_DEEP_COPY && !defined(ERR_CONST_ERRVINTP_ICOPY)
#define ERR_CONST_ERRVINTP_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERR_V_INT_T_P_DEEP_COPY && !defined(ERR_ERR_V_INT_T_P_ICOPY)
#define ERR_ERR_V_INT_T_P_ICOPY(A1,A2) err_v_int_copy_err((A1),(A2))
#endif

#if ERR_ERR_V_INT_T_CONST_P_DEEP_COPY && !defined(ERR_ERR_V_INT_T_CONST_P_ICOPY)
#define ERR_ERR_V_INT_T_CONST_P_ICOPY(A1,A2) err_v_int_copy_err((A1),(A2))
#endif

#if ERR_CONST_ERR_V_INT_T_P_DEEP_COPY && !defined(ERR_CONST_ERR_V_INT_T_P_ICOPY)
#define ERR_CONST_ERR_V_INT_T_P_ICOPY(A1,A2) err_v_int_copy_err((A1),(A2))
#endif

#if ERR_ERRVINT_P_DEEP_COPY && !defined(ERR_ERRVINT_P_ICOPY)
#define ERR_ERRVINT_P_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERRVINT_CONST_P_DEEP_COPY && !defined(ERR_ERRVINT_CONST_P_ICOPY)
#define ERR_ERRVINT_CONST_P_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_CONST_ERRVINT_P_DEEP_COPY && !defined(ERR_CONST_ERRVINT_P_ICOPY)
#define ERR_CONST_ERRVINT_P_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERR_V_INT_TP_DEEP_COPY && !defined(ERR_ERR_V_INT_TP_OCOPY)
#define ERR_ERR_V_INT_TP_OCOPY(A1,A2) err_v_int_copy_err((A1),(A2))
#endif

#if ERR_ERR_V_INT_T_CONSTP_DEEP_COPY && !defined(ERR_ERR_V_INT_T_CONSTP_OCOPY)
#define ERR_ERR_V_INT_T_CONSTP_OCOPY(A1,A2) err_v_int_copy_err((A1),(A2))
#endif

#if ERR_CONST_ERR_V_INT_TP_DEEP_COPY && !defined(ERR_CONST_ERR_V_INT_TP_OCOPY)
#define ERR_CONST_ERR_V_INT_TP_OCOPY(A1,A2) err_v_int_copy_err((A1),(A2))
#endif

#if ERR_ERRVINTP_DEEP_COPY && !defined(ERR_ERRVINTP_OCOPY)
#define ERR_ERRVINTP_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERRVINT_CONSTP_DEEP_COPY && !defined(ERR_ERRVINT_CONSTP_OCOPY)
#define ERR_ERRVINT_CONSTP_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_CONST_ERRVINTP_DEEP_COPY && !defined(ERR_CONST_ERRVINTP_OCOPY)
#define ERR_CONST_ERRVINTP_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERR_V_INT_T_P_DEEP_COPY && !defined(ERR_ERR_V_INT_T_P_OCOPY)
#define ERR_ERR_V_INT_T_P_OCOPY(A1,A2) err_v_int_copy_err((A1),(A2))
#endif

#if ERR_ERR_V_INT_T_CONST_P_DEEP_COPY && !defined(ERR_ERR_V_INT_T_CONST_P_OCOPY)
#define ERR_ERR_V_INT_T_CONST_P_OCOPY(A1,A2) err_v_int_copy_err((A1),(A2))
#endif

#if ERR_CONST_ERR_V_INT_T_P_DEEP_COPY && !defined(ERR_CONST_ERR_V_INT_T_P_OCOPY)
#define ERR_CONST_ERR_V_INT_T_P_OCOPY(A1,A2) err_v_int_copy_err((A1),(A2))
#endif

#if ERR_ERRVINT_P_DEEP_COPY && !defined(ERR_ERRVINT_P_OCOPY)
#define ERR_ERRVINT_P_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERRVINT_CONST_P_DEEP_COPY && !defined(ERR_ERRVINT_CONST_P_OCOPY)
#define ERR_ERRVINT_CONST_P_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_CONST_ERRVINT_P_DEEP_COPY && !defined(ERR_CONST_ERRVINT_P_OCOPY)
#define ERR_CONST_ERRVINT_P_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERR_V_INT_TP_DEEP_COPY && !defined(ERR_ERR_V_INT_TP_IFREE)
#define ERR_ERR_V_INT_TP_IFREE(A1) err_v_int_delete((A1))
#endif

#if ERR_ERR_V_INT_T_CONSTP_DEEP_COPY && !defined(ERR_ERR_V_INT_T_CONSTP_IFREE)
#define ERR_ERR_V_INT_T_CONSTP_IFREE(A1) err_v_int_delete((A1))
#endif

#if ERR_CONST_ERR_V_INT_TP_DEEP_COPY && !defined(ERR_CONST_ERR_V_INT_TP_IFREE)
#define ERR_CONST_ERR_V_INT_TP_IFREE(A1) err_v_int_delete((A1))
#endif

#if ERR_ERRVINTP_DEEP_COPY && !defined(ERR_ERRVINTP_IFREE)
#define ERR_ERRVINTP_IFREE(A1) delete((A1))
#endif

#if ERR_ERRVINT_CONSTP_DEEP_COPY && !defined(ERR_ERRVINT_CONSTP_IFREE)
#define ERR_ERRVINT_CONSTP_IFREE(A1) delete((A1))
#endif

#if ERR_CONST_ERRVINTP_DEEP_COPY && !defined(ERR_CONST_ERRVINTP_IFREE)
#define ERR_CONST_ERRVINTP_IFREE(A1) delete((A1))
#endif

#if ERR_ERR_V_INT_T_P_DEEP_COPY && !defined(ERR_ERR_V_INT_T_P_IFREE)
#define ERR_ERR_V_INT_T_P_IFREE(A1) err_v_int_delete((A1))
#endif

#if ERR_ERR_V_INT_T_CONST_P_DEEP_COPY && !defined(ERR_ERR_V_INT_T_CONST_P_IFREE)
#define ERR_ERR_V_INT_T_CONST_P_IFREE(A1) err_v_int_delete((A1))
#endif

#if ERR_CONST_ERR_V_INT_T_P_DEEP_COPY && !defined(ERR_CONST_ERR_V_INT_T_P_IFREE)
#define ERR_CONST_ERR_V_INT_T_P_IFREE(A1) err_v_int_delete((A1))
#endif

#if ERR_ERRVINT_P_DEEP_COPY && !defined(ERR_ERRVINT_P_IFREE)
#define ERR_ERRVINT_P_IFREE(A1) delete((A1))
#endif

#if ERR_ERRVINT_CONST_P_DEEP_COPY && !defined(ERR_ERRVINT_CONST_P_IFREE)
#define ERR_ERRVINT_CONST_P_IFREE(A1) delete((A1))
#endif

#if ERR_CONST_ERRVINT_P_DEEP_COPY && !defined(ERR_CONST_ERRVINT_P_IFREE)
#define ERR_CONST_ERRVINT_P_IFREE(A1) delete((A1))
#endif

#if ERR_ERR_V_INT_TP_DEEP_COPY && !defined(ERR_ERR_V_INT_TP_OFREE)
#define ERR_ERR_V_INT_TP_OFREE(A1) err_v_int_delete((A1))
#endif

#if ERR_ERR_V_INT_T_CONSTP_DEEP_COPY && !defined(ERR_ERR_V_INT_T_CONSTP_OFREE)
#define ERR_ERR_V_INT_T_CONSTP_OFREE(A1) err_v_int_delete((A1))
#endif

#if ERR_CONST_ERR_V_INT_TP_DEEP_COPY && !defined(ERR_CONST_ERR_V_INT_TP_OFREE)
#define ERR_CONST_ERR_V_INT_TP_OFREE(A1) err_v_int_delete((A1))
#endif

#if ERR_ERRVINTP_DEEP_COPY && !defined(ERR_ERRVINTP_OFREE)
#define ERR_ERRVINTP_OFREE(A1) delete((A1))
#endif

#if ERR_ERRVINT_CONSTP_DEEP_COPY && !defined(ERR_ERRVINT_CONSTP_OFREE)
#define ERR_ERRVINT_CONSTP_OFREE(A1) delete((A1))
#endif

#if ERR_CONST_ERRVINTP_DEEP_COPY && !defined(ERR_CONST_ERRVINTP_OFREE)
#define ERR_CONST_ERRVINTP_OFREE(A1) delete((A1))
#endif

#if ERR_ERR_V_INT_T_P_DEEP_COPY && !defined(ERR_ERR_V_INT_T_P_OFREE)
#define ERR_ERR_V_INT_T_P_OFREE(A1) err_v_int_delete((A1))
#endif

#if ERR_ERR_V_INT_T_CONST_P_DEEP_COPY && !defined(ERR_ERR_V_INT_T_CONST_P_OFREE)
#define ERR_ERR_V_INT_T_CONST_P_OFREE(A1) err_v_int_delete((A1))
#endif

#if ERR_CONST_ERR_V_INT_T_P_DEEP_COPY && !defined(ERR_CONST_ERR_V_INT_T_P_OFREE)
#define ERR_CONST_ERR_V_INT_T_P_OFREE(A1) err_v_int_delete((A1))
#endif

#if ERR_ERRVINT_P_DEEP_COPY && !defined(ERR_ERRVINT_P_OFREE)
#define ERR_ERRVINT_P_OFREE(A1) delete((A1))
#endif

#if ERR_ERRVINT_CONST_P_DEEP_COPY && !defined(ERR_ERRVINT_CONST_P_OFREE)
#define ERR_ERRVINT_CONST_P_OFREE(A1) delete((A1))
#endif

#if ERR_CONST_ERRVINT_P_DEEP_COPY && !defined(ERR_CONST_ERRVINT_P_OFREE)
#define ERR_CONST_ERRVINT_P_OFREE(A1) delete((A1))
#endif

#ifndef ERR_ERRVINT_CONSTRUCTOR
#define ERR_ERRVINT_CONSTRUCTOR(A1) ((A1)._constructor())
#endif

#ifndef ERR_ERRVINT_DESTRUCTOR
#define ERR_ERRVINT_DESTRUCTOR(A1) ((A1)._destructor())
#endif


#endif /* defined ERWIN_ERR_V_INT_f_h */

