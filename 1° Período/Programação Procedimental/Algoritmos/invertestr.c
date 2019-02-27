#include <stdio.h>
#include <string.h>
int main(){
	char s[500];
	int x,i;
	gets(s);
	for (i=strlen(s)-1;i>=0;i--)printf("%c",s[i]);
}
