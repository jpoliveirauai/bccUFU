// Programa - nomearquivo.c
// Autor: Claudio C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>

// declaração de variaveis globais, macros e protótipos


int main(int argc, char *argv[]){
     // declaração de variáveis locais e comandos
     unsigned int o;
     do {
        printf("1. continua\n");
        printf("2. sair\n");
        printf("opcao --> ");
        scanf("%u",&o);
     } while(o != 2);

     return 0;
}
