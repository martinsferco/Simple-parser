#include "../src/dictionary.h"
#include "stdio.h"
#include "stdlib.h"
#include "../src/dictionary.h"



int main() {

  Dictionary dictionary = dictionary_create();

  FILE* file = fopen("../dictionaries/small_dictionary.txt","r");

  dictionary = dictionary_load_from_file(dictionary, file);
  
  //dictionary = ctrie_add_string(dictionary, "quien");
  //dictionary = ctrie_add_string(dictionary, "deposito");
  //dictionary = ctrie_add_string(dictionary, "dolar");
  //dictionary = ctrie_add_string(dictionary, "dolares");
  //dictionary = ctrie_add_string(dictionary, "dolor");

  


  fclose(file);

  dictionary_iterate(dictionary);

  dictionary_destroy(dictionary);


  return 0;
}