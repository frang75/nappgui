/*
 * NAppGUI-v1.1.2.2443 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: array.h
 * https://nappgui.com/en/core/array.html
 *
 */

/* Array data structure */

#include "core.hxx"

__EXTERN_C

Array *array_create_imp(const uint16_t esize, const char_t *type);

void array_destroy_imp(Array **array, FPtr_remove func_remove, const char_t *type);

void array_destroy_ptr_imp(Array **array, FPtr_destroy func_destroy, const char_t *type);

void array_clear_imp(Array *array, FPtr_remove func_remove);

void array_clear_ptr_imp(Array *array, FPtr_destroy func_destroy);

Array *array_read_imp(Stream *stream, const uint16_t esize, FPtr_read_init func_read_init, const char_t *type);

Array *array_read_ptr_imp(Stream *stream, FPtr_read func_read, const char_t *type);

void array_write_imp(Stream *stream, const Array *array, FPtr_write func_write);

void array_write_ptr_imp(Stream *stream, const Array *array, FPtr_write func_write);

uint32_t array_size_imp(const Array *array);

uint32_t array_esize_imp(const Array *array);

byte_t *array_get_imp(const Array *array, const uint32_t pos);

byte_t *array_get_last_imp(const Array *array);

byte_t *array_all_imp(const Array *array);

byte_t *array_insert_imp(Array *array, const uint32_t pos, const uint32_t n);

void array_delete_imp(Array *array, const uint32_t pos, const uint32_t n, FPtr_remove func_remove);

void array_delete_ptr_imp(Array *array, const uint32_t pos, const uint32_t n, FPtr_destroy func_destroy);

void array_pop_imp(Array *array, FPtr_remove func_remove);

void array_pop_ptr_imp(Array *array, FPtr_destroy func_destroy);

void array_sort_imp(Array *array, FPtr_compare func_compare);

void array_sort_ptr_imp(Array *array, FPtr_compare func_compare);

uint32_t array_find_ptr_imp(const Array *array, const void *elem);

byte_t *array_search_imp(const Array *array, FPtr_compare func_compare, const void *key, uint32_t *pos);

byte_t *array_search_ptr_imp(const Array *array, FPtr_compare func_compare, const void *key, uint32_t *pos);

byte_t *array_bsearch_imp(const Array *array, FPtr_compare func_compare, const void *key, uint32_t *pos);

byte_t *array_bsearch_ptr_imp(const Array *array, FPtr_compare func_compare, const void *key, uint32_t *pos);

__END_C
