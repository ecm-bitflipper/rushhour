
#ifndef ERWIN_ERR_V_STREAM_f_h
#define ERWIN_ERR_V_STREAM_f_h

/* Unification of ErrVStream and err_v_stream_t: they are identical now. */
struct err_v_stream_t;

#ifndef __cplusplus
typedef struct err_v_stream_t err_v_stream_t;
#endif /* not defined __cplusplus */

typedef err_v_stream_t ErrVStream;

typedef err_v_stream_t *err_v_stream_t_p;

typedef err_v_stream_t const *err_v_stream_t_const_p;

#define ERR_V_STREAM_SIG 348153875



#ifdef ERR_ERR_V_STREAM_TP_DEEP
#  if ERR_ERR_V_STREAM_TP_DEEP
#    ifndef ERR_ERR_V_STREAM_TP_DEEP_COPY
#      define ERR_ERR_V_STREAM_TP_DEEP_COPY 1
#    endif
#    ifndef ERR_ERR_V_STREAM_TP_DEEP_COMPARE
#      define ERR_ERR_V_STREAM_TP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERR_V_STREAM_TP_DEEP_COPY
#      define ERR_ERR_V_STREAM_TP_DEEP_COPY 0
#    endif
#    ifndef ERR_ERR_V_STREAM_TP_DEEP_COMPARE
#      define ERR_ERR_V_STREAM_TP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERR_V_STREAM_TP_DEEP_COPY
#define ERR_ERR_V_STREAM_TP_DEEP_COPY 0
#endif /* !defined ERR_ERR_V_STREAM_TP_DEEP_COPY */

#ifndef ERR_ERR_V_STREAM_TP_DEEP_COMPARE
#define ERR_ERR_V_STREAM_TP_DEEP_COMPARE 0
#endif /* !defined ERR_ERR_V_STREAM_TP_DEEP_COMPARE */

#ifdef ERR_ERR_V_STREAM_T_CONSTP_DEEP
#  if ERR_ERR_V_STREAM_T_CONSTP_DEEP
#    ifndef ERR_ERR_V_STREAM_T_CONSTP_DEEP_COPY
#      define ERR_ERR_V_STREAM_T_CONSTP_DEEP_COPY 1
#    endif
#    ifndef ERR_ERR_V_STREAM_T_CONSTP_DEEP_COMPARE
#      define ERR_ERR_V_STREAM_T_CONSTP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERR_V_STREAM_T_CONSTP_DEEP_COPY
#      define ERR_ERR_V_STREAM_T_CONSTP_DEEP_COPY 0
#    endif
#    ifndef ERR_ERR_V_STREAM_T_CONSTP_DEEP_COMPARE
#      define ERR_ERR_V_STREAM_T_CONSTP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERR_V_STREAM_T_CONSTP_DEEP_COPY
#define ERR_ERR_V_STREAM_T_CONSTP_DEEP_COPY 0
#endif /* !defined ERR_ERR_V_STREAM_T_CONSTP_DEEP_COPY */

#ifndef ERR_ERR_V_STREAM_T_CONSTP_DEEP_COMPARE
#define ERR_ERR_V_STREAM_T_CONSTP_DEEP_COMPARE 0
#endif /* !defined ERR_ERR_V_STREAM_T_CONSTP_DEEP_COMPARE */

#ifdef ERR_CONST_ERR_V_STREAM_TP_DEEP
#  if ERR_CONST_ERR_V_STREAM_TP_DEEP
#    ifndef ERR_CONST_ERR_V_STREAM_TP_DEEP_COPY
#      define ERR_CONST_ERR_V_STREAM_TP_DEEP_COPY 1
#    endif
#    ifndef ERR_CONST_ERR_V_STREAM_TP_DEEP_COMPARE
#      define ERR_CONST_ERR_V_STREAM_TP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_CONST_ERR_V_STREAM_TP_DEEP_COPY
#      define ERR_CONST_ERR_V_STREAM_TP_DEEP_COPY 0
#    endif
#    ifndef ERR_CONST_ERR_V_STREAM_TP_DEEP_COMPARE
#      define ERR_CONST_ERR_V_STREAM_TP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_CONST_ERR_V_STREAM_TP_DEEP_COPY
#define ERR_CONST_ERR_V_STREAM_TP_DEEP_COPY 0
#endif /* !defined ERR_CONST_ERR_V_STREAM_TP_DEEP_COPY */

