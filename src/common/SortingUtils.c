#include "SortingUtils.h"

// Just for code comprehension
// This is a functional macro so it's undef'd at the end of this file
// Last semicolon has been removed intentionally
#define SU_SWAP(a, b) temp = a; a = b; b = temp

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
		for ( j = 0; j < length - i; j++ ) {
			if ( cmp(vector[j], vector[j + 1], data) > 0 ) {
				SU_SWAP(vector[j], vector[j + 1]);
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
			if ( cmp(vector[j], vector[lower_index], data) < 0 ) {
				lower_index = j;
			}
		}
		SU_SWAP(vector[i - 1], vector[lower_index]);
	}

	return vector;
}

/**
 * Sorting a vector of pointers using insert sort algorithm
 *
 * @param void **vector
 * @param size_t length
 * @param SortingComparison cmp
 * @param void *data
 *
 * @return void ** the same vector
 */
void ** SortingUtils__insertSort(void **vector, size_t length, SortingComparison cmp, void *data) {
	void *temp;
	void *unsorted;
	size_t i;
	size_t j;

	// Assume the first element is sorted, we'll swap later
	for ( i = 1; i < length; i++ ) {
		unsorted = vector[i];
		j = i;
		// We go to the left
		while ( j-- ) {
			// If the current element is smaller than the left one
			// Move left element one position to the rigth
			if ( cmp(unsorted, vector[j], data) < 0 ) {
				SU_SWAP(vector[j], vector[j + 1]);
			} else {
				// Else we stop, we have to insert element on j + 1
				break;
			}
		}

		// insert the element in the last position where it 
		vector[j + 1] = unsorted;
	}

	return vector;
}

/**
 * Sorting a vector of pointers using quick sort algorithm
 *
 * @param void **vector
 * @param size_t length
 * @param SortingComparison cmp
 * @param void *data
 *
 * @return void ** the same vector
 */
void ** SortingUtils__quickSort(void **vector, size_t length, SortingComparison cmp, void *data) {
	void *temp;
	size_t pivot_index = 0;
	size_t store_index = 1; // store_index is the index of the first element which is greater than the pivot
	size_t i;

	if ( length == 1 ) {
		return;
	}

	for ( i = 1; i < length; i++) {
		if ( cmp(vector[i], vector[pivot_index], data) < 0 ) {
			// if element is smaller than the pivot
			// swap it with the first element greater than it
			// So the first element greater than it is potencially the next one
			if ( store_index != i ) { // Just avoid unnecessary swaps
				SU_SWAP(vector[store_index], vector[i]);
			}
			store_index++;
		}
	}

	// Move the pivot to a location where all the left elements are smaller than it
	// and all the right elements are greater than it
	SU_SWAP(vector[pivot_index], vector[store_index - 1]);

	// Sort the smaller elements
	SortingUtils__quickSort(vector, store_index, cmp, data);

	// And sort the greater ones
	SortingUtils__quickSort(vector + store_index, length - store_index, cmp, data);
	
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

	return *i2 - *i1;
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

#undef SU_SWAP
