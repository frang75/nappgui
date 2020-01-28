/*
 * NAppGUI-v1.1.1.2372 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: date.h
 * https://nappgui.com/en/core/date.html
 *
 */

/* Dates */

#include "core.hxx"

__EXTERN_C

int date_cmp(const Date *date1, const Date *date2);

String *date_DD_MM_YYYY_HH_MM_SS(const Date *date);

String *date_YYYY_MM_DD_HH_MM_SS(const Date *date);

const char_t *date_month_en(const month_t month);

const char_t *date_month_es(const month_t month);

__END_C
