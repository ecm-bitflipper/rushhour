
#ifndef ERWIN_V_CHAR_f_h
#define ERWIN_V_CHAR_f_h

/* Unification of VChar and v_char_t: they are identical now. */
struct v_char_t;

#ifndef __cplusplus
typedef struct v_char_t v_char_t;
#endif /* not defined __cplusplus */

typedef v_char_t VChar;

typedef v_char_t *v_char_t_p;

typedef v_char_t const *v_char_t_const_p;

#define V_CHAR_SIG 1803833872



#ifdef V_CHAR_TP_DEEP
#  if V_CHAR_TP_DEEP
#    ifndef V_CHAR_TP_DEEP_COPY
#      define V_CHAR_TP_DEEP_COPY 1
#    endif
#    ifndef V_CHAR_TP_DEEP_COMPARE
#      define V_CHAR_TP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef V_CHAR_TP_DEEP_COPY
#      define V_CHAR_TP_DEEP_COPY 0
#    endif
#    ifndef V_CHAR_TP_DEEP_COMPARE
#      define V_CHAR_TP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef V_CHAR_TP_DEEP_COPY
#define V_CHAR_TP_DEEP_COPY 0
#endif /* !defined V_CHAR_TP_DEEP_COPY */

#ifndef V_CHAR_TP_DEEP_COMPARE
#define V_CHAR_TP_DEEP_COMPARE 0
#endif /* !defined V_CHAR_TP_DEEP_COMPARE */

#ifdef V_CHAR_T_CONSTP_DEEP
#  if V_CHAR_T_CONSTP_DEEP
#    ifndef V_CHAR_T_CONSTP_DEEP_COPY
#      define V_CHAR_T_CONSTP_DEEP_COPY 1
#    endif
#    ifndef V_CHAR_T_CONSTP_DEEP_COMPARE
#      define V_CHAR_T_CONSTP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef V_CHAR_T_CONSTP_DEEP_COPY
#      define V_CHAR_T_CONSTP_DEEP_COPY 0
#    endif
#    ifndef V_CHAR_T_CONSTP_DEEP_COMPARE
#      define V_CHAR_T_CONSTP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef V_CHAR_T_CONSTP_DEEP_COPY
#define V_CHAR_T_CONSTP_DEEP_COPY 0
#endif /* !defined V_CHAR_T_CONSTP_DEEP_COPY */

#ifndef V_CHAR_T_CONSTP_DEEP_COMPARE
#define V_CHAR_T_CONSTP_DEEP_COMPARE 0
#endif /* !defined V_CHAR_T_CONSTP_DEEP_COMPARE */

#ifdef CONST_V_CHAR_TP_DEEP
#  if CONST_V_CHAR_TP_DEEP
#    ifndef CONST_V_CHAR_TP_DEEP_COPY
#      define CONST_V_CHAR_TP_DEEP_COPY 1
#    endif
#    ifndef CONST_V_CHAR_TP_DEEP_COMPARE
#      define CONST_V_CHAR_TP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef CONST_V_CHAR_TP_DEEP_COPY
#      define CONST_V_CHAR_TP_DEEP_COPY 0
#    endif
#    ifndef CONST_V_CHAR_TP_DEEP_COMPARE
#      define CONST_V_CHAR_TP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef CONST_V_CHAR_TP_DEEP_COPY
#define CONST_V_CHAR_TP_DEEP_COPY 0
#endif /* !defined CONST_V_CHAR_TP_DEEP_COPY */

#ifndef CONST_V_CHAR_TP_DEEP_COMPARE
#define CONST_V_CHAR_TP_DEEP_COMPARE 0
#endif /* !defined CONST_V_CHAR_TP_DEEP_COMPARE */

