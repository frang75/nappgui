/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2021 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: gui.h
 * https://nappgui.com/en/gui/gui.html
 *
 */

/* Graphics User Interface */

#include "gui.hxx"

__EXTERN_C

void gui_start(void);

void gui_finish(void);

void gui_respack(FPtr_respack func_respack);

void gui_language(const char_t *lang);

const char_t *gui_text(const ResId id);

const Image *gui_image(const ResId id);

const byte_t *gui_file(const ResId id, uint32_t *size);

void gui_OnThemeChanged(Listener *listener);

__END_C
