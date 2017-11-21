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

prog:	STMTS
STMTS:	 | STMT STMTS
STMT:	DTYPE ID IDLIST SEMI
STMT:	ID ASSIGN EXPR SEMI
STMT:	IF LP EXPR RP THEN BLOCK
STMT:	WHILE LP EXPR RP BLOCK
IDLIST:	 | COMMA ID IDLIST
BLOCK:	LC STMTS RC
EXPR:	EXPR OPTR TERM | TERM
EXPR:	LP EXPR RP | MINUS EXPR
TERM:	ID | CONST
DTYPE:	INT | FLOAT | CHAR
CONST:	ILIT | RLIT | CLIT | SLIT
OPTR:	PLUS | MINUS | TIMES | DIVIDE | REM

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