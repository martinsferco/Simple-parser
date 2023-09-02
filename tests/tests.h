#ifndef __TESTS_H__
#define __TESTS_H__

#include "compare_files.h"
#include <assert.h>

// FUNCION TESTEO DE COMPARACION ARCHIVOS
void test_compare_files();

// FUNCIONES DE TESTO DE DICTIONARY
void test_dictionary_create();
void test_dictionary_load_from_file();
void test_dictionary_larges_prefix();
	
// FUNCIONES DE TESTEO DE PARSER
void test_parse_line();
void test_parse_file();
void test_save_parsing_errors(); // STATIC


// FUNCIONES DE TESTO DE CTRIE
void test_lower_case_strcpy(); // STATIC
void test_ctrie_create_node(); // STATIC 
void test_ctrie_exchange_childs(); // STATUC
void test_ctrie_split_node(); // STATIC 
void test_ctrie_create_bifurcation(); // STATIC
void test_ctrie_create();
void test_ctrie_empty();
void test_ctrie_add_string();
void test_ctrie_search_string();
void test_ctrie_node_length();
void test_ctrie_node_char();
void test_ctrie_end_of_word();
void test_ctrie_child();

// FUNCIONES DE TESTEO DE DSTRING
void test_dstring_extends(); // STATIC
void test_dstring_create();
void test_dstring_read();
void test_dstring_save_segment();
void test_dstring_used();
void test_dstring_append();
void test_dstring_append_from_file();
void test_dstring_reset();

#endif // __TESTS_H__


