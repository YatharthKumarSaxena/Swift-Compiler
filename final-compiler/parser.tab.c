/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "symbol_table.h"
#include "tac.h"
#include "ast_nodes.h"
#include "compiler_context.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
void yyerror(const char* s);

CompilerContext g_compiler;

static bool isNumeric(DataType t) {
    return t == TYPE_INT || t == TYPE_DOUBLE;
}

static bool checkTypeCompatibility(const TypeInfo& dest, const TypeInfo& src) {
    if (dest.base_type == TYPE_UNKNOWN || src.base_type == TYPE_UNKNOWN) return true;
    if (dest.base_type == TYPE_ERROR || src.base_type == TYPE_ERROR) return false;
    if (dest.base_type == src.base_type) {
        if (dest.base_type == TYPE_ARRAY) {
            return dest.elem_type == src.elem_type;
        }
        if (dest.base_type == TYPE_STRUCT) {
            return dest.struct_name == src.struct_name;
        }
        return true;
    }
    if (dest.base_type == TYPE_DOUBLE && src.base_type == TYPE_INT) {
        return true;
    }
    return false;
}

#line 111 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LET = 3,                        /* LET  */
  YYSYMBOL_VAR = 4,                        /* VAR  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_SWITCH = 7,                     /* SWITCH  */
  YYSYMBOL_CASE = 8,                       /* CASE  */
  YYSYMBOL_DEFAULT = 9,                    /* DEFAULT  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_REPEAT = 11,                    /* REPEAT  */
  YYSYMBOL_FOR = 12,                       /* FOR  */
  YYSYMBOL_IN = 13,                        /* IN  */
  YYSYMBOL_FUNC = 14,                      /* FUNC  */
  YYSYMBOL_RETURN = 15,                    /* RETURN  */
  YYSYMBOL_STRUCT = 16,                    /* STRUCT  */
  YYSYMBOL_PRINT = 17,                     /* PRINT  */
  YYSYMBOL_ARROW = 18,                     /* ARROW  */
  YYSYMBOL_DOTDOTDOT = 19,                 /* DOTDOTDOT  */
  YYSYMBOL_TYPE_INT_KW = 20,               /* TYPE_INT_KW  */
  YYSYMBOL_TYPE_DOUBLE_KW = 21,            /* TYPE_DOUBLE_KW  */
  YYSYMBOL_TYPE_BOOL_KW = 22,              /* TYPE_BOOL_KW  */
  YYSYMBOL_TYPE_CHAR_KW = 23,              /* TYPE_CHAR_KW  */
  YYSYMBOL_TYPE_STRING_KW = 24,            /* TYPE_STRING_KW  */
  YYSYMBOL_TYPE_VOID_KW = 25,              /* TYPE_VOID_KW  */
  YYSYMBOL_INT_LITERAL = 26,               /* INT_LITERAL  */
  YYSYMBOL_DOUBLE_LITERAL = 27,            /* DOUBLE_LITERAL  */
  YYSYMBOL_BOOL_LITERAL = 28,              /* BOOL_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 29,              /* CHAR_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 30,            /* STRING_LITERAL  */
  YYSYMBOL_IDENTIFIER = 31,                /* IDENTIFIER  */
  YYSYMBOL_EQ = 32,                        /* EQ  */
  YYSYMBOL_NE = 33,                        /* NE  */
  YYSYMBOL_LE = 34,                        /* LE  */
  YYSYMBOL_GE = 35,                        /* GE  */
  YYSYMBOL_AND = 36,                       /* AND  */
  YYSYMBOL_OR = 37,                        /* OR  */
  YYSYMBOL_NOT = 38,                       /* NOT  */
  YYSYMBOL_39_ = 39,                       /* '='  */
  YYSYMBOL_LT = 40,                        /* LT  */
  YYSYMBOL_GT = 41,                        /* GT  */
  YYSYMBOL_42_ = 42,                       /* '+'  */
  YYSYMBOL_43_ = 43,                       /* '-'  */
  YYSYMBOL_44_ = 44,                       /* '*'  */
  YYSYMBOL_45_ = 45,                       /* '/'  */
  YYSYMBOL_46_ = 46,                       /* '%'  */
  YYSYMBOL_UMINUS = 47,                    /* UMINUS  */
  YYSYMBOL_48_ = 48,                       /* '.'  */
  YYSYMBOL_49_ = 49,                       /* '['  */
  YYSYMBOL_50_ = 50,                       /* ']'  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_52_ = 52,                       /* ')'  */
  YYSYMBOL_53_ = 53,                       /* ';'  */
  YYSYMBOL_54_ = 54,                       /* '{'  */
  YYSYMBOL_55_ = 55,                       /* '}'  */
  YYSYMBOL_56_ = 56,                       /* ':'  */
  YYSYMBOL_57_ = 57,                       /* ','  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_program = 59,                   /* program  */
  YYSYMBOL_statements = 60,                /* statements  */
  YYSYMBOL_statement = 61,                 /* statement  */
  YYSYMBOL_opt_semi = 62,                  /* opt_semi  */
  YYSYMBOL_block = 63,                     /* block  */
  YYSYMBOL_64_1 = 64,                      /* $@1  */
  YYSYMBOL_variable_declaration = 65,      /* variable_declaration  */
  YYSYMBOL_type_spec = 66,                 /* type_spec  */
  YYSYMBOL_struct_declaration = 67,        /* struct_declaration  */
  YYSYMBOL_struct_members = 68,            /* struct_members  */
  YYSYMBOL_struct_member = 69,             /* struct_member  */
  YYSYMBOL_function_declaration = 70,      /* function_declaration  */
  YYSYMBOL_71_2 = 71,                      /* $@2  */
  YYSYMBOL_72_3 = 72,                      /* $@3  */
  YYSYMBOL_opt_parameters = 73,            /* opt_parameters  */
  YYSYMBOL_parameters = 74,                /* parameters  */
  YYSYMBOL_parameter = 75,                 /* parameter  */
  YYSYMBOL_assignment = 76,                /* assignment  */
  YYSYMBOL_print_statement = 77,           /* print_statement  */
  YYSYMBOL_return_statement = 78,          /* return_statement  */
  YYSYMBOL_if_header = 79,                 /* if_header  */
  YYSYMBOL_if_statement = 80,              /* if_statement  */
  YYSYMBOL_81_4 = 81,                      /* @4  */
  YYSYMBOL_switch_statement = 82,          /* switch_statement  */
  YYSYMBOL_83_5 = 83,                      /* $@5  */
  YYSYMBOL_switch_cases = 84,              /* switch_cases  */
  YYSYMBOL_switch_case = 85,               /* switch_case  */
  YYSYMBOL_86_6 = 86,                      /* @6  */
  YYSYMBOL_while_header = 87,              /* while_header  */
  YYSYMBOL_88_7 = 88,                      /* @7  */
  YYSYMBOL_while_statement = 89,           /* while_statement  */
  YYSYMBOL_repeat_header = 90,             /* repeat_header  */
  YYSYMBOL_repeat_while_statement = 91,    /* repeat_while_statement  */
  YYSYMBOL_for_in_statement = 92,          /* for_in_statement  */
  YYSYMBOL_93_8 = 93,                      /* @8  */
  YYSYMBOL_94_9 = 94,                      /* @9  */
  YYSYMBOL_expression = 95,                /* expression  */
  YYSYMBOL_literal = 96,                   /* literal  */
  YYSYMBOL_array_literal = 97,             /* array_literal  */
  YYSYMBOL_array_access = 98,              /* array_access  */
  YYSYMBOL_field_access = 99,              /* field_access  */
  YYSYMBOL_call_or_init = 100,             /* call_or_init  */
  YYSYMBOL_opt_arguments = 101,            /* opt_arguments  */
  YYSYMBOL_arguments = 102,                /* arguments  */
  YYSYMBOL_argument = 103                  /* argument  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   651

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  234

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    46,     2,     2,
      51,    52,    44,    42,    57,    43,    48,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,    53,
       2,    39,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    40,    41,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   101,   101,   108,   109,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   129,   130,
     135,   134,   150,   167,   184,   202,   220,   230,   240,   241,
     242,   243,   244,   245,   246,   251,   269,   287,   293,   302,
     311,   328,   327,   359,   358,   391,   392,   396,   402,   411,
     420,   438,   458,   484,   521,   530,   536,   548,   561,   567,
     566,   587,   586,   599,   600,   605,   604,   615,   627,   626,
     647,   660,   669,   683,   682,   719,   718,   772,   776,   789,
     793,   797,   801,   805,   809,   826,   841,   856,   871,   885,
     896,   907,   918,   929,   940,   951,   962,   973,   983,  1000,
    1004,  1008,  1012,  1019,  1028,  1048,  1078,  1115,  1164,  1165,
    1169,  1175,  1184,  1193
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LET", "VAR", "IF",
  "ELSE", "SWITCH", "CASE", "DEFAULT", "WHILE", "REPEAT", "FOR", "IN",
  "FUNC", "RETURN", "STRUCT", "PRINT", "ARROW", "DOTDOTDOT", "TYPE_INT_KW",
  "TYPE_DOUBLE_KW", "TYPE_BOOL_KW", "TYPE_CHAR_KW", "TYPE_STRING_KW",
  "TYPE_VOID_KW", "INT_LITERAL", "DOUBLE_LITERAL", "BOOL_LITERAL",
  "CHAR_LITERAL", "STRING_LITERAL", "IDENTIFIER", "EQ", "NE", "LE", "GE",
  "AND", "OR", "NOT", "'='", "LT", "GT", "'+'", "'-'", "'*'", "'/'", "'%'",
  "UMINUS", "'.'", "'['", "']'", "'('", "')'", "';'", "'{'", "'}'", "':'",
  "','", "$accept", "program", "statements", "statement", "opt_semi",
  "block", "$@1", "variable_declaration", "type_spec",
  "struct_declaration", "struct_members", "struct_member",
  "function_declaration", "$@2", "$@3", "opt_parameters", "parameters",
  "parameter", "assignment", "print_statement", "return_statement",
  "if_header", "if_statement", "@4", "switch_statement", "$@5",
  "switch_cases", "switch_case", "@6", "while_header", "@7",
  "while_statement", "repeat_header", "repeat_while_statement",
  "for_in_statement", "@8", "@9", "expression", "literal", "array_literal",
  "array_access", "field_access", "call_or_init", "opt_arguments",
  "arguments", "argument", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-76)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -65,    22,   361,   -65,    -6,    -4,   144,   144,   -65,   -65,
      12,    14,   144,    23,    11,   -65,   -65,   -65,   -65,   -65,
     -16,   144,   144,   389,   144,   -65,   -65,   -65,   -65,   -65,
      17,    17,    17,    27,   -65,   -65,    27,   -65,    27,    17,
     -65,   467,   -65,   -65,   -65,   -65,   -65,   -30,   -20,    48,
     562,   452,   144,    58,    33,   562,    29,   144,   144,    54,
     144,   389,   -65,   -65,    31,   562,   -13,   -65,   482,   -65,
     -65,   -65,   -65,   -65,    82,   -65,    79,   -65,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   -65,   144,    -7,   144,    -7,    59,   144,   -65,   562,
     415,    62,    35,   503,   562,    61,   524,    73,    53,   144,
     -65,   389,   -65,   -65,   -65,   144,   605,   605,    60,    60,
     592,   577,    60,    60,   -15,   -15,   -65,   -65,   -65,   467,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,    -7,   -32,   467,
     -19,   -65,   543,    52,    -1,    32,   -28,    78,    76,   -65,
      80,   104,     8,   -65,   -65,   144,    97,   -65,   562,   -65,
     211,    27,   562,   -65,    87,   144,   -65,   -65,   144,   -65,
     -65,   144,    83,    -3,   -65,    84,   144,    85,    -7,   122,
      62,    88,    90,    17,   -65,   562,   144,   -65,   -65,   -65,
     467,   467,   435,   -65,   -65,   -65,   -65,   562,    -7,   -65,
      -7,    93,   -65,    -7,    -7,   -65,   562,   -65,   -65,   -65,
     361,   241,    94,   -65,   -65,   -65,    17,    17,   -65,   -65,
     -65,    96,   271,   -65,   -65,   361,   301,   -65,    17,   -65,
     331,   -65,    17,   -65
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,    68,    71,
       0,     0,    56,     0,     0,    99,   100,   101,   102,   103,
      78,     0,     0,     0,     0,    17,     3,     5,     6,     7,
      19,    19,    19,     0,     9,    10,     0,    11,     0,    19,
      13,    19,    77,    81,    79,    80,    82,     0,     0,    78,
      57,     0,     0,     0,     0,    55,     0,     0,     0,     0,
       0,   109,    97,    98,    78,   113,     0,   111,     0,    18,
       8,    15,    14,    20,    58,    70,     0,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,     0,     0,     0,     0,     0,     0,    61,    69,
       0,    46,     0,     0,    51,   106,     0,     0,   108,     0,
     104,     0,    83,     4,    59,     0,    89,    90,    93,    94,
      95,    96,    91,    92,    84,    85,    86,    87,    88,    19,
      28,    29,    30,    31,    32,    33,    35,     0,    19,    19,
      19,   106,     0,     0,    78,     0,     0,     0,    45,    48,
       0,     0,     0,    38,    54,     0,   105,   107,   112,   110,
       0,     0,    72,    22,     0,     0,    27,    23,     0,    26,
     105,     0,     0,     0,    64,     0,     0,     0,     0,    43,
       0,     0,     0,    19,    37,    53,     0,    21,    60,    34,
      19,    19,     0,     4,    62,    63,     4,    73,     0,    49,
       0,     0,    47,     0,     0,    36,    52,    24,    25,    65,
      67,     0,     0,    50,    41,     4,    19,    19,     4,    76,
       4,     0,     0,    40,    39,    66,     0,     4,    19,    74,
       0,    44,    19,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,   -64,   -65,   -31,   -34,   -65,   -65,   -36,   -65,
     -65,     1,   -65,   -65,   -65,   -65,   -65,   -25,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -12,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,    34,   -65,   -65,
     -65,   -65,   -65,   -65,   105,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    26,    70,    74,   113,    27,   138,    28,
     152,   153,    29,   221,   201,   147,   148,   149,    30,    31,
      32,    33,    34,   161,    35,   143,   173,   174,   218,    36,
      52,    37,    38,    39,    40,   212,   175,    41,    42,    43,
      44,    45,    46,   107,    66,    67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      71,    72,    75,   177,    76,   171,   172,   165,    77,    92,
      91,   150,   151,   130,   131,   132,   133,   134,   135,    94,
     168,    69,     3,    58,   136,    47,    93,    48,   178,    88,
      89,    90,    59,    60,    69,    61,    95,   110,   150,   151,
      50,    51,   137,    53,   111,    54,    55,    96,    97,   160,
      61,   176,   194,   -75,    56,    62,    63,    65,    68,   140,
     171,   172,    57,   183,    78,    79,    80,    81,    82,    83,
      69,   100,    84,    85,    86,    87,    88,    89,    90,    96,
      97,    73,    61,   102,   101,   105,    99,   109,   114,   115,
     141,   103,   104,   146,   106,    65,    96,    97,   163,    61,
     155,   164,    86,    87,    88,    89,    90,   166,   167,   169,
     111,   181,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   157,   129,   188,   139,   210,
     179,   142,   211,   180,   145,   182,   186,   189,   196,   193,
     200,   198,   199,   158,   203,    65,   204,   215,   220,   162,
     227,   222,   205,   184,   225,   202,   226,   159,     0,   207,
     208,   195,   213,   230,   214,     0,   108,   216,   217,     0,
      15,    16,    17,    18,    19,    49,     0,     0,     0,     0,
       0,     0,    21,     0,     0,   223,   224,    22,     0,   185,
       0,     0,     0,    23,     0,    24,     0,   231,     0,   190,
       0,   233,   191,     0,     0,   192,     0,     0,     0,     0,
     197,     0,     0,     0,     4,     5,     6,     0,     7,     0,
     206,     8,     9,    10,     0,    11,    12,    13,    14,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    16,    17,
      18,    19,    20,     0,     4,     5,     6,     0,     7,    21,
       0,     8,     9,    10,    22,    11,    12,    13,    14,     0,
      23,     0,    24,     0,    25,     0,   187,    15,    16,    17,
      18,    19,    20,     0,     4,     5,     6,     0,     7,    21,
       0,     8,     9,    10,    22,    11,    12,    13,    14,     0,
      23,     0,    24,     0,    25,     0,   219,    15,    16,    17,
      18,    19,    20,     0,     4,     5,     6,     0,     7,    21,
       0,     8,     9,    10,    22,    11,    12,    13,    14,     0,
      23,     0,    24,     0,    25,     0,   228,    15,    16,    17,
      18,    19,    20,     0,     4,     5,     6,     0,     7,    21,
       0,     8,     9,    10,    22,    11,    12,    13,    14,     0,
      23,     0,    24,     0,    25,     0,   229,    15,    16,    17,
      18,    19,    20,     0,     4,     5,     6,     0,     7,    21,
       0,     8,     9,    10,    22,    11,    12,    13,    14,     0,
      23,     0,    24,     0,    25,     0,   232,    15,    16,    17,
      18,    19,    20,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,    22,     0,     0,     0,     0,     0,
      23,     0,    24,     0,    25,    15,    16,    17,    18,    19,
      64,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,     0,    22,     0,     0,     0,     0,     0,    23,     0,
      24,    15,    16,    17,    18,    19,   144,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,    22,     0,
       0,     0,     0,     0,    23,     0,    24,    78,    79,    80,
      81,    82,    83,     0,     0,    84,    85,    86,    87,    88,
      89,    90,     0,     0,    78,    79,    80,    81,    82,    83,
       0,   209,    84,    85,    86,    87,    88,    89,    90,    78,
      79,    80,    81,    82,    83,     0,    98,    84,    85,    86,
      87,    88,    89,    90,    78,    79,    80,    81,    82,    83,
      69,     0,    84,    85,    86,    87,    88,    89,    90,     0,
       0,     0,     0,     0,   112,    78,    79,    80,    81,    82,
      83,     0,     0,    84,    85,    86,    87,    88,    89,    90,
       0,     0,     0,     0,     0,   154,    78,    79,    80,    81,
      82,    83,     0,     0,    84,    85,    86,    87,    88,    89,
      90,     0,     0,     0,   156,    78,    79,    80,    81,    82,
      83,     0,     0,    84,    85,    86,    87,    88,    89,    90,
       0,     0,     0,   170,    78,    79,    80,    81,    82,    83,
       0,     0,    84,    85,    86,    87,    88,    89,    90,    78,
      79,    80,    81,    82,     0,     0,     0,    84,    85,    86,
      87,    88,    89,    90,    78,    79,    80,    81,     0,     0,
       0,     0,    84,    85,    86,    87,    88,    89,    90,    80,
      81,     0,     0,     0,     0,    84,    85,    86,    87,    88,
      89,    90
};

static const yytype_int16 yycheck[] =
{
      31,    32,    36,    31,    38,     8,     9,    39,    39,    39,
      41,     3,     4,    20,    21,    22,    23,    24,    25,    39,
      39,    53,     0,    39,    31,    31,    56,    31,    56,    44,
      45,    46,    48,    49,    53,    51,    56,    50,     3,     4,
       6,     7,    49,    31,    57,    31,    12,    48,    49,   113,
      51,    19,    55,    54,    31,    21,    22,    23,    24,    95,
       8,     9,    51,    55,    32,    33,    34,    35,    36,    37,
      53,    13,    40,    41,    42,    43,    44,    45,    46,    48,
      49,    54,    51,    54,    51,    31,    52,    56,     6,    10,
      31,    57,    58,    31,    60,    61,    48,    49,   129,    51,
      39,   137,    42,    43,    44,    45,    46,   138,   139,   140,
      57,    31,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    52,    92,   161,    94,   193,
      52,    97,   196,    57,   100,    31,    39,    50,    54,    56,
      18,    56,   178,   109,    56,   111,    56,    54,    54,   115,
      54,   215,   183,   152,   218,   180,   220,   111,    -1,   190,
     191,   173,   198,   227,   200,    -1,    61,   203,   204,    -1,
      26,    27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,   216,   217,    43,    -1,   155,
      -1,    -1,    -1,    49,    -1,    51,    -1,   228,    -1,   165,
      -1,   232,   168,    -1,    -1,   171,    -1,    -1,    -1,    -1,
     176,    -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,
     186,    10,    11,    12,    -1,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    -1,     3,     4,     5,    -1,     7,    38,
      -1,    10,    11,    12,    43,    14,    15,    16,    17,    -1,
      49,    -1,    51,    -1,    53,    -1,    55,    26,    27,    28,
      29,    30,    31,    -1,     3,     4,     5,    -1,     7,    38,
      -1,    10,    11,    12,    43,    14,    15,    16,    17,    -1,
      49,    -1,    51,    -1,    53,    -1,    55,    26,    27,    28,
      29,    30,    31,    -1,     3,     4,     5,    -1,     7,    38,
      -1,    10,    11,    12,    43,    14,    15,    16,    17,    -1,
      49,    -1,    51,    -1,    53,    -1,    55,    26,    27,    28,
      29,    30,    31,    -1,     3,     4,     5,    -1,     7,    38,
      -1,    10,    11,    12,    43,    14,    15,    16,    17,    -1,
      49,    -1,    51,    -1,    53,    -1,    55,    26,    27,    28,
      29,    30,    31,    -1,     3,     4,     5,    -1,     7,    38,
      -1,    10,    11,    12,    43,    14,    15,    16,    17,    -1,
      49,    -1,    51,    -1,    53,    -1,    55,    26,    27,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    51,    -1,    53,    26,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      51,    26,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    51,    32,    33,    34,
      35,    36,    37,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    32,    33,    34,    35,    36,    37,
      -1,    56,    40,    41,    42,    43,    44,    45,    46,    32,
      33,    34,    35,    36,    37,    -1,    54,    40,    41,    42,
      43,    44,    45,    46,    32,    33,    34,    35,    36,    37,
      53,    -1,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    52,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    -1,    -1,    52,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    50,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    50,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    34,
      35,    -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    59,    60,     0,     3,     4,     5,     7,    10,    11,
      12,    14,    15,    16,    17,    26,    27,    28,    29,    30,
      31,    38,    43,    49,    51,    53,    61,    65,    67,    70,
      76,    77,    78,    79,    80,    82,    87,    89,    90,    91,
      92,    95,    96,    97,    98,    99,   100,    31,    31,    31,
      95,    95,    88,    31,    31,    95,    31,    51,    39,    48,
      49,    51,    95,    95,    31,    95,   102,   103,    95,    53,
      62,    62,    62,    54,    63,    63,    63,    62,    32,    33,
      34,    35,    36,    37,    40,    41,    42,    43,    44,    45,
      46,    62,    39,    56,    39,    56,    48,    49,    54,    95,
      13,    51,    54,    95,    95,    31,    95,   101,   102,    56,
      50,    57,    52,    64,     6,    10,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      20,    21,    22,    23,    24,    25,    31,    49,    66,    95,
      66,    31,    95,    83,    31,    95,    31,    73,    74,    75,
       3,     4,    68,    69,    52,    39,    50,    52,    95,   103,
      60,    81,    95,    62,    66,    39,    62,    62,    39,    62,
      50,     8,     9,    84,    85,    94,    19,    31,    56,    52,
      57,    31,    31,    55,    69,    95,    39,    55,    63,    50,
      95,    95,    95,    56,    55,    85,    54,    95,    56,    66,
      18,    72,    75,    56,    56,    62,    95,    62,    62,    56,
      60,    60,    93,    66,    66,    54,    66,    66,    86,    55,
      54,    71,    60,    62,    62,    60,    60,    54,    55,    55,
      60,    62,    55,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    62,    62,
      64,    63,    65,    65,    65,    65,    65,    65,    66,    66,
      66,    66,    66,    66,    66,    66,    67,    68,    68,    69,
      69,    71,    70,    72,    70,    73,    73,    74,    74,    75,
      75,    76,    76,    76,    77,    78,    78,    79,    80,    81,
      80,    83,    82,    84,    84,    86,    85,    85,    88,    87,
      89,    90,    91,    93,    92,    94,    92,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    96,
      96,    96,    96,    96,    97,    98,    99,   100,   101,   101,
     102,   102,   103,   103
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     2,     1,
       1,     1,     2,     1,     2,     2,     2,     1,     1,     0,
       0,     4,     5,     5,     7,     7,     5,     5,     1,     1,
       1,     1,     1,     1,     3,     1,     6,     2,     1,     5,
       5,     0,    12,     0,    10,     1,     0,     3,     1,     3,
       4,     3,     6,     5,     4,     2,     1,     2,     2,     0,
       5,     0,     6,     2,     1,     0,     5,     3,     0,     3,
       2,     1,     4,     0,    10,     0,     8,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     1,
       1,     1,     1,     1,     3,     4,     3,     4,     1,     0,
       3,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: statements  */
