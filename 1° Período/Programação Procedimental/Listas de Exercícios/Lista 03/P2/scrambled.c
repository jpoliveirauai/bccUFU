#include<stdio.h>
#include <stdlib.h>
#include<time.h>
char mistura(char *str, int tam);
int main(){
    FILE *in, *out;
    int i=0;
    char input[500],output[500],c,palavra[47];
    puts("Digite o nome do arquivo de entrada:");
    gets(input);
    if((in=fopen(input,"r"))==NULL){
        puts("Não foi possivel abrir o arquivo de entrada");
        exit(1);
    }
    puts("Digite o nome do arquivo de saida:");
    gets(output);
    if((out=fopen(output,"w"))==NULL){
        puts("Não foi possivel criar o arquivo de saida");
        exit(1);
    }
    while(1){
        c=getc(in);
        if (c==' '||c==','||c=='.'||c=='\n'){
            if (i!=0){
                palavra[i]='\0';
                mistura(palavra,strlen(palavra));
                fputs(palavra,out);
            }
            i=0;
            putc(c,out);
        }else{
            palavra[i]=c;
            if(c==EOF){
                palavra[i]='\0';
                mistura(palavra,strlen(palavra));
                fputs(palavra,out);
                break;
            }
            i++;
        }
    }
    fclose(in);
    fclose(out);
    return 0;
}
char mistura(char *str, int tam){
    if (tam>3){
        tam--;
        srand((unsigned)time(NULL));
        int i,p;
        char aux;
        for(i=1;i<tam;i++){
            p=1+(rand()%(tam-1));
            aux=str[i];
            str[i]=str[p];
            str[p]=aux;
        }
    }
}
