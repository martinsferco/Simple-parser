#include "tests.h"

int main() {

  // Funcion de testeo de comparacion de archivos
  test_compare_files();

  // Funciones de testeo de dictionary.h
  test_dictionary_create();
  test_dictionary_load_from_file();
  test_dictionary_largest_prefix();
    
  // Funciones de testeo de parse.h
  test_parse_file();

  // Funciones de testeo de ctrie.h
  test_ctrie_create();
  test_ctrie_empty();
  test_ctrie_add_string();
  test_ctrie_search_string();
  test_ctrie_node_length();
  test_ctrie_node_char();
  test_ctrie_end_of_word();

  // Funciones de testeo de dstring.h
  test_dstring_read();
  test_dstring_save_segment();
  test_dstring_used();
  test_dstring_append();
  test_dstring_reset();

  return 0;
}


void test_compare_files() {

  FILE* file1 = fopen("testdata/prueba.txt", "r");
  FILE* file2 = fopen("testdata/prueba_copy.txt", "r");
  FILE* file3 = fopen("testdata/parseResult.txt", "r");

  assert(compare_files(file1, file2));
  fseek(file1, 0, SEEK_SET);
  fseek(file2, 0, SEEK_SET);
  assert(compare_files(file2, file1));
  fseek(file1, 0, SEEK_SET);
  fseek(file2, 0, SEEK_SET);
  assert(! compare_files(file1, file3));
  fseek(file3, 0, SEEK_SET);
  assert(! compare_files(file2, file3));
  
  fclose(file1);  
  fclose(file2);  
  fclose(file3);  
}