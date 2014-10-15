#ifndef __ARRAY_H
#define __ARRAY_H

CPP_START

#include "../core/core.h"
#include "str.h"

#ifndef ARRAY_STRING_LENGTH
#define ARRAY_STRING_LENGTH 100
#endif

#define __IN_ARRAY(arr, el) \
	size_t i = 0;\
	for(; i < length; i++) {\
		if( array[i] == element ) {\
			return i;\
		}\
	}\
	return -1;

// fs = format specifier
#define __ARRAY_READ(arr, len, fs) \
	size_t i = 0; \
	for(; i < len; i++) { \
		printf("[%zu]: ", i); \
		if( 1 !=  scanf(fs, arr + i)) { \
			utils_ib_clean(); \
			i--; \
		} \
	}


/**
 * Creates an array using dynamic memory allocation
 *
 * @param size_t size
 * @param size_t elementsize
 *
 * @return void * the new array, NULL on failure
 */
void * array_create(size_t size, size_t elementsize);

#define array_create_int(size) (int *) array_create(size, sizeof(int));
#define array_create_uint(size) (uint *) array_create(size, sizeof(uint));
#define array_create_long(size) (long *) array_create(size, sizeof(long));
#define array_create_ulong(size) (ulong *) array_create(size, sizeof(ulong));
#define array_create_llong(size) (llong *) array_create(size, sizeof(llong));
#define array_create_ullong(size) (ullong *) array_create(size, sizeof(ullong));
#define array_create_short(size) (short *) array_create(size, sizeof(short));
#define array_create_ushort(size) (ushort *) array_create(size, sizeof(ushort));
#define array_create_char(size) (char *) array_create(size, sizeof(char));
#define array_create_string(size) (char * *) array_create(size, sizeof(char *));
#define array_create_float(size) (float *) array_create(size, sizeof(float));
#define array_create_double(size) (double *) array_create(size, sizeof(double));
#define array_create_ldouble(size) (ldouble *) array_create(size, sizeof(ldouble));


/**
 * Get the length of array
 * NOTE: this only works with statically alocated arrays
 */
#define array_length(a) (sizeof(a)/sizeof(a[0]))

/**
 * Clone an array
 *
 * @param const void * array
 * @param const size_t length
 * @param const size_t elementsize
 *
 * @return void * the new array
 */
void * array_clone_raw(const void * array, const size_t length, const size_t elementsize);
#define __array_clone_3(array, length, elementsize) (array_clone_raw(array, length, elementsize))
#define __array_clone_2(array, length) (array_clone_raw(array, length, sizeof(array[0])))
#define __array_clone_1(array) (array_clone_raw(array, array_length(array), sizeof(array[0])))
#ifdef C99
#define array_clone(...) GET_VA_MACRO_3(__VA_ARGS__, __array_clone_3, __array_clone_2, __array_clone_1)(__VA_ARGS__)
#else
#define array_clone(args...) GET_VA_MACRO_3(args, __array_clone_3, __array_clone_2, __array_clone_1)(args)
#endif

/**
 * Concat two arrays
 *
 * @param const void * v1 first array
 * @param const size_t l1
 * @param const void * v2
 * @param const size_t l2
 *
 * @return void * the new array
 */
void * array_concat_raw(const void * v1, const size_t l1, const void * v2, const size_t l2, const size_t elementsize);
#define __array_concat_5(v1, l1, v2, l2, elementsize) (array_concat_raw(v1, l1, v2, l2, elementsize))
#define __array_concat_4(v1, l1, v2, l2) (array_concat_raw(v1, l1, v2, l2, sizeof(v1[0])))
#define __array_concat_3(v1, v2, l) (array_concat_raw(v1, l, v2, l, sizeof(v1[0])))
#define __array_concat_2(v1, v2) (array_concat_raw(v1, array_length(v1), v2, array_length(v2), sizeof(v1[0])))
#ifdef C99
#define array_concat(...) GET_VA_MACRO_5(__VA_ARGS__, __array_concat_5, __array_concat_4, __array_concat_3, __array_concat_2)(__VA_ARGS__)
#else
#define array_concat(args...) GET_VA_MACRO_5(args, __array_concat_5, __array_concat_4, __array_concat_3, __array_concat_2)(args)
#endif

/**
 * Revert order of an array
 *
 * @param void * array
 * @param const size_t length
 * @param const size_t elementsize
 *
 * @return void * the input array
 */
