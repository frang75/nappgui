/*
 * NAppGUI-v1.1.1.2372 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: lex.h
 * https://nappgui.com/en/core/lex.html
 *
 */

/* Lexical scanner */

#include "core.hxx"

__EXTERN_C

LexScn *lexscn_create(void);

void lexscn_destroy(LexScn **lex);

void lexscn_spaces(LexScn *lex, const bool_t activate);

void lexscn_newlines(LexScn *lex, const bool_t activate);

void lexscn_escapes(LexScn *lex, const bool_t activate);

void lexscn_comments(LexScn *lex, const bool_t activate);

void lexscn_start(LexScn *lex, Stream *stm);

lextoken_t lexscn_token(LexScn *lex);

uint32_t lexscn_row(const LexScn *lex);

uint32_t lexscn_col(const LexScn *lex);

const char_t *lexscn_lexeme(const LexScn *lex, uint32_t *size);

const char_t *lexscn_string(const lextoken_t token);

__END_C
