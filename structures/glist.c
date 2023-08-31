#include "glist.h"
#include <stdlib.h>



typedef struct _GNode {

  void* data;
  struct _GNode* next;

} GNode;



struct _GList {

  GNode* first;
  GNode* last;

};



GList glist_create() {

  GList new_list = malloc(sizeof(struct _GList));

  new_list->first = NULL;
  new_list->last = NULL;

  return new_list;
}


void glist_destroy(GList list, DestroyFunction destroy) {

  GNode* remove_node;

  GNode* temp = list->first;

  while (temp != NULL) {

    remove_node = temp;
    temp = temp->next;
    destroy(remove_node->data);
    free(remove_node);
  }
}



int glist_empty(GList list) { return (list->first == NULL); }



void glist_add_last(GList list, void* data, CopyFunction copy) {

  GNode* new_node = malloc(sizeof(GNode));
  new_node->data = copy(data);

  if (glist_empty(list)) {

    new_node->next = NULL;
    list->first = new_node;
    list->last = new_node;
  }

  else {

    new_node->next = NULL;
    list->last->next = new_node;
    list->last = new_node;
  }
}



void glist_remove_first(GList list, DestroyFunction destroy) {

  if (glist_empty(list)) return;

  GNode* new_start = list->first->next;

  // Liberamos el primer nodo
  destroy(list->first->data);
  free(list->first);

  list->first = new_start;
}



void* glist_first_element(GList list, CopyFunction copy) {

  return glist_empty(list) ? NULL : copy(list->first->data);
}



void* glist_recorrer(GList list, VisitFunction visit) {

  for (GNode* temp = list->first ; temp != NULL ; temp->next)
    visit(temp->data);
}





