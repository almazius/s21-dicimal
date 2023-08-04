CFLAGS=-c -Wall -Werror -Wextra -std=c11

ifeq ($(shell uname), Linux)
	LINUX_LIBS=-lsubunit -lrt -lpthread -lm
endif

all: clean s21_decimal.a

s21_decimal.a:
	rm -rf *.o
	gcc $(CFLAGS) s21_decimal.c
	ar r s21_decimal.a s21_decimal.o
	ranlib s21_decimal.a

s21_decimal.o: s21_decimal.c s21_decimal.h
	gcc $(CFLAGS) s21_decimal.c

test: s21_decimal.o
	gcc test_decimal.c s21_decimal.o -o check.out -lcheck $(LINUX_LIBS)
	./check.out

gcov_report: test_decimal.c s21_decimal.c
	clear
	gcc test_decimal.c s21_decimal.c -o coverage.o -lcheck $(LINUX_LIBS) -fprofile-arcs -ftest-coverage  
	./coverage.o
	lcov -c -d . -o coverage.info
	genhtml coverage.info -o coverage
	open coverage/index.html

	
clean:
	rm -rf *.o *.out *.a
	rm -rf *.gcda *.gcno
	rm -rf coverage coverage.info 
	rm -rf CPPLINT.cfg cpplint.py

leaks: test
	gcc -g test_decimal.c s21_decimal.o -o check.out -lcheck $(LINUX_LIBS)
	valgrind --quiet --leak-check=full --show-leak-kinds=all --track-origins=yes --show-reachable=no --log-file=valgrind-out.txt ./check.out

leaks2: test
	CK_FORK=no leaks --atExit -- ./check.out

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem ./*.c

lint:
	cp ./../materials/linters/CPPLINT.cfg ./
	cp ./../materials/linters/cpplint.py ./
	python3 cpplint.py --extensions=c *.c *.h
