#include <stdio.h>
#include <stdlib.h>
    int amendoim(int p,int i){
        p/=10;
        if (p==0) {
            i++;
            return i;
        } else i++;
        amendoim(p,i);
    }


int main(int argc, char* argv){
    printf("Digite um numero:");
    int pacoca;
    do
    scanf("%d",&pacoca); while (sizeof(pacoca)!=4);
    int i=0;
    printf("\no numero tem %d digitos C====3   _!_",amendoim(pacoca,i));
}
