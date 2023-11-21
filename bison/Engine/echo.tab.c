
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
    struct {
        int size;
        void* elements;
    } array;
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
void* allocateArrayElements(VarType type, int size);
void parseArrayLiteral(const char* literal, int** elements, int* size);


int variable_count = 0;
int statement_count = 0;
int function_count = 0;
int array_count = 0;




/* Line 189 of yacc.c  */
#line 132 "echo.tab.c"

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
     CONTINUE = 288,
     INPUT_OP = 289,
     NOT_OP = 290,
     INCREMENT = 291,
     DECREMENT = 292,
     OPEN_PAREN = 293,
     CLOSE_PAREN = 294,
     LBRACKET = 295,
     RBRACKET = 296,
     LBRACE = 297,
     RBRACE = 298,
     SEMICOLON = 299,
     COMMA = 300,
     INVERTED_COMMA = 301,
     DOUBLE_QUOTE = 302,
     COLON = 303,
     BODY_START = 304,
     BODY_END = 305,
     DOUBLE = 306,
     FLOAT = 307,
     INTEGER = 308,
     BOOL = 309,
     CHAR_LITERAL = 310,
     STRING_LITERAL = 311,
     IDENTIFIER = 312,
     PATH = 313,
     TYPE = 314,
     ARRAY_LITERAL = 315,
     SINGLE_LINE_COMMENT_START = 316,
     MULTI_LINE_COMMENT_START = 317,
     MULTI_LINE_COMMENT_END = 318,
     ARRAY_INIT = 319,
     END = 320
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 59 "echo.y"

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
            struct {
                int size;
                void* elements;
            } array;
        } value;
        int type;
    } exprValue;



