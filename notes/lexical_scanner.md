The assignment is to identify the lexical tokens and write a simple lexical scanner. The source code is fed to the scanner, and the output is a simple token stream. That's it.

We store every token in the token structure of defs.h, which is a pretty simple struct token {..} declaration. Each token has a value among the digits from 0-9, if it's an integer. Otherwise, just a token.

T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INTLIT are enumerated as per defs.h.

The scan.c file holds the functions of our lexical scanner. We are going to read in one character at a time from our input file. However, there will be times when we need to "put back" a character if we have read too far ahead in the input stream. We also want to track what line we are currently on so that we can print the line number in our debug messages. All of this is done by the next() function.
The putback_char and current_line variables are defined in data.h along with our input file pointer. Finally we put a char back into the input stream.

We need a function that reads and silently skips whitespace characters until it gets a non-whitespace character, and returns it.
So now we can read characters in while skipping whitespace; we can also put back a character if we read one character too far ahead. Cool.

We will need to recognise multi-character tokens such as == and keywords like if and while, so I won't just turn a recognized character into a token. A numbered list is better.

Handling the int values etc by scanning each legit digit and adding the final number(most brainy part of this exercise to me)


Putting the main() puts the scanner to work.


And it works for input01.txt! File contents:

2 + 3 * 5 - 8 / 3

The output is:
Admin@DESKTOP-11I48FD UCRT64 /d/c-compiler-from-scratch
$ ./scanner input01.txt
Token intlit, value 2
Token +
Token intlit, value 3
Token *
Token intlit, value 5
Token -
Token intlit, value 8
Token /
Token intlit, value 3
