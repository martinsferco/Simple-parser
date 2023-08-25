#include "../src/dictionary.h"
#include "stdio.h"
#include "stdlib.h"
#include "../src/dictionary.h"



int main() {

  Dictionary dictionary = dictionary_create();

  FILE* file = fopen("../dictionaries/small_dictionary.txt", "r");
  FILE* line = fopen("../dictionaries/prueba.txt", "r");

  dictionary = dictionary_load_from_file(dictionary, file);
  

  fclose(file);

  dictionary_iterate(dictionary);

  int length = dictionary_largest_prefix(dictionary, line);

  printf("MAXIMO LARGO: %d\n", length);

  dictionary_destroy(dictionary);


  return 0;
}