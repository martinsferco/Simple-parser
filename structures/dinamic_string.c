#include "dinamic_string.h"
#include <stdlib.h>
#include <stdio.h>


#define RESIZE_FACTOR 0.5




 struct _DinamicString {

  char* chars; // Datos guardados
  int capacity; // Capacidad total de elementos

};



DinamicString dinamic_string_create(int initial_capacity) {

  // Pedimos uno adicional por el cara
  DinamicString new_string = malloc(sizeof(struct _DinamicString) + 1);

  new_string->chars= malloc(sizeof(void*) * initial_capacity);
  
  new_string->capacity = initial_capacity;

  return new_string;
}


void dinamic_string_destroy(DinamicString string) {

  // Liberamos el arreglo de datos
  free(string->chars);

  // Liberamos el string dinamico
  free(string);
}


// Consideramos que la posicion es correcta
char dinamic_string_read(DinamicString string, int pos) { 
  
  return string->chars[pos];
}



// Consideramos que la posicion es correcta
void dinamic_string_write(DinamicString string, int pos, char c) {
  
  string->chars[pos] = c;
}



void dinamic_string_print_segment(DinamicString string, int start, int length) {

  for (int i = 0 ; i < length ; i++) 

    printf("%c", string->chars[i + start]);

  printf(" ");
}




int dinamic_string_capacity(DinamicString string) { return string->capacity; }




void dinamic_array_extends(DinamicString string) {
  
  // Marcamos nueva capacidad, considerando el espacio para el terminador
  string->capacity = (string->capacity - 1) * (1 + RESIZE_FACTOR) + 1; 

  // Realocamos el arreglo de los datos
  string->chars = realloc(string->chars, sizeof(char) * string->capacity);
}




int dinamic_string_load_line(DinamicString string, FILE* file) {

  char c = fgetc(file);

  if (c == EOF) return 1; // Era una cadena vacia, terminamos de leer el archivo

  int line_length = 0;

  while (c != '\n') { // Mientras no hayamos llegado a fin de linea

    dinamic_string_write(string, line_length, c); // Cargamos el caracter

    c = fgetc(file);

    line_length++;

    // En caso de que lo llenemos, lo extendemos
    if (line_length == dinamic_string_capacity(string)) 
      
      dinamic_array_extends(string);
  }

  // Agregamos el terminador de cadena
  dinamic_string_write(string, line_length, '\0');

  return 0; // Cargamos la cadena dentro del string dinamico
}