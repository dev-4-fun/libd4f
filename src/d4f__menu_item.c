#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "d4f__menu_item.h"

typedef struct d4f__MenuItem {
	char* title;
	d4f__MenuItemHandler handler;
} _d4f__MenuItem;

d4f__MenuItem d4f__MenuItem_create(d4f__MenuItemOptions options) {
	_d4f__MenuItem* item;
	char* title;

	assert(options.title != NULL);
	assert(options.handler != NULL);
	item = malloc(sizeof(*item));
	if (item == NULL) {
		return NULL;
	}
	title = malloc(sizeof(char) * (strlen(options.title) + 1));
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
	_d4f__MenuItem* item;

	if (self == NULL) {
		return;
	}
	item = self;
	free(item->title);
	free(item);
}

const char* d4f__MenuItem_getTitle(const d4f__MenuItem self) {
	_d4f__MenuItem* item;

	assert(self != NULL);
	item = self;
	return item->title;
}

d4f__MenuItemHandler d4f__MenuItem_getHandler(const d4f__MenuItem self) {
	_d4f__MenuItem* item;

	assert(self != NULL);
	item = self;
	return item->handler;
}
