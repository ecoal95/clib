#ifndef __ARRAY_STRUCT_H
#define __ARRAY_STRUCT_H

#include "../core.h"

CPP_START


/**
 * Simple linked list
 */
struct ArrayItem {
	pointer data;
	struct ArrayItem * next;
};

typedef struct ArrayItem ArrayItem;

/**
 * Wrapper element
 */
typedef struct Array {
	ArrayItem * items;
	ArrayItem * last;
	size_t length;
} Array;


/**
 * Optimized loop through data
 */
#define ARRAY_EACH(array, value, ...) do { \
	ArrayItem * __item = array->items; \
	if ( __item == NULL ) { \
		break; \
	} \
	do { \
		value = (typeof(value)) __item->data; \
		__VA_ARGS__ \
	} while( (__item = __item->next) ); \
} while ( 0 )

#define ARRAY_EACH_WITH_INDEX(array, value, index, ...) do { \
	ArrayItem * __item = array->items; \
	index = 0; \
	if ( __item == NULL ) { \
		break; \
	} \
	do { \
		value = (typeof(value)) __item->data; \
		__VA_ARGS__ \
		index++; \
	} while ( (__item = __item->next) ); \
} while ( 0 )
/**
 * Check emptyness of array
 *
 * @param Array * array
 */
#define Array_empty(arr) (arr->items == NULL)

/**
 * Check emptyness of an array item
 *
 * @param ArrayItem * array
 */
#define ArrayItem_empty(item) (item->data == NULL)

/**
 * Allocate a new array
 *
 * @return Array *
 */
Array * newArray();

/**
 * Clone an array
 *
 * @param Array * arr
 *
 * @return Array *
 */
Array * Array_clone(Array * arr);

/**
 * Allocate a new array item
 *
 * @param const pointer data
 *
 * @return ArrayItem *
 */
ArrayItem * newArrayItem(const pointer data);

/**
 * Calculate the length of the array
 *
 * @param Array * array
 *
 * @return size_t
 */
#define Array_length(arr) (arr->length)


/**
 * Get the nth element from the array
 *
 * @param Array * arr
 * @param int index
 *
 * NOTE: we allow negative index
 * TODO: Optimize this
 *
 * @return ArrayItem *
 */
ArrayItem * Array_nth(Array * arr, int index);

/**
 * Get the last element from the array
 *
 * @param Array * arr
 *
 * @return ArrayItem *
 */
#define Array_last(arr) (arr->last)

/**
 * Push data into the array
 *
 * @param Array * arr
 * @param const pointer data
 *
 * @return Array *
 */
Array * Array_push(Array * arr, const pointer data);

/**
 * Set the data at given index. If element doesnt exists we add elements
 *
 * @param Array * arr
 * @param int index
 * @param const pointer data
 *
 * @return pointer data
 */
pointer Array_set(Array * arr, int index, const pointer data);

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
 * Removes the last element of the array and returns the data in it
 * NOTE: You must manually free the data in the returned pointer
 *
 * @param Array * arr
 *
 * @return pointer
 */
pointer Array_pop(Array * arr);

/**
 * Removes the first element from the array and returns the data in it
 *
 * @param Array * arr
 *
 * @return pointer
 */
pointer Array_shift(Array * arr);

/**
 * Insert an element in the first position and return the length of the new array
 *
 * @param Array * arr
 * @param const pointer data
 *
 * @return size_t
 */
size_t Array_unshift(Array * arr, const pointer data);

/**
 * Delete a single element from array
 * If with_data is true, returns the element value
 * else returns null
 *
 * @param Array * arr
 * @param int index
 * @param boolean with_data
 *
 * @return void
 */
pointer Array_delete(Array * arr, int index, boolean with_data);

/**
 * Removes elements from an array and returns the new length
 *
 * @param Array * arr
 * @param int index starting item
 * @param size_t elements number of elements to remove
 * @param boolean with_data
 *
 * @return size_t
 */
size_t Array_splice(Array * arr, int index, size_t elements, boolean with_data);

/**
 * Concat two arrays, modifying the first one
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
 * @param const pointer data
 *
 * @return int -1 in error, index in success
 * NOTE: This performs strict pointer comparison
 */
int Array_contains(Array * arr, const pointer data);

/**
 * Loop through each array element data, calling callback
 *
 * @param Array * arr
 * @param void (* callback)(pointer, size_t, pointer) a function that receives the data, the index and the custom data
 * @param pointer data
 */
void Array_forEach(Array * arr, void (* callback)(pointer, size_t, pointer), pointer data);

/**
 * Loop through each array element, calling callback
 *
 * @param Array * arr
 * @param void (* callback)(Array *, size_t) a function that receives the data and the index
 */
void Array_forEachItem(Array * arr, void (* callback)(ArrayItem *, size_t));

/**
 * Free an element memory
 *
 * @param ArrayItem * item
 * @param boolean with_data
 *
 * @return pointer the data if with_data was TRUE
 */
pointer ArrayItem_free(ArrayItem * item, boolean with_data);

/**
 * Remove an array with all its items
 *
 * @param Array * arr
 *
 * @return void
 */
void Array_destroy(Array * arr, boolean with_data);

/**
 * Sorts the array using the bubble sort algo
 *
 * @param Array * arr
 * @param int (* compfunc) (pointer, pointer)
 *
 * @return void
 */
void Array_bsort(Array * arr, int (* compfunc)(pointer, pointer));

CPP_END

#endif
