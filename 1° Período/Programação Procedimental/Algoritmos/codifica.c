#include <stdio.h>
#include <string.h>
int main(){
    char s[500],t;
    int tam,i;
    gets(s);
    tam=strlen(s);
    for (i=0;i<tam;i++){
        t = tolower(s[i]);
        switch(t){
            case 'a':
                s[i]='4';
            break;
            case 'e':
                s[i]='3';
            break;
            case 'i':
                s[i]='1';
            break;
            case 'o':
                s[i]='0';
            break;
            case 'u':
                s[i]='6';
            break;
            case ' ':
                s[i]='_';
            break;
        }
    }
    for (i=0;i<tam;i++) printf("%c",s[i]);
}
