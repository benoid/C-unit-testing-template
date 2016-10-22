/* Copyright (c) 2016 David Benoit
   run_tests.c
   
*/
#include <stdio.h>
#include <string.h>
#include "unit_test.h"

typedef struct test_info (*unit_test)(void);

const array_of_tests[] = {
  /* Pointers to test functions go here */
};

int execute_test(struct test_info (*test)());

int main(int argc, char* argv[])
{
  int i, passed=0, failed=0, errors=0;
  for (i = 0; i < sizeof(array_of_tests) / sizeof(unit_test); ++i) {
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

int execute_test(struct test_info (*test)()) {
  struct test_info t = test();
  int i;
  if (t.num_errors == 0) {
    printf("PASSED %s\n", t.test_name);
    return 0;
  }
  else   {
    printf("FAILED: %s WITH ERRORS: \n", t.test_name);
    for (i = 0; i < t.num_errors; ++i)
      printf("%s\n", t.error_list[i]);
    return t.num_errors;
  }
  
}
