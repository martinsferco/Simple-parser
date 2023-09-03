#include "tests.h"
#include "../src/parser.h"


void test_parse_file() {

  Dictionary dictionary = dictionary_create();

  FILE* dicFile = fopen("../dictionaries/small_dictionary.txt","r");

  dictionary = dictionary_load_from_file(dictionary, dicFile);

  fclose(dicFile);

  FILE* parseFile = fopen("../dictionaries/prueba.txt", "r");
  FILE* resultsFile = fopen("../dictionaries/parseResult.txt", "w");

  parse_file(dictionary, parseFile, resultsFile);

  fclose(parseFile);

  FILE* expectedResultsFile = fopen("../dictionaries/result1.txt", "r");

  assert(compare_files(resultsFile, expectedResultsFile));
}

// void test_save_parsing_errors(); // STATIC