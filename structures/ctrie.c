#include "ctrie.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



CTrie ctrie_crear() { return NULL; }



static CTrie ctrie_create_node(char* cadena, int largo) { // Agregar un argumento para ver si copiamos o solamente dejamos el puntero

  CTrie new_node = malloc(sizeof(CTrie_Nodo));
  
  int length = largo;

  new_node->cadena = malloc(sizeof(char) * (length + 1));
  
  strcpy(new_node->cadena, cadena); // Modificar strcpy con algo que copia a mano
  
  new_node->largo_cadena = length;

  new_node->comienzo_cadena = 0;
  new_node->fin_cadena = 1;

  // Initialize all children to NULL
  new_node->hijos = malloc(sizeof(CTrie) * TAM_ALFABETO);

  for (int i = 0 ; i < TAM_ALFABETO ; new_node->hijos[i++] = NULL);

  return new_node;
}



CTrie ctrie_agregar_cadena(CTrie ctrie, char* cadena) {

  if (cadena == NULL) return ctrie;


  if (ctrie_vacio(ctrie))  // If the ctrie is empty, add the string normaly 

    return ctrie_create_node(cadena, strlen(cadena));



  // If the CTrie isn't empty
  int i;

  // Recorremos hasta que no matcheen o lleguemos al final de alguna cadena
  for (i = 0 ; ctrie->cadena[i] == cadena[i] && cadena[i] != '\0' && i < ctrie->largo_cadena ; i++);

  // CASE 1: The word is of the same size, and have matched all the chars before
  if (cadena[i] == '\0' && i == ctrie->largo_cadena) {

    if (! ctrie->fin_cadena) ctrie->fin_cadena = 1;

    return ctrie;
  }
  
  
  
  // CASE 2: The word is smaller and have matched all the chars before
  if (cadena[i] == '\0') {

    CTrie new_node = ctrie_create_node(ctrie->cadena + i, ctrie->largo_cadena - i);
    ctrie->largo_cadena = i; // Actualizamos largo cadena

    new_node->fin_cadena = 1;
    

    CTrie* change = new_node->hijos;
    new_node->hijos = ctrie->hijos;
    ctrie->hijos = change;



    ctrie->hijos[(int)(ctrie->cadena[i]) - OFFSET] = new_node; // Agregar opcion de copiar, o no copiar
    
    return ctrie;
  }

  // CASE 3: The word is bigger and have matched all the chars before
  if (i == ctrie->largo_cadena) {

    CTrie new_child =  ctrie_agregar_cadena(ctrie->hijos[(int)cadena[i] - OFFSET], cadena + i);

    ctrie->hijos[(int)cadena[i] - 97] = new_child;

    return ctrie;
  }

  // CASE 4: The word fails matching a char 
  if (ctrie->cadena[i] != cadena[i]) {
    
    CTrie nuevo_nodo1 = ctrie_create_node(ctrie->cadena + i, ctrie->largo_cadena - i);

    ctrie->largo_cadena = i;

    CTrie* change = ctrie->hijos;

    ctrie->hijos = nuevo_nodo1->hijos;

    nuevo_nodo1->hijos = change;

    ctrie->hijos[(int)ctrie->cadena[i] - OFFSET] = nuevo_nodo1;

    CTrie nuevo_nodo2 = ctrie_create_node(cadena + i, strlen(cadena) - i);

    ctrie->hijos[cadena[i] - OFFSET] = nuevo_nodo2;

    return ctrie;
  }







  
  return ctrie;

}


int ctrie_vacio(CTrie ctrie) { return ctrie == NULL; }


void ctrie_destruir(CTrie ctrie) {

  if (! ctrie_vacio(ctrie)) {

    for (int i = 0 ; i < TAM_ALFABETO ; i++)
      
      if (! ctrie_vacio(ctrie->hijos[i])) ctrie_destruir(ctrie->hijos[i]);
      
    free(ctrie->hijos);


    if (ctrie->comienzo_cadena) free(ctrie->cadena); // Liberamos cadena  



    free(ctrie); // Liberamos nodo

  }
}



void ctrie_recorrer(CTrie ctrie) {

  if (ctrie_vacio(ctrie)) return;


  printf("%d\n",ctrie->largo_cadena);
  for (int i = 0 ; i < ctrie->largo_cadena ; i++)
    printf("%c",ctrie->cadena[i]);

  printf("\n");

  for (int i = 0 ; i < TAM_ALFABETO ; i++) // Recorremos los hijos
    
    ctrie_recorrer(ctrie->hijos[i]);
}
