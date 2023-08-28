#ifndef __DINAMIC_ARRAY_H__
#define __DINAMIC_ARRAY_H__

#define RESIZE_FACTOR 50

typedef void (*DestroyFunction) (void*);
typedef void* (*CopyFunction) (void*);
typedef void (*VisitFunction) (void*);



typedef struct {

  void** elements;
  int capacity;
  int last;

} _DinamicArray;

typedef _DinamicArray* DinamicArray;

DinamicArray dinamic_array_create(int initial_capacity);

void dinamic_array_destroy(DinamicArray array, DestroyFunction destroy);

void* dinamic_array_read(DinamicArray array, int pos, CopyFunction copy);

void dinamic_array_write(DinamicArray array, int pos, void* data, CopyFunction copy, DestroyFunction destroy);

int dinamic_array_capacity(DinamicArray array);

void dinamic_array_extends(DinamicArray array, DestroyFunction destroy);


#endif // __DINAMIC_ARRAY_H__