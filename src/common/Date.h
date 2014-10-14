#ifndef __DATE_H
#define __DATE_H

CPP_START
#include "../core/core.h"

#include <time.h>

#define DATE_FORMAT_ISO "%F"
#define TIME_FORMAT_ISO "%T"
#define DATETIME_FORMAT_ISO "%F %T %z"

typedef struct tm Date;

/** Max length for formatted dates */
#ifndef DATE_FORMATTED_MAX_LENGTH
#define DATE_FORMATTED_MAX_LENGTH 50
#endif


/**
 * Get a Date object with current time
 *
 * @return Date *
 */
Date * newDate();

/**
 * Get a date from a string
 *
 * @param const char * str
 *
 * @return Date *
 */
Date * Date__parse(const char * str);

/**
 * Get a date's time
 *
 * @param Date * self
 *
 * @return time_t
 */
time_t Date_getTime(Date * self);

/**
 * Set a date's time
 *
 * @param Date * self
 * @param time_t time
 *
 * @return Date *
 */
Date * Date_setTime(Date * self, time_t time);

/** Interval types */
typedef enum DateIntervalType {
	DATE_INTERVAL_TYPE_SECONDS,
	DATE_INTERVAL_TYPE_DAYS,
	DATE_INTERVAL_TYPE_MONTHS,
	DATE_INTERVAL_TYPE_YEARS
} DateIntervalType;

/**
 * Add interval to a date
 *
 * @param Date * self
 * @param int value
 * @param DateIntervalType interval_type
 *
 * @return Date *
 */
Date * Date_addInterval(Date * self, int value, DateIntervalType interval_type);

/**
 * Return a date formatted
 *
 * @param Date * self
 * @param const char * format
 *
 * @return char *
 */
char * Date_formatted(Date * self, const char * format);

CPP_END

#endif
