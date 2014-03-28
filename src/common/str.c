#include "str.h"

/**
 * Replaces one string with another string
 * NOTE: returns a new string
 * http://creativeandcritical.net/str-replace-c/
 *
 * @param const char * str
 * @param const char * oldstr
 * @param const char * newstr
 *
 * @return char *
 */
char * str_replace(const char * str, const char * oldstr, const char * newstr) {
	char *ret, *r;
	const char *p, *q;
	size_t oldlen = strlen(oldstr);
	size_t count, retlen, newlen = strlen(newstr);

	if (oldlen != newlen) {
		for (count = 0, p = str; (q = strstr(p, oldstr)) != NULL; p = q + oldlen)
			count++;
		/* this is undefined if p - str > PTRDIFF_MAX */
		retlen = p - str + strlen(p) + count * (newlen - oldlen);
	} else {
		retlen = strlen(str);
	}

	if ((ret = (char*) (char *) malloc((retlen + 1) * sizeof (char))) == NULL)
		return NULL;

	for (r = ret, p = str; (q = strstr(p, oldstr)) != NULL; p = q + oldlen) {
		/* this is undefined if q - p > PTRDIFF_MAX */
		ptrdiff_t l = q - p;
		memcpy(r, p, l);
		r += l;
		memcpy(r, newstr, newlen);
		r += newlen;
	}
	strcpy(r, p);

	return ret;
}

/**
 * Alloc enough space in memory for a clone of str
 *
 * @param const char * str
 *
 * @return char *
 */
// char * str_alloc_from(const char * str) {
// 	return (char *) malloc(strlen(str) + 1);
// }

/**
 * Clone a string
 *
 * @param const char * str
 *
 * @return char *
 */
char * str_clone(const char * str) {
	char * ret = str_alloc_from(str);
	strcpy(ret, str);
	return ret;
}

/**
 * Turn string to lowercase
 *
 * NOTE:
 *   This function modifies the char * passed itself
 *   If you want to get a new char * you should use str_toupper(str_clone(str))
 *
 * @param char * str
 *
 * @return char * str
 */
char * str_toupper(char * str) {
	size_t length = strlen(str),
		i = 0;

	for(; i < length ; i++) {
		str[i] = toupper(str[i]);
	}
	return str;
}

/**
 * Turn string to lowercase
 *
 * NOTE:
 *   This function modifies the char * passed itself
 *   If you want to get a new char * you should use str_tolower(str_clone(str))
 *
 * @param char * str
 *
 * @return char * str
 */
char * str_tolower(char * str) {
	size_t length = strlen(str),
		i = 0;
	for(; i < length; i++) {
		str[i] = tolower(str[i]);
	}
	return str;
}

/**
 * Turn string to camelcase
 *
 * @param char * str the char * to be converted
 * @param const char separator the character as separator
 *
 * @see str_removechar()
 *
 * @return char * str
 */
char * str_tocamel(char * str, const char separator) {
	size_t i = 0,
		length = strlen(str);
	str_tolower(str);
	for(; i < length; i++) {
		if( str[i] == separator ) {
			str[i + 1] = toupper(str[i + 1]);
		}
	}
	return str_removechar(str, separator);
}

/**
 * Replace a character with another one
 *
 * @param char * str
 * @param const char what
 * @param const char with
 *
 * @return char * str
 */
char * str_replacec(char *str, const char what, const char with) {
	size_t length = strlen(str),
		i = 0;

	for(; i < length; i++) {
		if( str[i] == what ) {
			str[i] = with;
		}
	}
	return str;
}

/**
 * Removes all ocurrences of a character
 *
 * @param char * str
 * @param const char car
 *
 * @return char * str
 */
char * str_removechar(char *str, const char car) {
	size_t i = 0,
		// J lo usaremos para incrementar la posición de la cadena si encontramos el caracter
		j = 0;

	for( ; str[i] != '\0'; i++) {
		if( str[i] == car ) {
			j++;
		}

		str[i] = str[i + j];

		if( str[i] == car ) {
			i--;
		}
	}
	return str;
}


/**
 * Removes the \s character from a string
 *
 * @see str_removechar()
 *
 * @param const char * str
 *
 * @return char * str
 */
char * str_removewhitespace(char * str) {
	return str_removechar(str, ' ');
}

