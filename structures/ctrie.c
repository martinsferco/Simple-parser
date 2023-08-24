#include "ctrie.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



CTrie ctrie_crear() { return NULL; }



static CTrie ctrie_create_node(char* cadena) {

  CTrie new_node = malloc(sizeof(CTrie_Nodo));
  
  int length = strlen(cadena);

  new_node->cadena = malloc(sizeof(char) * (length + 1));
  strcpy(new_node->cadena, cadena);
  new_node->largo_cadena = length;

  new_node->comienzo_cadena = 0;
  new_node->fin_cadena = 0;

  // Initialize all children to NULL
  for (int i = 0 ; i < TAM_ALFABETO ; new_node->hijos[i++] = NULL);

}



CTrie ctrie_agregar_cadena(CTrie ctrie, char* cadena) {

  if (cadena == NULL && ctrie == NULL) return;


  if (ctrie_vacio(ctrie)) { // If the ctrie is empty, add the string normaly 

    return ctrie_create_node(cadena);



  // If the CTrie isn't empty
  int i;

  for (i = 0 ; ctrie->cadena[i] == cadena[i] && cadena[i] != '\0' && i < ctrie->largo_cadena ; i++)

  // CASE 1: The word is smaller and have matched all the chars before
    


  // CASE 2: The word is bigger and have matched all the chars before

  // CASE 3: The word is of the same size, and have matched all the chars before

  // CASE 4: The word fails matching a char 





  }



}


int ctrie_vacio(CTrie ctrie) { return ctrie == NULL; }


void ctrie_destruir(CTrie ctrie) {

  if (! ctrie_vacio(ctrie)) {

    for (int i = 0 ; i < TAM_ALFABETO ; i++)
      
      if (! ctrie_vacio(ctrie->hijos[i])) ctrie_destruir(ctrie->hijos[i]);
      

    if (ctrie->comienzo_cadena) free(ctrie->cadena); // Liberamos cadena  

    free(ctrie); // Liberamos nodo
  }
}



void ctrie_recorrer(CTrie ctrie) {

  if (ctrie_vacio(ctrie)) return;

  printf("%s\n",ctrie->cadena); // Procesamos el nodo

  for (int i = 0 ; i < TAM_ALFABETO ; i++) // Recorremos los hijos
    
    ctrie_recorrer(ctrie->hijos[i]);
}
