#include "tests.h"
#include "../structures/ctrie.h"

// void test_lower_case_strcpy(); // STATIC
// void test_ctrie_create_node(); // STATIC 
// void test_ctrie_exchange_childs(); // STATUC
// void test_ctrie_split_node(); // STATIC 
// void test_ctrie_create_bifurcation(); // STATIC



void test_ctrie_create() {

  assert(ctrie_create() == NULL);
}


void test_ctrie_empty() {

  CTrie ctrie = ctrie_create();
  assert(ctrie_empty(ctrie));

  ctrie = ctrie_add_string(ctrie, "hola");
  assert(! ctrie_empty(ctrie));
}


void test_ctrie_add_string() {

  CTrie ctrie = ctrie_create();

  char* words[] = {"dolar", "dolares", "quien", "deposito", "hoy", "recibir"}; // MEJORAR TESTS

  for (int i = 0 ; i < 6 ; i++)
    assert(! ctrie_search_string(ctrie, words[i]));

  for (int i = 0 ; i < 6 ; i++)
    ctrie = ctrie_add_string(ctrie, words[i]);

  for (int i = 0 ; i < 6 ; i++)
    assert(ctrie_search_string(ctrie, words[i]));

}

void test_ctrie_search_string() {



}


void test_ctrie_node_length() {

}


void test_ctrie_node_char() {


}


void test_ctrie_end_of_word() {


}


void test_ctrie_child() {


}