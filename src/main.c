#include "dictionary.h"
#include "parser.h"
#include <stdio.h>

int main(int argc, char** argv) {

  // Chequeamos la cantidad de argumentos
  if (argc != 4) {
    printf("Cantidad de argumentos incorrecta... Finalizando programa.\n");
    return 1;
  }

  // Abrimos archivo de diccionario
  FILE* dictionary_file = fopen(argv[1], "r");
  
  // Cargamos el diccionario
  Dictionary dictionary = dictionary_create();
  dictionary = dictionary_load_from_file(dictionary, dictionary_file);

  // Cerramos archivo de diccionario
  fclose(dictionary_file);
  
  // Abrimos el archivo de parseo, y el archivo donde guardaremos el parseo
  FILE* file_to_parse = fopen(argv[2], "r");
  FILE* parse_results = fopen(argv[3], "w");


  // Parseamos el archivo
  parse_file(dictionary, file_to_parse, parse_results);


  // Cerramos los archivos de entrada y salida
  dictionary_destroy(dictionary);
  fclose(file_to_parse);
  fclose(parse_results);

  return 0;
}