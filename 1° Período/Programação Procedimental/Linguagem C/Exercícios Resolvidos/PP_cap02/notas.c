/* programa notas.c */
#include <stdio.h>
int main()
{
    float a, b, m;
    printf("\n Digite duas notas: ");
    scanf("%f %f", &a, &b);
    m = (a+b)/2.0;
    if( m >= 7.0 ) {
        printf("\n Aprovado\n");
        }
    else {
         if(m >= 5.0) printf("\n Recuperacao\n");
         else printf("\n Reprovado\n");
         }
         getch();
    return 0;
}
