#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tm 200
int main(){
    int interr=2,vet[tm],i,n,j,cont=0;
    do{
    puts("Tamanho do relogio:");
    scanf("%d",&n);
    }while (n>tm||n<1);
    for(i=0;i<n;i++){
        vet[i]=i+1;
    }
    srand(time(NULL));
    do {j=rand();} while (j<0||j>=n);
    for(;cont<n-1;j++){
        if (vet[j]!=0&&cont!=0)interr++;
        if (interr==2){
            vet[j]=0;
            cont++;
            interr=0;
        }
        if(j==n-1) j=-1;
    }

        for(i=0;i<n;i++){
            if (vet[i]!=0) printf("o vencedor eh: %d\n",vet[i]);
        }
        return 0;
}
