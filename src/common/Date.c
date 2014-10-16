#include "Date.h"

/**
 * Get a Date object with current time
 *
 * @return Date *
 */
Date * newDate() {
	Date * ret;
	time_t t = time(NULL);

	return_null_if(t == (time_t) -1);

	ret = (Date *) malloc(sizeof(Date));

	return_null_if(ret == NULL);

	*ret = *localtime(&t);

	return ret;
}

/**
 * Get a date from a string
 *
 * @param const char * str
 * @param const char * format
 *
 * @return Date *
 */
Date * Date__parse(const char * str, const char * format) {
	Date * ret = (Date *) malloc(sizeof(Date));

	return_null_if(ret == NULL);

	strptime(str, format, ret);

	mktime(ret);

	return ret;
}

/**
 * Get a date's time
 *
 * @param Date * self
 *
 * @return time_t
 */
time_t Date_getTime(Date * self) {
	return mktime(self);
}

/**
 * Set a date's time
 *
 * @param Date * self
 * @param time_t time
 *
 * @return Date *
 */
Date * Date_setTime(Date * self, time_t time) {

	*self = *localtime(&time);

	return self;
}

/**
 * Destroy a date
 *
 * @param Date * self
 */
void Date_destroy(Date * self) {
	free(self);
}

/**
 * Add interval to a date
 *
 * @param Date * self
 * @param int value
 * @param DateIntervalType interval_type
 *
 * @return Date *
 */
Date * Date_addInterval(Date * self, int value, DateIntervalType interval_type) {
	switch ( interval_type ) {
		case DATE_INTERVAL_TYPE_SECONDS:
			self->tm_sec += value;
			break;
		case DATE_INTERVAL_TYPE_DAYS:
			self->tm_mday += value;
			break;
		case DATE_INTERVAL_TYPE_MONTHS:
			self->tm_mon += value;
			break;
		case DATE_INTERVAL_TYPE_YEARS:
			self->tm_year += value;
			break;
	}


	mktime(self);

	return self;
}

/**
 * Return a date formatted
 *
 * @param Date * self
 * @param const char * format
 *
 * @return char *
 */
char * Date_formatted(Date * self, const char * format) {
	char * ret;

	return_null_if(self == NULL);

	ret = (char *) malloc(DATE_FORMATTED_MAX_LENGTH /* * sizeof(char) */);

	// If size was exceeded
	return_null_if(strftime(ret, DATE_FORMATTED_MAX_LENGTH, format, self) == 0);

	return ret;
}
