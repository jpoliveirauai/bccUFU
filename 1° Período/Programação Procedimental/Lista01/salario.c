#include <stdio.h>
#include <stdlib.h>

int main (){
    float salario;
    int anos,i;
    char nome[100];
    puts("nome:");
    gets(nome);
    puts("\nanos de servico:");
    do{
        scanf ("%d",&anos);
    }while (anos<0);
    salario = 90000;
    switch (anos){
    case 0:

    break;
    default:
        for(i=1;i<=anos;i++){
            salario +=(salario*0.08);
            if (i%4==0){ salario +=(salario *0.04);}
        }
    break;
    }
    if (salario>150000) salario=150000;
    printf("%s trabalha por %d ano(s). Salario atual: R$ %.2f/ano\n",nome, anos, salario);
    return 0;
}
