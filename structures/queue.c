#include "queue.h"
#include <stdio.h>

Queue queue_create() { return glist_create(); }


void queue_destroy(Queue queue, DestroyFunction destroy) { 

  glist_destroy(queue, destroy);
}


static void* id(void* data) { return data; }

static void skip(void* data) { return; }


int queue_empty(Queue queue) { return glist_empty(queue); }


void queue_enqueue(Queue queue, void* data) { 

  glist_add_last(queue, data, id); // Agregamos sin hacer copia fisica
}




void* queue_dequeue(Queue queue) {

  // Obtenemos el elemento, sin copiar fisica
  void* first_element = glist_first_element(queue, id); 

  // Lo eliminamos de la cola, pero no liberamos el dato
  glist_remove_first(queue, skip);

  return first_element;

}


void queue_dequeue_print(Queue queue) {

  while (! queue_empty(queue)) printf("%c", *((char*) queue_dequeue(queue)));

  printf("\n");


}
