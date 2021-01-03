/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2021 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: json.h
 * https://nappgui.com/en/inet/json.html
 *
 */

/* Json parser */

#include "inet.hxx"

__EXTERN_C

void *json_read_imp(Stream *stm, const JsonOpts *opts, const char_t *type);

void json_write_imp(Stream *stm, const void *data, const JsonOpts *opts, const char_t *type);

__END_C

#define json_read(stm, opts, type)\
    (type*)json_read_imp(stm, opts, (const char_t*)#type)

#define json_write(stm, data, opts, type)\
    ((void)((const type*)data == data),\
    json_write_imp(stm, (const void*)data, opts, (const char_t*)#type))

#define json_destroy(data, type)\
    dbind_destroy(data, type)

#define json_destopt(data, type)\
    dbind_destopt(data, type)
