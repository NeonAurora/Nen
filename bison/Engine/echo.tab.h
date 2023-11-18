
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
     INPUT_OP = 273,
     EQUALS = 274,
     LESS_THAN = 275,
     LESS_THAN_EQUAL = 276,
     GREATER_THAN = 277,
     GREATER_THAN_EQUAL = 278,
     EQUALS_EQUALS = 279,
     NOT_EQUAL = 280,
     PLUS = 281,
     MINUS = 282,
     MULT = 283,
     DIV = 284,
     MOD = 285,
     AND_OP = 286,
     OR_OP = 287,
     NOT_OP = 288,
     OPEN_PAREN = 289,
     CLOSE_PAREN = 290,
     LBRACKET = 291,
     RBRACKET = 292,
     LBRACE = 293,
     RBRACE = 294,
     SEMICOLON = 295,
     COMMA = 296,
     INVERTED_COMMA = 297,
     DOUBLE_QUOTE = 298,
     COLON = 299,
     BODY_START = 300,
     BODY_END = 301,
     STRING_LITERAL = 302,
     IDENTIFIER = 303,
     PATH = 304,
     NUMBER = 305,
     SINGLE_LINE_COMMENT_START = 306,
     MULTI_LINE_COMMENT_START = 307,
     MULTI_LINE_COMMENT_END = 308,
     ARRAY_INIT = 309,
     TYPE = 310
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
#line 115 "echo.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


