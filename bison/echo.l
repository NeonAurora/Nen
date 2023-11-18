%{
#include <stdio.h>
#include <string.h>
#include <map> // Include map header for C++
#include <string>
#include "echo.tab.h"
std::map<std::string, std::string> varMap;
#include "counters.h"
int varCount = 0;
int smtCount = 0;
int functionCount = 0;
int arrCount = 0;
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
"pre"        { return PRE; }
"post"       { return POST; }
"always"     { return ALWAYS; }
"int"        { return TYPE; }
"float"      { return TYPE; }
"char"       { return TYPE; }
"double"     { return TYPE; }
"string"     { return TYPE; }
"{"          { return LBRACE; }  // Added LBRACE
"}"          { return RBRACE; }  // Added RBRACE
"("          { return OPEN_PAREN; }
")"          { return CLOSE_PAREN; }
"["          { return LBRACKET; }
"]"          { return RBRACKET; }
";"          { return SEMICOLON; }
","          { return COMMA; }
"'"          { return INVERTED_COMMA; }
"\""         { return DOUBLE_QUOTE; }
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
"=>>"        { return INPUT_OP; }
"//"         { return SINGLE_LINE_COMMENT_START; }
"<<"         { return MULTI_LINE_COMMENT_START; }
">>"         { return MULTI_LINE_COMMENT_END; }
"<-<-<>->->" { return END_PROGRAM; }
[0-9]+      { yylval.num = atoi(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z_0-9]* {  yylval.str = strdup(yytext); return IDENTIFIER; }
\"[^\"]*\" { yylval.str = strdup(yytext); return STRING_LITERAL; }
[a-zA-Z0-9_\/\.\-]+ { yylval.str = strdup(yytext); return PATH; }

%%

