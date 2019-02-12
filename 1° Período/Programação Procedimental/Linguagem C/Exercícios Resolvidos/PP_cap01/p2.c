// Programa para calcular a área de um círculo

#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159

int main() {
    double raio = 0.0, area;
    printf("Digite o valor do raio: ");
    scanf("%lf", &raio);
    area= PI * raio * raio;
    printf("A area do circulo de raio %lf eh %f\n", raio, area);
    getch();
    return 0;   
}
