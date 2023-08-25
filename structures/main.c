#include "ctrie.h"
#include "stdio.h"
#include "stdlib.h"

int main() {

  CTrie jorge = ctrie_create();

  FILE* archivo = fopen("../dictionaries/small_dictionary.txt","r");

  char buffer[1000];

  for (int i = 0 ; i < 620891 ; i++) {

    fscanf(archivo, "%s",buffer);

    jorge = ctrie_add_string(jorge,buffer);

  }

  fclose(archivo);

  ctrie_iterate(jorge);

  ctrie_destroy(jorge);


  return 0;
}