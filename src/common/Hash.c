#include "Hash.h"
/**
 * Alloc a new hash
 *
 * @return Hash *
 */
Hash * newHash() {
	Hash * hash = malloc(sizeof(Hash));

	hash->keys = newArray();
	hash->values = newArray();

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
Hash * Hash_set(Hash * self, const char * key, pointer data) {
	size_t i = 0,
		len = Array_length(self->keys);

	for ( ; i < len; i++ ) {
		if ( strcmp(Array_get(self->keys, i), key) == 0 ) {
			break;
		}
	}

	if ( i < len ) {
		Array_set(self->values, i, data);
	} else {
		Array_push(self->keys, str_clone(key));
		Array_push(self->values, data);
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

/**
 * Merge two hashes
 *
 * @param Hash * hash_1
 * @param Hash * hash_2
 *
 * @return Hash *
 */
Hash * Hash_merge(Hash * hash_1, Hash * hash_2) {
	size_t len = hash_2->length,
		i = 0;

	/* TODO: This is expensive, consider change hash structure to use linked lists like `Array` */
	for ( ; i < len; i++ ) {
		Hash_set(hash_1, hash_2->keys[i], hash_2->data[i]);
	}

	return hash_1;
}
