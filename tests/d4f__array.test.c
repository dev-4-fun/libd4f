#include "test_tool.h"

#define D4F__ARRAY_NS
#include "d4f__array.h"
#undef D4F__ARRAY_NS

Array arr = NULL;
int items[] = { 1, 2, 3, 4 };

void init(void);
void done(void);

void create(void);
void from(void);
void clone(void);
void set(void);
void get(void);
void resize(void);
void length(void);


TestSuite("d4f__Array", init)

TestCase(create)
TestCase(from)
TestCase(clone)
TestCase(get)
TestCase(set)
TestCase(resize)
TestCase(length)

TestDone(done)


void init(void) {
    arr = Array_create(10, sizeof(int));
}

void done(void) {
    Array_destroy(arr);
}

void create(void) {
    assert(arr != NULL);
}

void from(void) {
    Array clone = Array_from((byte *)items, sizeof(int), 4);
    assert(&items[3] == (int *)Array_at(clone, 3));
}

void clone(void) {
	int* p_element;
    Array clone = Array_clone(arr);

    assert(clone != arr);
    assert(*(Array_at(clone, 0)) == *(Array_at(arr, 0)));
	p_element = (int *)Array_at(clone, 0);
	*p_element = items[0];
    assert(*(Array_at(clone, 0)) != *(Array_at(arr, 0)));

    Array_destroy(clone);
}

void get(void) {
    int* x = (int *)Array_at(arr, 0);
    assert(*x == 0);
}

void set(void) {
    int* p_element;
    p_element = (int *)Array_at(arr, 0);
	*p_element = items[1];
    p_element = (int *)Array_at(arr, 0);
    assert(items[1] == *p_element);
}

void resize(void) {
	int* p_element;
    Array_resize(arr, 15);
    p_element = (int *)Array_at(arr, 14);
	*p_element = items[2];
    assert((Array_at(arr, 14)) != NULL);
}

void length(void) {
    assert((Array_length(arr)) == 15);
}
