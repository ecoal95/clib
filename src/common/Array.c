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
	Array * item = arr;

	if( index < 0 ) {
		index += length;
	}

	return_null_if(index >= length || index < 0);

	while(index--) {
		item = item->next;
	}

	return item;
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
	Array * last;

	return_null_if(item == NULL);

	last = Array_last(arr);

	return_null_if(last == NULL);

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

	return_null_if(item == NULL);

	return item->data;
}

/**
 * Removes the last element of the array and returns the array
 *
 * @param Array * arr
 *
 * @return Array *
 */
Array * Array_pop(Array * arr) {
	Array * penultimate = Array_nth(arr, -2);

	Array_free(penultimate->next);

	penultimate->next = NULL;

	return arr;
}

/**
 * Removes the first element from the array and returns the new array
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

	return arr;
}

/**
 * Insert an element in the first position and return the new array
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
 * Delete a single element from array
 *
 * @param Array * arr
 * @param int index
 *
 * @return Array * the new array
 */
Array * Array_delete(Array * arr, int index) {
	Array * element;
	if( index == 0 ) {
		return Array_shift(arr);
	}

	element = Array_nth(arr, index);

	Array_nth(arr, index - 1)->next = element->next;

	Array_free(element);

	return arr;
}

/**
 * Removes elements from an array and returns the new array
 *
 * @param int index starting item
 * @param size_t elements number of elements to remove
 *
 * @return Array * arr
 */
Array * Array_splice(Array * arr, int index, size_t elements) {
	size_t length = Array_length(arr),
		i;
	Array * prev;
	Array * last_removed_element;

	// TODO: allow negative index
	return_val_if(index > length, arr);
	return_val_if(elements + index > length, arr);

	if( index == 0 ) {
		for(i = 0; i < elements; i++) {
			arr = Array_shift(arr);
		}
		return arr;
	}

	prev = Array_nth(arr, index - 1);

	return_val_if(prev == NULL, arr);

	last_removed_element = Array_nth(arr, index + elements - 1);


	i = elements - 1; // want to keep the last one
	while(i--) {
		Array_free(Array_nth(arr, index + i));
	}

	prev->next = last_removed_element->next;

	Array_free(last_removed_element);

	return arr;
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
 * Free an element memory
 *
 * @param Array * item
 *
 * @return void
 */
void Array_free(Array * item) {
	// NOTE: should we clean data?
	free(item->data);
	free(item);
}

/**
 * Free memory function for iteration
 *
 * @param Array * item
 * @param size_t index
 *
 * @return void
 */
void Array_free_1(Array * item, size_t index) {
	Array_free(item);
}

/**
 * Remove an array with all its items
 *
 * @param Array * arr
 *
 * @return void
 */
void Array_destroy(Array * arr) {
	Array_forEachItem(arr, Array_free_1);
}
