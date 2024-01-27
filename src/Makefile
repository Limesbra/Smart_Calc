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

all : clean SmartCalc_v1.a test install

install: dist
	@cd calc; qmake -o ../SmartCalc
	@cd SmartCalc; make
	./SmartCalc/calc.app/Contents/MacOS/calc

run:
	./SmartCalc/calc.app/Contents/MacOS/calc

uninstall:
	@rm -rf SmartCalc
dvi:
	open manual.md
dist:
	@rm -rf SmartCalc
	@rm -rf smart_calc.tar
	@mkdir SmartCalc
	@cp -r calc SmartCalc/
	@cp  SmartCalc_v1.c SmartCalc_v1.h Makefile SmartCalc/
	@tar -cf smart_calc.tar  SmartCalc/calc SmartCalc/SmartCalc_v1.c SmartCalc/SmartCalc_v1.h SmartCalc/Makefile
	@rm -rf SmartCalc/calc SmartCalc/*.c SmartCalc/*.h SmartCalc/Makefile

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
	rm -rf *.gcno *.gcda *.o *.a *.info SmartCalc_v1 report test test_check test.log smart_calc.tar

clang:
	clang-format -style="{BasedOnStyle: Google}" -i *.c *.h

val: clean SmartCalc_v1.a
	$(CC) $(CFLAGS) SmartCalc_tests.c -L. SmartCalc_v1.a -o test $(LIBS) 
	valgrind --tool=memcheck --leak-check=yes ./test

#valgrind --leak-check=full --show-leak-kinds=all

# valgrind --tool=memcheck --leak-check=yes