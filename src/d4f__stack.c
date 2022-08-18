#include <assert.h>
#include <stdlib.h>

#include "d4f__bool.h"
#include "d4f__stack.h"

typedef struct d4f__StackNode {
    void* item;
    struct d4f__StackNode* next;
} _d4f__StackNode;

typedef struct d4f__Stack {
    size_t length;
    _d4f__StackNode* top;
} _d4f__Stack;

d4f__Stack d4f__Stack_create() {
    _d4f__Stack* self = malloc(sizeof(*self));
    if (self == NULL) {
        return NULL;
    }

    self->length = 0;
    self->top = NULL;

    return self;
}

d4f__Stack d4f__Stack_from(void* array, const size_t item_size, const size_t array_length) {
    assert(array != NULL);

    _d4f__Stack* clone = d4f__Stack_create();
    if (clone == NULL) {
        return NULL;
    }

    size_t i;
    void* p = array;
    for (i = 0; i < array_length; i++) {
        d4f__Stack_push(clone, p);
        p += item_size;
    }

    return clone;
}

d4f__Stack d4f__Stack_clone(const d4f__Stack self) {
    assert(self != NULL);

    _d4f__Stack* stack = self;
    _d4f__Stack* clone = d4f__Stack_create();
    if (clone == NULL) {
        return NULL;
    }

    if (stack->top == NULL) {
        return clone;
    }

    void** items = malloc(sizeof(*items) * stack->length);
    if (items == NULL) {
        d4f__Stack_destroy(clone);
        return NULL;
    }

    size_t i;
    _d4f__StackNode* node = stack->top;
    for (i = stack->length - 1; i >= 0; i--) {
        items[i] = node->item;
        node = node->next;
    }

    for (i = 0; i < stack->length; i++) {
        d4f__Stack_push(clone, items[i]);
    }

    free(items);

    return clone;
}

void d4f__Stack_destroy(d4f__Stack self) {
    assert(self != NULL);

    _d4f__Stack* stack = self;
    _d4f__StackNode* node = stack->top;
    while (node != NULL) {
        _d4f__StackNode* tmp = node->next;
        free(node);
        node = tmp;
    }

    free(stack);
}

d4f__BOOL d4f__Stack_push(d4f__Stack self, void* item) {
    assert(self != NULL);

    _d4f__Stack* stack = self;
    _d4f__StackNode* node = malloc(sizeof(*node));
    if (node == NULL) {
        return FALSE;
    }

    node->item = item;
    node->next = stack->top;

    stack->top = node;
    stack->length++;

    return TRUE;
}

void* d4f__Stack_pop(d4f__Stack self) {
    assert(self != NULL);

    _d4f__Stack* stack = self;
    _d4f__StackNode* node = stack->top;
    if (node == NULL) {
        return NULL;
    }

    void* item = node->item;

    stack->top = node->next;
    stack->length--;

    free(node);

    return item;
}

size_t d4f__Stack_length(const d4f__Stack self) {
    assert(self != NULL);

    const _d4f__Stack* stack = self;

    return stack->length;
}