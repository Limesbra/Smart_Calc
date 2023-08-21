CC = gcc
CC_FLAGS = --std=c11 -Wall -Werror -Wextra -g
GCOV_FLAGS = -lgcov --coverage

O_EXT = o_ext/

UNAME := $(shell uname -s)
ifeq ($(UNAME), Darwin)
LIBS = -lcheck 
endif
ifeq ($(UNAME), Linux)
LIBS = -lcheck -lsubunit -pthread -lrt -lm
endif

all : clean SmartCalc_v1.a test

# install:
# uninstall:
# dvi:
# dist:
test: clean SmartCalc_v1.a
	$(CC) $(CFLAGS) SmartCalc_tests.c -L. SmartCalc_v1.a -o test $(LIBS) 
	./test

SmartCalc_v1.a: SmartCalc_v1.o
	ar rcs SmartCalc_v1.a *.o
	ranlib SmartCalc_v1.a

SmartCalc_v1.o:
	$(CC) $(CFLAGS) -c SmartCalc_v1.c

s21_gcov.gcno: clean
	$(CC) $(CFLAGS) -c SmartCalc_v1.c $(GCOV_FLAGS)

gcov_report: clean s21_gcov.gcno 
	$(CC) SmartCalc_tests.c SmartCalc_v1.c -o test_check $(LIBS) $(GCOV_FLAGS)
	-./test_check > test.log
	lcov --capture --directory . -o test.info
	genhtml test.info -o report
	open report/index.html

clean:
	rm -rf *.gcno *.gcda *.o *.a *.info SmartCalc_v1 report test test_check test.log

clang:
	clang-format -style="{BasedOnStyle: Google}" -i *.c *.h

val: clean SmartCalc_v1.a
	$(CC) $(CFLAGS) SmartCalc_v1_test.c -L. SmartCalc_v1.a -o test $(LIBS) 
	valgrind --tool=memcheck --leak-check=yes ./test

#valgrind --leak-check=full --show-leak-kinds=all

# valgrind --tool=memcheck --leak-check=yes