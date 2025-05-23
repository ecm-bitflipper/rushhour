
#ifndef ERWIN_ERR_V_CALLBACK_f_h
#define ERWIN_ERR_V_CALLBACK_f_h

/* Unification of ErrVCallback and err_v_callback_t: they are identical now. */
struct err_v_callback_t;

#ifndef __cplusplus
typedef struct err_v_callback_t err_v_callback_t;
#endif /* not defined __cplusplus */

typedef err_v_callback_t ErrVCallback;

typedef err_v_callback_t *err_v_callback_t_p;

typedef err_v_callback_t const *err_v_callback_t_const_p;

#define ERR_V_CALLBACK_SIG 632426688



#ifdef ERR_ERR_V_CALLBACK_TP_DEEP
#  if ERR_ERR_V_CALLBACK_TP_DEEP
#    ifndef ERR_ERR_V_CALLBACK_TP_DEEP_COPY
#      define ERR_ERR_V_CALLBACK_TP_DEEP_COPY 1
#    endif
#    ifndef ERR_ERR_V_CALLBACK_TP_DEEP_COMPARE
#      define ERR_ERR_V_CALLBACK_TP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERR_V_CALLBACK_TP_DEEP_COPY
#      define ERR_ERR_V_CALLBACK_TP_DEEP_COPY 0
#    endif
#    ifndef ERR_ERR_V_CALLBACK_TP_DEEP_COMPARE
#      define ERR_ERR_V_CALLBACK_TP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERR_V_CALLBACK_TP_DEEP_COPY
#define ERR_ERR_V_CALLBACK_TP_DEEP_COPY 0
#endif /* !defined ERR_ERR_V_CALLBACK_TP_DEEP_COPY */

#ifndef ERR_ERR_V_CALLBACK_TP_DEEP_COMPARE
#define ERR_ERR_V_CALLBACK_TP_DEEP_COMPARE 0
#endif /* !defined ERR_ERR_V_CALLBACK_TP_DEEP_COMPARE */

#ifdef ERR_ERR_V_CALLBACK_T_CONSTP_DEEP
#  if ERR_ERR_V_CALLBACK_T_CONSTP_DEEP
#    ifndef ERR_ERR_V_CALLBACK_T_CONSTP_DEEP_COPY
#      define ERR_ERR_V_CALLBACK_T_CONSTP_DEEP_COPY 1
#    endif
#    ifndef ERR_ERR_V_CALLBACK_T_CONSTP_DEEP_COMPARE
#      define ERR_ERR_V_CALLBACK_T_CONSTP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERR_V_CALLBACK_T_CONSTP_DEEP_COPY
#      define ERR_ERR_V_CALLBACK_T_CONSTP_DEEP_COPY 0
#    endif
#    ifndef ERR_ERR_V_CALLBACK_T_CONSTP_DEEP_COMPARE
#      define ERR_ERR_V_CALLBACK_T_CONSTP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERR_V_CALLBACK_T_CONSTP_DEEP_COPY
#define ERR_ERR_V_CALLBACK_T_CONSTP_DEEP_COPY 0
#endif /* !defined ERR_ERR_V_CALLBACK_T_CONSTP_DEEP_COPY */

#ifndef ERR_ERR_V_CALLBACK_T_CONSTP_DEEP_COMPARE
#define ERR_ERR_V_CALLBACK_T_CONSTP_DEEP_COMPARE 0
#endif /* !defined ERR_ERR_V_CALLBACK_T_CONSTP_DEEP_COMPARE */

#ifdef ERR_CONST_ERR_V_CALLBACK_TP_DEEP
#  if ERR_CONST_ERR_V_CALLBACK_TP_DEEP
#    ifndef ERR_CONST_ERR_V_CALLBACK_TP_DEEP_COPY
#      define ERR_CONST_ERR_V_CALLBACK_TP_DEEP_COPY 1
#    endif
#    ifndef ERR_CONST_ERR_V_CALLBACK_TP_DEEP_COMPARE
#      define ERR_CONST_ERR_V_CALLBACK_TP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_CONST_ERR_V_CALLBACK_TP_DEEP_COPY
#      define ERR_CONST_ERR_V_CALLBACK_TP_DEEP_COPY 0
#    endif
#    ifndef ERR_CONST_ERR_V_CALLBACK_TP_DEEP_COMPARE
#      define ERR_CONST_ERR_V_CALLBACK_TP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_CONST_ERR_V_CALLBACK_TP_DEEP_COPY
#define ERR_CONST_ERR_V_CALLBACK_TP_DEEP_COPY 0
#endif /* !defined ERR_CONST_ERR_V_CALLBACK_TP_DEEP_COPY */

