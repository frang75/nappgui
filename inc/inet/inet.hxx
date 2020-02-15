/*
 * NAppGUI-v1.1.2.2443 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: inet.hxx
 * https://nappgui.com/en/inet/inet.html
 *
 */

/* inet library */

#ifndef __INET_HXX__
#define __INET_HXX__

#include "core.hxx"

typedef enum _ierror_t
{
    ekINONET = 1,
    ekINOHOST,
    ekITIMEOUT,
    ekISTREAM,
    ekISERVER,
    ekINOIMPL,
    ekIUNDEF,
    ekIOK
} ierror_t;

typedef struct _http_t Http;
typedef struct _jsonopts_t JsonOpts;

struct _jsonopts_t
{
    uint32_t not_used;
};

#endif
