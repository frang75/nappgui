/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: seg2d.hpp
 * https://nappgui.com/en/geom2d/seg2d.html
 *
 */

/* 2d segments */

#include "v2d.hpp"

template<typename real>
struct Seg2D
{
    Seg2D() {p0.x = 0, p0.y = 0, p1.x = 0, p1.y = 0;}

    Seg2D(const real x0, const real y0, const real x1, const real y1) {p0.x = x0, p0.y = y0, p1.x = x1, p1.y = y1;}

    V2D<real> p0;
    V2D<real> p1;
};

