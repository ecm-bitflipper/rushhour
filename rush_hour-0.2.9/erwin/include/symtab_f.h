
#ifndef ERWIN_SYMTAB_f_h
#define ERWIN_SYMTAB_f_h

struct symtab_t;
#ifndef __cplusplus
typedef struct symtab_t symtab_t;
#endif
typedef struct symtab_t Symtab;

typedef symtab_t *symtab_t_p;

typedef symtab_t const *symtab_t_const_p;

#define SYMTAB_SIG 1945594982



#ifdef SYMTAB_TP_DEEP
#  if SYMTAB_TP_DEEP
#    ifndef SYMTAB_TP_DEEP_COPY
#      define SYMTAB_TP_DEEP_COPY 1
#    endif
#    ifndef SYMTAB_TP_DEEP_COMPARE
#      define SYMTAB_TP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef SYMTAB_TP_DEEP_COPY
#      define SYMTAB_TP_DEEP_COPY 0
#    endif
#    ifndef SYMTAB_TP_DEEP_COMPARE
#      define SYMTAB_TP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef SYMTAB_TP_DEEP_COPY
#define SYMTAB_TP_DEEP_COPY 0
#endif /* !defined SYMTAB_TP_DEEP_COPY */

#ifndef SYMTAB_TP_DEEP_COMPARE
#define SYMTAB_TP_DEEP_COMPARE 0
#endif /* !defined SYMTAB_TP_DEEP_COMPARE */

#ifdef SYMTAB_T_CONSTP_DEEP
#  if SYMTAB_T_CONSTP_DEEP
#    ifndef SYMTAB_T_CONSTP_DEEP_COPY
#      define SYMTAB_T_CONSTP_DEEP_COPY 1
#    endif
#    ifndef SYMTAB_T_CONSTP_DEEP_COMPARE
#      define SYMTAB_T_CONSTP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef SYMTAB_T_CONSTP_DEEP_COPY
#      define SYMTAB_T_CONSTP_DEEP_COPY 0
#    endif
#    ifndef SYMTAB_T_CONSTP_DEEP_COMPARE
#      define SYMTAB_T_CONSTP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef SYMTAB_T_CONSTP_DEEP_COPY
#define SYMTAB_T_CONSTP_DEEP_COPY 0
#endif /* !defined SYMTAB_T_CONSTP_DEEP_COPY */

#ifndef SYMTAB_T_CONSTP_DEEP_COMPARE
#define SYMTAB_T_CONSTP_DEEP_COMPARE 0
#endif /* !defined SYMTAB_T_CONSTP_DEEP_COMPARE */

#ifdef CONST_SYMTAB_TP_DEEP
#  if CONST_SYMTAB_TP_DEEP
#    ifndef CONST_SYMTAB_TP_DEEP_COPY
#      define CONST_SYMTAB_TP_DEEP_COPY 1
#    endif
#    ifndef CONST_SYMTAB_TP_DEEP_COMPARE
#      define CONST_SYMTAB_TP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef CONST_SYMTAB_TP_DEEP_COPY
#      define CONST_SYMTAB_TP_DEEP_COPY 0
#    endif
#    ifndef CONST_SYMTAB_TP_DEEP_COMPARE
#      define CONST_SYMTAB_TP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef CONST_SYMTAB_TP_DEEP_COPY
#define CONST_SYMTAB_TP_DEEP_COPY 0
#endif /* !defined CONST_SYMTAB_TP_DEEP_COPY */

#ifndef CONST_SYMTAB_TP_DEEP_COMPARE
#define CONST_SYMTAB_TP_DEEP_COMPARE 0
#endif /* !defined CONST_SYMTAB_TP_DEEP_COMPARE */

