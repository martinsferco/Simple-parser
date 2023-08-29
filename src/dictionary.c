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
  
  int i;

  int length = ctrie_node_length(dictionary);
  
  char c = dinamic_string_read(string, pos);

  for (i = 0 ; c != '\0' && i < length && ctrie_node_char(dictionary, i) == c ; i++)
  
    c = dinamic_string_read(string, i + pos + 1);


  // Si coinciden y terminamos de leer la cadena, devolvemos el largo del nodo
  // solamente si es un fin de palabra
  if (c == '\0' && i == length)

    return ctrie_end_of_word(dictionary) ? length : 0;


  // Nos vemos tantas posiciones en la linea, y vemos si podemos continuar
  // recorriendo el arbol
  else if (i == length) {
    
    // Hijo que debemos seguir
    Dictionary child = ctrie_child(dictionary,(int)c - OFFSET); 


    // Nos guardamos la longitud del nodo, si es fin de palabra, si no, es nulo
    int prefix_length = ctrie_end_of_word(dictionary) ? length : 0;

    // Vemos si podemos encontrar algun prefijo, cuando seguimos recorriendo
    // el diccionario
    int prefix_child_length = child ? dictionary_largest_prefix(child, string, pos + i) : 0;

    // Si encontramos un prefijo nuevo mas largo, devolvemos dicha distancia,
    // si no, devolvemos el largo del prefijo actual
    return prefix_child_length ? length + prefix_child_length : prefix_length;

  }
  
  // Cualquier otro caso, no se encuentra otro prefijo
  else return 0;
}


void dictionary_iterate(Dictionary dictionary) { ctrie_iterate(dictionary); }