#ifndef ERR_CONST_ERR_V_CALLBACK_TP_DEEP_COMPARE
#define ERR_CONST_ERR_V_CALLBACK_TP_DEEP_COMPARE 0
#endif /* !defined ERR_CONST_ERR_V_CALLBACK_TP_DEEP_COMPARE */

#ifdef ERR_ERRVCALLBACKP_DEEP
#  if ERR_ERRVCALLBACKP_DEEP
#    ifndef ERR_ERRVCALLBACKP_DEEP_COPY
#      define ERR_ERRVCALLBACKP_DEEP_COPY 1
#    endif
#    ifndef ERR_ERRVCALLBACKP_DEEP_COMPARE
#      define ERR_ERRVCALLBACKP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERRVCALLBACKP_DEEP_COPY
#      define ERR_ERRVCALLBACKP_DEEP_COPY 0
#    endif
#    ifndef ERR_ERRVCALLBACKP_DEEP_COMPARE
#      define ERR_ERRVCALLBACKP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERRVCALLBACKP_DEEP_COPY
#define ERR_ERRVCALLBACKP_DEEP_COPY 0
#endif /* !defined ERR_ERRVCALLBACKP_DEEP_COPY */

#ifndef ERR_ERRVCALLBACKP_DEEP_COMPARE
#define ERR_ERRVCALLBACKP_DEEP_COMPARE 0
#endif /* !defined ERR_ERRVCALLBACKP_DEEP_COMPARE */

#ifdef ERR_ERRVCALLBACK_CONSTP_DEEP
#  if ERR_ERRVCALLBACK_CONSTP_DEEP
#    ifndef ERR_ERRVCALLBACK_CONSTP_DEEP_COPY
#      define ERR_ERRVCALLBACK_CONSTP_DEEP_COPY 1
#    endif
#    ifndef ERR_ERRVCALLBACK_CONSTP_DEEP_COMPARE
#      define ERR_ERRVCALLBACK_CONSTP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERRVCALLBACK_CONSTP_DEEP_COPY
#      define ERR_ERRVCALLBACK_CONSTP_DEEP_COPY 0
#    endif
#    ifndef ERR_ERRVCALLBACK_CONSTP_DEEP_COMPARE
#      define ERR_ERRVCALLBACK_CONSTP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERRVCALLBACK_CONSTP_DEEP_COPY
#define ERR_ERRVCALLBACK_CONSTP_DEEP_COPY 0
#endif /* !defined ERR_ERRVCALLBACK_CONSTP_DEEP_COPY */

#ifndef ERR_ERRVCALLBACK_CONSTP_DEEP_COMPARE
#define ERR_ERRVCALLBACK_CONSTP_DEEP_COMPARE 0
#endif /* !defined ERR_ERRVCALLBACK_CONSTP_DEEP_COMPARE */

#ifdef ERR_CONST_ERRVCALLBACKP_DEEP
#  if ERR_CONST_ERRVCALLBACKP_DEEP
#    ifndef ERR_CONST_ERRVCALLBACKP_DEEP_COPY
#      define ERR_CONST_ERRVCALLBACKP_DEEP_COPY 1
#    endif
#    ifndef ERR_CONST_ERRVCALLBACKP_DEEP_COMPARE
#      define ERR_CONST_ERRVCALLBACKP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_CONST_ERRVCALLBACKP_DEEP_COPY
#      define ERR_CONST_ERRVCALLBACKP_DEEP_COPY 0
#    endif
#    ifndef ERR_CONST_ERRVCALLBACKP_DEEP_COMPARE
#      define ERR_CONST_ERRVCALLBACKP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_CONST_ERRVCALLBACKP_DEEP_COPY
#define ERR_CONST_ERRVCALLBACKP_DEEP_COPY 0
#endif /* !defined ERR_CONST_ERRVCALLBACKP_DEEP_COPY */

#ifndef ERR_CONST_ERRVCALLBACKP_DEEP_COMPARE
#define ERR_CONST_ERRVCALLBACKP_DEEP_COMPARE 0
#endif /* !defined ERR_CONST_ERRVCALLBACKP_DEEP_COMPARE */

#ifdef ERR_ERR_V_CALLBACK_T_P_DEEP
#  if ERR_ERR_V_CALLBACK_T_P_DEEP
#    ifndef ERR_ERR_V_CALLBACK_T_P_DEEP_COPY
#      define ERR_ERR_V_CALLBACK_T_P_DEEP_COPY 1
#    endif
#    ifndef ERR_ERR_V_CALLBACK_T_P_DEEP_COMPARE
#      define ERR_ERR_V_CALLBACK_T_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERR_V_CALLBACK_T_P_DEEP_COPY
#      define ERR_ERR_V_CALLBACK_T_P_DEEP_COPY 0
#    endif
#    ifndef ERR_ERR_V_CALLBACK_T_P_DEEP_COMPARE
#      define ERR_ERR_V_CALLBACK_T_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERR_V_CALLBACK_T_P_DEEP_COPY
#define ERR_ERR_V_CALLBACK_T_P_DEEP_COPY 0
#endif /* !defined ERR_ERR_V_CALLBACK_T_P_DEEP_COPY */

