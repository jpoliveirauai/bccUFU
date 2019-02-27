// Programa - estatistica.c
// Autor: Claudio C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// declaração de variaveis globais, macros e protótipos


int main(int argc, char *argv[]){
	int i, n;
	float x[100], xp[100], soma1 = 0.0, soma2 = 0.0, media, mediaq, desvio;
	do{
        printf("Digite a quantidade de valores (<=100): ");
        scanf("%d",&n);
	} while(n>100);
	for(i=0;i<n;i++){
		printf("x%d: ",i);
		scanf("%f",&x[i]);
		soma1 += x[i];
		soma2 += x[i]*x[i];
	}
	media = soma1/n;
	mediaq = soma2/n;
	desvio = sqrt(fabs(mediaq-media*media));
	printf("Valores:\t|\tValores Padronizados");
	for(i=0;i<n;i++){
		xp[i] = 500+100*(x[i]-media)/desvio;
		printf("\nx[%d]: %.3f \t|\t %.3f",i,x[i],xp[i]);
	}
	printf("\n\nMedia : %f\nDesvio: %f\n",media,desvio);
	return 0;
}

