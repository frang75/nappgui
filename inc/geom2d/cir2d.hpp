/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: cir2d.hpp
 * https://nappgui.com/en/geom2d/cir2d.html
 *
 */

/* Circle 2d */

#ifndef __CIR2D_HPP__
#define __CIR2D_HPP__

#include "box2d.hpp"

template<typename real>
struct Cir2D
{
    Cir2D() {c.x = 0, c.y = 0, r = 0;}

    Cir2D(const real _x, const real _y, const real _r) {c.x = _x, c.y = _y, r = _r;}

    static bool_t (*null)(const Cir2D<real> *cir);

    static void (*add)(Cir2D<real> *cir, const V2D<real> *p);

    static void (*addn)(Cir2D<real> *cir, const V2D<real> *p, const uint32_t n);

    static void (*add_box)(Cir2D<real> *cir, const Box2D<real> *box);

    static void (*merge)(Cir2D<real> *dest, const Cir2D<real> *src);

    static const Cir2D<real> *kNULL;

    V2D<real> c;
    real r;
};

#endif

