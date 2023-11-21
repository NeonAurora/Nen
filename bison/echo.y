%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

extern int yylex();
void yyerror(char *s);


typedef enum { INT_TYPE, FLOAT_TYPE, CHAR_TYPE, DOUBLE_TYPE, STRING_TYPE, ARRAY_TYPE, BOOL_TYPE } VarType;

typedef union {
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
} VarValue;

typedef struct VarNode {
    char* name;
    VarValue value;
    VarType type;
    struct VarNode* next;
} VarNode;

typedef struct {
    VarValue value;
    VarType type;
} ExprValue;

VarNode* varList = NULL;

int varExists(const char* name); // Function prototype
void addVar(const char* name, VarValue* value, VarType type);   // Function prototype
VarType determineType(const char* typeStr);
VarValue getVarValue(const char* name);
void printVarValue(const char* name);
VarNode* findVarNode(const char* name);
VarType mapIntToVarType(int typeInt);
void freeVarValue(VarValue *value, VarType type);
void* allocateArrayElements(VarType type, int size);
void parseArrayLiteral(const char* literal, int** elements, int* size);
VarType determineTypeFromArray(void* arrayElements);
void bubbleSort(int arr[], int n);


int variable_count = 0;
int statement_count = 0;
int function_count = 0;
int array_count = 0;


%}

%union {
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
}

%type <exprValue> value
%type <exprValue> expression

%right EQUALS
%left OR_OP
%left AND_OP
%left EQUALS_EQUALS NOT_EQUAL
%left LESS_THAN LESS_THAN_EQUAL GREATER_THAN GREATER_THAN_EQUAL
%left PLUS MINUS
%left MULT DIV MOD

%token IMPORT PRINT VAR RETURN FUNCTION IF ELSE WHILE MAIN END_PROGRAM FOR PRE POST BODY ALWAYS BREAK CONTINUE SWITCH CASE DEFAULT
%token INPUT_OP
%token NOT_OP INCREMENT DECREMENT
%token OPEN_PAREN CLOSE_PAREN LBRACKET RBRACKET LBRACE RBRACE SEMICOLON COMMA INVERTED_COMMA DOUBLE_QUOTE COLON BODY_START BODY_END
%token <doubleValue> DOUBLE
%token <floatValue> FLOAT
%token <num> INTEGER
%token <boolValue> BOOL
%token <charValue> CHAR_LITERAL
%token <str> STRING_LITERAL IDENTIFIER PATH TYPE ARRAY_LITERAL
%token SINGLE_LINE_COMMENT_START MULTI_LINE_COMMENT_START MULTI_LINE_COMMENT_END ARRAY_INIT END SORT_ARRAY




%%
// Grammar rules
program:
    | program statement
    ;

statement:
    import_statement { statement_count++; }
    | print_statement { statement_count++; }
    | input_statement { statement_count++; }
    | var_declaration { statement_count++; }
    | assignment_statement { statement_count++; }
	| function_declaration { statement_count++; }
	| return_statement { statement_count++; }	
	| conditional_statement { statement_count++; }
	| for_statement { statement_count++; }
	| while_statement { statement_count++; }
	| break_statement { statement_count++; }
	| increment_statement { statement_count++; }
	| decrement_statement { statement_count++; }
	| function_call_statement { statement_count++; }
    | continue_statement { statement_count++; }
    | sort_statement { statement_count++; }
    ;

sort_statement:
    SORT_ARRAY OPEN_PAREN IDENTIFIER CLOSE_PAREN SEMICOLON {
        VarNode* var = findVarNode($3);
        if (var && var->type == ARRAY_TYPE) {
            if (determineTypeFromArray(var->value.array.elements) != INT_TYPE) {
                yyerror("Only integer arrays can be sorted.");
            } else {
                bubbleSort((int*)var->value.array.elements, var->value.array.size);
                printf("Array %s sorted.\n", $3);
            }
        } else {
            yyerror("Variable is not an array or does not exist.");
        }
    }

import_statement:
    IMPORT PATH { printf("Import detected FROM BISON with path: %s\n", $2); }
    ;

continue_statement:
    CONTINUE SEMICOLON {
        printf("Continue statement detected.\n");
    }
    ;


