#ifndef __FILE_H
#define __FILE_H
/**
 * Returns file size in bytes
 *
 * @param FILE * src pointer to stream
 *
 * @return size_t the file size
 */
size_t file_size(FILE *src);

/**
 * Returns if a file exists or not
 *
 * @param const char * src the file name
 *
 * @return unsigned int
 */
unsigned int file_exists(const char *src);

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
#endif
