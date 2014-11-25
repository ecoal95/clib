#ifndef __DEFS_H
#define __DEFS_H

#ifdef __cplusplus
#define CPP_START extern "C" {
#define CPP_END }
#else
#define CPP_START
#define CPP_END
#endif

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

#define return_if(expr) return_val_if(expr,)
#define return_if_fail(expr) return_val_if_fail(expr,)

#define return_null_if(expr) return_val_if(expr, NULL)
#define return_null_if_fail(expr) return_val_if_fail(expr, NULL)

#define return_val_if(expr, val) if(expr) { \
	fprintf(stderr, "[WARNING] [%s:%d:%s] "#expr" passed\n", __FILE__, __LINE__, __FUNCTION__); \
	return val;                            \
}

#define return_val_if_fail(expr, val) if(!(expr)) { \
	fprintf(stderr, "[WARNING] [%s:%d:%s] "#expr" failed\n", __FILE__, __LINE__, __FUNCTION__); \
	return val;                                 \
}


CPP_START

typedef void * pointer;

// typedef char * string;
typedef int boolean;

typedef unsigned int uint;
typedef unsigned short int ushort;

typedef unsigned long int ulong;
typedef long long int llong;
typedef unsigned long long int ullong;

typedef long double ldouble;

#define FALSE (0)
#define TRUE (!FALSE)

#define FS_CHAR "%c"
#define FS_STRING "%s"

#define FS_INT "%i"
#define FS_INT_DECIMAL "%d"
#define FS_INT_HEXA "%x"
#define FS_INT_OCTAL "%o"
#define FS_UINT "%u"

#define FS_BOOLEAN FS_INT_DECIMAL

#define FS_LONG "%li"
#define FS_LONG_DECIMAL "%ld"
#define FS_LONG_HEXA "%lx"
#define FS_LONG_OCTAL "%lo"
#define FS_ULONG "%lu"

#define FS_LLONG "%lli"
#define FS_LLONG_DECIMAL "%lld"
#define FS_LLONG_HEXA "%llx"
#define FS_LLONG_OCTAL "%llo"
#define FS_ULLONG "%llu"

#define FS_SHORT "%hi"
#define FS_SHORT_DECIMAL "%hd"
#define FS_SHORT_HEXA "%hx"
#define FS_SHORT_OCTAL "%ho"
#define FS_USHORT "%hu"

#define FS_FLOAT "%f"
#define FS_DOUBLE "%lf"
#define FS_LDOUBLE "%Lf"

#define POINTER_TO_CHAR(a) ((char) (pointer) a)
#define POINTER_TO_STRING(a) ((char *) (pointer) a)
#define POINTER_TO_INT(a) ((int) (pointer) a)
#define POINTER_TO_BOOLEAN(a) ((boolean) (pointer) a)
#define POINTER_TO_UINT(a) ((uint) (pointer) a)
#define POINTER_TO_LONG(a) ((long) (pointer) a)
#define POINTER_TO_ULONG(a) ((ulong) (pointer) a)
#define POINTER_TO_LLONG(a) ((llong) (pointer) a)
#define POINTER_TO_ULLONG(a) ((ullong) (pointer) a)
#define POINTER_TO_SHORT(a) ((short) (pointer) a)
#define POINTER_TO_USHORT(a) ((ushort) (pointer) a)
#define POINTER_TO_FLOAT(a) ((float) (pointer) a)
#define POINTER_TO_DOUBLE(a) ((double) (pointer) a)
#define POINTER_TO_LDOUBLE(a) ((ldouble) (pointer) a)

#define TO_POINTER(a) ((pointer) a)
#define CHAR_TO_POINTER(a) ((pointer) (char) a)
#define STRING_TO_POINTER(a) ((pointer) (char *) a)
#define INT_TO_POINTER(a) ((pointer) (int) a)
#define BOOLEAN_TO_POINTER(a) ((pointer) (boolean) a)
#define UINT_TO_POINTER(a) ((pointer) (uint) a)
#define LONG_TO_POINTER(a) ((pointer) (long) a)
#define ULONG_TO_POINTER(a) ((pointer) (ulong) a)
#define LLONG_TO_POINTER(a) ((pointer) (llong) a)
#define ULLONG_TO_POINTER(a) ((pointer) (ullong) a)
#define SHORT_TO_POINTER(a) ((pointer) (short) a)
#define USHORT_TO_POINTER(a) ((pointer) (ushort) a)
#define FLOAT_TO_POINTER(a) ((pointer) (float) a)
#define DOUBLE_TO_POINTER(a) ((pointer) (double) a)
#define LDOUBLE_TO_POINTER(a) ((pointer) (ldouble) a)

CPP_END

#endif
