#ifndef __DSTRING_H__
#define __DSTRING_H__

#include <stdio.h>

typedef struct _DString* DString; // Definimos el tipo de string dinamico


//! @brief Crea un DString vacio con cierta capacidad inicial.
//! @param[in] initialCapacity: Capacidad inicial que tendra el DString.
//! @return El nuevo DString, con la capacidad incial pasada.
DString dstring_create(int initialCapacity);


//! @brief Destruye un DString.
//! @param[in] string: DString que queremos destruir.
void dstring_destroy(DString string);


//! @brief Se encarga de leer el caracter en una posicion del DString.
//! @param[in] string: String del cual queremos leer el caracter.
//! @param[in] pos: Posicion de la que queremos leer el caracter.
//! @return El caracter que leimos.
char dstring_read(DString string, int pos);


//! @brief Se encarga de escribir un caracter en una posicion del DString.
//! @param[out] string: String en el cual queremos escribir el caracter.
//! @param[in] pos: Posicion en la cua queremos escribir el caracter.
//! @param[in] c: Caracter que queremos escribir.
void dstring_write(DString string, int pos, char c);


//! @brief Se encar
//! @param[in] string:
//! @param[in] start:
//! @param[in] length:
//! @param[out] destiny:
void dstring_save_segment(DString string, int start, int length, FILE* destiny);


//! @brief Se encar
//! @param[in] string:
//! @return 
int dstring_capacity(DString string);


//! @brief Se encar
//! @param[in] string:
//! @return 
int dstring_used(DString string);



//! @brief Se encar
//! @param[in] string:
void dstring_extends(DString string);



//! @brief Se encar
//! @param[in] string:
//! @param[in] i:
//! @return
char* dstring_pointer_index(DString string, int i);


//! @brief Se encar
//! @param[in] string:
//! @param[in] file:
//! @return
char dstring_add_end(DString string, FILE* file);


//! @brief Se encar
//! @param[in] string:
void dstring_reset(DString string); 



#endif // __DSTRING_H__