#ifdef SYMTABP_DEEP
#  if SYMTABP_DEEP
#    ifndef SYMTABP_DEEP_COPY
#      define SYMTABP_DEEP_COPY 1
#    endif
#    ifndef SYMTABP_DEEP_COMPARE
#      define SYMTABP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef SYMTABP_DEEP_COPY
#      define SYMTABP_DEEP_COPY 0
#    endif
#    ifndef SYMTABP_DEEP_COMPARE
#      define SYMTABP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef SYMTABP_DEEP_COPY
#define SYMTABP_DEEP_COPY 0
#endif /* !defined SYMTABP_DEEP_COPY */

#ifndef SYMTABP_DEEP_COMPARE
#define SYMTABP_DEEP_COMPARE 0
#endif /* !defined SYMTABP_DEEP_COMPARE */

#ifdef SYMTAB_CONSTP_DEEP
#  if SYMTAB_CONSTP_DEEP
#    ifndef SYMTAB_CONSTP_DEEP_COPY
#      define SYMTAB_CONSTP_DEEP_COPY 1
#    endif
#    ifndef SYMTAB_CONSTP_DEEP_COMPARE
#      define SYMTAB_CONSTP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef SYMTAB_CONSTP_DEEP_COPY
#      define SYMTAB_CONSTP_DEEP_COPY 0
#    endif
#    ifndef SYMTAB_CONSTP_DEEP_COMPARE
#      define SYMTAB_CONSTP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef SYMTAB_CONSTP_DEEP_COPY
#define SYMTAB_CONSTP_DEEP_COPY 0
#endif /* !defined SYMTAB_CONSTP_DEEP_COPY */

#ifndef SYMTAB_CONSTP_DEEP_COMPARE
#define SYMTAB_CONSTP_DEEP_COMPARE 0
#endif /* !defined SYMTAB_CONSTP_DEEP_COMPARE */

#ifdef CONST_SYMTABP_DEEP
#  if CONST_SYMTABP_DEEP
#    ifndef CONST_SYMTABP_DEEP_COPY
#      define CONST_SYMTABP_DEEP_COPY 1
#    endif
#    ifndef CONST_SYMTABP_DEEP_COMPARE
#      define CONST_SYMTABP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef CONST_SYMTABP_DEEP_COPY
#      define CONST_SYMTABP_DEEP_COPY 0
#    endif
#    ifndef CONST_SYMTABP_DEEP_COMPARE
#      define CONST_SYMTABP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef CONST_SYMTABP_DEEP_COPY
#define CONST_SYMTABP_DEEP_COPY 0
#endif /* !defined CONST_SYMTABP_DEEP_COPY */

#ifndef CONST_SYMTABP_DEEP_COMPARE
#define CONST_SYMTABP_DEEP_COMPARE 0
#endif /* !defined CONST_SYMTABP_DEEP_COMPARE */

#ifdef SYMTAB_T_P_DEEP
#  if SYMTAB_T_P_DEEP
#    ifndef SYMTAB_T_P_DEEP_COPY
#      define SYMTAB_T_P_DEEP_COPY 1
#    endif
#    ifndef SYMTAB_T_P_DEEP_COMPARE
#      define SYMTAB_T_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef SYMTAB_T_P_DEEP_COPY
#      define SYMTAB_T_P_DEEP_COPY 0
#    endif
#    ifndef SYMTAB_T_P_DEEP_COMPARE
#      define SYMTAB_T_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef SYMTAB_T_P_DEEP_COPY
#define SYMTAB_T_P_DEEP_COPY 0
#endif /* !defined SYMTAB_T_P_DEEP_COPY */

#ifndef SYMTAB_T_P_DEEP_COMPARE
#define SYMTAB_T_P_DEEP_COMPARE 0
#endif /* !defined SYMTAB_T_P_DEEP_COMPARE */

