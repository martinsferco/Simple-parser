#include "glist.h"
#include <stdlib.h>



GList glist_crear() {

  GList nueva_lista;

  nueva_lista.primero = NULL;
  nueva_lista.ultimo = NULL;

  return nueva_lista;
}


void glist_destruir(GList lista, FuncionDestructora destruir) {

  GNode* nodo_eliminado;

  GNode* temp = lista.primero;

  while (temp != NULL) {

    nodo_eliminado = temp;
    temp = temp->sig;
    destruir(nodo_eliminado->dato);
    free(nodo_eliminado);
  }
}



int glist_vacia(GList list) { return (list.primero == NULL); }



GList glist_agregar_final(GList lista, void* dato, FuncionCopia copiar) {

  GNode* nuevo_nodo = malloc(sizeof(GNode));
  nuevo_nodo->dato = copiar(dato);

  if (glist_vacia(lista)) {

    nuevo_nodo->sig = NULL;
    lista.primero = nuevo_nodo;
    lista.ultimo = nuevo_nodo;
  }

  else {

    nuevo_nodo->sig = NULL;
    lista.ultimo->sig = nuevo_nodo;
    lista.ultimo = nuevo_nodo;
  }

  return lista;
}



GList glist_eliminar_inicio(GList lista, FuncionDestructora destruir) {

  if (glist_vacia(lista)) return lista;

  GNode* nuevo_comienzo = lista.primero->sig;

  // Liberamos el primero nodo
  destruir(lista.primero->dato);
  free(lista.primero);

  lista.primero = nuevo_comienzo;

  return lista;
}



void* glist_primer_elemento(GList lista, FuncionCopia copiar) {

  return glist_vacia(lista) ? NULL : copiar(lista.primero->dato);
}



void* glist_recorrer(GList lista, FuncionVisitante visitante) {

  for (GNode* temp = lista.primero ; temp != NULL ; temp->sig)
    visitante(temp->dato);
}




