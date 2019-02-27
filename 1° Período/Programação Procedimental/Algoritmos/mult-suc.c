#include <stdio.h>
#include <math.h>
int main(){
    int x,y,i,resultado=0;
    do {
        printf("X:");
        scanf("%d",&x);
        printf("Y:");
        scanf("%d",&y);
    }while (x<0||y<0);
    for(i=1;i<=y;i++)resultado+=x;
    printf("o produto de %d por %d eh %d",x,y,resultado);;
}
