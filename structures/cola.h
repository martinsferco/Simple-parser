#ifndef __COLA_H__
#define __COLA_H__

#include "glist.h"


typedef GList Cola; // Impletamos el tipo Cola con una Lista General


/**
 * Devuelve una cola vacia.
*/
Cola cola_crear();

/**
 * Destruye la cola pasada como argumento.
*/
void cola_destruir(Cola cola, FuncionDestructora destruir);

/**
 * Determina si la cola pasada como argumento es vacia.
*/
int cola_es_vacia(Cola cola);

/**
 * Nos devuelve el primer elemento de la cola. No queda determinado el 
 * comportamiento si la cola se encuentra vacia
*/
void* cola_inicio(Cola cola, FuncionCopia copiar);

/**
 * Encola un elemento e la lsita pasada como argumento.
*/
Cola cola_encolar(Cola cola, void* dato, FuncionCopia copiar);

/**
 * Desencola al primer elemento de la cola.
*/
Cola cola_desencolar(Cola cola, FuncionDestructora destruir);

#endif