# Makefile para compilar el TP Simple-parser.

# Declaracion de banderas
CFLAGS = -std=c99
TEST_FLAGS = $(FLAGS) -g
CC = gcc

# Directorios
STR = structures/
SRC = src/

all: parser
	rm *.o 


parser: main.o dictionary.o parser.o ctrie.o glist.o dstring.o gqueue.o glist.o
	$(CC) -o $^ $(CFLAGS)

main.o: $(SRC)main.c
	$(CC) -c $< $(CFLAGS)

dictionary.o: $(SRC)dictionary.c $(SRC)dictionary.h
	$(CC) -c $< $(CFLAGS)

parser.o: $(SRC)parser.c $(SRC)parser.h
	$(CC) -c $< $(CFLAGS)
 

# Compilacion de estructuras de datos base
ctrie.o: $(STR)ctrie.c $(STR)ctrie.h
	$(CC) -c $< $(CFLAGS)

glist.o: $(STR)glist.c $(STR)glist.h
	$(CC) -c $< $(CFLAGS)

dstring.o: $(STR)dstring.c $(STR)dstring.h
	$(CC) -c $< $(CFLAGS)

gqueue.o: $(STR)gqueue.c $(STR)gqueue.h 
	$(CC) $(CFLAGS) -c $< 

clean:
	rm parser
	rm test


.PHONY = clean