#ifdef VCHARP_DEEP
#  if VCHARP_DEEP
#    ifndef VCHARP_DEEP_COPY
#      define VCHARP_DEEP_COPY 1
#    endif
#    ifndef VCHARP_DEEP_COMPARE
#      define VCHARP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef VCHARP_DEEP_COPY
#      define VCHARP_DEEP_COPY 0
#    endif
#    ifndef VCHARP_DEEP_COMPARE
#      define VCHARP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef VCHARP_DEEP_COPY
#define VCHARP_DEEP_COPY 0
#endif /* !defined VCHARP_DEEP_COPY */

#ifndef VCHARP_DEEP_COMPARE
#define VCHARP_DEEP_COMPARE 0
#endif /* !defined VCHARP_DEEP_COMPARE */

#ifdef VCHAR_CONSTP_DEEP
#  if VCHAR_CONSTP_DEEP
#    ifndef VCHAR_CONSTP_DEEP_COPY
#      define VCHAR_CONSTP_DEEP_COPY 1
#    endif
#    ifndef VCHAR_CONSTP_DEEP_COMPARE
#      define VCHAR_CONSTP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef VCHAR_CONSTP_DEEP_COPY
#      define VCHAR_CONSTP_DEEP_COPY 0
#    endif
#    ifndef VCHAR_CONSTP_DEEP_COMPARE
#      define VCHAR_CONSTP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef VCHAR_CONSTP_DEEP_COPY
#define VCHAR_CONSTP_DEEP_COPY 0
#endif /* !defined VCHAR_CONSTP_DEEP_COPY */

#ifndef VCHAR_CONSTP_DEEP_COMPARE
#define VCHAR_CONSTP_DEEP_COMPARE 0
#endif /* !defined VCHAR_CONSTP_DEEP_COMPARE */

#ifdef CONST_VCHARP_DEEP
#  if CONST_VCHARP_DEEP
#    ifndef CONST_VCHARP_DEEP_COPY
#      define CONST_VCHARP_DEEP_COPY 1
#    endif
#    ifndef CONST_VCHARP_DEEP_COMPARE
#      define CONST_VCHARP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef CONST_VCHARP_DEEP_COPY
#      define CONST_VCHARP_DEEP_COPY 0
#    endif
#    ifndef CONST_VCHARP_DEEP_COMPARE
#      define CONST_VCHARP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef CONST_VCHARP_DEEP_COPY
#define CONST_VCHARP_DEEP_COPY 0
#endif /* !defined CONST_VCHARP_DEEP_COPY */

#ifndef CONST_VCHARP_DEEP_COMPARE
#define CONST_VCHARP_DEEP_COMPARE 0
#endif /* !defined CONST_VCHARP_DEEP_COMPARE */

#ifdef V_CHAR_T_P_DEEP
#  if V_CHAR_T_P_DEEP
#    ifndef V_CHAR_T_P_DEEP_COPY
#      define V_CHAR_T_P_DEEP_COPY 1
#    endif
#    ifndef V_CHAR_T_P_DEEP_COMPARE
#      define V_CHAR_T_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef V_CHAR_T_P_DEEP_COPY
#      define V_CHAR_T_P_DEEP_COPY 0
#    endif
#    ifndef V_CHAR_T_P_DEEP_COMPARE
#      define V_CHAR_T_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef V_CHAR_T_P_DEEP_COPY
#define V_CHAR_T_P_DEEP_COPY 0
#endif /* !defined V_CHAR_T_P_DEEP_COPY */

#ifndef V_CHAR_T_P_DEEP_COMPARE
#define V_CHAR_T_P_DEEP_COMPARE 0
#endif /* !defined V_CHAR_T_P_DEEP_COMPARE */

