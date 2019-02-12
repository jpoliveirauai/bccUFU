#ifndef LABIRINTO_H_INCLUDED
#define LABIRINTO_H_INCLUDED
#define MIN 4

typedef struct posicao {
    int i;
    int j;
    struct posicao* prox;
}pos;

typedef struct {
    int size;
    pos* topo;
}pilha;
void percorre (int*** matriz,int tamanho);
int** cria_matriz(int tamanho);
void libera_matriz(int** M, int tamanho);
void printa(int** matriz,int tamanho);
void cria_labirinto(int*** matriz,const int tamanho);
void waitFor (unsigned int secs);
#endif // LABIRINTO_H_INCLUDED