#line 102 "parser.y"
      {
          g_compiler.logParseEvent("Program parsing completed successfully.");
      }
#line 1450 "parser.tab.c"
    break;

  case 16: /* statement: expression opt_semi  */
#line 124 "parser.y"
                          { delete (yyvsp[-1].expr); }
#line 1456 "parser.tab.c"
    break;

  case 20: /* $@1: %empty  */
#line 135 "parser.y"
      {
          g_compiler.symtab.enterScope();
      }
#line 1464 "parser.tab.c"
    break;

  case 21: /* block: '{' $@1 statements '}'  */
#line 139 "parser.y"
      {
          g_compiler.symtab.exitScope();
      }
#line 1472 "parser.tab.c"
    break;

  case 22: /* variable_declaration: LET IDENTIFIER '=' expression opt_semi  */
#line 151 "parser.y"
      {
          g_compiler.logParseEvent("Variable declaration (let with inference): " + std::string((yyvsp[-3].str_val)));
          if ((yyvsp[-1].expr)->type.base_type == TYPE_ERROR) {
              g_compiler.reportSemanticError(yylineno, "Cannot infer type from invalid expression for 'let " + std::string((yyvsp[-3].str_val)) + "'");
          }
          if (!g_compiler.symtab.insertVar((yyvsp[-3].str_val), (yyvsp[-1].expr)->type, true, yylineno)) {
              g_compiler.reportSemanticError(yylineno, "Invalid redeclaration of identifier '" + std::string((yyvsp[-3].str_val)) + "' in current scope.");
          } else {
              Symbol* sym = g_compiler.symtab.lookupVar((yyvsp[-3].str_val));
              if (sym) sym->is_initialized = true;
              g_compiler.tac.emitAssign((yyvsp[-3].str_val), (yyvsp[-1].expr)->place);
          }
          free((yyvsp[-3].str_val));
          delete (yyvsp[-1].expr);
      }
