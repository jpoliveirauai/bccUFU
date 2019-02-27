#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
const int MAX=5000;
Stack pilha;
int main(){
    char expressao[MAX];
    gets(expressao);
    int i,j;
    //char* data = (char *)malloc(sizeof(char));
    for(i=0;i<strlen(expressao);i++){
        if (expressao[i]=='('){
            //stack_push(&pilha,(char*)'(');
            for(j=i;j<strlen(expressao);j++){
                if (expressao[j]==')'){
                    //empilha o ')'
                    break;
                }
            }
        }
        if (expressao[i]==')'){
            break;
            puts("falta no mínimo um abre parenteses");
        }
        //se ( ) estao na pilha, esvazia a pilha
    }

    stack_init(&pilha,free);
    printf("%d",j);
    stack_destroy(&pilha);
    return 0;
}
