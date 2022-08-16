#include <string.h>

#include "test_case.h"

#define D4F__MENU_NS
#include "d4f__menu.h"
#undef D4F__MENU_NS

Menu menu;
void handler() {};
MenuItemOptions options[] = {
    {
        .title = "Title",
        .handler = handler
    },
};

void init();
void done();

void create();
void addItem();
void length();
void getItemTitle();
void getItemHandler();


TestSuite("d4f__Menu", init);

TestCase(create);
TestCase(addItem);
TestCase(length);
TestCase(getItemTitle);
TestCase(getItemHandler);

TestDone(done);


void init() {
    menu = Menu_create(2);
}

void done() {
    Menu_destroy(menu);
}

void create() {
    assert(menu != NULL);
}

void addItem() {
    Menu_addItem(menu, options[0]);
}

void length() {
    size_t length = Menu_length(menu);
    assert(length = 1);
}

void getItemTitle() {
    const char* title = Menu_getItemTitle(menu, 0);
    int result = strcmp(title, options[0].title);
    assert(result == 0);
}

void getItemHandler() {
    MenuItemHandler item_handler = Menu_getItemHandler(menu, 0);
    assert(item_handler == options[0].handler);
}
