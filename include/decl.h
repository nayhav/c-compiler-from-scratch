#ifndef DECL_H
#define DECL_H

#include "defs.h"

/*
 * Function declarations shared across compiler modules.
 */

/* Reads the next token from the input stream.
 * Returns 1 if a token was read successfully,
 * or 0 if the end of the input has been reached.
 */
int scan(struct token *token);

#endif