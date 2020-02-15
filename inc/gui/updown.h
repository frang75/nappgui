/*
 * NAppGUI-v1.1.2.2443 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: updown.h
 * https://nappgui.com/en/gui/updown.html
 *
 */

/* Up Down */

#include "gui.hxx"

__EXTERN_C

UpDown *updown_create(void);

void updown_OnClick(UpDown *updown, Listener *listener);

void updown_tooltip(UpDown *updown, const char_t *text);

__END_C
