#include "ctrie.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



CTrie ctrie_create() { return NULL; }



static CTrie ctrie_create_node(char* string, int length, CopyOption option) { 

  CTrie new_node = malloc(sizeof(CTrie_Node));

  new_node->string = malloc(sizeof(char) * (length + 1));


  if (option == POINTER_COPY) new_node->string = string;

  else strcpy(new_node->string, string);  
  
  
  new_node->length = length;

  new_node->start_memory_block = 0;
  new_node->end_of_word = 0;

  // Inicializamos todos sus hijos a NULL
  new_node->childs = malloc(sizeof(CTrie) * ALPHABET_SIZE);

  for (int i = 0 ; i < ALPHABET_SIZE; new_node->childs[i++] = NULL);

  return new_node;
}

static CTrie ctrie_extend_node(CTrie ctrie, char* string) {}



static CTrie ctrie_create_bifurcation(CTrie ctrie, char* string) {}



CTrie ctrie_add_string(CTrie ctrie, char* string) {

  if (string == NULL) return ctrie; 


  if (ctrie_empty(ctrie))  // Si el CTrie esta vacio, agregamos la cadena
                           // a un nuevo nodo

    return ctrie_create_node(string, strlen(string), PHYSIC_COPY);



  // Si el CTrie no esta vacio, tenemos que recorrer el string del nodo
  int i;

  // Recorremos hasta que no matcheen o lleguemos al final de alguna cadena
  for (i = 0 ; ctrie->string[i] == string[i] && string[i] != '\0' && i < ctrie->length ; i++);


  // CASO 1: La palabra y el string del nodo coinciden en largo y caracteres
  if (string[i] == '\0' && i == ctrie->length) {

    // Marcamos como fin de palabra, si antes no lo era
    if (! ctrie->end_of_word) ctrie->end_of_word = 1;
  }
  
  // CASO 2: La palabra es mas chica que el string del nodo y coincidio en todo // TODO MODULARIZAR
  else if (string[i] == '\0') {

    
    CTrie new_node = ctrie_create_node(ctrie->string + i, ctrie->length - i, POINTER_COPY); // TODO CORREGIR
    ctrie->length = i; // Actualizamos largo cadena

    new_node->end_of_word= 1;
    

    CTrie* change = new_node->childs;
    new_node->childs = ctrie->childs;
    ctrie->childs= change;



    ctrie->childs[(int)(ctrie->string[i]) - OFFSET] = new_node; // Agregar opcion de copiar, o no copiar
    
  }

  // CASO 3: La palabra es mas larga que el string del nodo y coincidio en todo 
  else if (i == ctrie->length) {

    CTrie new_child =  ctrie_add_string(ctrie->childs[(int)string[i] - OFFSET], string + i);

    ctrie->childs[(int)string[i] - 97] = new_child;

  }

  // CASO 4: La palabra no coincide en algun caracter con el string del nodo // TODO MODULARIZAR
  else if (ctrie->string[i] != string[i]) {
    
    CTrie nuevo_nodo1 = ctrie_create_node(ctrie->string + i, ctrie->length - i, POINTER_COPY); //TODO CORREGIR

    ctrie->length = i;

    CTrie* change = ctrie->childs;

    ctrie->childs = nuevo_nodo1->childs;

    nuevo_nodo1->childs = change;

    ctrie->childs[(int)ctrie->string[i] - OFFSET] = nuevo_nodo1;

    CTrie nuevo_nodo2 = ctrie_create_node(string + i, strlen(string) - i, POINTER_COPY); //TODO CORREGIR

    ctrie->childs[string[i] - OFFSET] = nuevo_nodo2;
  }



  return ctrie;
}


int ctrie_empty(CTrie ctrie) { return ctrie == NULL; }


void ctrie_destroy(CTrie ctrie) {

  if (! ctrie_empty(ctrie)) {

    for (int i = 0 ; i < ALPHABET_SIZE ; i++)
      
      // Liberamos cada uno de los hijos
      if (! ctrie_empty(ctrie->childs[i])) ctrie_destroy(ctrie->childs[i]);
      
    // Liberamos el arreglo de hijos
    free(ctrie->childs);

    // Liberamos la cadena, solo si el string es el comienzo del bloque
    if (ctrie->start_memory_block) free(ctrie->string);   

    // Liberamos el nodo
    free(ctrie);
  }
}



void ctrie_iterate(CTrie ctrie) {

  if (ctrie_empty(ctrie)) return;

  for (int i = 0 ; i < ctrie->length ; i++) // Imprimimos los caracteres del string
    printf("%c",ctrie->string[i]);

  printf("\n");

  for (int i = 0 ; i < ALPHABET_SIZE ; i++) // Visitamos los hijos

    ctrie_iterate(ctrie->childs[i]);
}
