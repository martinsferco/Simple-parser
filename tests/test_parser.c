#include "tests.h"
#include "../src/parser.h"


void test_parse_file() {

  Dictionary dictionary = dictionary_create();

  FILE* dicFile = fopen("dictionaries/small_dictionary.txt","r");

  dictionary = dictionary_load_from_file(dictionary, dicFile);

  fclose(dicFile);

  FILE* parseFile = fopen("testdata/prueba.txt", "r");
  FILE* resultsFile = fopen("testdata/parseResult.txt", "w+");

  parse_file(dictionary, parseFile, resultsFile);

  fclose(parseFile);

  FILE* expectedResultsFile = fopen("testdata/result.txt", "r");

  fseek(resultsFile, 0, SEEK_SET);

  assert(compare_files(resultsFile, expectedResultsFile));

  fclose(resultsFile);
  fclose(expectedResultsFile);
  dictionary_destroy(dictionary);
}