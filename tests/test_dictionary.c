#include "tests.h"
#include "../src/dictionary.h"



void test_dictionary_create() {

  Dictionary dictionary = dictionary_create();

  assert(dictionary == NULL);

  dictionary_destroy(dictionary);
}



void test_dictionary_load_from_file() {

  Dictionary dictionary = dictionary_create();

  FILE* file = fopen("dictionaries/big_dictionary.txt", "r");

  dictionary = dictionary_load_from_file(dictionary, file);

  fseek(file, 0, SEEK_SET);

  char word[1000];

  while (fscanf(file, "%s", word) != EOF) 

    assert(ctrie_search_string(dictionary, word));

  dictionary_destroy(dictionary);
  fclose(file);
}



void test_dictionary_largest_prefix() {

  FILE* dictionaryFile = fopen("dictionaries/small_dictionary.txt", "r");

  Dictionary dictionary = dictionary_create();

  dictionary = dictionary_load_from_file(dictionary, dictionaryFile);

  fclose(dictionaryFile);

  FILE* parserFile = fopen("testdata/prueba.txt", "r");

  DString string = dstring_create(100);

  assert(dictionary_largest_prefix(dictionary, string, 0, parserFile) == 5);

  dictionary_destroy(dictionary);
  dstring_destroy(string);
  fclose(parserFile);
}