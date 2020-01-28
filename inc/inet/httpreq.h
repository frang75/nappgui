/*
 * NAppGUI-v1.1.1.2374 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: httpreq.h
 * https://nappgui.com/en/inet/httpreq.html
 *
 */

/* HTTP request */

#include "inet.hxx"

__EXTERN_C

Http *http_create(const char_t *host, const uint16_t port, ierror_t *error);

void http_destroy(Http **http);

void http_param(Http *http, const char_t *name, const char_t *value);

void http_header(Http *http, const char_t *name, const char_t *value);

void http_clear_params(Http *http);

void http_clear_headers(Http *http);

bool_t http_get(Http *http, const char_t *uri, Stream *body, ierror_t *error);

Stream *http_dget(const char_t *host, const uint16_t port, const char_t *uri, ierror_t *error);

__END_C

