#include "test_tool.h"

#define D4FLIB_NS
#include "d4flib.h"
#undef D4FLIB_NS

void init(void);
void done(void);

void collide(void);

TestSuite("d4f__Coord2d", init);
TestCase(collide);
TestDone(done);

void init() {}

void done() {}

void collide() {
    d4f__Coord2d a = { .x = 1, .y = 1 };
    d4f__Coord2d b = { .x = 1, .y = 1 };
    assert(d4f__Coord2d_collide(a, b));

    b.y = 2;
    assert(!d4f__Coord2d_collide(a, b));
}