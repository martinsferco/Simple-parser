#include "ctrie.h"

int main() {

  CTrie jorge = ctrie_crear();

  jorge = ctrie_agregar_cadena(jorge, "dolares");
  
  jorge = ctrie_agregar_cadena(jorge, "dolar");

  jorge = ctrie_agregar_cadena(jorge, "dolarizacion");
  

  jorge = ctrie_agregar_cadena(jorge, "dolor");

  jorge = ctrie_agregar_cadena(jorge, "quien");
  jorge = ctrie_agregar_cadena(jorge, "quienes");
  jorge = ctrie_agregar_cadena(jorge, "reciben");
  jorge = ctrie_agregar_cadena(jorge, "recibiran");
  jorge = ctrie_agregar_cadena(jorge, "hoy");
  jorge = ctrie_agregar_cadena(jorge, "habia");
  jorge = ctrie_agregar_cadena(jorge, "fue");



  ctrie_recorrer(jorge);

  return 0;
}