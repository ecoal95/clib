#ifndef __MAP_H
#define __MAP_H

#include "../core.h"

CPP_START

#include "Array.h"

typedef struct MapKeyPair {
	const void * key;
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
MapKeyPair * newKeyPair(const void * key, pointer data );

/**
 * Get map length, for consistency
 */
#define Map_length(m) (m->length)

/**
 * Set a map key
 *
 * @param Map * self
 * @param void * key
 * @param pointer data
 *
 * @return hash
 */
Map * Map_set(Map * self, const void * key, pointer data);

/**
 * Get data from hash
 *
 * @param Map * self
 * @param void * key
 *
 * @return pointer
 */
pointer Map_get(Map * self, const void * key);

/**
 * Get data from a hash assuming keys are strings
 *
 * @param Map * self
 * @param const char * key
 */
pointer Map_getString(Map * self, const char * key);

/**
 * Iterate through keys and values
 *
 * @param Map * self
 * @param void (callback *)(void *, pointer)
 */
void Map_iterate(Map * self, void (* callback)(const void *, pointer));


/**
 * Deallocate hash
 *
 * @param Map * self
 */
void Map_destroy(Map * self);

/**
 * Merge two hashes
 *
 * @param Map * self_1
 * @param Map * self_2
 *
 * @return Map *
 */
Map * Map_merge(Map * map_1, Map * map_2);

CPP_END
#endif