print_statement:
    PRINT OPEN_PAREN STRING_LITERAL CLOSE_PAREN SEMICOLON { printf("Print detected FROM BISON with message: %s\n", $3); }
    | PRINT OPEN_PAREN expression CLOSE_PAREN SEMICOLON {
        switch ($3.type) {
            case INT_TYPE:
                printf("Print detected of TYPE INT and value %d\n", $3.value.intValue);
                break;
            case FLOAT_TYPE:
                printf("Print detected of TYPE FLOAT and value %f\n", $3.value.floatValue);
                break;
            case CHAR_TYPE:
                printf("Print detected of TYPE CHAR and value %c\n", $3.value.charValue);
                break;
            case DOUBLE_TYPE:
                printf("Print detected of TYPE DOUBLE and value %lf\n", $3.value.doubleValue);
                break;
            case STRING_TYPE:
                if ($3.value.stringValue != NULL) {
                    printf("Print detected of TYPE STRING and value %s\n", $3.value.stringValue);
                } else {
                    printf("(null)\n");
                }
                break;
            case BOOL_TYPE:
                printf("Print detected of TYPE BOOL and value %d\n", $3.value.boolValue);
                break;
            default:
                printf("Unknown type for printing\n");
        }
    }
    ;


input_statement:
    IDENTIFIER INPUT_OP OPEN_PAREN STRING_LITERAL CLOSE_PAREN SEMICOLON { printf("Input detected FROM BISON for variable %s with message: %s\n", $1, $4); }
    ;

var_declaration:
    var_declaration_without_semicolon SEMICOLON
    ;

var_declaration_without_semicolon:
    VAR var_declaration_list
    ;

var_declaration_list:
    var_decl 
    | var_declaration_list COMMA var_decl
    ;

var_decl:
    IDENTIFIER { 
        if (varExists($1)) {
            printf("Variable collision detected for variable: %s\n", $1);
        } else {
            printf("<Invalid variable declaration %s> Pls include a type. read docs for mor information.\n URL: https://www.swift.org", $1);
        }
        free($1);
    }
    | IDENTIFIER COLON TYPE { 
        if (varExists($1)) {
            printf("Variable collision detected for variable: %s\n", $1);
        } else {
            VarType type = determineType($3);
            addVar($1, NULL, type); // Pass NULL as the value
            printf("Variable declaration detected FROM BISON, Type: %s\n", $3);
            variable_count++; 
        }
        free($3);
        free($1);
    }
    | IDENTIFIER COLON TYPE EQUALS value { 
        if (varExists($1)) {
            printf("Variable collision detected for variable: %s\n", $1);
        } else {
            VarType type = determineType($3);
            VarValue val;
            switch(type) {
                case INT_TYPE:
                    val.intValue = $5.value.intValue;
                    break;
                case FLOAT_TYPE:
                    val.floatValue = $5.value.floatValue;
                    break;
				case STRING_TYPE:
					val.stringValue = $5.value.stringValue;
					break;
				case CHAR_TYPE:
					val.charValue = $5.value.charValue;
					break;
				case DOUBLE_TYPE:
					val.doubleValue = $5.value.doubleValue;
					break;
                case BOOL_TYPE:
                    val.boolValue = $5.value.boolValue;
                    break;
            }
            addVar($1, &val, type);
            printf("Variable declaration with type %s and Variable Name: %s\n", $3, $1);
            variable_count++;
        }
        free($1);
    }
    | IDENTIFIER COLON TYPE LBRACKET INTEGER RBRACKET { 
        if (varExists($1)) {
            printf("Variable collision detected for variable: %s\n", $1);
        } else {
            VarType type = determineType($3);
            // Allocate and initialize array
            void* arrayElements = allocateArrayElements(type, $5);
            VarValue val;
            val.array.size = $5;
            val.array.elements = arrayElements;
            addVar($1, &val, ARRAY_TYPE); // ARRAY_TYPE is a new enum value to represent arrays
            printf("Array declaration detected FROM BISON: %s of type %s with size %d\n", $1, $3, $5);
            variable_count++;
        }
        free($3);
        free($1);
    }

    | IDENTIFIER EQUALS value { 
        if (varExists($1)) {
            printf("Variable collision detected for variable: %s\n", $1);
        } else {
            VarType type;
            VarValue val;

            switch ($3.type) {
                case INT_TYPE:
                    val.intValue = $3.value.intValue;
                    type = INT_TYPE;
                    break;
                case FLOAT_TYPE:
                    val.floatValue = $3.value.floatValue;
                    type = FLOAT_TYPE;
                    break;
                case CHAR_TYPE:
                    val.charValue = $3.value.charValue;
                    type = CHAR_TYPE;
                    break;
                case DOUBLE_TYPE:
                    val.doubleValue = $3.value.doubleValue;
                    type = DOUBLE_TYPE;
                    break;
                case STRING_TYPE:
                    val.stringValue = strdup($3.value.stringValue);
                    type = STRING_TYPE;
                    break;
                case BOOL_TYPE:
                    val.boolValue = $3.value.floatValue;
                    type = BOOL_TYPE;
                    break;

            }
            addVar($1, &val, type);
            printf("Variable declaration and assignment detected FROM BISON: %s\n", $1);
            variable_count++; 
        }
        free($1);
    }
    ;

