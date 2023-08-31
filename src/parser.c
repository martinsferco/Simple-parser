#include "parser.h"
#include <stdio.h>

#define INITIAL_READ_SIZE 500



int parse_line(Dictionary dictionary, DinamicString string, FILE* file) {

  // Obtenemos el primer caracter para ver si llegamos a fin de linea
  char c = dinamic_string_add_end(string, file);
  
  // TODO Depende del tipo de terminacion, podemos devolver un enum adecuado

  if (c == EOF) return 1; // Llegamos al final del archivo

  if (c == '\n') return 0; // No llegamos al final del archivo, pero es linea vacia


  int i = 0;

  while (dinamic_string_read(string, i) != '\n') { // Recorremos hasta llegar a fin de linea
    
    int length = dictionary_largest_prefix(dictionary, string, i, file);

    if (length) { // Si encontramos un prefijo

     dinamic_string_print_segment(string, i, length);
      
      i += length;
    }

    // No encontramos prefijo, nos movemos uno para delante
    else {
      
      // parsing_errors = queue_enqueue(parsing_errors,string[i],id);  
      i++;
    } // TODO GUARDAR EN UNA GLIST LOS CARACTERES QUE FALLARON
  }

  return 0; // La linea que parseamos no era la vacia
}


































void parse_file(Dictionary dictionary, FILE* file) {

  // String dinamico donde iremos almacenando la linea leida
  DinamicString string = dinamic_string_create(INITIAL_READ_SIZE);

  // GList errors = glist_create();

  int finished = 0;

  while (! finished) {
  
    finished = parse_line(dictionary, string, file); // Parseamos linea
    
    // IMPRIMIMOS ERRORES

    dinamic_string_reset(string);  // Reseteamos string dinamico
    
    //printf("\n"); // Seperamos parseo de lineas

    // LIBERAMOS ERRORES
  }

  dinamic_string_destroy(string);
  //glist_destroy(errors);
}



