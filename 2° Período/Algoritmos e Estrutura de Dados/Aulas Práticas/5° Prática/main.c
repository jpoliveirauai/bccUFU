#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <sys/time.h>
int main(int argc, char *argv[]){
    struct timeval t;
    TipoLista lista1, lista2, lista3;
    TipoItem item;
    int vetor[MAX];
    TipoApontador p,r;
    int i, j, k, n, posicao;
    float tamanho1 = 0, tamanho2 = 0;
    gettimeofday(&t,NULL);
    srand((unsigned int)t.tv_usec);
    FLVazia(&lista1);
    FLVazia(&lista2);
    FLVazia(&lista3);
    /*-Lista 01-----------------------------------------------------*/
    printf("Inserindo elementos na Lista 1:\n");
    /*Gera uma permutacao aleatoria de chaves entre 1 e MAX*/
    for(i = 0; i < MAX; i++) vetor[i] = i + 1;
    for(i = 0; i < MAX; i++){
        k = (int) (10.0 * rand()/(RAND_MAX + 1.0));
        j = (int) (10.0 * rand()/(RAND_MAX + 1.0));
        n = vetor[k];
        vetor[k] = vetor[j];
        vetor[j] = n;
    }
    /*Insere cada chave na lista */
    for (i = 0; i < MAX; i++){
        item.Chave = vetor[i];
        Insere(item, &lista1);
        tamanho1++;
        printf("Inseriu: %d \n", item.Chave);
    }
    printf("\nLista 1:\n");
    Imprime(lista1);
    printf("Inserindo elementos na Lista 2:\n");
    for(i = 0; i < MAX; i++) vetor[i] = i + 1;
    for(i = 0; i < MAX; i++){
        k = (int) (10.0 * rand()/(RAND_MAX + 1.0));
        j = (int) (10.0 * rand()/(RAND_MAX + 1.0));
        n = vetor[k];
        vetor[k] = vetor[j];
        vetor[j] = n;
    }
    /*Insere cada chave na lista */
    for (i = 0; i < MAX; i++){
        item.Chave = vetor[i] + 10;
        Insere(item, &lista2);
        tamanho2++;
        printf("Inseriu: %d \n", item.Chave);
    }
    printf("\nLista 02:\n");
    Imprime(lista2);
    printf("Situacao da lista 1:");
    Imprime(lista1);
    printf("Situacao da lista 2:");
    Imprime(lista2);
    r = lista1.Primeiro;
    printf("Retirada da Lista 01:\n");
    Retira(r, &lista1, &item);
    printf("\n Retirou: %d\n", item.Chave);
    printf("Situacao atual da lista 1:\n");
    Imprime(lista1);
    do
    {
        printf("\nDigite a posicao:");
        scanf("%d", &posicao);
    }
    while((posicao < 0)||(posicao > 9));
    InsereItem(posicao, item, &lista1);
    printf("Elemento inserido:\n");
    Imprime(lista1);
    conc_Lis(&lista1, &lista2, &lista3);
    printf("\nLista Concatenada:\n");
    Imprime(lista3);
    printf("\nElementos retirados da Lista 01:\n");
    for(i = 0; i < MAX; i++)
    {
        k = (int) ((tamanho1) * rand() / (RAND_MAX + 1.0));
        p = lista1.Primeiro;
        Retira(p, &lista1, &item);
        tamanho1--;
        printf("Retirou: %d\n", item.Chave);
    }
    printf("Lista 1:\n");
    Imprime(lista1);
    printf("Lista 2:\n");
    Imprime(lista2);
    printf("Lista Concatenada:\n");
    Imprime(lista3);
    return(0);
}
