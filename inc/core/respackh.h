/*
 * NAppGUI-v1.1.1.2374 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: respackh.h
 * https://nappgui.com/en/core/respackh.html
 *
 */

/* Resource Packages */

#include "core.hxx"

__EXTERN_C

ResPack *respack_embedded(const char_t *name);

ResPack *respack_packed(const char_t *name, const char_t *locale);

void respack_add_msg(ResPack *pack, const char_t *msg);

void respack_add_cdata(ResPack *pack, const uint32_t type, const byte_t *data, const uint32_t data_size);

__END_C

    