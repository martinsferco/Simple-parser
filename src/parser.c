#include "parser.h"



int parse_line(Dictionary dictionary, FILE* file) {

  char c = fgetc(file); // Obtenemos un caracter para ver si llegamos a fin de linea

  while (c != '\n' && c != EOF) {
    
    fseek(file, -1, SEEK_CUR); // Nos movemos uno para atras por la lectura de fgetc

    long start_position = ftell(file);

    int length = dictionary_largest_prefix(dictionary, file);

    fseek(file, start_position, SEEK_SET);

    if (length) { // Si encontramos un prefijo

      char buffer[READ_SIZE];

      fgets(buffer, length + 1, file);

     // printf("%s ", buffer);

    }

    else { // No encontramos prefijo, nos movemos uno para delante

      fseek(file, 1, SEEK_CUR);

    }

    c = fgetc(file);
  }

  //printf("\n");

  return c != EOF;

}

void parse_file(Dictionary dictionary, FILE* file) {

  int continue_parsing;

  do {

    continue_parsing = parse_line(dictionary, file);

  } while (continue_parsing);
}