#ifdef V_CHAR_T_CONST_P_DEEP
#  if V_CHAR_T_CONST_P_DEEP
#    ifndef V_CHAR_T_CONST_P_DEEP_COPY
#      define V_CHAR_T_CONST_P_DEEP_COPY 1
#    endif
#    ifndef V_CHAR_T_CONST_P_DEEP_COMPARE
#      define V_CHAR_T_CONST_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef V_CHAR_T_CONST_P_DEEP_COPY
#      define V_CHAR_T_CONST_P_DEEP_COPY 0
#    endif
#    ifndef V_CHAR_T_CONST_P_DEEP_COMPARE
#      define V_CHAR_T_CONST_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef V_CHAR_T_CONST_P_DEEP_COPY
#define V_CHAR_T_CONST_P_DEEP_COPY 0
#endif /* !defined V_CHAR_T_CONST_P_DEEP_COPY */

#ifndef V_CHAR_T_CONST_P_DEEP_COMPARE
#define V_CHAR_T_CONST_P_DEEP_COMPARE 0
#endif /* !defined V_CHAR_T_CONST_P_DEEP_COMPARE */

#ifdef CONST_V_CHAR_T_P_DEEP
#  if CONST_V_CHAR_T_P_DEEP
#    ifndef CONST_V_CHAR_T_P_DEEP_COPY
#      define CONST_V_CHAR_T_P_DEEP_COPY 1
#    endif
#    ifndef CONST_V_CHAR_T_P_DEEP_COMPARE
#      define CONST_V_CHAR_T_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef CONST_V_CHAR_T_P_DEEP_COPY
#      define CONST_V_CHAR_T_P_DEEP_COPY 0
#    endif
#    ifndef CONST_V_CHAR_T_P_DEEP_COMPARE
#      define CONST_V_CHAR_T_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef CONST_V_CHAR_T_P_DEEP_COPY
#define CONST_V_CHAR_T_P_DEEP_COPY 0
#endif /* !defined CONST_V_CHAR_T_P_DEEP_COPY */

#ifndef CONST_V_CHAR_T_P_DEEP_COMPARE
#define CONST_V_CHAR_T_P_DEEP_COMPARE 0
#endif /* !defined CONST_V_CHAR_T_P_DEEP_COMPARE */

#ifdef VCHAR_P_DEEP
#  if VCHAR_P_DEEP
#    ifndef VCHAR_P_DEEP_COPY
#      define VCHAR_P_DEEP_COPY 1
#    endif
#    ifndef VCHAR_P_DEEP_COMPARE
#      define VCHAR_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef VCHAR_P_DEEP_COPY
#      define VCHAR_P_DEEP_COPY 0
#    endif
#    ifndef VCHAR_P_DEEP_COMPARE
#      define VCHAR_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef VCHAR_P_DEEP_COPY
#define VCHAR_P_DEEP_COPY 0
#endif /* !defined VCHAR_P_DEEP_COPY */

#ifndef VCHAR_P_DEEP_COMPARE
#define VCHAR_P_DEEP_COMPARE 0
#endif /* !defined VCHAR_P_DEEP_COMPARE */

#ifdef VCHAR_CONST_P_DEEP
#  if VCHAR_CONST_P_DEEP
#    ifndef VCHAR_CONST_P_DEEP_COPY
#      define VCHAR_CONST_P_DEEP_COPY 1
#    endif
#    ifndef VCHAR_CONST_P_DEEP_COMPARE
#      define VCHAR_CONST_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef VCHAR_CONST_P_DEEP_COPY
#      define VCHAR_CONST_P_DEEP_COPY 0
#    endif
#    ifndef VCHAR_CONST_P_DEEP_COMPARE
#      define VCHAR_CONST_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef VCHAR_CONST_P_DEEP_COPY
#define VCHAR_CONST_P_DEEP_COPY 0
#endif /* !defined VCHAR_CONST_P_DEEP_COPY */

#ifndef VCHAR_CONST_P_DEEP_COMPARE
#define VCHAR_CONST_P_DEEP_COMPARE 0
#endif /* !defined VCHAR_CONST_P_DEEP_COMPARE */

