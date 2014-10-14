#ifndef __I18N_H
#define __I18N_H

CPP_START

#include <locale.h>
#include "../common/Array.h"
#include "../common/Hash.h"
#include "../common/str.h"

/** Consider moving to enum? */
typedef const char * I18nKey;

/** Current locale */
static char * locale;

/** Set with I18n__setPath() */
static Array * translations_paths;

/** To store a list with the translations */
static Hash * translations;

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
 * Load translations for a path
 *
 * @param const char * locale
 * @param const char * path
 *
 * @rerturn Hash *
 */
Hash * I18n__loadPathTranslations(const char * locale, const char * path) {
	Hash * ret = newHash();

	/** TODO: Parse file, add keys and values */

	return ret;
}

/**
 * Load translations for a locale, that loads all translations for all the paths
 *
 * @param const char * locale
 * @param const char * path
 *
 * @rerturn Hash *
 */
Hash * I18n__loadTranslations(const char * locale) {
	size_t len,
		i = 0;
	Hash * ret,
		temp;


	return_null_if(translations_paths == NULL);

	len = Array_length(translations_paths)

	for ( ; i < len; i++ ) {
		temp = I18n__loadPathTranslations(locale, Array_get(translations_paths, i));
		if ( ret == NULL ) {
			ret = temp;
		} else {
			ret = Hash_merge(ret, temp);
			free(temp);
		}
	}

	return  ret;
}

/**
 * Get translations set with current locale
 *
 * @param const char * locale
 *
 * @return Hash *
 */
static Hash * I18n__translations(const char * locale) {
	Hash * locale_translations;

	if ( translations == NULL ) {
		translations = newHash();
	}

	if ( (locale_translations = Hash_get(translations, locale)) == NULL ) {
		locale_translations = I18n__loadTranslations(locale);
		Hash_set(translations, locale, locale_translations);
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
static char * I18n__translation(Hash * translations, I18nKey key) {
	char * translation = Hash_get(translations, key);

	return_null_if(translation == NULL);

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
	return I18n__translation(I18n__translations(setlocale(LC_ALL, NULL)), key);
}

CPP_END

#endif
