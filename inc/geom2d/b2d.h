/*
 * NAppGUI-v1.1.2.2443 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: b2d.h
 * https://nappgui.com/en/geom2d/b2d.html
 *
 */

/* Box 2d */

#include "geom2d.hxx"

__EXTERN_C

bool_t b2d_nullf(const B2Df *box);

bool_t b2d_nulld(const B2Dd *box);

void b2d_addf(B2Df *box, const V2Df *p);

void b2d_addd(B2Dd *box, const V2Dd *p);

void b2d_addnf(B2Df *box, const V2Df *p, const uint32_t n);

void b2d_addnd(B2Dd *box, const V2Dd *p, const uint32_t n);

void b2d_mergef(B2Df *dest, const B2Df *src);

void b2d_merged(B2Dd *dest, const B2Dd *src);

bool_t b2d_overlapf(const B2Df *box1, const B2Df *box2);

bool_t b2d_overlapd(const B2Dd *box1, const B2Dd *box2);

extern const B2Df kB2D_NULLf;
extern const B2Dd kB2D_NULLd;

__END_C

