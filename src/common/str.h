#ifndef __STR_H
#define __STR_H

CPP_START

#include "../core/core.h"
#include "array.h"

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
 * Count occurrences of a substring
 *
 * @param const char * str
 * @param const char * substr
 *
 * @return size_t
 */
size_t str_strcount(const char * str, const char * substr);

/**
 * Get a substring of `length` chars that goes for position `start`
 *
 * @param const char * str
 * @param const size_t start
 * @param const size_t length
 */
char * substr_raw(const char * str, const size_t start, const size_t length);
#define __substr_3(str, start, length) (substr_raw(str, start, length))
#define __substr_2(str, start) (substr_raw(str, start, strlen(str) - (start)))
#ifdef C99
#define substr(...) GET_VA_MACRO_3(__VA_ARGS__,  __substr_3, __substr_2)(__VA_ARGS__)
#else
#define substr(args...) GET_VA_MACRO_3(args, __substr_3, __substr_2)(args)
#endif
/**
 * Get a substring that goes for position `start` to position `end`
 */
#define substring_raw(str, start, end) (substr(str, start, end - start))
#define __substring_3(str, start, end) (substring_raw(str, start, end))
#define __substring_2(str, start) (substr(str, start))
#ifdef C99
#define substring(...) GET_VA_MACRO_3(__VA_ARGS__,  __substring_3, __substring_2)(__VA_ARGS__)
#else
#define substring(args...) GET_VA_MACRO_3(args, __substring_3, __substring_2)(args)
#endif

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
char * str_replace(const char * str, const char * oldstr, const char * newstr);

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

/**
 * Check if char belongs to STR_WORD_SEPARATORS
 *
 * @param const char a
 *
 * @return boolean
 */
boolean is_word_separator(const char a);

/**
 * Counts the number of words in string and returns it
 *
 * @param const char * str
 *
 * @return size_t
 */
size_t str_wordcount(const char * str);

/**
 * Parse a string to an int
 *
 * @see strtol()
 *
 * @param const char * string
 * @param char * end
 * @param int base
 *
 * @return long
 */
#define __parseInt_3(str, end, base) (strtol(str, end, base))
#define __parseInt_2(str, base) (strtol(str, NULL, base))
#define __parseInt_1(str) (strtol(str, NULL, 0))
#ifdef C99
#define parseInt(...) GET_VA_MACRO_3(__VA_ARGS__,  __parseInt_3, __parseInt_2, __parseInt_1)(__VA_ARGS__)
#else
#define parseInt(args...) GET_VA_MACRO_3(args, __parseInt_3, __parseInt_2, __parseInt_1)(args)
#endif

/**
 * Parse a string to an int
 *
 * @see strtol()
 *
 * @param const char * string
 * @param char * end
 *
 * @return double
 */
#define __parseFloat_2(str, end) (strtod(str, end))
#define __parseFloat_1(str) (strtod(str, NULL))
#ifdef C99
#define parseFloat(...) GET_VA_MACRO_2(__VA_ARGS__,  __parseInt_2, __parseInt_1)(__VA_ARGS__)
#else
#define parseFloat(args...) GET_VA_MACRO_2(args, __parseInt_2, __parseInt_1)(args)
#endif

/**
 * Alias for isnan()
 */
#define isNaN isnan

/**
 * Check if string has just numeric values
 *
 * @param const char * str
 *
 * @return boolean
 */
#define is_numeric(str) (! isNaN(parseInt(str)) || ! isNaN(parseFloat(str)))

CPP_END

#endif