void * array_revert_raw(void * array, const size_t length, const size_t elementsize);
#define __array_revert_3(array, length, elementsize) (array_revert_raw(array, length, elementsize))
#define __array_revert_2(array, length) (array_revert_raw(array, length, sizeof(array[0])))
#define __array_revert_1(array) (array_revert_raw(array, array_length(array), sizeof(array[0])))
#ifdef C99
#define array_revert(...) GET_VA_MACRO_3(__VA_ARGS__, __array_revert_3, __array_revert_2, __array_revert_1)(__VA_ARGS__)
#else
#define array_revert(args...) GET_VA_MACRO_3(args, __array_revert_3, __array_revert_2, __array_revert_1)(args)
#endif


/**
 * Generic in_array
 * Check if element is in array, returns index on success, -1 on failure
 *
 * @param const void * array
 * @param const size_t length
 * @param const void * element
 * @param const size_t elementsize
 *
 * @return int
 */
int in_array_raw(const void * array, const size_t length, const void * element, const size_t elementsize);
#define __in_array_4(array, length, element, elementsize) (in_array_raw(array, length, element, elementsize))
#define __in_array_3(array, length, element) (in_array_raw(array, length, element, sizeof(array[0])))
#define __in_array_2(array, element) (in_array_raw(array, array_length(array), TO_POINTER(element), sizeof(array[0])))
#ifdef C99
#define in_array(...) GET_VA_MACRO_4(__VA_ARGS__, __in_array_4, __in_array_3, __in_array_2)(__VA_ARGS__)
#else
#define in_array(args...) GET_VA_MACRO_4(args, __in_array_4, __in_array_3, __in_array_2)(args)
#endif

/**
 * Check if element exists in an int array and returns the index or -1 if it doesn't
 *
 * @param int * array
 * @param size_t length
 * @param const int element
 *
 * @return int
 */
int in_int_array(const int *array, size_t length, const int element);
int in_uint_array(const uint *array, size_t length, const uint element);
int in_long_array(const long * array, size_t length, const long element);
int in_ulong_array(const ulong * array, size_t length, const ulong element);
int in_llong_array(const llong * array, size_t length, const llong element);
int in_ullong_array(const ullong * array, size_t length, const ullong element);
int in_short_array(const short * array, size_t length, const short element);
int in_ushort_array(const ushort * array, size_t length, const ushort element);
int in_char_array(const char * array, size_t length, const char element);
int in_string_array(const char * * array, size_t length, const char * element);
int in_float_array(const float *array, size_t length, const float element);
int in_double_array(const double *array, size_t length, const double element);
int in_ldouble_array(const ldouble *array, size_t length, const ldouble element);

/**
 * Reads from stdin a whole array
 *
 * @param int * array
 * @param size_t length
 *
 */
void array_read_int(int * array, size_t length);
void array_read_uint(uint * array, size_t length);
void array_read_long(long * array, size_t length);
void array_read_ulong(ulong * array, size_t length);
void array_read_llong(llong * array, size_t length);
void array_read_ullong(ullong * array, size_t length);
void array_read_short(short * array, size_t length);
void array_read_ushort(ushort * array, size_t length);
void array_read_char(char * array, size_t length);
void array_read_string(char * * array, size_t length);
void array_read_float(float * array, size_t length);
void array_read_double(double * array, size_t length);
void array_read_ldouble(ldouble * array, size_t length);

/**
 * Prints an array
 *
 * @param int * array
 * @param size_t length
 *
 */
void array_print_int(int * array, size_t length);
void array_print_uint(uint * array, size_t length);
void array_print_long(long * array, size_t length);
void array_print_ulong(ulong * array, size_t length);
void array_print_llong(llong * array, size_t length);
void array_print_ullong(ullong * array, size_t length);
void array_print_short(short * array, size_t length);
void array_print_ushort(ushort * array, size_t length);
void array_print_char(char * array, size_t length);
void array_print_string(char * * array, size_t length);
void array_print_float(float * array, size_t length);
void array_print_double(double * array, size_t length);
void array_print_ldouble(ldouble * array, size_t length);

/**
 * Inicializar arrays
 *
 * @param int * array
 * @param size_t length
 * @param const int val
 *
 */
void array_initialize_int(int * array, size_t length, const int val);
void array_initialize_uint(uint * array, size_t length, const uint val);
void array_initialize_long(long * array, size_t length, const long val);
void array_initialize_ulong(ulong * array, size_t length, const ulong val);
void array_initialize_llong(long * array, size_t length, const llong val);
void array_initialize_ullong(ullong * array, size_t length, const ullong val);
void array_initialize_short(short * array, size_t length, const short val);
void array_initialize_ushort(ushort * array, size_t length, const ushort val);
void array_initialize_char(char * array, size_t length, const char val);
void array_initialize_string(char * * array, size_t length, const char * val);
void array_initialize_float(float * array, size_t length, float val);
void array_initialize_double(double * array, size_t length, double val);
void array_initialize_ldouble(ldouble * array, size_t length, ldouble val);

CPP_END

#endif
