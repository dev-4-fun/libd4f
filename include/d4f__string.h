#ifndef D4F__STRING_H
#define D4F__STRING_H

#ifdef D4F__STRING_IMPORT
#define EXTERN
#else
#define EXTERN extern
#endif

#ifdef __cplusplus
extern "C" {
#endif

    EXTERN char* d4f__String_create(const char* c_string);
    EXTERN void d4f__String_destroy(char* str);

#ifdef __cplusplus
}
#endif

#undef EXTERN

#endif