#line 1492 "parser.tab.c"
    break;

  case 23: /* variable_declaration: VAR IDENTIFIER '=' expression opt_semi  */
#line 168 "parser.y"
      {
          g_compiler.logParseEvent("Variable declaration (var with inference): " + std::string((yyvsp[-3].str_val)));
          if ((yyvsp[-1].expr)->type.base_type == TYPE_ERROR) {
              g_compiler.reportSemanticError(yylineno, "Cannot infer type from invalid expression for 'var " + std::string((yyvsp[-3].str_val)) + "'");
          }
          if (!g_compiler.symtab.insertVar((yyvsp[-3].str_val), (yyvsp[-1].expr)->type, false, yylineno)) {
              g_compiler.reportSemanticError(yylineno, "Invalid redeclaration of identifier '" + std::string((yyvsp[-3].str_val)) + "' in current scope.");
          } else {
              Symbol* sym = g_compiler.symtab.lookupVar((yyvsp[-3].str_val));
              if (sym) sym->is_initialized = true;
              g_compiler.tac.emitAssign((yyvsp[-3].str_val), (yyvsp[-1].expr)->place);
          }
          free((yyvsp[-3].str_val));
          delete (yyvsp[-1].expr);
      }
#line 1512 "parser.tab.c"
    break;

  case 24: /* variable_declaration: LET IDENTIFIER ':' type_spec '=' expression opt_semi  */
#line 185 "parser.y"
      {
          g_compiler.logParseEvent("Variable declaration (let with type annotation): " + std::string((yyvsp[-5].str_val)) + ": " + (yyvsp[-3].type_info)->toString());
          if (!checkTypeCompatibility(*(yyvsp[-3].type_info), (yyvsp[-1].expr)->type)) {
              g_compiler.reportSemanticError(yylineno, "Cannot assign value of type '" + (yyvsp[-1].expr)->type.toString() + "' to type '" + (yyvsp[-3].type_info)->toString() + "' in declaration of '" + std::string((yyvsp[-5].str_val)) + "'.");
          }
          if (!g_compiler.symtab.insertVar((yyvsp[-5].str_val), *(yyvsp[-3].type_info), true, yylineno)) {
              g_compiler.reportSemanticError(yylineno, "Invalid redeclaration of identifier '" + std::string((yyvsp[-5].str_val)) + "' in current scope.");
          } else {
              Symbol* sym = g_compiler.symtab.lookupVar((yyvsp[-5].str_val));
              if (sym) sym->is_initialized = true;
              g_compiler.tac.emitAssign((yyvsp[-5].str_val), (yyvsp[-1].expr)->place);
          }
          free((yyvsp[-5].str_val));
          delete (yyvsp[-3].type_info);
          delete (yyvsp[-1].expr);
      }
#line 1533 "parser.tab.c"
    break;

  case 25: /* variable_declaration: VAR IDENTIFIER ':' type_spec '=' expression opt_semi  */
#line 203 "parser.y"
      {
          g_compiler.logParseEvent("Variable declaration (var with type annotation): " + std::string((yyvsp[-5].str_val)) + ": " + (yyvsp[-3].type_info)->toString());
          if (!checkTypeCompatibility(*(yyvsp[-3].type_info), (yyvsp[-1].expr)->type)) {
              g_compiler.reportSemanticError(yylineno, "Cannot assign value of type '" + (yyvsp[-1].expr)->type.toString() + "' to type '" + (yyvsp[-3].type_info)->toString() + "' in declaration of '" + std::string((yyvsp[-5].str_val)) + "'.");
          }
          if (!g_compiler.symtab.insertVar((yyvsp[-5].str_val), *(yyvsp[-3].type_info), false, yylineno)) {
              g_compiler.reportSemanticError(yylineno, "Invalid redeclaration of identifier '" + std::string((yyvsp[-5].str_val)) + "' in current scope.");
          } else {
              Symbol* sym = g_compiler.symtab.lookupVar((yyvsp[-5].str_val));
              if (sym) sym->is_initialized = true;
              g_compiler.tac.emitAssign((yyvsp[-5].str_val), (yyvsp[-1].expr)->place);
          }
          free((yyvsp[-5].str_val));
          delete (yyvsp[-3].type_info);
          delete (yyvsp[-1].expr);
      }
#line 1554 "parser.tab.c"
    break;

  case 26: /* variable_declaration: VAR IDENTIFIER ':' type_spec opt_semi  */
#line 221 "parser.y"
      {
          g_compiler.logParseEvent("Variable declaration (uninitialized var): " + std::string((yyvsp[-3].str_val)) + ": " + (yyvsp[-1].type_info)->toString());
          if (!g_compiler.symtab.insertVar((yyvsp[-3].str_val), *(yyvsp[-1].type_info), false, yylineno)) {
              g_compiler.reportSemanticError(yylineno, "Invalid redeclaration of identifier '" + std::string((yyvsp[-3].str_val)) + "' in current scope.");
          }
          free((yyvsp[-3].str_val));
          delete (yyvsp[-1].type_info);
      }
