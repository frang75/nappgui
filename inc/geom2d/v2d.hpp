/*
 * NAppGUI-v1.1.1.2374 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: v2d.hpp
 * https://nappgui.com/en/geom2d/v2d.html
 *
 */

/* Vector 2d */

#include "geom2d.hxx"

template<typename real>
struct V2D
{
    V2D();

    V2D(const real x, const real y);

    static bool_t (*norm)(V2D<real> *v2d);

    static real (*length)(const V2D<real> *v2d);

    static real (*dist)(const V2D<real> *v2d1, const V2D<real> *v2d2);

    static const V2D<real> *kZERO;

    real x;
    real y;
};
