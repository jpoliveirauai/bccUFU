#include <stdio.h>
#include <stdlib.h>

int main(){
    int x=1,i,m=0,p=0,q=0,r=0;
    for (i=1;i<201;i++){
        x=0;
        for (m=i;m>0;m--){
            if (i%m==0){
                x+=m;
            }

        }
        x-=i;
    if(i==x){
        printf("%d eh Perfeito\n",i);
        p++;
    }
    if(i<x){
        printf("%d eh Abundante\n",i);
        q++;
    }
    if(i>x){
        printf("%d eh Reduzido\n",i);
        r++;
    }
    }
    printf("\n\n%d sao perfeitos\n%d sao reduzidos\n%dsao abundantes\n\n",p,q,r);
}
