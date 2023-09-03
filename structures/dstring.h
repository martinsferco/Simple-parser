#ifndef __DSTRING_H__
#define __DSTRING_H__



#include <stdio.h>



typedef struct _DString* DString; // Tipo DString



//! @brief Crea un DString vacio con cierta capacidad inicial.
//! @param[in] initialCapacity: Capacidad inicial que tendra el DString.
//! @return El nuevo DString, con la capacidad incial pasada.
DString dstring_create(int initialCapacity);


//! @brief Destruye un DString.
//! @param[out] string: DString que queremos destruir.
void dstring_destroy(DString string);


//! @brief Lee el caracter en una posicion del DString.
//! @param[in] string: String del cual queremos leer el caracter.
//! @param[in] pos: Posicion de la que queremos leer el caracter.
//! @return El caracter que leimos.
char dstring_read(DString string, int pos);


//! @brief Escribe un caracter en una posicion del DString.
//! @param[out] string: String en el cual queremos escribir el caracter.
//! @param[in] pos: Posicion en la cua queremos escribir el caracter.
//! @param[in] c: Caracter que queremos escribir.
void dstring_write(DString string, int pos, char c);


//! @brief Escribe en el archivo un segmento del dstring.
//! @param[in] string: Dstring del cual iremos leyendo los caracteres.
//! @param[in] start: Inicio del segmento que vamos a leer.
//! @param[in] length: Largo del segmento que vamos a leer.
//! @param[out] destiny: Puntero al archivo en donde escribiremos el segmento de
//!                      string.
void dstring_save_segment(DString string, int start, int length, FILE* destiny);



//! @brief Nos determina cuan usado esta un DString.
//! @param[in] string: DString del cual queremos saber cuan usado esta.
//! @return Numero de casilas que estan siendo usadas.
int dstring_used(DString string);


//! @brief Agrega un caracter al final del DString.
//! @param[out] string: DString al cual queremos agregar el caracter.
//! @param[in] c: Caracter que queremos agregar.
//! @note En caso de que no haya mas capacidad para el caracter, extendemos el 
//!       DString.
void dstring_append(DString string, char c);


//! @brief Agrega un caracter leido desde un archivo, al final del DString.
//! @param[in] string: DString al cual agregaremos el caracter leido.
//! @param[in] file: Puntero al archivo de donde leeremos el caracter.
//! @return Caracter leido desde el archivo.
char dstring_append_from_file(DString string, FILE* file);


//! @brief Resetea un DString, poniendo su valor de uso en cero.
//! @param[in] string: DString al cual queremos resetear.
void dstring_reset(DString string); 



char dstring_last(DString string);

#endif // __DSTRING_H__