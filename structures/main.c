#include "ctrie.h"

int main() {

  CTrie jorge = ctrie_create();

  jorge = ctrie_add_string(jorge, "dolares");
  
  jorge = ctrie_add_string(jorge, "dolar");

  jorge = ctrie_add_string(jorge, "dolarizacion");
  

  jorge = ctrie_add_string(jorge, "dolor");

  jorge = ctrie_add_string(jorge, "quien");
  jorge = ctrie_add_string(jorge, "quienes");
  jorge = ctrie_add_string(jorge, "reciben");
  jorge = ctrie_add_string(jorge, "recibiran");
  jorge = ctrie_add_string(jorge, "hoy");
  jorge = ctrie_add_string(jorge, "habia");
  jorge = ctrie_add_string(jorge, "fue");



  ctrie_iterate(jorge);

  return 0;
}