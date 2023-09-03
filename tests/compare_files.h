#ifndef __COMPARE_FILES_H__
#define __COMPARE_FILES_H__

#include <stdio.h>

//! @brief Compara el contenido de dos archivos para ver si son iguales.
//! @param[in] file1: Archivo 1 que queremos comparar.
//! @param[in] file2: Archivo 2 que queremos comparar.
//! @return 1 si son iguales de contenido, 0 si no.
int compare_files(FILE* file1, FILE* file2);

#endif // __COMPARE_FILES_H__