#include "test_tool.h"
#include "d4f__logger.h"

void init(void);
void done(void);

void dlog(void);
void dwarn(void);
void derror(void);

TestSuite("d4f__logger", init)

TestCase(dlog)
TestCase(dwarn)
TestCase(derror)

TestDone(done)

void init(void) {}

void done(void) {}

void dlog(void) {
	d4f__log1("Hello %s!\n", "Dima");
}

void dwarn(void) {
	d4f__warn1("Hello %s!\n", "Dima");
}

void derror(void) {
	d4f__error1("Hello %s!\n", "Dima");
}
