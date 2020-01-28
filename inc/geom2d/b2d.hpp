/*
 * NAppGUI-v1.1.1.2374 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: b2d.hpp
 * https://nappgui.com/en/geom2d/b2d.html
 *
 */

/* Box 2d */

#include "v2d.hpp"

template<typename real>
struct B2D
{
    static bool_t (*null)(const B2D<real> *box);

    static void (*add)(B2D<real> *box, const V2D<real> *p);

    static void (*addn)(B2D<real> *box, const V2D<real> *p, const uint32_t n);

    static void (*merge)(B2D<real> *dest, const B2D<real> *src);

    static bool_t (*overlap)(const B2D<real> *box1, const B2D<real> *box2);

    static const B2D<real> *kUNIT;
    static const B2D<real> *kNULL;

    V2D<real> min;
    V2D<real> max;
};

template<typename real, typename real2>
struct B2D2
{
    static void (*copy)(B2D<real> *dest, const B2D<real2> *src);
};
