
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
     CHAR_LITERAL = 308,
     STRING_LITERAL = 309,
     IDENTIFIER = 310,
     PATH = 311,
     TYPE = 312,
     SINGLE_LINE_COMMENT_START = 313,
     MULTI_LINE_COMMENT_START = 314,
     MULTI_LINE_COMMENT_END = 315,
     ARRAY_INIT = 316,
     END = 317
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 49 "echo.y"

    char *str;
    int num;
	char charValue;
	float floatValue;
	double doubleValue;

	struct {
        union {
            int intValue;
            float floatValue;
            char charValue;
            double doubleValue;
            char* stringValue;
        } value;
        int type;
    } exprValue;

	union {
        int intValue;
        float floatValue;
        char charValue;
        double doubleValue;
        char* stringValue;
    } varValue;



/* Line 1676 of yacc.c  */
#line 143 "echo.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


