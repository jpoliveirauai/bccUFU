#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct Lista lista;
lista* cria_lista();
int n_elementos(lista *l);
int insere_lista(lista* l,int v,int cu,int ca, int de,int tra_at);
int remove_lista(lista* l,int v1);
int elemento_n(lista* l, int n,int *x,int *cap, int *cus, int *trafego,int *delay);
void libera_lista(lista* l);
int jaexiste(lista* l,int v);
#endif // LISTA_H_INCLUDED