#line 1567 "parser.tab.c"
    break;

  case 27: /* variable_declaration: LET IDENTIFIER ':' type_spec opt_semi  */
#line 231 "parser.y"
      {
          g_compiler.reportSemanticError(yylineno, "Immutable 'let' constant '" + std::string((yyvsp[-3].str_val)) + "' requires an initializing expression.");
          g_compiler.symtab.insertVar((yyvsp[-3].str_val), *(yyvsp[-1].type_info), true, yylineno);
          free((yyvsp[-3].str_val));
          delete (yyvsp[-1].type_info);
      }
#line 1578 "parser.tab.c"
    break;

  case 28: /* type_spec: TYPE_INT_KW  */
#line 240 "parser.y"
                       { (yyval.type_info) = new TypeInfo(TYPE_INT); }
#line 1584 "parser.tab.c"
    break;

  case 29: /* type_spec: TYPE_DOUBLE_KW  */
#line 241 "parser.y"
                       { (yyval.type_info) = new TypeInfo(TYPE_DOUBLE); }
#line 1590 "parser.tab.c"
    break;

  case 30: /* type_spec: TYPE_BOOL_KW  */
#line 242 "parser.y"
                       { (yyval.type_info) = new TypeInfo(TYPE_BOOL); }
#line 1596 "parser.tab.c"
    break;

  case 31: /* type_spec: TYPE_CHAR_KW  */
#line 243 "parser.y"
                       { (yyval.type_info) = new TypeInfo(TYPE_CHAR); }
#line 1602 "parser.tab.c"
    break;

  case 32: /* type_spec: TYPE_STRING_KW  */
#line 244 "parser.y"
                       { (yyval.type_info) = new TypeInfo(TYPE_STRING); }
#line 1608 "parser.tab.c"
    break;

  case 33: /* type_spec: TYPE_VOID_KW  */
#line 245 "parser.y"
                       { (yyval.type_info) = new TypeInfo(TYPE_VOID); }
#line 1614 "parser.tab.c"
    break;

  case 34: /* type_spec: '[' type_spec ']'  */
#line 247 "parser.y"
      {
          (yyval.type_info) = new TypeInfo(TYPE_ARRAY, (yyvsp[-1].type_info)->base_type, 0);
          delete (yyvsp[-1].type_info);
      }
#line 1623 "parser.tab.c"
    break;

  case 35: /* type_spec: IDENTIFIER  */
#line 252 "parser.y"
      {
          StructSymbol* st = g_compiler.symtab.lookupStruct((yyvsp[0].str_val));
          if (!st) {
              g_compiler.reportSemanticError(yylineno, "Cannot find type '" + std::string((yyvsp[0].str_val)) + "' in scope.");
              (yyval.type_info) = new TypeInfo(TYPE_ERROR);
          } else {
              (yyval.type_info) = new TypeInfo(TYPE_STRUCT, std::string((yyvsp[0].str_val)));
          }
          free((yyvsp[0].str_val));
      }
#line 1638 "parser.tab.c"
    break;

  case 36: /* struct_declaration: STRUCT IDENTIFIER '{' struct_members '}' opt_semi  */
#line 270 "parser.y"
      {
          g_compiler.logParseEvent("Struct declaration: " + std::string((yyvsp[-4].str_val)));
          StructSymbol st;
          st.name = (yyvsp[-4].str_val);
          st.line_declared = yylineno;
          for (const auto& m : (yyvsp[-2].member_list)->members) {
              st.members.push_back({m.name, m.type, m.is_let});
          }
          if (!g_compiler.symtab.insertStruct(st)) {
              g_compiler.reportSemanticError(yylineno, "Invalid redeclaration of struct '" + std::string((yyvsp[-4].str_val)) + "'.");
          }
          free((yyvsp[-4].str_val));
          delete (yyvsp[-2].member_list);
      }
#line 1657 "parser.tab.c"
    break;

  case 37: /* struct_members: struct_members struct_member  */
#line 288 "parser.y"
      {
          (yyvsp[-1].member_list)->members.push_back(*(yyvsp[0].member));
          delete (yyvsp[0].member);
          (yyval.member_list) = (yyvsp[-1].member_list);
      }
#line 1667 "parser.tab.c"
    break;

  case 38: /* struct_members: struct_member  */
#line 294 "parser.y"
      {
          (yyval.member_list) = new MemberList();
          (yyval.member_list)->members.push_back(*(yyvsp[0].member));
          delete (yyvsp[0].member);
      }
#line 1677 "parser.tab.c"
    break;

  case 39: /* struct_member: VAR IDENTIFIER ':' type_spec opt_semi  */
#line 303 "parser.y"
      {
          (yyval.member) = new MemberNode();
          (yyval.member)->name = (yyvsp[-3].str_val);
          (yyval.member)->type = *(yyvsp[-1].type_info);
          (yyval.member)->is_let = false;
          free((yyvsp[-3].str_val));
          delete (yyvsp[-1].type_info);
      }
#line 1690 "parser.tab.c"
    break;

  case 40: /* struct_member: LET IDENTIFIER ':' type_spec opt_semi  */
#line 312 "parser.y"
      {
          (yyval.member) = new MemberNode();
          (yyval.member)->name = (yyvsp[-3].str_val);
          (yyval.member)->type = *(yyvsp[-1].type_info);
          (yyval.member)->is_let = true;
          free((yyvsp[-3].str_val));
          delete (yyvsp[-1].type_info);
      }
#line 1703 "parser.tab.c"
    break;

  case 41: /* $@2: %empty  */
#line 328 "parser.y"
      {
          FunctionSymbol fn;
          fn.name = (yyvsp[-5].str_val);
          fn.return_type = *(yyvsp[0].type_info);
          fn.line_declared = yylineno;
          if ((yyvsp[-3].param_list)) {
              for (const auto& p : (yyvsp[-3].param_list)->params) {
                  fn.params.push_back({p.label, p.name, p.type, false});
              }
          }
          if (!g_compiler.symtab.insertFunction(fn)) {
              g_compiler.reportSemanticError(yylineno, "Invalid redeclaration of function '" + std::string((yyvsp[-5].str_val)) + "'.");
          }
          g_compiler.tac.emitLabel("func_" + std::string((yyvsp[-5].str_val)));
          g_compiler.symtab.enterScope();
          if ((yyvsp[-3].param_list)) {
              for (const auto& p : (yyvsp[-3].param_list)->params) {
                  g_compiler.symtab.insertVar(p.name, p.type, true, yylineno);
              }
          }
      }
#line 1729 "parser.tab.c"
    break;

  case 42: /* function_declaration: FUNC IDENTIFIER '(' opt_parameters ')' ARROW type_spec $@2 '{' statements '}' opt_semi  */
#line 350 "parser.y"
      {
          g_compiler.logParseEvent("Function declaration: " + std::string((yyvsp[-10].str_val)) + " -> " + (yyvsp[-5].type_info)->toString());
          g_compiler.symtab.exitScope();
          g_compiler.tac.emit("return", "", "", "");
          free((yyvsp[-10].str_val));
          delete (yyvsp[-5].type_info);
          if ((yyvsp[-8].param_list)) delete (yyvsp[-8].param_list);
      }
#line 1742 "parser.tab.c"
    break;

  case 43: /* $@3: %empty  */
#line 359 "parser.y"
      {
          FunctionSymbol fn;
          fn.name = (yyvsp[-3].str_val);
          fn.return_type = TypeInfo(TYPE_VOID);
          fn.line_declared = yylineno;
          if ((yyvsp[-1].param_list)) {
              for (const auto& p : (yyvsp[-1].param_list)->params) {
                  fn.params.push_back({p.label, p.name, p.type, false});
              }
          }
          if (!g_compiler.symtab.insertFunction(fn)) {
              g_compiler.reportSemanticError(yylineno, "Invalid redeclaration of function '" + std::string((yyvsp[-3].str_val)) + "'.");
          }
          g_compiler.tac.emitLabel("func_" + std::string((yyvsp[-3].str_val)));
          g_compiler.symtab.enterScope();
          if ((yyvsp[-1].param_list)) {
              for (const auto& p : (yyvsp[-1].param_list)->params) {
                  g_compiler.symtab.insertVar(p.name, p.type, true, yylineno);
              }
          }
      }
#line 1768 "parser.tab.c"
    break;

  case 44: /* function_declaration: FUNC IDENTIFIER '(' opt_parameters ')' $@3 '{' statements '}' opt_semi  */
#line 381 "parser.y"
      {
          g_compiler.logParseEvent("Function declaration (Void): " + std::string((yyvsp[-8].str_val)));
          g_compiler.symtab.exitScope();
          g_compiler.tac.emit("return", "", "", "");
          free((yyvsp[-8].str_val));
          if ((yyvsp[-6].param_list)) delete (yyvsp[-6].param_list);
      }
#line 1780 "parser.tab.c"
    break;

  case 45: /* opt_parameters: parameters  */
#line 391 "parser.y"
                  { (yyval.param_list) = (yyvsp[0].param_list); }
#line 1786 "parser.tab.c"
    break;

  case 46: /* opt_parameters: %empty  */
#line 392 "parser.y"
                  { (yyval.param_list) = nullptr; }
#line 1792 "parser.tab.c"
    break;

  case 47: /* parameters: parameters ',' parameter  */
#line 397 "parser.y"
      {
          (yyvsp[-2].param_list)->params.push_back(*(yyvsp[0].param));
          delete (yyvsp[0].param);
          (yyval.param_list) = (yyvsp[-2].param_list);
      }
#line 1802 "parser.tab.c"
    break;

  case 48: /* parameters: parameter  */
#line 403 "parser.y"
      {
          (yyval.param_list) = new ParamList();
          (yyval.param_list)->params.push_back(*(yyvsp[0].param));
          delete (yyvsp[0].param);
      }
#line 1812 "parser.tab.c"
    break;

  case 49: /* parameter: IDENTIFIER ':' type_spec  */
#line 412 "parser.y"
      {
          (yyval.param) = new ParamNode();
          (yyval.param)->label = (yyvsp[-2].str_val);
          (yyval.param)->name = (yyvsp[-2].str_val);
          (yyval.param)->type = *(yyvsp[0].type_info);
          free((yyvsp[-2].str_val));
          delete (yyvsp[0].type_info);
      }
#line 1825 "parser.tab.c"
    break;

  case 50: /* parameter: IDENTIFIER IDENTIFIER ':' type_spec  */
#line 421 "parser.y"
      {
          (yyval.param) = new ParamNode();
          (yyval.param)->label = (yyvsp[-3].str_val);
          (yyval.param)->name = (yyvsp[-2].str_val);
          (yyval.param)->type = *(yyvsp[0].type_info);
          free((yyvsp[-3].str_val));
          free((yyvsp[-2].str_val));
          delete (yyvsp[0].type_info);
      }
