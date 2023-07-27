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

all : clean s21_matrix.a test

# install:
# uninstall:
# dvi:
# dist:
test: clean SmartCalc_v1.0.a
	$(CC) $(CFLAGS) s21_matrix_test.c -L. s21_matrix.a -o test $(LIBS) 
	./test

SmartCalc_v1.0.a: SmartCalc_v1.0.o
	ar rcs SmartCalc_v1.0.a *.o
	ranlib SmartCalc_v1.0.a

s21_matrix.o:
	$(CC) $(CFLAGS) -c s21_matrix.c

s21_gcov.gcno: clean
	$(CC) $(CFLAGS) -c s21_matrix.c $(GCOV_FLAGS)

gcov_report: clean s21_gcov.gcno 
	$(CC) s21_matrix_test.c s21_matrix.c -o test_check $(LIBS) $(GCOV_FLAGS)
	-./test_check > test.log
	lcov --capture --directory . -o test.info
	genhtml test.info -o report
	open report/index.html

clean:
	rm -rf *.gcno *.gcda *.o *.a *.info s21_matrix report test test_check test.log

clang:
	clang-format -style="{BasedOnStyle: Google}" -i *.c *.h

val: clean s21_matrix.a
	$(CC) $(CFLAGS) s21_matrix_test.c -L. s21_matrix.a -o test $(LIBS) 
	valgrind --tool=memcheck --leak-check=yes ./test

#valgrind --leak-check=full --show-leak-kinds=all

# valgrind --tool=memcheck --leak-check=yes