#ifndef ERR_CONST_ERR_V_STREAM_TP_DEEP_COMPARE
#define ERR_CONST_ERR_V_STREAM_TP_DEEP_COMPARE 0
#endif /* !defined ERR_CONST_ERR_V_STREAM_TP_DEEP_COMPARE */

#ifdef ERR_ERRVSTREAMP_DEEP
#  if ERR_ERRVSTREAMP_DEEP
#    ifndef ERR_ERRVSTREAMP_DEEP_COPY
#      define ERR_ERRVSTREAMP_DEEP_COPY 1
#    endif
#    ifndef ERR_ERRVSTREAMP_DEEP_COMPARE
#      define ERR_ERRVSTREAMP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERRVSTREAMP_DEEP_COPY
#      define ERR_ERRVSTREAMP_DEEP_COPY 0
#    endif
#    ifndef ERR_ERRVSTREAMP_DEEP_COMPARE
#      define ERR_ERRVSTREAMP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERRVSTREAMP_DEEP_COPY
#define ERR_ERRVSTREAMP_DEEP_COPY 0
#endif /* !defined ERR_ERRVSTREAMP_DEEP_COPY */

#ifndef ERR_ERRVSTREAMP_DEEP_COMPARE
#define ERR_ERRVSTREAMP_DEEP_COMPARE 0
#endif /* !defined ERR_ERRVSTREAMP_DEEP_COMPARE */

#ifdef ERR_ERRVSTREAM_CONSTP_DEEP
#  if ERR_ERRVSTREAM_CONSTP_DEEP
#    ifndef ERR_ERRVSTREAM_CONSTP_DEEP_COPY
#      define ERR_ERRVSTREAM_CONSTP_DEEP_COPY 1
#    endif
#    ifndef ERR_ERRVSTREAM_CONSTP_DEEP_COMPARE
#      define ERR_ERRVSTREAM_CONSTP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERRVSTREAM_CONSTP_DEEP_COPY
#      define ERR_ERRVSTREAM_CONSTP_DEEP_COPY 0
#    endif
#    ifndef ERR_ERRVSTREAM_CONSTP_DEEP_COMPARE
#      define ERR_ERRVSTREAM_CONSTP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERRVSTREAM_CONSTP_DEEP_COPY
#define ERR_ERRVSTREAM_CONSTP_DEEP_COPY 0
#endif /* !defined ERR_ERRVSTREAM_CONSTP_DEEP_COPY */

#ifndef ERR_ERRVSTREAM_CONSTP_DEEP_COMPARE
#define ERR_ERRVSTREAM_CONSTP_DEEP_COMPARE 0
#endif /* !defined ERR_ERRVSTREAM_CONSTP_DEEP_COMPARE */

#ifdef ERR_CONST_ERRVSTREAMP_DEEP
#  if ERR_CONST_ERRVSTREAMP_DEEP
#    ifndef ERR_CONST_ERRVSTREAMP_DEEP_COPY
#      define ERR_CONST_ERRVSTREAMP_DEEP_COPY 1
#    endif
#    ifndef ERR_CONST_ERRVSTREAMP_DEEP_COMPARE
#      define ERR_CONST_ERRVSTREAMP_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_CONST_ERRVSTREAMP_DEEP_COPY
#      define ERR_CONST_ERRVSTREAMP_DEEP_COPY 0
#    endif
#    ifndef ERR_CONST_ERRVSTREAMP_DEEP_COMPARE
#      define ERR_CONST_ERRVSTREAMP_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_CONST_ERRVSTREAMP_DEEP_COPY
#define ERR_CONST_ERRVSTREAMP_DEEP_COPY 0
#endif /* !defined ERR_CONST_ERRVSTREAMP_DEEP_COPY */

#ifndef ERR_CONST_ERRVSTREAMP_DEEP_COMPARE
#define ERR_CONST_ERRVSTREAMP_DEEP_COMPARE 0
#endif /* !defined ERR_CONST_ERRVSTREAMP_DEEP_COMPARE */

#ifdef ERR_ERR_V_STREAM_T_P_DEEP
#  if ERR_ERR_V_STREAM_T_P_DEEP
#    ifndef ERR_ERR_V_STREAM_T_P_DEEP_COPY
#      define ERR_ERR_V_STREAM_T_P_DEEP_COPY 1
#    endif
#    ifndef ERR_ERR_V_STREAM_T_P_DEEP_COMPARE
#      define ERR_ERR_V_STREAM_T_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERR_V_STREAM_T_P_DEEP_COPY
#      define ERR_ERR_V_STREAM_T_P_DEEP_COPY 0
#    endif
#    ifndef ERR_ERR_V_STREAM_T_P_DEEP_COMPARE
#      define ERR_ERR_V_STREAM_T_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERR_V_STREAM_T_P_DEEP_COPY
#define ERR_ERR_V_STREAM_T_P_DEEP_COPY 0
#endif /* !defined ERR_ERR_V_STREAM_T_P_DEEP_COPY */

