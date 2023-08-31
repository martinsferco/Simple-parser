#ifndef __DSTRING_H__
#define __DSTRING_H__

#include <stdio.h>

typedef struct _DString* DString; // Definimos el tipo de string dinamico


/**
 * Crea un arreglo dinamico con una cierta capacidad inicial.
*/
DString dstring_create(int initial_capacity);


/**
 * Destruye un arreglo dinamico.
*/
void dstring_destroy(DString string);


/**
 * Leemos una casilla del arreglo dinamico.
*/
char dstring_read(DString string, int pos);


/**
 * Escribimos en una casilla del arreglo dinamico.
*/
void dstring_write(DString string, int pos, char c);


/**
 * Imprime una seccion del string.
*/
void dstring_print_segment(DString string, int start, int length);


/**
 * Devuelve la capacidad del arreglo dinamico.
*/
int dstring_capacity(DString string);


/**
 * Devuelve la cantidad de arreglo utilizado en el string dinamico
*/
int dstring_used(DString string);



/**
 * Aumentamos la capacidad del arreglo dinamico por un factor RESIZE_FACTOR.
*/
void dstring_extends(DString string);



/**
 * 
*/
char dstring_add_end(DString string, FILE* file);


/**
 * 
*/
void dstring_reset(DString string); 



#endif // __DSTRING_H__