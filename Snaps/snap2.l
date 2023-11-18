%{
#include <stdio.h>
#include <string.h>
%}

%option noyywrap

%%

"//"[^"\n"]*               { printf("Single-line comment detected: %s\n", yytext); }
"<<"[^">"]*">>"            { printf("Multi-line comment detected: %s\n", yytext); }
"var"                     { printf("Variable declaration keyword detected: %s\n", yytext); }
"int"                     { printf("Data type detected: %s\n", yytext); }
"float"                   { printf("Data type detected: %s\n", yytext); }
"double"                  { printf("Data type detected: %s\n", yytext); }
"char"                    { printf("Data type detected: %s\n", yytext); }
"if"                      { printf("If keyword detected: %s\n", yytext); }
"else"                    { printf("Else keyword detected: %s\n", yytext); }
"for"                     { printf("For loop keyword detected: %s\n", yytext); }
[a-zA-Z_][a-zA-Z_0-9]*    { printf("Identifier detected: %s\n", yytext); }
":"                       { printf("Type separator detected: %s\n", yytext); }
"="                       { printf("Assignment operator detected: %s\n", yytext); }
[0-9]+                    { printf("Integer literal detected: %s\n", yytext); }
[0-9]+"."[0-9]+           { printf("Floating-point literal detected: %s\n", yytext); }
"\"[^\"]*\""              { printf("String literal detected: %s\n", yytext); }
"\'[^\']*\'"              { printf("Character literal detected: %s\n", yytext); }
";"                       { printf("Statement end detected: %s\n", yytext); }
"+"|"-"|"*"|"/"|"%"       { printf("Arithmetic operator detected: %s\n", yytext); }
"<"|"<="|">"|">="|"=="|"!=" { printf("Relational operator detected: %s\n", yytext); }
"&&"|"||"|"!"             { printf("Logical operator detected: %s\n", yytext); }
"("|")"                   { printf("Round parenthesis detected: %s\n", yytext); }
"{"|"}"                   { printf("Curly braces detected: %s\n", yytext); }
"["|"]"                   { printf("Square parenthesis detected: %s\n", yytext); }
[a-zA-Z_][a-zA-Z_0-9]*[ \t]*\([^;\n]*\)[ \t]* { printf("Function header detected: %s\n", yytext); }
[ \t\n]+                  { /* ignore whitespace */ }
.                         { printf("Unrecognized character: %s\n", yytext); }

%%

int main() {
  yylex();
  return 0;
}
