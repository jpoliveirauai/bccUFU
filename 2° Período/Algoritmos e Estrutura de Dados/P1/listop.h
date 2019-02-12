#ifndef LISTOP_H_INCLUDED
#define LISTOP_H_INCLUDED

typedef struct lists{
    char nome[30];
    struct lists* prox;
}lista;

lista* criar();
void insere_elemento(lista* p,int quantidade);
void atribui_nomes(lista* p);
int tamanho(lista* p);
void remove_elemento(lista** l,int elemento);
#endif // LISTOP_H_INCLUDED
