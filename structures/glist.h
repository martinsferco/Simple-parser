#ifndef __GLIST_H__
#define __GLIST_H__

// TODO: Agregar una interfaz de alto nivel

typedef void (*DestroyFunction) (void*);
typedef void* (*CopyFunction) (void*);
typedef void (*VisitFunction) (void*);

typedef struct _GNode {

  void* data;
  struct _GNode* next;

} GNode;


typedef struct {

  GNode* first;
  GNode* last;

} GList;


/**
 * Devuelve una lista vacia.
*/
GList glist_create();

/**
 * Destruye la lista.
*/
void glist_destroy(GList list, DestroyFunction destroy);

/**
 * Determina si la lista esta vacia.
*/
int glist_empty(GList list);

/**
 * Agrega un elemento al comienzo de la lista.
*/
GList glist_add_end(GList list, void* data, CopyFunction copy);

/**
 * Elimina el ultimo elemento de la lista.
*/
GList glist_remove_first(GList list, DestroyFunction destroy);

/**
 * Nos devuleve el primer elemento de la lista. No queda determinado el 
 * comportamiento si la lista esta vacia.
*/
void* glist_first_element(GList list, CopyFunction copy);
 

/**
 * Recorre la lista, aplicando la funcion visitante a cada uno de los elementos.
*/
void* glist_iterate(GList lista, VisitFunction visitante);

#endif