value:
    INTEGER { 
        $$.value.intValue = $1;
        $$.type = INT_TYPE;
    }
    | FLOAT {
        $$.value.floatValue = $1;
        $$.type = FLOAT_TYPE;
    }
    | STRING_LITERAL {
        $$.value.stringValue = $1;
        $$.type = STRING_TYPE;
    }
	| CHAR_LITERAL {
		$$.value.charValue = $1;
        $$.type = CHAR_TYPE;
	}
	| DOUBLE {
		$$.value.doubleValue = $1;
        $$.type = DOUBLE_TYPE;
	}
    ;

assignment_statement:
    IDENTIFIER EQUALS expression SEMICOLON {
        if (varExists($1)) {
            VarNode* var = findVarNode($1);
            if (var) {
                switch (var->type) {
                    case INT_TYPE:
                        if ($3.type == INT_TYPE) {
                            var->value.intValue = $3.value.intValue;
                            printf("Variable %s assigned value of %d of type INT_TYPE \n", $1, $3.value.intValue);
                        } else {
                            fprintf(stderr, "Type mismatch: Cannot assign non-integer to integer variable '%s'.\n", var->name);
                        }
                        break;

                    case FLOAT_TYPE:
                        if ($3.type == FLOAT_TYPE) {
                            var->value.floatValue = $3.value.floatValue;
                            printf("Variable %s assigned value of %f of type FLOAT_TYPE \n", $1, $3.value.floatValue);
                        } else {
                            fprintf(stderr, "Type mismatch: Cannot assign non-float to float variable '%s'.\n", var->name);
                        }
                        break;

                    case CHAR_TYPE:
                        if ($3.type == CHAR_TYPE) {
                            var->value.charValue = $3.value.charValue;
                            printf("Variable %s assigned value of %c of type CHAR_TYPE \n", $1, $3.value.charValue);
                        } else {
                            fprintf(stderr, "Type mismatch: Cannot assign non-char to char variable '%s'.\n", var->name);
                        }
                        break;

                    case DOUBLE_TYPE:
                        if ($3.type == DOUBLE_TYPE) {
                            var->value.doubleValue = $3.value.doubleValue;
                            printf("Variable %s assigned value of %lf of type DOUBLE_TYPE \n", $1, $3.value.doubleValue);
                        } else {
                            fprintf(stderr, "Type mismatch: Cannot assign non-double to double variable '%s'.\n", var->name);
                        }
                        break;

                    case STRING_TYPE:
                        if ($3.type == STRING_TYPE) {
                            free(var->value.stringValue); // Free existing string
                            var->value.stringValue = strdup($3.value.stringValue);
                            printf("Variable %s assigned value of \"%s\" of type STRING_TYPE \n", $1, var->value.stringValue);
                        } else {
                            fprintf(stderr, "Type mismatch: Cannot assign non-string to string variable '%s'.\n", var->name);
                        }
                        break;
                    
                    case BOOL_TYPE:
                        if($3.type == BOOL_TYPE) {
                            var->value.boolValue = $3.value.boolValue;
                            
                        } else if ($3.type == INT_TYPE) {
                            var->value.boolValue = ($3.value.intValue != 0) ? 1 : 0;
                        } else {
                            fprintf(stderr, "Type mismatch: Cannot assign non-double to double variable '%s'.\n", var->name);
                        }
                        break;
                    default:
                        fprintf(stderr, "Unsupported variable type for variable '%s'.\n", var->name);
                        break;
                }
                freeVarValue(&var->value, var->type);  
            }
        } else {
            printf("Variable not declared: %s\n", $1);
        }
    }
    | IDENTIFIER EQUALS ARRAY_LITERAL SEMICOLON {
        if (varExists($1)) {
            VarNode* var = findVarNode($1);
            if (var && var->type == ARRAY_TYPE) {
                int* elements;
                int size;
                parseArrayLiteral($3, &elements, &size);
                if (size != var->value.array.size) {
                    printf("Size is %d\n", size);
                    printf("var size is %d\n", var->value.array.size);
                    yyerror("Array size mismatch");
                } else {
                    memcpy(var->value.array.elements, elements, size * sizeof(int));
                }
                free(elements); // Assuming parseArrayLiteral allocates memory for elements
            } else {
                yyerror("Variable is not an array");
            }
        } else {
            yyerror("Undefined variable");
        }
        free($3); // Free the literal string
    }
	;

