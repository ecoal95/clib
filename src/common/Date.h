#ifndef __DATE_H
#define __DATE_H

#include <time.h>

typedef struct tm Date;

/**
 * Get a Date object with current time
 *
 * @return Date *
 */
Date * newDate() {
	time_t time = time(NULL);

	return_null_if(time == (time_t) -1);

	return localtime(&time);
}

/**
 * Get a date from a string
 *
 * @param const char * str
 *
 * @return Date *
 */
Date * Date__parse(const char * str) {
	return getdate(str);
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
	self->tm_sec = time;
	self->tm_mon = 0;
	self->tm_mday = 0;
	self->tm_year = 1970;

	mktime(self);

	return self;
}
#endif
