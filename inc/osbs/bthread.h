/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2021 Francisco Garcia Collado
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

int bthread_current_id(void);

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
