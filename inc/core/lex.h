/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2021 Francisco Garcia Collado
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

void lexscn_jump_bom(LexScn *lex);

lextoken_t lexscn_token(LexScn *lex);

uint32_t lexscn_row(const LexScn *lex);

uint32_t lexscn_col(const LexScn *lex);

const char_t *lexscn_lexeme(const LexScn *lex, uint32_t *size);

const char_t *lexscn_string(const lextoken_t token);

void lexscn_jump(LexScn *lex, const lextoken_t token);

const char_t *lexscn_read_line(LexScn *lex);

uint32_t lexscn_read_u32(LexScn *lex);

real32_t lexscn_read_r32(LexScn *lex);

real64_t lexscn_read_r64(LexScn *lex);

__END_C
