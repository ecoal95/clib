/** Current locale */
static char * locale = NULL;

/** Set with I18n__setPath() */
static Array * translations_paths = NULL;

/** To store a list with the translations */
static Map * translations = NULL;

/**
 * Set current locale
 *
 * @param const char * loc
 */
char * I18n__setLocale(const char * loc) {
	if ( locale != NULL ) {
		free(locale);
	}
	locale = str_clone(loc);
	setlocale(LC_ALL, loc);

	return locale;
}

/**
 * Get current locale
 *
 * @return char *
 */
char * I18n__getLocale() {
	// return setLocale(LC_ALL, NULL);
	return locale;
}

/**
 * Add a path to the translations path
 *
 * @param const char * path
 *
 * @return char *
 */
char * I18n__setPath(const char * path) {
	char * cloned_path;

	if ( translations_paths == NULL ) {
		translations_paths = newArray();
	}

	cloned_path = str_clone(path);

	Array_push(translations_paths, cloned_path);

	return cloned_path;
}

/**
 * Release all memory allocated in the module
 */
void I18n__destroy() {
	Map * lang_translations;
	char * locale;
	char * key;
	char * value;

	Array_destroy(translations_paths, TRUE);

	MAP_ITERATE(translations, locale, lang_translations,
		MAP_ITERATE(lang_translations, key, value,
			free(key);
			free(value);
		);
		free(locale);
		Map_destroy(lang_translations);
	);

	Map_destroy(translations);
}


/**
 * Parse a line of a translation file
 *
 * @param char * line
 * @param void * map
 *
 * @return 0
 */
int I18n__parseLine(char * line, void * map) {
	char * key;
	char * value;

	key = strtok(line, ":");
	value = strtok(NULL, "");

	// invalid or empty line
	if ( value == NULL ) {
		return 0;
	}

	key = str_trim(str_clone(key));
	value = str_trim(str_clone(value));

	Map_set((Map *) map, key, value);

	return 0;
}

/**
 * Load translations for a path
 *
 * @param const char * locale
 * @param const char * path
 * @param Map * path
 *
 * @rerturn Map *
 */
Map * I18n__loadPathTranslations(const char * locale, char * path, Map * map) {
	char * file = str_concat(path, locale);

	if ( file_exists(file) ) {
		file_eachLine(file, I18n__parseLine, map);
	} else {
		free(file);
		return_null_if( TRUE ); // FILE not found
	}

	free(file);

	return map;
}

/**
 * Load translations for a locale, that loads all translations for all the paths
 *
 * @param const char * locale
 * @param const char * path
 *
 * @rerturn Map *
 */
Map * I18n__loadTranslations(const char * locale) {
	char * path;
	Map * ret = newMap();


	return_null_if(translations_paths == NULL);

	ARRAY_EACH(translations_paths, path,
		I18n__loadPathTranslations(locale, path, ret);
	);

	return  ret;
}

/**
 * Get translations set with current locale
 *
 * @param const char * locale
 *
 * @return Map *
 */
static Map * I18n__translations(const char * locale) {
	Map * locale_translations;

	if ( translations == NULL ) {
		translations = newMap();
	}

	if ( (locale_translations = Map_get(translations, locale)) == NULL ) {
		locale_translations = I18n__loadTranslations(locale);
		return_null_if(locale_translations == NULL);
		Map_set(translations, locale, locale_translations);
	}

	return locale_translations;
}

/**
 * Find the translation for the key given a set and a key
 *
 * @param I18nTranslations translations
 * @param I18nKey key
 *
 * @return char *
 */
char * I18n__translation(Map * translations, I18nKey key) {
	char * translation = Map_getString(translations, key);

	return_val_if(translation == NULL, (char *) key);

	return translation;
}

/**
 * Translate a key with current locale
 *
 * @param I18nKey key
 *
 * @return char *
 */
char * I18n__t(I18nKey key) {
	return I18n__translation(I18n__translations(locale), key);
}