value_list:
    INTEGER
    | value_list COMMA INTEGER

return_statement:
    RETURN expression SEMICOLON {
        switch($2.type) {
            case INT_TYPE:
                printf("Return statement with integer value: %d\n", $2.value.intValue);
                break;
            case FLOAT_TYPE:
                printf("Return statement with float value: %f\n", $2.value.floatValue);
                break;
            case STRING_TYPE:
                printf("Return statement with string value: \"%s\"\n", $2.value.stringValue);
                free($2.value.stringValue); // Don't forget to free the duplicated string
                break;
            case CHAR_TYPE:
                printf("Return statement with char value: '%c'\n", $2.value.charValue);
                break;
            case DOUBLE_TYPE:
                printf("Return statement with double value: %lf\n", $2.value.doubleValue);
                break;
            case BOOL_TYPE:
                printf("Return statement with bool value: %s\n", $2.value.boolValue ? "true" : "false");
                break;
            default:
                printf("Return statement with unknown type\n");
                break;
        }
    }
;

conditional_statement:
    if_conditional_statement
    | switch_conditional_statement

switch_conditional_statement:
    SWITCH OPEN_PAREN expression CLOSE_PAREN LBRACE case_clauses default_clause RBRACE {
        printf("Switch statement detected FROM BISON.\n");
    }
    ;

case_clauses:
    | case_clauses case_clause
    | case_clause
    ;

case_clause:
    CASE expression COLON function_body break_statement {
        printf("Case clause detected FROM BISON.\n");
    }
    ;

default_clause:
    | DEFAULT COLON function_body
    | /* Empty, for when no default clause is provided */
    ;

if_conditional_statement:
    IF OPEN_PAREN expression CLOSE_PAREN LBRACE function_body RBRACE else_if_clauses {
        printf("If with Else-If(s) statement detected FROM BISON.\n");
    }
    | IF OPEN_PAREN expression CLOSE_PAREN LBRACE function_body RBRACE else_if_clauses ELSE LBRACE function_body RBRACE {
        printf("If with Else-If(s) and Else statement detected FROM BISON.\n");
    }
    ;

else_if_clauses:
    | else_if_clauses ELSE IF OPEN_PAREN expression CLOSE_PAREN LBRACE function_body RBRACE {
        printf("Else-If clause detected FROM BISON.\n");
    }
    ;

