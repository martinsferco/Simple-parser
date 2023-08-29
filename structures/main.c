#include "../src/dictionary.h"
#include "stdio.h"
#include "stdlib.h"
#include "../src/parser.h"
#include <assert.h>



int main() {

  Dictionary dictionary = dictionary_create();

  FILE* file = fopen("../dictionaries/big_dictionary.txt", "r");
  FILE* file_to_parse = fopen("../dictionaries/duhalde_3600_800-1200.txt", "r");

  dictionary = dictionary_load_from_file(dictionary, file);
  


  //dictionary_iterate(dictionary); 

  //assert (ctrie_search_string(dictionary, "quien"));
  //assert (ctrie_search_string(dictionary, "dolar"));
  //assert (! ctrie_search_string(dictionary, "do"));

  //parse_file(dictionary, file_to_parse);

  //int l = dictionary_largest_prefix(dictionary, line);

  //printf("LARGO: %d",l);

  dictionary_destroy(dictionary);

  fclose(file);
  fclose(file_to_parse);

  return 0;
}