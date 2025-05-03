
#ifndef ERWIN_ERR_V_CHAR_f_h
#define ERWIN_ERR_V_CHAR_f_h

/* Unification of ErrVChar and err_v_char_t: they are identical now. */
struct err_v_char_t;

#ifndef __cplusplus
typedef struct err_v_char_t err_v_char_t;
#endif /* not defined __cplusplus */

typedef err_v_char_t ErrVChar;

typedef err_v_char_t *err_v_char_t_p;

typedef err_v_char_t const *err_v_char_t_const_p;

#define ERR_V_CHAR_SIG 1138051342



#ifdef ERR_ERR_V_CHAR_TP_DEEP
#  if ERR_ERR_V_CHAR_TP_DEEP
#    ifndef ERR_ERR_V_CHAR_TP_DEEP_COPY
#      define ERR_ERR_V_CHAR_TP_DEEP_COPY 1
#    endif
#    ifndef ERR_ERR_V_CHAR_TP_DEEP_COMPARE
#      define ERR_ERR_V_CHAR_TP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERR_V_CHAR_TP_DEEP_COPY
#      define ERR_ERR_V_CHAR_TP_DEEP_COPY 0
#    endif
#    ifndef ERR_ERR_V_CHAR_TP_DEEP_COMPARE
#      define ERR_ERR_V_CHAR_TP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERR_V_CHAR_TP_DEEP_COPY
#define ERR_ERR_V_CHAR_TP_DEEP_COPY 0
#endif /* !defined ERR_ERR_V_CHAR_TP_DEEP_COPY */

#ifndef ERR_ERR_V_CHAR_TP_DEEP_COMPARE
#define ERR_ERR_V_CHAR_TP_DEEP_COMPARE 0
#endif /* !defined ERR_ERR_V_CHAR_TP_DEEP_COMPARE */

#ifdef ERR_ERR_V_CHAR_T_CONSTP_DEEP
#  if ERR_ERR_V_CHAR_T_CONSTP_DEEP
#    ifndef ERR_ERR_V_CHAR_T_CONSTP_DEEP_COPY
#      define ERR_ERR_V_CHAR_T_CONSTP_DEEP_COPY 1
#    endif
#    ifndef ERR_ERR_V_CHAR_T_CONSTP_DEEP_COMPARE
#      define ERR_ERR_V_CHAR_T_CONSTP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERR_V_CHAR_T_CONSTP_DEEP_COPY
#      define ERR_ERR_V_CHAR_T_CONSTP_DEEP_COPY 0
#    endif
#    ifndef ERR_ERR_V_CHAR_T_CONSTP_DEEP_COMPARE
#      define ERR_ERR_V_CHAR_T_CONSTP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERR_V_CHAR_T_CONSTP_DEEP_COPY
#define ERR_ERR_V_CHAR_T_CONSTP_DEEP_COPY 0
#endif /* !defined ERR_ERR_V_CHAR_T_CONSTP_DEEP_COPY */

#ifndef ERR_ERR_V_CHAR_T_CONSTP_DEEP_COMPARE
#define ERR_ERR_V_CHAR_T_CONSTP_DEEP_COMPARE 0
#endif /* !defined ERR_ERR_V_CHAR_T_CONSTP_DEEP_COMPARE */

#ifdef ERR_CONST_ERR_V_CHAR_TP_DEEP
#  if ERR_CONST_ERR_V_CHAR_TP_DEEP
#    ifndef ERR_CONST_ERR_V_CHAR_TP_DEEP_COPY
#      define ERR_CONST_ERR_V_CHAR_TP_DEEP_COPY 1
#    endif
#    ifndef ERR_CONST_ERR_V_CHAR_TP_DEEP_COMPARE
#      define ERR_CONST_ERR_V_CHAR_TP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_CONST_ERR_V_CHAR_TP_DEEP_COPY
#      define ERR_CONST_ERR_V_CHAR_TP_DEEP_COPY 0
#    endif
#    ifndef ERR_CONST_ERR_V_CHAR_TP_DEEP_COMPARE
#      define ERR_CONST_ERR_V_CHAR_TP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_CONST_ERR_V_CHAR_TP_DEEP_COPY
#define ERR_CONST_ERR_V_CHAR_TP_DEEP_COPY 0
#endif /* !defined ERR_CONST_ERR_V_CHAR_TP_DEEP_COPY */

