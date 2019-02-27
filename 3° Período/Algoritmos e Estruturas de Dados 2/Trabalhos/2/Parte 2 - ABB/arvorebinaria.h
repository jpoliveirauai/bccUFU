#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED

struct registro{
    char nome[50];
    int idade;
    char curso[50];
};
typedef struct registro reg;
struct No{
    reg dados;
    struct No* subarvore_esquerda;
    struct No* subarvore_direita;

};


typedef struct No no;
typedef no* Arv;


Arv cria_vazia_binaria(); // retorna para o ponteiro, null, ou seja, limpa o ponteiro pra receber uma nova alocacao

int arvore_binaria_vazia (Arv);

void libera_arvore_binaria(Arv);

void exibe_arvore_binaria(Arv);

void exibe_ordenado(Arv);

int insere_ordenado(Arv*,reg);

int remove_arv_binaria_ordenado(Arv*, int chave);

reg* busca_binaria(Arv,int chave);

reg* maior(Arv);

int de_maior(Arv);

int qnt_nos(Arv,int,int);

int um_filho(Arv);

int completa(Arv);

int altura_arvore_binaria(Arv);

Arv juntar(Arv,Arv);














#endif // ARVOREBINARIA_H_INCLUDED
