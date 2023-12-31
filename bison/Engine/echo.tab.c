
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "echo.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

extern int yylex();
void yyerror(char *s);


typedef struct VarNode {
    char* name;
    struct VarNode* next;
} VarNode;

VarNode* varList = NULL;


int varExists(const char* name); // Function prototype
void addVar(const char* name);   // Function prototype

int variable_count = 0;
int statement_count = 0;
int function_count = 0;
int array_count = 0;



/* Line 189 of yacc.c  */
#line 101 "echo.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     EQUALS = 258,
     OR_OP = 259,
     AND_OP = 260,
     NOT_EQUAL = 261,
     EQUALS_EQUALS = 262,
     GREATER_THAN_EQUAL = 263,
     GREATER_THAN = 264,
     LESS_THAN_EQUAL = 265,
     LESS_THAN = 266,
     MINUS = 267,
     PLUS = 268,
     MOD = 269,
     DIV = 270,
     MULT = 271,
     IMPORT = 272,
     PRINT = 273,
     VAR = 274,
     RETURN = 275,
     FUNCTION = 276,
     IF = 277,
     ELSE = 278,
     WHILE = 279,
     MAIN = 280,
     END_PROGRAM = 281,
     FOR = 282,
     PRE = 283,
     POST = 284,
     BODY = 285,
     ALWAYS = 286,
     BREAK = 287,
     INPUT_OP = 288,
     NOT_OP = 289,
     INCREMENT = 290,
     DECREMENT = 291,
     OPEN_PAREN = 292,
     CLOSE_PAREN = 293,
     LBRACKET = 294,
     RBRACKET = 295,
     LBRACE = 296,
     RBRACE = 297,
     SEMICOLON = 298,
     COMMA = 299,
     INVERTED_COMMA = 300,
     DOUBLE_QUOTE = 301,
     COLON = 302,
     BODY_START = 303,
     BODY_END = 304,
     STRING_LITERAL = 305,
     IDENTIFIER = 306,
     PATH = 307,
     TYPE = 308,
     NUMBER = 309,
     SINGLE_LINE_COMMENT_START = 310,
     MULTI_LINE_COMMENT_START = 311,
     MULTI_LINE_COMMENT_END = 312,
     ARRAY_INIT = 313
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 28 "echo.y"

    char *str;
    int num;
    // Other types as needed