#ifndef ERR_ERR_V_STREAM_T_P_DEEP_COMPARE
#define ERR_ERR_V_STREAM_T_P_DEEP_COMPARE 0
#endif /* !defined ERR_ERR_V_STREAM_T_P_DEEP_COMPARE */

#ifdef ERR_ERR_V_STREAM_T_CONST_P_DEEP
#  if ERR_ERR_V_STREAM_T_CONST_P_DEEP
#    ifndef ERR_ERR_V_STREAM_T_CONST_P_DEEP_COPY
#      define ERR_ERR_V_STREAM_T_CONST_P_DEEP_COPY 1
#    endif
#    ifndef ERR_ERR_V_STREAM_T_CONST_P_DEEP_COMPARE
#      define ERR_ERR_V_STREAM_T_CONST_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERR_V_STREAM_T_CONST_P_DEEP_COPY
#      define ERR_ERR_V_STREAM_T_CONST_P_DEEP_COPY 0
#    endif
#    ifndef ERR_ERR_V_STREAM_T_CONST_P_DEEP_COMPARE
#      define ERR_ERR_V_STREAM_T_CONST_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERR_V_STREAM_T_CONST_P_DEEP_COPY
#define ERR_ERR_V_STREAM_T_CONST_P_DEEP_COPY 0
#endif /* !defined ERR_ERR_V_STREAM_T_CONST_P_DEEP_COPY */

#ifndef ERR_ERR_V_STREAM_T_CONST_P_DEEP_COMPARE
#define ERR_ERR_V_STREAM_T_CONST_P_DEEP_COMPARE 0
#endif /* !defined ERR_ERR_V_STREAM_T_CONST_P_DEEP_COMPARE */

#ifdef ERR_CONST_ERR_V_STREAM_T_P_DEEP
#  if ERR_CONST_ERR_V_STREAM_T_P_DEEP
#    ifndef ERR_CONST_ERR_V_STREAM_T_P_DEEP_COPY
#      define ERR_CONST_ERR_V_STREAM_T_P_DEEP_COPY 1
#    endif
#    ifndef ERR_CONST_ERR_V_STREAM_T_P_DEEP_COMPARE
#      define ERR_CONST_ERR_V_STREAM_T_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_CONST_ERR_V_STREAM_T_P_DEEP_COPY
#      define ERR_CONST_ERR_V_STREAM_T_P_DEEP_COPY 0
#    endif
#    ifndef ERR_CONST_ERR_V_STREAM_T_P_DEEP_COMPARE
#      define ERR_CONST_ERR_V_STREAM_T_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_CONST_ERR_V_STREAM_T_P_DEEP_COPY
#define ERR_CONST_ERR_V_STREAM_T_P_DEEP_COPY 0
#endif /* !defined ERR_CONST_ERR_V_STREAM_T_P_DEEP_COPY */

#ifndef ERR_CONST_ERR_V_STREAM_T_P_DEEP_COMPARE
#define ERR_CONST_ERR_V_STREAM_T_P_DEEP_COMPARE 0
#endif /* !defined ERR_CONST_ERR_V_STREAM_T_P_DEEP_COMPARE */

#ifdef ERR_ERRVSTREAM_P_DEEP
#  if ERR_ERRVSTREAM_P_DEEP
#    ifndef ERR_ERRVSTREAM_P_DEEP_COPY
#      define ERR_ERRVSTREAM_P_DEEP_COPY 1
#    endif
#    ifndef ERR_ERRVSTREAM_P_DEEP_COMPARE
#      define ERR_ERRVSTREAM_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERRVSTREAM_P_DEEP_COPY
#      define ERR_ERRVSTREAM_P_DEEP_COPY 0
#    endif
#    ifndef ERR_ERRVSTREAM_P_DEEP_COMPARE
#      define ERR_ERRVSTREAM_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERRVSTREAM_P_DEEP_COPY
#define ERR_ERRVSTREAM_P_DEEP_COPY 0
#endif /* !defined ERR_ERRVSTREAM_P_DEEP_COPY */

#ifndef ERR_ERRVSTREAM_P_DEEP_COMPARE
#define ERR_ERRVSTREAM_P_DEEP_COMPARE 0
#endif /* !defined ERR_ERRVSTREAM_P_DEEP_COMPARE */