#ifndef ERR_ERR_V_CALLBACK_T_P_DEEP_COMPARE
#define ERR_ERR_V_CALLBACK_T_P_DEEP_COMPARE 0
#endif /* !defined ERR_ERR_V_CALLBACK_T_P_DEEP_COMPARE */

#ifdef ERR_ERR_V_CALLBACK_T_CONST_P_DEEP
#  if ERR_ERR_V_CALLBACK_T_CONST_P_DEEP
#    ifndef ERR_ERR_V_CALLBACK_T_CONST_P_DEEP_COPY
#      define ERR_ERR_V_CALLBACK_T_CONST_P_DEEP_COPY 1
#    endif
#    ifndef ERR_ERR_V_CALLBACK_T_CONST_P_DEEP_COMPARE
#      define ERR_ERR_V_CALLBACK_T_CONST_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERR_V_CALLBACK_T_CONST_P_DEEP_COPY
#      define ERR_ERR_V_CALLBACK_T_CONST_P_DEEP_COPY 0
#    endif
#    ifndef ERR_ERR_V_CALLBACK_T_CONST_P_DEEP_COMPARE
#      define ERR_ERR_V_CALLBACK_T_CONST_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERR_V_CALLBACK_T_CONST_P_DEEP_COPY
#define ERR_ERR_V_CALLBACK_T_CONST_P_DEEP_COPY 0
#endif /* !defined ERR_ERR_V_CALLBACK_T_CONST_P_DEEP_COPY */

#ifndef ERR_ERR_V_CALLBACK_T_CONST_P_DEEP_COMPARE
#define ERR_ERR_V_CALLBACK_T_CONST_P_DEEP_COMPARE 0
#endif /* !defined ERR_ERR_V_CALLBACK_T_CONST_P_DEEP_COMPARE */

#ifdef ERR_CONST_ERR_V_CALLBACK_T_P_DEEP
#  if ERR_CONST_ERR_V_CALLBACK_T_P_DEEP
#    ifndef ERR_CONST_ERR_V_CALLBACK_T_P_DEEP_COPY
#      define ERR_CONST_ERR_V_CALLBACK_T_P_DEEP_COPY 1
#    endif
#    ifndef ERR_CONST_ERR_V_CALLBACK_T_P_DEEP_COMPARE
#      define ERR_CONST_ERR_V_CALLBACK_T_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_CONST_ERR_V_CALLBACK_T_P_DEEP_COPY
#      define ERR_CONST_ERR_V_CALLBACK_T_P_DEEP_COPY 0
#    endif
#    ifndef ERR_CONST_ERR_V_CALLBACK_T_P_DEEP_COMPARE
#      define ERR_CONST_ERR_V_CALLBACK_T_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_CONST_ERR_V_CALLBACK_T_P_DEEP_COPY
#define ERR_CONST_ERR_V_CALLBACK_T_P_DEEP_COPY 0
#endif /* !defined ERR_CONST_ERR_V_CALLBACK_T_P_DEEP_COPY */

#ifndef ERR_CONST_ERR_V_CALLBACK_T_P_DEEP_COMPARE
#define ERR_CONST_ERR_V_CALLBACK_T_P_DEEP_COMPARE 0
#endif /* !defined ERR_CONST_ERR_V_CALLBACK_T_P_DEEP_COMPARE */

#ifdef ERR_ERRVCALLBACK_P_DEEP
#  if ERR_ERRVCALLBACK_P_DEEP
#    ifndef ERR_ERRVCALLBACK_P_DEEP_COPY
#      define ERR_ERRVCALLBACK_P_DEEP_COPY 1
#    endif
#    ifndef ERR_ERRVCALLBACK_P_DEEP_COMPARE
#      define ERR_ERRVCALLBACK_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERRVCALLBACK_P_DEEP_COPY
#      define ERR_ERRVCALLBACK_P_DEEP_COPY 0
#    endif
#    ifndef ERR_ERRVCALLBACK_P_DEEP_COMPARE
#      define ERR_ERRVCALLBACK_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERRVCALLBACK_P_DEEP_COPY
#define ERR_ERRVCALLBACK_P_DEEP_COPY 0
#endif /* !defined ERR_ERRVCALLBACK_P_DEEP_COPY */

