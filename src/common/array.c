#include "array.h"
/**
 * Creates an array using dynamic memory allocation
 *
 * @param size_t size
 * @param size_t elementsize
 *
 * @return void * the new array, NULL on failure
 */
void * array_create(size_t size, size_t elementsize) {
	void * ret;

	return_null_if(size <= 0);
	return_null_if(elementsize <= 0);

	ret = (void *) malloc(size * elementsize);

	return_null_if(ret == NULL); // ensure warning

	return ret;
}

/**
 * Clone an array
 *
 * @param const void * array
 * @param const size_t length
 * @param const size_t elementsize
 *
 * @return void * the new array
 */
void * array_clone_raw(const void * array, const size_t length, const size_t elementsize) {
	void * ret = malloc(length * elementsize);

	return_null_if(ret == NULL);

	memcpy(ret, array, length * elementsize);

	return ret;
}

/**
 * Concat two arrays
 *
 * @param const void * v1 first array
 * @param const size_t l1
 * @param const void * v2
 * @param const size_t l2
 * @param const size_t elementsize
 *
 * @return void * the new array
 */
void * array_concat_raw(const void * v1, const size_t l1, const void * v2, const size_t l2, const size_t elementsize) {
	size_t len = l1 + l2;
	void * ret = malloc(len * elementsize);
	// We cast it to char * because char type is always 1 byte, and void * pointer arithmetic is not defined
	char * ret_bytes = (char *) ret;

	return_val_if(ret == NULL, NULL);

	memcpy(ret_bytes, v1, l1 * elementsize);
	memcpy(ret_bytes + l1 * elementsize, v2, l2 * elementsize);

	return ret;
}

/**
 * Revert order of an array
 *
 * @param void * array
 * @param const size_t length
 * @param const size_t elementsize
 *
 * @return void * the input array
 */
void * array_revert_raw(void * array, const size_t length, const size_t elementsize) {
	char * array_bytes = (char *) array;
	size_t i = 0,
		iterations = length / 2;
	char temp;

	// If element size isn't one we have to use a different method
	if( elementsize != 1 ) {
		char * element = (char *) malloc(elementsize);

		return_val_if(element == NULL, NULL);

		for( ; i < iterations; i++) {
			// temp = array[i]
			memcpy(element, array_bytes + i * elementsize, elementsize);
			// array[i] = array[length - i - 1]
			memcpy(array_bytes + i * elementsize, array_bytes + (length - i - 1) * elementsize, elementsize);
			// array[length - i - 1] = temp;
			memcpy(array_bytes + (length - i - 1) * elementsize, element, elementsize);
		}

		free(element);

		return array;
	}

	for( ; i < iterations; i++) {
		temp = array_bytes[i];
		array_bytes[i] = array_bytes[length - i - 1];
		array_bytes[length - i - 1] = temp;
	}
	return array;
}

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
int in_array_raw(const void * array, const size_t length, const void * element, const size_t elementsize) {
	size_t i = 0,
		length_in_bytes = length * elementsize;
	// We use a char * type to do some pointer arithmetic, since char size is always 1
	char * array_bytes = (char *) array;
	for( ; i < length_in_bytes; i += elementsize) {
		if( memcmp(array_bytes + i, element, elementsize) == 0 ) {
			return i / elementsize;
		}
	}

	return -1;
}

/**
 * Check if element exists in an int array and returns the index or -1 if it doesn't
 *
 * @param int * array
 * @param size_t length
 * @param const int element
 *
 * @return int
 */
int in_int_array(const int *array, size_t length, const int element) {
	__IN_ARRAY(array, element);
}

/**
 * Check if element exists in an uint array and returns the index or -1 if it doesn't
 *
 * @param uint * array
 * @param size_t length
 * @param const uint element
 *
 * @return int
 */
int in_uint_array(const uint *array, size_t length, const uint element) {
	__IN_ARRAY(array, element);
}

/**
 * Check if element exists in an long array and returns the index or -1 if it doesn't
 *
 * @param long * array
 * @param size_t length
 * @param const long element
 *
 * @return int
 */
int in_long_array(const long * array, size_t length, const long element) {
	__IN_ARRAY(array, element);
}

/**
 * Check if element exists in an ulong array and returns the index or -1 if it doesn't
 *
 * @param ulong * array
 * @param size_t length
 * @param const ulong element
 *
 * @return int
 */
int in_ulong_array(const ulong * array, size_t length, const ulong element) {
	__IN_ARRAY(array, element);
}

/**
 * Check if element exists in an llong array and returns the index or -1 if it doesn't
 *
 * @param llong * array
 * @param size_t length
 * @param const long element
 *
 * @return int
 */
