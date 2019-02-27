#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"
#include <locale.h>
int main()
{
    char op = 0;
    setlocale (LC_ALL,"");
    printf("Bem Vindo ao programa JJ\n");
    getchar();
    int watchdog, id, localx,localy,capacidade,trafego;
    info *elemento;
    AVL a = cria_arvore();

    while(op!='0')
    {
        printf("Digite um n%cmero:\n",163);
        printf("1\)verifica se sua %crvore %c vazia\n",160,130);
        printf("2\)inserir um novo elemento\n");
        printf("3\)remover um elemento\n");
        printf("4\)buscar um elemento\n");
        printf("5\)exibir sua %crvore\n",160);
        printf("6\)exibir a arvore de modo visual\(ordenado\)\n");
        printf("7\)limpar sua arvore\n");
        printf("8\)verificar o menor tr%cfego\n",160);
        printf("9\)verificar a ociosidade da sua rede\n");
        printf("A\)verificar a quantidade de pontos finais da rede\n");
        printf("B\)verificar se a arvore %c cheia\n",130);
        printf("C\)observar o n%cvel de um elemento\n",161);
        printf("0\)sair\n");

        op = getchar();
        getchar();
        system("cls");
        switch(op)
        {
        case '1':
            printf("Sua arvore %s%c vazia\n",arvore_vazia(a)?"":"não ",130);
            break;
        case '2':
            printf("Digite os atributos do novo ponto:\n");
            printf("id: ");
            scanf("%d",&id);
            getchar();
            printf("\ncoordenada x: ");
            scanf("%d",&localx);
            getchar();
            printf("\ncoordenada y: ");
            scanf("%d",&localy);
            getchar();
            printf("\ntr%cfego: ",160);
            scanf("%d",&trafego);
            getchar();
            printf("\ncapacidade: ");
            scanf("%d",&capacidade);
            getchar();
            printf("\n");
            watchdog = insere_AVL(&a,id,localx,localy,capacidade,trafego);
            break;
        case '3'://remover um elemento
            printf("Digite o tr%cfego do ponto a excluir:\n",160);
            scanf("%d",&trafego);
            getchar();
            watchdog = remove_AVL(&a,trafego);
            break;
        case '4'://buscar um elemento
            printf("Digite o tr%cfego do ponto a buscar:\n",160);
            scanf("%d",&trafego);
            getchar();
            elemento = busca_binaria(a,trafego);
            if(elemento) exibe_raiz(elemento);
            else printf("Elemento n%co encontrado\n",198);
        case '5'://exibir sua arvore em modo texto
            exibe_arvore(a);
            break;
        case '6' : //exibir a arvore ordenadamente
           exibe_arvore_ordenada(a);
            break;
        case '7' ://limpar sua arvore
            libera_arvore(&a);
            break;
        case '8' ://verificar o menor trafego
            elemento = menor_trafego(a);
            printf("o menor trafego é: ");
            exibe_raiz(elemento);
            putchar('\n');
            break;
        case '9'://verificar a ociosidade da sua rede
            printf("a quantidade de elementos que est%co ociosos é: ",198);
            printf("%d\n",qtde_ocioso(a));
            break;
        case 'a'://quantidade de pontos finais da rede
        case 'A':
            printf("%d",nro_folha(a));
            break;
        case 'b'://verificar se a arvore é cheia
        case 'B':
            printf("a arvore %sé cheia\n",cheia(a)?"":"não ");
            break;

        }
    if(watchdog!=sucess)
    {
        printf("ocorreu um erro ao executar a opera%c%co",135,198);
        getchar();
        exit(EXIT_FAILURE);
    }
    }
    return 0;
}