#ifndef ERR_CONST_ERR_V_CHAR_TP_DEEP_COMPARE
#define ERR_CONST_ERR_V_CHAR_TP_DEEP_COMPARE 0
#endif /* !defined ERR_CONST_ERR_V_CHAR_TP_DEEP_COMPARE */

#ifdef ERR_ERRVCHARP_DEEP
#  if ERR_ERRVCHARP_DEEP
#    ifndef ERR_ERRVCHARP_DEEP_COPY
#      define ERR_ERRVCHARP_DEEP_COPY 1
#    endif
#    ifndef ERR_ERRVCHARP_DEEP_COMPARE
#      define ERR_ERRVCHARP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERRVCHARP_DEEP_COPY
#      define ERR_ERRVCHARP_DEEP_COPY 0
#    endif
#    ifndef ERR_ERRVCHARP_DEEP_COMPARE
#      define ERR_ERRVCHARP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERRVCHARP_DEEP_COPY
#define ERR_ERRVCHARP_DEEP_COPY 0
#endif /* !defined ERR_ERRVCHARP_DEEP_COPY */

#ifndef ERR_ERRVCHARP_DEEP_COMPARE
#define ERR_ERRVCHARP_DEEP_COMPARE 0
#endif /* !defined ERR_ERRVCHARP_DEEP_COMPARE */

#ifdef ERR_ERRVCHAR_CONSTP_DEEP
#  if ERR_ERRVCHAR_CONSTP_DEEP
#    ifndef ERR_ERRVCHAR_CONSTP_DEEP_COPY
#      define ERR_ERRVCHAR_CONSTP_DEEP_COPY 1
#    endif
#    ifndef ERR_ERRVCHAR_CONSTP_DEEP_COMPARE
#      define ERR_ERRVCHAR_CONSTP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERRVCHAR_CONSTP_DEEP_COPY
#      define ERR_ERRVCHAR_CONSTP_DEEP_COPY 0
#    endif
#    ifndef ERR_ERRVCHAR_CONSTP_DEEP_COMPARE
#      define ERR_ERRVCHAR_CONSTP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERRVCHAR_CONSTP_DEEP_COPY
#define ERR_ERRVCHAR_CONSTP_DEEP_COPY 0
#endif /* !defined ERR_ERRVCHAR_CONSTP_DEEP_COPY */

#ifndef ERR_ERRVCHAR_CONSTP_DEEP_COMPARE
#define ERR_ERRVCHAR_CONSTP_DEEP_COMPARE 0
#endif /* !defined ERR_ERRVCHAR_CONSTP_DEEP_COMPARE */

#ifdef ERR_CONST_ERRVCHARP_DEEP
#  if ERR_CONST_ERRVCHARP_DEEP
#    ifndef ERR_CONST_ERRVCHARP_DEEP_COPY
#      define ERR_CONST_ERRVCHARP_DEEP_COPY 1
#    endif
#    ifndef ERR_CONST_ERRVCHARP_DEEP_COMPARE
#      define ERR_CONST_ERRVCHARP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_CONST_ERRVCHARP_DEEP_COPY
#      define ERR_CONST_ERRVCHARP_DEEP_COPY 0
#    endif
#    ifndef ERR_CONST_ERRVCHARP_DEEP_COMPARE
#      define ERR_CONST_ERRVCHARP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_CONST_ERRVCHARP_DEEP_COPY
#define ERR_CONST_ERRVCHARP_DEEP_COPY 0
#endif /* !defined ERR_CONST_ERRVCHARP_DEEP_COPY */

#ifndef ERR_CONST_ERRVCHARP_DEEP_COMPARE
#define ERR_CONST_ERRVCHARP_DEEP_COMPARE 0
#endif /* !defined ERR_CONST_ERRVCHARP_DEEP_COMPARE */

#ifdef ERR_ERR_V_CHAR_T_P_DEEP
#  if ERR_ERR_V_CHAR_T_P_DEEP
#    ifndef ERR_ERR_V_CHAR_T_P_DEEP_COPY
#      define ERR_ERR_V_CHAR_T_P_DEEP_COPY 1
#    endif
#    ifndef ERR_ERR_V_CHAR_T_P_DEEP_COMPARE
#      define ERR_ERR_V_CHAR_T_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERR_V_CHAR_T_P_DEEP_COPY
#      define ERR_ERR_V_CHAR_T_P_DEEP_COPY 0
#    endif
#    ifndef ERR_ERR_V_CHAR_T_P_DEEP_COMPARE
#      define ERR_ERR_V_CHAR_T_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERR_V_CHAR_T_P_DEEP_COPY
#define ERR_ERR_V_CHAR_T_P_DEEP_COPY 0
#endif /* !defined ERR_ERR_V_CHAR_T_P_DEEP_COPY */

