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
  FILE* dictionaryFile = fopen(argv[1], "r");
  
  if (dictionaryFile == NULL) {

    printf("Error al abrir archivo de diccionario... Finalizando programa.\n");
    return 1;
  }

  // Cargamos el diccionario
  Dictionary dictionary = dictionary_create();
  dictionary = dictionary_load_from_file(dictionary, dictionaryFile);

  // Cerramos archivo de diccionario
  fclose(dictionaryFile);
  
  // Abrimos el archivo de parseo, y el archivo donde guardaremos el parseo
  FILE* fileToParse = fopen(argv[2], "r");
  FILE* parseResults = fopen(argv[3], "w");

  if (fileToParse == NULL || parseResults == NULL) {

    printf("Error al abrir archivos de parseo... Finalizando programa.\n");
    return 1;
  }

  // Parseamos el archivo
  parse_file(dictionary, fileToParse, parseResults);

  // Cerramos los archivos de entrada y salida
  dictionary_destroy(dictionary);
  fclose(fileToParse);
  fclose(parseResults);

  return 0;
}