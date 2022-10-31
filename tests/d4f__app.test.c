#include "test_tool.h"

#define D4FLIB_NS
#include "d4flib.h"
#undef D4FLIB_NS

int on_init_called = 0;
int onAppInit() {
    on_init_called = 1;

    return 0;
}

int on_exit_called = 0;
int onAppExit() {
    on_exit_called = 1;

    return 0;
}

int on_update_called = 0;
int onAppUpdate() {
    on_update_called = 1;

    return App_exit();
}

void init();
void done();

void run();


TestSuite("d4f__App", init);

TestCase(run);

TestDone(done);


void init() {
    App_init((AppOptions) {
        .onExit = onAppExit, .onInit = onAppInit, .onUpdate = onAppUpdate,
    });
}

void done() {}

void run() {
    assert(on_init_called == 1);
    App_run();
    assert(on_update_called == 1);
    assert(on_exit_called == 1);
}
