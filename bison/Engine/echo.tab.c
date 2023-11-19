
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


typedef enum { INT_TYPE, FLOAT_TYPE, CHAR_TYPE, DOUBLE_TYPE, STRING_TYPE, ARRAY_TYPE, BOOL_TYPE } VarType;

typedef union {
    int intValue;
    float floatValue;
    char charValue;
    double doubleValue;
    char* stringValue;
    bool boolValue;
} VarValue;

typedef struct VarNode {
    char* name;
    VarValue value;
    VarType type;
    struct VarNode* next;
} VarNode;

typedef struct {
    VarValue value;
    VarType type;
} ExprValue;

VarNode* varList = NULL;

int varExists(const char* name); // Function prototype
void addVar(const char* name, VarValue* value, VarType type);   // Function prototype
VarType determineType(const char* typeStr);
VarValue getVarValue(const char* name);
void printVarValue(const char* name);
VarNode* findVarNode(const char* name);
VarType mapIntToVarType(int typeInt);
void freeVarValue(VarValue *value, VarType type);


int variable_count = 0;
int statement_count = 0;
int function_count = 0;
int array_count = 0;




/* Line 189 of yacc.c  */
#line 126 "echo.tab.c"

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
     DOUBLE = 305,
     FLOAT = 306,
     INTEGER = 307,
     BOOL = 308,
     CHAR_LITERAL = 309,
     STRING_LITERAL = 310,
     IDENTIFIER = 311,
     PATH = 312,
     TYPE = 313,
     SINGLE_LINE_COMMENT_START = 314,
     MULTI_LINE_COMMENT_START = 315,
     MULTI_LINE_COMMENT_END = 316,
     ARRAY_INIT = 317,
     END = 318
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 53 "echo.y"

    char *str;
    int num;
	char charValue;
	float floatValue;
	double doubleValue;
    bool boolValue;

	struct {
        union {
            int intValue;
            float floatValue;
            char charValue;
            double doubleValue;
            char* stringValue;
            bool boolValue;
        } value;
        int type;
    } exprValue;



