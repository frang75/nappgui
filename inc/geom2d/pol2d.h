/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2021 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: pol2d.h
 * https://nappgui.com/en/geom2d/pol2d.html
 *
 */

/* 2d convex polygon */

#include "geom2d.hxx"

__EXTERN_C

Pol2Df* pol2d_createf(const V2Df *points, const uint32_t n);

Pol2Dd* pol2d_created(const V2Dd *points, const uint32_t n);

Pol2Df* pol2d_copyf(const Pol2Df *pol);

Pol2Dd* pol2d_copyd(const Pol2Dd *pol);

void pol2d_destroyf(Pol2Df **pol);

void pol2d_destroyd(Pol2Dd **pol);

void pol2d_transformf(Pol2Df *pol, const T2Df *t2d);

void pol2d_transformd(Pol2Dd *pol, const T2Dd *t2d);

const V2Df *pol2d_pointsf(const Pol2Df *pol);

const V2Dd *pol2d_pointsd(const Pol2Dd *pol);

uint32_t pol2d_nf(const Pol2Df *pol);

uint32_t pol2d_nd(const Pol2Dd *pol);

real32_t pol2d_areaf(const Pol2Df *pol);

real64_t pol2d_aread(const Pol2Dd *pol);

bool_t pol2d_ccwf(const Pol2Df *pol);

bool_t pol2d_ccwd(const Pol2Dd *pol);

bool_t pol2d_convexf(const Pol2Df *pol);

bool_t pol2d_convexd(const Pol2Dd *pol);

__END_C
