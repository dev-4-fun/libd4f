#ifndef D4F__STRING_H
#define D4F__STRING_H

#include "d4f__bool.h"

#ifdef D4F__STRING_IMPORT
#define EXTERN
#else
#define EXTERN extern
#endif

#ifdef __cplusplus
extern "C" {
#endif

    typedef void* d4f__String;

    EXTERN d4f__String d4f__String_create(const char* string);
    EXTERN void d4f__String_destroy(d4f__String self);
    EXTERN const char* d4f__String_get(const d4f__String self);
    EXTERN d4f__BOOL d4f__String_equals(const d4f__String self, const d4f__String string);


#ifdef D4F__STRING_NS
#define String d4f__String
#define String_create d4f__String_create
#define String_destroy d4f__String_destroy
#define String_get d4f__String_get
#define String_equals d4f__String_equals
#endif

#ifdef __cplusplus
}
#endif

#undef EXTERN

#endif