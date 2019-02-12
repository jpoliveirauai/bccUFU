//Programa:regressao.c
//Autor: Thiago Pereira Burgos
//Data:02/05/2016
//Descriçao:regressao de funcao

#include <stdlib.h>
#include <stdio.h>

void le_2vetor(float v[],float c[],int n,char a,char b){
    int i;
    for(i=1;i<=n;i++){
        printf("%c[%i]:",a,i);
        scanf("%i",&v[i]);
        printf("%c[%i]:",b,i);
        scanf("%d",&c[i]);
    }
}
float regressao_linearA(float x[],float y[],int n){
float A,B,sx=0,sxy=0,sxx=0,syy=0,sy=0;
int i;
for(i=1;i<=n;i++){
    sx+=x[i];
}
for(i=1;i<=n;i++){
    sy+=y[i];
}
for(i=1;i<=n;i++){
    sxy+=x[i]*y[i];
}
for(i=1;i<=n;i++){
    sxx+=x[i]*x[i];
}
for(i=1;i<=n;i++){
    syy+=y[i]*y[i];
}
A=((n*sxy)-(sx*sy))/((n*sxx)-(sx*sx));
B=(sy-(A*sx))/n;
return A;
}
float regressao_linearB(float x[],float y[],int n){
float A,B,sx=0,sxy=0,sxx=0,syy=0,sy=0;
int i;
for(i=1;i<=n;i++){
    sx+=x[i];
}
for(i=1;i<=n;i++){
    sy+=y[i];
}
for(i=1;i<=n;i++){
        sxy+=x[i]*y[i];
}
for(i=1;i<=n;i++){
    sxx+=x[i]*x[i];
}
for(i=1;i<=n;i++){
    syy+=y[i]*y[i];
}
A=((n*sxy)-(sx*sy))/((n*sxx)-(sx*sx));
B=(sy-A*sx)/n;
return B;
}
int main (int argc,char* argv[]){
float X[20],Y[20],a,b;
int n;
do{printf("Quantos pontos serao fornecidos:");
scanf("%d",&n);
}while(n<2);
le_2vetor(X,Y,n,'X','Y');
a=regressao_linearA(X,Y,n);
b=regressao_linearB(X,Y,n);
if(a==0)printf("\nY=%.2f",b);
else{
    if(b==0){
        printf("\nY=%.2f*X",a);
    }
    else{
        printf("\nY=%.2f*X%.2f",a,b);
    }
}
return 0;
}