#line 1839 "parser.tab.c"
    break;

  case 51: /* assignment: IDENTIFIER '=' expression  */
#line 439 "parser.y"
      {
          g_compiler.logParseEvent("Assignment to variable: " + std::string((yyvsp[-2].str_val)));
          Symbol* sym = g_compiler.symtab.lookupVar((yyvsp[-2].str_val));
          if (!sym) {
              g_compiler.reportSemanticError(yylineno, "Cannot find identifier '" + std::string((yyvsp[-2].str_val)) + "' in scope.");
          } else {
              if (sym->is_let) {
                  g_compiler.reportSemanticError(yylineno, "Cannot assign to value: '" + std::string((yyvsp[-2].str_val)) + "' is a 'let' constant.");
              }
              if (!checkTypeCompatibility(sym->type, (yyvsp[0].expr)->type)) {
                  g_compiler.reportSemanticError(yylineno, "Cannot assign value of type '" + (yyvsp[0].expr)->type.toString() + "' to type '" + sym->type.toString() + "'.");
              }
              sym->is_initialized = true;
              g_compiler.tac.emitAssign((yyvsp[-2].str_val), (yyvsp[0].expr)->place);
          }
          free((yyvsp[-2].str_val));
          delete (yyvsp[0].expr);
      }
#line 1862 "parser.tab.c"
    break;

  case 52: /* assignment: IDENTIFIER '[' expression ']' '=' expression  */
#line 459 "parser.y"
      {
          g_compiler.logParseEvent("Assignment to array element: " + std::string((yyvsp[-5].str_val)) + "[]");
          Symbol* sym = g_compiler.symtab.lookupVar((yyvsp[-5].str_val));
          if (!sym) {
              g_compiler.reportSemanticError(yylineno, "Cannot find array '" + std::string((yyvsp[-5].str_val)) + "' in scope.");
          } else {
              if (sym->is_let) {
                  g_compiler.reportSemanticError(yylineno, "Cannot mutate elements of immutable 'let' array '" + std::string((yyvsp[-5].str_val)) + "'.");
              }
              if (sym->type.base_type != TYPE_ARRAY) {
                  g_compiler.reportSemanticError(yylineno, "Cannot subscript non-array type '" + sym->type.toString() + "'.");
              }
              if ((yyvsp[-3].expr)->type.base_type != TYPE_INT) {
                  g_compiler.reportSemanticError(yylineno, "Array index must be of type 'Int', got '" + (yyvsp[-3].expr)->type.toString() + "'.");
              }
              if (!checkTypeCompatibility(TypeInfo(sym->type.elem_type), (yyvsp[0].expr)->type)) {
                  g_compiler.reportSemanticError(yylineno, "Cannot assign value of type '" + (yyvsp[0].expr)->type.toString() + "' to array element type '" + dataTypeToString(sym->type.elem_type) + "'.");
              }
              g_compiler.tac.emitArrayWrite((yyvsp[-5].str_val), (yyvsp[-3].expr)->place, (yyvsp[0].expr)->place);
          }
          free((yyvsp[-5].str_val));
          delete (yyvsp[-3].expr);
          delete (yyvsp[0].expr);
      }
#line 1891 "parser.tab.c"
    break;

  case 53: /* assignment: IDENTIFIER '.' IDENTIFIER '=' expression  */
#line 485 "parser.y"
      {
          g_compiler.logParseEvent("Assignment to struct member: " + std::string((yyvsp[-4].str_val)) + "." + std::string((yyvsp[-2].str_val)));
          Symbol* sym = g_compiler.symtab.lookupVar((yyvsp[-4].str_val));
          if (!sym) {
              g_compiler.reportSemanticError(yylineno, "Cannot find identifier '" + std::string((yyvsp[-4].str_val)) + "' in scope.");
          } else {
              if (sym->is_let) {
                  g_compiler.reportSemanticError(yylineno, "Cannot mutate member of immutable 'let' struct '" + std::string((yyvsp[-4].str_val)) + "'.");
              }
              if (sym->type.base_type != TYPE_STRUCT) {
                  g_compiler.reportSemanticError(yylineno, "Type '" + sym->type.toString() + "' is not a struct.");
              } else {
                  StructSymbol* st = g_compiler.symtab.lookupStruct(sym->type.struct_name);
                  if (st) {
                      const StructMember* mem = st->findMember((yyvsp[-2].str_val));
                      if (!mem) {
                          g_compiler.reportSemanticError(yylineno, "Struct '" + st->name + "' has no member named '" + std::string((yyvsp[-2].str_val)) + "'.");
                      } else {
                          if (mem->is_let) {
                              g_compiler.reportSemanticError(yylineno, "Cannot mutate immutable struct member '" + std::string((yyvsp[-2].str_val)) + "'.");
                          }
                          if (!checkTypeCompatibility(mem->type, (yyvsp[0].expr)->type)) {
                              g_compiler.reportSemanticError(yylineno, "Cannot assign value of type '" + (yyvsp[0].expr)->type.toString() + "' to member type '" + mem->type.toString() + "'.");
                          }
                      }
                  }
              }
              g_compiler.tac.emitFieldWrite((yyvsp[-4].str_val), (yyvsp[-2].str_val), (yyvsp[0].expr)->place);
          }
          free((yyvsp[-4].str_val));
          free((yyvsp[-2].str_val));
          delete (yyvsp[0].expr);
      }
#line 1929 "parser.tab.c"
    break;

  case 54: /* print_statement: PRINT '(' expression ')'  */
#line 522 "parser.y"
      {
          g_compiler.logParseEvent("Print statement: print(" + (yyvsp[-1].expr)->place + ")");
          g_compiler.tac.emitPrint((yyvsp[-1].expr)->place);
          delete (yyvsp[-1].expr);
      }
#line 1939 "parser.tab.c"
    break;

  case 55: /* return_statement: RETURN expression  */
#line 531 "parser.y"
      {
          g_compiler.logParseEvent("Return statement with value: " + (yyvsp[0].expr)->place);
          g_compiler.tac.emitReturn((yyvsp[0].expr)->place);
          delete (yyvsp[0].expr);
      }
#line 1949 "parser.tab.c"
    break;

  case 56: /* return_statement: RETURN  */
#line 537 "parser.y"
      {
          g_compiler.logParseEvent("Return statement (void)");
          g_compiler.tac.emitReturn("");
      }
#line 1958 "parser.tab.c"
    break;

  case 57: /* if_header: IF expression  */
#line 549 "parser.y"
      {
          if ((yyvsp[0].expr)->type.base_type != TYPE_BOOL && (yyvsp[0].expr)->type.base_type != TYPE_ERROR) {
              g_compiler.reportSemanticError(yylineno, "Condition of 'if' statement must be 'Bool', got '" + (yyvsp[0].expr)->type.toString() + "'.");
          }
          std::string else_label = g_compiler.tac.newLabel();
          g_compiler.tac.emitIfFalse((yyvsp[0].expr)->place, else_label);
          (yyval.str_val) = strdup(else_label.c_str());
          delete (yyvsp[0].expr);
      }
#line 1972 "parser.tab.c"
    break;

  case 58: /* if_statement: if_header block  */
#line 562 "parser.y"
      {
          g_compiler.tac.emitLabel((yyvsp[-1].str_val));
          free((yyvsp[-1].str_val));
      }
#line 1981 "parser.tab.c"
    break;

  case 59: /* @4: %empty  */
#line 567 "parser.y"
      {
          std::string end_label = g_compiler.tac.newLabel();
          g_compiler.tac.emitGoto(end_label);
          g_compiler.tac.emitLabel((yyvsp[-2].str_val));
          free((yyvsp[-2].str_val));
          (yyval.str_val) = strdup(end_label.c_str());
      }
#line 1993 "parser.tab.c"
    break;

  case 60: /* if_statement: if_header block ELSE @4 block  */
#line 575 "parser.y"
      {
          g_compiler.tac.emitLabel((yyvsp[-1].str_val));
          free((yyvsp[-1].str_val));
      }
#line 2002 "parser.tab.c"
    break;

  case 61: /* $@5: %empty  */
#line 587 "parser.y"
      {
          g_compiler.logParseEvent("Switch statement on expression: " + (yyvsp[-1].expr)->place);
          g_compiler.enterSwitch((yyvsp[-1].expr)->place);
          delete (yyvsp[-1].expr);
      }
#line 2012 "parser.tab.c"
    break;

  case 62: /* switch_statement: SWITCH expression '{' $@5 switch_cases '}'  */
#line 593 "parser.y"
      {
          g_compiler.exitSwitch();
      }
#line 2020 "parser.tab.c"
    break;

  case 65: /* @6: %empty  */
#line 605 "parser.y"
      {
          std::string next_lbl = g_compiler.startCase((yyvsp[-1].expr)->place);
          (yyval.str_val) = strdup(next_lbl.c_str());
          delete (yyvsp[-1].expr);
      }
#line 2030 "parser.tab.c"
    break;

  case 66: /* switch_case: CASE expression ':' @6 statements  */
#line 611 "parser.y"
      {
          g_compiler.endCase((yyvsp[-1].str_val));
          free((yyvsp[-1].str_val));
      }
#line 2039 "parser.tab.c"
    break;

  case 67: /* switch_case: DEFAULT ':' statements  */
#line 616 "parser.y"
      {
          g_compiler.logParseEvent("Default case in switch");
      }
#line 2047 "parser.tab.c"
    break;

  case 68: /* @7: %empty  */
#line 627 "parser.y"
      {
          std::string loop_start = g_compiler.tac.newLabel();
          g_compiler.tac.emitLabel(loop_start);
          (yyval.str_val) = strdup(loop_start.c_str());
      }
#line 2057 "parser.tab.c"
    break;

  case 69: /* while_header: WHILE @7 expression  */
#line 633 "parser.y"
      {
          if ((yyvsp[0].expr)->type.base_type != TYPE_BOOL && (yyvsp[0].expr)->type.base_type != TYPE_ERROR) {
              g_compiler.reportSemanticError(yylineno, "Condition of 'while' loop must be 'Bool', got '" + (yyvsp[0].expr)->type.toString() + "'.");
          }
          std::string loop_end = g_compiler.tac.newLabel();
          g_compiler.tac.emitIfFalse((yyvsp[0].expr)->place, loop_end);
          std::string combined = std::string((yyvsp[-1].str_val)) + "," + loop_end;
          free((yyvsp[-1].str_val));
          (yyval.str_val) = strdup(combined.c_str());
          delete (yyvsp[0].expr);
      }
#line 2073 "parser.tab.c"
    break;

  case 70: /* while_statement: while_header block  */