#ifdef ERR_ERRVSTREAM_CONST_P_DEEP
#  if ERR_ERRVSTREAM_CONST_P_DEEP
#    ifndef ERR_ERRVSTREAM_CONST_P_DEEP_COPY
#      define ERR_ERRVSTREAM_CONST_P_DEEP_COPY 1
#    endif
#    ifndef ERR_ERRVSTREAM_CONST_P_DEEP_COMPARE
#      define ERR_ERRVSTREAM_CONST_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_ERRVSTREAM_CONST_P_DEEP_COPY
#      define ERR_ERRVSTREAM_CONST_P_DEEP_COPY 0
#    endif
#    ifndef ERR_ERRVSTREAM_CONST_P_DEEP_COMPARE
#      define ERR_ERRVSTREAM_CONST_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_ERRVSTREAM_CONST_P_DEEP_COPY
#define ERR_ERRVSTREAM_CONST_P_DEEP_COPY 0
#endif /* !defined ERR_ERRVSTREAM_CONST_P_DEEP_COPY */

#ifndef ERR_ERRVSTREAM_CONST_P_DEEP_COMPARE
#define ERR_ERRVSTREAM_CONST_P_DEEP_COMPARE 0
#endif /* !defined ERR_ERRVSTREAM_CONST_P_DEEP_COMPARE */

#ifdef ERR_CONST_ERRVSTREAM_P_DEEP
#  if ERR_CONST_ERRVSTREAM_P_DEEP
#    ifndef ERR_CONST_ERRVSTREAM_P_DEEP_COPY
#      define ERR_CONST_ERRVSTREAM_P_DEEP_COPY 1
#    endif
#    ifndef ERR_CONST_ERRVSTREAM_P_DEEP_COMPARE
#      define ERR_CONST_ERRVSTREAM_P_DEEP_COMPARE 1
#    endif
#  else
#    ifndef ERR_CONST_ERRVSTREAM_P_DEEP_COPY
#      define ERR_CONST_ERRVSTREAM_P_DEEP_COPY 0
#    endif
#    ifndef ERR_CONST_ERRVSTREAM_P_DEEP_COMPARE
#      define ERR_CONST_ERRVSTREAM_P_DEEP_COMPARE 0
#    endif
#  endif
#endif
#ifndef ERR_CONST_ERRVSTREAM_P_DEEP_COPY
#define ERR_CONST_ERRVSTREAM_P_DEEP_COPY 0
#endif /* !defined ERR_CONST_ERRVSTREAM_P_DEEP_COPY */

#ifndef ERR_CONST_ERRVSTREAM_P_DEEP_COMPARE
#define ERR_CONST_ERRVSTREAM_P_DEEP_COMPARE 0
#endif /* !defined ERR_CONST_ERRVSTREAM_P_DEEP_COMPARE */

#if ERR_ERR_V_STREAM_TP_DEEP_COMPARE && !defined(ERR_ERR_V_STREAM_TP_HASH_RAW)
#define ERR_ERR_V_STREAM_TP_HASH_RAW(A1) err_v_stream_hash_raw((A1))
#endif

#if ERR_ERR_V_STREAM_T_CONSTP_DEEP_COMPARE && !defined(ERR_ERR_V_STREAM_T_CONSTP_HASH_RAW)
#define ERR_ERR_V_STREAM_T_CONSTP_HASH_RAW(A1) err_v_stream_hash_raw((A1))
#endif

#if ERR_CONST_ERR_V_STREAM_TP_DEEP_COMPARE && !defined(ERR_CONST_ERR_V_STREAM_TP_HASH_RAW)
#define ERR_CONST_ERR_V_STREAM_TP_HASH_RAW(A1) err_v_stream_hash_raw((A1))
#endif

#if ERR_ERRVSTREAMP_DEEP_COMPARE && !defined(ERR_ERRVSTREAMP_HASH_RAW)
#define ERR_ERRVSTREAMP_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if ERR_ERRVSTREAM_CONSTP_DEEP_COMPARE && !defined(ERR_ERRVSTREAM_CONSTP_HASH_RAW)
#define ERR_ERRVSTREAM_CONSTP_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if ERR_CONST_ERRVSTREAMP_DEEP_COMPARE && !defined(ERR_CONST_ERRVSTREAMP_HASH_RAW)
#define ERR_CONST_ERRVSTREAMP_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if ERR_ERR_V_STREAM_T_P_DEEP_COMPARE && !defined(ERR_ERR_V_STREAM_T_P_HASH_RAW)
#define ERR_ERR_V_STREAM_T_P_HASH_RAW(A1) err_v_stream_hash_raw((A1))
#endif

