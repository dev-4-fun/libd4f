#include <stdlib.h>
#include <assert.h>

#include "d4f__bool.h"

#define D4F__APP_IMPORT
#include "d4f__app.h"
#undef D4F__APP_IMPORT

struct d4f__App {
    d4f__BOOL b_running;
    d4f__AppOnInitFn onInit;
    d4f__AppOnUpdateFn onUpdate;
    d4f__AppOnExitFn onExit;
};

d4f__App d4f__App_create(const d4f__AppOptions options) {
    assert(options.onInit != NULL);
    assert(options.onUpdate != NULL);
    assert(options.onExit != NULL);

    struct d4f__App* app = malloc(sizeof(*app));
    if (app == NULL) {
        return NULL;
    }

    app->b_running = FALSE;
    app->onInit = options.onInit;
    app->onUpdate = options.onUpdate;
    app->onExit = options.onExit;

    app->onInit(app);

    return app;
}

void d4f__App_destroy(d4f__App self) {
    if (self != NULL) {
        free(self);
        self = NULL;
    }
}

void d4f__App_setOnInit(d4f__App self, d4f__AppOnInitFn fn) {
    assert(self != NULL);
    assert(fn != NULL);

    struct d4f__App* app = self;

    app->onInit = fn;
}

void d4f__App_setOnUpdate(d4f__App self, d4f__AppOnUpdateFn fn) {
    assert(self != NULL);
    assert(fn != NULL);

    struct d4f__App* app = self;

    app->onUpdate = fn;
}

void d4f__App_setOnExit(d4f__App self, d4f__AppOnExitFn fn) {
    assert(self != NULL);
    assert(fn != NULL);

    struct d4f__App* app = self;

    app->onExit = fn;
}

int d4f__App_run(d4f__App self) {
    assert(self != NULL);

    struct d4f__App* app = self;

    app->b_running = TRUE;

    while (app->b_running) {
        app->onUpdate(app);
    }

    app->onExit(app);

    return 0;
}

void d4f__App_exit(d4f__App self) {
    assert(self != NULL);

    struct d4f__App* app = self;

    app->b_running = FALSE;
}