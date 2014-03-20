#ifndef __HASH_H
#define __HASH_H

typedef struct Hash {
	size_t length;
	string * keys;
	pointer * data;
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
 * @param const string key
 * @param pointer data
 *
 * @return hash
 */
Hash * Hash_set(Hash * hash, const string key, pointer data);

/**
 * Get data from hash
 *
 * @param Hash * hash
 * @param const string key
 *
 * @return pointer
 */
pointer Hash_get(Hash * hash, const string key);
#endif
