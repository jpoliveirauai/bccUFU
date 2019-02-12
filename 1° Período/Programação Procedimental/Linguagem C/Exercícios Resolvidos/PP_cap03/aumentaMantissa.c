#include <stdio.h>

int main(void)
{
    double valor = 10.0 / 3.0;
    int i, comprimento = 4, mantissa = 0;
    for (i = 0; i < 10; i = i + 1)
    {
        comprimento = comprimento + 1;
        mantissa = mantissa + 1;
        printf("%*.*lf\n", comprimento, mantissa, valor);
    }
    getch();
    return 0;
}
