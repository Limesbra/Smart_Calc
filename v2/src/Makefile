CC = g++
CC_FLAGS = --std=c++17 -Wall -Werror -Wextra -g
TEST_FLAGS = -lgtest -pthread
COVERAGE_FLAGS = --coverage -fprofile-arcs -ftest-coverage
FILES = ../model/*.cc
FILES1 = model/*.cc

UNAME := $(shell uname -s)
ifeq ($(UNAME), Darwin)
	RUN = ./build/SmartCalc2.app/Contents/MacOS/SmartCalc2
endif
ifeq ($(UNAME), Linux)
	RUN = ./build/SmartCalc2
endif

all : install

install: uninstall
	mkdir build
	@cd view/SmartCalc2; qmake -o ../../build
	@cd build; make

run:
	$(RUN)

uninstall:
	@rm -rf build

dist:
	@rm -rf SmartCalc2
	@rm -rf smart_calc2.tar
	@mkdir SmartCalc2
	@cp -r model controller view tests doc Makefile SmartCalc2
	@tar -cvzf smart_calc2.tar  SmartCalc2
	@rm -rf SmartCalc2

dvi:
	open doc/html/index.html

test: clean
	cd tests && $(CC) $(CC_FLAGS) $(COVERAGE_FLAGS) *.cc $(FILES) -o test $(TEST_FLAGS)
	./tests/test

# t: clean
# 	$(CC) $(CC_FLAGS) test.cc $(FILES1) -o test
# 	./test

gcov_report : test
	gcovr -r . --html-details -o tests/test_list.html
	open tests/test_list.html

clean:
	rm -rf tests/*.gcno tests/*.gcda tests/*.o tests/*.a tests/*.info tests/*.html tests/*.css report tests/test smart_calc2.tar *.info tests/*.gcov

check_clang:
	clang-format -style="{BasedOnStyle: Google}" -n model/* controller/* view/SmartCalc2/*.cpp view/SmartCalc2/*.h

clang:
	clang-format -style="{BasedOnStyle: Google}" -i model/* controller/* view/SmartCalc2/*.cpp view/SmartCalc2/*.h tests/*.cc

val: clean
	cd tests && $(CC) $(CC_FLAGS) $(COVERAGE_FLAGS) *.cc $(FILES) -o test $(TEST_FLAGS)
	valgrind --tool=memcheck --leak-check=yes ./tests/test
