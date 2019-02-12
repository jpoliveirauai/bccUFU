#include <stdio.h>
#include <stdlib.h>
#include "listop.h"

lista* criar(){
    lista* pato;
    pato = malloc(sizeof(lista));
    pato->prox=NULL;
    return (pato);
}
void insere_elemento(lista* p,const int quantidade){
    int i;
    for(i=0;i<quantidade;i++){
        p ->prox = malloc(sizeof(lista));
        p = p->prox;
    }
    p->prox=NULL;
}
int tamanho(lista* p){
    int i=0;
    while(p->prox!=NULL){
        i++;
        p = p->prox;
    }
    return i;
}
void atribui_nomes(lista* p){
    while(p->prox!=NULL){
        gets(p->nome);
        p=p->prox;
    }
}


void remove_elemento(lista** l,int elemento){
    if(l->prox==NULL)
        free(l);
    else{
        lista* atual=l;
        elemento--;
        int i;
        for(i=0;i<elemento;i++)
            atual = atual->prox;
        lista* eliminado = atual -> prox;
        atual -> prox = (atual->prox)->prox;
        free(eliminado);
    }
}
