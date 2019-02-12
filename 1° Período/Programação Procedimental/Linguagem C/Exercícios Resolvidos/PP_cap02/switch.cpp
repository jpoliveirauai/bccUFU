
#include <stdlib.h>
#include <stdio.h>

int main(){
    int n1, n2;
    char op;
    printf("Digite a operacao: \n");
    printf("operando1 operando2 operacao: \n");
    printf("Ex.: 5 2 + \n");
    scanf("%d %c %d",&n1,&op, &n2);
    switch(op){
        case '+': printf("\nA adicao de %d por %d eh igual a %d\n",n1,n2,n1+n2); break;
        case '-': printf("\nA subtracao de %d por %d eh igual a %d\n",n1,n2,n1-n2); break;
        case '*': printf("\nO produto de %d por %d eh igual a %d\n",n1,n2,n1*n2); break;
        case '/': printf("\nA divisao de %d por %d eh igual a %d\n",n1,n2,n1/n2); break;
        case '%': printf("\nO módulo de %d por %d eh igual a %d\n",n1,n2,n1%n2); break;
        default: printf("\nOperacao desconhecida...\n");
    }

    system("PAUSE");

    return 0;
}
