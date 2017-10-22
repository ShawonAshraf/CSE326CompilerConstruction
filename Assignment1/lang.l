%{
    #include <stdio.h>
    #include <stdlib.h>
%}

digit [0-9]
symbol [A-za-z]
hex [0-9A-F]

id symbol(symbol|digit)*
literal digit+|(digit*"."digit+)|symbol|symbol+|0x(hex+)

ILIT digit+
RLIT (digit*)(".")(digit+)
CLIT symbol
SLIT symbol+
HLIT 0x(hex+)

LPT "(" 
RPT ")"
LCB "{"
RCB "}"
LSB "["
RSB "]"

DOT "."
SEMI ";"

ESYMBOLS LPT|RPT|LCB|RCB|LSB|RSB|DOT|SEMI

PLUS "+"
MINUS "-"
PROD "*"
DIV "/"
ASSIGN ":="
REM "%"
INC PLUSPLUS
DEC MINUSMINUS
MSYMBOLS PLUS|MINUS|PROD|DIV|ASSIGN|INC|DEC

BACKSL "\\"
SINGLEQ "'"
DOUBLEQ "\""
OSYMBOL BACKSL|SINGLEQ|DOUBLEQ

IF "if"
ELSE "else"
FOR "for"
RETURN "return"
INT "int"
REAL "real"
CHAR "char"
VOID "void"

NL BACKSLn
TAB BACKSLt
CR BACKSLr
BKSL BACKSLBACKSL


%%
{id} {printf("ID\n");}
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
{IF} {printf("IF\n");}
{ELSE} {printf("ELSE\n");}
{FOR} {printf("FOR\n");}
{RETURN} {printf("RETURN\n");}
{INT} {printf("INT\n");}
{REAL} {printf("REAL\n");}
{CHAR} {printf("CHAR\n");}
{VOID} {printf("VOID\n");}
{NL} {printf("NL\n");}
{TAB} {printf("TAB\n");}
{CR} {printf("CR\n");}
{BKSL} {printf("BKSL\n");}
%%

int main() {
    yylex();
    return 0;
}


