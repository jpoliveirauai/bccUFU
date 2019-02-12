#include "arvore_generica.h"
#include <stdio.h>
#include <stdlib.h>


struct _Info{
    int dados;
}info;

// DEFINICAO: FILHO NO NÓ A ESQUERDA, E IRMAOS NO NÓ A DIREITA!
// STRUCT PARA ALOCACAO DO NÓ QUE SERÁ USADO NA ARVORE.
struct No{
    int data;
    struct No* esquerda;
    struct No* direita;

};

typedef struct No no;

//altura(Arv A){
//
//}

int altura(Arv A) {
    int hmax = -1;
    Arv p;
    p=A->esquerda;
    while(p!=NULL){
        int h = altura(p);
        if (h > hmax)
        hmax = h;
        p=p->direita;
    }
    return hmax + 1;
}

Arv busca_elemento(Arv arvore, int elem){
    if(arvore==NULL) return NULL;
    if(arvore->data == elem)return arvore;
    if(busca_elemento(arvore->esquerda, elem)!=NULL) return busca_elemento(arvore->esquerda, elem);
        else return busca_elemento(arvore->direita,elem);
    return NULL;
}


int altura_no(Arv A, int elem){
    if(busca_elemento(A,elem)==NULL) return -1;
    printf("\nahoy %d",busca_elemento(A,elem)->data);
    return altura(busca_elemento(A,elem));
}


int grau_arv(Arv A){
    if(A==NULL) return 0;
    Arv aux = A;
    int grau = 0;
    while(aux!=NULL){
        grau++;
        aux = aux->direita;
    }
    if(A->esquerda!= NULL){
        int grau2 = grau_arv(A->esquerda);
        if(grau2 > grau) return grau2;
    }
    return grau;
}

int qtde_nos(Arv A){
    if(A==NULL) return 0;
    Arv aux = A;
    int x=0;
    while(aux!=NULL){
        x++;
        aux = aux->direita;
    }
    return x + qtde_nos(A->esquerda);
}

int nro_derivacao(Arv A){
    if(A==NULL) return 0;
    if(A->esquerda!=NULL) return 1+nro_derivacao(A->direita)+nro_derivacao(A->esquerda);
    return 0;
}

void postorder(Arv A){
    if(A==NULL) return;
    postorder(A->esquerda);
    postorder(A->direita);
    printf("%d ",A->data);
}

void percorre_nivel(Arv A){
    if(A==NULL) return;
    Arv aux = A;
    while(aux!=NULL){
        printf("%d ",aux->data);
        aux = aux->direita;
    }
    percorre_nivel(A->esquerda);
}

// funcao de criacao da arvore referida

Arv cria_arvore_generica(int elemento){
    Arv arvore;
    arvore = (no*) malloc (sizeof(no));
    if(arvore==NULL)return NULL;
    arvore->data = elemento;
    arvore->esquerda = NULL;
    arvore->direita = NULL;
    return arvore;

}

Arv cria_vazia(){
        return NULL;

}

int insere(Arv A, Arv sa){
    if(A==NULL)return 0;
    sa->direita = A->esquerda; // os filhos do no raiz, neste caso A, se tornam irmãos do nó sa.
    A->esquerda = sa;  // o nó A, recebe o nó sa como filho e consequentemente, como atualizado os irmaos anteriormente, nao há
    return 1;                   //perda de referencia
}

void exibe_arvore(Arv arvore){
        if(arvore==NULL){
            printf("<>");
            return;
        }
        printf("<");
        printf("%d", arvore->data);
        exibe_arvore(arvore->esquerda);
        printf(">");
        exibe_arvore(arvore->direita);
        return;
}

int busca_arv_generica(Arv arvore, int elemento){
    if(arvore==NULL) return 0;
    if(arvore->data == elemento)return 1;
    if(busca_arv_generica(arvore->esquerda, elemento)) return 1;
    if(busca_arv_generica(arvore->direita,elemento))   return 1;
    return 0;
}

void libera_arvore_generica(Arv *arvore){
    if((*arvore) == NULL)return;
    libera_arvore_generica(&((*arvore)->esquerda));
    libera_arvore_generica(&((*arvore)->direita));
    free(*arvore);
    *arvore = NULL;
    return;
}

void busca_preorder(Arv arvore){
    if(arvore==NULL)return;
    printf("%d ",arvore->data);
    busca_preorder(arvore->esquerda);
    busca_preorder(arvore->direita);
    return;
}
