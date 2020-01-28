/*
 * NAppGUI-v1.1.1.2374 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: geom2d.hxx
 * https://nappgui.com/en/geom2d/geom2d.html
 *
 */

/* 2d geometry */

#ifndef __GEOM2D_HXX__
#define __GEOM2D_HXX__

#include "core.hxx"

typedef struct _v2df_t V2Df;
typedef struct _v2dd_t V2Dd;
typedef struct _s2df_t S2Df;
typedef struct _s2dd_t S2Dd;
typedef struct _r2df_t R2Df;
typedef struct _r2dd_t R2Dd;
typedef struct _b2df_t B2Df;
typedef struct _b2dd_t B2Dd;
typedef struct _t2df_t T2Df;
typedef struct _t2dd_t T2Dd;
typedef struct _curve2df_t Curve2Df;
typedef struct _curve2dd_t Curve2Dd;
typedef struct _brep2df_t Brep2Df;
typedef struct _brep2dd_t Brep2Dd;

struct _v2df_t
{
    real32_t x;
    real32_t y;
};

struct _v2dd_t
{
    real64_t x;
    real64_t y;
};

struct _s2df_t
{
    real32_t width;
    real32_t height;
};

struct _s2dd_t
{
    real64_t width;
    real64_t height;
};

struct _r2df_t
{

    V2Df pos;
    S2Df size;
};

struct _r2dd_t
{
    V2Dd pos;
    S2Dd size;
};

struct _b2df_t
{
    V2Df min;
    V2Df max;
};

struct _b2dd_t
{
    V2Dd min;
    V2Dd max;
};

struct _t2df_t
{
    V2Df i;
    V2Df j;
    V2Df p;
};

struct _t2dd_t
{
    V2Dd i;
    V2Dd j;
    V2Dd p;
};

#endif

