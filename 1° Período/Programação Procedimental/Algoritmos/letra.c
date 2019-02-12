#include <stdio.h>
#include <ctype.h>
int main(){
    char letra;
    do{
        fflush(stdin);
        scanf("%c",&letra);
        letra=toupper(letra);
    }while(letra<65||letra>90);
    printf("eh %s",letra=='A'||letra=='E'||letra=='I'||letra=='O'||letra=='U'?"vogal":"consoante");


}