/* Line 214 of yacc.c  */
#line 260 "echo.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 272 "echo.tab.c"

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
#define YYLAST   637

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNRULES -- Number of states.  */
#define YYNSTATES  226

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   320

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    42,    45,    51,    57,    64,    67,    70,    72,    76,
      78,    82,    88,    95,    99,   101,   103,   105,   107,   109,
     114,   119,   123,   132,   145,   146,   156,   158,   160,   162,
     164,   166,   168,   170,   175,   180,   184,   188,   192,   196,
     200,   204,   208,   212,   216,   220,   224,   228,   232,   236,
     239,   243,   246,   249,   260,   270,   271,   275,   277,   281,
     282,   285,   287,   293,   294,   296,   300,   310,   312,   317,
     319,   322,   324,   328,   331,   334,   335,   343,   348,   349,
     354,   355,   356,   361,   362,   363,   368,   369,   370,   375,
     376,   380,   384,   387
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      67,     0,    -1,    -1,    67,    68,    -1,   102,    -1,    69,
      -1,    71,    -1,    72,    -1,    73,    -1,    78,    -1,    83,
      -1,    79,    -1,    80,    -1,    89,    -1,    93,    -1,   101,
      -1,    99,    -1,   100,    -1,    87,    -1,    70,    -1,    17,
      58,    -1,    33,    44,    -1,    18,    38,    56,    39,    44,
      -1,    18,    38,    82,    39,    44,    -1,    57,    34,    38,
      56,    39,    44,    -1,    74,    44,    -1,    19,    75,    -1,
      76,    -1,    75,    45,    76,    -1,    57,    -1,    57,    48,
      59,    -1,    57,    48,    59,     3,    77,    -1,    57,    48,
      59,    40,    53,    41,    -1,    57,     3,    77,    -1,    53,
      -1,    52,    -1,    56,    -1,    55,    -1,    51,    -1,    57,
       3,    82,    44,    -1,    57,     3,    60,    44,    -1,    20,
      82,    44,    -1,    22,    38,    82,    39,    42,    86,    43,
      81,    -1,    22,    38,    82,    39,    42,    86,    43,    81,
      23,    42,    86,    43,    -1,    -1,    81,    23,    22,    38,
      82,    39,    42,    86,    43,    -1,    53,    -1,    52,    -1,
      56,    -1,    55,    -1,    51,    -1,    54,    -1,    57,    -1,
      57,    40,    82,    41,    -1,    57,    38,    88,    39,    -1,
      82,     3,    82,    -1,    82,     4,    82,    -1,    82,     5,
      82,    -1,    82,     7,    82,    -1,    82,     6,    82,    -1,
      82,    11,    82,    -1,    82,    10,    82,    -1,    82,     9,
      82,    -1,    82,     8,    82,    -1,    82,    13,    82,    -1,
      82,    12,    82,    -1,    82,    16,    82,    -1,    82,    15,
      82,    -1,    82,    14,    82,    -1,    35,    82,    -1,    38,
      82,    39,    -1,    57,    36,    -1,    57,    37,    -1,    21,
      57,    48,    59,    38,    84,    39,    42,    86,    43,    -1,
      25,    21,    48,    59,    38,    39,    42,    86,    43,    -1,
      -1,    84,    45,    85,    -1,    85,    -1,    11,    74,     9,
      -1,    -1,    86,    68,    -1,    68,    -1,    57,    38,    88,
      39,    44,    -1,    -1,    82,    -1,    88,    45,    82,    -1,
      27,    38,    90,    91,    92,    39,    42,    86,    43,    -1,
      73,    -1,    57,     3,    82,    44,    -1,    44,    -1,    82,
      44,    -1,    44,    -1,    57,     3,    82,    -1,    57,    36,
      -1,    57,    37,    -1,    -1,    24,    11,    82,     9,    42,
      94,    43,    -1,    95,    96,    97,    98,    -1,    -1,    28,
      42,    86,    43,    -1,    -1,    -1,    30,    42,    86,    43,
      -1,    -1,    -1,    29,    42,    86,    43,    -1,    -1,    -1,
      31,    42,    86,    43,    -1,    -1,    57,    36,    44,    -1,
      57,    37,    44,    -1,    32,    44,    -1,    65,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   112,   112,   113,   115,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     137,   141,   148,   149,   181,   185,   189,   193,   194,   198,
     206,   218,   250,   268,   311,   315,   319,   323,   327,   334,
     405,   435,   465,   468,   473,   474,   480,   484,   488,   492,
     496,   500,   504,   541,   561,   562,   563,   567,   571,   575,
     579,   583,   587,   591,   595,   607,   620,   633,   655,   668,
     673,   674,   695,   718,   722,   727,   728,   729,   733,   736,
     737,   738,   742,   747,   749,   750,   754,   760,   761,   762,
     766,   767,   771,   772,   773,   774,   778,   784,   790,   791,
     792,   795,   796,   797,   800,   801,   802,   805,   806,   807,
     811,   832,   853,   856
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
  "CONTINUE", "INPUT_OP", "NOT_OP", "INCREMENT", "DECREMENT", "OPEN_PAREN",
  "CLOSE_PAREN", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "SEMICOLON",
  "COMMA", "INVERTED_COMMA", "DOUBLE_QUOTE", "COLON", "BODY_START",
  "BODY_END", "DOUBLE", "FLOAT", "INTEGER", "BOOL", "CHAR_LITERAL",
  "STRING_LITERAL", "IDENTIFIER", "PATH", "TYPE", "ARRAY_LITERAL",
  "SINGLE_LINE_COMMENT_START", "MULTI_LINE_COMMENT_START",
  "MULTI_LINE_COMMENT_END", "ARRAY_INIT", "END", "$accept", "program",
  "statement", "import_statement", "continue_statement", "print_statement",
  "input_statement", "var_declaration",
  "var_declaration_without_semicolon", "var_declaration_list", "var_decl",
  "value", "assignment_statement", "return_statement",
  "conditional_statement", "else_if_clauses", "expression",
  "function_declaration", "param_list", "param", "function_body",
  "function_call_statement", "argument_list", "for_statement", "for_init",
  "for_condition", "for_increment", "while_statement", "while_body",
  "pre_block", "body_block", "post_block", "always_block",
  "increment_statement", "decrement_statement", "break_statement",
  "end_of_the_line", 0
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
     315,   316,   317,   318,   319,   320
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    67,    67,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      69,    70,    71,    71,    72,    73,    74,    75,    75,    76,
      76,    76,    76,    76,    77,    77,    77,    77,    77,    78,
      78,    79,    80,    80,    81,    81,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    83,    84,    84,    84,    85,    86,
      86,    86,    87,    88,    88,    88,    89,    90,    90,    90,
      91,    91,    92,    92,    92,    92,    93,    94,    95,    95,
      95,    96,    96,    96,    97,    97,    97,    98,    98,    98,
      99,   100,   101,   102
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     5,     5,     6,     2,     2,     1,     3,     1,
       3,     5,     6,     3,     1,     1,     1,     1,     1,     4,
       4,     3,     8,    12,     0,     9,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     2,     2,    10,     9,     0,     3,     1,     3,     0,
       2,     1,     5,     0,     1,     3,     9,     1,     4,     1,
       2,     1,     3,     2,     2,     0,     7,     4,     0,     4,
       0,     0,     4,     0,     0,     4,     0,     0,     4,     0,
       3,     3,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,   113,     0,     4,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     3,     5,    19,
       6,     7,     8,     0,     9,    11,    12,    10,    18,    13,
      14,    16,    17,    15,    20,     0,    29,    26,    27,     0,
       0,    50,    47,    46,    51,    49,    48,    52,     0,     0,
       0,     0,     0,     0,   112,    21,     0,     0,     0,     0,
      83,    25,    48,     0,     0,     0,     0,    69,     0,    71,
      72,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,     0,    89,     0,    87,     0,     0,     0,     0,   110,
     111,    84,     0,     0,     0,    38,    35,    34,    37,    36,
      33,    30,    28,    70,     0,     0,    55,    56,    57,    59,
      58,    63,    62,    61,    60,    65,    64,    68,    67,    66,
       0,     0,     0,     0,     0,    91,     0,    95,    40,    39,
       0,     0,     0,    22,    23,     0,     0,    54,    53,    75,
      79,    98,     0,     0,    90,     0,     0,     0,    82,    85,
      31,     0,     0,     0,    77,    81,     0,     0,     0,   101,
       0,    88,     0,    93,    94,     0,    24,    32,     0,     0,
       0,    44,    80,    79,    96,     0,   104,    79,    92,    79,
      78,    79,    76,    42,     0,    79,     0,   107,     0,     0,
       0,     0,    99,     0,    79,     0,    97,    74,    86,    73,
       0,    79,   102,     0,    79,     0,     0,   105,     0,     0,
      43,   108,     0,    79,     0,    45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   165,    18,    19,    20,    21,    22,    23,    37,
      38,   110,    24,    25,    26,   193,   101,    27,   163,   164,
     166,    28,   102,    29,    95,   137,   156,    30,   168,   169,
     186,   197,   206,    31,    32,    33,     3
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -36
static const yytype_int16 yypact[] =
{
     -35,   -36,     2,   -36,   -36,    -5,    16,    30,   529,    67,
      45,   115,    36,    90,    87,    88,    48,   -36,   -36,   -36,
     -36,   -36,   -36,    89,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,   -36,   552,     0,    98,   -36,   529,
     529,   -36,   -36,   -36,   -36,   -36,   -36,   123,     1,   114,
     529,   529,   118,     6,   -36,   -36,   519,    96,   129,   132,
     529,   -36,   139,   442,    66,   120,    30,   607,   479,   -36,
     -36,   529,   529,   529,   529,   529,   529,   529,   529,   529,
     529,   529,   529,   529,   529,   529,   529,   -36,   121,   493,
     621,   122,   -36,   181,   -36,    85,   141,    86,   131,   -36,
     -36,   607,    -8,   144,   145,   -36,   -36,   -36,   -36,   -36,
     -36,    15,   -36,   -36,     7,   428,   607,   514,   464,   451,
     451,    26,    26,    26,    26,    46,    46,   -36,   -36,   -36,
     152,   149,   371,   156,   529,   -36,   100,   138,   -36,   -36,
     160,   158,   529,   -36,   -36,    66,   147,   -36,   -36,   192,
     359,   176,   166,   142,   -36,    44,   167,   165,   -36,   607,
     -36,   169,   193,    19,   -36,   -36,   150,   171,   172,   187,
     177,   -36,   529,   -36,   -36,   178,   -36,   -36,   209,   179,
     192,   -36,   -36,   359,   -36,   190,   200,   359,   607,   359,
     -36,   359,   -36,   211,   206,   359,   194,   204,   223,   240,
     257,    14,   -36,   274,   359,   195,   -36,   -36,   -36,   -36,
     208,   359,   -36,   291,   359,   529,   308,   -36,   325,   530,
     -36,   -36,   210,   359,   342,   -36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -36,   -36,    -2,   -36,   -36,   -36,   -36,   198,    91,   -36,
     188,   124,   -36,   -36,   -36,   -36,    -7,   -36,   -36,   105,
     207,   -36,   197,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,   -36,   -36,   -36
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      17,    48,     4,    64,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,   145,     5,
       6,     7,     8,     9,    10,     7,    11,    12,    63,    13,
       1,   141,    67,    68,    14,    15,   210,   142,    82,    83,
      84,    85,    86,    89,    90,    87,   147,   172,    65,    97,
      92,    56,   142,    34,    35,   146,   211,    52,   179,    16,
      84,    85,    86,    93,   180,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     173,   174,    57,    50,    58,    59,    60,    36,   136,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,   105,   106,   107,
      39,   108,   109,    40,    49,   122,    51,   153,    53,   135,
     139,    54,    55,    61,    98,   159,    41,    42,    43,    44,
      45,    46,    47,    66,   154,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    69,
      70,    71,    88,    72,   182,   188,    91,     5,     6,     7,
       8,     9,    10,    99,    11,    12,   100,    13,   103,   111,
     130,   133,    14,    15,   134,   138,   171,   140,   143,   144,
     149,   150,   182,   181,   152,   155,   182,   182,   182,   157,
     161,   182,   158,   162,   167,   170,   175,    16,   219,   176,
     177,   182,     7,   183,   182,   184,   182,   185,   190,   187,
     189,   191,   182,     5,     6,     7,     8,     9,    10,   196,
      11,    12,   195,    13,   201,   205,   204,   214,    14,    15,
       5,     6,     7,     8,     9,    10,   215,    11,    12,   202,
      13,    94,   223,   178,   112,    14,    15,     5,     6,     7,
       8,     9,    10,    16,    11,    12,   207,    13,   114,   160,
       0,     0,    14,    15,     5,     6,     7,     8,     9,    10,
      16,    11,    12,   208,    13,   192,     0,     0,     0,    14,
      15,     5,     6,     7,     8,     9,    10,    16,    11,    12,
     209,    13,     0,     0,     0,     0,    14,    15,     5,     6,
       7,     8,     9,    10,    16,    11,    12,   212,    13,     0,
       0,     0,     0,    14,    15,     5,     6,     7,     8,     9,
      10,    16,    11,    12,   217,    13,     0,     0,     0,     0,
      14,    15,     5,     6,     7,     8,     9,    10,    16,    11,
      12,   220,    13,     0,     0,     0,     0,    14,    15,     5,
       6,     7,     8,     9,    10,    16,    11,    12,   221,    13,
       0,     0,     0,     0,    14,    15,     5,     6,     7,     8,
       9,    10,    16,    11,    12,   225,    13,     0,     0,     0,
     194,    14,    15,     0,   198,     0,   199,     0,   200,    16,
       0,     0,   203,     0,     0,     0,    39,     0,     0,    40,
       0,   213,     0,   151,     0,     0,    16,     0,   216,     0,
       0,   218,    41,    42,    43,    44,    45,    46,    47,     0,
     224,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    78,
      79,    80,    81,    82,    83,    84,    85,    86,     0,   148,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,   104,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,   113,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,     0,   131,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,     0,
       0,     0,     0,     0,    39,     0,     0,    40,     0,     0,
       0,     0,     0,     0,    39,     0,     0,    40,     0,   222,
      41,    42,    43,    44,    45,    46,    47,     0,     0,    96,
      41,    42,    43,    44,    45,    46,    47,    39,     0,     0,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,    42,    43,    44,    45,    62,    47,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    73,    74,    75,    76,    77,    78,
     132,    80,    81,    82,    83,    84,    85,    86
};

