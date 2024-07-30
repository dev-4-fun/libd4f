#ifndef d4f__logger_h
#define d4f__logger_h

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

#define d4f__log(format) \
	_d4f__log(stdout, "%s:%d \x1b[32m[LOG]: " format "\x1b[0m\n", __FILE__, __LINE__)

#define d4f__log1(format, arg1) \
	_d4f__log(stdout, "%s:%d \x1b[32m[LOG]: " format "\x1b[0m\n", __FILE__, __LINE__, arg1)

#define d4f__log2(format, arg1, arg2) \
	_d4f__log(stdout, "%s:%d \x1b[32m[LOG]: " format "\x1b[0m\n", __FILE__, __LINE__, arg1, arg2)

#define d4f__log3(format, arg1, arg2, arg3) \
	_d4f__log(stdout, "%s:%d \x1b[32m[LOG]: " format "\x1b[0m\n", __FILE__, __LINE__, arg1, arg2, arg3)

#define d4f__warn(format) \
    _d4f__log(stdout, "%s:%d \x1b[33m[WARNING]: " format "\x1b[0m\n", __FILE__, __LINE__)

#define d4f__warn1(format, arg1) \
    _d4f__log(stdout, "%s:%d \x1b[33m[WARNING]: " format "\x1b[0m\n", __FILE__, __LINE__, arg1)

#define d4f__warn2(format, arg1, arg2) \
    _d4f__log(stdout, "%s:%d \x1b[33m[WARNING]: " format "\x1b[0m\n", __FILE__, __LINE__, arg1, arg2)

#define d4f__warn3(format, arg1, arg2, arg3) \
    _d4f__log(stdout, "%s:%d \x1b[33m[WARNING]: " format "\x1b[0m\n", __FILE__, __LINE__, arg1, arg2, arg3)

#define d4f__error(format) \
    _d4f__log(stderr, "%s:%d \x1b[31m[ERROR]: " format "\x1b[0m\n", __FILE__, __LINE__)

#define d4f__error1(format, arg1) \
    _d4f__log(stderr, "%s:%d \x1b[31m[ERROR]: " format "\x1b[0m\n", __FILE__, __LINE__, arg1)

#define d4f__error2(format, arg1, arg2) \
    _d4f__log(stderr, "%s:%d \x1b[31m[ERROR]: " format "\x1b[0m\n", __FILE__, __LINE__, arg1, arg2)

#define d4f__error3(format, arg1, arg2, arg3) \
    _d4f__log(stderr, "%s:%d \x1b[31m[ERROR]: " format "\x1b[0m\n", __FILE__, __LINE__, arg1, arg2, arg3)

void _d4f__log(FILE* stream, const char* format, ...) {
	va_list args;
	va_start(args, format);
	vfprintf(stream, format, args);
	va_end(args);
}

#ifdef __cplusplus
}
#endif

#endif /* !d4f__logger_h */

