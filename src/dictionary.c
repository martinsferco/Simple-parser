#include "dictionary.h"



Dictionary dictionary_create() { return ctrie_create(); }

Dictionary dictionary_load_from_file(Dictionary dictionary, FILE* file) { // TODO CORREGIR

  char buffer[READ_SIZE];

  while (EOF != fscanf(file, "%[^\n]\n", buffer)) { 
    
    dictionary = ctrie_add_string(dictionary, buffer);

  }
  return dictionary;
}


void dictionary_destroy(Dictionary dictionary) { ctrie_destroy(dictionary); }


int dictionary_largest_prefix(Dictionary dictionary, FILE* file) {
  
  char c = fgetc(file);

  int i;

  for (i = 0 ; dictionary->string[i] == c && c != '\n' && i < dictionary->length ; i++) 

    c = fgetc(file);
  

  // Si coinciden y terminamos de leer la cadena, devolvemos el largo del nodo
  // solamente si es un fin de palabra
  if (c == '\n' && i == dictionary->length) { 
    
    file->_IO_read_ptr --;
    // fseek(file, -1, SEEK_CUR);
    return dictionary->end_of_word ? dictionary->length : 0;

  }
  // Nos vemos tantas posiciones en la linea, y vemos si podemos continuar
  // recorriendo el arbol
  else if (i == dictionary->length) {
    
    Dictionary child = dictionary->childs[(int)c - OFFSET]; // Hijo que debemos seguir

    // Nos vemos un caracter antes, para poder seguir buscando en el diccionario
    //fseek(file, -1, SEEK_CUR);
    file->_IO_read_ptr --;


    // Nos guardamos la longitud del nodo, si es fin de palabra, si no, es nulo
    int prefix_length = dictionary->end_of_word ? dictionary->length : 0;

    // Vemos si podemos encontrar algun prefijo, cuando seguimos recorriendo
    // el diccionario
    int prefix_child_length = child ? dictionary_largest_prefix(child, file) : 0;

    // Si encontramos un prefijo nuevo mas largo, devolvemos dicha distancia,
    // si no, devolvemos el largo del prefijo actual
    return prefix_child_length ? dictionary->length + prefix_child_length : prefix_length;

  }
  
  // Cualquier otro caso, no se encuentra la palabra
  else return 0;
  


}


void dictionary_iterate(Dictionary dictionary) { ctrie_iterate(dictionary); }


