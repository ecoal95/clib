#ifndef MODEL_H
#define MODEL_H

/**
 * Model structure
 */
typedef struct Model {
	size_t fieldCount;
	char * * fields;
	// size_t * sizes;
} Model;

/**
 * Initialize a model
 *
 * @param Model * model
 * @param char * * fields
 * @param size_t fieldCount
 */
void Model_initialize(Model * model, char ** fields, size_t fieldCount);

/**
 * Get a new model
 *
 * @param char ** fields
 * @param size_t fieldCount
 *
 * @return Model *
 */
Model * newModel(char ** fields, size_t fieldCount);

#endif
