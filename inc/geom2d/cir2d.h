/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: cir2d.h
 * https://nappgui.com/en/geom2d/cir2d.html
 *
 */

/* Circle 2d */

#include "geom2d.hxx"

__EXTERN_C

Cir2Df cir2df(const real32_t x, const real32_t y, const real32_t r);

Cir2Dd cir2dd(const real64_t x, const real64_t y, const real64_t r);

bool_t cir2d_nullf(const Cir2Df *cir);

bool_t cir2d_nulld(const Cir2Dd *cir);

void cir2d_addf(Cir2Df *cir, const V2Df *p);

void cir2d_addd(Cir2Dd *cir, const V2Dd *p);

void cir2d_addnf(Cir2Df *cir, const V2Df *p, const uint32_t n);

void cir2d_addnd(Cir2Dd *cir, const V2Dd *p, const uint32_t n);

void cir2d_add_boxf(Cir2Df *cir, const Box2Df *box);

void cir2d_add_boxd(Cir2Dd *cir, const Box2Dd *box);

void cir2d_mergef(Cir2Df *dest, const Cir2Df *src);

void cir2d_merged(Cir2Dd *dest, const Cir2Dd *src);

extern const Cir2Df kCIR2D_NULLf;
extern const Cir2Dd kCIR2D_NULLd;

__END_C

