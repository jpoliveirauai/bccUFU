// Programa - nomearquivo.c
// Autor: Fulano C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>

// declaração de variaveis globais, macros e protótipos


int main(int argc, char *argv[]){
     // declaração de variáveis locais e comandos
	unsigned int n, d;
	printf("\n Digite um n\X163mero: ");
	scanf("%u", &n);
	printf("\n Os seus d\X161gitos s\X132o: ");
	while( n != 0 ) {
		d = n % 10;
		n /= 10;
		printf("%u, ", d);
	}
	getch();

   return 0;
}
