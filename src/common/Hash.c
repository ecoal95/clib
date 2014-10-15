#include "Hash.h"

/**
 * TODO: Review implementation
 * Maybe store both pointers (key and value) in the same place will be cool for perf
 *
 * Something like:
typedef struct HashValue {
	char * key;
	pointer value;
} HashValue;
 * Instead of both arrays
 */
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

	return self;
}

/**
 * Get data from hash
 *
 * @param Hash * hash
 * @param const char * key
 *
 * @return pointer
 */
pointer Hash_get(Hash * self, const char * key) {
	size_t i,
		len = self->length;
	void * data;
	ARRAY_EACH_WITH_INDEX(self->keys, data, i,
		if(strcmp((char *) data, key) == 0) {
			break;
		}
	);

	if( i < len ) {
		return Array_nth(self->values, i);
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
		callback((char *) Array_nth(hash->keys, i), Array_nth(hash->values, i));
	}
}

/**
 * Deallocate hash
 *
 * @param Hash * self
 * @param boolean with_data
 */
void Hash_destroy(Hash * self, boolean with_data) {
	Array_destroy(self->keys, TRUE);
	Array_destroy(self->values, with_data);
	free(self);
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

	for ( ; i < len; i++ ) {
		Hash_set(hash_1, (char *) Array_nth(hash_2->keys, i), Array_nth(hash_2->values, i));
	}

	return hash_1;
}
