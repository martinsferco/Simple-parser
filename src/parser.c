#include "parser.h"


#define INITIAL_SIZE 1000 // Capacidad inicial de un DString. 


struct _ParseFiles{ 

  FILE* parseFile;
  FILE* resultsFile;

};

// Estructura que almacena la linea leida del archivo, y los errores del parseo.
struct _ParsedLine {

  DString string;
  DString parsingErrors;

}; 

// Enumeracion de las posibles situaciones al parsear una linea.
enum _ParseResult {

  END_OF_FILE,
  EMPTY_LINE,
  NON_EMPTY_LINE

};


//! @brief Se encarga de guardar en un archivo los errores de parseo.
//! @param[in] parsingErrors: DString que almaceno los errores resultantes del 
//!                           parseo de una linea.
//! @param[out] resultsFile: Puntero al archivo donde guardamos los errores.
static void save_parsing_errors(DString parsingErrors, FILE* resultsFile) {

  if (dstring_used(parsingErrors) == 0)
    
    fprintf(resultsFile,"%s", "| NO PARSING ERRORS\n");

  else {
  fprintf(resultsFile,"%s", "| PARSING ERRORS:");
  dstring_save_segment(parsingErrors, 0, dstring_used(parsingErrors), resultsFile);
  fprintf(resultsFile,"%c", '\n');
  }
}


ParseResult parse_line(Dictionary dictionary, ParsedLine line, ParseFiles files) {

  // Obtenemos el primer caracter para ver si llegamos a fin de linea
  char c = dstring_append_from_file(line.string, files.parseFile);

  if (c == EOF) return END_OF_FILE; // Llegamos al final del archivo

  if (c == '\n') return EMPTY_LINE; // No llegamos al final del archivo, pero es linea vacia

  int match = 1;

  int i = 0;

  while (dstring_read(line.string, i) != '\n' && dstring_read(line.string, i) != EOF && dstring_read(line.string,i) != '\0') { // Recorremos hasta llegar a fin de linea
    
    if (dstring_last(line.string) != '\n')
      
      dstring_append_from_file(line.string, files.parseFile);
    

    int length = dictionary_largest_prefix(dictionary, line.string, i, files.parseFile);

    if (length) { // Si encontramos un prefijo

      dstring_save_segment(line.string, i, length, files.resultsFile);
      
      i += length;
      
      match = 1;
    }
    
    else { // No encontramos prefijo, nos movemos uno para delante
        
      if (match) dstring_append(line.parsingErrors, ' ');

      dstring_append(line.parsingErrors, dstring_read(line.string, i));      
      i++;
      match = 0;
    }
  }

  return NON_EMPTY_LINE; // La linea que parseamos no era la vacia
}


void parse_file(Dictionary dictionary, FILE* parseFile, FILE* resultsFile) {


  ParsedLine line;
  line.string = dstring_create(INITIAL_SIZE);
  line.parsingErrors = dstring_create(INITIAL_SIZE);

  ParseFiles files;
  files.parseFile = parseFile;
  files.resultsFile = resultsFile;


  ParseResult result = NON_EMPTY_LINE;

  while (result != END_OF_FILE) {
  
    result = parse_line(dictionary, line, files); // Parseamos linea
    
    if (result == EMPTY_LINE) 
      
      fprintf(resultsFile, "%s", "EMPTY LINE\n");

    else if (result == NON_EMPTY_LINE)
    
      save_parsing_errors(line.parsingErrors, files.resultsFile);


    dstring_reset(line.string);  
    dstring_reset(line.parsingErrors);
  }

  dstring_destroy(line.string);
  dstring_destroy(line.parsingErrors);
}