static const yytype_int16 yycheck[] =
{
       2,     8,     0,     3,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     3,    17,
      18,    19,    20,    21,    22,    19,    24,    25,    35,    27,
      65,    39,    39,    40,    32,    33,    22,    45,    12,    13,
      14,    15,    16,    50,    51,    44,    39,     3,    48,    56,
      44,     3,    45,    58,    38,    40,    42,    21,    39,    57,
      14,    15,    16,    57,    45,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      36,    37,    34,    38,    36,    37,    38,    57,    95,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    51,    52,    53,
      35,    55,    56,    38,    57,   132,    11,   134,    38,    44,
      44,    44,    44,    44,    38,   142,    51,    52,    53,    54,
      55,    56,    57,    45,    44,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    36,
      37,    38,    48,    40,   166,   172,    48,    17,    18,    19,
      20,    21,    22,    44,    24,    25,    44,    27,    39,    59,
      59,    59,    32,    33,     3,    44,    44,    56,    44,    44,
      38,    42,   194,    43,    38,    57,   198,   199,   200,    39,
      53,   203,    44,    11,    28,    39,    39,    57,   215,    44,
      41,   213,    19,    42,   216,    43,   218,    30,     9,    42,
      42,    42,   224,    17,    18,    19,    20,    21,    22,    29,
      24,    25,    42,    27,    23,    31,    42,    42,    32,    33,
      17,    18,    19,    20,    21,    22,    38,    24,    25,    43,
      27,    53,    42,   162,    66,    32,    33,    17,    18,    19,
      20,    21,    22,    57,    24,    25,    43,    27,    71,   145,
      -1,    -1,    32,    33,    17,    18,    19,    20,    21,    22,
      57,    24,    25,    43,    27,   180,    -1,    -1,    -1,    32,
      33,    17,    18,    19,    20,    21,    22,    57,    24,    25,
      43,    27,    -1,    -1,    -1,    -1,    32,    33,    17,    18,
      19,    20,    21,    22,    57,    24,    25,    43,    27,    -1,
      -1,    -1,    -1,    32,    33,    17,    18,    19,    20,    21,
      22,    57,    24,    25,    43,    27,    -1,    -1,    -1,    -1,
      32,    33,    17,    18,    19,    20,    21,    22,    57,    24,
      25,    43,    27,    -1,    -1,    -1,    -1,    32,    33,    17,
      18,    19,    20,    21,    22,    57,    24,    25,    43,    27,
      -1,    -1,    -1,    -1,    32,    33,    17,    18,    19,    20,
      21,    22,    57,    24,    25,    43,    27,    -1,    -1,    -1,
     183,    32,    33,    -1,   187,    -1,   189,    -1,   191,    57,
      -1,    -1,   195,    -1,    -1,    -1,    35,    -1,    -1,    38,
      -1,   204,    -1,    42,    -1,    -1,    57,    -1,   211,    -1,
      -1,   214,    51,    52,    53,    54,    55,    56,    57,    -1,
     223,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    41,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    39,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    39,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    38,    -1,    39,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    60,
      51,    52,    53,    54,    55,    56,    57,    35,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    65,    67,   102,     0,    17,    18,    19,    20,    21,
      22,    24,    25,    27,    32,    33,    57,    68,    69,    70,
      71,    72,    73,    74,    78,    79,    80,    83,    87,    89,
      93,    99,   100,   101,    58,    38,    57,    75,    76,    35,
      38,    51,    52,    53,    54,    55,    56,    57,    82,    57,
      38,    11,    21,    38,    44,    44,     3,    34,    36,    37,
      38,    44,    56,    82,     3,    48,    45,    82,    82,    36,
      37,    38,    40,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    44,    48,    82,
      82,    48,    44,    57,    73,    90,    60,    82,    38,    44,
      44,    82,    88,    39,    39,    51,    52,    53,    55,    56,
      77,    59,    76,    39,    88,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      59,    39,     9,    59,     3,    44,    82,    91,    44,    44,
      56,    39,    45,    44,    44,     3,    40,    39,    41,    38,
      42,    42,    38,    82,    44,    57,    92,    39,    44,    82,
      77,    53,    11,    84,    85,    68,    86,    28,    94,    95,
      39,    44,     3,    36,    37,    39,    44,    41,    74,    39,
      45,    43,    68,    42,    43,    30,    96,    42,    82,    42,
       9,    42,    85,    81,    86,    42,    29,    97,    86,    86,
      86,    23,    43,    86,    42,    31,    98,    43,    43,    43,
      22,    42,    43,    86,    42,    38,    86,    43,    86,    82,
      43,    43,    39,    42,    86,    43
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
#line 119 "echo.y"
    { statement_count++; ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 120 "echo.y"
    { statement_count++; ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 121 "echo.y"
    { statement_count++; ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 122 "echo.y"
    { statement_count++; ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 123 "echo.y"
    { statement_count++; ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 124 "echo.y"
    { statement_count++; ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 125 "echo.y"
    { statement_count++; ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 126 "echo.y"
    { statement_count++; ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 127 "echo.y"
    { statement_count++; ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 128 "echo.y"
    { statement_count++; ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 129 "echo.y"
    { statement_count++; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 130 "echo.y"
    { statement_count++; ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 131 "echo.y"
    { statement_count++; ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 132 "echo.y"
    { statement_count++; ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 133 "echo.y"
    { statement_count++; ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 137 "echo.y"
    { printf("Import detected FROM BISON with path: %s\n", (yyvsp[(2) - (2)].str)); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 141 "echo.y"
    {
        printf("Continue statement detected.\n");
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 148 "echo.y"
    { printf("Print detected FROM BISON with message: %s\n", (yyvsp[(3) - (5)].str)); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 149 "echo.y"
    {
        switch ((yyvsp[(3) - (5)].exprValue).type) {
            case INT_TYPE:
                printf("Print detected of TYPE INT and value %d\n", (yyvsp[(3) - (5)].exprValue).value.intValue);
                break;
            case FLOAT_TYPE:
                printf("Print detected of TYPE FLOAT and value %f\n", (yyvsp[(3) - (5)].exprValue).value.floatValue);
                break;
            case CHAR_TYPE:
                printf("Print detected of TYPE CHAR and value %c\n", (yyvsp[(3) - (5)].exprValue).value.charValue);
                break;
            case DOUBLE_TYPE:
                printf("Print detected of TYPE DOUBLE and value %lf\n", (yyvsp[(3) - (5)].exprValue).value.doubleValue);
                break;
            case STRING_TYPE:
                if ((yyvsp[(3) - (5)].exprValue).value.stringValue != NULL) {
                    printf("Print detected of TYPE STRING and value %s\n", (yyvsp[(3) - (5)].exprValue).value.stringValue);
                } else {
                    printf("(null)\n");
                }
                break;
            case BOOL_TYPE:
                printf("Print detected of TYPE BOOL and value %d\n", (yyvsp[(3) - (5)].exprValue).value.boolValue);
                break;
            default:
                printf("Unknown type for printing\n");
        }
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 181 "echo.y"
    { printf("Input detected FROM BISON for variable %s with message: %s\n", (yyvsp[(1) - (6)].str), (yyvsp[(4) - (6)].str)); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 198 "echo.y"
    { 
        if (varExists((yyvsp[(1) - (1)].str))) {
            printf("Variable collision detected for variable: %s\n", (yyvsp[(1) - (1)].str));
        } else {
            printf("<Invalid variable declaration %s> Pls include a type. read docs for mor information.\n URL: https://www.swift.org", (yyvsp[(1) - (1)].str));
        }
        free((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 206 "echo.y"
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

  case 31:

/* Line 1455 of yacc.c  */
#line 218 "echo.y"
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

  case 32:

/* Line 1455 of yacc.c  */
#line 250 "echo.y"
    { 
        if (varExists((yyvsp[(1) - (6)].str))) {
            printf("Variable collision detected for variable: %s\n", (yyvsp[(1) - (6)].str));
        } else {
            VarType type = determineType((yyvsp[(3) - (6)].str));
            // Allocate and initialize array
            void* arrayElements = allocateArrayElements(type, (yyvsp[(5) - (6)].num));
            VarValue val;
            val.array.size = (yyvsp[(5) - (6)].num);
            val.array.elements = arrayElements;
            addVar((yyvsp[(1) - (6)].str), &val, ARRAY_TYPE); // ARRAY_TYPE is a new enum value to represent arrays
            printf("Array declaration detected FROM BISON: %s of type %s with size %d\n", (yyvsp[(1) - (6)].str), (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].num));
            variable_count++;
        }
        free((yyvsp[(3) - (6)].str));
        free((yyvsp[(1) - (6)].str));
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 268 "echo.y"
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

  case 34:

/* Line 1455 of yacc.c  */
#line 311 "echo.y"
    { 
        (yyval.exprValue).value.intValue = (yyvsp[(1) - (1)].num);
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 315 "echo.y"
    {
        (yyval.exprValue).value.floatValue = (yyvsp[(1) - (1)].floatValue);
        (yyval.exprValue).type = FLOAT_TYPE;
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 319 "echo.y"
    {
        (yyval.exprValue).value.stringValue = (yyvsp[(1) - (1)].str);
        (yyval.exprValue).type = STRING_TYPE;
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 323 "echo.y"
    {
		(yyval.exprValue).value.charValue = (yyvsp[(1) - (1)].charValue);
        (yyval.exprValue).type = CHAR_TYPE;
	;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 327 "echo.y"
    {
		(yyval.exprValue).value.doubleValue = (yyvsp[(1) - (1)].doubleValue);
        (yyval.exprValue).type = DOUBLE_TYPE;
	;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 334 "echo.y"
    {
        if (varExists((yyvsp[(1) - (4)].str))) {
            VarNode* var = findVarNode((yyvsp[(1) - (4)].str));
            if (var) {
                switch (var->type) {
                    case INT_TYPE:
                        if ((yyvsp[(3) - (4)].exprValue).type == INT_TYPE) {
                            var->value.intValue = (yyvsp[(3) - (4)].exprValue).value.intValue;
                            printf("Variable %s assigned value of %d of type INT_TYPE \n", (yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].exprValue).value.intValue);
                        } else {
                            fprintf(stderr, "Type mismatch: Cannot assign non-integer to integer variable '%s'.\n", var->name);
                        }
                        break;

                    case FLOAT_TYPE:
                        if ((yyvsp[(3) - (4)].exprValue).type == FLOAT_TYPE) {
                            var->value.floatValue = (yyvsp[(3) - (4)].exprValue).value.floatValue;
                            printf("Variable %s assigned value of %f of type FLOAT_TYPE \n", (yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].exprValue).value.floatValue);
                        } else {
                            fprintf(stderr, "Type mismatch: Cannot assign non-float to float variable '%s'.\n", var->name);
                        }
                        break;

                    case CHAR_TYPE:
                        if ((yyvsp[(3) - (4)].exprValue).type == CHAR_TYPE) {
                            var->value.charValue = (yyvsp[(3) - (4)].exprValue).value.charValue;
                            printf("Variable %s assigned value of %c of type CHAR_TYPE \n", (yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].exprValue).value.charValue);
                        } else {
                            fprintf(stderr, "Type mismatch: Cannot assign non-char to char variable '%s'.\n", var->name);
                        }
                        break;

                    case DOUBLE_TYPE:
                        if ((yyvsp[(3) - (4)].exprValue).type == DOUBLE_TYPE) {
                            var->value.doubleValue = (yyvsp[(3) - (4)].exprValue).value.doubleValue;
                            printf("Variable %s assigned value of %lf of type DOUBLE_TYPE \n", (yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].exprValue).value.doubleValue);
                        } else {
                            fprintf(stderr, "Type mismatch: Cannot assign non-double to double variable '%s'.\n", var->name);
                        }
                        break;

                    case STRING_TYPE:
                        if ((yyvsp[(3) - (4)].exprValue).type == STRING_TYPE) {
                            free(var->value.stringValue); // Free existing string
                            var->value.stringValue = strdup((yyvsp[(3) - (4)].exprValue).value.stringValue);
                            printf("Variable %s assigned value of \"%s\" of type STRING_TYPE \n", (yyvsp[(1) - (4)].str), var->value.stringValue);
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
                        break;
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

  case 40:

/* Line 1455 of yacc.c  */
#line 405 "echo.y"
    {
        if (varExists((yyvsp[(1) - (4)].str))) {
            VarNode* var = findVarNode((yyvsp[(1) - (4)].str));
            if (var && var->type == ARRAY_TYPE) {
                int* elements;
                int size;
                parseArrayLiteral((yyvsp[(3) - (4)].str), &elements, &size);
                if (size != var->value.array.size) {
                    printf("Size is %d\n", size);
                    printf("var size is %d\n", var->value.array.size);
                    yyerror("Array size mismatch");
                } else {
                    memcpy(var->value.array.elements, elements, size * sizeof(int));
                }
                free(elements); // Assuming parseArrayLiteral allocates memory for elements
            } else {
                yyerror("Variable is not an array");
            }
        } else {
            yyerror("Undefined variable");
        }
        free((yyvsp[(3) - (4)].str)); // Free the literal string
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 435 "echo.y"
    {
        switch((yyvsp[(2) - (3)].exprValue).type) {
            case INT_TYPE:
                printf("Return statement with integer value: %d\n", (yyvsp[(2) - (3)].exprValue).value.intValue);
                break;
            case FLOAT_TYPE:
                printf("Return statement with float value: %f\n", (yyvsp[(2) - (3)].exprValue).value.floatValue);
                break;
            case STRING_TYPE:
                printf("Return statement with string value: \"%s\"\n", (yyvsp[(2) - (3)].exprValue).value.stringValue);
                free((yyvsp[(2) - (3)].exprValue).value.stringValue); // Don't forget to free the duplicated string
                break;
            case CHAR_TYPE:
                printf("Return statement with char value: '%c'\n", (yyvsp[(2) - (3)].exprValue).value.charValue);
                break;
            case DOUBLE_TYPE:
                printf("Return statement with double value: %lf\n", (yyvsp[(2) - (3)].exprValue).value.doubleValue);
                break;
            case BOOL_TYPE:
                printf("Return statement with bool value: %s\n", (yyvsp[(2) - (3)].exprValue).value.boolValue ? "true" : "false");
                break;
            default:
                printf("Return statement with unknown type\n");
                break;
        }
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 465 "echo.y"
    {
        printf("If with Else-If(s) statement detected FROM BISON.\n");
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 468 "echo.y"
    {
        printf("If with Else-If(s) and Else statement detected FROM BISON.\n");
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 474 "echo.y"
    {
        printf("Else-If clause detected FROM BISON.\n");
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 480 "echo.y"
    { 
		(yyval.exprValue).value.intValue = (yyvsp[(1) - (1)].num);
		(yyval.exprValue).type = INT_TYPE;
	;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 484 "echo.y"
    {
        (yyval.exprValue).value.floatValue = (yyvsp[(1) - (1)].floatValue); 
        (yyval.exprValue).type = FLOAT_TYPE;
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 488 "echo.y"
    {
        (yyval.exprValue).value.stringValue = strdup((yyvsp[(1) - (1)].str)); 
        (yyval.exprValue).type = STRING_TYPE;
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 492 "echo.y"
    {
        (yyval.exprValue).value.charValue = (yyvsp[(1) - (1)].charValue); 
        (yyval.exprValue).type = CHAR_TYPE;
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 496 "echo.y"
    {
        (yyval.exprValue).value.doubleValue = (yyvsp[(1) - (1)].doubleValue); 
        (yyval.exprValue).type = DOUBLE_TYPE;
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 500 "echo.y"
    {
        (yyval.exprValue).value.boolValue = (yyvsp[(1) - (1)].boolValue);
        (yyval.exprValue).type = BOOL_TYPE; 
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 504 "echo.y"
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
                    break;
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

  case 53:

/* Line 1455 of yacc.c  */
#line 541 "echo.y"
    {
        VarNode* var = findVarNode((yyvsp[(1) - (4)].str));
        if (var && var->type == ARRAY_TYPE) {
            int index;
            if((yyvsp[(3) - (4)].exprValue).type == INT_TYPE) {
                index = (yyvsp[(3) - (4)].exprValue).value.intValue;
            } else {
                fprintf(stderr, "Array index must be an integer\n");
                return -1;
            }
            if (index >= 0 && index < var->value.array.size) {
                (yyval.exprValue).value.intValue = ((int*)var->value.array.elements)[index];
                (yyval.exprValue).type = INT_TYPE;
            } else {
                yyerror("Array index out of bounds");
            }
        } else {
            yyerror("Variable is not an array");
        }
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 563 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(1) - (3)].exprValue).value.intValue || (yyvsp[(3) - (3)].exprValue).value.intValue) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 567 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(1) - (3)].exprValue).value.intValue && (yyvsp[(3) - (3)].exprValue).value.intValue) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 571 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(1) - (3)].exprValue).value.intValue == (yyvsp[(3) - (3)].exprValue).value.intValue) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 575 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(1) - (3)].exprValue).value.intValue != (yyvsp[(3) - (3)].exprValue).value.intValue) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 579 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(1) - (3)].exprValue).value.intValue < (yyvsp[(3) - (3)].exprValue).value.intValue) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 583 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(1) - (3)].exprValue).value.intValue <= (yyvsp[(3) - (3)].exprValue).value.intValue) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 587 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(1) - (3)].exprValue).value.intValue > (yyvsp[(3) - (3)].exprValue).value.intValue) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 591 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(1) - (3)].exprValue).value.intValue >= (yyvsp[(3) - (3)].exprValue).value.intValue) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 595 "echo.y"
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

  case 65:

/* Line 1455 of yacc.c  */
#line 607 "echo.y"
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

  case 66:

/* Line 1455 of yacc.c  */
#line 620 "echo.y"
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

  case 67:

/* Line 1455 of yacc.c  */
#line 633 "echo.y"
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

  case 68:

/* Line 1455 of yacc.c  */
#line 655 "echo.y"
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

  case 69:

/* Line 1455 of yacc.c  */
#line 668 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(2) - (2)].exprValue).value.intValue == 0) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 673 "echo.y"
    { printf("open_paren detected for expression \n"); (yyval.exprValue) = (yyvsp[(2) - (3)].exprValue); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 674 "echo.y"
    {
        printf("IDENTIFIER increment detected \n");
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

  case 72:

/* Line 1455 of yacc.c  */
#line 695 "echo.y"
    {
        VarNode* var = findVarNode((yyvsp[(1) - (2)].str));
        printf("IDENTIFIER decrement detected \n");
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

  case 73:

/* Line 1455 of yacc.c  */
#line 718 "echo.y"
    {
        printf("Function %s with return type %s declared.\n", (yyvsp[(2) - (10)].str), (yyvsp[(4) - (10)].str));
        free((yyvsp[(2) - (10)].str)); free((yyvsp[(4) - (10)].str)); function_count++;
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 722 "echo.y"
    {
		printf("Main Function detected \n"); function_count++;
	;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 742 "echo.y"
    {
        printf("Function call detected FROM BISON: %s\n", (yyvsp[(1) - (5)].str));
    ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 754 "echo.y"
    {
        printf("For loop detected FROM BISON.\n");
    ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 778 "echo.y"
    {
        printf("While loop detected FROM BISON.\n");
    ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 791 "echo.y"
    { printf("Pre block detected FROM BISON.\n"); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 796 "echo.y"
    { printf("Body block detected FROM BISON.\n"); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 801 "echo.y"
    { printf("Post block detected FROM BISON.\n"); ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 806 "echo.y"
    { printf("Always block detected FROM BISON.\n"); ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 811 "echo.y"
    {
        printf("increament_statment detected \n");
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

  case 111:

/* Line 1455 of yacc.c  */
#line 832 "echo.y"
    {
        printf("decrement_statement detected \n");
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

  case 112:

/* Line 1455 of yacc.c  */
#line 853 "echo.y"
    { printf("Break Statement Detected. \n"); ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 856 "echo.y"
    { printf("program terminates here"); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2800 "echo.tab.c"
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
#line 858 "echo.y"


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

void* allocateArrayElements(VarType type, int size) {
    void* elements = NULL;
    switch (type) {
        case INT_TYPE:
            elements = malloc(size * sizeof(int));
            break;
        case FLOAT_TYPE:
            elements = malloc(size * sizeof(float));
            break;
        // Add cases for other types...
        default:
            fprintf(stderr, "Unsupported array type.\n");
    }
    return elements;
}

void parseArrayLiteral(const char* literal, int** elements, int* size) {
    // Initial size
    int capacity = 10;
    *elements = (int*)malloc(capacity * sizeof(int));
    *size = 0;

    if (!*elements) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Tokenize the string
    const char* delim = "<[],>";
    char* copyLiteral = strdup(literal);
    char* token = strtok(copyLiteral, delim);
    while (token != NULL) {
        if (*size >= capacity) {
            capacity *= 2;
            int* temp = (int*)realloc(*elements, capacity * sizeof(int));
            if (!temp) {
                // Handle memory allocation failure
                fprintf(stderr, "Memory allocation failed during resizing\n");
                free(*elements);
                free(copyLiteral);
                return;
            }
            *elements = temp;
        }
        (*elements)[*size] = atoi(token);
        (*size)++;
        token = strtok(NULL, delim);
    }

    free(copyLiteral); // Don't forget to free the copy
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