/**
 * Trims all ocurrences of a character from the right
 *
 * @param char * str
 * @param const char c
 *
 * @return char * str
 */
char * str_trimcharright(char *str, const char c) {
	size_t i = strlen(str);
	while( str[--i] == c ) {
		str[i] = '\0';
	}
	return str;
}

/**
 * Trims all ocurrences of a character from the left
 *
 * @param char * str
 * @param const char c
 *
 * @return char * str
 */
char * str_trimcharleft(char * str, const char c) {
	size_t length = strlen(str),
		i = 0;

	while( str[i++] == c && i < length ) {
		str++;
	}
	return str;
}

/**
 * Trims all ocurrences of a character from both sides
 *
 * @see str_trimcharleft()
 * @see str_trimcharright()
 *
 * @param char * str
 * @param const char c
 *
 * @return char * str
 */
char * str_trimchar(char * str, const char c) {
	return str_trimcharright(str_trimcharleft(str, c), c);
}

/**
 * Trims whitespace from the right
 *
 * @see str_trimcharright()
 *
 * @param char * str
 *
 * @return char * str
 */
char * str_trimrigth(char * str) {
	return str_trimcharright(str, ' ');
}

/**
 * Trims whitespace from the left
 *
 * @see str_trimcharleft()
 *
 * @param char * str
 *
 * @return char * str
 */
char * str_trimleft(char *str) {
	return str_trimcharleft(str, ' ');
}

/**
 * Trims whitespace from both sides
 *
 * @see str_trimchar()
 *
 * @param char * str
 *
 * @return char * str
 */
char * str_trim(char * str) {
	return str_trimchar(str, ' ');
}

/**
 * Remove different kinds of whitespace from both sides of the string
 *
 * @param char * str
 *
 * @return char * str
 */
char * str_strip(char * str) {
	size_t last = strlen(str) - 1;

	while (str[0] == ' ' || str[0] == '\n' || str[0] == '\t') {
		str++;
	}

	while (str[last] == ' ' || str[last] == '\n' || str[last] == '\n' ) {
		last--;
	}

	str[last + 1] = '\0';

	return str;
}


/**
 * Get a random string
 *
 * @param char * dest
 * @param size_t length
 * @param enum str_random_type type
 *
 * @return char * dest
 */
char * str_random(char * dest, size_t length, enum str_random_type type) {
	size_t i = 0;
	int min, max;
	// Rellenaremos todos los caracteres menos el último, que pondremos a \0
	length--;
	switch (type) {
		case STR_RANDOM_ALPHA_UPPER:
			min = STR_ALPHA_UPPER_MIN;
			max = STR_ALPHA_UPPER_MAX;
			break;
		case STR_RANDOM_ALPHA_LOWER:
			min = STR_ALPHA_LOWER_MIN;
			max = STR_ALPHA_LOWER_MAX;
			break;
		case STR_RANDOM_ASCII:
			min = STR_ASCII_MIN;
			max = STR_ASCII_MAX;
			break;
		default:
			return dest;
	}
	for(; i < length; i++) {
		dest[i] = rand_in_range(min, max);
	}
	dest[length] = '\0';
	return dest;
}

/**
 * Check if char belongs to STR_WORD_SEPARATORS
 *
 * @param const char a
 *
 * @return boolean
 */
boolean is_word_separator(const char c) {
	static char word_separators[] = {' ', '\n', '\r', '\t', '\0', ',', '.' /*, '?', '!'*/};
	static size_t word_separators_length = 0;

	if( word_separators_length == 0 ) {
		word_separators_length = sizeof(word_separators) /* / sizeof(char) */;
	}

	return (in_char_array(word_separators, word_separators_length, c) != -1);
}


/**
 * Counts the number of words in string and returns it
 *
 * @param const char * str
 *
 * @return size_t
 */
size_t str_wordcount(const char * str) {
	size_t
		i = 0,
		length = strlen(str),
		count = 0;
	// we can assume a word if the first char is not a separator
	if( ! is_word_separator(str[0]) ) {
		count++;
	}
	for(; i < length; i++) {
		// If the current character is a word separator and the next one isn't, we increment the word count
		if( is_word_separator(str[i]) && ! is_word_separator(str[i + 1]) ) {
				count++;
		}
	}
	return count;
}
