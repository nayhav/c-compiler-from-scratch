#include <errno.h>

#include "defs.h"

#define extern_
#include "data.h"
#undef extern_

#include "decl.h"

/*
 * Initializes the shared compiler state before scanning begins.
 */
static void initialize_compiler(void) {
    current_line = 1;
    putback_char = '\n';
}

/*
 * Prints the correct command-line usage and exits.
 */
static void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <input-file>\n", program_name);
    exit(EXIT_FAILURE);
}

/*
 * String representation of each token.
 */
static const char *token_names[] = {
    "+",
    "-",
    "*",
    "/",
    "intlit"
};

/*
 * Continuously scans tokens from the input file
 * and prints them to the console.
 */
static void scan_input(void) {
    struct token token;

    while (scan(&token)) {
        printf("Token %s", token_names[token.token]);

        if (token.token == T_INTLIT)
            printf(", value %d", token.intvalue);

        putchar('\n');
    }
}

int main(int argc, char *argv[]) {

    if (argc != 2)
        print_usage(argv[0]);

    initialize_compiler();

    input_file = fopen(argv[1], "r");

    if (input_file == NULL) {
        fprintf(stderr,
                "Unable to open '%s': %s\n",
                argv[1],
                strerror(errno));
        exit(EXIT_FAILURE);
    }

    scan_input();

    fclose(input_file);
    return EXIT_SUCCESS;
}

