#ifndef D4F__QUEUE_H
#define D4F__QUEUE_H

#include <stdlib.h>

#include "d4f__bool.h"

#ifdef D4F__QUEUE_NS
#define Queue d4f__Queue
#define Queue_create d4f__Queue_create
#define Queue_from d4f__Queue_from
#define Queue_clone d4f__Queue_clone
#define Queue_destroy d4f__Queue_destroy
#define Queue_add d4f__Queue_add
#define Queue_next d4f__Queue_next
#define Queue_length d4f__Queue_length
#define Queue_resize d4f__Queue_resize
#endif

#ifdef __cplusplus
extern "C" {
#endif

    typedef void* d4f__Queue;

    extern d4f__Queue d4f__Queue_create(void);
    extern d4f__Queue d4f__Queue_from(void* array, const size_t item_size, const size_t array_length);
    extern d4f__Queue d4f__Queue_clone(const d4f__Queue self);
    extern void d4f__Queue_destroy(d4f__Queue self);
    extern d4f__BOOL d4f__Queue_add(d4f__Queue self, void* item);
    extern void* d4f__Queue_next(d4f__Queue self);
    extern size_t d4f__Queue_length(const d4f__Queue self);

#ifdef __cplusplus
}
#endif

#endif /* !D4F__QUEUE_H */