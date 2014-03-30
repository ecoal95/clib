
#define __LIB_AUTO_INCLUDE 1
#define __LIB_JUST_CORE 1

#include "../minunit.h"
#include "../../src/lib.h"
#include "../../src/common/str.c"
#include "../../src/common/array.c"

int tests_run = 0;

static char * TEST_str_strcount() {
	char str[] = "babcabb";
	mu_assert("ERROR: not expected result", str_strcount(str, "ab") == 2);
	return 0;
}

static char * TEST_str_replace() {
	char str[] = "Hola, pepe!";
	char * new_str = str_replace(str, "pepe", "mundo");
	mu_assert("ERROR: not expected result", strcmp(new_str, "Hola, mundo!") == 0);
	return 0;
}

static char * TEST_substr() {
	char str[] = "Hola, mundo!";

	mu_assert("ERROR: function keeps working", substr(str, 0, 100) == NULL);
	mu_assert("ERROR: something is wrong", strcmp(substr(str, 1, 2), "ol") == 0);
	mu_assert("ERROR: something is wrong", strcmp(substring(str, 1, 2), "o") == 0);
	mu_assert("ERROR: two parameters doesn't work", strcmp(substr(str, 1), "ola, mundo!") == 0);
	return 0;
}


static char * all_tests() {
	mu_run_test(TEST_str_strcount);
	mu_run_test(TEST_str_replace);
	mu_run_test(TEST_substr);
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
