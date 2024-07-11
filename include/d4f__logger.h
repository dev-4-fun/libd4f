#ifndef d4f__logger_h
#define d4f__logger_h

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

#define d4f__log(format, ARGS) \
    _d4f___log(stdout, "%s:%d \e[32m[LOG]" format "\e[0m\n", __FILE__, __LINE__, ##ARGS)

#define d4f__warn(format, ARGS) \
    _d4f___log(stdout, "%s:%d \e[33m[WARNING]: " format "\e[0m\n", __FILE__, __LINE__, (ARGS))

#define d4f__error(format, ARGS) \
    _d4f__log(stderr, "%s:%d \e[31m[ERROR]: " format "\e[0m\n", __FILE__, __LINE__, ##ARGS)

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

