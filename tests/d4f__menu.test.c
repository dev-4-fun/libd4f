#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "d4f__menu.h"

d4f__BOOL b_running;
d4f__Menu menu_main, menu_options, menu_current;

void handler_new_game(void);
void handler_load_game(void);
void handler_options(void);
void handler_exit(void);
void handler_options_audio();
void handler_options_video();
void handler_options_controls();
void handler_options_back();

d4f__Menu createMenu(d4f__MenuItemOptions options[], size_t num_items);
void createMainMenu(void);
void createOptionsMenu(void);
void showCurrentMenu(void);

void onInit(void);
void onExit(void);

int main() {
    onInit();

    while (b_running) {
        showCurrentMenu();
    }

    onExit();
    return 0;
}

void handler_new_game() {
    printf("New game selected\n");
}

void handler_load_game() {
    printf("Load game selected\n");
}

void handler_options() {
    menu_current = menu_options;
    showCurrentMenu();
}

void handler_exit() {
    b_running = FALSE;
}

void handler_options_audio() {
    printf("Options Audio selected\n");
}

void handler_options_video() {
    printf("Options Video selected\n");
}

void handler_options_controls() {
    printf("Options Controlls selected\n");
}

void handler_options_back() {
    menu_current = menu_main;
    showCurrentMenu();
}


d4f__Menu createMenu(d4f__MenuItemOptions options[], size_t num_items) {
    d4f__Menu menu = d4f__Menu_create(num_items);
    if (menu == NULL) {
        abort();
    }

    size_t i;
    for (i = 0; i < num_items; i++) {
        d4f__Menu_addItem(menu, options[i]);
    }

    return menu;
}

void createMainMenu() {
    d4f__MenuItemOptions options[] = {
        {
            .title = "New game",
            .handler = handler_new_game
        },
        {
            .title = "Load game",
            .handler = handler_load_game
        },
        {
            .title = "Options",
            .handler = handler_options
        },
        {
            .title = "Exit",
            .handler = handler_exit
        }
    };

    menu_main = createMenu(options, 4);
}

void createOptionsMenu() {
    d4f__MenuItemOptions options[] = {
        {
            .title = "Audio",
            .handler = handler_options_audio
        },
        {
            .title = "Video",
            .handler = handler_options_video
        },
        {
            .title = "Controls",
            .handler = handler_options_controls
        },
        {
            .title = "Back",
            .handler = handler_options_back
        }
    };

    menu_options = createMenu(options, 4);
}

void showCurrentMenu() {
    assert(menu_current != NULL);

    int i;
    int item_count = d4f__Menu_itemsCount(menu_current);

    for (i = 0; i < item_count; i++) {
        printf("%d) %s\n", i + 1, d4f__Menu_getItemTitle(menu_current, i));
    }

    int choice;
    printf("Your choice: ");
    scanf("%d", &choice);

    d4f__Menu_getItemHandler(menu_current, choice - 1)();
}

void onInit() {
    printf("Initializing app... ");
    createMainMenu();
    createOptionsMenu();

    if (menu_main == NULL || menu_options == NULL) {
        d4f__Menu_destroy(menu_main);
        d4f__Menu_destroy(menu_options);
        abort();
    }

    menu_current = menu_main;

    b_running = TRUE;
    printf("OK\n");
}

void onExit() {
    printf("Deinitializing app... ");
    d4f__Menu_destroy(menu_main);
    d4f__Menu_destroy(menu_options);
    printf("OK\n");
    printf("Good bye!\n");
}