#ifndef D4F__MENU_H
#define D4F__MENU_H

#include <stdlib.h>

#include "d4f__bool.h"
#include "d4f__menu_types.h"

#ifdef D4F__MENU_NS
#define Menu d4f__Menu
#define MenuItemHandler d4f__MenuItemHandler
#define MenuItemOptions d4f__MenuItemOptions
#define Menu_create d4f__Menu_create
#define Menu_from d4f__Menu_from
#define Menu_destroy d4f__Menu_destroy
#define Menu_addItem d4f__Menu_addItem
#define Menu_length d4f__Menu_length
#define Menu_getItemTitle d4f__Menu_getItemTitle
#define Menu_getItemHandler d4f__Menu_getItemHandler
#endif

#ifdef __cplusplus
extern "C" {
#endif

    typedef void* d4f__Menu;

    extern d4f__Menu d4f__Menu_create(size_t capacity);
    extern d4f__Menu d4f__Menu_from(d4f__MenuItemOptions* options, const size_t options_length);
    extern void d4f__Menu_destroy(d4f__Menu self);
    extern d4f__BOOL d4f__Menu_addItem(
        d4f__Menu self,
        const d4f__MenuItemOptions options
    );
    extern size_t d4f__Menu_length(const d4f__Menu self);
    extern const char* d4f__Menu_getItemTitle(
        const d4f__Menu self,
        size_t index
    );
    extern d4f__MenuItemHandler d4f__Menu_getItemHandler(
        const d4f__Menu self,
        size_t index
    );


#ifdef __cplusplus
}
#endif

#endif 