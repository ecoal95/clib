#ifndef __FILE_H
#define __FILE_H

#include "../core.h"

CPP_START

#define DIRECTORY_SEPARATOR '/'
#define EOL '\n'
#define FILE_LINE_BASE_LENGTH 256

/**
 * Returns file size in bytes
 *
 * @param FILE * src pointer to stream
 *
 * @return size_t the file size
 */
size_t FILE_size(FILE *src);


/**
 * Make a callback each line of the file
 * TODO: Consider changing return type to boolean
 *
 * @param FILE * file
 * @param int (*callback)(char *, pointer) callback function that receives the line and the custom data, returns 0 on success
 * @param pointer data custom data
 *
 * @return int (< 0 on error)
 */
int FILE_eachLine(FILE * file, int (*callback)(char *, pointer), pointer data);

/**
 * Copies two files
 *
 * @param FILE * dest
 * @param FILE * src
 *
 * @return boolean
 */
boolean FILE_copy(FILE * dest, FILE * src);

/**
 * Returns if a file exists or not
 *
 * @param const char * src the file name
 *
 * @return unsigned int
 */
boolean file_exists(const char *src);

/**
 * Returns a file name
 *
 * @param const char * src
 *
 * @return char *
 */
char * file_filename(const char * src);

/**
 * Returns a file extension
 *
 * @param const char * src
 *
 * @return char *
 */
char * file_extension(const char * src);

/**
 * Returns a file basename
 *
 * @param const char * src
 *
 * @return char *
 */
char * file_basename(const char * src);

/**
 * Copies two files
 *
 * @param const char * dest
 * @param const char * src
 *
 * @return boolean
 */
boolean file_copy(const char * dest, const char * src);

/**
 * Make a callback each line of the file
 *
 * @param const char * file
 * @param int (*callback)(char *, pointer) callback function that receives the line and the custom data, and returns 0 on success
 * @param pointer data custom data
 *
 * @return int (< 0 on error)
 */
int file_eachLine(const char * file, int (*callback)(char *, pointer), pointer data);

/**
 * Returns the full content of a file
 *
 * @param const char * src the file name
 *
 * @return char *
 */
char * file_get_contents(const char * src);

enum file_method {
	FILE_REPLACE, /**< add content to a file replacing existing content */
	FILE_APPEND /**< add content to a file appending to existing content */
};

/**
 * Write into a file. If file doesnt exists it'll be created
 *
 * @param const char * src file name
 * @param const char * content
 * @param const enum file_method mode
 *
 * @return int
 */
int file_put_contents(const char *src, const char *content, const enum file_method mode);

CPP_END

#endif
