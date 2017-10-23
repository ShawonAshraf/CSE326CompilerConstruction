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

	if (inputFile)
	{
		while ((c = getc(inputFile)) != EOF)
		{
			//printf("test == %c \n", c);

			input[counter] = c;
			counter++;
		}
	}

	//now checking tokens
	int tokenChecker, i;
	//printf("counter == %d\n", counter);
	for (i = 0; i<counter; i++)
	{

		//printf("current character == %c and value of i == %d\n", input[i], i);
		if (input[i] == 10 || input[i] == 32)
		{
			//printf("if 1 == %d\n", i);
			continue;
		}
		if (input[i] == '(')
		{
			//printf("if 2 == %d\n", i);
			printf("LPT\n");
		}
		else if (input[i] == ')')
		{
			//printf("if 3 == %d\n", i);
			printf("RPT\n");
		}
		else if (input[i] == '{')
		{
			//printf("if 4 == %d\n", i);
			printf("LCB\n");
		}
		else if (input[i] == '}')
		{
			//printf("if 5 == %d\n", i);
			printf("RCB\n");
		}
		else if (input[i] == '[')
		{
			//printf("if 6 == %d\n", i);
			printf("LSB\n");
		}
		else if (input[i] == ']')
		{
			//printf("if 7 == %d\n", i);
			printf("RSB\n");
		}
		else if (input[i] == '.')
		{
			//printf("if 8 == %d\n", i);
			printf("DOT\n");
		}
		else if (input[i] == ';')
		{
			//printf("if 9 == %d\n", i);
			printf("SEMI\n");
		}
		else if (input[i] == '+')
		{
			//printf("if 10 == %d\n", i);
			if (i + 1 <= counter&&input[i + 1] == '+')
			{
				printf("INC\n");
				i++;
			}
			else
			{
				printf("PLUS\n");
			}
		}
		else if (input[i] == '-')
		{
			//printf("if 11 == %d\n", i);
			if (i + 1 <= counter&&input[i + 1] == '-')
			{
				printf("DEC\n");
				i++;
			}
			else
			{
				printf("MINUS\n");
			}
		}
		else if (input[i] == '*')
		{
			//printf("if 12 == %d\n", i);
			printf("PROD\n");
		}
		else if (input[i] == '/')
		{
			//printf("if 13 == %d\n", i);
			printf("DIV\n");
		}
		else if (input[i] == '%')
		{
			//printf("if 14 == %d\n", i);
			printf("REM\n");
		}
		else if (input[i] == ':')
		{
			//printf("if 15 == %d\n", i);
			if (i + 1 <= counter&&input[i + 1] == '=')
			{
				printf("ASSIGN\n");
				i++;
			}
			else
			{

				printf("ERROR1\n");
			}
		}
		else if (input[i] == 92) //back slash
		{
			//printf("if 16 == %d\n", i);
			if (i == counter)
			{
				printf("BACKSL\n");
			}
			else if (i + 1 <= counter && (input[i + 1] != 'n' || input[i + 1] != 't' || input[i + 1] != 'r' || input[i + 1] != 92))
			{
				printf("BACKSL\n");
			}
			else if (i + 1 <= counter && (input[i + 1] == 'n'))
			{
				printf("NL\n");
			}
			else if (i + 1 <= counter && (input[i + 1] == 't'))
			{
				printf("TAB\n");
			}
			else if (i + 1 <= counter && (input[i + 1] == 'r'))
			{
				printf("CR\n");
			}
			else if (i + 1 <= counter && (input[i + 1] == 92))
			{
				printf("BKSL\n");
			}
		}
		else if (input[i] == 39)   //singleQ
		{
			//printf("if 17 == %d\n", i);
			if (i + 2 <= counter&&input[i + 2] == 39)
			{
				printf("CLIT\n");
				i += 2;
			}
			else
			{
				printf("SINGLEQ\n");
			}
		}
		else if (input[i] == 34)   //doubleQ
		{
			//printf("if 18 == %d\n", i);
			tokenChecker = 0;
			int j;
			for (j = i + 2; j <= counter; j++)
			{
				if (input[j] == 34)
				{
					printf("SLIT\n");
					i = j;
					tokenChecker = 1;
					break;
				}
			}
			if (tokenChecker == 0)
			{
				printf("DOUBLEQ\n");
			}
		}
		else if ((input[i] >= 'a'&&input[i] <= 'z') || (input[i] >= 'A'&&input[i] <= 'Z'))
		{
			//printf("coming here == %c\n", input[i]);
			//printf("if 19 == %d\n", i);
			if (i + 1 <= counter&&input[i] == 'i'&&input[i + 1] == 'f')
			{
				printf("IF\n");
			}
			else if (i + 3 <= counter&&input[i] == 'e'&&input[i + 1] == 'l'&&input[i + 2] == 's'&&input[i + 3] == 'e')
			{
				printf("ELSE\n");
			}
			else if (i + 2 <= counter&&input[i] == 'f'&&input[i + 1] == 'o'&&input[i + 2] == 'r')
			{
				printf("FOR\n");
			}
			else if (i + 5 <= counter&&input[i] == 'r'&&input[i + 1] == 'e'&&input[i + 2] == 't'&&input[i + 3] == 'u'&&input[i + 4] == 'r'&&input[i + 5] == 'n')
			{
				printf("RETURN\n");
			}
			else if (i + 2 <= counter&&input[i] == 'i'&&input[i + 1] == 'n'&&input[i + 2] == 't')
			{
				printf("INT\n");
			}
			else if (i + 3 <= counter&&input[i] == 'r'&&input[i + 1] == 'e'&&input[i + 2] == 'a'&&input[i + 3] == 'l')
			{
				printf("REAL\n");
			}
			else if (i + 3 <= counter&&input[i] == 'c'&&input[i + 1] == 'h'&&input[i + 2] == 'a'&&input[i + 3] == 'r')
			{
				printf("CHAR\n");
			}
			else if (i + 3 <= counter&&input[i] == 'v'&&input[i + 1] == 'o'&&input[i + 2] == 'i'&&input[i + 3] == 'd')
			{
				printf("VOID\n");
			}
			else
			{
				int j = i + 1;
				while (j <= counter)
				{
					if (input[j] == 10 || input[j] == 32 || input[j] == 0 || j>counter)
					{
						printf("IDENTIFIER\n");
						i = j;
						break;
					}
					else if (!((input[j] >= 'a'&&input[j] <= 'z') || (input[j] >= 'A'&&input[j] <= 'Z') || (input[j] >= '0'&&input[j] <= '9')))
					{
						//printf("test: %d\n", input[j]);
						printf("ERROR2\n");
						int k = j;
						while (input[k] != 10 || input[k] != 32 || k <= counter)
						{
							i = k;
							k++;
						}
						break;
					}
					j++;
				}
			}

		}
		else if (input[i] >= '0'&&input[i] <= '9')
		{
			//printf("if 20 == %d\n", i);
			int realCheck = 0;
			int j = i + 1;

			while (j <= counter)
			{
				if (input[j] == 10 || input[j] == 32 || j>counter)
				{
					//printf("test1 == %c\n", input[i]);
					printf("ILIT\n");
					i = j + 1;
					break;
				}
				else if (input[j] != '.' && !(input[i] >= '0'&&input[i] <= '9'))
				{
					//printf("test2\n");
					printf("ERROR3\n");
					int k = j;
					while (input[k] != 10 || input[k] != 32 || k <= counter)
					{
						i = k;
						k++;
					}
					break;
				}
				else if (input[j] == '.')
				{
					//printf("test3\n");
					//printf("test2 == %d %c\n",j, input[j]);
					int k = j + 1;
					while (k <= counter)
					{
						if (input[k] == 10 || input[k] == 32 || k>counter)
						{
							//printf("this is where it ends == %d\n",k);
							printf("RLIT\n");
							realCheck = 1;

							i = k;
							break;
						}
						else if (!(input[k] >= '0'&&input[k] <= '9'))
						{
							printf("ERROR4\n");
							int l = k;
							while (input[l] != 10 || input[l] != 32 || l <= counter)
							{
								i = l;
								l++;
							}
							break;
						}
						k++;
					}
					if (realCheck == 1)
					{
						break;
					}
				}
				j++;
			}
		}
		//printf("end current character == %c and value of i == %d\n", input[i], i);

	}

	// _gettche(); 
	return 0;
}
