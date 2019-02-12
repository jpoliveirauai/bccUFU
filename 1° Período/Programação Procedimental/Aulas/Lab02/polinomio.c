/*************************************/
/* program: polinomio.c                   */
/* autor: Claudio C. Rodrigues       */
/* data: dd/mm/2013                  */
/*************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {
	float coef[10]={0};
	int i, j, n, k;
	float x[20], Px[20]={0};
	printf("Calculo do polinomio P(x)=a0+a1.x + a2.x^2 + ... + an.x^n\n");
	printf("Digite a ordem do polinomio : ");
	scanf("%d",&n);
	printf("Digite os coeficientes (ai) do polinomio: \n");
	for(i=0;i<=n;i++){
		printf("a%2d: ",i);
		scanf("%f",&coef[i]);
	}
	printf("Digite a quantidade de pontos x que deseja calcular o ponomio P(x): \n");
	scanf("%d",&k);
	x[0] = 1.0;
	for(i=1;i<=k;i++){
		printf("Ponto %d: ",i);
		scanf("%f",&x[i]);
	}
	printf("P(x) = %.2f ",coef[0]);
	for(i=1;i<=n;i++) if(coef[i]!=0.0) printf("%c %.2f.x^%d ",(coef[i]<0)? '-' : '+',fabs(coef[i]),i);
	printf("\n");

	for(i=1;i<=k;i++){
		for(j=0;j<=n;j++) Px[i] += coef[j]*pow(x[i],j);
		printf("P(%.2f): %.2f\n",x[i], Px[i]);
	}



	return 0;
}