#line 648 "parser.y"
      {
          std::string s((yyvsp[-1].str_val));
          size_t comma = s.find(',');
          std::string start_label = s.substr(0, comma);
          std::string end_label = s.substr(comma + 1);
          g_compiler.tac.emitGoto(start_label);
          g_compiler.tac.emitLabel(end_label);
          free((yyvsp[-1].str_val));
      }
#line 2087 "parser.tab.c"
    break;

  case 71: /* repeat_header: REPEAT  */
#line 661 "parser.y"
      {
          std::string loop_start = g_compiler.tac.newLabel();
          g_compiler.tac.emitLabel(loop_start);
          (yyval.str_val) = strdup(loop_start.c_str());
      }
#line 2097 "parser.tab.c"
    break;

  case 72: /* repeat_while_statement: repeat_header block WHILE expression  */
#line 670 "parser.y"
      {
          if ((yyvsp[0].expr)->type.base_type != TYPE_BOOL && (yyvsp[0].expr)->type.base_type != TYPE_ERROR) {
              g_compiler.reportSemanticError(yylineno, "Condition of 'repeat-while' loop must be 'Bool', got '" + (yyvsp[0].expr)->type.toString() + "'.");
          }
          g_compiler.tac.emitIfTrue((yyvsp[0].expr)->place, (yyvsp[-3].str_val));
          free((yyvsp[-3].str_val));
          delete (yyvsp[0].expr);
      }
#line 2110 "parser.tab.c"
    break;

  case 73: /* @8: %empty  */
#line 683 "parser.y"
      {
          g_compiler.symtab.enterScope();
          g_compiler.symtab.insertVar((yyvsp[-4].str_val), TypeInfo(TYPE_INT), true, yylineno);
          g_compiler.tac.emitAssign((yyvsp[-4].str_val), (yyvsp[-2].expr)->place);
          std::string loop_cond = g_compiler.tac.newLabel();
          std::string loop_end = g_compiler.tac.newLabel();
          g_compiler.tac.emitLabel(loop_cond);
          std::string t = g_compiler.tac.newTemp();
          g_compiler.tac.emitBinary("<=", (yyvsp[-4].str_val), (yyvsp[0].expr)->place, t);
          g_compiler.tac.emitIfFalse(t, loop_end);
          std::string labels = loop_cond + "," + loop_end + "," + std::string((yyvsp[-4].str_val));
          (yyval.str_val) = strdup(labels.c_str());
          delete (yyvsp[-2].expr);
          delete (yyvsp[0].expr);
      }
#line 2130 "parser.tab.c"
    break;

  case 74: /* for_in_statement: FOR IDENTIFIER IN expression DOTDOTDOT expression @8 '{' statements '}'  */
#line 699 "parser.y"
      {
          std::string s((yyvsp[-3].str_val));
          size_t c1 = s.find(',');
          size_t c2 = s.rfind(',');
          std::string cond_label = s.substr(0, c1);
          std::string end_label = s.substr(c1 + 1, c2 - c1 - 1);
          std::string var_name = s.substr(c2 + 1);

          std::string next_val = g_compiler.tac.newTemp();
          g_compiler.tac.emitBinary("+", var_name, "1", next_val);
          g_compiler.tac.emitAssign(var_name, next_val);
          g_compiler.tac.emitGoto(cond_label);
          g_compiler.tac.emitLabel(end_label);

          g_compiler.symtab.exitScope();
          free((yyvsp[-3].str_val));
          free((yyvsp[-8].str_val));
      }
#line 2153 "parser.tab.c"
    break;

  case 75: /* @9: %empty  */
#line 719 "parser.y"
      {
          g_compiler.symtab.enterScope();
          Symbol* arr_sym = g_compiler.symtab.lookupVar((yyvsp[0].str_val));
          TypeInfo elem_t(TYPE_INT);
          int arr_sz = 5;
          if (arr_sym && arr_sym->type.base_type == TYPE_ARRAY) {
              elem_t = TypeInfo(arr_sym->type.elem_type);
              arr_sz = arr_sym->type.array_size > 0 ? arr_sym->type.array_size : 5;
          } else {
              g_compiler.reportSemanticError(yylineno, "Identifier '" + std::string((yyvsp[0].str_val)) + "' is not an iterable array.");
          }
          g_compiler.symtab.insertVar((yyvsp[-2].str_val), elem_t, true, yylineno);

          std::string idx_var = g_compiler.tac.newTemp();
          g_compiler.tac.emitAssign(idx_var, "0");
          std::string loop_cond = g_compiler.tac.newLabel();
          std::string loop_end = g_compiler.tac.newLabel();
          g_compiler.tac.emitLabel(loop_cond);
          std::string t_cmp = g_compiler.tac.newTemp();
          g_compiler.tac.emitBinary("<", idx_var, std::to_string(arr_sz), t_cmp);
          g_compiler.tac.emitIfFalse(t_cmp, loop_end);
          g_compiler.tac.emitArrayRead((yyvsp[-2].str_val), (yyvsp[0].str_val), idx_var);

          std::string labels = loop_cond + "," + loop_end + "," + idx_var;
          (yyval.str_val) = strdup(labels.c_str());
      }
#line 2184 "parser.tab.c"
    break;

  case 76: /* for_in_statement: FOR IDENTIFIER IN IDENTIFIER @9 '{' statements '}'  */
#line 746 "parser.y"
      {
          std::string s((yyvsp[-3].str_val));
          size_t c1 = s.find(',');
          size_t c2 = s.rfind(',');
          std::string cond_label = s.substr(0, c1);
          std::string end_label = s.substr(c1 + 1, c2 - c1 - 1);
          std::string idx_var = s.substr(c2 + 1);

          std::string next_idx = g_compiler.tac.newTemp();
          g_compiler.tac.emitBinary("+", idx_var, "1", next_idx);
          g_compiler.tac.emitAssign(idx_var, next_idx);
          g_compiler.tac.emitGoto(cond_label);
          g_compiler.tac.emitLabel(end_label);

          g_compiler.symtab.exitScope();
          free((yyvsp[-3].str_val));
          free((yyvsp[-6].str_val));
          free((yyvsp[-4].str_val));
      }
#line 2208 "parser.tab.c"
    break;

  case 77: /* expression: literal  */
#line 773 "parser.y"
      {
          (yyval.expr) = (yyvsp[0].expr);
      }
#line 2216 "parser.tab.c"
    break;

  case 78: /* expression: IDENTIFIER  */
#line 777 "parser.y"
      {
          Symbol* sym = g_compiler.symtab.lookupVar((yyvsp[0].str_val));
          if (!sym) {
              g_compiler.reportSemanticError(yylineno, "Cannot find identifier '" + std::string((yyvsp[0].str_val)) + "' in scope.");
              (yyval.expr) = new ExprNode((yyvsp[0].str_val), TypeInfo(TYPE_ERROR));
          } else {
              (yyval.expr) = new ExprNode((yyvsp[0].str_val), sym->type);
              (yyval.expr)->is_lvalue = true;
              (yyval.expr)->is_let = sym->is_let;
          }
          free((yyvsp[0].str_val));
      }
#line 2233 "parser.tab.c"
    break;

  case 79: /* expression: array_access  */
#line 790 "parser.y"
      {
          (yyval.expr) = (yyvsp[0].expr);
      }
#line 2241 "parser.tab.c"
    break;

  case 80: /* expression: field_access  */
#line 794 "parser.y"
      {
          (yyval.expr) = (yyvsp[0].expr);
      }
#line 2249 "parser.tab.c"
    break;

  case 81: /* expression: array_literal  */
#line 798 "parser.y"
      {
          (yyval.expr) = (yyvsp[0].expr);
      }
#line 2257 "parser.tab.c"
    break;

  case 82: /* expression: call_or_init  */
#line 802 "parser.y"
      {
          (yyval.expr) = (yyvsp[0].expr);
      }
#line 2265 "parser.tab.c"
    break;

  case 83: /* expression: '(' expression ')'  */
#line 806 "parser.y"
      {
          (yyval.expr) = (yyvsp[-1].expr);
      }
#line 2273 "parser.tab.c"
    break;

  case 84: /* expression: expression '+' expression  */
#line 810 "parser.y"
      {
          std::string t = g_compiler.tac.newTemp();
          TypeInfo res_type(TYPE_ERROR);
          if ((yyvsp[-2].expr)->type.base_type == TYPE_STRING && (yyvsp[0].expr)->type.base_type == TYPE_STRING) {
              res_type = TypeInfo(TYPE_STRING);
          } else if (isNumeric((yyvsp[-2].expr)->type.base_type) && isNumeric((yyvsp[0].expr)->type.base_type)) {
              res_type = ((yyvsp[-2].expr)->type.base_type == TYPE_DOUBLE || (yyvsp[0].expr)->type.base_type == TYPE_DOUBLE) 
                         ? TypeInfo(TYPE_DOUBLE) : TypeInfo(TYPE_INT);
          } else {
              g_compiler.reportSemanticError(yylineno, "Binary operator '+' cannot be applied to operands of type '" + (yyvsp[-2].expr)->type.toString() + "' and '" + (yyvsp[0].expr)->type.toString() + "'.");
          }
          g_compiler.tac.emitBinary("+", (yyvsp[-2].expr)->place, (yyvsp[0].expr)->place, t);
          (yyval.expr) = new ExprNode(t, res_type);
          delete (yyvsp[-2].expr);
          delete (yyvsp[0].expr);
      }
#line 2294 "parser.tab.c"
    break;

  case 85: /* expression: expression '-' expression  */
#line 827 "parser.y"
      {
          std::string t = g_compiler.tac.newTemp();
          TypeInfo res_type(TYPE_ERROR);
          if (isNumeric((yyvsp[-2].expr)->type.base_type) && isNumeric((yyvsp[0].expr)->type.base_type)) {
              res_type = ((yyvsp[-2].expr)->type.base_type == TYPE_DOUBLE || (yyvsp[0].expr)->type.base_type == TYPE_DOUBLE) 
                         ? TypeInfo(TYPE_DOUBLE) : TypeInfo(TYPE_INT);
          } else {
              g_compiler.reportSemanticError(yylineno, "Binary operator '-' cannot be applied to operands of type '" + (yyvsp[-2].expr)->type.toString() + "' and '" + (yyvsp[0].expr)->type.toString() + "'.");
          }
          g_compiler.tac.emitBinary("-", (yyvsp[-2].expr)->place, (yyvsp[0].expr)->place, t);
          (yyval.expr) = new ExprNode(t, res_type);
          delete (yyvsp[-2].expr);
          delete (yyvsp[0].expr);
      }
#line 2313 "parser.tab.c"
    break;

  case 86: /* expression: expression '*' expression  */
