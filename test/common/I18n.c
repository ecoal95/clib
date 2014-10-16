
#define __LIB_AUTO_INCLUDE 1

#include "../minunit.h"
#include "../../src/lib.h"

int tests_run = 0;

static char * TEST_I18n__t() {
	I18n__setLocale("es");
	I18n__setPath("translations/");

	mu_assert("something is not right...", strcmp(I18n__t("hello"), "hola!") == 0);
	printf("%s\n", I18n__t("bye"));

	I18n__destroy();

	return 0;

}

static char * all_tests() {
	mu_run_test(TEST_I18n__t);
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
