// Programa - eq2grau.c
// Autor: Claudio C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>

int main(){

	float a, b, c, delta;
	float xr1, xr2, xi1, xi2;

	printf("Cálculo das Raízes da Eq. Segundo Grau\n");
	printf("y = a.x2 + b.x + c\n");
	printf("Digite os valores de a, b e c\n") ;
	scanf("%f %f %f",&a,&b,&c);
	delta = b*b - 4 * a * c;
	if (delta == 0) {
		xr1 = -b/(2*a);
		printf ("Raizes iguais: %7.5f\n", xr1);
	} else {
		if (delta < 0) {
			printf("ha duas raizes complexas\n");
			xr1 = -b/(2*a);
			xi1 = sqrt(abs(delta))/(2*a);
			printf("Raizes: %7.5f +- %7.5fi\n",xr1,xi1);
		} else {
			printf("ha duas raizes reais\n");
			xr1 = (-b + sqrt(delta))/(2*a);
			printf("x1: %7.5f\n",xr1);
			xr2 = (-b - sqrt(delta))/(2*a);
			printf("x2: %7.5f\n",xr2);
		}
	}
	
	getch();
	return 0;
}
