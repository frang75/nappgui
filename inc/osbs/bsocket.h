/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: bsocket.h
 * https://nappgui.com/en/osbs/bsocket.html
 *
 */

/* Sockets base API */

#include "osbs.hxx"

__EXTERN_C

Socket *bsocket_connect(const uint32_t ip, const uint16_t port, const SockOpt *opts, serror_t *error);

void bsocket_close(Socket **socket);

void bsocket_ip(Socket *socket, uint32_t *ip, uint16_t *port);

bool_t bsocket_read(Socket *socket, byte_t *data, const uint32_t size, uint32_t *rsize, serror_t *error);

bool_t bsocket_write(Socket *socket, const byte_t *data, const uint32_t size, uint32_t *wsize, serror_t *error);

bool_t bsocket_host_ip(const char_t *url, uint32_t *ip, serror_t *error);

__END_C

#define bsocket_ipv4(a, b, c, d) (uint32_t)(((uint8_t)(a << 24)) | ((uint8_t)(b << 16)) | ((uint8_t)(c << 8)) | ((uint8_t)d))
