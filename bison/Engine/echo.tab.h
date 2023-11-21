
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 148 "echo.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


