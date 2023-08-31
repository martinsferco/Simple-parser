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
 * Encola un elemento a la cola pasada como argumento.
*/
void queue_enqueue(Queue queue, void* data);

/**
 * Desencola al primer elemento de la cola y nos los devuelve
*/
void* queue_dequeue(Queue queue);


void queue_dequeue_print(Queue queue);


#endif // __QUEUE_H__