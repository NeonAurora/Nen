
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
VarType determineTypeFromArray(void* arrayElements);
void bubbleSort(int arr[], int n);


int variable_count = 0;
int statement_count = 0;
int function_count = 0;
int array_count = 0;




/* Line 189 of yacc.c  */
#line 134 "echo.tab.c"

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
     SWITCH = 289,
     CASE = 290,
     DEFAULT = 291,
     INPUT_OP = 292,
     NOT_OP = 293,
     INCREMENT = 294,
     DECREMENT = 295,
     OPEN_PAREN = 296,
     CLOSE_PAREN = 297,
     LBRACKET = 298,
     RBRACKET = 299,
     LBRACE = 300,
     RBRACE = 301,
     SEMICOLON = 302,
     COMMA = 303,
     INVERTED_COMMA = 304,
     DOUBLE_QUOTE = 305,
     COLON = 306,
     BODY_START = 307,
     BODY_END = 308,
     DOUBLE = 309,
     FLOAT = 310,
     INTEGER = 311,
     BOOL = 312,
     CHAR_LITERAL = 313,
     STRING_LITERAL = 314,
     IDENTIFIER = 315,
     PATH = 316,
     TYPE = 317,
     ARRAY_LITERAL = 318,
     SINGLE_LINE_COMMENT_START = 319,
     MULTI_LINE_COMMENT_START = 320,
     MULTI_LINE_COMMENT_END = 321,
     ARRAY_INIT = 322,
     END = 323,
     SORT_ARRAY = 324
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 61 "echo.y"

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
#line 266 "echo.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 278 "echo.tab.c"

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
#define YYLAST   781

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNRULES -- Number of states.  */
#define YYNSTATES  250

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   324

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
      65,    66,    67,    68,    69
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    45,    48,    51,    57,    63,    70,    73,    76,    78,
      82,    84,    88,    94,   101,   105,   107,   109,   111,   113,
     115,   120,   125,   129,   131,   133,   142,   143,   146,   148,
     154,   155,   159,   160,   169,   182,   183,   193,   195,   197,
     199,   201,   203,   205,   207,   212,   217,   221,   225,   229,
     233,   237,   241,   245,   249,   253,   257,   261,   265,   269,
     273,   276,   280,   283,   286,   297,   307,   308,   312,   314,
     318,   319,   322,   324,   330,   331,   333,   337,   347,   349,
     354,   356,   359,   361,   365,   368,   371,   372,   380,   385,
     386,   391,   392,   393,   398,   399,   400,   405,   406,   407,
     412,   413,   417,   421
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      71,     0,    -1,    -1,    71,    72,    -1,    74,    -1,    76,
      -1,    77,    -1,    78,    -1,    83,    -1,    93,    -1,    84,
      -1,    85,    -1,    99,    -1,   103,    -1,   111,    -1,   109,
      -1,   110,    -1,    97,    -1,    75,    -1,    73,    -1,    69,
      41,    60,    42,    47,    -1,    17,    61,    -1,    33,    47,
      -1,    18,    41,    59,    42,    47,    -1,    18,    41,    92,
      42,    47,    -1,    60,    37,    41,    59,    42,    47,    -1,
      79,    47,    -1,    19,    80,    -1,    81,    -1,    80,    48,
      81,    -1,    60,    -1,    60,    51,    62,    -1,    60,    51,
      62,     3,    82,    -1,    60,    51,    62,    43,    56,    44,
      -1,    60,     3,    82,    -1,    56,    -1,    55,    -1,    59,
      -1,    58,    -1,    54,    -1,    60,     3,    92,    47,    -1,
      60,     3,    63,    47,    -1,    20,    92,    47,    -1,    90,
      -1,    86,    -1,    34,    41,    92,    42,    45,    87,    89,
      46,    -1,    -1,    87,    88,    -1,    88,    -1,    35,    92,
      51,    96,   111,    -1,    -1,    36,    51,    96,    -1,    -1,
      22,    41,    92,    42,    45,    96,    46,    91,    -1,    22,
      41,    92,    42,    45,    96,    46,    91,    23,    45,    96,
      46,    -1,    -1,    91,    23,    22,    41,    92,    42,    45,
      96,    46,    -1,    56,    -1,    55,    -1,    59,    -1,    58,
      -1,    54,    -1,    57,    -1,    60,    -1,    60,    43,    92,
      44,    -1,    60,    41,    98,    42,    -1,    92,     3,    92,
      -1,    92,     4,    92,    -1,    92,     5,    92,    -1,    92,
       7,    92,    -1,    92,     6,    92,    -1,    92,    11,    92,
      -1,    92,    10,    92,    -1,    92,     9,    92,    -1,    92,
       8,    92,    -1,    92,    13,    92,    -1,    92,    12,    92,
      -1,    92,    16,    92,    -1,    92,    15,    92,    -1,    92,
      14,    92,    -1,    38,    92,    -1,    41,    92,    42,    -1,
      60,    39,    -1,    60,    40,    -1,    21,    60,    51,    62,
      41,    94,    42,    45,    96,    46,    -1,    25,    21,    51,
      62,    41,    42,    45,    96,    46,    -1,    -1,    94,    48,
      95,    -1,    95,    -1,    11,    79,     9,    -1,    -1,    96,
      72,    -1,    72,    -1,    60,    41,    98,    42,    47,    -1,
      -1,    92,    -1,    98,    48,    92,    -1,    27,    41,   100,
     101,   102,    42,    45,    96,    46,    -1,    78,    -1,    60,
       3,    92,    47,    -1,    47,    -1,    92,    47,    -1,    47,
      -1,    60,     3,    92,    -1,    60,    39,    -1,    60,    40,
      -1,    -1,    24,    11,    92,     9,    45,   104,    46,    -1,
     105,   106,   107,   108,    -1,    -1,    28,    45,    96,    46,
      -1,    -1,    -1,    30,    45,    96,    46,    -1,    -1,    -1,
      29,    45,    96,    46,    -1,    -1,    -1,    31,    45,    96,
      46,    -1,    -1,    60,    39,    47,    -1,    60,    40,    47,
      -1,    32,    47,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   114,   114,   115,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     138,   153,   157,   164,   165,   197,   201,   205,   209,   210,
     214,   222,   234,   266,   284,   327,   331,   335,   339,   343,
     350,   421,   451,   480,   481,   484,   489,   490,   491,   495,
     500,   501,   502,   506,   509,   514,   515,   521,   525,   529,
     533,   537,   541,   545,   582,   602,   603,   604,   608,   612,
     616,   620,   624,   628,   632,   636,   648,   661,   674,   696,
     709,   714,   715,   736,   759,   763,   768,   769,   770,   774,
     777,   778,   779,   783,   788,   790,   791,   795,   801,   802,
     803,   807,   808,   812,   813,   814,   815,   819,   825,   831,
     832,   833,   836,   837,   838,   841,   842,   843,   846,   847,
     848,   852,   873,   894
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
  "CONTINUE", "SWITCH", "CASE", "DEFAULT", "INPUT_OP", "NOT_OP",
  "INCREMENT", "DECREMENT", "OPEN_PAREN", "CLOSE_PAREN", "LBRACKET",
  "RBRACKET", "LBRACE", "RBRACE", "SEMICOLON", "COMMA", "INVERTED_COMMA",
  "DOUBLE_QUOTE", "COLON", "BODY_START", "BODY_END", "DOUBLE", "FLOAT",
  "INTEGER", "BOOL", "CHAR_LITERAL", "STRING_LITERAL", "IDENTIFIER",
  "PATH", "TYPE", "ARRAY_LITERAL", "SINGLE_LINE_COMMENT_START",
  "MULTI_LINE_COMMENT_START", "MULTI_LINE_COMMENT_END", "ARRAY_INIT",
  "END", "SORT_ARRAY", "$accept", "program", "statement", "sort_statement",
  "import_statement", "continue_statement", "print_statement",
  "input_statement", "var_declaration",
  "var_declaration_without_semicolon", "var_declaration_list", "var_decl",
  "value", "assignment_statement", "return_statement",
  "conditional_statement", "switch_conditional_statement", "case_clauses",
  "case_clause", "default_clause", "if_conditional_statement",
  "else_if_clauses", "expression", "function_declaration", "param_list",
  "param", "function_body", "function_call_statement", "argument_list",
  "for_statement", "for_init", "for_condition", "for_increment",
  "while_statement", "while_body", "pre_block", "body_block", "post_block",
  "always_block", "increment_statement", "decrement_statement",
  "break_statement", 0
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    71,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    74,    75,    76,    76,    77,    78,    79,    80,    80,
      81,    81,    81,    81,    81,    82,    82,    82,    82,    82,
      83,    83,    84,    85,    85,    86,    87,    87,    87,    88,
      89,    89,    89,    90,    90,    91,    91,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    93,    93,    94,    94,    94,    95,
      96,    96,    96,    97,    98,    98,    98,    99,   100,   100,
     100,   101,   101,   102,   102,   102,   102,   103,   104,   105,
     105,   105,   106,   106,   106,   107,   107,   107,   108,   108,
     108,   109,   110,   111
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     2,     2,     5,     5,     6,     2,     2,     1,     3,
       1,     3,     5,     6,     3,     1,     1,     1,     1,     1,
       4,     4,     3,     1,     1,     8,     0,     2,     1,     5,
       0,     3,     0,     8,    12,     0,     9,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     3,     3,     3,     3,
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
       0,     0,     0,     0,     0,     0,     0,     3,    19,     4,
      18,     5,     6,     7,     0,     8,    10,    11,    44,    43,
       9,    17,    12,    13,    15,    16,    14,    21,     0,    30,
      27,    28,     0,     0,    61,    58,    57,    62,    60,    59,
      63,     0,     0,     0,     0,     0,     0,   123,    22,     0,
       0,     0,     0,     0,    94,     0,    26,    59,     0,     0,
       0,     0,    80,     0,    82,    83,    94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,     0,   100,     0,    98,
       0,     0,     0,     0,     0,   121,   122,    95,     0,     0,
       0,     0,    39,    36,    35,    38,    37,    34,    31,    29,
      81,     0,     0,    66,    67,    68,    70,    69,    74,    73,
      72,    71,    76,    75,    79,    78,    77,     0,     0,     0,
       0,     0,   102,     0,   106,     0,    41,    40,     0,     0,
       0,     0,    23,    24,     0,     0,    65,    64,    86,    90,
     109,     0,     0,   101,     0,     0,    46,     0,    93,    96,
      20,    32,     0,     0,     0,    88,    92,     0,     0,     0,
     112,     0,    99,     0,   104,   105,     0,     0,    50,    48,
      25,    33,     0,     0,     0,    55,    91,    90,   107,     0,
     115,    90,   103,    90,     0,     0,    47,     0,    89,    90,
      87,    53,     0,    90,     0,   118,     0,     0,     0,    90,
      45,     0,     0,   110,     0,    90,     0,   108,    85,    97,
       0,    51,    84,     0,    90,   113,     0,    90,    14,     0,
       0,   116,     0,     0,    54,   119,     0,    90,     0,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   176,    18,    19,    20,    21,    22,    23,    24,
      40,    41,   117,    25,    26,    27,    28,   188,   189,   207,
      29,   211,   107,    30,   174,   175,   177,    31,   108,    32,
     100,   144,   165,    33,   179,   180,   200,   215,   227,    34,
      35,    36
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -34
static const yytype_int16 yypact[] =
{
     -34,     2,   -34,   -33,   -11,   -28,   430,   -21,     3,    36,
      29,    11,    22,    23,    16,    61,    20,   -34,   -34,   -34,
     -34,   -34,   -34,   -34,    40,   -34,   -34,   -34,   -34,   -34,
     -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   510,    14,
      55,   -34,   430,   430,   -34,   -34,   -34,   -34,   -34,   -34,
     110,   502,    37,   430,   430,    56,     6,   -34,   -34,   430,
     247,    67,    83,    84,   430,    60,   -34,    85,   603,    88,
      71,   -28,   751,   643,   -34,   -34,   430,   430,   430,   430,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   -34,    75,   657,   765,    77,   -34,   132,   -34,
     311,   697,    93,   516,    89,   -34,   -34,   751,    73,   112,
     117,   119,   -34,   -34,   -34,   -34,   -34,   -34,    15,   -34,
     -34,    80,   589,   751,   681,   546,   487,   487,   230,   230,
     230,   230,    27,    27,   -34,   -34,   -34,   126,   123,   375,
     128,   430,   -34,   530,   113,   129,   -34,   -34,   133,   130,
     430,   134,   -34,   -34,    88,   124,   -34,   -34,   172,   423,
     151,   149,   575,   -34,    28,   152,   161,   150,   -34,   751,
     -34,   -34,   155,   184,    81,   -34,   -34,    72,   159,   160,
     175,   163,   -34,   430,   -34,   -34,   164,   430,    24,   -34,
     -34,   -34,   201,   167,   172,   -34,   -34,   423,   -34,   173,
     188,   423,   751,   423,     0,   162,   -34,   176,   -34,   423,
     -34,   196,    92,   423,   179,   190,   138,   168,   423,   423,
     -34,   231,    18,   -34,   249,   423,   180,   -34,   -34,   -34,
     423,   423,   -34,   185,   423,   -34,   295,   423,    10,   430,
     313,   -34,   359,   711,   -34,   -34,   182,   423,   377,   -34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -34,   -34,    -1,   -34,   -34,   -34,   -34,   -34,   177,    58,
     -34,   165,    78,   -34,   -34,   -34,   -34,   -34,    50,   -34,
     -34,   -34,    -5,   -34,   -34,    46,   257,   -34,   178,   -34,
     -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,
     -34,    30
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -50
static const yytype_int16 yytable[] =
{
      17,    51,     2,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    69,   154,     3,
       4,     5,     6,     7,     8,     5,     9,    10,    37,    11,
      38,   183,    39,    68,    12,    13,    14,    72,    73,    52,
     233,    89,    90,    91,    53,   -49,   -49,    54,    94,    95,
      55,   218,    56,    97,   101,   103,   -49,    59,   155,   187,
     205,    65,    15,   234,    60,    70,    98,   184,   185,    57,
      58,    16,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,    66,    93,     3,
       4,     5,     6,     7,     8,   143,     9,    10,    61,    11,
      62,    63,    64,    71,    12,    13,    14,    96,   104,     3,
       4,     5,     6,     7,     8,   149,     9,    10,   195,    11,
     109,   150,   156,   193,    12,    13,    14,   110,   150,   194,
     105,   106,    15,   118,   129,   141,   162,   137,   223,   140,
     146,    16,   112,   113,   114,   169,   115,   116,   148,    74,
      75,    76,    15,    77,   151,     3,     4,     5,     6,     7,
       8,    16,     9,    10,   152,    11,   153,   158,   159,   161,
      12,    13,    14,   164,   166,   167,   196,   168,   202,   178,
     172,   170,   204,   173,   228,     3,     4,     5,     6,     7,
       8,   181,     9,    10,   186,    11,   187,   190,    15,   191,
      12,    13,    14,     5,   197,   199,   198,    16,   201,   203,
     208,   196,   209,   219,   229,   196,   196,   214,   213,   222,
     196,   226,   220,   196,   225,   237,   239,   247,    15,   196,
     196,   192,   171,    99,   243,   196,   119,    16,   206,   196,
     210,   196,    87,    88,    89,    90,    91,   196,     3,     4,
       5,     6,     7,     8,   121,     9,    10,     0,    11,     0,
     238,     0,     0,    12,    13,    14,     3,     4,     5,     6,
       7,     8,     0,     9,    10,     0,    11,   232,     0,     0,
       0,    12,    13,    14,     0,    42,     0,     0,    43,     0,
       0,    15,     0,     0,     0,   235,     0,     0,     0,     0,
      16,    44,    45,    46,    47,    48,    49,    50,     0,    15,
     102,     0,     3,     4,     5,     6,     7,     8,    16,     9,
      10,     0,    11,     0,     0,     0,     0,    12,    13,    14,
       3,     4,     5,     6,     7,     8,     0,     9,    10,     0,
      11,   241,     0,     0,     0,    12,    13,    14,     0,    42,
       0,     0,    43,     0,     0,    15,     0,     0,   142,   244,
       0,     0,     0,     0,    16,    44,    45,    46,    47,    48,
      49,    50,     0,    15,     0,     0,     3,     4,     5,     6,
       7,     8,    16,     9,    10,     0,    11,     0,     0,     0,
       0,    12,    13,    14,     3,     4,     5,     6,     7,     8,
       0,     9,    10,     0,    11,   245,     0,     0,     0,    12,
      13,    14,     0,    42,     0,     0,    43,     0,     0,    15,
     160,     0,     0,   249,     0,     0,     0,     0,    16,    44,
      45,    46,    47,    48,    49,    50,     0,    15,     0,     0,
       3,     4,     5,     6,     7,     8,    16,     9,    10,     0,
      11,     0,     0,     0,   212,    12,    13,    14,   216,     0,
     217,     0,     0,     0,     0,     0,   221,     0,    42,     0,
     224,    43,     0,     0,     0,   230,   231,     0,     0,     0,
       0,     0,   236,    15,    44,    45,    46,    47,    48,    49,
      50,   240,    16,     0,   242,    83,    84,    85,    86,    87,
      88,    89,    90,    91,   248,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,    42,    92,
       0,    43,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,   147,    44,    45,    46,    47,    48,    67,
      50,     0,     0,     0,     0,     0,     0,   163,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
       0,     0,   182,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   111,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   120,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,     0,   138,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   246,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    78,    79,
      80,    81,    82,    83,   139,    85,    86,    87,    88,    89,
      90,    91
};

static const yytype_int16 yycheck[] =
{
       1,     6,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     3,     3,    17,
      18,    19,    20,    21,    22,    19,    24,    25,    61,    27,
      41,     3,    60,    38,    32,    33,    34,    42,    43,    60,
      22,    14,    15,    16,    41,    35,    36,    11,    53,    54,
      21,    51,    41,    47,    59,    60,    46,    41,    43,    35,
      36,    41,    60,    45,     3,    51,    60,    39,    40,    47,
      47,    69,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    47,    51,    17,
      18,    19,    20,    21,    22,   100,    24,    25,    37,    27,
      39,    40,    41,    48,    32,    33,    34,    51,    41,    17,
      18,    19,    20,    21,    22,    42,    24,    25,    46,    27,
      60,    48,    42,    42,    32,    33,    34,    42,    48,    48,
      47,    47,    60,    62,   139,     3,   141,    62,    46,    62,
      47,    69,    54,    55,    56,   150,    58,    59,    59,    39,
      40,    41,    60,    43,    42,    17,    18,    19,    20,    21,
      22,    69,    24,    25,    47,    27,    47,    41,    45,    41,
      32,    33,    34,    60,    45,    42,   177,    47,   183,    28,
      56,    47,   187,    11,    46,    17,    18,    19,    20,    21,
      22,    42,    24,    25,    42,    27,    35,    47,    60,    44,
      32,    33,    34,    19,    45,    30,    46,    69,    45,    45,
       9,   212,    45,    51,    46,   216,   217,    29,    45,    23,
     221,    31,    46,   224,    45,    45,    41,    45,    60,   230,
     231,   173,   154,    56,   239,   236,    71,    69,   188,   240,
     194,   242,    12,    13,    14,    15,    16,   248,    17,    18,
      19,    20,    21,    22,    76,    24,    25,    -1,    27,    -1,
     230,    -1,    -1,    32,    33,    34,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    -1,    27,    46,    -1,    -1,
      -1,    32,    33,    34,    -1,    38,    -1,    -1,    41,    -1,
      -1,    60,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      69,    54,    55,    56,    57,    58,    59,    60,    -1,    60,
      63,    -1,    17,    18,    19,    20,    21,    22,    69,    24,
      25,    -1,    27,    -1,    -1,    -1,    -1,    32,    33,    34,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    -1,
      27,    46,    -1,    -1,    -1,    32,    33,    34,    -1,    38,
      -1,    -1,    41,    -1,    -1,    60,    -1,    -1,    47,    46,
      -1,    -1,    -1,    -1,    69,    54,    55,    56,    57,    58,
      59,    60,    -1,    60,    -1,    -1,    17,    18,    19,    20,
      21,    22,    69,    24,    25,    -1,    27,    -1,    -1,    -1,
      -1,    32,    33,    34,    17,    18,    19,    20,    21,    22,
      -1,    24,    25,    -1,    27,    46,    -1,    -1,    -1,    32,
      33,    34,    -1,    38,    -1,    -1,    41,    -1,    -1,    60,
      45,    -1,    -1,    46,    -1,    -1,    -1,    -1,    69,    54,
      55,    56,    57,    58,    59,    60,    -1,    60,    -1,    -1,
      17,    18,    19,    20,    21,    22,    69,    24,    25,    -1,
      27,    -1,    -1,    -1,   197,    32,    33,    34,   201,    -1,
     203,    -1,    -1,    -1,    -1,    -1,   209,    -1,    38,    -1,
     213,    41,    -1,    -1,    -1,   218,   219,    -1,    -1,    -1,
      -1,    -1,   225,    60,    54,    55,    56,    57,    58,    59,
      60,   234,    69,    -1,   237,     8,     9,    10,    11,    12,
      13,    14,    15,    16,   247,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    38,    47,
      -1,    41,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    47,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    47,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    42,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    71,     0,    17,    18,    19,    20,    21,    22,    24,
      25,    27,    32,    33,    34,    60,    69,    72,    73,    74,
      75,    76,    77,    78,    79,    83,    84,    85,    86,    90,
      93,    97,    99,   103,   109,   110,   111,    61,    41,    60,
      80,    81,    38,    41,    54,    55,    56,    57,    58,    59,
      60,    92,    60,    41,    11,    21,    41,    47,    47,    41,
       3,    37,    39,    40,    41,    41,    47,    59,    92,     3,
      51,    48,    92,    92,    39,    40,    41,    43,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    47,    51,    92,    92,    51,    47,    60,    78,
     100,    92,    63,    92,    41,    47,    47,    92,    98,    60,
      42,    42,    54,    55,    56,    58,    59,    82,    62,    81,
      42,    98,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    62,    42,     9,
      62,     3,    47,    92,   101,    42,    47,    47,    59,    42,
      48,    42,    47,    47,     3,    43,    42,    44,    41,    45,
      45,    41,    92,    47,    60,   102,    45,    42,    47,    92,
      47,    82,    56,    11,    94,    95,    72,    96,    28,   104,
     105,    42,    47,     3,    39,    40,    42,    35,    87,    88,
      47,    44,    79,    42,    48,    46,    72,    45,    46,    30,
     106,    45,    92,    45,    92,    36,    88,    89,     9,    45,
      95,    91,    96,    45,    29,   107,    96,    96,    51,    51,
      46,    96,    23,    46,    96,    45,    31,   108,    46,    46,
      96,    96,    46,    22,    45,    46,    96,    45,   111,    41,
      96,    46,    96,    92,    46,    46,    42,    45,    96,    46
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
#line 119 "echo.y"
    { statement_count++; ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 120 "echo.y"
    { statement_count++; ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 121 "echo.y"
    { statement_count++; ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 122 "echo.y"
    { statement_count++; ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 123 "echo.y"
    { statement_count++; ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 124 "echo.y"
    { statement_count++; ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 125 "echo.y"
    { statement_count++; ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 126 "echo.y"
    { statement_count++; ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 127 "echo.y"
    { statement_count++; ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 128 "echo.y"
    { statement_count++; ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 129 "echo.y"
    { statement_count++; ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 130 "echo.y"
    { statement_count++; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 131 "echo.y"
    { statement_count++; ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 132 "echo.y"
    { statement_count++; ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 133 "echo.y"
    { statement_count++; ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 134 "echo.y"
    { statement_count++; ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 138 "echo.y"
    {
        VarNode* var = findVarNode((yyvsp[(3) - (5)].str));
        if (var && var->type == ARRAY_TYPE) {
            if (determineTypeFromArray(var->value.array.elements) != INT_TYPE) {
                yyerror("Only integer arrays can be sorted.");
            } else {
                bubbleSort((int*)var->value.array.elements, var->value.array.size);
                printf("Array %s sorted.\n", (yyvsp[(3) - (5)].str));
            }
        } else {
            yyerror("Variable is not an array or does not exist.");
        }
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 153 "echo.y"
    { printf("Import detected FROM BISON with path: %s\n", (yyvsp[(2) - (2)].str)); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 157 "echo.y"
    {
        printf("Continue statement detected.\n");
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 164 "echo.y"
    { printf("Print detected FROM BISON with message: %s\n", (yyvsp[(3) - (5)].str)); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 165 "echo.y"
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

  case 25:

/* Line 1455 of yacc.c  */
#line 197 "echo.y"
    { printf("Input detected FROM BISON for variable %s with message: %s\n", (yyvsp[(1) - (6)].str), (yyvsp[(4) - (6)].str)); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 214 "echo.y"
    { 
        if (varExists((yyvsp[(1) - (1)].str))) {
            printf("Variable collision detected for variable: %s\n", (yyvsp[(1) - (1)].str));
        } else {
            printf("<Invalid variable declaration %s> Pls include a type. read docs for mor information.\n URL: https://www.swift.org", (yyvsp[(1) - (1)].str));
        }
        free((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 222 "echo.y"
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

  case 32:

/* Line 1455 of yacc.c  */
#line 234 "echo.y"
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

  case 33:

/* Line 1455 of yacc.c  */
#line 266 "echo.y"
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

  case 34:

/* Line 1455 of yacc.c  */
#line 284 "echo.y"
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

  case 35:

/* Line 1455 of yacc.c  */
#line 327 "echo.y"
    { 
        (yyval.exprValue).value.intValue = (yyvsp[(1) - (1)].num);
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 331 "echo.y"
    {
        (yyval.exprValue).value.floatValue = (yyvsp[(1) - (1)].floatValue);
        (yyval.exprValue).type = FLOAT_TYPE;
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 335 "echo.y"
    {
        (yyval.exprValue).value.stringValue = (yyvsp[(1) - (1)].str);
        (yyval.exprValue).type = STRING_TYPE;
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 339 "echo.y"
    {
		(yyval.exprValue).value.charValue = (yyvsp[(1) - (1)].charValue);
        (yyval.exprValue).type = CHAR_TYPE;
	;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 343 "echo.y"
    {
		(yyval.exprValue).value.doubleValue = (yyvsp[(1) - (1)].doubleValue);
        (yyval.exprValue).type = DOUBLE_TYPE;
	;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 350 "echo.y"
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

  case 41:

/* Line 1455 of yacc.c  */
#line 421 "echo.y"
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

  case 42:

/* Line 1455 of yacc.c  */
#line 451 "echo.y"
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

  case 45:

/* Line 1455 of yacc.c  */
#line 484 "echo.y"
    {
        printf("Switch statement detected FROM BISON.\n");
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 495 "echo.y"
    {
        printf("Case clause detected FROM BISON.\n");
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 506 "echo.y"
    {
        printf("If with Else-If(s) statement detected FROM BISON.\n");
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 509 "echo.y"
    {
        printf("If with Else-If(s) and Else statement detected FROM BISON.\n");
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 515 "echo.y"
    {
        printf("Else-If clause detected FROM BISON.\n");
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 521 "echo.y"
    { 
		(yyval.exprValue).value.intValue = (yyvsp[(1) - (1)].num);
		(yyval.exprValue).type = INT_TYPE;
	;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 525 "echo.y"
    {
        (yyval.exprValue).value.floatValue = (yyvsp[(1) - (1)].floatValue); 
        (yyval.exprValue).type = FLOAT_TYPE;
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 529 "echo.y"
    {
        (yyval.exprValue).value.stringValue = strdup((yyvsp[(1) - (1)].str)); 
        (yyval.exprValue).type = STRING_TYPE;
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 533 "echo.y"
    {
        (yyval.exprValue).value.charValue = (yyvsp[(1) - (1)].charValue); 
        (yyval.exprValue).type = CHAR_TYPE;
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 537 "echo.y"
    {
        (yyval.exprValue).value.doubleValue = (yyvsp[(1) - (1)].doubleValue); 
        (yyval.exprValue).type = DOUBLE_TYPE;
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 541 "echo.y"
    {
        (yyval.exprValue).value.boolValue = (yyvsp[(1) - (1)].boolValue);
        (yyval.exprValue).type = BOOL_TYPE; 
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 545 "echo.y"
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

  case 64:

/* Line 1455 of yacc.c  */
#line 582 "echo.y"
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

  case 67:

/* Line 1455 of yacc.c  */
#line 604 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(1) - (3)].exprValue).value.intValue || (yyvsp[(3) - (3)].exprValue).value.intValue) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 608 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(1) - (3)].exprValue).value.intValue && (yyvsp[(3) - (3)].exprValue).value.intValue) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 612 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(1) - (3)].exprValue).value.intValue == (yyvsp[(3) - (3)].exprValue).value.intValue) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 616 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(1) - (3)].exprValue).value.intValue != (yyvsp[(3) - (3)].exprValue).value.intValue) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 620 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(1) - (3)].exprValue).value.intValue < (yyvsp[(3) - (3)].exprValue).value.intValue) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 624 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(1) - (3)].exprValue).value.intValue <= (yyvsp[(3) - (3)].exprValue).value.intValue) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 628 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(1) - (3)].exprValue).value.intValue > (yyvsp[(3) - (3)].exprValue).value.intValue) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 632 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(1) - (3)].exprValue).value.intValue >= (yyvsp[(3) - (3)].exprValue).value.intValue) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 636 "echo.y"
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

  case 76:

/* Line 1455 of yacc.c  */
#line 648 "echo.y"
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

  case 77:

/* Line 1455 of yacc.c  */
#line 661 "echo.y"
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

  case 78:

/* Line 1455 of yacc.c  */
#line 674 "echo.y"
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

  case 79:

/* Line 1455 of yacc.c  */
#line 696 "echo.y"
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

  case 80:

/* Line 1455 of yacc.c  */
#line 709 "echo.y"
    {
        (yyval.exprValue).value.intValue = ((yyvsp[(2) - (2)].exprValue).value.intValue == 0) ? 1 : 0;
        (yyval.exprValue).type = INT_TYPE;
    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 714 "echo.y"
    { printf("open_paren detected for expression \n"); (yyval.exprValue) = (yyvsp[(2) - (3)].exprValue); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 715 "echo.y"
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

  case 83:

/* Line 1455 of yacc.c  */
#line 736 "echo.y"
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

  case 84:

/* Line 1455 of yacc.c  */
#line 759 "echo.y"
    {
        printf("Function %s with return type %s declared.\n", (yyvsp[(2) - (10)].str), (yyvsp[(4) - (10)].str));
        free((yyvsp[(2) - (10)].str)); free((yyvsp[(4) - (10)].str)); function_count++;
    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 763 "echo.y"
    {
		printf("Main Function detected \n"); function_count++;
	;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 783 "echo.y"
    {
        printf("Function call detected FROM BISON: %s\n", (yyvsp[(1) - (5)].str));
    ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 795 "echo.y"
    {
        printf("For loop detected FROM BISON.\n");
    ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 819 "echo.y"
    {
        printf("While loop detected FROM BISON.\n");
    ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 832 "echo.y"
    { printf("Pre block detected FROM BISON.\n"); ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 837 "echo.y"
    { printf("Body block detected FROM BISON.\n"); ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 842 "echo.y"
    { printf("Post block detected FROM BISON.\n"); ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 847 "echo.y"
    { printf("Always block detected FROM BISON.\n"); ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 852 "echo.y"
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

  case 122:

/* Line 1455 of yacc.c  */
#line 873 "echo.y"
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

  case 123:

/* Line 1455 of yacc.c  */
#line 894 "echo.y"
    { printf("Break Statement Detected. \n"); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2891 "echo.tab.c"
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
#line 896 "echo.y"


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

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

VarType determineTypeFromArray(void* arrayElements) {
    // This is a simplified check. In a real scenario, you would need to store type information for each array.
    return INT_TYPE; // Assuming all arrays are integer arrays for this example.
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
