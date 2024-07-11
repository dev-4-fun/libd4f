#include "test_tool.h"

#define D4FLIB_NS
#include "d4flib.h"
#undef D4FLIB_NS

int on_init_called = 0;
int onAppInit(void) {
    on_init_called = 1;

    return 0;
}

int on_exit_called = 0;
int onAppExit(void) {
    on_exit_called = 1;

    return 0;
}

int on_update_called = 0;
int onAppUpdate(void) {
    on_update_called = 1;

    return App_exit();
}

void init(void);
void done(void);

void run(void);


TestSuite("d4f__App", init)

TestCase(run)

TestDone(done)


void init(void) {
	const AppOptions options = {
        .onExit = onAppExit, .onInit = onAppInit, .onUpdate = onAppUpdate,
	};
    App_init(options);
}

void done(void) {}

void run(void) {
    assert(on_init_called == 1);
    App_run();
    assert(on_update_called == 1);
    assert(on_exit_called == 1);
}
