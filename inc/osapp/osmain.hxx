/*
 * NAppGUI-v1.1.2.2443 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: osmain.hxx
 * https://nappgui.com/en/osapp/osmain.html
 *
 */

/* Cross-platform main */

#ifndef __OSMAIN_HXX__
#define __OSMAIN_HXX__

#include "osapp.hxx"

typedef void*(*FPtr_app_create)(void);
#define FUNC_CHECK_APP_CREATE(func, type)\
    (void)((type*(*)(void))func == func)

typedef void(*FPtr_app_update)(void *app, const real64_t prtime, const real64_t ctime);
#define FUNC_CHECK_APP_UPDATE(func, type)\
    (void)((void(*)(type*, const real64_t, const real64_t))func == func)

#endif
