#ifndef D4F__LIST_H
#define D4F__LIST_H

#include <stdlib.h>

#include "d4f__bool.h"

#ifdef D4F__LIST_NS
#define List d4f__List
#define List_create d4f__List_create
#define List_from d4f__List_from
#define List_clone d4f__List_clone
#define List_destroy d4f__List_destroy
#define List_get d4f__List_get
#define List_set d4f__List_set
#define List_append d4f__List_append
#define List_insert d4f__List_insert
#define List_remove d4f__List_remove
#define List_length d4f__List_length
#endif

#ifdef __cplusplus
extern "C" {
#endif

    typedef void* d4f__List;

    extern d4f__List d4f__List_create(void);
    extern d4f__List d4f__List_from(void* array, const size_t item_size, const size_t array_length);
    extern d4f__List d4f__List_clone(const d4f__List self);
    extern void d4f__List_destroy(d4f__List self);
    extern void* d4f__List_get(const d4f__List self, const size_t index);
    extern void d4f__List_set(d4f__List self, const size_t index, void* item);
    extern d4f__BOOL d4f__List_append(d4f__List self, void* item);
    extern d4f__BOOL d4f__List_insert(d4f__List self, const size_t index, void* item);
    extern d4f__BOOL d4f__List_remove(d4f__List self, const size_t index);
    extern size_t d4f__List_length(const d4f__List self);

#ifdef __cplusplus
}
#endif

#endif /* !D4F__LIST_H */