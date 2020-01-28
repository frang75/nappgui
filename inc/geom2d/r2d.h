/*
 * NAppGUI-v1.1.1.2372 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: r2d.h
 * https://nappgui.com/en/geom2d/r2d.html
 *
 */

/* 2D rectangles */

#include "geom2d.hxx"

__EXTERN_C

R2Df r2df(const real32_t x, const real32_t y, const real32_t width, const real32_t height);

R2Dd r2dd(const real64_t x, const real64_t y, const real64_t width, const real64_t height);

bool_t r2d_containsf(const R2Df *r2d, const real32_t x, const real32_t y);

bool_t r2d_containsd(const R2Dd *r2d, const real64_t x, const real64_t y);

extern const R2Df kR2D_ZEROf;
extern const R2Dd kR2D_ZEROd;

__END_C
