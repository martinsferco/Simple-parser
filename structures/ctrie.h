#ifndef __CTRIE_H__
#define __CTRIE_H__

#define TAM_ALFABETO 26 // Definimos como constante global el tamanio del alfabeto


typedef struct _Casilla {

  char letra;                   // Caracter de la casilla.
  struct _Casilla* sufijo_max;  // Sufijo maximo en el CTrie.
  struct _Casilla* sufijo_dict; // Sufijo maximo en el diccionario.

} Casilla;


typedef struct _CTrie_Nodo {

  Casilla* cadena;

  int largo_cadena; // Largo de la cadena

  unsigned int fin_cadena; // Vemos si llegamos hasta un fin de cadena
  unsigned int comienzo_cadena; // Vemos si es el comienzo de una cadena alocada

  struct _CTrie_Nodo hijos[TAM_ALFABETO]; // Hijos del nodo

} CTrie_Nodo;


typedef CTrie_Nodo* CTrie; // Definimos el tipo CTrie


/**
 * Dada una cadena, se encarga de insertarla en el CTrie.
*/
CTrie ctrie_agregar_cadena(CTrie ctrie, char* cadena);

/**
 * Dado un CTrie que ya fue cargado con todas las cadenas que se van a utilizar,
 * comienza a determinar los sufijos propios mas largos que se encuentren en el 
 * CTrie, de cada una de las partes de las cadenas.
*/
CTrie ctrie_encontrar_sufijos_maximos(CTrie ctrie);

/**
 * Dado un CTrie que ya fue cargado con todas las cadenas, y realizado en enlaze
 * de los maximos sufijos del CTrie, se encarga de enlazar cada una de las partes
 * de las cadenas, con un sufijo del CTrie que se encuentre dentro del diccionario.
*/
CTrie ctrie_encontrar_sufijos_diccionario(CTrie ctrie);

/**
 * Dado un CTrie cargado y enlazado, y un comienzo de una cadena, nos devuelve
 * la longitud de la maxima cadena encontrada, empezando desde la direccion
 * apuntada por el puntero pasado.
*/
int ctrie_buscar_cadena(CTrie trie, char* cadena);

/**
 * Destruye el CTrie pasado como argumento.
*/
void ctrie_destruir(CTrie ctrie);



#endif