# Makefile para compilar el TP Simple-parser.

# Declaracion de banderas
CFLAGS = -Wall -Wextra -Werror -std=c99
TEST_FLAGS = $(FLAGS) -g
CC = gcc


parser: main.c ctrie.

ctrie.o: ctrie.c ctrie.h
	$(CC) -c $< $(CFLAGS)

glist.o: glist.c glist.h
	$(CC) -c $< $(CFLAGS)


clean:
	rm *.o
	rm parser

.PHONY = clean
.PHONY = test