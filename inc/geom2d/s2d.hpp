/*
 * NAppGUI-v1.1.1.2372 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: s2d.hpp
 * https://nappgui.com/en/geom2d/s2d.html
 *
 */

/* Size 2d */

template<typename real>
struct S2D
{
    S2D();

    S2D(const real width, const real height);

    static const S2D<real> *kZERO;

    real width;
    real height;
};