#if ERR_ERR_V_STREAM_T_CONST_P_DEEP_COMPARE && !defined(ERR_ERR_V_STREAM_T_CONST_P_HASH_RAW)
#define ERR_ERR_V_STREAM_T_CONST_P_HASH_RAW(A1) err_v_stream_hash_raw((A1))
#endif

#if ERR_CONST_ERR_V_STREAM_T_P_DEEP_COMPARE && !defined(ERR_CONST_ERR_V_STREAM_T_P_HASH_RAW)
#define ERR_CONST_ERR_V_STREAM_T_P_HASH_RAW(A1) err_v_stream_hash_raw((A1))
#endif

#if ERR_ERRVSTREAM_P_DEEP_COMPARE && !defined(ERR_ERRVSTREAM_P_HASH_RAW)
#define ERR_ERRVSTREAM_P_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if ERR_ERRVSTREAM_CONST_P_DEEP_COMPARE && !defined(ERR_ERRVSTREAM_CONST_P_HASH_RAW)
#define ERR_ERRVSTREAM_CONST_P_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#if ERR_CONST_ERRVSTREAM_P_DEEP_COMPARE && !defined(ERR_CONST_ERRVSTREAM_P_HASH_RAW)
#define ERR_CONST_ERRVSTREAM_P_HASH_RAW(A1) ((A1)->hash_raw())
#endif

#ifndef ERR_ERRVSTREAM_HASH_RAW
#define ERR_ERRVSTREAM_HASH_RAW(A1) ((A1).hash_raw())
#endif

#if ERR_ERR_V_STREAM_TP_DEEP_COMPARE && !defined(ERR_ERR_V_STREAM_TP_CMP)
#define ERR_ERR_V_STREAM_TP_CMP(A1,A2) err_v_stream_cmp((A1),(A2),NULL)
#endif

#if ERR_ERR_V_STREAM_T_CONSTP_DEEP_COMPARE && !defined(ERR_ERR_V_STREAM_T_CONSTP_CMP)
#define ERR_ERR_V_STREAM_T_CONSTP_CMP(A1,A2) err_v_stream_cmp((A1),(A2),NULL)
#endif

#if ERR_CONST_ERR_V_STREAM_TP_DEEP_COMPARE && !defined(ERR_CONST_ERR_V_STREAM_TP_CMP)
#define ERR_CONST_ERR_V_STREAM_TP_CMP(A1,A2) err_v_stream_cmp((A1),(A2),NULL)
#endif

#if ERR_ERRVSTREAMP_DEEP_COMPARE && !defined(ERR_ERRVSTREAMP_CMP)
#define ERR_ERRVSTREAMP_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if ERR_ERRVSTREAM_CONSTP_DEEP_COMPARE && !defined(ERR_ERRVSTREAM_CONSTP_CMP)
#define ERR_ERRVSTREAM_CONSTP_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if ERR_CONST_ERRVSTREAMP_DEEP_COMPARE && !defined(ERR_CONST_ERRVSTREAMP_CMP)
#define ERR_CONST_ERRVSTREAMP_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if ERR_ERR_V_STREAM_T_P_DEEP_COMPARE && !defined(ERR_ERR_V_STREAM_T_P_CMP)
#define ERR_ERR_V_STREAM_T_P_CMP(A1,A2) err_v_stream_cmp((A1),(A2),NULL)
#endif

#if ERR_ERR_V_STREAM_T_CONST_P_DEEP_COMPARE && !defined(ERR_ERR_V_STREAM_T_CONST_P_CMP)
#define ERR_ERR_V_STREAM_T_CONST_P_CMP(A1,A2) err_v_stream_cmp((A1),(A2),NULL)
#endif

#if ERR_CONST_ERR_V_STREAM_T_P_DEEP_COMPARE && !defined(ERR_CONST_ERR_V_STREAM_T_P_CMP)
#define ERR_CONST_ERR_V_STREAM_T_P_CMP(A1,A2) err_v_stream_cmp((A1),(A2),NULL)
#endif

