
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

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 144 "echo.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


