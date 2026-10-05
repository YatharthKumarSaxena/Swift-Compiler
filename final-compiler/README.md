# Swift Subset Compiler (Lex & Yacc / Flex & Bison)

A complete compiler for a subset of the Swift programming language built using Flex (Lex), Bison (Yacc), and C++17.

## Features Supported

1. **Primitive Types**: `Int`, `Double`, `Bool`, `Character`, `String`, `Void`.
2. **Type Inference**: Automatic type deduction for literals (e.g., `let x = 5` infers `Int`, `let s = "hello"` infers `String`).
3. **Variable Declarations**:
   - `let` (immutable constants, reassignments rejected with semantic error).
   - `var` (mutable variables).
   - Type annotations: `var x: Int = 10` or uninitialized `var y: Int`.
4. **Operators**:
   - Arithmetic: `+`, `-`, `*`, `/`, `%`
   - Relational: `==`, `!=`, `<`, `>`, `<=`, `>=`
   - Logical: `&&`, `||`, `!`
   - String concatenation: `+` with String operands.
5. **Control Flow**:
   - `if` and `else` constructs (with boolean condition checking).
   - `switch` with `case` values and `default` branch.
6. **Loops**:
   - `while` loops.
   - `repeat-while` loops.
   - `for-in` range loops (`for i in 1...10`) and array iteration (`for x in arr`).
7. **Functions**:
   - Parameters and return values.
   - Named argument calls (e.g. `add(a: 10, b: 20)`).
   - `Void` return types (`-> Void` or implicit void).
8. **Arrays**:
   - 1D fixed-size arrays (e.g., `[10, 20, 30]`).
   - Element access via subscript (`arr[0]`).
   - Subscript mutation (`arr[0] = 99`).
9. **User-Defined Types (struct)**:
   - Struct declaration with value semantics (e.g. `struct Point { var x: Int; var y: Int }`).
   - Instantiation with fields (`var p = Point(x: 3, y: 4)`).
   - Member access (`p.x`) and field mutation (`p.x = 10`).
   - Immutability enforcement on `let` struct instances.
10. **Three-Address Code (TAC)**:
    - Intermediate representation generation for expressions, control flow, loops, functions, arrays, and structs.
11. **Error Diagnostics**:
    - Lexical errors (unterminated strings, unterminated multi-line comments, unexpected characters).
    - Syntactic errors with line numbers.
    - Semantic errors (immutability violations, type mismatches, undeclared identifiers, duplicate declarations).

## Build Instructions

```bash
cd final-compiler
make
```

Binary generated: `swiftc_subset`

## Usage

```bash
./swiftc_subset [options] <source_file.swift>

Options:
  -a, --all      Display all compiler stages (Tokens, Parse Log, SymTab, TAC) [default]
  -t, --tokens   Display lexical tokens only
  -p, --parse    Display parsing messages only
  -s, --symtab   Display symbol table only
  -c, --tac      Display Three-Address Code (TAC) only
  -h, --help     Show help message
```

## Running the Automated Test Suite

From the repository root:
```bash
./run_all_tests.sh
```
or
```bash
make test
```

Generates:
- `COMPILER_EXECUTION_RESULTS.txt` (full execution output of tests 1 to 9)
- `Swift_Subset_Compiler_Report.pdf` (26-page PDF report)
- `submission_txt/` (all source files renamed with `.txt` extension ready for submission)