#ifdef SYMTAB_T_CONST_P_DEEP
#  if SYMTAB_T_CONST_P_DEEP
#    ifndef SYMTAB_T_CONST_P_DEEP_COPY
#      define SYMTAB_T_CONST_P_DEEP_COPY 1
#    endif
#    ifndef SYMTAB_T_CONST_P_DEEP_COMPARE
#      define SYMTAB_T_CONST_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef SYMTAB_T_CONST_P_DEEP_COPY
#      define SYMTAB_T_CONST_P_DEEP_COPY 0
#    endif
#    ifndef SYMTAB_T_CONST_P_DEEP_COMPARE
#      define SYMTAB_T_CONST_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef SYMTAB_T_CONST_P_DEEP_COPY
#define SYMTAB_T_CONST_P_DEEP_COPY 0
#endif /* !defined SYMTAB_T_CONST_P_DEEP_COPY */

#ifndef SYMTAB_T_CONST_P_DEEP_COMPARE
#define SYMTAB_T_CONST_P_DEEP_COMPARE 0
#endif /* !defined SYMTAB_T_CONST_P_DEEP_COMPARE */

#ifdef CONST_SYMTAB_T_P_DEEP
#  if CONST_SYMTAB_T_P_DEEP
#    ifndef CONST_SYMTAB_T_P_DEEP_COPY
#      define CONST_SYMTAB_T_P_DEEP_COPY 1
#    endif
#    ifndef CONST_SYMTAB_T_P_DEEP_COMPARE
#      define CONST_SYMTAB_T_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef CONST_SYMTAB_T_P_DEEP_COPY
#      define CONST_SYMTAB_T_P_DEEP_COPY 0
#    endif
#    ifndef CONST_SYMTAB_T_P_DEEP_COMPARE
#      define CONST_SYMTAB_T_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef CONST_SYMTAB_T_P_DEEP_COPY
#define CONST_SYMTAB_T_P_DEEP_COPY 0
#endif /* !defined CONST_SYMTAB_T_P_DEEP_COPY */

#ifndef CONST_SYMTAB_T_P_DEEP_COMPARE
#define CONST_SYMTAB_T_P_DEEP_COMPARE 0
#endif /* !defined CONST_SYMTAB_T_P_DEEP_COMPARE */

#ifdef SYMTAB_P_DEEP
#  if SYMTAB_P_DEEP
#    ifndef SYMTAB_P_DEEP_COPY
#      define SYMTAB_P_DEEP_COPY 1
#    endif
#    ifndef SYMTAB_P_DEEP_COMPARE
#      define SYMTAB_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef SYMTAB_P_DEEP_COPY
#      define SYMTAB_P_DEEP_COPY 0
#    endif
#    ifndef SYMTAB_P_DEEP_COMPARE
#      define SYMTAB_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef SYMTAB_P_DEEP_COPY
#define SYMTAB_P_DEEP_COPY 0
#endif /* !defined SYMTAB_P_DEEP_COPY */

#ifndef SYMTAB_P_DEEP_COMPARE
#define SYMTAB_P_DEEP_COMPARE 0
#endif /* !defined SYMTAB_P_DEEP_COMPARE */

#ifdef SYMTAB_CONST_P_DEEP
#  if SYMTAB_CONST_P_DEEP
#    ifndef SYMTAB_CONST_P_DEEP_COPY
#      define SYMTAB_CONST_P_DEEP_COPY 1
#    endif
#    ifndef SYMTAB_CONST_P_DEEP_COMPARE
#      define SYMTAB_CONST_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef SYMTAB_CONST_P_DEEP_COPY
#      define SYMTAB_CONST_P_DEEP_COPY 0
#    endif
#    ifndef SYMTAB_CONST_P_DEEP_COMPARE
#      define SYMTAB_CONST_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef SYMTAB_CONST_P_DEEP_COPY
#define SYMTAB_CONST_P_DEEP_COPY 0
#endif /* !defined SYMTAB_CONST_P_DEEP_COPY */

#ifndef SYMTAB_CONST_P_DEEP_COMPARE
#define SYMTAB_CONST_P_DEEP_COMPARE 0
#endif /* !defined SYMTAB_CONST_P_DEEP_COMPARE */

