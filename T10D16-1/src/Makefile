CC = gcc
CFLAGS = -Werror -Wextra -Wall
LDFLAGS = -lm

OBJ = ./s21_string_test.o ./s21_string.o

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests
strlen_tests: ../build/Quest_1
strcmp_tests: ../build/Quest_2
strcpy_tests: ../build/Quest_3
strcat_tests: ../build/Quest_4
strchr_tests: ../build/Quest_5
strstr_tests: ../build/Quest_6

../build/Quest_1: s21_strlen_tests_Q1.o s21_string.o
	$(CC) $(CFLAGS) $^ -o ../build/Quest_1 $(LDFLAGS)

../build/Quest_2: s21_strcmp_tests_Q2.o s21_string.o
	$(CC) $(CFLAGS) $^ -o ../build/Quest_2 $(LDFLAGS)

../build/Quest_3: s21_strcpy_tests_Q3.o s21_string.o
	$(CC) $(CFLAGS) $^ -o ../build/Quest_3 $(LDFLAGS)

../build/Quest_4: s21_strcat_tests_Q4.o s21_string.o
	$(CC) $(CFLAGS) $^ -o ../build/Quest_4 $(LDFLAGS)

../build/Quest_5: s21_strchr_tests_Q5.o s21_string.o
	$(CC) $(CFLAGS) $^ -o ../build/Quest_5 $(LDFLAGS)

../build/Quest_6: s21_strstr_tests_Q6.o s21_string.o
	$(CC) $(CFLAGS) $^ -o ../build/Quest_6 $(LDFLAGS)





s21_strlen_tests_Q1.o: s21_string_test.c
	$(CC) $(CFLAGS) -DQuest_1 -c $< -o s21_strlen_tests_Q1.o

s21_strcmp_tests_Q2.o: s21_string_test.c
	$(CC) $(CFLAGS) -DQuest_2 -c $< -o s21_strcmp_tests_Q2.o

s21_strcpy_tests_Q3.o: s21_string_test.c
	$(CC) $(CFLAGS) -DQuest_3 -c $< -o s21_strcpy_tests_Q3.o

s21_strcat_tests_Q4.o: s21_string_test.c
	$(CC) $(CFLAGS) -DQuest_4 -c $< -o s21_strcat_tests_Q4.o

s21_strchr_tests_Q5.o: s21_string_test.c
	$(CC) $(CFLAGS) -DQuest_5 -c $< -o s21_strchr_tests_Q5.o

s21_strstr_tests_Q6.o: s21_string_test.c
	$(CC) $(CFLAGS) -DQuest_6 -c $< -o s21_strstr_tests_Q6.o

clean:
	-rm -f ./*.o


rebuild: all clean



