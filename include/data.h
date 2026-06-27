#ifndef DATA_H
#define DATA_H

#include <stdio.h>

/*
 * Variables shared across compiler modules.
 *
 * The extern_ macro allows these variables to be declared in every source
 * file, while being defined only once in main.c.
 */
#ifndef extern_
#define extern_ extern
#endif

extern_ FILE *input_file;
extern_ int current_line;
extern_ int putback_char;

#endif