#ifdef CONST_SYMTAB_P_DEEP
#  if CONST_SYMTAB_P_DEEP
#    ifndef CONST_SYMTAB_P_DEEP_COPY
#      define CONST_SYMTAB_P_DEEP_COPY 1
#    endif
#    ifndef CONST_SYMTAB_P_DEEP_COMPARE
#      define CONST_SYMTAB_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef CONST_SYMTAB_P_DEEP_COPY
#      define CONST_SYMTAB_P_DEEP_COPY 0
#    endif
#    ifndef CONST_SYMTAB_P_DEEP_COMPARE
#      define CONST_SYMTAB_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef CONST_SYMTAB_P_DEEP_COPY
#define CONST_SYMTAB_P_DEEP_COPY 0
#endif /* !defined CONST_SYMTAB_P_DEEP_COPY */

#ifndef CONST_SYMTAB_P_DEEP_COMPARE
#define CONST_SYMTAB_P_DEEP_COMPARE 0
#endif /* !defined CONST_SYMTAB_P_DEEP_COMPARE */

#if SYMTAB_TP_DEEP_COMPARE && !defined(SYMTAB_TP_HASH_RAW)
#define SYMTAB_TP_HASH_RAW(A1) symtab_hash_raw((A1))
#endif

#if SYMTAB_T_CONSTP_DEEP_COMPARE && !defined(SYMTAB_T_CONSTP_HASH_RAW)
#define SYMTAB_T_CONSTP_HASH_RAW(A1) symtab_hash_raw((A1))
#endif

#if CONST_SYMTAB_TP_DEEP_COMPARE && !defined(CONST_SYMTAB_TP_HASH_RAW)
#define CONST_SYMTAB_TP_HASH_RAW(A1) symtab_hash_raw((A1))
#endif

#if SYMTABP_DEEP_COMPARE && !defined(SYMTABP_HASH_RAW)
#define SYMTABP_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if SYMTAB_CONSTP_DEEP_COMPARE && !defined(SYMTAB_CONSTP_HASH_RAW)
#define SYMTAB_CONSTP_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if CONST_SYMTABP_DEEP_COMPARE && !defined(CONST_SYMTABP_HASH_RAW)
#define CONST_SYMTABP_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if SYMTAB_T_P_DEEP_COMPARE && !defined(SYMTAB_T_P_HASH_RAW)
#define SYMTAB_T_P_HASH_RAW(A1) symtab_hash_raw((A1))
#endif

#if SYMTAB_T_CONST_P_DEEP_COMPARE && !defined(SYMTAB_T_CONST_P_HASH_RAW)
#define SYMTAB_T_CONST_P_HASH_RAW(A1) symtab_hash_raw((A1))
#endif

#if CONST_SYMTAB_T_P_DEEP_COMPARE && !defined(CONST_SYMTAB_T_P_HASH_RAW)
#define CONST_SYMTAB_T_P_HASH_RAW(A1) symtab_hash_raw((A1))
#endif

#if SYMTAB_P_DEEP_COMPARE && !defined(SYMTAB_P_HASH_RAW)
#define SYMTAB_P_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if SYMTAB_CONST_P_DEEP_COMPARE && !defined(SYMTAB_CONST_P_HASH_RAW)
#define SYMTAB_CONST_P_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if CONST_SYMTAB_P_DEEP_COMPARE && !defined(CONST_SYMTAB_P_HASH_RAW)
#define CONST_SYMTAB_P_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#ifndef SYMTAB_HASH_RAW
#define SYMTAB_HASH_RAW(A1) ((A1).hash_raw())
#endif

#if SYMTAB_TP_DEEP_COMPARE && !defined(SYMTAB_TP_CMP)
#define SYMTAB_TP_CMP(A1,A2) symtab_cmp((A1),(A2))
#endif