#line 842 "parser.y"
      {
          std::string t = g_compiler.tac.newTemp();
          TypeInfo res_type(TYPE_ERROR);
          if (isNumeric((yyvsp[-2].expr)->type.base_type) && isNumeric((yyvsp[0].expr)->type.base_type)) {
              res_type = ((yyvsp[-2].expr)->type.base_type == TYPE_DOUBLE || (yyvsp[0].expr)->type.base_type == TYPE_DOUBLE) 
                         ? TypeInfo(TYPE_DOUBLE) : TypeInfo(TYPE_INT);
          } else {
              g_compiler.reportSemanticError(yylineno, "Binary operator '*' cannot be applied to operands of type '" + (yyvsp[-2].expr)->type.toString() + "' and '" + (yyvsp[0].expr)->type.toString() + "'.");
          }
          g_compiler.tac.emitBinary("*", (yyvsp[-2].expr)->place, (yyvsp[0].expr)->place, t);
          (yyval.expr) = new ExprNode(t, res_type);
          delete (yyvsp[-2].expr);
          delete (yyvsp[0].expr);
      }
#line 2332 "parser.tab.c"
    break;

  case 87: /* expression: expression '/' expression  */
#line 857 "parser.y"
      {
          std::string t = g_compiler.tac.newTemp();
          TypeInfo res_type(TYPE_ERROR);
          if (isNumeric((yyvsp[-2].expr)->type.base_type) && isNumeric((yyvsp[0].expr)->type.base_type)) {
              res_type = ((yyvsp[-2].expr)->type.base_type == TYPE_DOUBLE || (yyvsp[0].expr)->type.base_type == TYPE_DOUBLE) 
                         ? TypeInfo(TYPE_DOUBLE) : TypeInfo(TYPE_INT);
          } else {
              g_compiler.reportSemanticError(yylineno, "Binary operator '/' cannot be applied to operands of type '" + (yyvsp[-2].expr)->type.toString() + "' and '" + (yyvsp[0].expr)->type.toString() + "'.");
          }
          g_compiler.tac.emitBinary("/", (yyvsp[-2].expr)->place, (yyvsp[0].expr)->place, t);
          (yyval.expr) = new ExprNode(t, res_type);
          delete (yyvsp[-2].expr);
          delete (yyvsp[0].expr);
      }
#line 2351 "parser.tab.c"
    break;

  case 88: /* expression: expression '%' expression  */
#line 872 "parser.y"
      {
          std::string t = g_compiler.tac.newTemp();
          TypeInfo res_type(TYPE_ERROR);
          if ((yyvsp[-2].expr)->type.base_type == TYPE_INT && (yyvsp[0].expr)->type.base_type == TYPE_INT) {
              res_type = TypeInfo(TYPE_INT);
          } else {
              g_compiler.reportSemanticError(yylineno, "Binary operator '%' requires integer operands, got '" + (yyvsp[-2].expr)->type.toString() + "' and '" + (yyvsp[0].expr)->type.toString() + "'.");
          }
          g_compiler.tac.emitBinary("%", (yyvsp[-2].expr)->place, (yyvsp[0].expr)->place, t);
          (yyval.expr) = new ExprNode(t, res_type);
          delete (yyvsp[-2].expr);
          delete (yyvsp[0].expr);
      }
#line 2369 "parser.tab.c"
    break;

  case 89: /* expression: expression EQ expression  */
#line 886 "parser.y"
      {
          std::string t = g_compiler.tac.newTemp();
          if (!checkTypeCompatibility((yyvsp[-2].expr)->type, (yyvsp[0].expr)->type) && !checkTypeCompatibility((yyvsp[0].expr)->type, (yyvsp[-2].expr)->type)) {
              g_compiler.reportSemanticError(yylineno, "Operator '==' cannot compare incompatible types '" + (yyvsp[-2].expr)->type.toString() + "' and '" + (yyvsp[0].expr)->type.toString() + "'.");
          }
          g_compiler.tac.emitBinary("==", (yyvsp[-2].expr)->place, (yyvsp[0].expr)->place, t);
          (yyval.expr) = new ExprNode(t, TypeInfo(TYPE_BOOL));
          delete (yyvsp[-2].expr);
          delete (yyvsp[0].expr);
      }
#line 2384 "parser.tab.c"
    break;

  case 90: /* expression: expression NE expression  */
#line 897 "parser.y"
      {
          std::string t = g_compiler.tac.newTemp();
          if (!checkTypeCompatibility((yyvsp[-2].expr)->type, (yyvsp[0].expr)->type) && !checkTypeCompatibility((yyvsp[0].expr)->type, (yyvsp[-2].expr)->type)) {
              g_compiler.reportSemanticError(yylineno, "Operator '!=' cannot compare incompatible types '" + (yyvsp[-2].expr)->type.toString() + "' and '" + (yyvsp[0].expr)->type.toString() + "'.");
          }
          g_compiler.tac.emitBinary("!=", (yyvsp[-2].expr)->place, (yyvsp[0].expr)->place, t);
          (yyval.expr) = new ExprNode(t, TypeInfo(TYPE_BOOL));
          delete (yyvsp[-2].expr);
          delete (yyvsp[0].expr);
      }
#line 2399 "parser.tab.c"
    break;

  case 91: /* expression: expression LT expression  */
#line 908 "parser.y"
      {
          std::string t = g_compiler.tac.newTemp();
          if (!isNumeric((yyvsp[-2].expr)->type.base_type) || !isNumeric((yyvsp[0].expr)->type.base_type)) {
              g_compiler.reportSemanticError(yylineno, "Relational operator '<' requires numeric operands.");
          }
          g_compiler.tac.emitBinary("<", (yyvsp[-2].expr)->place, (yyvsp[0].expr)->place, t);
          (yyval.expr) = new ExprNode(t, TypeInfo(TYPE_BOOL));
          delete (yyvsp[-2].expr);
          delete (yyvsp[0].expr);
      }
#line 2414 "parser.tab.c"
    break;

  case 92: /* expression: expression GT expression  */
#line 919 "parser.y"
      {
          std::string t = g_compiler.tac.newTemp();
          if (!isNumeric((yyvsp[-2].expr)->type.base_type) || !isNumeric((yyvsp[0].expr)->type.base_type)) {
              g_compiler.reportSemanticError(yylineno, "Relational operator '>' requires numeric operands.");
          }
          g_compiler.tac.emitBinary(">", (yyvsp[-2].expr)->place, (yyvsp[0].expr)->place, t);
          (yyval.expr) = new ExprNode(t, TypeInfo(TYPE_BOOL));
          delete (yyvsp[-2].expr);
          delete (yyvsp[0].expr);
      }
#line 2429 "parser.tab.c"
    break;

  case 93: /* expression: expression LE expression  */
#line 930 "parser.y"
      {
          std::string t = g_compiler.tac.newTemp();
          if (!isNumeric((yyvsp[-2].expr)->type.base_type) || !isNumeric((yyvsp[0].expr)->type.base_type)) {
              g_compiler.reportSemanticError(yylineno, "Relational operator '<=' requires numeric operands.");
          }
          g_compiler.tac.emitBinary("<=", (yyvsp[-2].expr)->place, (yyvsp[0].expr)->place, t);
          (yyval.expr) = new ExprNode(t, TypeInfo(TYPE_BOOL));
          delete (yyvsp[-2].expr);
          delete (yyvsp[0].expr);
      }
#line 2444 "parser.tab.c"
    break;

  case 94: /* expression: expression GE expression  */
#line 941 "parser.y"
      {
          std::string t = g_compiler.tac.newTemp();
          if (!isNumeric((yyvsp[-2].expr)->type.base_type) || !isNumeric((yyvsp[0].expr)->type.base_type)) {
              g_compiler.reportSemanticError(yylineno, "Relational operator '>=' requires numeric operands.");
          }
          g_compiler.tac.emitBinary(">=", (yyvsp[-2].expr)->place, (yyvsp[0].expr)->place, t);
          (yyval.expr) = new ExprNode(t, TypeInfo(TYPE_BOOL));
          delete (yyvsp[-2].expr);
          delete (yyvsp[0].expr);
      }
#line 2459 "parser.tab.c"
    break;

  case 95: /* expression: expression AND expression  */
#line 952 "parser.y"
      {
          std::string t = g_compiler.tac.newTemp();
          if ((yyvsp[-2].expr)->type.base_type != TYPE_BOOL || (yyvsp[0].expr)->type.base_type != TYPE_BOOL) {
              g_compiler.reportSemanticError(yylineno, "Logical operator '&&' requires 'Bool' operands.");
          }
          g_compiler.tac.emitBinary("&&", (yyvsp[-2].expr)->place, (yyvsp[0].expr)->place, t);
          (yyval.expr) = new ExprNode(t, TypeInfo(TYPE_BOOL));
          delete (yyvsp[-2].expr);
          delete (yyvsp[0].expr);
      }
#line 2474 "parser.tab.c"
    break;

  case 96: /* expression: expression OR expression  */
#line 963 "parser.y"
      {
          std::string t = g_compiler.tac.newTemp();
          if ((yyvsp[-2].expr)->type.base_type != TYPE_BOOL || (yyvsp[0].expr)->type.base_type != TYPE_BOOL) {
              g_compiler.reportSemanticError(yylineno, "Logical operator '||' requires 'Bool' operands.");
          }
          g_compiler.tac.emitBinary("||", (yyvsp[-2].expr)->place, (yyvsp[0].expr)->place, t);
          (yyval.expr) = new ExprNode(t, TypeInfo(TYPE_BOOL));
          delete (yyvsp[-2].expr);
          delete (yyvsp[0].expr);
      }
#line 2489 "parser.tab.c"
    break;

  case 97: /* expression: NOT expression  */
#line 974 "parser.y"
      {
          std::string t = g_compiler.tac.newTemp();
          if ((yyvsp[0].expr)->type.base_type != TYPE_BOOL) {
              g_compiler.reportSemanticError(yylineno, "Logical operator '!' requires 'Bool' operand.");
          }
          g_compiler.tac.emitUnary("not", (yyvsp[0].expr)->place, t);
          (yyval.expr) = new ExprNode(t, TypeInfo(TYPE_BOOL));
          delete (yyvsp[0].expr);
      }
#line 2503 "parser.tab.c"
    break;

  case 98: /* expression: '-' expression  */
#line 984 "parser.y"
      {
          std::string t = g_compiler.tac.newTemp();
          if (!isNumeric((yyvsp[0].expr)->type.base_type)) {
              g_compiler.reportSemanticError(yylineno, "Unary operator '-' requires numeric operand.");
          }
          g_compiler.tac.emitUnary("neg", (yyvsp[0].expr)->place, t);
          (yyval.expr) = new ExprNode(t, (yyvsp[0].expr)->type);
          delete (yyvsp[0].expr);
      }
