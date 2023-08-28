#ifndef __DINAMIC_STRING_H__
#define __DINAMIC_STRING_H__


typedef struct {

  char* chars; // Datos guardados
  int capacity; // Capacidad total de elementos
  int used; // Cuantos elementos estan siendo utilizados   

} _DinamicString;



typedef _DinamicString* DinamicString; // Definimos el tipo de arreglo dinamico



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
void* dinamic_string_read(DinamicString string, int pos);

/**
 * Escribimos en una casilla del arreglo dinamico.
*/
void dinamic_string_write(DinamicString string, int pos, char c);


/**
 * Devuelve la capacidad del arreglo dinamico.
*/
int dinamic_string_capacity(DinamicString string);


/**
 * Devuelve cuanto del string ha sido utilizado
*/
int dinamic_string_used(DinamicString string);

/**
 * Aumentamos la capacidad del arreglo dinamico por un factor RESIZE_FACTOR
*/
void dinamic_string_extends(DinamicString string);


#endif // __DINAMIC_STRING_H__