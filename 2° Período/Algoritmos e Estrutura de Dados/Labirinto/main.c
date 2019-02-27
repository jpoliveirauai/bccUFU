#include <stdio.h>
#include <stdlib.h>
#include "labirinto.h"
#include <ctype.h>
#include <string.h>
int main(){
    int tamanho;
    char opcao;
    while(1){
        printf("******************************************************************************\n");
        printf("*                                                                            *\n");
        printf("*                  Bem Vindo Ao Labirinto do AssusTAdo                       *\n");
        printf("*                                                                            *\n");
        printf("*                                                                            *\n");
        printf("*               Sou um fodendo labirinto que se resove sozinho e             *\n");
        printf("*                           sem a ajuda de humanos                           *\n");
        printf("******************************************************************************\n\n");
        puts("Digite:");
        puts("1 - Jogar");
        puts("2 - Sair");
        scanf("%c",&opcao);
        switch(opcao){
            case '1':
                system("cls");
                do{
                    puts("Digite o tamanho do labirinto  >=1 :");
                    scanf("%d",&tamanho);
                }while(tamanho<=1);
                system("cls");
                puts("\tLabirinto:");
                int **matriz = cria_matriz(tamanho);
                cria_labirinto(&matriz,tamanho);
                system("cls");
                percorre(&matriz,tamanho);
                puts("\tLabirinto Resolvido:");
                printa(matriz,tamanho);
                system("pause");
                libera_matriz(matriz,tamanho);
            break;

            case '2':
                exit(1);
            break;
            default:
                system("cls");
                continue;
            break;
        }
    }
    return 0;
}
