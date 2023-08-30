#ifndef __DINAMIC_STRING_H__
#define __DINAMIC_STRING_H__

#include <stdlib.h>
#include <stdio.h>


typedef struct _DinamicString* DinamicString; // Definimos el tipo de string dinamico


/**
 * Crea un arreglo dinamico con una cierta capacidad inicial.
*/
DinamicString dinamic_string_create(int initial_capacity);


/**
 * Destruye un arreglo dinamico.
*/
void dinamic_string_destroy(DinamicString string);


/**
 * Leemos una casilla del arreglo dinamico.
*/
char dinamic_string_read(DinamicString string, int pos);


/**
 * Escribimos en una casilla del arreglo dinamico.
*/
void dinamic_string_write(DinamicString string, int pos, char c);


/**
 * Imprime una seccion del string.
*/
void dinamic_string_print_segment(DinamicString string, int start, int length);


/**
 * Devuelve la capacidad del arreglo dinamico.
*/
int dinamic_string_capacity(DinamicString string);


/**
 * Devuelve la cantidad de arreglo utilizado en el string dinamico
*/
int dinamic_string_used(DinamicString string);



/**
 * Aumentamos la capacidad del arreglo dinamico por un factor RESIZE_FACTOR.
*/
void dinamic_string_extends(DinamicString string);



/**
 * 
*/
char dinamic_string_add_end(DinamicString string, FILE* file);


/**
 * 
*/
void dinamic_string_reset(DinamicString string); 



#endif // __DINAMIC_STRING_H__