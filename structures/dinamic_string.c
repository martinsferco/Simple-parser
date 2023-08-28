#include "dinamic_string.h"
#include <stdlib.h>

#define RESIZE_FACTOR 50

DinamicString dinamic_string_create(int initial_capacity) {

  DinamicString new_string = malloc(sizeof(_DinamicString));

  new_string->chars= malloc(sizeof(void*) * initial_capacity);
  
  new_string->capacity = initial_capacity;

  new_string->used = 0;

  return new_string;
}


void dinamic_string_destroy(DinamicString string) {

  // Liberamos el arreglo de datos
  free(string->chars);

  // Liberamos el string dinamico
  free(string);
}

// Consideramos que la posicion es correcta
void* dinamic_string_read(DinamicString string, int pos) { 
  
  return string->chars[pos];
}


// Consideramos que la posicion es correcta
void dinamic_string_write(DinamicString string, int pos, char c) {
  
  string->chars[pos] = c;
}


int dinamic_string_capacity(DinamicString string) { return string->capacity; }


int dinamic_string_used(DinamicString string) { return string->used; }


void dinamic_array_extends(DinamicString string) {
  
  // Marcamos nueva capacidad
  string->capacity = string->capacity * (1 + RESIZE_FACTOR / 100); 

  // Realocamos el arreglo de los datos
  string->chars = realloc(string->chars, sizeof(char) * string->capacity);
}

