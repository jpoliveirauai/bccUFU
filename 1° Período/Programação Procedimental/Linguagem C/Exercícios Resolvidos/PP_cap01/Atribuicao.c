/****
 *
 * Exemplo: Atribuicao.c
 *
 * Capítulo: 1
 * Demonstra: atribuições múltiplas e conversão de atribuição
 *
 ****/

#include <stdio.h>

int main()
{
   float x;
   int y;

   x = y = 3.9;
   printf("\nx = y = 3.9\n");
   printf("x = %f \t y = %d \n", x, y);

   y = x = 3.9;
   printf("\ny = x = 3.9\n");
   printf("x = %f \t y = %d \n", x, y);

   return 0;
}

