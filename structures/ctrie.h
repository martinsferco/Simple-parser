#ifndef __CTRIE_H__
#define __CTRIE_H__


#define ALPHABET_SIZE 26 // Definimos el tamanio del alfabeto
#define OFFSET (int)('a') // Definimos el valor ASCII de el caracter 'a'



typedef struct CTrieNode* CTrie; // Tipo CTrie



//! @brief Devuelve un nuevo CTrie vacio.
//! @return El nuevo arbol vacio.
CTrie ctrie_create();


//! @brief Determina si un CTrie esta vacio.
//! @param[in] ctrie: CTrie que queremos determinar si esta vacio. 
//! @return 1 si esta vacio y 0 si no lo esta.
int ctrie_empty(CTrie ctrie);


//! @brief Agrega una cadena a un CTrie.
//! @param[out] ctrie: CTrie donde queremos agregar el string.
//! @param[in] string: String que agregamos al CTrie.
//! @return El mismo Ctrie, pero con el String agregado.
CTrie ctrie_add_string(CTrie ctrie, char* string);


//! @brief Busca un string en el CTrie.
//! @param[in] ctrie: 
//! @param[in] string:
//! @return 
int ctrie_search_string(CTrie ctrie, char* string);


//! @brief Recorre el CTrie, mostrando las cadenas de cada uno de los nodos.
//! @param[in] ctrie CTrie que vamos a recorrer.
//! @note Al recorrer, se procesa el nodo y luego los subarboles de izquierda
//!       a derecha.
void ctrie_iterate(CTrie ctrie);


//! @brief Determina la longitud del string almacenado en la raiz del CTrie.
//! @param[in] ctrie: CTrie del cual queremos saber la longitud del string de ru 
//!                  raiz.
//! @return Longitud del string de la raiz del CTrie.  
int ctrie_node_length(CTrie ctrie);


//! @brief Nos devuelve un caracter de una posicion determinada del string 
//! @param[in] ctrie: 
//! @param[in] pos: Posicion de la queremos obtener el caracter.
//! @return Caracter en la posicion 'pos'  
char ctrie_node_char(CTrie ctrie, int pos);


//! @brief
//! @param[in] ctrie: 
//! @return 1 si 
int ctrie_end_of_word(CTrie ctrie);


//! @brief
//! @param[in] ctrie:
//! @return 
CTrie ctrie_child(CTrie ctrie, int i);


//! @brief Destruye un CTrie.
//! @param[out] ctrie: CTrie que queremos destruir.
void ctrie_destroy(CTrie ctrie);

#endif // __CTRIE_H__