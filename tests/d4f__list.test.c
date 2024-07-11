#include "test_tool.h"

#define D4F__LIST_NS
#include "d4f__list.h"
#undef D4F__LIST_NS

List list;
int items[] = { 1, 2, 3, 4 };

void init(void);
void done(void);

void create(void);
void from(void);
void clone(void);
void append_get_set_length(void);
void insert_remove_length(void);

TestSuite("d4f__List", init)

TestCase(create)
TestCase(from)
TestCase(clone)
TestCase(append_get_set_length)
TestCase(insert_remove_length)

TestDone(done)

void init(void) {
    list = List_create();
}

void done(void) {
    List_destroy(list);
}

void create(void) {
    assert(list != NULL);
}

void from(void) {
    List clone = List_from(items, sizeof(*items), 4);
    assert(clone != NULL);
    assert(List_length(clone) == 4);
    List_destroy(clone);
}

void clone(void) {
    List clone = List_clone(list);
    assert(clone != NULL);
    assert(clone != list);
    assert(List_length(clone) == List_length(list));
    List_destroy(clone);
}

void append_get_set_length(void) {
    size_t length = List_length(list);
    assert(List_append(list, &items[0]));
    assert(List_length(list) == length + 1);
    assert(List_get(list, 0) == &items[0]);
    List_set(list, 0, &items[1]);
    assert(List_get(list, 0) == &items[1]);
}

void insert_remove_length(void) {
    size_t length = List_length(list);
    assert(List_insert(list, 0, &items[0]));
    assert(List_length(list) == length + 1);
    assert(List_remove(list, 1));
    assert(List_length(list) == length);
}
