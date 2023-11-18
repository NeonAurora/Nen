%{
    #include <stdio.h>
    int yylex();
    void yyerror(char *s);
%}

%token IMPORT

%%

program:
    | program statement
    ;

statement:
    import_statement
    // ... Other statements ...
    ;

import_statement:
    IMPORT { printf("Import detected FROM BISON\n"); }
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
