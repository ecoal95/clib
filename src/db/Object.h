#ifndef OBJECT_H
#define OBJECT_H

#include "../core/core.h"
#include "Model.h"
#include "../common/array.h"
/**
 * Object structure
 */
typedef struct Object {
	Model * model;
	pointer * values;
} Object;

/**
 * Initialize an object
 *
 * @param Object * o
 * @param Model * model
 */
void Object_initialize(Object * o, Model * model);

/**
 * Generates a new object
 *
 * @param Model * model
 *
 * @return Object *
 */
Object * newObject(Model * model);


/**
 * Set key and value
 * Lot of code repetition...
 */
void Object_set_int    (Object * o, const char * key, int value);
void Object_set_char   (Object * o, const char * key, char value);
void Object_set_string (Object * o, const char * key, char * value);
void Object_set_uint   (Object * o, const char * key, uint value);
void Object_set_short  (Object * o, const char * key, short value);
void Object_set_ushort (Object * o, const char * key, ushort value);
void Object_set_boolean(Object * o, const char * key, ushort value);
void Object_set_long   (Object * o, const char * key, long value);
void Object_set_ulong  (Object * o, const char * key, ulong value);
void Object_set_llong  (Object * o, const char * key, llong value);
void Object_set_ullong (Object * o, const char * key, ullong value);
void Object_set_float  (Object * o, const char * key, float value);
void Object_set_double (Object * o, const char * key, double value);
void Object_set_ldouble(Object * o, const char * key, ldouble value);

/**
 * Get a value
 */
void *  Object_get        (Object * o, const char * key);

int     Object_get_int    (Object * o, const char * key);
char    Object_get_char   (Object * o, const char * key);
char *  Object_get_string (Object * o, const char * key);
uint    Object_get_uint   (Object * o, const char * key);
short   Object_get_short  (Object * o, const char * key);
ushort  Object_get_ushort (Object * o, const char * key);
ushort  Object_get_boolean(Object * o, const char * key);
long    Object_get_long   (Object * o, const char * key);
ulong   Object_get_ulong  (Object * o, const char * key);
llong   Object_get_llong  (Object * o, const char * key);
ullong  Object_get_ullong (Object * o, const char * key);
float   Object_get_float  (Object * o, const char * key);
double  Object_get_double (Object * o, const char * key);
ldouble Object_get_ldouble(Object * o, const char * key);
#endif