#ifndef ERR_ERR_V_CHAR_T_P_DEEP_COMPARE
#define ERR_ERR_V_CHAR_T_P_DEEP_COMPARE 0
#endif /* !defined ERR_ERR_V_CHAR_T_P_DEEP_COMPARE */

#ifdef ERR_ERR_V_CHAR_T_CONST_P_DEEP
#  if ERR_ERR_V_CHAR_T_CONST_P_DEEP
#    ifndef ERR_ERR_V_CHAR_T_CONST_P_DEEP_COPY
#      define ERR_ERR_V_CHAR_T_CONST_P_DEEP_COPY 1
#    endif
#    ifndef ERR_ERR_V_CHAR_T_CONST_P_DEEP_COMPARE
#      define ERR_ERR_V_CHAR_T_CONST_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERR_V_CHAR_T_CONST_P_DEEP_COPY
#      define ERR_ERR_V_CHAR_T_CONST_P_DEEP_COPY 0
#    endif
#    ifndef ERR_ERR_V_CHAR_T_CONST_P_DEEP_COMPARE
#      define ERR_ERR_V_CHAR_T_CONST_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERR_V_CHAR_T_CONST_P_DEEP_COPY
#define ERR_ERR_V_CHAR_T_CONST_P_DEEP_COPY 0
#endif /* !defined ERR_ERR_V_CHAR_T_CONST_P_DEEP_COPY */

#ifndef ERR_ERR_V_CHAR_T_CONST_P_DEEP_COMPARE
#define ERR_ERR_V_CHAR_T_CONST_P_DEEP_COMPARE 0
#endif /* !defined ERR_ERR_V_CHAR_T_CONST_P_DEEP_COMPARE */

#ifdef ERR_CONST_ERR_V_CHAR_T_P_DEEP
#  if ERR_CONST_ERR_V_CHAR_T_P_DEEP
#    ifndef ERR_CONST_ERR_V_CHAR_T_P_DEEP_COPY
#      define ERR_CONST_ERR_V_CHAR_T_P_DEEP_COPY 1
#    endif
#    ifndef ERR_CONST_ERR_V_CHAR_T_P_DEEP_COMPARE
#      define ERR_CONST_ERR_V_CHAR_T_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_CONST_ERR_V_CHAR_T_P_DEEP_COPY
#      define ERR_CONST_ERR_V_CHAR_T_P_DEEP_COPY 0
#    endif
#    ifndef ERR_CONST_ERR_V_CHAR_T_P_DEEP_COMPARE
#      define ERR_CONST_ERR_V_CHAR_T_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_CONST_ERR_V_CHAR_T_P_DEEP_COPY
#define ERR_CONST_ERR_V_CHAR_T_P_DEEP_COPY 0
#endif /* !defined ERR_CONST_ERR_V_CHAR_T_P_DEEP_COPY */

#ifndef ERR_CONST_ERR_V_CHAR_T_P_DEEP_COMPARE
#define ERR_CONST_ERR_V_CHAR_T_P_DEEP_COMPARE 0
#endif /* !defined ERR_CONST_ERR_V_CHAR_T_P_DEEP_COMPARE */

#ifdef ERR_ERRVCHAR_P_DEEP
#  if ERR_ERRVCHAR_P_DEEP
#    ifndef ERR_ERRVCHAR_P_DEEP_COPY
#      define ERR_ERRVCHAR_P_DEEP_COPY 1
#    endif
#    ifndef ERR_ERRVCHAR_P_DEEP_COMPARE
#      define ERR_ERRVCHAR_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERRVCHAR_P_DEEP_COPY
#      define ERR_ERRVCHAR_P_DEEP_COPY 0
#    endif
#    ifndef ERR_ERRVCHAR_P_DEEP_COMPARE
#      define ERR_ERRVCHAR_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERRVCHAR_P_DEEP_COPY
#define ERR_ERRVCHAR_P_DEEP_COPY 0
#endif /* !defined ERR_ERRVCHAR_P_DEEP_COPY */

