%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

extern int yylex();
void yyerror(char *s);


typedef enum { INT_TYPE, FLOAT_TYPE, CHAR_TYPE, DOUBLE_TYPE, STRING_TYPE } VarType;

typedef union {
    int intValue;
    float floatValue;
    char charValue;
    double doubleValue;
    char* stringValue;
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
void addVar(const char* name, VarValue value, VarType type);   // Function prototype
VarType determineType(const char* typeStr);
VarValue getVarValue(const char* name);
void printVarValue(const char* name);
VarNode* findVarNode(const char* name);
VarType mapIntToVarType(int typeInt);


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
}

%type <varValue> value
%type <exprValue> expression

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
%token <doubleValue> DOUBLE
%token <floatValue> FLOAT
%token <num> INTEGER
%token <charValue> CHAR_LITERAL
%token <str> STRING_LITERAL IDENTIFIER PATH TYPE
%token SINGLE_LINE_COMMENT_START MULTI_LINE_COMMENT_START MULTI_LINE_COMMENT_END ARRAY_INIT END




%%
// Grammar rules
program:
    | program statement
	| end_of_the_line
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
    ;

import_statement:
    IMPORT PATH { printf("Import detected FROM BISON with path: %s\n", $2); }
    ;

print_statement:
    PRINT OPEN_PAREN STRING_LITERAL CLOSE_PAREN SEMICOLON { printf("Print detected FROM BISON with message: %s\n", $3); }
	| PRINT OPEN_PAREN IDENTIFIER CLOSE_PAREN SEMICOLON { printf("Print detected FROM BISON with IDENTIFIER: %s\n", $3); printVarValue($3); }
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
    IDENTIFIER { 
        if (varExists($1)) {
            printf("Variable collision detected for variable: %s\n", $1);
        } else {
            printf("Variable declaration detected FROM BISON: %s\n", $1); 
            variable_count++; 
        }
        free($1);
    }
    | IDENTIFIER COLON TYPE { 
        if (varExists($1)) {
            printf("Variable collision detected for variable: %s\n", $1);
        } else {
            printf("Variable declaration detected FROM BISON, Type: %s\n", $3); free($3);
            variable_count++; 
        }
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
                    val.intValue = $5.intValue;
                    break;
                case FLOAT_TYPE:
                    val.floatValue = $5.floatValue;
                    break;
				case STRING_TYPE:
					val.stringValue = $5.stringValue;
					break;
				case CHAR_TYPE:
					val.charValue = $5.charValue;
					break;
				case DOUBLE_TYPE:
					val.doubleValue = $5.doubleValue;
					break;
            }
            addVar($1, val, type);
            printf("Variable declaration with type %s and Variable Name: %s\n", $3, $1);
            variable_count++;
        }
        free($1);
    }
    | IDENTIFIER COLON TYPE LBRACKET INTEGER RBRACKET { 
        if (varExists($1)) {
            printf("Variable collision detected for variable: %s\n", $1);
        } else {
            printf("Array declaration detected FROM BISON: %s of type %s with size %d\n", $1, $3, $5); free($3); 
            variable_count++; 
        }
        free($1);
    }
    | IDENTIFIER EQUALS INTEGER { 
        if (varExists($1)) {
            printf("Variable collision detected for variable: %s\n", $1);
        } else {
            printf("Variable assignment detected FROM BISON: %s = %d\n", $1, $3); 
            variable_count++; 
        }
        free($1);
    }
    ;

value:
    INTEGER { 
        $$.intValue = $1;
    }
    | FLOAT {
        $$.floatValue = $1;
    }
    | STRING_LITERAL {
        $$.stringValue = $1;
    }
	| CHAR_LITERAL {
		$$.charValue = $1;
	}
	| DOUBLE {
		$$.doubleValue = $1;
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
                        } else {
                            fprintf(stderr, "Type mismatch: Cannot assign non-integer to integer variable '%s'.\n", var->name);
                        }
                        break;

                    case FLOAT_TYPE:
                        if ($3.type == FLOAT_TYPE) {
                            var->value.floatValue = $3.value.floatValue;
                        } else {
                            fprintf(stderr, "Type mismatch: Cannot assign non-float to float variable '%s'.\n", var->name);
                        }
                        break;

                    case CHAR_TYPE:
                        if ($3.type == CHAR_TYPE) {
                            var->value.charValue = $3.value.charValue;
                        } else {
                            fprintf(stderr, "Type mismatch: Cannot assign non-char to char variable '%s'.\n", var->name);
                        }
                        break;

                    case DOUBLE_TYPE:
                        if ($3.type == DOUBLE_TYPE) {
                            var->value.doubleValue = $3.value.doubleValue;
                        } else {
                            fprintf(stderr, "Type mismatch: Cannot assign non-double to double variable '%s'.\n", var->name);
                        }
                        break;

                    case STRING_TYPE:
                        if ($3.type == STRING_TYPE) {
                            free(var->value.stringValue); // Free existing string
                            var->value.stringValue = strdup($3.value.stringValue);
                        } else {
                            fprintf(stderr, "Type mismatch: Cannot assign non-string to string variable '%s'.\n", var->name);
                        }
                        break;

                    default:
                        fprintf(stderr, "Unsupported variable type for variable '%s'.\n", var->name);
                }
            }
        } else {
            printf("Variable not declared: %s\n", $1);
        }
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
    	        default:
    	            yyerror("Unsupported variable type");
    	            break;
    	    }
    	} else {
    	    yyerror("Undefined variable");
    	}
	}
    | IDENTIFIER OPEN_PAREN argument_list CLOSE_PAREN 
    | expression EQUALS expression    %prec EQUALS   
    | expression OR_OP expression                    
    | expression AND_OP expression                    
    | expression EQUALS_EQUALS expression          
    | expression NOT_EQUAL expression                
    | expression LESS_THAN expression               
    | expression LESS_THAN_EQUAL expression        
    | expression GREATER_THAN expression     
    | expression GREATER_THAN_EQUAL expression        
    | expression PLUS expression                  
    | expression MINUS expression                    
    | expression MULT expression                      
    | expression DIV expression                       
    | expression MOD expression                   
    | NOT_OP expression                              
    | OPEN_PAREN expression CLOSE_PAREN              
    | IDENTIFIER INCREMENT                            
    | IDENTIFIER DECREMENT                            
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

end_of_the_line:
	END { printf("program terminates here"); }

%%

void addVar(const char* name, VarValue value, VarType type) {
    VarNode* newNode = (VarNode*) malloc(sizeof(VarNode));
    newNode->name = strdup(name);
    newNode->value = value;
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


VarType determineType(const char* typeStr) {
    if (strcmp(typeStr, "int") == 0) return INT_TYPE;
    if (strcmp(typeStr, "float") == 0) return FLOAT_TYPE;
	if (strcmp(typeStr, "string") == 0) return STRING_TYPE;
	if (strcmp(typeStr, "char") == 0) return CHAR_TYPE;
	if (strcmp(typeStr, "double") == 0) return DOUBLE_TYPE;
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
        default: return INT_TYPE;
    }
}

void yyerror(char *s) {
    fprintf(stderr, "error: %s\n", s);
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