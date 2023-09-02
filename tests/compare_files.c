#include "compare_files.h"



int compare_files(FILE* file1, FILE* file2) {

  char c1;
  char c2;

  int equal = 1;

  do {

    c1 = fgetc(file1);
    c2 = fgetc(file2);

    if (c1 != c2) equal = 0;

  } while (c1 != EOF && c2 != EOF && equal);

  return c1 == EOF && c2 == EOF && equal;
}