expression:
     INTEGER { 
		$$.value.intValue = $1;
		$$.type = INT_TYPE;
	}
	| FLOAT {
        $$.value.floatValue = $1; 
        $$.type = FLOAT_TYPE;
    }
    | STRING_LITERAL {
        $$.value.stringValue = strdup($1); 
        $$.type = STRING_TYPE;
    }
    | CHAR_LITERAL {
        $$.value.charValue = $1; 
        $$.type = CHAR_TYPE;
    }
    | DOUBLE {
        $$.value.doubleValue = $1; 
        $$.type = DOUBLE_TYPE;
    }
    | BOOL {
        $$.value.boolValue = $1;
        $$.type = BOOL_TYPE; 
    }
    | IDENTIFIER {
    	VarNode* var = findVarNode($1);
    	if (var) {
    	    switch(var->type) {
    	        case INT_TYPE:
    	            $$.value.intValue = var->value.intValue;
    	            $$.type = INT_TYPE;
    	            break;
    	        case FLOAT_TYPE:
    	            $$.value.floatValue = var->value.floatValue;
    	            $$.type = FLOAT_TYPE;
    	            break;
    	        case CHAR_TYPE:
    	            $$.value.charValue = var->value.charValue;
    	            $$.type = CHAR_TYPE;
    	            break;
    	        case DOUBLE_TYPE:
    	            $$.value.doubleValue = var->value.doubleValue;
    	            $$.type = DOUBLE_TYPE;
    	            break;
    	        case STRING_TYPE:
    	            $$.value.stringValue = strdup(var->value.stringValue);
    	            $$.type = STRING_TYPE;
    	            break;
                case BOOL_TYPE:
                    $$.value.boolValue = var->value.boolValue;
                    $$.type = BOOL_TYPE;
                    break;
    	        default:
    	            yyerror("Unsupported variable type");
    	            break;
                freeVarValue(&var->value, var->type);
    	    }
    	} else {
    	    yyerror("Undefined variable");
    	}
	}
    | IDENTIFIER LBRACKET expression RBRACKET {
        VarNode* var = findVarNode($1);
        if (var && var->type == ARRAY_TYPE) {
            int index;
            if($3.type == INT_TYPE) {
                index = $3.value.intValue;
            } else {
                fprintf(stderr, "Array index must be an integer\n");
                return -1;
            }
            if (index >= 0 && index < var->value.array.size) {
                $$.value.intValue = ((int*)var->value.array.elements)[index];
                $$.type = INT_TYPE;
            } else {
                yyerror("Array index out of bounds");
            }
        } else {
            yyerror("Variable is not an array");
        }
    }
    | IDENTIFIER OPEN_PAREN argument_list CLOSE_PAREN 
    | expression EQUALS expression    %prec EQUALS   
    | expression OR_OP expression {
        $$.value.intValue = ($1.value.intValue || $3.value.intValue) ? 1 : 0;
        $$.type = INT_TYPE;
    }         
    | expression AND_OP expression {
        $$.value.intValue = ($1.value.intValue && $3.value.intValue) ? 1 : 0;
        $$.type = INT_TYPE;
    }       
    | expression EQUALS_EQUALS expression {
        $$.value.intValue = ($1.value.intValue == $3.value.intValue) ? 1 : 0;
        $$.type = INT_TYPE;
    }
    | expression NOT_EQUAL expression {
        $$.value.intValue = ($1.value.intValue != $3.value.intValue) ? 1 : 0;
        $$.type = INT_TYPE;
    }                
    | expression LESS_THAN expression {
        $$.value.intValue = ($1.value.intValue < $3.value.intValue) ? 1 : 0;
        $$.type = INT_TYPE;
    }
    | expression LESS_THAN_EQUAL expression {
        $$.value.intValue = ($1.value.intValue <= $3.value.intValue) ? 1 : 0;
        $$.type = INT_TYPE;
    }
    | expression GREATER_THAN expression {
        $$.value.intValue = ($1.value.intValue > $3.value.intValue) ? 1 : 0;
        $$.type = INT_TYPE;
    }
    | expression GREATER_THAN_EQUAL expression {
        $$.value.intValue = ($1.value.intValue >= $3.value.intValue) ? 1 : 0;
        $$.type = INT_TYPE;
    }       
    | expression PLUS expression {
        if ($1.type == INT_TYPE && $3.type == INT_TYPE) {
            $$.value.intValue = $1.value.intValue + $3.value.intValue;
            $$.type = INT_TYPE;
        } else if (($1.type == INT_TYPE || $1.type == FLOAT_TYPE) &&
                   ($3.type == INT_TYPE || $3.type == FLOAT_TYPE)) {
            $$.value.floatValue = ($1.type == INT_TYPE ? (float)$1.value.intValue : $1.value.floatValue) + ($3.type == INT_TYPE ? (float)$3.value.intValue : $3.value.floatValue);
            $$.type = FLOAT_TYPE;
        } else {
            yyerror("Type mismatch in addition operation");
        }
    }      
    | expression MINUS expression {
        if ($1.type == INT_TYPE && $3.type == INT_TYPE) {
            $$.value.intValue = $1.value.intValue - $3.value.intValue;
            $$.type = INT_TYPE;
        } else if (($1.type == INT_TYPE || $1.type == FLOAT_TYPE) &&
                   ($3.type == INT_TYPE || $3.type == FLOAT_TYPE)) {
            $$.value.floatValue = ($1.type == INT_TYPE ? (float)$1.value.intValue : $1.value.floatValue) - ($3.type == INT_TYPE ? (float)$3.value.intValue : $3.value.floatValue);
            $$.type = FLOAT_TYPE;
        } else {
            yyerror("Type mismatch in subtraction operation");
        }
    }
                    
    | expression MULT expression {
        if ($1.type == INT_TYPE && $3.type == INT_TYPE) {
            $$.value.intValue = $1.value.intValue * $3.value.intValue;
            $$.type = INT_TYPE;
        } else if (($1.type == INT_TYPE || $1.type == FLOAT_TYPE) &&
                   ($3.type == INT_TYPE || $3.type == FLOAT_TYPE)) {
            $$.value.floatValue = ($1.type == INT_TYPE ? (float)$1.value.intValue : $1.value.floatValue) * ($3.type == INT_TYPE ? (float)$3.value.intValue : $3.value.floatValue);
            $$.type = FLOAT_TYPE;
        } else {
            yyerror("Type mismatch in multiplication operation");
        }
    }
                      
    | expression DIV expression {
        if ($1.type == INT_TYPE && $3.type == INT_TYPE) {
            if ($3.value.intValue == 0) {
                yyerror("Division by zero");
                break;
            }
            $$.value.intValue = $1.value.intValue / $3.value.intValue;
            $$.type = INT_TYPE;
        } else if (($1.type == INT_TYPE || $1.type == FLOAT_TYPE) &&
                   ($3.type == INT_TYPE || $3.type == FLOAT_TYPE)) {
            float divisor = ($3.type == INT_TYPE ? (float)$3.value.intValue : $3.value.floatValue);
            if (divisor == 0.0) {
                yyerror("Division by zero");
                break;
            }
            $$.value.floatValue = ($1.type == INT_TYPE ? (float)$1.value.intValue : $1.value.floatValue) / divisor;
            $$.type = FLOAT_TYPE;
        } else {
            yyerror("Type mismatch in division operation");
        }
    }
                       
    | expression MOD expression {
        if ($1.type == INT_TYPE && $3.type == INT_TYPE) {
            if ($3.value.intValue == 0) {
                yyerror("Modulo by zero");
                break;
            }
            $$.value.intValue = $1.value.intValue % $3.value.intValue;
            $$.type = INT_TYPE;
        } else {
            yyerror("Modulo operation only valid for integers");
        }
    }
                   
    | NOT_OP expression {
        $$.value.intValue = ($2.value.intValue == 0) ? 1 : 0;
        $$.type = INT_TYPE;
    }
                             
    | OPEN_PAREN expression CLOSE_PAREN { printf("open_paren detected for expression \n"); $$ = $2; }         
    | IDENTIFIER INCREMENT {
        printf("IDENTIFIER increment detected \n");
        VarNode* var = findVarNode($1);
        if (var) {
            switch(var->type) {
                case INT_TYPE:
                    int a;
                    a = var->value.intValue;
                    a = a + 1;
                    $$.value.intValue = a;
                    $$.type = INT_TYPE;
                    break;
                // You can add cases for other types if incrementing them makes sense in your language
                default:
                    yyerror("Increment operation not supported for this type");
            }
        } else {
            yyerror("Undefined variable");
        }
    }

    | IDENTIFIER DECREMENT {
        VarNode* var = findVarNode($1);
        printf("IDENTIFIER decrement detected \n");
        if (var) {
            switch(var->type) {
                case INT_TYPE:
                    int a;
                    a = var->value.intValue;
                    a = a - 1;
                    $$.value.intValue = a;
                    break;
                // You can add cases for other types if decrementing them makes sense in your language
                default:
                    yyerror("Decrement operation not supported for this type");
            }
        } else {
            yyerror("Undefined variable");
        }
    }
                            
    ;

