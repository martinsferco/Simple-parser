#include "../structures/ctrie.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main(int argc, char** argv) {

  // Chequeamos la cantidad de argumentos
  if (argc != 4) {
    printf("Cantidad de argumentos incorrecta... Finalizando programa.");
    return 1;
  }

  // Cargamos diccionario 
  FILE* archivo_diccionario = fopen(argv[1], "r");
  assert(archivo_diccionario);
  
  CTrie diccionario = ctrie_crear();

  // Cerramos archivo de diccionario
  fclose(archivo_diccionario);
  

  FILE* archivo_entrada = fopen(argv[2], "r");
  FILE* archivo_salida = fopen(argv[3], "w");





  // Cerramos los archivos de entrada y salida
  fclose(archivo_entrada);
  fclose(archivo_salida);

  return 0;
}