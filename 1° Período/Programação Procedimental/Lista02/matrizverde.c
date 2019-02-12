//Programa:matrizverde.c
//Autor: Thiago Pereira Burgos
//Data:02/05/2016
/*Descriçao:Escreva uma função em linguagem C denominada diag_superior que receba como
parâmetros uma matriz Anxn de elementos reais de dupla precisão e um valor inteiro (n) que define
a dimensão da matriz nxn. Em seguida, calcule e mostre a média considerando somente aqueles
elementos que estão na área superior da matriz, conforme ilustrado abaixo (área verde).
*/

#include <stdlib.h>
#include <stdio.h>
#define SIZE 100

void le_matriz(double A[][SIZE],int a)
{
    int i,j;
    for (i=0; i<a; i++)
    {
        for (j=0; j<a; j++)
        {
            printf("\nA[%d;%d]:",i,j);
            scanf("%lf", &A[i][j]);
        }
    }
}

double diag_superior(double A[][SIZE],int a)
{
    double soma=0;
    int i,j,con=0;

    for(i=0; i<a; i++)
    {
        for(j=0; j<a; j++)
        {
            if(i<j&&i+j<a-1)
            {
                soma+=A[i][j];
                con+=1;
            }
        }
    }
    soma=soma/con;
    return soma;
}

int main (int argc,char* argv[])
{
    int n;
    double A[100][100],med;
    do{
    printf("informe a ordem da matriz:");
    scanf("%d",&n);
    }while(n<3);
    le_matriz(A,n);
    med=diag_superior(A,n);
    printf("a media da diagonal superior dessa matriz eh %.3lf",med);
    return 0;
}