#if ERR_ERRVSTREAM_P_DEEP_COMPARE && !defined(ERR_ERRVSTREAM_P_CMP)
#define ERR_ERRVSTREAM_P_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if ERR_ERRVSTREAM_CONST_P_DEEP_COMPARE && !defined(ERR_ERRVSTREAM_CONST_P_CMP)
#define ERR_ERRVSTREAM_CONST_P_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#if ERR_CONST_ERRVSTREAM_P_DEEP_COMPARE && !defined(ERR_CONST_ERRVSTREAM_P_CMP)
#define ERR_CONST_ERRVSTREAM_P_CMP(A1,A2) ((A1)->cmp((A2),NULL))
#endif

#ifndef ERR_ERRVSTREAM_CMP
#define ERR_ERRVSTREAM_CMP(A1,A2) ((A1).cmp((A2),NULL))
#endif

#ifndef ERR_ERRVSTREAM_ZERO
#define ERR_ERRVSTREAM_ZERO (ErrVStream::static_zero())
#endif

#if ERR_ERR_V_STREAM_TP_DEEP_COPY && !defined(ERR_ERR_V_STREAM_TP_ICOPY)
#define ERR_ERR_V_STREAM_TP_ICOPY(A1,A2) err_v_stream_copy_err((A1),(A2))
#endif

#if ERR_ERR_V_STREAM_T_CONSTP_DEEP_COPY && !defined(ERR_ERR_V_STREAM_T_CONSTP_ICOPY)
#define ERR_ERR_V_STREAM_T_CONSTP_ICOPY(A1,A2) err_v_stream_copy_err((A1),(A2))
#endif

#if ERR_CONST_ERR_V_STREAM_TP_DEEP_COPY && !defined(ERR_CONST_ERR_V_STREAM_TP_ICOPY)
#define ERR_CONST_ERR_V_STREAM_TP_ICOPY(A1,A2) err_v_stream_copy_err((A1),(A2))
#endif

#if ERR_ERRVSTREAMP_DEEP_COPY && !defined(ERR_ERRVSTREAMP_ICOPY)
#define ERR_ERRVSTREAMP_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERRVSTREAM_CONSTP_DEEP_COPY && !defined(ERR_ERRVSTREAM_CONSTP_ICOPY)
#define ERR_ERRVSTREAM_CONSTP_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_CONST_ERRVSTREAMP_DEEP_COPY && !defined(ERR_CONST_ERRVSTREAMP_ICOPY)
#define ERR_CONST_ERRVSTREAMP_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERR_V_STREAM_T_P_DEEP_COPY && !defined(ERR_ERR_V_STREAM_T_P_ICOPY)
#define ERR_ERR_V_STREAM_T_P_ICOPY(A1,A2) err_v_stream_copy_err((A1),(A2))
#endif

#if ERR_ERR_V_STREAM_T_CONST_P_DEEP_COPY && !defined(ERR_ERR_V_STREAM_T_CONST_P_ICOPY)
#define ERR_ERR_V_STREAM_T_CONST_P_ICOPY(A1,A2) err_v_stream_copy_err((A1),(A2))
#endif

#if ERR_CONST_ERR_V_STREAM_T_P_DEEP_COPY && !defined(ERR_CONST_ERR_V_STREAM_T_P_ICOPY)
#define ERR_CONST_ERR_V_STREAM_T_P_ICOPY(A1,A2) err_v_stream_copy_err((A1),(A2))
#endif

#if ERR_ERRVSTREAM_P_DEEP_COPY && !defined(ERR_ERRVSTREAM_P_ICOPY)
#define ERR_ERRVSTREAM_P_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERRVSTREAM_CONST_P_DEEP_COPY && !defined(ERR_ERRVSTREAM_CONST_P_ICOPY)
#define ERR_ERRVSTREAM_CONST_P_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_CONST_ERRVSTREAM_P_DEEP_COPY && !defined(ERR_CONST_ERRVSTREAM_P_ICOPY)
#define ERR_CONST_ERRVSTREAM_P_ICOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERR_V_STREAM_TP_DEEP_COPY && !defined(ERR_ERR_V_STREAM_TP_OCOPY)
#define ERR_ERR_V_STREAM_TP_OCOPY(A1,A2) err_v_stream_copy_err((A1),(A2))
#endif

#if ERR_ERR_V_STREAM_T_CONSTP_DEEP_COPY && !defined(ERR_ERR_V_STREAM_T_CONSTP_OCOPY)
#define ERR_ERR_V_STREAM_T_CONSTP_OCOPY(A1,A2) err_v_stream_copy_err((A1),(A2))
#endif

#if ERR_CONST_ERR_V_STREAM_TP_DEEP_COPY && !defined(ERR_CONST_ERR_V_STREAM_TP_OCOPY)
#define ERR_CONST_ERR_V_STREAM_TP_OCOPY(A1,A2) err_v_stream_copy_err((A1),(A2))
#endif

