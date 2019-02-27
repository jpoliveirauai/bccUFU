#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.141592

int main(){
    float graus,senx,fat=1;
    int i,j;
    scanf("%f", &graus);
    graus*=(pi/180);
    senx = graus;
    for (i=5;i<18;i+=4){
         for (j=i;j>1;j--) fat*=j;
         //printf("\n\n%d %d %d\n\n",i,j ,fat);
        senx+=pow(graus,i)/(fat);
        fat=1;
    }
    for (i=3;i<20;i+=4){
         for (j=i;j>1;j--) fat*=j;
        senx-=pow(graus,i)/(fat);
        fat=1;
    }
    printf("\n%.3f\n",senx);
}
