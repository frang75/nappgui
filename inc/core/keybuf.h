/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: keybuf.h
 * https://nappgui.com/en/core/keybuf.html
 *
 */

/* Keyboard buffer */

#include "core.hxx"

__EXTERN_C

KeyBuf *keybuf_create(void);

void keybuf_destroy(KeyBuf **buffer);

void keybuf_OnUp(KeyBuf *buffer, const vkey_t key);

void keybuf_OnDown(KeyBuf *buffer, const vkey_t key);

void keybuf_clear(KeyBuf *buffer);

bool_t keybuf_pressed(const KeyBuf *buffer, const vkey_t key);

const char_t* keybuf_str(const vkey_t key);

void keybuf_dump(const KeyBuf *buffer);

__END_C
