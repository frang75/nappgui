/*
 * NAppGUI-v1.1.1.2374 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: arrst.h
 * https://nappgui.com/en/core/arrst.html
 *
 */

/* Arrays of structures */

#include "array.h"

#define arrst_create(type)\
    (ArrSt(type)*)array_create_imp(sizeof(type), (const char_t*)(ARRST#type))

#define arrst_destroy(array, func_remove, type)\
    ((void)((array) == (ArrSt(type)**)(array)),\
    FUNC_CHECK_REMOVE(func_remove, type),\
    array_destroy_imp((Array**)(array), (FPtr_remove)func_remove, (const char_t*)(ARRST#type)))

#define arrst_clear(array, func_remove, type)\
    ((void)((array) == (ArrSt(type)*)(array)),\
    FUNC_CHECK_REMOVE(func_remove, type),\
    array_clear_imp((Array*)(array), (FPtr_remove)func_remove))

#define arrst_read(stream, func_read, type)\
	(FUNC_CHECK_READ_INIT(func_read, type),\
    (ArrSt(type)*)array_read_imp(stream, sizeof(type), (FPtr_read_init)func_read, (const char_t*)(ARRST#type)))

#define arrst_write(stream, array, func_write, type)\
	((void)((array) == (const ArrSt(type)*)(array)),\
    FUNC_CHECK_WRITE(func_write, type),\
    array_write_imp(stream, (const Array*)(array), (FPtr_write)func_write))

#define arrst_size(array, type)\
	((void)((array) == (ArrSt(type)*)(array)),\
	array_size_imp((Array*)(array)))

#define arrst_get(array, pos, type)\
    ((void)((array) == (ArrSt(type)*)(array)),\
    (type*)array_get_imp((Array*)(array), (pos)))

#define arrst_last(array, type)\
    ((void)((array) == (ArrSt(type)*)(array)),\
    (type*)array_get_last_imp((Array*)(array)))

#define arrst_all(array, type)\
    ((void)((array) == (ArrSt(type)*)(array)),\
    (type*)array_all_imp((Array*)(array)))

#define arrst_grow(array, n, type)\
    ((void)((array) == (ArrSt(type)*)(array)),\
	(void)array_insert_imp((Array*)(array), UINT32_MAX, (n)))

#define arrst_append(array, value, type)\
    ((void)((array) == (ArrSt(type)*)(array)),\
	(*(type*)array_insert_imp((Array*)(array), UINT32_MAX, 1)) = (value))

#define arrst_append1(array, type)\
    ((void)((array) == (ArrSt(type)*)(array)),\
	(type*)array_insert_imp((Array*)(array), UINT32_MAX, 1))

#define arrst_prepend(array, value, type)\
    ((void)((array) == (ArrSt(type)*)(array)),\
	(*(type*)array_insert_imp((Array*)(array), 0, 1)) = (value))

#define arrst_prepend1(array, type)\
    ((void)((array) == (ArrSt(type)*)(array)),\
	(type*)array_insert_imp((Array*)(array), 0, 1))

#define arrst_insert(array, pos, value, type)\
    ((void)((array) == (ArrSt(type)*)(array)),\
	(*(type*)array_insert_imp((Array*)(array), (pos), 1)) = (value))

#define arrst_insert1(array, pos, type)\
    ((void)((array) == (ArrSt(type)*)(array)),\
	(type*)array_insert_imp((Array*)(array), (pos), 1))

#define arrst_delete(array, pos, func_remove, type)\
	((void)((array) == (ArrSt(type)*)(array)),\
    FUNC_CHECK_REMOVE(func_remove, type),\
    array_delete_imp((Array*)(array), (pos), 1, (FPtr_remove)func_remove))

#define arrst_pop(array, func_remove, type)\
	((void)((array) == (ArrSt(type)*)(array)),\
    FUNC_CHECK_REMOVE(func_remove, type),\
    array_pop_imp((Array*)(array), (FPtr_remove)func_remove))

#define arrst_sort(array, func_compare, type)\
    ((void)((array) == (ArrSt(type)*)(array)),\
    FUNC_CHECK_COMPARE(func_compare, type),\
    array_sort_imp((Array*)(array), (FPtr_compare)func_compare))

#define arrst_search(array, func_compare, key, pos, type, ktype)\
    ((void)((array) == (ArrSt(type)*)(array)),\
    FUNC_CHECK_COMPARE_KEY(func_compare, type, ktype),\
    (void)((key) == (ktype*)(key)),\
    (type*)array_search_imp((const Array*)(array), (FPtr_compare)func_compare, (const void*)key, pos))

#define arrst_bsearch(array, func_compare, key, pos, type, ktype)\
    ((void)((array) == (ArrSt(type)*)(array)),\
    FUNC_CHECK_COMPARE_KEY(func_compare, type, ktype),\
    (void)((key) == (ktype*)(key)),\
    (type*)array_bsearch_imp((const Array*)(array), (FPtr_compare)func_compare, (const void*)key, pos))

#define arrst_foreach(elem, array, type)\
    {\
        register type *elem = NULL;\
        register uint32_t elem##_i, elem##_total;\
        elem = arrst_all((array), type);\
        elem##_total = arrst_size((array), type);\
        for (elem##_i = 0; elem##_i < elem##_total; ++elem##_i, ++elem)\
        {

#define arrst_foreach_rev(elem, array, type)\
    {\
        register type *elem = NULL;\
        register uint32_t i, elem##_i, elem##_total;\
        elem = arrst_all((array), type);\
        elem##_total = arrst_size((array), type);\
        elem += elem##_total - 1;\
        elem##_i = elem##_total - 1;\
        for (i = 0; i < elem##_total; ++i, --elem##_i, --elem)\
        {

#define arrst_end()\
        }\
    }
