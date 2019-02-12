#include <stdio.h>
#include <stdlib.h>

int binomial (int n,int p){
	int i,fn=1,fp=1,fnp=1;
	int rs=0;
	for (i=n;i>0;i--){
		fn*=i;	
	}

	for (i=p;i>0;i--){
		fp*=i;	
	}
	for (i=(n-p);i>0;i--){
		fnp*=i;	
	}
	rs=fn/(fp*fnp);
	return rs;
}

int main (){
	int k,n;
	do {
		printf("N:");
		scanf("%d",&n);
		printf("K:");
		scanf("%d",&k);
	} while(k<0||k>n);
	printf("o a combinacao de %d e %d eh %d\n",n,k,binomial(n,k));
	return 0;
	
}
