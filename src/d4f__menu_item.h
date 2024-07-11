#ifndef D4F__MENU_ITEM_H
#define D4F__MENU_ITEM_H

#include "d4f__menu_types.h"

#ifdef __cplusplus
extern "C" {
#endif

    typedef void* d4f__MenuItem;

    extern d4f__MenuItem d4f__MenuItem_create(const d4f__MenuItemOptions options);
    extern void d4f__MenuItem_destroy(const d4f__MenuItem self);
    extern const char* d4f__MenuItem_getTitle(const d4f__MenuItem self);
    extern d4f__MenuItemHandler d4f__MenuItem_getHandler(const d4f__MenuItem self);

#ifdef __cplusplus
}
#endif

#endif

