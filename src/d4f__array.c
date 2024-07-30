#include <stdlib.h>
#include <assert.h>

#include "d4f__array.h"

typedef struct d4f__Array {
    size_t capacity;
    size_t length;
	size_t item_size;
    d4f__byte* data;
} _d4f__Array;

d4f__Array d4f__Array_create(const size_t capacity, const size_t item_size) {
	_d4f__Array* array;
	d4f__byte* data;
	size_t full_size;
	size_t i;

    assert(capacity > 0);

    array = malloc(sizeof(*array));
    if (array == NULL) {
        return NULL;
    }

	full_size = capacity * item_size;
    data = malloc(full_size);
    if (data == NULL) {
        free(array);
        return NULL;
    }
    for (i = 0; i < full_size; i++) {
        data[i] = 0;
    }

    array->data = data;
    array->capacity = capacity;
    array->length = 0;
	array->item_size = item_size;

    return array;
}

d4f__Array d4f__Array_from(d4f__byte* array, const size_t item_size, const size_t array_length) {
	_d4f__Array* clone;
	size_t i;
	size_t full_size;
	d4f__byte* p;

    assert(array != NULL);

    clone = d4f__Array_create(array_length, item_size);
    if (clone == NULL) {
        return NULL;
    }

	full_size = array_length * item_size;
    p = array;
    for (i = 0; i < full_size; i++, p++) {
        clone->data[i] = *p;
    }

    clone->length = array_length;

    return clone;
}

d4f__Array d4f__Array_clone(const d4f__Array self) {
	_d4f__Array* array;
	_d4f__Array* clone;
    size_t i;
	size_t full_size;
    assert(self != NULL);

    array = self;
    clone = d4f__Array_create(array->capacity, array->item_size);
    if (clone == NULL) {
        return NULL;
    }

	full_size = array->length * array->item_size;
    for (i = 0; i < full_size; i++) {
        clone->data[i] = array->data[i];
    }

    clone->length = array->length;

    return clone;
}

void d4f__Array_destroy(d4f__Array self) {
	_d4f__Array* array;
    assert(self != NULL);

    array = self;

    free(array->data);
    free(array);
}


d4f__byte* d4f__Array_at(const d4f__Array self, const size_t index) {
	_d4f__Array* array;
    assert(self != NULL);

    array = self;
    assert(index < array->capacity);

    return &array->data[index * array->item_size];
}


size_t d4f__Array_length(const d4f__Array self) {
	_d4f__Array* array;
    assert(self != NULL);

    array = self;

    return array->length;
}

void d4f__Array_resize(d4f__Array self, const size_t new_capacity) {
    _d4f__Array* array;
	size_t full_size;

    assert(self != NULL);

    array = self;
    assert(array->length <= new_capacity);

	full_size = array->item_size * new_capacity;
    array->data = realloc(array->data, full_size);
	if (array->data == NULL) {
		array->length = 0;
		array->capacity = 0;
		return;
	}

    array->capacity = new_capacity;
}
