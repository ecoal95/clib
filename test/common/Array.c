
#define __LIB_AUTO_INCLUDE 1
#define __LIB_JUST_CORE 1

#include "../minunit.h"
#include "../../src/lib.h"
#include "../../src/common/Array.c"

int tests_run = 0;

static char * TEST_Array_push() {
	Array * arr = newArray();

	Array_push(arr, "Hola");
	Array_push(arr, "Mundo");


	mu_assert("ERROR: something went wrong", Array_length(arr) == 2);
	mu_assert("ERROR: different values", strcmp(Array_get(arr, 0), "Hola") == 0);
	mu_assert("ERROR: different values", strcmp(Array_get(arr, -1), "Mundo") == 0);
	return 0;
}

static char * all_tests() {
	mu_run_test(TEST_Array_push);
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
