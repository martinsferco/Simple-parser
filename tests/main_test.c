#include "tests.h"




int main() {

  test_compare_files();

  // FUNCIONES DE TESTO DE DICTIONARY
  test_dictionary_create();
  test_dictionary_load_from_file();
  test_dictionary_larges_prefix();
    
  // FUNCIONES DE TESTEO DE PARSER
  test_parse_line();
  test_parse_file();
  test_save_parsing_errors(); // STATIC


  // FUNCIONES DE TESTO DE CTRIE
  test_lower_case_strcpy(); // STATIC
  test_ctrie_create_node(); // STATIC 
  test_ctrie_exchange_childs(); // STATUC
  test_ctrie_split_node(); // STATIC 
  test_ctrie_create_bifurcation(); // STATIC
  test_ctrie_create();
  test_ctrie_empty();
  test_ctrie_add_string();
  test_ctrie_search_string();
  test_ctrie_node_length();
  test_ctrie_node_char();
  test_ctrie_end_of_word();
  test_ctrie_child();

  // FUNCIONES DE TESTEO DE DSTRING
  test_dstring_extends(); // STATIC
  test_dstring_create();
  test_dstring_read();
  test_dstring_save_segment();
  test_dstring_used();
  test_dstring_append();
  test_dstring_append_from_file();
  test_dstring_reset();

  return 0;
}


void test_compare_files() {



}