#if SYMTAB_T_CONSTP_DEEP_COMPARE && !defined(SYMTAB_T_CONSTP_CMP)
#define SYMTAB_T_CONSTP_CMP(A1,A2) symtab_cmp((A1),(A2))
#endif

#if CONST_SYMTAB_TP_DEEP_COMPARE && !defined(CONST_SYMTAB_TP_CMP)
#define CONST_SYMTAB_TP_CMP(A1,A2) symtab_cmp((A1),(A2))
#endif

#if SYMTABP_DEEP_COMPARE && !defined(SYMTABP_CMP)
#define SYMTABP_CMP(A1,A2) ((A1)->cmp((A2)))
#endif

#if SYMTAB_CONSTP_DEEP_COMPARE && !defined(SYMTAB_CONSTP_CMP)
#define SYMTAB_CONSTP_CMP(A1,A2) ((A1)->cmp((A2)))
#endif

#if CONST_SYMTABP_DEEP_COMPARE && !defined(CONST_SYMTABP_CMP)
#define CONST_SYMTABP_CMP(A1,A2) ((A1)->cmp((A2)))
#endif

#if SYMTAB_T_P_DEEP_COMPARE && !defined(SYMTAB_T_P_CMP)
#define SYMTAB_T_P_CMP(A1,A2) symtab_cmp((A1),(A2))
#endif

#if SYMTAB_T_CONST_P_DEEP_COMPARE && !defined(SYMTAB_T_CONST_P_CMP)
#define SYMTAB_T_CONST_P_CMP(A1,A2) symtab_cmp((A1),(A2))
#endif

#if CONST_SYMTAB_T_P_DEEP_COMPARE && !defined(CONST_SYMTAB_T_P_CMP)
#define CONST_SYMTAB_T_P_CMP(A1,A2) symtab_cmp((A1),(A2))
#endif

#if SYMTAB_P_DEEP_COMPARE && !defined(SYMTAB_P_CMP)
#define SYMTAB_P_CMP(A1,A2) ((A1)->cmp((A2)))
#endif

#if SYMTAB_CONST_P_DEEP_COMPARE && !defined(SYMTAB_CONST_P_CMP)
#define SYMTAB_CONST_P_CMP(A1,A2) ((A1)->cmp((A2)))
#endif

#if CONST_SYMTAB_P_DEEP_COMPARE && !defined(CONST_SYMTAB_P_CMP)
#define CONST_SYMTAB_P_CMP(A1,A2) ((A1)->cmp((A2)))
#endif

#ifndef SYMTAB_CMP
#define SYMTAB_CMP(A1,A2) ((A1).cmp((A2)))
#endif

#ifndef SYMTAB_ZERO
#define SYMTAB_ZERO (Symtab::static_zero())
#endif

#if SYMTAB_TP_DEEP_COMPARE && !defined(SYMTAB_TP_EQUAL)
#define SYMTAB_TP_EQUAL(A1,A2) symtab_equal((A1),(A2))
#endif

#if SYMTAB_T_CONSTP_DEEP_COMPARE && !defined(SYMTAB_T_CONSTP_EQUAL)
#define SYMTAB_T_CONSTP_EQUAL(A1,A2) symtab_equal((A1),(A2))
#endif

#if CONST_SYMTAB_TP_DEEP_COMPARE && !defined(CONST_SYMTAB_TP_EQUAL)
#define CONST_SYMTAB_TP_EQUAL(A1,A2) symtab_equal((A1),(A2))
#endif

#if SYMTABP_DEEP_COMPARE && !defined(SYMTABP_EQUAL)
#define SYMTABP_EQUAL(A1,A2) ((A1)->equal((A2)))
#endif

#if SYMTAB_CONSTP_DEEP_COMPARE && !defined(SYMTAB_CONSTP_EQUAL)
#define SYMTAB_CONSTP_EQUAL(A1,A2) ((A1)->equal((A2)))
#endif

