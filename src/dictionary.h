#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__


#define READ_SIZE 1000 // Maximo tamanio de lectura de diccionario


#include <stdlib.h>
#include <stdio.h>
#include "../structures/ctrie.h"
#include "../structures/dstring.h"


typedef CTrie Dictionary; // Definimos el tipo Dictionary


/**
 * Crea un diccionario vacio.
*/
Dictionary dictionary_create();


/**
 * Carga el diccionario a partir de las cadenas que se encuentran
 * en un archivo.
*/
Dictionary dictionary_load_from_file(Dictionary dictionary, FILE* file);


/**
 * Recorre el diccionario, mostrando el contenido de sus nodos.
*/
void dictionary_iterate(Dictionary dictionary);


/**
 * Destruye el diccionario.
*/
void dictionary_destroy(Dictionary dictionary);

/**
 * Dado un diccionario y un puntero a posicion de una linea de archivo, 
 * nos devuelve la maxima longitud de un prefijo que comienze en dicha
 * posicion.
*/
int dictionary_largest_prefix(Dictionary dictionary, DString string, int pos, FILE* file);

#endif // __DICTIONARY_H__