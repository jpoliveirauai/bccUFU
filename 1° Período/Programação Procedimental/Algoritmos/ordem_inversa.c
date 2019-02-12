#include <stdio.h>
#define t 5
int main(){
	int vet[t],i;
	for(i=0;i<t;i++){
        scanf("%d",&vet[i]);
	}
	for(i=t-1;i>=0;i--){
        printf("%d\n",vet[i]);
	}
}
