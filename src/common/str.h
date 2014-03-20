#ifndef __STR_H
#define __STR_H
/**
 * Functions to work with strings
 *
 * @author Emilio Cobos <emiliocobos@usal.es>
 */
#include <string.h>

#define STR_ALPHA_UPPER_MIN 65
#define STR_ALPHA_UPPER_MAX 90

#define STR_ALPHA_LOWER_MIN 97
#define STR_ALPHA_LOWER_MAX 122

#define STR_ASCII_MIN 32
#define STR_ASCII_MAX 126

enum str_random_type {
	STR_RANDOM_ALPHA_UPPER,
	STR_RANDOM_ALPHA_LOWER,
	// STR_RANDOM_ALPHA_SPACE,
	STR_RANDOM_ASCII
};

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
char * str_replace(const char * str, const char * oldstr, const char * newstr);

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

#define str_alloc_from(str) ((char *) malloc(strlen(str) + 1))

/**
 * Clone a string
 *
 * @param const char * str
 *
 * @return char *
 */
char * str_clone(const char * str);

/**
 * Turn string to lowercase
 *
 * NOTE:
 *   This function modifies the string passed itself
 *   If you want to get a new string you should use str_toupper(str_clone(str))
 *
 * @param char * str
 *
 * @return char * str
 */
char * str_toupper(char * str);

/**
 * Turn string to lowercase
 *
 * NOTE:
 *   This function modifies the string passed itself
 *   If you want to get a new string you should use str_tolower(str_clone(str))
 *
 * @param char * str
 *
 * @return char * str
 */
char * str_tolower(char * str);

/**
 * Turn string to camelcase
 *
 * @param char * str the string to be converted
 * @param const char separator the character as separator
 *
 * @see str_removechar()
 *
 * @return char * str
 */
char * str_tocamel(char * str, const char separator);

/**
 * Replace a character with another one
 *
 * @param char * str
 * @param const char what
 * @param const char with
 *
 * @return char * str
 */
char * str_replacec(char *str, const char what, const char with);

/**
 * Removes all ocurrences of a character
 *
 * @param char * str
 * @param const char car
 *
 * @return char * str
 */
char * str_removechar(char *str, const char car);


/**
 * Removes the \s character from a string
 *
 * @see str_removechar()
 *
 * @param const char * str
 *
 * @return char * str
 */
char * str_removewhitespace(char * str);

/**
 * Trims all ocurrences of a character from the right
 *
 * @param char * str
 * @param const char c
 *
 * @return char * str
 */
char * str_trimcharright(char *str, const char c);
/**
 * Trims all ocurrences of a character from the left
 *
 * @param char * str
 * @param const char c
 *
 * @return char * str
 */
char * str_trimcharleft(char * str, const char c);

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
char * str_trimchar(char * str, const char c);

/**
 * Trims whitespace from the right
 *
 * @see str_trimcharright()
 *
 * @param char * str
 *
 * @return char * str
 */
char * str_trimrigth(char * str);

/**
 * Trims whitespace from the left
 *
 * @see str_trimcharleft()
 *
 * @param char * str
 *
 * @return char * str
 */
char * str_trimleft(char *str);

/**
 * Trims whitespace from both sides
 *
 * @see str_trimchar()
 *
 * @param char * str
 *
 * @return char * str
 */
char * str_trim(char * str);

/**
 * Remove different kinds of whitespace from both sides of the string
 *
 * @param char * str
 *
 * @return char * str
 */
char * str_strip(char * str);


/**
 * Get a random string
 *
 * @param char * dest
 * @param size_t length
 * @param enum str_random_type type
 *
 * @return char * dest
 */
char * str_random(char * dest, size_t length, enum str_random_type type);
#endif
