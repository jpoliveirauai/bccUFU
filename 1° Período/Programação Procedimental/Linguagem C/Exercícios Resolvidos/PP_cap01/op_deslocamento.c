/* Demonstracao do operador deslocamento*/

#include <stdio.h>
int main() {
    int n1, n2, n3;
    n1 = 10; n2 = 7;
    n3 = (n1>>2)+(++n2<<2);
    printf("Numeros: %d, %d e %d\n", n1, n2, n3);
    getch();
    return 0;
}
