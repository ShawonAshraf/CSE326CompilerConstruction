%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	#include "y.tab.h"		
	#define YYSTYPE double
%}

white 	[ \t\r]+
digit 	[0-9]
real 	{digit}+("."{digit}+)
letter 	[A-Za-z]
char    '{letter}*'
string 	"\""[^"]*"\""

%%
{white}		{}
"+" 		{printf("<PLUS>\n"); return PLUS;}
"-" 		{printf("<MINUS>\n"); return MINUS;}
"*" 		{printf("<TIMES>\n"); return TIMES;}
"/" 		{printf("<DIVIDE>\n"); return DIVIDE;}
"%" 		{printf("<REM>\n"); return REM;}
"(" 		{printf("<LP>\n"); return LP;}
")" 		{printf("<RP>\n"); return RP;}
"{" 		{printf("<LC>\n"); return LC;}
"}" 		{printf("<RC>\n"); return RC;}
"[" 		{printf("<LB>\n"); return LB;}
"]" 		{printf("<RB>\n"); return RB;}
"\n" 		{printf("<ENDL>\n");}
";"			{printf("<SEMI>\n"); return SEMI;}
"#" 		{printf("<HASH>\n"); return HASH;}
":="		{printf("<ASSIGN>\n"); return ASSIGN;}
"," 		{printf("<COMMA>\n"); return COMMA;}
"int" 		{printf("<INT>\n"); return INT;}
"float" 	{printf("<FLOAT>\n"); return FLOAT;}
"char" 		{printf("<CHAR>\n"); return CHAR;}
"if" 		{printf("<IF>\n"); return IF;}
"then" 		{printf("<THEN>\n"); return THEN;}
"while" 	{printf("<WHILE>\n"); return WHILE;}

{real}		{	yylval=atof(yytext);
				printf("<%s,RLIT>\n", yytext);
				return RLIT;
			}
			
{digit}+	{
				yylval= atoi(yytext); 
				printf("<%s,ILIT>\n", yytext); 
				return ILIT;
			}

{char}		{printf("<CHAR>\n"); return CLIT;}

{string}	{printf("<TEXT>\n"); return SLIT;}

{letter}({letter}|{digit})* {
				printf("<%s,ID>\n", yytext); 
				return ID;
			}
			
.			{
				printf("<INVALID SYMBOL>\n"); 
				return LEXERR;
			}
%%

int test(void)
{  
   return 0;
}