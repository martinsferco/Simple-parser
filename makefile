# Makefile para compilar el TP Simple-parser.

CFLAGS = -std=c99
TEST_FLAGS = $(FLAGS) -g
CC = gcc

# Directorios
STR = structures/
SRC = src/


all: main
	rm *.o

clean:
	rm parser


main: $(SRC)main.c dictionary.o parser.o ctrie.o dstring.o
	$(CC) $^ $(CFLAGS) -o parser

parser.o: $(SRC)parser.c $(SRC)parser.h dstring.o
	$(CC) -c $< $(CFLAGS)
 
dictionary.o: $(SRC)dictionary.c $(SRC)dictionary.h ctrie.o dstring.o
	$(CC) -c $< ctrie.o dstring.o $(CFLAGS)



ctrie.o: $(STR)ctrie.c $(STR)ctrie.h
	$(CC) -c $< $(CFLAGS)

dstring.o: $(STR)dstring.c $(STR)dstring.h
	$(CC) -c $< $(CFLAGS)



.PHONY = clean,all
