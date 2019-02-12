#include <stdio.h>
#include <stdlib.h>
float pot(float x,int y){
	int i;
	float res12=1;
	for (i=0;i<y;i++) res12*=x;
	return (res12);
}

int main(){
        float x,b;
	int y;
	printf("X:");
	scanf("%f",&x);
	printf("Y:");
	do{	
		scanf("%d",&y);
	}while (y<0);
	b=pot(x,y);
	printf("%f elevado à %d e igual a %f\n",x,y,b);
}
