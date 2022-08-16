#include "test_case.h"

#define D4F__APP_NS
#include "d4f__app.h"
#undef D4F__APP_NS

App app;
int on_init_called = 0;
void onAppInit() {
    on_init_called = 1;
}
int on_exit_called = 0;
void onAppExit() {
    on_exit_called = 1;
}
int on_update_called = 0;
void onAppUpdate() {
    on_update_called = 1;
    App_exit(app);
}

void init();
void done();

void create();
void run();
void app_exit();


TestSuite("d4f__app", init);

TestCase(create);
TestCase(run);
TestCase(app_exit);

TestDone(done);


void init() {
    app = App_create((AppOptions) {
        .onExit = onAppExit, .onInit = onAppInit, .onUpdate = onAppUpdate,
    });
}

void done() {
    App_destroy(app);
}

void create() {
    assert(app != NULL);
    assert(on_init_called == 1);
}

void run() {
    App_run(app);
    assert(on_update_called == 1);
    assert(on_exit_called == 1);
    on_exit_called = 0;
}

void app_exit() {
    App_exit(app);
    assert(on_exit_called == 1);
}
