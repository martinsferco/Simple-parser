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






int dictionary_largest_prefix(Dictionary dictionary, DString string, int pos, FILE* file) {
  
  int i = 0; // Indice que usaremos para recorrer string del nodo del diccionario

  int length = ctrie_node_length(dictionary);   
  
  char c;

  // Todo podemos modularizar esta parte
  if (pos < dstring_used(string)) // Ya leimos este parte del archivo
      
      c = dstring_read(string, pos + i);  

    else // Nunca leimos esta parte del archivo, leemos del archivo y guardamos

      c = dstring_add_end(string, file);
    
  
  for (; c != '\n' && c != EOF && i < length && ctrie_node_char(dictionary, i) == c ; i++) {
  
    if (pos + i + 1 < dstring_used(string)) // Ya leimos este parte del archivo
        
        c = dstring_read(string, pos + i + 1);  

      else // Nunca leimos esta parte del archivo, leemos del archivo y guardamos

        c = dstring_add_end(string, file);



  }
  


  // Si coinciden y terminamos de leer la cadena, devolvemos el largo del nodo
  // solamente si es un fin de palabra
  if (c == '\n' && i == length)

    return ctrie_end_of_word(dictionary) ? length : 0;


  // Nos movemos tantas posiciones en la linea, y vemos si podemos continuar
  // recorriendo el arbol
  else if (i == length) {
    
    // Hijo que debemos seguir
    Dictionary child = ctrie_child(dictionary,(int)c - OFFSET); 


    // Nos guardamos la longitud del nodo, si es fin de palabra, si no, es nulo
    int prefix_length = ctrie_end_of_word(dictionary) ? length : 0;

    // Vemos si podemos encontrar algun prefijo, cuando seguimos recorriendo
    // el diccionario
    int prefix_child_length = child ? dictionary_largest_prefix(child, string, pos + i, file) : 0;

    // Si encontramos un prefijo nuevo mas largo, devolvemos dicha distancia,
    // si no, devolvemos el largo del prefijo actual
    return prefix_child_length ? length + prefix_child_length : prefix_length;

  }
  
  // Cualquier otro caso, no se encuentra otro prefijo
  else return 0;
}


void dictionary_iterate(Dictionary dictionary) { ctrie_iterate(dictionary); }


