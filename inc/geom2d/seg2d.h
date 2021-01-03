/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2021 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: seg2d.h
 * https://nappgui.com/en/geom2d/seg2d.html
 *
 */

/* 2d segments */

#include "geom2d.hxx"

__EXTERN_C

Seg2Df seg2df(const real32_t x0, const real32_t y0, const real32_t x1, const real32_t y1);

Seg2Dd seg2dd(const real64_t x0, const real64_t y0, const real64_t x1, const real64_t y1);

V2Df seg2d_evalf(const Seg2Df *seg, const real32_t t);

V2Dd seg2d_evald(const Seg2Dd *seg, const real64_t t);

real32_t seg2d_close_paramf(const Seg2Df *seg, const V2Df *pnt);

real64_t seg2d_close_paramd(const Seg2Dd *seg, const V2Dd *pnt);

real32_t seg2d_point_sqdistf(const Seg2Df *seg, const V2Df *pnt, real32_t *t);

real64_t seg2d_point_sqdistd(const Seg2Dd *seg, const V2Dd *pnt, real64_t *t);

__END_C

