/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: listbox.h
 * https://nappgui.com/en/gui/listbox.html
 *
 */

/* Listbox */

#include "gui.hxx"

__EXTERN_C

ListBox *listbox_create(void);

void listbox_OnSelect(ListBox *box, Listener *listener);

void listbox_size(ListBox *box, S2Df size);

void listbox_clear(ListBox *box);

void listbox_add_elem(ListBox *box, const char_t *text, const Image *image);

void listbox_set_elem(ListBox *box, const uint32_t index, const char_t *text, const Image *image);

void listbox_color(ListBox *box, const uint32_t index, const color_t color);

void listbox_selected(ListBox *box, const uint32_t index);

uint32_t listbox_count(const ListBox *box);

const char_t *listbox_text(const ListBox *box, const uint32_t index);

uint32_t listbox_get_selected(const ListBox *box);

__END_C

