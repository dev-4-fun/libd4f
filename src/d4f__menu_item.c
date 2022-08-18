#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "d4f__menu_item.h"

typedef struct d4f__MenuItem {
    char* title;
    d4f__MenuItemHandler handler;
} _d4f__MenuItem;

d4f__MenuItem d4f__MenuItem_create(d4f__MenuItemOptions options) {
    assert(options.title != NULL);
    assert(options.handler != NULL);

    _d4f__MenuItem* item = malloc(sizeof(*item));
    if (item == NULL) {
        return NULL;
    }

    char* title = malloc(sizeof(char) * (strlen(options.title) + 1));
    if (title == NULL) {
        free(item);
        return NULL;
    }
    strcpy(title, options.title);

    item->title = title;
    item->handler = options.handler;

    return item;
}

void d4f__MenuItem_destroy(d4f__MenuItem self) {
    if (self == NULL) {
        return;
    }

    _d4f__MenuItem* item = self;

    free(item->title);
    free(item);
}

const char* d4f__MenuItem_getTitle(const d4f__MenuItem self) {
    assert(self != NULL);

    _d4f__MenuItem* item = self;

    return item->title;
}

d4f__MenuItemHandler d4f__MenuItem_getHandler(const d4f__MenuItem self) {
    assert(self != NULL);

    _d4f__MenuItem* item = self;

    return item->handler;
}