#ifndef ERR_ERRVCHAR_P_DEEP_COMPARE
#define ERR_ERRVCHAR_P_DEEP_COMPARE 0
#endif /* !defined ERR_ERRVCHAR_P_DEEP_COMPARE */

#ifdef ERR_ERRVCHAR_CONST_P_DEEP
#  if ERR_ERRVCHAR_CONST_P_DEEP
#    ifndef ERR_ERRVCHAR_CONST_P_DEEP_COPY
#      define ERR_ERRVCHAR_CONST_P_DEEP_COPY 1
#    endif
#    ifndef ERR_ERRVCHAR_CONST_P_DEEP_COMPARE
#      define ERR_ERRVCHAR_CONST_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERRVCHAR_CONST_P_DEEP_COPY
#      define ERR_ERRVCHAR_CONST_P_DEEP_COPY 0
#    endif
#    ifndef ERR_ERRVCHAR_CONST_P_DEEP_COMPARE
#      define ERR_ERRVCHAR_CONST_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERRVCHAR_CONST_P_DEEP_COPY
#define ERR_ERRVCHAR_CONST_P_DEEP_COPY 0
#endif /* !defined ERR_ERRVCHAR_CONST_P_DEEP_COPY */

#ifndef ERR_ERRVCHAR_CONST_P_DEEP_COMPARE
#define ERR_ERRVCHAR_CONST_P_DEEP_COMPARE 0
#endif /* !defined ERR_ERRVCHAR_CONST_P_DEEP_COMPARE */

#ifdef ERR_CONST_ERRVCHAR_P_DEEP
#  if ERR_CONST_ERRVCHAR_P_DEEP
#    ifndef ERR_CONST_ERRVCHAR_P_DEEP_COPY
#      define ERR_CONST_ERRVCHAR_P_DEEP_COPY 1
#    endif
#    ifndef ERR_CONST_ERRVCHAR_P_DEEP_COMPARE
#      define ERR_CONST_ERRVCHAR_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_CONST_ERRVCHAR_P_DEEP_COPY
#      define ERR_CONST_ERRVCHAR_P_DEEP_COPY 0
#    endif
#    ifndef ERR_CONST_ERRVCHAR_P_DEEP_COMPARE
#      define ERR_CONST_ERRVCHAR_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_CONST_ERRVCHAR_P_DEEP_COPY
#define ERR_CONST_ERRVCHAR_P_DEEP_COPY 0
#endif /* !defined ERR_CONST_ERRVCHAR_P_DEEP_COPY */

#ifndef ERR_CONST_ERRVCHAR_P_DEEP_COMPARE
#define ERR_CONST_ERRVCHAR_P_DEEP_COMPARE 0
#endif /* !defined ERR_CONST_ERRVCHAR_P_DEEP_COMPARE */

#if ERR_ERR_V_CHAR_TP_DEEP_COMPARE && !defined(ERR_ERR_V_CHAR_TP_HASH_RAW)
#define ERR_ERR_V_CHAR_TP_HASH_RAW(A1) err_v_char_hash_raw((A1))
#endif

#if ERR_ERR_V_CHAR_T_CONSTP_DEEP_COMPARE && !defined(ERR_ERR_V_CHAR_T_CONSTP_HASH_RAW)
#define ERR_ERR_V_CHAR_T_CONSTP_HASH_RAW(A1) err_v_char_hash_raw((A1))
#endif

#if ERR_CONST_ERR_V_CHAR_TP_DEEP_COMPARE && !defined(ERR_CONST_ERR_V_CHAR_TP_HASH_RAW)
#define ERR_CONST_ERR_V_CHAR_TP_HASH_RAW(A1) err_v_char_hash_raw((A1))
#endif

#if ERR_ERRVCHARP_DEEP_COMPARE && !defined(ERR_ERRVCHARP_HASH_RAW)
#define ERR_ERRVCHARP_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if ERR_ERRVCHAR_CONSTP_DEEP_COMPARE && !defined(ERR_ERRVCHAR_CONSTP_HASH_RAW)
#define ERR_ERRVCHAR_CONSTP_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if ERR_CONST_ERRVCHARP_DEEP_COMPARE && !defined(ERR_CONST_ERRVCHARP_HASH_RAW)
#define ERR_CONST_ERRVCHARP_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if ERR_ERR_V_CHAR_T_P_DEEP_COMPARE && !defined(ERR_ERR_V_CHAR_T_P_HASH_RAW)
#define ERR_ERR_V_CHAR_T_P_HASH_RAW(A1) err_v_char_hash_raw((A1))
#endif

