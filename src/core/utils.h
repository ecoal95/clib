#ifndef __UTILS_H
#define __UTILS_H

#if __STDC_VERSION__ >= 199901L
#define C99
#endif

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define ABS(a) (((a) < 0) ? (a) : -(a))

// http://stackoverflow.com/questions/11761703/overloading-macro-on-number-of-arguments
#ifdef C99
#define GET_VA_MACRO_2(_1, _2, NAME, ...) NAME
#define GET_VA_MACRO_3(_1, _2, _3, NAME, ...) NAME
#define GET_VA_MACRO_4(_1, _2, _3, _4, NAME, ...) NAME
#define GET_VA_MACRO_5(_1, _2, _3, _4, _5, NAME, ...) NAME
#else
#define GET_VA_MACRO_2(_1, _2, NAME, args...) NAME
#define GET_VA_MACRO_3(_1, _2, _3, NAME, args...) NAME
#define GET_VA_MACRO_4(_1, _2, _3, _4, NAME, args...) NAME
#define GET_VA_MACRO_5(_1, _2, _3, _4, _5, NAME, args...) NAME
#endif

#define is_null(a) ((a) == NULL)

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

#define return_null_if(expr) return_val_if(expr, NULL)
#define return_null_if_fail(expr) return_val_if_fail(expr, NULL)

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
