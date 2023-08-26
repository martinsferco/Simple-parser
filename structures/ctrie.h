#ifndef __CTRIE_H__
#define __CTRIE_H__


#define ALPHABET_SIZE 26 // Definimos el tamanio del alfabeto
#define OFFSET (int)('a') // Definimos el valor ASCII de el caracter 'a'


typedef struct _CTrie_Node { // Estructura del nodo de nuestro CTrie

  char* string;

  int length; // Largo de la cadena

  unsigned int end_of_word; // Vemos si llegamos hasta un fin de cadena

  unsigned int start_memory_block; // Vemos si en el nodo, 'string' apunta al 
                                   // comienzo de un bloque de memoria 

  struct _CTrie_Node** childs; // Hijos del nodo

} CTrie_Node;


typedef enum { // Definimos las opciones de copiado, al crear un nuevo nodo

  PHYSIC_COPY,
  POINTER_COPY,

} CopyOption;



typedef CTrie_Node* CTrie; // Definimos el tipo CTrie


/**
 * Crea un CTrie vacio.
*/
CTrie ctrie_create();


/**
 * Determina si el CTrie esta vacio.
*/
int ctrie_empty(CTrie ctrie);


/**
 * Dada una cadena, se encarga de insertarla en el CTrie.
*/
CTrie ctrie_add_string(CTrie ctrie, char* string);


/**
 * Destruye el CTrie pasado como argumento.
*/
void ctrie_destroy(CTrie ctrie);


/**
 * Busca un string en el CTrie.
*/
int ctrie_search_string(CTrie ctrie, char* string);


/**
 * Recorre el ctrie, en un orden dado, mostrando las cadenas de cada
 * uno de los nodos. Consideramos que se procesa el nodo, y luego se recorren
 * los subarboles de izquierda a derecha.
*/
void ctrie_iterate(CTrie ctrie);


#endif // __CTRIE_H__