#line 2517 "parser.tab.c"
    break;

  case 99: /* literal: INT_LITERAL  */
#line 1001 "parser.y"
      {
          (yyval.expr) = new ExprNode(std::to_string((yyvsp[0].int_val)), TypeInfo(TYPE_INT));
      }
#line 2525 "parser.tab.c"
    break;

  case 100: /* literal: DOUBLE_LITERAL  */
#line 1005 "parser.y"
      {
          (yyval.expr) = new ExprNode(std::to_string((yyvsp[0].double_val)), TypeInfo(TYPE_DOUBLE));
      }
#line 2533 "parser.tab.c"
    break;

  case 101: /* literal: BOOL_LITERAL  */
#line 1009 "parser.y"
      {
          (yyval.expr) = new ExprNode((yyvsp[0].bool_val) ? "true" : "false", TypeInfo(TYPE_BOOL));
      }
#line 2541 "parser.tab.c"
    break;

  case 102: /* literal: CHAR_LITERAL  */
#line 1013 "parser.y"
      {
          std::string c = "'";
          c += (yyvsp[0].char_val);
          c += "'";
          (yyval.expr) = new ExprNode(c, TypeInfo(TYPE_CHAR));
      }
#line 2552 "parser.tab.c"
    break;

  case 103: /* literal: STRING_LITERAL  */
#line 1020 "parser.y"
      {
          (yyval.expr) = new ExprNode(std::string((yyvsp[0].str_val)), TypeInfo(TYPE_STRING));
          free((yyvsp[0].str_val));
      }
#line 2561 "parser.tab.c"
    break;

  case 104: /* array_literal: '[' arguments ']'  */
#line 1029 "parser.y"
      {
          DataType elem_t = TYPE_UNKNOWN;
          if ((yyvsp[-1].arg_list) && !(yyvsp[-1].arg_list)->args.empty()) {
              elem_t = (yyvsp[-1].arg_list)->args[0].type.base_type;
          }
          int sz = (yyvsp[-1].arg_list) ? (int)(yyvsp[-1].arg_list)->args.size() : 0;
          std::string arr_temp = g_compiler.tac.newTemp();
          if ((yyvsp[-1].arg_list)) {
              for (int i = 0; i < sz; ++i) {
                  g_compiler.tac.emitArrayWrite(arr_temp, std::to_string(i), (yyvsp[-1].arg_list)->args[i].place);
              }
          }
          (yyval.expr) = new ExprNode(arr_temp, TypeInfo(TYPE_ARRAY, elem_t, sz));
          delete (yyvsp[-1].arg_list);
      }
#line 2581 "parser.tab.c"
    break;

  case 105: /* array_access: IDENTIFIER '[' expression ']'  */
#line 1049 "parser.y"
      {
          Symbol* sym = g_compiler.symtab.lookupVar((yyvsp[-3].str_val));
          TypeInfo elem_t(TYPE_ERROR);
          if (!sym) {
              g_compiler.reportSemanticError(yylineno, "Cannot find array '" + std::string((yyvsp[-3].str_val)) + "' in scope.");
          } else {
              if (sym->type.base_type != TYPE_ARRAY) {
                  g_compiler.reportSemanticError(yylineno, "Cannot subscript non-array type '" + sym->type.toString() + "'.");
              } else {
                  elem_t = TypeInfo(sym->type.elem_type);
              }
              if ((yyvsp[-1].expr)->type.base_type != TYPE_INT) {
                  g_compiler.reportSemanticError(yylineno, "Array index must be of type 'Int', got '" + (yyvsp[-1].expr)->type.toString() + "'.");
              }
          }
          std::string t = g_compiler.tac.newTemp();
          g_compiler.tac.emitArrayRead(t, (yyvsp[-3].str_val), (yyvsp[-1].expr)->place);
          (yyval.expr) = new ExprNode(t, elem_t);
          (yyval.expr)->base_id = (yyvsp[-3].str_val);
          (yyval.expr)->member_id = (yyvsp[-1].expr)->place;
          (yyval.expr)->is_lvalue = true;
          (yyval.expr)->is_let = sym ? sym->is_let : false;
          free((yyvsp[-3].str_val));
          delete (yyvsp[-1].expr);
      }
#line 2611 "parser.tab.c"
    break;

  case 106: /* field_access: IDENTIFIER '.' IDENTIFIER  */
#line 1079 "parser.y"
      {
          Symbol* sym = g_compiler.symtab.lookupVar((yyvsp[-2].str_val));
          TypeInfo field_t(TYPE_ERROR);
          bool is_let_field = false;
          if (!sym) {
              g_compiler.reportSemanticError(yylineno, "Cannot find identifier '" + std::string((yyvsp[-2].str_val)) + "' in scope.");
          } else {
              if (sym->type.base_type != TYPE_STRUCT) {
                  g_compiler.reportSemanticError(yylineno, "Cannot access field on non-struct type '" + sym->type.toString() + "'.");
              } else {
                  StructSymbol* st = g_compiler.symtab.lookupStruct(sym->type.struct_name);
                  if (st) {
                      const StructMember* mem = st->findMember((yyvsp[0].str_val));
                      if (!mem) {
                          g_compiler.reportSemanticError(yylineno, "Value of type '" + st->name + "' has no member '" + std::string((yyvsp[0].str_val)) + "'.");
                      } else {
                          field_t = mem->type;
                          is_let_field = mem->is_let;
                      }
                  }
              }
          }
          std::string t = g_compiler.tac.newTemp();
          g_compiler.tac.emitFieldRead(t, (yyvsp[-2].str_val), (yyvsp[0].str_val));
          (yyval.expr) = new ExprNode(t, field_t);
          (yyval.expr)->base_id = (yyvsp[-2].str_val);
          (yyval.expr)->member_id = (yyvsp[0].str_val);
          (yyval.expr)->is_lvalue = true;
          (yyval.expr)->is_let = sym ? (sym->is_let || is_let_field) : false;
          free((yyvsp[-2].str_val));
          free((yyvsp[0].str_val));
      }
#line 2648 "parser.tab.c"
    break;

  case 107: /* call_or_init: IDENTIFIER '(' opt_arguments ')'  */
#line 1116 "parser.y"
      {
          StructSymbol* st = g_compiler.symtab.lookupStruct((yyvsp[-3].str_val));
          if (st) {
              std::string t = g_compiler.tac.newTemp();
              if ((yyvsp[-1].arg_list)) {
                  for (const auto& arg : (yyvsp[-1].arg_list)->args) {
                      std::string field_name = arg.label.empty() ? "field" : arg.label;
                      const StructMember* mem = st->findMember(field_name);
                      if (!mem && !arg.label.empty()) {
                          g_compiler.reportSemanticError(yylineno, "Struct '" + st->name + "' has no member named '" + arg.label + "'.");
                      }
                      g_compiler.tac.emitFieldWrite(t, field_name, arg.place);
                  }
              }
              (yyval.expr) = new ExprNode(t, TypeInfo(TYPE_STRUCT, st->name));
          } else {
              FunctionSymbol* fn = g_compiler.symtab.lookupFunction((yyvsp[-3].str_val));
              TypeInfo ret_t(TYPE_VOID);
              if (!fn) {
                  g_compiler.reportSemanticError(yylineno, "Cannot find function or struct '" + std::string((yyvsp[-3].str_val)) + "' in scope.");
              } else {
                  ret_t = fn->return_type;
                  int expected_params = (int)fn->params.size();
                  int provided_args = (yyvsp[-1].arg_list) ? (int)(yyvsp[-1].arg_list)->args.size() : 0;
                  if (expected_params != provided_args) {
                      g_compiler.reportSemanticError(yylineno, "Function '" + fn->name + "' expects " + std::to_string(expected_params) + " arguments, got " + std::to_string(provided_args) + ".");
                  }
              }
              int num_args = 0;
              if ((yyvsp[-1].arg_list)) {
                  num_args = (int)(yyvsp[-1].arg_list)->args.size();
                  for (const auto& arg : (yyvsp[-1].arg_list)->args) {
                      g_compiler.tac.emitParam(arg.place);
                  }
              }
              std::string res = "";
              if (ret_t.base_type != TYPE_VOID) {
                  res = g_compiler.tac.newTemp();
              }
              g_compiler.tac.emitCall("func_" + std::string((yyvsp[-3].str_val)), num_args, res);
              (yyval.expr) = new ExprNode(res, ret_t);
          }
          free((yyvsp[-3].str_val));
          if ((yyvsp[-1].arg_list)) delete (yyvsp[-1].arg_list);
      }
#line 2698 "parser.tab.c"
    break;

  case 108: /* opt_arguments: arguments  */
#line 1164 "parser.y"
                  { (yyval.arg_list) = (yyvsp[0].arg_list); }
#line 2704 "parser.tab.c"
    break;

  case 109: /* opt_arguments: %empty  */
#line 1165 "parser.y"
                  { (yyval.arg_list) = new ArgList(); }
#line 2710 "parser.tab.c"
    break;

  case 110: /* arguments: arguments ',' argument  */
#line 1170 "parser.y"
      {
          (yyvsp[-2].arg_list)->args.push_back(*(yyvsp[0].arg));
          delete (yyvsp[0].arg);
          (yyval.arg_list) = (yyvsp[-2].arg_list);
      }
#line 2720 "parser.tab.c"
    break;

  case 111: /* arguments: argument  */
#line 1176 "parser.y"
      {
          (yyval.arg_list) = new ArgList();
          (yyval.arg_list)->args.push_back(*(yyvsp[0].arg));
          delete (yyvsp[0].arg);
      }
#line 2730 "parser.tab.c"
    break;

  case 112: /* argument: IDENTIFIER ':' expression  */
#line 1185 "parser.y"
      {
          (yyval.arg) = new ArgNode();
          (yyval.arg)->label = (yyvsp[-2].str_val);
          (yyval.arg)->place = (yyvsp[0].expr)->place;
          (yyval.arg)->type = (yyvsp[0].expr)->type;
          free((yyvsp[-2].str_val));
          delete (yyvsp[0].expr);
      }
#line 2743 "parser.tab.c"
    break;

  case 113: /* argument: expression  */
#line 1194 "parser.y"
      {
          (yyval.arg) = new ArgNode();
          (yyval.arg)->label = "";
          (yyval.arg)->place = (yyvsp[0].expr)->place;
          (yyval.arg)->type = (yyvsp[0].expr)->type;
          delete (yyvsp[0].expr);
      }
#line 2755 "parser.tab.c"
    break;


#line 2759 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1203 "parser.y"


void yyerror(const char* s) {
    g_compiler.reportSyntaxError(yylineno, std::string(s) + " near '" + yytext + "'");
}
