#ifndef __VMATH_H
#define __VMATH_H

#include <math.h>

typedef int * IntVector;

typedef double * FloatVector;

/**
 * Allocate a new int vector
 * @param size_t length
 *
 * @return IntVector
 */
IntVector newIntVector(size_t length);

/**
 * Sum of two int vectors
 * @param IntVector v1
 * @param IntVector v2
 * @param size_t length
 *
 * @return IntVector
 */
IntVector IntVector_sum(IntVector v1, IntVector v2, size_t length);

/**
 * Get the modulus of a vector
 *
 * @param Intvector v
 * @param size_t length
 */
double IntVector_modulus(IntVector v, size_t length);

/**
 * Allocate a new floating point vector
 * @param size_t length
 *
 * @return FloatVector
 */
FloatVector newFloatVector(size_t length);

/**
 * Sum of two floating point vectors
 * @param FloatVector v1
 * @param FloatVector v2
 * @param size_t length
 *
 * @return FloatVector
 */
FloatVector FloatVector_sum(FloatVector v1, FloatVector v2, size_t length);

/**
 * Get the modulus of a vector
 *
 * @param FloatVector v
 * @param size_t length
 */
double FloatVector_modulus(FloatVector v, size_t length);

#endif
