#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "lista.h"
void FLVazia(TipoLista *Lista)
{
    Lista -> Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista -> Ultimo = Lista -> Primeiro;
    Lista -> Primeiro -> Prox = NULL;
}
int Vazia(TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}
void Insere(TipoItem x, TipoLista *Lista)
{
    Lista -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista -> Ultimo = Lista -> Ultimo -> Prox;
    Lista -> Ultimo -> Item = x;
    Lista -> Ultimo -> Prox = NULL;
}
void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item)
{
    /* --- Obs.: o item a ser retirado e o seguinte ao apontado por p --- */
    TipoApontador q;
    if (Vazia(*Lista) || p == NULL || p -> Prox == NULL)
    {
        printf(" Erro - Lista vazia ou posicao nao existe\n");
        return;
    }
    q = p -> Prox;
    *Item = q -> Item;
    p -> Prox = q -> Prox;
    if (p -> Prox == NULL) Lista -> Ultimo = p;
    free(q);
}
void Imprime(TipoLista Lista)
{
    int i;
    TipoApontador Aux;
    Aux = Lista.Primeiro -> Prox;
    i = Vazia(Lista);
    if(i == 1)
    {
        printf("(Lista Vazia)\n");
    }
    else
    {
        while (Aux != NULL)
        {
            printf(" / %d", Aux -> Item.Chave);
            Aux = Aux -> Prox;
        }
        printf (" /");
        printf("\n\n");
    }
}
void InsereItem(int posicao, TipoItem x, TipoLista *Lista)
{
    int i = 1;
    TipoCelula *elemento, *aux = Lista->Primeiro;
    elemento = (TipoCelula*) malloc(sizeof(TipoCelula));
    elemento->Item = x;
    while(aux->Prox != NULL && i <= posicao)
    {
        aux = aux->Prox;
        i++;
    }
    elemento->Prox = aux->Prox;
    aux->Prox = elemento;
}
void conc_Lis(TipoLista *Lista1, TipoLista *Lista2, TipoLista *Lista3)
{
    TipoCelula *aux = Lista1->Primeiro;
    while(aux->Prox != NULL)
    {
        aux = aux->Prox;
        Insere(aux->Item, Lista3);
    }
    aux = Lista2->Primeiro;
    while(aux->Prox != NULL)
    {
        aux = aux->Prox;
        Insere(aux->Item, Lista3);
    }
}
