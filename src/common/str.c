#include "str.h"
#include "array.h"
#include "rand.h"

/**
 * Clone a string
 *
 * @param const char * str
 *
 * @return char *
 */
char * str_clone(const char * str) {
	size_t size = strlen(str) + 1;
	char * ret = (char *) malloc(size);

	return_val_if(ret == NULL, NULL);

	memcpy(ret, str, size);

	return ret;
}

/**
 * Get an empty string
 *
 * @return char *
 */
char * str_empty() {
	char * ret = (char *) calloc(1, sizeof(char));

	return_val_if(ret == NULL, NULL);

	return ret;
}

/**
 * Concat two strings
 *
 * @param const char * str1
 * @param const char * str2
 *
 * @return char *
 */
char * str_concat(const char * str1, const char * str2) {
	size_t
		str1_length = strlen(str1),
		str2_length = strlen(str2);
	char * ret = (char *) malloc(str1_length + str2_length + 1);

	memcpy(ret, str1, str1_length);
	memcpy(ret + str1_length, str2, str2_length + 1);

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
 * Count occurrences of a substring
 *
 * @param const char * str
 * @param const char * substr
 *
 * @return size_t
 */
size_t str_strcount(const char * str, const char * substr) {
	size_t
		substr_length = strlen(substr),
		occurrences = 0;
	const char * occurrence = str;

	while( (occurrence = strstr(occurrence, substr)) != NULL ) {
		occurrences++;
		occurrence += substr_length;
	}

	return occurrences;
}

/**
 * Get a substring of `length` chars that goes for position `start`
 *
 * @param const char * str
 * @param const size_t start
 * @param const size_t length
 */
char * substr_raw(const char * str, const size_t start, const size_t length) {
	char * ret;
	size_t i;

	return_null_if(strlen(str) < (length + start));

	ret = (char *) malloc(length + 1);

	ret[length] = '\0';

	for(i = 0; i < length; i++) {
		ret[i] = str[start + i];
	}

	return ret;
}

/**
 * Replaces one string with another string
 * NOTE: returns a new string
 *
 * @param const char * str
 * @param const char * oldstr
 * @param const char * newstr
 *
 * @return char *
 */
char * str_replace(const char * str, const char * oldstr, const char * newstr) {
	char * ret;
	const char * occurrence = str;
	ptrdiff_t positions;
	size_t
		old_length = strlen(oldstr),
		new_length = strlen(newstr),
		str_length = strlen(str),
		length_diff = new_length - old_length;
	size_t
		occurrences,
		retlen;

	if (old_length != new_length) {
		occurrences = str_strcount(str, oldstr);

		// Nothing to replace, just make a new string
		if( occurrences == 0 ) {
			return str_clone(str);
		}

		retlen = str_length + occurrences * length_diff;
	} else {
		retlen = str_length;
	}

	ret = (char *) malloc(retlen + 1);

	return_null_if(ret == NULL);

	occurrences = 0;
	positions = 0;

	while( (occurrence = strstr(occurrence, oldstr)) != NULL ) {
		// we copy everything until occurrence
		// in `positions` we have the distance to the last substring + old_length, so we have to copy from str + positions to
		memcpy(ret + positions + occurrences * length_diff, str + positions, occurrence - str - positions);

		// we copy the new string in the position of the old one
		positions = occurrence - str;
		memcpy(ret + positions + occurrences * length_diff, newstr, new_length);
		occurrence += old_length;
		occurrences++;
		positions += old_length;
	}


	// Copy the rest of the string. str_length + 1 ensures that the last char gets copied
	// the same than strcpy(ret + positions + occurrences * length_diff, str + positions)
	// and the same than memcpy(ret + positions + occurrences * length_diff, str + positions, strlen(str + positions) + 1);
	memcpy(ret + positions + occurrences * length_diff, str + positions, str_length - positions + 1);

	return ret;
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
		positions = 0,
		i = 0;

	while ( str[i++] == c && i < length ) {
		positions++;
	}

	if ( positions ) {
		memmove(str, str + positions, length - positions + 1);
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
	size_t positions = 0;

	while (isspace(str[0])) {
		positions++;
	}

	while (isspace(str[last])) {
		last--;
	}

	str[last + 1] = '\0';

	if( positions ) {
		memmove(str, str + positions, last + 1 - positions + 1);
	}

	return str;
}

/**
 * Splits string into multiple strings delimited by separator
 *
 * TODO: optimize, and avoid passing length by reference:
 *       (use `Array`?)
 * NOTE: `str` gets modified, so clone if neccesary
 *
 * @param char * str
 * @param const char * separator
 * @param size_t * ret_length
 *
 * @return char **
 */
char ** str_split(char * str, const char * separator, size_t * ret_length) {
	char ** ret;
	char * temp;
	char * token;
	size_t i = 0;

	return_null_if(str == NULL);
	return_null_if(separator == NULL);

	temp = str;
	*ret_length = 1; // even if string is empty, there's at least one token (the whole string)

	// First we count the number of substrings
	while((temp = strstr(temp, separator))) {
		(*ret_length)++;
		temp++;
	}

	ret = (char **) malloc(sizeof(char *) * (*ret_length));

	return_null_if(ret == NULL);

	token = strtok(str, separator);

	while(token != NULL) {
		ret[i++] = token;
		token = strtok(NULL, separator);
	}

	return ret;
}

#ifdef __ARRAY_STRUCT_H
/**
 * Splits string into multiple strings delimited by separator
 *
 * @param char * str
 * @param const char * separator
 *
 * @return Array *
 */
Array * str_split_array(char * str, const char * separator) {
	Array * ret;
	char * token;

	return_null_if(str == NULL);
	return_null_if(separator == NULL);

	ret = newArray();

	return_null_if(ret == NULL);

	token = strtok(str, separator);

	while(token != NULL) {
		Array_push(ret, token);
		token = strtok(NULL, separator);
	}

	return ret;
}
#endif

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
	static char word_separators[] = {'\0', ',', '.' /*, '?', '!'*/};
	static size_t word_separators_length = 0;

	if( word_separators_length == 0 ) {
		word_separators_length = sizeof(word_separators) /* / sizeof(char) */;
	}

	return (isspace(c) || (in_char_array(word_separators, word_separators_length, c) != -1));
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
		length,
		count = 0;

	// Return 0 and warn if `str` isn't a valid string
	return_val_if(str == NULL, count);

	length = strlen(str);
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
