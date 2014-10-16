#include "Map.h"

/**
 * Alloc a new map
 *
 * @return Map *
 */
Map * newMap() {
	Map * ret = (Map *) malloc(sizeof(Map));

	return_null_if(ret == NULL);

	ret->length = 0;

	ret->keyPairs = newArray();

	return ret;
}

/**
 * Alloc a new map keyPair
 *
 * @return MapKeyPair *
 */
MapKeyPair * newKeyPair( void * key, pointer data ) {
	MapKeyPair * ret = (MapKeyPair *) malloc(sizeof(MapKeyPair));

	return_null_if(ret == NULL);

	ret->key = key;
	ret->value = data;

	return ret;
}

/**
 * Set a hash key
 *
 * @param Map * self
 * @param const void * key
 * @param pointer data
 *
 * @return self
 */
Map * Map_set(Map * self, void * key, pointer data) {
	MapKeyPair * keyPair;
	size_t i = 0;

	return_null_if(key == NULL);

	ARRAY_EACH(self->keyPairs, keyPair,
		if ( keyPair->key == key ) {
			keyPair->value = data;
			return self;
		}
	);

	Array_push(self->keyPairs, newKeyPair(key, data));

	return self;
}

/**
 * Get data from map
 *
 * @param Map * self
 * @param const void * key
 *
 * @return pointer
 */
pointer Map_get(Map * self, void * key) {
	size_t i;
	MapKeyPair * keyPair;
	ARRAY_EACH(self->keyPairs, keyPair,
		if ( keyPair->key == key ) {
			return keyPair->value;
		}
	);

	return NULL;
}

/**
 * Iterate through keys and values
 *
 * @param Map * self
 * @param void (callback *)(char *, pointer)
 */
void Map_iterate(Map * self, void (* callback)(void *, pointer)) {
	MapKeyPair * keyPair;
	ARRAY_EACH(self->keyPairs, keyPair,
		callback(keyPair->key, keyPair->value);
	);
}

/**
 * Deallocate map
 *
 * @param Map * self
 */
void Map_destroy(Map * self) {
	Array_destroy(self->keyPairs, FALSE);
	free(self);
}

/**
 * Merge two maps
 *
 * @param Map * map_1
 * @param Map * map_2
 *
 * @return Map *
 */
Map * Map_merge(Map * map_1, Map * map_2) {
	MapKeyPair * keyPair;

	ARRAY_EACH(map_2->keyPairs, keyPair,
		Map_set(map_1, keyPair->key, keyPair->value);
	);

	return map_1;
}
