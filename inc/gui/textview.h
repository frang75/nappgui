/*
 * NAppGUI-v1.1.1.2372 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: textview.h
 * https://nappgui.com/en/gui/textview.html
 *
 */

/* Text view */

#include "gui.hxx"

__EXTERN_C

TextView *textview_create(void);

void textview_insert(const TextView *view, const char_t *text);

void textview_text(const TextView *view, const char_t *text);

const char_t *textview_get_text(const TextView *view);

__END_C

