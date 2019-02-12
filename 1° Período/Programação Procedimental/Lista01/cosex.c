#include<stdio.h>
#include<stdlib.h>
#define pi 3.141592
int main(){
    float graus,cosx,fat=1;
    int i,j;
    scanf("%f", &graus);
    graus*=(pi/180);
    cosx =1;
    for (i=4;i<21;i+=4){
        for (j=i;j>1;j--) fat*=j;
        cosx+=pow(graus,i)/(fat);
        fat=1;
    }
    for (i=2;i<21;i+=4){
         for (j=i;j>1;j--) fat*=j;
        cosx-=pow(graus,i)/(fat);
        fat=1;
    }
    printf("\n%.3f\n",cosx);
}
