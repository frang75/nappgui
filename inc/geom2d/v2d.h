/*
 * NAppGUI-v1.1.2.2443 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: v2d.h
 * https://nappgui.com/en/geom2d/v2d.html
 *
 */

/* Vector 2d */

#include "geom2d.hxx"

__EXTERN_C

V2Df v2df(const real32_t x, const real32_t y);

V2Dd v2dd(const real64_t x, const real64_t y);

bool_t v2d_normf(V2Df *v2d);

bool_t v2d_normd(V2Dd *v2d);

real32_t v2d_lengthf(const V2Df *v2d);

real64_t v2d_lengthd(const V2Dd *v2d);

real32_t v2d_distf(const V2Df *v2d1, const V2Df *v2d2);

real64_t v2d_distd(const V2Dd *v2d1, const V2Dd *v2d2);

extern const V2Df kV2D_ZEROf;
extern const V2Dd kV2D_ZEROd;

__END_C
