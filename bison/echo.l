%{
#include <stdio.h>
#include <string.h>
#include <map> // Include map header for C++
#include <string>
#include "echo.tab.h"
%}


%option noyywrap

%%


"import"     { return IMPORT; }
"print"      { return PRINT; }
"var"        { return VAR; }
"return"     { return RETURN; }
"function"   { return FUNCTION; }
"main"       { return MAIN; }
"if"         { return IF; }
"else"       { return ELSE; }
"while"      { return WHILE; }
"for"        { return FOR;}
"pre"        { return PRE; }
"body"       { return BODY; }
"post"       { return POST; }
"always"     { return ALWAYS; }
"int"        { yylval.str = strdup("int"); return TYPE; }
"float"      { yylval.str = strdup("float"); return TYPE; }
"char"       { yylval.str = strdup("char"); return TYPE; }
"double"     { yylval.str = strdup("double"); return TYPE; }
"string"     { yylval.str = strdup("string"); return TYPE; }
"break"      { return BREAK; }
"{"          { return LBRACE; }  
"}"          { return RBRACE; } 
"("          { return OPEN_PAREN; }
")"          { return CLOSE_PAREN; }
"["          { return LBRACKET; }
"]"          { return RBRACKET; }
";"          { return SEMICOLON; }
":"          { return COLON; }
","          { return COMMA; }
"'"          { return INVERTED_COMMA; }
"\""         { return DOUBLE_QUOTE; }
"="          { return EQUALS; }
"<"          { return LESS_THAN; }
"<="         { return LESS_THAN_EQUAL; }
">"          { return GREATER_THAN; }
">="         { return GREATER_THAN_EQUAL; }
"=="         { return EQUALS_EQUALS; }
"!="         { return NOT_EQUAL; }
"+"          { return PLUS; }
"-"          { return MINUS; }
"*"          { return MULT; }
"/"          { return DIV; }
"%"          { return MOD; }
"++"         { return INCREMENT; }
"--"         { return DECREMENT; }
"=>>"        { return INPUT_OP; }
"//"         { return SINGLE_LINE_COMMENT_START; }
"<<"         { return MULTI_LINE_COMMENT_START; }
">>"         { return MULTI_LINE_COMMENT_END; }
"<-<-<>->->" { return END_PROGRAM; return END; }
@[+-]?[0-9]+\.?[0-9]*([eE][+-]?[0-9]+)? { 
    char* numberPart = strdup(yytext + 1);
    printf("NumberPart = %s\n", numberPart);
    yylval.doubleValue = strtod(numberPart, NULL); 
    return DOUBLE; }
[0-9]+"."[0-9]+    { yylval.floatValue = atof(yytext); return FLOAT; }
[0-9]+      { yylval.num = atoi(yytext); return INTEGER; }
[a-zA-Z_][a-zA-Z_0-9]* { yylval.str = strdup(yytext); return IDENTIFIER; }
\'[^\'\\n]\' { yylval.charValue = yytext[1]; return CHAR_LITERAL; }
\"[^\"]*\" { yylval.str = strdup(yytext); return STRING_LITERAL; }
[a-zA-Z0-9_\/\.]+ { yylval.str = strdup(yytext); return PATH; }

%%

