/* Copyright (c) 2016 David Benoit
   unit_test.c
   
   Implementation of unit test utilities
*/
#include <string.h>
#include <stdio.h>
#include "unit_test.h"

struct test_info {
  char test_name[ERR_LENGTH_MAX];
  unsigned int num_errors;
  char error_list[MAX_NUM_ERRORS][ERR_LENGTH_MAX];
};

struct test_info THE_TEST_INFO;

void test_info_init() {
  THE_TEST_INFO.num_errors = 0;
  strncpy(THE_TEST_INFO.test_name, "Unknown Test", ERR_LENGTH_MAX);
}

void SET_TEST_NAME(char* test_name) {
  strncpy(THE_TEST_INFO.test_name, test_name, ERR_LENGTH_MAX);
}

void TEST_CASE(int expression, char* fail_notification) {
  if (!expression) {
    if (THE_TEST_INFO.num_errors < MAX_NUM_ERRORS) {
      strncpy(THE_TEST_INFO.error_list[THE_TEST_INFO.num_errors], fail_notification, ERR_LENGTH_MAX);
      THE_TEST_INFO.num_errors++;
    }
    else {
      printf("WARNING: cannot append test failure: %s to test_info."
             "  MAX_NUM_ERRORS reached\n", 
             fail_notification);
    }
  }
}   

int execute_test(void (*test)()) {
  int i;
  test_info_init();
  test();
  if (THE_TEST_INFO.num_errors == 0) {
    printf("PASSED: %s\n", THE_TEST_INFO.test_name);
    return 0;
  }
  else   {
    printf("FAILED: %s \n    WITH ERRORS: ", THE_TEST_INFO.test_name);
    for (i = 0; i < THE_TEST_INFO.num_errors; ++i)
      printf("%s\n                 ", THE_TEST_INFO.error_list[i]);
    return THE_TEST_INFO.num_errors;
  }
}

int run_test_suite(unit_test *array_of_tests, char *test_suite_name, unsigned int num_tests)
{
  int i, passed=0, failed=0, errors=0;
  printf("Running Test Suite: %s\n", test_suite_name);
  for (i = 0; i < num_tests; ++i) {
    int current_test_errors = execute_test(array_of_tests[i]);
    if (current_test_errors > 0) {
      ++failed;
      errors += current_test_errors;
    }
    else {
      ++passed;
    }
  } 
  printf("\nTOTAL PASSED: %d\nTOTAL FAILED: %d\nTOTAL ERRORS: %d\n", passed, failed, errors); 
  return 0;
}

