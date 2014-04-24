#ifndef __ARRAY_STRUCT_H
#define __ARRAY_STRUCT_H

CPP_START

#include "../core/core.h"

/**
 * One direction linked list
 */
struct Array {
	pointer data;
	struct Array * next;
};

typedef struct Array Array;


/**
 * Check emptyness of array contents
 *
 * @param Array * array
 */
#define Array_empty(arr) (arr->data == NULL)

/**
 * Allocate a new array
 *
 * @param pointer data
 *
 * @return Array *
 */
Array * newArray(pointer data);

/**
 * Calculate the length of the array
 *
 * @param Array * array
 *
 * @return size_t
 */
size_t Array_length(Array * arr);

/**
 * Get the nth element from the array
 *
 * @param Array * arr
 * @param int index
 *
 * NOTE: we allow negative index
 *
 * @return Array *
 */
Array * Array_nth(Array * arr, int index);

/**
 * Get the last element from the array
 *
 * @param Array * arr
 *
 * @return Array *
 */
Array * Array_last(Array * arr);

/**
 * Push data into the array
 *
 * @param Array * arr
 * @param pointer data
 *
 * @return Array *
 */
Array * Array_push(Array * arr, pointer data);

/**
 * Set the data at given index. If element doesnt exists we add elements
 *
 * @param Array * arr
 * @param int index
 * @param pointer data
 *
 * @return pointer data
 */
pointer Array_set(Array * arr, int index, pointer data);

/**
 * Get data from the nth element of the array
 *
 * @param Array * arr
 * @param int index
 *
 * @return pointer
 */
pointer Array_get(Array * arr, int index);

/**
 * Removes the last element of the array and returns the array
 *
 * @param Array * arr
 *
 * @return Array *
 */
Array * Array_pop(Array * arr);

/**
 * Removes the first element from the array and returns the new array
 *
 * @param Array * arr
 *
 * @return Array *
 */
Array * Array_shift(Array * arr);

/**
 * Insert an element in the first position and return the new array
 *
 * @param Array * arr
 * @param pointer data
 *
 * @return Array *
 */
Array * Array_unshift(Array * arr, pointer data);

/**
 * Delete a single element from array
 *
 * @param Array * arr
 * @param int index
 *
 * @return Array * the new array
 */
Array * Array_delete(Array * arr, int index);

/**
 * Removes elements from an array and returns the new array
 *
 * @param int index starting item
 * @param size_t elements number of elements to remove
 *
 * @return Array * arr
 */
Array * Array_splice(Array * arr, int index, size_t elements);

/**
 * Concat two arrays
 *
 * @param Array * arr1
 * @param Array * arr2
 *
 * @return Array *
 */
Array * Array_concat(Array * arr1, Array * arr2);

/**
 * Check if element is in array
 *
 * @param Array * arr
 * @param pointer data
 *
 * @return int -1 in error, index in success
 * NOTE: This performs strict pointer comparison
 */
int Array_contains(Array * arr, pointer data);

/**
 * Loop through each array element data, calling callback
 *
 * @param Array * arr
 * @param void (* callback)(pointer, size_t) a function that receives the data and the index
 */
void Array_forEach(Array * arr, void (* callback)(pointer, size_t));

/**
 * Loop through each array element, calling callback
 *
 * @param Array * arr
 * @param void (* callback)(Array *, size_t) a function that receives the data and the index
 */
void Array_forEachItem(Array * arr, void (* callback)(Array *, size_t));

/**
 * Free an element memory
 *
 * @param Array * item
 *
 * @return void
 */
void Array_free(Array * item);

/**
 * Free memory function for iteration
 *
 * @param Array * item
 * @param size_t index
 *
 * @return void
 */
void Array_free_1(Array * item, size_t index);

/**
 * Remove an array with all its items
 *
 * @param Array * arr
 *
 * @return void
 */
void Array_destroy(Array * arr);



CPP_END

#endif
