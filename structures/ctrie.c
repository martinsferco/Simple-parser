#include "ctrie.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



struct CTrieNode { // Estructura del nodo de nuestro CTrie

  char* string;

  int length; // Largo de la cadena

  unsigned int end_of_word; // Vemos si llegamos hasta un fin de cadena

  unsigned int start_memory_block; // Vemos si en el nodo, 'string' apunta al 
                                   // comienzo de un bloque de memoria 

  struct CTrieNode** childs; // Hijos del nodo

};


typedef enum { // Definimos las opciones de copiado, al crear un nuevo nodo

  PHYSIC_COPY,
  POINTER_COPY,

} CopyOption;


CTrie ctrie_create() { return NULL; }



static CTrie ctrie_create_node(char* string, int length, CopyOption option) { 

  CTrie new_node = malloc(sizeof(struct CTrieNode));

  // Seteamos variables del bloque
  new_node->start_memory_block = option == PHYSIC_COPY;
  new_node->end_of_word = 1; 

  new_node->length = length;

  // Copiamos el string fisicamente, o solo guardamos su direccion
  if (option == POINTER_COPY) new_node->string = string;

  else {
    
    new_node->string = malloc(sizeof(char) * (length + 1));
    strcpy(new_node->string, string);  
  }
  
  // Pedimos memoria para todos los hijos
  new_node->childs = malloc(sizeof(CTrie) * ALPHABET_SIZE);

  // Inicializamos todos sus hijos a NULL
  for (int i = 0 ; i < ALPHABET_SIZE; new_node->childs[i++] = ctrie_create());

  return new_node;
}



/**
 * Dados dos CTrie, la funcion intercambia todos los hijos de uno por los hijos
 * del otro y visceversa.
*/
static void ctrie_exchange_childs(CTrie ctrie1, CTrie ctrie2) {

  CTrie* childs = ctrie1->childs;
  ctrie1->childs = ctrie2->childs;
  ctrie2->childs = childs;
}



/**
 * 
*/
static CTrie ctrie_extend_node(CTrie ctrie, int index) {

  // Creamos el nodo que sera la extension del nodo actual
  CTrie new_node = ctrie_create_node(ctrie->string + index, ctrie->length - index,
                                                            POINTER_COPY); 
  

  ctrie->length = index; // Actualizamos largo string

  new_node->end_of_word = ctrie->end_of_word; // Sera fin de palabra si la 
                                              // origina lo era 
  
  ctrie->end_of_word = 1; // El nodo actual pasa a ser un fin de palabra

  
  ctrie_exchange_childs(new_node, ctrie); // Intercambiamos hijos
  

  // Lo ponemos como nuevo hijo
  ctrie->childs[(int)ctrie->string[index] - OFFSET] = new_node; 

  return ctrie;

}



/**
 * Esta funcion toma un CTrie, 
*/
static CTrie ctrie_create_bifurcation(CTrie ctrie, char* string, int index) {

  // Creamos el nodo en donde guardaremos la otra parte del string del nodo, 
  // que no coincidio con el string a insertar.
  CTrie string_partition_node = ctrie_create_node(ctrie->string + index,
                                                  ctrie->length - index,
                                                  POINTER_COPY);


  ctrie->length = index; // Actualizamos largo string

  ctrie->end_of_word = 0; // AL haberse particionado, no es mas fin de palabra


  // Los hijos del nodo resultante de la particion del string del nodo actual, 
  // tendra como hijos a los del actual. 
  ctrie_exchange_childs(string_partition_node, ctrie);

  
  // Creamos el nodo donde almacenaremos la parte del string a insertar, que no 
  // coincidio con el string del nodo
  CTrie new_string_node = ctrie_create_node(string + index,
                                            strlen(string) - index,
                                            PHYSIC_COPY); 


  // A los dos nuevos nodos, los agregamos como hijos del nodo actual
  ctrie->childs[(int)ctrie->string[index] - OFFSET] = string_partition_node;
  ctrie->childs[string[index] - OFFSET] = new_string_node;

  return ctrie;
}



CTrie ctrie_add_string(CTrie ctrie, char* string) {

  if (string == NULL) return ctrie; 


  if (ctrie_empty(ctrie)) { // Si el CTrie esta vacio, agregamos la cadena
                           // a un nuevo nodo

    return ctrie_create_node(string, strlen(string), PHYSIC_COPY);
  }


  // Si el CTrie no esta vacio, tenemos que recorrer el string del nodo
  int i;

  // Recorremos hasta que no matcheen o lleguemos al final de alguna cadena
  for (i = 0 ; ctrie->string[i] == string[i] && string[i] != '\0' && i < ctrie->length ; i++);


  // CASO 1: La palabra y el string del nodo coinciden en largo y caracteres
  if (string[i] == '\0' && i == ctrie->length) {

    // Marcamos como fin de palabra, si antes no lo era
    if (! ctrie->end_of_word) ctrie->end_of_word = 1;
  }


  // CASO 2: La palabra es mas chica que el string del nodo y coincidio en todo 
  else if (string[i] == '\0') 
    
    ctrie = ctrie_extend_node(ctrie, i);


  // CASO 3: La palabra es mas larga que el string del nodo y coincidio en todo 
  else if (i == ctrie->length) {

    CTrie new_child =  ctrie_add_string(ctrie->childs[(int)string[i] - OFFSET], string + i);

    ctrie->childs[(int)string[i] - OFFSET] = new_child;
  }


  // CASO 4: La palabra no coincide en algun caracter con el string del nodo 
  else if (ctrie->string[i] != string[i]) 
    
    ctrie = ctrie_create_bifurcation(ctrie, string, i);
    

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


int ctrie_search_string(CTrie ctrie, char* string) { // TODO CORREGIR

  int i;

  for (i = 0 ; ctrie->string[i] == string[i] && string[i] != '\0' && i < ctrie->length ; i++);


  // Si coinciden, solo se encuentra en el ctrie si el nodo tiene fin de palabra
  if (string[i] == '\0' && i == ctrie->length) return ctrie->end_of_word;

  // Seguimos buscando el otro pedazo del string en los hijos del CTrie
  else if (i == ctrie->length) { 
    
    CTrie child = ctrie->childs[(int)string[i] - OFFSET];

    // Solo buscamos si existe el hijo
    return child ? ctrie_search_string(child, string + i) : 0;
  }

  // Cualquier otro caso, no se encuentra la palabra
  else return 0;
}



void ctrie_iterate(CTrie ctrie) {

  if (ctrie_empty(ctrie)) return;
  printf("------------------\n");
  for (int i = 0 ; i < ctrie->length ; i++) // Imprimimos los caracteres del string
  
    printf("%c",ctrie->string[i]);
  

  printf("\n");
  printf("Bloque: %d\n", ctrie->start_memory_block);
  printf("Fin: %d\n", ctrie->end_of_word);
  printf("------------------\n");


  for (int i = 0 ; i < ALPHABET_SIZE ; i++) // Visitamos los hijos

    ctrie_iterate(ctrie->childs[i]);
}
