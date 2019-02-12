#include <stdio.h>

int main(){
    int x,pares[10],impares[10],i,p=0,im=0;
    for (i=0;i<10;i++){
        scanf("%d",&x);
        if (x&1){
            impares[im]=x;
            im++;
        }else{
            pares[p]=x;
            p++;
        }
    }
    printf("Pares:");
    for (i=0;i<p;i++)  printf(" %d%c",pares[i],i==p-1?' ':',');
    printf("\nImpares:");
    for (i=0;i<im;i++)  printf(" %d%c",impares[i],i==im-1?' ':',');
}
