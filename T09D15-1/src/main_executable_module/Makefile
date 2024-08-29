CC = gcc
CFLAGS = -Werror -Wextra -Wall
LDFLAGS = -lm

OBJ = ../data_libs/sort.o ../data_libs/data_stat.o ../data_module/data_process.o ../yet_another_decision_module/decision.o main_executable_module.o ../data_libs/data_io.o

all: Quest_3
Quest_3: $(OBJ)
	$(CC) $(CFLAGS) $^ -o ../../build/$@ $(LDFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@
all: build_with_static
build_with_static: $(OBJ)
	$(CC) $(CFLAGS) $^ -o ../../build/Quest_5 $(LDFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@
data_stat.a:
	ar cr data_stat.a data_stat.o
all: build_with_dynamic
build_with_dynamic: data_process.so $(OBJ)
	$(CC) $(CFLAGS) -L $^ -o ../../build/Quest_6 $(LDFLAGS)
data_process.so: $(OBJ)
	$(CC) $(CFLAGS) -shared $^ -o data_process.so  $(LDFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@
clean:
	-rm -f ../data_libs/*.o
	-rm -f ../data_module/*.o
	-rm -f ../main_executable_module/*.o
	-rm -f ../yet_another_decision_module/*.o
	-rm -f ../main_executable_module/data_process.so
rebuild: clean all