#if CONST_SYMTABP_DEEP_COMPARE && !defined(CONST_SYMTABP_EQUAL)
#define CONST_SYMTABP_EQUAL(A1,A2) ((A1)->equal((A2)))
#endif

#if SYMTAB_T_P_DEEP_COMPARE && !defined(SYMTAB_T_P_EQUAL)
#define SYMTAB_T_P_EQUAL(A1,A2) symtab_equal((A1),(A2))
#endif

#if SYMTAB_T_CONST_P_DEEP_COMPARE && !defined(SYMTAB_T_CONST_P_EQUAL)
#define SYMTAB_T_CONST_P_EQUAL(A1,A2) symtab_equal((A1),(A2))
#endif

#if CONST_SYMTAB_T_P_DEEP_COMPARE && !defined(CONST_SYMTAB_T_P_EQUAL)
#define CONST_SYMTAB_T_P_EQUAL(A1,A2) symtab_equal((A1),(A2))
#endif

#if SYMTAB_P_DEEP_COMPARE && !defined(SYMTAB_P_EQUAL)
#define SYMTAB_P_EQUAL(A1,A2) ((A1)->equal((A2)))
#endif

#if SYMTAB_CONST_P_DEEP_COMPARE && !defined(SYMTAB_CONST_P_EQUAL)
#define SYMTAB_CONST_P_EQUAL(A1,A2) ((A1)->equal((A2)))
#endif

#if CONST_SYMTAB_P_DEEP_COMPARE && !defined(CONST_SYMTAB_P_EQUAL)
#define CONST_SYMTAB_P_EQUAL(A1,A2) ((A1)->equal((A2)))
#endif

#ifndef SYMTAB_EQUAL
#define SYMTAB_EQUAL(A1,A2) ((A1).equal((A2)))
#endif

#if SYMTAB_TP_DEEP_COPY && !defined(SYMTAB_TP_ICOPY)
#define SYMTAB_TP_ICOPY(A1,A2) symtab_copy_err((A1),(A2))
#endif

#if SYMTAB_T_CONSTP_DEEP_COPY && !defined(SYMTAB_T_CONSTP_ICOPY)
#define SYMTAB_T_CONSTP_ICOPY(A1,A2) symtab_copy_err((A1),(A2))
#endif

#if CONST_SYMTAB_TP_DEEP_COPY && !defined(CONST_SYMTAB_TP_ICOPY)
#define CONST_SYMTAB_TP_ICOPY(A1,A2) symtab_copy_err((A1),(A2))
#endif

#if SYMTABP_DEEP_COPY && !defined(SYMTABP_ICOPY)
#define SYMTABP_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if SYMTAB_CONSTP_DEEP_COPY && !defined(SYMTAB_CONSTP_ICOPY)
#define SYMTAB_CONSTP_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if CONST_SYMTABP_DEEP_COPY && !defined(CONST_SYMTABP_ICOPY)
#define CONST_SYMTABP_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if SYMTAB_T_P_DEEP_COPY && !defined(SYMTAB_T_P_ICOPY)
#define SYMTAB_T_P_ICOPY(A1,A2) symtab_copy_err((A1),(A2))
#endif

#if SYMTAB_T_CONST_P_DEEP_COPY && !defined(SYMTAB_T_CONST_P_ICOPY)
#define SYMTAB_T_CONST_P_ICOPY(A1,A2) symtab_copy_err((A1),(A2))
#endif

#if CONST_SYMTAB_T_P_DEEP_COPY && !defined(CONST_SYMTAB_T_P_ICOPY)
#define CONST_SYMTAB_T_P_ICOPY(A1,A2) symtab_copy_err((A1),(A2))
#endif