#ifdef CONST_VCHAR_P_DEEP
#  if CONST_VCHAR_P_DEEP
#    ifndef CONST_VCHAR_P_DEEP_COPY
#      define CONST_VCHAR_P_DEEP_COPY 1
#    endif
#    ifndef CONST_VCHAR_P_DEEP_COMPARE
#      define CONST_VCHAR_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef CONST_VCHAR_P_DEEP_COPY
#      define CONST_VCHAR_P_DEEP_COPY 0
#    endif
#    ifndef CONST_VCHAR_P_DEEP_COMPARE
#      define CONST_VCHAR_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef CONST_VCHAR_P_DEEP_COPY
#define CONST_VCHAR_P_DEEP_COPY 0
#endif /* !defined CONST_VCHAR_P_DEEP_COPY */

#ifndef CONST_VCHAR_P_DEEP_COMPARE
#define CONST_VCHAR_P_DEEP_COMPARE 0
#endif /* !defined CONST_VCHAR_P_DEEP_COMPARE */

#if V_CHAR_TP_DEEP_COMPARE && !defined(V_CHAR_TP_HASH_RAW)
#define V_CHAR_TP_HASH_RAW(A1) v_char_hash_raw((A1))
#endif

#if V_CHAR_T_CONSTP_DEEP_COMPARE && !defined(V_CHAR_T_CONSTP_HASH_RAW)
#define V_CHAR_T_CONSTP_HASH_RAW(A1) v_char_hash_raw((A1))
#endif

#if CONST_V_CHAR_TP_DEEP_COMPARE && !defined(CONST_V_CHAR_TP_HASH_RAW)
#define CONST_V_CHAR_TP_HASH_RAW(A1) v_char_hash_raw((A1))
#endif

#if VCHARP_DEEP_COMPARE && !defined(VCHARP_HASH_RAW)
#define VCHARP_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if VCHAR_CONSTP_DEEP_COMPARE && !defined(VCHAR_CONSTP_HASH_RAW)
#define VCHAR_CONSTP_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if CONST_VCHARP_DEEP_COMPARE && !defined(CONST_VCHARP_HASH_RAW)
#define CONST_VCHARP_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if V_CHAR_T_P_DEEP_COMPARE && !defined(V_CHAR_T_P_HASH_RAW)
#define V_CHAR_T_P_HASH_RAW(A1) v_char_hash_raw((A1))
#endif

#if V_CHAR_T_CONST_P_DEEP_COMPARE && !defined(V_CHAR_T_CONST_P_HASH_RAW)
#define V_CHAR_T_CONST_P_HASH_RAW(A1) v_char_hash_raw((A1))
#endif

#if CONST_V_CHAR_T_P_DEEP_COMPARE && !defined(CONST_V_CHAR_T_P_HASH_RAW)
#define CONST_V_CHAR_T_P_HASH_RAW(A1) v_char_hash_raw((A1))
#endif

#if VCHAR_P_DEEP_COMPARE && !defined(VCHAR_P_HASH_RAW)
#define VCHAR_P_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if VCHAR_CONST_P_DEEP_COMPARE && !defined(VCHAR_CONST_P_HASH_RAW)
#define VCHAR_CONST_P_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if CONST_VCHAR_P_DEEP_COMPARE && !defined(CONST_VCHAR_P_HASH_RAW)
#define CONST_VCHAR_P_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#ifndef VCHAR_HASH_RAW
#define VCHAR_HASH_RAW(A1) ((A1).hash_raw())
#endif

#if V_CHAR_TP_DEEP_COMPARE && !defined(V_CHAR_TP_CMP)
#define V_CHAR_TP_CMP(A1,A2) v_char_cmp((A1),(A2),NULL)
#endif

#if V_CHAR_T_CONSTP_DEEP_COMPARE && !defined(V_CHAR_T_CONSTP_CMP)
#define V_CHAR_T_CONSTP_CMP(A1,A2) v_char_cmp((A1),(A2),NULL)
#endif

