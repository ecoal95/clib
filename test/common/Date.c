
#define __LIB_AUTO_INCLUDE 1
#define __LIB_JUST_CORE 1

#include "../minunit.h"
#include "../../src/lib.h"
#include "../../src/common/Date.c"

int tests_run = 0;

static char * TEST_Date() {
	Date * date = newDate();
	time_t t = time(NULL);
	Date d = *localtime(&t);

	Date_setTime(date, t);

	mu_assert("ERROR: something went wrong", Date_getTime(date) == t);

	free(date);
	return 0;
}

static char * TEST_Date__parse() {
	Date * date = newDate();
	char * formatted = Date_formatted(date, DATETIME_FORMAT_ISO);
	char * d_formatted;
	Date * d = Date__parse(formatted, DATETIME_FORMAT_ISO);

	printf("%zu | %s\n%zu | %s\n",
		Date_getTime(date),
		formatted,
		Date_getTime(d),
		d_formatted = Date_formatted(d, DATETIME_FORMAT_ISO));

	mu_assert("ERROR: parsing failed", Date_getTime(date) == Date_getTime(d));

	free(date);
	free(d);
	free(formatted);

	return 0;
}

static char * all_tests() {
	mu_run_test(TEST_Date);
	mu_run_test(TEST_Date__parse);
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
