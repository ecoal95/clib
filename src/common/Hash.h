#ifndef __HASH_H
#define __HASH_H

CPP_START

#include "../core/core.h"
#include "./Array.h"

typedef struct Hash {
	size_t length;
	Array * keys;
	Array * values;
} Hash;

/**
 * Alloc a new hash
 *
 * @return Hash *
 */
Hash * newHash();

/**
 * Get hash length, for consistency
 */
#define Hash_length(h) (h->length)

/**
 * Set a hash key
 *
 * @param Hash * hash
 * @param const char * key
 * @param pointer data
 *
 * @return hash
 */
Hash * Hash_set(Hash * hash, const char * key, pointer data);

/**
 * Get data from hash
 *
 * @param Hash * hash
 * @param const char * key
 *
 * @return pointer
 */
pointer Hash_get(Hash * hash, const char * key);

/**
 * Iterate through keys and values
 *
 * @param Hash * hash
 * @param void (callback *)(char *, pointer)
 */
void Hash_iterate(Hash * hash, void (* callback)(char *, pointer));


/**
 * Deallocate hash
 *
 * @param Hash * self
 * @param boolean with_data
 */
void Hash_destroy(Hash * self, boolean with_data);

/**
 * Merge two hashes
 *
 * @param Hash * hash_1
 * @param Hash * hash_2
 *
 * @return Hash *
 */
Hash * Hash_merge(Hash * hash_1, Hash * hash_2);

CPP_END
#endif
