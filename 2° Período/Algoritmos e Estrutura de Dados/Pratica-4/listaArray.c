#include <stdio.h>
#include <stdlib.h>
#include "listaArray.h"
/* ========================================================================== */

void FLVazia(TipoLista *Lista){
    Lista -> Primeiro = INICIOARRANJO;
    Lista -> Ultimo = Lista -> Primeiro;
}  /* FLVazia */

int Vazia(TipoLista Lista){
    return (Lista.Primeiro == Lista.Ultimo);
}  /* Vazia */

void Insere(TipoItem x, TipoLista *Lista){
    if (Lista -> Ultimo >= MAXTAM)
        printf("Lista esta cheia\n");
    else{
        Lista -> Item[Lista -> Ultimo] = x;
        if (Lista -> Ultimo++;
    }
}  /* Insere */

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item){
    int Aux;
    if (Vazia(*Lista) || p >= Lista -> Ultimo) {
        printf(" Erro   Posicao nao existe\n");
    return;
    }
    *Item = Lista -> Item[p - 1];
    Lista -> Ultimo--;
    for (Aux = p; Aux < Lista -> Ultimo; Aux++)
        Lista -> Item[Aux - 1] = Lista -> Item[Aux];
}  /* Retira */

void Imprime(TipoLista Lista){
    int Aux;
    for (Aux = Lista.Primeiro - 1; Aux <= (Lista.Ultimo - 2); Aux++)
        printf("%d\n", Lista.Item[Aux].Chave);
}  /* Imprime */

/* ========================================================================== */
