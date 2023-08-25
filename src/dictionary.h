#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__


#define READ_SIZE 1000


#include <stdlib.h>
#include <stdio.h>
#include "../structures/ctrie.h"


typedef CTrie Dictionary; // Definimos el tipo Dictionary


Dictionary dictionary_create();

Dictionary dictionary_load_from_file(Dictionary dictionary, FILE* file);

void dictionary_iterate(Dictionary dictionary);

void dictionary_destroy(Dictionary dictionary);

int dictionary_largest_prefix(Dictionary dictionary, FILE* file);


#endif // __DICTIONARY_H__