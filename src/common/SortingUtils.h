#ifndef __SORTING_UTILS_H
#define __SORTING_UTILS_H
/** A sorting comparison function must receive the two values, and a custom data pointer */
typedef int (*SortingComparison)(const void *, const void *, void *);

/** A sorting function must receive the vector, the size, the comparison function, and a custom data pointer */
typedef void ** (*SortingFunction)(void **, size_t, SortingComparison, void *);

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
void ** SortingUtils__bubbleSort(void **vector, size_t length, SortingComparison cmp, void *data);

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
void ** SortingUtils__selectSort(void **vector, size_t length, SortingComparison cmp, void *data);

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
void ** SortingUtils__insertSort(void **vector, size_t length, SortingComparison cmp, void *data);

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
void ** SortingUtils__quickSort(void **vector, size_t length, SortingComparison cmp, void *data);

/**
 * Sorting comparisong for descending order of ints
 *
 * @param void *v1
 * @param void *v2
 * @param void *data
 *
 * @return int
 */
int SortingUtils__INT_DESCENDING(const void *v1, const void *v2, void *data);

/**
 * Sorting comparisong for ascending order of ints
 *
 * @param void *v1
 * @param void *v2
 * @param void *data
 *
 * @return int
 */
int SortingUtils__INT_ASCENDING(const void *v1, const void *v2, void *data);

#endif