#if CONST_V_CHAR_TP_DEEP_COMPARE && !defined(CONST_V_CHAR_TP_CMP)
#define CONST_V_CHAR_TP_CMP(A1,A2) v_char_cmp((A1),(A2),NULL)
#endif

#if VCHARP_DEEP_COMPARE && !defined(VCHARP_CMP)
#define VCHARP_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if VCHAR_CONSTP_DEEP_COMPARE && !defined(VCHAR_CONSTP_CMP)
#define VCHAR_CONSTP_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if CONST_VCHARP_DEEP_COMPARE && !defined(CONST_VCHARP_CMP)
#define CONST_VCHARP_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if V_CHAR_T_P_DEEP_COMPARE && !defined(V_CHAR_T_P_CMP)
#define V_CHAR_T_P_CMP(A1,A2) v_char_cmp((A1),(A2),NULL)
#endif

#if V_CHAR_T_CONST_P_DEEP_COMPARE && !defined(V_CHAR_T_CONST_P_CMP)
#define V_CHAR_T_CONST_P_CMP(A1,A2) v_char_cmp((A1),(A2),NULL)
#endif

#if CONST_V_CHAR_T_P_DEEP_COMPARE && !defined(CONST_V_CHAR_T_P_CMP)
#define CONST_V_CHAR_T_P_CMP(A1,A2) v_char_cmp((A1),(A2),NULL)
#endif

#if VCHAR_P_DEEP_COMPARE && !defined(VCHAR_P_CMP)
#define VCHAR_P_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if VCHAR_CONST_P_DEEP_COMPARE && !defined(VCHAR_CONST_P_CMP)
#define VCHAR_CONST_P_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if CONST_VCHAR_P_DEEP_COMPARE && !defined(CONST_VCHAR_P_CMP)
#define CONST_VCHAR_P_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#ifndef VCHAR_CMP
#define VCHAR_CMP(A1,A2) ((A1).cmp((A2),NULL))
#endif

#ifndef VCHAR_ZERO
#define VCHAR_ZERO (VChar::static_zero())
#endif

#if V_CHAR_TP_DEEP_COPY && !defined(V_CHAR_TP_ICOPY)
#define V_CHAR_TP_ICOPY(A1,A2) v_char_copy_err((A1),(A2))
#endif

#if V_CHAR_T_CONSTP_DEEP_COPY && !defined(V_CHAR_T_CONSTP_ICOPY)
#define V_CHAR_T_CONSTP_ICOPY(A1,A2) v_char_copy_err((A1),(A2))
#endif

#if CONST_V_CHAR_TP_DEEP_COPY && !defined(CONST_V_CHAR_TP_ICOPY)
#define CONST_V_CHAR_TP_ICOPY(A1,A2) v_char_copy_err((A1),(A2))
#endif

#if VCHARP_DEEP_COPY && !defined(VCHARP_ICOPY)
#define VCHARP_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if VCHAR_CONSTP_DEEP_COPY && !defined(VCHAR_CONSTP_ICOPY)
#define VCHAR_CONSTP_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if CONST_VCHARP_DEEP_COPY && !defined(CONST_VCHARP_ICOPY)
#define CONST_VCHARP_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if V_CHAR_T_P_DEEP_COPY && !defined(V_CHAR_T_P_ICOPY)
#define V_CHAR_T_P_ICOPY(A1,A2) v_char_copy_err((A1),(A2))
#endif

#if V_CHAR_T_CONST_P_DEEP_COPY && !defined(V_CHAR_T_CONST_P_ICOPY)
#define V_CHAR_T_CONST_P_ICOPY(A1,A2) v_char_copy_err((A1),(A2))
#endif

#if CONST_V_CHAR_T_P_DEEP_COPY && !defined(CONST_V_CHAR_T_P_ICOPY)
#define CONST_V_CHAR_T_P_ICOPY(A1,A2) v_char_copy_err((A1),(A2))
#endif