#if ERR_ERR_V_CHAR_T_CONST_P_DEEP_COMPARE && !defined(ERR_ERR_V_CHAR_T_CONST_P_HASH_RAW)
#define ERR_ERR_V_CHAR_T_CONST_P_HASH_RAW(A1) err_v_char_hash_raw((A1))
#endif

#if ERR_CONST_ERR_V_CHAR_T_P_DEEP_COMPARE && !defined(ERR_CONST_ERR_V_CHAR_T_P_HASH_RAW)
#define ERR_CONST_ERR_V_CHAR_T_P_HASH_RAW(A1) err_v_char_hash_raw((A1))
#endif

#if ERR_ERRVCHAR_P_DEEP_COMPARE && !defined(ERR_ERRVCHAR_P_HASH_RAW)
#define ERR_ERRVCHAR_P_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if ERR_ERRVCHAR_CONST_P_DEEP_COMPARE && !defined(ERR_ERRVCHAR_CONST_P_HASH_RAW)
#define ERR_ERRVCHAR_CONST_P_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if ERR_CONST_ERRVCHAR_P_DEEP_COMPARE && !defined(ERR_CONST_ERRVCHAR_P_HASH_RAW)
#define ERR_CONST_ERRVCHAR_P_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#ifndef ERR_ERRVCHAR_HASH_RAW
#define ERR_ERRVCHAR_HASH_RAW(A1) ((A1).hash_raw())
#endif

#if ERR_ERR_V_CHAR_TP_DEEP_COMPARE && !defined(ERR_ERR_V_CHAR_TP_CMP)
#define ERR_ERR_V_CHAR_TP_CMP(A1,A2) err_v_char_cmp((A1),(A2),NULL)
#endif

#if ERR_ERR_V_CHAR_T_CONSTP_DEEP_COMPARE && !defined(ERR_ERR_V_CHAR_T_CONSTP_CMP)
#define ERR_ERR_V_CHAR_T_CONSTP_CMP(A1,A2) err_v_char_cmp((A1),(A2),NULL)
#endif

#if ERR_CONST_ERR_V_CHAR_TP_DEEP_COMPARE && !defined(ERR_CONST_ERR_V_CHAR_TP_CMP)
#define ERR_CONST_ERR_V_CHAR_TP_CMP(A1,A2) err_v_char_cmp((A1),(A2),NULL)
#endif

#if ERR_ERRVCHARP_DEEP_COMPARE && !defined(ERR_ERRVCHARP_CMP)
#define ERR_ERRVCHARP_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if ERR_ERRVCHAR_CONSTP_DEEP_COMPARE && !defined(ERR_ERRVCHAR_CONSTP_CMP)
#define ERR_ERRVCHAR_CONSTP_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if ERR_CONST_ERRVCHARP_DEEP_COMPARE && !defined(ERR_CONST_ERRVCHARP_CMP)
#define ERR_CONST_ERRVCHARP_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if ERR_ERR_V_CHAR_T_P_DEEP_COMPARE && !defined(ERR_ERR_V_CHAR_T_P_CMP)
#define ERR_ERR_V_CHAR_T_P_CMP(A1,A2) err_v_char_cmp((A1),(A2),NULL)
#endif

#if ERR_ERR_V_CHAR_T_CONST_P_DEEP_COMPARE && !defined(ERR_ERR_V_CHAR_T_CONST_P_CMP)
#define ERR_ERR_V_CHAR_T_CONST_P_CMP(A1,A2) err_v_char_cmp((A1),(A2),NULL)
#endif

#if ERR_CONST_ERR_V_CHAR_T_P_DEEP_COMPARE && !defined(ERR_CONST_ERR_V_CHAR_T_P_CMP)
#define ERR_CONST_ERR_V_CHAR_T_P_CMP(A1,A2) err_v_char_cmp((A1),(A2),NULL)
#endif

