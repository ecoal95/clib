#ifndef __DATE_H
#define __DATE_H
/**
 * La función de los romanos es casi más de la biblioteca de las fechas pero bueno...
 * En vez de hacer un void retornamos la cadena
 */
const char ROMAN_LETTERS[][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
const size_t ROMAN_LENGTH = 13;
const int ROMAN_VALUES[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
char * date_toRoman(unsigned int year) {
	// Longitud de la cadena
	size_t i = 0,
		j = 0;
	char *ret = (char*)malloc(16 * sizeof(char));
	ret[0] = '\0';// ret vacío

	// La longitud máxima de un número romano son unos 15...
	if( year > 3999 ) {
		return NULL;
	}
	for( ; i < ROMAN_LENGTH; i++ ) {
		while(year >= ROMAN_VALUES[i]) {
			// printf("%i\n", year);
			strcat(ret, ROMAN_LETTERS[i]);
			year -= ROMAN_VALUES[i];
		}
	}

	return ret;
}

#endif
