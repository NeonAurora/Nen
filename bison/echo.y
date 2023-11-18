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

%right EQUALS
%left OR_OP
%left AND_OP
%left EQUALS_EQUALS NOT_EQUAL
%left LESS_THAN LESS_THAN_EQUAL GREATER_THAN GREATER_THAN_EQUAL
%left PLUS MINUS
%left MULT DIV MOD

%token IMPORT PRINT VAR RETURN FUNCTION IF ELSE WHILE MAIN END_PROGRAM FOR PRE POST BODY ALWAYS BREAK
%token INPUT_OP
%token NOT_OP INCREMENT DECREMENT
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
	| while_statement
	| break_statement
	| increment_statement
	| decrement_statement
	| function_call_statement
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
        printf("Return statement detected FROM BISON with <expression>\n");
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
    expression EQUALS_EQUALS expression   
    | expression NOT_EQUAL expression              
    | expression LESS_THAN expression                
    | expression LESS_THAN_EQUAL expression          
    | expression GREATER_THAN expression              
    | expression GREATER_THAN_EQUAL expression

expression:
      NUMBER { printf("%d", $1); }
    | STRING_LITERAL
    | IDENTIFIER
    | IDENTIFIER OPEN_PAREN argument_list CLOSE_PAREN  // Function call
    | expression EQUALS expression    %prec EQUALS    // Assignment
    | expression OR_OP expression                     // Logical OR
    | expression AND_OP expression                    // Logical AND
    | expression EQUALS_EQUALS expression             // Equality
    | expression NOT_EQUAL expression                 // Inequality
    | expression LESS_THAN expression                 // Less than
    | expression LESS_THAN_EQUAL expression           // Less than or equal
    | expression GREATER_THAN expression              // Greater than
    | expression GREATER_THAN_EQUAL expression        // Greater than or equal
    | expression PLUS expression                      // Addition
    | expression MINUS expression                     // Subtraction
    | expression MULT expression                      // Multiplication
    | expression DIV expression                       // Division
    | expression MOD expression                       // Modulus
    | NOT_OP expression                               // Logical NOT
    | OPEN_PAREN expression CLOSE_PAREN               // Parenthesized expression
    | IDENTIFIER INCREMENT                            // Post-increment
    | IDENTIFIER DECREMENT                            // Post-decrement
    ;

function_declaration:
    FUNCTION IDENTIFIER COLON TYPE OPEN_PAREN param_list CLOSE_PAREN LBRACE function_body RBRACE {
        printf("Function %s with return type %s declared.\n", $2, $4);
        free($2); free($4);
    }
	| MAIN FUNCTION COLON TYPE OPEN_PAREN CLOSE_PAREN LBRACE function_body RBRACE {
		printf("Main Function detected \n");
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

function_call_statement:
    IDENTIFIER OPEN_PAREN argument_list CLOSE_PAREN SEMICOLON {
        printf("Function call detected FROM BISON: %s\n", $1);
    }
    ;

argument_list:
      /* empty */                                    // No arguments
    | expression                                     // Single argument
    | argument_list COMMA expression                 // Multiple arguments
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

while_statement:
    WHILE LESS_THAN condition GREATER_THAN LBRACE while_body RBRACE {
        printf("While loop detected FROM BISON.\n");
    }
    ;

while_body:
    pre_block
    body_block
    post_block
    always_block
    ;

pre_block:
    | PRE LBRACE function_body RBRACE { printf("Pre block detected FROM BISON.\n"); }
    | /* empty */
    ;

body_block:
    | BODY LBRACE function_body RBRACE { printf("Body block detected FROM BISON.\n"); }
    | /* empty */
    ;

post_block:
    | POST LBRACE function_body RBRACE { printf("Post block detected FROM BISON.\n"); }
    | /* empty */
    ;

always_block:
    | ALWAYS LBRACE function_body RBRACE { printf("Always block detected FROM BISON.\n"); }
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
