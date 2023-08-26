#include "../src/dictionary.h"
#include "stdio.h"
#include "stdlib.h"
#include "../src/parser.h"
#include <assert.h>



int main() {

  Dictionary dictionary = dictionary_create();

  FILE* file = fopen("../dictionaries/small_dictionary.txt", "r");
  FILE* line = fopen("../dictionaries/prueba.txt", "r");

  dictionary = dictionary_load_from_file(dictionary, file);
  


  //dictionary_iterate(dictionary); 

  //assert (ctrie_search_string(dictionary, "quien"));
  //assert (ctrie_search_string(dictionary, "dolar"));
  //assert (! ctrie_search_string(dictionary, "do"));

  parse_line(dictionary, line);

  //int l = dictionary_largest_prefix(dictionary, line);

  //printf("LARGO: %d",l);

  dictionary_destroy(dictionary);

  fclose(file);
  fclose(line);

  return 0;
}