#ifndef D4F__STACK_H
#define D4F__STACK_H

#include <stdlib.h>

#include "d4f__bool.h"

#ifdef D4F__STACK_NS
#define Stack d4f__Stack
#define Stack_create d4f__Stack_create
#define Stack_from d4f__Stack_from
#define Stack_clone d4f__Stack_clone
#define Stack_destroy d4f__Stack_destroy
#define Stack_push d4f__Stack_push
#define Stack_pop d4f__Stack_pop
#define Stack_length d4f__Stack_length
#endif

#ifdef __cplusplus
extern "C" {
#endif

    typedef void* d4f__Stack;

    extern d4f__Stack d4f__Stack_create(void);
    extern d4f__Stack d4f__Stack_from(void* array, const size_t item_size, const size_t array_length);
    extern d4f__Stack d4f__Stack_clone(const d4f__Stack self);
    extern void d4f__Stack_destroy(d4f__Stack self);
    extern d4f__BOOL d4f__Stack_push(d4f__Stack self, void* item);
    extern void* d4f__Stack_pop(d4f__Stack self);
    extern size_t d4f__Stack_length(const d4f__Stack self);

#ifdef __cplusplus
}
#endif

#endif /* !D4F__STACK_H */