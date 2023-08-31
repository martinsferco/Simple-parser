#include "queue.h"


Queue queue_create() { return glist_create(); }


void queue_destroy(Queue queue, DestroyFunction destroy) { 

  glist_destroy(queue, destroy);
}


int queue_empty(Queue queue) { return glist_empty(queue); }


void* queue_first(Queue queue, CopyFunction copy) { 

  return glist_first_element(queue, copy);
}

void queue_enqueue(Queue queue, void* data, CopyFunction copy) { 

  glist_add_last(queue, data, copy);
}


void queue_dequeue(Queue queue, DestroyFunction destroy) {

  glist_remove_first(queue, destroy);
}
