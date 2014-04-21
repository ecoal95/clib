#include "Array.h"
/**
 * Allocate a new array
 *
 * @param pointer data
 *
 * @return Array *
 */
Array * newArray(pointer data) {
	Array * arr = (Array *) malloc(sizeof(Array));

	return_null_if(arr == NULL);

	arr->data = data;
	return arr;
}

/**
 * Calculate the length of the array
 *
 * @param Array * array
 *
 * @return size_t
 */
size_t Array_length(Array * arr) {
	size_t length = 1;
	while(arr->next) {
		length++;
		arr = arr->next;
	}
	return length;
}

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
Array * Array_nth(Array * arr, int index) {
	size_t length = Array_length(arr);

	if( index < 0 ) {
		index += length;
	}

	if( index >= length || index < 0) {
		return NULL;
	}

	if( index == 0 ) {
		return arr;
	}

	return arr[index - 1].next;
}

/**
 * Get the last element from the array
 *
 * @param Array * arr
 *
 * @return Array *
 */
Array * Array_last(Array * arr) {
	return Array_nth(arr, -1);
}

/**
 * Push data into the array
 *
 * @param Array * arr
 * @param pointer data
 *
 * @return Array *
 */
Array * Array_push(Array * arr, pointer data) {
	Array * item = newArray(data);
	Array * last = Array_last(arr);
	last->next = item;
	return arr;
}

/**
 * Set the data at given index. If element doesnt exists we add elements
 *
 * @param Array * arr
 * @param int index
 * @param pointer data
 *
 * @return pointer data
 */
pointer Array_set(Array * arr, int index, pointer data) {
	Array * item = Array_nth(arr, index);
	size_t length;

	// If the element does exist
	if( item != NULL ) {
		item->data = data;
		return data;
	}

	// We doesn't let assignment with negative index to an unknown element
	if( index < 0 ) {
		return NULL;
	}

	// If item doesnt exist we create enough empty elements
	length = Array_length(arr);
	while(length <= index) {
		Array_push(arr, NULL);
		length++;
	}

	Array_push(arr, data);
	return data;
}

/**
 * Get data from the nth element of the array
 *
 * @param Array * arr
 * @param int index
 *
 * @return pointer
 */
pointer Array_get(Array * arr, int index) {
	Array * item = Array_nth(arr, index);

	if( item == NULL ) {
		return NULL;
	}

	return item->data;
}

/**
 * Pops the last element of the array and returns it
 *
 * @param Array * arr
 *
 * @return Array *
 */
Array * Array_pop(Array * arr) {
	Array * penultimate = Array_nth(arr, -2);
	Array * last = penultimate->next;

	penultimate->next = NULL;

	return last;
}

/**
 * Removes the first element from the array and returns it
 *
 * @param Array * arr
 *
 * @return Array *
 */
Array * Array_shift(Array * arr) {
	Array * first = arr;
	arr = arr->next;

	return_null_if(first == NULL);

	first->next = NULL;

	return first;
}

/**
 * Insert an element in the first position
 *
 * @param Array * arr
 * @param pointer data
 *
 * @return Array *
 */
Array * Array_unshift(Array * arr, pointer data) {
	Array * item = newArray(data);
	item->next = arr;
	return item;
}

/**
 * Concat two arrays
 *
 * @param Array * arr1
 * @param Array * arr2
 *
 * @return Array *
 */
Array * Array_concat(Array * arr1, Array * arr2) {

	return_null_if(arr1 == NULL || arr2 == NULL);

	Array_last(arr1)->next = arr2;
	return arr1;
}

/**
 * Check if element is in array
 *
 * @param Array * arr
 * @param pointer data
 *
 * @return int -1 in error, index in success
 * NOTE: This performs strict pointer comparison
 */
int Array_contains(Array * arr, pointer data) {
	size_t len = Array_length(arr),
		i = 0;
	for(; i < len; i++) {
		if( Array_get(arr, i) == data ) {
			return i;
		}
	}
	return -1;
}

/**
 * Loop through each array element data, calling callback
 *
 * @param Array * arr
 * @param void (* callback)(pointer, size_t) a function that receives the data and the index
 */
void Array_forEach(Array * arr, void (* callback)(pointer, size_t)) {
	Array * current = arr;
	size_t i = 0;

	return_if(arr == NULL);

	do {
		callback(current->data, i++);
	} while((current = current->next));
}

/**
 * Loop through each array element, calling callback
 *
 * @param Array * arr
 * @param void (* callback)(Array *, size_t) a function that receives the data and the index
 */
void Array_forEachItem(Array * arr, void (* callback)(Array *, size_t)) {
	Array * current = arr;
	size_t i = 0;

	return_if(arr == NULL);

	do {
		callback(current, i++);
	} while((current = current->next));
}

/**
 * Free memory function for iteration
 *
 * @param Array * item
 * @param size_t index
 */
void Array_free(Array * item, size_t index) {
	// should we clean data?
	free(item->data);
	free(item);
}

/**
 * Remove an array with all its items
 *
 * @param Array * arr
 */
void Array_destroy(Array * arr) {
	Array_forEachItem(arr, Array_free);
}
