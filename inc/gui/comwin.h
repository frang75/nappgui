/*
 * NAppGUI-v1.1.1.2372 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: comwin.h
 * https://nappgui.com/en/gui/comwin.html
 *
 */

/* Common windows */

#include "gui.hxx"

__EXTERN_C

const char_t *comwin_open_file(Window *parent, const char_t **ftypes, const uint32_t size, const char_t *start_dir);

const char_t *comwin_save_file(Window *parent, const char_t **ftypes, const uint32_t size, const char_t *start_dir);

__END_C
