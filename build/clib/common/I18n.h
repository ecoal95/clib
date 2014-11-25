#ifndef __I18N_H
#define __I18N_H

#include "../core.h"

CPP_START

/** Consider moving to enum? */
typedef const char * I18nKey;

/**
 * Set current locale
 *
 * @param const char * loc
 */
char * I18n__setLocale(const char * loc);

/**
 * Get current locale
 *
 * @return char *
 */
char * I18n__getLocale();

/**
 * Add a path to the translations path
 *
 * @param const char * path
 *
 * @return char *
 */
char * I18n__setPath(const char * path);

/**
 * Release all memory allocated in the module
 */
void I18n__destroy();

/**
 * Translate a key with current locale
 *
 * @param I18nKey key
 *
 * @return char *
 */
char * I18n__t(I18nKey key);

CPP_END

#endif
