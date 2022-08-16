#include <string.h>

#include "test_case.h"

#define D4F__STRING_NS
#include "d4f__string.h"
#undef D4F__STRING_NS

String string;
const char* test_string = "Test";
char test_string2[] = "Test2";

void init();
void done();

void create();
void get();
void equals();


TestSuite("d4f__String", init);

TestCase(create);
TestCase(get);
TestCase(equals);

TestDone(done);


void init() {
    string = String_create(test_string);
}

void done() {
    String_destroy(string);
}

void create() {
    assert(string != NULL);
}

void get() {
    const char* string_value = String_get(string);
    assert(strcmp(string_value, test_string) == 0);
}

void equals() {
    assert(String_equals(string, (String)test_string) == TRUE);
    assert(String_equals((String)test_string, string) == TRUE);
    assert(String_equals(string, (String)test_string2) == FALSE);
}