/* Line 214 of yacc.c  */
#line 248 "echo.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 260 "echo.tab.c"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   589

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNRULES -- Number of states.  */
#define YYNSTATES  230

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      40,    46,    52,    59,    63,    65,    69,    71,    75,    81,
      88,    92,    94,    96,    98,   100,   102,   107,   111,   120,
     133,   134,   144,   148,   152,   156,   160,   164,   168,   170,
     172,   174,   176,   178,   180,   182,   187,   191,   195,   199,
     203,   207,   211,   215,   219,   223,   227,   231,   235,   239,
     243,   246,   250,   253,   256,   267,   277,   278,   282,   284,
     288,   289,   292,   294,   300,   301,   303,   307,   317,   319,
     324,   326,   329,   331,   335,   338,   341,   342,   350,   355,
     356,   361,   362,   363,   368,   369,   370,   375,   376,   377,
     382,   383,   387,   391,   394
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      65,     0,    -1,    -1,    65,    66,    -1,    99,    -1,    67,
      -1,    68,    -1,    69,    -1,    70,    -1,    74,    -1,    80,
      -1,    75,    -1,    76,    -1,    86,    -1,    90,    -1,    98,
      -1,    96,    -1,    97,    -1,    84,    -1,    17,    57,    -1,
      18,    37,    55,    38,    43,    -1,    18,    37,    56,    38,
      43,    -1,    56,    33,    37,    55,    38,    43,    -1,    19,
      71,    43,    -1,    72,    -1,    71,    44,    72,    -1,    56,
      -1,    56,    47,    58,    -1,    56,    47,    58,     3,    73,
      -1,    56,    47,    58,    39,    52,    40,    -1,    56,     3,
      73,    -1,    52,    -1,    51,    -1,    55,    -1,    54,    -1,
      50,    -1,    56,     3,    79,    43,    -1,    20,    79,    43,
      -1,    22,    37,    78,    38,    41,    83,    42,    77,    -1,
      22,    37,    78,    38,    41,    83,    42,    77,    23,    41,
      83,    42,    -1,    -1,    77,    23,    22,    37,    78,    38,
      41,    83,    42,    -1,    79,     7,    79,    -1,    79,     6,
      79,    -1,    79,    11,    79,    -1,    79,    10,    79,    -1,
      79,     9,    79,    -1,    79,     8,    79,    -1,    52,    -1,
      51,    -1,    55,    -1,    54,    -1,    50,    -1,    53,    -1,
      56,    -1,    56,    37,    85,    38,    -1,    79,     3,    79,
      -1,    79,     4,    79,    -1,    79,     5,    79,    -1,    79,
       7,    79,    -1,    79,     6,    79,    -1,    79,    11,    79,
      -1,    79,    10,    79,    -1,    79,     9,    79,    -1,    79,
       8,    79,    -1,    79,    13,    79,    -1,    79,    12,    79,
      -1,    79,    16,    79,    -1,    79,    15,    79,    -1,    79,
      14,    79,    -1,    34,    79,    -1,    37,    79,    38,    -1,
      56,    35,    -1,    56,    36,    -1,    21,    56,    47,    58,
      37,    81,    38,    41,    83,    42,    -1,    25,    21,    47,
      58,    37,    38,    41,    83,    42,    -1,    -1,    81,    44,
      82,    -1,    82,    -1,    56,    47,    58,    -1,    -1,    83,
      66,    -1,    66,    -1,    56,    37,    85,    38,    43,    -1,
      -1,    79,    -1,    85,    44,    79,    -1,    27,    37,    87,
      88,    89,    38,    41,    83,    42,    -1,    70,    -1,    56,
       3,    79,    43,    -1,    43,    -1,    78,    43,    -1,    43,
      -1,    56,     3,    79,    -1,    56,    35,    -1,    56,    36,
      -1,    -1,    24,    11,    78,     9,    41,    91,    42,    -1,
      92,    93,    94,    95,    -1,    -1,    28,    41,    83,    42,
      -1,    -1,    -1,    30,    41,    83,    42,    -1,    -1,    -1,
      29,    41,    83,    42,    -1,    -1,    -1,    31,    41,    83,
      42,    -1,    -1,    56,    35,    43,    -1,    56,    36,    43,
      -1,    32,    43,    -1,    63,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   103,   104,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   125,
     129,   130,   134,   138,   142,   143,   147,   155,   167,   199,
     209,   253,   256,   259,   262,   265,   271,   339,   345,   348,
     353,   354,   360,   361,   362,   363,   364,   365,   368,   372,
     376,   380,   384,   388,   392,   428,   429,   430,   434,   438,
     442,   446,   447,   448,   449,   450,   462,   475,   488,   510,
     523,   528,   529,   550,   572,   576,   581,   582,   583,   587,
     590,   591,   592,   596,   601,   603,   604,   608,   614,   615,
     616,   620,   621,   625,   626,   627,   628,   632,   638,   644,
     645,   646,   649,   650,   651,   654,   655,   656,   659,   660,
     661,   665,   686,   707,   710
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
  "BODY_END", "DOUBLE", "FLOAT", "INTEGER", "BOOL", "CHAR_LITERAL",
  "STRING_LITERAL", "IDENTIFIER", "PATH", "TYPE",
  "SINGLE_LINE_COMMENT_START", "MULTI_LINE_COMMENT_START",
  "MULTI_LINE_COMMENT_END", "ARRAY_INIT", "END", "$accept", "program",
  "statement", "import_statement", "print_statement", "input_statement",
  "var_declaration", "var_declaration_list", "var_decl", "value",
  "assignment_statement", "return_statement", "conditional_statement",
  "else_if_clauses", "condition", "expression", "function_declaration",
  "param_list", "param", "function_body", "function_call_statement",
  "argument_list", "for_statement", "for_init", "for_condition",
  "for_increment", "while_statement", "while_body", "pre_block",
  "body_block", "post_block", "always_block", "increment_statement",
  "decrement_statement", "break_statement", "end_of_the_line", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    67,
      68,    68,    69,    70,    71,    71,    72,    72,    72,    72,
      72,    73,    73,    73,    73,    73,    74,    75,    76,    76,
      77,    77,    78,    78,    78,    78,    78,    78,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    80,    80,    81,    81,    81,    82,
      83,    83,    83,    84,    85,    85,    85,    86,    87,    87,
      87,    88,    88,    89,    89,    89,    89,    90,    91,    92,
      92,    92,    93,    93,    93,    94,    94,    94,    95,    95,
      95,    96,    97,    98,    99
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       5,     5,     6,     3,     1,     3,     1,     3,     5,     6,
       3,     1,     1,     1,     1,     1,     4,     3,     8,    12,
       0,     9,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     2,     2,    10,     9,     0,     3,     1,     3,
       0,     2,     1,     5,     0,     1,     3,     9,     1,     4,
       1,     2,     1,     3,     2,     2,     0,     7,     4,     0,
       4,     0,     0,     4,     0,     0,     4,     0,     0,     4,
       0,     3,     3,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,   114,     0,     4,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     5,     6,     7,
       8,     9,    11,    12,    10,    18,    13,    14,    16,    17,
      15,    19,     0,    26,     0,    24,     0,     0,    52,    49,
      48,    53,    51,    50,    54,     0,     0,     0,     0,     0,
       0,   113,     0,     0,     0,     0,    84,     0,     0,     0,
       0,    23,     0,    70,     0,    72,    73,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,    90,     0,
      88,     0,     0,     0,   111,   112,    85,     0,     0,     0,
      35,    32,    31,    34,    33,    30,    27,    25,    71,     0,
      56,    57,    58,    60,    59,    64,    63,    62,    61,    66,
      65,    69,    68,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,     0,    96,    36,     0,
       0,     0,    20,    21,     0,     0,    55,    76,    80,    60,
      59,    64,    63,    62,    61,    99,     0,     0,    91,     0,
       0,     0,    83,    86,    28,     0,     0,     0,    78,    82,
       0,     0,     0,   102,     0,    89,     0,    94,    95,     0,
      22,    29,     0,     0,     0,    40,    81,    80,    97,     0,
     105,    80,    93,    80,    79,    80,    77,    38,     0,    80,
       0,   108,     0,     0,     0,     0,   100,     0,    80,     0,
      98,    75,    87,    74,     0,    80,   103,     0,    80,     0,
       0,   106,     0,     0,    39,   109,     0,    80,     0,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   169,    17,    18,    19,    20,    34,    35,   105,
      21,    22,    23,   197,    84,    85,    24,   167,   168,   170,
      25,    97,    26,    91,   137,   160,    27,   172,   173,   190,
     201,   210,    28,    29,    30,     3
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -168
static const yytype_int16 yypact[] =
{
     -26,  -168,    59,  -168,  -168,    -8,    16,    29,   473,    34,
      79,    99,    96,    81,    83,    19,  -168,  -168,  -168,  -168,
    -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,
    -168,  -168,   -13,     0,    70,  -168,   473,   473,  -168,  -168,
    -168,  -168,  -168,  -168,    -1,     2,    80,   473,   473,    82,
      63,  -168,   473,    93,    88,    90,   473,   112,   113,    57,
      76,  -168,    29,   527,   395,  -168,  -168,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,  -168,   100,   123,   541,   154,   106,  -168,   162,
    -168,   465,    89,   111,  -168,  -168,   527,   -17,   126,   128,
    -168,  -168,  -168,  -168,  -168,  -168,     1,  -168,  -168,   -15,
     527,   553,   564,   573,   573,   252,   252,   252,   252,    73,
      73,  -168,  -168,  -168,   136,   134,   473,   473,   473,   473,
     473,   473,   143,   137,   473,  -168,   144,   138,  -168,   151,
     147,   473,  -168,  -168,    57,   140,  -168,   139,   357,   406,
     415,   423,   455,   463,   471,   169,   160,   133,  -168,    22,
     166,   156,  -168,   527,  -168,   172,   175,    -5,  -168,  -168,
     135,   178,   181,   194,   184,  -168,   473,  -168,  -168,   186,
    -168,  -168,   170,   188,   139,  -168,  -168,   357,  -168,   197,
     201,   357,   527,   357,  -168,   357,  -168,   218,   161,   357,
     202,   213,   189,   215,   231,    -3,  -168,   257,   357,   205,
    -168,  -168,  -168,  -168,   217,   357,  -168,   273,   357,   473,
     299,  -168,   315,   221,  -168,  -168,   219,   357,   341,  -168
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -168,  -168,    -2,  -168,  -168,  -168,   211,  -168,   200,   125,
    -168,  -168,  -168,  -168,   -47,    -6,  -168,  -168,    86,  -167,
    -168,   216,  -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,
    -168,  -168,  -168,  -168,  -168,  -168
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -48
static const yytype_int16 yytable[] =
{
      16,    86,    45,    59,   144,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,   214,
     198,   140,    52,   146,   202,   176,   203,   141,   204,   141,
      63,    64,   207,   183,    65,    66,    67,     1,   215,   184,
     145,   217,    57,    58,   136,    82,    92,    60,   220,    31,
      96,   222,    53,    32,    54,    55,    56,   177,   178,     4,
     228,    96,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,     5,     6,     7,     8,
       9,    10,     7,    11,    12,    33,    13,    79,    80,    81,
      46,    14,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    88,   100,   101,   102,
      48,   103,   104,    61,    62,    15,    47,    49,    50,    89,
     149,   150,   151,   152,   153,   154,    51,    83,   157,    87,
      93,    94,   138,    95,   106,   163,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      98,    99,     5,     6,     7,     8,     9,    10,   124,    11,
      12,   125,    13,   132,   133,   134,   139,    14,   186,   142,
     192,   143,   223,   147,   156,   148,   175,   185,     5,     6,
       7,     8,     9,    10,   155,    11,    12,   158,    13,   161,
     162,    15,   165,    14,   159,   166,   186,   171,   174,   180,
     186,   186,   186,   206,   179,   186,     5,     6,     7,     8,
       9,    10,   181,    11,    12,   186,    13,    15,   186,   187,
     186,    14,   182,   188,   189,   191,   186,   193,   194,   195,
     200,   211,     5,     6,     7,     8,     9,    10,   199,    11,
      12,   205,    13,   208,   209,    15,   218,    14,     5,     6,
       7,     8,     9,    10,   219,    11,    12,   212,    13,   226,
     227,    90,   107,    14,    77,    78,    79,    80,    81,   164,
     196,    15,     0,   213,     5,     6,     7,     8,     9,    10,
       0,    11,    12,   109,    13,     0,     0,    15,     0,    14,
       5,     6,     7,     8,     9,    10,     0,    11,    12,   216,
      13,     0,     0,     0,     0,    14,     0,     0,     0,     0,
       0,     0,     0,    15,     0,   221,     5,     6,     7,     8,
       9,    10,     0,    11,    12,     0,    13,     0,     0,    15,
       0,    14,     5,     6,     7,     8,     9,    10,     0,    11,
      12,   224,    13,     0,     0,     0,     0,    14,     0,     0,
       0,     0,     0,     0,     0,    15,     0,   225,     5,     6,
       7,     8,     9,    10,     0,    11,    12,     0,    13,     0,
       0,    15,     0,    14,     5,     6,     7,     8,     9,    10,
       0,    11,    12,   229,    13,     0,     0,     0,     0,    14,
       0,     0,     0,     0,     0,     0,     0,    15,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,     0,    15,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    73,    74,    75,    76,    77,    78,    79,
      80,    81,   -47,   108,     0,    77,    78,    79,    80,    81,
       0,     0,     0,     0,   -43,     0,     0,     0,     0,   -43,
       0,     0,     0,   -42,     0,     0,     0,     0,   -42,     0,
       0,   -47,     0,     0,   -46,     0,   -47,    77,    78,    79,
      80,    81,   -45,     0,     0,    77,    78,    79,    80,    81,
     -44,     0,     0,    77,    78,    79,    80,    81,     0,     0,
       0,     0,     0,   -46,     0,     0,     0,     0,   -46,    36,
       0,   -45,    37,     0,     0,     0,   -45,    36,   135,   -44,
      37,     0,     0,     0,   -44,    38,    39,    40,    41,    42,
      43,    44,     0,    38,    39,    40,    41,    42,    43,    44,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    68,    69,    70,   126,   127,   128,
     129,   130,   131,    77,    78,    79,    80,    81,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    73,    74,    75,    76,    77,    78,    79,    80,    81
};

static const yytype_int16 yycheck[] =
{
       2,    48,     8,     3,     3,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    22,
     187,    38,     3,    38,   191,     3,   193,    44,   195,    44,
      36,    37,   199,    38,    35,    36,    37,    63,    41,    44,
      39,   208,    55,    56,    91,    43,    52,    47,   215,    57,
      56,   218,    33,    37,    35,    36,    37,    35,    36,     0,
     227,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    17,    18,    19,    20,
      21,    22,    19,    24,    25,    56,    27,    14,    15,    16,
      56,    32,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    43,    50,    51,    52,
      11,    54,    55,    43,    44,    56,    37,    21,    37,    56,
     126,   127,   128,   129,   130,   131,    43,    47,   134,    47,
      37,    43,    43,    43,    58,   141,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      38,    38,    17,    18,    19,    20,    21,    22,    58,    24,
      25,    38,    27,     9,    58,     3,    55,    32,   170,    43,
     176,    43,   219,    37,    37,    41,    43,    42,    17,    18,
      19,    20,    21,    22,    41,    24,    25,    43,    27,    38,
      43,    56,    52,    32,    56,    56,   198,    28,    38,    43,
     202,   203,   204,    42,    38,   207,    17,    18,    19,    20,
      21,    22,    40,    24,    25,   217,    27,    56,   220,    41,
     222,    32,    47,    42,    30,    41,   228,    41,    58,    41,
      29,    42,    17,    18,    19,    20,    21,    22,    41,    24,
      25,    23,    27,    41,    31,    56,    41,    32,    17,    18,
      19,    20,    21,    22,    37,    24,    25,    42,    27,    38,
      41,    50,    62,    32,    12,    13,    14,    15,    16,   144,
     184,    56,    -1,    42,    17,    18,    19,    20,    21,    22,
      -1,    24,    25,    67,    27,    -1,    -1,    56,    -1,    32,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    42,
      27,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    42,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    -1,    27,    -1,    -1,    56,
      -1,    32,    17,    18,    19,    20,    21,    22,    -1,    24,
      25,    42,    27,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    42,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    -1,    27,    -1,
      -1,    56,    -1,    32,    17,    18,    19,    20,    21,    22,
      -1,    24,    25,    42,    27,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    56,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     9,    38,    -1,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    38,    -1,    -1,     9,    -1,    43,    12,    13,    14,
      15,    16,     9,    -1,    -1,    12,    13,    14,    15,    16,
       9,    -1,    -1,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    43,    34,
      -1,    38,    37,    -1,    -1,    -1,    43,    34,    43,    38,
      37,    -1,    -1,    -1,    43,    50,    51,    52,    53,    54,
      55,    56,    -1,    50,    51,    52,    53,    54,    55,    56,
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
       0,    63,    65,    99,     0,    17,    18,    19,    20,    21,
      22,    24,    25,    27,    32,    56,    66,    67,    68,    69,
      70,    74,    75,    76,    80,    84,    86,    90,    96,    97,
      98,    57,    37,    56,    71,    72,    34,    37,    50,    51,
      52,    53,    54,    55,    56,    79,    56,    37,    11,    21,
      37,    43,     3,    33,    35,    36,    37,    55,    56,     3,
      47,    43,    44,    79,    79,    35,    36,    37,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    43,    47,    78,    79,    78,    47,    43,    56,
      70,    87,    79,    37,    43,    43,    79,    85,    38,    38,
      50,    51,    52,    54,    55,    73,    58,    72,    38,    85,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    58,    38,     6,     7,     8,     9,
      10,    11,     9,    58,     3,    43,    78,    88,    43,    55,
      38,    44,    43,    43,     3,    39,    38,    37,    41,    79,
      79,    79,    79,    79,    79,    41,    37,    79,    43,    56,
      89,    38,    43,    79,    73,    52,    56,    81,    82,    66,
      83,    28,    91,    92,    38,    43,     3,    35,    36,    38,
      43,    40,    47,    38,    44,    42,    66,    41,    42,    30,
      93,    41,    79,    41,    58,    41,    82,    77,    83,    41,
      29,    94,    83,    83,    83,    23,    42,    83,    41,    31,
      95,    42,    42,    42,    22,    41,    42,    83,    41,    37,
      83,    42,    83,    78,    42,    42,    38,    41,    83,    42
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
        case 5:

/* Line 1455 of yacc.c  */
#line 108 "echo.y"
    { statement_count++; ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 109 "echo.y"
    { statement_count++; ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 110 "echo.y"
    { statement_count++; ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 111 "echo.y"
    { statement_count++; ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 112 "echo.y"
    { statement_count++; ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 113 "echo.y"
    { statement_count++; ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 114 "echo.y"
    { statement_count++; ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 115 "echo.y"
    { statement_count++; ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 116 "echo.y"
    { statement_count++; ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 117 "echo.y"
    { statement_count++; ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 118 "echo.y"
    { statement_count++; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 119 "echo.y"
    { statement_count++; ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 120 "echo.y"
    { statement_count++; ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 121 "echo.y"
    { statement_count++; ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 125 "echo.y"
    { printf("Import detected FROM BISON with path: %s\n", (yyvsp[(2) - (2)].str)); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 129 "echo.y"
    { printf("Print detected FROM BISON with message: %s\n", (yyvsp[(3) - (5)].str)); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 130 "echo.y"
    { printf("Print detected FROM BISON with IDENTIFIER: %s\n", (yyvsp[(3) - (5)].str)); printVarValue((yyvsp[(3) - (5)].str)); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 134 "echo.y"
    { printf("Input detected FROM BISON for variable %s with message: %s\n", (yyvsp[(1) - (6)].str), (yyvsp[(4) - (6)].str)); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 147 "echo.y"
    { 
        if (varExists((yyvsp[(1) - (1)].str))) {
            printf("Variable collision detected for variable: %s\n", (yyvsp[(1) - (1)].str));
        } else {
            printf("<Invalid variable declaration %s> Pls include a type. read docs for mor information.\n URL: https://www.swift.org", (yyvsp[(1) - (1)].str));
        }
        free((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 155 "echo.y"
    { 
        if (varExists((yyvsp[(1) - (3)].str))) {
            printf("Variable collision detected for variable: %s\n", (yyvsp[(1) - (3)].str));
        } else {
            VarType type = determineType((yyvsp[(3) - (3)].str));
            addVar((yyvsp[(1) - (3)].str), NULL, type); // Pass NULL as the value
            printf("Variable declaration detected FROM BISON, Type: %s\n", (yyvsp[(3) - (3)].str));
            variable_count++; 
        }
        free((yyvsp[(3) - (3)].str));
        free((yyvsp[(1) - (3)].str));
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 167 "echo.y"
    { 
        if (varExists((yyvsp[(1) - (5)].str))) {
            printf("Variable collision detected for variable: %s\n", (yyvsp[(1) - (5)].str));
        } else {
            VarType type = determineType((yyvsp[(3) - (5)].str));
            VarValue val;
            switch(type) {
                case INT_TYPE:
                    val.intValue = (yyvsp[(5) - (5)].exprValue).value.intValue;
                    break;
                case FLOAT_TYPE:
                    val.floatValue = (yyvsp[(5) - (5)].exprValue).value.floatValue;
                    break;
				case STRING_TYPE:
					val.stringValue = (yyvsp[(5) - (5)].exprValue).value.stringValue;
					break;
				case CHAR_TYPE:
					val.charValue = (yyvsp[(5) - (5)].exprValue).value.charValue;
					break;
				case DOUBLE_TYPE:
					val.doubleValue = (yyvsp[(5) - (5)].exprValue).value.doubleValue;
					break;
                case BOOL_TYPE:
                    val.boolValue = (yyvsp[(5) - (5)].exprValue).value.boolValue;
                    break;
            }
            addVar((yyvsp[(1) - (5)].str), &val, type);
            printf("Variable declaration with type %s and Variable Name: %s\n", (yyvsp[(3) - (5)].str), (yyvsp[(1) - (5)].str));
            variable_count++;
        }
        free((yyvsp[(1) - (5)].str));
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 199 "echo.y"
    { 
        if (varExists((yyvsp[(1) - (6)].str))) {
            printf("Variable collision detected for variable: %s\n", (yyvsp[(1) - (6)].str));
        } else {

            printf("Array declaration detected FROM BISON: %s of type %s with size %d\n", (yyvsp[(1) - (6)].str), (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].num)); free((yyvsp[(3) - (6)].str)); 
            variable_count++; 
        }
        free((yyvsp[(1) - (6)].str));
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 209 "echo.y"
    { 
        if (varExists((yyvsp[(1) - (3)].str))) {
            printf("Variable collision detected for variable: %s\n", (yyvsp[(1) - (3)].str));
        } else {
            VarType type;
            VarValue val;

            switch ((yyvsp[(3) - (3)].exprValue).type) {
                case INT_TYPE:
                    val.intValue = (yyvsp[(3) - (3)].exprValue).value.intValue;
                    type = INT_TYPE;
                    break;
                case FLOAT_TYPE:
                    val.floatValue = (yyvsp[(3) - (3)].exprValue).value.floatValue;
                    type = FLOAT_TYPE;
                    break;
                case CHAR_TYPE:
                    val.charValue = (yyvsp[(3) - (3)].exprValue).value.charValue;
                    type = CHAR_TYPE;
                    break;
                case DOUBLE_TYPE:
                    val.doubleValue = (yyvsp[(3) - (3)].exprValue).value.doubleValue;
                    type = DOUBLE_TYPE;
                    break;
                case STRING_TYPE:
                    val.stringValue = strdup((yyvsp[(3) - (3)].exprValue).value.stringValue);
                    type = STRING_TYPE;
                    break;
                case BOOL_TYPE:
                    val.boolValue = (yyvsp[(3) - (3)].exprValue).value.floatValue;
                    type = BOOL_TYPE;
                    break;

            }

            addVar((yyvsp[(1) - (3)].str), &val, type);
            printf("Variable declaration and assignment detected FROM BISON: %s\n", (yyvsp[(1) - (3)].str));
            variable_count++; 
        }
        free((yyvsp[(1) - (3)].str));
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 253 "echo.y"
    { 
        (yyval.exprValue).value.intValue = (yyvsp[(1) - (1)].num);
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 256 "echo.y"
    {
        (yyval.exprValue).value.floatValue = (yyvsp[(1) - (1)].floatValue);
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 259 "echo.y"
    {
        (yyval.exprValue).value.stringValue = (yyvsp[(1) - (1)].str);
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 262 "echo.y"
    {
		(yyval.exprValue).value.charValue = (yyvsp[(1) - (1)].charValue);
	;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 265 "echo.y"
    {
		(yyval.exprValue).value.doubleValue = (yyvsp[(1) - (1)].doubleValue);
	;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 271 "echo.y"
    {
        if (varExists((yyvsp[(1) - (4)].str))) {
            VarNode* var = findVarNode((yyvsp[(1) - (4)].str));
            if (var) {
                switch (var->type) {
                    case INT_TYPE:
                        if ((yyvsp[(3) - (4)].exprValue).type == INT_TYPE) {
                            var->value.intValue = (yyvsp[(3) - (4)].exprValue).value.intValue;
                        } else {
                            fprintf(stderr, "Type mismatch: Cannot assign non-integer to integer variable '%s'.\n", var->name);
                        }
                        break;

                    case FLOAT_TYPE:
                        if ((yyvsp[(3) - (4)].exprValue).type == FLOAT_TYPE) {
                            var->value.floatValue = (yyvsp[(3) - (4)].exprValue).value.floatValue;
                        } else {
                            fprintf(stderr, "Type mismatch: Cannot assign non-float to float variable '%s'.\n", var->name);
                        }
                        break;

                    case CHAR_TYPE:
                        if ((yyvsp[(3) - (4)].exprValue).type == CHAR_TYPE) {
                            var->value.charValue = (yyvsp[(3) - (4)].exprValue).value.charValue;
                        } else {
                            fprintf(stderr, "Type mismatch: Cannot assign non-char to char variable '%s'.\n", var->name);
                        }
                        break;

                    case DOUBLE_TYPE:
                        if ((yyvsp[(3) - (4)].exprValue).type == DOUBLE_TYPE) {
                            var->value.doubleValue = (yyvsp[(3) - (4)].exprValue).value.doubleValue;
                        } else {
                            fprintf(stderr, "Type mismatch: Cannot assign non-double to double variable '%s'.\n", var->name);
                        }
                        break;

                    case STRING_TYPE:
                        if ((yyvsp[(3) - (4)].exprValue).type == STRING_TYPE) {
                            free(var->value.stringValue); // Free existing string
                            var->value.stringValue = strdup((yyvsp[(3) - (4)].exprValue).value.stringValue);
                        } else {
                            fprintf(stderr, "Type mismatch: Cannot assign non-string to string variable '%s'.\n", var->name);
                        }
                        break;
                    
                    case BOOL_TYPE:
                        if((yyvsp[(3) - (4)].exprValue).type == BOOL_TYPE) {
                            var->value.boolValue = (yyvsp[(3) - (4)].exprValue).value.boolValue;
                        } else if ((yyvsp[(3) - (4)].exprValue).type == INT_TYPE) {
                            var->value.boolValue = ((yyvsp[(3) - (4)].exprValue).value.intValue != 0) ? 1 : 0;
                        } else {
                            fprintf(stderr, "Type mismatch: Cannot assign non-double to double variable '%s'.\n", var->name);
                        }

                    default:
                        fprintf(stderr, "Unsupported variable type for variable '%s'.\n", var->name);
                        break;
                }
                freeVarValue(&var->value, var->type);  
            }
        } else {
            printf("Variable not declared: %s\n", (yyvsp[(1) - (4)].str));
        }
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 339 "echo.y"
    {
        printf("Return statement detected FROM BISON with <expression>\n");
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 345 "echo.y"
    {
        printf("If with Else-If(s) statement detected FROM BISON.\n");
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 348 "echo.y"
    {
        printf("If with Else-If(s) and Else statement detected FROM BISON.\n");
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 354 "echo.y"
    {
        printf("Else-If clause detected FROM BISON.\n");
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 368 "echo.y"
    { 
		(yyval.exprValue).value.intValue = (yyvsp[(1) - (1)].num);
		(yyval.exprValue).type = INT_TYPE;
	;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 372 "echo.y"
    {
        (yyval.exprValue).value.floatValue = (yyvsp[(1) - (1)].floatValue); 
        (yyval.exprValue).type = FLOAT_TYPE;
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 376 "echo.y"
    {
        (yyval.exprValue).value.stringValue = strdup((yyvsp[(1) - (1)].str)); 
        (yyval.exprValue).type = STRING_TYPE;
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 380 "echo.y"
    {
        (yyval.exprValue).value.charValue = (yyvsp[(1) - (1)].charValue); 
        (yyval.exprValue).type = CHAR_TYPE;
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 384 "echo.y"
    {
        (yyval.exprValue).value.doubleValue = (yyvsp[(1) - (1)].doubleValue); 
        (yyval.exprValue).type = DOUBLE_TYPE;
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 388 "echo.y"
    {
        (yyval.exprValue).value.boolValue = (yyvsp[(1) - (1)].boolValue);
        (yyval.exprValue).type = BOOL_TYPE; 
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 392 "echo.y"
    {
    	VarNode* var = findVarNode((yyvsp[(1) - (1)].str));
    	if (var) {
    	    switch(var->type) {
    	        case INT_TYPE:
    	            (yyval.exprValue).value.intValue = var->value.intValue;
    	            (yyval.exprValue).type = INT_TYPE;
    	            break;
    	        case FLOAT_TYPE:
    	            (yyval.exprValue).value.floatValue = var->value.floatValue;
    	            (yyval.exprValue).type = FLOAT_TYPE;
    	            break;
    	        case CHAR_TYPE:
    	            (yyval.exprValue).value.charValue = var->value.charValue;
    	            (yyval.exprValue).type = CHAR_TYPE;
    	            break;
    	        case DOUBLE_TYPE:
    	            (yyval.exprValue).value.doubleValue = var->value.doubleValue;
    	            (yyval.exprValue).type = DOUBLE_TYPE;
    	            break;
    	        case STRING_TYPE:
    	            (yyval.exprValue).value.stringValue = strdup(var->value.stringValue);
    	            (yyval.exprValue).type = STRING_TYPE;
    	            break;
                case BOOL_TYPE:
                    (yyval.exprValue).value.boolValue = var->value.boolValue;
                    (yyval.exprValue).type = BOOL_TYPE;
    	        default:
    	            yyerror("Unsupported variable type");
    	            break;
                freeVarValue(&var->value, var->type);
    	    }
    	} else {
    	    yyerror("Undefined variable");
    	}
	;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 430 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(1) - (3)].exprValue).value.intValue || (yyvsp[(3) - (3)].exprValue).value.intValue) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 434 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(1) - (3)].exprValue).value.intValue && (yyvsp[(3) - (3)].exprValue).value.intValue) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 438 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(1) - (3)].exprValue).value.intValue == (yyvsp[(3) - (3)].exprValue).value.intValue) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 442 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(1) - (3)].exprValue).value.intValue != (yyvsp[(3) - (3)].exprValue).value.intValue) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 450 "echo.y"
    {
        if ((yyvsp[(1) - (3)].exprValue).type == INT_TYPE && (yyvsp[(3) - (3)].exprValue).type == INT_TYPE) {
            (yyval.exprValue).value.intValue = (yyvsp[(1) - (3)].exprValue).value.intValue + (yyvsp[(3) - (3)].exprValue).value.intValue;
            (yyval.exprValue).type = INT_TYPE;
        } else if (((yyvsp[(1) - (3)].exprValue).type == INT_TYPE || (yyvsp[(1) - (3)].exprValue).type == FLOAT_TYPE) &&
                   ((yyvsp[(3) - (3)].exprValue).type == INT_TYPE || (yyvsp[(3) - (3)].exprValue).type == FLOAT_TYPE)) {
            (yyval.exprValue).value.floatValue = ((yyvsp[(1) - (3)].exprValue).type == INT_TYPE ? (float)(yyvsp[(1) - (3)].exprValue).value.intValue : (yyvsp[(1) - (3)].exprValue).value.floatValue) + ((yyvsp[(3) - (3)].exprValue).type == INT_TYPE ? (float)(yyvsp[(3) - (3)].exprValue).value.intValue : (yyvsp[(3) - (3)].exprValue).value.floatValue);
            (yyval.exprValue).type = FLOAT_TYPE;
        } else {
            yyerror("Type mismatch in addition operation");
        }
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 462 "echo.y"
    {
        if ((yyvsp[(1) - (3)].exprValue).type == INT_TYPE && (yyvsp[(3) - (3)].exprValue).type == INT_TYPE) {
            (yyval.exprValue).value.intValue = (yyvsp[(1) - (3)].exprValue).value.intValue - (yyvsp[(3) - (3)].exprValue).value.intValue;
            (yyval.exprValue).type = INT_TYPE;
        } else if (((yyvsp[(1) - (3)].exprValue).type == INT_TYPE || (yyvsp[(1) - (3)].exprValue).type == FLOAT_TYPE) &&
                   ((yyvsp[(3) - (3)].exprValue).type == INT_TYPE || (yyvsp[(3) - (3)].exprValue).type == FLOAT_TYPE)) {
            (yyval.exprValue).value.floatValue = ((yyvsp[(1) - (3)].exprValue).type == INT_TYPE ? (float)(yyvsp[(1) - (3)].exprValue).value.intValue : (yyvsp[(1) - (3)].exprValue).value.floatValue) - ((yyvsp[(3) - (3)].exprValue).type == INT_TYPE ? (float)(yyvsp[(3) - (3)].exprValue).value.intValue : (yyvsp[(3) - (3)].exprValue).value.floatValue);
            (yyval.exprValue).type = FLOAT_TYPE;
        } else {
            yyerror("Type mismatch in subtraction operation");
        }
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 475 "echo.y"
    {
        if ((yyvsp[(1) - (3)].exprValue).type == INT_TYPE && (yyvsp[(3) - (3)].exprValue).type == INT_TYPE) {
            (yyval.exprValue).value.intValue = (yyvsp[(1) - (3)].exprValue).value.intValue * (yyvsp[(3) - (3)].exprValue).value.intValue;
            (yyval.exprValue).type = INT_TYPE;
        } else if (((yyvsp[(1) - (3)].exprValue).type == INT_TYPE || (yyvsp[(1) - (3)].exprValue).type == FLOAT_TYPE) &&
                   ((yyvsp[(3) - (3)].exprValue).type == INT_TYPE || (yyvsp[(3) - (3)].exprValue).type == FLOAT_TYPE)) {
            (yyval.exprValue).value.floatValue = ((yyvsp[(1) - (3)].exprValue).type == INT_TYPE ? (float)(yyvsp[(1) - (3)].exprValue).value.intValue : (yyvsp[(1) - (3)].exprValue).value.floatValue) * ((yyvsp[(3) - (3)].exprValue).type == INT_TYPE ? (float)(yyvsp[(3) - (3)].exprValue).value.intValue : (yyvsp[(3) - (3)].exprValue).value.floatValue);
            (yyval.exprValue).type = FLOAT_TYPE;
        } else {
            yyerror("Type mismatch in multiplication operation");
        }
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 488 "echo.y"
    {
        if ((yyvsp[(1) - (3)].exprValue).type == INT_TYPE && (yyvsp[(3) - (3)].exprValue).type == INT_TYPE) {
            if ((yyvsp[(3) - (3)].exprValue).value.intValue == 0) {
                yyerror("Division by zero");
                break;
            }
            (yyval.exprValue).value.intValue = (yyvsp[(1) - (3)].exprValue).value.intValue / (yyvsp[(3) - (3)].exprValue).value.intValue;
            (yyval.exprValue).type = INT_TYPE;
        } else if (((yyvsp[(1) - (3)].exprValue).type == INT_TYPE || (yyvsp[(1) - (3)].exprValue).type == FLOAT_TYPE) &&
                   ((yyvsp[(3) - (3)].exprValue).type == INT_TYPE || (yyvsp[(3) - (3)].exprValue).type == FLOAT_TYPE)) {
            float divisor = ((yyvsp[(3) - (3)].exprValue).type == INT_TYPE ? (float)(yyvsp[(3) - (3)].exprValue).value.intValue : (yyvsp[(3) - (3)].exprValue).value.floatValue);
            if (divisor == 0.0) {
                yyerror("Division by zero");
                break;
            }
            (yyval.exprValue).value.floatValue = ((yyvsp[(1) - (3)].exprValue).type == INT_TYPE ? (float)(yyvsp[(1) - (3)].exprValue).value.intValue : (yyvsp[(1) - (3)].exprValue).value.floatValue) / divisor;
            (yyval.exprValue).type = FLOAT_TYPE;
        } else {
            yyerror("Type mismatch in division operation");
        }
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 510 "echo.y"
    {
        if ((yyvsp[(1) - (3)].exprValue).type == INT_TYPE && (yyvsp[(3) - (3)].exprValue).type == INT_TYPE) {
            if ((yyvsp[(3) - (3)].exprValue).value.intValue == 0) {
                yyerror("Modulo by zero");
                break;
            }
            (yyval.exprValue).value.intValue = (yyvsp[(1) - (3)].exprValue).value.intValue % (yyvsp[(3) - (3)].exprValue).value.intValue;
            (yyval.exprValue).type = INT_TYPE;
        } else {
            yyerror("Modulo operation only valid for integers");
        }
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 523 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(2) - (2)].exprValue).value.intValue == 0) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 529 "echo.y"
    {
        printf("IDENTIFIER increment detected");
        VarNode* var = findVarNode((yyvsp[(1) - (2)].str));
        if (var) {
            switch(var->type) {
                case INT_TYPE:
                    int a;
                    a = var->value.intValue;
                    a = a + 1;
                    (yyval.exprValue).value.intValue = a;
                    (yyval.exprValue).type = INT_TYPE;
                    break;
                // You can add cases for other types if incrementing them makes sense in your language
                default:
                    yyerror("Increment operation not supported for this type");
            }
        } else {
            yyerror("Undefined variable");
        }
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 550 "echo.y"
    {
        VarNode* var = findVarNode((yyvsp[(1) - (2)].str));
        if (var) {
            switch(var->type) {
                case INT_TYPE:
                    int a;
                    a = var->value.intValue;
                    a = a - 1;
                    (yyval.exprValue).value.intValue = a;
                    break;
                // You can add cases for other types if decrementing them makes sense in your language
                default:
                    yyerror("Decrement operation not supported for this type");
            }
        } else {
            yyerror("Undefined variable");
        }
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 572 "echo.y"
    {
        printf("Function %s with return type %s declared.\n", (yyvsp[(2) - (10)].str), (yyvsp[(4) - (10)].str));
        free((yyvsp[(2) - (10)].str)); free((yyvsp[(4) - (10)].str)); function_count++;
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 576 "echo.y"
    {
		printf("Main Function detected \n"); function_count++;
	;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 587 "echo.y"
    { printf("Parameter: %s, Type: %s\n", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)); free((yyvsp[(1) - (3)].str)); free((yyvsp[(3) - (3)].str)); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 596 "echo.y"
    {
        printf("Function call detected FROM BISON: %s\n", (yyvsp[(1) - (5)].str));
    ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 608 "echo.y"
    {
        printf("For loop detected FROM BISON.\n");
    ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 632 "echo.y"
    {
        printf("While loop detected FROM BISON.\n");
    ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 645 "echo.y"
    { printf("Pre block detected FROM BISON.\n"); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 650 "echo.y"
    { printf("Body block detected FROM BISON.\n"); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 655 "echo.y"
    { printf("Post block detected FROM BISON.\n"); ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 660 "echo.y"
    { printf("Always block detected FROM BISON.\n"); ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 665 "echo.y"
    {
        printf("increament_statment detected");
        VarNode* var = findVarNode((yyvsp[(1) - (3)].str));
        if (var) {
            switch(var->type) {
                case INT_TYPE:
                    int a;
                    a = var->value.intValue;
                    a = a + 1;
                    var->value.intValue = a;
                    break;
                // You can add cases for other types if incrementing them makes sense in your language
                default:
                    yyerror("Increment operation not supported for this type");
            }
        } else {
            yyerror("Undefined variable");
        }
    ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 686 "echo.y"
    {
        printf("decrement_statement detected");
        VarNode* var = findVarNode((yyvsp[(1) - (3)].str));
        if (var) {
            switch(var->type) {
                case INT_TYPE:
                    int a;
                    a = var->value.intValue;
                    a = a - 1;
                    var->value.intValue = a;
                    break;
                // You can add cases for other types if decrementing them makes sense in your language
                default:
                    yyerror("Decrement operation not supported for this type");
            }
        } else {
            yyerror("Undefined variable");
        }
    ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 707 "echo.y"
    { printf("Break Statement Detected. \n"); ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 710 "echo.y"
    { printf("program terminates here"); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2596 "echo.tab.c"
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
#line 712 "echo.y"


void addVar(const char* name, VarValue* value, VarType type) {
    VarNode* newNode = (VarNode*) malloc(sizeof(VarNode));
    newNode->name = strdup(name);
    if (value != NULL) {
        newNode->value = *value;
    } else {
        // Set default values based on the type
        switch (type) {
            case INT_TYPE:
                newNode->value.intValue = 0;
                break;
            case FLOAT_TYPE:
                newNode->value.floatValue = 0.0; 
                break;
            case CHAR_TYPE:
                newNode->value.charValue = '\0'; 
                break;
            case DOUBLE_TYPE:
                newNode->value.doubleValue = 0.0; 
                break;
            case STRING_TYPE:
                newNode->value.stringValue = NULL; 
                break;
            case BOOL_TYPE:
                newNode->value.intValue = 0;
        }
    }
    newNode->type = type;
    newNode->next = varList;
    varList = newNode;
}


int varExists(const char* name) {
    VarNode* current = varList;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

VarValue getVarValue(const char* name) {
    VarNode* current = varList;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->value;
        }
        current = current->next;
    }
    // Return a default value if not found, or handle the error as needed
    /* return (VarValue){ .intValue = 0 };  */
}

void printVarValue(const char* name) {
    VarValue val = getVarValue(name);
    VarNode* varNode = findVarNode(name);

    if (varNode == NULL) {
        printf("Variable '%s' not found.\n", name);
        return;
    }

    switch (varNode->type) {
        case INT_TYPE:
            printf("Value of %s is %d and Type is Integer\n", name, val.intValue);
            break;
        case FLOAT_TYPE:
            printf("Value of %s is %f and Type is Float\n", name, val.floatValue);
            break;
        case DOUBLE_TYPE:
            printf("Value of %s is %lf and Type is Double\n", name, val.doubleValue);
            break;
        case CHAR_TYPE:
            printf("Value of %s is '%c' and Type is Character\n", name, val.charValue);
            break;
        case STRING_TYPE:
            printf("Value of %s is \"%s\"  and Type is String\n", name, val.stringValue);
            break;
        case BOOL_TYPE:
            printf("Value of %s is %d and Type is BOOL\n", name, val.boolValue);
            break;
        default:
            printf("Unknown type for variable %s.\n", name);
    }
}


VarNode* findVarNode(const char* name) {
    VarNode* current = varList;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}


VarType determineType(const char* typeStr) {
    if (strcmp(typeStr, "int") == 0) return INT_TYPE;
    if (strcmp(typeStr, "float") == 0) return FLOAT_TYPE;
	if (strcmp(typeStr, "string") == 0) return STRING_TYPE;
	if (strcmp(typeStr, "char") == 0) return CHAR_TYPE;
	if (strcmp(typeStr, "double") == 0) return DOUBLE_TYPE;
    if (strcmp(typeStr, "bool") == 0) return BOOL_TYPE;
    // ... other type cases
    return INT_TYPE; // Default case, or you could handle error here
}

VarType mapIntToVarType(int typeInt) {
    switch (typeInt) {
        case 0: return INT_TYPE;
        case 1: return FLOAT_TYPE;
        case 2: return CHAR_TYPE;
        case 3: return DOUBLE_TYPE;
        case 4: return STRING_TYPE;
        case 5: return BOOL_TYPE;
        default: return INT_TYPE;
    }
}

void yyerror(char *s) {
    fprintf(stderr, "error: %s\n", s);
}

void freeVarValue(VarValue *value, VarType type) {
    if (type == STRING_TYPE && value->stringValue != NULL) {
        free(value->stringValue);
        value->stringValue = NULL;
    }
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
