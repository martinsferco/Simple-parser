#include "tests.h"
#include "../structures/dstring.h"

// void test_dstring_extends() {} // STATIC

//void test_dstring_create() 


void test_dstring_read() { 

  DString string = dstring_create(100);

  char letters[] = "abcdefghijklmnopqrstuvwxyz";
  
  for (int i = 0 ; i < 26 ; i++) 
    dstring_append(string, letters[i]);

  for (int i = 0 ; i < 26 ; i++) 
    assert(dstring_read(string, i) == letters[i]);

  dstring_destroy(string);
}


void test_dstring_save_segment() {} // HACER


void test_dstring_used() {

  DString string = dstring_create(50);
  
  for (int i = 0 ; i < 100 ; i++) {

    dstring_append(string, 'a');
    assert(dstring_used(string) == i + 1);
  }

  dstring_destroy(string);
}


void test_dstring_append() {

  DString string = dstring_create(100);

  char letters[] = "abcdefghijklmnopqrstuvwxyz";
  
  for (int i = 0 ; i < 100 ; i++) {

    dstring_append(string, letters[i]);
    assert(dstring_read(string, dstring_used(string) - 1) == letters[i]);
  }

  dstring_destroy(string);
  
}


void test_dstring_reset() {


  DString string = dstring_create(100);

  char letters[] = "abcdefghijklmnopqrstuvwxyz";
  
  for (int i = 0 ; i < 26 ; i++) 
    dstring_append(string, letters[i]);

  assert(dstring_used(string));
  dstring_reset(string);
  assert(! dstring_used(string));

  dstring_destroy(string);
}
