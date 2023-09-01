#include "parser.h"

#define INITIAL_READ_SIZE 1000


struct _ParseFiles{

  FILE* parseFile;
  FILE* resultsFile;

};

struct _ParsedLine {

  DString string;
  DString parsingErrors;

};


enum _ParseResult {

  END_OF_FILE,
  EMPTY_LINE,
  NON_EMPTY_LINE

};


static void save_parsing_errors(DString parsingErrors, FILE* resultsFile) {

  fprintf(resultsFile,"%s", "| PARSING ERRORS:");
  dstring_save_all(parsingErrors, resultsFile);
}


ParseResult parse_line(Dictionary dictionary, ParsedLine line, ParseFiles files) {

  // Obtenemos el primer caracter para ver si llegamos a fin de linea
  char c = dstring_append_from_file(line.string, files.parseFile);

  int match = 1;

  char espacio = ' ';

  if (c == EOF) return END_OF_FILE; // Llegamos al final del archivo

  if (c == '\n') return EMPTY_LINE; // No llegamos al final del archivo, pero es linea vacia


  int i = 0;

  while (dstring_read(line.string, i) != '\n' && dstring_read(line.string, i) != EOF && dstring_read(line.string,i) != '\0') { // Recorremos hasta llegar a fin de linea
    
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


static void skip(void* data) { return; }


void parse_file(Dictionary dictionary, FILE* parseFile, FILE* resultsFile) {


  ParsedLine line;
  line.string = dstring_create(INITIAL_READ_SIZE);
  line.parsingErrors = dstring_create(INITIAL_READ_SIZE);

  ParseFiles files;
  files.parseFile = parseFile;
  files.resultsFile = resultsFile;


  ParseResult result = NON_EMPTY_LINE;

  while (result != END_OF_FILE) {
  
    result = parse_line(dictionary, line, files); // Parseamos linea
    
    if (result == EMPTY_LINE) 
      
      fprintf(resultsFile, "%s", "LINEA VACIA\n");

    else if (result == NON_EMPTY_LINE)
    
      save_parsing_errors(line.parsingErrors, files.resultsFile);

    dstring_reset(line.string);  // Reseteamos string dinamico
    dstring_reset(line.parsingErrors);
  }

  dstring_destroy(line.string);
  dstring_destroy(line.parsingErrors);
}



