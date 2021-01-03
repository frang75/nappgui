/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2021 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: url.h
 * https://nappgui.com/en/inet/url.html
 *
 */

/* URL parser */

#include "inet.hxx"

__EXTERN_C

Url *url_parse(const char_t *url);

void url_destroy(Url **url);

const char_t *url_protocol(const Url *url);

const char_t *url_host(const Url *url);

const char_t *url_resource(const Url *url);

__END_C
