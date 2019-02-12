#include <stdio.h>
#include <stdlib.h>

int main (){
    int nv=1,i,mv;
    float temp, acm=0,mt;
    do {
        scanf("%d", &nv);
    } while(nv<1);
    for(i=1;i<=nv;i++){
        scanf("%f", &temp);
        if (i==1||temp<mt){
            mt=temp;
            mv=i;
        }
        acm+=temp;
    }
    acm/=i-1;
    printf("melhor volta: %d\n melhor tempo: %.3f\n tempo medio das voltas: %.3f",mv,mt,acm);
}
