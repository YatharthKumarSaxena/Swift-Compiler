#ifndef COMPILER_CONTEXT_H
#define COMPILER_CONTEXT_H

#include "symbol_table.h"
#include "tac.h"
#include "ast_nodes.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

struct TokenInfo {
    std::string token_name;
    std::string lexeme;
    int line;
};

struct SwitchContext {
    std::string expr_place;
    std::string end_label;
};

struct LoopContext {
    std::string start_label;
    std::string end_label;
};

class CompilerContext {
public:
    SymbolTable symtab;
    TACGenerator tac;
    std::vector<TokenInfo> recorded_tokens;
    std::vector<std::string> errors;
    std::vector<std::string> parsing_events;
    std::vector<SwitchContext> switch_stack;
    std::vector<LoopContext> loop_stack;

    int lexical_errors = 0;
    int syntax_errors = 0;
    int semantic_errors = 0;

    void logToken(const std::string& name, const std::string& lexeme, int line) {
        recorded_tokens.push_back({name, lexeme, line});
    }

    void logParseEvent(const std::string& event) {
        parsing_events.push_back(event);
    }

    void reportLexicalError(int line, const std::string& msg) {
        std::string err = "[Lexical Error at line " + std::to_string(line) + "]: " + msg;
        errors.push_back(err);
        lexical_errors++;
    }

    void reportSyntaxError(int line, const std::string& msg) {
        std::string err = "[Syntax Error at line " + std::to_string(line) + "]: " + msg;
        errors.push_back(err);
        syntax_errors++;
    }

    void reportSemanticError(int line, const std::string& msg) {
        std::string err = "[Semantic Error at line " + std::to_string(line) + "]: " + msg;
        errors.push_back(err);
        semantic_errors++;
    }

    bool hasErrors() const {
        return (lexical_errors + syntax_errors + semantic_errors) > 0;
    }

    // Switch helpers
    void enterSwitch(const std::string& expr_place) {
        std::string end_lbl = tac.newLabel();
        switch_stack.push_back({expr_place, end_lbl});
    }

    std::string startCase(const std::string& case_val) {
        if (switch_stack.empty()) return "";
        std::string next_lbl = tac.newLabel();
        std::string t = tac.newTemp();
        tac.emitBinary("==", switch_stack.back().expr_place, case_val, t);
        tac.emitIfFalse(t, next_lbl);
        return next_lbl;
    }

    void endCase(const std::string& next_lbl) {
        if (!switch_stack.empty()) {
            tac.emitGoto(switch_stack.back().end_label);
        }
        if (!next_lbl.empty()) {
            tac.emitLabel(next_lbl);
        }
    }

    void exitSwitch() {
        if (!switch_stack.empty()) {
            tac.emitLabel(switch_stack.back().end_label);
            switch_stack.pop_back();
        }
    }

    void printErrors() const {
        if (errors.empty()) {
            std::cout << "\n>>> Compilation finished successfully with 0 errors.\n";
            return;
        }
        std::cout << "\n============================== COMPILATION ERRORS ==============================\n";
        for (const auto& err : errors) {
            std::cout << err << "\n";
        }
        std::cout << "Summary: " << lexical_errors << " lexical, "
                  << syntax_errors << " syntax, "
                  << semantic_errors << " semantic errors.\n";
        std::cout << "================================================================================\n\n";
    }

    void printTokens() const {
        std::cout << "\n================================ TOKEN STREAM ==================================\n";
        std::cout << std::left << std::setw(8) << "Line" 
                  << std::setw(24) << "Token Type" 
                  << "Lexeme\n";
        std::cout << "--------------------------------------------------------------------------------\n";
        for (const auto& tok : recorded_tokens) {
            std::cout << std::left << std::setw(8) << tok.line 
                      << std::setw(24) << tok.token_name 
                      << tok.lexeme << "\n";
        }
        std::cout << "================================================================================\n\n";
    }

    void printParseEvents() const {
        std::cout << "\n================================ PARSING MESSAGES ==============================\n";
        for (const auto& ev : parsing_events) {
            std::cout << "  [PARSER] " << ev << "\n";
        }
        std::cout << "================================================================================\n\n";
    }
};

extern CompilerContext g_compiler;

#endif // COMPILER_CONTEXT_H
