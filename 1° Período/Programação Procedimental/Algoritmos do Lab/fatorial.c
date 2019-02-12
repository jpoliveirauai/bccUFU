#include <stdio.h>
#include <stdlib.h>

int fat (int x){
	int i;
	int rs=1;
	for (i=x;i>0;i--){
		rs*=i;	
	}
	return rs;
}


int main (){
	int x;
	printf("x:");
	do {
		scanf ("%d",&x);
	}while (x<0);
	printf("fatorial de %d = %d\n",x,fat(x));	
}
