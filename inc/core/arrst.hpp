/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2021 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: arrst.hpp
 * https://nappgui.com/en/core/arrst.html
 *
 */

/* Arrays of structures */

#include "array.h"

template<typename type>
struct ArrSt
{
	static ArrSt<type>* create(void);

	static void destroy(ArrSt<type> **array, void(*func_remove)(type*));

	static void clear(ArrSt<type> *array, void(*func_remove)(type*));

	static uint32_t size(const ArrSt<type> *array);

	static type* get(ArrSt<type> *array, const uint32_t pos);

	static type* last(ArrSt<type> *array);

	static type* all(ArrSt<type> *array);

	static void grow(ArrSt<type> *array, const uint32_t n);

    static void append(ArrSt<type> *array, type value);

	static type* append1(ArrSt<type> *array);

    static void prepend(ArrSt<type> *array, type value);

	static type* prepend1(ArrSt<type> *array);

    static void insert(ArrSt<type> *array, const uint32_t pos, type value);

	static type* insert1(ArrSt<type> *array, const uint32_t pos);

	//static void append(ArrSt<type> *array, type *value);

	//static void set(ArrSt<type> *array, const uint32_t pos, type *value);
};

/*---------------------------------------------------------------------------*/

template<typename type> 
ArrSt<type>* ArrSt<type>::create(void)
{
	return (ArrSt<type>*)array_create_imp(sizeof(type), "ArrSt<type>");
}

/*---------------------------------------------------------------------------*/

template<typename type> 
void ArrSt<type>::destroy(ArrSt<type> **array, void(*func_remove)(type*))
{
	array_destroy_imp((Array**)array, (FPtr_remove)func_remove, "ArrSt<type>");
}

/*---------------------------------------------------------------------------*/

template<typename type> 
void ArrSt<type>::clear(ArrSt<type> *array, void(*func_remove)(type*))
{
	array_clear_imp((Array*)array, (FPtr_remove)func_remove);
}

/*---------------------------------------------------------------------------*/

template<typename type> 
uint32_t ArrSt<type>::size(const ArrSt<type> *array)
{
	return array_size_imp((Array*)array);
}

/*---------------------------------------------------------------------------*/

template<typename type>
type* ArrSt<type>::get(ArrSt<type> *array, const uint32_t pos)
{
    return (type*)array_get_imp((Array*)array, pos);
}

/*---------------------------------------------------------------------------*/

template<typename type>
type* ArrSt<type>::last(ArrSt<type> *array)
{
    return (type*)array_get_last_imp((Array*)array);
}

/*---------------------------------------------------------------------------*/

template<typename type>
type* ArrSt<type>::all(ArrSt<type> *array)
{
    return (type*)array_all_imp((Array*)array);
}

/*---------------------------------------------------------------------------*/

template<typename type>
void ArrSt<type>::grow(ArrSt<type> *array, const uint32_t n)
{
	array_insert_imp((Array*)array, UINT32_MAX, n);
}

/*---------------------------------------------------------------------------*/

template<typename type>
void ArrSt<type>::append(ArrSt<type> *array, type value)
{
	*(type*)array_insert_imp((Array*)array, UINT32_MAX, 1) = value;
}

/*---------------------------------------------------------------------------*/

template<typename type>
type* ArrSt<type>::append1(ArrSt<type> *array)
{
	(type*)array_insert_imp((Array*)array, UINT32_MAX, 1);
}

/*---------------------------------------------------------------------------*/

template<typename type>
void ArrSt<type>::prepend(ArrSt<type> *array, type value)
{
	*(type*)array_insert_imp((Array*)array, 0, 1) = value;
}

/*---------------------------------------------------------------------------*/

template<typename type>
type* ArrSt<type>::prepend1(ArrSt<type> *array)
{
	(type*)array_insert_imp((Array*)array, 0, 1);
}

/*---------------------------------------------------------------------------*/

template<typename type>
void ArrSt<type>::insert(ArrSt<type> *array, const uint32_t pos, type value)
{
	*(type*)array_insert_imp((Array*)array, pos, 1) = value;
}

/*---------------------------------------------------------------------------*/

template<typename type>
type* ArrSt<type>::insert1(ArrSt<type> *array, const uint32_t pos)
{
	(type*)array_insert_imp((Array*)array, pos, 1);
}
