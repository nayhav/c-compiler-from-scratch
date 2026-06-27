# Understanding the Compilation Process

A compiler translates a high-level programming language into a lower-level language that the computer can understand.

For this project, the compiler will take C source code as input and eventually generate x86-64 assembly.

## Compilation Pipeline

### Lexical Analysis

The lexer reads the source code character by character and groups them into tokens.

Examples of tokens: keywords, identifiers, operators and literals.

One of the lexer's jobs is distinguishing between similar-looking operators like `=` and `==`.

### Parsing

The parser checks whether the token stream follows the grammar of the C language.

This stage catches syntax errors such as missing semicolons, unmatched parentheses, or malformed expressions. It also builds an Abstract Syntax Tree (AST), which represents the structure of the program.

### Semantic Analysis

Once the syntax is valid, the compiler checks whether the program actually makes sense. Stuff like variables used before they are declared, type mismatches, non-valid operations and checking for scope.

### Code Generation

After semantic analysis, the compiler generates lower-level code.

For this project, the final output will be x86-64 assembly, which can then be assembled and linked into an executable.

## Why C?

C is a good language for writing a compiler because it's relatively small, simple, and gives direct control over memory.

Unlike languages like Python or Go, there isn't a large runtime or standard library to worry about, making it easier to focus on compiler construction itself.

Many production compilers, including early versions of GCC, were written in C.

## Development Environment

This project is being developed on Windows 11 using MSYS2 UCRT64.

### Tools

- Windows 11
- Visual Studio Code
- MSYS2 UCRT64 Bash
- GCC (MSYS2 UCRT64 Toolchain)
- GNU Make
- Git

I already had an older MinGW GCC installation, but switched to the MSYS2 UCRT64 toolchain to better match the environment used by the tutorial.

## Note

This project is a learning exercise. The implementation and explanations are my own. ChatGPT was used only as a learning aid for understanding concepts and polishing documentation.
