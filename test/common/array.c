
#define __LIB_AUTO_INCLUDE 1
#define __LIB_JUST_CORE 1

#include "../minunit.h"
#include "../../src/lib.h"
#include "../../src/common/str.c"
#include "../../src/common/array.c"

int tests_run = 0;

static char * TEST_array_clone() {
	int arr1[] = {1, 2, 3, 4};
	int * clone = (int *) array_clone(arr1);
	size_t i = 0,
		length = array_length(arr1);

	for(; i < length; i++) {
		mu_assert("ERROR: different values", arr1[i] == clone[i]);
	}
	return 0;
}

static char * TEST_array_concat() {
	int arr1[] = {1, 2, 3, 4};
	int arr2[] = {5, 6, 7, 8};
	int * concat;

	concat = array_concat(arr1, arr2);

	mu_assert("ERROR: concat failed", concat[4] == arr2[0]);
	return 0;
}

static char * TEST_array_revert() {
	int arr1[] = {1, 2, 3, 4};
	int * clone = array_clone(arr1);
	size_t
		i = 0,
		length = array_length(arr1);

	array_revert(clone, length);

	for(; i < length; i++) {
		mu_assert("ERROR: reverse failed", arr1[i] == clone[length - i - 1]);
	}
	return 0;
}

static char * all_tests() {
	mu_run_test(TEST_array_clone);
	mu_run_test(TEST_array_concat);
	mu_run_test(TEST_array_revert);
	return 0;
}


int main() {
	char *result = all_tests();
	if (result != 0) {
		printf("%s\n", result);
	} else {
		printf("ALL TESTS PASSED\n");
	}
	printf("Tests run: %d\n", tests_run);
	return 0;
}
