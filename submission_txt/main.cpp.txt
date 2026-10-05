#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include "compiler_context.h"
#include "parser.tab.h"

extern FILE* yyin;
extern int yyparse();

void printBanner() {
    std::cout << "================================================================================\n";
    std::cout << "           SWIFT SUBSET COMPILER (LEX & YACC / FLEX & BISON)                   \n";
    std::cout << "================================================================================\n";
}

void printHelp(const char* prog) {
    std::cout << "Usage: " << prog << " [options] <source_file.swift>\n\n";
    std::cout << "Options:\n";
    std::cout << "  -a, --all      Display all compiler stages (Tokens, Parse Log, SymTab, TAC) [default]\n";
    std::cout << "  -t, --tokens   Display lexical tokens\n";
    std::cout << "  -p, --parse    Display parsing messages\n";
    std::cout << "  -s, --symtab   Display symbol table\n";
    std::cout << "  -c, --tac      Display Three-Address Code (TAC)\n";
    std::cout << "  -h, --help     Show this help message\n";
}

int main(int argc, char* argv[]) {
    bool show_all = true;
    bool show_tokens = false;
    bool show_parse = false;
    bool show_symtab = false;
    bool show_tac = false;
    const char* filename = nullptr;

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--all") == 0) {
            show_all = true;
        } else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--tokens") == 0) {
            show_tokens = true;
            show_all = false;
        } else if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--parse") == 0) {
            show_parse = true;
            show_all = false;
        } else if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--symtab") == 0) {
            show_symtab = true;
            show_all = false;
        } else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--tac") == 0) {
            show_tac = true;
            show_all = false;
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            printHelp(argv[0]);
            return 0;
        } else if (argv[i][0] != '-') {
            filename = argv[i];
        } else {
            std::cerr << "Unknown option: " << argv[i] << "\n";
            printHelp(argv[0]);
            return 1;
        }
    }

    if (filename) {
        yyin = fopen(filename, "r");
        if (!yyin) {
            std::cerr << "Error: Could not open input file: " << filename << "\n";
            return 1;
        }
    } else {
        std::cout << "Reading from standard input (Ctrl+D to end)...\n";
        yyin = stdin;
    }

    printBanner();
    if (filename) {
        std::cout << "Compiling file: " << filename << "\n\n";
    }

    // Run Parser and Lexer
    int parse_result = yyparse();

    if (filename) {
        fclose(yyin);
    }

    // Display outputs
    if (show_all || show_tokens) {
        g_compiler.printTokens();
    }

    if (show_all || show_parse) {
        g_compiler.printParseEvents();
    }

    if (show_all || show_symtab) {
        g_compiler.symtab.printTable();
    }

    if (show_all || show_tac) {
        g_compiler.tac.printTAC();
    }

    g_compiler.printErrors();

    if (parse_result != 0 || g_compiler.hasErrors()) {
        std::cout << "STATUS: Compilation FAILED with errors.\n";
        return 1;
    } else {
        std::cout << "STATUS: Compilation SUCCEEDED without errors.\n";
        return 0;
    }
}
