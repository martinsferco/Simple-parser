#include "dictionary.h"
#include "parser.h"
#include <stdio.h>

int main(int argc, char** argv) {

  // Chequeamos la cantidad de argumentos
  if (argc != 4) {

    printf("Wrong number of arguments... Ending program.\n");
    return 1;
  }


  // Abrimos archivo de diccionario
  FILE* dictionaryFile = fopen(argv[1], "r");
  
  if (dictionaryFile == NULL) { // Chequeamos correcta apertura del archivo

    printf("Erros opening dictionary file... Ending program.\n");
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

  // Chequeamos correcta apertura de los archivos de parseo
  if (fileToParse == NULL || parseResults == NULL) {

    printf("Error opening parse files... Ending program.\n");
    return 1;
  }

  // Parseamos el archivo y guardamos el resultado
  parse_file(dictionary, fileToParse, parseResults);

  // Destruimos el diccionario
  dictionary_destroy(dictionary);

  // Cerramos los archivos de entrada y salida
  fclose(fileToParse);
  fclose(parseResults);

  return 0;
}