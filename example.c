/* For this example, we will implement a set of 
   simple arithmetic functions. */

#include "c-mini-test.h"

   /* The API */

/* Add two integers */
int add(int a, int b) {
  return a + b;
}

/* Subtract two integers */
int subtract(int a, int b) {
  return a - b;
}

/* Multiply two integers */
int multiply(int a, int b) {
  return a * b;
}

/* Divide two integers */
int divide(int a, int b) {
/* Oops! Someone on the team mistake was lazily
   copying/pasting, and forgot to make a critical change.  
   Hopefully our test cases will catch the error.  */
  return a * b;
}

  /* The Unit Tests */

/* Each unit test should be a function which takes zero arguments,
   and returns void. For convenience when declaring an array, 
   there is a typedef for these functions called unit_test. */

/* To perform a check inside of a unit_test, use TEST_CASE(...) */

struct test_info test_add_works_correctly() {
/* Optionally name the test */
  TEST_BEGIN("test_add_works_correctly()");
/* Run the test cases.  The first argument is an expression
   which returns a condition.  The second argument is a
   const char* error message to print if the test_case_fails. */
  TEST_CASE(add(2, 3) == 5, "add(2, 3) did not return 5");
  TEST_CASE(add(6, -7) == -1, "add(6, -7) did not return -1");
  TEST_END()
}

struct test_info test_subtract_works_correctly() {
  TEST_BEGIN("test_subtract_works_correctly()");
  TEST_CASE(subtract(3, 2) == 1, "subtract(3, 2) did not return 1");
  TEST_CASE(subtract(4, -8) == 12, "subtract(4, -8) did not return 12");
  TEST_END()
}

struct test_info test_multiply_works_correctly() {
  TEST_BEGIN("test_multiply_works_correctly()");
  TEST_CASE(multiply(3, 4) == 12, "multiply(3, 4) did not return 12");
  TEST_CASE(multiply(10, -6) == -60, "multiply(10, -6) did not return -60");
  TEST_END()
}

struct test_info test_divide_works_correctly() {
  TEST_BEGIN("test_divide_works_correctly()");
  TEST_CASE(divide(8, 4) == 2, "divide(8, 4) did not return 2");
  TEST_CASE(divide(6, -2) == -3, "divide(6, -2) did not return -3");
  TEST_END()
}

const unit_test test_suite[] = {
  test_add_works_correctly,
  test_subtract_works_correctly,
  test_multiply_works_correctly,
  test_divide_works_correctly
};

int main(int argc, char* argv[]) {
  RUN_TEST_SUITE(test_suite, "Test Arithmetic Module");
  return 0;
}
