#ifndef __CTRIE_H__
#define __CTRIE_H__


typedef struct CTrieNode* CTrie; // Tipo CTrie


//! @brief Devuelve un nuevo CTrie vacio.
//! @return El nuevo CTrie vacio.
CTrie ctrie_create();


//! @brief Determina si un CTrie esta vacio.
//! @param[in] ctrie: CTrie que queremos determinar si esta vacio. 
//! @return 1 si esta vacio y 0 si no lo esta.
int ctrie_empty(CTrie ctrie);


//! @brief Agrega una cadena a un CTrie.
//! @param[out] ctrie: CTrie donde queremos agregar el string.
//! @param[in] string: String que queremos agregar al CTrie.
//! @return El mismo Ctrie, pero con el String agregado.
CTrie ctrie_add_string(CTrie ctrie, char* string);

//? VER SI INCLUIR ESTA FUNCION
//! @brief Busca un string en un CTrie.
//! @param[in] ctrie: CTrie en donde quremos buscar el string.
//! @param[in] string: String que queremos buscar.
//! @return 1 si se encuentra el string y 0 si no se encuentra.
int ctrie_search_string(CTrie ctrie, char* string);


// ? VER SI INCLUIR ESTA FUNCION
//! @brief Recorre el CTrie, mostrando las cadenas de cada uno de los nodos.
//! @param[in] ctrie CTrie que vamos a recorrer.
//! @note Al recorrer, se procesa el nodo y luego los subarboles de izquierda
//!       a derecha.
void ctrie_iterate(CTrie ctrie);


//! @brief Determina la longitud del string almacenado en la raiz del CTrie.
//! @param[in] ctrie: CTrie del cual queremos saber la longitud del string de szu 
//!                  raiz.
//! @return Longitud del string de la raiz del CTrie.  
int ctrie_node_length(CTrie ctrie);


//! @brief Nos devuelve un caracter de una posicion determinada del string que
//!        se encuentra en la raiz del CTrie. 
//! @param[in] ctrie: CTrie de donde queremos obtener el caracter.
//! @param[in] pos: Posicion de la queremos obtener el caracter.
//! @return Caracter del string en la posicion 'pos'.  
char ctrie_node_char(CTrie ctrie, int pos);


//! @brief Determina si el nodo es un fin de palabra.
//! @param[in] ctrie: CTrie del que queremos ver si guarda un fin de palabra.
//! @return 1 si el nodo contiene un fin de palabra y 0 en caso contrario.
int ctrie_end_of_word(CTrie ctrie);


//! @brief Nos devuelve el hijo asociado a un caracter del alfabeto. 
//! @param[in] ctrie: CTrie del que queremos obtener uno de sus hijos.
//! @param[in] c: Caracter asociado al hijo que queremos buscar. 
//! @return El hijo CTrie asociado al caracter pasado. 
CTrie ctrie_child(CTrie ctrie, char c);


//! @brief Destruye un CTrie.
//! @param[out] ctrie: CTrie que queremos destruir.
void ctrie_destroy(CTrie ctrie);

#endif // __CTRIE_H__