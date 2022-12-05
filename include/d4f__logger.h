#ifndef d4f__logger_h
#define d4f__logger_h

#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#define d4f__log(format, ...) \
    fprintf(stdout, "%s:%d: \e[32m[LOG]: " format "\e[0m\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define d4f__warn(format, ...) \
    fprintf(stdout, "%s:%d \e[33m[WARNING]: " format "\e[0m\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define d4f__error(format, ...) \
    fprintf(stderr, "%s:%d \e[31m[ERROR]: " format "\e[0m\n", __FILE__, __LINE__, ##__VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif /* !d4f__logger_h */