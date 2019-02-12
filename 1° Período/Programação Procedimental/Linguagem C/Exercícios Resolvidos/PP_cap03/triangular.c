// Programa - triangular.c
// Autor: Fulano C. Rodrigues
// Data: dd/mm/aaaa
// 
/* Programa que determina se um numero e' triangular
-  Dizemos que um número natural é triangular se ele é produto 
   de três números naturais consecutivos. 
   Exemplo: 120 é triangular, pois 4.5.6 = 120.
*/
#include <stdlib.h>
#include <stdio.h>

// declaração de variaveis globais, macros e protótipos


int main(int argc, char *argv[]){
     // declaração de variáveis locais e comandos
	int i, n;
	
//	printf("Digite o valor de n: ");
//	scanf("%d",&n);
	for(n=1;n<1000000;n++) {
	/* for com comando vazio! */
	for (i = 1; i*(i+1)*(i+2) < n; i++) ;
	
	if (i*(i+1)*(i+2) == n)
	printf("%d e' o produto %d*%d*%d\n", n, i, i+1, i+2);
//	else
//	printf("%d nao e' triangular\n", n);
   }
	
	getch();
	
   return 0;
}
