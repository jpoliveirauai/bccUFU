#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.141592
int main(){
/*
    int a=7,b=5,c=9,d=2,e=1;
    puts("Exercicio 1:");
    printf("a) %d, retornou nao\n",d%b==c%b);
    printf("b) %d, retornou sim\n",a*b!=d*b);
    printf("c) %d, retornou nao\n",d*b==c*e);
    printf("d) %d, retornou zero\n",!(a*b));
    printf("e) %d, retornou zero\n",!(a%b*c));
    printf("f) %d, retornou zero\n",!(c%b*a));
    printf("g) %d, retornou 63\n",b%c*a);

    puts("Ecercicio 3:");
    printf("a) %d, retornou\n",a % b * c && c % b * a);
    printf("b) %d, retornou\n",a % b * c || c % b * a);
    printf("c) %d, retornou\n",b % c * a && a % c * b);
    printf("d) %d, retornou\n",b % c * a || a % c * b);

    puts("Exercicio 5:");
    int ab=10;
    printf("10=\noctal: %o\ndecimal: %d\nHexadecimal: %X",ab,ab,ab);

    puts("Exercicio 6:");
    char tb=1;
    printf("1=%c",tb);
    puts("Exercicio 7:");
    float f;
    double g=1;
    long double ld;
    //printf("%.5f\n",d);

    puts("exercicio 8:");

    do {
        scanf("%d",&a);
    } while (a<100||a>999);
    b=a/100;
    c=(a%100)/10;
    d=(a%100)%10;
    printf("o numero %s um numero de angstron",(((pow(b,3))+(pow(c,3))+(pow(d,3)))==a) ?"eh":"nao eh");



    puts("\nexercicio 8:");
    float prova,teste1, teste2,teste3;
    printf("prova:");
    scanf("%f",&prova);
    printf("teste 1:");
    scanf("%f",&teste1);
    printf("teste 2:");
    scanf("%f",&teste2);
    printf("teste 3:");
    scanf("%f",&teste3);
    printf("%.2f eh a nota final\n",0.8*prova+0.2*((teste1+teste2+teste3)/3));


    puts("\nexercicio 11:");
    float notafinal;
    scanf("%f",&notafinal);
    printf("%d\n", notafinal >= 5.0);

    char tb;
    puts("\nexercicio 12:");
    scanf("%c",&tb);
    tb++;
    printf("%d  %c\n", tb,tb);
    return 0;

    //orbita.c
    float m,r,g,v,t;
    m=5.9*pow(10,24);
    scanf("%f",&r);
    g=6.7*pow(10,-11);
    v=sqrt((g*m)/r);
    t=2*pi*sqrt((pow(r,3))/g*m);
    printf("velocidade escalar: %.5f\nTempo do movimento orbital: %.5f",v,t);
    */
    //triangulo.c
    float x1,x2,x3,y1,y2,y3,a,b,c,s,A;
    scanf("%f %f %f %f %f %f",&x1,&x2,&x3,&y1,&y2,&y3);
    a=sqrt((pow(x1-x2,2)+pow(y1-y2,2)));
    b=sqrt((pow(x2-x3,2)+pow(y2-y3,2)));
    c=sqrt((pow(x3-x1,2)+pow(y3-y1,2)));
    printf("\n%f %.0f %.0f\n",a,b,c);
    A=sqrt((s*(s-a)*(s-b)*(s-c)));
    s=(a+b+c)/2;
    printf("A area do triangulo eh: %.0f\n",A);
}