#if SYMTAB_P_DEEP_COPY && !defined(SYMTAB_P_ICOPY)
#define SYMTAB_P_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if SYMTAB_CONST_P_DEEP_COPY && !defined(SYMTAB_CONST_P_ICOPY)
#define SYMTAB_CONST_P_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if CONST_SYMTAB_P_DEEP_COPY && !defined(CONST_SYMTAB_P_ICOPY)
#define CONST_SYMTAB_P_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if SYMTAB_TP_DEEP_COPY && !defined(SYMTAB_TP_OCOPY)
#define SYMTAB_TP_OCOPY(A1,A2) symtab_copy_err((A1),(A2))
#endif

#if SYMTAB_T_CONSTP_DEEP_COPY && !defined(SYMTAB_T_CONSTP_OCOPY)
#define SYMTAB_T_CONSTP_OCOPY(A1,A2) symtab_copy_err((A1),(A2))
#endif

#if CONST_SYMTAB_TP_DEEP_COPY && !defined(CONST_SYMTAB_TP_OCOPY)
#define CONST_SYMTAB_TP_OCOPY(A1,A2) symtab_copy_err((A1),(A2))
#endif

#if SYMTABP_DEEP_COPY && !defined(SYMTABP_OCOPY)
#define SYMTABP_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if SYMTAB_CONSTP_DEEP_COPY && !defined(SYMTAB_CONSTP_OCOPY)
#define SYMTAB_CONSTP_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if CONST_SYMTABP_DEEP_COPY && !defined(CONST_SYMTABP_OCOPY)
#define CONST_SYMTABP_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if SYMTAB_T_P_DEEP_COPY && !defined(SYMTAB_T_P_OCOPY)
#define SYMTAB_T_P_OCOPY(A1,A2) symtab_copy_err((A1),(A2))
#endif

#if SYMTAB_T_CONST_P_DEEP_COPY && !defined(SYMTAB_T_CONST_P_OCOPY)
#define SYMTAB_T_CONST_P_OCOPY(A1,A2) symtab_copy_err((A1),(A2))
#endif

#if CONST_SYMTAB_T_P_DEEP_COPY && !defined(CONST_SYMTAB_T_P_OCOPY)
#define CONST_SYMTAB_T_P_OCOPY(A1,A2) symtab_copy_err((A1),(A2))
#endif

#if SYMTAB_P_DEEP_COPY && !defined(SYMTAB_P_OCOPY)
#define SYMTAB_P_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if SYMTAB_CONST_P_DEEP_COPY && !defined(SYMTAB_CONST_P_OCOPY)
#define SYMTAB_CONST_P_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if CONST_SYMTAB_P_DEEP_COPY && !defined(CONST_SYMTAB_P_OCOPY)
#define CONST_SYMTAB_P_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if SYMTAB_TP_DEEP_COPY && !defined(SYMTAB_TP_IFREE)
#define SYMTAB_TP_IFREE(A1) symtab_delete((A1))
#endif

#if SYMTAB_T_CONSTP_DEEP_COPY && !defined(SYMTAB_T_CONSTP_IFREE)
#define SYMTAB_T_CONSTP_IFREE(A1) symtab_delete((A1))
#endif

#if CONST_SYMTAB_TP_DEEP_COPY && !defined(CONST_SYMTAB_TP_IFREE)
#define CONST_SYMTAB_TP_IFREE(A1) symtab_delete((A1))
#endif

#if SYMTABP_DEEP_COPY && !defined(SYMTABP_IFREE)
#define SYMTABP_IFREE(A1) delete((A1))
#endif

#if SYMTAB_CONSTP_DEEP_COPY && !defined(SYMTAB_CONSTP_IFREE)
#define SYMTAB_CONSTP_IFREE(A1) delete((A1))
#endif

#if CONST_SYMTABP_DEEP_COPY && !defined(CONST_SYMTABP_IFREE)
#define CONST_SYMTABP_IFREE(A1) delete((A1))
#endif

#if SYMTAB_T_P_DEEP_COPY && !defined(SYMTAB_T_P_IFREE)
#define SYMTAB_T_P_IFREE(A1) symtab_delete((A1))
#endif