#if VCHAR_P_DEEP_COPY && !defined(VCHAR_P_ICOPY)
#define VCHAR_P_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if VCHAR_CONST_P_DEEP_COPY && !defined(VCHAR_CONST_P_ICOPY)
#define VCHAR_CONST_P_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if CONST_VCHAR_P_DEEP_COPY && !defined(CONST_VCHAR_P_ICOPY)
#define CONST_VCHAR_P_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if V_CHAR_TP_DEEP_COPY && !defined(V_CHAR_TP_OCOPY)
#define V_CHAR_TP_OCOPY(A1,A2) v_char_copy_err((A1),(A2))
#endif

#if V_CHAR_T_CONSTP_DEEP_COPY && !defined(V_CHAR_T_CONSTP_OCOPY)
#define V_CHAR_T_CONSTP_OCOPY(A1,A2) v_char_copy_err((A1),(A2))
#endif

#if CONST_V_CHAR_TP_DEEP_COPY && !defined(CONST_V_CHAR_TP_OCOPY)
#define CONST_V_CHAR_TP_OCOPY(A1,A2) v_char_copy_err((A1),(A2))
#endif

#if VCHARP_DEEP_COPY && !defined(VCHARP_OCOPY)
#define VCHARP_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if VCHAR_CONSTP_DEEP_COPY && !defined(VCHAR_CONSTP_OCOPY)
#define VCHAR_CONSTP_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if CONST_VCHARP_DEEP_COPY && !defined(CONST_VCHARP_OCOPY)
#define CONST_VCHARP_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if V_CHAR_T_P_DEEP_COPY && !defined(V_CHAR_T_P_OCOPY)
#define V_CHAR_T_P_OCOPY(A1,A2) v_char_copy_err((A1),(A2))
#endif

#if V_CHAR_T_CONST_P_DEEP_COPY && !defined(V_CHAR_T_CONST_P_OCOPY)
#define V_CHAR_T_CONST_P_OCOPY(A1,A2) v_char_copy_err((A1),(A2))
#endif

#if CONST_V_CHAR_T_P_DEEP_COPY && !defined(CONST_V_CHAR_T_P_OCOPY)
#define CONST_V_CHAR_T_P_OCOPY(A1,A2) v_char_copy_err((A1),(A2))
#endif

#if VCHAR_P_DEEP_COPY && !defined(VCHAR_P_OCOPY)
#define VCHAR_P_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if VCHAR_CONST_P_DEEP_COPY && !defined(VCHAR_CONST_P_OCOPY)
#define VCHAR_CONST_P_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if CONST_VCHAR_P_DEEP_COPY && !defined(CONST_VCHAR_P_OCOPY)
#define CONST_VCHAR_P_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if V_CHAR_TP_DEEP_COPY && !defined(V_CHAR_TP_IFREE)
#define V_CHAR_TP_IFREE(A1) v_char_delete((A1))
#endif

#if V_CHAR_T_CONSTP_DEEP_COPY && !defined(V_CHAR_T_CONSTP_IFREE)
#define V_CHAR_T_CONSTP_IFREE(A1) v_char_delete((A1))
#endif

#if CONST_V_CHAR_TP_DEEP_COPY && !defined(CONST_V_CHAR_TP_IFREE)
#define CONST_V_CHAR_TP_IFREE(A1) v_char_delete((A1))
#endif

#if VCHARP_DEEP_COPY && !defined(VCHARP_IFREE)
#define VCHARP_IFREE(A1) delete((A1))
#endif

#if VCHAR_CONSTP_DEEP_COPY && !defined(VCHAR_CONSTP_IFREE)
#define VCHAR_CONSTP_IFREE(A1) delete((A1))
#endif

#if CONST_VCHARP_DEEP_COPY && !defined(CONST_VCHARP_IFREE)
#define CONST_VCHARP_IFREE(A1) delete((A1))
#endif

