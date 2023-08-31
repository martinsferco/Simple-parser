# Makefile para compilar el TP Simple-parser.

# Declaracion de banderas
CFLAGS = -Wall -Wextra -Werror -std=c99
TEST_FLAGS = $(FLAGS) -g
CC = gcc


all: parser #Compilamos el parser y eliminamos los archivos objeto
	rm *.o 

parser: 

# Compilacion de estructuras de datos base
ctrie.o: structures/ctrie.c structures/ctrie.h
	$(CC) -c $< $(CFLAGS)

glist.o: structures/glist.c structures/glist.h
	$(CC) -c $< $(CFLAGS)

dinamic_string.o: structures/dinamic_string.c structures/dinamic_string.h
	$(CC) -c $< $(CFLAGS)

gqueue.o: structures/gqueue.c structures/gqueue.h
	$(CC) -c $< $(CFLAGS)


clean:
	rm *.o
	rm parser

.PHONY = clean
.PHONY = test