function_declaration:
    FUNCTION IDENTIFIER COLON TYPE OPEN_PAREN param_list CLOSE_PAREN LBRACE function_body RBRACE {
        printf("Function %s with return type %s declared.\n", $2, $4);
        free($2); free($4); function_count++;
    }
	| MAIN FUNCTION COLON TYPE OPEN_PAREN CLOSE_PAREN LBRACE function_body RBRACE {
		printf("Main Function detected \n"); function_count++;
	}
    ;

param_list:
    | param_list COMMA param
    | param
    ;

param:
    LESS_THAN var_declaration_without_semicolon GREATER_THAN
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
    expression SEMICOLON
    | SEMICOLON
    ;

for_increment:
    IDENTIFIER EQUALS expression
    | IDENTIFIER INCREMENT
    | IDENTIFIER DECREMENT
    | /* empty */
    ;

while_statement:
    WHILE LESS_THAN expression GREATER_THAN LBRACE while_body RBRACE {
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
	IDENTIFIER INCREMENT SEMICOLON {
        printf("increament_statment detected \n");
        VarNode* var = findVarNode($1);
        if (var) {
            switch(var->type) {
                case INT_TYPE:
                    int a;
                    a = var->value.intValue;
                    a = a + 1;
                    var->value.intValue = a;        
                    break;
                // You can add cases for other types if incrementing them makes sense in your language
                default:
                    yyerror("Increment operation not supported for this type");
            }
        } else {
            yyerror("Undefined variable");
        }
    }

decrement_statement:
	IDENTIFIER DECREMENT SEMICOLON {
        printf("decrement_statement detected \n");
        VarNode* var = findVarNode($1);
        if (var) {
            switch(var->type) {
                case INT_TYPE:
                    int a;
                    a = var->value.intValue;
                    a = a - 1;
                    var->value.intValue = a;
                    break;
                // You can add cases for other types if decrementing them makes sense in your language
                default:
                    yyerror("Decrement operation not supported for this type");
            }
        } else {
            yyerror("Undefined variable");
        }
    }
    ; 
break_statement:
	BREAK SEMICOLON { printf("Break Statement Detected. \n"); }

%%

void addVar(const char* name, VarValue* value, VarType type) {
    VarNode* newNode = (VarNode*) malloc(sizeof(VarNode));
    newNode->name = strdup(name);
    if (value != NULL) {
        newNode->value = *value;
    } else {
        // Set default values based on the type
        switch (type) {
            case INT_TYPE:
                newNode->value.intValue = 0;
                break;
            case FLOAT_TYPE:
                newNode->value.floatValue = 0.0; 
                break;
            case CHAR_TYPE:
                newNode->value.charValue = '\0'; 
                break;
            case DOUBLE_TYPE:
                newNode->value.doubleValue = 0.0; 
                break;
            case STRING_TYPE:
                newNode->value.stringValue = NULL; 
                break;
            case BOOL_TYPE:
                newNode->value.intValue = 0;
        }
    }
    newNode->type = type;
    newNode->next = varList;
    varList = newNode;
}


int varExists(const char* name) {
    VarNode* current = varList;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

VarValue getVarValue(const char* name) {
    VarNode* current = varList;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->value;
        }
        current = current->next;
    }
    // Return a default value if not found, or handle the error as needed
    /* return (VarValue){ .intValue = 0 };  */
}

