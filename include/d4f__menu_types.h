#ifndef D4F__MENU_TYPES_H
#define D4F__MENU_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef void (*d4f__MenuItemHandler)(void);
    typedef struct d4f__MenuItemOptions {
        const char* title;
        d4f__MenuItemHandler handler;
    } d4f__MenuItemOptions;

#ifdef __cplusplus
}
#endif

#endif

