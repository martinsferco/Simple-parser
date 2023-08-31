#include "parser.h"

#define INITIAL_READ_SIZE 500


struct _ParseFiles{

  FILE* parse_file;
  FILE* results_file;

};

struct _ParsedLine {

  DString string;
  Queue parsing_errors;

};




// int parse_line(Dictionary dictionary, ParseFiles files, ParsedLineline)

int parse_line(Dictionary dictionary, ParsedLine line, ParseFiles files) {

  // Obtenemos el primer caracter para ver si llegamos a fin de linea
  char c = dstring_add_end(line.string, files.parse_file);
  
  // TODO Depende del tipo de terminacion, podemos devolver un enum adecuado

  if (c == EOF) return 1; // Llegamos al final del archivo

  if (c == '\n') return 0; // No llegamos al final del archivo, pero es linea vacia


  int i = 0;

  while (dstring_read(line.string, i) != '\n' && dstring_read(line.string, i) != EOF) { // Recorremos hasta llegar a fin de linea
    
    int length = dictionary_largest_prefix(dictionary, line.string, i, files.parse_file);

    if (length) { // Si encontramos un prefijo

     
     
     dstring_save_segment(line.string, i, length, files.results_file);


      i += length;
    }

    // No encontramos prefijo, nos movemos uno para delante
    else {
      
      queue_enqueue(line.parsing_errors, dstring_pointer_index(line.string, i));

      i++;
    }
  }

  return 0; // La linea que parseamos no era la vacia
}



void parse_file(Dictionary dictionary, FILE* parse_file, FILE* results_file) {


  ParsedLine line;
  line.string = dstring_create(INITIAL_READ_SIZE);
  line.parsing_errors = queue_create();

  ParseFiles files;
  files.parse_file = parse_file;
  files.results_file = results_file;



  int finished = 0;

  while (! finished) {
  
    finished = parse_line(dictionary, line, files); // Parseamos linea
    
    queue_dequeue_print(line.parsing_errors);

    dstring_reset(line.string);  // Reseteamos string dinamico
    
    fprintf(files.results_file,"%c",'\n'); // Seperamos parseo de lineas

    // LIBERAMOS ERRORES
  }


  dstring_destroy(line.string);
  //queue_destroy(line.parsing_errors, );

  //glist_destroy(errors);
}



