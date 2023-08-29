#include "parser.h"

#define INITIAL_READ_SIZE 1000

int parse_line(Dictionary dictionary, DinamicString string) {

  // Obtenemos un caracter para ver si llegamos a fin de linea
  char c = dinamic_string_read(string, 0);
  if (c == '\0') return 1;

  int i = 0;

  while (dinamic_string_read(string, i) != '\0') {
    
    //long start_position = ftell(file);

    int length = dictionary_largest_prefix(dictionary, string, i);


    if (length) { // Si encontramos un prefijo

      dinamic_string_print_segment(string, i, length);
      i += length;
    }

    // No encontramos prefijo, nos movemos uno para delante
    else i++;
  }

  return 0; // La linea que parseamos no era la vacia
}

void parse_file(Dictionary dictionary, FILE* file) {

  DinamicString string = dinamic_string_create(INITIAL_READ_SIZE);

  int finish = dinamic_string_load_line(string, file);

  while (! finish) {

    parse_line(dictionary, string);
    
    finish = dinamic_string_load_line(string, file);

    printf("\n");

  }

  dinamic_string_destroy(string);
}


