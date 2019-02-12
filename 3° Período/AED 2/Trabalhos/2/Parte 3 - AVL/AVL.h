#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED
#define null NULL
#define sucess 1
#define failure 0

typedef struct avl *AVL;
typedef struct info info;

AVL cria_arvore();

int arvore_vazia(AVL a);

info *busca_binaria(AVL a, int trafego);

void exibe_arvore_ordenada(AVL a);

void exibe_arvore(AVL a);

void exibe_raiz(info *raiz);

void libera_arvore(AVL *a);

int insere_AVL(AVL *a,int id, int localx, int localy, int capacidade, int trafego );

int remove_AVL(AVL *a, int trafego );

int balancea_esquerda(AVL *a);

int balancea_direita(AVL *a);

info* menor_trafego(AVL a);

int qtde_ocioso(AVL a);

int nro_folha(AVL a);

int cheia(AVL a);

int nivel_no(AVL a, info * elemento);

int altura(AVL a);

int iguais(AVL a, AVL b);

        //fb == h(sae) - h(sad)
#endif // AVL_H_INCLUDED
