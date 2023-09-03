#include "dstring.h"
#include <stdlib.h>


#define RESIZE_FACTOR 0.5


 struct _DString {

  char* chars; // Datos guardados
  int capacity; // Capacidad total de elementos
  int used; // Cuanto del arreglo esta siendo utilizado

};

//! @brief Extiende la capacidad de un DString.
//! @param[out] string: DString al cual queremos extender su capacidad.
static void dstring_extends(DString string) {
  
  // Cambiamos a la nueva capacidad
  string->capacity = (string->capacity - 1) * (1 + RESIZE_FACTOR); 

  // Realocamos el arreglo de los datos
  string->chars = realloc(string->chars, sizeof(char) * string->capacity + 1);
}


DString dstring_create(int initialCapacity) {

  DString newString = malloc(sizeof(struct _DString));

  // Pedimos uno adicional por el caracter de terminacion
  newString->chars= malloc(sizeof(void*) * (initialCapacity + 1));
  
  newString->capacity = initialCapacity;

  newString->used = 0;

  newString->chars[0] = '\0'; // Colocamos el terminador de cadena

  return newString;
}


void dstring_destroy(DString string) {

  // Liberamos el arreglo de datos
  free(string->chars);

  // Liberamos el string dinamico
  free(string);
}


char dstring_read(DString string, int pos) { return string->chars[pos]; }


void dstring_write(DString string, int pos, char c) {
  
  string->chars[pos] = c;
}


void dstring_save_segment(DString string, int start, int length, FILE* destiny) {

  for (int i = 0 ; i < length ; i++) 

    fprintf(destiny,"%c", string->chars[i + start]);

  fprintf(destiny,"%s"," ");
}


inline int dstring_used(DString string) { return string->used; }


void dstring_append(DString string, char c) {

  // Si queremos agregar, y no tenemos suficiente espacio
  if (string->used == string->capacity) dstring_extends(string);

  // Adicionamos el caracter al final
  dstring_write(string, string->used, c);
  dstring_write(string, string->used + 1, '\0');
  
  string->used++; // Sumamos uno en la cantidad de usados
}


char dstring_append_from_file(DString string, FILE* file) {

  char c = fgetc(file);

  dstring_append(string, c);

  return c;
}


inline void dstring_reset(DString string) { string->used = 0; } 


inline char dstring_last(DString string) { return string->chars[string->used - 1]; }
