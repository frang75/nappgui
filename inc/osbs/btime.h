/*
 * NAppGUI-v1.1.1.2372 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: btime.h
 * https://nappgui.com/en/osbs/btime.html
 *
 */

/* Basic time services */

#include "osbs.hxx"

__EXTERN_C

uint64_t btime_now(void);

void btime_date(Date *date);

uint16_t btime_year(void);

__END_C
