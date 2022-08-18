#ifndef TEST_TOOL_H
#define TEST_TOOL_H

#include <assert.h>
#include <stdio.h>

#define TestSuite(title, suite_init_fn) int main(void) {\
    printf("\n* %s *\n", title);\
    suite_init_fn();\

#define TestCase(test_fn) \
    printf(">   %s... ", #test_fn);\
    test_fn();\
    printf("OK\n");\

#define TestDone(suite_done_fn) \
    suite_done_fn();\
    printf("* passed *\n");\
    return 0;\
}\


#endif 