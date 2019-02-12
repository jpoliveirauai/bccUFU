// Programa - nomearquivo.c
// Autor: Fulano C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>

// declaração de variaveis globais, macros e protótipos


int main(int argc, char *argv[]){
     // declaração de variáveis locais e comandos
   int i;
 
   for (i=1; i < 30; i++) /* de 1 até 29 */
   {
      if (i > 10 &&  i < 20) /* se a variável estiver entre 11 e 19... */
      {
         continue; /* ...desvia para a condição inicial */
      }
      printf ("%d\n", i); /* ...senão mostra o número na tela */
   }

	getch();
   return 0;
}
