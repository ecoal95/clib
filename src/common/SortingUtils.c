#include "SortingUtils.h"
/**
 * Sorting a vector of pointers using bubble sort algorithm
 *
 * @param void **vector
 * @param size_t length
 * @param SortingComparison cmp
 * @param void *data
 *
 * @return void ** the same vector
 */
void ** SortingUtils__bubbleSort(void **vector, size_t length, SortingComparison cmp, void *data) {
	size_t i = 0,
		j;
	void *temp;

	length--;

	for ( ; i < length; i++ ) {
		for ( j = 0; j < length - i; i++ ) {
			if ( cmp(vector[j], vector[j + 1], data) > 0 ) {
				temp = vector[j];
				vector[j] = vector[j + 1];
				vector[j + 1] = temp;
			}
		}
	}

	return vector;
}

/**
 * Sorting a vector of pointers using select sort algorithm
 *
 * @param void **vector
 * @param size_t length
 * @param SortingComparison cmp
 * @param void *data
 *
 * @return void ** the same vector
 */
void ** SortingUtils__selectSort(void **vector, size_t length, SortingComparison cmp, void *data) {
	size_t i, j;
	size_t lower_index;
	void *temp;

	for ( i = 1; i < length; i++) {
		lower_index = i - 1;
		for ( j = i; j < length; j++) {
			if ( cmp(vector[lower_index], vector[j], data) > 0 ) {
				lower_index = j;
			}
		}
		temp = vector[i - 1];
		vector[i - 1] = vector[lower_index];
		vector[lower_index] = temp;
	}

	return vector;
}

/**
 * Sorting comparisong for descending order of ints
 *
 * @param void *v1
 * @param void *v2
 * @param void *data
 *
 * @return int
 */
int SortingUtils__INT_DESCENDING(const void *v1, const void *v2, void *data) {
	int *i1 = (int *) v1;
	int *i2 = (int *) v2;

	return *i1 - *i2;
}

/**
 * Sorting comparisong for ascending order of ints
 *
 * @param void *v1
 * @param void *v2
 * @param void *data
 *
 * @return int
 */
int SortingUtils__INT_ASCENDING(const void *v1, const void *v2, void *data) {
	return -SortingUtils__INT_DESCENDING(v1, v2, data);
}
