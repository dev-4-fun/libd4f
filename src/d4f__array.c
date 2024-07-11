#include <stdlib.h>
#include <assert.h>

#include "d4f__array.h"

typedef struct d4f__Array {
    size_t capacity;
    size_t length;
    void** items;
} _d4f__Array;

d4f__Array d4f__Array_create(const size_t capacity) {
	_d4f__Array* array;
	void** items;
	size_t i;

    assert(capacity > 0);

    array = malloc(sizeof(*array));
    if (array == NULL) {
        return NULL;
    }

    items = calloc(capacity, sizeof(*items));
    if (items == NULL) {
        free(array);
        return NULL;
    }
    for (i = 0; i < capacity; i++) {
        items[i] = NULL;
    }

    array->items = items;
    array->capacity = capacity;
    array->length = 0;

    return array;
}

d4f__Array d4f__Array_from(void* array, const size_t item_size, const size_t array_length) {
	_d4f__Array* clone;
	size_t i;
	void* p;

    assert(array != NULL);

    clone = d4f__Array_create(array_length);
    if (clone == NULL) {
        return NULL;
    }

    p = array;
    for (i = 0; i < array_length; i++) {
        clone->items[i] = p;
        p = (char *)p + item_size;
    }

    clone->length = array_length;

    return clone;
}

d4f__Array d4f__Array_clone(const d4f__Array self) {
	_d4f__Array* array;
	_d4f__Array* clone;
    size_t i;
    assert(self != NULL);

    array = self;
    clone = d4f__Array_create(array->capacity);
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
	_d4f__Array* array;
    assert(self != NULL);

    array = self;

    free(array->items);
    free(array);
}


void* d4f__Array_get(const d4f__Array self, const size_t index) {
	_d4f__Array* array;
    assert(self != NULL);

    array = self;
    assert(index < array->capacity);

    return array->items[index];
}


void d4f__Array_set(d4f__Array self, const size_t index, void* item) {
	_d4f__Array* array;
    assert(self != NULL);

    array = self;
    assert(index < array->capacity);

    array->items[index] = item;

    array->length = index < array->length ? array->length : index + 1;
}

size_t d4f__Array_length(const d4f__Array self) {
	_d4f__Array* array;
    assert(self != NULL);

    array = self;

    return array->length;
}

void d4f__Array_resize(d4f__Array self, const size_t new_capacity) {
    _d4f__Array* array;
	void** reallocated_items;
	size_t i;

    assert(self != NULL);

    array = self;
    assert(array->length <= new_capacity);

    reallocated_items = calloc(sizeof(*reallocated_items), new_capacity);

    for (i = 0; i < array->length; i++) {
        reallocated_items[i] = array->items[i];
    }
    free(array->items);

    array->capacity = new_capacity;
    array->items = reallocated_items;
}
