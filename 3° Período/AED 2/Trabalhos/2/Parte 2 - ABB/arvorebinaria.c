#include <stdio.h>
#include "arvorebinaria.h"

Arv cria_arvore_binaria(){
    return  NULL;
}

int arvore_binaria_vazia(Arv arvore){
    if(arvore==NULL){
        return 1; // significa que a arvore esta no estado de vazia
    }
    return 0; // significa que a arvore possui um endereco valido, ou lixo. Mas que ela nao esta setada como NULL

}

void libera_arvore_binaria(Arv arvore){
    if(!arvore_binaria_vazia(arvore)){
        libera_arvore_binaria(arvore->subarvore_esquerda);
        libera_arvore_binaria(arvore->subarvore_direita);
        free(&arvore);

    }
        arvore = NULL;
        return;
}

void exibe_arvore_binaria(Arv arvore){
    if(arvore == NULL){
        printf("<>");
        return;
    }
    printf("<");
    printf("%d", arvore->dados.idade);
    exibe_arvore_binaria(arvore->subarvore_esquerda);
    exibe_arvore_binaria(arvore->subarvore_direita);

    printf(">");

    return;
}

void exibe_ordenado(Arv arvore){
    printf("ordem: ");
    exibe_arvore_binaria_ordenado(arvore);
    printf("\n");
    return;
}

void exibe_arvore_binaria_ordenado(Arv arvore){
    if(arvore!=NULL){
        exibe_arvore_binaria_ordenado(arvore->subarvore_esquerda);
        printf("%d,",arvore->dados.idade);
        exibe_arvore_binaria_ordenado(arvore->subarvore_direita);
    }
    return;
}

int insere_ordenado(Arv *A, reg elemento){

    if(A==NULL){
        printf("erro, arvore nao existe\n");
        return 0;  // arvore não existe!
    }
    if(*A==NULL){  //verifica se a arvore esta vazia

        Arv no_auxiliar = (no*) malloc(sizeof(no));
        if(no_auxiliar==NULL)return 0; // falha na alocacao

        no_auxiliar->dados = elemento;              //se esta vazia, faz com que o elemento seja a raiz. obs: posicao correta
        no_auxiliar->subarvore_direita = NULL;
        no_auxiliar->subarvore_esquerda = NULL;
        (*A) = no_auxiliar;
        return 1;
    }
    else{  // encontra a posicao relativa do novo no, se for maior acrescenta na direita, se menor acrescenta na esquerda
        if(elemento.idade > (*A)->dados.idade){
            return insere_ordenado(&((*A)->subarvore_direita),elemento);  // faz uma recursao até encontrar o lugar certo para alocar
        }
        else{
            return insere_ordenado(&((*A)->subarvore_esquerda),elemento);
        }

    }

    return 0;
}


int remove_arv_binaria_ordenado(Arv * arvore, int chave){

    if(arvore == NULL || *arvore == NULL){            //verifica a condicao da arvore, e se ela esta disponivel para fazer alguma
                                                      // remocao
        printf("erro, arvore nao existe ou vazia\n");
        return 0;
    }

    if(chave > (*arvore)->dados.idade){
        return remove_arv_binaria_ordenado(&((*arvore)->subarvore_direita),chave); // se a chave for maior, tenta pra direita
    }

    else if(chave < (*arvore)->dados.idade){
        return remove_arv_binaria_ordenado(&((*arvore)->subarvore_esquerda),chave); // se a chave for menor tenta pra esquerda
    }

    else if(chave == (*arvore)->dados.idade){  //senao for maior nem menor, significa que voce esta na posicao correta para a remocao

        if((*arvore)->subarvore_direita == NULL && (*arvore)->subarvore_esquerda == NULL){ //tipo 1: sem sub_arvores
            free(*arvore);
            arvore = NULL;
            return 1; return 1;
        }
        else if((*arvore)->subarvore_direita == NULL && (*arvore)->subarvore_esquerda != NULL){ //tipo2: com sub_arvore a direita
            Arv aux;
            aux = *arvore;
            *arvore = aux->subarvore_esquerda;
            free(aux);
            return 1;
        }
        else if((*arvore)->subarvore_direita != NULL && (*arvore)->subarvore_esquerda == NULL){ //tipo3: com sub_arvore a esquerda
            Arv aux;
            aux = *arvore;
            *arvore = aux->subarvore_direita;
            free(aux);
            return 1;
        }
        else{                                                                                 //tipo4: com ambas as sub_arvores
            Arv aux1,temp;

            aux1 = (*arvore)->subarvore_esquerda;  //inicializa auxiliar para encontrar a maior chave da arvore a esquerda

            while(aux1->subarvore_direita){ // faca até que a sub_arvore a direita seja NULL obs: encontra a maior chave da SAE
                aux1 = aux1->subarvore_direita;
            }
            temp = *arvore;           //um temp para não existir perda de informacao durante a troca de posicao
            *arvore = aux1;
            aux1 = temp;
            return remove_arv_binaria_ordenado(&((*arvore)->subarvore_esquerda), chave);  //chama a funcao novamente para fazer a remocao
                                                                                          // em um no folha sem filhos

        }
    }
    else{
        printf("impossivel remover\n");
        printf("chave inexistente\n");
        return 0;
    }
}

