/**
 * Allocate a new int vector
 * @param size_t length
 *
 * @return IntVector
 */
IntVector newIntVector(size_t length) {
	IntVector v = malloc(sizeof(int) * length);
	return v;
}

/**
 * Sum of two int vectors
 * @param IntVector v1
 * @param IntVector v2
 * @param size_t length
 *
 * @return IntVector
 */
IntVector IntVector_sum(IntVector v1, IntVector v2, size_t length) {
	size_t i = 0;
	IntVector sum = newIntVector(length);

	for(; i < length; i++) {
		sum[i] = v1[i] + v2[i];
	}
	return sum;
}

/**
 * Get the modulus of a vector
 *
 * @param Intvector v
 * @param size_t length
 */
double IntVector_modulus(IntVector v, size_t length) {
	size_t i = 0;
	double modulus = 0;

	for(; i < length; i++) {
		modulus += v[i] * v[i];
	}

	return sqrt(modulus);
}

/**
 * Allocate a new int vector
 * @param size_t length
 *
 * @return FloatVector
 */
FloatVector newFloatVector(size_t length) {
	FloatVector v = malloc(sizeof(double) * length);
	return v;
}

/**
 * Sum of two int vectors
 * @param FloatVector v1
 * @param FloatVector v2
 * @param size_t length
 *
 * @return FloatVector
 */
FloatVector FloatVector_sum(FloatVector v1, FloatVector v2, size_t length) {
	size_t i = 0;
	FloatVector sum = newFloatVector(length);

	for(; i < length; i++) {
		sum[i] = v1[i] + v2[i];
	}
	return sum;
}

/**
 * Get the modulus of a vector
 *
 * @param FloatVector v
 * @param size_t length
 */
double FloatVector_modulus(FloatVector v, size_t length) {
	size_t i = 0;
	ldouble modulus = 0;

	for(; i < length; i++) {
		modulus += pow(v[i], 2);
	}

	return sqrt(modulus);
}
