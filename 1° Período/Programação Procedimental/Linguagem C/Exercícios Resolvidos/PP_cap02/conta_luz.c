// Programa - conta_luz.c
// Autor: Claudio C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>

// declaração de variaveis globais, macros e protótipos


int main(int argc, char *argv[]){
     // declaração de variáveis locais e comandos
     float tarifa, VF, VP, taxa_icms, icms, consumo;
     char classe;
     
     printf("Personal Light Agency: \n");
     printf("Informe a classe consumidora: ");
     scanf("%c",&classe);
     printf("Informe o consumo (kW.h): ");
     scanf("%f",&consumo);
     if(classe=='a' || classe=='A') tarifa = 0.5;
     if(classe=='b' || classe=='B') tarifa = 0.8;
     if(classe=='c' || classe=='C') tarifa = 1.0;
     
     VF = consumo*tarifa;
     taxa_icms = 0.3*VF;
     VP = VF + taxa_icms;
     printf("Valor a pagar: R$%6.2f\n", VP);
     printf("Taxa de icms : R$%6.2f\n", taxa_icms);
     
     getch();
     

     return 0;
}
