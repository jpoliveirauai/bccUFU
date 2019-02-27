#include "dicionario.h"
#include <stdlib.h>
struct reg{
    int chave;      //campo de ordenação
    char nome[100]; //demais dados
};

struct arquivo{
    registro itens[MAX];    //conjunto de registros
    int tamanho;            //demais dados do arquivo
};

arq* cria_arquivo(){
    arq* r = (arq*) malloc(sizeof(arq));
    if(r == NULL) return NULL;
    r->tamanho = 0;
    return r;
}

int insere_arquivo(arq *r,registro novo){
    if(r->tamanho==MAX) return 0;
    r->itens[r->tamanho] = novo;
    r->tamanho++;
    return 1;
}

int pesquisa_linear(arq *r, int chave){
    int i;
    if(chave<0||r==NULL||r->tamanho==0) return -1;
    for(i = 0;i<r->tamanho;i++){
        if(r->itens[i].chave == chave)return i;
    }
    return -1;
}

int remove_arquivo(arq *r,int chave){
    if(r==NULL) return 0;
    if(r->tamanho==0)return 0;
    int i,posicao = pesquisa_linear(r,chave);
    if(posicao==-1) return 0;
    for(i = posicao;i<r->tamanho;i++){
        r->itens[i] = r->itens[i+1];
    }
    r->tamanho--;
    return 1;
}

int busca_seq_ord(arq *r,int chave){
    int i=0;
    if(r->tamanho == 0||r -> itens[i].chave>chave||chave > r->itens[r->tamanho].chave) return -1;

    while(r->itens[i].chave>r->itens[i+1].chave)
        i++;
    if(r->itens[i].chave > chave) return -1;
    return i;
}

int ordena_itens(arq *r){

    return 1;
}
