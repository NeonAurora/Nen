/* C declarations */

%{
	#include<stdio.h>
	//int yyerror(char *s);
	//int yylex();
%}

/* Bison declarations */

%start input 
%token EVEN ODD

/* Simple grammar rules */

%%

input:  EVEN	{ printf("\nEVEN NUMBER\n");  }

	|ODD	{ printf("\nODD NUMBER\n");  }
	; 
%%
int yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}


int main(void)
{
	printf("\nEnter the number: ");
	yyparse();
	return 0;
}
