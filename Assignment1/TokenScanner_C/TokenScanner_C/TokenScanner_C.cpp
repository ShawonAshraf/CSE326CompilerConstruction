// TokenScanner_C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>



int main()
{
    FILE *inputFile;
    
    inputFile = fopen("input.txt", "r");
    
    char input[50000];
    int counter = 0;
    char  c;
    
    if(inputFile)
    {
        while((c = getc(inputFile)) != EOF)
        {
            input[counter] = c;
            counter++;
        }
    }
    
    //now checking tokens
    int tokenChecker,i;
    
    for(i=0;i<counter;i++)
    {
        
        if(input[i]==10||input[i]==32)
        {
            continue;
        }
        if(input[i]=='(')
        {
            printf("LPT\n");
        }
        else if(input[i]==')')
        {
            printf("RPT\n");
        }
        else if(input[i]=='{')
        {
            printf("LCB\n");
        }
        else if(input[i]=='}')
        {
            printf("RCB\n");
        }
        else if(input[i]=='[')
        {
            printf("LSB\n");
        }
        else if(input[i]==']')
        {
            printf("RSB\n");
        }
        else if(input[i]=='.')
        {
            printf("DOT\n");
        }
        else if(input[i]==';')
        {
            printf("SEMI\n");
        }
        else if(input[i]=='+')
        {
            if(i+1<=counter&&input[i+1]=='+')
            {
                printf("INC\n");
                i++;
            }
            else
            {
                printf("PLUS\n");
            }
        }
        else if(input[i]=='-')
        {
            if(i+1<=counter&&input[i+1]=='-')
            {
                printf("DEC\n");
                i++;
            }
            else
            {
                printf("MINUS\n");
            }
        }
        else if(input[i]=='*')
        {
            printf("PROD\n");
        }
        else if(input[i]=='/')
        {
            printf("DIV\n");
        }
        else if(input[i]=='%')
        {
            printf("REM\n");
        }
        else if(input[i]==':')
        {
            if(i+1<=counter&&input[i+1]=='=')
            {
                printf("ASSIGN\n");
                i++;
            }
            else
            {
                
                printf("ERROR\n");
            }
        }
        else if(input[i]==92) //back slash
        {
            if(i==counter)
            {
                printf("BACKSL\n");
            }
            else if(i+1<=counter&&(input[i+1]!='n'&&input[i+1]!='t'&&input[i+1]!='r'&&input[i+1]!=92))
            {
                printf("BACKSL\n");
            }
            else if(i+1<=counter&&(input[i+1]=='n'))
            {
                printf("NL\n");
                i++;
            }
            else if(i+1<=counter&&(input[i+1]=='t'))
            {
                printf("TAB\n");
                i++;
            }
            else if(i+1<=counter&&(input[i+1]=='r'))
            {
                printf("CR\n");
                i++;
            }
            else if(i+1<=counter&&(input[i+1]==92))
            {
                printf("BKSL\n");
                i++;
            }
        }
        else if(input[i]==39)   //singleQ
        {
            if(i+2<=counter&&input[i+2]==39)
            {
                printf("CLIT\n");
                i+=2;
            }
            else
            {
                printf("SINGLEQ\n");
            }
        }
        else if(input[i]==34)   //doubleQ
        {
            tokenChecker = 0;
            int j;
            for(j=i+2;j<=counter;j++)
            {
                if(input[j]==34)
                {
                    printf("SLIT\n");
                    i = j;
                    tokenChecker = 1;
                    break;
                }
            }
            if(tokenChecker==0)
            {
                printf("DOUBLEQ\n");
            }
        }
        else if((input[i]>='a'&&input[i]<='z')||(input[i]>='A'&&input[i]<='Z'))
        {
            
            if(i+1<=counter&&input[i]=='i'&&input[i+1]=='f')
            {
                printf("IF\n");
                i = i+1;
            }
            else if(i+3<=counter&&input[i]=='e'&&input[i+1]=='l'&&input[i+2]=='s'&&input[i+3]=='e')
            {
                printf("ELSE\n");
                i = i+3;
            }
            else if(i+2<=counter&&input[i]=='f'&&input[i+1]=='o'&&input[i+2]=='r')
            {
                printf("FOR\n");
                i = i+2;
            }
            else if(i+5<=counter&&input[i]=='r'&&input[i+1]=='e'&&input[i+2]=='t'&&input[i+3]=='u'&&input[i+4]=='r'&&input[i+5]=='n')
            {
                printf("RETURN\n");
                i = i+5;
            }
            else if(i+2<=counter&&input[i]=='i'&&input[i+1]=='n'&&input[i+2]=='t')
            {
                printf("INT\n");
                i = i+2;
            }
            else if(i+3<=counter&&input[i]=='r'&&input[i+1]=='e'&&input[i+2]=='a'&&input[i+3]=='l')
            {
                printf("REAL\n");
                i = i+3;
            }
            else if(i+3<=counter&&input[i]=='c'&&input[i+1]=='h'&&input[i+2]=='a'&&input[i+3]=='r')
            {
                printf("CHAR\n");
                i = i+3;
            }
            else if(i+3<=counter&&input[i]=='v'&&input[i+1]=='o'&&input[i+2]=='i'&&input[i+3]=='d')
            {
                printf("VOID\n");
                i = i+3;
            }
            else
            {
                int j = i+1;
                while(j<=counter)
                {
                    if(input[j]==10||input[j]==32||input[j]==0||j>counter)
                    {
                        printf("ID\n");
                        i = j;
                        break;
                    }
                    else if(((input[j]>='a'&&input[j]<='z')||(input[j]>='A'&&input[j]<='Z')||(input[j]>='0'&&input[j]<='9')))
                    {
                        j++;
                        continue;
                    }
                    else
                    {
                        printf("ID\n");
                        i = j-1;
                        break;
                    }
                    j++;
                }
            }
            
        }
        else if(input[i]>='0'&&input[i]<='9')
        {
            if(input[i]=='0'&&i+1<=counter&&input[i+1]=='x')
            {
                int j = i+2;
                while(j<=counter)
                {
                    if(input[j]==10||input[j]==32||input[j]==0||j>counter)
                    {
                        
                        printf("HLIT\n");
                        i = j;
                        break;
                    }
                    else if(!((input[j]>='0'&&input[j]<='9')||(input[j]>='A'&&input[j]<='F')))
                    {
                        printf("ERROR\n");
                        i = j-1;
                        break;
                    }
                    j++;
                }
            }
            else
            {
                int realCheck = 0;
                int j=i+1;
                
                while(j<=counter)
                {
                    if(input[j]==10||input[j]==32||j>counter)
                    {
                        printf("ILIT\n");
                        i = j+1;
                        break;
                    }
                    else if(input[j]!='.'&&!(input[i]>='0'&&input[i]<='9'))
                    {
                        printf("ERROR\n");
                        int k = j;
                        while(input[k]!=10||input[k]!=32||k<=counter)
                        {
                            i = k;
                            k++;
                        }
                        break;
                    }
                    else if(input[j]=='.')
                    {
                        int k = j+1;
                        while(k<=counter)
                        {
                            if(input[k]==10||input[k]==32||k>counter)
                            {
                                printf("RLIT\n");
                                realCheck = 1;
                                
                                i = k;
                                break;
                            }
                            else if(!(input[k]>='0'&&input[k]<='9'))
                            {
                                printf("ERROR\n");
                                int l = k;
                                while(input[l]!=10||input[l]!=32||l<=counter)
                                {
                                    i = l;
                                    l++;
                                }
                                break;
                            }
                            k++;
                        }
                        if(realCheck==1)
                        {
                            break;
                        }
                    }
                    j++;
                }
            }
        }
        else
        {
            printf("ERROR\n");
        }
        
    }
    return 0;
}

