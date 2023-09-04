# Makefile para compilar el TP Simple-parser.

# Banderas para la compilacion
ifeq ($(debug),yes)
	
	CFLAGS = -std=c99 -Wall -Werror -Wextra -g

else
	
	CFLAGS = -std=c99 -Wall -Werror -Wextra

endif


# Compilador de C
CC = gcc 

# Directorios de archivos
STR = structures/
SRC = src/
TEST = tests/

PARSER_DEPENDENCIES = $(SRC)main.c dictionary.o parser.o ctrie.o dstring.o

TEST_DEPENDENCIES = $(TEST)main_test.c test_parser.o parser.o test_dictionary.o \
													 dictionary.o test_ctrie.o ctrie.o test_dstring.o \
													 dstring.o compare_files.o 

all: parser test
	rm *.o

clean:
	rm parser
	rm test

# Compilacion del programa 
parser: $(PARSER_DEPENDENCIES)
	$(CC) $^ $(CFLAGS) -o parser


# Compilacion de los tests
test: $(TEST_DEPENDENCIES)
	$(CC) $^ $(CFLAGS) -o test


# Archivos objeto generales
parser.o: $(SRC)parser.c $(SRC)parser.h dictionary.o dstring.o
	$(CC) -c $< $(CFLAGS)
 
dictionary.o: $(SRC)dictionary.c $(SRC)dictionary.h ctrie.o dstring.o
	$(CC) -c $<  $(CFLAGS)

ctrie.o: $(STR)ctrie.c $(STR)ctrie.h
	$(CC) -c $< $(CFLAGS)

dstring.o: $(STR)dstring.c $(STR)dstring.h
	$(CC) -c $< $(CFLAGS)


# Archivos objeto especificos de los tests
test_parser.o: $(TEST)test_parser.c $(TEST)tests.h
	$(CC) -c $< $(CFLAGS)

test_dictionary.o: $(TEST)test_dictionary.c $(TEST)tests.h
	$(CC) -c $< $(CFLAGS)

test_ctrie.o: $(TEST)test_ctrie.c $(TEST)tests.h
	$(CC) -c $< $(CFLAGS)

test_dstring.o: $(TEST)test_dstring.c $(TEST)tests.h
	$(CC) -c $< $(CFLAGS)

compare_files.o: $(TEST)compare_files.c $(TEST)compare_files.h
	$(CC) -c $< $(CFLAGS)



.PHONY = clean
