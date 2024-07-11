#include <string.h>

#include "test_tool.h"

#define D4F__MENU_NS
#include "d4f__menu.h"
#undef D4F__MENU_NS

Menu menu;
void handler(void) {}
MenuItemOptions options[] = {
    {
        .title = "Title",
        .handler = handler
    },
};

void init(void);
void done(void);

void create(void);
void addItem(void);
void length(void);
void getItemTitle(void);
void getItemHandler(void);


TestSuite("d4f__Menu", init)

TestCase(create)
TestCase(addItem)
TestCase(length)
TestCase(getItemTitle)
TestCase(getItemHandler)

TestDone(done)


void init(void) {
    menu = Menu_create(2);
}

void done(void) {
    Menu_destroy(menu);
}

void create(void) {
    assert(menu != NULL);
}

void addItem(void) {
    Menu_addItem(menu, options[0]);
}

void length(void) {
    size_t length = Menu_length(menu);
    assert(length = 1);
}

void getItemTitle(void) {
    const char* title = Menu_getItemTitle(menu, 0);
    int result = strcmp(title, options[0].title);
    assert(result == 0);
}

void getItemHandler(void) {
    MenuItemHandler item_handler = Menu_getItemHandler(menu, 0);
    assert(item_handler == options[0].handler);
}