#ifndef ERR_ERRVCALLBACK_P_DEEP_COMPARE
#define ERR_ERRVCALLBACK_P_DEEP_COMPARE 0
#endif /* !defined ERR_ERRVCALLBACK_P_DEEP_COMPARE */

#ifdef ERR_ERRVCALLBACK_CONST_P_DEEP
#  if ERR_ERRVCALLBACK_CONST_P_DEEP
#    ifndef ERR_ERRVCALLBACK_CONST_P_DEEP_COPY
#      define ERR_ERRVCALLBACK_CONST_P_DEEP_COPY 1
#    endif
#    ifndef ERR_ERRVCALLBACK_CONST_P_DEEP_COMPARE
#      define ERR_ERRVCALLBACK_CONST_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERRVCALLBACK_CONST_P_DEEP_COPY
#      define ERR_ERRVCALLBACK_CONST_P_DEEP_COPY 0
#    endif
#    ifndef ERR_ERRVCALLBACK_CONST_P_DEEP_COMPARE
#      define ERR_ERRVCALLBACK_CONST_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERRVCALLBACK_CONST_P_DEEP_COPY
#define ERR_ERRVCALLBACK_CONST_P_DEEP_COPY 0
#endif /* !defined ERR_ERRVCALLBACK_CONST_P_DEEP_COPY */

#ifndef ERR_ERRVCALLBACK_CONST_P_DEEP_COMPARE
#define ERR_ERRVCALLBACK_CONST_P_DEEP_COMPARE 0
#endif /* !defined ERR_ERRVCALLBACK_CONST_P_DEEP_COMPARE */

#ifdef ERR_CONST_ERRVCALLBACK_P_DEEP
#  if ERR_CONST_ERRVCALLBACK_P_DEEP
#    ifndef ERR_CONST_ERRVCALLBACK_P_DEEP_COPY
#      define ERR_CONST_ERRVCALLBACK_P_DEEP_COPY 1
#    endif
#    ifndef ERR_CONST_ERRVCALLBACK_P_DEEP_COMPARE
#      define ERR_CONST_ERRVCALLBACK_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_CONST_ERRVCALLBACK_P_DEEP_COPY
#      define ERR_CONST_ERRVCALLBACK_P_DEEP_COPY 0
#    endif
#    ifndef ERR_CONST_ERRVCALLBACK_P_DEEP_COMPARE
#      define ERR_CONST_ERRVCALLBACK_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_CONST_ERRVCALLBACK_P_DEEP_COPY
#define ERR_CONST_ERRVCALLBACK_P_DEEP_COPY 0
#endif /* !defined ERR_CONST_ERRVCALLBACK_P_DEEP_COPY */

#ifndef ERR_CONST_ERRVCALLBACK_P_DEEP_COMPARE
#define ERR_CONST_ERRVCALLBACK_P_DEEP_COMPARE 0
#endif /* !defined ERR_CONST_ERRVCALLBACK_P_DEEP_COMPARE */

#if ERR_ERR_V_CALLBACK_TP_DEEP_COMPARE && !defined(ERR_ERR_V_CALLBACK_TP_HASH_RAW)
#define ERR_ERR_V_CALLBACK_TP_HASH_RAW(A1) err_v_callback_hash_raw((A1))
#endif

#if ERR_ERR_V_CALLBACK_T_CONSTP_DEEP_COMPARE && !defined(ERR_ERR_V_CALLBACK_T_CONSTP_HASH_RAW)
#define ERR_ERR_V_CALLBACK_T_CONSTP_HASH_RAW(A1) err_v_callback_hash_raw((A1))
#endif

#if ERR_CONST_ERR_V_CALLBACK_TP_DEEP_COMPARE && !defined(ERR_CONST_ERR_V_CALLBACK_TP_HASH_RAW)
#define ERR_CONST_ERR_V_CALLBACK_TP_HASH_RAW(A1) err_v_callback_hash_raw((A1))
#endif

#if ERR_ERRVCALLBACKP_DEEP_COMPARE && !defined(ERR_ERRVCALLBACKP_HASH_RAW)
#define ERR_ERRVCALLBACKP_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if ERR_ERRVCALLBACK_CONSTP_DEEP_COMPARE && !defined(ERR_ERRVCALLBACK_CONSTP_HASH_RAW)
#define ERR_ERRVCALLBACK_CONSTP_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if ERR_CONST_ERRVCALLBACKP_DEEP_COMPARE && !defined(ERR_CONST_ERRVCALLBACKP_HASH_RAW)
#define ERR_CONST_ERRVCALLBACKP_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if ERR_ERR_V_CALLBACK_T_P_DEEP_COMPARE && !defined(ERR_ERR_V_CALLBACK_T_P_HASH_RAW)
#define ERR_ERR_V_CALLBACK_T_P_HASH_RAW(A1) err_v_callback_hash_raw((A1))
#endif

