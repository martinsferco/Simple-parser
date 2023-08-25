#include "dictionary.h"



Dictionary dictionary_create() { return ctrie_create(); }

Dictionary dictionary_load_from_file(Dictionary dictionary, FILE* file) { // TODO CORREGIR

  char buffer[READ_SIZE];

  while (EOF != fscanf(file, "%[^\n]\n", buffer)) { 
    
    dictionary = ctrie_add_string(dictionary, buffer);

  }
  return dictionary;
}

void dictionary_destroy(Dictionary dictionary) { ctrie_destroy(dictionary); }


int dictionary_largest_prefix(Dictionary dictionary, FILE* file) {

  return 0; // TODO
}


void dictionary_iterate(Dictionary dictionary) { ctrie_iterate(dictionary); }
