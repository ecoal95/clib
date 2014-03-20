/**
 * Returns file size in bytes
 *
 * @param FILE * src pointer to stream
 *
 * @return size_t the file size
 */
size_t file_size(FILE *src) {
	size_t ret;
	fseek(src, 0, SEEK_END);
	ret = ftell(src);
	rewind(src);
	return ret;
}

/**
 * Returns if a file exists or not
 *
 * @param const char * src the file name
 *
 * @return unsigned int
 */
unsigned int file_exists(const char *src) {
	FILE *file = fopen(src, "r");

	if( file == NULL ) {
		return 0;
	}
	fclose(file);
	return 1;
}

/**
 * Returns the full content of a file
 *
 * @param const char * src the file name
 *
 * @return char *
 */
char * file_get_contents(const char * src) {
	char * ret;
	size_t filesize;
	size_t contentlength;

	if( ! file_exists(src) ) {
		return "";
	}

	FILE *file = fopen(src, "r");
	filesize = file_size(file);

	ret = (char *) malloc(filesize + sizeof(char)); // Sizeof char para poder poner el \0 y que lo trate como string
	contentlength = fread(ret, 1, filesize, file); // Leemos byte a byte y lo ponemos en el buffer
	ret[contentlength] = '\0'; // Tenemos que indicar que acaba la cadena, no aparecen caracteres almacenados en otros slots de memoria

	fclose (file);
	return ret;
}


enum file_method {
	FILE_REPLACE, // add content to a file replacing existing content
	FILE_APPEND // add content to a file appending to existing content
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
int file_put_contents(const char *src, const char *content, const enum file_method mode) {
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
