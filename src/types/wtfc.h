/**
 * @file wtfc.h
 * @author ezeire (ognieff@yandex.ru)
 * @brief Wrapping types for C
 * @version 1.0
 * @date 2023-10-14
 * 
 */

#pragma once

#include <stddef.h>
#include <inttypes.h>
#include <limits.h>
#include <stdbool.h>
#include <uchar.h>

/* 
  new type aliases
*/

/*
  immutable types
*/

/* uint */
typedef uint8_t const u8;
typedef uint16_t const u16;
typedef uint32_t const u32;
typedef uint64_t const u64;

/* int */
typedef int8_t const i8;
typedef int16_t const i16;
typedef int32_t const i32;
typedef int64_t const i64;

/* floating numbers */
typedef float const f32;
typedef double const f64;
typedef long double const f128;

/* uint_fast */
typedef uint_fast8_t const uf8;
typedef uint_fast16_t const uf16;
typedef uint_fast32_t const uf32;
typedef uint_fast64_t const uf64;

/* int_fast */
typedef int_fast8_t const if8;
typedef int_fast16_t const if16;
typedef int_fast32_t const if32;
typedef int_fast64_t const if64;

/* uint_least */
typedef uint_least8_t const ul8;
typedef uint_least16_t const ul16;
typedef uint_least32_t const ul32;
typedef uint_least64_t const ul64;

/* unsigned integer type */
typedef size_t const usize;

/* ptr */
typedef uintptr_t const uptr;
typedef intptr_t const iptr;
typedef ptrdiff_t const dptr;

/* intmax */
typedef uintmax_t const umax;
typedef intmax_t const imax;

/* wchar */
typedef char16_t const ch16;
typedef char32_t const ch32;

typedef char const* str;
typedef ch16* str16;
typedef ch32* str32;

/*
  mutable types
*/

/* uint */
typedef uint8_t mut_u8;
typedef uint16_t mut_u16;
typedef uint32_t mut_u32;
typedef uint64_t mut_u64;

/* int */
typedef int8_t mut_i8;
typedef int16_t mut_i16;
typedef int32_t mut_i32;
typedef int64_t mut_i64;

/* floating numbers */
typedef float mut_f32;
typedef double mut_f64;
typedef long double mut_f128;

/* uint_fast */
typedef uint_fast8_t mut_uf8;
typedef uint_fast16_t mut_uf16;
typedef uint_fast32_t mut_uf32;
typedef uint_fast64_t mut_uf64;

/* int_fast */
typedef int_fast8_t mut_if8;
typedef int_fast16_t mut_if16;
typedef int_fast32_t mut_if32;
typedef int_fast64_t mut_if64;

/* uint_least */
typedef uint_least8_t mut_ul8;
typedef uint_least16_t mut_ul16;
typedef uint_least32_t mut_ul32;
typedef uint_least64_t mut_ul64;

/* unsigned integer type */
typedef size_t mut_usize;

/* ptr */
typedef uintptr_t mut_uptr;
typedef intptr_t mut_iptr;
typedef ptrdiff_t mut_dptr;

/* intmax */
typedef uintmax_t mut_umax;
typedef intmax_t mut_imax;

/* wchar */
typedef char16_t mut_ch16;
typedef char32_t mut_ch32;

typedef char* mut_str;
typedef mut_ch16* mut_str16;
typedef mut_ch32* mut_str32;

/* 
  new maximum limits
*/

#define U8_MAX UINT8_MAX
#define U16_MAX UINT16_MAX
#define U32_MAX UINT32_MAX
#define U64_MAX UINT64_MAX

#define I8_MAX INT8_MAX
#define I16_MAX INT16_MAX
#define I32_MAX INT32_MAX
#define I64_MAX INT64_MAX

#define F32_MAX __FLT_MAX__
#define F64_MAX __DBL_MAX__
#define F128_MAX __LDBL_MAX__

#define UF8_MAX UINT_FAST8_MAX
#define UF16_MAX UINT_FAST16_MAX
#define UF32_MAX UINT_FAST32_MAX
#define UF64_MAX UINT_FAST64_MAX

#define IF8_MAX INT_FAST8_MAX
#define IF16_MAX INT_FAST16_MAX
#define IF32_MAX INT_FAST32_MAX
#define IF64_MAX INT_FAST64_MAX

#define UPTR_MAX UINTPTR_MAX
#define IPTR_MAX INTPTR_MAX

#define USIZE_MAX SIZE_MAX
#define DPTR_MAX PTRDIFF_MAX

/* 
  new minimum limits
*/

#define U8_MIN UINT8_MIN
#define U16_MIN UINT16_MIN
#define U32_MIN UINT32_MIN
#define U64_MIN UINT64_MIN

#define I8_MIN INT8_MIN
#define I16_MIN INT16_MIN
#define I32_MIN INT32_MIN
#define I64_MIN INT64_MIN

#define F32_MIN __FLT_MIN__
#define F64_MIN __DBL_MIN__
#define F128_MIN __LDBL_MIN__

#define UF8_MIN UINT_FAST8_MIN
#define UF16_MIN UINT_FAST16_MIN
#define UF32_MIN UINT_FAST32_MIN
#define UF64_MIN UINT_FAST64_MIN

#define IF8_MIN INT_FAST8_MIN
#define IF16_MIN INT_FAST16_MIN
#define IF32_MIN INT_FAST32_MIN
#define IF64_MIN INT_FAST64_MIN

#define UPTR_MIN UINTPTR_MIN
#define IPTR_MIN INTPTR_MIN

#define USIZE_MIN SIZE_MIN
#define DPTR_MIN PTRDIFF_MIN

/* 
  new width limits 
*/
#define U8_WIDTH UINT8_WIDTH
#define U16_WIDTH UINT16_WIDTH
#define U32_WIDTH UINT32_WIDTH
#define U64_WIDTH UINT64_WIDTH

#define I8_WIDTH INT8_WIDTH
#define I16_WIDTH INT16_WIDTH
#define I32_WIDTH INT32_WIDTH
#define I64_WIDTH INT64_WIDTH

#define F32_WIDTH __FLT_WIDTH__
#define F64_WIDTH __DBL_WIDTH__
#define F128_WIDTH __LDBL_WIDTH__

#define UF8_WIDTH UINT_FAST8_WIDTH
#define UF16_WIDTH UINT_FAST16_WIDTH
#define UF32_WIDTH UINT_FAST32_WIDTH
#define UF64_WIDTH UINT_FAST64_WIDTH

#define IF8_WIDTH INT_FAST8_WIDTH
#define IF16_WIDTH INT_FAST16_WIDTH
#define IF32_WIDTH INT_FAST32_WIDTH
#define IF64_WIDTH INT_FAST64_WIDTH

#define UPTR_WIDTH UINTPTR_WIDTH
#define IPTR_WIDTH INTPTR_WIDTH

#define USIZE_WIDTH SIZE_WIDTH
#define DPTR_WIDTH PTRDIFF_WIDTH