#if ERR_ERR_V_CALLBACK_T_CONST_P_DEEP_COMPARE && !defined(ERR_ERR_V_CALLBACK_T_CONST_P_HASH_RAW)
#define ERR_ERR_V_CALLBACK_T_CONST_P_HASH_RAW(A1) err_v_callback_hash_raw((A1))
#endif

#if ERR_CONST_ERR_V_CALLBACK_T_P_DEEP_COMPARE && !defined(ERR_CONST_ERR_V_CALLBACK_T_P_HASH_RAW)
#define ERR_CONST_ERR_V_CALLBACK_T_P_HASH_RAW(A1) err_v_callback_hash_raw((A1))
#endif

#if ERR_ERRVCALLBACK_P_DEEP_COMPARE && !defined(ERR_ERRVCALLBACK_P_HASH_RAW)
#define ERR_ERRVCALLBACK_P_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if ERR_ERRVCALLBACK_CONST_P_DEEP_COMPARE && !defined(ERR_ERRVCALLBACK_CONST_P_HASH_RAW)
#define ERR_ERRVCALLBACK_CONST_P_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if ERR_CONST_ERRVCALLBACK_P_DEEP_COMPARE && !defined(ERR_CONST_ERRVCALLBACK_P_HASH_RAW)
#define ERR_CONST_ERRVCALLBACK_P_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#ifndef ERR_ERRVCALLBACK_HASH_RAW
#define ERR_ERRVCALLBACK_HASH_RAW(A1) ((A1).hash_raw())
#endif

#if ERR_ERR_V_CALLBACK_TP_DEEP_COMPARE && !defined(ERR_ERR_V_CALLBACK_TP_CMP)
#define ERR_ERR_V_CALLBACK_TP_CMP(A1,A2) err_v_callback_cmp((A1),(A2),NULL)
#endif

#if ERR_ERR_V_CALLBACK_T_CONSTP_DEEP_COMPARE && !defined(ERR_ERR_V_CALLBACK_T_CONSTP_CMP)
#define ERR_ERR_V_CALLBACK_T_CONSTP_CMP(A1,A2) err_v_callback_cmp((A1),(A2),NULL)
#endif

#if ERR_CONST_ERR_V_CALLBACK_TP_DEEP_COMPARE && !defined(ERR_CONST_ERR_V_CALLBACK_TP_CMP)
#define ERR_CONST_ERR_V_CALLBACK_TP_CMP(A1,A2) err_v_callback_cmp((A1),(A2),NULL)
#endif

#if ERR_ERRVCALLBACKP_DEEP_COMPARE && !defined(ERR_ERRVCALLBACKP_CMP)
#define ERR_ERRVCALLBACKP_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if ERR_ERRVCALLBACK_CONSTP_DEEP_COMPARE && !defined(ERR_ERRVCALLBACK_CONSTP_CMP)
#define ERR_ERRVCALLBACK_CONSTP_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if ERR_CONST_ERRVCALLBACKP_DEEP_COMPARE && !defined(ERR_CONST_ERRVCALLBACKP_CMP)
#define ERR_CONST_ERRVCALLBACKP_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if ERR_ERR_V_CALLBACK_T_P_DEEP_COMPARE && !defined(ERR_ERR_V_CALLBACK_T_P_CMP)
#define ERR_ERR_V_CALLBACK_T_P_CMP(A1,A2) err_v_callback_cmp((A1),(A2),NULL)
#endif

#if ERR_ERR_V_CALLBACK_T_CONST_P_DEEP_COMPARE && !defined(ERR_ERR_V_CALLBACK_T_CONST_P_CMP)
#define ERR_ERR_V_CALLBACK_T_CONST_P_CMP(A1,A2) err_v_callback_cmp((A1),(A2),NULL)
#endif

#if ERR_CONST_ERR_V_CALLBACK_T_P_DEEP_COMPARE && !defined(ERR_CONST_ERR_V_CALLBACK_T_P_CMP)
#define ERR_CONST_ERR_V_CALLBACK_T_P_CMP(A1,A2) err_v_callback_cmp((A1),(A2),NULL)
#endif

