/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2021 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: pol2d.hpp
 * https://nappgui.com/en/geom2d/pol2d.html
 *
 */

/* 2d convex polygon */

#ifndef __POL2D_HPP__
#define __POL2D_HPP__

#include "v2d.hpp"
#include "t2d.hpp"

template<typename real>
struct Pol2D
{
    static Pol2D<real>* (*create)(const V2D<real> *points, const uint32_t n);

    static Pol2D<real>* (*copy)(const Pol2D<real> *pol);

    static void (*destroy)(Pol2D<real> **pol);

    static void (*transform)(Pol2D<real> *pol, const T2D<real> *t2d);

    static const V2D<real>* (*points)(const Pol2D<real> *pol);

    static uint32_t (*n)(const Pol2D<real> *pol);

    static real (*area)(const Pol2D<real> *pol);

    static bool_t (*ccw)(const Pol2D<real> *pol);

    static bool_t (*convex)(const Pol2D<real> *pol);
};

#endif

