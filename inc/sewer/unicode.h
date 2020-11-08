/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: unicode.h
 * https://nappgui.com/en/sewer/unicode.html
 *
 */

/* Unicode */

#include "sewer.hxx"

__EXTERN_C

uint32_t unicode_convers(const char_t *from_str, char_t *to_str, const unicode_t from, const unicode_t to, const uint32_t osize);

uint32_t unicode_convers_n(const char_t *from_str, char_t *to_str, const unicode_t from, const unicode_t to, const uint32_t isize, const uint32_t osize);

uint32_t unicode_convers_nbytes(const char_t *str, const unicode_t from, const unicode_t to);

uint32_t unicode_nbytes(const char_t *str, const unicode_t format);

uint32_t unicode_nchars(const char_t *str, const unicode_t format);

uint32_t unicode_to_u32(const char_t *str, const unicode_t format);

uint32_t unicode_to_u32b(const char_t *str, const unicode_t format, uint32_t *bytes);

uint32_t unicode_to_char(const uint32_t codepoint, char_t *str, const unicode_t format);

bool_t unicode_valid_str(const char_t *str, const unicode_t format);

bool_t unicode_valid_str_n(const char_t *str, const uint32_t size, const unicode_t format);

bool_t unicode_valid(const uint32_t codepoint);

const char_t *unicode_next(const char_t *str, const unicode_t format);

const char_t *unicode_back(const char_t *str, const unicode_t format);

bool_t unicode_isascii(const uint32_t codepoint);

bool_t unicode_isalnum(const uint32_t codepoint);

bool_t unicode_isalpha(const uint32_t codepoint);

bool_t unicode_iscntrl(const uint32_t codepoint);

bool_t unicode_isdigit(const uint32_t codepoint);

bool_t unicode_isgraph(const uint32_t codepoint);

bool_t unicode_isprint(const uint32_t codepoint);

bool_t unicode_ispunct(const uint32_t codepoint);

bool_t unicode_isspace(const uint32_t codepoint);

bool_t unicode_isxdigit(const uint32_t codepoint);

bool_t unicode_islower(const uint32_t codepoint);

bool_t unicode_isupper(const uint32_t codepoint);

uint32_t unicode_tolower(const uint32_t codepoint);

uint32_t unicode_toupper(const uint32_t codepoint);

__END_C

