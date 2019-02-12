#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*compfn)(const void*, const void*);

typedef struct
{
    char nome[100];
    int idade;
    double altura;
} PESSOA;

int  compare(PESSOA *, PESSOA *);

int main(void)
{
    char str[100], str2[100], pendrive[200], C;
    PESSOA P;
    FILE *dados, *dados2;
    int i=0, j=0;

    printf("Digite o caminho completo inclusive o nome do arquivo a ser aberto:\n");
    gets(str);
    dados=fopen("exemplo.txt","r");
    if(dados==NULL)
    {
        printf("\nERRO: Nao Foi Encontrado o Arquivo!");
        exit(1);
    }

    printf("Digite o caminho completo inclusive o nome do arquivo a ser criado:\n");
    gets(str2);
    dados2=fopen("exemplosaida.txt","w+");
    if(dados2==NULL)
    {
        printf("\nERRO: Nao Foi Criar o Arquivo!");
        exit(1);
    }
    while(!feof(dados))
    {
        C=getc(dados);
        if(C=='\n')
        {
            j++;
        }
    }
    j++;
    rewind(dados);
    PESSOA Povo[j];
    while(!feof(dados))
    {
        fgets(pendrive,200,dados);
        strcpy(P.nome,strtok(pendrive, ";"));
        //printf("\n%s\n",P.nome);
        P.idade = atoi(strtok(NULL, ";"));
        //printf("\n%d",P.idade);
        P.altura = atof((char*)strtok(NULL, ";"));
        //printf("\n%f\n",P.altura);
        Povo[i] = P;
        i++;
    }
    qsort((void *) &Povo, j, sizeof(PESSOA), (compfn)compare );

//   for (i = 0; i < j; i++)
//      printf("%d: %f - %d - %s\n",
//               i+1, Povo[i].altura, Povo[i].idade, Povo[i].nome);

    fclose(dados);
    for (i = 0; i < j; i++)
    {
        fputs(Povo[i].nome,dados2);
        fputc(';',dados2);
        fprintf(dados2,"%d;",Povo[i].idade);
        fprintf(dados2,"%.2f\n",Povo[i].altura);
    }
    fclose(dados2);
    //printf("\n\n%d",j);
    system("pause");
    return 0;
}
int compare(PESSOA *elem1, PESSOA *elem2)
    {
        if ( elem1->altura < elem2->altura)
            return -1;

        else if (elem1->altura > elem2->altura)
            return 1;

        else
            return 0;
    }
