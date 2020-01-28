/*
 * NAppGUI-v1.1.1.2374 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: imageview.h
 * https://nappgui.com/en/gui/imageview.html
 *
 */

/* Image view */

#include "gui.hxx"

__EXTERN_C

ImageView *imageview_create(void);

void imageview_size(ImageView *view, S2Df size);

void imageview_scale(ImageView *view, const scale_t scale);

void imageview_image(ImageView *view, const Image *image);

void imageview_OnClick(ImageView *view, Listener *listener);

void imageview_OnOverDraw(ImageView *view, Listener *listener);

__END_C
