#include "file.h"
/**
 * Returns file size in bytes
 *
 * @param FILE * src pointer to stream
 *
 * @return size_t the file size
 */
size_t FILE_size(FILE *src) {
	size_t ret;
	fseek(src, 0, SEEK_END);
	ret = ftell(src);
	rewind(src);
	return ret;
}

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
int FILE_eachLine(FILE * file, int (*callback)(char *, pointer), pointer data) {
	static char line[FILE_LINE_BASE_LENGTH];
	char * current_line = NULL;
	size_t current_line_len;
	int ret = 0;

	return_val_if(file == NULL, -1);

	while(fgets(line, FILE_LINE_BASE_LENGTH, file)) {
		if( current_line == NULL ) {
			current_line = str_clone(line);
		} else {
			// continue reading the line
			current_line = (char *) realloc(current_line, current_line_len + FILE_LINE_BASE_LENGTH);
			return_val_if(current_line == NULL, -1);

			strcpy(current_line + current_line_len, line);
		}

		current_line_len = strlen(current_line);

		// if line is not over continue reading
		if( current_line[current_line_len - 1] != EOL ) {
			continue;
		}

		// remove eol
		current_line[current_line_len - 1] = '\0';

		if( (ret = callback(current_line, data)) < 0 ) {
			free(current_line);
			return ret;
		}
		free(current_line);
		current_line = NULL;
	}

	return ret;
}


/**
 * Copies two files
 *
 * @param FILE * dest
 * @param FILE * src
 *
 * @return boolean
 */
boolean FILE_copy(FILE * dest, FILE * src) {
	void * chunk;
	size_t copied;

	return_val_if(dest == NULL || src == NULL, 0);

	// we make it in chunks for performance
	chunk = malloc(FILE_LINE_BASE_LENGTH);

	while((copied = fread(chunk, 1, FILE_LINE_BASE_LENGTH, src))) {
		fwrite(chunk, 1, copied, dest);
	}

	rewind(dest);
	rewind(src);

	return TRUE;
}

/**
 * Returns if a file exists or not
 *
 * @param const char * src the file name
 *
 * @return unsigned int
 */
boolean file_exists(const char *src) {
	FILE *file = fopen(src, "r");

	if( file == NULL ) {
		return FALSE;
	}
	fclose(file);
	return TRUE;
}

/**
 * Returns a file name
 *
 * @param const char * src
 *
 * @return char *
 */
char * file_filename(const char * src) {
	const char * last_separator = strrchr(src, DIRECTORY_SEPARATOR);

	if( ! last_separator ) {
		last_separator = src;
	} else {
		last_separator++;
	}

	return str_clone(last_separator);
}

/**
 * Returns a file extension
 *
 * @param const char * src
 *
 * @return char *
 */
char * file_extension(const char * src) {
	char * filename = file_filename(src);
	char * dot = strchr(filename, '.');

	if( ! dot ) {
		free(filename);
		return str_empty();
	}
	free(filename);
	return str_clone(dot + 1);
}

/**
 * Returns a file basename
 *
 * @param const char * src
 *
 * @return char *
 */
char * file_basename(const char * src) {
	char * filename = file_filename(src);
	char * dot = strchr(filename, '.');

	if( ! dot ) {
		return filename;
	}

	dot[0] = '\0';

	return filename;
}

/**
 * Copies two files
 *
 * @param const char * dest
 * @param const char * src
 *
 * @return boolean
 */
boolean file_copy(const char * dest, const char * src) {
	FILE * fdest;
	FILE * fsrc;
	boolean ret;

	fdest = fopen(dest, "w");

	return_val_if(fdest == NULL, 0);

	fsrc = fopen(src, "r");

	if( fsrc == NULL ) {
		fclose(fdest);
	}

	return_val_if(fsrc == NULL, 0); // This is done for avoid writing unnecesary warnings, but should go in the conditional above

	ret = FILE_copy(fdest, fsrc);

	fclose(fdest);
	fclose(fsrc);

	return ret;
}

/**
 * Make a callback each line of the file
 *
 * @param const char * file
 * @param int (*callback)(char *, pointer) callback function that receives the line and the custom data, and returns 0 on success
 * @param pointer data custom data
 *
 * @return int (< 0 on error)
 */
int file_eachLine(const char * src, int (*callback)(char *, pointer), pointer data) {
	int ret;
	FILE * file = fopen(src, "r");

	return_val_if(file == NULL, -1);

	ret = FILE_eachLine(file, callback, data);

	fclose(file);

	return ret;
}

/**
 * Returns the full content of a file
 *
 * @param const char * src the file name
 *
 * @return char *
 */
char * file_get_contents(const char * src) {
	FILE * file;
	char * ret;
	size_t filesize;
	size_t contentlength;

	if( ! file_exists(src) ) {
		return "";
	}

	file = fopen(src, "r");

	filesize = FILE_size(file);

	ret = (char *) malloc(filesize + 1); // Sizeof char para poder poner el \0 y que lo trate como strubg
	contentlength = fread(ret, 1, filesize, file); // Leemos byte a byte y lo ponemos en el buffer
	ret[contentlength] = '\0'; // Tenemos que indicar que acaba la cadena, no aparecen caracteres almacenados en otros slots de memoria

	fclose (file);
	return ret;
}

/**
 * Write into a file. If file doesnt exists it'll be created
 *
 * @param const char * src file name
 * @param const char * content
 * @param const enum file_method mode
 *
 * @return int
 */
int file_put_contents(const char * src, const char * content, const enum file_method mode) {
	int ret;
	FILE * file;
	switch(mode) {
		case FILE_APPEND:
			file = fopen(src, "a");
			break;
		case FILE_REPLACE:
			file = fopen(src, "w");
			break;
		default:
			return 0;
	}

	ret = fputs(content, file);
	fclose (file);
	return ret;
}
