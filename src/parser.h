#ifndef __PARSER_H__
#define __PARSER_H__


#include "dictionary.h"
#include "../structures/dstring.h"
#include <stdio.h>


typedef struct _ParseFiles ParseFiles; 

typedef struct _ParsedLine ParsedLine ; 

typedef enum _ParseResult ParseResult;  


//! @brief Realiza el parseo de una linea completa del achivo.
//! @param[in] dictionary: Diccionario a partir del cual vamos a parsear.
//! @param[out] line: Donde almacenamos los caracteres leidos y los errores
//!                   encontrados.
//! @param[out] files: Estructura de archivos, uno de donde leemos los 
//!                    caracteres de la linea, y otro donde guardamos los 
//!                    resultados de parseo.
//! @return Resultados del parseo de la linea, dependiendo con que tipo de 
//!         sitaucion nos encontramos. Pueden ser: END_OF_FILE, EMPTY_LINE,
//!         NON_EMPTY_LINE.
ParseResult parse_line(Dictionary dictionary, ParsedLine line, ParseFiles files);


//! @brief Realiza el parseo de un archivo completo, linea por linea, mostrando
//!        tambien los erroes encontrados.
//! @param[in] dictionary: Diccionario a parti del cual vamos a parsear.
//! @param[in] parseFile: Puntero al archivo que vamos a parsea.
//! @param[out] resultsFile: Puntero al archivo en donde vamos a guardar los
//!                          resultados del parseo.
void parse_file(Dictionary dictionary, FILE* parseFile, FILE* resultsFile);


#endif // __PARSER_H__