#if ERR_ERRVSTREAMP_DEEP_COPY && !defined(ERR_ERRVSTREAMP_OCOPY)
#define ERR_ERRVSTREAMP_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERRVSTREAM_CONSTP_DEEP_COPY && !defined(ERR_ERRVSTREAM_CONSTP_OCOPY)
#define ERR_ERRVSTREAM_CONSTP_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_CONST_ERRVSTREAMP_DEEP_COPY && !defined(ERR_CONST_ERRVSTREAMP_OCOPY)
#define ERR_CONST_ERRVSTREAMP_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERR_V_STREAM_T_P_DEEP_COPY && !defined(ERR_ERR_V_STREAM_T_P_OCOPY)
#define ERR_ERR_V_STREAM_T_P_OCOPY(A1,A2) err_v_stream_copy_err((A1),(A2))
#endif

#if ERR_ERR_V_STREAM_T_CONST_P_DEEP_COPY && !defined(ERR_ERR_V_STREAM_T_CONST_P_OCOPY)
#define ERR_ERR_V_STREAM_T_CONST_P_OCOPY(A1,A2) err_v_stream_copy_err((A1),(A2))
#endif

#if ERR_CONST_ERR_V_STREAM_T_P_DEEP_COPY && !defined(ERR_CONST_ERR_V_STREAM_T_P_OCOPY)
#define ERR_CONST_ERR_V_STREAM_T_P_OCOPY(A1,A2) err_v_stream_copy_err((A1),(A2))
#endif

#if ERR_ERRVSTREAM_P_DEEP_COPY && !defined(ERR_ERRVSTREAM_P_OCOPY)
#define ERR_ERRVSTREAM_P_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERRVSTREAM_CONST_P_DEEP_COPY && !defined(ERR_ERRVSTREAM_CONST_P_OCOPY)
#define ERR_ERRVSTREAM_CONST_P_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_CONST_ERRVSTREAM_P_DEEP_COPY && !defined(ERR_CONST_ERRVSTREAM_P_OCOPY)
#define ERR_CONST_ERRVSTREAM_P_OCOPY(A1,A2) ((A1)->copy_err((A2)))
#endif

#if ERR_ERR_V_STREAM_TP_DEEP_COPY && !defined(ERR_ERR_V_STREAM_TP_IFREE)
#define ERR_ERR_V_STREAM_TP_IFREE(A1) err_v_stream_delete((A1))
#endif

#if ERR_ERR_V_STREAM_T_CONSTP_DEEP_COPY && !defined(ERR_ERR_V_STREAM_T_CONSTP_IFREE)
#define ERR_ERR_V_STREAM_T_CONSTP_IFREE(A1) err_v_stream_delete((A1))
#endif

#if ERR_CONST_ERR_V_STREAM_TP_DEEP_COPY && !defined(ERR_CONST_ERR_V_STREAM_TP_IFREE)
#define ERR_CONST_ERR_V_STREAM_TP_IFREE(A1) err_v_stream_delete((A1))
#endif

#if ERR_ERRVSTREAMP_DEEP_COPY && !defined(ERR_ERRVSTREAMP_IFREE)
#define ERR_ERRVSTREAMP_IFREE(A1) delete((A1))
#endif

#if ERR_ERRVSTREAM_CONSTP_DEEP_COPY && !defined(ERR_ERRVSTREAM_CONSTP_IFREE)
#define ERR_ERRVSTREAM_CONSTP_IFREE(A1) delete((A1))
#endif

#if ERR_CONST_ERRVSTREAMP_DEEP_COPY && !defined(ERR_CONST_ERRVSTREAMP_IFREE)
#define ERR_CONST_ERRVSTREAMP_IFREE(A1) delete((A1))
#endif

#if ERR_ERR_V_STREAM_T_P_DEEP_COPY && !defined(ERR_ERR_V_STREAM_T_P_IFREE)
#define ERR_ERR_V_STREAM_T_P_IFREE(A1) err_v_stream_delete((A1))
#endif

#if ERR_ERR_V_STREAM_T_CONST_P_DEEP_COPY && !defined(ERR_ERR_V_STREAM_T_CONST_P_IFREE)
#define ERR_ERR_V_STREAM_T_CONST_P_IFREE(A1) err_v_stream_delete((A1))
#endif

