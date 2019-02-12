// Programa - nomearquivo.c
// Autor: Claudio C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>

// declaração de variaveis globais, macros e protótipos


int main(int argc, char *argv[]){
     // declaração de variáveis locais e comandos

	int n;
	do{
	printf("\nDigite um número:");
	scanf("%d",&n);
	switch(n){
		case 1:putchar('A');
		 break;
		case 3:putchar('B');
		case 4:putchar('C');break;
		default: putchar('*');
		case 5:putchar('D');
		case 9:printf("Saindo...\n");
	}
	putchar('.');
	}while(n!=9);
	getchar();
	return 0;
}
