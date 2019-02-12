#include<stdio.h>

int main()
{
	char c = ' ';
	int i;
	for (i=0 ; (i<5) && (c != '*'); i++ )
	{
		printf("%c\n", c);
		c = getchar();
	}
	return 0;
}
