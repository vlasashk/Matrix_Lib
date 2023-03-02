CC = gcc
C_LIBS = -lm
TEST_LIBS = -lpthread -lcheck -lm
CFLAGS = -std=c11 -Wall -Wextra -Werror 
SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

all: build

build: test

test: s21_matrix.a
	$(CC) $(CFLAGS) Tests/*.c s21_matrix.a $(TEST_LIBS) -o test
	./test


s21_matrix.a: $(OBJECTS)
	ar rcs s21_matrix.a $(OBJECTS)
	ranlib s21_matrix.a

gcov_flag:
	$(eval CFLAGS += --coverage)

debug_flag:
	$(eval CFLAGS += -g)

gcov_report: clean gcov_flag test
	mkdir -p gcov
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov
	rm -rf *.gcno *.gcda *.gcov
	
debug: clean debug_flag build
	rm -rf *.o

rebuild: clean all

valgrind:
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test

clang:
	cp ../materials/linters/.clang-format ../src/.clang-format
	cp ../materials/linters/.clang-format ../src/Tests/.clang-format
	clang-format -style=Google -n *.c *.h
	clang-format -style=Google -n Tests/*.c Tests/*.h
	rm .clang-format Tests/.clang-format

clean:
	rm -rf *.a *.o Tests/*.o test *.a *.gcno *.gcda *.gcov *.info