/**
 * Random functions
 * NOTE:
 * 	The random number generator must be seeded outside the file
 */
#ifndef __RAND_H
#define __RAND_H

#include "../core/core.h"

CPP_START

/**
 * Get a random number in some range
 *
 * @param int min
 * @param int max
 *
 * @return int
 */
int rand_in_range(int min, int max);

CPP_END
#endif
