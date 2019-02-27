#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void inv_st (char *stri,int j,int i) {
    if (i<=j){
        char aux;
        aux = stri[i];
        stri[i]= stri[j];
        stri[j]= aux;
        i++;
        j--;
        inv_st(stri,j,i);
    }

}


int main(int argc, char* argv[]){
    char str[200];
    printf("Digite uma frase:");
    gets(str);
    int i=0;
    inv_st(str,(strlen(str)-1),i);
    printf("\nfrase invertida: %s",str);
}
