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

void pol2d_updatef(Pol2Df *pol, const V2Df *points);

void pol2d_updated(Pol2Dd *pol, const V2Dd *points);

const V2Df *pol2d_pointsf(const Pol2Df *pol);

const V2Dd *pol2d_pointsd(const Pol2Dd *pol);

uint32_t pol2d_nf(const Pol2Df *pol);

uint32_t pol2d_nd(const Pol2Dd *pol);

__END_C
