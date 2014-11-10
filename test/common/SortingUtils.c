#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/SortingUtils.h"
#include "../common/SortingUtils.c"

void print(int ** l, size_t length) {
	size_t i;
	printf("{");

	printf("%d", *l[0]);
	for ( i = 1; i < length; i++) {
		printf(", %d", *l[i]);
	}

	printf("}\n");	
}

#define TEST_SORTING(fn) do { \
	list = malloc(length * sizeof(int *)); \
	memcpy(list, original_list, length * sizeof(int *)); \
	fn((void **) list, length, SortingUtils__INT_DESCENDING, NULL); \
	printf("%s\n", #fn); \
	print(list, length); \
	free(list); \
} while (0)

int main() {
	int l[] = {1,4,5,6,2,1,54,3};
	size_t length = sizeof(l) / sizeof(l[0]);
	size_t i = 0;
	int ** original_list = malloc(length * sizeof(int *));
	int ** list;

	for (; i < length; i++) {
		original_list[i] = &l[i];
	}

	print(original_list, length);

	TEST_SORTING(SortingUtils__bubbleSort);	
	TEST_SORTING(SortingUtils__selectSort);	
	TEST_SORTING(SortingUtils__insertSort);	
	TEST_SORTING(SortingUtils__quickSort);	

	return 0;
};
