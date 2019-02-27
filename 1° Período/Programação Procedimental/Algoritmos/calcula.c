#include <stdio.h>

int main(){
    printf("escreva a operação:");
    int op1,op2;
    float result;
    char op;
    scanf("%d %c %d",&op1,&op,&op2);
    switch(op){
        case '+':
            result=op1+op2;
            printf(" = %.2f",result);
        break;
        case '-':
            result=op1-op2;
            printf(" = %.2f",result);
        break;
        case '*':
            result=op1*op2;
            printf(" = %.2f",result);
        break;
        case '/':
            result=op1/op2;
            printf(" = %.2f",result);
        break;
        default:
            printf("\ndigite um operador invalido");
    }

}
