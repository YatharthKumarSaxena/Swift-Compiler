/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    LET = 258,                     /* LET  */
    VAR = 259,                     /* VAR  */
    IF = 260,                      /* IF  */
    ELSE = 261,                    /* ELSE  */
    SWITCH = 262,                  /* SWITCH  */
    CASE = 263,                    /* CASE  */
    DEFAULT = 264,                 /* DEFAULT  */
    WHILE = 265,                   /* WHILE  */
    REPEAT = 266,                  /* REPEAT  */
    FOR = 267,                     /* FOR  */
    IN = 268,                      /* IN  */
    FUNC = 269,                    /* FUNC  */
    RETURN = 270,                  /* RETURN  */
    STRUCT = 271,                  /* STRUCT  */
    PRINT = 272,                   /* PRINT  */
    ARROW = 273,                   /* ARROW  */
    DOTDOTDOT = 274,               /* DOTDOTDOT  */
    TYPE_INT_KW = 275,             /* TYPE_INT_KW  */
    TYPE_DOUBLE_KW = 276,          /* TYPE_DOUBLE_KW  */
    TYPE_BOOL_KW = 277,            /* TYPE_BOOL_KW  */
    TYPE_CHAR_KW = 278,            /* TYPE_CHAR_KW  */
    TYPE_STRING_KW = 279,          /* TYPE_STRING_KW  */
    TYPE_VOID_KW = 280,            /* TYPE_VOID_KW  */
    INT_LITERAL = 281,             /* INT_LITERAL  */
    DOUBLE_LITERAL = 282,          /* DOUBLE_LITERAL  */
    BOOL_LITERAL = 283,            /* BOOL_LITERAL  */
    CHAR_LITERAL = 284,            /* CHAR_LITERAL  */
    STRING_LITERAL = 285,          /* STRING_LITERAL  */
    IDENTIFIER = 286,              /* IDENTIFIER  */
    EQ = 287,                      /* EQ  */
    NE = 288,                      /* NE  */
    LE = 289,                      /* LE  */
    GE = 290,                      /* GE  */
    AND = 291,                     /* AND  */
    OR = 292,                      /* OR  */
    NOT = 293,                     /* NOT  */
    LT = 294,                      /* LT  */
    GT = 295,                      /* GT  */
    UMINUS = 296                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 41 "parser.y"

    int int_val;
    double double_val;
    int bool_val;
    char char_val;
    char* str_val;
    struct ExprNode* expr;
    struct ParamNode* param;
    struct ParamList* param_list;
    struct ArgNode* arg;
    struct ArgList* arg_list;
    struct MemberNode* member;
    struct MemberList* member_list;
    struct TypeInfo* type_info;

#line 121 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
