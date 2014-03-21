#include "Hash.h"
/**
 * Alloc a new hash
 *
 * @return Hash *
 */
Hash * newHash() {
	Hash * hash = malloc(sizeof(Hash));

	hash->length = 0;

	return hash;
}

/**
 * Set a hash key
 *
 * @param Hash * hash
 * @param const char * key
 * @param pointer data
 *
 * @return hash
 */
Hash * Hash_set(Hash * hash, const char * key, pointer data) {
	size_t i = 0,
		len = hash->length;

	for(; i < len; i++ ) {
		if(strcmp(hash->keys[i], key) == 0) {
			break;
		}
	}

	if( i < len ) {
		hash->data[i] = data;
	} else {
		hash->length++;

		hash->keys = realloc(hash->keys, sizeof(char *) * hash->length);
		hash->data = realloc(hash->data, sizeof(void *) * hash->length);

		hash->keys[len] = malloc(strlen(key) + 1);
		strcpy(hash->keys[len], key);

		hash->data[len] = data;
	}

	return hash;
}

/**
 * Get data from hash
 *
 * @param Hash * hash
 * @param const char * key
 *
 * @return pointer
 */
pointer Hash_get(Hash * hash, const char * key) {
	size_t i = 0,
		len = hash->length;
	for(; i < len; i++ ) {
		if(strcmp(hash->keys[i], key) == 0) {
			break;
		}
	}

	if( i < len ) {
		return hash->data[i];
	}

	return NULL;
}

/**
 * Iterate through keys and values
 *
 * @param Hash * hash
 * @param void (callback *)(char *, pointer)
 */
void Hash_iterate(Hash * hash, void (* callback)(char *, pointer)) {
	size_t len = hash->length,
		i = 0;
	for(; i < len; i++) {
		callback(hash->keys[i], hash->data[i]);
	}
}

/**
 * Deallocate hash
 *
 * @param Hash * hash
 */
void Hash_destroy(Hash * hash) {
	size_t len = hash->length,
		i = 0;
	for(; i < len; i++) {
		free(hash->keys[i]);
		// Should we?
		free(hash->data[i]);
	}
	free(hash);
}
