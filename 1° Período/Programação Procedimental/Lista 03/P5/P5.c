#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *html, *ed;
    char arquivo[100], arquivo2[100],C;

    printf("Digite o caminho completo inclusive o nome do arquivo a ser aberto:\n");
    gets(arquivo);
    html=fopen(arquivo,"r");
    if(html==NULL)
    {
        printf("\nERRO: Nao Foi Encontrado o Arquivo!");
        exit(1);
    }

    printf("Digite o caminho completo inclusive o nome do arquivo a ser criado:\n");
    gets(arquivo2);
    ed=fopen(arquivo2,"w+");
    if(ed==NULL)
    {
        printf("\nERRO: Nao Foi Criar o Arquivo!");
        exit(1);
    }
    while(1)
    {
        C=fgetc(html);
        if(C=='<')
        {
            while(C!='>')
            {
                C=fgetc(html);
            }
            C=fgetc(html);
        }
        if(C==EOF)break;
        fputc(C,ed);
    }
    fclose(html);
    fclose(ed);

    return 0;
}