#if ERR_ERRVCALLBACK_P_DEEP_COMPARE && !defined(ERR_ERRVCALLBACK_P_CMP)
#define ERR_ERRVCALLBACK_P_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if ERR_ERRVCALLBACK_CONST_P_DEEP_COMPARE && !defined(ERR_ERRVCALLBACK_CONST_P_CMP)
#define ERR_ERRVCALLBACK_CONST_P_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if ERR_CONST_ERRVCALLBACK_P_DEEP_COMPARE && !defined(ERR_CONST_ERRVCALLBACK_P_CMP)
#define ERR_CONST_ERRVCALLBACK_P_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#ifndef ERR_ERRVCALLBACK_CMP
#define ERR_ERRVCALLBACK_CMP(A1,A2) ((A1).cmp((A2),NULL))
#endif

#ifndef ERR_ERRVCALLBACK_ZERO
#define ERR_ERRVCALLBACK_ZERO (ErrVCallback::static_zero())
#endif

#if ERR_ERR_V_CALLBACK_TP_DEEP_COPY && !defined(ERR_ERR_V_CALLBACK_TP_ICOPY)
#define ERR_ERR_V_CALLBACK_TP_ICOPY(A1,A2) err_v_callback_copy_err((A1),(A2))
#endif

#if ERR_ERR_V_CALLBACK_T_CONSTP_DEEP_COPY && !defined(ERR_ERR_V_CALLBACK_T_CONSTP_ICOPY)
#define ERR_ERR_V_CALLBACK_T_CONSTP_ICOPY(A1,A2) err_v_callback_copy_err((A1),(A2))
#endif

#if ERR_CONST_ERR_V_CALLBACK_TP_DEEP_COPY && !defined(ERR_CONST_ERR_V_CALLBACK_TP_ICOPY)
#define ERR_CONST_ERR_V_CALLBACK_TP_ICOPY(A1,A2) err_v_callback_copy_err((A1),(A2))
#endif

#if ERR_ERRVCALLBACKP_DEEP_COPY && !defined(ERR_ERRVCALLBACKP_ICOPY)
#define ERR_ERRVCALLBACKP_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERRVCALLBACK_CONSTP_DEEP_COPY && !defined(ERR_ERRVCALLBACK_CONSTP_ICOPY)
#define ERR_ERRVCALLBACK_CONSTP_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_CONST_ERRVCALLBACKP_DEEP_COPY && !defined(ERR_CONST_ERRVCALLBACKP_ICOPY)
#define ERR_CONST_ERRVCALLBACKP_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERR_V_CALLBACK_T_P_DEEP_COPY && !defined(ERR_ERR_V_CALLBACK_T_P_ICOPY)
#define ERR_ERR_V_CALLBACK_T_P_ICOPY(A1,A2) err_v_callback_copy_err((A1),(A2))
#endif

#if ERR_ERR_V_CALLBACK_T_CONST_P_DEEP_COPY && !defined(ERR_ERR_V_CALLBACK_T_CONST_P_ICOPY)
#define ERR_ERR_V_CALLBACK_T_CONST_P_ICOPY(A1,A2) err_v_callback_copy_err((A1),(A2))
#endif

#if ERR_CONST_ERR_V_CALLBACK_T_P_DEEP_COPY && !defined(ERR_CONST_ERR_V_CALLBACK_T_P_ICOPY)
#define ERR_CONST_ERR_V_CALLBACK_T_P_ICOPY(A1,A2) err_v_callback_copy_err((A1),(A2))
#endif

#if ERR_ERRVCALLBACK_P_DEEP_COPY && !defined(ERR_ERRVCALLBACK_P_ICOPY)
#define ERR_ERRVCALLBACK_P_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERRVCALLBACK_CONST_P_DEEP_COPY && !defined(ERR_ERRVCALLBACK_CONST_P_ICOPY)
#define ERR_ERRVCALLBACK_CONST_P_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_CONST_ERRVCALLBACK_P_DEEP_COPY && !defined(ERR_CONST_ERRVCALLBACK_P_ICOPY)
#define ERR_CONST_ERRVCALLBACK_P_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERR_V_CALLBACK_TP_DEEP_COPY && !defined(ERR_ERR_V_CALLBACK_TP_OCOPY)
#define ERR_ERR_V_CALLBACK_TP_OCOPY(A1,A2) err_v_callback_copy_err((A1),(A2))
#endif

#if ERR_ERR_V_CALLBACK_T_CONSTP_DEEP_COPY && !defined(ERR_ERR_V_CALLBACK_T_CONSTP_OCOPY)
#define ERR_ERR_V_CALLBACK_T_CONSTP_OCOPY(A1,A2) err_v_callback_copy_err((A1),(A2))
#endif

#if ERR_CONST_ERR_V_CALLBACK_TP_DEEP_COPY && !defined(ERR_CONST_ERR_V_CALLBACK_TP_OCOPY)
#define ERR_CONST_ERR_V_CALLBACK_TP_OCOPY(A1,A2) err_v_callback_copy_err((A1),(A2))
#endif

