#include <assert.h>
#include <stdlib.h>

#include "d4f__string.h"

#define D4F__MENU_ITEM_IMPORT
#include "d4f__menu_item.h"
#undef D4F__MENU_ITEM_IMPORT

struct d4f__MenuItem {
    char* title;
    d4f__MenuItemHandler handler;
};

d4f__MenuItem d4f__MenuItem_create(d4f__MenuItemOptions options) {
    assert(options.title != NULL);
    assert(options.handler != NULL);

    struct d4f__MenuItem* item = malloc(sizeof(*item));
    if (item == NULL) {
        return NULL;
    }

    char* title = d4f__String_create(options.title);
    if (title == NULL) {
        free(item);
        return NULL;
    }

    item->title = title;
    item->handler = options.handler;

    return item;
}

void d4f__MenuItem_destroy(d4f__MenuItem self) {
    if (self == NULL) {
        return;
    }

    struct d4f__MenuItem* item = self;

    d4f__String_destroy(item->title);
    free(item);
}

const char* d4f__MenuItem_getTitle(const d4f__MenuItem self) {
    assert(self != NULL);

    struct d4f__MenuItem* item = self;

    return item->title;
}

d4f__MenuItemHandler d4f__MenuItem_getHandler(const d4f__MenuItem self) {
    assert(self != NULL);

    struct d4f__MenuItem* item = self;

    return item->handler;
}