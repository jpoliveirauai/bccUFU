#include <stdio.h>
#include <math.h>
int main(){
    int lados,lado;
    float a;
	printf("Digite o numero de lados do poligono: ");
	scanf("%d",&lados);
	printf("\nDigite tamanho de um lado do poligono REGULAR: ");
	scanf("%d",&lado);
	switch(lados){
        case 3:
            a= pow(lado,2)*(sqrt(3)/4);
        break;
        case 4:
            a=pow(lado,2);
        break;
        case 6:
            a= 6 * pow(lado,2)*(sqrt(3)/4);
        break;
	}
	printf("A area do poligono eh %.2f",a);
}