#if SYMTAB_T_CONST_P_DEEP_COPY && !defined(SYMTAB_T_CONST_P_IFREE)
#define SYMTAB_T_CONST_P_IFREE(A1) symtab_delete((A1))
#endif

#if CONST_SYMTAB_T_P_DEEP_COPY && !defined(CONST_SYMTAB_T_P_IFREE)
#define CONST_SYMTAB_T_P_IFREE(A1) symtab_delete((A1))
#endif

#if SYMTAB_P_DEEP_COPY && !defined(SYMTAB_P_IFREE)
#define SYMTAB_P_IFREE(A1) delete((A1))
#endif

#if SYMTAB_CONST_P_DEEP_COPY && !defined(SYMTAB_CONST_P_IFREE)
#define SYMTAB_CONST_P_IFREE(A1) delete((A1))
#endif

#if CONST_SYMTAB_P_DEEP_COPY && !defined(CONST_SYMTAB_P_IFREE)
#define CONST_SYMTAB_P_IFREE(A1) delete((A1))
#endif

#if SYMTAB_TP_DEEP_COPY && !defined(SYMTAB_TP_OFREE)
#define SYMTAB_TP_OFREE(A1) symtab_delete((A1))
#endif

#if SYMTAB_T_CONSTP_DEEP_COPY && !defined(SYMTAB_T_CONSTP_OFREE)
#define SYMTAB_T_CONSTP_OFREE(A1) symtab_delete((A1))
#endif

#if CONST_SYMTAB_TP_DEEP_COPY && !defined(CONST_SYMTAB_TP_OFREE)
#define CONST_SYMTAB_TP_OFREE(A1) symtab_delete((A1))
#endif

#if SYMTABP_DEEP_COPY && !defined(SYMTABP_OFREE)
#define SYMTABP_OFREE(A1) delete((A1))
#endif

#if SYMTAB_CONSTP_DEEP_COPY && !defined(SYMTAB_CONSTP_OFREE)
#define SYMTAB_CONSTP_OFREE(A1) delete((A1))
#endif

#if CONST_SYMTABP_DEEP_COPY && !defined(CONST_SYMTABP_OFREE)
#define CONST_SYMTABP_OFREE(A1) delete((A1))
#endif

#if SYMTAB_T_P_DEEP_COPY && !defined(SYMTAB_T_P_OFREE)
#define SYMTAB_T_P_OFREE(A1) symtab_delete((A1))
#endif

#if SYMTAB_T_CONST_P_DEEP_COPY && !defined(SYMTAB_T_CONST_P_OFREE)
#define SYMTAB_T_CONST_P_OFREE(A1) symtab_delete((A1))
#endif

#if CONST_SYMTAB_T_P_DEEP_COPY && !defined(CONST_SYMTAB_T_P_OFREE)
#define CONST_SYMTAB_T_P_OFREE(A1) symtab_delete((A1))
#endif

#if SYMTAB_P_DEEP_COPY && !defined(SYMTAB_P_OFREE)
#define SYMTAB_P_OFREE(A1) delete((A1))
#endif

#if SYMTAB_CONST_P_DEEP_COPY && !defined(SYMTAB_CONST_P_OFREE)
#define SYMTAB_CONST_P_OFREE(A1) delete((A1))
#endif

#if CONST_SYMTAB_P_DEEP_COPY && !defined(CONST_SYMTAB_P_OFREE)
#define CONST_SYMTAB_P_OFREE(A1) delete((A1))
#endif

#ifndef SYMTAB_CONSTRUCTOR
#define SYMTAB_CONSTRUCTOR(A1) ((A1)._constructor())
#endif

#ifndef SYMTAB_DESTRUCTOR
#define SYMTAB_DESTRUCTOR(A1) ((A1)._destructor())
#endif


#endif /* defined ERWIN_SYMTAB_f_h */

