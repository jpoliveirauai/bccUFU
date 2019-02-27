#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char*argv){
    struct endereco{
        char rua[10];
        char cidade[20];
        char numero:    6;

    }Joao;
    struct endereco *p;
    p=&Joao;
    p->rua;
    printf("%p\n",p);
    printf("%p\n",&Joao.rua);
    scanf("%s[^\n]", p);
    printf("%s\n",Joao.rua);
    printf("%p\n",p);
    int vet[5]={1,2,3,4,5};
    int *p1;
    p1=&vet;
    int i=4;
    for (;i>=0;p1++,--i){
        printf("%d\n",*p1);
    }

}