#if ERR_CONST_ERR_V_STREAM_T_P_DEEP_COPY && !defined(ERR_CONST_ERR_V_STREAM_T_P_IFREE)
#define ERR_CONST_ERR_V_STREAM_T_P_IFREE(A1) err_v_stream_delete((A1))
#endif

#if ERR_ERRVSTREAM_P_DEEP_COPY && !defined(ERR_ERRVSTREAM_P_IFREE)
#define ERR_ERRVSTREAM_P_IFREE(A1) delete((A1))
#endif

#if ERR_ERRVSTREAM_CONST_P_DEEP_COPY && !defined(ERR_ERRVSTREAM_CONST_P_IFREE)
#define ERR_ERRVSTREAM_CONST_P_IFREE(A1) delete((A1))
#endif

#if ERR_CONST_ERRVSTREAM_P_DEEP_COPY && !defined(ERR_CONST_ERRVSTREAM_P_IFREE)
#define ERR_CONST_ERRVSTREAM_P_IFREE(A1) delete((A1))
#endif

#if ERR_ERR_V_STREAM_TP_DEEP_COPY && !defined(ERR_ERR_V_STREAM_TP_OFREE)
#define ERR_ERR_V_STREAM_TP_OFREE(A1) err_v_stream_delete((A1))
#endif

#if ERR_ERR_V_STREAM_T_CONSTP_DEEP_COPY && !defined(ERR_ERR_V_STREAM_T_CONSTP_OFREE)
#define ERR_ERR_V_STREAM_T_CONSTP_OFREE(A1) err_v_stream_delete((A1))
#endif

#if ERR_CONST_ERR_V_STREAM_TP_DEEP_COPY && !defined(ERR_CONST_ERR_V_STREAM_TP_OFREE)
#define ERR_CONST_ERR_V_STREAM_TP_OFREE(A1) err_v_stream_delete((A1))
#endif

#if ERR_ERRVSTREAMP_DEEP_COPY && !defined(ERR_ERRVSTREAMP_OFREE)
#define ERR_ERRVSTREAMP_OFREE(A1) delete((A1))
#endif

#if ERR_ERRVSTREAM_CONSTP_DEEP_COPY && !defined(ERR_ERRVSTREAM_CONSTP_OFREE)
#define ERR_ERRVSTREAM_CONSTP_OFREE(A1) delete((A1))
#endif

#if ERR_CONST_ERRVSTREAMP_DEEP_COPY && !defined(ERR_CONST_ERRVSTREAMP_OFREE)
#define ERR_CONST_ERRVSTREAMP_OFREE(A1) delete((A1))
#endif

#if ERR_ERR_V_STREAM_T_P_DEEP_COPY && !defined(ERR_ERR_V_STREAM_T_P_OFREE)
#define ERR_ERR_V_STREAM_T_P_OFREE(A1) err_v_stream_delete((A1))
#endif

#if ERR_ERR_V_STREAM_T_CONST_P_DEEP_COPY && !defined(ERR_ERR_V_STREAM_T_CONST_P_OFREE)
#define ERR_ERR_V_STREAM_T_CONST_P_OFREE(A1) err_v_stream_delete((A1))
#endif

#if ERR_CONST_ERR_V_STREAM_T_P_DEEP_COPY && !defined(ERR_CONST_ERR_V_STREAM_T_P_OFREE)
#define ERR_CONST_ERR_V_STREAM_T_P_OFREE(A1) err_v_stream_delete((A1))
#endif

#if ERR_ERRVSTREAM_P_DEEP_COPY && !defined(ERR_ERRVSTREAM_P_OFREE)
#define ERR_ERRVSTREAM_P_OFREE(A1) delete((A1))
#endif

#if ERR_ERRVSTREAM_CONST_P_DEEP_COPY && !defined(ERR_ERRVSTREAM_CONST_P_OFREE)
#define ERR_ERRVSTREAM_CONST_P_OFREE(A1) delete((A1))
#endif

#if ERR_CONST_ERRVSTREAM_P_DEEP_COPY && !defined(ERR_CONST_ERRVSTREAM_P_OFREE)
#define ERR_CONST_ERRVSTREAM_P_OFREE(A1) delete((A1))
#endif

#ifndef ERR_ERRVSTREAM_CONSTRUCTOR
#define ERR_ERRVSTREAM_CONSTRUCTOR(A1) ((A1)._constructor())
#endif

#ifndef ERR_ERRVSTREAM_DESTRUCTOR
#define ERR_ERRVSTREAM_DESTRUCTOR(A1) ((A1)._destructor())
#endif


#endif /* defined ERWIN_ERR_V_STREAM_f_h */

