#include "tests.h"
#include <string.h>
#include "../structures/ctrie.h"


#define BUFFER_SIZE 1000


void test_ctrie_create() {

  CTrie ctrie = ctrie_create();

  assert(ctrie == NULL);

  ctrie_destroy(ctrie);
}



void test_ctrie_empty() {

  CTrie ctrie = ctrie_create();
  assert(ctrie_empty(ctrie));

  ctrie = ctrie_add_string(ctrie, "hola");
  assert(! ctrie_empty(ctrie));

  ctrie_destroy(ctrie);
}



void test_ctrie_add_string() {

  CTrie ctrie = ctrie_create();

  FILE* file = fopen("dictionaries/big_dictionary.txt", "r");

  char word[BUFFER_SIZE];
  
  while (fscanf(file, "%s", word) != EOF) 
    
    ctrie = ctrie_add_string(ctrie, word); 

  fseek(file, 0, SEEK_SET); 

  while (fscanf(file, "%s", word) != EOF)

    assert(ctrie_search_string(ctrie, word));


  ctrie_destroy(ctrie);
  fclose(file);
}



void test_ctrie_search_string() {

  char* words[] = {"dolar", "dolares", "dolor", "quien", "recibir", "recibira"};
  CTrie ctrie = ctrie_create();

  for (int i = 0 ; i < 6 ; i++) 

    ctrie = ctrie_add_string(ctrie, words[i]);
    
  
  for (int i = 0 ; i < 6 ; i++)

    assert(ctrie_search_string(ctrie, words[i]));


  assert(! ctrie_search_string(ctrie, "dol"));
  assert(! ctrie_search_string(ctrie, "es"));
  assert(! ctrie_search_string(ctrie, "a"));
  assert(! ctrie_search_string(ctrie, "deposite"));

  ctrie_destroy(ctrie);
}



void test_ctrie_node_length() {

  CTrie ctrie = ctrie_create();

  ctrie = ctrie_add_string(ctrie, "dolares");
  assert(ctrie_node_length(ctrie) == 7);

  ctrie = ctrie_add_string(ctrie, "dolaresssssss");
  assert(ctrie_node_length(ctrie) == 7);

  ctrie = ctrie_add_string(ctrie, "dolar");
  assert(ctrie_node_length(ctrie) == 5);

  ctrie = ctrie_add_string(ctrie, "dia");
  assert(ctrie_node_length(ctrie) == 1);

  ctrie = ctrie_add_string(ctrie, "quien");
  assert(ctrie_node_length(ctrie) == 0);

  ctrie_destroy(ctrie);
}



void test_ctrie_node_char() {

  CTrie ctrie = ctrie_create();

  char word1[] = "dolares";
  char word2[] = "quien";
  char word3[] = "recibira";

  ctrie = ctrie_add_string(ctrie, word1);
  ctrie = ctrie_add_string(ctrie, word2);
  ctrie = ctrie_add_string(ctrie, word3);

  CTrie d_child = ctrie_child(ctrie, word1[0]);
  CTrie q_child = ctrie_child(ctrie, word2[0]);
  CTrie r_child = ctrie_child(ctrie, word3[0]);

  for (int i = 0 ; i < (int)strlen(word1) ; i++)
    assert(ctrie_node_char(d_child, i) == word1[i]);

  for (int i = 0 ; i < (int)strlen(word2) ; i++)
    assert(ctrie_node_char(q_child, i) == word2[i]);

  for (int i = 0 ; i < (int)strlen(word3) ; i++)
    assert(ctrie_node_char(r_child, i) == word3[i]);

  ctrie_destroy(ctrie);
}


void test_ctrie_end_of_word() {

  CTrie ctrie = ctrie_create();

  ctrie = ctrie_add_string(ctrie, "dolares");
  assert(ctrie_end_of_word(ctrie));

  ctrie = ctrie_add_string(ctrie, "dolaresssss");
  assert(ctrie_end_of_word(ctrie));

  ctrie = ctrie_add_string(ctrie, "dolar");
  assert(ctrie_end_of_word(ctrie));

  ctrie = ctrie_add_string(ctrie, "dolor");
  assert(! ctrie_end_of_word(ctrie));
  
  ctrie = ctrie_add_string(ctrie, "dol");
  assert(ctrie_end_of_word(ctrie));
  
  ctrie = ctrie_add_string(ctrie, "dorado");
  assert(! ctrie_end_of_word(ctrie));

  ctrie = ctrie_add_string(ctrie, "d");
  assert(ctrie_end_of_word(ctrie));

  ctrie_destroy(ctrie);
}