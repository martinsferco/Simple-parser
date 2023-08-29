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






int dictionary_largest_prefix(Dictionary dictionary, DinamicString string, int pos) {
  
  int i = 0;

  char c_string = dinamic_string_read(string, pos);
  char c_node = ctrie_node_char(dictionary, i); 

  int length = ctrie_node_length(dictionary);

  for (i = 0 ; c_node == c_string && c_string != '\0' && i < length ; i++) {
    
    c_string = dinamic_string_read(string, pos);
    c_node = ctrie_node_char(dictionary, i); 
  } 


  // Si coinciden y terminamos de leer la cadena, devolvemos el largo del nodo
  // solamente si es un fin de palabra
  if (c_string == '\0' && i == length)

    return ctrie_end_of_word(dictionary) ? ctrie_node_length(dictionary) : 0;


  // Nos vemos tantas posiciones en la linea, y vemos si podemos continuar
  // recorriendo el arbol
  else if (i == ctrie_node_length(dictionary)) {
    
    // Hijo que debemos seguir
    Dictionary child = ctrie_child(dictionary,(int)c_string - OFFSET); 


    // Nos guardamos la longitud del nodo, si es fin de palabra, si no, es nulo
    int prefix_length = ctrie_end_of_word(dictionary) ? ctrie_node_length(dictionary) : 0;

    // Vemos si podemos encontrar algun prefijo, cuando seguimos recorriendo
    // el diccionario
    int prefix_child_length = child ? dictionary_largest_prefix(child, string, pos) : 0;

    // Si encontramos un prefijo nuevo mas largo, devolvemos dicha distancia,
    // si no, devolvemos el largo del prefijo actual
    return prefix_child_length ? ctrie_node_length(dictionary) + prefix_child_length : prefix_length;

  }
  
  // Cualquier otro caso, no se encuentra otro prefijo
  else return 0;
}


void dictionary_iterate(Dictionary dictionary) { ctrie_iterate(dictionary); }


