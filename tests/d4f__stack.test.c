#include "test_tool.h"

#define d4f__stack_ns
#include "d4f__stack.h"
#undef d4f__stack_ns

Stack stack;
int items[] = { 1, 2, 3, 4 };

void init(void);
void done(void);

void create(void);
void from(void);
void clone(void);
void push_pop_length(void);

TestSuite("d4f__Stack", init);

TestCase(create)
TestCase(from)
TestCase(clone)
TestCase(push_pop_length)

TestDone(done)

void init(void) {
    stack = Stack_create();
}

void done(void) {
    Stack_destroy(stack);
}

void create(void) {
    assert(stack != NULL);
}

void from(void) {
    Stack clone = Stack_from(items, sizeof(*items), 4);
    assert(clone != NULL);
    assert(Stack_length(clone) == 4);
    assert(Stack_pop(clone) == &items[3]);
    Stack_destroy(clone);
}

void clone(void) {
    Stack clone = Stack_clone(stack);
    assert(clone != NULL);
    assert(clone != stack);
    assert(Stack_length(clone) == Stack_length(stack));
    Stack_destroy(clone);
}

void push_pop_length(void) {
    size_t length = Stack_length(stack);
    assert(Stack_push(stack, &items[0]) == TRUE);
    assert(Stack_length(stack) == length + 1);
    assert(Stack_pop(stack) == &items[0]);
    assert(Stack_length(stack) == length);
}
