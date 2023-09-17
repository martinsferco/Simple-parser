#include "ctrie.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>



#define ALPHABET_SIZE 26 // Definimos el tamanio del alfabeto
#define OFFSET (int)('a') // Definimos el valor ASCII del caracter 'a'



struct CTrieNode { // Estructura de un nodo del CTrie

  char* string;  // Inicio de la cadena almacenada

  int length; // Largo de la cadena almacenada

  unsigned int endOfWord; // Vemos si llegamos hasta un fin de cadena

  unsigned int startMemoryBlock; // Vemos si en el nodo, 'string' apunta al 
                                 // comienzo de un bloque de memoria 

  struct CTrieNode** children; // Hijos del nodo
};



typedef enum { // Definimos las opciones de copiado, al crear un nuevo nodo

  PHYSIC_COPY,
  POINTER_COPY,

} CopyOption;



//! @brief Copia un string en otro lugar de memoria, haciendo minusculas todos 
//!        sus caracteres.
//! @param[out] destiny: Direccion donde guardaremos la copia del string.
//! @param[in] origin: Direccion desde donde copiaremos el string.
static void lower_case_strcpy(char* destiny, char* origin) {

  if (destiny == NULL || origin == NULL) return;

  for (int i = 0 ; origin[i] != '\0' ; i++)
    destiny[i] = tolower(origin[i]);
} 



//! @brief Crea un nuevo nodo que insertaremos al CTrie.
//! @param[in] string: Apunta al comienzo del string que ira en el nuevo nodo.
//! @param[in] length: Largo de la cadena del nuevo nodo.
//! @param[in] option: PHYSIC_COPY: Pedimos memoria y copiamos el string.
//!                    POINTER_COPY: Guardamos la direccion del string pasado.
//! @return El nuevo nodo inicializado con el string y largo, con todos los 
//!         hijos vacios. 
static CTrie ctrie_create_node(char* string, int length, CopyOption option) { 

  CTrie newNode = malloc(sizeof(struct CTrieNode));

  // Seteamos variables del bloque
  newNode->startMemoryBlock = (option == PHYSIC_COPY);
  newNode->endOfWord = 1; 

  newNode->length = length;

  if (option == POINTER_COPY) newNode->string = string; // Solo guardamos puntero

  else { // Copiamos el string
    
    newNode->string = malloc(sizeof(char) * (length + 1));
    lower_case_strcpy(newNode->string, string); // Guardamos el string en minusculas
  }
  
  // Pedimos memoria para todos los hijos
  newNode->children = malloc(sizeof(CTrie) * ALPHABET_SIZE);

  // Inicializamos todos sus hijos a NULL
  for (int i = 0 ; i < ALPHABET_SIZE; newNode->children[i++] = ctrie_create());

  return newNode;
}



//! @brief Dados dos CTries, intercambia los hijos de uno por los hijos del otro
//         y visceversa.
//! @param[out] ctrie1: CTrie que recibira los hijos de ctri2.
//! @param[out] ctrie2: CTrie que recibira los hijos de ctri1.
static void ctrie_exchange_children(CTrie ctrie1, CTrie ctrie2) {

  CTrie* children = ctrie1->children;
  ctrie1->children = ctrie2->children;
  ctrie2->children = children;
}



//! @brief Divide un nodo en dos partes, colocando la segunda parte como hijo
//!        de la primera.
//! @param[out] ctrie: CTrie del cual queremos hacer la extension.
//! @param[in] index: Indice a partir del cual vamos a hacer la division.
//! @return El mismo nodo, pero con menor largo de palabra y tiene como hijo
//!         a otro nodo, con la otra parte de la palabra.
static CTrie ctrie_split_node(CTrie ctrie, int index) {

  // Creamos el nodo que sera la extension del nodo actual
  CTrie newNode = ctrie_create_node(ctrie->string + index, ctrie->length - index,
                                                            POINTER_COPY); 
  
  ctrie->length = index; // Actualizamos largo string

  newNode->endOfWord = ctrie->endOfWord; // Sera fin de palabra si la 
                                         // el string original lo era 
  
  ctrie->endOfWord = 1; // El nodo actual pasa a ser un fin de palabra


  ctrie_exchange_children(newNode, ctrie); // Intercambiamos hijos
  

  // Ponems como hijo del nodo actual, a la extension que creamos
  ctrie->children[(int)ctrie->string[index] - OFFSET] = newNode; 

  return ctrie;
}



//! @brief Realiza una bifurcacion a partir de un indice y un nuevo string.
//! @param[out] ctrie: CTrie en donde realizaremos la bifurcacion.
//! @param[in] string: String que sera parte de uno de los nodos de la
//!                    bifurcaion.
//! @param[in] index: Indice a partir del cual realizarmos la bifurcacion.
//! @return El mismo nodo, pero con menor largo de palabra, y tiene como nuevos 
//!         hijos a un nodo con la segunda parte de su string y todos sus hijos,
//!         y otro que tiene al string pasado como argumento.
static CTrie ctrie_create_bifurcation(CTrie ctrie, char* string, int index) {

  // Creamos el nodo en donde guardaremos la otra parte del string del nodo, 
  // que no coincidio con el string a insertar.
  CTrie stringPartitionNode = ctrie_create_node(ctrie->string + index,
                                                  ctrie->length - index,
                                                  POINTER_COPY);

  // Solo es fin de palabra si el nodo a bifurcar lo era
  stringPartitionNode->endOfWord = ctrie->endOfWord; 

  ctrie->endOfWord = 0; // AL haberse particionado, no es mas fin de palabra
  
  ctrie->length = index; // Actualizamos largo string


  // Los hijos del nodo resultante de la bifuracion del nodo actual, seran los
  // hijos del nodo actual. 
  ctrie_exchange_children(stringPartitionNode, ctrie);

  // Creamos el nodo donde almacenaremos la parte del string a insertar, que no 
  // coincidio con el string del nodo
  CTrie newStringNode = ctrie_create_node(string + index, strlen(string) - index,
                                          PHYSIC_COPY); 


  // A los dos nuevos nodos, los agregamos como hijos del nodo actual
  ctrie->children[(int)ctrie->string[index] - OFFSET] = stringPartitionNode;
  ctrie->children[tolower(string[index]) - OFFSET] = newStringNode;

  return ctrie;
}


