#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
Fila* cria_Fila(){
    Fila *fi = (Fila*) malloc(sizeof(struct fila));
    if(fi!=NULL){
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}
void libera_Fila(Fila* fi){
    free(fi);
}
int tamanho_Fila(Fila* fi){
    if(fi==NULL)
        return 1;
    return fi->qtd;
}
int Fila_cheia(Fila*fi){
    if(fi == NULL)return -1;
    if(fi->qtd==MAX)
        return 1;
    else
        return 0;
}
int Fila_vazia(Fila*fi){
    if(fi == NULL)return -1;
    if(fi->qtd==0)
        return 1;
    else
        return 0;
}
int insere_Fila(Fila* fi, int elemento){
    if(fi == NULL)return 0;
    if(Fila_cheia(fi))return 0;
    fi->elemento = elemento;
    fi ->final = (fi->final+1)%MAX;
    fi->qtd++;
    return 1;
}
int remove_Fila(Fila *fi){
    if(fi == NULL||Fila_vazia(fi))return 0;
    fi->inicio = (fi->inicio+1)%MAX;
    fi->qtd--;
    return 1;
}
int consulta_Fila(Fila* fi, int elemento){
    if(fi == NULL||Fila_vazia(fi))return 0;
    elemento = fi->elemento;
    return 1;
}
