/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: globals.h
 * https://nappgui.com/en/gui/globals.html
 *
 */

/* System globals */

#include "gui.hxx"

__EXTERN_C

device_t globals_device(void);

void globals_resolution(S2Df *resolution);

void globals_mouse_position(V2Df *mouse_position);

__END_C
