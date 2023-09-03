#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__


#define READ_SIZE 1000 // Maximo tamanio de lectura para carga diccionario


#include <stdlib.h>
#include <stdio.h>
#include "../structures/ctrie.h"
#include "../structures/dstring.h"


typedef CTrie Dictionary; // Tipo Dictionary


//! @brief Crea un diccionario vacio.
//! @return Un nuevo diccionario vacio.
Dictionary dictionary_create();


//! @brief Destruye un diccionario.
//! @param[out] dictionary: Diccionario que queremos destruir.
void dictionary_destroy(Dictionary dictionary);


//! @brief Carga el diccionario a partir de las cadenas que se encuentran en
//!        un archivo.
//! @param[out] dictionary: Dictionary que queremos cargar.
//! @param[in] file: Puntero a archivo del que queremos cargar el diccionario.
//! @return El diccionario con todas las palabras del archivo cargadas.
Dictionary dictionary_load_from_file(Dictionary dictionary, FILE* file);

//? VER SI INCLUIR ESTA FUNCION
//! @brief Recorre el diccionario, mostrando el contenido de sus nodos.
//! @param[in] dictionary: Diccionario del cual queremos mostrar su contenido.
void dictionary_iterate(Dictionary dictionary);


//! @brief Busca la maxima longitud de prefijo valido desde una determinada 
//!        posicion de una cadena, en funcion de un diccionario. 
//! @param[in] dictionary: Diccionario de donde buscamos las palabras validas.
//! @param[out] string: DString de donde buscamos el maximo prefijo y vamos
//!                     guardando los caracteres todavia no leidos del archivo.
//! @param[in] pos: Posicion desde donde queremos hacer la busqueda.
//! @param[in] file: Puntero a archivo del que queremos parsear la linea.
//! @return La maxima longitud de prefijo desde la posicion indicada.
int dictionary_largest_prefix(Dictionary dictionary, DString string, int pos, FILE* file);

#endif // __DICTIONARY_H__