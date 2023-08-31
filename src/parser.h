#ifndef __PARSER_H__
#define __PARSER_H__

#include "dictionary.h"
#include "../structures/queue.h"
#include <stdio.h>


int parse_line(Dictionary dictionary, DString string, FILE* file, Queue errors);

void parse_file(Dictionary dictionary, FILE* file);


#endif // __PARSER_H__