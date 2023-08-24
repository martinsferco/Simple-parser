#ifndef __CTRIE_H__
#define __CTRIE_H__


#define TAM_ALFABETO 26 // Definimos el tamanio del alfabeto
#define OFFSET (int)('a') // Definimos el valor ASCII de el caracter 'a'


typedef struct _CTrie_Nodo {

  char* cadena;

  int largo_cadena; // Largo de la cadena

  unsigned int fin_cadena; // Vemos si llegamos hasta un fin de cadena
  unsigned int comienzo_cadena; // Vemos si es el comienzo de una cadena

  struct _CTrie_Nodo** hijos; // Hijos del nodo

} CTrie_Nodo;


typedef enum {

  COPIA_FISICA,
  COPIA_PUNTERO,

} OpcionCopiado;



typedef CTrie_Nodo* CTrie; // Definimos el tipo CTrie


/**
 * Crea un CTrie vacio.
*/
CTrie ctrie_crear();


/**
 * Determina si el CTrie esta vacio.
*/
int ctrie_vacio(CTrie ctrie);


/**
 * Dada una cadena, se encarga de insertarla en el CTrie.
*/
CTrie ctrie_agregar_cadena(CTrie ctrie, char* cadena);


/**
 * Destruye el CTrie pasado como argumento.
*/
void ctrie_destruir(CTrie ctrie);

/**
 * Recorre el ctrie, en un orden dado, mostrando las cadenas de cada
 * uno de los nodos. Consideramos que se procesa el nodo, y luego se recorren
 * los subarboles de izquierda a derecha.
*/
void ctrie_recorrer(CTrie ctrie);


#endif