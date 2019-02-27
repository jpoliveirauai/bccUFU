#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#define MAX 10
typedef int TipoChave;
typedef struct
{
    int Chave;
} TipoItem;
typedef struct TipoCelula *TipoApontador;
typedef struct TipoCelula
{
    TipoItem Item;
    TipoApontador Prox;
} TipoCelula;
typedef struct
{
    TipoApontador Primeiro, Ultimo;
} TipoLista;
void FLVazia(TipoLista *Lista);
int Vazia(TipoLista Lista);
void Insere(TipoItem x, TipoLista *Lista);
void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item);
void Imprime(TipoLista Lista);
void InsereItem(int p, TipoItem x, TipoLista *Lista);
void conc_List(TipoLista *Lista1, TipoLista *Lista2, TipoLista *Lista3);
#endif // LISTA_H_INCLUDED
