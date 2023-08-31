#ifndef __QUEUE_H__
#define __QUEUE_H__



#include "glist.h"


typedef GList Queue; // Impletamos el tipo Cola con una Lista General


/**
 * Devuelve una cola vacia.
*/
Queue queue_create();

/**
 * Destruye la cola pasada como argumento.
*/
void queue_destroy(Queue queue, DestroyFunction destroy);

/**
 * Determina si la cola pasada como argumento es vacia.
*/
int queue_empty(Queue queue);

/**
 * Nos devuelve el primer elemento de la cola. No queda determinado el 
 * comportamiento si la cola se encuentra vacia
*/
void* queue_first(Queue queue, CopyFunction copy);

/**
 * Encola un elemento e la lsita pasada como argumento.
*/
void queue_enqueue(Queue queue, void* data, CopyFunction copy);

/**
 * Desencola al primer elemento de la cola.
*/
void queue_dequeue(Queue queue, DestroyFunction destroy);


#endif // __QUEUE_H__