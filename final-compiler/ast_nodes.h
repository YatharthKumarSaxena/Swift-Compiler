#ifndef AST_NODES_H
#define AST_NODES_H

#include "symbol_table.h"
#include "tac.h"
#include <string>
#include <vector>

struct ExprNode {
    std::string place;
    TypeInfo type;
    bool is_lvalue;
    bool is_let;
    std::string base_id;
    std::string member_id;

    ExprNode() : place(""), type(TYPE_UNKNOWN), is_lvalue(false), is_let(false), base_id(""), member_id("") {}
    ExprNode(const std::string& p, const TypeInfo& t)
        : place(p), type(t), is_lvalue(false), is_let(false), base_id(""), member_id("") {}
};

struct ParamNode {
    std::string label;
    std::string name;
    TypeInfo type;
};

struct ParamList {
    std::vector<ParamNode> params;
};

struct ArgNode {
    std::string label;
    std::string place;
    TypeInfo type;
};

struct ArgList {
    std::vector<ArgNode> args;
};

struct MemberNode {
    std::string name;
    TypeInfo type;
    bool is_let;
};

struct MemberList {
    std::vector<MemberNode> members;
};

struct CaseNode {
    std::string val_place;
    std::string label;
    bool is_default;
};

struct CaseList {
    std::vector<CaseNode> cases;
};

#endif // AST_NODES_H
