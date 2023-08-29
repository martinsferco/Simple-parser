#ifndef __PARSER_H__
#define __PARSER_H__

#include "dictionary.h"


int parse_line(Dictionary dictionary, DinamicString string);

void parse_file(Dictionary dictionary, FILE* file);



#endif // __PARSER_H__