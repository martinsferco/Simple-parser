#include "dinamic_string.h"
#include <stdlib.h>
#include <stdio.h>


#define RESIZE_FACTOR 0.5




 struct _DinamicString {

  char* chars; // Datos guardados
  int capacity; // Capacidad total de elementos
  int used; // Cuanto del arreglo esta siendo utilizado

};



DinamicString dinamic_string_create(int initial_capacity) {

  // Pedimos uno adicional por el caracter de terminacion
  DinamicString new_string = malloc(sizeof(struct _DinamicString) + 1);

  new_string->chars= malloc(sizeof(void*) * initial_capacity);
  
  new_string->capacity = initial_capacity;

  new_string->used = 0;

  new_string->chars[0] = '\0'; // Colocamos el terminador de cadena

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


int dinamic_string_used(DinamicString string) { return string->used; }



void dinamic_string_extends(DinamicString string) {
  
  // Cambiamos a la nueva capacidad
  string->capacity = (string->capacity - 1) * (1 + RESIZE_FACTOR); 

  // Realocamos el arreglo de los datos
  string->chars = realloc(string->chars, sizeof(char) * string->capacity + 1);
}





char dinamic_string_add_end(DinamicString string, FILE* file) {

  char c = fgetc(file);

  // Si queremos agregar, y no tenemos suficiente espacio
  if (string->used == string->capacity) dinamic_string_extends(string);

  // Adicionamos el caracter al final
  dinamic_string_write(string, string->used, c);
  dinamic_string_write(string, string->used + 1, '\0');
  
  string->used++; // Sumamos uno en la cantidad de usados

  return c;
}




void dinamic_string_reset(DinamicString string) { string->used = 0; } 