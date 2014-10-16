#include "Array.h"

/**
 * Allocate a new array
 *
 * @return Array *
 */
Array * newArray() {
	Array * ret = (Array *) malloc(sizeof(Array));

	return_null_if(ret == NULL);

	ret->items = NULL;

	return ret;
}

/**
 * Clone an array
 *
 * @param Array * arr
 *
 * @return Array *
 */
Array * Array_clone(Array * arr) {
	Array * ret;
	ArrayItem * items;

	return_null_if(arr == NULL);

	ret = newArray();

	if( arr->items != NULL ) {
		items = arr->items;
		do {
			Array_push(ret, items->data);
		} while((items = items->next));
	}

	return ret;
}

/**
 * Allocate a new array item
 *
 * @param const pointer data
 *
 * @return ArrayItem *
 */
ArrayItem * newArrayItem(const pointer data) {
	ArrayItem * ret = (ArrayItem *) malloc(sizeof(ArrayItem));

	return_null_if(ret == NULL);

	ret->next = NULL;

	ret->data = data;

	return ret;
}

/**
 * Calculate the length of the array
 *
 * @param Array * array
 *
 * @return size_t
 */
size_t Array_length(Array * arr) {
	size_t length = 0;
	ArrayItem * items = arr->items;
	if ( items ) {
		do {
			length++;
		} while ( (items = items->next) );
	}
	return length;
}

/**
 * Get the nth element from the array, null if doesn't exist
 *
 * @param Array * arr
 * @param int index
 *
 * NOTE: we allow negative index
 *
 * @return ArrayItem *
 */
ArrayItem * Array_nth(Array * arr, int index) {
	size_t length;
	ArrayItem * items;

	return_null_if(arr == NULL);

	length = Array_length(arr);


	items = arr->items;

	// if in empty array
	return_null_if(items == NULL);

	if ( index < 0 ) {
		index += length;
	}

	return_null_if(index >= length || index < 0);

	while ( index-- ) {
		items = items->next;
	}

	return items;
}

/**
 * Push data into the array
 *
 * @param Array * arr
 * @param const pointer data
 *
 * @return Array *
 */
Array * Array_push(Array * arr, const pointer data) {

	return_null_if(arr == NULL);

	if( arr->items == NULL ) {
		arr->items = newArrayItem(data);
		return arr;
	}

	Array_last(arr)->next = newArrayItem(data);

	return arr;
}

/**
 * Set the data at given index. If element doesnt exists we add elements
 *
 * @param Array * arr
 * @param int index
 * @param const pointer data
 *
 * @return pointer data
 */
pointer Array_set(Array * arr, int index, const pointer data) {
	ArrayItem * item;
	size_t length;

	return_null_if(arr == NULL);

	item = Array_nth(arr, index);
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
	ArrayItem * item;

	return_null_if(arr == NULL);

	item = Array_nth(arr, index);

	return_null_if(item == NULL);

	return item->data;
}

/**
 * Removes the last element of the array and returns the data in it
 * NOTE: You must manually free the data in the returned pointer
 *
 * @param Array * arr
 *
 * @return pointer
 */
pointer Array_pop(Array * arr) {
	size_t length;
	ArrayItem * penultimate;
	pointer ret;

	return_null_if(arr == NULL);

	length = Array_length(arr);

	// trying to pop from empty array
	return_null_if(length == 0);

	if( length == 1 ) {
		ret = ArrayItem_free(arr->items, FALSE);

		arr->items = NULL;

		return ret;
	}

	penultimate = Array_nth(arr, -2);

	ret = ArrayItem_free(penultimate->next, FALSE);

	penultimate->next = NULL;

	return ret;
}

/**
 * Removes the first element from the array and returns the data in it
 *
 * @param Array * arr
 *
 * @return pointer
 */
pointer Array_shift(Array * arr) {
	ArrayItem * first;

	return_null_if(arr == NULL);

	first = arr->items;

	arr->items = arr->items->next;

	return ArrayItem_free(first, FALSE);
}

/**
 * Insert an element in the first position and return the length of the new array
 * TODO: do not return length and return another thing (for performance)
 *
 * @param Array * arr
 * @param const pointer data
 *
 * @return size_t
 */
