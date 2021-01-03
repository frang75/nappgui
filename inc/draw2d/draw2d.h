/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2021 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: draw2d.h
 * https://nappgui.com/en/draw2d/draw2d.html
 *
 */

/* Operating system 2D drawing support */

#include "draw2d.hxx"

__EXTERN_C

void draw2d_start(void);

void draw2d_finish(void);

const Image *image_from_resource(const ResPack *pack, const ResId id);

#define resid_image(resid) (const Image*)(resid)

__END_C
