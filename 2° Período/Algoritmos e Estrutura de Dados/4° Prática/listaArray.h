#ifndef LISTAARRAY_H_INCLUDED
#define LISTAARRAY_H_INCLUDED

#define INICIOARRANJO -1
#define MAXTAM          1000

typedef int TipoChave;

typedef int TipoApontador;

typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;

typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontador Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista);

int Vazia(TipoLista Lista);

void Insere(TipoItem x, TipoLista *Lista);

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item);

void Imprime(TipoLista Lista);

void InsereItem(TipoItem x, TipoLista *Lista, int n);


#endif // LISTAARRAY_H_INCLUDED
