/*
 * NAppGUI-v1.1.1.2372 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: window.h
 * https://nappgui.com/en/gui/window.html
 *
 */

/* Windows */

#include "gui.hxx"

__EXTERN_C

Window *window_create(const uint32_t flags, Panel **main_panel);

void window_destroy(Window **window);

void window_OnClose(Window *window, Listener *listener);

void window_OnMoved(Window *window, Listener *listener);

void window_OnResize(Window *window, Listener *listener);

void window_title(Window *window, const char_t *text);

void window_show(Window *window);

void window_hide(Window *window);

uint32_t window_modal(Window *window, Window *parent);

void window_stop_modal(Window *window, const uint32_t return_value);

void window_update(Window *window);

void window_origin(Window *window, const V2Df origin);

void window_size(Window *window, const S2Df size);

V2Df window_get_origin(const Window *window);

S2Df window_get_size(const Window *window);

S2Df window_get_client_size(const Window *window);

void window_defbutton(Window *window, Button *button);

__END_C
