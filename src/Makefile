COMPILE=gcc
FLAGS=-Wall -Wextra -Werror -std=c11
TEST_FLAGS=-lcheck -lm -lrt -lpthread -lsubunit

test:
	$(COMPILE) -g -L. $(FLAGS) s21_test.c s21_string.c s21_sprintf/*.c $(TEST_FLAGS)

main:
	$(COMPILE) -g $(FLAGS) s21_sprintf/*.c

coverage:
	$(COMPILE) --coverage -L. $(FLAGS) s21_test.c s21_string.c s21_sprintf/*.c $(TEST_FLAGS)

s21_string.a:
	$(COMPILE) $(FLAGS) -c  s21_string.c s21_sprintf/*.c
	ar rc libs21_string.a *.o
	ranlib libs21_string.a

clean:
	rm -r *.gcno *.gcda *.info *.out *.exe *.o