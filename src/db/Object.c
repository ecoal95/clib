/**
 * Initialize an object
 *
 * @param Object * o
 * @param Model * model
 */
void Object_initialize(Object * o, Model * model) {
	o->model = model;
	o->values = malloc(sizeof(pointer) * model->fieldCount);
}

/**
 * Generates a new object
 *
 * @param Model * model
 *
 * @return Object *
 */
Object * newObject(Model * model) {
	Object * object = malloc(sizeof(object));
	Object_initialize(&object, model);

	return object;
}


/**
 * Set key and value
 * Lot of code repetition...
 */
void Object_set_int(Object * o, const char * key, int value) {
	size_t index = in_string_array(o->model->fields, o->model->fieldCount, key);

	if( index == -1 ) return;

	o->values[index] = malloc(sizeof(value));
	* (int *) o->values[index] = value;
}

void Object_set_char(Object * o, const char * key, char value) {
	// since char === int..
	Object_set_int(o, key, value);
}

void Object_set_string(Object * o, const char * key, char * value) {
	size_t index = in_string_array(o->model->fields, o->model->fieldCount, key);

	if( index == -1 ) return;

	o->values[index] = malloc(strlen(value) + 1);
	strcpy(o->values[index], value);
}

void Object_set_uint(Object * o, const char * key, unsigned value) {
	size_t index = in_string_array(o->model->fields, o->model->fieldCount, key);

	if( index == -1 ) return;

	o->values[index] = malloc(sizeof(value));
	* (unsigned *) o->values[index] = value;
}

void Object_set_short(Object * o, const char * key, short value) {
	size_t index = in_string_array(o->model->fields, o->model->fieldCount, key);

	if( index == -1 ) return;

	o->values[index] = malloc(sizeof(value));
	* (short *) o->values[index] = value;
}

void Object_set_ushort(Object * o, const char * key, ushort value) {
	size_t index = in_string_array(o->model->fields, o->model->fieldCount, key);

	if( index == -1 ) return;

	o->values[index] = malloc(sizeof(value));
	* (ushort *) o->values[index] = value;
}

void Object_set_boolean(Object * o, const char * key, ushort value) {
	size_t index = in_string_array(o->model->fields, o->model->fieldCount, key);

	if( index == -1 ) return;

	if( value != 0 ) value = 1;

	o->values[index] = malloc(sizeof(value));
	* (ushort *) o->values[index] = value;
}

void Object_set_long(Object * o, const char * key, long value) {
	size_t index = in_string_array(o->model->fields, o->model->fieldCount, key);

	if( index == -1 ) return;

	o->values[index] = malloc(sizeof(value));
	* (long *) o->values[index] = value;
}

void Object_set_ulong(Object * o, const char * key, ulong value) {
	size_t index = in_string_array(o->model->fields, o->model->fieldCount, key);

	if( index == -1 ) return;

	o->values[index] = malloc(sizeof(value));
	* (ulong *) o->values[index] = value;
}

void Object_set_llong(Object * o, const char * key, llong value) {
	size_t index = in_string_array(o->model->fields, o->model->fieldCount, key);

	if( index == -1 ) return;

	o->values[index] = malloc(sizeof(value));
	* (llong *) o->values[index] = value;
}

void Object_set_ullong(Object * o, const char * key, ullong value) {
	size_t index = in_string_array(o->model->fields, o->model->fieldCount, key);

	if( index == -1 ) return;

	o->values[index] = malloc(sizeof(value));
	* (ullong *) o->values[index] = value;
}


void Object_set_float(Object * o, const char * key, float value) {
	size_t index = in_string_array(o->model->fields, o->model->fieldCount, key);

	if( index == -1 ) return;

	o->values[index] = malloc(sizeof(value));
	* (float *) o->values[index] = value;
}

void Object_set_double(Object * o, const char * key, double value) {
	size_t index = in_string_array(o->model->fields, o->model->fieldCount, key);

	if( index == -1 ) return;

	o->values[index] = malloc(sizeof(value));
	* (double *) o->values[index] = value;
}

void Object_set_ldouble(Object * o, const char * key, ldouble value) {
	size_t index = in_string_array(o->model->fields, o->model->fieldCount, key);

	if( index == -1 ) return;

	o->values[index] = malloc(sizeof(value));
	* (ldouble *) o->values[index] = value;
}

/**
 * Get a value
 */
void * Object_get(Object * o, const char * key) {
	size_t index = in_string_array(o->model->fields, o->model->fieldCount, key);
	if( index == -1 ) {
		// TODO throw Exception of some kind
		return NULL;
	}
	return o->values[index];
}

int Object_get_int(Object * o, const char * key) {
	return * ((int *) Object_get(o, key));
}

char Object_get_char(Object * o, const char * key) {
	return * ((char *) Object_get(o, key));
}

char * Object_get_string(Object * o, const char * key) {
	return ((char *) Object_get(o, key));
}

unsigned Object_get_uint(Object * o, const char * key) {
	return * ((unsigned *) Object_get(o, key));
}

short Object_get_short(Object * o, const char * key) {
	return * ((short *) Object_get(o, key));
}

ushort Object_get_ushort(Object * o, const char * key) {
	return * ((ushort *) Object_get(o, key));
}

ushort Object_get_boolean(Object * o, const char * key) {
	return * ((ushort *) Object_get(o, key));
}

long Object_get_long(Object * o, const char * key) {
	return * ((long *) Object_get(o, key));
}

ulong Object_get_ulong(Object * o, const char * key) {
	return * ((ulong *) Object_get(o, key));
}

llong Object_get_llong(Object * o, const char * key) {
	return * ((llong *) Object_get(o, key));
}

ullong Object_get_ullong(Object * o, const char * key) {
	return * ((ullong *) Object_get(o, key));
}

float Object_get_float(Object * o, const char * key) {
	return * ((float *) Object_get(o, key));
}

double Object_get_double(Object * o, const char * key) {
	return * ((double *) Object_get(o, key));
}

ldouble Object_get_ldouble(Object * o, const char * key) {
	return * ((ldouble *) Object_get(o, key));
}
