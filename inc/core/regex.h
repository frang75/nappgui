/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2021 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: regex.h
 * https://nappgui.com/en/core/regex.html
 *
 */

/* Regular expresions */

#include "core.hxx"

__EXTERN_C

RegEx *regex_create(const char_t *pattern);

void regex_destroy(RegEx **regex);

bool_t regex_match(const RegEx *regex, const char_t *str);

__END_C
