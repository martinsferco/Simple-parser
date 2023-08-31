#ifndef __PARSER_H__
#define __PARSER_H__

#include "dictionary.h"
#include "../structures/queue.h"
#include <stdio.h>

typedef struct _ParseFiles ParseFiles;

typedef struct _ParsedLine ParsedLine ;


int parse_line(Dictionary dictionary, ParsedLine line, ParseFiles files);

void parse_file(Dictionary dictionary, FILE* parse_file, FILE* results_file);


#endif // __PARSER_H__