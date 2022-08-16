#include <stdio.h>
#include <assert.h>

#include "test_case.h"
#define D4F__ARRAY_NS
#include "d4f__array.h"

Array arr = NULL;
int items[] = { 1, 2, 3, 4 };

void init(void);
void done(void);

void create(void);
void clone(void);
void set(void);
void get(void);
void resize(void);
void length(void);

int main() {
    TestSuite("d4f__Array", init);

    TestCase(create);
    TestCase(clone);
    TestCase(get);
    TestCase(set);
    TestCase(resize);
    TestCase(length);

    TestDone(done);
    return 0;
}

void init() {
    arr = Array_create(10);
}

void done() {
    Array_destroy(arr);
}

void create() {
    assert(arr != NULL);
}

void clone() {
    Array clone = Array_clone(arr);

    assert(clone != arr);
    assert((Array_get(clone, 0)) == (Array_get(arr, 0)));
    Array_set(clone, 0, &items[0]);
    assert((Array_get(clone, 0)) != (Array_get(arr, 0)));

    Array_destroy(clone);
}

void get() {
    int* x = Array_get(arr, 0);
    assert(x == NULL);
}

void set() {
    int* p_element;
    Array_set(arr, 0, &items[1]);
    p_element = Array_get(arr, 0);
    assert(&items[1] == p_element);
}

void resize() {
    Array_resize(arr, 15);
    Array_set(arr, 14, &items[2]);
    assert((Array_get(arr, 14)) != NULL);
}

void length() {
    assert((Array_length(arr)) == 15);
}

#undef D4F__ARRAY_NS