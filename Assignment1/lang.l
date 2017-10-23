%{
    #include <stdio.h>
    #include <stdlib.h>
%}

digit [0-9]
symbol [A-Z a-z]
hex [0-9 A-F]

id symbol(symbol|digit)*


ILIT {digit}+
RLIT {digit}*("."{digit}+)
CLIT {symbol}
SLIT {symbol}+
HLIT 0x({hex}+)

LPT "(" 
RPT ")"
LCB "{"
RCB "}"
LSB "["
RSB "]"

DOT "."
SEMI ";"



PLUS "+"
MINUS "-"
PROD "*"
DIV "/"
ASSIGN ":="
REM "%"
INC {PLUS}{PLUS}
DEC {MINUS}{MINUS}


BACKSL "\\"
SINGLEQ "'"
DOUBLEQ "\""

IF "if"
ELSE "else"
FOR "for"
RETURN "return"
INT "int"
REAL "real"
CHAR "char"
VOID "void"


NL {BACKSL}"n"
TAB {BACKSL}"t"
CR {BACKSL}"r"
BKSL {BACKSL}{BACKSL}


%%
{id} {printf("ID\n");}

{IF} {printf("IF\n");}
{ELSE} {printf("ELSE\n");}
{FOR} {printf("FOR\n");}
{RETURN} {printf("RETURN\n");}
{INT} {printf("INT\n");}
{REAL} {printf("REAL\n");}
{CHAR} {printf("CHAR\n");}
{VOID} {printf("VOID\n");}
{ILIT} {printf("ILIT\n");}
{RLIT} {printf("RLIT\n");}
{CLIT} {printf("CLIT\n");}
{SLIT} {printf("SLIT\n");}
{HLIT} {printf("HLIT");}
{LPT} {printf("LPT\n");}
{RPT} {printf("RPT\n");}
{LCB} {printf("LCB\n");}
{RCB} {printf("RCB\n");}
{LSB} {printf("LSB\n");}
{RSB} {printf("RSB\n");}
{DOT} {printf("DOT\n");}
{SEMI} {printf("SEMI\n");}
{PLUS} {printf("PLUS\n");}
{MINUS} {printf("MINUS\n");}
{PROD} {printf("PROD\n");}
{DIV} {printf("DIV\n");}
{REM} {printf("REM\n");}
{ASSIGN} {printf("ASSIGN\n");}
{INC} {printf("INC\n");}
{DEC} {printf("DEC\n");}
{BACKSL} {printf("BACKSL\n");}
{SINGLEQ} {printf("SINGLEQ\n");}
{DOUBLEQ} {printf("DOUBLEQ\n");}

{NL} {printf("NL\n");}
{TAB} {printf("TAB\n");}
{CR} {printf("CR\n");}
{BKSL} {printf("BKSL\n");}

{} {printf("ERROR\n");}
%%

int main() {
    yylex();
    return 0;
}