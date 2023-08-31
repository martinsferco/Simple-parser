#include "parser.h"

#define INITIAL_READ_SIZE 500


typedef struct {

  FILE* parse_file;
  FILE* results_file;

} ParsingFiles;

typedef struct {

  DString string;
  Queue parsing_errors;

} ParsingLine;


// int parse_line(Dictionary dictionary, ParsingFiles files, ParsingLine line)

int parse_line(Dictionary dictionary, DString string, FILE* file, Queue errors) {

  // Obtenemos el primer caracter para ver si llegamos a fin de linea
  char c = dstring_add_end(string, file);
  
  // TODO Depende del tipo de terminacion, podemos devolver un enum adecuado

  if (c == EOF) return 1; // Llegamos al final del archivo

  if (c == '\n') return 0; // No llegamos al final del archivo, pero es linea vacia


  int i = 0;

  while (dstring_read(string, i) != '\n' && dstring_read(string, i) != EOF) { // Recorremos hasta llegar a fin de linea
    
    int length = dictionary_largest_prefix(dictionary, string, i, file);

    if (length) { // Si encontramos un prefijo

     dstring_print_segment(string, i, length);
      
      i += length;
    }

    // No encontramos prefijo, nos movemos uno para delante
    else {
      
      //queue_enqueue(errors, )
      i++;
    } // TODO GUARDAR EN UNA GLIST LOS CARACTERES QUE FALLARON
  }

  return 0; // La linea que parseamos no era la vacia
}



void parse_file(Dictionary dictionary, FILE* file) {

  // String dinamico donde iremos almacenando la linea leida
  DString string = dstring_create(INITIAL_READ_SIZE);

  Queue errors = queue_create();

  int finished = 0;

  while (! finished) {
  
    finished = parse_line(dictionary, string, file, errors); // Parseamos linea
    
    // IMPRIMIMOS ERRORES queue_print

    dstring_reset(string);  // Reseteamos string dinamico
    
    printf("\n"); // Seperamos parseo de lineas

    // LIBERAMOS ERRORES
  }

  dstring_destroy(string);
  //glist_destroy(errors);
}



