// Programa - break.c
// Autor: Fulano C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>

// declaração de variaveis globais, macros e protótipos


int main(int argc, char *argv[]){
     // declaração de variáveis locais e comandos
   int limite;
   int i;
   char op;
 
   printf ("Contar ate : ");
   scanf ("%d", &limite);
 
   i = 1;
   while (i <= limite)
   {
      printf("\n%d", i++);
 
      printf("\nTermina (S/N)?");
      fflush(stdin);
      scanf("%c", &op); 
 
      if (op == 's' || op == 'S') /* Se for respondindo sim... */
      {
         break;  /* ... interrompe a execução */
      }
   }
   printf("\nContagem Encerrada"); /* ...desviando o programaa próxima instrução depois do } (fecha chaves) do while */
	getch();

   return 0;
}
