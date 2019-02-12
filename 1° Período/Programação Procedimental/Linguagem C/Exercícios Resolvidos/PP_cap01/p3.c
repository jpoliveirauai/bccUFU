
// Programa para calcular a área de um círculo
#include <stdio.h>

int main() {
    const double PI = 3.14159;
    double raio = 0.0, area;
    printf("Digite valor do raio: ");
    scanf("%lf", &raio);
    area= PI * raio * raio;
    printf("A areado circulo de raio %4.2f eh %6.4f", raio, area);
    getch();
    return 0;
}
