// Programa - heron.c
// Autor: Claudio C. Rodrigues
// Data: dd/mm/aaaa
// Este programa calcula a raiz quadrada de um número 
// pelo metodo de heron

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>

// declaração de variaveis globais, macros e protótipos


int main(int argc, char *argv[]){
     // declaração de variáveis locais e comandos
   float fK, fN;
   int iI;
 
   printf("Entre com o valor de N:");
   scanf("%f", &fN);
 
   fK = 1;
   for( iI = 1; iI <= 12; iI++)
   {
      fK = (fK + (fN/fK))/2;
      printf("\nI = %d e K = %f", iI, fK);
   }
	getch();

   return 0;
}
