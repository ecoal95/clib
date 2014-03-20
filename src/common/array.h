#ifndef __ARRAY_H
#define __ARRAY_H

#ifndef ARRAY_STRING_LENGTH
#define ARRAY_STRING_LENGTH 100
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
int in_int_array(int *array, size_t length, const int element);
int in_uint_array(uint *array, size_t length, const uint element);
int in_long_array(long * array, size_t length, const long element);
int in_ulong_array(ulong * array, size_t length, const ulong element);
int in_llong_array(llong * array, size_t length, const llong element);
int in_ullong_array(ullong * array, size_t length, const ullong element);
int in_short_array(short * array, size_t length, const short element);
int in_ushort_array(ushort * array, size_t length, const ushort element);
int in_char_array(char * array, size_t length, const char element);
int in_string_array(string * array, size_t length, const string element);
int in_float_array(float *array, size_t length, const float element);
int in_double_array(double *array, size_t length, const double element);
int in_ldouble_array(ldouble *array, size_t length, const ldouble element);

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
void array_read_string(string * array, size_t length);
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
void array_print_string(string * array, size_t length);
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
void array_initialize_string(string * array, size_t length, const string val);
void array_initialize_float(float * array, size_t length, float val);
void array_initialize_double(double * array, size_t length, double val);
void array_initialize_ldouble(ldouble * array, size_t length, ldouble val);
#endif
