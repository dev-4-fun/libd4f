#include <stdlib.h>

#include "d4f__bool.h"

#define D4F__APP_H_IMPL
#include "d4f__app.h"
#undef D4F__APP_H_IMPL

static d4f__BOOL quit_flag;
static d4f__AppOnInitFn onInit;
static d4f__AppOnExitFn onExit;
static d4f__AppOnUpdateFn onUpdate;

int d4f__App_init(const d4f__AppOptions options) {
    quit_flag = FALSE;

    onInit = options.onInit;
    onExit = options.onExit;
    onUpdate = options.onUpdate;

    if (onInit != NULL) {
        return onInit();
    }
    return 0;
}

int d4f__App_run(void) {
    int app_status = 0;

    if (onUpdate != NULL) {
        while (quit_flag == FALSE) {
            app_status = onUpdate();
        }

        if (onExit) {
            app_status = onExit();
        }
    }

    return app_status;
}

int d4f__App_exit(void) {
    quit_flag = TRUE;

    return 0;
}
