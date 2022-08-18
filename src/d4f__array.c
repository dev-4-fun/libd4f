#include <stdlib.h>
#include <assert.h>

#include "d4f__array.h"

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

    void** items = calloc(capacity, sizeof(*items));
    if (items == NULL) {
        free(array);
        return NULL;
    }
    size_t i;
    for (i = 0; i < capacity; i++) {
        items[i] = NULL;
    }

    array->items = items;
    array->capacity = capacity;
    array->length = 0;

    return array;
}

d4f__Array d4f__Array_from(void* array, const size_t item_size, const size_t array_length) {
    assert(array != NULL);

    _d4f__Array* clone = d4f__Array_create(array_length);
    if (clone == NULL) {
        return NULL;
    }

    size_t i;
    void* p = array;
    for (i = 0; i < array_length; i++) {
        clone->items[i] = p;
        p += item_size;
    }

    clone->length = array_length;

    return clone;
}

d4f__Array d4f__Array_clone(const d4f__Array self) {
    assert(self != NULL);

    size_t i;
    _d4f__Array* array = self;
    _d4f__Array* clone = d4f__Array_create(array->capacity);
    if (clone == NULL) {
        return NULL;
    }

    for (i = 0; i < array->length; i++) {
        clone->items[i] = array->items[i];
    }

    clone->length = array->length;

    return clone;
}

void d4f__Array_destroy(d4f__Array self) {
    assert(self != NULL);

    _d4f__Array* array = self;

    free(array->items);
    free(array);
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