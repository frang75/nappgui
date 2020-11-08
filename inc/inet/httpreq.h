/*
 * NAppGUI Cross-platform C SDK
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

Http *http_secure(const char_t *host, const uint16_t port, ierror_t *error);

void http_destroy(Http **http);

void http_add_param(Http *http, const char_t *name, const char_t *value);

void http_add_header(Http *http, const char_t *name, const char_t *value);

void http_clear_params(Http *http);

void http_clear_headers(Http *http);

bool_t http_get(Http *http, const char_t *uri, const byte_t *data, const uint32_t size, ierror_t *error);

bool_t http_post(Http *http, const char_t *uri, const byte_t *data, const uint32_t size, ierror_t *error);

uint32_t http_response_status(Http *http);

const char_t *http_response_protocol(Http *http);

const char_t *http_response_message(Http *http);

uint32_t http_response_size(Http *http);

const char_t *http_response_name(Http *http, const uint32_t index);

const char_t *http_response_value(Http *http, const uint32_t index);

const char_t *http_response_header(Http *http, const char_t *name);

bool_t http_response_body(Http *http, Stream *body, ierror_t *error);

__END_C

