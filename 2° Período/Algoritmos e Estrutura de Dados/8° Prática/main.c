#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
const int MAX=5000;
Stack pilha;
int main(){
    char expressao[MAX];
    gets(expressao);
    int i;
    char *aux,*dat;
    stack_init(&pilha,free);
    while(1){
    for(i=0;i<strlen(expressao);i++){
        if (expressao[i]=='('){
            stack_push(&pilha,&expressao[i]);
        }
        if (expressao[i]==')'){
            if (pilha.head==NULL){
                stack_push(&pilha,&expressao[i]);
            }
            else
                stack_pop(&pilha,(void*)&dat);
        }
    }

    if(pilha.size==0){
        printf("Balanceada");
    }else{
        if(*(aux = stack_peek(&pilha))=='('){
            printf("Falta fecha parenteses\n");
        }
        if(*(aux = stack_peek(&pilha))==')'){
            printf("Falta abre parenteses\n");
        }
    }
    return 0;
    }
}
