/* Copyright (c) 2016 David Benoit
   unit_test.h

   Some unit testing utilities.

*/
#include <stdio.h>

#ifndef UNIT_TEST_H
#define UNIT_TEST_H
 
#define ERR_LENGTH_MAX 128
#define MAX_NUM_ERRORS 64


#define TEST_BEGIN(N) \
	struct test_info _reserved_test_info_name_; \
	test_info_init(&_reserved_test_info_name_); \
	set_test_name(&_reserved_test_info_name_, N); \

#define TEST_CASE(E, F) test_case(&_reserved_test_info_name_, E, F);

#define TEST_END() return _reserved_test_info_name_;

#define RUN_TEST_SUITE(X,Y) run_test_suite(X,Y,sizeof(X) / sizeof(unit_test))

struct test_info {
  char test_name[ERR_LENGTH_MAX];
  unsigned int num_errors;
  char error_list[MAX_NUM_ERRORS][ERR_LENGTH_MAX];
};

typedef struct test_info (*unit_test)(void);

void test_info_init(struct test_info* t);
/* Set the name of the current test. */
void set_test_name(struct test_info*, char *test_name);
/* Run a test case */
void test_case(struct test_info*, int expression, char* fail_notification);
/* Run a test suite */
int run_test_suite(const unit_test* array_of_tests, char *test_suite_name, unsigned int num_tests);

#endif
