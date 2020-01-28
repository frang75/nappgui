/*
 * NAppGUI-v1.1.1.2374 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: clock.h
 * https://nappgui.com/en/core/clock.html
 *
 */

/* Clock (Frame counter) */

#include "core.hxx"

__EXTERN_C

Clock *clock_create(const real64_t interval);

void clock_destroy(Clock **clk);

bool_t clock_frame(Clock *clk, real64_t *prev_frame, real64_t *curr_frame);

void clock_reset(Clock *clk);

real64_t clock_elapsed(const Clock *clk);

__END_C
