/*
 * NAppGUI-v1.1.1.2374 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: bmutex.h
 * https://nappgui.com/en/osbs/bmutex.html
 *
 */

/* Basic synchronization services */

#include "osbs.hxx"

__EXTERN_C

Mutex *bmutex_create(void);

void bmutex_close(Mutex **mutex);

void bmutex_lock(Mutex *mutex);

void bmutex_unlock(Mutex *mutex);

__END_C

