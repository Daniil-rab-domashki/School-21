CC = gcc
CFLAGS = -Werror -Wextra -Wall
SRC = ./cipher.c ./logger.c
OBJ = $(SRC:.c=.o)

all: logging_cipher

logging_cipher: $(OBJ)
	$(CC) $(OBJ) -o ../build/$@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f ./*.o

rebuild: all clean













# all: cipher logging_cipher
#
# cipher: cipher.o
# 	$(CC) $(CFLAGS) $^ -o ../build/cipher
#
# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@
#
# logging_cipher: cipher.o logger.o
# 	$(CC) $(CFLAGS) $^ -o ../build/logging_cipher
# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o cipher.o
# 	$(CC) $(CFLAGS) -c $< -o logging_cipher.o
# clean:
# 	-rm -f ./*.o
#
# rebuild: all clean