/* Line 214 of yacc.c  */
#line 203 "echo.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 215 "echo.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   589

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNRULES -- Number of states.  */
#define YYNSTATES  219

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    38,
      44,    50,    57,    61,    63,    67,    69,    73,    79,    86,
      90,    95,    99,   108,   121,   122,   132,   136,   140,   144,
     148,   152,   156,   158,   160,   162,   167,   171,   175,   179,
     183,   187,   191,   195,   199,   203,   207,   211,   215,   219,
     223,   226,   230,   233,   236,   247,   257,   258,   262,   264,
     268,   269,   272,   274,   280,   281,   283,   287,   297,   299,
     304,   306,   309,   311,   315,   318,   321,   322,   330,   335,
     336,   341,   342,   343,   348,   349,   350,   355,   356,   357,
     362,   363,   367,   371
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      60,     0,    -1,    -1,    60,    61,    -1,    62,    -1,    63,
      -1,    64,    -1,    65,    -1,    68,    -1,    74,    -1,    69,
      -1,    70,    -1,    80,    -1,    84,    -1,    92,    -1,    90,
      -1,    91,    -1,    78,    -1,    17,    52,    -1,    18,    37,
      50,    38,    43,    -1,    18,    37,    51,    38,    43,    -1,
      51,    33,    37,    50,    38,    43,    -1,    19,    66,    43,
      -1,    67,    -1,    66,    44,    67,    -1,    51,    -1,    51,
      47,    53,    -1,    51,    47,    53,     3,    54,    -1,    51,
      47,    53,    39,    54,    40,    -1,    51,     3,    54,    -1,
      51,     3,    73,    43,    -1,    20,    73,    43,    -1,    22,
      37,    72,    38,    41,    77,    42,    71,    -1,    22,    37,
      72,    38,    41,    77,    42,    71,    23,    41,    77,    42,
      -1,    -1,    71,    23,    22,    37,    72,    38,    41,    77,
      42,    -1,    73,     7,    73,    -1,    73,     6,    73,    -1,
      73,    11,    73,    -1,    73,    10,    73,    -1,    73,     9,
      73,    -1,    73,     8,    73,    -1,    54,    -1,    50,    -1,
      51,    -1,    51,    37,    79,    38,    -1,    73,     3,    73,
      -1,    73,     4,    73,    -1,    73,     5,    73,    -1,    73,
       7,    73,    -1,    73,     6,    73,    -1,    73,    11,    73,
      -1,    73,    10,    73,    -1,    73,     9,    73,    -1,    73,
       8,    73,    -1,    73,    13,    73,    -1,    73,    12,    73,
      -1,    73,    16,    73,    -1,    73,    15,    73,    -1,    73,
      14,    73,    -1,    34,    73,    -1,    37,    73,    38,    -1,
      51,    35,    -1,    51,    36,    -1,    21,    51,    47,    53,
      37,    75,    38,    41,    77,    42,    -1,    25,    21,    47,
      53,    37,    38,    41,    77,    42,    -1,    -1,    75,    44,
      76,    -1,    76,    -1,    51,    47,    53,    -1,    -1,    77,
      61,    -1,    61,    -1,    51,    37,    79,    38,    43,    -1,
      -1,    73,    -1,    79,    44,    73,    -1,    27,    37,    81,
      82,    83,    38,    41,    77,    42,    -1,    65,    -1,    51,
       3,    73,    43,    -1,    43,    -1,    72,    43,    -1,    43,
      -1,    51,     3,    73,    -1,    51,    35,    -1,    51,    36,
      -1,    -1,    24,    11,    72,     9,    41,    85,    42,    -1,
      86,    87,    88,    89,    -1,    -1,    28,    41,    77,    42,
      -1,    -1,    -1,    30,    41,    77,    42,    -1,    -1,    -1,
      29,    41,    77,    42,    -1,    -1,    -1,    31,    41,    77,
      42,    -1,    -1,    51,    35,    43,    -1,    51,    36,    43,
      -1,    32,    43,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    56,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    77,    81,
      82,    86,    90,    94,    95,    99,   109,   119,   129,   139,
     152,   158,   164,   167,   172,   173,   179,   180,   181,   182,
     183,   184,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   212,   216,   221,   222,   223,   227,
     230,   231,   232,   236,   241,   243,   244,   248,   254,   255,
     256,   260,   261,   265,   266,   267,   268,   272,   278,   284,
     285,   286,   289,   290,   291,   294,   295,   296,   299,   300,
     301,   305,   308,   311
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EQUALS", "OR_OP", "AND_OP", "NOT_EQUAL",
  "EQUALS_EQUALS", "GREATER_THAN_EQUAL", "GREATER_THAN", "LESS_THAN_EQUAL",
  "LESS_THAN", "MINUS", "PLUS", "MOD", "DIV", "MULT", "IMPORT", "PRINT",
  "VAR", "RETURN", "FUNCTION", "IF", "ELSE", "WHILE", "MAIN",
  "END_PROGRAM", "FOR", "PRE", "POST", "BODY", "ALWAYS", "BREAK",
  "INPUT_OP", "NOT_OP", "INCREMENT", "DECREMENT", "OPEN_PAREN",
  "CLOSE_PAREN", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "SEMICOLON",
  "COMMA", "INVERTED_COMMA", "DOUBLE_QUOTE", "COLON", "BODY_START",
  "BODY_END", "STRING_LITERAL", "IDENTIFIER", "PATH", "TYPE", "NUMBER",
  "SINGLE_LINE_COMMENT_START", "MULTI_LINE_COMMENT_START",
  "MULTI_LINE_COMMENT_END", "ARRAY_INIT", "$accept", "program",
  "statement", "import_statement", "print_statement", "input_statement",
  "var_declaration", "var_declaration_list", "var_decl",
  "assignment_statement", "return_statement", "conditional_statement",
  "else_if_clauses", "condition", "expression", "function_declaration",
  "param_list", "param", "function_body", "function_call_statement",
  "argument_list", "for_statement", "for_init", "for_condition",
  "for_increment", "while_statement", "while_body", "pre_block",
  "body_block", "post_block", "always_block", "increment_statement",
  "decrement_statement", "break_statement", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    62,    63,
      63,    64,    65,    66,    66,    67,    67,    67,    67,    67,
      68,    69,    70,    70,    71,    71,    72,    72,    72,    72,
      72,    72,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    74,    74,    75,    75,    75,    76,
      77,    77,    77,    78,    79,    79,    79,    80,    81,    81,
      81,    82,    82,    83,    83,    83,    83,    84,    85,    86,
      86,    86,    87,    87,    87,    88,    88,    88,    89,    89,
      89,    90,    91,    92
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     5,
       5,     6,     3,     1,     3,     1,     3,     5,     6,     3,
       4,     3,     8,    12,     0,     9,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     2,     2,    10,     9,     0,     3,     1,     3,
       0,     2,     1,     5,     0,     1,     3,     9,     1,     4,
       1,     2,     1,     3,     2,     2,     0,     7,     4,     0,
       4,     0,     0,     4,     0,     0,     4,     0,     0,     4,
       0,     3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
      10,    11,     9,    17,    12,    13,    15,    16,    14,    18,
       0,    25,     0,    23,     0,     0,    43,    44,    42,     0,
       0,     0,     0,     0,     0,   103,     0,     0,     0,     0,
      74,     0,     0,     0,     0,    22,     0,    60,     0,    62,
      63,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,    80,     0,    78,     0,     0,     0,   101,   102,
      75,     0,     0,     0,    29,    26,    24,    61,     0,    46,
      47,    48,    50,    49,    54,    53,    52,    51,    56,    55,
      59,    58,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,    86,    30,     0,     0,
       0,    19,    20,     0,     0,    45,    66,    70,    50,    49,
      54,    53,    52,    51,    89,     0,     0,    81,     0,     0,
       0,    73,    76,    27,     0,     0,     0,    68,    72,     0,
       0,     0,    92,     0,    79,     0,    84,    85,     0,    21,
      28,     0,     0,     0,    34,    71,    70,    87,     0,    95,
      70,    83,    70,    69,    70,    67,    32,     0,    70,     0,
      98,     0,     0,     0,     0,    90,     0,    70,     0,    88,
      65,    77,    64,     0,    70,    93,     0,    70,     0,     0,
      96,     0,     0,    33,    99,     0,    70,     0,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   158,    15,    16,    17,    18,    32,    33,    19,
      20,    21,   186,    78,    79,    22,   156,   157,   159,    23,
      91,    24,    85,   126,   149,    25,   161,   162,   179,   190,
     199,    26,    27,    28
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -42
static const yytype_int16 yypact[] =
{
     -42,    55,   -42,   -11,     6,     5,    71,    35,    13,    96,
      88,    80,    75,    48,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
      53,     0,     9,   -42,    71,    71,   -42,   109,   -42,     2,
      76,    71,    71,    77,    59,   -42,    71,    90,   105,   107,
      71,   116,   118,   103,   106,   -42,     5,   527,   214,   -42,
     -42,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,   -42,   110,   122,   541,
     153,   112,   -42,   165,   -42,   469,    85,   120,   -42,   -42,
     527,   -10,   123,   130,   -42,     1,   -42,   -42,    -6,   527,
     553,   564,   573,   573,   184,   184,   184,   184,    21,    21,
     -42,   -42,   -42,   143,   140,    71,    71,    71,    71,    71,
      71,   141,   147,    71,   -42,   142,   136,   -42,   150,   146,
      71,   -42,   -42,   139,   148,   -42,   152,   446,    11,   223,
     163,   470,   478,   486,   166,   169,   126,   -42,   117,   171,
     161,   -42,   527,   -42,   172,   164,    -5,   -42,   -42,   226,
     173,   198,   183,   174,   -42,    71,   -42,   -42,   200,   -42,
     -42,   189,   208,   152,   -42,   -42,   446,   -42,   213,   227,
     446,   527,   446,   -42,   446,   -42,   232,   254,   446,   216,
     228,   270,   298,   314,     7,   -42,   342,   446,   219,   -42,
     -42,   -42,   -42,   225,   446,   -42,   358,   446,    71,   386,
     -42,   402,   229,   -42,   -42,   222,   446,   430,   -42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -42,   -42,    -1,   -42,   -42,   -42,   220,   -42,   209,   -42,
     -42,   -42,   -42,   -41,    -4,   -42,   -42,    97,   -33,   -42,
     221,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,   -42,   -42
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -42
static const yytype_int16 yytable[] =
{
      14,    80,    39,    53,   133,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    67,
      68,    69,    70,    71,    72,    73,    74,    75,   129,   203,
      57,    58,   135,   172,   130,    73,    74,    75,   130,   173,
     134,    29,    86,    30,   125,    76,    90,    54,   204,   -37,
      41,    46,    55,    56,   -37,     2,    31,    90,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     3,     4,     5,     6,     7,     8,     5,     9,
      10,    47,    11,    48,    49,    50,    40,    12,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    82,    51,    52,    34,    13,    42,    35,    43,
      83,   138,   139,   140,   141,   142,   143,    44,    45,   146,
     165,    36,    37,    77,    81,    38,   152,    87,   127,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,   187,    59,    60,    61,   191,    88,   192,
      89,   193,   166,   167,    92,   196,    93,    94,   175,    95,
     114,   181,   121,   113,   206,   122,   131,   212,   123,   164,
     128,   209,   -41,   132,   211,    71,    72,    73,    74,    75,
     136,   137,   144,   217,   145,   147,   175,   148,   150,   151,
     175,   175,   175,   153,   160,   175,    71,    72,    73,    74,
      75,   -41,   154,   155,   169,   175,   -41,   163,   175,   168,
     175,   171,   170,   178,   176,   180,   175,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    67,    68,    69,    70,    71,    72,    73,    74,    75,
     177,   182,   183,     3,     4,     5,     6,     7,     8,   184,
       9,    10,    97,    11,   188,   194,   189,   197,    12,   198,
     207,   -36,   208,   216,    84,    96,   -36,   215,   174,     0,
     185,     3,     4,     5,     6,     7,     8,    13,     9,    10,
       0,    11,    98,     0,     0,     0,    12,     3,     4,     5,
       6,     7,     8,     0,     9,    10,   195,    11,     0,     0,
       0,     0,    12,     0,     0,    13,     0,     0,     0,     0,
       0,     0,   200,     0,     0,     3,     4,     5,     6,     7,
       8,    13,     9,    10,     0,    11,     0,     0,     0,     0,
      12,     3,     4,     5,     6,     7,     8,     0,     9,    10,
     201,    11,     0,     0,     0,     0,    12,     0,     0,    13,
       0,     0,     0,     0,     0,     0,   202,     0,     0,     3,
       4,     5,     6,     7,     8,    13,     9,    10,     0,    11,
       0,     0,     0,     0,    12,     3,     4,     5,     6,     7,
       8,     0,     9,    10,   205,    11,     0,     0,     0,     0,
      12,     0,     0,    13,     0,     0,     0,     0,     0,     0,
     210,     0,     0,     3,     4,     5,     6,     7,     8,    13,
       9,    10,     0,    11,     0,     0,     0,     0,    12,     3,
       4,     5,     6,     7,     8,     0,     9,    10,   213,    11,
       0,     0,     0,     0,    12,     0,     0,    13,     0,     0,
       0,     0,     0,     0,   214,     0,     0,     3,     4,     5,
       6,     7,     8,    13,     9,    10,     0,    11,     0,     0,
       0,     0,    12,     3,     4,     5,     6,     7,     8,     0,
       9,    10,   218,    11,     0,     0,     0,     0,    12,   -40,
       0,    13,    71,    72,    73,    74,    75,   -39,     0,     0,
      71,    72,    73,    74,    75,   -38,     0,    13,    71,    72,
      73,    74,    75,    34,     0,     0,    35,     0,   -40,     0,
       0,     0,   124,   -40,     0,     0,   -39,     0,     0,    36,
      37,   -39,     0,    38,   -38,     0,     0,     0,     0,   -38,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    62,    63,    64,   115,   116,   117,
     118,   119,   120,    71,    72,    73,    74,    75,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    67,    68,    69,    70,    71,    72,    73,    74,    75
};

static const yytype_int16 yycheck[] =
{
       1,    42,     6,     3,     3,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    38,    22,
      34,    35,    38,    38,    44,    14,    15,    16,    44,    44,
      39,    52,    46,    37,    85,    43,    50,    47,    41,    38,
      37,     3,    43,    44,    43,     0,    51,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    17,    18,    19,    20,    21,    22,    19,    24,
      25,    33,    27,    35,    36,    37,    51,    32,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    43,    50,    51,    34,    51,    11,    37,    21,
      51,   115,   116,   117,   118,   119,   120,    37,    43,   123,
       3,    50,    51,    47,    47,    54,   130,    37,    43,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,   176,    35,    36,    37,   180,    43,   182,
      43,   184,    35,    36,    38,   188,    38,    54,   159,    53,
      38,   165,     9,    53,   197,    53,    43,   208,     3,    43,
      50,   204,     9,    43,   207,    12,    13,    14,    15,    16,
      37,    41,    41,   216,    37,    43,   187,    51,    38,    43,
     191,   192,   193,    54,    28,   196,    12,    13,    14,    15,
      16,    38,    54,    51,    43,   206,    43,    38,   209,    38,
     211,    47,    40,    30,    41,    41,   217,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      42,    41,    53,    17,    18,    19,    20,    21,    22,    41,
      24,    25,    38,    27,    41,    23,    29,    41,    32,    31,
      41,    38,    37,    41,    44,    56,    43,    38,    42,    -1,
     173,    17,    18,    19,    20,    21,    22,    51,    24,    25,
      -1,    27,    61,    -1,    -1,    -1,    32,    17,    18,    19,
      20,    21,    22,    -1,    24,    25,    42,    27,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    17,    18,    19,    20,    21,
      22,    51,    24,    25,    -1,    27,    -1,    -1,    -1,    -1,
      32,    17,    18,    19,    20,    21,    22,    -1,    24,    25,
      42,    27,    -1,    -1,    -1,    -1,    32,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    17,
      18,    19,    20,    21,    22,    51,    24,    25,    -1,    27,
      -1,    -1,    -1,    -1,    32,    17,    18,    19,    20,    21,
      22,    -1,    24,    25,    42,    27,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    17,    18,    19,    20,    21,    22,    51,
      24,    25,    -1,    27,    -1,    -1,    -1,    -1,    32,    17,
      18,    19,    20,    21,    22,    -1,    24,    25,    42,    27,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    17,    18,    19,
      20,    21,    22,    51,    24,    25,    -1,    27,    -1,    -1,
      -1,    -1,    32,    17,    18,    19,    20,    21,    22,    -1,
      24,    25,    42,    27,    -1,    -1,    -1,    -1,    32,     9,
      -1,    51,    12,    13,    14,    15,    16,     9,    -1,    -1,
      12,    13,    14,    15,    16,     9,    -1,    51,    12,    13,
      14,    15,    16,    34,    -1,    -1,    37,    -1,    38,    -1,
      -1,    -1,    43,    43,    -1,    -1,    38,    -1,    -1,    50,
      51,    43,    -1,    54,    38,    -1,    -1,    -1,    -1,    43,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     8,     9,    10,    11,    12,    13,    14,    15,    16
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    60,     0,    17,    18,    19,    20,    21,    22,    24,
      25,    27,    32,    51,    61,    62,    63,    64,    65,    68,
      69,    70,    74,    78,    80,    84,    90,    91,    92,    52,
      37,    51,    66,    67,    34,    37,    50,    51,    54,    73,
      51,    37,    11,    21,    37,    43,     3,    33,    35,    36,
      37,    50,    51,     3,    47,    43,    44,    73,    73,    35,
      36,    37,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    43,    47,    72,    73,
      72,    47,    43,    51,    65,    81,    73,    37,    43,    43,
      73,    79,    38,    38,    54,    53,    67,    38,    79,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    53,    38,     6,     7,     8,     9,    10,
      11,     9,    53,     3,    43,    72,    82,    43,    50,    38,
      44,    43,    43,     3,    39,    38,    37,    41,    73,    73,
      73,    73,    73,    73,    41,    37,    73,    43,    51,    83,
      38,    43,    73,    54,    54,    51,    75,    76,    61,    77,
      28,    85,    86,    38,    43,     3,    35,    36,    38,    43,
      40,    47,    38,    44,    42,    61,    41,    42,    30,    87,
      41,    73,    41,    53,    41,    76,    71,    77,    41,    29,
      88,    77,    77,    77,    23,    42,    77,    41,    31,    89,
      42,    42,    42,    22,    41,    42,    77,    41,    37,    77,
      42,    77,    72,    42,    42,    38,    41,    77,    42
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:

/* Line 1455 of yacc.c  */
#line 60 "echo.y"
    { statement_count++; ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 61 "echo.y"
    { statement_count++; ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 62 "echo.y"
    { statement_count++; ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 63 "echo.y"
    { statement_count++; ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 64 "echo.y"
    { statement_count++; ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 65 "echo.y"
    { statement_count++; ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 66 "echo.y"
    { statement_count++; ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 67 "echo.y"
    { statement_count++; ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 68 "echo.y"
    { statement_count++; ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 69 "echo.y"
    { statement_count++; ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 70 "echo.y"
    { statement_count++; ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 71 "echo.y"
    { statement_count++; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 72 "echo.y"
    { statement_count++; ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 73 "echo.y"
    { statement_count++; ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 77 "echo.y"
    { printf("Import detected FROM BISON with path: %s\n", (yyvsp[(2) - (2)].str)); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 81 "echo.y"
    { printf("Print detected FROM BISON with message: %s\n", (yyvsp[(3) - (5)].str)); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 82 "echo.y"
    { printf("Print detected FROM BISON with IDENTIFIER: %s\n", (yyvsp[(3) - (5)].str)); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 86 "echo.y"
    { printf("Input detected FROM BISON for variable %s with message: %s\n", (yyvsp[(1) - (6)].str), (yyvsp[(4) - (6)].str)); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 99 "echo.y"
    { 
        if (varExists((yyvsp[(1) - (1)].str))) {
            printf("Variable collision detected for variable: %s\n", (yyvsp[(1) - (1)].str));
        } else {
            addVar((yyvsp[(1) - (1)].str));
            printf("Variable declaration detected FROM BISON: %s\n", (yyvsp[(1) - (1)].str)); 
            variable_count++; 
        }
        free((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 109 "echo.y"
    { 
        if (varExists((yyvsp[(1) - (3)].str))) {
            printf("Variable collision detected for variable: %s\n", (yyvsp[(1) - (3)].str));
        } else {
            addVar((yyvsp[(1) - (3)].str));
            printf("Variable declaration detected FROM BISON, Type: %s\n", (yyvsp[(3) - (3)].str)); free((yyvsp[(3) - (3)].str));
            variable_count++; 
        }
        free((yyvsp[(1) - (3)].str));
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 119 "echo.y"
    { 
        if (varExists((yyvsp[(1) - (5)].str))) {
            printf("Variable collision detected for variable: %s\n", (yyvsp[(1) - (5)].str));
        } else {
            addVar((yyvsp[(1) - (5)].str));
            printf("Variable declaration detected FROM BISON, Type: %s Value: %d\n", (yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].num)); 
            variable_count++; 
        }
        free((yyvsp[(1) - (5)].str));
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 129 "echo.y"
    { 
        if (varExists((yyvsp[(1) - (6)].str))) {
            printf("Variable collision detected for variable: %s\n", (yyvsp[(1) - (6)].str));
        } else {
            addVar((yyvsp[(1) - (6)].str));
            printf("Array declaration detected FROM BISON: %s of type %s with size %d\n", (yyvsp[(1) - (6)].str), (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].num)); free((yyvsp[(3) - (6)].str)); 
            variable_count++; 
        }
        free((yyvsp[(1) - (6)].str));
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 139 "echo.y"
    { 
        if (varExists((yyvsp[(1) - (3)].str))) {
            printf("Variable collision detected for variable: %s\n", (yyvsp[(1) - (3)].str));
        } else {
            addVar((yyvsp[(1) - (3)].str));
            printf("Variable assignment detected FROM BISON: %s = %d\n", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].num)); 
            variable_count++; 
        }
        free((yyvsp[(1) - (3)].str));
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 152 "echo.y"
    {
        printf("Assignment detected FROM BISON: %s = <expression>\n", (yyvsp[(1) - (4)].str));
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 158 "echo.y"
    {
        printf("Return statement detected FROM BISON with <expression>\n");
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 164 "echo.y"
    {
        printf("If with Else-If(s) statement detected FROM BISON.\n");
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 167 "echo.y"
    {
        printf("If with Else-If(s) and Else statement detected FROM BISON.\n");
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 173 "echo.y"
    {
        printf("Else-If clause detected FROM BISON.\n");
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 187 "echo.y"
    { printf("%d", (yyvsp[(1) - (1)].num)); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 212 "echo.y"
    {
        printf("Function %s with return type %s declared.\n", (yyvsp[(2) - (10)].str), (yyvsp[(4) - (10)].str));
        free((yyvsp[(2) - (10)].str)); free((yyvsp[(4) - (10)].str)); function_count++;
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 216 "echo.y"
    {
		printf("Main Function detected \n"); function_count++;
	;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 227 "echo.y"
    { printf("Parameter: %s, Type: %s\n", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)); free((yyvsp[(1) - (3)].str)); free((yyvsp[(3) - (3)].str)); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 236 "echo.y"
    {
        printf("Function call detected FROM BISON: %s\n", (yyvsp[(1) - (5)].str));
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 248 "echo.y"
    {
        printf("For loop detected FROM BISON.\n");
    ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 272 "echo.y"
    {
        printf("While loop detected FROM BISON.\n");
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 285 "echo.y"
    { printf("Pre block detected FROM BISON.\n"); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 290 "echo.y"
    { printf("Body block detected FROM BISON.\n"); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 295 "echo.y"
    { printf("Post block detected FROM BISON.\n"); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 300 "echo.y"
    { printf("Always block detected FROM BISON.\n"); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 305 "echo.y"
    { printf("Increment detected FROM BISON: %s++\n", (yyvsp[(1) - (3)].str)); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 308 "echo.y"
    { printf("Decrement detected FROM BISON: %s--\n", (yyvsp[(1) - (3)].str)); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 311 "echo.y"
    { printf("Break Statement Detected. \n"); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2043 "echo.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 313 "echo.y"


int varExists(const char* name) {
    VarNode* current = varList;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return 1;  // Variable exists
        }
        current = current->next;
    }
    return 0;  // Variable does not exist
}

void addVar(const char* name) {
    VarNode* newNode = (VarNode*) malloc(sizeof(VarNode));
    newNode->name = strdup(name);
    newNode->next = varList;
    varList = newNode;
}

void yyerror(char *s) {
    fprintf(stderr, "error: %s\n", s);
}

void freeVarList() {
    VarNode* current = varList;
    while (current != NULL) {
        VarNode* temp = current;
        current = current->next;
        free(temp->name);
        free(temp);
    }
}

int main() {
    printf("Starting the parser.\n");
    yyparse();
	printf("\nCounts:\n");
    printf("Variables: %d\n", variable_count);
    printf("Statements: %d\n", statement_count);
    printf("Functions: %d\n", function_count);
    printf("Arrays: %d\n", array_count);
	freeVarList();
    return 0;
}

