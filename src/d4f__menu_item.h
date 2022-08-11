#ifndef D4F__MENU_ITEM_H
#define D4F__MENU_ITEM_H

#include "d4f__menu.h"

#ifdef D4F__MENU_ITEM_IMPORT
#define EXTERN
#else
#define EXTERN extern
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    typedef void* d4f__MenuItem;

    d4f__MenuItem d4f__MenuItem_create(d4f__MenuItemOptions options);
    void d4f__MenuItem_destroy(d4f__MenuItem self);
    const char* d4f__MenuItem_getTitle(const d4f__MenuItem self);
    d4f__MenuItemHandler d4f__MenuItem_getHandler(const d4f__MenuItem self);

    #ifdef __cplusplus
}
#endif

#undef EXTERN

#endif