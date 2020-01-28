/*
 * NAppGUI-v1.1.1.2372 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: r2d.hpp
 * https://nappgui.com/en/geom2d/r2d.html
 *
 */

/* 2D rectangles */

#include "v2d.hpp"
#include "s2d.hpp"

template<typename real>
struct R2D
{
    R2D();

    R2D(const real x, const real y, const real width, const real height);

    static bool_t(*contains)(const R2D *r2d, const real x, const real y);

    static const R2D<real> *kZERO;

    V2D<real> pos;
    S2D<real> size;
};
