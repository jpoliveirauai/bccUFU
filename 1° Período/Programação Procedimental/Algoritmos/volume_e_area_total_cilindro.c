#include <stdio.h>
#include<math.h>
#define pi 3.141592
int main(){
	float r,al;
	printf ("Digite o raio:");
	scanf ("%f",&r);
	printf ("Digite a altura:");
	scanf ("%f",&al);
	printf("o volume desse circulo e: %.3f\nA area total e : %.3f",pow(r,2)*al*pi,(2*pi*r*al)+ 2*(pow(r,2)*pi));
	return 0;
}
