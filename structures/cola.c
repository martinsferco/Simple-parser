#include "cola.h"

Cola cola_crear() { return glist_crear(); }


void cola_destruir(Cola cola, FuncionDestructora destruir) { 
  
  glist_destruir(cola, destruir);
}


int cola_es_vacia(Cola cola) { return glist_vacia(cola); }


void* cola_inicio(Cola cola, FuncionCopia copiar) { 
  
  return glist_primer_elemento(cola, copiar);
}


Cola cola_encolar(Cola cola, void* dato, FuncionCopia c) { 
  
  return glist_agregar_final(cola, dato, c);
}


Cola cola_desencolar(Cola cola, FuncionDestructora d) {

   return glist_eliminar_inicio(cola, d);
}
