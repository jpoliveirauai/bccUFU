// Programa - quadrado.c
// Autor: Fulano C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>

// declaração de variaveis globais, macros e protótipos


int main(int argc, char *argv[]){
     // declaração de variáveis locais e comandos
	unsigned int n, i, j, quad=0;
	
	printf("Digite um número inteiro: ");
	scanf("%u",&n);
	for(i=0;i<n;i++) quad += 2*i+1;
	
	printf("%d ao quadrado eh igual a %d\n",n,quad);
	
	getch();

   return 0;
}
