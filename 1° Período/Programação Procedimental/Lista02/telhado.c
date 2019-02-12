//Programa:telhado.c
//Autor: Thiago Pereira Burgos
//Data:02/05/2016
/*Descriçao:Escreva em linguagem C uma função denominada telhado que receba como parâmetros uma
matriz Anxn e um valor inteiro e ímpar (n) que define a dimensão da matriz nxn. A função telhado
deve preencher a matriz recebida Anxn como ilustrado nos exemplos abaixo. Elabore a função
main() para testar a função telhado. O programa deve ler do dispositivo padrão de entrada (teclado)
a dimensão n da matriz A e mostrar o resultado na tela de saída.
*/


#include <stdlib.h>
#include <stdio.h>
#define SIZE 100
void telhado(int [][100],int);
/*nao recomanedo colocar numetos acima do 27 pois perdera a estetica da matriz
o prompt de comando nao suporta a matriz tao grande
obrigado.
*/
int main (int argc,char* argv[])
{

    int n,A[SIZE][SIZE];
    do
    {
        printf("informe a ordem da matriz:");
        scanf("%d",&n);
    }
    while(!(n&1));

    telhado(A,n);
    return 0;
}

void telhado(int A[100][100],int n)
{
    int i,j;
    for (i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==j)
            {
                printf(" 0 ");
            }
            else
            {
                if(i+j==n-1)
                {
                    printf(" 0 ");
                }
                else
                {
                    if(i<=n/2&&j<=n/2)
                    {
                        printf("%2d ",abs(i-j));
                    }
                    else
                    {
                        if(i+j<n-1)
                        {
                            printf("%2d ",abs(i+j-n+1));
                        }
                    }
                    if(i>n/2&&j>n/2)
                    {
                        printf("%2d ",abs(i-j));
                    }
                    else
                    {
                        if(i+j>n-1)
                        {
                            printf("%2d ",abs(i+j-n+1));
                        }
                    }
                }
            }
        }
        printf("\n");

    }
}
