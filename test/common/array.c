#define __LIB_AUTO_INCLUDE 1
// #define __LIB_JUST_CORE 0

#include "../../src/lib.h"
#include "../../src/common/array.h"

int main() {
	int arr1[] = {1, 2, 3, 4};
	int arr2[] = {5, 6, 7, 8};
	int * concat;
	size_t length =  array_length(arr1) + array_length(arr2);
	int element = 4;

	concat = array_concat(arr1, arr2);

	array_print_int(concat, length);
	printf("\n");

	array_revert(concat, length);

	array_print_int(concat, length);
	printf("\n");

	printf("%d | %d\n", in_array(arr1, &element), in_array(concat, length, &element));
	printf("%d | %d\n", in_int_array(arr1, array_length(arr1), 4), in_int_array(concat, length, 4));
	return 0;
}
