#ifndef __UTILS_H
#define __UTILS_H

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define ABS(a) (((a) < 0) ? (a) : -(a))

/**
 * Clean the input buffer
 * We can fflush(stdin) on windows, but it apparently doesn't work on ubuntu
 */
void utils_ib_clean();

/**
 * Pause the program until a key is pressed, but sending a message before
 */
void utils_pause();
#endif