size_t Array_unshift(Array * arr, const pointer data) {
	ArrayItem * item;

	return_val_if(arr == NULL, 0);

	item = newArrayItem(data);

	item->next = arr->items;

	arr->items = item;

	return Array_length(arr);
}

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
pointer Array_delete(Array * arr, int index, boolean with_data) {
	ArrayItem * element;

	return_null_if(arr == NULL);

	element = Array_nth(arr, index);

	// TODO: Check for negative index to the first element, which wont work
	if( index == 0 ) {
		arr->items = element->next;
	} else {
		Array_nth(arr, index - 1)->next = element->next;
	}

	return ArrayItem_free(element, with_data);
}

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
size_t Array_splice(Array * arr, int index, size_t elements, boolean with_data) {
	size_t length,
		i;
	ArrayItem * prev;
	ArrayItem * last_removed_element;

	return_val_if(arr == NULL, 0);

	length = Array_length(arr);

	// this allows negative index
	if( index < 0 ) {
		index += length;
	}

	return_val_if(index >= length, length);
	return_val_if(elements + index > length, length);

	if( index == 0 ) {
		for(i = 0; i < elements; i++) {
			Array_delete(arr, 0, with_data);
		}
		return length - elements;
	}

	prev = Array_nth(arr, index - 1);

	return_val_if(prev == NULL, length);

	last_removed_element = Array_nth(arr, index + elements - 1);


	i = elements - 1; // want to keep the last one
	while(i--) {
		ArrayItem_free(Array_nth(arr, index + i), with_data);
	}

	prev->next = last_removed_element->next;

	ArrayItem_free(last_removed_element, with_data);

	return length - elements;
}

/**
 * Concat two arrays, modifying the first one
 *
 * @param Array * arr1
 * @param Array * arr2
 *
 * @return Array * arr1
 */
Array * Array_concat(Array * arr1, Array * arr2) {
	Array_last(arr1)->next = arr2->items;

	return arr1;
}

/**
 * Check if element is in array
 *
 * @param Array * arr
 * @param const pointer data
 *
 * @return int -1 in error, index in success
 * NOTE: This performs strict pointer comparison
 */
int Array_contains(Array * arr, const pointer data) {
	size_t len,
		i = 0;

	return_val_if(arr == NULL, -1);

	len = Array_length(arr);
	for ( ; i < len; i++ ) {
		if ( Array_get(arr, i) == data ) {
			return i;
		}
	}
	return -1;
}

/**
 * Loop through each array element data, calling callback
 *
 * @param Array * arr
 * @param void (* callback)(pointer, size_t, pointer) a function that receives the data, the index and the custom data
 * @param pointer data
 */
void Array_forEach(Array * arr, void (* callback)(pointer, size_t, pointer), pointer data) {
	ArrayItem * items;
	size_t i = 0;

	return_if(arr == NULL);

	items = arr->items;

	if( items ) {
		do {
			callback(items->data, i++, data);
		} while((items = items->next));
	}
}

/**
 * Loop through each array element, calling callback
 *
 * @param Array * arr
 * @param void (* callback)(Array *, size_t) a function that receives the data and the index
 */
void Array_forEachItem(Array * arr, void (* callback)(ArrayItem *, size_t)) {
	ArrayItem * items;
	size_t i = 0;

	return_if(arr == NULL);

	items = arr->items;

	if( items ) {
		do {
			callback(items, i++);
		} while((items = items->next));
	}
}

/**
 * Free an element memory
 *
 * @param ArrayItem * item
 * @param boolean with_data
 *
 * @return pointer the data if with_data was TRUE
 */
pointer ArrayItem_free(ArrayItem * item, boolean with_data) {
	pointer data;

	return_null_if(item == NULL);

	data = item->data;

	if ( with_data && data != NULL ) {
		free(item->data);
		data = NULL;
	}

	free(item);

	return data;
}

/**
 * Remove an array with all its items
 *
 * @param Array * arr
 *
 * @return void
 */
void Array_destroy(Array * arr, boolean with_data) {
	size_t length;

	return_if(arr == NULL);

	length = Array_length(arr);

	while(length--) {
		ArrayItem_free(Array_nth(arr, length), with_data);
	}

	free(arr);
}


/**
 * Sorts the array using the bubble sort algo
 *
 * @param Array * arr
 * @param int (* compfunc) (pointer, pointer)
 *
 * @return void
 */
void Array_bsort(Array * arr, int (* compfunc)(pointer, pointer)) {
	size_t
		length,
		i,
		j;

	ArrayItem * current_item;
	ArrayItem * compared_item;
	pointer temp_data;

	return_if(arr == NULL);
	return_if(compfunc == NULL);

	length = Array_length(arr);

	for(i = 0; i < length; i++) {
		for(j = 0; j < length - i - 1; j++) {
			current_item = Array_nth(arr, j);
			compared_item = current_item->next;
			if( compfunc(current_item->data, compared_item->data) <= 0 ) {
				// Instead of swapping the whole element we just swap the data
				temp_data = current_item->data;
				current_item->data = compared_item->data;
				compared_item->data = temp_data;
			}
		}
	}
}
