//Programa:correlacao.c
//Autor: Thiago Pereira Burgos
//Data:03/05/2016
//Descriçao:realacao entre duas tabelas


#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include<math.h>

void le_matriz(double A[][50],int a,int b,char na[][30],char nn[][30])
{
    int i,j;
    for (i=1; i<=a; i++)
    {
        for (j=1; j<=b; j++)
        {
            printf("\nA[%s;%s]:",na[i],nn[j]);
            scanf("%lf", &A[i][j]);
        }
    }
}

double fator_de_correlacao(double A[][50],int a,int b,char n1[][30],char n2[][30],char n[][30])
{
    int i,j,na,nb;
    char aux[2];
    double fat,sx=0,sy=0,sxx=0,syy=0,sxy=0;
    for(i=1; i<=b; i++)
    {
        for(j=1; j<=b; j++)
        {
            if(strcmp(n[i],n1[j])==0)
            {
                aux[0]=n[i];
                na=i;
            }
            if(strcmp(n[i],n2[j])==0)
            {
                aux[1]=n[i];
                nb=i;
            }
        }
    }
    for(i=1; i<=a; i++)
    {
        sx=sx+A[i][na];
    }

    sx=sx/a;

    for(i=1; i<=a; i++)
    {
        sy=sy+A[i][nb];
    }

    sy=sy/a;

    for(i=1; i<=a; i++)
    {
        sxy=sxy+( A[i][na]-sx)*( A[i][nb]-sy);
    }

    for(i=1; i<=a; i++)
    {
        sxx=sxx+((A[i][na]-sx)*(A[i][na]-sx));
    }

    for(i=1; i<=a; i++)
    {
        syy=syy+((A[i][nb]-sy)*(A[i][nb]-sy));
    }

    if(sqrt(sxx)*sqrt(syy)!=0){

    fat= sxy /(sqrt(sxx)*sqrt(syy));

    printf("%f\n%f\n%f\n%f\n%f\n",sx,sy,sxx,syy,sxy);

    printf("\nO  fator de correlacao entre os nutrientes %s e %s eh %lf",n[na],n[nb],fat);}
    else
    printf("Erro denominador nao pode ser 0");
    return fat;
}

int main (int argc,char* argv[])
{
    int l,c,i;
    char al[30][30],nutr[30][30],nom1[1][30],nom2[1][30];
    double M[50][50],fc=0;
    printf("Informe quantos alimentos tem na tabela:");
    scanf("%d",&l);
    for(i=1; i<=l; i++)
    {
        printf("qual o %d alimento:",i);
        scanf("%s",&al[i]);
    }
    do
    {
        printf("\nInforme quantos nutrientes tem na tabela:");
        scanf("%d",&c);
    }
    while(c<2);
    for(i=1; i<=c; i++)
    {
        printf("qual o %d nutriente:",i);
        scanf("%s",&nutr[i]);
    }
    printf("\nQue nutrientes voce deseja relacionar:");
    scanf("%s",&nom1[1]);
    scanf("%s",&nom2[1]);

    le_matriz(M,l,c,al,nutr);
    fc = fator_de_correlacao(M,l,c,nom1,nom2,nutr);

    if(fc == -1)
    {
        printf("\n Total anticorrelacao\n");
    }
    else{
    if(fc == 0)
    {
        printf("\n Nenhuma correlacao\n");
    }
    else
    {
        printf("\n Total correlacao\n");
    }
    }
    return 0;
}