#if ERR_ERRVCHAR_P_DEEP_COMPARE && !defined(ERR_ERRVCHAR_P_CMP)
#define ERR_ERRVCHAR_P_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if ERR_ERRVCHAR_CONST_P_DEEP_COMPARE && !defined(ERR_ERRVCHAR_CONST_P_CMP)
#define ERR_ERRVCHAR_CONST_P_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if ERR_CONST_ERRVCHAR_P_DEEP_COMPARE && !defined(ERR_CONST_ERRVCHAR_P_CMP)
#define ERR_CONST_ERRVCHAR_P_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#ifndef ERR_ERRVCHAR_CMP
#define ERR_ERRVCHAR_CMP(A1,A2) ((A1).cmp((A2),NULL))
#endif

#ifndef ERR_ERRVCHAR_ZERO
#define ERR_ERRVCHAR_ZERO (ErrVChar::static_zero())
#endif

#if ERR_ERR_V_CHAR_TP_DEEP_COPY && !defined(ERR_ERR_V_CHAR_TP_ICOPY)
#define ERR_ERR_V_CHAR_TP_ICOPY(A1,A2) err_v_char_copy_err((A1),(A2))
#endif

#if ERR_ERR_V_CHAR_T_CONSTP_DEEP_COPY && !defined(ERR_ERR_V_CHAR_T_CONSTP_ICOPY)
#define ERR_ERR_V_CHAR_T_CONSTP_ICOPY(A1,A2) err_v_char_copy_err((A1),(A2))
#endif

#if ERR_CONST_ERR_V_CHAR_TP_DEEP_COPY && !defined(ERR_CONST_ERR_V_CHAR_TP_ICOPY)
#define ERR_CONST_ERR_V_CHAR_TP_ICOPY(A1,A2) err_v_char_copy_err((A1),(A2))
#endif

#if ERR_ERRVCHARP_DEEP_COPY && !defined(ERR_ERRVCHARP_ICOPY)
#define ERR_ERRVCHARP_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERRVCHAR_CONSTP_DEEP_COPY && !defined(ERR_ERRVCHAR_CONSTP_ICOPY)
#define ERR_ERRVCHAR_CONSTP_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_CONST_ERRVCHARP_DEEP_COPY && !defined(ERR_CONST_ERRVCHARP_ICOPY)
#define ERR_CONST_ERRVCHARP_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERR_V_CHAR_T_P_DEEP_COPY && !defined(ERR_ERR_V_CHAR_T_P_ICOPY)
#define ERR_ERR_V_CHAR_T_P_ICOPY(A1,A2) err_v_char_copy_err((A1),(A2))
#endif

#if ERR_ERR_V_CHAR_T_CONST_P_DEEP_COPY && !defined(ERR_ERR_V_CHAR_T_CONST_P_ICOPY)
#define ERR_ERR_V_CHAR_T_CONST_P_ICOPY(A1,A2) err_v_char_copy_err((A1),(A2))
#endif

#if ERR_CONST_ERR_V_CHAR_T_P_DEEP_COPY && !defined(ERR_CONST_ERR_V_CHAR_T_P_ICOPY)
#define ERR_CONST_ERR_V_CHAR_T_P_ICOPY(A1,A2) err_v_char_copy_err((A1),(A2))
#endif

#if ERR_ERRVCHAR_P_DEEP_COPY && !defined(ERR_ERRVCHAR_P_ICOPY)
#define ERR_ERRVCHAR_P_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERRVCHAR_CONST_P_DEEP_COPY && !defined(ERR_ERRVCHAR_CONST_P_ICOPY)
#define ERR_ERRVCHAR_CONST_P_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_CONST_ERRVCHAR_P_DEEP_COPY && !defined(ERR_CONST_ERRVCHAR_P_ICOPY)
#define ERR_CONST_ERRVCHAR_P_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERR_V_CHAR_TP_DEEP_COPY && !defined(ERR_ERR_V_CHAR_TP_OCOPY)
#define ERR_ERR_V_CHAR_TP_OCOPY(A1,A2) err_v_char_copy_err((A1),(A2))
#endif

#if ERR_ERR_V_CHAR_T_CONSTP_DEEP_COPY && !defined(ERR_ERR_V_CHAR_T_CONSTP_OCOPY)
#define ERR_ERR_V_CHAR_T_CONSTP_OCOPY(A1,A2) err_v_char_copy_err((A1),(A2))
#endif

#if ERR_CONST_ERR_V_CHAR_TP_DEEP_COPY && !defined(ERR_CONST_ERR_V_CHAR_TP_OCOPY)
#define ERR_CONST_ERR_V_CHAR_TP_OCOPY(A1,A2) err_v_char_copy_err((A1),(A2))
#endif

