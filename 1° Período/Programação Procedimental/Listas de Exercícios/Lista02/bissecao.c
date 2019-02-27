//Programa:bissecao
//Autor: Thiago Pereira Burgos
//Data:07/05/2016
//Descriçao:achar raizes pelo intervalo

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int graupoli;
double a[100];

double fx(double);
double bissecao(double, double);
void get_raizes(int,int);


int main()
{
    int i, menv, maiorv;

    printf("Apartir do grau dos coeficientes, do grau do polinomio e um intervalo eh possivel descobrir uma raiz.\n\n");

    do
    {
        printf("Digite o grau do polinomio desejado: ");
        scanf("%i",&graupoli);
    }
    while(graupoli <= 0);

    printf("\n");

    for(i = 0; i <= graupoli; i++)
    {
        printf("Digite o coeficiente do termo \"x^%d\": ",i);
        scanf("%lf",&a[i]);
    }
    printf("\n");


    printf("Funcao polinomial:\n");

    printf("f(x) = ");
    for(i = 0; i <= graupoli; i++)
    {
        if(i == 0)
        {
            printf("%.2lf + ",a[i]);
        }
        else
        {
            if(i == graupoli)
            {
                printf("(%.2lf*(x^%i))",a[i],i);
            }
            else
            {
                printf("(%.2lf*x^%i) + ",a[i],i);
            }
        }
    }
    printf("\n");

    do
    {
        printf("\nDigite o intervalo que sera analisado dois numeros diferentes se possivel:\n");
        printf("Digite o maior valor: ");
        scanf("%d",&maiorv);
        printf("Digite o menor valor: ");
        scanf("%d",&menv);
    }
    while(menv >= maiorv);

    printf("\nIntervalo = [%d;%d]\n",menv,maiorv);

    get_raizes(menv,maiorv);

    return 0;
}

double fx(double n)
{
    int i;
    double funcao_x = 0;

    for(i = 0; i <= graupoli; i++)
    {
        funcao_x += (a[i] * pow(n,i));
    }
    return funcao_x;
}

double bissecao(double x1, double x2)
{
    double xm;

    xm = (x1 + x2)/2;

    if(fx(xm) >= -0.000000001 && fx(xm) <= 0.000000001)
    {
        return xm;
    }
    else if (fx(xm) < 0)
    {
        x1 = xm;
        return bissecao(x1, x2);
    }
    else
    {
        x2 = xm;
        return bissecao(x1,x2);
    }
}

void get_raizes(int a, int b)
{
    int i, j;
    double raiz = 0;
    int prova = 0;

    for(i = a; i <= b; i++)
    {
        if((fx(i) <= 0) && (fx(i+1) >= 0))
        {
            raiz = bissecao(i,i+1);
            prova = 1;
        }
    }

    if(!prova)
    {
        printf("\nNesse intervalo nao e possivel encontrar raizes\n\n");
    }
    else
    {
        printf("\nRaiz = %lf\n",raiz);
    }
}
