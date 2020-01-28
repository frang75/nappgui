/*
 * NAppGUI-v1.1.1.2372 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: buffer.h
 * https://nappgui.com/en/core/buffer.html
 *
 */

/* Fixed size memory buffers */

#include "core.hxx"

__EXTERN_C

Buffer *buffer_create(const uint32_t size);

void buffer_destroy(Buffer **buffer);

uint32_t buffer_size(const Buffer *buffer);

byte_t *buffer_data(Buffer *buffer);

__END_C

