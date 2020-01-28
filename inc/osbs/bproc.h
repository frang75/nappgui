/*
 * NAppGUI-v1.1.1.2374 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: bproc.h
 * https://nappgui.com/en/osbs/bproc.html
 *
 */

/* Processes */

#include "osbs.hxx"

__EXTERN_C

Proc *bproc_exec(const char_t *command, const ProcOpt *opts, perror_t *error);

void bproc_close(Proc **proc);

bool_t bproc_cancel(Proc *proc);

uint32_t bproc_wait(Proc *proc);

bool_t bproc_finish(Proc *proc, uint32_t *code);

bool_t bproc_read(Proc *proc, byte_t *data, const uint32_t size, uint32_t *rsize, perror_t *error);

bool_t bproc_eread(Proc *proc, byte_t *data, const uint32_t size, uint32_t *rsize, perror_t *error);

bool_t bproc_write(Proc *proc, const byte_t *data, const uint32_t size, uint32_t *wsize, perror_t *error);

bool_t bproc_read_close(Proc *proc);

bool_t bproc_eread_close(Proc *proc);

bool_t bproc_write_close(Proc *proc);

void bproc_exit(const uint32_t code);

__END_C


        
