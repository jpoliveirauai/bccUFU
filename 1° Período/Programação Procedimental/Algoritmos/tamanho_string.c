#include <stdio.h>
#include <string.h>

int main(){
	char st[32]={"informatica"}	;
	int tm,i;
	puts("informatica");
	tm=strlen(st);
	printf("\n%d\n",tm);
	/*gets (st);*/
	for(i=tm-1;i>=0;i--) printf("%c",st[i]);
}
