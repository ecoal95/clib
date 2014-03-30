#ifndef __DATE_H
#define __DATE_H
#include "str.h"
/**
 * La función de los romanos es casi más de la biblioteca de las fechas pero bueno...
 * En vez de hacer un void retornamos la cadena
 */
char * date(const char * format, const time_t time) {
	struct tm * t;
	if( strcmp("c", format) == 0 ) {
		return ctime(time);
	}

	t = localtime(&time);


}

#endif
