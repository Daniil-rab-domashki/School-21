FLAGS=-Wall -Wextra -Werror -std=c11

all: print_module

print_module: main_module_entry_point.c print_module.c
	gcc $(FLAGS) print_module.c main_module_entry_point.c -o ../build/Quest_1

../build/print_module.o: print_module.c print_module.h
	gcc $(FLAGS) -c print_module.c

clang:
	rm -f ../build/*.o  ../build/Quest_1
