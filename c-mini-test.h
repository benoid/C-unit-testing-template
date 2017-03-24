/* Copyright (c) 2016 David Benoit
   unit_test.h

   Some unit testing utilities.

   IMPORTANT: Do not attempt to run multiple test_suites simultaneously via multi-threading.
              This is a very primitive library.  All tests use the same singleton data table 
              to record their results.  

              
              Not thread safe under any circumstance:
                SET_TEST_NAME(...)
                RUN_TEST_SUITE(...)
                run_test_suite(...)

              Not thread safe unless thread locked
                TEST_CASE(...)
*/
#ifndef UNIT_TEST_H
#define UNIT_TEST_H
 
#define ERR_LENGTH_MAX 128
#define MAX_NUM_ERRORS 64

#define RUN_TEST_SUITE(X,Y) run_test_suite(X,Y,sizeof(X) / sizeof(unit_test))

typedef void (*unit_test)(void);

/* Set the name of the current test. */
void SET_TEST_NAME(char *test_name);
/* Run a test case */
void TEST_CASE(int expression, char* fail_notification);
/* Run a test suite */
int run_test_suite(const unit_test* array_of_tests, char *test_suite_name, unsigned int num_tests);


#endif
