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
	ret->last = NULL;
	ret->length = 0;

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

	if( arr->last == NULL ) {
		arr->items = arr->last = newArrayItem(data);
		arr->length++;
		return arr;
	}

	// debugging purposes
	return_null_if(arr->last->next != NULL);

	arr->last->next = newArrayItem(data);
	arr->last = arr->last->next;
	arr->length++;

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
	while(arr->length <= index) {
		Array_push(arr, NULL);
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
	ArrayItem * penultimate;
	pointer ret;

	return_null_if(arr == NULL);

	// trying to pop from empty array
	return_null_if(arr->length == 0);

	if ( arr->length == 1 ) {
		ret = ArrayItem_free(arr->items, FALSE);

		arr->items = NULL;
		arr->length = 0;

		return ret;
	}

	penultimate = Array_nth(arr, -2);

	ret = ArrayItem_free(penultimate->next, FALSE);

	penultimate->next = NULL;
	arr->length--;

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
	arr->length--;

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

	arr->length++;

	return arr->length;
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
	ArrayItem * element,
		prev;

	return_null_if(arr == NULL);

	element = Array_nth(arr, index);

	// TODO: Check for negative index to the first element, which wont work
	if( index == 0 || index == - ((int) arr->length) ) {
		arr->items = element->next;
		// Element was last
		if ( element->next == NULL ) {
			arr->last = NULL;
		}
	} else {
		prev = Array_nth(arr, index - 1);

		prev->next = element->next;

		if ( element->next == NULL ) {
			arr->last = prev;
		}
	}

	arr->length--;

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
	size_t i;
	ArrayItem * prev;
	ArrayItem * last_removed_element;

	return_val_if(arr == NULL, 0);


	// this allows negative index
	if( index < 0 ) {
		index += arr->length;
	}

	return_val_if(index >= arr->length, arr->length);
	return_val_if(elements + index > arr->length, arr->length);

	if( index == 0 ) {
		for(i = 0; i < elements; i++) {
			Array_delete(arr, 0, with_data);
		}
		arr->length -= elements;
		return arr->length;
	}

	prev = Array_nth(arr, index - 1);

	return_val_if(prev == NULL, arr->length);

	last_removed_element = Array_nth(arr, index + elements - 1);


	i = elements - 1; // want to keep the last one

	// TODO: optimize
	while(i--) {
		ArrayItem_free(Array_nth(arr, index + i), with_data);
	}

	prev->next = last_removed_element->next;
	arr->length -= elements;
	
	// If removed the last element
	if ( prev->next == NULL ) {
		arr->last = prev;
	}

	ArrayItem_free(last_removed_element, with_data);


	return arr->length;
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
	arr1->last->next = arr2->items;
	arr1->length += arr2->length;
	arr->last = arr2->last;

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
	size_t i = 0;
	pointer arr_data;

	return_val_if(arr == NULL, -1);

	ARRAY_EACH_WITH_INDEX(arr, arr_data, i,
		if ( arr_data == data ) {
			return i;
		}
	);

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
	pointer arr_data;
	size_t i = 0;

	return_if(arr == NULL);

	ARRAY_EACH_WITH_INDEX(arr, arr_data, i,
		callback(arr_data, i, data);
	);
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

	length = arr->length;

	// TODO: optimize, we must free reversing the order...
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

	length = arr->length;

	for(i = 0; i < length; i++) {
		for(j = 0; j < length - i - 1; j++) {
			current_item = Array_nth(arr, j);
			compared_item = current_item->next;
			if( compfunc(current_item->data, compared_item->data) <= 0 ) {
				// Instead of swapping the whole element we just swap the data
				// This doesn't break arr->last, so even better
				temp_data = current_item->data;
				current_item->data = compared_item->data;
				compared_item->data = temp_data;
			}
		}
	}
}
