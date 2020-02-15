/*
 * NAppGUI-v1.1.2.2443 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: osapp.hxx
 * https://nappgui.com/en/osapp/osapp.html
 *
 */

/* Application runloop */

#ifndef __OSAPP_HXX__
#define __OSAPP_HXX__

#include "gui.hxx"

typedef uint32_t(*FPtr_task_main)(void *data);
#define FUNC_CHECK_TASK_MAIN(func, type)\
    (void)((uint32_t(*)(type*))func == func)

typedef void(*FPtr_task_update)(void *data);
#define FUNC_CHECK_TASK_UPDATE(func, type)\
    (void)((void(*)(type*))func == func)

typedef void(*FPtr_task_end)(void *data, const uint32_t rvalue);
#define FUNC_CHECK_TASK_END(func, type)\
    (void)((void(*)(type*, const uint32_t))func == func)

#endif
