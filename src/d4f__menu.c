#include <assert.h>
#include <stdlib.h>

#include "d4f__array.h"
#include "d4f__menu_item.h"

#define D4F__MENU_IMPORT
#include "d4f__menu.h"
#undef D4F__MENU_IMPORT

struct d4f__Menu {
    d4f__MenuItem* items;
};

d4f__Menu d4f__Menu_create(size_t capacity) {
    struct d4f__Menu* self = malloc(sizeof(*self));
    if (self == NULL) {
        return NULL;
    }

    d4f__MenuItem* items = d4f__Array_create(capacity);
    if (items == NULL) {
        free(self);
        return NULL;
    }

    self->items = items;

    return self;
}

void d4f__Menu_destroy(d4f__Menu self) {
    if (self == NULL) {
        return;
    }

    struct d4f__Menu* menu = self;
    size_t length = d4f__Array_length(menu->items);
    size_t i = 0;

    for (i = 0; i < length; i++) {
        d4f__MenuItem item = d4f__Array_get(menu->items, i);
        d4f__MenuItem_destroy(item);
    }

    free(self);
    self = NULL;
}

d4f__BOOL d4f__Menu_addItem(d4f__Menu self, const d4f__MenuItemOptions options) {
    assert(self != NULL);

    struct d4f__Menu* menu = self;

    d4f__MenuItem item = d4f__MenuItem_create(options);
    if (item == NULL) {
        return FALSE;
    }

    size_t length = d4f__Array_length(menu->items);

    d4f__Array_set(menu->items, length, item);

    return TRUE;
}

size_t d4f__Menu_length(const d4f__Menu self) {
    assert(self != NULL);

    struct d4f__Menu* menu = self;

    return d4f__Array_length(menu->items);
}

const char* d4f__Menu_getItemTitle(const d4f__Menu self, size_t index) {
    assert(self != NULL);

    struct d4f__Menu* menu = self;
    d4f__MenuItem item = d4f__Array_get(menu->items, index);

    return d4f__MenuItem_getTitle(item);
}

d4f__MenuItemHandler d4f__Menu_getItemHandler(const d4f__Menu self, size_t index) {
    assert(self != NULL);

    struct d4f__Menu* menu = self;
    d4f__MenuItem item = d4f__Array_get(menu->items, index);

    return d4f__MenuItem_getHandler(item);
}
