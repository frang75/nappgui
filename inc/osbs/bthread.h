/*
 * NAppGUI-v1.1.1.2372 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: bthread.h
 * https://nappgui.com/en/osbs/bthread.html
 *
 */

/* Basic threading services */

#include "osbs.hxx"

__EXTERN_C

Thread *bthread_create_imp(FPtr_thread_main thmain, void *data);

Thread *bthread_current(void);

void bthread_close(Thread **thread);

bool_t bthread_cancel(Thread *thread);

uint32_t bthread_wait(Thread *thread);

bool_t bthread_finish(Thread *thread, uint32_t *code);

void bthread_sleep(const uint32_t milliseconds);

__END_C

#define bthread_create(thmain, data, type)\
    (\
        (void)(data == (type*)data),\
        FUNC_CHECK_THREAD_MAIN(thmain, type),\
        bthread_create_imp((FPtr_thread_main)thmain, (void*)data)\
    )
