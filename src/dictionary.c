#include "dictionary.h"


//! @brief Obtiene el caracter i de la linea que esta siendo parseada.
//! @param[out] string: DString donde almacenamos la linea leida.
//! @param[in] index: Indice del caracter que necesitamos.
//! @param[out] parseFile: Archivo de donde estamos parseando la linea.
//! @return El caracter que se encuentra en la posicion i de la linea.
static char get_parse_char(DString string, int index, FILE* parseFile) {

  char c;

  // Ya leimos este parte del archivo y esta cargada en el string
  if (index < dstring_used(string)) 
      
      c = dstring_read(string, index);  

  else // Nunca leimos esta parte del archivo, leemos del archivo y guardamos

      c = dstring_append_from_file(string, parseFile);
  
  return c; // Retornamos el caracter
}



inline Dictionary dictionary_create() { return ctrie_create(); }



Dictionary dictionary_load_from_file(Dictionary dictionary, FILE* file) {

  char buffer[READ_SIZE]; // Donde iremos almacenando las palabras

  while (fscanf(file, "%[^\n]\n", buffer) != EOF) 
    
    dictionary = ctrie_add_string(dictionary, buffer); // Las cargamos

  return dictionary;
}



inline void dictionary_destroy(Dictionary dictionary) { ctrie_destroy(dictionary); }



static int continue_matching(int i, char c, int length, Dictionary dictionary) {

  return c != '\n' && c != EOF && i < length && ctrie_node_char(dictionary, i) == c;
}



int dictionary_largest_prefix(Dictionary dictionary, DString string, int pos, FILE* file) {
  
  
  int i; // Indice que usaremos para recorrer string del nodo del diccionario

  if (dictionary == NULL) return 0;

  int length = ctrie_node_length(dictionary);   
  

  char c = get_parse_char(string, pos, file);
  
  for (i = 0; continue_matching(i, c, length, dictionary) ; i++)
    
    c = get_parse_char(string, pos + i + 1, file);


  // Si coinciden y terminamos de leer la cadena, devolvemos el largo del nodo
  // solamente si es un fin de palabra
  if ((c == '\n' || c == EOF) && i == length)

    return ctrie_end_of_word(dictionary) ? length : 0;


  // Vemos si podemos seguir buscando un prefijo mas largo
  else if (i == length) {
    
    // Hijo que debemos seguir
    Dictionary child = ctrie_child(dictionary, c); 

    // Nos guardamos la longitud del nodo, si es fin de palabra
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