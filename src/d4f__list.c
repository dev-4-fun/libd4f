#include <assert.h>
#include <stdlib.h>

#include "d4f__list.h"

typedef struct d4f__ListNode {
    void* item;
    struct d4f__ListNode* next;
} _d4f__ListNode;

typedef struct d4f__List {
    size_t length;
    _d4f__ListNode* first;
} _d4f__List;

static _d4f__ListNode* __get(_d4f__List* list, const size_t index);

d4f__List d4f__List_create(void) {
    _d4f__List* self = malloc(sizeof(*self));

    if (self == NULL) {
        return NULL;
    }
    self->length = 0;
    self->first = NULL;
    return self;
}

d4f__List d4f__List_from(void* array, const size_t item_size, const size_t array_length) {
	_d4f__List* clone;
	size_t i;
	void* p;

    assert(array != NULL);
    clone = d4f__List_create();
    if (clone == NULL) {
        return NULL;
    }
    p = array;
    for (i = 0; i < array_length; i++) {
        d4f__List_append(clone, p);
        p = (char *)p + item_size;
    }
    return clone;
}

d4f__List d4f__List_clone(const d4f__List self) {
	_d4f__List* list;
	_d4f__List* clone;
	_d4f__ListNode* node;
	size_t i;
	void* item;

    assert(self != NULL);
    list = self;
    clone = d4f__List_create();
    if (clone == NULL) {
        return NULL;
    }
    node = list->first;
    if (node == NULL) {
        return clone;
    }
    item = node->item;
    for (i = 0; i < list->length; i++) {
        d4f__List_set(clone, i, item);
        node = node->next;
    }
    return clone;
}

void d4f__List_destroy(d4f__List self) {
	_d4f__List* list;
	_d4f__ListNode* node;

    assert(self != NULL);
    list = self;
    node = list->first;
    while (node != NULL) {
        _d4f__ListNode* tmp = node->next;
        free(node);
        node = tmp;
    }
    free(list);
}


void* d4f__List_get(const d4f__List self, const size_t index) {
	_d4f__List* list;
	_d4f__ListNode* node;

    assert(self != NULL);
    list = self;
    assert(index < list->length);
    node = __get(list, index);
    return node->item;
}

void d4f__List_set(d4f__List self, const size_t index, void* item) {
	_d4f__List* list;
	_d4f__ListNode* node;

    assert(self != NULL);
    list = self;
    assert(index < list->length);
    node = __get(list, index);
    node->item = item;
}

d4f__BOOL d4f__List_append(d4f__List self, void* item) {
	_d4f__List* list;
	_d4f__ListNode* node;
	_d4f__ListNode* last;

    assert(self != NULL);
    list = self;
    node = malloc(sizeof(*node));
    if (node == NULL) {
        return FALSE;
    }
    list->length++;
    node->item = item;
    node->next = NULL;
    if (list->first == NULL) {
        list->first = node;
        return TRUE;
    }
    last = __get(list, d4f__List_length(list) - 1);
    last->next = node;
    return TRUE;
}

d4f__BOOL d4f__List_insert(d4f__List self, const size_t index, void* item) {
	_d4f__List* list;
	_d4f__ListNode* node;
	_d4f__ListNode* prev;
	_d4f__ListNode* next; 

    assert(self != NULL);
    list = self;
    node = malloc(sizeof(*node));
    if (node == NULL) {
        return FALSE;
    }
    node->item = item;
    list->length++;
    if (index == 0) {
        node->next = list->first;
        list->first = node;
        return TRUE;
    }
    prev = __get(list, index - 1);
    next = prev->next;
    node->next = next;
    prev->next = node;
    return TRUE;
}

d4f__BOOL d4f__List_remove(d4f__List self, const size_t index) {
	_d4f__List* list;
	_d4f__ListNode* node;
	_d4f__ListNode* prev;
	
    assert(self != NULL);
    list = self;
    list->length--;
    if (index == 0) {
        node = list->first;
        list->first = node->next;
        free(node);
        return TRUE;
    }
    prev = __get(list, index - 1);
    node = prev->next;
    prev->next = node->next;
    free(node);
    return TRUE;
}

extern size_t d4f__List_length(const d4f__List self) {
	_d4f__List* list;

    assert(self != NULL);
    list = self;
    return list->length;
}

_d4f__ListNode* __get(_d4f__List* list, const size_t index) {
    size_t i;
    _d4f__ListNode* node = list->first;

    if (index > 0) {
        for (i = 0; i < index - 1; i++) {
            node = node->next;
        }
    }
    return node;
}
