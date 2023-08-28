#include "dinamic_array.h"
#include <stdlib.h>


DinamicArray dinamic_array_create(int initial_capacity) {

  DinamicArray new_array = malloc(sizeof(_DinamicArray));

  new_array->elements = malloc(sizeof(void*) * initial_capacity);
  
  new_array->capacity = initial_capacity;

  new_array->last = 0;

  return new_array;
}


void dinamic_array_destroy(DinamicArray array, DestroyFunction destroy) {

  // Liberamos primero los datos
  for (int i = 0 ; i < array->last ; i++)
    
    destroy(array->elements[i]);

  // Liberamos el arreglo de datos
  free(array->elements);

  // Liberamos el arreglo dinamico
  free(array);
}

// Consideramos que la posicion es correcta
void* dinamic_array_read(DinamicArray array, int pos, CopyFunction copy) {

  return copy(array->elements[pos]);


}


// Consideramos que la posicion es correcta
void dinamic_array_write(DinamicArray array, int pos, void* data, 
                          CopyFunction copy,
                          DestroyFunction DestroyFunction) {

  // Liberamos el dato anterior
  free(array->elements[pos]);

  // Cargamos el nuevo dato
  array->elements[pos] = copy(data);
}


int dinamic_array_capacity(DinamicArray array) { return array->capacity; }



void dinamic_array_extends(DinamicArray array, DestroyFunction destroy) {
  
  // Marcamos nueva capacidad
  array->capacity = array->capacity * (1 + RESIZE_FACTOR / 100); 

  // Realocamos el arreglo de los datos
  array->elements = realloc(array->elements, sizeof(void*) * array->capacity);
}

