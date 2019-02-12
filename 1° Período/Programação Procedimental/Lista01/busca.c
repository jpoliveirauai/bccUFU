#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tm 100

int main () {
    char stm [tm], stme [tm];
    int cstm , i , cont;
    printf ("Digite a string maior: ") ;
    scanf ("%[^\n]" ,stm);
    printf ("Digite a string menor: ") ;
    scanf ("%[^\n]" , stme);
    for (cstm=0; stm[cstm]!=0; cstm++);
    for (i=0; stme [i] != 0 ; i++);
    for (i=cont=0; i < cstm − i + 1; i++) {
        cont = cont + encaixa (stme ,stm, i) ;
    }
    printf ("%s aparece em %s %d vezes\n" , stme ,stm, cont) ;
    return 0 ;
}
