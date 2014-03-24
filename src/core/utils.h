#ifndef __UTILS_H
#define __UTILS_H

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define ABS(a) (((a) < 0) ? (a) : -(a))

#define is_null(a) ((a) == NULL)

#if __LIB_DEBUG_MODE == 0
#define return_if(expr) if(expr) { \
	return;                        \
}

#define return_val_if(expr, val) if(expr) { \
	return val;                            \
}

#define return_if_fail(expr) if(!(expr)) { \
	return;                               \
}

#define return_val_if_fail(expr, val) if(!(expr)) { \
	return val;                                 \
}
#else
#define return_if(expr) if(expr) { \
	fprintf(stderr, "[WARNING] [%s:%d:%s] "#expr" passed\n", __FILE__, __LINE__, __FUNCTION__); \
	return;                       \
}

#define return_val_if(expr, val) if(expr) { \
	fprintf(stderr, "[WARNING] [%s:%d:%s] "#expr" passed\n", __FILE__, __LINE__, __FUNCTION__); \
	return val;                            \
}

#define return_if_fail(expr) if(!(expr)) { \
	fprintf(stderr, "[WARNING] [%s:%d:%s] "#expr" failed\n", __FILE__, __LINE__, __FUNCTION__); \
	return;                               \
}

#define return_val_if_fail(expr, val) if(!(expr)) { \
	fprintf(stderr, "[WARNING] [%s:%d:%s] "#expr" failed\n", __FILE__, __LINE__, __FUNCTION__); \
	return val;                                 \
}
#endif
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