int in_llong_array(const llong * array, size_t length, const llong element) {
	__IN_ARRAY(array, element);
}

/**
 * Check if element exists in an ullong array and returns the index or -1 if it doesn't
 *
 * @param ullong * array
 * @param size_t length
 * @param const ullong element
 *
 * @return int
 */
int in_ullong_array(const ullong * array, size_t length, const ullong element) {
	__IN_ARRAY(array, element);
}

/**
 * Check if element exists in an short array and returns the index or -1 if it doesn't
 *
 * @param short * array
 * @param size_t length
 * @param const short element
 *
 * @return int
 */
int in_short_array(const short * array, size_t length, const short element) {
	__IN_ARRAY(array, element);
}

/**
 * Check if element exists in an ushort array and returns the index or -1 if it doesn't
 *
 * @param ushort * array
 * @param size_t length
 * @param const ushort element
 *
 * @return int
 */
int in_ushort_array(const ushort * array, size_t length, const ushort element) {
	__IN_ARRAY(array, element);
}

/**
 * Check if element exists in an char array and returns the index or -1 if it doesn't
 *
 * @param char * array
 * @param size_t length
 * @param const char element
 *
 * @return int
 */
int in_char_array(const char * array, size_t length, const char element) {
	__IN_ARRAY(array, element);
}

/**
 * Check if element exists in an char * array and returns the index or -1 if it doesn't
 *
 * @param char * * array
 * @param size_t length
 * @param const char * element
 *
 * @return int
 */
int in_string_array(const char * * array, size_t length, const char * element) {
	size_t i = 0;
	for(; i < length; i++) {
		if( strcmp(array[i], element) == 0 ) {
			return i;
		}
	}
	return -1;
}

/**
 * Check if element exists in an float array and returns the index or -1 if it doesn't
 *
 * @param float * array
 * @param size_t length
 * @param const float element
 *
 * @return int
 */
int in_float_array(const float *array, size_t length, const float element) {
	__IN_ARRAY(array, element);
}

/**
 * Check if element exists in a double array and returns the index or -1 if it doesn't
 *
 * @param double * array
 * @param size_t length
 * @param const double element
 *
 * @return int
 */
int in_double_array(const double *array, size_t length, const double element) {
	__IN_ARRAY(array, element);
}

/**
 * Check if element exists in a double array and returns the index or -1 if it doesn't
 *
 * @param ldouble * array
 * @param size_t length
 * @param const ldouble element
 *
 * @return int
 */
int in_ldouble_array(const ldouble *array, size_t length, const ldouble element) {
	__IN_ARRAY(array, element);
}

/**
 * Reads from stdin a whole array
 *
 * @param int * array
 * @param size_t length
 *
 */
void array_read_int(int * array, size_t length) {
	__ARRAY_READ(array, length, FS_INT);
}

/**
 * Reads from stdin a whole array
 *
 * @param uint * array
 * @param size_t length
 *
 */
void array_read_uint(uint * array, size_t length) {
	__ARRAY_READ(array, length, FS_UINT);
}

/**
 * Reads from stdin a whole array
 *
 * @param long * array
 * @param size_t length
 *
 */
void array_read_long(long * array, size_t length) {
	__ARRAY_READ(array, length, FS_LONG);
}

/**
 * Reads from stdin a whole array
 *
 * @param ulong * array
 * @param size_t length
 *
 */
void array_read_ulong(ulong * array, size_t length) {
	__ARRAY_READ(array, length, FS_ULONG);
}

/**
 * Reads from stdin a whole array
 *
 * @param llong * array
 * @param size_t length
 *
 */
void array_read_llong(llong * array, size_t length) {
	__ARRAY_READ(array, length, FS_LLONG);
}

/**
 * Reads from stdin a whole array
 *
 * @param ullong * array
 * @param size_t length
 *
 */
void array_read_ullong(ullong * array, size_t length) {
	__ARRAY_READ(array, length, FS_ULLONG);
}


/**
 * Reads from stdin a whole array
 *
 * @param short * array
 * @param size_t length
 *
 */
void array_read_short(short * array, size_t length) {
	__ARRAY_READ(array, length, FS_SHORT);
}

/**
 * Reads from stdin a whole array
 *
 * @param short * array
 * @param size_t length
 *
 */
void array_read_ushort(ushort * array, size_t length) {
	__ARRAY_READ(array, length, FS_USHORT);
}

/**
 * Reads from stdin a whole array
 *
 * @param char * array
 * @param size_t length
 *
 */
