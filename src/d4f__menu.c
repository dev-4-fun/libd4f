#include <assert.h>
#include <stdlib.h>

#include "d4f__array.h"
#include "d4f__menu_item.h"

#include "d4f__menu.h"

typedef struct d4f__Menu {
    d4f__MenuItem* items;
} _d4f__Menu;

d4f__Menu d4f__Menu_create(size_t capacity) {
    _d4f__Menu* self;
	d4f__MenuItem* items;

	self = malloc(sizeof(*self));
    if (self == NULL) {
        return NULL;
    }
    items = d4f__Array_create(capacity, sizeof(d4f__MenuItem));
    if (items == NULL) {
        free(self);
        return NULL;
    }
    self->items = items;
    return self;
}

d4f__Menu d4f__Menu_from(d4f__MenuItemOptions* options, const size_t options_length) {
	_d4f__Menu* self;
    size_t i;

    self = d4f__Menu_create(options_length);
    for (i = 0; i < options_length; i++) {
        d4f__Menu_addItem(self, options[i]);
    }
    return self;
}

void d4f__Menu_destroy(d4f__Menu self) {
	_d4f__Menu* menu;
	size_t i, length;

    if (self == NULL) {
        return;
    }
    menu = self;
    length = d4f__Array_length(menu->items);
    for (i = 0; i < length; i++) {
        d4f__MenuItem item = (d4f__MenuItem)d4f__Array_at(menu->items, i);
        d4f__MenuItem_destroy(item);
    }
    d4f__Array_destroy(menu->items);
    free(menu);
}

d4f__BOOL d4f__Menu_addItem(d4f__Menu self, const d4f__MenuItemOptions options) {
	_d4f__Menu* menu;
	d4f__MenuItem item;
	d4f__MenuItem* p_element;
	size_t length;

    assert(self != NULL);
    menu = self;
    item = d4f__MenuItem_create(options);
    if (item == NULL) {
        return FALSE;
    }
    length = d4f__Array_length(menu->items);
    p_element = (d4f__MenuItem*)d4f__Array_at(menu->items, length);
	*p_element = item;
    return TRUE;
}

size_t d4f__Menu_length(const d4f__Menu self) {
	_d4f__Menu* menu;

    assert(self != NULL);
    menu = self;
    return d4f__Array_length(menu->items);
}

const char* d4f__Menu_getItemTitle(const d4f__Menu self, size_t index) {
	_d4f__Menu* menu;
	d4f__MenuItem *item;
	
    assert(self != NULL);
    menu = self;
    item = (d4f__MenuItem *)d4f__Array_at(menu->items, index);
    return d4f__MenuItem_getTitle(*item);
}

d4f__MenuItemHandler d4f__Menu_getItemHandler(const d4f__Menu self, size_t index) {
	_d4f__Menu* menu;
	d4f__MenuItem* item;

    assert(self != NULL);
    menu = self;
    item = (d4f__MenuItem *)d4f__Array_at(menu->items, index);
    return d4f__MenuItem_getHandler(*item);
}
