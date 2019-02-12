// Programa - nomearquivo.c
// Autor: Claudio C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>

// declaração de variaveis globais, macros e protótipos


int main(int argc, char *argv[]){
     // declaração de variáveis locais e comandos
	int up, down;
	for (up = 0, down=10; up <= down; up++, down--)
	{
	printf("up = %d, down= %d\n",up,down);
	}
	getch();
     return 0;
}
