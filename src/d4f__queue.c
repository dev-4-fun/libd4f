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


d4f__Queue d4f__Queue_create(void) {
    _d4f__Queue* self;

	self = malloc(sizeof(*self));
    if (self == NULL) {
        return NULL;
    }
    self->length = 0;
    self->next = NULL;
    self->last = NULL;
    return self;
}

d4f__Queue d4f__Queue_from(void* array, const size_t item_size, const size_t array_length) {
	_d4f__Queue* clone;
    size_t i;
	void* p;

    assert(array != NULL);
    clone = d4f__Queue_create();
    if (clone == NULL) {
        return NULL;
    }
    p = array;
    for (i = 0; i < array_length; i++) {
        d4f__Queue_add(clone, p);
        p = (char *)p + item_size;
    }
    return clone;
}

d4f__Queue d4f__Queue_clone(const d4f__Queue self) {
	_d4f__Queue* queue;
	_d4f__Queue* clone;
	_d4f__QueueNode* node;

    assert(self != NULL);
    queue = self;
    clone = d4f__Queue_create();
    if (clone == NULL) {
        return NULL;
    }
    node = queue->next;
    while (node != NULL) {
        d4f__Queue_add(clone, node->item);
        node = node->next;
    }
    return clone;
}

void d4f__Queue_destroy(d4f__Queue self) {
	_d4f__Queue* queue;
	_d4f__QueueNode* node;

    assert(self != NULL);
    queue = self;
    node = queue->next;
    while (node != NULL) {
        _d4f__QueueNode* temp = node->next;
        free(node);
        node = temp;
    }
    free(queue);
}

d4f__BOOL d4f__Queue_add(d4f__Queue self, void* item) {
	_d4f__Queue* queue;
	_d4f__QueueNode* node;
	_d4f__QueueNode* last;

    assert(self != NULL);
    queue = self;
    node = malloc(sizeof(*node));
    if (node == NULL) {
        return FALSE;
    }
    node->item = item;
    node->next = NULL;
    last = queue->last;
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
	_d4f__Queue* queue;
	_d4f__QueueNode* node;
	_d4f__QueueNode* tmp;
	void* item;

    assert(self != NULL);
    queue = self;
    node = queue->next;
    if (node == NULL) {
        return NULL;
    }
    tmp = node->next;
    item = node->item;
    free(node);
    queue->next = tmp;
    queue->length--;
    return item;
}

size_t d4f__Queue_length(const d4f__Queue self) {
	_d4f__Queue* queue;

    assert(self != NULL);
    queue = self;
    return queue->length;
}
