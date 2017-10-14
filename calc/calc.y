%{
	#include <math.h>
	#include <stdio.h>
	#include <stdlib.h>
	#define YYSTYPE double
%}

%token NUMBER
%token PLUS MINUS TIMES DIVIDE POWER
%token LEFT RIGHT
%token ENDL
%token HASH

%left PLUS MINUS
%left TIMES DIVIDE
%left NEG
%right POWER

%start input

%%

input:	
	input line	
	| /* empty  */
;
line:
    ENDL			{ printf("Line\n"); }
	| HASH			{ printf("End of Program\n"); }
	| expr ENDL 	{ printf("Result: %f\n", $1); }
;
expr:
     NUMBER { $$=$1; }
	| expr PLUS expr { $$=$1+$3; }
	| expr MINUS expr { $$=$1-$3; }
	| expr TIMES expr { $$=$1*$3; }
	| expr DIVIDE expr { $$=$1/$3; }
	| MINUS expr %prec NEG { $$=-$2; }
	| expr POWER expr { $$=pow($1,$3); }
	| LEFT expr RIGHT { $$=$2; }
;

%%

extern int yylex(void);
extern int yyparse(void);

int yyerror(char *s) {
  printf("%s\n", s);
}

int yywrap(void) {
    return 1;
}

int main() {
	return yyparse();  
}