#if V_CHAR_T_P_DEEP_COPY && !defined(V_CHAR_T_P_IFREE)
#define V_CHAR_T_P_IFREE(A1) v_char_delete((A1))
#endif

#if V_CHAR_T_CONST_P_DEEP_COPY && !defined(V_CHAR_T_CONST_P_IFREE)
#define V_CHAR_T_CONST_P_IFREE(A1) v_char_delete((A1))
#endif

#if CONST_V_CHAR_T_P_DEEP_COPY && !defined(CONST_V_CHAR_T_P_IFREE)
#define CONST_V_CHAR_T_P_IFREE(A1) v_char_delete((A1))
#endif

#if VCHAR_P_DEEP_COPY && !defined(VCHAR_P_IFREE)
#define VCHAR_P_IFREE(A1) delete((A1))
#endif

#if VCHAR_CONST_P_DEEP_COPY && !defined(VCHAR_CONST_P_IFREE)
#define VCHAR_CONST_P_IFREE(A1) delete((A1))
#endif

#if CONST_VCHAR_P_DEEP_COPY && !defined(CONST_VCHAR_P_IFREE)
#define CONST_VCHAR_P_IFREE(A1) delete((A1))
#endif

#if V_CHAR_TP_DEEP_COPY && !defined(V_CHAR_TP_OFREE)
#define V_CHAR_TP_OFREE(A1) v_char_delete((A1))
#endif

#if V_CHAR_T_CONSTP_DEEP_COPY && !defined(V_CHAR_T_CONSTP_OFREE)
#define V_CHAR_T_CONSTP_OFREE(A1) v_char_delete((A1))
#endif

#if CONST_V_CHAR_TP_DEEP_COPY && !defined(CONST_V_CHAR_TP_OFREE)
#define CONST_V_CHAR_TP_OFREE(A1) v_char_delete((A1))
#endif

#if VCHARP_DEEP_COPY && !defined(VCHARP_OFREE)
#define VCHARP_OFREE(A1) delete((A1))
#endif

#if VCHAR_CONSTP_DEEP_COPY && !defined(VCHAR_CONSTP_OFREE)
#define VCHAR_CONSTP_OFREE(A1) delete((A1))
#endif

#if CONST_VCHARP_DEEP_COPY && !defined(CONST_VCHARP_OFREE)
#define CONST_VCHARP_OFREE(A1) delete((A1))
#endif

#if V_CHAR_T_P_DEEP_COPY && !defined(V_CHAR_T_P_OFREE)
#define V_CHAR_T_P_OFREE(A1) v_char_delete((A1))
#endif

#if V_CHAR_T_CONST_P_DEEP_COPY && !defined(V_CHAR_T_CONST_P_OFREE)
#define V_CHAR_T_CONST_P_OFREE(A1) v_char_delete((A1))
#endif

#if CONST_V_CHAR_T_P_DEEP_COPY && !defined(CONST_V_CHAR_T_P_OFREE)
#define CONST_V_CHAR_T_P_OFREE(A1) v_char_delete((A1))
#endif

#if VCHAR_P_DEEP_COPY && !defined(VCHAR_P_OFREE)
#define VCHAR_P_OFREE(A1) delete((A1))
#endif

#if VCHAR_CONST_P_DEEP_COPY && !defined(VCHAR_CONST_P_OFREE)
#define VCHAR_CONST_P_OFREE(A1) delete((A1))
#endif

#if CONST_VCHAR_P_DEEP_COPY && !defined(CONST_VCHAR_P_OFREE)
#define CONST_VCHAR_P_OFREE(A1) delete((A1))
#endif

#ifndef VCHAR_CONSTRUCTOR
#define VCHAR_CONSTRUCTOR(A1) ((A1)._constructor())
#endif

#ifndef VCHAR_DESTRUCTOR
#define VCHAR_DESTRUCTOR(A1) ((A1)._destructor())
#endif


#endif /* defined ERWIN_V_CHAR_f_h */