#if ERR_ERRVCALLBACKP_DEEP_COPY && !defined(ERR_ERRVCALLBACKP_OCOPY)
#define ERR_ERRVCALLBACKP_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERRVCALLBACK_CONSTP_DEEP_COPY && !defined(ERR_ERRVCALLBACK_CONSTP_OCOPY)
#define ERR_ERRVCALLBACK_CONSTP_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_CONST_ERRVCALLBACKP_DEEP_COPY && !defined(ERR_CONST_ERRVCALLBACKP_OCOPY)
#define ERR_CONST_ERRVCALLBACKP_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERR_V_CALLBACK_T_P_DEEP_COPY && !defined(ERR_ERR_V_CALLBACK_T_P_OCOPY)
#define ERR_ERR_V_CALLBACK_T_P_OCOPY(A1,A2) err_v_callback_copy_err((A1),(A2))
#endif

#if ERR_ERR_V_CALLBACK_T_CONST_P_DEEP_COPY && !defined(ERR_ERR_V_CALLBACK_T_CONST_P_OCOPY)
#define ERR_ERR_V_CALLBACK_T_CONST_P_OCOPY(A1,A2) err_v_callback_copy_err((A1),(A2))
#endif

#if ERR_CONST_ERR_V_CALLBACK_T_P_DEEP_COPY && !defined(ERR_CONST_ERR_V_CALLBACK_T_P_OCOPY)
#define ERR_CONST_ERR_V_CALLBACK_T_P_OCOPY(A1,A2) err_v_callback_copy_err((A1),(A2))
#endif

#if ERR_ERRVCALLBACK_P_DEEP_COPY && !defined(ERR_ERRVCALLBACK_P_OCOPY)
#define ERR_ERRVCALLBACK_P_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERRVCALLBACK_CONST_P_DEEP_COPY && !defined(ERR_ERRVCALLBACK_CONST_P_OCOPY)
#define ERR_ERRVCALLBACK_CONST_P_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_CONST_ERRVCALLBACK_P_DEEP_COPY && !defined(ERR_CONST_ERRVCALLBACK_P_OCOPY)
#define ERR_CONST_ERRVCALLBACK_P_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERR_V_CALLBACK_TP_DEEP_COPY && !defined(ERR_ERR_V_CALLBACK_TP_IFREE)
#define ERR_ERR_V_CALLBACK_TP_IFREE(A1) err_v_callback_delete((A1))
#endif

#if ERR_ERR_V_CALLBACK_T_CONSTP_DEEP_COPY && !defined(ERR_ERR_V_CALLBACK_T_CONSTP_IFREE)
#define ERR_ERR_V_CALLBACK_T_CONSTP_IFREE(A1) err_v_callback_delete((A1))
#endif

#if ERR_CONST_ERR_V_CALLBACK_TP_DEEP_COPY && !defined(ERR_CONST_ERR_V_CALLBACK_TP_IFREE)
#define ERR_CONST_ERR_V_CALLBACK_TP_IFREE(A1) err_v_callback_delete((A1))
#endif

#if ERR_ERRVCALLBACKP_DEEP_COPY && !defined(ERR_ERRVCALLBACKP_IFREE)
#define ERR_ERRVCALLBACKP_IFREE(A1) delete((A1))
#endif

#if ERR_ERRVCALLBACK_CONSTP_DEEP_COPY && !defined(ERR_ERRVCALLBACK_CONSTP_IFREE)
#define ERR_ERRVCALLBACK_CONSTP_IFREE(A1) delete((A1))
#endif

#if ERR_CONST_ERRVCALLBACKP_DEEP_COPY && !defined(ERR_CONST_ERRVCALLBACKP_IFREE)
#define ERR_CONST_ERRVCALLBACKP_IFREE(A1) delete((A1))
#endif

#if ERR_ERR_V_CALLBACK_T_P_DEEP_COPY && !defined(ERR_ERR_V_CALLBACK_T_P_IFREE)
#define ERR_ERR_V_CALLBACK_T_P_IFREE(A1) err_v_callback_delete((A1))
#endif

#if ERR_ERR_V_CALLBACK_T_CONST_P_DEEP_COPY && !defined(ERR_ERR_V_CALLBACK_T_CONST_P_IFREE)
#define ERR_ERR_V_CALLBACK_T_CONST_P_IFREE(A1) err_v_callback_delete((A1))
#endif

#if ERR_CONST_ERR_V_CALLBACK_T_P_DEEP_COPY && !defined(ERR_CONST_ERR_V_CALLBACK_T_P_IFREE)
#define ERR_CONST_ERR_V_CALLBACK_T_P_IFREE(A1) err_v_callback_delete((A1))
#endif

