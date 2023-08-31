#include "../src/dictionary.h"
#include "stdio.h"
#include "stdlib.h"
#include "../src/parser.h"
#include <assert.h>



int main() {

  Dictionary dictionary = dictionary_create();

  // FILE* dictionary_file = fopen("../dictionaries/small_dictionary.txt", "r");
  // FILE* file_to_parse = fopen("../dictionaries/prueba.txt", "r");

  FILE* dictionary_file = fopen("../dictionaries/duhalde_dict.txt", "r");
  
  dictionary = dictionary_load_from_file(dictionary, dictionary_file);
  
  fclose(dictionary_file); // Cerramos el archivo del diccionario


  FILE* file_to_parse = fopen("../dictionaries/prueba.txt", "r");
  FILE* save_parsing = fopen("../results.txt","w");
  //dictionary_iterate(dictionary); 

  //assert (ctrie_search_string(dictionary, "quien"));
  //assert (ctrie_search_string(dictionary, "dolar"));
  //assert (! ctrie_search_string(dictionary, "do"));

  parse_file(dictionary, file_to_parse, save_parsing);

  //int l = dictionary_largest_prefix(dictionary, line);

  //printf("LARGO: %d",l);

  

  dictionary_destroy(dictionary);

  fclose(file_to_parse); // Cerramos el archivo a parsear
  fclose(save_parsing); // Cerramos el archivo del resultado del parseo

  return 0;
}