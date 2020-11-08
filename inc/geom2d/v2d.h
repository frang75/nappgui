/*
 * NAppGUI Cross-platform C SDK
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

V2Df v2d_addf(const V2Df *v1, const V2Df *v2);

V2Dd v2d_addd(const V2Dd *v1, const V2Dd *v2);

V2Df v2d_subf(const V2Df *v1, const V2Df *v2);

V2Dd v2d_subd(const V2Dd *v1, const V2Dd *v2);

V2Df v2d_mulf(const V2Df *v, const real32_t s);

V2Dd v2d_muld(const V2Dd *v, const real64_t s);

V2Df v2d_unitf(const V2Df *v1, const V2Df *v2, real32_t *dist);

V2Dd v2d_unitd(const V2Dd *v1, const V2Dd *v2, real64_t *dist);

V2Df v2d_perp_posf(const V2Df *v);

V2Dd v2d_perp_posd(const V2Dd *v);

V2Df v2d_perp_negf(const V2Df *v);

V2Dd v2d_perp_negd(const V2Dd *v);

bool_t v2d_normf(V2Df *v);

bool_t v2d_normd(V2Dd *v);

real32_t v2d_lengthf(const V2Df *v);

real64_t v2d_lengthd(const V2Dd *v);

real32_t v2d_sqlengthf(const V2Df *v);

real64_t v2d_sqlengthd(const V2Dd *v);

real32_t v2d_dotf(const V2Df *v1, const V2Df *v2);

real64_t v2d_dotd(const V2Dd *v1, const V2Dd *v2);

real32_t v2d_distf(const V2Df *v1, const V2Df *v2);

real64_t v2d_distd(const V2Dd *v1, const V2Dd *v2);

real32_t v2d_sqdistf(const V2Df *v1, const V2Df *v2);

real64_t v2d_sqdistd(const V2Dd *v1, const V2Dd *v2);

real32_t v2d_anglef(const V2Df *v1, const V2Df *v2);

real64_t v2d_angled(const V2Dd *v1, const V2Dd *v2);

void v2d_rotatef(V2Df *v, const real32_t a);

void v2d_rotated(V2Dd *v, const real64_t a);

extern const V2Df kV2D_ZEROf;
extern const V2Dd kV2D_ZEROd;

extern const V2Df kV2D_Xf;
extern const V2Dd kV2D_Xd;

extern const V2Df kV2D_Yf;
extern const V2Dd kV2D_Yd;

__END_C
