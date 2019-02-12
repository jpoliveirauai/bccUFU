#ifndef ARVOREGENERICA_H_INCLUDED
#define ARVOREGENERICA_H_INCLUDED


typedef struct No* Arv;

void postorder(Arv A);                 //percorre a árvore em pos-ordem
Arv cria_arvore_generica(int dados);   //recebe o elemento que será usado no primeiro nó, e cria a arvore
int insere(Arv A, Arv sa);             // valores de retorno: 0 para falha, 1 para sucesso
void exibe_arvore(Arv arvore);         // exibe a organizacao da arvore
Arv cria_vazia();                      // seta a arvore como vazia, setando o seu endereço atual como nulo
int busca_arv_generica(Arv, int);      // verifica se um elemento esta contido na arvore. retorna 0 para falha 1 para sucesso
void libera_arvore_generica(Arv *arvore);      // libera a arvore
void busca_preorder(Arv arvore);          // dispara a funcao de busca em pre ordem da arvore
void percorre_nivel(Arv A);                 //Percorre a árvore por nível(da esquerda para a direita
int nro_derivacao(Arv A);
int grau_arv(Arv A);
int altura_no(Arv A, int elem);
int qtde_nos(Arv A);











#endif // ARVOREGENERICA_H_INCLUDED