void array_read_char(char * array, size_t length) {
	__ARRAY_READ(array, length, FS_CHAR);
}

/**
 * Reads from stdin a whole array
 *
 * @param char * * array
 * @param size_t length
 *
 */
void array_read_string(char * * array, size_t length) {
	size_t i = 0;
	for(; i < length; i++) {
		array[i] = malloc(ARRAY_STRING_LENGTH);
		printf("[%zu]:", i);
		fgets(array[i], ARRAY_STRING_LENGTH, stdin);
		utils_ib_clean();
	}
}

/**
 * Reads from stdin a whole array
 *
 * @param float * array
 * @param size_t length
 *
 */
void array_read_float(float * array, size_t length) {
	__ARRAY_READ(array, length, FS_FLOAT);
}

/**
 * Reads from stdin a whole array
 *
 * @param double * array
 * @param size_t length
 *
 */
void array_read_double(double * array, size_t length) {
	__ARRAY_READ(array, length, FS_DOUBLE);
}

/**
 * Reads from stdin a whole array
 *
 * @param ldouble * array
 * @param size_t length
 *
 */
void array_read_ldouble(ldouble * array, size_t length) {
	__ARRAY_READ(array, length, FS_LDOUBLE);
}


/**
 * Prints an array
 *
 * @param int * array
 * @param size_t length
 *
 */
void array_print_int(int * array, size_t length) {
	size_t i = 0;
	length--;
	printf("{");
	for(; i < length; i++) {
		printf("%d, ", array[i]);
	}
	printf("%d}", array[i]);
}

/**
 * Prints an array
 *
 * @param int * array
 * @param size_t length
 *
 */
void array_print_uint(uint * array, size_t length){
	size_t i = 0;
	length--;
	printf("{");
	for(; i < length; i++) {
		printf("%u, ", array[i]);
	}
	printf("%u}", array[i]);
}

/**
 * Prints an array
 *
 * @param int * array
 * @param size_t length
 *
 */
void array_print_long(long * array, size_t length){
	size_t i = 0;
	length--;
	printf("{");
	for(; i < length; i++) {
		printf("%ld, ", array[i]);
	}
	printf("%ld}", array[i]);
}

/**
 * Prints an array
 *
 * @param int * array
 * @param size_t length
 *
 */
void array_print_ulong(ulong * array, size_t length){
	size_t i = 0;
	length--;
	printf("{");
	for(; i < length; i++) {
		printf("%lu, ", array[i]);
	}
	printf("%lu}", array[i]);
}

/**
 * Prints an array
 *
 * @param int * array
 * @param size_t length
 *
 */
void array_print_llong(llong * array, size_t length){
	size_t i = 0;
	length--;
	printf("{");
	for(; i < length; i++) {
		printf("%lld, ", array[i]);
	}
	printf("%lld}", array[i]);
}

/**
 * Prints an array
 *
 * @param int * array
 * @param size_t length
 *
 */
void array_print_ullong(ullong * array, size_t length){
	size_t i = 0;
	length--;
	printf("{");
	for(; i < length; i++) {
		printf("%llu, ", array[i]);
	}
	printf("%llu}", array[i]);
}

/**
 * Prints an array
 *
 * @param int * array
 * @param size_t length
 *
 */
void array_print_short(short * array, size_t length){
	size_t i = 0;
	length--;
	printf("{");
	for(; i < length; i++) {
		printf("%hd, ", array[i]);
	}
	printf("%hd}", array[i]);
}

/**
 * Prints an array
 *
 * @param int * array
 * @param size_t length
 *
 */
void array_print_ushort(ushort * array, size_t length){
	size_t i = 0;
	length--;
	printf("{");
	for(; i < length; i++) {
		printf("%hu, ", array[i]);
	}
	printf("%hu}", array[i]);
}

/**
 * Prints an array
 *
 * @param int * array
 * @param size_t length
 *
 */
void array_print_char(char * array, size_t length){
	size_t i = 0;
	length--;
	printf("{");
	for(; i < length; i++) {
		printf("%c, ", array[i]);
	}
	printf("%c}", array[i]);
}

/**
 * Prints an array
 *
 * @param int * array
 * @param size_t length
 *
 */
void array_print_string(char * * array, size_t length){
	size_t i = 0;
	length--;
	printf("{");
	for(; i < length; i++) {
		printf("\"%s\", ", array[i]);
	}
	printf("\"%s\"}", array[i]);
}

/**
 * Prints an array
 *
 * @param int * array
 * @param size_t length
 *
 */
void array_print_float(float * array, size_t length){
	size_t i = 0;
	length--;
	printf("{");
	for(; i < length; i++) {
		printf("%g, ", array[i]);
	}
	printf("%g}", array[i]);
}

