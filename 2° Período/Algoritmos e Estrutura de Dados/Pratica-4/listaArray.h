#ifndef LISTAARRAY_H_INCLUDED
#define LISTAARRAY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define INICIOARRANJO   0
#define MAXTAM          1000
typedef int TipoChave;

typedef int TipoApontador;

typedef struct {
    TipoChave Chave;
} TipoItem;

typedef struct {
    TipoItem Item[MAXTAM];
    TipoApontador Primeiro, Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista);
int Vazia(TipoLista Lista);
void Insere(TipoItem x, TipoLista *Lista);
void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item);
void Imprime(TipoLista Lista);
#endif // LISTAARRAY_H_INCLUDED
