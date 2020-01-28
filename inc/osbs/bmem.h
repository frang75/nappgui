/*
 * NAppGUI-v1.1.1.2372 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: bmem.h
 * https://nappgui.com/en/osbs/bmem.html
 *
 */

/* Operating System memory support */

#include "osbs.hxx"

__EXTERN_C

byte_t *bmem_aligned_malloc(const uint32_t size, const uint32_t align);

byte_t *bmem_aligned_realloc(byte_t *mem, const uint32_t size, const uint32_t new_size, const uint32_t align);

void bmem_free(byte_t *mem);

void bmem_set1(byte_t *dest, const uint32_t size, const byte_t mask);

void bmem_set4(byte_t *dest, const uint32_t size, const byte_t *mask);

void bmem_set8(byte_t *dest, const uint32_t size, const byte_t *mask);

void bmem_set16(byte_t *dest, const uint32_t size, const byte_t *mask);

bool_t bmem_is_zero(const byte_t *mem, const uint32_t size);

void bmem_set_zero(byte_t *dest, const uint32_t size);

void bmem_copy(byte_t *dest, const byte_t *src, const uint32_t size);

void bmem_move(byte_t *dest, const byte_t *src, const uint32_t size);

bool_t bmem_overlaps(const byte_t *mem1, const byte_t *mem2, const uint32_t size1, const uint32_t size2);

void bmem_rev(byte_t *mem, const uint32_t size);

void bmem_rev2(byte_t *mem);

void bmem_rev4(byte_t *mem);

void bmem_rev8(byte_t *mem);

void bmem_revcopy(byte_t *dest, const byte_t *src, const uint32_t size);

void bmem_swap(byte_t *mem1, byte_t *mem2, const uint32_t size);

void bmem_shuffle(byte_t *mem, const uint32_t size, const uint32_t esize);

__END_C

#define bmem_malloc(size)\
    bmem_aligned_malloc((size), sizeof(void*))

#define bmem_realloc(mem, size, new_size)\
    bmem_aligned_realloc((mem), (size), (new_size), sizeof(void*))

#define bmem_zero(dest, type)\
    ((void)((dest) == (type*)(dest)),\
    bmem_set_zero((byte_t*)(dest), sizeof(type)))

#define bmem_zero_n(dest, n, type)\
    ((void)((dest) == (type*)(dest)),\
    bmem_set_zero((byte_t*)(dest), n * sizeof(type)))

#define bmem_copy_n(dest, src, n, type)\
    ((void)((dest) == (type*)(dest)),\
    (void)((src) == (const type*)(src)),\
    bmem_copy((byte_t*)(dest), (const byte_t*)(src), (uint32_t)sizeof(type) * (uint32_t)(n)))

#define bmem_swap_type(obj1, obj2, type)\
    ((void)((obj1) == (type*)(obj1)),\
    (void)((obj2) == (type*)(obj2)),\
    bmem_swap((byte_t*)(obj1), (byte_t*)(obj2), (uint32_t)sizeof(type)))

#define bmem_shuffle_n(arr, size, type)\
    ((void)(arr == (type*)arr),\
    bmem_shuffle((byte_t*)arr, size, sizeof(type)))

#define bmem_set_u32(dest, n, value)\
    {uint32_t ___value = (value);\
    bmem_set4((byte_t*)(dest), (uint32_t)(sizeof(uint32_t) * (n)), (const byte_t*)&___value); }
