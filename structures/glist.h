#ifndef __GLIST_H__
#define __GLIST_H__

// TODO: Agregar una interfaz de alto nivel

typedef void (*FuncionDestructora) (void*);
typedef void* (*FuncionCopia) (void*);
typedef void (*FuncionVisitante) (void*);

typedef struct _GNode {

  void* dato;
  struct _GNode* sig;

} GNode;


typedef struct {

  GNode* primero;
  GNode* ultimo;

} GList;


/**
 * Devuelve una lista vacia.
*/
GList glist_crear();

/**
 * Destruye la lista.
*/
void glist_destruir(GList lista, FuncionDestructora destruir);

/**
 * Determina si la lista esta vacia.
*/
int glist_vacia(GList lista);

/**
 * Agrega un elemento al comienzo de la lista.
*/
GList glist_agregar_final(GList lista, void* dato, FuncionCopia copiar);

/**
 * Elimina el ultimo elemento de la lista.
*/
GList glist_eliminar_inicio(GList lista, FuncionDestructora destruir);

/**
 * Nos devuleve el primer elemento de la lista. No queda determinado el 
 * comportamiento si la lista esta vacia.
*/
void* glist_primer_elemento(GList lista, FuncionCopia copiar);


/**
 * Recorre la lista, aplicando la funcion visitante a cada uno de los elementos.
*/
void* glist_recorrer(GList lista, FuncionVisitante visitante);

#endif