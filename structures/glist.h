#ifndef __GLIST_H__
#define __GLIST_H__


typedef void (*DestroyFunction) (void*);
typedef void* (*CopyFunction) (void*);
typedef void (*VisitFunction) (void*);


typedef struct _GList* GList;


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
 * Agrega un elemento al final de la lista.
*/
void glist_add_last(GList list, void* data, CopyFunction copy);

/**
 * Elimina el primer elemento de la lista.
*/
void glist_remove_first(GList list, DestroyFunction destroy);

/**
 * Nos devuleve una copia del primer elemento de la lista.
*/
void* glist_first_element(GList list, CopyFunction copy);
 

/**
 * Recorre la lista, aplicando la funcion visitante a cada uno de los elementos.
*/
void* glist_iterate(GList lista, VisitFunction visit);

#endif // __GLIST_H__