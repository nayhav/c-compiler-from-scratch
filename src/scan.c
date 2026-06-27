#include "defs.h"
#include "data.h"
#include "decl.h"

// Lexical scanning
//Reads characters from an input source and converts it to a token stream.
static int chrpos(char *s, int c) {
  char *p;

  p = strchr(s, c);
  return (p ? p - s : -1);
}
// Get the next character from the input file.
static int next(void) {
  int c;

  if (putback_char) {		// Use the character put
    c = putback_char;		// back if there is one
    putback_char = 0;
    return c;
  }

  c = fgetc(input_file);		// Read from input file
  if ('\n' == c)
    current_line++;			// Increment line count
  return c;
}

// Put back an unwanted character
static void putback(int c) {
  putback_char = c;
}

// Skip past input that we don't need to deal with, 
// i.e. whitespace, newlines. Return the first
// character we do need to deal with.
static int skip(void) {
  int c;

  c = next();
  while (' ' == c || '\t' == c || '\n' == c || '\r' == c || '\f' == c) {
    c = next();
  }
  return (c);
}

// Scan and return an integer literal
// value from the input file.
static int scanint(int c) {
  int k, val = 0;

  // Convert each character into an int value
  while ((k = chrpos("0123456789", c)) >= 0) {
    val = val * 10 + k;
    c = next();
  }

  // We hit a non-integer character, put it back.
  putback(c);
  return val;
}

// Scan and return the next token found in the input.
// Return 1 if token valid, 0 if no tokens left.
int scan(struct token *token) {
  int c;

  // Skip whitespace
  c = skip();

  // Determine the token based on
  // the input character
  switch (c) {
  case EOF:
    return (0);
  case '+':
    token->token = T_PLUS;
    break;
  case '-':
    token->token = T_MINUS;
    break;
  case '*':
    token->token = T_STAR;
    break;
  case '/':
    token->token = T_SLASH;
    break;
  default:

    // If it's a digit, scan the
    // literal integer value in
    if (isdigit(c)) {
      token->intvalue = scanint(c);
      token->token = T_INTLIT;
      break;
    }

    printf("Unrecognised character %c on line %d\n", c, current_line);
    exit(1);
  }

  // We found a token
  return (1);
}