#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#define MAX 3
struct fila{
    int inicio,final,qtd;
    int elemento;
};
typedef struct fila Fila;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_cheia(Fila*fi);
int Fila_vazia(Fila*fi);
int insere_Fila(Fila* fi, int elemento);
int remove_Fila(Fila *fi);
int consulta_Fila(Fila* fi, int elemento);
#endif // LISTA_H_INCLUDED