#if ERR_ERRVCHARP_DEEP_COPY && !defined(ERR_ERRVCHARP_OCOPY)
#define ERR_ERRVCHARP_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERRVCHAR_CONSTP_DEEP_COPY && !defined(ERR_ERRVCHAR_CONSTP_OCOPY)
#define ERR_ERRVCHAR_CONSTP_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_CONST_ERRVCHARP_DEEP_COPY && !defined(ERR_CONST_ERRVCHARP_OCOPY)
#define ERR_CONST_ERRVCHARP_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERR_V_CHAR_T_P_DEEP_COPY && !defined(ERR_ERR_V_CHAR_T_P_OCOPY)
#define ERR_ERR_V_CHAR_T_P_OCOPY(A1,A2) err_v_char_copy_err((A1),(A2))
#endif

#if ERR_ERR_V_CHAR_T_CONST_P_DEEP_COPY && !defined(ERR_ERR_V_CHAR_T_CONST_P_OCOPY)
#define ERR_ERR_V_CHAR_T_CONST_P_OCOPY(A1,A2) err_v_char_copy_err((A1),(A2))
#endif

#if ERR_CONST_ERR_V_CHAR_T_P_DEEP_COPY && !defined(ERR_CONST_ERR_V_CHAR_T_P_OCOPY)
#define ERR_CONST_ERR_V_CHAR_T_P_OCOPY(A1,A2) err_v_char_copy_err((A1),(A2))
#endif

#if ERR_ERRVCHAR_P_DEEP_COPY && !defined(ERR_ERRVCHAR_P_OCOPY)
#define ERR_ERRVCHAR_P_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERRVCHAR_CONST_P_DEEP_COPY && !defined(ERR_ERRVCHAR_CONST_P_OCOPY)
#define ERR_ERRVCHAR_CONST_P_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_CONST_ERRVCHAR_P_DEEP_COPY && !defined(ERR_CONST_ERRVCHAR_P_OCOPY)
#define ERR_CONST_ERRVCHAR_P_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERR_V_CHAR_TP_DEEP_COPY && !defined(ERR_ERR_V_CHAR_TP_IFREE)
#define ERR_ERR_V_CHAR_TP_IFREE(A1) err_v_char_delete((A1))
#endif

#if ERR_ERR_V_CHAR_T_CONSTP_DEEP_COPY && !defined(ERR_ERR_V_CHAR_T_CONSTP_IFREE)
#define ERR_ERR_V_CHAR_T_CONSTP_IFREE(A1) err_v_char_delete((A1))
#endif

#if ERR_CONST_ERR_V_CHAR_TP_DEEP_COPY && !defined(ERR_CONST_ERR_V_CHAR_TP_IFREE)
#define ERR_CONST_ERR_V_CHAR_TP_IFREE(A1) err_v_char_delete((A1))
#endif

#if ERR_ERRVCHARP_DEEP_COPY && !defined(ERR_ERRVCHARP_IFREE)
#define ERR_ERRVCHARP_IFREE(A1) delete((A1))
#endif

#if ERR_ERRVCHAR_CONSTP_DEEP_COPY && !defined(ERR_ERRVCHAR_CONSTP_IFREE)
#define ERR_ERRVCHAR_CONSTP_IFREE(A1) delete((A1))
#endif

#if ERR_CONST_ERRVCHARP_DEEP_COPY && !defined(ERR_CONST_ERRVCHARP_IFREE)
#define ERR_CONST_ERRVCHARP_IFREE(A1) delete((A1))
#endif

#if ERR_ERR_V_CHAR_T_P_DEEP_COPY && !defined(ERR_ERR_V_CHAR_T_P_IFREE)
#define ERR_ERR_V_CHAR_T_P_IFREE(A1) err_v_char_delete((A1))
#endif

#if ERR_ERR_V_CHAR_T_CONST_P_DEEP_COPY && !defined(ERR_ERR_V_CHAR_T_CONST_P_IFREE)
#define ERR_ERR_V_CHAR_T_CONST_P_IFREE(A1) err_v_char_delete((A1))
#endif

#if ERR_CONST_ERR_V_CHAR_T_P_DEEP_COPY && !defined(ERR_CONST_ERR_V_CHAR_T_P_IFREE)
#define ERR_CONST_ERR_V_CHAR_T_P_IFREE(A1) err_v_char_delete((A1))
#endif

