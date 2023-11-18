%{
#include <stdio.h>
%}

%token NUMBER

%%
/* Define your grammar rules here */
line: 
    | line expr '\n' { printf("Result = %d\n", $2); }
    ;

expr:
      NUMBER                { $$ = $1; }
    | expr '+' expr         { $$ = $1 + $3; }
    | expr '*' expr         { $$ = $1 * $3; }
    ;

%%

/* Additional C code */

#include <stdlib.h>

int yyerror(char *s) {
    fprintf(stderr, "error: %s\n", s);
    return 0;
}

int main(void) {
    printf("Enter a simple arithmetic expression:\n");
    yyparse();
    return 0;
}

int yylex(void) {
    int c;
    while ((c = getchar()) == ' ' || c == '\t'); // Skip whitespace
    if (c == EOF) return 0;
    if (c >= '0' && c <= '9') {
        ungetc(c, stdin);
        scanf("%d", &yylval);
        return NUMBER;
    }
    return c;
}
