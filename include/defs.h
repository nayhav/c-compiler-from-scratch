#ifndef DEFS_H
#define DEFS_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Token types recognized by the lexical scanner.
 */
enum TokenType {
    T_PLUS,
    T_MINUS,
    T_STAR,
    T_SLASH,
    T_INTLIT
};

/*
 * Represents a single token produced by the scanner.
 *
 * token    : identifies the type of token
 * intvalue : stores the numeric value for integer literals
 */
struct token {
    int token;
    int intvalue;
};

#endif