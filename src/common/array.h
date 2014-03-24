#ifndef __ARRAY_H
#define __ARRAY_H

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
		printf("[%d]:", i); \
		scanf(fs, arr + i); \
		utils_ib_clean(); \
	}
/**
 * Get the length of array
 * NOTE: this only works with statically alocated arrays
 */
#define array_length(a) (sizeof(a)/sizeof(a[0]))

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
void * array_concat(const void * v1, const size_t l1, const void * v2, const size_t l2, const size_t elementsize);

#define array_concat_int(v1, l1, v2, l2) ((int *) array_concat(v1, l1, v2, l2, sizeof(int)))
#define array_concat_uint(v1, l1, v2, l2) ((uint *) array_concat(v1, l1, v2, l2, sizeof(uint)))
#define array_concat_long(v1, l1, v2, l2) ((long *) array_concat(v1, l1, v2, l2, sizeof(long)))
#define array_concat_ulong(v1, l1, v2, l2) ((ulong *) array_concat(v1, l1, v2, l2, sizeof(ulong)))
#define array_concat_llong(v1, l1, v2, l2) ((llong *) array_concat(v1, l1, v2, l2, sizeof(llong)))
#define array_concat_ullong(v1, l1, v2, l2) ((ullong *) array_concat(v1, l1, v2, l2, sizeof(ullong)))
#define array_concat_short(v1, l1, v2, l2) ((short *) array_concat(v1, l1, v2, l2, sizeof(short)))
#define array_concat_ushort(v1, l1, v2, l2) ((ushort *) array_concat(v1, l1, v2, l2, sizeof(ushort)))
#define array_concat_char(v1, l1, v2, l2) ((char *) array_concat(v1, l1, v2, l2, sizeof(char)))
#define array_concat_string(v1, l1, v2, l2) ((char * *) array_concat(v1, l1, v2, l2, sizeof(char *)))
#define array_concat_float(v1, l1, v2, l2) ((float *) array_concat(v1, l1, v2, l2, sizeof(float)))
#define array_concat_double(v1, l1, v2, l2) ((double *) array_concat(v1, l1, v2, l2, sizeof(double)))
#define array_concat_ldouble(v1, l1, v2, l2) ((ldouble *) array_concat(v1, l1, v2, l2, sizeof(ldouble)))


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
int in_array(const void * array, const size_t length, const void * element, const size_t elementsize);

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
#endif
