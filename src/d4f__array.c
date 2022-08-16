#include <stdlib.h>
#include <assert.h>

#define D4F__ARRAY_IMPORT
#include "d4f__array.h"
#undef D4F__ARRAY_IMPORT

typedef struct d4f__Array {
    size_t capacity;
    size_t length;
    void** items;
} _d4f__Array;

d4f__Array d4f__Array_create(const size_t capacity) {
    assert(capacity > 0);

    _d4f__Array* array = malloc(sizeof(*array));
    if (array == NULL) {
        return NULL;
    }

    array->items = calloc(capacity, sizeof(*array->items));
    if (array->items == NULL) {
        free(array);
        return NULL;
    }

    size_t i;

    for (i = 0; i < capacity; i++) {
        array->items[i] = NULL;
    }
    array->capacity = capacity;
    array->length = 0;

    return array;
}

void d4f__Array_destroy(d4f__Array self) {
    assert(self != NULL);

    _d4f__Array* array = self;
    free(array->items);
    array->items = NULL;

    free(self);
    self = NULL;
}


d4f__Array d4f__Array_clone(const d4f__Array self) {
    assert(self != NULL);

    _d4f__Array* array = self;
    _d4f__Array* clone = d4f__Array_create(array->capacity);

    size_t i;
    for (i = 0; i < array->length; i++) {
        clone->items[i] = array->items[i];
    }

    clone->length = array->length;

    return clone;
}


void* d4f__Array_get(const d4f__Array self, const size_t index) {
    assert(self != NULL);

    _d4f__Array* array = self;
    assert(index < array->capacity);

    return array->items[index];
}


void d4f__Array_set(d4f__Array self, const size_t index, void* item) {
    assert(self != NULL);

    _d4f__Array* array = self;
    assert(index < array->capacity);

    array->items[index] = item;

    array->length = index < array->length ? array->length : index + 1;
}

size_t d4f__Array_length(const d4f__Array self) {
    assert(self != NULL);

    _d4f__Array* array = self;

    return array->length;
}

void d4f__Array_resize(d4f__Array self, const size_t new_capacity) {
    assert(self != NULL);

    _d4f__Array* array = self;
    assert(array->length <= new_capacity);

    void** reallocated_items = calloc(sizeof(*reallocated_items), new_capacity);

    size_t i;
    for (i = 0; i < array->length; i++) {
        reallocated_items[i] = array->items[i];
    }
    free(array->items);

    array->capacity = new_capacity;
    array->items = reallocated_items;
}