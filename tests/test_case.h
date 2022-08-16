#ifndef TEST_CASE_H
#define TEST_CASE_H

#define TestSuite(title, suite_init_fn) ({\
    printf("\n* %s *\n", title);\
    suite_init_fn();\
})

#define TestCase(test_fn) ({\
    printf(">   %s... ", #test_fn);\
    test_fn();\
    printf("OK\n");\
})

#define TestDone(suite_done_fn) ({\
    suite_done_fn();\
    printf("* passed *\n");\
})


#endif 