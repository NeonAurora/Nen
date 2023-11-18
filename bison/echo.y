%{
#include <stdio.h>

extern int yylex();
void yyerror(char *s);
%}

%union {
    char *str;
    int num;
    // Other types as needed
}

%token IMPORT PRINT VAR RETURN FUNCTION IF ELSE WHILE MAIN END_PROGRAM FOR PRE POST BODY ALWAYS
%token INPUT_OP EQUALS LESS_THAN LESS_THAN_EQUAL GREATER_THAN GREATER_THAN_EQUAL EQUALS_EQUALS NOT_EQUAL
%token PLUS MINUS MULT DIV MOD AND_OP OR_OP NOT_OP
%token OPEN_PAREN CLOSE_PAREN LBRACKET RBRACKET LBRACE RBRACE SEMICOLON COMMA INVERTED_COMMA DOUBLE_QUOTE COLON BODY_START BODY_END
%token <str> STRING_LITERAL IDENTIFIER PATH
%token <num> NUMBER
%token SINGLE_LINE_COMMENT_START MULTI_LINE_COMMENT_START MULTI_LINE_COMMENT_END ARRAY_INIT TYPE



%%
// Grammar rules
program:
    | program statement
    ;

statement:
    import_statement
    | print_statement
    | input_statement
    ;

import_statement:
    IMPORT PATH { printf("Import detected FROM BISON with path: %s\n", $2); }
    ;

print_statement:
    PRINT OPEN_PAREN STRING_LITERAL CLOSE_PAREN SEMICOLON { printf("Print detected FROM BISON with message: %s\n", $3); }
    ;

input_statement:
    IDENTIFIER INPUT_OP OPEN_PAREN STRING_LITERAL CLOSE_PAREN SEMICOLON { printf("Input detected FROM BISON for variable %s with message: %s\n", $1, $4); }
    ;

%%

void yyerror(char *s) {
    fprintf(stderr, "error: %s\n", s);
}

int main() {
    printf("Starting the parser.\n");
    yyparse();
    return 0;
}