reg* busca_binaria(Arv arvore, int chave){

    if(arvore==NULL){
        printf("erro, nao encontrado\n");
        return NULL;
    }
    if(arvore->dados.idade == chave){
        return &(arvore->dados);
    }

    else if(chave > arvore->dados.idade){
        return busca_binaria(arvore->subarvore_direita, chave);
    }
    else if(chave < arvore->dados.idade) {
        return busca_binaria(arvore->subarvore_esquerda, chave);
    }
    else{
        printf("Nao encontrado\n");
        return NULL;
    }
}

reg* maior(Arv arvore){

    if(arvore==NULL){
        printf("arvore vazia ou inexistente\n");
        return NULL;
    }

    Arv aux;
    aux = arvore;

    while(aux->subarvore_direita){                 // percorre a arvore ate que o proximo elemento apontado pra direita seja nulo
        aux = aux->subarvore_direita;
    }

    return (&(aux->dados));


}



int de_maior(Arv arvore){

    if(arvore == NULL){
        printf("arvore inexistente ou vazia\n");
        return 0;
    }
    int h =0;

    de_maior_aux(arvore,&h);

    return h;

}

void de_maior_aux(Arv a, int*h){

    if(a == NULL){
        return;
    }
    if(a->dados.idade >= 18){
        (*h)++;
    }

    de_maior_aux(a->subarvore_esquerda, h);
    de_maior_aux(a->subarvore_direita,h);



    return;

}

int qnt_nos(Arv arvore, int ini, int fim){

    if(arvore==NULL)
        return -1;
    int h=0;
    qnt_nos_aux(arvore,ini,fim,&h);
    return h;

}


void qnt_nos_aux(Arv arvore, int ini, int fim, int* h){

    if(arvore==NULL){
        return;
            }
    if(arvore->dados.idade >= ini && arvore->dados.idade <=fim){
        (*h)++;
    }


    qnt_nos_aux(arvore->subarvore_esquerda,ini,fim,h);
    qnt_nos_aux(arvore->subarvore_direita,ini,fim,h);

    return;

}

int um_filho(Arv arvore){

    if(arvore==NULL){
        return 0;
    }
    if(arvore->subarvore_direita == NULL && arvore->subarvore_esquerda!=NULL){
        return 1;
    }
    if(arvore->subarvore_direita != NULL && arvore->subarvore_esquerda==NULL){
            return 1;
    }


    return um_filho(arvore->subarvore_direita) + um_filho(arvore->subarvore_esquerda);

}

int completa(Arv arvore){

    if(!um_filho(arvore)){     // se a arvore for completa, os nos terao 2 ou 0 filhos. Logo se um_filho retornar 0, é uma arvore completa
        return 1;
    }
    else return 0;
}

int altura_arvore_binaria(Arv arvore){

    if(arvore == NULL){
        return -1;
    }
    int hd, he;
    hd = altura_arvore_binaria(arvore->subarvore_direita);
    he = altura_arvore_binaria(arvore->subarvore_esquerda);
    if(hd > he){
        return hd+1;
    }
    else return he+1;

}

void juntar_aux(Arv *nova, Arv concatena);

Arv juntar(Arv a1, Arv a2){

    Arv *nova_arvore ;
    nova_arvore = (Arv*) malloc(sizeof(Arv));

    *nova_arvore = cria_arvore_binaria();


    juntar_aux(nova_arvore,a1);
    juntar_aux(nova_arvore,a2);


    return (*nova_arvore);


}



void juntar_aux(Arv *nova, Arv concatena){


        if(concatena == NULL){
            return;
        }

        insere_ordenado(nova,concatena->dados);

        juntar_aux(nova,concatena->subarvore_esquerda);
        juntar_aux(nova,concatena->subarvore_direita);

        return;



}
