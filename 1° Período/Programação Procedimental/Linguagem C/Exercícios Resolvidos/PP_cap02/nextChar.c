/*
	Arquivo: nextchar.c
	Descricao: Le um caractere e imprime a proxima letra
*/

#include<stdio.h>
int main (void)
{
	char c;
	
	c = getchar();
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
			if (c == 'z')
			{
				c = 'a';
			}
			else if (c == 'Z')
			{
				c = 'A';
			}
			else 
			{
				c = c + 1;
			}
			printf("%c\n", c);
	}
	else
	{
		printf("Nao e letra\n");
	}
	
	return 0;
}
