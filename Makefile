tests: run_tests.c unit_test.c
	gcc -o run_tests run_tests.c unit_test.c 
clean:
	rm run_tests
