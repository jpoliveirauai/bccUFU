// programa exponencial --> e^x;

#include <stdio.h>

int main()
{
    const double erro = 1.0E-7; 
    double x, termo, soma;
    float n;
    
    printf("Programa calcula a exponencial de x:\n");
    printf("Digite o valor de x: ");
    scanf("%lf",&x);
    printf("%lf\n",x);
    // inicializacoes
    soma = 0.0;
    termo = 1.0;
    n = 0;
    while (termo >= erro) 
    {
          printf("%f\n",n);
          soma = soma + termo;
          n = n + 1;
          termo = termo*(x/n);
    }
    printf("O exponecial de %lf eh: %lf\n",x,soma);
    
    system("PAUSE");
    return 0;
}
          
