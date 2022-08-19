#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "d4f__bool.h"
#include "d4f__app.h"

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

    atexit(app->onExit);

    app->onInit();

    return app;
}

void d4f__App_destroy(d4f__App self) {
    if (self == NULL) {
        return;
    }

    free(self);
}

int d4f__App_run(d4f__App self) {
    assert(self != NULL);

    struct d4f__App* app = self;

    app->b_running = TRUE;

    while (app->b_running) {
        app->onUpdate((float)clock() / CLOCKS_PER_SEC);
    }

    return 0;
}

void d4f__App_exit(d4f__App self) {
    assert(self != NULL);

    struct d4f__App* app = self;

    app->b_running = FALSE;

    app->onExit();
}