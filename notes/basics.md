# Understanding the Compilation Process

A compiler translates a **high-level programming language** into a **lower-level language** that can eventually be executed by the computer.

For example, a C compiler takes C source code as input and processes it through several stages before producing assembly (and eventually machine code).

## Compilation Pipeline

### 1. Lexical Analysis (Lexer)

The lexer reads the source code character by character and groups them into meaningful **tokens**.

Examples of tokens include:

- Keywords (`int`, `return`)
- Identifiers (`main`, `count`)
- Operators (`+`, `=`, `==`)
- Literals (`42`, `"Hello"`)

One important responsibility of the lexer is distinguishing between similar-looking operators such as `=` (assignment) and `==` (equality).

---

### 2. Parsing

The parser takes the stream of tokens and checks whether they follow the grammar of the C language.

At this stage, syntax errors such as missing semicolons, unmatched parentheses, or incorrectly structured statements are detected.

The parser also builds an **Abstract Syntax Tree (AST)** representing the structure of the program.

---

### 3. Semantic Analysis

After the syntax is validated, the compiler checks whether the program is **meaningful**.

Some examples include:

- Using variables before they are declared
- Type mismatches
- Invalid operations
- Scope checking

A program can be syntactically correct while still being semantically incorrect.

---

### 4. Code Generation

Finally, the compiler translates the semantically valid program into a lower-level language.

For this project, the compiler will eventually generate **x86-64 assembly**, which can then be assembled and linked into an executable.

---

# Why C?

C is an excellent language for writing a compiler because it is relatively small, simple, and provides direct control over memory and data structures.

Unlike higher-level languages such as Python or Go, C has a much smaller runtime and standard library, allowing the focus to remain on compiler construction rather than language-specific infrastructure.

Many production compilers, including early versions of GCC, were written in C.

---

# Development Environment

This project is developed on **Windows 11** using **MSYS2 UCRT64**, providing a Unix-like development environment.

## Tools

- **Operating System:** Windows 11
- **Editor:** Visual Studio Code
- **Shell:** MSYS2 UCRT64 Bash
- **Compiler:** GCC (MSYS2 UCRT64 Toolchain)
- **Build System:** GNU Make
- **Version Control:** Git

Although I already had an older MinGW GCC installation, this project uses the modern MSYS2 UCRT64 toolchain to closely match the Linux-based environment assumed by the tutorial.



