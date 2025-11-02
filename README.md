# Number System Converter (C)

A small command-line tool written in C to convert numbers between bases (2–36). Good for learning parsing, validation and string manipulation in C. Clean, documented and easy to extend.

## Features
- Convert a number from a source base to a target base (2–36).
- Supports optional leading `-` for negative numbers.
- Validates input digits for the source base.
- Clear CLI usage and examples.

## Build
```bash
# from repo root
make
# or compile directly
gcc -std=c11 -O2 -Wall -Wextra -o bin/numconv src/numconv.c