/**
 * Prints an array
 *
 * @param int * array
 * @param size_t length
 *
 */
void array_print_double(double * array, size_t length){
	size_t i = 0;
	length--;
	printf("{");
	for(; i < length; i++) {
		printf("%lg, ", array[i]);
	}
	printf("%lg}", array[i]);
}

/**
 * Prints an array
 *
 * @param ldouble * array
 * @param size_t length
 *
 */
void array_print_ldouble(ldouble * array, size_t length){
	size_t i = 0;
	length--;
	printf("{");
	for(; i < length; i++) {
		printf("%Lg, ", array[i]);
	}
	printf("%Lg}", array[i]);
}

/**
 * Inicializar arrays
 *
 * @param int * array
 * @param size_t length
 * @param const int val
 *
 */
void array_initialize_int(int * array, size_t length, const int val) {
	size_t i;
	for( i = 0; i < length; i++ ) {
		array[i] = val;
	}
}

/**
 * Inicializar arrays
 *
 * @param uint * array
 * @param size_t length
 * @param const uint val
 *
 */
void array_initialize_uint(uint * array, size_t length, const uint val) {
	size_t i;
	for( i = 0; i < length; i++ ) {
		array[i] = val;
	}
}

/**
 * Inicializar arrays
 *
 * @param long * array
 * @param size_t length
 * @param const long val
 *
 */
void array_initialize_long(long * array, size_t length, const long val) {
	size_t i;
	for( i = 0; i < length; i++ ) {
		array[i] = val;
	}
}

/**
 * Inicializar arrays
 *
 * @param ulong * array
 * @param size_t length
 * @param const ulong val
 *
 */
void array_initialize_ulong(ulong * array, size_t length, const ulong val) {
	size_t i;
	for( i = 0; i < length; i++ ) {
		array[i] = val;
	}
}

/**
 * Inicializar arrays
 *
 * @param llong * array
 * @param size_t length
 * @param const llong val
 *
 */
void array_initialize_llong(long * array, size_t length, const llong val) {
	size_t i;
	for( i = 0; i < length; i++ ) {
		array[i] = val;
	}
}

/**
 * Inicializar arrays
 *
 * @param ullong * array
 * @param size_t length
 * @param const ullong val
 *
 */
void array_initialize_ullong(ullong * array, size_t length, const ullong val) {
	size_t i;
	for( i = 0; i < length; i++ ) {
		array[i] = val;
	}
}

/**
 * Inicializar arrays
 *
 * @param short * array
 * @param size_t length
 * @param const short val
 *
 */
void array_initialize_short(short * array, size_t length, const short val) {
	size_t i;
	for( i = 0; i < length; i++ ) {
		array[i] = val;
	}
}

/**
 * Inicializar arrays
 *
 * @param ushort * array
 * @param size_t length
 * @param const ushort val
 *
 */
void array_initialize_ushort(ushort * array, size_t length, const ushort val) {
	size_t i;
	for( i = 0; i < length; i++ ) {
		array[i] = val;
	}
}

/**
 * Inicializar arrays
 *
 * @param char * array
 * @param size_t length
 * @param const char val
 *
 */
void array_initialize_char(char * array, size_t length, const char val) {
	size_t i;
	for( i = 0; i < length; i++ ) {
		array[i] = val;
	}
}

/**
 * Inicializar arrays
 *
 * @param char * * array
 * @param size_t length
 * @param const char * val
 *
 */
void array_initialize_string(char * * array, size_t length, const char * val) {
	size_t i;
	for( i = 0; i < length; i++ ) {
		// yep, we dont point to the same value
		array[i] = str_clone(val);
	}
}

/**
 * Inicializar arrays
 *
 * @param float * array
 * @param size_t length
 * @param const float val
 *
 */
void array_initialize_float(float * array, size_t length, float val) {
	size_t i;
	for( i = 0; i < length; i++ ) {
		array[i] = val;
	}
}

/**
 * Inicializar arrays
 *
 * @param double * array
 * @param size_t length
 * @param const double val
 *
 */
void array_initialize_double(double * array, size_t length, double val) {
	size_t i;
	for( i = 0; i < length; i++ ) {
		array[i] = val;
	}
}

/**
 * Inicializar arrays
 *
 * @param ldouble * array
 * @param size_t length
 * @param const ldouble val
 *
 */
void array_initialize_ldouble(ldouble * array, size_t length, ldouble val) {
	size_t i;
	for( i = 0; i < length; i++ ) {
		array[i] = val;
	}
}