#if ERR_ERRVCALLBACK_P_DEEP_COPY && !defined(ERR_ERRVCALLBACK_P_IFREE)
#define ERR_ERRVCALLBACK_P_IFREE(A1) delete((A1))
#endif

#if ERR_ERRVCALLBACK_CONST_P_DEEP_COPY && !defined(ERR_ERRVCALLBACK_CONST_P_IFREE)
#define ERR_ERRVCALLBACK_CONST_P_IFREE(A1) delete((A1))
#endif

#if ERR_CONST_ERRVCALLBACK_P_DEEP_COPY && !defined(ERR_CONST_ERRVCALLBACK_P_IFREE)
#define ERR_CONST_ERRVCALLBACK_P_IFREE(A1) delete((A1))
#endif

#if ERR_ERR_V_CALLBACK_TP_DEEP_COPY && !defined(ERR_ERR_V_CALLBACK_TP_OFREE)
#define ERR_ERR_V_CALLBACK_TP_OFREE(A1) err_v_callback_delete((A1))
#endif

#if ERR_ERR_V_CALLBACK_T_CONSTP_DEEP_COPY && !defined(ERR_ERR_V_CALLBACK_T_CONSTP_OFREE)
#define ERR_ERR_V_CALLBACK_T_CONSTP_OFREE(A1) err_v_callback_delete((A1))
#endif

#if ERR_CONST_ERR_V_CALLBACK_TP_DEEP_COPY && !defined(ERR_CONST_ERR_V_CALLBACK_TP_OFREE)
#define ERR_CONST_ERR_V_CALLBACK_TP_OFREE(A1) err_v_callback_delete((A1))
#endif

#if ERR_ERRVCALLBACKP_DEEP_COPY && !defined(ERR_ERRVCALLBACKP_OFREE)
#define ERR_ERRVCALLBACKP_OFREE(A1) delete((A1))
#endif

#if ERR_ERRVCALLBACK_CONSTP_DEEP_COPY && !defined(ERR_ERRVCALLBACK_CONSTP_OFREE)
#define ERR_ERRVCALLBACK_CONSTP_OFREE(A1) delete((A1))
#endif

#if ERR_CONST_ERRVCALLBACKP_DEEP_COPY && !defined(ERR_CONST_ERRVCALLBACKP_OFREE)
#define ERR_CONST_ERRVCALLBACKP_OFREE(A1) delete((A1))
#endif

#if ERR_ERR_V_CALLBACK_T_P_DEEP_COPY && !defined(ERR_ERR_V_CALLBACK_T_P_OFREE)
#define ERR_ERR_V_CALLBACK_T_P_OFREE(A1) err_v_callback_delete((A1))
#endif

#if ERR_ERR_V_CALLBACK_T_CONST_P_DEEP_COPY && !defined(ERR_ERR_V_CALLBACK_T_CONST_P_OFREE)
#define ERR_ERR_V_CALLBACK_T_CONST_P_OFREE(A1) err_v_callback_delete((A1))
#endif

#if ERR_CONST_ERR_V_CALLBACK_T_P_DEEP_COPY && !defined(ERR_CONST_ERR_V_CALLBACK_T_P_OFREE)
#define ERR_CONST_ERR_V_CALLBACK_T_P_OFREE(A1) err_v_callback_delete((A1))
#endif

#if ERR_ERRVCALLBACK_P_DEEP_COPY && !defined(ERR_ERRVCALLBACK_P_OFREE)
#define ERR_ERRVCALLBACK_P_OFREE(A1) delete((A1))
#endif

#if ERR_ERRVCALLBACK_CONST_P_DEEP_COPY && !defined(ERR_ERRVCALLBACK_CONST_P_OFREE)
#define ERR_ERRVCALLBACK_CONST_P_OFREE(A1) delete((A1))
#endif

#if ERR_CONST_ERRVCALLBACK_P_DEEP_COPY && !defined(ERR_CONST_ERRVCALLBACK_P_OFREE)
#define ERR_CONST_ERRVCALLBACK_P_OFREE(A1) delete((A1))
#endif

#ifndef ERR_ERRVCALLBACK_CONSTRUCTOR
#define ERR_ERRVCALLBACK_CONSTRUCTOR(A1) ((A1)._constructor())
#endif

#ifndef ERR_ERRVCALLBACK_DESTRUCTOR
#define ERR_ERRVCALLBACK_DESTRUCTOR(A1) ((A1)._destructor())
#endif


#endif /* defined ERWIN_ERR_V_CALLBACK_f_h */

