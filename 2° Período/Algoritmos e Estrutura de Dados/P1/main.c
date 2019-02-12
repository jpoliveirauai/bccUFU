#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listop.h"
int main(){
    lista* familia = criar();
    insere_elemento(familia,5);
    atribui_nomes(familia);
    printf("%d",tamanho(familia));
    return 0;
}
