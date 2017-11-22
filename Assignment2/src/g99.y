%{
	#include <math.h>
	#include <stdio.h>
	#include <stdlib.h>
	#define YYSTYPE double
%}

%token RLIT ILIT CLIT SLIT
%token PLUS MINUS TIMES DIVIDE REM
%token ASSIGN
%token COMMA
%token IF THEN WHILE
%token LP RP LC RC LB RB
%token ID
%token ENDL SEMI
%token HASH LEXERR
%token INT FLOAT CHAR

%right ASSIGN
%left PLUS MINUS
%left TIMES DIVIDE REM
%left NEG


%start prog
%%

prog:	STMTS	{if (yychar == YYEOF) {
                    printf("accept\n");
                 	}
                 }
STMTS:	 | STMT STMTS
STMT:	DTYPE ID IDLIST SEMI
STMT:	ID ASSIGN EXPR SEMI		{printf("variable value = %d\n", $3);}
STMT:	IF LP EXPR RP THEN BLOCK
STMT:	WHILE LP EXPR RP BLOCK
IDLIST:	 | COMMA ID IDLIST
BLOCK:	LC STMTS RC
EXPR:	TERM	{$$ = $1;} | EXPR OPTR TERM	{ if($2=='+')
											  {
											  	  $$ = $1 + $3;
											  }
											  else if($2=='-')
											  {
											  	  $$ = $1 - $3;
											  }
											  else if($2=='*')
											  {
											  	  $$ = $1 * $3;
											  }
											  else if($2=='/')
											  {
											  	  $$ = $1 / $3;
											  }
											  else if($2=='%')
											  {
											  	  $$ = $1 - ($3 * ($1 / $3));
											  }
											  
											}

									
EXPR:	LP EXPR RP {$$ = $2;}| MINUS EXPR	{$$ = -1 * $2;}
TERM:	ID 	{$$ = $1;} | CONST	{$$ = $1;}
DTYPE:	INT 	{$$ = $1;} | FLOAT	{$$ = $1;} | CHAR 	{$$ = $1;}
CONST:	ILIT 	{$$ = $1;} | RLIT 	{$$ = $1;} | CLIT  	{$$ = $1;} | SLIT 	{$$ = $1;}
OPTR:	PLUS 	{$$ = $1;} | MINUS	{$$ = $1;} | TIMES	{$$ = $1;} | DIVIDE	{$$ = $1;} | REM	{$$ = $1;}

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