#if ERR_ERRVCHAR_P_DEEP_COPY && !defined(ERR_ERRVCHAR_P_IFREE)
#define ERR_ERRVCHAR_P_IFREE(A1) delete((A1))
#endif

#if ERR_ERRVCHAR_CONST_P_DEEP_COPY && !defined(ERR_ERRVCHAR_CONST_P_IFREE)
#define ERR_ERRVCHAR_CONST_P_IFREE(A1) delete((A1))
#endif

#if ERR_CONST_ERRVCHAR_P_DEEP_COPY && !defined(ERR_CONST_ERRVCHAR_P_IFREE)
#define ERR_CONST_ERRVCHAR_P_IFREE(A1) delete((A1))
#endif

#if ERR_ERR_V_CHAR_TP_DEEP_COPY && !defined(ERR_ERR_V_CHAR_TP_OFREE)
#define ERR_ERR_V_CHAR_TP_OFREE(A1) err_v_char_delete((A1))
#endif

#if ERR_ERR_V_CHAR_T_CONSTP_DEEP_COPY && !defined(ERR_ERR_V_CHAR_T_CONSTP_OFREE)
#define ERR_ERR_V_CHAR_T_CONSTP_OFREE(A1) err_v_char_delete((A1))
#endif

#if ERR_CONST_ERR_V_CHAR_TP_DEEP_COPY && !defined(ERR_CONST_ERR_V_CHAR_TP_OFREE)
#define ERR_CONST_ERR_V_CHAR_TP_OFREE(A1) err_v_char_delete((A1))
#endif

#if ERR_ERRVCHARP_DEEP_COPY && !defined(ERR_ERRVCHARP_OFREE)
#define ERR_ERRVCHARP_OFREE(A1) delete((A1))
#endif

#if ERR_ERRVCHAR_CONSTP_DEEP_COPY && !defined(ERR_ERRVCHAR_CONSTP_OFREE)
#define ERR_ERRVCHAR_CONSTP_OFREE(A1) delete((A1))
#endif

#if ERR_CONST_ERRVCHARP_DEEP_COPY && !defined(ERR_CONST_ERRVCHARP_OFREE)
#define ERR_CONST_ERRVCHARP_OFREE(A1) delete((A1))
#endif

#if ERR_ERR_V_CHAR_T_P_DEEP_COPY && !defined(ERR_ERR_V_CHAR_T_P_OFREE)
#define ERR_ERR_V_CHAR_T_P_OFREE(A1) err_v_char_delete((A1))
#endif

#if ERR_ERR_V_CHAR_T_CONST_P_DEEP_COPY && !defined(ERR_ERR_V_CHAR_T_CONST_P_OFREE)
#define ERR_ERR_V_CHAR_T_CONST_P_OFREE(A1) err_v_char_delete((A1))
#endif

#if ERR_CONST_ERR_V_CHAR_T_P_DEEP_COPY && !defined(ERR_CONST_ERR_V_CHAR_T_P_OFREE)
#define ERR_CONST_ERR_V_CHAR_T_P_OFREE(A1) err_v_char_delete((A1))
#endif

#if ERR_ERRVCHAR_P_DEEP_COPY && !defined(ERR_ERRVCHAR_P_OFREE)
#define ERR_ERRVCHAR_P_OFREE(A1) delete((A1))
#endif

#if ERR_ERRVCHAR_CONST_P_DEEP_COPY && !defined(ERR_ERRVCHAR_CONST_P_OFREE)
#define ERR_ERRVCHAR_CONST_P_OFREE(A1) delete((A1))
#endif

#if ERR_CONST_ERRVCHAR_P_DEEP_COPY && !defined(ERR_CONST_ERRVCHAR_P_OFREE)
#define ERR_CONST_ERRVCHAR_P_OFREE(A1) delete((A1))
#endif

#ifndef ERR_ERRVCHAR_CONSTRUCTOR
#define ERR_ERRVCHAR_CONSTRUCTOR(A1) ((A1)._constructor())
#endif

#ifndef ERR_ERRVCHAR_DESTRUCTOR
#define ERR_ERRVCHAR_DESTRUCTOR(A1) ((A1)._destructor())
#endif


#endif /* defined ERWIN_ERR_V_CHAR_f_h */

