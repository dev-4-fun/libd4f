#ifndef D4F__ARRAY_H
#define D4F__ARRAY_H

#include <stdlib.h>

#ifdef D4F__ARRAY_NS
#define Array d4f__Array
#define Array_create d4f__Array_create
#define Array_from d4f__Array_from
#define Array_clone d4f__Array_clone
#define Array_destroy d4f__Array_destroy
#define Array_get d4f__Array_get
#define Array_set d4f__Array_set
#define Array_length d4f__Array_length
#define Array_resize d4f__Array_resize
#endif

#ifdef __cplusplus
extern "C" {
#endif

    typedef void* d4f__Array;

    extern d4f__Array d4f__Array_create(const size_t capacity);
    extern d4f__Array d4f__Array_from(void* array, const size_t item_size, const size_t array_length);
    extern d4f__Array d4f__Array_clone(const d4f__Array self);
    extern void d4f__Array_destroy(d4f__Array self);
    extern void* d4f__Array_get(const d4f__Array self, const size_t index);
    extern void d4f__Array_set(d4f__Array self, const size_t index, void* item);
    extern size_t d4f__Array_length(const d4f__Array self);
    extern void d4f__Array_resize(d4f__Array self, const size_t new_capacity);

#ifdef __cplusplus
}
#endif

#endif

