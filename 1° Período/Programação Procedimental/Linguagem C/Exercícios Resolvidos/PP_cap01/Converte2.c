/****
 *
 * Exemplo: Converte2.c
 *
 * Capítulo: 1
 * Demonstra: Conversão de atribuição.
 *
 ****/

#include <stdio.h>

int main(void)
{
   double d = 4.1021456789654;
   float  f;

   f = d;

   printf("d = %20.18lf\nf = %20.18f\n", d, f);

   getchar();
   return 0;
}

/* Resultado:

	d = 4.102145678965399600
	f = 4.102145671844482400

*/
