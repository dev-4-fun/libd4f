#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "d4f__menu_item.h"

#define D4F__MENU_IMPORT
#include "d4f__menu.h"
#undef D4F__MENU_IMPORT

struct d4f__Menu {
    size_t size;
    size_t count;
    d4f__MenuItem* items;
};

d4f__Menu d4f__Menu_create(size_t size) {
    struct d4f__Menu* self = malloc(sizeof(*self));
    if (self == NULL) {
        return NULL;
    }

    d4f__MenuItem* items = malloc(size * sizeof(*items));
    if (items == NULL) {
        free(self);
        return NULL;
    }
    size_t i;
    for (i = 0; i < size; i++) {
        items[i] = NULL;
    }

    self->items = (d4f__MenuItem*)items;
    self->size = size;
    self->count = 0;

    return self;
}

void d4f__Menu_destroy(d4f__Menu self) {
    if (self == NULL) {
        return;
    }

    struct d4f__Menu* menu = self;
    size_t count = menu->count;
    size_t i = 0;

    for (i = 0; i < count; i++) {
        d4f__MenuItem item = menu->items[i];
        d4f__MenuItem_destroy(item);
    }

    free(self);
}

d4f__BOOL d4f__Menu_addItem(d4f__Menu self, const d4f__MenuItemOptions options) {
    assert(self != NULL);

    struct d4f__Menu* menu = self;
    size_t size = menu->size;
    size_t count = menu->count;

    assert(count < size);

    d4f__MenuItem item = d4f__MenuItem_create(options);
    if (item == NULL) {
        return FALSE;
    }

    menu->items[count] = item;
    menu->count++;

    return TRUE;
}

size_t d4f__Menu_itemsCount(const d4f__Menu self) {
    assert(self != NULL);

    struct d4f__Menu* menu = self;

    return menu->count;
}

const char* d4f__Menu_getItemTitle(const d4f__Menu self, size_t index) {
    assert(self != NULL);

    struct d4f__Menu* menu = self;
    assert(index < menu->size);

    d4f__MenuItem item = menu->items[index];
    if (item == NULL) {
        return NULL;
    }

    return d4f__MenuItem_getTitle(menu->items[index]);
}

d4f__MenuItemHandler d4f__Menu_getItemHandler(const d4f__Menu self, size_t index) {
    assert(self != NULL);

    struct d4f__Menu* menu = self;
    assert(index < menu->size);

    d4f__MenuItem item = menu->items[index];
    if (item == NULL) {
        return NULL;
    }

    return d4f__MenuItem_getHandler(menu->items[index]);
}
