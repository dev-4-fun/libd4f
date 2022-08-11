#ifndef D4F__MENU_H
#define D4F__MENU_H

#include "d4f__bool.h"

#ifdef D4F__MENU_IMPORT
#define EXTERN
#else
#define EXTERN extern
#endif

#ifdef __cplusplus
extern "C" {
#endif

    typedef void* d4f__Menu;
    typedef void (*d4f__MenuItemHandler)(void);
    typedef struct d4f__MenuItemOptions {
        const char* title;
        d4f__MenuItemHandler handler;
    } d4f__MenuItemOptions;

    EXTERN d4f__Menu d4f__Menu_create(size_t size);
    EXTERN void d4f__Menu_destroy(d4f__Menu self);
    EXTERN d4f__BOOL d4f__Menu_addItem(
        d4f__Menu self,
        const d4f__MenuItemOptions options
    );
    EXTERN size_t d4f__Menu_itemsCount(const d4f__Menu self);
    EXTERN const char* d4f__Menu_getItemTitle(
        const d4f__Menu self,
        size_t index
    );
    EXTERN d4f__MenuItemHandler d4f__Menu_getItemHandler(
        const d4f__Menu self,
        size_t index
    );

#ifdef __cplusplus
}
#endif

#undef EXTERN

#endif 