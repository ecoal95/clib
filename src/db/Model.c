/**
 * Initialize a model
 *
 * @param Model * model
 * @param char * * fields
 * @param size_t fieldCount
 */
void Model_initialize(Model * model, char ** fields, size_t fieldCount) {
	size_t i,
		size = 0;
	model->fieldCount = fieldCount;

	model->fields = malloc(fieldCount * sizeof(char *));

	for(i = 0; i < fieldCount; i++) {
		model->fields[i] = malloc(strlen(fields[i] + 1));
		strcpy(model->fields[i], fields[i]);
	}
}

/**
 * Get a new model
 *
 * @param char ** fields
 * @param size_t fieldCount
 *
 * @return Model *
 */
Model * newModel(char ** fields, size_t fieldCount) {
	Model * model = malloc(sizeof(Model));

	Model_initialize(&model, fields, fieldCount);

	return model;
}
