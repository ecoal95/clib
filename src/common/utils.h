#ifndef __UTILS_H
#define __UTILS_H

#include "../core/core.h"

CPP_START

/**
 * Clean the input buffer
 * We can fflush(stdin) on windows, but it apparently doesn't work on ubuntu
 */
void utils_ib_clean();

/**
 * Pause the program until a key is pressed, but sending a message before
 */
void utils_pause();

CPP_END

#endif
