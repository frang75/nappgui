/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: types.hxx
 * https://nappgui.com/en/sewer/types.html
 *
 */

/* Types */

#ifndef __BASETYPES_HXX__
#define __BASETYPES_HXX__

#include "nowarn.hxx"
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include "warn.hxx"

typedef char                char_t;
typedef unsigned char       byte_t;
typedef unsigned char       bool_t;
typedef float               real32_t;
typedef double              real64_t;

#define REAL32_MAX          1e20f
#define REAL64_MAX          1e38
#define REAL32_MIN          1e-20f
#define REAL64_MIN          1e-38
#define ENUM_MAX(type)      (type)INT32_MAX

#undef FALSE
#undef TRUE
#define	FALSE               (bool_t)0
#define	TRUE                (bool_t)1

typedef enum _enum_t
{
    ekENUM_GENERIC_VALUE
} enum_t;

#ifdef  __cplusplus
#define __EXTERN_C  extern "C" {
#define __END_C     }
#else
#define __EXTERN_C
#define __END_C
#endif

#endif



