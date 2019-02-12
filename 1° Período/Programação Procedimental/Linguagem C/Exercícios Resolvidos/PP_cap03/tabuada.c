// Programa - nomearquivo.c
// Autor: Claudio C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>

// declaração de variaveis globais, macros e protótipos


int main(int argc, char *argv[]){
     // declaração de variáveis locais e comandos
	int i, j;
	
	for(i=1;i<=10;i++) {
		for(j=1;j<=10;j++)
		  printf("%3d",i*j);
		printf("\n");
	}
	
	getch();
	

   return 0;
}
