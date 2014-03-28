#ifndef __TYPES_H
#define __TYPES_H

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

#endif
