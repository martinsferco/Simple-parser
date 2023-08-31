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

  GList newList = malloc(sizeof(struct _GList));

  newList->first = NULL;
  newList->last = NULL;

  return newList;
}


void glist_destroy(GList list, DestroyFunction destroy) {

  GNode* removedNode;

  GNode* temp = list->first;

  while (temp != NULL) {

    removedNode = temp;
    temp = temp->next;
    destroy(removedNode->data);
    free(removedNode);
  }
}



int glist_empty(GList list) { return (list->first == NULL); }



void glist_add_last(GList list, void* data, CopyFunction copy) {

  GNode* newNode = malloc(sizeof(GNode));
  newNode->data = copy(data);

  if (glist_empty(list)) {

    newNode->next = NULL;
    list->first = newNode;
    list->last = newNode;
  }

  else {

    newNode->next = NULL;
    list->last->next = newNode;
    list->last = newNode;
  }
}



void glist_remove_first(GList list, DestroyFunction destroy) {

  if (glist_empty(list)) return;

  GNode* newStart = list->first->next;

  // Liberamos el primer nodo
  destroy(list->first->data);
  free(list->first);

  list->first = newStart;
}



void* glist_first_element(GList list, CopyFunction copy) {

  return glist_empty(list) ? NULL : copy(list->first->data);
}



void* glist_recorrer(GList list, VisitFunction visit) {

  for (GNode* temp = list->first ; temp != NULL ; temp->next)
    visit(temp->data);
}





