/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: obb2d.hpp
 * https://nappgui.com/en/geom2d/obb2d.html
 *
 */

/* Oriented Box 2d */

#ifndef __OBB2D_HPP__
#define __OBB2D_HPP__

#include "box2d.hpp"

template<typename real>
struct OBB2D
{
    static OBB2D<real>* (*create)(const V2D<real> *center, const real width, const real height, const real angle);

    static OBB2D<real>* (*from_line)(const V2D<real> *p0, const V2D<real> *p1, const real thickness);

    static OBB2D<real>* (*copy)(const OBB2D<real> *obb);

    static void (*destroy)(OBB2D<real> **obb);

    static void (*update)(OBB2D<real> *obb, const V2D<real> *center, const real width, const real height, const real angle);

    static void (*move)(OBB2D<real> *obb, const real offset_x, const real offset_y);

    static const V2D<real>* (*corners)(const OBB2D<real> *obb);

    static V2D<real> (*center)(const OBB2D<real> *obb);

    static real (*width)(const OBB2D<real> *obb);

    static real (*height)(const OBB2D<real> *obb);

    static real (*angle)(const OBB2D<real> *obb);

    static Box2D<real> (*box)(const OBB2D<real> *obb);
};

#endif

