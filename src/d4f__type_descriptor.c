#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>

#include "d4f__type_descriptor.h"

typedef struct TypeDescriptor {
    size_t size;
    void* (*ctor)(void* self, va_list* args);
    void (*dtor)(void* self);
    void* (*clone)(const void* self);
    int (*compare)(const void* a, const void* b);
} TypeDescriptor;

void* d4f__new(const void* type, ...) {
	TypeDescriptor* td;
	void* new_object;

    assert(type != NULL);
    td = (TypeDescriptor*)type;
    new_object = malloc(td->size);
    assert(new_object != NULL);
    *(TypeDescriptor**)new_object = td;
    if (td->ctor != NULL) {
        va_list args;
        va_start(args, type);
        td->ctor(new_object, &args);
        va_end(args);
    }
    return new_object;
}

void d4f__delete(void* self) {
    TypeDescriptor* td;
	
	td = *(TypeDescriptor**)self;
    if (td->dtor != NULL) {
        td->dtor(self);
    }
    free(self);
}