//! @brief Determina si seguimos comparando los caracteres del string con los
//!        del string del nodo.
//! @param[in] ctrie: Nodo del CTrie que estamos comparando con el string.
//! @param[in] string: String que estamos comparando con el string del nodo.
//! @param[in] i: Indice que estamos comparando.
//! @return 1 si podemos seguir avanzando, 0 si no.
static int matching(CTrie ctrie, char* string, int i) {
  
  return i < ctrie->length && ctrie->string[i] == tolower(string[i]) &&
         string[i] != '\0';
}



inline CTrie ctrie_create() { return NULL; }



inline int ctrie_empty(CTrie ctrie) { return ctrie == NULL; }



CTrie ctrie_add_string(CTrie ctrie, char* string) {

  if (string == NULL) return ctrie; 

  // Si el CTrie esta vacio, agregamos toda la cadena a un nuevo nodo
  if (ctrie_empty(ctrie))  

    return ctrie_create_node(string, strlen(string), PHYSIC_COPY);


  // Si el CTrie no esta vacio, tenemos que recorrer el string del nodo
  int i;

  // Recorremos hasta que no matcheen o lleguemos al final de alguna cadena
  for (i = 0 ; matching(ctrie, string, i) ; i++);


  // CASO 1: La palabra y el string del nodo coinciden en largo y caracteres
  if (string[i] == '\0' && i == ctrie->length)

    ctrie->endOfWord = 1; // Pasa a ser fin de palabra


  // CASO 2: La palabra es mas chica que el string del nodo y coincidio en todo 
  else if (string[i] == '\0') 
    
    ctrie = ctrie_split_node(ctrie, i); // Dividimos el nodo


  // CASO 3: La palabra es mas larga que el string del nodo y coincidio en todo 
  else if (i == ctrie->length) {

    char c = tolower(string[i]);

    // Inseramos el resto del string, en el subarbol asociado al caracter
    // que estamos leyendo del string.
    CTrie newChild =  ctrie_add_string(ctrie_child(ctrie, c), string + i);

    ctrie->children[(int)c - OFFSET] = newChild;
  }

  // CASO 4: La palabra no coincide en algun caracter con el string del nodo 
  else if (ctrie->string[i] != tolower(string[i])) 
    
    ctrie = ctrie_create_bifurcation(ctrie, string, i); // Bifurcamos el nodo
    

  return ctrie;
}



int ctrie_search_string(CTrie ctrie, char* string) { 

  if (ctrie == NULL) return 0;

  int i;

  for (i = 0 ; matching(ctrie, string, i) ; i++);

  // Si coinciden, solo se encuentra en el ctrie si el nodo tiene fin de palabra
  if (string[i] == '\0' && i == ctrie->length) return ctrie->endOfWord;

  // Seguimos buscando el otro pedazo del string en los hijos del CTrie
  else if (i == ctrie->length) { 
    
    CTrie child = ctrie->children[(int)tolower(string[i]) - OFFSET];

    return ctrie_search_string(child, string + i);
  }

  // Cualquier otro caso, no se encuentra la palabra
  else return 0;
}



void ctrie_iterate(CTrie ctrie) {

  if (ctrie_empty(ctrie)) return;
  
  printf("------------------\n");
  
  for (int i = 0 ; i < ctrie->length ; i++) // Imprimimos los caracteres del string
    
    printf("%c",ctrie->string[i]);
  
  printf("\n");

  // Imprimimos informacion relacionada con el bloque
  printf("Comienzo bloque memoria: %d\n", ctrie->startMemoryBlock);
  printf("Fin de palabra: %d\n", ctrie->endOfWord);
  
  printf("------------------\n");

  for (int i = 0 ; i < ALPHABET_SIZE ; i++) // Visitamos los hijos

    ctrie_iterate(ctrie->children[i]);
}



inline int ctrie_node_length(CTrie ctrie) { return ctrie->length; }



inline char ctrie_node_char(CTrie ctrie, int pos) { return ctrie->string[pos];}



inline int ctrie_end_of_word(CTrie ctrie) { return ctrie->endOfWord; }



inline CTrie ctrie_child(CTrie ctrie, char c) { return ctrie->children[(int)c - OFFSET];}



void ctrie_destroy(CTrie ctrie) {

  if (! ctrie_empty(ctrie)) {

    for (int i = 0 ; i < ALPHABET_SIZE ; i++)
      
      // Liberamos cada uno de los hijos
      if (! ctrie_empty(ctrie->children[i])) ctrie_destroy(ctrie->children[i]);
      
    // Liberamos el arreglo de hijos
    free(ctrie->children);

    // Liberamos la cadena, solo si estamos en el comienzo del bloque de memoria
    if (ctrie->startMemoryBlock) free(ctrie->string);   

    // Liberamos el nodo
    free(ctrie);
  }
}