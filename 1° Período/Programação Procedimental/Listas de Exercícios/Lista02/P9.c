#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Funcoes
void tamanho_campo(int *n);
void arrumando_matrizM(int n, int M[n][n]);
void imprimir_campo(int n, int M[n][n]);
void escolher_quadrado(int n, int *l, int *c, int M[n][n]);
void soma(int n, int l, int c, int M[n][n]);
//Final Funcoes
void tamanho_campo(int *n)
{
    printf("Digite qual a ordem da matriz: ");
    scanf("%d", *&n);
}
void arrumando_matrizM(int n, int M[n][n])
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            M[i][j]=0;
        }
    }
}
void imprimir_campo(int n, int M[n][n])
{
    int i, j;
    system("cls");
    printf("l/c|");
    for(i=0; i<n; i++)
    {
        printf("%3d",(i+1));
    }
    printf("\n");
    for(i=0; i<n; i++)
    {
        printf("%3d|",(i+1));
        for(j=0; j<n; j++)
        {
            printf("%3d",M[i][j]);
        }
        printf("\n");
    }
}
void escolher_quadrado(int n, int *l, int *c, int M[n][n])
{
    do
    {
        printf("\nEscolha a linha: ");
        do
        {
            scanf("%d", *&l );
            --*l;
        }
        while((*l<0) || (*l>=n));
        printf("\nEscolha a coluna: ");
        do
        {
            scanf("%d",*&c);
            --*c;
        }
        while((*c<0) || (*c>=n));
    }
    while(M[*l][*c]>=9);
}
void soma(int n, int l, int c, int M[n][n])
{
    int i, j, aux;
    n=n-1;
    if(l==0)
    {
        if(c==0)
        {
            M[0][1]+=1;
            M[1][1]+=1;
            M[1][0]+=1;
        }
        if(c==n)
        {
            M[0][(n-1)]+=1;
            M[1][(n-1)]+=1;
            M[1][n]+=1;
        }
        if(c!=0)
        {
            if(c!=n)
            {
                for(i=(c-1); i<=(c+1); i++)
                {
                    M[0][i]+=1;
                    M[1][i]+=1;
                }
            }
        }
    }
    if(l==n)
    {
        if(c==0)
        {
            M[(n-1)][0]+=1;
            M[(n-1)][1]+=1;
            M[n][1]+=1;
        }
        if(c==n)
        {
            M[(n-1)][n]+=1;
            M[(n-1)][(n-1)]+=1;
            M[n][(n-1)]+=1;
        }
        if(c!=0)
        {
            if(c!=n)
            {
                for(i=(c-1); i<=(c+1); i++)
                {
                    M[n][i]+=1;
                    M[(n-1)][i]+=1;
                }
            }
        }
    }
    if(l!=0)
    {
        if(l!=n)
        {
            if(c==0)
            {
                for(i=(l-1); i<=(l+1); i++)
                {
                    M[i][0]+=1;
                    M[i][1]+=1;
                }
            }
            if(c==n)
            {
                for(i=(l-1); i<=(l+1); i++)
                {
                    M[i][(n-1)]+=1;
                    M[i][n]+=1;
                }
            }
            if(c!=0)
            {
                if(c!=n)
                {
                    for(i=(l-1); i<=(l+1); i++)
                    {
                        for(j=(c-1); j<=(c+1); j++)
                        {
                            M[i][j]+=1;
                        }
                    }
                }
            }
        }
    }
}
int main(int argc, char* argrv)
{
    int n=0, i, j, l=-1, c=-1;
    tamanho_campo(&n);
    int M[n][n];
    arrumando_matrizM(n,M);
    while(1==1)
    {
        imprimir_campo(n,M);
        escolher_quadrado(n,&l,&c,M);
        soma(n,l,c,M);
        M[l][c]=9;
    }
    return 0;
}
