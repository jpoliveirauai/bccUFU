#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
int main(){
    Fila* fila;
    fila = cria_Fila();
    int el=0,i;
    for(i=0;i<5;i++){
        scanf("%d",&el);
        if (i==0)fila->inicio = el;
        else insere_Fila(fila,el);
        printf("inserido: %d\n",el);
        if(i==3){
            printf("removido: %d\n",fila->inicio);
            remove_Fila(fila);
        }
    }

    for(i=0;i<3;i++){
        printf("removido: %d\n",fila->inicio);
        remove_Fila(fila);
    }
    libera_Fila(fila);
    return 0;
}
