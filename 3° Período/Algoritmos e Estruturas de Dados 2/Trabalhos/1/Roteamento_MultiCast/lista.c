#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
struct No{
    int vertice;

    int custo;
    int delay;
    int capacidade;
    int trafego_atual;

    struct No *prox;
};
typedef struct No no;

struct Lista{
    int n_elementos;
    no *primeiro;
};

lista* cria_lista(){
    lista* l = (lista*) malloc(sizeof(lista));
    l->n_elementos=0;
    l->primeiro = NULL;
    return l;
}

int jaexiste(lista* l,int v){
    no* aux = l->primeiro;
    while(aux!=NULL){
        if(aux->vertice==v)return 1;
        aux = aux->prox;
    }
    return 0;
}

int n_elementos(lista *l){
    return l->n_elementos;
}

int elemento_n(lista* l, int n,int *x,int *cap, int *cus, int *trafego,int *delay){
    no* aux = l->primeiro;
    int i;
    for(i=0;i<l->n_elementos,aux!=NULL;i++){
        if(i==n)break;
        aux = aux->prox;
    }

    if(aux!=NULL) {
        *cap = aux->capacidade;
        *cus = aux->custo;
        *trafego = aux->trafego_atual;
        *delay = aux ->delay;
        *x = aux->vertice;
        return 1;
    }else return 0;
}

int insere_lista(lista* l,int v,int cu,int ca, int de,int tra_at){
    if(l==NULL||v<0||cu<0||ca<0||de<0||tra_at<0)return -1;
    no *novo = (no*) malloc(sizeof(no));
    if(novo == NULL)return -1;
    //atribuições
    novo->capacidade = ca;
    ca = novo->capacidade;
    novo ->trafego_atual = tra_at;
    novo ->custo = cu;
    novo ->vertice = v;
    novo ->delay = de;
    novo ->prox = l->primeiro;
    l->n_elementos++;
    l->primeiro = novo;
    return 1;
}

int remove_lista(lista* l,int v1){
    if(l==NULL||v1<0)return -1;
    if(l->n_elementos == 0)return 0;
    no* aux = l -> primeiro;

    if(l->n_elementos==1&&aux->vertice ==v1){
        l->primeiro = NULL;
        free(aux);
    }else{
        no* anterior = aux;
        aux = aux->prox;
        while(aux!=NULL){
            if(aux->vertice == v1){

                        anterior->prox = aux->prox;
                        free(aux);
                        break;

            }
            anterior = aux;
            if(aux!=NULL)aux = aux->prox;
        }

    }
    if(aux==NULL)return 0;
    return 1;

}

void libera_lista(lista* l){
    no* aux2 = l->primeiro;
    no *aux1;
    if(aux2 != NULL)

        aux1 = l->primeiro->prox;
    else {
        free(l);
        return;
    }
    while(aux1!=NULL){
        free(aux2);
        aux2 = aux1;
        aux1 = aux1->prox;
    }
    free(aux2);
    free(l);
}
