/*
 * NAppGUI-v1.1.2.2443 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: s2d.h
 * https://nappgui.com/en/geom2d/s2d.html
 *
 */

/* Size 2d */

#include "geom2d.hxx"

__EXTERN_C

S2Df s2df(const real32_t width, const real32_t height);

S2Df s2di(const uint32_t width, const uint32_t height);

S2Dd s2dd(const real64_t width, const real64_t height);

extern const S2Df kS2D_ZEROf;
extern const S2Dd kS2D_ZEROd;

__END_C
