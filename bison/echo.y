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

%token IMPORT PRINT VAR RETURN FUNCTION IF ELSE WHILE MAIN END_PROGRAM FOR PRE POST BODY ALWAYS BREAK
%token INPUT_OP EQUALS LESS_THAN LESS_THAN_EQUAL GREATER_THAN GREATER_THAN_EQUAL EQUALS_EQUALS NOT_EQUAL
%token PLUS MINUS MULT DIV MOD AND_OP OR_OP NOT_OP INCREMENT DECREMENT
%token OPEN_PAREN CLOSE_PAREN LBRACKET RBRACKET LBRACE RBRACE SEMICOLON COMMA INVERTED_COMMA DOUBLE_QUOTE COLON BODY_START BODY_END
%token <str> STRING_LITERAL IDENTIFIER PATH TYPE
%token <num> NUMBER
%token SINGLE_LINE_COMMENT_START MULTI_LINE_COMMENT_START MULTI_LINE_COMMENT_END ARRAY_INIT



%%
// Grammar rules
program:
    | program statement
    ;

statement:
    import_statement
    | print_statement
    | input_statement
    | var_declaration
    | assignment_statement
	| function_declaration
	| return_statement
	| conditional_statement
	| for_statement
	| break_statement
	| increment_statement
	| decrement_statement
    ;

import_statement:
    IMPORT PATH { printf("Import detected FROM BISON with path: %s\n", $2); }
    ;

print_statement:
    PRINT OPEN_PAREN STRING_LITERAL CLOSE_PAREN SEMICOLON { printf("Print detected FROM BISON with message: %s\n", $3); }
	| PRINT OPEN_PAREN IDENTIFIER CLOSE_PAREN SEMICOLON { printf("Print detected FROM BISON with IDENTIFIER: %s\n", $3); }
    ;

input_statement:
    IDENTIFIER INPUT_OP OPEN_PAREN STRING_LITERAL CLOSE_PAREN SEMICOLON { printf("Input detected FROM BISON for variable %s with message: %s\n", $1, $4); }
    ;

var_declaration:
    VAR var_declaration_list SEMICOLON
    ;

var_declaration_list:
    var_decl 
    | var_declaration_list COMMA var_decl
    ;

var_decl:
    IDENTIFIER { printf("Variable declaration detected FROM BISON: %s\n", $1); }
    | IDENTIFIER COLON TYPE { printf("Variable declaration detected FROM BISON, Type: %s\n", $3); free($3); }
    | IDENTIFIER COLON TYPE EQUALS NUMBER { printf("Variable declaration detected FROM BISON, Type: %s Value: %d\n", $3, $5); free($3); }
    | IDENTIFIER COLON TYPE LBRACKET NUMBER RBRACKET { printf("Array declaration detected FROM BISON: %s of type %s with size %d\n", $1, $3, $5); free($3); }
    | IDENTIFIER EQUALS NUMBER { printf("Variable assignment detected FROM BISON: %s = %d\n", $1, $3); }
    ;

assignment_statement:
    IDENTIFIER EQUALS expression SEMICOLON {
        printf("Assignment detected FROM BISON: %s = <expression>\n", $1);
    }
    ;

return_statement:
    RETURN expression SEMICOLON {
        printf("Return statement detected FROM BISON.\n");
    }
    ;

conditional_statement:
    IF OPEN_PAREN condition CLOSE_PAREN LBRACE function_body RBRACE else_if_clauses {
        printf("If with Else-If(s) statement detected FROM BISON.\n");
    }
    | IF OPEN_PAREN condition CLOSE_PAREN LBRACE function_body RBRACE else_if_clauses ELSE LBRACE function_body RBRACE {
        printf("If with Else-If(s) and Else statement detected FROM BISON.\n");
    }
    ;

else_if_clauses:
    | else_if_clauses ELSE IF OPEN_PAREN condition CLOSE_PAREN LBRACE function_body RBRACE {
        printf("Else-If clause detected FROM BISON.\n");
    }
    ;

condition:
    expression relational_op expression {
        printf("Condition detected FROM BISON.\n");
    }
    ;

relational_op:
    LESS_THAN { printf("Less than operator\n"); }
    | LESS_THAN_EQUAL { printf("Less than or equal operator\n"); }
    | GREATER_THAN { printf("Greater than operator\n"); }
    | GREATER_THAN_EQUAL { printf("Greater than or equal operator\n"); }
    | EQUALS_EQUALS { printf("Equals operator\n"); }
    | NOT_EQUAL { printf("Not equal operator\n"); }

expression:
    term
    | expression PLUS term   { printf("Addition\n"); }
    | expression MINUS term  { printf("Subtraction\n"); }
    ;

term:
    factor
    | term MULT factor   { printf("Multiplication\n"); }
    | term DIV factor    { printf("Division\n"); }
    ;

factor:
    NUMBER
    | STRING_LITERAL
	| IDENTIFIER
    | OPEN_PAREN expression CLOSE_PAREN
    ;

function_declaration:
    FUNCTION IDENTIFIER COLON TYPE OPEN_PAREN param_list CLOSE_PAREN LBRACE function_body RBRACE {
        printf("Function %s with return type %s declared.\n", $2, $4);
        free($2); free($4);
    }
    ;

param_list:
    | param_list COMMA param
    | param
    ;

param:
    IDENTIFIER COLON TYPE { printf("Parameter: %s, Type: %s\n", $1, $3); free($1); free($3); }
    ;

function_body:
    | function_body statement
    | statement
    ;

for_statement:
    FOR OPEN_PAREN for_init for_condition for_increment CLOSE_PAREN LBRACE function_body RBRACE {
        printf("For loop detected FROM BISON.\n");
    }
    ;

for_init:
    var_declaration
    | IDENTIFIER EQUALS expression SEMICOLON
    | SEMICOLON
    ;

for_condition:
    condition SEMICOLON
    | SEMICOLON
    ;

for_increment:
    IDENTIFIER EQUALS expression
    | IDENTIFIER INCREMENT
    | IDENTIFIER DECREMENT
    | /* empty */
    ;

increment_statement:
	IDENTIFIER INCREMENT SEMICOLON { printf("Increment detected FROM BISON: %s++\n", $1); }

decrement_statement:
	IDENTIFIER DECREMENT SEMICOLON { printf("Decrement detected FROM BISON: %s--\n", $1); }

break_statement:
	BREAK SEMICOLON { printf("Break Statement Detected. \n"); }

%%



void yyerror(char *s) {
    fprintf(stderr, "error: %s\n", s);
}

int main() {
    printf("Starting the parser.\n");
    yyparse();
    return 0;
}
