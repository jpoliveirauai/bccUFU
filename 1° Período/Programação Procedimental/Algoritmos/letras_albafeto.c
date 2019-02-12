#include <stdio.h>
#define alf 26
int main(){
	int vet[alf],i,j;
	for (i=0,j=97;i<26;i++,j++){
        vet[i]=j;
        printf("%c\n",vet[i]);
	}
	return 0;
}
