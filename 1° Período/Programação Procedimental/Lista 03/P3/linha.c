#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int procura(FILE *p,char *palavra);
int main (int argc, char*argv){
    char caminho[500],sea[500];
    puts("Digite o caminho do arquivo onde procurar:");
    gets(caminho);
    puts("Digite a string a ser pesquisada:");

    gets(sea);
    FILE *arq;
    if((arq=fopen(caminho,"r"))==NULL){
        puts("Nao foi possivel abrir o arquivo");
        exit(1);
    }
    system("cls");
    procura(arq,sea);
    return 0;
}


int procura(FILE *p,char *palavra){
    char linha [1024];
    int nlinha=1;
    while((fgets(linha,1024,p))!=NULL){
        if (strstr(linha,palavra)!=NULL){
            printf("Encontrado na linha %d: %s\n\n",nlinha,linha);
        }
        nlinha++;
    }
}
