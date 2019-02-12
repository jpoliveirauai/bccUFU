// Programa - potencia.c
// Autor: Fulano C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>

// declaração de variaveis globais, macros e protótipos


int main(int argc, char *argv[]){
     // declaração de variáveis locais e comandos
  int x,        /* base                         */ 
      n,        /* expoente                     */
      potencia, /* guarda as potencias parciais */ 
      contador; 
  
  printf("\n\tCalculo de potencias\n");
  printf("\nDigite um numero inteiro: ");
  scanf("%d", &x);
  printf("Digite um numero um inteiro nao-negativo: ");
  scanf("%d", &n);
  
  /* Inicializacoes */
  potencia = 1;
  contador = 0;
  
  /* Calculo da potencia */
  while (contador != n) {
    potencia = potencia * x;
    contador = contador + 1;
  }
  
  printf("\nO valor de %d elevado a %d: %d\n", x, n, potencia);

  getch();
  return 0;
}
