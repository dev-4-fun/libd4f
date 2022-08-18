#include <assert.h>
#include <stdlib.h>

#include "d4f__bool.h"
#include "d4f__queue.h"

typedef struct d4f__QueueNode {
    void* item;
    struct d4f__QueueNode* next;
} _d4f__QueueNode;

typedef struct d4f__Queue {
    size_t length;
    _d4f__QueueNode* next;
    _d4f__QueueNode* last;
} _d4f__Queue;


d4f__Queue d4f__Queue_create() {
    _d4f__Queue* self = malloc(sizeof(*self));
    if (self == NULL) {
        return NULL;
    }

    self->length = 0;
    self->next = NULL;
    self->last = NULL;

    return self;
}

d4f__Queue d4f__Queue_from(void* array, const size_t item_size, const size_t array_length) {
    assert(array != NULL);

    _d4f__Queue* clone = d4f__Queue_create();
    if (clone == NULL) {
        return NULL;
    }

    size_t i;
    void* p = array;
    for (i = 0; i < array_length; i++) {
        d4f__Queue_add(clone, p);
        p += item_size;
    }

    return clone;
}

d4f__Queue d4f__Queue_clone(const d4f__Queue self) {
    assert(self != NULL);

    _d4f__Queue* queue = self;
    _d4f__Queue* clone = d4f__Queue_create();
    if (clone == NULL) {
        return NULL;
    }

    _d4f__QueueNode* node = queue->next;
    while (node != NULL) {
        d4f__Queue_add(clone, node->item);
        node = node->next;
    }

    return clone;
}

void d4f__Queue_destroy(d4f__Queue self) {
    assert(self != NULL);

    _d4f__Queue* queue = self;
    _d4f__QueueNode* node = queue->next;

    while (node != NULL) {
        _d4f__QueueNode* temp = node->next;
        free(node);
        node = temp;
    }

    free(queue);
}

d4f__BOOL d4f__Queue_add(d4f__Queue self, void* item) {
    assert(self != NULL);

    _d4f__Queue* queue = self;
    _d4f__QueueNode* node = malloc(sizeof(*node));
    if (node == NULL) {
        return FALSE;
    }

    node->item = item;
    node->next = NULL;

    _d4f__QueueNode* last = queue->last;
    if (queue->next == NULL) {
        queue->next = last = node;
    } else {
        last->next = node;
        last = last->next;
    }

    queue->last = last;
    queue->length++;

    return TRUE;
}

void* d4f__Queue_next(d4f__Queue self) {
    assert(self != NULL);

    _d4f__Queue* queue = self;
    _d4f__QueueNode* node = queue->next;
    if (node == NULL) {
        return NULL;
    }

    _d4f__QueueNode* tmp = node->next;
    void* item = node->item;

    free(node);

    queue->next = tmp;
    queue->length--;

    return item;
}

size_t d4f__Queue_length(const d4f__Queue self) {
    assert(self != NULL);

    const _d4f__Queue* queue = self;

    return queue->length;
}