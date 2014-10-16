#ifndef __MAP_H
#define __MAP_H

CPP_START

#include "../core/core.h"
#include "./Array.h"

typedef struct MapKeyPair {
	void * key;
	void * value;
} MapKeyPair;

typedef struct Map {
	size_t length;
	Array * keyPairs;
} Map;

#define MAP_ITERATE(self, _key, _value, ...) do { \
	MapKeyPair * __keyPair; \
	ARRAY_EACH(self->keyPairs, __keyPair, \
		_key = (typeof(_key)) __keyPair->key; \
		_value = (typeof(_value)) __keyPair->value; \
		__VA_ARGS__ \
	); \
} while ( 0 )

/**
 * Alloc a new hash
 *
 * @return Map *
 */
Map * newMap();

/**
 * Alloc a new map keyPair
 *
 * @return MapKeyPair *
 */
MapKeyPair * newKeyPair(void * key, pointer data );

/**
 * Get map length, for consistency
 */
#define Map_length(m) (m->length)

/**
 * Set a map key
 *
 * @param Map * hash
 * @param void * key
 * @param pointer data
 *
 * @return hash
 */
Map * Map_set(Map * hash, void * key, pointer data);

/**
 * Get data from hash
 *
 * @param Map * hash
 * @param void * key
 *
 * @return pointer
 */
pointer Map_get(Map * hash, void * key);

/**
 * Iterate through keys and values
 *
 * @param Map * hash
 * @param void (callback *)(void *, pointer)
 */
void Map_iterate(Map * hash, void (* callback)(void *, pointer));


/**
 * Deallocate hash
 *
 * @param Map * self
 */
void Map_destroy(Map * self);

/**
 * Merge two hashes
 *
 * @param Map * hash_1
 * @param Map * hash_2
 *
 * @return Map *
 */
Map * Map_merge(Map * map_1, Map * map_2);

CPP_END
#endif
