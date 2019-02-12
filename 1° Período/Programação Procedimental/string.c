#include <stdio.h>
#include <stdlib.h>

int main (){
    char x[]={'a','l','o'};
    char y[]={"alguma coisa"};
    fflush(stdin);
    gets(x);
    //printf("%s\n %s",x,y);
    strcpy(x,y);
    puts(x);

    //printf("%s",strcmp(x,y)==0?"iguais":"diferentes");
    return 0;
}
