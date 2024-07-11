#include "test_tool.h"

#define D4F__QUEUE_NS
#include "d4f__queue.h"
#undef D4f__QUEUE_NS

#define TEST 0

Queue queue;
int items[] = { 1, 2, 3, 4 };

void init(void);
void done(void);

void create(void);
void from(void);
void clone(void);
void add_next_length(void);


TestSuite("d4f__Queue", init)

TestCase(create)
TestCase(from)
TestCase(clone)
TestCase(add_next_length)

TestDone(done)

void init(void) {
    queue = Queue_create();
}

void done(void) {
    Queue_destroy(queue);
}

void create(void) {
    assert(queue != NULL);
}

void from(void) {
    Queue clone = Queue_from(items, sizeof(int), 4);
    assert(clone != NULL);
    assert(Queue_length(clone) == 4);
    assert(Queue_next(clone) == &items[0]);
    Queue_destroy(clone);
}

void clone(void) {
    Queue clone = Queue_clone(queue);
    assert(clone != NULL);
    assert(clone != queue);
    assert(Queue_length(clone) == Queue_length(queue));
    Queue_destroy(clone);
}

void add_next_length(void) {
    size_t length = Queue_length(queue);
    assert(Queue_add(queue, &items[0]) != FALSE);
    assert(Queue_length(queue) == length + 1);
    assert(Queue_next(queue) == &items[0]);
    assert(Queue_length(queue) == length);
}
