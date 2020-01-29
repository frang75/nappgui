/*
 * NAppGUI-v1.1.1.2374 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: types.h
 * https://nappgui.com/en/sewer/types.html
 *
 */

/* Basic types utils */ 

#include "sewer.hxx"

__EXTERN_C

uint32_t min_u32(const uint32_t v1, const uint32_t v2);

real32_t min_r32(const real32_t v1, const real32_t v2);

uint32_t max_u32(const uint32_t v1, const uint32_t v2);

real32_t max_r32(const real32_t v1, const real32_t v2);

real32_t abs_r32(const real32_t v);

__END_C
