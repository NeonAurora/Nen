
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
     IMPORT = 258,
     PRINT = 259,
     VAR = 260,
     RETURN = 261,
     FUNCTION = 262,
     IF = 263,
     ELSE = 264,
     WHILE = 265,
     MAIN = 266,
     END_PROGRAM = 267,
     FOR = 268,
     PRE = 269,
     POST = 270,
     BODY = 271,
     ALWAYS = 272,
     BREAK = 273,
     INPUT_OP = 274,
     EQUALS = 275,
     LESS_THAN = 276,
     LESS_THAN_EQUAL = 277,
     GREATER_THAN = 278,
     GREATER_THAN_EQUAL = 279,
     EQUALS_EQUALS = 280,
     NOT_EQUAL = 281,
     PLUS = 282,
     MINUS = 283,
     MULT = 284,
     DIV = 285,
     MOD = 286,
     AND_OP = 287,
     OR_OP = 288,
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

/* Line 1676 of yacc.c  */
#line 8 "echo.y"

    char *str;
    int num;
    // Other types as needed



/* Line 1676 of yacc.c  */
#line 118 "echo.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