void printVarValue(const char* name) {
    VarValue val = getVarValue(name);
    VarNode* varNode = findVarNode(name);

    if (varNode == NULL) {
        printf("Variable '%s' not found.\n", name);
        return;
    }

    switch (varNode->type) {
        case INT_TYPE:
            printf("Value of %s is %d and Type is Integer\n", name, val.intValue);
            break;
        case FLOAT_TYPE:
            printf("Value of %s is %f and Type is Float\n", name, val.floatValue);
            break;
        case DOUBLE_TYPE:
            printf("Value of %s is %lf and Type is Double\n", name, val.doubleValue);
            break;
        case CHAR_TYPE:
            printf("Value of %s is '%c' and Type is Character\n", name, val.charValue);
            break;
        case STRING_TYPE:
            printf("Value of %s is \"%s\"  and Type is String\n", name, val.stringValue);
            break;
        case BOOL_TYPE:
            printf("Value of %s is %d and Type is BOOL\n", name, val.boolValue);
            break;
        default:
            printf("Unknown type for variable %s.\n", name);
    }
}


VarNode* findVarNode(const char* name) {
    VarNode* current = varList;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

VarType determineTypeFromArray(void* arrayElements) {
    // This is a simplified check. In a real scenario, you would need to store type information for each array.
    return INT_TYPE; // Assuming all arrays are integer arrays for this example.
}




VarType determineType(const char* typeStr) {
    if (strcmp(typeStr, "int") == 0) return INT_TYPE;
    if (strcmp(typeStr, "float") == 0) return FLOAT_TYPE;
	if (strcmp(typeStr, "string") == 0) return STRING_TYPE;
	if (strcmp(typeStr, "char") == 0) return CHAR_TYPE;
	if (strcmp(typeStr, "double") == 0) return DOUBLE_TYPE;
    if (strcmp(typeStr, "bool") == 0) return BOOL_TYPE;
    // ... other type cases
    return INT_TYPE; // Default case, or you could handle error here
}

VarType mapIntToVarType(int typeInt) {
    switch (typeInt) {
        case 0: return INT_TYPE;
        case 1: return FLOAT_TYPE;
        case 2: return CHAR_TYPE;
        case 3: return DOUBLE_TYPE;
        case 4: return STRING_TYPE;
        case 5: return BOOL_TYPE;
        default: return INT_TYPE;
    }
}

void* allocateArrayElements(VarType type, int size) {
    void* elements = NULL;
    switch (type) {
        case INT_TYPE:
            elements = malloc(size * sizeof(int));
            break;
        case FLOAT_TYPE:
            elements = malloc(size * sizeof(float));
            break;
        // Add cases for other types...
        default:
            fprintf(stderr, "Unsupported array type.\n");
    }
    return elements;
}

void parseArrayLiteral(const char* literal, int** elements, int* size) {
    // Initial size
    int capacity = 10;
    *elements = (int*)malloc(capacity * sizeof(int));
    *size = 0;

    if (!*elements) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Tokenize the string
    const char* delim = "<[],>";
    char* copyLiteral = strdup(literal);
    char* token = strtok(copyLiteral, delim);
    while (token != NULL) {
        if (*size >= capacity) {
            capacity *= 2;
            int* temp = (int*)realloc(*elements, capacity * sizeof(int));
            if (!temp) {
                // Handle memory allocation failure
                fprintf(stderr, "Memory allocation failed during resizing\n");
                free(*elements);
                free(copyLiteral);
                return;
            }
            *elements = temp;
        }
        (*elements)[*size] = atoi(token);
        (*size)++;
        token = strtok(NULL, delim);
    }

    free(copyLiteral); // Don't forget to free the copy
}

void yyerror(char *s) {
    fprintf(stderr, "error: %s\n", s);
}

void freeVarValue(VarValue *value, VarType type) {
    if (type == STRING_TYPE && value->stringValue != NULL) {
        free(value->stringValue);
        value->stringValue = NULL;
    }
}

void freeVarList() {
    VarNode* current = varList;
    while (current != NULL) {
        VarNode* temp = current;
        current = current->next;
        free(temp->name);
        free(temp);
    }
}

int main() {
    printf("Starting the parser.\n");
    yyparse();
	printf("\nCounts:\n");
    printf("Variables: %d\n", variable_count);
    printf("Statements: %d\n", statement_count);
    printf("Functions: %d\n", function_count);
    printf("Arrays: %d\n", array_count);
	freeVarList();
    return 0;
}